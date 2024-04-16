echo "Enter the word to delete lines containing:"
read word
echo "Enter the file name:"
read file_name
sed -i "/$word/d" "$file_name"
echo "Lines containing the word '$word' have been deleted from '$file_name'."
