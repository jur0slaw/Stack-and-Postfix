#include <iostream>
#include <cstring>

using namespace std;

int ipow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

struct stosik{
     char tab[32];
     int licznik = -1;



     void push(char value){
        licznik++;
        tab[licznik]=value;
     }

     char pop(){
        if(isEmpty()==false)
        return tab[licznik--];
        else return 0;
     }

     char peek(){
        return tab[licznik];
     }

     bool isEmpty(){
        if(licznik==-1){
            return true;
            }else
                return false;
     }

     int size(){
        return licznik+1;
     }
};

int main()
{


    stosik stos;
    string wynik ;
    string arek = "A * (B + C) - D/(E - F)";
    int i=0;
    char rak;
    while(arek[i]!= 0 ){
        if(arek[i]>47 ){
            while(arek[i]>47){
                    wynik+=arek[i];

                    i++;
            }

            wynik+=',';
        }
        if(arek[i]==40){
            stos.push(arek[i]);
        }
        if(arek[i]==41){
            while(stos.peek()!=40){
                wynik+=stos.pop();
                wynik+=',';
            }
            stos.pop();
        }


        if(arek[i]>41 && arek[i]<48){
             if(arek[i]=='*' || arek[i]=='/'){
                    while(stos.peek()=='*' || stos.peek()=='/'){
                        wynik+=stos.pop();
                        wynik+=',';
                    }
                    stos.push(arek[i]);
             }
             if(arek[i]=='+' || arek[i]=='-' ){
                    while(stos.peek()=='*' || stos.peek()=='/' || stos.peek()=='+' || stos.peek()=='-' ){
                        wynik+=stos.pop();
                        wynik+=',';
                    }
                    stos.push(arek[i]);
             }
        }

        i++;
    }

    while(stos.isEmpty()==false){
        wynik+=stos.pop();
        wynik+=',';
    }

    cout << wynik << endl;


    char wejscie[16] = {6,5,15,'*','+'};



    stosik licz;
    char temp;
    i=0;
    while(wejscie[i]!=0){

        if(wejscie[i]>=0 && wejscie[i]<=16){

                licz.push(wejscie[i]);

        }
        switch((int)wejscie[i]){

            case '+':
                temp=licz.pop();
                licz.push(licz.pop()+temp);
                break;
            case '-':
                temp=licz.pop();
                licz.push(licz.pop()-temp);
                break;
            case '*':
                temp=licz.pop();
                licz.push(licz.pop()*temp);
                break;
            case '/':
                temp=licz.pop();
                licz.push(licz.pop()/temp);
                break;
        }
        i++;

    }

    cout << (int)licz.peek();

    return 0;
}
