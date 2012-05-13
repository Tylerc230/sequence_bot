task :default  => 'upload'

task :clean do
	%x(ino clean)
end

task :build => [:clean, :build_resources] do
	%x(ino build)
end

task :upload => [:build] do
	%x(ino upload)
end

task :build_resources do
	resource_folder = 'resources'
	c_header_file = 'src/resources.h'
	header_file = File.open c_header_file, 'w'
	Dir.foreach resource_folder do |filename| 
		extension = File.extname filename
		case extension
		when ''#skip '.' and '..'
			next
		when '.html'
			input_file_path = File.join resource_folder, filename
			add_html header_file, input_file_path
		else
			puts 'can\'t handle: ' + filename
		end
		
	end
	header_file.close
end

def add_html output_file, html_path
	minified_html =  %x(java -jar tools/htmlcompressor-1.5.3.jar #{html_path})
	c_var_name = html_path.gsub('.', '_').gsub('/', '_')
	c_resource = "const prog_char #{c_var_name}[] PROGMEM = {\"#{minified_html}\"};"
	output_file.write c_resource
end


