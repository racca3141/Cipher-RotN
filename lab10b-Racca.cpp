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

	cout << "Ciper RotN\n\n";

	cout << "Enter a string to encrypt:  ";
	getline(cin, userMsg);

	Message myMsg(userMsg, 12);

	userMsgCopy = myMsg.getMsg();

	cout << "\n\n\nMethod calls:\n";

	//cout << myMsg.getMsg() << endl;
	//cout << myMsg.getN() << endl;

	//Lowercase.
	cout << "\nLowercase:                ";
	cout << myMsg.toLower() << endl;

	//Groups of 5 minus punctuations.
	cout << "Grouped, no punctuation:  ";
	cout << myMsg.group5() << endl;

	//Encrypt the message.
	cout << "Encrypted with Rot13:     ";
	cout << myMsg.RotN(13) << endl << endl;

	//Use the original message to do lab requirements.
	cout << "\n\nThe message-->lowercase-->encrypted-->grouped without punctuation:\n\n";
	for (int i = 0; i < 26; i++) { //rot0 for testing
		cout << "Rot" << i << endl;
		cout << "--------------------------------------------\n";
		//lowercase
		temp = myMsg.toLower();
		cout << "Lowercase:        " << temp << endl;

		myMsg.setMsg(temp);

		//encrypt
		temp = myMsg.RotN(i);
		cout << "Then encrypted:   " << temp << endl;

		myMsg.setMsg(temp);

		//group
		temp = myMsg.group5();
		cout << "Finally, grouped: " << temp << endl << endl;
		
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

