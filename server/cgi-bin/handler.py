import cgi 

values = cgi.FieldStorage() 
cxem = values.getfirst("cxem", "none")
output_file = open("out.txt","a")
output_file.write(cxem) 
output_file.close()
