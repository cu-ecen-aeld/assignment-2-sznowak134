#!/bin/sh
# Tester script for assignment 1 part 1

filesdir=$1
searchstr=$2

helpmsg="Usage: $0 <directory> <search-string>"

if [ ! -d "$filesdir" ]
then
    echo "Directory $filesdir does not exist, provide a valid directory"
    exit 1
fi

numfiles=$(ls -1q "$filesdir"/* 2>/dev/null | wc -l)
totalmatches=0

for file in "$filesdir"/*
do
    if [ -f "$file" ]
    then
        nummatches=$(grep -c "$searchstr" "$file" || true)
        if [ "$nummatches" -gt 0 ]
        then
            totalmatches=$((totalmatches + nummatches))
        fi
    fi
done

echo "The number of files are $numfiles and the number of matching lines are $totalmatches"
exit 0