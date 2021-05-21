# Usage

Download the latest release [here](https://github.com/cs18b047/BMS/releases).
Run the app-image.
Create an account by clicking signup and get a customer identification number.
Login with your identification and password.For the very first time, your password will be same as that of your identification.
Inside your login screen, you can see and modify your account details, password, make and view transactions, etc.
You will be intimated with an email and text for every transaction.
If you forget your password, use the forgot password option and answer the required questions properly.Your password will be reset to your phone number.Please change it immediately by logging in.

# For Contributors
### User Interface
`QT` is used for creating user interface.You can find the `ui` files in the `ui` folder.
### Logic
`C++` is used for coding logic. `MySql` is embedded along with the main language to support database operations.These files are present in `src` folder.
### Include
The `ui` files and `src` files are interconnected using the `.h` files.Data structures and algorithms that are common to all `src` files are present in `include` folder.
### Alerts
The `comm` folder contains files related to communication via email and texts.These are written using `python`.These are written in a way that they can independently query the database and alert the users.
### Website
The website related `html` and `css` is available in `website` folder.
### Back-end
`MySql` is currently used for `SQL` operations.The server is hosted on `Azure` platform.
### Conclusion
Most of the sections can be independently developed.The `ui` and `src` are to be developed hand in hand.There are couple of other folders `deploy` and `resources`. These contain the deployment related and cross-platform related resources for developers.
