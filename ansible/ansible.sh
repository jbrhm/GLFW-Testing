#!/usr/bin/env bash

sudo -v

if [[ ! $(which zsh) =~ /usr/bin/zsh ]]; then
	echo "This script requires ZSH"
	exit 0
fi

ansible-playbook ./dev.yml
