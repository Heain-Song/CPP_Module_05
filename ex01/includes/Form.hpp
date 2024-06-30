/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:47:57 by hesong            #+#    #+#             */
/*   Updated: 2024/06/29 22:32:54 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	Form{

	public:
		Form(void);
		Form(const std::string name, int gradeToToSign, int gradeToToExec);
		Form(const Form & src);
		Form & operator=(const Form & rhs);
		~Form(void);

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getgradeToToSign(void) const;
		int			getgradeToToExec(void) const;
		void		beSigned(const Bureaucrat & bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string _name;
		bool		_isSigned;
		int			_gradeToSign;
		int			_gradeToExec;
};

std::ostream & operator<<(std::ostream & out, Form const & form);

#endif
