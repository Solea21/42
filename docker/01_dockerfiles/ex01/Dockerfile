FROM debian

MAINTAINER lechapus <lechapus@student.42.fr>

ENV TS3SERVER_LICENSE=accept

RUN apt-get update && apt-get -y upgrade 

RUN apt-get install -y wget bzip2

WORKDIR /opt/teamspeak

RUN wget https://files.teamspeak-services.com/releases/server/3.12.1/teamspeak3-server_linux_amd64-3.12.1.tar.bz2

RUN tar -xvf teamspeak3-server_linux_amd64-3.12.1.tar.bz2

WORKDIR /opt/teamspeak/teamspeak3-server_linux_amd64/

EXPOSE 9987/udp 10011 30033

ENTRYPOINT ["sh", "ts3server_minimal_runscript.sh", "createinifile=1"]
