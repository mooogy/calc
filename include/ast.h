#ifndef AST_H
#define AST_H

#include <iostream>
#include <memory>

class ASTNode {
public:
    virtual ~ASTNode() = default;
    [[nodiscard]] virtual double evaluate() const = 0;
};

class NumberNode : public ASTNode {
public:
    NumberNode(double v) : value_(v) {}
    double evaluate() const override { return value_; }

private:
    double value_;
};

enum class Operation : char {
    Add,
    Subtract,
    Multiply,
    Divide
};

class OperationNode : public ASTNode {
public:
    OperationNode(Operation type, std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right) :
    operator_(type), left_(std::move(left)), right_(std::move(right)) {}

    double evaluate() const override {
        double l = left_->evaluate();
        double r = right_->evaluate();

        switch (operator_) {
            case Operation::Add: return l + r;
            case Operation::Subtract: return l - r;
            case Operation::Multiply: return l * r;
            case Operation::Divide:
                if (r == 0) throw std::runtime_error("Division by zero");
                return l / r;
        }

        return 0;
    }

private:
    Operation operator_;
    std::unique_ptr<ASTNode> left_;
    std::unique_ptr<ASTNode> right_;
};


#endif
