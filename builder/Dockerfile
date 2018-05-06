FROM debian:stable

MAINTAINER haessal@mizutamauki.net

ENV DEBCONF_NOWARNINGS yes

WORKDIR /root

# Install packages
RUN \
  apt-get update && apt-get upgrade -y && \
  apt-get install -y --no-install-recommends gcc g++ make cmake && \
  apt-get install -y git

# Install Google test
RUN \
  git clone --depth=1 -b release-1.8.0 https://github.com/google/googletest.git /usr/src/gtest
RUN \
  cd /usr/src/gtest/ && cmake . && make && make install
