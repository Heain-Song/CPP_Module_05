/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:11:11 by hesong            #+#    #+#             */
/*   Updated: 2024/06/29 22:32:54 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(void)
: _name("unknown"), _isSigned(false), _gradeToSign(LOWEST), _gradeToExec(LOWEST)
{
	std::cout << "Default constructor called for Form " << this->_name << "." << std::endl;
}

Form::Form(const std::string name, int GradeToSign, int GradeToExec)
: _name(name), _isSigned(false), _gradeToSign(GradeToSign), _gradeToExec(GradeToExec)
{
	std::cout << "Parameterized Constructor called for AForm " << this->_name << "." << std::endl;
	if (GradeToSign < HIGHEST || GradeToExec < HIGHEST)
		throw GradeTooHighException();
	else if (GradeToSign > LOWEST || GradeToExec > LOWEST)
		throw GradeTooLowException();
}

Form::Form(const Form & src)
{
	std::cout << "Copy Constructor called for Form " << this->_name << "." << std::endl;
	*this = src;
}

Form & Form::operator=(const Form & rhs)
{
	std::cout << "Copy Assignment Operator called for AForm " << this->_name << "." << std::endl;
	if (this != &rhs)
	{	this->_name = rhs._name;
		this->_isSigned = rhs._isSigned;
		this->_gradeToSign = rhs._gradeToSign;
		this->_gradeToExec = rhs._gradeToExec;
	}
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

int	Form::getgradeToToSign(void) const
{
	return(this->_gradeToSign);
}

int	Form::getgradeToToExec(void) const
{
	return(this->_gradeToExec);
}

void	Form::beSigned(const Bureaucrat & bureaucrat)
{
	if (this->_gradeToSign < bureaucrat.getGrade())
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
	out << "Required grade to sign: " << form.getgradeToToSign() << std::endl;
	out << "Required grade to execute: " << form.getgradeToToExec() << std::endl;
	std::cout << "-------------End---------------";
	return (out);
}
