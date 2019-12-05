#!/bin/bash
# Moves scriptfolder from one computer to another
helpFunction()
{
   echo ""
   echo "Sends or receive scripts using scp"
   echo "Usage: $0 [to|from] User Hostname"
   echo "Example - Fetch from nuc : $0 from nuc NUC"
   echo "Example - Send to TX2    : $0 to nvidia TX2"
   exit 1 # Exit script after printing help
}

if [ -z "$1" ] || [ -z "$2" ] || [ -z "$3" ]
then
  echo "Some or all of the parameters are empty";
  helpFunction
fi
if [ $1 = "to" ]
then
  scp -r ~/scripts $2@$3:~

elif [ $1 = "from" ]
then
  scp -r $2@$3:~/scripts ~
else
echo "Sends or receive scripts using scp"
exit 0
fi





