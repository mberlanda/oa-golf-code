def numberAmazonTreasureTrucks(rows, column, grid)
    # diagonal moves are not part of the same block
    directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]
    # check if move is valid and within the matrix
    valid = ->(r, c) { r >= 0 && r < rows && c >= 0 && c < column && grid[r][c] == 1 }

    check_block = lambda do |r, c|
        directions.each do |(dr, dc)|
            pr = r + dr
            pc = c + dc
            puts "dir"
            puts [pr,pc].inspect
            if valid.(pr, pc)
                puts "valid"
                puts [pr,pc].inspect
                grid[pr][pc] = 0
                check_block.(pr, pc)
            end
        end
    end


    sum = 0

    (0...rows).each do |r|
        (0...column).each do |c|
            next if grid[r][c] == 0
            puts [r,c].inspect
            sum += 1
            grid[r][c] = 0
            check_block.(r, c)
        end
    end
    sum
end

rows = 4
columns = 4
grid = [
 [1,1,0,0],
 [0,0,0,0],
 [0,0,1,1],
 [0,0,0,0]
]

puts numberAmazonTreasureTrucks(rows, columns, grid)
