/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:52:08 by hesong            #+#    #+#             */
/*   Updated: 2024/06/30 00:01:27 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
: AForm("PresidentialPardonForm", 72, 45), _target("unknown")
{
	std::cout << "Default constructor called for PresidentialPardonForm " << this->_target << "." << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 72, 45), _target(target)
{
	std::cout << "Parameterized constructor called for PresidentialPardonForm " << this->_target << "." << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src)
: AForm("PresidentialPardonForm", 72, 45), _target(src._target)
{
	std::cout << "Copy constructor called for PresidentialPardonForm " << this->_target << "." << std::endl;
	*this = src;
}
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & rhs)
{
	std::cout << "Copy Assignment Operator called for PresidentialPardonForm " << this->_target << "." << std::endl;
	this->_target = rhs._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Destructor called for PresidentialPardonForm " << this->_target << "." << std::endl;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!this->getIsSigned())
		throw PresidentialPardonForm::FormNotSigned();
	if (bureaucrat.getGrade() > this->getgradeToExec())
		throw PresidentialPardonForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
