/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:04:03 by hesong            #+#    #+#             */
/*   Updated: 2024/07/02 12:26:27 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>

class Intern{
	public:
		Intern(void);
		Intern(const Intern & src);
		Intern & operator=(const Intern & rhs);
		~Intern(void);

		class FormDoesNotExistExecption : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		AForm*	makeForm(std::string FormName, std::string FormTarget);
};

#endif
