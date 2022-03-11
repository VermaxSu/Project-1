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
    const int N = 26;       //количество букв/цифр/слов в словаре

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

    int random; //переменная для случайного выбора
    int score = 0;  //счетчик верно введенных букв/цифр/слов
    const float secs = 60;  //время,отведенное на выполнение заданий
    char S[N] = ""; //вводимое слово
    int k = 0;  //общий счетчик ввода
    int size = 0;
    const float delay = secs * CLOCKS_PER_SEC;
    clock_t start = clock();    //системное время, прошедшее с момента запуска программы

    cout<<"Добро пожаловать в Клавиатурный тренажер."<<endl
        <<"Программа предназначена для английской раскладки клавиатуры."<<endl
        <<"Разбалловка и условия прохождения уровнений программы."<<endl
        <<"Минимальный возможный балл после прохождения уровня - 2. Максимальный - 10."<<endl
        <<"Граммотность: без ошибок - 5 баллов, 1-3 ошибки - 4 балла, 4-5 ошибок - 3 балла, 6-10 ошибок - 2 балла, 11 и более - 1 балл."<<endl
        <<"Скоропись: 200 и более знаков в минуту - 5 баллов, 180-200 зн./мин. - 4 балла, 160-180 зн./мин. - 3 балла, 130-160 зн./мин. - 2 балла, менее 130 зн./мин. - 1 балл."<<endl
        <<"Получить меньше 2-х баллов или неполучить их вообще - нельзя."<<endl
        <<"На выполнение уровня дается 1 минута. Чем больше выполните, тем лучше.Не забывайте про аккуратность и грамотность."
        <<"Выберете предпочитаемый уровень:"<<endl<<"1)Буквы"<<endl<<"2)Цифры"<<endl<<"3)Слова"<<endl;

    cin>>level;
    while (level < 1 || level > 3){
        cout<<"Error."<<endl<<" Выберете из предложенных 3-х вариантов."<<endl;
        cin>>level;
    }

    if (level == 3)
    {
        while (clock() - start < delay){
            random = rand() % N;
            cout << "Введите слово:\t " << DictionaryOfWords[random] <<'\n';
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
            cout << "Введите букву:\t " << DictionaryOfLetters[random] << '\n';
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
            cout << "Введите цифру:\t " << DictionaryOfNumbers[random] << '\n';
            scanf("%s",S);
            if (strcmp(S, DictionaryOfNumbers[random]) == 0)
                score++;
            k++;
            size += strlen(S);
        }
    }

    if (k - score == 0)
        cout<<"Балл за граммотность: 5";
    else if (k - score <= 3)
        cout<<"Балл за граммотность: 4";
    else if (k - score <= 5)
        cout<<"Балл за граммотность: 3";
    else if (k - score <= 10)
        cout<<"Балл за граммотность: 2";
    else cout<<"Балл за граммотность: 1";
    cout<<endl<<endl;
    if (size >= 200)
        cout<<"Балл за скорость набора: 5";
    else if (size >= 180)
        cout<<"Балл за скорость набора: 4";
    else if (size >= 160)
        cout<<"Балл за скорость набора: 3";
    else if (size >= 130)
        cout<<"Балл за скорость набора: 2";
    else cout<<"Балл за скорость набора: 1";

}