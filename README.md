
# iptables-cpp
[![CircleCI](https://dl.circleci.com/status-badge/img/gh/thomastli/iptables-cpp/tree/main.svg?style=svg)](https://dl.circleci.com/status-badge/redirect/gh/thomastli/iptables-cpp/tree/main)
[![CodeFactor](https://www.codefactor.io/repository/github/thomastli/iptables-cpp/badge)](https://www.codefactor.io/repository/github/thomastli/iptables-cpp)
[![codecov](https://codecov.io/gh/thomastli/iptables-cpp/branch/master/graph/badge.svg?token=NZWAI45FRI)](https://codecov.io/gh/thomastli/iptables-cpp)

C++ library for listing, adding, modifying, and deleting iptable rules

## Build instructions

### Using a docker container
Building the docker image:
```
git clone https://github.com/thomastli/iptables-cpp.git \
cd iptables-cpp \
docker build -t iptables-ubuntu . \
```

Running the docker image in a container:
```
docker run -it --cap-add=NET_ADMIN --cap-add=NET_RAW iptables-ubuntu /bin/bash \
git clone https://github.com/thomastli/iptables-cpp.git \
cd iptables-cpp \
sudo ./build.sh
```

### Local builds
Building `iptables-cpp` using the build script:
```
git clone https://github.com/thomastli/iptables-cpp.git \
cd iptables-cpp \
sudo ./build.sh
```

### Usage instructions
Running the demo:
```
sudo ./iptablescpp
```

Running the unit tests:
```
sudo ./iptablescpp_test
```
