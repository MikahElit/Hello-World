

// Including Libraries 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Declaring Variables for global scope
string token,c;
int ACC, M0, M1, M2, M3, M4, M5, M6, M7, M8, M9;

string nextToken(istream& infile);  // defined in "token.cpp"

// Defining function to recall integer values from memory
int holder(string c){
    int x;
    if ( c == "0"){
        x = M0;
    }
    else if ( c == "1"){
        x = M1;
    }
    else if ( c == "2"){
        x = M2;
    }
    else if ( c == "3"){
        x = M3;
    }
    else if ( c == "4"){
        x = M4;
    }
    else if ( c == "5"){
        x = M5;
    }
    else if ( c == "6"){
        x = M6;
    }
    else if ( c == "7"){
        x = M7;
    }
    else if ( c == "8"){
        x = M8;
    }
    else if ( c == "9"){
        x = M9;
    }
    return x;
        
}
//
// main:
//
int main()
{
    string filename;
    cout << "Filename> ";
    cin >> filename;
    
    // open the program file:
    ifstream infile(filename);
    
    if (!infile.good())
    {
        cout << "**Error: unable to open input file '" << filename << "'." << endl;
        return 0;
    }
    
    // read the contents of the file and echo to the console:
    token = nextToken(infile);
    while (token != "")
    {
        if (token == "in_i"){           //Input to Cache
            cin >> ACC;
        }
        if (token == "out_i"){          //Output to screen
            cout << ACC;
        }
        if (token == "add_i"){          //Addition
            token = nextToken(infile);
            c = token.at(0);
            if (c == "M"){
                c = token.at(1);
                ACC = ACC + holder(c);
            }
            else{
                ACC = ACC + stoi(token);
            }
        }
        if (token == "sub_i"){          //Substraction
            token = nextToken(infile);
            c = token.at(0);
            if (c == "M"){
                c = token.at(1);
                ACC = ACC - holder(c);
            }
            else{
                ACC = ACC - stoi(token);
            }
        }
        if (token == "mult_i"){         //Multiplication
            token = nextToken(infile);
            c = token.at(0);
            if (c == "M"){
                c = token.at(1);
                ACC = ACC * holder(c);
            }
            else{
                ACC = ACC * stoi(token);
            }
        }
        if (token == "div_i"){          //Division
            token = nextToken(infile);
            c = token.at(0);
            if (c == "M"){
                c = token.at(1);
                ACC = ACC / holder(c);
            }
            else{
                ACC = ACC / stoi(token);
            }
        }
        if (token == "mod_i"){          //Remainder 
            token = nextToken(infile);
            c = token.at(0);
            if (c == "M"){
                c = token.at(1);
                 ACC = ACC % holder(c);
            }
            else{
                ACC = ACC % stoi(token);
            }
        }
        if (token == "load_i"){         //Loading values to cache
            token = nextToken(infile);
            c = token.at(0);
            if (c == "M"){
                c = token.at(1);
                ACC = holder(c);
            }
            else{
                ACC = stoi(token);
            }
        }
        if (token == "store_i"){        //Storing Values to variables
            token = nextToken(infile);
            c = token.at(0);
            if (c == "M"){
                c = token.at(1);
                if ( c == "0"){
                    M0 = ACC;
                }
                else if ( c == "1"){
                    M1 = ACC;
                 }
                else if ( c == "2"){
                    M2 = ACC;
                }
                else if ( c == "3"){
                    M3 = ACC;
                }
                else if ( c == "4"){
                    M4 = ACC;
                }
                else if ( c == "5"){
                    M5 = ACC;
                }
                else if ( c == "6"){
                    M6 = ACC;
                }
                else if ( c == "7"){
                    M7 = ACC;
                }
                else if ( c == "8"){
                    M8 = ACC;
                }
                else if ( c == "9"){
                    M9 = ACC;
                }
            }
            else{
                ACC = stoi(token);
            }
        }
        if (token == "clear"){          // Sets all memory location to zero
            ACC = 0;
            M0 = 0;
            M1 = 0;
            M2 = 0;
            M3 = 0;
            M4 = 0;
            M5 = 0;
            M6 = 0;
            M7 = 0;
            M8 = 0;
            M9 = 0;
        }
        if (token == "out_s"){          //Output to screen
            token = nextToken(infile);
            cout << token;
        }
        if (token == "\n"){             //Next line
            token = nextToken(infile);
            cout << endl;
        }
        if (token == "end"){            //End program
            return (-1);
        }
        token = nextToken(infile);
    }
    //
    // done:
    //

    return 0;
}
