/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:21:29 by hesong            #+#    #+#             */
/*   Updated: 2024/07/09 16:25:48 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main(void)
{

	std::cout << "= = = = = = = = = = = = = = = ShrubberyCreationForm Test = = = = = = = = = = = = = = = = = " << std::endl;
	Bureaucrat bureaucratS ("S", 1);
	std::cout << bureaucratS << std::endl;

	ShrubberyCreationForm shrubbery ("myShrubbery");
	std::cout << shrubbery << std::endl;

	bureaucratS.signAForm(shrubbery);
	bureaucratS.executeForm(shrubbery);

	std::cout << shrubbery << std::endl;

	std::cout << "= = = = = = = = = = = = = = = RobotomyRequest Test = = = = = = = = = = = = = = = = = " << std::endl;

	Bureaucrat bureaucratR ("R", 42);
	std::cout << bureaucratR << std::endl;

	RobotomyRequestForm robot ("myRobot");
	std::cout << robot << std::endl;

	bureaucratR.signAForm(robot);
	bureaucratR.executeForm(robot);

	std::cout << robot << std::endl;

	std::cout << "= = = = = = = = = = = = = = = PresidentialPardonForm Test = = = = = = = = = = = = = = = = = " << std::endl;

	Bureaucrat bureaucratP ("P", 150);
	std::cout << bureaucratP << std::endl;

	PresidentialPardonForm president("myPresident");
	std::cout << president << std::endl;

	bureaucratP.signAForm(president);
	bureaucratP.executeForm(president);

	std::cout << president << std::endl;

	return (0);
}
