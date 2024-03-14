#! /bin/bash
if [ $# -ne 2 ]
then
    echo "Errore , parms noo corretti"
    exit 1
fi

counter=0
while [ 1 -eq 1 ]
do
    arr=$(ps -el | grep "$1")
    status=$(echo $arr | cut -f9,9 -d " ")
    pid=$(echo $arr | cut -f2,2 -d " ")
    if [ $status == "Z" ]
    then
        counter=$(($counter+1))
    else
        counter=0
    fi
    echo $counter

    if [ $counter -gt 5 ]
    then
        kill -9 $pid
        echo "More than 5 times"
        exit 0
    fi
    sleep $2
done 