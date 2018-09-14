
output_str = ''
output_arr = []

with open("rosalind_revc.txt", "r") as file:
    input_str = file.read()

input_arr = list(input_str)

for i in reversed(input_arr):
    output_arr.append(i)

for i in output_arr:
    if i == 'G':
        output_str = output_str + 'C'
    elif i == 'C':
        output_str = output_str + 'G'
    elif i == 'A':
        output_str = output_str + 'T'
    elif i == 'T':
        output_str = output_str + 'A'

print(output_str)
