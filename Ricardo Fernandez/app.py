import itertools

#The sides of our dice
dice= [1,2,3,4,5,6]
#number of dice rolled
n = 2
#desired roll from dice rolls
desiredRoll = 6

#creating the Sample Space of the 2 die by taking the cartisian product.
sampleSpace  = list(itertools.product(dice, repeat = n))

desiredRoll = int(input("The odds of rolling a: "))
print("These are all the posible permutations of two 6 sided dice.")
print(sampleSpace)

#this is a list that will holds the desired subset from the Sample Space.
event = [] 

#This for loop will iterate over the Sample Space, sum the first element of the tuple with the second, if equal to desired roll, it will appened it to the event list. 
for x in range (0,len(sampleSpace)):
    if sampleSpace[x][0] + sampleSpace[x][1]  == desiredRoll:
        event.append(sampleSpace[x])


print("These are all the possible permuations of two six sided dice that will sum to " + str(desiredRoll))
print(event)

#Laplace's definition for the probability of an event.
probability = len(event)/len(sampleSpace)
print("The probablity of rolling a "+ str(desiredRoll) +" with two six-sided dice is: " + format(probability,'.4f') + "%")