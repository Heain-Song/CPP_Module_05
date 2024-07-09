/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:47:57 by hesong            #+#    #+#             */
/*   Updated: 2024/07/09 15:16:44 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# define LOWEST 150
# define HIGHEST 1

# include <string>
# include <iostream>

class Bureaucrat;

class	Form{

	public:
		Form(void);
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form & src);
		Form & operator=(const Form & rhs);
		~Form(void);

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExec(void) const;
		void		beSigned(Bureaucrat& bureaucrat);

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

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
