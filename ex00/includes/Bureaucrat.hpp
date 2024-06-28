/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:30:23 by hesong            #+#    #+#             */
/*   Updated: 2024/06/28 16:04:39 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define LOWEST_GRADE 150
# define HIGHEST_GRADE 1

# include <iostream>
# include <string>

class Bureaucrat{

	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat & src);
		Bureaucrat & operator=(const Bureaucrat & rhs);
		~Bureaucrat(void);

		std::string getName() const;
		int			getGrade() const;
		void		increaseGrade();
		void		decreaseGrade();

		class GradeTooHighException : public std::exception {

			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {

			public:
				virtual const char* what() const throw();
		};

	private:
		std::string _name;
		int			_grade;
};

std::ostream & operator<<(std::ostream & out, Bureaucrat const & bureaucrat);

#endif
