#! /bin/bash
if [ $# -ne 1 ]
then 
    echo "errore"
    exit 1
fi
let s=0;
let count=0;
while read stringa
do
    array=($stringa)
    let count=$count+${#array[$s]}
    let s=$s+1
done < $1

echo $count