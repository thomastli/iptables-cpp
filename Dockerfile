# our local base image
FROM ubuntu:20.04

LABEL maintainer="thomas.tong.li@gmail.com"

ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=America/UTC

LABEL description="Container for use with Visual Studio" 

# install build dependencies 
RUN DEBIAN_FRONTEND="noninteractive" apt-get update && apt-get install -y g++ make cmake git iptables libjsoncpp-dev \ 
 && apt-get clean \
 && rm -rf /var/lib/apt/lists/*
