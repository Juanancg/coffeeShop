# Basic dockerfile for working with C++ and python programs for development
FROM debian:11

# Install required packages
RUN apt-get update && \
    apt-get install -y cmake g++ clang-format libgtest-dev

WORKDIR /opt/orderManager

CMD ["/bin/bash"]