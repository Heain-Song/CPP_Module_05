/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:06:59 by hesong            #+#    #+#             */
/*   Updated: 2024/07/11 16:48:19 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/Form.hpp"
#include "../includes/Form.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
	std::cout << "Default constructor called for Intern" << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Copy constructor called for Intern" << std::endl;
	*this = src;
}

Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Destructor called for Intern" << std::endl;
}

Form* Intern::makeForm(std::string name, std::string target)
{
	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	Form* (Intern::*ptr[3])(std::string, std::string) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm,
		};

	for (size_t i = 0; i < 3; i++)
	{
		if (names[i] == name)
			return (this->*ptr[i])(name, target);
	}
	throw Intern::FormDoesNotExistExecption();
}

Form*	Intern::makeShrubberyCreationForm(std::string name, std::string target)
{
	std::cout << "Creating Shrubbery Creation Form for " << target << std::endl;
	return new ShrubberyCreationForm(name, target);
}

Form*	Intern::makeRobotomyRequestForm(std::string name, std::string target)
{
	std::cout << "Creating Robotomy Request Form for " << target << std::endl;
	return new RobotomyRequestForm(name, target);
}

Form*	Intern::makePresidentialPardonForm(std::string name, std::string target)
{
	std::cout << "Creating Presidential Pardon Form for " << target << std::endl;
	return new PresidentialPardonForm(name, target);
}

const char *Intern::FormDoesNotExistExecption::what() const throw()
{
	return ("FormDoesNotExistException");
}
