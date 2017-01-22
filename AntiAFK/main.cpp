#include <iostream>
#include <cbot.h>
#include <windows.h>
#include <String>
#include <cstdio>
using namespace std;

void stealth(){
    HWND stealth;
    AllocConsole();
    stealth=FindWindowA("ConsoleWindowClass",NULL);
    ShowWindow(stealth,0);
}

int askForTime(){
    int output;
    cout << "Time to kick you [In seconds example 60]:  ";
    cin >> output;
    if(output < 5){
        output = 5;
    }
    return output;
}

int main(int argc,  char** argv){ // AppName.exe 5 -silent  <- that's mean your app will start silent, and check if you're afk for 5 secs
    if(argc > 2 && string(argv[2]) == "-silent"){
        stealth();
    }
    int time;
    if(argc > 1){
        if(string(argv[1]) == "-silent"){
            cout << "Bad argument. Syntex: [appname.exe] [time](optional) [-silent](optional)"<<endl;
            return 0;
        }
        time = atoi(argv[1]);
    } else {
        time = askForTime();
    }
    time = time * 1000;
    CBot cbot; // https://github.com/orzel1244/CBot
    cbot.wait(1);
    while(true){
    while(cbot.isAfk(time) != true){}
        cbot.holdKey('w', 20); // Hold w for 20 ms
        cbot.addCursorForce(2,0); // move cursor 2px
        cbot.wait(2); // wait
        cbot.holdKey('s', 20);
        cbot.addCursorForce(-2,0); // move back
    }
    return 0;
}
