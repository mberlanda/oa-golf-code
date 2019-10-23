movie_durations = [90, 85, 75, 60, 120, 150, 125]
d = 250
k = 30

def find_pair(movie_durations, d, k)
  max_duration = d - k
  max_sum = 0
  # Two variants with values or indexes
  max_pair = nil
  max_pair_idx = nil

  movie_durations = movie_durations.each_with_index.sort
  # => [[60, 3], [75, 2], [85, 1], [90, 0], [120, 4], [125, 6], [150, 5]]
  while true do
    x, i = movie_durations.pop

    # This should never happen
    break if movie_durations.empty?

    # Since the list is sorted, we can break if the highest
    # value is less than the half of the current max_sum
    break if x < max_sum / 2

    movie_durations.each do |y, j|
      s = x + y
      break if s > max_duration

      if s > max_sum
        puts s
        max_sum = s
        max_pair = [x, y]
        max_pair_idx = [i, j]
      end

      # Since the list is sorted, the first optimal solution
      # is the best available
      break if s == max_duration
    end
  end

  [max_sum, max_pair, max_pair_idx]
end

puts find_pair(movie_durations, d, k).inspect
