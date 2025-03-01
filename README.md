# Memory-Game
C++ - CIS22B A1

This is a console based Memory game. 
We start by accepting the name of the player before the game beings, at the start we will display the grid with it's coordinates filled out. The player will enter the coordinates of 2 cards to flip them. The program will then show you the grid with the numbers specified at the entered coordinates. If the numbers matched then the numnbers stay flipped on the grid for the rest of the game. If not they are flipped back and the user is asked for another two coordinates. 
After each turn if the user wants to quit midway they can just enter q and the game will end. 
The game will end if all the numbers are matched or if the user quits before that. 
After the code ends the outcome of the game is recorded in a txt file called "output.txt". If the user quits, it will say: "<name_entered> don’t give up!". If the user completes the game it will record the number of turns it took to complete the game. 

#Sample Output
Output:
Welcome to my game!
Please enter your full name: 
jake peralta
Find all the matching pairs on the board!
    0 1 2 3
   =========
0 | * * * * |
1 | * * * * |
2 | * * * * |
3 | * * * * |
   =========
Press q to quit
Enter x and y position of the first card 0 0
Enter x and y position of the second card: 0 2
No match. Try again!
    0 1 2 3
   =========
0 | 6 * 8 * |
1 | * * * * |
2 | * * * * |
3 | * * * * |
   =========
    0 1 2 3
   =========
0 | * * * * |
1 | * * * * |
2 | * * * * |
3 | * * * * |
   =========
Press q to quit
Enter x and y position of the first card 1 2
Enter x and y position of the second card: 2 2
No match. Try again!
    0 1 2 3
   =========
0 | * * * * |
1 | * * 8 * |
2 | * * 5 * |
3 | * * * * |
   =========
    0 1 2 3
   =========
0 | * * * * |
1 | * * * * |
2 | * * * * |
3 | * * * * |
   =========
Press q to quit
Enter x and y position of the first card 0 1
Enter x and y position of the second card: 03
0
No match. Try again!
    0 1 2 3
   =========
0 | * 3 * * |
1 | * * * * |
2 | * * * * |
3 | 7 * * * |
   =========
    0 1 2 3
   =========
0 | * * * * |
1 | * * * * |
2 | * * * * |
3 | * * * * |
   =========
Press q to quit
Enter x and y position of the first card q
Thanks for playing!!!
