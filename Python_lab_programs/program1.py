#replacing first character with $ except first character
str1=input("enter string")
first_char=str1[0]
result=first_char+str1[1:].replace(first_char,'$')
print('Modified string:',result)