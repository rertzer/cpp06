#include <iostream>

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
		ScalarConerter & operator=(ScalarConverter const rhs){};
}

