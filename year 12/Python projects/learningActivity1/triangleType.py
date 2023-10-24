'''**********************************************************************************
* Triangle Type program
*
* Author: Joseph Healy
* Last Updated: 16/10/2023
*
*
**********************************************************************************'''

def getTriangleType(triangleValues):
      if triangleValues[0] == triangleValues[1] and triangleValues[1] == triangleValues[2]:
            print("Your triangle is an equilateral type!")
            print("It has 3 equal interior angles of 60 degrees")
      else:
            if triangleValues[0] != triangleValues[1] and triangleValues[0] != triangleValues[2] and triangleValues[1] != triangleValues[2]:
                  print("Your triangle is an scalene type!")
            else:
                  print("Your triangle is an isosceles type!")

# Confirming the triangle
def confirmTriangle(triangleValues):
      print("Side 1: ", triangleValues[0])
      print("Side 2: ", triangleValues[1])
      print("Side 3: ", triangleValues[2])
      print("Please confirm if this triangle is your preferred triangle (Y/N): ")
      userChoice = (input()).lower()
      if userChoice != 'y':
            print("Triangle discard, let us start anew!")
            grabTriangle()
      else:
            print("Let us learn some quick fun facts about your triangle")
            getTriangleType(triangleValues)

# Grabs the triangle of our users choice
def grabTriangle():
      print("Enter the three sides of your triangle (each number must be followed by a space)", '\n'
      "An example may be: 3 3.141592 90. Please input your three values (followed by the return key):")
      # Catch nefarious program busters in the act!
      try:
            triangleValues = [float(input()), float(input()), float(input())]
      except ValueError:
            grabTriangle()
      print(triangleValues)
      confirmTriangle(triangleValues)

def main():
      grabTriangle()

# Run the main-line
main()
