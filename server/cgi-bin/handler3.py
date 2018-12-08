
import cgi
  		  
print(Hello CXEM.NET!)		 
values = cgi.FieldStorage()
one = int(values.getfirst("one", 0))
two = int(values.getfirst("two", 0)) 
print(one + two)
