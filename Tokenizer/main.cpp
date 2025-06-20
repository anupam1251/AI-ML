#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <memory>
class Tokenization {
protected:
    size_t m_id;
    std::string m_text;
public:
    Tokenization(const std::string& str) : m_id(0), m_text(cleanText(str)) {}
    std::string cleanText(const std::string &str);
    virtual void tokenize() = 0;
    virtual void displayLookupTable() = 0;
};

std::string Tokenization::cleanText(const std::string& str) {
    std::string temp;
    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i]) || isspace(str[i]))
            temp += str[i];
    }
    return temp;
}


class WordTokenization : public Tokenization{
    std::unordered_map<std::string, int> m_store;
public:
    WordTokenization(const std::string& str) : Tokenization(str) {}
    void tokenize() override ;
    void displayLookupTable() override;
};


void WordTokenization::tokenize() {
    std::istringstream iss(this->m_text);
    std::string token;
    while (iss >> token) {
        if(m_store.find(token) == m_store.end())
            m_store.insert({ token, ++m_id });
    }
}

void WordTokenization::displayLookupTable() {
    for (auto& [token, val] : m_store) {
        std::cout << "Token : " << token << " , Val : " << val << '\n';
    }
}

class CharacterTokenization : public Tokenization {
    std::unordered_map<char, int> m_store;
public:
    CharacterTokenization(const std::string& str) : Tokenization(str) {}
    void tokenize() override;
    void displayLookupTable() override;
};

void CharacterTokenization::tokenize() {
    for (auto& token : this->m_text) {
        if(!isspace(token) && m_store.find(token) == m_store.end())
            m_store.insert({ token,++m_id });
    }
}

void CharacterTokenization::displayLookupTable() {
    for (auto& [token, val] : m_store) {
        std::cout << "Token : " << token << " , Val : " << val << '\n';
    }
}



int main() {
    auto ptr = std::make_unique<CharacterTokenization>("I am learning about Machine learning!!.");
    ptr->tokenize();
    ptr->displayLookupTable();
    return 0;

}
