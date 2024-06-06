/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Bureaucrat.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 05:05:37 by hesong            #+#    #+#             */
/*   Updated: 2024/06/06 15:49:12 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

/*Please note that exception classes don’t have to be designed in
Orthodox Canonical Form. But every other class has to.*/

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		class GradeTooHighException
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException
		{
			public:
				const char *what() const throw();
		};

}

#endif
