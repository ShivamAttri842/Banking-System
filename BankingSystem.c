#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
 
// Declaring all the functions
void checkbalance(char*);
void transfermoney(void);
void display(char*);
void login(void);
void loginsu(void);
void account(void);
void accountcreated(void);
void logout(void);
 
// Creating a structure to store data of the user
struct pass {
    char username[50];
    int date;
    int month;
    int year;
    char pnumber[15];
    char adharnum[20];
    char fname[20];
    char lname[20];
    char fathname[20];
    char mothname[20];
    char address[50];
    char typeaccount[20];
};
 
// Structure to keep track of amount transfer
struct money {
    char usernameto[50];
    char userpersonfrom[50];
    long int money1;
};
 
struct userpass {
    char password[50];
};
 
// Driver Code
int main()
{
    int i, a, b, choice;
    int passwordlength;

    printf("--------WELCOME TO BANK ACCOUNT SYSTEM--------\n");
    
    printf("1.... Create Account\n");

    printf("2.... Already a user? Sign in\n");

    printf("3.... Exit\n");
 
    printf("\nENTER YOUR CHOICE..");
 
    scanf("%d", &choice);
 
    switch (choice) {
    case 1:
        system("cls");
        account();
        break;
 
    case 2:
        login();
        break;
 
    case 3:
        exit(0);
        break;
 
        getch();
    }
}
 
