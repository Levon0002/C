#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <tuple>

// Person դասը
class Person {
public:
    Person(std::string first, std::string last)
        : m_firstName{ std::move(first) }, m_lastName{ std::move(last) } {}

    const std::string& getFirstName() const { return m_firstName; }
    const std::string& getLastName() const { return m_lastName; }

private:
    std::string m_firstName;
    std::string m_lastName;
};

// operator<< Person-ի համար
std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.getFirstName() << " " << person.getLastName();
    return os;
}

// myCopy ֆունկցիա (ինչպես std::copy)
template <typename InputIter>
void myCopy(InputIter begin, InputIter end) {
    for (auto it = begin; it != end; ++it)
        std::cout << *it << "\n";
}

int main() {
    // std::vector<std::pair<Person,int>> people = {
    //     {Person("John", "White"), 28},
    //     {Person("Anna", "Brown"), 34},
    //     {Person("Chris", "Blue"), 22},
    //     {Person("Laura", "Smith"), 30},
    //     {Person("Mike", "Black"), 25}
    // };

    // // 1️⃣ Pipeline առաջին 4 Person-ների համար
    // auto first4 = people
    //     | std::views::transform([](const auto& p){ return p.first; })
    //     | std::views::take(4)
    //     | std::views::all;  // common range GCC 11-ի համար

    // std::cout << "First 4 Persons (full name):\n";
    // myCopy(std::ranges::begin(first4), std::ranges::end(first4));

    // std::cout << "-------------------------\n";

    // // 2️⃣ Pipeline առաջին 4 Person-ների last name-ների համար
    // auto last_names = people
    //     | std::views::transform([](const auto& p){ return p.first; })
    //     | std::views::take(4)
    //     | std::views::transform([](const Person& p){ return p.getLastName(); })
    //     | std::views::all;  // common range GCC 11-ի համար

    // std::cout << "First 4 Persons (last names only):\n";
    // myCopy(std::ranges::begin(last_names), std::ranges::end(last_names));
    std::vector<int> vec;
    for(auto i : std::ranges::istream_view<int>(std::cin)
                | std::views::take_while([](int value ){return value != -1; })
                ){
                    vec.push_back(i);
                }
    myCopy(vec.begin(), vec.end());


}
