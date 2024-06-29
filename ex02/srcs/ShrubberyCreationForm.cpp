/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:14:17 by hesong            #+#    #+#             */
/*   Updated: 2024/06/29 23:26:34 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
: AForm("ShrubberyCreationForm", 145, 137), _target("unknown")
{
	std::cout << "Default constructor called for ShrubberyCreationForm " << this->_target << "." << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Parameterized constructor called for ShrubberyCreationForm " << this->_target << "." << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src)
: AForm("ShrubberyCreationForm", 145, 137), _target(src._target)
{
	std::cout << "Copy constructor called for ShrubberyCreationForm " << this->_target << "." << std::endl;
	*this = src;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs)
{
	std::cout << "Copy Assignment Operator called for ShrubberyCreationForm " << this->_target << "." << std::endl;
	this->_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Destructor called for ShrubberyCreationForm " << this->_target << "." << std::endl;
}
void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!this->getIsSigned())
		throw ShrubberyCreationForm::FormNotSigned();
	if (bureaucrat.getGrade() > this->getgradeToExec())
		throw ShrubberyCreationForm::GradeTooLowException();

	std::string fileName = _target + "_shrubbery";
	std::ofstream out(fileName.c_str());

	if (out.fail())
		throw ShrubberyCreationForm::CreateFileFailed();
	out << "                                              .         ;  \n";
	out << "                                                         .\n";
	out << "                 .              .              ;%     ;;   \n";
	out << "                   ,           ,                :;%  %;   \n";
	out << "                    :         ;                   :;%;'     .,   \n";
	out << "           ,.        %;     %;            ;        %;'    ,;\n";
	out << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
	out << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
	out << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
	out << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
	out << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
	out << "                    `:%;.  :;bd%;          %;@%;'\n";
	out << "                      `@%:.  :;%.         ;@@%;'   \n";
	out << "                        `@%.  `;@%.      ;@@%;         \n";
	out << "                          `@%%. `@%%    ;@@%;        \n";
	out << "                            ;@%. :@%%  %@@%;       \n";
	out << "                              %@bd%%%bd%%:;     \n";
	out << "                                #@%%%%%:;;\n";
	out << "                                %@@%%%::;\n";
	out << "                                %@@@%(o);  . '         \n";
	out << "                                %@@@o%;:(.,'         \n";
	out << "                            `.. %@@@o%::;         \n";
	out << "                               `)@@@o%::;         \n";
	out << "                                %@@(o)::;        \n";
	out << "                               .%@@@@%::;         \n";
	out << "                               ;%@@@@%::;.          \n";
	out << "                              ;%@@@@%%:;;;. \n";
	out << "                          ...;%@@@@@%%:;;;;,..  \n";
	out.close();
}
