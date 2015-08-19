/*
This is the source code for LinhPhi Hotspot Creator
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void start_hn(void);
void modify_hostednetwork(char[], char[]);
int evaluate_strings(char[], char[]);
void pause(void);
void exitnow(void);
void clearscreen(void);
void menu(void);
void menu_hotspot(void);
void menu_wireless(void);
void menu_about(void);
void echooff(void);
void askforhndetails(void);

char choice;

void echooff(void) {
    system("echo off");
}

void clearscreen(void) {
    system("cls");
}

int main() {
    menu();
    return 0;
}


void pause(void) {
    system("pause");
}

void exitnow(void) {
    exit(0);
}

void start_hostednetwork(void) {
    system("netsh wlan start hostednetwork");
}
void askforhndetails() {
    char hostname[64], keyphrase[64];
    echooff();
    clearscreen();
    system("title Modify your HotSpot Settings");
    puts("Enter your hotspot's name (SSID): ");
    gets(hostname);
    puts("Enter your hotspot's password (Security key): ");
    gets(keyphrase);
    echooff();
    clearscreen();
    modify_hostednetwork(hostname, keyphrase);
}
void modify_hostednetwork(char hostname[64], char keyphrase[64]) {
    char modifyhostednetwork[128] = "";
    strcat(modifyhostednetwork, "netsh wlan set hostednetwork mode=allow ssid=");
    strcat(modifyhostednetwork, hostname);
    strcat(modifyhostednetwork, " key=");
    strcat(modifyhostednetwork, keyphrase);
    puts(modifyhostednetwork);
    system(modifyhostednetwork);
    puts("Your wireless hotspot network has been set.\n\n");
    pause();
}

int evaluate_strings(char hostname[64], char keyphrase[64]) {
}

void menu(void) {
    while (1) {
        clearscreen();
        system("title KMAHotspot wireLess Ver 1.0 - By Linh Phi");
        system("color 0E");
        puts("\n\t\tThank you for using KMAHotspot Ver 1.0");
        puts("\n");
        puts("\tMain menu:\n");
        puts("\t[1] (H)otspot");
        puts("\t[2] (W)ireless");
        puts("\t[3] (A)bout");
        puts("\t[4] e(X)it");
        puts("\nPlease press the number or corresponding letter of your choice: ");
        choice = getch();

        if (choice == '1' || choice == 'h' || choice == 'H') {
            menu_hotspot();
        } else if (choice == '2' || choice == 'w' || choice == 'W') {
            menu_wireless();
        } else if (choice == '3' || choice == 'a' || choice == 'A') {
            menu_about();
        } else if (choice == '4' || choice == 'x' || choice == 'X') {
            exitnow();
        } else {
            puts("\n\n\tOption not found!.\n\n\t");
       
        }
    }
}

void menu_hotspot(void) {
menu_hotspot:

    while (1) {
        clearscreen();
        system("title KMAHotspot wireLess Ver 1.0 - HotSpot");
        system("color 0E");
        puts("\n\t\tHotSpot Options");
        puts("\n");
        puts("\tMenu:\n");
        puts("\t[1] (C)heck hotspot availability");
        puts("\t[2] (E)dit hotspot configuration");
        puts("\t[3] (S)tart hotspot");
        puts("\t[4] s(T)op hotspot");
        puts("\t[5] rest(A)rt hotspot");
        puts("\t[6] (V)iew hotspot");
        puts("\t[7] (R)eset hotspot configuration");
        puts("\t[8] (G)o back");
        puts("\t[9] e(X)it");
        puts("\nPlease press the number or corresponding letter of your choice: ");
        choice = getch();

        if (choice == '1' || choice == 'c' || choice == 'C') {
            echooff();
            clearscreen();
            system("title Hotspot Check if compatible");
            system("netsh wlan show drivers");
            puts("\tPlease check above if the information\n\t\"Hosted network supported  : Yes\"\n\tOtherwise, your wireless network card\n\tDOES NOT support hostednetworking");
            puts("\n");
            pause();
        } else if (choice == '2' || choice == 'e' || choice == 'E') {
            askforhndetails();
        } else if (choice == '3' || choice == 's' || choice == 'S') {
            echooff();
            clearscreen();
            system("netsh wlan start hostednetwork");
            puts("\n\n");
            pause();
        } else if (choice == '4' || choice == 't' || choice == 'T') {
            echooff();
            clearscreen();
            system("netsh wlan stop hostednetwork");
            puts("\n\n");
            pause();
        } else if (choice == '5' || choice == 'a' || choice == 'A') {
            echooff();
            clearscreen();
            system("netsh wlan stop hostednetwork");
         
            clearscreen();
            system("netsh wlan start hostednetwork");
       
            clearscreen();
            puts("Restart done!\n\n");
            pause();
        } else if (choice == '6' || choice == 'v' || choice == 'V') {
            echooff();
            clearscreen();
            system("title Current hotspot details");
            system("netsh wlan show hostednetwork");
            puts("\n\n");
            pause();
        } else if (choice == '7' || choice == 'r' || choice == 'R') {
            echooff();
            clearscreen();
            system("title Resetting hotspot configuration");
            system("netsh wlan set hostednetwork mode=allow ssid=nullnull key=nullnull");
            puts("Note:\nYour wifi hotspot name (ssid) and password (key) has been reset to \nSSID = nullnull\nkey = nullnull.\nPlease choose option 2 in Hotspot Menu to modify the settings.\n\n");
            pause();
        } else if (choice == '8' || choice == 'g' || choice == 'G') {
            menu();
        } else if (choice == '9' || choice == 'x' || choice == 'X') {
            exitnow();
        } else {
            puts("\n\n\tOption not found!.\n\n\t");
        
            goto menu_hotspot;
        }
    }
}
void menu_wireless(void) {
menu_wireless:

    while (1) {
        clearscreen();
        system("title KMA HOTSPOT");
        system("color 0E");
        puts("\n\t\tWireless Options");
        puts("\n");
        puts("\tMenu:\n");
        puts("\t[1] Wireless (I)nterfaces");
        puts("\t[2] Wireless (N)etworks");
        puts("\t[3] Wireless (P)rofiles");
        puts("\t[4] Wireless (S)ettings");
        puts("\t[5] Wireless (D)rivers");
        puts("\t[6] (G)o back");
        puts("\t[7] e(X)it");
        puts("\nPlease press the number or corresponding letter of your choice: ");
        choice = getch();

        if (choice == '1' || choice == 'i' || choice == 'I') {
            echooff();
            clearscreen();
            system("title Wireless Interfaces Information");
            system("netsh wlan show interfaces");
            puts("\n");
            pause();
        } else if (choice == '2' || choice == 'n' || choice == 'N') {
            echooff();
            clearscreen();
            system("title Wireless Networks Information");
            system("netsh wlan show networks");
            puts("\n");
            pause();
        } else if (choice == '3' || choice == 'p' || choice == 'P') {
            echooff();
            clearscreen();
            system("title Wireless Profiles Information");
            system("netsh wlan show profiles");
            puts("\n");
            pause();
        } else if (choice == '4' || choice == 's' || choice == 'S') {
            echooff();
            clearscreen();
            system("title Wireless Settings Information");
            system("netsh wlan show settings");
            puts("\n");
            pause();
        } else if (choice == '5' || choice == 'd' || choice == 'D') {
            echooff();
            clearscreen();
            system("title Wireless Drivers Information");
            system("netsh wlan show drivers");
            puts("\n");
            pause();
        } else if (choice == '6' || choice == 'g' || choice == 'G') {
            menu();
        } else if (choice == '7' || choice == 'x' || choice == 'X') {
            exitnow();
        } else {
            puts("\n\n\tOption not found!.\n\n\t");
          
            goto menu_wireless;
        }
    }
}
void menu_about(void) {
menu_about:

    while (1) {
        echooff();
        clearscreen();
        system("title KMAHotspot wireLess Ver 1.0 - About");
        system("color 0E");
        puts("\n\t\tAbout");
        system("type *.txt");
        puts("\n\nPlease press the number or corresponding letter of your choice: ");
        choice = getch();

        if (choice == '1' || choice == 'w' || choice == 'W') {
            echooff();
            clearscreen();
            puts("\nNow directing you to my website...\nYour default browser shall be launched.");
          
            system("start http://vn-developers.com");
          
            goto menu_about;
        } else if (choice == '2' || choice == 'g' || choice == 'G') {
            menu();
        } else if (choice == '3' || choice == 'x' || choice == 'X') {
            exitnow();
        }  else {
            puts("\n\n\tOption not found!.\n\n\t");
          
            goto menu_about;
        }
    }
}

