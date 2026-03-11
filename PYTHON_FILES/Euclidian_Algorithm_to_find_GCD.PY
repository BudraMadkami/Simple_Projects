#Iterative Version (to find gcd)
#________________________________

def Iterative_gcd(a,b):
    while b!=0:
        a,b= b,a%b
    return a
user1 = int(input("Enter first number:"))
user2 = int(input("Enter second number:"))
print(Iterative_gcd(user1,user2)) 

#####################################################
# By using inbuilt function(To find gcd)
#____________________________________________________
import math
print("Second :",math.gcd(48,18))

#######################################################
#Recursive way (to find gcd)
#______________________________________________________

def Recursive_gcd(a,b):
    if b==0:
        return a 
    return Recursive_gcd(b,a%b)
user1 = int(input("Enter first number:"))
user2 = int(input("Enter second number:"))
print(Recursive_gcd(user1,user2))
