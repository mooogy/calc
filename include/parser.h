#ifndef PARSE_H
#define PARSE_H

#include <iostream>

class Parser {
public:
    virtual void parse() = 0;
    virtual ~Parser() = default;
};

class CsvParser : public Parser {
public:
    void parse() final override {
        std::cout << "CSV parsed\n";
    }
};

class JsonParser final : public Parser {
public:
    void parse() final override {
        std::cout << "JSON parsed\n";
    }
};

#endif
