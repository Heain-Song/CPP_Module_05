/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:47:57 by hesong            #+#    #+#             */
/*   Updated: 2024/06/28 18:19:12 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form{

	public:
		Form(void);
		Form(const std::string name, int requiredGradeToSign, int requiredGradeToExec);
		Form(const Form & src);
		Form & operator=(const Form & rhs);
		~Form(void);

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getRequiredGradeToSign(void) const;
		int			getRequiredGradeToExec(void) const;
		void		beSigned(const Bureaucrat & bureaucrat) const;

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
		int			_requiredGradeToSign;
		int			_requiredGradeToExec;
};

std::ostream & operator<<(std::ostream & out, Form const & form);

#endif
