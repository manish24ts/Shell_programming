echo "Enter a number:"
read number
reversed_number=0
while [ $number -gt 0 ]
do
    remainder=$((number % 10))
    reversed_number=$((reversed_number * 10 + remainder))
    number=$((number / 10))
done
echo "Reversed number is $reversed_number"