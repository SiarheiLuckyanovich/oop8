#include <iostream>
#include <cmath>
#include <windows.h>
#include <chrono>

using namespace std;
//============================================================================================================
/*1. �������� ��������� ������� div, ������� ������ ��������� ��������� ������� ���� ����������
� ��������� ���������� DivisionByZero, ���� ������ �������� ����� 0.
� ������� main �������� ��������� ������ ������� div � �������, � ����� ������ ����������.*/
//============================================================================================================
template <class X> double div(X &a, X &b)
{
    if (b == 0.0)
    {
        throw "DivisionByZero";
    }
    else
    {
        return (a / b);
    }
}


//============================================================================================================
/*2. �������� ����� Ex, �������� ������������ ����� x � ������� ����������� �� ������������� �����,
 ���������������� x ��������� ���������. �������� ����� Bar,
 �������� ������������ ����� y (����������� �� ��������� �������������� ��� �����)
 � ������� ����� set � ������������ ������������ ���������� a. ���� y + a > 100,
 ������������ ���������� ���� Ex � ������� a*y, ����� � y ��������� �������� a.
 � ������� main ������� ���������� ������ Bar � � ����� � ����� try ������� � ���������� ����� n.
 ������������ ��� � �������� ��������� ������ set �� ��� ���, ���� �� ����� ������� 0.
 � ����������� ���������� �������� ��������� �� ������, ���������� ������ ������� ����������.*/
//============================================================================================================

class Ex
{
public:
    int x;
    Ex (int e_x) {x = e_x;}
};
class Bar
{
public:
    int y;
    Bar (){ y = 0;}
    int set (int a)
    {
        if (a != 0 && ( y + a ) > 100)
        {
            cout << " Error: ( y + a ) > 100 -> ( y * a)= " ;
            throw Ex( y * a);
        }
        else
        {
            y += a;
            cout << " ( y + a ) < 100 -> y = " << y << endl;
            return (y);
        }
    }
};


//============================================================================================================
/*3. �������� ����� ������, ������������ ����������� ������ �� ����� 10x10,
� �������� ���� �����, ���������� ������� ������������� �� �������� �������.
��� ������ ������ ��������� ������-���������� OffTheField, ���� ����� ������ ���� � �����,
� IllegalCommand, ���� ������ �������� ������� (����������� �� ��������� � ������ ���������).
������ ���������� ������ ��������� ��� ����������� ���������� � ������� ������� � ����������� ��������.
�������� ������� main, ������������ ���� ������� � ��������������� ��� ���������� �� ��� �������,
� ����� ��������� ��������� ���������� � ���� ����������� �������.*/
//============================================================================================================
void SetColor(int text, int background)
{
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
class robot
{
public:
const size_t SIZE {10U };
char CROSS = 'X';
char EMPTY = '_';
char m;
int ppField [9][9]{};
int r_x = 4;
int r_y = 4;


    robot (){}
    void __fastcall emptyField ()
    {

        for (size_t y = 0; y < SIZE; y++)
        {
            for (size_t x = 0; x < SIZE; x++)
            {
                ppField [y][x] = ' ';
            }
        }
    }
    void __fastcall printField()
    {
        SetColor( 13, 0);
        cout << "   ---====<<";
        SetColor( 12, 0);
        cout << "Move the robot!";
        SetColor( 13, 0);
        cout << " >>===---";
        cout << endl;
        cout << "       " ;
        for (size_t x = 0; x < SIZE; x++)
        {
            SetColor( 9, 0);
            cout << x+1 << "   ";
        }
        cout << endl;
        for (size_t y = 0; y < SIZE; y++)
        {
            SetColor( 9, 0);
            cout  << "  " << " " << y+1;
            SetColor( 7, 0);
            cout  << " | ";
            for (size_t x = 0; x < SIZE; x++)
            {
                SetColor( 7, 0);
                cout << static_cast <char> (ppField [y][x]) << " | ";
            }
            cout << endl;
            cout << endl;
        }
        SetColor( 3, 0);
        cout << endl << "   Robot: ";
    }
    void __fastcall getRobotCoord()
    {
        int r_x = 4;
        int r_y = 4;

            SetColor( 15, 0);
            cout << "  Move! " << endl;
            SetColor( 2, 0);
            cout << "   Enter the way (UP-W, DOWN-S, LEFT-A, RIGHT-D): ";
            cin >> m;
            if (m == 'w' || m == 'W')
            {
                r_y --;
            }
            if (m == 'd' || m == 'D')
            {
                r_x ++;
            }
            if (m == 's' || m == 'S')
            {
                r_y ++;
            }
            if (m == 'a' || m == 'A')
            {
                r_x --;
            }

           // ppField[r_y][r_x] = CROSS;
             cout << " " << r_y << " " << r_x;
            //return (r_x, r_y);
    }

};
//=========================================================================

//=========================================================================
//============================================================================================================
int main()
{
//============================================================================================================
cout << "1st task: Ex" << endl;
    cout << "Enter a numbers A & B: ";
    double a, b;
    cin >> a >> b;
    try
    {
        double d = div(a, b);
        cout << " " << a << " / " << " " << b << " = " << d << endl;
    }
        catch (const char* exception) // ��������� ���������� ���� const char*
    {
        cerr << "Error: " << exception << endl;
    }
cout << endl;
//============================================================================================================
//============================================================================================================
cout << "2st task: DivisionByZero" << endl;
    cout << "Enter a numbers A & B: ";
Bar y;
int n;
do
{
    cout << "Enter a integer ('0' to stop): ";
    cin >> n;
    try
    {
        y.set(n);
    }
        catch (const Ex& ex)
    {
        cerr << ex.x << endl;
    }
} while (n != 0);

cout << endl;
//============================================================================================================
//============================================================================================================
cout << "3st task: Robot" << endl;
robot r;
system("cls");
char answ = 'y';
cout << " " << r.r_y << " " << r.r_x;
//r.emptyField();
//r.printField();
do
{
    //cout << " " << r.r_y << " " << r.r_x;
    //system("cls");
    r.printField();
    r.getRobotCoord();
    //r.printField();
    //cout << "Do you wanna next move? (say yes): ";
    //cin >> answ;
} while (answ == 'y');



cout << endl;
//============================================================================================================
return 0;
}
