#include <cs50.h> 
#include <stdio.h>
#include <stdlib.h> // For strtoll
#include <string.h>

long long get_long_long_from_string(string s);
int get_length(long long n);
bool validate_checksum(long long card_number);
void identify_card_type(long long card_number);
int main(void)
{
    long long card_number;
    string s; // Prompt user for credit card number
    do
    {
        s = get_string("Number: ");
        card_number = get_long_long_from_string(s);
    }
    while (card_number <= 0); // Ensure a positive number is entered
    // Validate checksum using Luhn's algorithm
    if (validate_checksum(card_number))
    {
        // If checksum is valid, identify card type
        identify_card_type(card_number);
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

// Function to convert string to long long
long long get_long_long_from_string(string s)
{
    return strtoll(s, NULL, 10);
}

// Function to get the number of digits in a long long
int get_length(long long n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

// Function to validate credit card number using Luhn's Algorithm
bool validate_checksum(long long card_number)
{
    int sum = 0;
    int digit_count = 0;
    long long temp_number = card_number;

    while (temp_number > 0)
    {
        // Get the last digit
        int digit = temp_number % 10;

        // If it's an even-positioned digit (from the right, starting at 1)
        if (digit_count % 2 ==
            1) // 0-indexed, so 1 means second to last, 3 means fourth to last, etc.
        {
            digit *= 2;
            if (digit > 9)
            {
                sum += (digit % 10) + (digit / 10);
            }
            else
            {
                sum += digit;
            }
        }
        else // Odd-positioned digits
        {
            sum += digit;
        }

        temp_number /= 10;
        digit_count++;
    }

    return (sum % 10 == 0);
}

// Function to identify the credit card type
void identify_card_type(long long card_number)
{
    int length = get_length(card_number);

    // Get the first two digits
    long long first_two_digits = card_number;
    while (first_two_digits >= 100)
    {
        first_two_digits /= 10;
    }

    // Get the first digit
    int first_digit = first_two_digits / 10;

    // Check for American Express
    if ((length == 15) && (first_two_digits == 34 || first_two_digits == 37))
    {
        printf("AMEX\n");
    }
    // Check for MasterCard
    else if ((length == 16) && (first_two_digits >= 51 && first_two_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    // Check for Visa
    else if ((length == 13 || length == 16) && (first_digit == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
