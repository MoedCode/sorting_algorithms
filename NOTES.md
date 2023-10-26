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
put all number in array in buckets , which is array have length of 10 since with decimal numbers , fom 0 - 9 so buckets array will be same

1- pass1 "number of bases is = max int length"
sort integer in buckets according starting fom lest significant digit in each integer in targeted array to
corresponding bucket index
for previous example :
pass 1-max int was 825 length is 3 LSD 5 , 825 set to index 5, in bucket array
pass 2- second number after LSD 2 , 825 set to index 5, in bucket array
pass 3- third number after LSD 2 , 825 set to index 5, in bucket array
and the same for rest of array
{[0]=7, [1]=5, [2]=33, [3]=99, [4]=5} max number is 99 length is 2 since all number in array must have same length
so in pass 1
{[0]=07, [1]=05, [2]=33, [3]=99, [4]=05}
bucket array
after all index's in array become in the same length we loop over ll array element
and increment each index in bucket array if it corresponding to the LSD in
array of numbers for ex [3] = 99 LSD is 9 increment bucket array [9]
which is =0 by 1 so it will be [9] = 1, in [5] will be = 2
cause there are tow digit LSD = 5 [1] = 05, [4] = 05
numbers like if it was exist in array 45, 65, 85 will hve same LSD which is also 5
{[0]= 0,[1]= 0,[2]= 0,[3]= 1,[4]= 0,[5]=2 ,[6]=0,[7]=1,[8]=0,[9]=1}
