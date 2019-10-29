def criticalRouters(numRouters, numLinks, links)
    # I have been working for a while on my IDE
    # I really feel unconfortable with this online editor
    # and its autocomplete
    h = {}
    result = []
    links.each do |(x, y)|
        h[x] ||= []
        h[x] << y
    end

    puts h.inspect
    keys = h.keys
    max_i = (keys.size) -1

    is_critical = lambda do |i|
        return false if i == max_i

        k, nk = keys[i-1..i]
        v = h[k].sort
        nv = (h[nk] | [nk]).sort.uniq

        (nv - v).any?
    end

    (1...max_i).each do |i|
        result << keys[i] if is_critical.(i)
    end
    result
end

num_routers = 10
num_links = 13
links = [
[1, 2], [1, 3], [2, 3],
[3, 4], [4, 5], [4, 6],
[5, 6], [5, 7], [6, 7], [7, 8],
[8, 9], [8, 10], [9, 10],
]
print criticalRouters(num_routers, num_links, links)
