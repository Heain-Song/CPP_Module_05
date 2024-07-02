/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:15:52 by hesong            #+#    #+#             */
/*   Updated: 2024/07/01 21:09:16 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat; //Forward declaration

class	AForm{

	public:
		AForm(void);
		AForm(const std::string name, int gradeToToSign, int gradeToToExec);
		AForm(const AForm & src);
		AForm & operator=(const AForm & rhs);
		virtual ~AForm(void);

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

std::ostream & operator<<(std::ostream & out, AForm const & form);

#endif
