#! /bin/bash

if [ $# -eq 0 ]
then 
    read file
else 
    file=$1
fi
words_stored=0

for word in $(cat $file)
do
found=0
    for(( z=0; z<$words_stored; z++ ))
    do
        if [ "${arr[$z]}" == $word ]
        then
            values[$z]=$((${values[$z]} + 1))
            found=1
        fi
    done

    if [ $found -eq 0 ]
    then 
        arr[$words_stored]=$word
        values[$words_stored]=1
        words_stored=$(($words_stored+1))
    fi
done
echo $words_stored
for(( i=0; i<$words_stored; i++ ))
do
    echo ${arr[$i]} "-" ${values[$i]}
done