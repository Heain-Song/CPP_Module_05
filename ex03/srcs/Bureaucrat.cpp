/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:22:45 by hesong            #+#    #+#             */
/*   Updated: 2024/07/11 16:25:40 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
: _name("Unknown"), _grade(LOWEST)
{
	//std::cout << "Default constructor called for Bureaucrat " << this->_name << "." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
: _name(name)
{
	//std::cout << "Parameterized Constructor called for Bureaucrat " << this->_name << "." << std::endl;
	if (grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	if (grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & src)
{
	//std::cout << "Copy Constructor called for Bureaucrat " << this->_name << "." << std::endl;
	*this = src;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & rhs)
{
	//std::cout << "Copy  Assignment Operator called for Bureaucrat " << this->_name << "." << std::endl;
	if (rhs._grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	if (rhs._grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	//std::cout << "Destructor called for Bureaucrat " << this->_name << "." << std::endl;
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
	std::cout << "Grade increasement for " << this->getName() << " has been done" << std::endl;
}

void	Bureaucrat::decreaseGrade()
{
	this->_grade++;
	if (this->_grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Grade decreasement for " << this->getName() << " has been done" << std::endl;
}

void	Bureaucrat::signForm(Form & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " has signed " << form.getName() << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << this->getName() << " couldn't sign "<< form.getName() << " because of " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const Form & form)
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception & e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because of " << e.what() << std::endl;
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
