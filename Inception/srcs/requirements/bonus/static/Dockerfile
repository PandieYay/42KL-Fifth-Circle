FROM debian:buster

#install php and wordpress
RUN apt update && apt upgrade -y

COPY static-setup.sh /tmp
COPY index.html /tmp

CMD ["bash", "/tmp/static-setup.sh"]