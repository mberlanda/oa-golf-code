num_routers = 10
num_links = 13
links = [
[1, 2], [1, 3], [2, 3],
[3, 4], [4, 5], [4, 6],
[5, 6], [5, 7], [6, 7], [7, 8],
[8, 9], [8, 10], [9, 10],
]

def critical_routers(num_routers, num_links, links)
  h = {}
  result = []
  links.each do |(x, y)|
    h[x] ||= []
    h[x] << y
  end
  puts h.inspect

  keys = h.keys

  (0...keys.size-1).each do |i|
    k, nk = keys[i..i+1]
    node = h[k].sort
    next_node = (h[nk] | [nk]).uniq.sort
    puts node.inspect
    puts next_node.inspect
    puts (next_node - node).size.inspect
    if (next_node - node).any?
      puts "found"
      result << nk
    end
  end
  puts result.inspect
end
critical_routers(num_routers, num_links, links)
