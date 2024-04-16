echo "Enter file name:"
read file_name
echo "Enter starting position:"
read start_pos
echo "Enter ending position:"
read end_pos
echo "Content from position $start_pos to position $end_pos:"
sed -n "$start_pos,${end_pos}p" "$file_name"
