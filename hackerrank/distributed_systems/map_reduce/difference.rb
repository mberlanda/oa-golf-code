# https://www.hackerrank.com/challenges/relational-mapreduce-patterns-3-difference/problem

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

	# Return an array of JSONs
	def execute(data, mapper, reducer)
		outputJsons = []
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
			outputJsons += [outputMap.to_json]
		end
		return outputJsons
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
	mapred.emitIntermediate(key,value)
end

# Given two sets of integers, R and S select and display the difference, R - S.
def reducer(mapred,key,list_of_values)
  # Fill up the question mark below to complete the Reducer function
	if (list_of_values.uniq == %w(R))
		resultPair = Pair.new(key,key)
		mapred.emit(resultPair)
	end
end

inputData = []
counter = 0
Nr, Ns = gets().strip.split(" ").map{|x|x.to_i}
# The values over here are the names of the sets from which the elements were found (R or S)
(1..Nr).each do |num|
	inputData += [{"value"=>"R","key"=>gets().strip}.to_json]
end
(1..Ns).each do |num|
	inputData += [{"value"=>"S","key"=>gets().strip}.to_json]
end
@mapred = MapReduce.new()
outputJsons = @mapred.execute(inputData,method(:mapper),method(:reducer))
outputJsons.each do |json|
	puts JSON.parse(json)["value"]
end
