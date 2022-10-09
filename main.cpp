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
//============================================================================================================
class OffTheField
{
private:
string m_error;
public:
OffTheField(string error) : m_error(error)
{ }
const char* getError() { return m_error.c_str(); }
};
//============================================================================================================
class IllegalCommand
{
string m_error;
public:
IllegalCommand (string error) : m_error(error)
{ }
const char* getError() { return m_error.c_str(); }
};
//============================================================================================================
class robot
{
public:
const size_t SIZE {10U };
char m;
int Field [9][9];
int* ppField = new int ;
int r_x = 4;
int r_y = 4;

    robot (){}
    ~robot(){}
    void  emptyField ()
    {

        for (size_t y = 0; y < SIZE; y++)
        {
            for (size_t x = 0; x < SIZE; x++)
            {
                Field [y][x] = ' ';
            }
        }
    }

    void printField()
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
                cout << static_cast <char> (Field [y][x]) << " | ";
            }
            cout << endl;
            cout << endl;
        }
        SetColor( 3, 0);
        cout << endl << "Robot coord X = " << r_y << ", Y = " << r_x;;
    }
    void getRobotCoord()
    {
        int x = r_x;
        int y = r_y;

            SetColor( 10, 0);
            cout << "  Move! " << endl;
            SetColor( 9, 0);
            cout << "   Enter the way (UP-W, DOWN-S, LEFT-A, RIGHT-D): ";
            cin >> m;
            if ( m != 'w' && m != 's' && m != 'd' && m != 'a' && m != 'W' && m != 'S' && m != 'D' && m != 'A')
            {
                throw IllegalCommand (" Error: wrong way.");
            }
            if (m == 'w' || m == 'W')
            {
                y --;
            }
            if (m == 'd' || m == 'D')
            {
                x ++;
            }
            if (m == 's' || m == 'S')
            {
                y ++;
            }
            if (m == 'a' || m == 'A')
            {
                x --;
            }
            if ( y > 9 || y <0 || x > 9 || x <0 )
            {
                throw OffTheField (" Error: The robot cannot leave the Field");
            }
            else
            {
                //Field[r_y][r_x] = 'X';
                SetColor( 11, 0);
                r_y = y; r_x = x;
                cout << "Robot coord X = " << r_y << ", Y = " << r_x << endl;
            }
    }
};

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
cout << "2st task: Ex & Bar " << endl;
cout << endl;
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
//system("cls");
char answ = 'y';

do
{
    try
    {
        SetColor( 11, 0);
        system("cls");
        cout << "Robot coord X = " << r.r_y << ", Y = " << r.r_x;
        //r.emptyField();
        //r.printField();
        r.getRobotCoord();
        //system("cls");
        //r.printField();
    }
    catch (const OffTheField& off)
    {
        SetColor( 4, 0);
        cerr << " Error: The robot cannot leave the Field " << endl;
    }
    catch (const IllegalCommand& ill)
    {
        SetColor( 4, 0);
        cerr << " Error: wrong way." << endl;
    }



    SetColor( 15, 0);
    cout << "Do you wanna next move? (say yes): ";
    cin >> answ;
} while ( answ == 'y' );



cout << endl;
//============================================================================================================
return 0;
}
