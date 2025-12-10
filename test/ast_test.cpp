#include <gtest/gtest.h>
#include <ast.h>
#include <memory>

using Node = std::unique_ptr<ASTNode>;

double evaluateOperation(Operation op, double left, double right) {
    Node leftNode = std::make_unique<NumberNode>(left);
    Node rightNode = std::make_unique<NumberNode>(right);

    Node operatorNode = std::make_unique<OperationNode>(op, std::move(leftNode), std::move(rightNode));
    return operatorNode->evaluate();
}

TEST(AST_TESTS, ADD_TWO_POSITIVE) {
    double result = evaluateOperation(Operation::Add, 13.0, 17.0);

    EXPECT_EQ(result, 30.0);
}

TEST(AST_TESTS, SUBTRACT_TWO_POSTIVE) {
    double result = evaluateOperation(Operation::Subtract, 16.0, 9.0);

    EXPECT_EQ(result, 7.0);
}

TEST(AST_TESTS, SUBTRACT_TWO_POSITIVE_NEGATIVE_RESULT) {
    double result = evaluateOperation(Operation::Subtract, 2.0, 12.0);

    EXPECT_EQ(result, -10.0);
}

TEST(AST_TESTS, MULTIPLY_TWO_POSITIVE) {
    double result = evaluateOperation(Operation::Multiply, 14.0, 5.0);

    EXPECT_EQ(result, 70.0);
}

TEST(AST_TESTS, MULTIPLY_ONE_NEGATIVE) {
    double result = evaluateOperation(Operation::Multiply, -6.0, 7.0);

    EXPECT_EQ(result, -42.0);
}

TEST(AST_TESTS, DIVIDE_TWO_POSITIVE) {
    double result = evaluateOperation(Operation::Divide, 49.0, 7.0);

    EXPECT_EQ(result, 7.0);
}

TEST(AST_TESTS, DIVIDE_BY_ZERO) {
    EXPECT_THROW(evaluateOperation(Operation::Divide, 69.0, 0.0), std::runtime_error);
}
