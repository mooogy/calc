#include <iostream>
#include <parser.h>
#include <memory>

int main() {
    {
        std::unique_ptr<Parser> parser = std::make_unique<CsvParser>();
        parser->parse();
    }

    {
        std::unique_ptr<Parser> parser = std::make_unique<JsonParser>();
        parser->parse();
    }

    return 0;
}
