with open('rosalind_iprb.txt', 'r') as file:
    input_str = file.read()

input_arr = input_str.split(' ')

#############################################
dom_pairs = int(input_arr[0])
hetro_pairs = int(input_arr[1])
res_pairs = int(input_arr[2])

total = dom_pairs + hetro_pairs + res_pairs

dom_offspring = 0
total_offspring = 0

#############################################
parents = []

for i in range(0, res_pairs):
    parents.append('bb')
for i in range(0, hetro_pairs):
    parents.append('Bb')
for i in range(0, dom_pairs):
    parents.append('BB')


for p in range(0, len(parents)):
    for o in range(p + 1, len(parents)):
            total_offspring += 1
            if parents[p] == 'BB' or parents[o] == 'BB':
                dom_offspring += 1
            elif parents[p] == 'Bb' and parents[o] == 'Bb':
                dom_offspring += 0.75
            elif parents[p] == 'Bb' and parents[o] == 'bb':
                dom_offspring += 0.5
            elif parents[p] == 'bb' and parents[o] == 'Bb':
                dom_offspring += 0.5
            elif parents[p] == 'bb' and parents[o] == 'bb':
                dom_offspring += 0
            else:
                print('error, invaild combo')


#############################################
print(dom_offspring)
print('/')
print(total_offspring)
prob = dom_offspring / total_offspring

print(prob)
