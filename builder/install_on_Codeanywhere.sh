#!/bin/bash -xe

# Install packages
apt-get update && apt-get install -y --no-install-recommends cmake

# Setup timezone
rm /etc/localtime
ln -s /usr/share/zoneinfo/Japan /etc/localtime

# Install Google test
current_dir=${PWD}
git clone --depth=1 -b release-1.8.0 https://github.com/google/googletest.git /usr/src/gtest
cd /usr/src/gtest/
cmake .
make
make install
cd ${current_dir}

# Setup prompt to show git branch
git clone --depth=1 -b v1.9.1 https://github.com/git/git.git /usr/src/git
cat << EOS >> ~cabox/.bashrc
source /usr/src/git/contrib/completion/git-completion.bash
source /usr/src/git/contrib/completion/git-prompt.sh
export PS1='\[\e[32m\]\u@\h\[\e[00m\]:\[\e[34m\]\w\[\e[33m\]\$(__git_ps1 " (%s)")\[\e[00m\]\n\$ '
EOS

# Configure git to use vim as editor
git config --global core.editor vim

# Install pip
curl -s https://bootstrap.pypa.io/get-pip.py -o get-pip.py
python3 get-pip.py
rm get-pip.py

# Install gcovr
pip install gcovr

# Add public key for SSH access
if [ -e public_key ]; then
cat public_key >> ~cabox/.ssh/authorized_keys
cat public_key
git checkout -- public_key
fi
