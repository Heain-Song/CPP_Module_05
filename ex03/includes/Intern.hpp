/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:04:03 by hesong            #+#    #+#             */
/*   Updated: 2024/07/11 16:18:24 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern{
	public:
		Intern(void);
		Intern(const Intern & src);
		Intern & operator=(const Intern & rhs);
		~Intern(void);

		Form*	makeForm(std::string name, std::string target);
		Form*	makeShrubberyCreationForm(std::string name, std::string target);
		Form*	makeRobotomyRequestForm(std::string name, std::string target);
		Form*	makePresidentialPardonForm(std::string name, std::string target);

		class FormDoesNotExistExecption : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

#endif
