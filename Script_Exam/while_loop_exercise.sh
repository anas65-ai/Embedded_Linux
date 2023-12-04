#! /bin/bash 
echo Please Enter Positive  Number:
read n
if [[ "$n" =~ ^[0-9]+$ ]]; then
  i=1
  while [ $i -le $n ]
  do
    square=$(($i*$i))
    echo The Square of $i is :$square
    i=$(($i+1))
  done
else
  echo "Invalid Input, Please enter a Positive Number"
fi 
