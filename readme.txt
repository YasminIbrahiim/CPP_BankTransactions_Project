#######################################################################
This project is divided into 3 parts:
##The Bank side :
It's divided into 3 classes : Bank_server , User , Transaction;

#Bank server : contains the data of all users (each user has his own class)

#User class contains:
1- user name 
2- user Id
3- the amount of saved money
4- All transactions 

#Transaction class contains:
1- date of each transaction
2- withdrawn/ added money of each transaction 
3- type of transaction (add / withdraw)

##The Machine side :
1- the machine should acquire the data from the user 
2- check if the user id and name are valid 
3- if the user wants to withdraw some money it should check that he has enough credit 
4- send all the transaction info to the bank server 

##The card side :
1- it should contain some data such as card expiration date, username , id number , card activation date

