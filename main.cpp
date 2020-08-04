#include <iostream>
#include <ctime>
#include <time.h>
#include <cstdlib>

/*
Program for compare a 3 sorting algorithms, bubble sort, Quick Sort and hybrid Sort
(Quick sort with bubble sort on small part of array >=10)
on arrays with length 100, 1000, 10000, 100000 elements.
*/

using namespace std;
const int size1=100;
const int size2=1000;
const int size3=10000;
const int size4=100000;

// bubble sort
void booble_sort(int *d, int n)
{
    bool p;
    for(int i=0; i<n; i++)
    {
        p=false;
        for(int j = 1; j<n; j++)
        {
            if(d[j-1]>d[j])
            {
                swap(d[j-1],d[j]);
                /*int temp;
                temp = d[j-1];
                d[j-1]=d[j];
                d[j]=temp;*/
                p=true;
            }
        }
        if(p==false)break;
    }
}
// hybrid Sort bubble sort
void hybridBooble_sort(int *d,int first,int last)
{
    bool p;
    for(int i=first;i<last;i++)
    {
        p-false;
        for(int j=first;j<last;j++)
        {
            if(d[j]>d[j+1])
            {
                swap(d[j],d[j+1]);
                p=true;
            }
        }
        if(p==false)break;
    }

}

// pivot as a middle element of array
void quickSort(int *d,int first, int last)
{
    int i,j,pivot;

    i=(first + last)/2;
    pivot = d[i];
    d[i] = d[last];
    for(j=i=first; i<last; i++)
        if(d[i]<pivot)
        {
            swap(d[i],d[j]);
            j++;
        }
    d[last]=d[j];
    d[j]=pivot;
    if(first <j-1)
        quickSort(d,first,j-1);
    if(j+1<last)
        quickSort(d,j+1,last);
}

// hybrid Sort
void HybridSort(int *d,int first, int last,int r)
{
    if(first<last)
    {
        if((last - first) <=10)
        {
            hybridBooble_sort(d,first,last);
        }
        else
        {
            int i,j,pivot;

            i=(first + last)/2;
            pivot = d[i];
            d[i] = d[last];
            for(j=i=first; i<last; i++)
                if(d[i]<pivot)
                {
                    swap(d[i],d[j]);
                    j++;
                }
            d[last]=d[j];
            d[j]=pivot;
            if(first <j-1)
                HybridSort(d,first,j-1,r);
            if(j+1<last)
                HybridSort(d,j+1,last,r);

        }
    }
}


    void print_arr(int *tab,int n)
    {
        for(int i = 0; i<n; i++)
            cout<<tab[i]<<" ";

    }

    void CreateSortArr(int *tab,int r)
    {
        for(int i =0; i<r; i++)
            tab[i]=i;
    }
    void CreateUnSortArr(int *tab,int r)
    {
        for(int i = r; i>0; i--)
            tab[r-i]=i-1;
    }
    void CreateRandSortArr(int *tab,int r)
    {
        srand(time(NULL));
        for(int i = 0; i<r; i++)
            tab[i]=rand()%1000;
    }
    void CopyArr(int *tab,int *tab1,int r)
    {
        for(int i=0; i<r; i++)
            tab1[i]=tab[i];
    }

    int main()
    {
        int choice;
        int *tabOrginal;
        int *tabCopy1;
        int *tabCopy2;
        cout<<"Wybierz wielkosc tablicy: "<<endl;
        cout<<
            "1 - 100"<<
            "\n2 - 1000"<<
            "\n3 - 10000"<<
            "\n4 - 100000"<<endl;
        cin>>choice;
        int sizeTotal;
        switch(choice)
        {
        case 1:
            tabOrginal = new int[size1];
            tabCopy1 = new int[size1];
            tabCopy2 = new int[size1];
            sizeTotal=size1;
            break;
        case 2:
            tabOrginal = new int[size2];
            tabCopy1 = new int[size2];
            tabCopy2 = new int[size2];
            sizeTotal=size2;
            break;
        case 3:
            tabOrginal = new int[size3];
            tabCopy1 = new int[size3];
            tabCopy2 = new int[size3];
            sizeTotal=size3;
            break;
        case 4:
            tabOrginal = new int[size4];
            tabCopy1 = new int[size4];
            tabCopy2 = new int[size4];
            sizeTotal=size4;
            break;
        }
        cout<<"Wybierz rodzaj ustawien tablic: "<<endl;
        cout<<
            "1 - Posortowane"<<
            "\n2 - Posortowane odwrotnie"<<
            "\n3 - Posortowane losowo"<<endl;
        cin>>choice;

        switch(choice)
        {
        case 1:
            CreateSortArr(tabOrginal,sizeTotal);
            CopyArr(tabOrginal,tabCopy1,sizeTotal);
            CopyArr(tabOrginal,tabCopy2,sizeTotal);
            break;
        case 2:
            CreateUnSortArr(tabOrginal,sizeTotal);
            CopyArr(tabOrginal,tabCopy1,sizeTotal);
            CopyArr(tabOrginal,tabCopy2,sizeTotal);
            break;
        case 3:
            CreateRandSortArr(tabOrginal,sizeTotal);
            CopyArr(tabOrginal,tabCopy1,sizeTotal);
            CopyArr(tabOrginal,tabCopy2,sizeTotal);
            break;
        }

        /*print_arr(tabOrginal,sizeTotal);
        cout<<endl;
        //bubble_sort(tabOrginal,sizeTotal);
        //quickSort(tabOrginal,0,sizeTotal-1);
        HybridSort(tabOrginal,0,sizeTotal-1,sizeTotal);
        cout<<"wynik"<<endl;
        print_arr(tabOrginal,sizeTotal);*/


        double Time;
        clock_t start;
        clock_t finish;

        start =clock();
        booble_sort(tabOrginal,sizeTotal);
        finish = clock();;
        cout<<"\nPo sortowaniu bubble_sort: "<<endl;
        Time = 1000.0*(double)(finish-start)/CLOCKS_PER_SEC;
        cout<<"Sortowanie na tablicy "<<sizeTotal<<" elementowej"<<endl;
        cout<<"\nCzas: "<< Time<<" milisekund"<<endl;

        start =clock();
        quickSort(tabCopy1,0,sizeTotal-1);
        finish = clock();
        cout<<"\nPo sortowaniu quick sort: "<<endl;

        Time = 1000.0*(double)(finish-start)/CLOCKS_PER_SEC;
        cout<<"Sortowanie na tablicy "<<sizeTotal<<" elementowej"<<endl;
        cout<<"\nCzas: "<< Time <<" milisekund"<<endl;

        start =clock();
        HybridSort(tabCopy2,0,sizeTotal-1,sizeTotal);
        finish = clock();

        cout<<"\nPo sortowaniu Hybrydowym: "<<endl;
        Time = 1000.0*(double)(finish-start)/CLOCKS_PER_SEC;
        cout<<"Sortowanie na tablicy "<<sizeTotal<<" elementowej"<<endl;
        cout<<"\nCzas: "<< Time <<" milisekund"<<endl;



        delete [] tabOrginal;
        delete [] tabCopy1;
        delete [] tabCopy2;

        system("pause");

        return 0;
    }
