 #include <iostream>      //For I/O Functions
#include <windows.h>   //For Beep & Sleep functions
#include<stdlib.h>  //For System Pause
using namespace std;

int main()
{

    /**
    C 16 33 65 131 262 523 1046 2093
C# 17 35 69 139 277 554 1109 2217
D 18 37 73 147 294 587 1175 2349
D# 19 39 78 155 311 622 1244 2489
E 21 41 82 165 330 659 1328 2637
F 22 44 87 175 349 698 1397 2794
F# 23 46 92 185 370 740 1480 2960
G 24 49 98 196 392 784 1568 3136
G# 26 52 104 208 415 831 1661 3322
A 27 55 110 220 440 880 1760 3520
A# 29 58 116 233 466 932 1865 3729
B 31 62 123 245 494 988 1975 3951
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

    // CCDCFF
    Beep(C, 282);
    Beep(C, 282);
    Beep(D, 400);
    Beep(C, 382);
    Beep(F, 500);
    Beep(E, 400);


    //CCCGF
    Beep(C, 282);
    Beep(C, 282);
    Beep(D, 400);
    Beep(C, 382);
    Beep(G, 500);
    Beep(F, 600);

    //CCC#AFED
    Beep(C, 282);
    Beep(C, 282);
    Beep(_C, 350);
    Beep(A, 302);
    Beep(F, 400);
    Beep(E, 400);
    Beep(D, 500);

    //A#A#AFGF
    Beep(_A, 340);
    Beep(_A, 220);
    Beep(A, 220);
    Beep(F, 228);
    Beep(G, 286);
    Beep(F, 270);

    return 0;
}   
