#pragma once
#include<functional>
#include<map>
#include<string>
#include<vector>

class Wrapper {
public:
	template<typename classType, typename...Args>
	Wrapper(classType* instance, int(classType::* Func)(Args...), std::map<std::string, int> args) {
		if (!instance || !Func) {
			throw std::exception();
		}
		for (auto&& arg : args) {
			if (m_arg_names.find(arg.first) != m_arg_names.end()) {
				throw std::exception();
			}
			else {
				m_arg_names.insert(arg);
			}
		}
		encapsulatedFunction = [this, instance, Func](std::vector<int> args) {
			if (sizeof...(Args) != args.size()) {
				throw std::exception();
			}
			return indexBinding(instance, Func, args, std::make_index_sequence<sizeof...(Args)>{});
		};
	}
	int activateWrapper(std::map<std::string, int> args);
private:
	std::map<std::string, int> m_arg_names;
	std::function<int(std::vector<int> args)> encapsulatedFunction;

	template<typename classType, typename funcType, size_t...index>
	int indexBinding(classType instance, funcType Func, std::vector<int> args,
		std::index_sequence<index...>) {
		return (instance->*Func)(args[index]...);
	}
};


