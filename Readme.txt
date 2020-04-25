Steps to setup:

1)Create a folder named 'BMS' in C drive(just inside C drive) and download the file there and unzip.

2)Open Qt library and open BankManagementSystem.pro file which is present in BMS.

3)Build the project.

Guidelines to use the project:

1)Once you build the project,a window pops up.Lets call this the main window.The main window shows multiple interfaces namely 'customer signin','admin signin','singnup' and 'forgot password'.

2)Inside the main window,pressing 'signup' button will take you to a new window.After filling the mentioned details,the system will generate a new account number for you,which will be popped as a message.The password to your account is your account number by default.You will be taken back to the main window.

3)Inside the main window,to press 'customer signin',you need to fill your username(ie your account number) and password.After pressing,you will be taken to a new window.Lets call this 'customer signin' window.This window will show all your information.

4)Inside the 'customer signin' window,you can change your details like name,phone number,voter id,email id and password by just pressing and editing them.To save these details you need to enter your current password beside 'current password' and press 'go' button.

5)Inside the 'customer signin' window,you can make transactions.You can enter the amount in the space beside 'Add money' or 'Withdraw' to add money or withdraw to/from your account respectively.You can make transactions to other accounts by entering the account number and amount beside 'transfer'.To confirm these transactions,enter your password beside 'current password' and press 'go' button.

6)Inside the 'customer signin' window,you can view your last three transactions below 'recent transactions'.The first colounm shows the account number to/from you transacted or 'self' if you just add/withdraw money.The second coloumn shows the amount transacted along with + or - indicating credit or debit respectively.

7)Inside the 'customer signin' window,you can delete your account by just entering your password beside 'current password' and pressing 'delete account' button.

8)Inside the main window,you can press the 'forgot password' button after entering your account number in the 'customer signin' interface.This will take you to a new window where you will be asked to enter some details.If your information is correct,your password will be reset to your current phone number.

9)Inside the main window,you can press the 'admin signin' after entering the admin password.The password is present in the file 'Admin_Pass' which is 'admin' by default.You will be taken to a new interface where you can search the accounts with a given aadhaar number or name or account balance.The accounts matching the given conditions will be shown in a message box.You can exit from this window by clicking 'close'.
