#include <cstdlib>
#include <string>
#include <vector>

// rule 1
// Use spaces, not tabs. Tabs should only appear in files that require them for semantic meaning, like Makefiles.
void rule1()
{
    // right
    constexpr bool useSpace { true };
    // wrong
	constexpr bool useTab { true };
}


// rule 2
// The indent size is 4 spaces.
void rule2() 
{
    // right
    return;
    // wrong
        return;
}


// rule 3
// The contents of namespaces should not be indented.

// right
namespace RightNamespaceExample {
class Rule3Class {
};
}

// wrong
namespace WrongNamespaceExample {
    class Rule3Class {
    };
}


// rule 4
// A case label should line up with its switch statement. The case statement is indented.
void rule4() 
{
    enum class Condition : int {
        fooCondition,
        barCondition
    };
    Condition condition { Condition::fooCondition };
    int i {};

    // right
    switch (condition) {
    case Condition::fooCondition:
    case Condition::barCondition:
        i++;
        break;
    default:
        i--;
    }

    // wrong
    switch (condition) {
        case Condition::fooCondition:
        case Condition::barCondition:
            i++;
            break;
        default:
            i--;
    }
}

// rule 5
// Boolean expressions at the same nesting level that span multiple lines should have their operators on the left side of the line instead of the right side.
bool rule5()
{
    bool b1 { true };
    std::string s1 { "test" };
    bool b3 { true };

    // right
    bool right = b1 == true
        || s1 == "test"
        || b3 == !b1;

    // wrong
    return b1 == true ||
        s1 == "test" ||
        (b3 == !b1);
}


// rule 6
// Do not place spaces around unary operators.
void rule6()
{
    int i {};
    // right
    i++;

    // wrong
    i ++;
}


// rule 7
// Do place spaces around binary and ternary operators.
int rule7()
{
    int y {};
    int m {};
    int x {};
    int b {};
    int a {};
    int c {};
    bool condition { false };

    auto f = [](int a1, int b1) {};

    // right
    y = m * x + b;
    f(a, b);
    c = a | b;
    return condition ? 1 : 0;

    // wrong
    y=m*x+b;
    f(a,b);
    c = a|b;
    return condition ? 1:0;
}


// rule 8
// Place spaces around the colon in a range-based for loop.
void rule8()
{
    std::vector<int> buf;
    auto f = [](int v) {};

    // right
    for (const auto& value : buf) 
        f(value);

    // wrong
    for (const auto& value: buf) 
        f(value);
}

// rule 9
// Do not place spaces before comma and semicolon.
void rule9()
{
    auto f = [](int a, int b) {};
    auto doSomething = []() {};
    int a {};
    int b {};

    // right
    for (int i = 0; i < 10; ++i)
        doSomething();

    f(a, b);

    // wrong
    for (int i = 0 ; i < 10; ++i)
        doSomething();

    f(a , b);
}


// rule 10
// Place spaces between control statements and their parentheses.
void rule10()
{
    auto doIt = []() {};
    bool condition { true };

    // right
    if (condition)
        doIt();

    // wrong
    if(condition)
        doIt();
}


// rule 11
// Do not place spaces between the name, angle brackets and parentheses of a function declaration or invocation.
void rule11()
{
    auto f = [](){};
    
    // right
    f();
    // void g() { ... }
    std::vector<int> v1;

    // wrong
    f ();
    // void g () { ... }
    std::vector <int> v2;
}


// rule 12
// Do not place spaces between the parenthesis and its parameters, or angle brackets and its parameters of a function declaration or invocation.
void rule12()
{
    auto f = [](int a, int b){};
    
    // right
    f(1, 2);
    // void g(int a) { ... }
    std::vector<int> v1;

    // wrong
    f ( 1, 2 );
    // void g ( int a ) { ... }
    std::vector < int > v2;
}


// rule 13
// Do not place spaces between square brackets, angle brackets and parentheses of a lambda function but do place a space before braces.
void rule13()
{
    // right
    auto f = [](int x) { return x; };
    // [this] { return m_member; }
    //[=]<typename T> { return T(); }
    //[&]<typename X>(X parameter) { return parameter; }

    // wrong
    auto v = [] (int x) { return x; };
    // [this]{ return m_member; }
    //[=] <typename T> { return T(); }
    //[&]<typename X> (X parameter) { return parameter; }
}


