#swapping first and last character
s=input("Enter a string")
if len(s)<=1:
    result=s
else:
    result=s[-1]+s[1:-1]+s[0]
print("Swapped string=",result)