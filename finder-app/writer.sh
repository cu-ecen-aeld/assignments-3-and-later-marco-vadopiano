#!/bin/sh
echo "Number of parameters = "$#
echo "Program name = "$0
echo "Parameters = "$*

# Check if the correct number of arguments are provided
if [ $# != 2 ]
then
    echo "Bad number of parameters"
    exit 1
fi

writefile=$1
writestr=$2

# Create the directory path if it doesn't exist
mkdir -p "$(dirname $writefile)"

# Write the string to the file, overwriting if it exists
echo $writestr > $writefile

# Check if the file was created successfully
if [ $? -ne 0 ]
then
    echo "Error: Could not create file " $writefile
    exit 1
fi

echo "File " $writefile " created successfully with content: " $writestr
