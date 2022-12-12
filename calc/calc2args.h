#ifndef LAB5ISRPO_CALC2ARGS_H
#define LAB5ISRPO_CALC2ARGS_H

#include <iostream>
#include <optional>
#include <string>
#include <sstream>
#include <vector>

///Класс, содержащий данные про две операнды и операторе между ними
class CalcTwoArgs {
public:
    /**
     * @brief Показывает, верно ли были введены данные
     * @return Возвращает true, если данные были введены верно. False в противном случае
     */
    bool isValid() const {
        return valid;
    }
    friend CalcTwoArgs ArgParser(const std::string& str);
    friend bool CheckForOperation(CalcTwoArgs& temp, const std::string& str);
    /**
     * @brief Выводит результат арифм. операции между двумя операндами
     * @return Возвращает результат
     */
    double Calc() const {
        if (firstArg == std::nullopt || secondArg == std::nullopt) {
            std::cerr << "Arguments weren't entered or wrong enter" << std::endl;
            std::exit(1);
        }
        if (isPlus == true) {
            return *firstArg + *secondArg;
        }
        if (isMinus == true) {
            return *firstArg - *secondArg;
        }
        if (isMult == true) {
            return *firstArg * *secondArg;
        }
        if (isDiv == true) {
            return *firstArg / *secondArg;
        }
        std::cerr << "Wrong calc" << std::endl;
        std::exit(1);
    }
private:
    bool valid = false;
    std::optional<double> firstArg;
    std::optional<double> secondArg;
    bool isPlus = false;
    bool isMinus = false;
    bool isMult = false;
    bool isDiv = false;
};

/**
 * @brief Функция CheckForFloat проверяют строку на то, может ли быть строка конвертирована в строку
 * @param str Подаваемая строка на проверку
 * @return Возвращает true, если конвертируема, false в противном случае
 */
bool CheckForFloat(const std::string& str);

/**
 * @brief Функция CheckForFloat проверяют строку на то, является ли она арифм. операцией
 * @param temp Класс, которому мы передадим данные об операторе
 * @param str Подаваемая строка на проверку
 * @return Возвращает true, если является арифм. оператором, false в противном случае
 */
bool CheckForOperation(CalcTwoArgs& temp, const std::string& str);

/**
 * @brief Функция парсит входящую строку и переводит в класс CalcTwoArgs
 * @param str Подаваемая строка на парсинг
 * @return Возвращает класс, в котором содержатся данные о двух операндах и операторе между ними
 */
CalcTwoArgs ArgParser(const std::string& str);
#endif //LAB5ISRPO_CALC2ARGS_H
