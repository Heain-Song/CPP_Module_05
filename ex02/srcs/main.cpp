/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:21:29 by hesong            #+#    #+#             */
/*   Updated: 2024/07/02 11:42:06 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "= = = = = = = = = =  = = = = = = Bureaucrat Creation = = = = = = = = = = = = = = = = = = = " << std::endl;
	Bureaucrat bureaucratS ("bureaucratS", 140);
	std::cout << bureaucratS << std::endl;

	Bureaucrat bureaucratR ("bureaucratR", 50);
	std::cout << bureaucratR << std::endl;

	Bureaucrat bureaucratP ("bureaucratP", 10);
	std::cout << bureaucratP << std::endl;

	std::cout << "= = = = = = = = = = = = = = = ShrubberyCreationForm Test = = = = = = = = = = = = = = = = = " << std::endl;
	ShrubberyCreationForm shrubbery ("myShrubbery");

	std::cout << shrubbery << std::endl;

	bureaucratS.signAForm(shrubbery);
	bureaucratS.signAForm(shrubbery);
	bureaucratS.executeForm(shrubbery);
	bureaucratS.executeForm(shrubbery);

	std::cout << shrubbery << std::endl;

	std::cout << "= = = = = = = = = = = = = = = RobotomyRequest Test = = = = = = = = = = = = = = = = = " << std::endl;
	RobotomyRequestForm robot ("myRobot");
	std::cout << robot << std::endl;

	bureaucratR.signAForm(robot);
	bureaucratR.signAForm(robot);
	bureaucratR.executeForm(robot);
	bureaucratR.executeForm(robot);

	std::cout << robot << std::endl;

	std::cout << "= = = = = = = = = = = = = = = PresidentialPardonForm Test = = = = = = = = = = = = = = = = = " << std::endl;
	PresidentialPardonForm president("myPresident");
	std::cout << president << std::endl;

	bureaucratP.signAForm(president);
	bureaucratP.signAForm(president);
	bureaucratP.executeForm(president);
	bureaucratP.executeForm(president);

	std::cout << president << std::endl;

	return (0);
}
