
rna_prot = {
  "F" => 2,
  "L" => 6,
  "S" => 6,
  "Y" => 2,
  "C" => 2,
  "P" => 4,
  "H" => 2,
  "Q" => 2,
  "R" => 6,
  "I" => 3,
  "T" => 4,
  "N" => 2,
  "K" => 2,
  "V" => 4,
  "A" => 4,
  "D" => 2,
  "E" => 2,
  "G" => 4
}

MILLION = 1000000
STOP = 3

raw = File.read 'rosalind_mrna.txt'
raw.delete!("\n")
raw_arr = raw.split ""

poss = 1

for c in raw_arr
  if rna_prot.has_key?(c)
    poss *= rna_prot[c]
    poss = (poss % MILLION)
  end
end

poss *= STOP
poss = (poss % MILLION)

puts poss
