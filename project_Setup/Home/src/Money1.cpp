#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

// Global Variables
int balance = 1000;

// Function to Display Balance
void displayBalance() {
    char balanceText[50];
    sprintf(balanceText, "Your Balance: $%d", balance);
    outtextxy(150, 150, (char*)balanceText); // Casted string literal
}

// Function to Withdraw Money
void withdrawMoney(int amount) {
    char message[50];
    if (amount > balance) {
        outtextxy(150, 200, (char*)"Insufficient Balance!"); // Casted string literal
    } else {
        balance -= amount;
        sprintf(message, "Successfully Withdrawn: $%d", amount);
        outtextxy(150, 200, (char*)message);
        delay(2000); // Delay for user to see message
    }
}

// Function to Deposit Money
void depositMoney(int amount) {
    balance += amount;
    char message[50];
    sprintf(message, "Successfully Deposited: $%d", amount);
    outtextxy(150, 200, (char*)message);
    delay(2000); // Delay for user to see message
}

// Function to Run the ATM Simulation
void runATM() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)""); // Fixed initgraph warning

    while (1) {
        cleardevice(); // Clear screen
        outtextxy(180, 20, (char*)"Welcome to the ATM"); // Casted string literal
        outtextxy(150, 100, (char*)"1. View Balance");   // Menu options
        outtextxy(150, 120, (char*)"2. Withdraw Money");
        outtextxy(150, 140, (char*)"3. Deposit Money");
        outtextxy(150, 160, (char*)"4. Exit");

        // User input
        char choice;
        choice = getch(); // Get user input

        cleardevice(); // Clear screen for next action
        switch (choice) {
        case '1': // View Balance
            displayBalance();
            delay(2000); // Show balance for 2 seconds
            break;
        case '2': // Withdraw Money
            outtextxy(150, 100, (char*)"Enter amount to withdraw: ");
            char withdrawInput[10];
            int withdrawAmount;
            getstr(withdrawInput); // Get input as string
            withdrawAmount = atoi(withdrawInput); // Convert to integer
            withdrawMoney(withdrawAmount);
            delay(2000); // Wait to display withdrawal result
            break;
        case '3': // Deposit Money
            outtextxy(150, 100, (char*)"Enter amount to deposit: ");
            char depositInput[10];
            int depositAmount;
            getstr(depositInput); // Get input as string
            depositAmount = atoi(depositInput); // Convert to integer
            depositMoney(depositAmount);
            delay(2000); // Wait to display deposit result
            break;
        case '4': // Exit
            outtextxy(150, 100, (char*)"Thank you for using the ATM!");
            delay(2000);
            closegraph();
            return;
        default:
            outtextxy(150, 200, (char*)"Invalid Option! Try again.");
            delay(2000); // Wait for user to see message
        }
    }
}

int main() {
    runATM();
    return 0;
}
