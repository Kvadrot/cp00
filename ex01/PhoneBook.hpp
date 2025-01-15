/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:48:06 by ufo               #+#    #+#             */
/*   Updated: 2025/01/15 14:11:05 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <ctime>
# include "Contact.hpp"


#define MAX_CONTACTS 8


class PhoneBook {

    private:
        std::string test;
        Contact _contacts[MAX_CONTACTS];
        
    public:
    
    // Constructors:
        PhoneBook(){};
        ~PhoneBook(){};
    
    // Methods:
        void ft_addContact(){};
        void ft_searchContact(){};
};

#endif
