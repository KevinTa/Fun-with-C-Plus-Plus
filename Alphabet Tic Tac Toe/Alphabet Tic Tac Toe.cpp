#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class game{
public:
    game();
    void display();
    void playerinput();
    void compinput();
    bool playerwin();
    bool compwin();
    bool fullboard();
    void winner();
private:
    char data1[4][4];
    char data2[4][4];
};

int main()
{
    game x;
    while(x.fullboard()!= true && x.compwin()!= true && x.playerwin() != true)
    {
    x.display();
    x.playerinput();
    x.compinput();
    }
    x.winner();
    return 0;
}
game::game()
{
    string a1 = "ABCDEFGHIJKLMNOP";
    string a2 = "BKMHPECJGNLAIDFO";
    int k = 0;
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            data1[i][j]=a1[k];
            data2[i][j]=a2[k];
            k++;
        }
    }
}

void game::display()
{
    cout<<"Table 1: "<<endl;
    for(int i = 0; i<4;i++)
    {
        for(int j = 0; j<4; j++)
        {
            cout<<data1[i][j]<<" ";
        }
        cout<< endl;
    }
    cout<<"Table 2: "<<endl;
    for(int k = 0; k<4;k++)
    {
        for(int l = 0; l<4; l++)
        {
            cout<<data2[k][l]<<" ";
        }
        cout<< endl;
    }
}

void game::playerinput()
{
    char x;
    cout<<"Enter letter on grid"<<endl;
    cin>>x;
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            if(x==data1[i][j])
            {
                data1[i][j]='0';
            }
            if(x==data2[i][j])
            {
                data2[i][j]='0';
            }

        }
    }
}

void game::compinput()
{
    char x;
    char arr[17]="ABCDEFGHIJKLMNOP";
    x=arr[rand() % 16];
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            if(x==data1[i][j])
            {
                data1[i][j]='1';
            }
            if(x==data2[i][j])
            {
                data2[i][j]='1';
            }

        }
    }
}

bool game::playerwin()
{
    bool table1 = true;
    bool table2 = true;
    bool f= false;
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            if(data1[i][j]!='0')
            {
                table1 = false;
            }

            if(data2[i][j]!='0')
            {
                table2 = false;
            }
        }
    }

    if(table1==true || table2==true)
    {
        f = true;
    }

    return f;
}
bool game::compwin()
{
    bool table1 = true;
    bool table2 = true;
    bool f= false;
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            if(data1[i][j]!='1')
            {
                table1 = false;
            }

            if(data2[i][j]!='1')
            {
                table2 = false;
            }
        }
    }

    if(table1==true || table2==true)
    {
        f = true;
    }

    return f;
}

bool game::fullboard()
{
    bool table1 = true;
    bool table2 = true;
    bool f= false;
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            if(data1[i][j]!='0' && data1[i][j]!='1')
            {
                table1 = false;
            }

            if(data2[i][j]!='0' && data2[i][j]!='1')
            {
                table2 = false;
            }
        }
    }

    if(table1==true && table2==true)
    {
        f = true;
    }

    return f;

}

void game::winner()
{
    if(compwin()==false && playerwin()==false)
    {
        cout<<"Tie"<<endl;
    }
    if(compwin()==true)
    {
        cout<<"Computer Wins"<<endl;
    }
    if(playerwin()==true)
    {
        cout<<"Player Wins"<<endl;
    }
}
