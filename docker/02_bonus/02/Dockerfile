FROM debian

MAINTAINER lechapus <lechapus@student.42.fr>

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y build-essential python3.7 python3-pip
RUN pip3 install jupyter
CMD ["jupyter", "notebook", "--port=8888", "--no-browser", "--ip=0.0.0.0", "--allow-root"]
