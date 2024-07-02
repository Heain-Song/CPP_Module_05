/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:15:37 by hesong            #+#    #+#             */
/*   Updated: 2024/07/02 12:25:45 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm(void)
: _name("unknown"), _isSigned(false), _gradeToSign(LOWEST), _gradeToExec(LOWEST)
{
	//std::cout << "Default constructor called for AForm " << this->_name << "." << std::endl;
}

AForm::AForm(const std::string name, int GradeToSign, int GradeToExec)
: _name(name), _isSigned(false), _gradeToSign(GradeToSign), _gradeToExec(GradeToExec)
{
	//std::cout << "Parameterized Constructor called for AForm " << this->_name << "." << std::endl;
	if (GradeToSign < HIGHEST || GradeToExec < HIGHEST)
		throw GradeTooHighException();
	else if (GradeToSign > LOWEST || GradeToExec > LOWEST)
		throw GradeTooLowException();
}

AForm::AForm(const AForm & src)
{
	//std::cout << "Copy Constructor called for AForm " << this->_name << "." << std::endl;
	*this = src;
}

AForm & AForm::operator=(const AForm & rhs)
{
	//std::cout << "Copy Assignment Operator called for AForm " << this->_name << "." << std::endl;
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
	//std::cout << "Destructor called for AForm " << this->_name << "." << std::endl;
}

std::string	AForm::getName(void) const
{
	return(this->_name);
}

bool	AForm::getIsSigned(void) const
{
	return(this->_isSigned);
}

int	AForm::getGradeToSign(void) const
{
	return(this->_gradeToSign);
}

int	AForm::getGradeToExec(void) const
{
	return(this->_gradeToExec);
}

void	AForm::beSigned(Bureaucrat & bureaucrat)
{
	if (_isSigned)
		throw AForm::FormAlreadySignedException();
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	else
		this->_isSigned = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExec)
		throw GradeTooLowException();
	std::cout << std::endl;
	std::cout << executor.getName() << " is going to execute " << this->_name << std::endl;
	std::cout << std::endl;
	formActionExecute(executor);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}
const char* AForm::FormAlreadySignedException::what() const throw()
{
	return ("FormAlreadySignedException");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("FormNotSignedException");
}
const char* AForm::CreateFileFailedException::what() const throw()
{
	return ("CreateFileFailedException");
}
const char* AForm::ReadFileFailedException::what() const throw()
{
	return ("ReadFileFailedException");
}

std::ostream & operator<< (std::ostream & out, AForm const & form)
{
	std::cout << std::endl << "-----------Form Info-----------" << std::endl;
	out << "Form name: " << form.getName() << std::endl;
	out << "Status: " << form.getIsSigned() << std::endl;
	out << "Required grade to sign: " << form.getGradeToSign() << std::endl;
	out << "Required grade to execute: " << form.getGradeToExec() << std::endl;
	std::cout << "-------------End---------------" << std::endl;
	return (out);
}
