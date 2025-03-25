/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:11:18 by ufo               #+#    #+#             */
/*   Updated: 2025/03/25 11:32:28 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cctype>
#include "PhoneBook.hpp"

#define COLUMN_WIDTH 10
#include "Contact.hpp"

static void ft_printLimitedStr(std::string str, int limit)
{
    if (str.length() > (size_t)limit)
        str = str.substr(0, limit - 1) + ".";
    std::cout << std::setw(limit) << str;
}

static void ft_printContactList(const PhoneBook &phonebook)
{
    std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
    for (int i = 0; i < phonebook.getSize(); i++) {
        const Contact &c = phonebook.getContact(i);
        std::cout << std::setw(10) << c.getIndex() << "|";
        ft_printLimitedStr(c.getFirstName(), COLUMN_WIDTH); std::cout << "|";
        ft_printLimitedStr(c.getLastName(), COLUMN_WIDTH); std::cout << "|";
        ft_printLimitedStr(c.getNickName(), COLUMN_WIDTH); std::cout << std::endl;
    }
}

static std::string ft_readLine(std::string prompt)
{
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

static std::string ft_takeValidNumber(std::string message)
{
    std::string input;
    while (true)
    {
        input = ft_readLine(message);
        if (input.empty())
            return "";
        bool isDigitOnly = true;
        for (size_t i = 0; i < input.length(); ++i) {
            if (!std::isdigit(input[i])) {
                isDigitOnly = false;
                break;
            }
        }
        if (isDigitOnly)
            return input;
        std::cout << "Invalid number. Try again." << std::endl;
    }
}

static int ft_addContact(PhoneBook &phonebook)
{
    Contact c;
    c.setIndex(phonebook.getSize() + 1);
    std::string s;

    if ((s = ft_readLine("First Name: ")).empty()) return (1);
		c.setFirstName(s);
    if ((s = ft_readLine("Last Name: ")).empty()) return (1);
		c.setLastName(s);
    if ((s = ft_readLine("Nickname: ")).empty()) return (1);
		c.setNickName(s);
    if ((s = ft_takeValidNumber("Phone Number: ")).empty()) return (1); 
		c.setPhoneNumber(s);
    if ((s = ft_readLine("Darkest Secret: ")).empty()) return (1);
		c.setDarkestSecret(s);

    phonebook.addContact(c);
    std::cout << "Contact added successfully!\n";
    return (0);
}

static int ft_searchContact(PhoneBook &phonebook)
{
    ft_printContactList(phonebook);
    std::string indexStr = ft_takeValidNumber("Enter index: ");
    if (indexStr.empty()) return 1;

    int idx = std::atoi(indexStr.c_str());
    if (idx < 1 || idx > phonebook.getSize()) {
        std::cout << "Invalid index." << std::endl;
        return 1;
    }
    const Contact &c = phonebook.getContact(idx - 1);
    std::cout << "\nFull Contact Info:\n";
    std::cout << "First Name: " << c.getFirstName() << std::endl;
    std::cout << "Last Name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickName() << std::endl;
    std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
    return 0;
}

int main()
{
    PhoneBook phonebook;
    std::string command;

    std::cout << "Welcome to 80s PhoneBook! Commands: ADD, SEARCH, EXIT" << std::endl;
    while (true)
    {
        std::cout << "\n> ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            ft_addContact(phonebook);
        } else if (command == "SEARCH") {
            ft_searchContact(phonebook);
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Unknown command. Use ADD, SEARCH or EXIT." << std::endl;
        }
    }
    return 0;
}
