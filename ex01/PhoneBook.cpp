/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:09:34 by ufo               #+#    #+#             */
/*   Updated: 2025/03/25 11:07:40 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _size(0), _oldestIndex(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact& contact) {
    _contacts[_oldestIndex] = contact;
    _contacts[_oldestIndex].setIndex(_oldestIndex + 1); // Optional: set index internally
    _oldestIndex = (_oldestIndex + 1) % MAX_CONTACTS;
    if (_size < MAX_CONTACTS)
        _size++;
}

const Contact& PhoneBook::getContact(int index) const {
    return _contacts[index];
}

int PhoneBook::getSize() const {
    return _size;
}
