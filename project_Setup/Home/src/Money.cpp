#include <iostream>
using namespace std;

class ATM {
private:
    double balance;
    int pin;

public:
    ATM(double initialBalance, int initialPin) {
        balance = initialBalance;
        pin = initialPin;
    }

    bool authenticate(int inputPin) {
        if (inputPin == pin) {
            return true;
        } else {
            cout << "Invalid PIN. Please try again." << endl;
            return false;
        }
    }

    void checkBalance() {
        cout << "Your current balance is: $" << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited $" << amount << endl;
        } else {
            cout << "Invalid deposit amount. Please enter a positive number." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance. Please try a smaller amount." << endl;
        } else if (amount <= 0) {
            cout << "Invalid withdrawal amount. Please enter a positive number." << endl;
        } else {
            balance -= amount;
            cout << "Successfully withdrew $" << amount << endl;
        }
    }

    // Suggest accurate financial advice based on balance
    void suggestAdvice() {
        cout << "\n--- Financial Advice ---" << endl;

        if (balance < 100) {
            cout << "Warning: Your balance is low. Consider saving more to build a financial cushion." << endl;
            cout << "Suggestion: Start saving small amounts regularly and reduce unnecessary expenses.\n";
        } else if (balance >= 100 && balance < 1000) {
            cout << "Your balance is moderate. Here are some ways to grow your savings:\n";
            cout << "1. Fixed Deposits (FDs): Safe and steady growth with guaranteed returns.\n";
            cout << "2. Digital Savings Platforms: Online platforms offering higher interest rates.\n";
            cout << "\nWould you like more details about these options? (yes/no): ";
            string response;
            cin >> response;

            if (response == "yes") {
                cout << "\n1. Fixed Deposits: Offers a fixed return over a specific period. Ideal for low-risk growth.\n";
                cout << "2. Digital Savings Platforms: Flexible online accounts with better returns compared to traditional savings accounts.\n";
            }
        } else if (balance >= 1000 && balance < 5000) {
            cout << "Great job! Your balance is healthy. Here are some investment options to consider:\n";
            cout << "1. Mutual Funds: Diversified and professionally managed investments.\n";
            cout << "2. Stock Market: Potential for high returns, but requires understanding and risk tolerance.\n";
            cout << "\nWould you like more details about these options? (yes/no): ";
            string response;
            cin >> response;

            if (response == "yes") {
                cout << "\n1. Mutual Funds: Investment pools managed by professionals, offering moderate growth and risk.\n";
                cout << "2. Stock Market: Allows investing in individual companies or ETFs. Higher risk but potential for high returns.\n";
            }
        } else {
            cout << "Excellent balance! Consider diversifying with these options:\n";
            cout << "1. Mutual Funds\n";
            cout << "2. Stock Market\n";
            cout << "3. Cryptocurrencies: High risk, high reward. Ideal for tech-savvy investors.\n";
            cout << "\nWould you like more details about these options? (yes/no): ";
            string response;
            cin >> response;

            if (response == "yes") {
                cout << "\n1. Mutual Funds: Steady and balanced growth with professional management.\n";
                cout << "2. Stock Market: Offers significant returns but requires careful analysis and risk management.\n";
                cout << "3. Cryptocurrencies: Digital assets with potential for rapid growth, but very volatile and risky.\n";
            }
        }

        cout << "--- End of Advice ---\n";
    }
};

int main() {
    double initialBalance;
    int userPin;

    cout << "Welcome to the ATM!" << endl;
    cout << "Set your initial balance: $";
    cin >> initialBalance;
    cout << "Set your 4-digit PIN: ";
    cin >> userPin;

    ATM atm(initialBalance, userPin);

    int inputPin;
    cout << "\nPlease enter your PIN to access your account: ";
    cin >> inputPin;

    if (!atm.authenticate(inputPin)) {
        return 0;
    }

    int choice;
    do {
        cout << "\nATM Menu: \n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Get Advice\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            atm.checkBalance();
            break;
        case 2: {
            double depositAmount;
            cout << "Enter amount to deposit: $";
            cin >> depositAmount;
            atm.deposit(depositAmount);
            break;
        }
        case 3: {
            double withdrawAmount;
            cout << "Enter amount to withdraw: $";
            cin >> withdrawAmount;
            atm.withdraw(withdrawAmount);
            break;
        }
        case 4:
            atm.suggestAdvice();
            break;
        case 5:
            cout << "Thank you for using the ATM. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
        }

    } while (choice != 5);

    return 0;
}
