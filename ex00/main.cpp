#include "ScalarConverter.hpp"

int	main(int argc, char ** argv)
{
	if (argc != 2)
	{
		std::cout << "Please enter a number\n";
		return 1;
	}
	std::string	to_convert = static_cast<std::string>(argv[1]);
	ScalarConverter::convert(to_convert);
	return 0;
}
