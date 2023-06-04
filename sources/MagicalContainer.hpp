/**
 * When I ran make tidy it wrote me an error that I lack a copy and delete constructor I sent to chatGPT and it wrote me the following lines for each iterator
 * 
 *  ~AscendingIterator() {}
 *  AscendingIterator(AscendingIterator&& other) noexcept : container(other.container), currentIndex(other.currentIndex) {}
 * 
*/

#include <iostream>
#include <vector>

namespace ariel {

    bool isPrime(int num) {
        if(num == 2){
            return true;
        }
        if (num < 2 || (num & 1) == 0) {
            return false;
        }
        for (int i = 3; i * i <= num; i+=2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    class MagicalContainer {
    private:
        std::vector<int> elements;

    public:
        void addElement(int element) {
            elements.push_back(element);
        }

        void removeElement(int element) {
            for (auto it = elements.begin(); it != elements.end(); ++it) {
                if (*it == element) {
                    elements.erase(it);
                    break;
                }
            }
        }

        std::size_t size() const {
            return elements.size();
        }

        class AscendingIterator {
        private:
            const MagicalContainer& container;
            std::size_t currentIndex;

        public:
            AscendingIterator(const MagicalContainer& container) : container(container), currentIndex(0) {}

            AscendingIterator(const AscendingIterator& other) : container(other.container), currentIndex(other.currentIndex) {}

            ~AscendingIterator() {}
            
            AscendingIterator(AscendingIterator&& other) noexcept : container(other.container), currentIndex(other.currentIndex) {}


            AscendingIterator& operator=(const AscendingIterator& other) {
                if (this != &other) {
                    currentIndex = other.currentIndex;
                }
                return *this;
            }

            AscendingIterator& operator=(AscendingIterator&& other) noexcept {
                if (this != &other) {
                    currentIndex = other.currentIndex;
                }
                return *this;
            }

            bool operator==(const AscendingIterator& other) const {
                return currentIndex == other.currentIndex;
            }

            bool operator!=(const AscendingIterator& other) const {
                return !(*this == other);
            }

            bool operator>(const AscendingIterator& other) const {
                return currentIndex > other.currentIndex;
            }

            bool operator<(const AscendingIterator& other) const {
                return currentIndex < other.currentIndex;
            }

            int operator*() const {
                return container.elements[currentIndex];
            }

            AscendingIterator& operator++() {
                ++currentIndex;
                return *this;
            }

            AscendingIterator begin() const {
                return AscendingIterator(*this);
            }

            AscendingIterator end() const {
                return AscendingIterator(*this);
            }
        };

        class SideCrossIterator {
        private:
            const MagicalContainer& container;
            std::size_t forwardIndex;
            std::size_t backwardIndex;

        public:
            SideCrossIterator(const MagicalContainer& container)
                : container(container), forwardIndex(0), backwardIndex(container.size() - 1) {}

            SideCrossIterator(const SideCrossIterator& other)
                : container(other.container), forwardIndex(other.forwardIndex), backwardIndex(other.backwardIndex) {}

            ~SideCrossIterator() {}
            
            SideCrossIterator(SideCrossIterator&& other) noexcept
                : container(other.container), forwardIndex(other.forwardIndex), backwardIndex(other.backwardIndex) {}


            SideCrossIterator& operator=(const SideCrossIterator& other) {
                if (this != &other) {
                    forwardIndex = other.forwardIndex;
                    backwardIndex = other.backwardIndex;
                }
                return *this;
            }

            SideCrossIterator& operator=(SideCrossIterator&& other) noexcept {
                if (this != &other) {
                    forwardIndex = other.forwardIndex;
                    backwardIndex = other.backwardIndex;
                }
                return *this;
            }

            bool operator==(const SideCrossIterator& other) const {
                return forwardIndex == other.forwardIndex && backwardIndex == other.backwardIndex;
            }

            bool operator!=(const SideCrossIterator& other) const {
                return !(*this == other);
            }

            bool operator>(const SideCrossIterator& other) const {
                return forwardIndex > other.forwardIndex && backwardIndex > other.backwardIndex;
            }

            bool operator<(const SideCrossIterator& other) const {
                return forwardIndex < other.forwardIndex && backwardIndex < other.backwardIndex;
            }

            int operator*() {
                if (forwardIndex == backwardIndex) {
                    return container.elements[forwardIndex];
                }
                int value = container.elements[forwardIndex];
                ++forwardIndex;
                return value;
            }

            SideCrossIterator& operator++() {
                if (forwardIndex < backwardIndex) {
                    ++forwardIndex;
                    --backwardIndex;
                }
                return *this;
            }

            SideCrossIterator begin() const {
                return SideCrossIterator(*this);
            }

            SideCrossIterator end() const {
                return SideCrossIterator(*this);
            }
        };

        class PrimeIterator {
        private:
            const MagicalContainer& container;
            std::size_t currentIndex;

        public:
            PrimeIterator(const MagicalContainer& container) : container(container), currentIndex(0) {
                while (currentIndex < container.size() && !isPrime(container.elements[currentIndex])) {
                    ++currentIndex;
                }
            }

            PrimeIterator(const PrimeIterator& other) : container(other.container), currentIndex(other.currentIndex) {}

            ~PrimeIterator() {} 

            PrimeIterator(PrimeIterator&& other) noexcept : container(other.container), currentIndex(other.currentIndex) {}

            PrimeIterator& operator=(PrimeIterator&& other) noexcept{
                if (this != &other) {
                    currentIndex = other.currentIndex;
                }
                return *this;
            }

            PrimeIterator& operator=(const PrimeIterator& other) {
                if (this != &other) {
                    currentIndex = other.currentIndex;
                }
                return *this;
            }

            bool operator==(const PrimeIterator& other) const {
                return currentIndex == other.currentIndex;
            }

            bool operator!=(const PrimeIterator& other) const {
                return !(*this == other);
            }

            bool operator>(const PrimeIterator& other) const {
                return currentIndex > other.currentIndex;
            }

            bool operator<(const PrimeIterator& other) const {
                return currentIndex < other.currentIndex;
            }

            int operator*() const {
                return container.elements[currentIndex];
            }

            PrimeIterator& operator++() {
                ++currentIndex;
                while (currentIndex < container.size() && !isPrime(container.elements[currentIndex])) {
                    ++currentIndex;
                }
                return *this;
            }
            PrimeIterator begin() const {
                return PrimeIterator(*this);
            }

            PrimeIterator end() const {
                return PrimeIterator(*this);
            }
        };

    };

} // namespace ariel