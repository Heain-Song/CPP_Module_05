/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:48:58 by hesong            #+#    #+#             */
/*   Updated: 2024/07/11 16:46:35 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form {
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string name, const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm & src);
		PresidentialPardonForm & operator=(const PresidentialPardonForm & rhs);
		~PresidentialPardonForm(void);

		std::string	getTarget() const;
		void	formActionExecute(const Bureaucrat & bureaucrat) const;

	private:
		std::string _target;
};

#endif
