/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:06:59 by hesong            #+#    #+#             */
/*   Updated: 2024/07/02 13:43:05 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Intern.hpp"

Intern::Intern(void)
{
	//std::cout << "Default constructor called for Intern" << std::endl;
}

Intern::Intern(const Intern & src)
{
	//std::cout << "Copy constructor called for Intern" << std::endl;
	*this = src;
}

Intern & Intern::operator=(const Intern & rhs)
{
	(void)rhs;
	return (*this);
}

Intern::~Intern(void)
{
	//std::cout << "Destructor called for Intern" << std::endl;
}

AForm* Intern::makeForm(std::string FormName, std::string FormTarget)
{
}

const char* Intern::FormDoesNotExistExecption::what() const throw()
{
	return ("FormDoesNotExistException");
}
