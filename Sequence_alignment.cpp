#include <bits/stdc++.h>

using namespace std;


int Min(int a,int b,int c)
{
    int smallest = 99999;

    if (a < smallest)
        smallest=a;
    if (b < smallest)
        smallest=b;
    if(c < smallest)
        smallest=c;

    return smallest;
}
void Penalty(string x, string y, int pxy, int pgap)
{
    int i, j;

    int a = x.length();
    int b = y.length();


    int dp[a+1][b+1] = {0};


    for (int k = 1; k <= a; k++)
    {
        for(int s=1; s<=b; s++)
        {
            dp[k][0] = dp[k-1][0] + pgap;
            dp[0][s] = dp[0][s-1] + pgap;
        }
    }


    for (i = 1; i <= a; i++)
    {
        for (j = 1; j <= b; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = Min(dp[i - 1][j - 1] + pxy,
                               dp[i - 1][j] + pgap,
                               dp[i][j - 1] + pgap);
            }
        }
    }


    int len = a + b;
    i = a;
    j = b;

    int x_pos = len;
    int y_pos = len;


    int x_arr[len+1], y_arr[len+1];

    while ( !(i == 0 && j == 0))
    {
        if (x[i - 1] == y[j - 1])
        {
            x_arr[x_pos--] = (int)x[i - 1];
            y_arr[y_pos--] = (int)y[j - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j - 1] + pxy == dp[i][j])
        {
            x_arr[x_pos--] = (int)x[i - 1];
            y_arr[y_pos--] = (int)y[j - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] + pgap == dp[i][j])
        {
            x_arr[x_pos--] = (int)x[i - 1];
            y_arr[y_pos--] = (int)'_';
            i--;
        }
        else if (dp[i][j - 1] + pgap == dp[i][j])
        {
            x_arr[x_pos--] = (int)'_';
            y_arr[y_pos--] = (int)y[j - 1];
            j--;
        }
    }
    while (x_pos > 0)
    {
        if (i > 0)
        {
            x_arr[x_pos--] = (int)x[i--];
        }
        else
        {
            x_arr[x_pos--] = (int)'_';
        }
    }
    while (y_pos > 0)
    {
        if (j > 0)
        {
            y_arr[y_pos--] = (int)y[j--];
        }
        else
        {
            y_arr[y_pos--] = (int)'_';
        }
    }


    int id = 1;
    for (i = len; i >= 1; i--)
    {
        if ((char)y_arr[i] == '_' && (char)x_arr[i] == '_')
        {
            id = i + 1;
            break;
        }
    }


    cout << "Minimum penalty aligning two problem is: ";
    cout << dp[a][b] << "\n";
    cout << "Aligned as:\n";
    for (i = id; i <= len; i++)
    {
        cout<<(char)x_arr[i];
    }
    cout << "\n";
    for (i = id; i <= len; i++)
    {
        cout << (char)y_arr[i];
    }
    return;
}



int main()
{

    string gene1;
    string gene2;
    cout<<"Enter the First String"<<endl;
    cin>>gene1;
    cout<<"Enter the Second String"<<endl;
    cin>>gene2;

    int p_xy;
    int p_gap;
    cout<<"Enter the value of gap penalty"<<endl;
    cin>>p_gap;
    cout<<"Enter the value of mismatch penalty"<<endl;
    cin>>p_xy;

    Penalty(gene1, gene2,p_xy, p_gap);
    return 0;
}
