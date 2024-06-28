/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 05:05:52 by hesong            #+#    #+#             */
/*   Updated: 2024/06/12 17:45:18 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : Name("unknown")
{
	this->Grade = LOWEST;
}

Bureaucrat::Bureaucrat(std::string Name, int Grade) : Name(Name)
{
	if (Grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	if (Grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
	this->Grade = Grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat() //descructor
{

}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & obj) // assignment operator overload
{
	if (obj.Grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	if (obj.Grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
	this->Grade = obj.Grade;
	return *this;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & obj) // << insertion operator overload
{
	o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return o;
}

std::string Bureaucrat::getName() const
{
	return this->Name;
}

int Bureaucrat::getGrade() const
{
	return this->Grade;
}

void	Bureaucrat::incrementGrade()
{
	this->Grade--;
	if (this->Grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade()
{
	this->Grade++;
	if (this->Grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "TooHighException";
}

const char * Bureaucrat::GradeTooLowException::what () const throw()
{
	return "TooLowException";
}
