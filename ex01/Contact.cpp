/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:08:42 by ufo               #+#    #+#             */
/*   Updated: 2025/01/16 17:20:18 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//Constructors
Contact::Contact()
{
    _first_name = "";
    _lastName = "";
    _nickName = "";
    _phoneNumber = "";
    _darkestSecret = "";
}

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret) {
    _first_name = first_name;
	_lastName = last_name;
	_nickName = nick_name;
	_phoneNumber = phone_number;
	_darkestSecret = darkest_secret;
}

Contact::~Contact()
{

}

//Methods:
// std::string  Contact::ft_getName(void) {
//     return (_first_name);
// }

// std::string Contact:: ft_getLastName(void){
//     return (_lastName);
// }

// std::string Contact:: ft_getNickName(void){
//     return (_nickName);  
// }

// std::string Contact:: ft_getPhoneNumber(void){
//     return (_phoneNumber);    
// }

// std::string Contact:: ft_getDarkestSecret(void){
//     return (_darkestSecret);
// }
