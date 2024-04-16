echo "enter the string"
read str
len=${#str}
for (( i=$len-1; i&gt;=0; i-- ))
do
rev="$rev${str:$i:1}"
done
echo "Reverse= $rev"