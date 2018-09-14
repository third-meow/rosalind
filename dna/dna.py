
g = 0
t = 0
c = 0
a = 0


with open("rosalind_dna.txt", "r+") as file:
    input_str = file.read()

input_arr = list(input_str)
for nuc in input_arr:
    if nuc == 'G':
        g += 1
    elif nuc == 'T':
        t += 1
    elif nuc == 'A':
        a += 1
    elif nuc == 'C':
        c += 1

print(str(a)+' '+str(c)+' '+str(g)+' '+str(t))
