/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 05:04:36 by hesong            #+#    #+#             */
/*   Updated: 2024/06/12 17:54:44 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

/**
 * Design an artificial nightmare of offices, corridors, forms, and waiting queues.(???)
 * Start by the smallest cog in this vast bureaucratic machine: the Bureaucrat. (????)
 * A Bureaucrat must have a constant name, a grade from 1 to 150. 1 is the highest possible grade. (V)
 * Throw an exception (Bureaucrat::GradeTooHighException OR Bureaucrat::GradeTooLowException) on any attempt to instantiate a Bureaucrat using an invalid grade.
 * Implement getName() and getGrade()
 * Implement two member functions to increment or decrement the bureaucrat grade
 * If the grade is out of range, both of them will throw the same exceptions as the constructor.
 * Implement an overload of the insertion («) operator to print something like (without the angle brackets): <name>, bureaucrat grade <grade>
 * Turn in some tests to prove everything works as expected.
 */

int main(void)
{
	try
	{
		Bureaucrat bureaucratA("A", 42);
		std::cout << bureaucratA << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "TooHighException" << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "TooLowException" << std::endl;
	}

	//increment grade
	try
	{
		Bureaucrat bureaucratB("B", 1);
		bureaucratB.incrementGrade();
		std::cout << bureaucratB << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "TooHighException" << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "TooLowException" << std::endl;
	}

	//decrement grade
	try
	{
		Bureaucrat bureaucratC("C", 150);
		bureaucratC.decrementGrade();
		std::cout << bureaucratC << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "TooHighException" << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "TooLowException" << std::endl;
	}

}