// Function to create accounts of users
void account(void)
{
    char password[20];
    int passwordlength, i, seek = 0;
    char ch;
    FILE *fp, *fu;
    struct pass u1;
    struct userpass p1;
 
    struct userpass u2;

    fp = fopen("UserID.txt", "ab");

    system("cls");
    printf("\nCREATE ACCOUNT");
 
    printf("\nFirst Name: ");
    scanf("%s", &u1.fname);
 
    printf("\nLast Name: ");
    scanf("%s", &u1.lname);
 
    printf("\nFather's Name: ");
    scanf("%s", &u1.fathname);
 
    printf("\nMother's Name: ");
    scanf("%s", &u1.mothname);
 
    printf("\n\nAddress: ");
    scanf("%s", &u1.address);
 
    printf("\nAccount Type: ");
    scanf("%s", &u1.typeaccount);
 
    printf("\nDate of Birth ");
    printf("\nDate:  ");
    scanf("%d", &u1.date);
    printf("\nMonth: ");
    scanf("%d", &u1.month);
    printf("\nYear: ");
    scanf("%d", &u1.year);
 
    printf("\nAadhar Number: ");
    scanf("%s", u1.adharnum);
 
    printf("\nPhone Number: ");
    scanf("%s", u1.pnumber);
 
    printf("\nUsername: ");
    scanf("%s", &u1.username);
 
    printf("\nPassword: ");
 
    // Taking password in the form of stars
    for (i = 0; i < 50; i++) {
        ch = getch();
        if (ch != 13) {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
        else
            break;
    }
 
    // Writing to the file
    fwrite(&u1, sizeof(u1),
           1, fp);

    fclose(fp);

    accountcreated();
}

void accountcreated(void)
{
    int i;
    char ch;
    system("cls");
    printf("Please wait...\nYour data is processing...\n");

    printf("Account created succesfully\n");
 
    printf("Press enter to login\n");
 
    getch();
    login();
}
 
// Login function to check the username of the user
void login(void)
{
    system("cls");
 
    char username[50];
    char password[50];
 
    int i, j, k;
    char ch;
    FILE *fp, *fu;
    struct pass u1;
    struct userpass u2;

    fp = fopen("UserID.txt","rb");
 
    if (fp == NULL) {
        printf("Error in Opeaning File");
    }

    printf(" Account Login \n");


    printf("====== LOG IN ======\n");
 
    // Take input
    printf("Username: ");
    scanf("%s", &username);

    printf("Password: ");
 
    // Input the password
    for (i = 0; i < 50; i++) {
        ch = getch();
        if (ch != 13) {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
 
        else
            break;
    }
 
    // Checking if username exists in the file or not
    while (fread(&u1, sizeof(u1),1, fp)) {
        if (strcmp(username,u1.username)== 0) {
            loginsu();
            display(username);
        }
    }
 
    // Closing the file
    fclose(fp);
}
 
// Redirect after successful login
void loginsu(void)
{
    int i;
    FILE* fp;
    struct pass u1;
    system("cls");
    printf("Fetching account details.....\n");

    printf("Login Successful\n");

    printf("Press enter to continue\n");
 
    getch();
}
 
// Display function to show the data of the user on screen
void display(char username1[])
{
    system("cls");
    FILE* fp;
    int choice, i;
    fp = fopen("UserID.txt", "rb");
    struct pass u1;
 
    if (fp == NULL) {
        printf("Error in Opening File");
    }
 
    while (fread(&u1, sizeof(u1),
                 1, fp)) {
        if (strcmp(username1,u1.username)== 0) {

            printf("Welcome, %s %s\n",u1.fname, u1.lname);

            printf("==== YOUR ACCOUNT INFORMATION ====\n");

            printf("Name: %s %s\n", u1.fname,u1.lname);
 
            printf("Father's Name: %s %s\n",u1.fathname,u1.lname);
 
            printf("Mother's Name: %s\n",u1.mothname);
 
            printf("Aadhar Card Number: %s\n",u1.adharnum);

            printf("Mobile Number: %s\n",u1.pnumber);
 
            printf("Date of Birth: %d-%d-%d\n",u1.date, u1.month, u1.year);

            printf("Address: %s\n", u1.address);

            printf("Account Type: %s\n",u1.typeaccount);
        }
    }
 
    fclose(fp);
 
    // Menu to perform different actions by user
    printf(" HOME \n");

    printf(" 1. Check Balance\n");

    printf(" 2. Transfer Money\n");

    printf(" 3. Log out\n\n");

    printf(" 4. Exit\n\n");
 
    printf(" ENTER YOUR CHOICES: ");
    scanf("%d", &choice);
 
    switch (choice) {
    case 1:
        checkbalance(username1);
        break;
 
    case 2:
        transfermoney();
        break;
 
    case 3:
        logout();
        login();
        break;
 
    case 4:
        exit(0);
        break;
    }
}
 
// Function to transfer money from one user to another
void transfermoney(void)
{
    FILE *fm, *fp;
    struct pass u1;
    struct money m1;
    char usernamet[20];
    char usernamep[20];
    system("cls");
 
    fp = fopen("UserID.txt", "rb");

    fm = fopen("Money.txt", "ab");

    printf("------ TRANSFER MONEY ------\n"); 

    printf("FROM (Your Username): ");
    scanf("%s", &usernamet);

    printf(" TO (Username of Person): ");
    scanf("%s", &usernamep);

    while (fread(&u1, sizeof(u1),1, fp))
 
    {
        if (strcmp(usernamep,u1.username)== 0) {
            strcpy(m1.usernameto,u1.username);
            strcpy(m1.userpersonfrom,usernamet);
        }
    }
 
    // Taking amount input
    printf("Enter the amount to be transfered: ");
    scanf("%d", &m1.money1);
 
    // Writing to the file
    fwrite(&m1, sizeof(m1),1, fm);

    printf("Transferring Amount, Please wait...\n");

    printf("Amount Successfuly Transfered");
    getch();
 
    // Close the files
    fclose(fp);
    fclose(fm);
 
    // Function to return to the home screen
    display(usernamet);
}
 
// Function to check balance in users account
void checkbalance(char username2[])
{
    system("cls");
    FILE* fm;
    struct money m1;
    char ch;
    int i = 1, summoney = 0;
 
    // Opening amount file record
    fm = fopen("Money.txt", "rb");

    printf("====== BALANCE DASHBOARD ======\n");

    while (fread(&m1, sizeof(m1),1, fm)) {
        if (strcmp(username2,m1.usernameto)== 0) {
            summoney = summoney + m1.money1;
        }
    }
    printf("Total Amount: ");
 
    printf("%d", summoney);
 
    getch();

    fclose(fm);
    display(username2);
}

void logout(void)
{
    system("cls");
    printf("Please wait, Logging Out\n");

    printf("Sign out successfully\n");

    printf("Press any key to continue");
 
    getch();
}