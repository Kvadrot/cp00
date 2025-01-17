/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:48:08 by ufo               #+#    #+#             */
/*   Updated: 2025/01/17 13:36:25 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

# include <string>
# include <ctime>

class Contact {

    public:
        int         _index;
        std::string _first_name;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;

        // Constructors
		Contact();
		Contact(int index, std::string first_name, std::string last_name, std::string nick_name,
			std::string phone_number, std::string darkest_secret);
		~Contact();
};

#endif
