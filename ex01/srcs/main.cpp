/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:21:29 by hesong            #+#    #+#             */
/*   Updated: 2024/07/09 16:02:20 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void)
{
	Bureaucrat bureaucrat_unknown;
	std::cout << bureaucrat_unknown << std::endl;
	std::cout << std::endl;

	Form form_unknown;
	std::cout << form_unknown << std::endl;

	try
	{
		Bureaucrat bureaucratA("A", 150);
		std::cout << bureaucratA << std::endl;
		std::cout << std::endl;

		Form form1("Type 1", 150, 150);
		std::cout << form1 << std::endl;

		bureaucratA.signForm(form1);
		form1.beSigned(bureaucratA);

		std::cout << form1 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Bureaucrat bureaucratB("B", 150);
		std::cout << bureaucratB << std::endl;
		std::cout << std::endl;

		Form form2("Type 2", 150, 150);
		std::cout << form2 << std::endl;

		bureaucratB.increaseGrade();
		//bureaucratB.decreaseGrade();
		std::cout << bureaucratB << std::endl;

		form2.beSigned(bureaucratB);
		std::cout << form2 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Form form3("Type 3", 1, 1);
		std::cout << form3 << std::endl;

		Bureaucrat bureaucratC("C", 1);
		std::cout << bureaucratC << std::endl;

		//bureaucratC.increaseGrade();
		bureaucratC.decreaseGrade();
		//std::cout << bureaucratC << std::endl;

		form3.beSigned(bureaucratC);
		std::cout << form3 << std::endl;

	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
