#include <iostream>
using namespace std;
char letra=65;
void printOptimalParens(int** kArray, int i, int j)
{
    if(i==j)
    {
        cout<<letra<<" ";
        letra++;
    }
    else
    {
        cout<<"(";
        printOptimalParens(kArray,i, kArray[i][j]);
        printOptimalParens(kArray, kArray[i][j] + 1, j);
        cout<<")";
    }
}

int main()
{
    int numMat;
    cout<<"Numero de matrices: "<<endl;
    cin>>numMat;
    
    int *p;
    int psize = numMat + 1;
    p = new int[psize];
    
    cout<<"Ingresar arreglo de dimensiones"<<endl;
    for(int i = 0; i < psize; i++){
        cin>>p[i];
    }
    
    //an array which holds the cost table
    int **cost;
    cost = new int*[psize];  // sets up an array of row pointers
    for(int i =0; i < psize; i++)
    {
        cost[i] = new int[psize]; // allocates each row of the grades array
    }
    
    //an array which holds the splits
    int ** kArray;
    kArray = new int*[psize];
    for(int i=0; i<(psize); i++)
    {
        kArray[i]=new int[psize];
    }
    
    for(int length = 1; length < numMat; length++)
    {
        for(int i = 1; i<numMat-length + 1; i++)
        {
            
            int j = i+ length;
            int tempCost;
            int k = i;
            int minCost = cost[i][k] + cost[k+1][j] + p[i-1]*p[k]*p[j];
            int kay = i;
            for(; k<j; k++)
            {
                tempCost = cost[i][k] + cost[k+1][j] + p[i-1]*p[k]*p[j];
                if(tempCost<minCost)
                {
                    minCost = tempCost;
                    kay = k;
                }
            }
            
            cost[i][j] = minCost;
            kArray[i][j] = kay;
        }
    }
    
    printOptimalParens(kArray, 1, numMat);
    cout<<endl;
    return 0;
}

