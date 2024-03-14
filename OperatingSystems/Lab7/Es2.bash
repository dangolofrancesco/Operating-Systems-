#! /bin/bash
read filename
lines=$(cat $filename)
let start=0
echo $lines

for line in $lines
do
if [ $(echo $line | wc -c) -gt $start ]
then
    start=$(echo $line | wc -c)
    max=$line
fi 
done
echo 
echo
printf "Linea più lunga %s : %d\n" "$max" $start
printf "Num linee file: %d\n" $(wc -l $filename | tr -s " " | cut -d " " -f2)


