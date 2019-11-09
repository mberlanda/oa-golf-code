require 'bundler/setup'
require 'benchmark/ips'
require 'benchmark/memory'

require_relative 'treasure_island'

extend TreasureIsland

input = [
  ['O', 'O', 'O', 'O'],
  ['D', 'O', 'D', 'O'],
  ['O', 'O', 'O', 'O'],
  ['X', 'D', 'D', 'O']
]

benchmark_options = { time: 10, warmup: 5 }

Benchmark.ips do |x|
  x.config(benchmark_options)

  x.report 'original implementation' do
    min_steps(input)
  end
  x.report 'compact implementation' do
    min_steps2(input)
  end
  x.compare!
end

Benchmark.memory do |x|
  x.report 'original implementation' do
    min_steps(input)
  end
  x.report 'compact implementation' do
    min_steps2(input)
  end
  x.compare!
end
# Warming up --------------------------------------
# original implementation
#                          5.796k i/100ms
# compact implementation
#                          7.314k i/100ms
# Calculating -------------------------------------
# original implementation
#                          60.628k (± 6.2%) i/s -    608.580k in  10.082608s
# compact implementation
#                          73.980k (± 6.0%) i/s -    738.714k in  10.023827s

# Comparison:
# compact implementation:    73980.5 i/s
# original implementation:    60628.2 i/s - 1.22x  slower
