echo "Files in the current directory with read, write, and execute permissions:"
for file in *
do
    if [ -r "$file" -a -w "$file" -a -x "$file" ];
then
        echo "$file"
    fi
done
