file = open('in.txt', 'rb')
 
while 1:
     
    # read by character
    char = file.read(1)         
    if not char:
        break
         
    print(ord(char))
 
file.close()