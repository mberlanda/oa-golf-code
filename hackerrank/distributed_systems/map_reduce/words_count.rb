# https://www.hackerrank.com/challenges/map-reduce-tutorials-1-word-counts/problem
require 'json'

class MapReduce

  def initialize
      warn "Intermediate"
      @intermediate = Hash.new{|x,y|x[y]=Array.new}
      @finalResult = []
  end

  def emitIntermediate(key, value)
      @intermediate[key] += [value]
  end

  def emit(value)
      @finalResult += [value]
  end

  def execute(data, mapper, reducer)
      data.each do |line|
        record = JSON.parse(line)
        mapper(self,record)
      end

      @intermediate.keys.each do |key|
        reducer(self,key,@intermediate[key])
      end


      @finalResult.each do |item|
        outputMap = Hash.new
        outputMap["key"] = item.key
        outputMap["value"] = item.value
        puts outputMap.to_json
      end
  end
end

class Pair
    attr_accessor :key, :value

    def initialize(key,value)
        @key = key
        @value = value
    end
end

def mapper(mapred,record)
  key = record["key"]
  value = record["value"]
  words = value.split(/\s/)
  words.each do |word|
    mapred.emitIntermediate(word, 1)
  end
end

def reducer(mapred,key,list_of_values)
    total = list_of_values.reduce(:+)
    resultPair = Pair.new(key,total)
    mapred.emit(resultPair)
end

inputData = []
counter = 0
while line = gets()
    inputData += [{"key"=>counter,"value"=>line.strip}.to_json]
    counter += 1
end
@mapred = MapReduce.new()
@mapred.execute(inputData,method(:mapper),method(:reducer))
