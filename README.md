# iptables-cpp

C++ library for listing, adding, modifying, and deleting iptable rules

## Build instructions

### Using a docker container

git clone https://github.com/thomastli/iptables-cpp.git \
cd iptables-cpp \
docker build -t iptables-ubuntu . \

docker run -it --cap-add=NET_ADMIN --cap-add=NET_RAW iptables-ubuntu /bin/bash \
git clone https://github.com/thomastli/iptables-cpp.git \
cd iptables-cpp \
sudo ./build.sh

### Local builds

git clone https://github.com/thomastli/iptables-cpp.git \
cd iptables-cpp \
sudo ./build.sh

## Development Notes

### Preferred IDE

Visual Studio Code

### Recommended VS Code extensions

C/C++ IntelliSense (Microsoft) \
https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools

Clang-format (xaver) \
https://marketplace.visualstudio.com/items?itemName=xaver.clang-format

CMake (twxs) \
https://marketplace.visualstudio.com/items?itemName=twxs.cmake

CMake Tools (Microsoft) \
https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools

Doxygen Documentation Generator (Christoph Schlosser) \
https://marketplace.visualstudio.com/items?itemName=cschlosser.doxdocgen

Remote Development (Microsoft) \
https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.vscode-remote-extensionpack
