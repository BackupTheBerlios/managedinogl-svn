#pragma once

#include <vector>
#include "datatypes.h"
#include "database.h"


class DataContent
{
public:
	DataContent(void){};
	~DataContent(void){};

	std::vector<ResourceType> *getResourceTypeListReference()
	{ return &resource_type_list_; };
	std::vector<Resource> *getResourceListReference()
	{ return &resource_list_; };
	std::vector<Task> *getTaskListReference()
	{ return &task_list_; };
	std::vector<Project> *getProjectListReference()
	{ return &project_list_; };

private:
	std::vector<ResourceType> resource_type_list_;
	std::vector<Resource> resource_list_;
	std::vector<Task> task_list_;
	std::vector<Project> project_list_;
};

class CollisionDetector
{
public:
	CollisionDetector(const DataContent *data_content){};
	~CollisionDetector(void){};

	bool checkForTimeCollisions(){ return false; };
	bool checkForResourceUsageCollisions(){ return false; };
private:
	const DataContent *data_content_;
};

enum SystemStatus
{
	NOTHING_SELECTED,
	PROJECT_SELECTED,
	TASK_SELECTED
};

class ControlUnit
{
public:
	ControlUnit(void):collision_detector_(&data_content_){};
	~ControlUnit(void){};

	bool addProject(std::string name, std::string description, 
		time_t start_time, time_t end_time){ return false; };
	bool addTask(std::string name, std::string description, time_t 
		start_time, time_t end_time){ return false; };
	bool addRessouce(std::string name, std::string description, 
		time_t available_from, time_t available_until, 
		unsigned int maximum_usage){ return false; };
	SystemStatus getStatus(){ return system_status_; };
	bool selectProject(std::string name) { return false; };
	bool selectTask(std::string name) { return false; };
	bool selectResource(std::string name) { return false; };
	bool selectNone() { return false; };
	bool checkForTimeCollisions() { return false; };
	bool checkForResourceUsageCollisions() { return false; };

	bool applyResourceToTask(std::string task_name, std::string resource_name) { return false; };
	
	bool changeProjectPropertyName(std::string name) { return false; };
	bool changeProjectPropertyDescription(std::string description) { return false; };
	bool changeProjectPropertyStartTime(time_t time) { return false; };
	bool changeProjectPropertyEndTime(time_t time) { return false; };

	bool changeTaskPropertyName(std::string name) { return false; };
	bool changeTaskPropertyDescription(std::string description) { return false; };
	bool changeTaskPropertyStartTime(time_t time) { return false; };
	bool changeTaskPropertyEndTime(time_t time) { return false; };

	bool changeResourcePropertyName(std::string name) { return false; };
	bool changeResourcePropertyMaxUsage(unsigned int max_usage) { return false; };
	bool changeResourcePropertyAvailableStartTime(time_t time) { return false; };
	bool changeResourcePropertyAvailableEndTime(time_t time) { return false; };
	bool changeResourcePropertyType(std::string type_name) { return false; };

	bool renameResourceType(std::string old_name, std::string name) { return false; };	
private:
	SystemStatus system_status_;
	DataContent data_content_;
	CollisionDetector collision_detector_;
	Database database_;
};

