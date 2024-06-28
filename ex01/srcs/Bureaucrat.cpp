/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:22:45 by hesong            #+#    #+#             */
/*   Updated: 2024/06/28 18:09:55 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("unknown"), _grade(LOWEST_GRADE)
{
	std::cout << "Default constructor called for " << this->_name << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Parameterized Constructor called for " << this->_name << std::endl;	
	if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & src)
{
	std::cout << "Copy Constructor called for " << this->_name << std::endl;
	*this = src;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & rhs)
{
	std::cout << "Copy  Assignment Operator called for " << this->_name << std::endl;
	if (rhs._grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (rhs._grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called for " << this->_name << std::endl;
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
	if (this->_grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decreaseGrade()
{
	this->_grade++;
	if (this->_grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

std::ostream & operator<<(std::ostream & out, Bureaucrat const & bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}
