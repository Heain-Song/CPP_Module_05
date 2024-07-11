/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:22:15 by hesong            #+#    #+#             */
/*   Updated: 2024/07/11 16:26:17 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form(void)
: _name("Unknown"), _isSigned(false), _gradeToSign(LOWEST), _gradeToExec(LOWEST)
{
	//std::cout << "Default constructor called for Form " << this->_name << "." << std::endl;
}

Form::Form(const std::string name, int GradeToSign, int GradeToExec)
: _name(name), _isSigned(false), _gradeToSign(GradeToSign), _gradeToExec(GradeToExec)
{
	//std::cout << "Parameterized Constructor called for Form " << this->_name << "." << std::endl;
	if (GradeToSign < HIGHEST || GradeToExec < HIGHEST)
		throw GradeTooHighException();
	else if (GradeToSign > LOWEST || GradeToExec > LOWEST)
		throw GradeTooLowException();
}

Form::Form(const Form & src)
{
	//std::cout << "Copy Constructor called for Form " << this->_name << "." << std::endl;
	*this = src;
}

Form & Form::operator=(const Form & rhs)
{
	//std::cout << "Copy Assignment Operator called for Form " << this->_name << "." << std::endl;
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
	//std::cout << "Destructor called for AForm " << this->_name << "." << std::endl;
}

std::string	Form::getName(void) const
{
	return(this->_name);
}

bool	Form::getIsSigned(void) const
{
	return(this->_isSigned);
}

int	Form::getGradeToSign(void) const
{
	return(this->_gradeToSign);
}

int	Form::getGradeToExec(void) const
{
	return(this->_gradeToExec);
}

void	Form::beSigned(Bureaucrat & bureaucrat)
{
	if (_isSigned)
		throw Form::FormAlreadySignedException();
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	else
		this->_isSigned = true;
}

void	Form::execute(Bureaucrat const & executor) const
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

const char * Form::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}
const char * Form::FormAlreadySignedException::what() const throw()
{
	return ("FormAlreadySignedException");
}

const char * Form::FormNotSignedException::what() const throw()
{
	return ("FormNotSignedException");
}
const char * Form::CreateFileFailedException::what() const throw()
{
	return ("CreateFileFailedException");
}
const char * Form::ReadFileFailedException::what() const throw()
{
	return ("ReadFileFailedException");
}

std::ostream & operator<< (std::ostream & out, Form const & form)
{
	std::cout << std::endl << "-----------Form Info-----------" << std::endl;
	out << "Form name: " << form.getName() << std::endl;
	out << "Status: " << form.getIsSigned() << std::endl;
	out << "Required grade to sign: " << form.getGradeToSign() << std::endl;
	out << "Required grade to execute: " << form.getGradeToExec() << std::endl;
	std::cout << "-------------End---------------" << std::endl;
	return (out);
}
