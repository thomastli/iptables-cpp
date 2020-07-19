# our local base image
FROM ubuntu:20.04

MAINTAINER Thomas Li "thomas.tong.li@gmail.com"

ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=America/UTC

LABEL description="Container for use with Visual Studio" 

# install build dependencies 
RUN DEBIAN_FRONTEND="noninteractive" apt-get update && apt-get install -y g++ make cmake git iptables libiptc0 libiptc-dev autotools-dev autoconf