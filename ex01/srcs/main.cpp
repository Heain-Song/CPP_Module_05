/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:21:29 by hesong            #+#    #+#             */
/*   Updated: 2024/06/28 18:24:27 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void)
{
	Bureaucrat bureaucratA;
	std::cout << bureaucratA << std::endl;
	
	//Form formX;
	//std::cout << formX << std::endl;

	Form formY("Form Y", 100, 110);

	try
	{
		Bureaucrat bureaucratB("B", 1);
		std::cout << bureaucratB << std::endl;
		bureaucratB.increaseGrade();
		std::cout << bureaucratB << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "TooHighException" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "TooLowException" << std::endl;
	}

	try
	{
		Bureaucrat bureaucratC("C", 42);
		std::cout << bureaucratC << std::endl;
		bureaucratC.increaseGrade();
		//bureaucratC.decreaseGrade();
		std::cout << bureaucratC << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "TooHighException" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "TooLowException" << std::endl;
	}
	
	try
	{
		Bureaucrat bureaucratD("D", 150);
		std::cout << bureaucratD << std::endl;
		//bureaucratD.increaseGrade();
		bureaucratD.decreaseGrade();
		std::cout << bureaucratD << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "TooHighException" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "TooLowException" << std::endl;
	}

	return (0);
}
