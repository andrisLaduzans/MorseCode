/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
https://www.onlinegdb.com/online_c++_compiler

*******************************************************************************/

/**
 * morse code rules
 * The length of a dot is 1 time unit.
 * A dash is 3 time units.
 * The space between symbols (dots and dashes) of the same letter is 1 time unit.
 * The space between letters is 3 time units.
 * The space between words is 7 time units.
*/

#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

class Morse {
    private:
        string output[360];
        
        int msgLength = 0;
        
        int unitTiming = 1000;
        
        string decodeChar(char alpha) {
            switch (alpha) {
                case 'a': return ".-";
                case 'b': return "-...";
                case 'c': return "-.-.";
                case 'd': return "-..";
                case 'e': return ".";
                case 'f': return "..-.";
                case 'g': return "--.";
                case 'h': return "....";
                case 'i': return "..";
                case 'j': return ".---";
                case 'k': return "-.-.";
                case 'l': return ".-..";
                case 'm': return "--";
                case 'n': return "-.";
                case 'o': return "---";
                case 'p': return ".--.";
                case 'q': return "--.-";
                case 'r': return ".-.";
                case 's': return "...";
                case 't': return "-";
                case 'u': return "..-";
                case 'v': return "...-";
                case 'w': return ".--";
                case 'x': return "-..-";
                case 'y': return "-.--";
                case 'z': return "--..";
                default:  return "/";
            }
        }
        
        void decodeInput(string input) {
            for (int i = 0; i < input.length(); i++) {
                msgLength++;
                output[i] = decodeChar(input[i]);
            }
        }
        
        void indicateStartEnd(void (*blinkOn)(int), void (*blinkOff)(int)) {
                for(int i = 0; i < 3; i++) {
                    blinkOn(100);
                    blinkOff(100);
                }
                blinkOff(unitTiming);
        }
        
    public:
        string input;
        
        int& getUnitTiming(){ return unitTiming; };
        
        void translate(void (*blinkOn)(int), void (*blinkOff)(int)) {
            decodeInput(input);
            cout << "start" << endl;
            
            indicateStartEnd(blinkOn, blinkOff);
            
            for(int i = 0; i < msgLength; i++) {
                for(int j = 0; j < output[i].length(); j++) {
                    char symbol = char(output[i][j]);
                    cout << "symbol: " << symbol << endl;
                    
                    if(symbol == '.') {
                        blinkOn(unitTiming);
                        blinkOff(unitTiming);
                    } else if (symbol == '-') {
                        blinkOn(unitTiming * 3);
                        blinkOff(unitTiming);
                    } else if (symbol == '/') {
                        blinkOff(unitTiming * 3);
                    }
                }
                blinkOff(unitTiming * 3);
            }
            
            cout << "end" << endl;
            indicateStartEnd(blinkOn, blinkOff);
        }
};

void blinkOn(int unitTiming) {
    std::cout << "on " << "for: " << unitTiming / 1000 << " units" << std::endl;
    sleep(unitTiming / 1000);
}

void blinkOff(int unitTiming) {
    std::cout << "off " << "for: " << unitTiming / 1000 << " units" << std::endl;
    sleep(unitTiming / 1000);
}

int main() {
    Morse morse;
    morse.input = "a";
    morse.translate(&blinkOn, &blinkOff);
    return 0;
}