/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:11:18 by ufo               #+#    #+#             */
/*   Updated: 2025/01/17 11:57:40 by ufo              ###   ########.fr       */
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

static void ft_searchContact(void)
{
    std::cout << "search was triggered" << std::endl;
    
}

static int    ft_addContact(PhoneBook &phonebook)
{
    Contact contact = Contact();
    
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
            ft_searchContact();
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
