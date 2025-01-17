/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:11:18 by ufo               #+#    #+#             */
/*   Updated: 2025/01/17 13:55:43 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "Contact.hpp"
#include "PhoneBook.hpp"

static void ft_debugPrintContacts(PhoneBook& phonebook)
{
    Contact *allContacts = phonebook.ft_getAllContacts();

    for (int i = 0; i < MAX_CONTACTS - 1; i++)
    {
        if (!allContacts[i]._first_name.empty())
        {
            std::cout << allContacts[i]._first_name << std::endl;
        }
    }
}

static void ft_printLimitedStr(std::string str, int limit)
{
    unsigned int convertedLimit = static_cast<unsigned int>(limit);

    // If the string is longer than the limit, truncate it and add a dot
    if (str.length() > convertedLimit)
    {
        str = str.substr(0, convertedLimit - 1) + ".";
    }

    // Calculate the number of spaces needed for right alignment
    unsigned int spaces = convertedLimit - str.length();

    // Print the spaces for right alignment
    while (spaces > 0)
    {
        std::cout << " ";
        spaces--;
    }

    // Print the string
    std::cout << str;
}

static void ft_printContact(Contact contact)
{
    std::cout << "     index|first name| last name|  nickname\n";
    ft_printLimitedStr(std::to_string(contact._index), COLOMN_WIDTH);
    std::cout << "|";
    ft_printLimitedStr(contact._first_name, COLOMN_WIDTH);
    std::cout << "|";
    ft_printLimitedStr(contact._lastName, COLOMN_WIDTH);
    std::cout << "|";
    ft_printLimitedStr(contact._nickName, COLOMN_WIDTH);
    std::cout << std::endl;
}

bool isValidPhoneNumber(const std::string& input) {
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        // Check if the character is not a digit, space, or parenthesis
        if (!(std::isdigit(c))) {
            return false;
        }
    }
    return true;
}

bool ft_isOnlyWhitespaceOrNonPrint(const std::string& input) {
    for (size_t i = 0; i < input.length(); ++i) {
        if (std::isprint(input[i]) && !std::isspace(input[i])) {
            return false;
        }
    }
    return true;
}

static std::string  ft_readLine(std::string message)
{
    std::string input;
    
    std::cout << message << std::endl;
    while (1)
    {
        if (!(std::getline(std::cin, input)))
            return ("");
        if (ft_isOnlyWhitespaceOrNonPrint(input) == true)
           std::cout << "The input contains only whitespace or non-printable characters. Try again" << std::endl;
        else
            break;
    }
    return (input);
}

static std::string ft_takeValidNumber(std::string message)
{
    std::string input;
    while (1)
    {
        input = ft_readLine(message);
        if (input == "")
            return ("");
        if (isValidPhoneNumber(input))
            break;
        else
           std::cout << "The input must conatain only digits. Try again" << std::endl;  
    }

    return (input);
}

int ft_searchContact(PhoneBook &phonebook)
{
    std::string indexToFind;
    int convertedInd;
    Contact *contact;

    indexToFind = ft_takeValidNumber("pls enter index you are searching for\n");
    if (indexToFind == "")
        return (1);
    convertedInd = std::atoi(indexToFind.c_str());
    contact = phonebook.ft_searchContact(convertedInd);

    if (contact == NULL)
    {
        std::cout << "wrong contact id, you can try again" << std::endl; 
        return (2);
    }
    ft_printContact(*contact);
    return (0);
}

static int    ft_addContact(PhoneBook &phonebook)
{
    Contact contact = Contact();
    contact._index = phonebook.ft_getCurrentPhonebookSize() + 1;
    contact._first_name = ft_readLine("enter, first_name:");
    if (contact._first_name == "")
        return (3);
    contact._lastName = ft_readLine("Enter last name: ");
    if (contact._lastName == "")
        return (4);
	contact._nickName = ft_readLine("Enter nick name: ");
    if (contact._nickName == "")
        return (5);
	contact._phoneNumber = ft_takeValidNumber("Enter phone number: ");
    if (contact._phoneNumber == "")
        return (6);
	contact._darkestSecret = ft_readLine("Enter darkest secret: ");
    if (contact._darkestSecret == "")
        return (7);
    phonebook.ft_addContact(contact);
    std::cout << "contact is succefully added!" << std::endl;
    return (0);
}

int main(void)
{
    std::string command;
    PhoneBook phonebook = PhoneBook();
    
    std::cout << "Type command to use Command, available commnds:" << std::endl;
    std::cout << "ADD - create and add new contact to your phoneBook" << std::endl;
    std::cout << "SEARCH - display" << std::endl;
    std::cout << "EXIT - Terminate program" << std::endl;
    std::cout << "pls provide command" << std::endl;
    
    while (1)
    {
        if (!(std::getline(std::cin, command)))
        {
            std::cout << "command readding error occured, pls try latter" << std::endl;
            return (1);
        }
        if (command == "ADD") {
            if (ft_addContact(phonebook) > 0)
                return (2);
        }
        else if (command == "SEARCH") {
            ft_searchContact(phonebook);
        }
        else if (command == "EXIT")
            break;
        else if (command == "test")
            ft_debugPrintContacts(phonebook);
        else
            std::cout << "Wrong command, check up list of commands" << std::endl;
    }
    return (0);
}
