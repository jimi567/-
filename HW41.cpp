#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
  ifstream inStream;;
  int numTestCases;
  inStream.open("input.txt");
  if(inStream.fail())
  {
    cerr <<"input file opening failed. \n";
    exit(1);
  }

  inStream >> numTestCases;

  for (int i=0; i<numTestCases; i++)
  {
    int n ;
    inStream >> n;
    int ret[n][n];

    if (n%4 == 0){

      int a[n][n];
      int b[n][n];

      for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
          a[i][j] = ((i+1) % 4) / 2;
          b[j][i] = ((i+1) % 4) / 2;
        }
      }
      int num =1;
      for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
          if (a[i][j] == b[i][j]){
            ret[i][j] = (n*n+1)-num;
            num++;
          }
          else
            ret[i][j] = num++;
        }
      }
    }
    else{
      int i, j, s3, t, s, m;
       int js, is=0;

       m = ((n - 2) / 4);
       s = (m * 2) + 1;
       s3 = ((s - 3) / 2);

       for (i = 1;i <= n;i++) {
           if ((i % 2) > 0)
               is++;
           js = 0;

           for (j = 1;j <= n;j++) {
               if ((j % 2) > 0)
                   js++;

               t = ((((is + (js * 2) - 2) % s) + s*((s3 + is + js)%s)) * 4) + 1;

               if ((i % 2) > 0) {
                   if ((is > m + 2) || ((is == m + 2) && (js != m + 1)) || ((is == m + 1) && (js == m + 1))) {
                       if ((j % 2) > 0) {
                           ret[i - 1][j - 1] = t;
                       }
                       else {
                           ret[i - 1][j - 1] = t + 3;
                       }
                   }
                   else {
                       if ((j % 2) > 0)
                           ret[i - 1][j - 1] = t + 3;
                       else
                           ret[i - 1][j - 1] = t;
                   }
               }
               else {
                   if (is < m + 3) {
                       if (j % 2 > 0) {
                           ret[i - 1][j - 1] = t + 1;
                       }
                       else
                           ret[i - 1][j - 1] = t + 2;
                   }
                   else {
                       if (j % 2 > 0) {
                           ret[i - 1][j - 1] = t + 2;
                       }
                       else
                           ret[i - 1][j - 1] = t + 1;
                   }
               }
           }
       }

   }


    for (int i=0; i<n;i++){
      for (int j=0; j<n;j++){
        cout << ret[i][j] << ' ';
      }
      cout << endl;
    }
  }

  inStream.close();
}
