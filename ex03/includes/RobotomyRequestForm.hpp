/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 22:11:45 by hesong            #+#    #+#             */
/*   Updated: 2024/07/11 16:45:51 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form {
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string name, const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm & src);
		RobotomyRequestForm & operator=(const RobotomyRequestForm & rhs);
		~RobotomyRequestForm(void);

		std::string	getTarget() const;
		void	formActionExecute(const Bureaucrat & bureaucrat) const;

	private:
		std::string _target;
};

#endif
