#include <iostream>
#include <chrono>
using namespace std::chrono;
#include <concepts>
#include <format>
#include <thread>
#include <vector>
#include <numeric>
#include <string_view>
#include <random>


constexpr auto fast_pow(std::integral auto base, std::integral auto exp) {
    size_t result{ 1 };

    while (exp > 0) {
        if (exp % 2 == 0) {
            base *= base;
            exp /= 2;
        } else {
            result *= base;
            --exp;
        }
    }

    return result;
}

struct Result {
    double pi{0.0};
    milliseconds elapsed_time{0};
    size_t iteration_num{0};
    size_t thread_num{1};
};

void print(Result const& result, std::string const& test_name) {
    using namespace std::literals;
    constexpr auto header{"Calculated pi"sv};
    constexpr auto width{header.size()};
    constexpr auto fmt{"{:<{}} = {:.8}\n"};
    std::cout << std::format("{:=^80}\n", std::format("<{}>", test_name));
    std::cout << std::format(fmt, header, width, result.pi);
    std::cout << std::format(fmt, "Real pi", width, std::numbers::pi);
    std::cout << std::format(fmt, "Error", width, result.pi - std::numbers::pi);
    std::cout << std::format("{:<{}} = {}\n", "Time", width, result.elapsed_time);
    std::cout << std::format("{:<{}} = {}\n", "Threads", width, result.thread_num);
    std::cout << std::format("{:<{}} = {}\n", "Iterations", width, result.iteration_num);
    std::cout << std::format("{:=^80}\n", std::format("</{}>", test_name));
}


int main()
{
    auto const cors_num{std::thread::hardware_concurrency()};
    auto const thread_num{std::max(2u, cors_num + cors_num % 2u - 2u)};
    constexpr auto n{ fast_pow(10,9) };

    {
        std::vector<std::jthread> threads;
        threads.reserve(thread_num);

        std::vector<double> thread_data(thread_num, 0.0);

        auto const start{ steady_clock::now() };

        for (size_t id{ 0 }; id < thread_num; ++id) {
            threads.emplace_back(
                    [id, thread_num, &thread_data] {
                        double const coefficient{ 1.0 - 2.0 * static_cast<double>((id + 1) % 2) };
                        for (size_t i{ id + 1 }; i < n; i += thread_num) {
                            thread_data[id] += coefficient / static_cast<double>(i * 2 + 1);
                        }
                    }
            );
        }

        threads.clear();
        auto const sum{ std::accumulate(thread_data.cbegin(), thread_data.cend(), 1.0) };
        double pi = sum * 4;

        auto const diff{ duration_cast<milliseconds>(steady_clock::now() - start) };
        print({ pi, diff, n, thread_num }, "Parallel implementation");
    }

    {
        auto const start{ steady_clock::now() };
        double sum{ 1.0 };
        double coefficient{ -1.0 };
        for (size_t i{ 1 }; i < n; ++i) {
            sum += coefficient / static_cast<double>( i * 2 + 1 );
            coefficient *= -1;
        }

        auto const pi{sum * 4.0};
        auto const diff{ duration_cast<milliseconds>(steady_clock::now() - start) };
        print({ pi, diff, n, 1}, "Single thread implementation");
    }

    {
        std::random_device rd;
        std::vector<std::jthread> threads;
        threads.reserve(thread_num);

        struct alignas(std::hardware_destructive_interference_size) ThreadData{
            std::mt19937_64 gen;
            size_t sum{0};
        };

        std::vector<ThreadData> thread_data;
        thread_data.reserve(thread_num);
        for (auto i{0}; i < thread_num; ++i) {
            thread_data.emplace_back(ThreadData{std::mt19937_64 {rd()}, 0});
        }

        auto const start{ steady_clock::now() };

        for (size_t id{0}; id < thread_num; ++id) {
            auto const size{ n / thread_num + (id < n % thread_num ? 1 : 0)};
            threads.emplace_back([id, size, &thread_data]{
                auto& gen{thread_data[id].gen};
                std::uniform_real_distribution<> dis(0.0, 1.0);
                for (auto i{0}; i < size; ++i) {
                    auto const x{dis(gen) - 1.0};
                    auto const y{dis(gen) - 1.0};
                    if (x * x + y * y <= 1.0)
                        ++thread_data[id].sum;
                }
            });
        }

        threads.clear();

        auto op{[](std::integral auto acc, ThreadData const& data) {
            return acc + data.sum;
        }};
        auto const sum{ std::accumulate(thread_data.cbegin(), thread_data.cend(), 0, op) };
        auto const pi{sum * 4.0 / n};
        auto const diff{ duration_cast<milliseconds>(steady_clock::now() - start) };
        print({ pi, diff, n, thread_num }, "Randomized implementation");
    }

}
