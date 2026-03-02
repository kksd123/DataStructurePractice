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

            if (command == "add" && args.size() >= 3)
            {
                OnAdd(args[0], std::stoi(args[1]), std::stoi(args[2]));
            }
            else if (command == "remove" && args.size() >= 1)
            {
                OnRemove(args[0]);
            }
            else if (command == "find" && args.size() >= 1)
            {
                OnFind(args[0]);
            }
            else if (command == "list")
            {
                OnList();
            }
            else if (command == "quit")
            {
                m_bRunning = false;
            }
            else
            {
                std::cout << "Unknown command.\n";
                std::cout << "  add [name] [type] [value]\n";
                std::cout << "  remove [name]\n";
                std::cout << "  find [name]\n";
                std::cout << "  list \n";
                std::cout << "  quit\n";
            }
        }
    }

protected:
    virtual void OnAdd(const std::string& name, int type, int value) = 0;
    virtual void OnRemove(const std::string& name) = 0;
    virtual void OnFind(const std::string& name) = 0;
    virtual void OnList() = 0;

private:
    bool m_bRunning = false;
};