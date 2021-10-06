FROM debian

MAINTAINER lechapus <lechapus@student.42.fr>

RUN apt-get update && apt-get upgrade -y
RUN apt install -y apt-transport-https ca-certificates wget dirmngr gnupg software-properties-common
RUN wget -qO - https://adoptopenjdk.jfrog.io/adoptopenjdk/api/gpg/key/public | apt-key add -
RUN add-apt-repository --yes https://adoptopenjdk.jfrog.io/adoptopenjdk/deb/
RUN apt update -y
RUN apt install -y adoptopenjdk-8-hotspot
