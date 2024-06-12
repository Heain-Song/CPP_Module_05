/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 05:05:37 by hesong            #+#    #+#             */
/*   Updated: 2024/06/12 17:46:35 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define LOWEST 150
# define HIGHEST 1

# include <iostream>
# include <string>
# include <exception>

/*Please note that exception classes don’t have to be designed in
Orthodox Canonical Form. But every other class has to.*/

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string Name, int Grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();

		Bureaucrat & operator=(Bureaucrat const & obj);

		std::string getName() const;
		int getGrade() const;

		void	incrementGrade();
		void	decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
	private:
		std::string const Name;
		int	Grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & obj);

#endif
