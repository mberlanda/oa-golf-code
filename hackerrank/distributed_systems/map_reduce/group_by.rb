# https://www.hackerrank.com/challenges/map-reduce-tutorials-2-the-group-by-operator/problem

require 'json'

class MapReduce

  def initialize
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
      warn "Parsing the following Key-Value Pair and passing it to the Mapper function:#{data}"
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
  state = record["key"]
  city = record["value"]
  mapred.emitIntermediate(state, city)
end

def reducer(mapred,key,list_of_values)
  list_of_cities = list_of_values.sort.join(',')
  resultPair = Pair.new(key,list_of_cities)
  mapred.emit(resultPair)
end

inputData = []
while line = gets()
  state, city = line.strip.split("\t")
  inputData += [{"key"=>state,"value"=>city}.to_json]
end
@mapred = MapReduce.new()
@mapred.execute(inputData,method(:mapper),method(:reducer))


