# FIXME: Replace 'ubuntu' with your base image.
FROM ubuntu:23.04
# FIXME: Change maintainer name.
LABEL maintainer "Maintainer <maintainer@email>"
# FIXME: Install all packages you want to have in your release container.
# A minimal useful installation should include at least libstdc++ and binutils.

ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Moscow

RUN apt-get update && apt-get install build-essential manpages-dev software-properties-common -y
RUN add-apt-repository ppa:ubuntu-toolchain-r/test
RUN apt-get update && apt-get install gcc-13 g++-13 openssh-server ninja-build rsync gdb binutils -y
RUN apt-get install python3-pip pipx -y

RUN pip3 install --upgrade pip --break-system-packages
RUN pip3 install conan cmake --break-system-packages
#RUN pipx install conan 
#RUN pipx install cmake 
#RUN pipx ensurepath

RUN update-alternatives --remove-all cpp

RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-12 120 --slave /usr/bin/g++ g++ /usr/bin/g++-12 --slave /usr/bin/gcov gcov /usr/bin/gcov-12 --slave /usr/bin/gcc-ar gcc-ar /usr/bin/gcc-ar-12 --slave /usr/bin/gcc-ranlib gcc-ranlib /usr/bin/gcc-ranlib-12  --slave /usr/bin/cpp cpp /usr/bin/cpp-12 && \
update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-13 130 --slave /usr/bin/g++ g++ /usr/bin/g++-13 --slave /usr/bin/gcov gcov /usr/bin/gcov-13 --slave /usr/bin/gcc-ar gcc-ar /usr/bin/gcc-ar-13 --slave /usr/bin/gcc-ranlib gcc-ranlib /usr/bin/gcc-ranlib-13  --slave /usr/bin/cpp cpp /usr/bin/cpp-13;

RUN useradd -rm -s /bin/bash -u 1001 gcc-13 

RUN echo 'gcc-13:gcc-13' | chpasswd

RUN service ssh start

EXPOSE 22

CMD ["/usr/sbin/sshd", "-D"]


