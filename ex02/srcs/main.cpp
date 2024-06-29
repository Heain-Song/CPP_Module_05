/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:21:29 by hesong            #+#    #+#             */
/*   Updated: 2024/06/29 23:55:23 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat bureaucratA("A", 25);
	Bureaucrat bureaucratB("B", 1);
	ShrubberyCreationForm shrub ("shrub");

	// {
	// 	std::cout << "\n\n= = = = = TEST mandatory 1: ShrubberyCreationForm (static) = = = = =\n";
	// 	ShrubberyCreationForm a("test static");
	// 	ShrubberyCreationForm b = a;
	// 	std::cout << a << std::endl;
	// 	std::cout << b << std::endl;
	// }

	{
		std::cout << "\n\n= = = = = TEST mandatory 2: ShrubberyCreationForm (dynamic) = = = = =\n";
		ShrubberyCreationForm *a = new ShrubberyCreationForm("test dynamic");
		ShrubberyCreationForm *b = new ShrubberyCreationForm(*a); // deep copy
		ShrubberyCreationForm *c = b;// shallow copy thus do not delete c
		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
		std::cout << *c << std::endl;


		//FIXME:that's why I do not need to overload copy assignment operator in child
		// std::cout << RED << "\n\n* * * * no need test * * * *\n" << DFT;
		// ShrubberyCreationForm d;
		// ShrubberyCreationForm *d2 = new ShrubberyCreationForm();
		// std::cout << BLU << "\n\n(d)static:";
		// std::cout << d;
		// std::cout << BLU << "\n\n(d2)dynamic:";
		// std::cout << *d2;
		// d = *a;
		// *d2 = *b;
		// std::cout << BLU << "\n\n(d)static:";
		// std::cout << d;
		// std::cout << BLU << "\n\n(d2)dynamic:";
		// std::cout << *d2;
		// std::cout << RED << "\nSee _target is well copied although i didn't implement copy assignment operator in child\n" << DFT;
		// std::cout << RED << "\n* * * * * * * * * * * *\n" << DFT;

		delete a;
		delete b;
	}

	std::cout << "\n\n= = = = = TEST mandatory 4-1: RobotomyRequestForm (execute success) = = = = =\n";
	try {
		RobotomyRequestForm a("test_exec_success");
		Bureaucrat jean("Jean", 45);
		std::cout << jean << std::endl;
		std::cout << a << std::endl;
		jean.signForm(a);
		jean.executeForm(a);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
