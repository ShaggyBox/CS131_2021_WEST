import itertools

#The sides of our dice
dice= [1,2,3,4,5,6]
#number of dice rolled
n = 2
#desired sum from dice rolls
desiredSum = 6

#creates a list of all the possible permutations of two fair dice rolls. 
twoDiePermutations  = list(itertools.product(dice, repeat = n))


print("These are all the posible permutations of two 6 sided dice.")
print(twoDiePermutations)

#list var that will hold all possible permutations of 2  dice that sum to the desired sum
desiredSumPermutations = [] 

#This for look will iterate over all the permutations, sum the first element of the tuple with the second, if equal to desired sum, it will appened it to the desiredSumPermutations list. 
for x in range (0,len(twoDiePermutations)):
    if twoDiePermutations[x][0] + twoDiePermutations[x][1]  == desiredSum:
        desiredSumPermutations.append(twoDiePermutations[x])


print("These are all the possible permuations of two 6 sided dice that will sum to " + str(desiredSum))
print(desiredSumPermutations)

probability = len(desiredSumPermutations)/len(twoDiePermutations)

print("The probablity of rolling a "+ str(desiredSum) +" with two six-sided dice is: " + format(probability,'.4f') + "%")
