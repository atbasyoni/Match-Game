#include <iostream>
#include <iomanip>

using namespace std;

const int ROWS_NUM = 4 , COLS_NUM = 4;

char menu ();
void shulffeArray (char arrangArray[][COLS_NUM], int num_rows);
void gameInterface (char cipherArray [][COLS_NUM], int num_rows);
void choice (char Array [][COLS_NUM], int num_rows, string p1, string p2);

int main()
{
    int row_nums = 4;
    string p1,p2;
    char Array [ROWS_NUM][COLS_NUM] = {'1', '1', '2', '2', '3', '3', '4', '4', '5', '5', '6', '6', '7', '7', '8', '8'};

    if (menu () == '1')
    {
        cout << "Player (1) Enter Your Name : ";
        cin >> p1;
        cout << "Player (2) Enter Your Name : ";
        cin >> p2;
    }

    else if (menu () == 'q' || menu () == 'Q')
    {
        return 0;
    }

    shulffeArray (Array, row_nums);
    choice (Array, row_nums, p1, p2);

}

char menu ()
{
    char option;

    cout << "Welcome To The Match Game" << endl;
    cout << "1 - Play Now" << endl;
    cout << "Q - Quit" << endl;
    cin >> option;

    return option;
}

void shulffeArray (char arrangArray [][COLS_NUM], int num_rows)
{
    char tmp;
    arrangArray [ROWS_NUM][COLS_NUM];

    for (int i = 0 ; i < 1 ; i++)
    {
      for (int j = 0 ; j < 4 ; j++)
      {
          tmp = arrangArray [j][i+1];
          arrangArray [j][i+1] = arrangArray [j][i+2];
          arrangArray [j][i+2] = tmp;
      }
    }

    for (int m = 0 ; m < 2 ; m++)
    {
        for (int n = 0 ; n <= 2 ; n+=2)
        {
            tmp = arrangArray [n][m+2];
            arrangArray [n][m+2] = arrangArray [n+1][m+2];
            arrangArray [n+1][m+2] = tmp;
        }
    }

    for (int o = 0 ; o < 3 ; o++)
    {
        tmp = arrangArray [o][o];
        arrangArray [o][o] = arrangArray [o+1][o+1];
        arrangArray [o+1][o+1] = tmp;
    }

}


void gameInterface (char cipherArray [][COLS_NUM], int num_rows)
{

    cout << setw(5) << "1" << setw(2) << "2" << setw(2) << "3" << setw(2) << "4" << endl;
    cout << "------------" << endl;
    for (int i = 1 ; i <= 4 ; i++)
    {
        cout << i << setw (2) << "|" << setw(2);
        for (int j = 1 ; j <= 4 ; j++)
        {
            if (j == 4)
            {
                cout << cipherArray[i-1][j-1] << endl;
            }
            else
            {
                cout << cipherArray[i-1][j-1] << setw(2);
            }
        }
    }
}

void choice (char Array [][COLS_NUM], int num_rows, string p1, string p2)
{
    char tmp1, tmp2;
    char cipherArray [ROWS_NUM][COLS_NUM] = {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'};
    int cont[2] = {0, 0};

    while (true)
    {
        for (int i = 1 ; i <= 2 ; i++)
        {
            gameInterface (cipherArray, num_rows);

            int v, w, x, y;

            cout << endl;
            cout << p1 << i << " Enter The First Choice Row & Columne : ";
            cin >> v >> w;

            cout << p1 << i << " Enter The Second Choice Row & Columne : ";
            cin >> x >> y;
            cout << endl;


            if (v <= 4 && w <= 4 && x <= 4 && y <= 4)
            {
                if (Array[v-1][w-1] == Array[x-1][y-1])
                {
                    tmp1 = cipherArray[v-1][w-1];
                    cipherArray[v-1][w-1] = Array [v-1][w-1];
                    Array [v-1][w-1] = tmp1;

                    tmp2 = cipherArray[x-1][y-1];
                    cipherArray[x-1][y-1] = Array [x-1][y-1];
                    Array [x-1][y-1] = tmp2;
                    cont[i-1]++;
                }
            }

            else
            {
                cout << "Invaild Number" << endl;
                cout << endl;
            }
            cout << p1 << " : " << cont[0] << " | " << p2 << " : " << cont[1] << endl;
            cout << endl;
        }
    }


}

