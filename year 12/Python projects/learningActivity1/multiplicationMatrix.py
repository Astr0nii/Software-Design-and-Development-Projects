'''**********************************************************************************
* Multiplication Table Matrix program
*
* Author: Joseph Healy
* Last Updated: 16/10/2023
*
*
**********************************************************************************'''

# Current row we are printing, number of rows to print, number of columns to print
currentRow = 1 
currentColumn = 1
numberOfRows = 12
numberOfColumns = 12
width = 5

''' 
Main loop, we need to have our max value +1 of our actual
value due to how pre-test loops work.
'''
while (currentRow < numberOfRows+1):
    for currentColumn in range (1, numberOfColumns+1):
        ''' 
        convert our number to a string, left justify it and 
        set the width to 4, replacing unused space with a blank character: ' ',
        and prevent the print from creating a new line (end='')
        '''
        print(str(currentRow*currentColumn).ljust(4, ' '), end=' ')
    print('\n') # new line after printing the row
    currentRow += 1

