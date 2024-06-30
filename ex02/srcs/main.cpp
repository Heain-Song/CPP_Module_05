/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:21:29 by hesong            #+#    #+#             */
/*   Updated: 2024/06/30 15:15:52 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main(void)
{
	// Bureaucrat bureaucratA("A", 25);
	// Bureaucrat bureaucratB("B", 1);
	// ShrubberyCreationForm shrub ("shrubbery");

	{
		std::cout << "\n\n= = = = = TEST 1: ShrubberyCreationForm (static) = = = = =\n";
		ShrubberyCreationForm a("Test Static");
		std::cout << std::endl;

		ShrubberyCreationForm b = a;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}

	// {
	// 	std::cout << "\n\n= = = = = TEST 2: ShrubberyCreationForm (dynamic) = = = = =\n";
	// 	ShrubberyCreationForm *a = new ShrubberyCreationForm("Test Dynamic");
	// 	ShrubberyCreationForm *b = new ShrubberyCreationForm(*a); // deep copy
	// 	ShrubberyCreationForm *c = b;// shallow copy thus do not delete c
	// 	std::cout << *a << std::endl;
	// 	std::cout << *b << std::endl;
	// 	std::cout << *c << std::endl;


	// 	//FIXME:that's why I do not need to overload copy assignment operator in child
	// 	// std::cout << RED << "\n\n* * * * no need test * * * *\n" << DFT;
	// 	// ShrubberyCreationForm d;
	// 	// ShrubberyCreationForm *d2 = new ShrubberyCreationForm();
	// 	// std::cout << BLU << "\n\n(d)static:";
	// 	// std::cout << d;
	// 	// std::cout << BLU << "\n\n(d2)dynamic:";
	// 	// std::cout << *d2;
	// 	// d = *a;
	// 	// *d2 = *b;
	// 	// std::cout << BLU << "\n\n(d)static:";
	// 	// std::cout << d;
	// 	// std::cout << BLU << "\n\n(d2)dynamic:";
	// 	// std::cout << *d2;
	// 	// std::cout << RED << "\nSee _target is well copied although i didn't implement copy assignment operator in child\n" << DFT;
	// 	// std::cout << RED << "\n* * * * * * * * * * * *\n" << DFT;

	// 	delete a;
	// 	delete b;
	// }

	// std::cout << "\n\n= = = = = TEST mandatory 4-1: RobotomyRequestForm (execute success) = = = = =\n";
	// try {
	// 	RobotomyRequestForm a("test_exec_success");
	// 	Bureaucrat jean("Jean", 45);
	// 	std::cout << jean << std::endl;
	// 	std::cout << a << std::endl;
	// 	jean.signAForm(a);
	// 	jean.executeForm(a);
	// } catch(std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }
	return (0);
}

// #include "Bureaucrat.hpp"
// #include "AForm.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"

// int main()
// {
//     {
//         try {
//         Bureaucrat a("a1", 25);
//         Bureaucrat b("b1", 1);
//         AForm* rqf = new RobotomyRequestForm("ROBOT");
//         PresidentialPardonForm ppf("McQueen");

//         a.signAForm(*rqf);
//         a.signAForm(ppf);
//         std::cout << "-----" << std::endl;
//         a.executeForm(*rqf);
//         a.executeForm(ppf);
//         b.executeForm(ppf);
//         std::cout << "-----" << std::endl;
//         ShrubberyCreationForm scf("shrubbery");
//         b.signAForm(scf);
//         b.executeForm(scf);
//         delete rqf;
//         }
//         catch (std::exception &e) {
//             std::cout << "Exception caught: " << e.what() << std::endl;
//         }
//     }
// }

