/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:11:11 by hesong            #+#    #+#             */
/*   Updated: 2024/06/28 18:26:54 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form(void)
: _name("unknown"), _isSigned(false), _requiredGradeToSign(LOWEST_GRADE), _requiredGradeToExec(LOWEST_GRADE)
{
	std::cout << "Default constructor called for " << this->_name << std::endl;
}

Form::Form(const std::string name, int GradeToSign, int GradeToExec)
: _name(name), _isSigned(false), _requiredGradeToSign(GradeToSign), _requiredGradeToExec(GradeToExec)
{
	std::cout << "Parameterized Constructor called for " << this->_name << std::endl;
}

Form::Form(const Form & src)
{
	std::cout << "Copy Constructor called for " << this->_name << std::endl;
	*this = src;
}

Form::~Form(void)
{
	std::cout << "Destructor called for " << this->_name << std::endl;
}

std::string	Form::getName(void) const
{
	return(this->_name);
}

bool	Form::getIsSigned(void) const
{
	return(this->_isSigned);
}

int	Form::getRequiredGradeToSign(void) const
{
	return(this->_requiredGradeToSign);
}

int	Form::getRequiredGradeToExec(void) const
{
	return(this->_requiredGradeToExec);
}

void	Form::beSigned(const Bureaucrat & bureaucrat) const
{
	if (this->_requiredGradeToSign < bureaucrat.getGrade())
	{
		std::cout << "Bureaucrat " << bureaucrat.getName() << " is not qualified to sign the form " << this->_name << std::endl;
		throw GradeTooLowException();
	}
	if (this->_isSigned == true)
	{
		std::cout << "This form is already signed." << std::endl;
	}
	else
	{
		this->_isSigned = true;
		std::cout << "Bureaucrat " << bureaucrat.getName() << " has signed the form " << this->_name << std::endl;
	}
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

std::ostream & operator<< (std::ostream & out, Form const & form)
{
	out << "Form name: " << form.getName() << std::endl;
	out << "Status: " << form.getIsSigned() << std::endl;
	out << "Required grade to sign: " << form.getRequiredGradeToSign << std::endl;
	out << "Required grade to execute: " << form.getRequiredGradeToExec << std::endl;
	return (out);
}
