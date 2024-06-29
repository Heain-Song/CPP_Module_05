/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:15:37 by hesong            #+#    #+#             */
/*   Updated: 2024/06/29 23:06:29 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm(void)
: _name("unknown"), _isSigned(false), _gradeToSign(LOWEST), _gradeToExec(LOWEST)
{
	std::cout << "Default constructor called for AForm " << this->_name << "." << std::endl;
}

AForm::AForm(const std::string name, int GradeToSign, int GradeToExec)
: _name(name), _isSigned(false), _gradeToSign(GradeToSign), _gradeToExec(GradeToExec)
{
	std::cout << "Parameterized Constructor called for AForm " << this->_name << "." << std::endl;
	if (GradeToSign < HIGHEST || GradeToExec < HIGHEST)
		throw GradeTooHighException();
	else if (GradeToSign > LOWEST || GradeToExec > LOWEST)
		throw GradeTooLowException();
}

AForm::AForm(const AForm & src)
{
	std::cout << "Copy Constructor called for AForm " << this->_name << "." << std::endl;
	*this = src;
}

AForm & AForm::operator=(const AForm & rhs)
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

AForm::~AForm(void)
{
	std::cout << "Destructor called for AForm " << this->_name << "." << std::endl;
}

std::string	AForm::getName(void) const
{
	return(this->_name);
}

bool	AForm::getIsSigned(void) const
{
	return(this->_isSigned);
}

int	AForm::getgradeToSign(void) const
{
	return(this->_gradeToSign);
}

int	AForm::getgradeToExec(void) const
{
	return(this->_gradeToExec);
}

void	AForm::beSigned(const Bureaucrat & bureaucrat)
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

void	AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() >= _gradeToExec)
		throw GradeTooLowException();
	if (!_isSigned)
		std::cout << this->_name << "is already signed." << std::endl;
	std::cout << executor.getName() << " executed " << this->_name << std::endl;
	//specificExecute();
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("AForm::GradeTooHighException");
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("AForm::GradeTooLowException");
}
const char * AForm::FormAlreadySigned::what() const throw()
{
	return ("AForm::FormAlreadySigned");
}

const char * AForm::FormNotSigned::what() const throw()
{
	return ("AForm::FormNotSigned");
}
const char * AForm::CreateFileFailed::what() const throw()
{
	return ("AForm::CreateFileFailed");
}
const char * AForm::ReadFileFailed::what() const throw()
{
	return ("AForm::ReadFileFailed");
}

std::ostream & operator<< (std::ostream & out, AForm const & form)
{
	std::cout << "-----------Form Info-----------" << std::endl;
	out << "Form name: " << form.getName() << std::endl;
	out << "Status: " << form.getIsSigned() << std::endl;
	out << "Required grade to sign: " << form.getgradeToSign() << std::endl;
	out << "Required grade to execute: " << form.getgradeToExec() << std::endl;
	std::cout << "-------------End---------------";
	return (out);
}
