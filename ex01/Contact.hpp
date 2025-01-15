/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:48:08 by ufo               #+#    #+#             */
/*   Updated: 2025/01/15 14:59:50 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

# include <string>
# include <ctime>

class Contact {
    private:
        std::string _first_name;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;

    public:
        // Constructors
		Contact();
		Contact(std::string first_name, std::string last_name, std::string nick_name,
			std::string phone_number, std::string darkest_secret);
		~Contact();
    
        std::string  ft_getName(void);
        std::string  ft_getLastName(void);
        std::string  ft_getNickName(void);
        std::string  ft_getPhoneNumber(void);
        std::string  ft_getDarkestSecret(void);
};

#endif
