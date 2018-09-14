raw = File.read 'rosalind_iev.txt'
raw.delete! "\n"
raw_arr = raw.split " "
int_arr = []
for r in raw_arr do
  int_arr.push(r.to_i())
end

dom_offspring = 0.0
for p in 0..int_arr.length do
  if p == 0 or p == 1 or p == 2
    dom_offspring += 2 * int_arr[p]
  elsif p == 3
    dom_offspring += 1.5 * int_arr[p]
  elsif p == 4
    dom_offspring += 1 * int_arr[p]
  end
end
puts dom_offspring
