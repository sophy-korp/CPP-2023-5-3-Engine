#include"Wrapper.h"

int Wrapper::activateWrapper(std::map<std::string, int> args) {
	if (args.size() != m_arg_names.size()) {
		throw std::exception();
	}

	for (auto&& arg : args) {
		if (m_arg_names.count(arg.first) != 1) {
			throw std::exception();
		}
		else {
			m_arg_names[arg.first] = arg.second;
		}
	}

	std::vector<int> list;
	for (auto&& item : m_arg_names) {
		list.push_back(item.second);
	}
	return encapsulatedFunction(list);
}