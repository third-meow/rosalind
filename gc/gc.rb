raw = File.read 'rosalind_gc.txt'
raw.delete! "\n"
raw_arr = raw.split ">"

labels = []
seqs = []
gc_p = []

for i in raw_arr do
  labels << i[0,13]
  i.slice!(0..12)
  seqs.push(i)
end

labels.shift
seqs.shift

for i in seqs do
  test_case = i.split ""
  temp_gc = 0
  for t in test_case do
    if t == "C" or t == "G"
      temp_gc += 1
    end
  end
  gc_p.push((temp_gc.to_f / i.length.to_f) * 100)
end

max = 0
for i in gc_p do
  if i > max
    max = i
  end
end

max_idx = gc_p.find_index(max)

puts labels[max_idx]
puts gc_p[max_idx]
