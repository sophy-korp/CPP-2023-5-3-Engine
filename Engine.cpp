#include"Engine.h"
#include<iostream>

void Engine::register_command(Wrapper* wrapper, std::string command) {
	if (m_commands.find(command) != m_commands.end()) {
		throw std::exception();
	}
	m_commands.insert({ command, wrapper });
}

int Engine::execute(std::string command, std::map<std::string, int> args) {
	if (m_commands.find(command) == m_commands.end()) {
		throw std::exception();
	}
	if (!m_commands[command]) {
		throw std::exception();
	}

	int res = 0;
	try {
		res = m_commands[command]->activateWrapper(args);
	}
	catch (...) {
		std::cout << "Incorrect input" << std::endl;
	}
	return res;
}