# PIC10CHW1

<p>
	This homework is a simulation of a card game called &nbsp;'siete y medio' (seven and a half), which is similar to the game Blackjack, and the user will play the player against the dealer.
</p>
<p>
	The goal of the game is to get cards whose total value comes the closest to 71/2 without going over it. Getting a card total over 71/2 is called &quot;busting&quot;.&nbsp;<br />
	
</p>
<p>
	When a player makes a bet against the dealer. There are 4 possible outcomes:<br />
	<br />
	----The player comes closer to 71/2 than the dealer or the dealer busts but the player did not bust.&nbsp;In this case the player wins the round and the player's money increases by the amount that was bet.<br />
	----The dealer comes closer to 71/2 than the player, or the player busts.&nbsp;In this case the player loses the round and the player's money decreases by the amount that was bet.<br />
	----Both, the player and dealer bust.&nbsp;In this case the player loses the round and the player's money decreases by the amount that was bet.&nbsp;This is called house advantage.&nbsp;<br />
	----Both the player and the dealer have the same total and &nbsp;they do not bust.&nbsp;In this case a tie is declared and no money is exchanged.<br />
	
</p>
<p>
</p>
<h4 style="box-sizing: border-box; font-family: Lato, 'Helvetica Neue', Helvetica, Arial, sans-serif; font-weight: 500; line-height: 1.1; color: rgb(68, 68, 68); margin-top: 10px; margin-bottom: 10px; font-size: 18px;">
	<span style="box-sizing: border-box; font-size: 14px; line-height: 15.3999996185303px; color: inherit; font-family: inherit;">At each round of play the player places a bet. After that, the player and the dealer each draw one card from the deck.The player is then repeatedly asked if another card is wanted. The player can continue to draw cards while the total is less than 7<span style="box-sizing: border-box; vertical-align: baseline; font-size: 10.5px; line-height: 0; position: relative; top: -0.5em;">1</span>/<span style="box-sizing: border-box; vertical-align: baseline; font-size: 10.5px; line-height: 0; position: relative; bottom: -0.25em;">2</span>. After the player's turn is over, the dealer's cards are shown. The dealer's play is always the same: the dealer continues to draw cards only if the total is less than 5<span style="box-sizing: border-box; vertical-align: baseline; font-size: 10.5px; line-height: 0; position: relative; top: -0.5em;">1</span>/<span style="box-sizing: border-box; vertical-align: baseline; font-size: 10.5px; line-height: 0; position: relative; bottom: -0.25em;">2</span>.</span>
</h4>
<br />

<p>
</p>
<p>
	Three class: Card class representing each card and storing the rank and value of the cards, and Player class representing the player and storing the money of the player, and the Hand class representing the hands of the dealer and player.
</p>
<p>
	To play, just download the source code and compile. The simulation will also generate a log file recording the game process, with the player starting with 100 dollars. The actual log file is in this repo named &quot;log.txt&quot;.
</p>
