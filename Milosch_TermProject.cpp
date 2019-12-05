//Author:Nick Milosch
//Term Project
//This program asks the user a series of questions about an inorganic molecule
//It will then decide a point group for it and assign it an appropriate cahracter table
//Last date modified: 12/4/19

#include <iostream>
using namespace std;

// infinity sign unicode \u221E
//fuction to loop yes or no answer
char getYN(string prompt){
   char result;
   do {
       char result;
       cout <<prompt;
       cout <<"\n";
       cin >> result;
       if (cin.fail()){
           cout <<"Please enter a valid answer!\n";
           cin.clear();
           cin.ignore();
           cout <<"\n";
       }
       else if (result == 'y'){
           return result;
       }
       else if (result == 'n'){
           return result;
       }

   }while (true);
}
int main()
{
   char lowSymm = getYN("Does the Molecule have a low group of symmetry?");
    if (lowSymm == 'y'){
       cout <<"The point group of you molecule is either C1, Cs, or Ci" << endl;
    }
    else if (lowSymm == 'n'){
        char highSymm = getYN("Does the molecule have a high group of symmetry?");
        if (highSymm =='y'){
            cout <<"The point group of your molecule is either Td, Oh, C\u221Ev, D\u221Eh, or Ih\n";
        }
        else if (highSymm=='n'){
            int highrot;
            cout << "Please enter the Highest order of rotation for your molecule:\n";
            cin >> highrot;
            cout <<"\n";
            char perpC = getYN("Does the Molecule have a perpendicular C2 axis?");
            if (perpC == 'y'){
                cout <<"\n";
                char dSigh = getYN("Does the Molecule have a horizontal plane of reflection (\u03C3h)?");
                if (dSigh == 'y'){
                    cout << "The point group of your molecule is: D"<<highrot<<"h\n";
                }
                else if (dSigh == 'n'){
                    char dsigd = getYN("Does your Molecule have a diagonal plane of reflection (\u03C3d)?");
                    if (dsigd == 'y'){
                        cout <<"The point group of your molecule is: D"<<highrot<<"d\n";
                    }
                    else if (dsigd == 'n'){
                        cout << "The point group of your molecule is: D"<<highrot<<endl;
                    }
                }
                
            }
            else if (perpC == 'n'){
                char cSigH = getYN("Does the Molecule have a horizontal plane of reflection (\u03C3h)?");
                if (cSigH =='y'){
                    cout<<"The point group of your molecule is: C"<<highrot<<"h\n";
                }
                else if (cSigH =='n'){
                    char cSigv = getYN("Does your Molecule have a vertical plane of reflection (\u03C3v)?");
                    if (cSigv=='y'){
                        cout <<"The point group of your molecule is: C"<<highrot<<"v\n";
                    }
                    else if (cSigv =='n'){
                        char S2n= getYN("Does your molecule have an improper axis of rotation (S2n)?");
                            if (S2n=='y'){
                                cout<<"The point group of your molecule is: S2"<<highrot<<endl;
                            }
                            else if (S2n == 'n'){
                                cout <<"The point group of your molecule is: C"<<highrot<<endl;
                            }
                        }
                    }
                }
                
            }
            
        }

     
    cout <<"\n";
    string pointGroup;
    cout <<"Just a Heads up, There are a total of 63 point groups\n";
    cout <<"if your character table doesnt come up then theres a good chance you did something wrong!\n";
    cout <<"\n";
    cout <<"Please enter your point group\n";
    cin >>pointGroup;
    
    //sigma unicode \u03C3
    if (pointGroup == "C1")
    {
        cout <<"Here is the Character table for "<<pointGroup <<":"<<endl;
        cout <<"C1"<< "\t" <<"E\n";
        cout <<"A"<< "\t" << "-1\n";
    }
    
    else if (pointGroup == "Cs")
    {
        cout <<"Here is the Character table for "<<pointGroup <<":"<<endl;
        cout <<"Cs"<< "\t"<<"E"<< "\t"<<"\u03C3(h)\n";  
        cout <<"A'"<<"\t"<<"+1"<<"\t"<<"+1\n";                  
        cout <<"A'"<<"\t"<<"+1"<<"\t"<<"-1\n";                    
    }
    
    else if (pointGroup == "Ci")
    {
        cout <<"Here is the Character table for "<<pointGroup <<":"<<endl;
        cout <<"Ci"<< "\t"<<"E"<< "\t"<<"i/n";	
        cout <<"Ag"<< "\t"<<"+1"<< "\t"<<"+1\n";
        cout <<"Au"<< "\t"<<"+1"<< "\t"<<"-1\n";	
    }
    
    else if (pointGroup == "C2")
    {
        cout <<"Here is the Character table for "<<pointGroup <<":"<<endl;
        cout <<"C2"<< "\t"<<"E"<< "\t"<<"C2\n";	
        cout <<"A"<< "\t"<<"+1"<< "\t"<<"+1\n";
        cout <<"B"<< "\t"<<	"+1"<< "\t"<<	"-1\n";
    }
    
    else if (pointGroup == "C2v")
    {
        cout <<"Here is the Character table for "<<pointGroup <<":"<<endl;
        cout <<"C2v"<< "\t"<<"E"<< "\t"<<"C2(z)"<< "\t"<<"\u03C3v(xz)"<< "\t"<<"\u03C3v(yz)\n";	
        cout <<"A1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1\n";	
        cout <<"A2"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"-1"<< "\t"<<"+1\n";
        cout <<"B1"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"+1"<< "\t"<<"-1\n";
        cout <<"B2"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"-1"<< "\t"<<"+1\n";
    }
    else if (pointGroup == "D2")
    {
        cout << "Here is the character table for "<<pointGroup<<":"<<endl;
        cout <<"D2"<< "\t"<<"E"<< "\t"<<"C2z"<< "\t"<<"C2y"<< "\t"<<"C2x\n";
        cout <<"A"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1\n";
        cout <<"B1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"-1\n";
        cout <<"B2"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"+1"<< "\t"<<"-1\n";
        cout <<"B3"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"-1"<< "\t"<<"+1\n";
    }
    else if (pointGroup=="D3")
    {
        cout << "Here is the character table for "<<pointGroup<<":"<<endl;
        cout << "D3"<< "\t"<<"E"<< "\t"<<"2C3(z)"<< "\t"<<"3C'2\n";
        cout <<"A1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1\n";
        cout <<"A2"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"-1\n";
        cout <<"E"<< "\t"<<"+2"<< "\t"<<"-1"<< "\t"<<"0\n";
    }
    else if (pointGroup== "C3v")
    {
        cout << "Here is the character table for "<<pointGroup<<":"<<endl;
        cout << "D3"<< "\t"<<"E"<< "\t"<<"2C3(z)"<< "\t"<<"3C'2\n";
        cout <<"A1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1\n";
        cout <<"A2"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"-1\n";
        cout <<"E"<< "\t"<<"+2"<< "\t"<<"-1"<< "\t"<<"0\n";
    }
    else if (pointGroup=="C4v")
    {
        cout << "Here is the character table for "<<pointGroup<<":"<<endl;
        cout <<"C4v"<< "\t"<<"E"<< "\t"<<"C2"<<"\t"<<"C2"<< "\t"<<"2\u03C3v"<<"\t"<<"2\u03C3h\n";
        cout<<"A1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1\n";
        cout<<"A2"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"-1\n";
        cout<<"B1"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"-1\n";
        cout<<"B2"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"+1\n";
        cout<<"E"<< "\t"<<"+2"<< "\t"<<"0"<< "\t"<<"-2"<< "\t"<<"0"<< "\t" <<"0\n";
    }
    else if (pointGroup=="C2h")
    {
        cout << "Here is the character table for "<<pointGroup<<":"<<endl;
        cout<<"C2h"<< "\t"<<"E"<< "\t"<<"C2z"<< "\t"<<"i"<< "\t"<<"\u03C3h\n";
        cout<<"Ag"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1\n";
        cout<<"Bg"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"+1"<< "\t"<<"-1\n";
        cout<<"Au"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"-1\n";
        cout<<"Bu"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"-1"<< "\t"<<"+1\n";
    }
    else if (pointGroup=="C3h")
    {
        cout<<"Well you managed to find a molecule wiht a point group that you will never use in this class\n";
        cout<<"Theres a better chance you did something wrong, try again!\n";
    }
    else if (pointGroup== "D2h")
    {
        cout<<"Here is the character table for "<<pointGroup<<":"<<endl;
        cout<<"D2h"<<"\t"<<"E"<<"\t"<<"C2z"<< "\t"<<"C2y"<< "\t"<<"C2x"<< "\t"<<"i"<< "\t"<<"\u03C3xy"<< "\t"<<"\u03C3xz"<< "\t"<<"\u03C3yz\n";
        cout<<"Ag"<<"\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1\n";
        cout<<"B1g"<<"\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"-1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"-1\n";
        cout<<"B2g"<<"\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"+1"<< "\t"<<"-1\n";
        cout<<"B3g"<<"\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"-1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"-1"<< "\t"<<"+1\n";
        cout<<"Au"<<"\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"-1"<< "\t"<<"-1"<< "\t"<<"-1\n";
        cout<<"B1u"<<"\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"-1"<< "\t"<<"-1"<< "\t"<<"-1"<< "\t"<<"+1"<< "\t"<<"+1\n";
        cout<<"B2u"<<"\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"-1"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"+1\n";
        cout<<"B3u"<<"\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"-1"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"-1\n";
    }
    else if (pointGroup== "D3h")
    {
        cout<<"Here is the character table for "<<pointGroup<<":"<<endl;
        cout<<"D3h"<<"\t"<<"E"<<"\t"<<"2C3z"<<"\t"<<"3C'2"<< "\t"<<"\u03C3hxy"<< "\t"<<"2S3"<< "\t"<<"3\u03C3v\n";
        cout<<"A'1"<<"\t"<<"+1"<<"\t"<<"+1"<<"\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1\n";
        cout<<"A'2"<<"\t"<<"+1"<<"\t"<<"+1"<<"\t"<<"-1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"-1\n";
        cout<<"E'"<<"\t"<<"+2"<<"\t"<<"-1"<<"\t"<<"0"<< "\t"<<"+2"<< "\t"<<"-1"<< "\t"<<"0\n";
        cout<<"A''1"<<"\t"<<"+1"<<"\t"<<"+1"<<"\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"-1"<< "\t"<<"-1\n";
        cout<<"A''2"<<"\t"<<"+1"<<"\t"<<"+1"<<"\t"<<"-1"<< "\t"<<"-1"<< "\t"<<"-1"<< "\t"<<"+1\n";
        cout<<"E''"<<"\t"<<"+2"<<"\t"<<"-1"<<"\t"<<"0"<< "\t"<<"+2"<< "\t"<<"-1"<< "\t"<<"0\n";
    }
    else if (pointGroup=="D2d")
    {
        cout << "Here is the character table for "<<pointGroup<<":"<<endl;
        cout <<"D2d"<< "\t"<<"E"<< "\t"<<"2S4"<<"\t"<<"C2z"<< "\t"<<"2C'2"<<"\t"<<"2\u03C3d\n";
        cout<<"A1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1\n";
        cout<<"A2"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"-1\n";
        cout<<"B1"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"+1"<< "\t"<<"+1"<< "\t"<<"-1\n";
        cout<<"B2"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"+1"<< "\t"<<"-1"<< "\t"<<"+1\n";
        cout<<"E"<< "\t"<<"+2"<< "\t"<<"0"<< "\t"<<"-2"<< "\t"<<"0"<< "\t" <<"0\n";
    }
    else if (pointGroup == "Ci")
    {
        cout << "Here is the character table for "<<pointGroup<<":"<<endl;
        cout <<"Ci"<< "\t"<<"E"<< "\t"<<"i\n";  
        cout <<"Ag"<<"\t"<<"+1"<<"\t"<<"+1\n";                  
        cout <<"Au"<<"\t"<<"+1"<<"\t"<<"-1\n";
    }

return 0;
}