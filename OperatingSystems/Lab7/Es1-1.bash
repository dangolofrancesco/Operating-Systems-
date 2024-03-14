#! /bin/bash
if [ $# -ne 3 ]
then
echo "Errore"
exit 1
fi

find $1 -type f -exec grep "$2" -n -H \{} \; > $3
sort -k1,1 -k2,2n -t ":" $3 