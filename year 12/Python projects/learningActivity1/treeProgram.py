'''**********************************************************************************
* Tree program
*
* Author: Joseph Healy
* Last Updated: 17/10/2023
*
*
**********************************************************************************'''

# Variables for our tree so we can customize them later
treeLeavesWidth = 20
treeLogHeight = 3
treeLogWidth = 3

# Main for loop for printing a tree!
for i in range(2, treeLeavesWidth):
    # Current leaf we are working on!
    currentLeaf = (i)*2 - 1
    if i > 2:
        print(('x'*currentLeaf).center(treeLeavesWidth*2, ' ')) # printing based on 'i' variable
    else:
        print(('x').center(treeLeavesWidth*2, ' ')) # printing the first leaf

for i in range (0, treeLogHeight):
    print(('#'*treeLogWidth).center(treeLeavesWidth*2, ' '))
