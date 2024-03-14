#! /bin/bash
if [ $# -ne 3 ]
then 
echo "Error , number of params is not correct"
exit 1
fi

files=$(find $1 -type f)

for file in $files
do
result=$(grep -e $2 -n $file)
if [ "$result" != ""]
then
echo $result >> $3
fi

sort -k1,1 -k2,2n -t ":" $3  > $3
done 