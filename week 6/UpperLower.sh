echo -n "Enter filename"
read fileName
if[!-F $fileName];
then
echo "File doesnt exist"
exit 1
fi
tr '[a-z]' '[A-Z]' < $fileName