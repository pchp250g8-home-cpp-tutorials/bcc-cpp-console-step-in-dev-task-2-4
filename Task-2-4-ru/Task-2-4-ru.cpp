#include <iostream>
#include <locale>
#include <tchar.h>

int _tmain(int argc, _TCHAR* argv[])
{
    // Максимальная длина участка, где каждая волна длинее предыдущей
	unsigned int max_len = 0;
    // Текущая длина участка, где каждая волна длинее предыдущей
    unsigned int current_len = 0;
    // Предыдущее значение в цепочке вводимых данных
    unsigned int prev_wave = 0;
    bool b_done = false;  // Флаг контроля выполнения цикла
    // Установка русской локали для терминала Windows 11
    system("chcp 1251 >nul");// 1-й способ. Выплнить внешнюю команду.
    // 2 - й способ. Вызов библиотечной функции.
    setlocale(LC_ALL, "russian.1251");
    // 3 - й способ. Создать переменную типа локали
    std::locale rus_locale = std::locale("russian.1251");
    // 3 - й способ. Выбор кодировки(локали) терминала
    std::cout.imbue(std::locale::global(rus_locale));
    // Ввод данных
    std::cout << "Введите данные метеостанции (0 - конец ввода).\r\n";
    while (!b_done)  // Старт цикла
    {
        unsigned int wave; // перемменая для данных
        std::cin >> wave;  // Ввод новой порции данных
        b_done = (wave == 0);  // Условие окончания цикла - ввод 0
        if (current_len == 0)
        {
            current_len = 1;  // Счётчик длины установили в 1
        }
        else if (wave > prev_wave) // если каждая волна длинее предыдущей
        {
            current_len += 1; // то счётчик длины участка увеличить на 1
        }
        else
        {
            if (current_len > max_len)  // В противном случае вычислить
            {
                max_len = current_len;  // максимальную длину участка
            }
            current_len = 1;  // и сбросить счётчик текущей длины участка
        }
        prev_wave = wave;  // Предыдущее значение заменить новым
    }
    // Максимальная длина участка, где каждая волна длинее предыдущей
    // Окончательный ответ
    if (current_len > max_len)
    {
        max_len = current_len;
    }
    std::cout << "Максимальная длина участка: " << max_len;
    // Задержка вывода на экран до нажатия клавиши "Ввод"
    std::cin.ignore();
    std::cin.get();
    return 0;

}
