# License-Identifier: (MIT)
# Build
# docker build --build-arg "HOST_UID=$(id -u)" --build-arg "HOST_GID=$(id -g)" --rm -f "Dockerfile" -t pico-sdk-dev:v1.0.1 .
# Use
# docker run -it --rm -p 8080:8080 -v $(pwd):/project pico-sdk-dev:v1.0.1
FROM ubuntu:22.04

LABEL maintainer="SystemsBR"
LABEL version="1.0"
LABEL description="Develpment environment for raspberry pi pico"

ENV DEBIAN_FRONTEND=noninteractive

ENV USER=pico
ENV HOME=/home/${USER}
ENV WORK=/project
ENV PICO_SDK_PATH=${HOME}/sdk/pico-sdk
ENV DEFAULT_WORKSPACE=${WORK}

# Timezone
ENV TZ=Etc/UTC
ENV LANG=en_US.UTF-8
ENV LC_ALL=en_US.UTF-8

ARG HOST_UID=1000
ARG HOST_GID=1000

RUN \
    apt-get update && apt-get -y install --no-install-recommends \
    build-essential \
    cmake \
    cppcheck \
    curl \
    gcc-arm-none-eabi \
    gdb-multiarch \
    git \
    libnewlib-arm-none-eabi \
    libstdc++-arm-none-eabi-newlib \
    locales \
    minicom \
    ninja-build \
    openjdk-18-jre-headless \
    openocd \
    python3 \
    screen \
    software-properties-common \
    sudo \
    tzdata \
    wget \
    && rm -rf /var/lib/apt/lists/*

# AdoptOpenJDK
# https://objects.githubusercontent.com/github-production-release-asset-2e65be/372924883/bfec19f5-8c7d-4fbe-993c-d4ed38a901dd?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=releaseassetproduction%2F20241201%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20241201T174752Z&X-Amz-Expires=300&X-Amz-Signature=bd9e04a04616d79fa471bc53d2ac130153f90db3fd4154f7ef6279f06e443a4c&X-Amz-SignedHeaders=host&response-content-disposition=attachment%3B%20filename%3DOpenJDK11U-jre_aarch64_linux_hotspot_11.0.25_9.tar.gz&response-content-type=application%2Foctet-stream

# Instalar o VS Code Server
RUN wget -qO- https://code-server.dev/install.sh | bash 

# Instala extensoes do VS Code
RUN code-server --install-extension twxs.cmake
RUN code-server --install-extension ms-vscode.cmake-tools
RUN code-server --install-extension raspberry-pi.raspberry-pi-pico
#    sonarsource.sonarlint-vscode
#    ms-vscode.cpptools 

RUN \
    ln -fs /usr/share/zoneinfo/Etc/UTC /etc/localtime && \
    echo "Etc/UTC" > /etc/timezone && \
    dpkg-reconfigure -f noninteractive tzdata && \
    locale-gen en_US.UTF-8

RUN \
    groupadd -g ${HOST_GID} ${USER} && \
    useradd -g ${HOST_GID} -m -s /bin/bash -u ${HOST_UID} ${USER} && \
    echo "${USER} ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/${USER} && \
    chmod 0440 /etc/sudoers.d/${USER}

RUN usermod -aG sudo ${USER} 

# Setup passwords
RUN echo "root:rootpass" > /root/passwdfile
RUN echo "${USER}:picopass" >> /root/passwdfile
RUN chpasswd -c SHA512 < /root/passwdfile && \
    rm /root/passwdfile

#RUN \
#    git config --global color.ui false && \
#    git config --global http.sslverify false

RUN mkdir -p ${PICO_SDK_PATH} && git clone https://github.com/raspberrypi/pico-sdk ${PICO_SDK_PATH}

USER ${USER}

WORKDIR ${WORK}
EXPOSE 8080
CMD ["code-server", "--bind-addr", "0.0.0.0:8080", "--auth", "none"]