// rule 14
// Do not place spaces between the identifier template and its angle brackets.
// Right
template<typename T> T foo1();
template<typename U> struct Bar1 { };
// Wrong 
template <typename T> T foo2();
template <typename U> struct Bar2 { };


// rule 15
// When initializing an object, place a space before the leading brace as well as between the braces and their content.
namespace Rule15 {
class Foo {
public:
    Foo(int value) {}
};

}

void rule15()
{
    using namespace Rule15;
    constexpr int testValue { 0 };
    // Right
    Foo foo1 { testValue };

    // Wrong
    Foo foo2{ testValue };
    Foo foo3 {testValue};
}


// rule 16
// Each statement should get its own line.
void rule16()
{
    int x {};
    int y {};
    bool condition {  true };
    auto doIt = []() {};

    // Right
    x++;
    y++;
    if (condition)
        doIt();

    // Wrong
    x++; y++;
    if (condition) doIt();
}


// rule17
// Chained = assignments should be broken up into multiple statements.
void rule17()
{
    int rightSpacing {};
    int totalSpacing {};
    int leftSpacing{};
    // Right
    rightSpacing = totalSpacing / 2;
    leftSpacing = rightSpacing;
    // Wrong
    leftSpacing = rightSpacing = totalSpacing / 2;
}


// rule 18
// An else statement should go on the same line as a preceding close brace if one is present, else it should line up with the if statement.
void rule18()
{
    bool condition { true };
    auto doSomething = []() {};
    auto doSomethingElse = []() {};

    // Right
    if (condition) {
        // ...
    } else {
        // ...
    }

    if (condition)
        doSomething();
    else
        doSomethingElse();

    if (condition)
        doSomething();
    else {
        // ...
    }

    // Wrong
    if (condition) {
        // ...
    }
    else {
        // ...
    }

    if (condition) doSomething(); else doSomethingElse();

    if (condition) doSomething(); else {
        // ...
    }
}


// rule 19
// An else if statement should be written as an if statement when the prior if concludes with a return statement.
int rule19()
{
    bool condition { true };
    constexpr int someValue {};
    // Right
    if (condition) {
        // ...
        return someValue;
    }
    if (condition) {
        // ...
    }

    // Wrong
    if (condition) {
        // ...
        return someValue;
    } else if (condition) {
        // ...
    }

    return someValue;
}


// rule 20
// Function definitions: place each brace on its own line.
// Right
void rule20Right()
{

}
// Wrong
void rule20Wrong() {

}


// rule 21
// Other braces: place the open brace on the line preceding the code block; place the close brace on its own line.
// Right
namespace Rule21 {
class MyClass {
    MyClass()
    {
        for (int i = 0; i < 10; ++i) {
            // ...
        }
    }
};
}
// Wrong
namespace Rule21 
{
class MyClass1 
{
    MyClass1()
    {
        for (int i = 0; i < 10; ++i) 
        {
            // ...
        }
    }
};
}


// rule 22
// One-line control clauses should not use braces unless comments are included or a single statement spans multiple lines.
void rule22()
{
    bool condition { true };
    auto doIt = []() {};
    // Right
    if (condition)
        doIt();

    if (condition) {
        // Some comment
        doIt();
    }

    if (condition) {
        doIt( // ...
            // ...
        );
    }

    // Wrong
    if (condition) {
        doIt();
    }

    if (condition)
        // Some comment
        doIt();

    if (condition)
        doIt( // ...
            // ...
        );
}


// rule 23
// Control clauses without a body should use empty braces:
void rule23()
{
    // Right
    for (int i { 100 }; i > 0; --i) { }

    // Wrong
    for (int i { 100 }; i > 0; --i);
}


// rule 24
// Any empty braces should contain a space.
// Right
namespace Rule24Right {
void f() { }
struct Unit { };
union Unit1 { };
class Unit2 { };
enum Unit3 { };
int x { };
auto a = [] { };
// while (true) { }
}
// Wrong
namespace Rule24Wrong {
void f() {}
struct Unit {};
union Unit1 {};
class Unit2 {};
enum Unit3 {};
int x {};
auto a = [] {};
// while (true) {}
}


// rule 25
// In C++, the null pointer value should be written as nullptr. In C, it should be written as NULL
void rule25()
{
    // Right
    // C++
    int* v = nullptr;
    // C
    int* p = nullptr;
    
    // Wrong
    // C++
    int* v1 = 0;
    // C
    int* p1 = NULL;
}


int main()
{
    return EXIT_SUCCESS;
}
