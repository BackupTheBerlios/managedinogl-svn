#include "resourcemanager.h"
#include "tests.h"

ResourceManager::ResourceManager() : command_factory_(&shell_, &control_unit_), 
										command_handler_(&command_factory_)
{
	//System system;
	//Shell shell;
	//CommandFactory factory(&shell,&system);
	//CommandHandler handler(&factory);
	//shell.setHandlerReference(&handler);
}

ResourceManager::~ResourceManager()
{
}

int ResourceManager::run()
{
	return 0;
}

int main()
{
	testMain();
	ResourceManager application;
	return application.run();
}
