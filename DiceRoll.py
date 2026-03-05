#PLAY GAME WITH COMPUTER
#Competiton with points ,
#Who ever ha smore points will win the game.
import random
import time as t

user_points = 0
computer_points = 0

def roll_dice():
    dice_number = random.randint(1, 6)
    return dice_number

print("===== Welcome to Dice Rolling Simulator =====")
while 1:
     choice = input("Do you wanna roll a dice (y/n)")
     if 'y' in choice.lower():
         while 1:
            print ("How many rounds  do you wanna play with me ?")
            Rounds = int(input("Enter your number:\n")) 
            for _ in range(Rounds):
                while 1:
                    print("Now ,Your time to roll the Dice")
                    Users_dice_roll = input("Say ,yes to roll your dice [ type(y) ]:")
                    if 'y' in Users_dice_roll.lower(): 
                        print("Rolling dice...")
                        t.sleep(2)
                        number = roll_dice()
                        User_points += number
                        print("Dice has the number:", number)
                        break
                    else:
                        print("Sorry! \n You entered invalid \n Type again . ")
                        
                while 1:
                    print("Now ,Computer's time to roll the dice." )             
                    print("Rolling dice.....")
                    t.sleep(2)
                    number = roll_dice()
                    computer_points += number
                    print("Dice has the number:", number)
                    break
            
            print("Now it's the time to show the points ")
            print ("Your points :\n",User_points,"\n Computer's points :\n",computer_points)
         break
        
     elif 'n' in choice.lower():
        print('Exiting...')
        break
     else:
        print("Invalid input...please try again")
    
            
    
   
     
     
