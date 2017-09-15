#include <bits/stdc++.h>

using namespace std;

string abbreviation(string a, string b) {
    // Complete this function
    int l1=a.length(),l2=b.length();
    int i=0,j=0;
    char prev=' ';
    stringstream ss;
    for(i=0;i<l1;i++)
    {
        if( a[i]>=65 && a[i]<=90 )
        {
            if(b[j]==a[i])
                {prev=char(32);j++;}
            else if(b[j]!=a[i] && b[j]==prev)
             {prev=' ';j++;i--;}
            else
            {
                return "NO";
            }

        }
        else//a is small letters
        {
            if(a[i]-32 != b[j] )
              continue;
            else//if small and capital aplha are same
                prev=(char)(a[i]-32);
        }

       /*
        if(a[i]!=b[j] && a[i]!=b[j]+32)//small ! equal and capitals npt equal
        {
            if(a[i]>=65 && a[i]<=90)
                return "NO";


        }
        else if(a[i]== b[j] || a[i]==b[j]+32)
        {j++;}
        */

    }
    if(prev!=' ')
    {
        if(b[j]==prev)
        {j++;}
        
    }
    if(j<l2)
        return "NO";
    else
        return "YES";
}

int main() {
   // freopen("abbreviation.txt","r",stdin);//redirects standard input
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string a;
        cin >> a;
        string b;
        cin >> b;
        string result = abbreviation(a, b);
        cout << result << endl;
    }
    return 0;
}
