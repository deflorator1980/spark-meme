# IO.puts "Hello world from Elixir"
# IO.puts :math.pow(2,4)
n = Kernel.trunc(:math.pow(10, 7))
start = :os.system_time()
pi = Enum.sum(
    Enum.filter(
        Enum.map(1..n, fn _ -> (:math.pow(:rand.uniform - 1, 2) + :math.pow(:rand.uniform - 1, 2))  end),
         fn x -> x <= 1 end )) * 8 / n
stop = :os.system_time()
IO.puts pi
IO.inspect (stop-start)/:math.pow(10,9), label: "Time"

