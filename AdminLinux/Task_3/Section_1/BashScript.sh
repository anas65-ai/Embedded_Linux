#!/bin/bash	
my_file="${HOME}/.bashrc"

if [[ -f ${my_file} ]]; then
	echo File ${my_file} is Exist.
	export HELLO=${HOSTNAME}
	Local=${USER}
	echo HELLO: ${HELLO}
	echo Local: ${Local}
else
	echo File ${my_file} is Not Exist.
fi

gnome-terminal

