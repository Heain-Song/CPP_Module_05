/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:22:45 by hesong            #+#    #+#             */
/*   Updated: 2024/06/29 23:36:11 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("unknown"), _grade(LOWEST)
{
	std::cout << "Default constructor called for Bureaucrat " << this->_name << "." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Parameterized Constructor called for Bureaucrat " << this->_name << "." << std::endl;
	if (grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	if (grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & src)
{
	std::cout << "Copy Constructor called for Bureaucrat " << this->_name << "." << std::endl;
	*this = src;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & rhs)
{
	std::cout << "Copy  Assignment Operator called for Bureaucrat " << this->_name << "." << std::endl;
	if (rhs._grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	if (rhs._grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called for Bureaucrat " << this->_name << "." << std::endl;
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::increaseGrade()
{
	this->_grade--;
	if (this->_grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Grade increasement done." << std::endl;
}

void	Bureaucrat::decreaseGrade()
{
	this->_grade++;
	if (this->_grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Grade decreasement done." << std::endl;
}

void	Bureaucrat::signForm(const AForm & form)
{
 	if (this->_grade < form.getgradeToSign())
 		std::cout << this->_name << " couldn't sign Form " << form.getName() << " because " << form.getgradeToSign() << " is required to sign it." << std::endl;
 	if (this->_grade < form.getgradeToExec())
 		std::cout << this->_name << " couldn't execute Form " << form.getName() << " because " << form.getgradeToExec() << " is required to execute it." << std::endl;
	if (form.getIsSigned() == true)
		std::cout << this->_name << " couldn't sign " << form.getName() << " because this form is already signed." << std::endl;
	else
 		std::cout << this->_name << " signed " << form.getName() << "." << std::endl;
}
void	Bureaucrat::executeForm(const AForm & form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}


const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat::GradeTooHighException");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat::GradeTooLowException");
}

std::ostream & operator<<(std::ostream & out, Bureaucrat const & bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}
