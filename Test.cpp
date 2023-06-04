#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;
TEST_CASE("isPrime") {

    SUBCASE("Prime numbers") {
        CHECK(ariel::isPrime(2));
        CHECK(ariel::isPrime(3));
        CHECK(ariel::isPrime(29));
        CHECK(ariel::isPrime(31));
    }

    SUBCASE("Non-prime numbers") {
        CHECK_FALSE(ariel::isPrime(-5));
        CHECK_FALSE(ariel::isPrime(0));
        CHECK_FALSE(ariel::isPrime(1));
        CHECK_FALSE(ariel::isPrime(21));
        CHECK_FALSE(ariel::isPrime(28));
    }
}


TEST_CASE("Adding and removing elements and check size") {
    MagicalContainer container;

    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    CHECK(container.size() == 5);

    container.removeElement(2);
    container.removeElement(4);
    CHECK(container.size() == 3);
}

TEST_CASE("AscendingIterator") {
    MagicalContainer container;

    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    std::vector<int> expected {1, 2, 4, 5, 14};
    std::size_t index = 0; // Changed to std::size_t
    MagicalContainer::AscendingIterator ascIter(container);
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        CHECK(*it == expected[index]);
        ++index;
    }
}

TEST_CASE("SideCrossIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    std::vector<int> expected {1, 5, 2, 4, 3};
    std::size_t index = 0; // Changed to std::size_t
    MagicalContainer::SideCrossIterator crossIter(container);
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
        CHECK(*it == expected[index]);
        ++index;
    }
}

TEST_CASE("PrimeIterator") {
MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);

    std::vector<int> expected {2, 3, 5};
    std::size_t index = 0; // Changed to std::size_t
    MagicalContainer::PrimeIterator primeIter(container);
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        CHECK(*it == expected[index]);
        ++index;
    }
}

TEST_CASE("AscendingIterator cmparison operators") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);

    MagicalContainer::AscendingIterator ascIter(container);

    auto iter1 = ascIter.begin();
    auto iter2 = ascIter.begin();

    CHECK(*iter1 == *iter2);
    ++iter1;
    CHECK(*iter1 > *iter2);
    ++iter1;
    CHECK(*iter1 > *iter2);

}

TEST_CASE("SideCrossIterator cmparison operators") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);

    MagicalContainer::SideCrossIterator primeIter(container);

    auto iter1 = primeIter.begin();
    auto iter2 = primeIter.begin();

    CHECK(*iter1 == *iter2);
    ++iter1;
    CHECK(*iter1 > *iter2);
    ++iter1;
    CHECK(*iter1 > *iter2);
}

TEST_CASE("PrimeIterator cmparison operators") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);

    MagicalContainer::PrimeIterator primeIter(container);

    auto iter1 = primeIter.begin();
    auto iter2 = primeIter.begin();

    CHECK(*iter1 == *iter2);
    ++iter1;
    CHECK(*iter1 > *iter2);
    ++iter1;
    CHECK(*iter1 > *iter2);
}