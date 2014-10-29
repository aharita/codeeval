a = [1, 10, 10, 10, 2]
n = 10
rep_left = []
rep_right = []
counter = 0

a.each_with_index do |value, index|

  # get left reps
  counter = 0
  i = 0
  while i < index
    if a[i] != n
      counter += 1
    end
    i += 1
  end
  rep_left << counter
  #puts "left: #{counter}"

  # get right reps
  counter = 0
  i = index + 1
  while i < a.length
    if a[i] != n
      counter += 1
    end
    i += 1
  end
  rep_right << counter
  #puts "right: #{counter}"
end

k = -1
i = 0
while i < rep_left.length
  if rep_left[i] == rep_right[i] && (rep_left[i] != 0 && rep_right[i] != 0)
    k = i
    break
  end
  i += 1
end

puts k
