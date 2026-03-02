#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

class IConsoleCommand
{
public:
	virtual ~IConsoleCommand() = default;

	void Run()
	{
		m_bRunning = true;
		std::string line;

		while (m_bRunning)
		{
            std::cout << "> ";
            std::getline(std::cin, line);

            if (line.empty())
                continue;

            // 입력을 공백 기준으로 파싱
            std::istringstream iss(line);
            std::string command;
            iss >> command;

            std::vector<std::string> args;
            std::string arg;
            while (iss >> arg)
            {
                args.push_back(arg);
            }

            if (command == "insert" && args.size() >= 2)
            {
                OnInsert(args[0], std::stoi(args[1]));
            }
            else if (command == "delete" && args.size() >= 1)
            {
                OnDelete(args[0]);
            }
            else if (command == "find" && args.size() >= 1)
            {
                OnFind(args[0]);
            }
            else if (command == "top" && args.size() >= 1)
            {
                OnTop(std::stoi(args[0]));
            }
            else if (command == "quit")
            {
                m_bRunning = false;
            }
            else
            {
                std::cout << "Unknown command.\n";
                std::cout << "  insert [name] [score]\n";
                std::cout << "  delete [name]\n";
                std::cout << "  find [name]\n";
                std::cout << "  top [k]\n";
                std::cout << "  quit\n";
            }
		}
	}

protected:
	virtual void OnInsert(const std::string& name, int score) = 0;
	virtual void OnDelete(const std::string& name) = 0;
	virtual void OnFind(const std::string& name) = 0;
	virtual void OnTop(int k) = 0;

private:
	bool m_bRunning = false;
};