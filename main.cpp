#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

float WinningPossiblityOfMusketeer (int hp1, int hp2, int d)
{
    int h1, h2;
    float P, P1, P2;

// General Case
    P1 = hp1 * (1000.00 - d) / 1000.00;
    P2 = hp2 * d / 1000.00;
    h1 = (hp1 + hp2) % 100;
    h2 = (h1 * hp2) % 100;
    if ((h1 * P1 + h2 * P2) == 0.00)
    {
        if (h1 == 0.00 && h2 == 0.00)
            P = 0;
        if (h1 != 0.00 || h2 != 0.00)
        {
            if (P1<P2)
                P = 0.00;
            else
                P = 1.00;
        }
    }
    else
        P = (h1 * P1 - h2 * P2) / (h1 * P1 + h2 * P2);
    if (P < 0.00)
        P = 0.00;
    if (P > 1.00)
        P = 1.00;

// Special Cases are considered from this line down.
// Note: for any Special Case that requires alternation in variables, the necessary terms will be re-calculated from General Case.

    if ((hp1 == 777) && ((P1<P2)||(h1<h2)) && (hp2!=888))  //  condition a
    {
        d = 1;
        P1 = hp1 * (1000.00 - d) / 1000.00;
        P2 = hp2 * d / 1000.00;
        P = (h1 * P1 - h2 * P2) / (h1 * P1 + h2 * P2);
    }
    if ((hp1 == 888) && (hp2!=888))        // condition b. For this section, just re-compute h1 without changing h2
    {
        h1 = h1 * 10;
        P = (h1 * P1 - h2 * P2) / (h1 * P1 + h2 * P2);
    }
    if ((hp1 == 900) && (P<0.5) && (hp2!=888))       // condition c
    {
        P = 0.5;
    }
    if ((hp2 == 888) && ((hp1 != 777) && (hp1 != 888) && (hp1 != 900))) // condition d
    {
        P = 0.01;
    }
    if ((hp1 == 999) && (hp2 == 888))   // condition e
    {
        P = 1.00;
    }
    if (((hp1 == 220) && (hp2 == 284)) || ((hp1 == 284) && (hp2 == 220)))   // condition f
    {
        P = 0.5;
    }
    if (d == 987)   // condition g
    {
        // this section of code is used to re-calculate all the variables, because special cases are not allowed here.
        if (hp1 == 999 || (h1+h2) == 99)
        {
            P1 = hp1 * (1000.00 - d) / 1000.00;
            P2 = hp2 * d / 1000.00;
            h1 = (hp1 + hp2) % 100;
            h2 = (h1 * hp2) % 100;
            P = (h1 * P1 - h2 * P2) / (h1 * P1 + h2 * P2);
        }
        else
            P = 0.00;
    }

    P = floor(P*100+0.5)/100;
    return P;

}

void combat(int hp1, int hp2, int d) {
    if (WinningPossiblityOfMusketeer (hp1,hp2,d)==0)
        cout << "0.00";
    else if (WinningPossiblityOfMusketeer (hp1,hp2,d)==0.1)
        cout << "0.10";
    else if (WinningPossiblityOfMusketeer (hp1,hp2,d)==0.2)
        cout << "0.20";
    else if (WinningPossiblityOfMusketeer (hp1,hp2,d)==0.3)
        cout << "0.30";
    else if (WinningPossiblityOfMusketeer (hp1,hp2,d)==0.4)
        cout << "0.40";
    else if (WinningPossiblityOfMusketeer (hp1,hp2,d)==0.5)
        cout << "0.50";
    else if (WinningPossiblityOfMusketeer (hp1,hp2,d)==0.6)
        cout << "0.60";
    else if (WinningPossiblityOfMusketeer (hp1,hp2,d)==0.7)
        cout << "0.70";
    else if (WinningPossiblityOfMusketeer (hp1,hp2,d)==0.8)
        cout << "0.80";
    else if (WinningPossiblityOfMusketeer (hp1,hp2,d)==0.9)
        cout << "0.90";
    else if (WinningPossiblityOfMusketeer (hp1,hp2,d)==1)
        cout << "1.00";
    else
    cout << WinningPossiblityOfMusketeer (hp1,hp2,d);
}

int main ()
{   // create file and write in
    ofstream fileOpen;
    fileOpen.open("mytext.txt");
    if (fileOpen.is_open()) {
    fileOpen << 777 << " " << 188 << " " << 500;}
    fileOpen.close();

    // read data from file
    ifstream file_("mytext.txt");
    int hp1;
    int hp2;
    int d;
    if (file_.is_open())
        file_ >> hp1 >> hp2 >> d;

    combat(hp1,hp2,d);

    cin.get();                         // pause the console window
    return 0;
}
