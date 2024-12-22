
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <string.h>

// Global Variables
int balance = 1000;

// Function to Display Balance
void displayBalance() {
    char balanceText[50];
    sprintf(balanceText, "Your Balance: $%d", balance);
    outtextxy(150, 150, balanceText);
}

// Function to Withdraw Money
void withdrawMoney(int amount) {
    char message[50];
    if (amount > balance) {
        outtextxy(150, 200, "Insufficient Balance!");
    } else {
        balance -= amount;
        sprintf(message, "Successfully Withdrawn: $%d", amount);
        outtextxy(150, 200, message);
    }
    delay(2000); // Delay to display the message
}

// Function to Deposit Money
void depositMoney(int amount) {
    char message[50];
    balance += amount;
    sprintf(message, "Successfully Deposited: $%d", amount);
    outtextxy(150, 200, message);
    delay(2000); // Delay to display the message
}

// Function to Get Numeric Input from User
int getNumericInput(int x, int y) {
    char input[10];
    int i = 0;
    char ch;
    outtextxy(x, y, "Enter amount: ");
    while (1) {
        ch = getch();
        if (ch == 13) { // Enter key
            input[i] = '\0';
            break;
        } else if (ch >= '0' && ch <= '9') { // Allow only numeric input
            input[i++] = ch;
            char temp[2] = {ch, '\0'};
            outtextxy(x + 100 + (i * 10), y, temp);
        } else if (ch == 8 && i > 0) { // Backspace
            i--;
        }
    }
    return atoi(input); // Convert string to integer
}

// Function to Suggest Financial Advice Based on Balance
void suggestAdvice() {
    char message[200];
    if (balance < 100) {
        strcpy(message, "Warning: Your balance is low. Consider saving more.");
        outtextxy(150, 200, message);
        strcpy(message, "Start saving small amounts regularly and reduce unnecessary expenses.");
        outtextxy(150, 220, message);
    } else if (balance >= 100 && balance < 1000) {
        strcpy(message, "Your balance is moderate. Consider these options to grow your savings:");
        outtextxy(150, 200, message);
        strcpy(message, "1. Fixed Deposits (FDs): Safe with guaranteed returns.");
        outtextxy(150, 220, message);
        strcpy(message, "2. Digital Savings: Online platforms with higher interest rates.");
        outtextxy(150, 240, message);
        delay(2000); // Wait for user to read
        outtextxy(150, 260, "Would you like more details? (yes/no): ");
        char response = getch();
        if (response == 'y' || response == 'Y') {
            strcpy(message, "1. FDs: Fixed return over a period. Ideal for low-risk growth.");
            outtextxy(150, 280, message);
            strcpy(message, "2. Digital Savings: Flexible with better returns than regular accounts.");
            outtextxy(150, 300, message);
        }
    } else if (balance >= 1000 && balance < 5000) {
        strcpy(message, "Your balance is healthy! Consider these investment options:");
        outtextxy(150, 200, message);
        strcpy(message, "1. Mutual Funds: Diversified and professionally managed investments.");
        outtextxy(150, 220, message);
        strcpy(message, "2. Stock Market: Potential for high returns, but with higher risk.");
        outtextxy(150, 240, message);
        delay(2000);
        outtextxy(150, 260, "Would you like more details? (yes/no): ");
        char response = getch();
        if (response == 'y' || response == 'Y') {
            strcpy(message, "1. Mutual Funds: Moderate risk with professional management.");
            outtextxy(150, 280, message);
            strcpy(message, "2. Stock Market: Individual company or ETF investment. High return potential.");
            outtextxy(150, 300, message);
        }
    } else {
        strcpy(message, "Excellent balance! Consider diversifying your investments:");
        outtextxy(150, 200, message);
        strcpy(message, "1. Mutual Funds");
        outtextxy(150, 220, message);
        strcpy(message, "2. Stock Market");
        outtextxy(150, 240, message);
        strcpy(message, "3. Cryptocurrencies: High risk, high reward.");
        outtextxy(150, 260, message);
        delay(2000);
        outtextxy(150, 280, "Would you like more details? (yes/no): ");
        char response = getch();
        if (response == 'y' || response == 'Y') {
            strcpy(message, "1. Mutual Funds: Steady growth with professional management.");
            outtextxy(150, 300, message);
            strcpy(message, "2. Stock Market: High risk, high potential returns.");
            outtextxy(150, 320, message);
            strcpy(message, "3. Cryptocurrencies: Volatile but potentially lucrative.");
            outtextxy(150, 340, message);
        }
    }
    delay(2000); // Wait for user to read
}

// Function to Run the ATM Simulation
void runATM() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    while (1) {
        cleardevice(); // Clear screen
        outtextxy(180, 20, "Welcome to the Money Management Application");
        outtextxy(150, 100, "1. View Balance");
        outtextxy(150, 120, "2. Withdraw Money");
        outtextxy(150, 140, "3. Deposit Money");
        outtextxy(150, 160, "4. Get Financial Advice");
        outtextxy(150, 180, "5. Exit");

        char choice = getch(); // Get user input

        cleardevice(); // Clear screen for next action
        switch (choice) {
        case '1': // View Balance
            displayBalance();
            delay(2000); // Show balance for 2 seconds
            break;
        case '2': { // Withdraw Money
            int withdrawAmount = getNumericInput(150, 100);
            withdrawMoney(withdrawAmount);
            break;
        }
        case '3': { // Deposit Money
            int depositAmount = getNumericInput(150, 100);
            depositMoney(depositAmount);
            break;
        }
        case '4': // Financial Advice
            suggestAdvice();
            break;
        case '5': // Exit
            outtextxy(150, 100, "Thank you for using the ATM!");
            delay(2000);
            closegraph();
            return;
        default:
            outtextxy(150, 200, "Invalid Option! Try again.");
            delay(2000); // Wait for user to see the message
        }
    }
}

int main() {
    runATM();
    return 0;
}
