#! /bin/sh
read name_dir

for value in $(ls $name_dir)
do
    mv $name_dir/$value $name_dir/$(echo $value | tr A-Z a-z)
done