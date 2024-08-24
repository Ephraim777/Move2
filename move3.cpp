#include <iostream>
#include <string.h>
#include <ostream>

class big_integer {
    std::string str;
public:
    big_integer(std::string val) : str(val) {}
    
    big_integer(const big_integer &val) : str(val.str) {}
    
    big_integer(big_integer&& val) {
        str = std::move(val.str);
    }
    
    big_integer& operator=(const big_integer& val) {
        if (this != &val) {
            str = val.str;
        }
        return *this;
    }
    
    big_integer& operator=(big_integer&& val) {
        if (this != &val) {
            str = std::move(val.str);
        }
        return *this;
    }
    
    big_integer& operator+(const big_integer& val) {
        auto temp = std::stol(str);
        auto temp1 = std::stol(val.str);
        auto temp2 = temp + temp1;
        str = std::to_string(temp2);
        return *this;
    }
    
    big_integer& operator*(const big_integer& val) {
        auto temp = std::stol(str);
        auto temp1 = std::stol(val.str);
        auto temp2 = temp * temp1;
        str = std::to_string(temp2);
        return *this;
    }
    
    big_integer& operator*(const int& val) {
        auto temp = std::stoi(str);
        auto temp2 = temp * val;
        str = std::to_string(temp2);
        return *this;
    }
    
    friend std::ostream& operator<<(std::ostream& ex, const big_integer& obj) {
        ex << obj.str << std::endl;
        return ex;
    }
};

int main() {
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result; // 193099
    std::cout << result * (-1);
    return 0;
}