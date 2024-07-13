/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:30:23 by hesong            #+#    #+#             */
/*   Updated: 2024/07/13 11:55:39 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define HIGHEST 1
# define LOWEST 150

# include <iostream>
# include <string>

class Bureaucrat{

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat & src);
		Bureaucrat & operator=(const Bureaucrat & rhs);
		~Bureaucrat(void);

		std::string getName(void) const;
		int			getGrade(void) const;
		void		increaseGrade(void);
		void		decreaseGrade(void);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream & operator<<(std::ostream & out, Bureaucrat const & bureaucrat);

#endif
