#include <iostream>
#include <string>

bool isValidCreditCard(const std::string& cardNumber) {
    int sum = 0;
    bool isSecond = false;

    for (int i = cardNumber.size() - 1; i >= 0; --i) {
        int digit = cardNumber[i] - '0';

        if (isSecond) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;
        isSecond = !isSecond;
    }

    return sum % 10 == 0;
}

int main() {
    std::string cardNumber = "79927398713"; // Example credit card number

    if (isValidCreditCard(cardNumber)) {
        std::cout << "This is a valid credit card number." << std::endl;
    } else {
        std::cout << "This is not a valid credit card number." << std::endl;
    }

    return 0;
}


/*
Here’s a step-by-step explanation of the algorithm:

Initialize a sum variable to 0 and a boolean isSecond to false.
Iterate through the credit card number from right to left (i.e., from the check digit to the first digit).
For each digit:
If isSecond is true, double the digit value (unless it’s already 0, in which case skip this step).
If the doubled value is greater than 9, subtract 9 from it.
Add the resulting value to the sum.
Toggle isSecond to its opposite value (true becomes false, and vice versa).
After iterating through all digits, check if the sum is divisible by 10. If it is, the credit card number is valid according to the Luhn algorithm.
Note that this implementation assumes a string representation of the credit card number, where each character is a digit (0-9). You may need to modify the code to accommodate other input formats or error handling.
*/
