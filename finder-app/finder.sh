#!/bin/sh
# Script for assignment 1
# Author: Marco Bettini

filesdir=$1
searchstr=$2


if [ $# -eq 2 ]
then
	if [ -d "$filesdir" ]
	then
		echo "$filesdir is a directory"
	else
		exit 1
	fi
else
	echo "Bad number of parameters"
	exit 1
fi

FILECOUNT="$(find "$filesdir" -type f -printf x | wc -c)"
DIRCOUNT="$(find "$filesdir" -type d -printf x | wc -c)"
FILESMATCH="$(grep -oR "$searchstr" "$filesdir" | wc -l)"

printf "The number of files are %s and the number of matching lines are %s\n" "$FILECOUNT" "$FILESMATCH"
