#ifndef DATA_TYPES_H_
#define DATA_TYPES_H_

#include <string>
#include <vector>

class DynamicProperty
{
public:
	DynamicProperty(void){};
	~DynamicProperty(void){};

	std::string getName(){ return name_; };
	void setName(std::string name){ name_ = name; };

	std::string getDescription(){ return description_; };
	void setDescription(std::string description){ description_ = description; };

	std::string getValue(){ return value_; };
	void setValue(std::string value){ value_ = value; };

private:
	std::string name_;
	std::string description_;
	std::string value_;
};


class ResourceType
{
public:
	ResourceType(void){};
	~ResourceType(void){};

	std::string getName(){ return name_; };
	void setName(std::string name){};

	int getID(){ return id_; };
	void setID(int id){};

	std::vector<DynamicProperty> getAllProperties(){ return properties_; };
	DynamicProperty getPropertyAt(unsigned int index){ return properties_[index]; };
	void deletePropertyAt(unsigned int index){};
	unsigned int getPropertyCount(){ return static_cast<unsigned int>(properties_.size()); };
	void addProperty(DynamicProperty property){};

private:
	std::string name_;
	int id_;
	std::vector<DynamicProperty> properties_;
};


class Resource
{
public:
	Resource(void){};
	~Resource(void){};

	std::string getName(){ return name_; };
	void setName(std::string name){};

	std::string getDescription(){ return description_; };
	void setDescription(std::string description){};

	time_t getAvailableFrom(){ return available_from_; };
	void setAvailableFrom(time_t time){};

	time_t getAvailableUntil(){  return available_until_; };
	void setAvailableUntil(time_t time){};

	unsigned int getMaximumUsage(){ return max_usage_; };
	void setMaximusUsage(unsigned int usage){};

	ResourceType getResourceType(){ return resource_type_; };
	void setResourceType(ResourceType resource_type){};

private:
	std::string name_;
	std::string description_;
	time_t available_from_;
	time_t available_until_;
	unsigned int max_usage_;
	ResourceType resource_type_;
};


class Task
{
public:
	Task(void){};
	~Task(void){};

	std::string getName(){ return name_; };
	void setName(std::string name){};

	std::string getDescription(){ return description_; };
	void setDescription(std::string description){};

	time_t getStartTime(){ return start_time_; };
	void setStartTime(time_t time){};

	time_t getEndTime(){ return end_time_; };
	void setEndTime(time_t time){};

	std::vector<Resource> getAllResources(){ return resources_; };
	Resource getResourceAt(unsigned int index){ return resources_[index]; };
	void deleteResourceAt(unsigned int index){};
	unsigned int getResourceCount(){ return static_cast<unsigned int>(resources_.size()); };
	void addResource(Resource resource){};

private:
	std::string name_;
	std::string description_;
	time_t start_time_;
	time_t end_time_;
	std::vector<Resource> resources_;
};

class Project
{
public:
	Project(void){};
	~Project(void){};

	std::string getName(){ return name_; };
	void setName(std::string name){};

	std::string getDescription(){ return description_; };
	void setDescription(std::string description){};

	time_t getStartTime(){ return start_time_; };
	void setStartTime(time_t time){};

	time_t getEndTime(){ return end_time_; };
	void setEndTime(time_t time){};

	std::vector<Task> getAllTasks(){ return tasks_; };
	Task getTaskAt(unsigned int index){ return tasks_[index]; };
	void deleteTaskAt(unsigned int index){};
	unsigned int getTaskCount(){ return static_cast<unsigned int>(tasks_.size()); };
	void addTask(Task task){};


private:
	std::string name_;
	std::string description_;
	time_t start_time_;
	time_t end_time_;
	std::vector<Task> tasks_;
};

#endif DATA_TYPES_H_
