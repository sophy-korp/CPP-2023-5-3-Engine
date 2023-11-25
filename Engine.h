#pragma once
#include"Wrapper.h"
#include<string>
#include<map>

class Engine {
public:
	void register_command(Wrapper* wrapper, std::string command);
	int execute(std::string command, std::map<std::string, int> args);
private:
	std::map<std::string, Wrapper*> m_commands;
};