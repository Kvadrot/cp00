/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:08:42 by ufo               #+#    #+#             */
/*   Updated: 2025/03/25 11:01:11 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void Contact::setIndex(int index) { _index = index; }
void Contact::setFirstName(const std::string& fn) { _firstName = fn; }
void Contact::setLastName(const std::string& ln) { _lastName = ln; }
void Contact::setNickName(const std::string& nn) { _nickName = nn; }
void Contact::setPhoneNumber(const std::string& pn) { _phoneNumber = pn; }
void Contact::setDarkestSecret(const std::string& s) { _darkestSecret = s; }

int Contact::getIndex() const { return _index; }
std::string Contact::getFirstName() const { return _firstName; }
std::string Contact::getLastName() const { return _lastName; }
std::string Contact::getNickName() const { return _nickName; }
std::string Contact::getPhoneNumber() const { return _phoneNumber; }
std::string Contact::getDarkestSecret() const { return _darkestSecret; }
