# Radix Sort

A-
0- targeted array the array which wanted to be sorted
1- in 123 place value is the hundred is 100 tens is 20 ones is 3
2- positional 1 is first digit 2 is second , 3 is third
4- also 1 is most significant digit 3 is last significant digit
5- LSD Least Significant Digit
6- MSD Most Significant Digit

    B -	Max Int Length

in Radix Sort in case sorting array of integers
1- get maximum integer in array
2- get length of that number
3- all integers in array must have same length of maximum integer
3.1 in order to do that , make all most significant digit of all integers less than to maximum integer is 0
for example if 825 is max int in array number like 15 which is to digit length will be 015 and 1 => 001
so all digit have sane length of of max int 825 which is 3
C - Passes && Buckets
but all number in array in buckets , which is array have length of max integer value
1- pass1 "number of bases is = max int length"
sort integer in buckets according starting fom lest significant digit in each integer in targeted array to
corresponding bucket index
for previous example max int was 825 length is 3 LSD 5 , 825 set to index 5, in bucket array
