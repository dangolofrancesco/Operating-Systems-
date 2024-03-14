#! /bin/bash
echo -n "Stringa: "
read str
length=$(echo $str | wc -c)

let t=length-1
echo $t