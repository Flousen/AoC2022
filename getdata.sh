#!/bin/bash
year=2022
day=$1

cp -r template $day

curl --cookie "$(cat cookie)" https://adventofcode.com/${year}/day/${day}/input > ${day}/final.txt
cd $day

