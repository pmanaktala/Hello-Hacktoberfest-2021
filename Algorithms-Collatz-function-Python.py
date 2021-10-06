""" 
The Collatz conjecture is a conjecture in mathematics that concerns sequences defined as follows: start with any positive integer n. 
Then each term is obtained from the previous term as follows: 
if the previous term is even, the next term is one half of the previous term.
-Wikipidia- 
"""


def collatz(number):
  if number % 2 ==0: 
    answer = number //2
  else: 
    answer = 3 *number + 1
  
  print(answer)
  return answer 

while True: 
  try: 
    result = int (input("Enter a number: "))
  except ValueError:
    print("That's not a number.Try again")
    continue
    

  while result != 1: 
    result = collatz(result)
  quit = input("Do you want to continue? y / n ")
  if quit == 'n': 
    break
