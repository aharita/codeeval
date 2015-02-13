require 'pry'

parameter = 'DATABASE_CONFIG'

# IO.foreach("comandos.txt") do |x|
#   if x.include? parameter
#     puts "#{x.split('=')[1]}/XXX".gsub("\n", '')
#     break;
#   end
# end

binding.pry

IO.foreach("comandos.txt") { |x| puts "#{x.split('=')[1]}/XXX".gsub("\n", '');break if x.include? parameter }
