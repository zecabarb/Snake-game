# Snake-game
This is a snake game that is played in the windows console that I made as a C++ course project.
The game has a start menu, where the choice options selected from the arrows are presented.
The five options available are: Start, LeaderBoard, Difficulty, Reset, Quit.

The Start option allows you to start the Game. It starts by asking for the Player's name and waits to receive a "click" on one of the keyboard arrows for the snake to start moving (in the direction of the pressed key).
If during the Game the user presses the Home key, he returns to the initial menu and the Player data is not saved in the table.

The LeaderBoard option allows you to view the table of scores, from the highest score to the lowest. This table can be reset.

The Difficulty option allows you to choose the game's difficulty level from the user's choice. Within this option there are three more options, being Easy, Intermediate and Hard.
These options change the snake's speed, with only the Hard option causing the game to end if the snake hits one of the edges.

The Reset option clears the player map as well as the text file that was used as a database.

The Quit option allows you to end the game.

We added additional dependencies to complete the Game with sound files. The library used was Winmm.lib.

The controbutors to this game are myself and: Tiago S., Rosalina M., João S. and Lionel P.
