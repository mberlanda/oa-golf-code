require 'bundler/setup'
require 'benchmark/ips'

# input = [
#   ['O', 'O', 'O', 'O'],
#   ['D', 'O', 'D', 'O'],
#   ['O', 'O', 'O', 'O'],
#   ['X', 'D', 'D', 'O']
# ]
module TreasureIsland
  DIRECTIONS = [[1, 0], [0, 1], [-1, 0], [0, -1]]

  Point = Struct.new(:r, :c)

  def is_safe?(grid, r, c)
    r >= 0 && r < grid.size && c >= 0 && c < grid[0].size && grid[r][c] != 'D'
  end

  def min_steps(grid)
    q = [];
    q << Point.new(0, 0)
    grid[0][0] = 'D'
    steps = 1
    until q.empty?
      sz = q.size
      while sz > 0
        p = q.shift
        DIRECTIONS.each do |(dr, dc)|
          r = p.r + dr
          c = p.c + dc
          if is_safe?(grid, r, c)
            return steps if grid[r][c] == 'X'

            q << Point.new(r, c)
          end
        end
        sz -= 1
      end
      steps += 1
    end
    -1
  end

  def min_steps2(grid)
    n_rows = grid.size
    n_cols = grid[0].size

    f_safe = ->(r, c) { r >= 0 && r < n_rows && c >= 0 && c < n_cols && grid[r][c] != 'D' }

    q = [];
    q << [0, 0]

    grid[0][0] = 'D'
    steps = 1
    until q.empty?
      sz = q.size
      while sz > 0
        pr, pc = q.shift
        DIRECTIONS.each do |(dr, dc)|
          r = pr + dr
          c = pc + dc
          if f_safe.(r, c)
            return steps if grid[r][c] == 'X'

            q << [r, c]
          end
        end
        sz -= 1
      end
      steps += 1
    end
    -1
  end
end
