FROM ubuntu:24.04
RUN apt update && apt install -y clang g++ gdb valgrind make
WORKDIR /lab-debug
COPY . .
CMD ["bash"]
