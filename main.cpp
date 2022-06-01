#include <iostream>
#include <list>
using namespace std;
int Check_int()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::cout << "Число: ";
        int a;
        std::cin >> a;

        if (std::cin.fail() ) // если предыдущее извлечение оказалось неудачным,
        {
            std::cout<<"Введите нормально\n";
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}
std::string Check_string()
{
    int i;
    std::string str;
    do{
        std::cout<<"Строка: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') or (str[0]!=toupper(str[0])) )
                break;
        }

        if( str[i]){std::cout<<" Строку нужновводить с Большой буквы и без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
}

int Check_choice(){
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        cout<<"1 - добавить в начало, 2 - добавить в конец, 3 - добавить в произвольное место"<<endl;
        std::cout << "Ваш выбор: ";
        int a;
        std::cin >> a;

        if (std::cin.fail() or (a<=0) or (a>3)) // если предыдущее извлечение оказалось неудачным,
        {
            std::cout<<"Введите нормально\n";
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}

class A_class{
    public:
    int a;
    string some_string;
    A_class(){a=10; some_string="Something";}

    std::list<A_class> Array;

    int Special_check();

    void addData(int some_case)
    {

        this->a = Check_int();
        this->some_string = Check_string();

        if (some_case==1){Array.push_front(*this);}//добавление в начало
        else if (some_case==2){Array.push_back(*this);}//добавление в конец
        else
        {
            int position;
            cout<<"На какое место поставить этот объект?"<<endl;
            cout<<"Доступные позиции: [1,"<< Array.size()+1 <<"]"<<endl;
            position = Special_check();

            //кароче: я ставлю итератор на начало списка
            auto it = Array.begin();
            //а потом передвигю на позицию ПЕРЕД нужной
            advance(it, position-1);
            //а тут кладу на нужную позицию кладу все как надо
            Array.insert(it,*this);
        }


    }
    void printList()
    {
        for(auto & i : Array){
            cout<<"Число: "<<i.a<<" Строка: "<<i.some_string<<" "<<endl;
        }
    }

};

int A_class::Special_check() {
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::cout << "Число: ";
        int a;
        std::cin >> a;

        if (std::cin.fail() or (a>Array.size()+1)) // если предыдущее извлечение оказалось неудачным,
        {
            std::cout<<"Введите нормально\n";
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}



int showMenu()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {

        std::cout<<std::endl;
        std::cout << "____________________МЕНЮ____________________" << std::endl;
        std::cout << " 1.      Вывести бАзУ" << std::endl;
        std::cout << " 2.      Добавить новое что-то" << std::endl;
        std::cout << " 3.      Стоп" << std::endl;
        std::cout<<std::endl;
        std::cout << "Введите число [1 , 3]" << std::endl;
        int a;
        std::cin >> a;

        if (std::cin.fail() or (a <= 0) or (a>5)) // если предыдущее извлечение оказалось неудачным
        {
            std::cout<<"НЕПРАВИЛЬНЫЙ ВВОД В МЕНЮ"<<std::endl;
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a

            return a;
    }
}



int main()
{

    A_class element;

    int a;
    do {

        a = showMenu();

        switch (a)
        {
            case 1: //вывести то что написали щас
                element.printList();
                break;

            case 2: //добавить новый товар
                int current_choice = Check_choice();
                element.addData(current_choice);
                break;

        }

    } while (a != 3);

    return 0;
}
