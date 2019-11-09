logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]

# @param {String[]} logs
# @return {String[]}
def reorder_log_files(logs)
  s = []
  n = []

  logs.each do |log|
    if log =~ /\s[\s\d]+/
      n << log
    else
      k, _, v = log.partition(' ')
      s << [k, v]
    end
  end

  s.sort { |(a, b), (c, d)| [b, a] <=> [d, c] }.map { |el| el.join(' ') } | n
end
