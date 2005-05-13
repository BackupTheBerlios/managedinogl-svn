#ifndef DATA_BASE_H_
#define DATA_BASE_H_

#include <vector>
#include "datatypes.h"

class XmlIO
{
public:
	XmlIO(void){};
	~XmlIO(void){};

	bool writeProject(Project project, unsigned int id){ return false; };
	bool writeTask(Task task, unsigned int id){ return false; };
	bool writeResource(Resource resource, unsigned int id){ return false; };
	bool writeResourceType(ResourceType resource_type, unsigned int id){ return false; };

	Project readProject(unsigned int id){ return *(new Project()); };
	Task readTask(unsigned int id){ return *(new Task()); };
	Resource readResource(unsigned int id){ return *(new Resource()); };
	ResourceType readResourceType(unsigned int id){ return *(new ResourceType()); };
};



class Database
{
public:
	Database(void){};
	~Database(void){};

	bool saveAllProjects(std::vector<Project> projects){ return false; };
	bool saveAllTasks(std::vector<Task> tasks){ return false; };
	bool saveAllResources(std::vector<Resource> resources){ return false; };
	bool saveAllResourceTypes(std::vector<ResourceType> resource_types){ return false; };

	std::vector<Project> loadAllProjects(){ return std::vector<Project>(); };
	std::vector<Task> loadAllTasks(){ return std::vector<Task>(); };
	std::vector<Resource> loadAllResources(){ return std::vector<Resource>(); };
	std::vector<ResourceType> loadAllResourceTypes(){ return std::vector<ResourceType>(); };

private:
	XmlIO io_module_;
};

#endif DATA_BASE_H_
