/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:23:31 by hesong            #+#    #+#             */
/*   Updated: 2024/07/11 16:25:03 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat; //Forward declaration

class	Form{

	public:
		Form(void);
		Form(const std::string name, int gradeToToSign, int gradeToToExec);
		Form(const Form & src);
		Form & operator=(const Form & rhs);
		virtual ~Form(void);

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExec(void) const;

		void	beSigned(Bureaucrat & bureaucrat);
		void	execute(Bureaucrat const & executor) const;
		virtual void	formActionExecute(const Bureaucrat & bureaucrat) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class FormAlreadySignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class CreateFileFailedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class ReadFileFailedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string	_name;
		bool		_isSigned;
		int			_gradeToSign;
		int			_gradeToExec;
};

std::ostream & operator<<(std::ostream & out, Form const & form);

#endif
