/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:18:14 by hesong            #+#    #+#             */
/*   Updated: 2024/07/01 19:19:05 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm & src);
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm & rhs);
		~ShrubberyCreationForm(void);

		void	formActionExecute(const Bureaucrat & bureaucrat) const;

	private:
		std::string	_target;
};

#endif
