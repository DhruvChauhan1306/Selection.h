#include "selection.h"
using namespace std;

int main(){
    string option[] = {"1. Yes", "2. No"};      //Creating Custom Array
    setheader("Do you Want a Demo?\n");         //(optional) Use Header For Questions or Instructions
    setoptions(option,2);                       //Used for converting array to options
    setcolor(176);                              //(optional) Used to change colors: 0 to 255 available
    int input = getselection();                 //User input by key selection
    if(input==1){
        cout << "Yes selected";
    }else{
        cout << "No Selected";
    }
    cout << "\nPress Any Key to continue...";
    getch();

    //Another Example
    setcolor(233);
    string options[] = {" Green", " Yellow", " Violet", " Cyan", " Exit"};
    while(1){
        setheader("Select Your Favorite color: ");
        setoptions(options,5);
        input = getselection();
        switch(input){
            case 1:{
                setcolor(164);
                break;
            }
            case 2:{
                setcolor(236);
                break;
            }
            case 3:{
                setcolor(223);
                break;
            }
            case 4:{
                setcolor(176);
                break;
            }
            case 5:
            case 0:{
                exit(0);
            }
        }
    }
    return 0;
}
