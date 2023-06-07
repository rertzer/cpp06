#include <iostream>
#include <cctype>
#include <climits>
#include <sstream>

struct	number
{
	char	c;
	int		i;
	float	f;
	double	d;
	
	char	sign;

	bool	c_ok;
	bool	i_ok;
	bool	f_ok;
	bool	d_ok;
}

class	ScalarConverter
{
	public:
	static void	convert(std::string const literal);

	private:
		ScalarConverter(){};
		ScalarConverter(ScalarConverter const sc){};
		~ScalarConverter(){};
		ScalarConverter & operator=(ScalarConverter const rhs){};
		
		static void	convertNumber(std::string const & literal, struct & number nb);
		static void nbParsing(std::string const & literal);
}

