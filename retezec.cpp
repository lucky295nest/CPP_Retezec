#include <iostream>

class Retezec
{
private:
    char* text;
    size_t length;

public:
    Retezec() : text(new char[1]), length(0) {
        text[0] = '\0';
    }

    Retezec(const char* str) : text(nullptr), length(0) {
        if (str) {
            length = 0;
            while (str[length] != '\0') {
                ++length;
            }
            text = new char[length + 1];
            for (size_t i = 0; i <= length; ++i) {
                text[i] = str[i];
            }
        }
        else
        {
            Retezec();
        }
    }

    Retezec(const Retezec& other) : text(nullptr), length(other.length) {
        text = new char[length + 1];
        for (size_t i = 0; i <= length; ++i) {
            text[i] = other.text[i];
        }
    }

    ~Retezec() {
        delete[] text;
    }

    void GetString() const {
        std::cout << std::endl << "Obsah stringu je: " << text << std::endl;
    }

    void SetString(const char* str) {
        if (text != nullptr) {
            delete[] text;
        }

        if (str != nullptr) {
            length = 0;
            const char* temp = str;
            while (*temp != '\0') {
                ++length;
                ++temp;
            }
            text = new char[length + 1];
            for (size_t i = 0; i < length; ++i) {
                text[i] = str[i];
            }
            text[length] = '\0';
        }
    }

    void GetLength() {
        std::cout << std::endl << "Delka stringu je: " << length << std::endl;
    }

    char& operator[](size_t index) {
        if (index >= length) {
            std::cerr << "Index out of range!" << std::endl;
            return text[0];
        }
        return text[index];
    }

    Retezec& operator=(const Retezec& other) {
        if (this != &other) {
            delete[] text;
            length = other.length;
            text = new char[length + 1];
            for (size_t i = 0; i < length; ++i) {
                text[i] = other.text[i];
            }
            text[length] = '\0';
        }
        return *this;
    }

    Retezec& operator+=(const Retezec& other) {
        size_t newLength = length + other.length;
        char* newText = new char[newLength + 1];
        for (size_t i = 0; i < length; ++i) {
            newText[i] = text[i];
        }
        for (size_t i = 0; i < other.length; ++i) {
            newText[length + i] = other.text[i];
        }
        newText[newLength] = '\0';
        delete[] text;
        text = newText;
        length = newLength;
        return *this;
    }

    friend Retezec operator+(const Retezec& lhs, const Retezec& rhs) {
        Retezec result;
        result.length = lhs.length + rhs.length;
        result.text = new char[result.length + 1];
        for (size_t i = 0; i < lhs.length; ++i) {
            result.text[i] = lhs.text[i];
        }
        for (size_t i = 0; i < rhs.length; ++i) {
            result.text[lhs.length + i] = rhs.text[i];
        }
        result.text[result.length] = '\0';
        return result;
    }
};

int main() {
    Retezec firstText("fucking");
    firstText.GetLength();
    firstText.GetString();

    Retezec secondText(" nigger");
    firstText += secondText;
    firstText.GetLength();
    firstText.GetString();

    Retezec combinedText = firstText + secondText;
    combinedText.GetLength();
    combinedText.GetString();

    char character = firstText[4];
    std::cout << "Character at index 4: " << character << std::endl;

    return 0;
}