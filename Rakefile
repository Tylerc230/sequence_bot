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
	resources = []
	Dir.foreach resource_folder do |filename| 
		resource_info = nil
		extension = File.extname filename
		case extension
		when ''#skip '.' and '..'
			next
		when '.html'
			input_file_path = File.join resource_folder, filename
			resource_info = add_html input_file_path
		else
			puts 'can\'t handle: ' + filename
		end
		resources << resource_info
	end
	create_resource_declaration_file resources
	create_resource_map_file resources
end

def add_html html_path
	minified_html =  %x(java -jar tools/htmlcompressor-1.5.3.jar #{html_path})
	add_resource html_path, minified_html
end

def add_resource path, data
	resource_info = Hash.new
	resource_info['path'] = "/" + path
	resource_info['data'] = data
  resource_info['c_var_name'] = path.gsub('.', '_').gsub('/', '_')
	resource_info
end

def create_resource_declaration_file resource_info
  declaration_file = File.open 'src/resource_declarations.h', 'w'
	resource_info.each { |resource|
		data = resource['data']
		c_var_name = resource['c_var_name']
		c_resource_declaration = "const prog_char #{c_var_name}[] PROGMEM = {\"#{data}\"};"
    declaration_file.write c_resource_declaration
	}
  declaration_file.close
end

def create_resource_map_file resource_info
  map_file = File.open 'src/resource_mappings.h', 'w'
  resource_info.each { |resource|
    path = resource['path']
    c_var_name = resource['c_var_name']
    c_resource_mapping = "MAP_RESOURCE(\"#{path}\", #{c_var_name});"
    map_file.write c_resource_mapping
  }
  map_file.close
end



