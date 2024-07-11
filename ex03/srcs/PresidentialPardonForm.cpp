/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:52:08 by hesong            #+#    #+#             */
/*   Updated: 2024/07/11 16:46:50 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
: Form("PresidentialPardonForm", 25, 5), _target("Unknown")
{
	//std::cout << "Default constructor called for PresidentialPardonForm " << this->_target << "." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string name, const std::string target)
: Form(name, 25, 5), _target(target)
{
	//std::cout << "Parameterized constructor called for PresidentialPardonForm " << this->_target << "." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src)
: Form("PresidentialPardonForm", 25, 5), _target(src._target)
{
	//std::cout << "Copy constructor called for PresidentialPardonForm " << this->_target << "." << std::endl;
	*this = src;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & rhs)
{
	//std::cout << "Copy Assignment Operator called for PresidentialPardonForm " << this->_target << "." << std::endl;
	this->_target = rhs._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	//std::cout << "Destructor called for PresidentialPardonForm " << this->_target << "." << std::endl;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void	PresidentialPardonForm::formActionExecute(const Bureaucrat & bureaucrat) const
{
	if (!this->getIsSigned())
		throw PresidentialPardonForm::FormNotSignedException();
	if (bureaucrat.getGrade() > this->getGradeToExec())
		throw PresidentialPardonForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
