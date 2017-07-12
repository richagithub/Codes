   #include<stdio.h>
    #include<math.h>
    #include<stdlib.h>
    #include<string.h>
    #include<algorithm>
    using namespace std;
    int main()
    {
    int t;
    char st[1000000];
    int i=0;
    scanf("%d",&t);
    while(t--)
    {
    scanf(" %s",st);
    int mx=1,cur=1,j=0,ct=0;
    int len=strlen(st);
    /* Checking the 1st letter */            ----Test case 1
    if( st[0]=='=')
    {
       ct=1;
    }
    for(i=1;i<len;i++)
    {
 
     if(st[i]=='=')                          ----Test case 2
             {++ct;continue;}       //ignore all = sign and also count its frequency
 
    if(st[i]==st[j] )
          {cur=cur+1;  //count length of same signs sequences
            mx=max(mx,cur);
            j=i;       //j is last letter to be compared with this letter
          }
      else           
      {
         cur=1;j=i;
      }
 
    }
    if(mx==1 && ct==len)                    ----Test case 3
        printf("1\n");              //if and all letters are '=' sign then ans=1
    else
    printf("%d\n",mx+1);            //else ans is this
    }//while
    return 0;
    }
