HIGHLIGHTS:

This project has been a challenge, i've struggled the first day trying to remember c++ and understanding how i should start coding.
The second day, i began to write the base code with the clases (the basic ones), implemented the game cylcle and coded basic operations like Look and Go.
From here, this exercise started to be more challenging, making me think about the requirements to implement a new feature. 
Note: I have been outside the country for familiar reasons (worked 4/7 days).


This project is not finished and can be improved by:
	END -> We should detect the end condition and print it to the player, right now its just a Room description.
	Walking npc -> The Turn function inside of NPC is ready for that objective. We also are missing the Clock cycle in the game.
		       Also, it could be expanded to the npc going to certain places when player interacted with some item 
		       For example: You cant go to TV room until you cut the light. With no lights the NPC walks down the stairs to the basement to fix the issue (X Turns).
	Double Exits -> Now we have two elements exits for a one connection between rooms
	User input -> We are saving twice the input commands, once directly from user and the second one with the commands ready to be treated (ParseAction function)
	Item contains -> We should restric which item can be contained to avoid non-logical things like a Car being stored in your pocket.
	Item generate -> When picked up an item, it can generate a second one. This should be changed with states, and it should be implemented with Entities instead
			 of items, so we can have , for example, a Cockroach appearing under the doorMat (Creature).
	Etc, etc.

	
ACTIONS:

go *direction* : The current room will have any number of exits (1..n), you should type the direction to walk towards it.
look *element* : This will print in console the name and the description of that, and if it contains something, it will be printed too.
pick *item* / drop *item*: This will change the father of the near *item* (near = same room) that could be picked up.
intentory : Displays the items inside your bag.
pick *item1* *item2* : This will search the item2 inside item1, when found, will put it in your bag.
put *item1* *item2*  : This will search the items in your surroundings (your bag included), when found, will put item2 inside item1.
use *item1* *item2*  : If items exists within same space, it will try to combine them (it will generate a 3rd item if the combination is possible).
lock *direction* : This will lock the exit (If something is required to do this, it will print the condition).
unlock *direction* : Same as lock.
exit : Close the game.


MAP PLAN:

[FREEDOM] END
    \
  (Requires: WALLET)
      \
    [STREET]
        \
START [FRONT] ----------------------\
	  \ 			     \
       (Requires: KEY)		      \
            \			    [GARDEN]
           [HALL]		        \ 
   	      \		  (Requires: Broken electric post) 
	       \                          \
               [TV] ---[NOT IMPLEMENTED]---\
                 \
                [BASEMENT]


GAME GUIDE:

A) PUZZLE PLAN:

        1) Front Door
		Once in the front door, pick Doormat and it will make appear a Key, pick the Key and unlock the door at North.
	2) Pick the Wallet
		Go North until you reach the TV room, you will find a closet and a Wallet inside it. Pick the Wallet.
	4) Go back to your car
		Go South until you reach your Car (South), unlock the car with the Wallet and.. you won the game!

	pick Doormat, pick Key, unlock North, go North, go North, pick Closet Wallet, go South, go South, go South, unlock South, go South, exit

B) ALTERNATIVE PLAN (Not fininshed):

	1B) Front Door
		Go to the garden (West) and use the Bucket with the Fountain, you will now have a bucket filled with water
	2B) Cut the lights
		Once you have the bucket, go to the Street and use the bucket with the Post. It will cut the light of the house
	3B) [Not implemented] Sneak through the window
		With no lighting power, the window from the garden is open, go inside pick your Wallet from the Closet.
	4B) Go back to your car
		Get out from the house through the window, get to your Car (South), unlock the car with the Wallet and.. you won the game!

	go West, use Bucket Fountain, go East, go South, use Bucket Pole, go North, go West, go West, pick Closet Wallet, go East, go East, go South, unlock South, go South, exit
