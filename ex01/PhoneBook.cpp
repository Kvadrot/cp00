/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:09:34 by ufo               #+#    #+#             */
/*   Updated: 2025/01/17 11:20:43 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    currentPhonebookSize = 0;
}

PhoneBook::~PhoneBook(void)
{
    
}

void PhoneBook::ft_addContact(const Contact& contact)
{
    if (currentPhonebookSize < MAX_CONTACTS) 
    {
        _contacts[currentPhonebookSize] = contact;
        currentPhonebookSize += 1;
    } 
    else 
    {
        // Shift all existing contacts to make space for the new one
        for (int i = 1; i < MAX_CONTACTS; i++) 
        {
            _contacts[i - 1] = _contacts[i];
        }
        _contacts[MAX_CONTACTS - 1] = contact;
    }
}

Contact* PhoneBook::ft_getAllContacts(void)
{
    return (_contacts);
}
