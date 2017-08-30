#include <iostream>
#include <string>

class Cliente{
private:
	std::string name;
	std::string service;
	int account = 0;
public:
	Cliente() {}
	Cliente (std::string _name, std::string _service, int _account) { name = _name; service = _service; account = _account; }
	std::string getName() { return name; }
	std::string getService() { return service; }
	int getAccount() { return account; }

	friend std::ostream & operator<< (std::ostream & out, const Cliente & cliente);
};

std::ostream & operator<< (std::ostream & out, const Cliente & cliente)
{
	out << "Cliente: " << cliente.name << " wants " << cliente.service << " on account " << cliente.account << std::endl;
	return out;
}