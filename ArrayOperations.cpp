//Dorota Dyczek
#include <iostream>
using namespace std;

int main ()
{

    int operation, number, j = 0, N;
    cin >> operation;

    while (j < operation)
    {

        cin >> N;
        int tab[N];
        int i = 0, temp = 0;
        while (i < N)
        {
            cin >> number;
            tab[i] = number;
            i++;
        }
        i = 0;
        while (i < N)
        {
            cout << tab[i] << " ";
            i++;
        }
        cout << endl;
        char LETTER;
        cin >> LETTER;
        int segment;
        while (LETTER != 'F')
        {

            if (LETTER == 'R')
            {
                
                int start, segment;
                cin >> start >> segment;
                if (segment <= N && segment != 0)
                {

                    if (start >= 0)
                    {
                        start = start % N;
                    }
                    else
                    {
                        start =
                                (N + (start % N)) % N;
                    }
                    int krotki = N;
                    while (krotki >= segment)
                    {
                        int indeks_1 = start, indeks_2 = start + segment - 1;
                        int i = 0;
                        while (i < segment / 2)
                        {
                            int zamien = tab[indeks_1 % N];

                            tab[indeks_1 % N] =
                                    tab[indeks_2 % N];
                            tab[indeks_2 % N] = zamien;
                            indeks_1++;
                            indeks_2--;
                            i++;
                        }

                        start += segment;
                        krotki -= segment;
                    }

                }
            }

            if (LETTER == 'S')
            {
                int start, fragment, shift;
                cin >> start >> fragment;
                if (fragment <= N && fragment != 0)
                {
                    if (start >= 0)
                    {
                        start = start % N;
                    }
                    else
                    {
                        start =
                                (N + (start % N)) % N;
                    }
                    int pary = N / fragment;
                    int indeks1 = start, indeks2 =
                            (start + fragment) % N, change;
                    segment = fragment;
                    if (segment >= 1)
                    {
                        pary = pary / 2;
                        while (pary > 0)
                        {
                            fragment = segment;
                            while (fragment > 0)
                            {
                                change = tab[indeks1 % N];
                                tab[indeks1 % N] =
                                        tab[indeks2 % N];
                                tab[indeks2 % N] = change;
                                fragment--;
                                indeks1++;
                                indeks2++;

                            }
                            indeks1 += segment;
                            indeks2 += segment;
                            pary--;

                        }
                    }

                }
            }
            if (LETTER == 'C')
            {
                int first_elem, lenght, shift;
                cin >> first_elem >> lenght >> shift;
                int before_shift = N;

                first_elem = (N + (first_elem % N)) % N;

                while(before_shift > 0)
                {
                    int curr_lenght;
                    if(before_shift > lenght){
                        curr_lenght = lenght;
                    }
                    else{
                        curr_lenght = before_shift;
                    }
                    before_shift -= curr_lenght;
                    
                    int curr_shift = (curr_lenght + (shift % curr_lenght)) % curr_lenght;

                    
                    int index1 = first_elem, index2 = first_elem + curr_lenght - 1;
                    while(index1 < index2){
                        int tmp = tab[index1 % N];
                        tab[index1 % N] = tab[index2 % N];
                        tab[index2 % N] = tmp;
                        index1++;
                        index2--;
                    }

                    index1 = first_elem;
                    index2 = first_elem + curr_shift - 1;
                    while(index1 < index2){
                        int tmp = tab[index1 % N];
                        tab[index1 % N] = tab[index2 % N];
                        tab[index2 % N] = tmp;
                        index1++;
                        index2--;
                    }

                    index1 = first_elem + curr_shift;
                    index2 = first_elem + curr_lenght - 1;
                    while(index1 < index2){
                        int tmp = tab[index1 % N];
                        tab[index1 % N] = tab[index2 % N];
                        tab[index2 % N] = tmp;
                        index1++;
                        index2--;
                    }
                    first_elem += curr_lenght;


                }


            }

            cin >> LETTER;
        }

        i = 0;
        while (i < N)
        {
            cout << tab[i] << " ";
            i++;
        }

        cout << endl;
        j++;
    }
    return 0;

}


