/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:48:06 by ufo               #+#    #+#             */
/*   Updated: 2025/03/25 11:07:24 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
private:
    Contact _contacts[MAX_CONTACTS];
    int     _size;          // number of contacts added (up to 8)
    int     _oldestIndex;   // index to overwrite when full

public:
    PhoneBook();
    ~PhoneBook();

    void addContact(const Contact& contact);          // Add new contact (overwrite oldest if full)
    const Contact& getContact(int index) const;       // Get contact by index (0 to size-1)
    int getSize() const;                              // Return number of valid contacts
};

#endif

