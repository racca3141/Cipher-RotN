// Emerson Racca
// 11/17/2021
// Lab 10b - Cipher RotN

/*
Design and build a rotation cipher class. Add two simple methods to our design.

a. Code a method that takes the message and groups the letters in groups of 5 chars. -- (strip out the punctuation too)

b. Code a method that changes all chars to lower case.

c. In the main, allow the user to type in a message... show the encoded message GROUPED BY 5 CHARS - ALL LOWER CASE - NO PUNCTUATION.

Turn in a single .cpp source file.
*/

#include<iostream>
#include<string>

using namespace std;

class Message {
private:
	string msg;
	int n;

public:
	

	//constructors
	Message(string msgArg = "Hello world.", int nArg = 13); // This is actually the default constructor when creating an object without parameters, i.e. Message myMsg;

	//accessors -- get and sets
	string getMsg(void);
	int getN(void);
	void setMsg(string msgArg);
	void setN(int nArg);


	//methods
	string toLower(void);
	string group5(void);
	string RotN(int nArg);
};

int main(void) {
	string temp;
	string userMsg;
	string userMsgCopy;

	cout << "Enter a string to encrypt:  ";
	getline(cin, userMsg);

	Message myMsg(userMsg, 12);

	userMsgCopy = myMsg.getMsg();

	//cout << myMsg.getMsg() << endl;
	//cout << myMsg.getN() << endl;

	//Lowercase.
	cout << "\n\nThe message in lowercase is: \n";
	cout << myMsg.toLower() << endl;

	//Groups of 5 minus punctuations.
	cout << "\nThe message grouped in 5 chars and no punctuations: \n";
	cout << myMsg.group5() << endl;

	//Encrypt the message.
	cout << "\nThe message encrypted using Rot13 is: \n";
	cout << myMsg.RotN(13) << endl;


	//Use the original message to show lab requirement
	cout << "\nThe message encrypted, grouped and in lowercase:\n\n";
	for (int i = 0; i < 26; i++) { //rot0 for testing
		//encrypt
		temp = myMsg.RotN(i);
		//group
		myMsg.setMsg(temp);
		temp = myMsg.group5();
		//lowercase
		myMsg.setMsg(temp);
		temp = myMsg.toLower();
		//cout
		cout << "Rot" << i << ": " << temp << endl << endl;
		//reset to the original message
		myMsg.setMsg(userMsgCopy);
	}


	return 0;
}

//constructors
Message::Message(string msgArg, int nArg) {
	setMsg(msgArg);
	n = nArg;
}
//accessors
string Message::getMsg(void) {
	return msg;
}
int Message::getN(void) {
	return n;
}
void Message::setMsg(string msgArg) {
	msg = msgArg;
}
void Message::setN(int nArg) {
	n = nArg;
}

//methods
string Message::toLower(void) {
	string temp = "";
	string msgCopy = getMsg();
	for (unsigned int i = 0; i < msgCopy.size(); i++) {
		temp += tolower(msgCopy[i]);
	}
	return temp;
}

string Message::group5(void) {
	int count = 0;
	string temp = "";
	string msgCopy = getMsg();
	for (unsigned int i = 0; i < msgCopy.size(); i++) {
		if (count == 5) {
			temp += " ";
			count = 0;
		}
		if (int(msgCopy[i]) >= 97 && int(msgCopy[i]) <= 122) {
			temp += msgCopy[i];
			count++;
		}
	}
	return temp;
}


string Message::RotN(int n) {
	string temp = "";
	string msgCopy = getMsg();
	for (unsigned int i = 0; i < msgCopy.size(); i++) {
		if (int(msgCopy[i]) >= 97 && int(msgCopy[i]) <= 122) {
			if (int(msgCopy[i]) + n > 122) {
				temp = temp + char(msgCopy[i] + n - 26);
			}
			else
				temp = temp + char(msgCopy[i] + n);
		}
		else
			temp = temp + msgCopy[i];
	}
	return temp;
}

