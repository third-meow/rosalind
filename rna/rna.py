
output_str = ''

with open("rosalind_rna.txt", "r") as file:
    input_str = file.read()
input_arr = list(input_str)

for i in input_arr:
    if i == 'T':
        i = 'U'
    output_str = output_str + i

print(output_str)
