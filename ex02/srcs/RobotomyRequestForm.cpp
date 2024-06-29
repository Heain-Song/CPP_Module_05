/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 22:11:28 by hesong            #+#    #+#             */
/*   Updated: 2024/06/29 23:56:33 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
: AForm("RobotomyRequestForm", 72, 45), _target("unknown")
{
	std::cout << "Default constructor called for RobotomyRequestForm " << this->_target << "." << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string target)
: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Parameterized constructor called for RobotomyRequestForm " << this->_target << "." << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src)
: AForm("RobotomyRequestForm", 72, 45), _target(src._target)
{
	std::cout << "Copy constructor called for RobotomyRequestForm " << this->_target << "." << std::endl;
	*this = src;
}
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs)
{
	std::cout << "Copy Assignment Operator called for RobotomyRequestForm " << this->_target << "." << std::endl;
	this->_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Destructor called for RobotomyRequestForm " << this->_target << "." << std::endl;
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!this->getIsSigned())
	{
		std::cout << this->_target << " failed." << std::endl;
		throw RobotomyRequestForm::FormNotSigned();
	}
	if (bureaucrat.getGrade() > this->getgradeToExec())
	{
		std::cout << this->_target << " failed." << std::endl;
		throw RobotomyRequestForm::GradeTooLowException();
	}
	std::cout << "Making some drilling noises!" << std::endl;
	std::cout << this->_target << " has been robotomized successfully 50% of the time." << std::endl;
}
