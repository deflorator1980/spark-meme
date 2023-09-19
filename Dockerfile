FROM gcc
WORKDIR /app
COPY ./cpppi.cpp .
COPY ./cpppi3.cpp .
# RUN ls -la
# RUN g++ -v
# RUN g++ -std=c++20 -pthread -O3 cpppi -c cpppi.cpp

RUN g++ -std=c++14 -o cpppi cpppi.cpp && ./cpppi
RUN g++ -std=c++20 -o cpppi cpppi.cpp && ./cpppi
RUN g++ -std=c++20 -pthread -O3 cpppi -c cpppi.cpp && ./cpppi
# CMD ./cpppi
CMD sleep 9999

