# Embarcatech Devcontainer

O objetivo deste container é criar um ambiente de desenvolvimento para raspberry pi pico com vscode e demais ferramentas necessárias.

## Build

docker build --build-arg "HOST_UID=$(id -u)" --build-arg "HOST_GID=$(id -g)" --rm -f "Dockerfile" -t pico-sdk-dev:v1.0.0 .

## Use

docker run -it --rm -p 8080:8080 -v $(pwd):/project pico-sdk-dev:v1.0.0

## TODO

Melhorar a documentação.
