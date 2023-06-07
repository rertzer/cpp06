#include "ScalarConverter.hpp"

static void	ScalarConverter::convert(std::string  const literal)
{
	int	type = 4;
	struct number nb = {0, 0, 0, 0, 1, false, false, false, false};
	void (* funCast[])(std::string const) = {
		&charcast,
		&intcast,
		&doublecast,
		&floatcast
	};
	
	type = getType(literal, nb);
	if (type == 4)
	{
		cout << "Bad luck: parsing error\n";
		return;
	}
	funcast[type](literal, nb);
	printnb(nb);
}

static int ScalarConverter::getType(std::string const literal)
{
	int	state = 0;
	std::string const dspecial[] = {"-inf", "+inf", "nan"};
	std::string const fspecial[] = {"-inff", "+inff", "nanf"};


	if (literal.size() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
		return 0;

	for (int i = 0; i < 3; i++)
	{
		if (literal.compare(dspecial[i] == 0))
				return 2;
		if (literal.compare(fspecial[i] == 0))
			return 3;
	}

	return (nbParsing(literal));
}

static int	ScalarConverter::nbParsing(std::string const &  literal)
{
	for (int i = 0 ; i < literal.size(); i++)
	{
		switch (state)
		{
			case 0:
				state = 1;
				if (literal[i] == '-')
					nb.sign = -1;
				else if (!isdigit(literal[i]) && literal[i] != '+')
					state = 4;
				break;
			case 1:
				if (literal == '.')
					case = 2;
				else if (!isdigit(literal[i]))
					state = 4;
				break;
			case 2:
				if (literal == 'f')
					state = 3;
				else if (!isdigit(lieral[i]))
					state = 4;
				break;
			case 3:
				state = 4;
				break;
		}
		if (state == 4)
			break;
	}
		return state;
}

static void	ScalarConverter::charcast(std::string const & literal, struct number & nb)
{
	nb.c = literal[0];
	nb.c_ok = 1;
	
	nb.i = static_cast<int> nb.c;
	nb.i_ok = 1;
	
	nb.d = static_cast<double> nb.c;
	nb.d_ok = 1;

	nb.f = static_cast<float> nb.f;
	nb.f_ok = 1;
}

static void	ScalarConverter::intcast(std::string const & literal, struct nunber nb)
{
	stringstream	ss;

	ss << literal;
	ss>> nb.i;
	if (ss.fail())
		return ;
	nb.i_ok = 1;

	if (nb.d <= static_cast<double>CHAR_MAX && nb.d >= static_cast<double>CHAR_MIN)
	{
		nb.c = static_cast<char> nb.i;
		nb.c_ok = 1;
	}
	
	nb.d = static_cast<double> nb.i;
	nb.d_ok = 1;

	nb.f = static_cast<float> nb.i;
	nb.f_ok = 1;
}

static void	ScalarConverter::doublecast(std::string const & literal, struct number nb)
{
	stringstream	ss;
	
	ss << literal;
	nb.d << literal;
	if (ss.fail())
		return ;
	nb.d_ok = 1;

	if (nb.d <= static_cast<double>CHAR_MAX && nb.d >= static_cast<double>CHAR_MIN)
	{
		nb.c = static_cast<char> nb.d;
		nb.c_ok = 1;
	}
	if (nb.d <= static_cast<double>INT_MAX && nb.d >= static_cast<double>INT_MIN)
	{
		nb.i = static_cast<int> nb.d;
		nb.i_ok = 1;
	}
	nb.f = static_cast<float> nb.d;
	nb.f_ok = 1;
}

static void	ScalarConverter::floatcast(std::string const & literal, struct number nb)
{
	stringstream	ss;
	
	ss << literal;
	nb.f << literal;
	if (ss.fail())
		return ;
	nb.f_ok = 1;

	if (nb.f <= static_cast<double>CHAR_MAX && nb.f >= static_cast<double>CHAR_MIN)
	{
		nb.c = static_cast<char> nb.f;
		nb.c_ok = 1;
	}
	if (nb.f <= static_cast<double>INT_MAX && nb.f >= static_cast<double>INT_MIN)
	{
		nb.i = static_cast<int> nb.f;
		nb.i_ok = 1;
	}
	nb.d = static_cast<float> nb.f;
	nb.d_ok = 1;
}

static void	ScalarConverter::printNb(stuct number nb)
{
	if (nb.c_ok)
	{
		if (isprint(nb.c))
			std::cout << "char: " << nb.c << std::endl;
		else
			std::cout << "char: Non displayable\n";
	}
	else
		std::cout << "impossible\n";
	
	if (nb.i_ok)
		std::cout << "int: " << nb.c << std::endl;
	else
		std::cout << "int: Non displayable\n";
	if (nb.f_ok)
		std::cout << "float: " << std::fixed << std::setprecision(1) << nb.f << std::endl;
	else
		std::cout << "float: Non displayable\n";
	if (nb.d_ok)
		std::cout << "double: " << std::fixed << std::setprecision(1) << nb.d << std::end;
	else
		std::cout << "double: Non displayable\n";
}














}
