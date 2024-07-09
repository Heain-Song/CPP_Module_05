/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:11:11 by hesong            #+#    #+#             */
/*   Updated: 2024/07/09 15:36:25 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

Form::Form(void)
: _name("Unknown"), _isSigned(false), _gradeToSign(LOWEST), _gradeToExec(LOWEST)
{
	std::cout << "Default constructor called for Form " << this->_name << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "Parameterized Constructor called for Form " << this->_name << std::endl;
	if (gradeToSign < HIGHEST || gradeToExec < HIGHEST)
		throw GradeTooHighException();
	else if (gradeToSign > LOWEST || gradeToExec > LOWEST)
		throw GradeTooLowException();
}

Form::Form(const Form & src)
: _name(src.getName()), _isSigned(src.getIsSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec())
{
	std::cout << "Copy Constructor called for Form " << this->_name << std::endl;
}

Form & Form::operator=(const Form & rhs)
{
	std::cout << "Copy Assignment Operator called for Form " << this->_name << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs.getIsSigned();
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Destructor called for Form " << this->_name << std::endl;
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
	if (this->_gradeToSign < bureaucrat.getGrade())
	{
		std::cout << "Bureaucrat " << bureaucrat.getName() << " is not qualified to sign the form " << this->_name << std::endl;
		throw GradeTooLowException();
	}
	if (this->_isSigned == true)
	{
		std::cout << "This form is already signed..." << std::endl;
		throw  FormAlreadySignedException();
	}
	else
	{
		this->_isSigned = true;
		std::cout << "Bureaucrat " << bureaucrat.getName() << " has signed the Form " << this->_name << "!" << std::endl;
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

const char * Form::FormAlreadySignedException::what() const throw()
{
	return ("FormAlreadySignedException");
}

const char * Form::FormNotSignedException::what() const throw()
{
	return ("FormNotSignedException");
}

std::ostream & operator<< (std::ostream & out, Form const & form)
{
	std::cout << "-----------Form Info-----------" << std::endl;
	out << "Form name: " << form.getName() << std::endl;
	out << "Status: " << form.getIsSigned() << std::endl;
	out << "Required grade to sign: " << form.getGradeToSign() << std::endl;
	out << "Required grade to execute: " << form.getGradeToExec() << std::endl;
	std::cout << "-------------End---------------" << std::endl;
	return (out);
}
