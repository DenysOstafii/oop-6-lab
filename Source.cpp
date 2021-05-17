#include <iostream>
#define N 6

using namespace std;

template <class T>
class Array
{
private:
    T* M;
public:

    Array()
    {
        for (int n = 0; n < N; n++)
        {
            M = new T[n];
        }
    }
    ~Array()
    {
        delete[] M;
    }
    friend istream& operator>>(istream& in, Array<T>& Arr)
    {
        cout << "Input data : \n";
        for (int n = 0; n < N; n++)
        {
            in >> Arr.M[n];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, Array<T>& Arr)
    {
        for (int n = 0; n < N; n++)
        {
            out << Arr.M[n] << " ";
        }
        return out;

    }

    void Swap(T& ob, T& ob2)
    {
        T change = ob;
        ob = ob2;
        ob2 = change;
    }

    void Sort()
    {
        for (int n = 0; n < N - 1; ++n)
        {
            for (int m = 0; m < N - 1 - n; m++)
            {
                if (M[m] > M[m + 1])
                {
                    this->Swap(M[m], M[m + 1]);
                }
            }
        }
    }
};

int main()
{
    cout << "\t\tInt : " << endl;
    Array<int> Arr;
    cin >> Arr;
    Arr.Sort();
    cout << "Sorted integer Array " << endl;
    cout << Arr;

    cout << "\n\t\tDouble : " << endl;
    Array<double> Arr1;
    cin >> Arr1;
    Arr1.Sort();
    cout << "Sorted double Array " << endl;
    cout << Arr1;

    cout << "\n\t\tChar : " << endl;
    Array<char> Arr2;
    cin >> Arr2;
    Arr2.Sort();
    cout << "Sorted char Array " << endl;
    cout << Arr2;

    return 0;
}