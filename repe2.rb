a = [2, 10, 4, 10, 4, 10, 4]
n = 10

left = 0
right = 0
array_left = []
array_right = []

j = 0
k = a.length - 1
while j < a.length

  if a[j] != n
    left += 1
  end

  array_left << left

  if a[k] != n
    right += 1
  end

  array_right << right

  j += 1
  k -= 1
end

i = 0
k = array_left.length - 1
final = -1
while i < array_left.length
  if array_left[i] == array_right[k] && (array_right[k] != 0 && array_left[i] != 0)
    final = i
    break
  end

  i += 1
  k -= 1
end

puts array_left.inspect
puts array_right.reverse.inspect
puts final
