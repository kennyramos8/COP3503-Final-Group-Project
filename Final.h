//
//  main.h
//  ATM
//
#ifndef main_h
#define main_h

using namespace std;

/*class ATM {
private:
	vector<Customer> allCustomers;
	Person currentCustomer;

public:
	bool addNewCustomer();
	bool findCustomer(int cardNumber);
	bool checkPIN(int PIN);

};
*/


class Customer {

private:
	string name;
	string address;
	string DOB;
	int cardNumber;
	int PIN;
	int balance;

public:
	Customer(string name, string address, string DOB, int cardNumber, double startingBalance, int PIN) {
		this->name = name;
		this->address = address;
		this->DOB = DOB;
		this->cardNumber = cardNumber;
		this->balance = (int)(startingBalance * 100);
		this->PIN = PIN;
	}

	bool changePIN() {
		int enteredPIN = -1;

		while (enteredPIN != 0) {
			cout << "Enter your current PIN (enter 0 to cancel): ";
			cin >> enteredPIN;
			if (comparePIN(enteredPIN)) {
				
				//accepts 2 user inputed PIN's to make sure new PIN is desired PIN
				cout << "Please enter new PIN: ";
				cin >> enteredPIN;
				int newPIN;
				cout << "Please re-enter new PIN: ";
				cin >> newPIN;

				//if 2 entered PIN's are same, set new PIN
				if (newPIN == enteredPIN) {
					this->PIN = newPIN;
					return true;
				}
				else {
					cout << "Entered PINS do not match. Please try again";
					
				}
			}

		}
	}

	bool comparePIN(int PIN) {
		if (this->PIN = PIN) {
			return true;
		}
		return false;
	}

	bool compareCardNumber(int cardNumber) {
		if (this->cardNumber = cardNumber) {
			return true;
		}
		return false;
	}

	bool makeDeposit(double x) {
		this->balance += (int)(x * 100);
		return true;
	}

	bool makeWithdrawal(double x) {
		int withdrawalAmount = (int)(x * 100);
		//checks to make sure user has sufficient funds to make a withdrawal
		if (this->balance >= withdrawalAmount) {
			balance -= withdrawalAmount;
			return true;
		}

		cout << "Insufficient funds." << endl;
		return false;
	}

	double getBalance() {
		cout << "Your current balance is: " << ((double) this->balance) / 100 << endl;
		return this->balance;
	}

	bool transfer(int cardNumber, double x);
};

#endif /* main_h */
