#!/bin/sh

if [$1 == ""]
then
	OUTPUT_NAME="main"
else
	OUTPUT_NAME=$1
fi

gcc main.c -o $OUTPUT_NAME -I/usr/include/SDL2 -lSDL2main -lSDL2 && ./$OUTPUT_NAME
