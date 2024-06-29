/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:21:29 by hesong            #+#    #+#             */
/*   Updated: 2024/06/29 15:28:53 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void)
{
	Bureaucrat bureaucrat_unknown;
	std::cout << bureaucrat_unknown << std::endl;

	Form form_unknown;
	std::cout << form_unknown << std::endl;


	std::cout << std::endl << ">> FIRST TRY" << std::endl;
	try
	{
		Form form1("Type 1", 42, 42);
		std::cout << form1 << std::endl;

		Bureaucrat bureaucratA("A", 42);
		std::cout << bureaucratA << std::endl;

		form1.beSigned(bureaucratA);
	}
	catch (std::exception & e)
	{
		std::cerr << "The system caught " << e.what() << "!" << std::endl;
	}

	std::cout << std::endl << ">> SECOND TRY" << std::endl;
	try
	{
		Form form2("Type 2", 150, 150);
		std::cout << form2 << std::endl;

		Bureaucrat bureaucratB("B", 151);
		std::cout << bureaucratB << std::endl;
		//bureaucratB.increaseGrade();
		bureaucratB.decreaseGrade();
		std::cout << "Afer change, " << bureaucratB << std::endl;

		form2.beSigned(bureaucratB);
	}
	catch (std::exception & e)
	{
		std::cerr << "The system caught " << e.what() << "!" << std::endl;
	}

	std::cout << std::endl << ">> THIRD TRY" << std::endl;
	try
	{
		Form form3("Type 3", 1, 1);
		std::cout << form3 << std::endl;

		Bureaucrat bureaucratC("C", 1);
		std::cout << bureaucratC << std::endl;
		//bureaucratC.increaseGrade();
		bureaucratC.decreaseGrade();
		std::cout << "After change, " << bureaucratC << std::endl;

		form3.beSigned(bureaucratC);
		//form1.beSigned(bureaucratC);
	}
	catch (std::exception & e)
	{
		std::cerr << "The system caught " << e.what() << "!" << std::endl;
	}

	return (0);
}
