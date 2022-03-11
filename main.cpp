#include <iostream>
#include <ctime>
#include <clocale>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    int level;
    srand(time(nullptr));
    const int N = 26;       //���������� ����/����/���� � �������

    const char* const DictionaryOfWords[N] = {
            "hello", "world","goodbye",
            "monday","tuesday","wednesday",
            "thursday","friday","saturday",
            "sunday","mother","father",
            "brother","sister","one",
            "two","three","four",
            "five","six","seven",
            "eight","nine","ten",
            "eleven","twelve"
    };

    const char* const DictionaryOfLetters [N] = {
            "a","b","c","d","e",
            "f","g","h","i","j",
            "k","l","m","n","o",
            "p","q","r","s","t",
            "u","v","w","x","y","z"
    };

    const char* const DictionaryOfNumbers [N] = {
            "1","2","3","4","5",
            "6","7","8","9","0",
            "10","11","12","13",
            "14","15","16","17",
            "18","19","20","21",
            "22","23","24","25"
    };

    int random; //���������� ��� ���������� ������
    int score = 0;  //������� ����� ��������� ����/����/����
    const float secs = 60;  //�����,���������� �� ���������� �������
    char S[N] = ""; //�������� �����
    int k = 0;  //����� ������� �����
    int size = 0;
    const float delay = secs * CLOCKS_PER_SEC;
    clock_t start = clock();    //��������� �����, ��������� � ������� ������� ���������

    cout<<"����� ���������� � ������������ ��������."<<endl
        <<"��������� ������������� ��� ���������� ��������� ����������."<<endl
        <<"����������� � ������� ����������� ��������� ���������."<<endl
        <<"����������� ��������� ���� ����� ����������� ������ - 2. ������������ - 10."<<endl
        <<"������������: ��� ������ - 5 ������, 1-3 ������ - 4 �����, 4-5 ������ - 3 �����, 6-10 ������ - 2 �����, 11 � ����� - 1 ����."<<endl
        <<"���������: 200 � ����� ������ � ������ - 5 ������, 180-200 ��./���. - 4 �����, 160-180 ��./���. - 3 �����, 130-160 ��./���. - 2 �����, ����� 130 ��./���. - 1 ����."<<endl
        <<"�������� ������ 2-� ������ ��� ���������� �� ������ - ������."<<endl
        <<"�� ���������� ������ ������ 1 ������. ��� ������ ���������, ��� �����.�� ��������� ��� ������������ � �����������."
        <<"�������� �������������� �������:"<<endl<<"1)�����"<<endl<<"2)�����"<<endl<<"3)�����"<<endl;

    cin>>level;
    while (level < 1 || level > 3){
        cout<<"Error."<<endl<<" �������� �� ������������ 3-� ���������."<<endl;
        cin>>level;
    }

    if (level == 3)
    {
        while (clock() - start < delay){
            random = rand() % N;
            cout << "������� �����:\t " << DictionaryOfWords[random] <<'\n';
            scanf("%s",S);
            if (strcmp(S, DictionaryOfWords[random]) == 0)
                score++;
            k++;
            size += strlen(S);
        }
    }

    if (level == 1)
    {
        while (clock() - start < delay){
            random = rand() % N;
            cout << "������� �����:\t " << DictionaryOfLetters[random] << '\n';
            scanf("%s",S);
            if (strcmp(S, DictionaryOfLetters[random]) == 0)
                score++;
            k++;
            size += strlen(S);
        }
    }

    if (level == 2)
    {
        while (clock() - start < delay){
            random = rand() % N;
            cout << "������� �����:\t " << DictionaryOfNumbers[random] << '\n';
            scanf("%s",S);
            if (strcmp(S, DictionaryOfNumbers[random]) == 0)
                score++;
            k++;
            size += strlen(S);
        }
    }

    if (k - score == 0)
        cout<<"���� �� ������������: 5";
    else if (k - score <= 3)
        cout<<"���� �� ������������: 4";
    else if (k - score <= 5)
        cout<<"���� �� ������������: 3";
    else if (k - score <= 10)
        cout<<"���� �� ������������: 2";
    else cout<<"���� �� ������������: 1";
    cout<<endl<<endl;
    if (size >= 200)
        cout<<"���� �� �������� ������: 5";
    else if (size >= 180)
        cout<<"���� �� �������� ������: 4";
    else if (size >= 160)
        cout<<"���� �� �������� ������: 3";
    else if (size >= 130)
        cout<<"���� �� �������� ������: 2";
    else cout<<"���� �� �������� ������: 1";

}