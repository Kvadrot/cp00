/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:11:18 by ufo               #+#    #+#             */
/*   Updated: 2025/01/15 15:03:10 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
// #include "main.hpp"

static void ft_searchContact(void)
{
    std::cout << "search was triggered" << std::endl;
}

static void    ft_addContact(void)
{
    std::cout << "add was triggered" << std::endl;
    
}

int main(void)
{
    std::string command;
    PhoneBook phonebook = PhoneBook();
    
    std::cout << "Type command to use Command, available commnds:";
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
        if (command == "ADD")
            ft_addContact();
        else if (command == "SEARCH")
            ft_searchContact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Wrong command, check up list of commands" << std::endl;
    }
    return (0);
}
