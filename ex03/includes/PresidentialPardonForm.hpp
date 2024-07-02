/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:48:58 by hesong            #+#    #+#             */
/*   Updated: 2024/07/01 19:19:49 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm & src);
		PresidentialPardonForm & operator=(const PresidentialPardonForm & rhs);
		~PresidentialPardonForm(void);

		std::string	getTarget() const;
		void	formActionExecute(const Bureaucrat & bureaucrat) const;

	private:
		std::string _target;
};

#endif
