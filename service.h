#ifndef _service_h_
#define _service_h_

#include <string>
#include <vector>

class Service
{
	public:

		typedef std::vector<int> intvector;

	private:

		bool		valid;
		std::string	service;
		intvector	service_field;

		Service();
		Service(const Service &);

	public:
						Service(std::string service) throw(std::string);
		bool			is_valid() const throw();
		std::string		service_string() const throw(std::string);
		intvector		service_vector() const throw(std::string);
};

#endif
