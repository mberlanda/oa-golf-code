#!/bin/ruby

#
# Complete the runningMedian function below.
# This solution does not pass all test cases
#

class Heap
  attr_accessor :size, :nodes

  def initialize(size: 0, nodes: [])
    @size = size
    @nodes = nodes
  end

  def pop
    @size -= 1
    @nodes.pop()
  end

  def top
      @nodes.last
  end
end

class MinHeap < Heap
  def push(n)
    @nodes = @nodes.push(n).sort { |a, b| b <=> a } #[-3..-1]
    @size += 1
  end
end

class MaxHeap < Heap
  def push(n)
    nodes = @nodes.push(n).sort { |a, b| a <=> b } #[-3..-1]
    @size += 1
  end
end

def balance(heap1, heap2)
  if heap1.size - heap2.size > 1
    heap2.push(heap1.pop)
    return
  end

  if heap2.size - heap1.size > 1
    heap1.push(heap2.pop)
    return
  end
end

def runningMedian(a)
  #
  # Write your code here.
  #
  median = 0
  min_heap = MinHeap.new
  max_heap = MaxHeap.new

  a.map do |n|
    n > median ? min_heap.push(n) : max_heap.push(n)

    balance(min_heap, max_heap)

    if min_heap.size > max_heap.size
      median = min_heap.top.to_f
    elsif max_heap.size > min_heap.size
      median = max_heap.top.to_f
    else
      median = (min_heap.top + max_heap.top) / 2.0
    end
  end
end


fptr = File.open(ENV['OUTPUT_PATH'], 'w')

a_count = gets.to_i

a = Array.new(a_count)

a_count.times do |a_itr|
    a_item = gets.to_i
    a[a_itr] = a_item
end

result = runningMedian a

fptr.write result.join "\n"
fptr.write "\n"

fptr.close()
