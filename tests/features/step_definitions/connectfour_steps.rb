Given /^the input "(.*)"$/ do |arg|
    @input=arg
end

When /^the connectfour program is run$/ do
    @output=`cat #{@input}  | ./connectfour`
    #puts @output
end
    
Then /^the output should be "(.*)"$/ do |correct_output|
    	file = File.open(correct_output, "rb")
	contents = file.read
	file.close
	#puts contents
	raise ('wrong answer!!!!') unless (@output <=> contents) == 0 
end
