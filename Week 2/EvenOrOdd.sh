echo "Enter a number:"
read num

# according to note if [`expr $num % 2 == 0`] (here ; isnt needed)
if [ $(($num % 2)) -eq 0 ]; then
    echo "The number is even."
else
    echo "The number is odd."
fi