/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:11:11 by hesong            #+#    #+#             */
/*   Updated: 2024/06/29 17:56:37 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(void)
: _name("unknown"), _isSigned(false), _requiredGradeToSign(LOWEST_GRADE), _requiredGradeToExec(LOWEST_GRADE)
{
	std::cout << "Default constructor called for Form " << this->_name << "." << std::endl;
}

Form::Form(const std::string name, int GradeToSign, int GradeToExec)
: _name(name), _isSigned(false)
{
	std::cout << "Parameterized Constructor called for Form " << this->_name << "." << std::endl;
	if (GradeToSign < HIGHEST_GRADE || GradeToExec < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (GradeToSign > LOWEST_GRADE || GradeToExec > LOWEST_GRADE)
		throw GradeTooLowException();
	else
	{
		this->_requiredGradeToSign = GradeToSign;
		this->_requiredGradeToExec = GradeToExec;
	}
}

Form::Form(const Form & src)
{
	std::cout << "Copy Constructor called for Form " << this->_name << "." << std::endl;
	*this = src;
}

Form & Form::operator=(const Form & rhs)
{
	std::cout << "Copy Assignment Operator called for Form " << this->_name << "." << std::endl;
	this->_name = rhs._name;
	this->_isSigned = rhs._isSigned;
	this->_requiredGradeToSign = rhs._requiredGradeToSign;
	this->_requiredGradeToExec = rhs._requiredGradeToExec;
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Destructor called for Form " << this->_name << "." << std::endl;
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

void	Form::beSigned(const Bureaucrat & bureaucrat)
{
	if (this->_requiredGradeToSign < bureaucrat.getGrade())
	{
		std::cout << "Bureaucrat " << bureaucrat.getName() << " is not qualified to sign the form " << this->_name << "." << std::endl;
		throw GradeTooLowException();
	}
	if (this->_isSigned == true)
	{
		std::cout << "This form is already signed." << std::endl;
	}
	else
	{
		this->_isSigned = true;
		std::cout << "Bureaucrat " << bureaucrat.getName() << " has signed the Form " << this->_name << "." << std::endl;
	}
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("Form::GradeTooHighException");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("Form::GradeTooLowException");
}

std::ostream & operator<< (std::ostream & out, Form const & form)
{
	std::cout << "-----------Form Info-----------" << std::endl;
	out << "Form name: " << form.getName() << std::endl;
	out << "Status: " << form.getIsSigned() << std::endl;
	out << "Required grade to sign: " << form.getRequiredGradeToSign() << std::endl;
	out << "Required grade to execute: " << form.getRequiredGradeToExec() << std::endl;
	std::cout << "-------------End---------------";
	return (out);
}
