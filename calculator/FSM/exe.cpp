#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <stdexcept>

using namespace std;

enum class State {
    START,
    NUMBER,
    OPERATOR,
    OPEN_PAREN,
    CLOSE_PAREN,
    END
};

// Ստուգում ենք՝ թույլատրելի՞ է անցումը
bool validTransition(State from, State to) {
    if (from == State::START)
        return to == State::NUMBER || to == State::OPEN_PAREN;

    if (from == State::NUMBER)
        return to == State::OPERATOR || to == State::CLOSE_PAREN || to == State::END;

    if (from == State::OPERATOR)
        return to == State::NUMBER || to == State::OPEN_PAREN;

    if (from == State::OPEN_PAREN)
        return to == State::NUMBER || to == State::OPEN_PAREN;

    if (from == State::CLOSE_PAREN)
        return to == State::OPERATOR || to == State::CLOSE_PAREN || to == State::END;

    return false;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double apply(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    throw runtime_error("Անհայտ օպերատոր");
}

void process(stack<double>& values, stack<char>& ops) {
    if (values.size() < 2)
        throw runtime_error("Սխալ արտահայտություն");

    double b = values.top(); values.pop();
    double a = values.top(); values.pop();
    char op = ops.top(); ops.pop();
    values.push(apply(a, b, op));
}

double calculate(const string& expr) {
    stack<double> values;
    stack<char> ops;

    State state = State::START;

    for (size_t i = 0; i < expr.size();) {
        char c = expr[i];

        if (isspace(c)) {
            i++;
            continue;
        }

        // Թիվ
        if (isdigit(c)) {
            if (!validTransition(state, State::NUMBER))
                throw runtime_error("FSM սխալ: թիվը այստեղ թույլատրելի չէ");

            state = State::NUMBER;

            double num = 0;
            while (i < expr.size() && isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            values.push(num);
        }
        // (
        else if (c == '(') {
            if (!validTransition(state, State::OPEN_PAREN))
                throw runtime_error("FSM սխալ: '(' այստեղ թույլատրելի չէ");

            state = State::OPEN_PAREN;
            ops.push(c);
            i++;
        }
        // )
        else if (c == ')') {
            if (!validTransition(state, State::CLOSE_PAREN))
                throw runtime_error("FSM սխալ: ')' այստեղ թույլատրելի չէ");

            state = State::CLOSE_PAREN;

            while (!ops.empty() && ops.top() != '(')
                process(values, ops);

            if (ops.empty())
                throw runtime_error("Փակագծերի սխալ");

            ops.pop(); // '('
            i++;
        }
        // Օպերատոր
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (!validTransition(state, State::OPERATOR))
                throw runtime_error("FSM սխալ: երկու օպերատոր իրար կողք");

            state = State::OPERATOR;

            while (!ops.empty() &&
                   ops.top() != '(' &&
                   precedence(ops.top()) >= precedence(c))
                process(values, ops);

            ops.push(c);
            i++;
        }
        else {
            throw runtime_error("Անթույլատրելի սիմվոլ");
        }
    }

    // Վերջ
    if (!validTransition(state, State::END))
        throw runtime_error("Արտահայտությունը չի կարող այսպես ավարտվել");

    while (!ops.empty())
        process(values, ops);

    if (values.size() != 1)
        throw runtime_error("Սխալ արտահայտություն");

    return values.top();
}

int main() {
    string expr;
    cout << "Մուտքագրիր արտահայտությունը: ";
    getline(cin, expr);

    try {
        cout << "Արդյունք = " << calculate(expr) << endl;
    } catch (const exception& e) {
        cout << "ՍԽԱԼ: " << e.what() << endl;
    }

    return 0;
}
