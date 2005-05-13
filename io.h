#ifndef IO_H_
#define IO_H_

#include <string>
#include <vector>

#include "system.h"

extern class CommandFactory;
extern class CommandHandler;

enum InputType
{
	COMMAND,
	PLAIN_TEXT,
	NUMBER,
	TIME_DATE
};

class Shell
{
public:
	Shell(void){};
	~Shell(void){};

	void startShell(){};
	void setCommandHandlerReference(CommandHandler *command_handler) {command_handler_= command_handler;};
	void setInputTyp(InputType input_typ) { input_typ_ = input_typ ;};
	void setPromptString(std::string prompt_string) { prompt_string_ = prompt_string; };
private:
	CommandHandler* command_handler_;

	void readCommand(){};
	void commandLoop(){};

	std::string prompt_string_;
	InputType input_typ_;

};

class TestShell : public Shell
{
public:
	void startShell(){};
	void commandLoop(){};
	std::string getPromptString() { return ">";};
	void setCommand(std::string command) {};
};

class CommandHandler
{
public:
	CommandHandler(CommandFactory *command_factory):command_factory_(command_factory){};
	~CommandHandler(void){};

	bool executeCommand(std::string cmd, InputType input_typ_){ return false; };
	bool checkSyntax(std::string cmd, InputType input_typ_){ return false; };

private:
	CommandFactory* command_factory_;
	std::vector<std::string> splitCommand(std::string cmd){};
};

class CommandFactory
{
private:
	Shell *shell_;
	ControlUnit *control_unit_;
	std::vector<std::string> ordered_command_parts_;
	
public:
	CommandFactory(Shell *shell, ControlUnit *control_unit):shell_(shell) , control_unit_(control_unit){};
	~CommandFactory(void){};

	void addCommandParts(std::vector<std::string> command_parts);

	void createResourceType(){};
	void createResource(){};
	void createTask(){};
	void createProject(){};

	void deleteResourceType(){};
	void deleteResource(){};
	void deleteTask(){};
	void deleteProject(){};

	void checkForCollisions(){};
	void save(){};
	void load(){};

};

#endif IO_H_
