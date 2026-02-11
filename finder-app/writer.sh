#!/bin/sh
# Tester script for assignment 1 part 2

writefile=$1
writestr=$2


if [ "${writefile}" = "" ] || [ "${writestr}" = "" ]
then
    echo "Missing argument: <file-to-write> or <string-to-write>"
    exit 1
fi

mkdir -p "$(dirname "${writefile}")" && : > "${writefile}"
echo "${writestr}" > "${writefile}"