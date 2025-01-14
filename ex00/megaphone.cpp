/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:59:01 by ufo               #+#    #+#             */
/*   Updated: 2025/01/14 13:40:15 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

void    ft_toUpperCase(std::string &str)
{
    for (size_t counter = 0; counter < str.size(); counter++)
    {
        str[counter] = std::toupper(str[counter]);
    }
}

int main(int argc, char **argv)
{
    std::string text;
    std::string converted_arg;

    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } else {
        for (int i = 1; i < argc; i ++)
        {
            converted_arg = argv[i];
            ft_toUpperCase(converted_arg);
            text += converted_arg;
            if (i != argc - 1)
                text += " ";
        }
        std::cout << text << std::endl;
    }
}
