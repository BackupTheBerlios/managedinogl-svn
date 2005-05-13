#ifndef RESOURCE_MANAGER_H_
#define RESOURCE_MANAGER_H_

#include "system.h"
#include "io.h"

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	int run();
private:
	ControlUnit control_unit_; 
	Shell shell_;
	CommandHandler command_handler_;
	CommandFactory command_factory_;
};


#endif RESOURCE_MANAGER_H_
