/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:21:29 by hesong            #+#    #+#             */
/*   Updated: 2024/07/11 16:49:36 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int main(void)
{
	Intern someRandomIntern;

	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	 if (rrf != NULL) {
		std::cout << "Form created successfully!" << std::endl;
		// Optionally, perform more operations with rrf
	}
	else {
		std::cout << "Form creation failed!" << std::endl;
	}

	// Remember to delete the created form to avoid memory leaks
	delete rrf;
	return (0);
}
