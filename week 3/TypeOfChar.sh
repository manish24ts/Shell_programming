echo "Enter a character:"
read char
case "$char" in
[a-z])echo "The character '$char' is lowercase.";;
[A-Z])echo "The character '$char' is Uppercase.";;
[0-9])echo "The character '$char' is a digit.";;
*)echo "The character '$char' is a special character.";;
esac
