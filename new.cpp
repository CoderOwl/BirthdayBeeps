#include <iostream>      																	//For I/O Functions
#include <windows.h>   																		//For Beep & Sleep functions
#include <stdlib.h>  																		//For System Pause

using namespace std;

int typeWait = 50; 																			//Number of milliseconds to wait before typing next charactar.

/**	Input: 
 *	@lpParameter - Contains the string. 
 *
 *	Prints each character of a string with 
 *	a gap of 50 milliseconds. 
 */
DWORD WINAPI typingThread(LPVOID lpParameter)
{
        char *msg = (char *)lpParameter;
        int i;
        for(i=0; msg[i]!='\0'; i++)															// Print each character till End of Line charactar is detected. 
        {
            cout << msg[i];
            cout.flush();																	// Flush the output buffer without waiting for an new line. 
            Sleep(typeWait);																// Time to wait before printing next charactar. 
        }
        return 0;
}

/**	Input: 
 *	@s - The string to be typed.
 *  @h - The HANDLE of the previous typeString thread.
 *
 *	Waits for the previous typeString thread to finish executing
 *  and creates a thread to type string s. 
 */
HANDLE typeMessage(string msg, HANDLE h)
{
    if(h!=0)
        WaitForSingleObject(h, INFINITE); 													// Wait till the previous thread of typeString completes execution.
    LPVOID lpString = (LPVOID)msg.c_str();
    HANDLE myHandle = CreateThread(0, 0, typingThread, lpString, 0, 0);
    return myHandle;
}

/**
 * TODO:
 * Add getch() before closing the program. 
 */
int main()
{

    /**				Frequency Chart
    Octave	1  2  3   4   5   6    7    8
    C 		16 33 65 131 262 523 1046 2093
    C# 		17 35 69 139 277 554 1109 2217
    D 		18 37 73 147 294 587 1175 2349
    D# 		19 39 78 155 311 622 1244 2489
    E 		21 41 82 165 330 659 1328 2637
    F 		22 44 87 175 349 698 1397 2794
    F# 		23 46 92 185 370 740 1480 2960
    G 		24 49 98 196 392 784 1568 3136
    G# 		26 52 104 208 415 831 1661 3322
    A 		27 55 110 220 440 880 1760 3520
    A# 		29 58 116 233 466 932 1865 3729
    B 		31 62 123 245 494 988 1975 3951
    **/

    int C = 523;
    int _C = 554;
    int D = 587;
    int _D = 622;
    int E = 659;
    int F = 698;
    int _F = 740;
    int G = 784;
    int _G = 831;
    int A = 880;
    int _A = 932;
    int B = 988;


    string s = "Happy Birthday to you...\n";											    // The message to be typed along with the following tune.
    HANDLE h = typeMessage(s, 0);                                                           // Create a thread to type the message and get it's HANDLE.

    //Tune: CCDCFF
    Beep(C, 282);                                                                           // The note to be played with the number of milliseconds to play it.
    Beep(C, 282);
    Beep(D, 400);
    Beep(C, 382);
    Beep(F, 500);
    Beep(E, 400);


    s = "Happy Birthday to you...\n";
    h = typeMessage(s,h);

    //Tune: CCCGF
    Beep(C, 282);
    Beep(C, 282);
    Beep(D, 400);
    Beep(C, 382);
    Beep(G, 500);
    Beep(F, 600);

    s = "Happy Birthday to dear <Name>\n";
    h = typeMessage(s, h);

    //Tune: CCC#AFED
    Beep(C, 282);
    Beep(C, 282);
    Beep(_C, 350);
    Beep(A, 302);
    Beep(F, 400);
    Beep(E, 400);
    Beep(D, 500);

    s = "Happy Birthday to you...\n";
    h = typeMessage(s, h);

    //Tune: A#A#AFGF
    Beep(_A, 340);
    Beep(_A, 220);
    Beep(A, 220);
    Beep(F, 228);
    Beep(G, 286);
    Beep(F, 270);

    s = "";
    h = typeMessage(s, h);

    return 0;
}