/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 22:11:45 by hesong            #+#    #+#             */
/*   Updated: 2024/06/29 23:56:25 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm & src);
		RobotomyRequestForm & operator=(const RobotomyRequestForm & rhs);
		~RobotomyRequestForm(void);

		std::string	getTarget() const;
		void execute(const Bureaucrat &bureaucrat) const;

	private:
		std::string _target;
};

#endif
