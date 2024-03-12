echo "Enter the first number:"
read a
echo "Enter the second number:"
read b
a = $((a+b))
b = $((a-b))
a = $((a-b))

echo "After swapping, the numbers are:"
echo "First number: $a"
echo "Second number: $b"