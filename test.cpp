#include "tests.h"
#include <assert.h>
#include <string>
#include <vector>
#include "datatypes.h"
#include "database.h"
#include "system.h"
#include "io.h"

using std::string;
using std::vector;

//--------------------------------------------------------------------------------------------
///
/// testDynamicProperty tests all Getter- und Setter-Methods of DynamicProperty
void testDynamicProperty()
{
	DynamicProperty test_property;

	test_property.setDescription(TEST_STRING_1);
	assert(TEST_STRING_1 == test_property.getDescription());

	test_property.setName(TEST_STRING_2);
	assert(TEST_STRING_2 == test_property.getName());

	test_property.setValue(TEST_STRING_3);
	assert(TEST_STRING_3 == test_property.getValue());
}

//--------------------------------------------------------------------------------------------
///
/// testResourceType tests all Getter- und Setter-Methods of ResourceType
void testResourceType()
{
	ResourceType test_resource_type;
	DynamicProperty test_property;

	test_property.setName(TEST_STRING_1);
	test_property.setDescription(TEST_STRING_2);
	test_property.setValue(TEST_STRING_3);

	test_resource_type.setName(TEST_STRING_1);
	assert(TEST_STRING_1 == test_resource_type.getName());

	test_resource_type.setID(TEST_UINT_NUMBER_1);
	assert(TEST_UINT_NUMBER_1 == test_resource_type.getID());

	test_resource_type.addProperty(test_property);
	
	assert(test_property.getName() == test_resource_type.getPropertyAt(0).getName());
	assert(test_property.getDescription() == 
		test_resource_type.getPropertyAt(0).getDescription());
	assert(test_property.getValue() == test_resource_type.getPropertyAt(0).getValue());

	assert(1 == test_resource_type.getPropertyCount());
	assert(1 == test_resource_type.getAllProperties().size());

	test_resource_type.deletePropertyAt(0);

	assert(0 == test_resource_type.getPropertyCount());
	assert(0 == test_resource_type.getAllProperties().size());
}

//--------------------------------------------------------------------------------------------
///
/// testResource tests all Getter- und Setter-Methods of Resource
void testResource()
{
	Resource test_resource;
	ResourceType test_resource_type;

	test_resource_type.setID(TEST_UINT_NUMBER_1);
	test_resource_type.setName(TEST_STRING_1);

	test_resource.setAvailableFrom(TEST_TIME_1);
	assert(TEST_TIME_1 == test_resource.getAvailableFrom());

	test_resource.setAvailableUntil(TEST_TIME_2);
	assert(TEST_TIME_2 == test_resource.getAvailableUntil());

	test_resource.setDescription(TEST_STRING_1);
	assert(TEST_STRING_1 == test_resource.getDescription());

	test_resource.setName(TEST_STRING_2);
	assert(TEST_STRING_2 == test_resource.getName());

	test_resource.setMaximusUsage(TEST_UINT_NUMBER_1);
	assert(TEST_UINT_NUMBER_1 == test_resource.getMaximumUsage());

	test_resource.setResourceType(test_resource_type);
	assert(TEST_UINT_NUMBER_1 == test_resource.getResourceType().getID());
	assert(TEST_STRING_1 == test_resource.getResourceType().getName());
}

//--------------------------------------------------------------------------------------------
///
/// testTask tests all Getter- und Setter-Methods of Task
void testTask()
{
	Task test_task;
	Resource test_resource;

	test_resource.setAvailableFrom(TEST_TIME_1);
	test_resource.setAvailableUntil(TEST_TIME_2);
	test_resource.setDescription(TEST_STRING_1);
	test_resource.setName(TEST_STRING_2);
	test_resource.setMaximusUsage(TEST_UINT_NUMBER_1);


	test_task.setDescription(TEST_STRING_1);
	assert(TEST_STRING_1 == test_task.getDescription());

	test_task.setName(TEST_STRING_2);
	assert(TEST_STRING_2 == test_task.getName());

	test_task.setStartTime(TEST_TIME_1);
	assert(TEST_TIME_1 == test_task.getStartTime());
	
	test_task.setEndTime(TEST_TIME_2);
	assert(TEST_TIME_2 == test_task.getEndTime());


	test_task.addResource(test_resource);
	
	assert(test_resource.getName() == test_task.getResourceAt(0).getName());
	assert(test_resource.getDescription() == test_task.getResourceAt(0).getDescription());
	assert(test_resource.getAvailableFrom() == test_task.getResourceAt(0).getAvailableFrom());
	assert(test_resource.getAvailableUntil() == test_task.getResourceAt(0).getAvailableUntil());
	assert(test_resource.getMaximumUsage() == test_task.getResourceAt(0).getMaximumUsage());


	assert(1 == test_task.getResourceCount());
	assert(1 == test_task.getAllResources().size());

	test_task.deleteResourceAt(0);

	assert(0 == test_task.getResourceCount());
	assert(0 == test_task.getAllResources().size());
}

//--------------------------------------------------------------------------------------------
///
/// testProject tests all Getter- und Setter-Methods of Project
void testProject()
{
	Project test_project;
	Task test_task;

	test_task.setDescription(TEST_STRING_1);
	test_task.setEndTime(TEST_TIME_1);
	test_task.setStartTime(TEST_TIME_2);
	test_task.setName(TEST_STRING_2);

	test_project.setDescription(TEST_STRING_1);
	assert(TEST_STRING_1 == test_project.getDescription());

	test_project.setName(TEST_STRING_2);
	assert(TEST_STRING_2 == test_project.getName());

	test_project.setEndTime(TEST_TIME_1);
	assert(TEST_TIME_1 == test_project.getEndTime());

	test_project.setStartTime(TEST_TIME_2);
	assert(TEST_TIME_2 == test_project.getStartTime());

	test_project.addTask(test_task);

	assert(test_task.getName() == test_project.getTaskAt(0).getName());
	assert(test_task.getDescription() == test_project.getTaskAt(0).getDescription());
	assert(test_task.getStartTime() == test_project.getTaskAt(0).getStartTime());
	assert(test_task.getEndTime() == test_project.getTaskAt(0).getEndTime());


	assert(1 == test_project.getTaskCount());
	assert(1 == test_project.getAllTasks().size());

	test_project.deleteTaskAt(0);

	assert(0 == test_project.getTaskCount());
	assert(0 == test_project.getAllTasks().size());
}

//--------------------------------------------------------------------------------------------
///
/// testXmlIO creates a project, a task, a resource and a resource-type to test its reader
/// and writer-Methods by comparing the loaded values with the old ones.
void testXmlIO()
{
	XmlIO xml;

	Project test_project;
	Project test_project_result;

	Task test_task;
	Task test_task_result;

	Resource test_resource;
	Resource test_resource_result;

	ResourceType test_resource_type;
	ResourceType test_resource_type_result;


	test_project.setDescription(TEST_STRING_1);
	test_project.setName(TEST_STRING_2);

	test_task.setDescription(TEST_STRING_3);
	test_task.setName(TEST_STRING_1);

	test_resource.setDescription(TEST_STRING_2);
	test_resource.setName(TEST_STRING_3);

	test_resource_type.setName(TEST_STRING_2);

	assert(xml.writeProject(test_project,TEST_UINT_NUMBER_1));
	test_project_result = xml.readProject(TEST_UINT_NUMBER_1);

	assert(test_project.getDescription() == test_project_result.getDescription());
	assert(test_project.getName() == test_project_result.getName());

	assert(xml.writeTask(test_task,TEST_UINT_NUMBER_2));
	test_task_result = xml.readTask(TEST_UINT_NUMBER_2);

	assert(test_task.getDescription() == test_task_result.getDescription());
	assert(test_task.getName() == test_task_result.getName());

	assert(xml.writeResource(test_resource,TEST_UINT_NUMBER_3));
	test_resource_result = xml.readResource(TEST_UINT_NUMBER_3);

	assert(test_resource.getDescription() == test_resource_result.getDescription());
	assert(test_resource.getName() == test_resource_result.getName());

	assert(xml.writeResourceType(test_resource_type,TEST_UINT_NUMBER_3));
	test_resource_type_result = xml.readResourceType(TEST_UINT_NUMBER_3);

	assert(test_resource_type.getName() == test_resource_type_result.getName());
}

//--------------------------------------------------------------------------------------------
///
/// testDatabase creates Projekt-, Task-, Ressource- und RessourceTypeLists, being saved,
/// loaded and compared with the originals.
void testDatabase()
{
	Database database;

	Project project1;
	Project project2;
	Project project3;
	vector<Project> projects;
	vector<Project> projects_result;

	Task task1;
	Task task2;
	Task task3;
	vector<Task> tasks;
	vector<Task> tasks_result;

	Resource resource1;
	Resource resource2;
	Resource resource3;
	vector<Resource> resources;
	vector<Resource> resources_result;

	ResourceType resource_type1;
	ResourceType resource_type2;
	ResourceType resource_type3;
	vector<ResourceType> resource_types;
	vector<ResourceType> resource_types_result;

	project1.setName(TEST_STRING_1);
	project2.setName(TEST_STRING_2);
	project3.setName(TEST_STRING_3);
	projects.push_back(project1);
	projects.push_back(project2);
	projects.push_back(project3);

	database.saveAllProjects(projects);
	projects_result = database.loadAllProjects();

	assert(projects_result[0].getName() == project1.getName());
	assert(projects_result[1].getName() == project2.getName());
	assert(projects_result[2].getName() == project3.getName());


	task1.setName(TEST_STRING_1);
	task2.setName(TEST_STRING_2);
	task3.setName(TEST_STRING_3);
	tasks.push_back(task1);
	tasks.push_back(task2);
	tasks.push_back(task3);

	database.saveAllTasks(tasks);
	tasks_result = database.loadAllTasks();

	assert(tasks_result[0].getName() == task1.getName());
	assert(tasks_result[1].getName() == task2.getName());
	assert(tasks_result[2].getName() == task3.getName());


	resource1.setName(TEST_STRING_1);
	resource2.setName(TEST_STRING_2);
	resource3.setName(TEST_STRING_3);
	resources.push_back(resource1);
	resources.push_back(resource2);
	resources.push_back(resource3);

	database.saveAllResources(resources);
	resources_result = database.loadAllResources();

	assert(resources_result[0].getName() == resource1.getName());
	assert(resources_result[1].getName() == resource2.getName());
	assert(resources_result[2].getName() == resource3.getName());


	resource_type1.setName(TEST_STRING_1);
	resource_type2.setName(TEST_STRING_2);
	resource_type3.setName(TEST_STRING_3);
	resource_types.push_back(resource_type1);
	resource_types.push_back(resource_type2);
	resource_types.push_back(resource_type3);

	database.saveAllResourceTypes(resource_types);
	resource_types_result = database.loadAllResourceTypes();

	assert(resource_types_result[0].getName() == resource_type1.getName());
	assert(resource_types_result[1].getName() == resource_type2.getName());
	assert(resource_types_result[2].getName() == resource_type3.getName());
}

//--------------------------------------------------------------------------------------------
///
/// testCollisionDetector tests the following constructs in exactly this order:
///
/// project with 2 Tasks in project time not colliding in time and no resources
/// project with 2 tasks mixing up but in project time and no resources
/// project with 2 tasks - first out of project time and no resources
/// project with 2 tasks - second out of project time and no resources
/// project with 2 tasks - both out of project time and no resources
/// project with 2 tasks: first start=project start (both in project time) and no resources
/// project with 2 tasks - second end = project end (both in project time) and no resources
/// project with 2 tasks no time colliding with same resource available for both
/// project with 2 tasks no time colliding with same resource available for one of them
/// project with 2 tasks no time colliding with same resource available for none of them
/// project with 2 tasks time colliding with same resource available for none of them
/// project with 2 tasks time colliding with same resource available for one of them
/// project with 2 tasks time colliding with same resource available for both of them
void testCollisionDetector()
{
	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_6));
		assert(controler.selectProject(TEST_STRING_1));
		assert(controler.addTask(TEST_STRING_2,"",TEST_TIME_2,TEST_TIME_3));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_4,TEST_TIME_5));
		assert(controler.checkForTimeCollisions() == false);
		assert(controler.checkForResourceUsageCollisions() == false);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_6));
		assert(controler.selectProject(TEST_STRING_1));
		assert(controler.addTask(TEST_STRING_2,"",TEST_TIME_2,TEST_TIME_4));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_3,TEST_TIME_5));
		assert(controler.checkForTimeCollisions() == false);
		assert(controler.checkForResourceUsageCollisions() == false);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_2,TEST_TIME_6));
		assert(controler.selectProject(TEST_STRING_1));
		assert(controler.addTask(TEST_STRING_2,"",TEST_TIME_1,TEST_TIME_3));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_4,TEST_TIME_5));
		assert(controler.checkForTimeCollisions() == true);
		assert(controler.checkForResourceUsageCollisions() == false);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_5));
		assert(controler.selectProject(TEST_STRING_1));
		assert(controler.addTask(TEST_STRING_2,"",TEST_TIME_2,TEST_TIME_3));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_4,TEST_TIME_6));
		assert(controler.checkForTimeCollisions() == true);
		assert(controler.checkForResourceUsageCollisions() == false);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_2,TEST_TIME_5));
		assert(controler.selectProject(TEST_STRING_1));
		assert(controler.addTask(TEST_STRING_2,"",TEST_TIME_1,TEST_TIME_3));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_4,TEST_TIME_6));
		assert(controler.checkForTimeCollisions() == true);
		assert(controler.checkForResourceUsageCollisions() == false);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_6));
		assert(controler.selectProject(TEST_STRING_1));
		assert(controler.addTask(TEST_STRING_2,"",TEST_TIME_1,TEST_TIME_3));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_4,TEST_TIME_5));
		assert(controler.checkForTimeCollisions() == false);
		assert(controler.checkForResourceUsageCollisions() == false);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_6));
		assert(controler.selectProject(TEST_STRING_1));
		assert(controler.addTask(TEST_STRING_2,"",TEST_TIME_2,TEST_TIME_3));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_4,TEST_TIME_6));
		assert(controler.checkForTimeCollisions() == false);
		assert(controler.checkForResourceUsageCollisions() == false);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_6));
		assert(controler.selectProject(TEST_STRING_1));
		assert(controler.addTask(TEST_STRING_2,"",TEST_TIME_2,TEST_TIME_3));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_4,TEST_TIME_5));
		assert(controler.addRessouce(TEST_STRING_4,"",TEST_TIME_1,TEST_TIME_6,TEST_USAGE_2));
		assert(controler.applyResourceToTask(TEST_STRING_2,TEST_STRING_4));
		assert(controler.applyResourceToTask(TEST_STRING_3,TEST_STRING_4));
		assert(controler.checkForTimeCollisions() == false);
		assert(controler.checkForResourceUsageCollisions() == false);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_6));
		assert(controler.selectProject(TEST_STRING_1));
		assert(controler.addTask(TEST_STRING_2,"",TEST_TIME_2,TEST_TIME_3));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_4,TEST_TIME_5));
		assert(controler.addRessouce(TEST_STRING_4,"",TEST_TIME_1,TEST_TIME_6,TEST_USAGE_1));
		assert(controler.applyResourceToTask(TEST_STRING_2,TEST_STRING_4));
		assert(controler.applyResourceToTask(TEST_STRING_3,TEST_STRING_4));
		assert(controler.checkForTimeCollisions() == false);
		assert(controler.checkForResourceUsageCollisions() == false);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_6));
		assert(controler.selectProject(TEST_STRING_1));
		assert(controler.addTask(TEST_STRING_2,"",TEST_TIME_2,TEST_TIME_3));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_4,TEST_TIME_5));
		assert(controler.addRessouce(TEST_STRING_4,"",TEST_TIME_1,TEST_TIME_6,TEST_USAGE_0));
		assert(controler.applyResourceToTask(TEST_STRING_2,TEST_STRING_4));
		assert(controler.applyResourceToTask(TEST_STRING_3,TEST_STRING_4));
		assert(controler.checkForTimeCollisions() == false);
		assert(controler.checkForResourceUsageCollisions() == true);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_6));
		assert(controler.selectProject(TEST_STRING_1));
		assert(controler.addTask(TEST_STRING_2,"",TEST_TIME_2,TEST_TIME_3));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_4,TEST_TIME_5));
		assert(controler.addRessouce(TEST_STRING_4,"",TEST_TIME_1,TEST_TIME_6,TEST_USAGE_0));
		assert(controler.applyResourceToTask(TEST_STRING_2,TEST_STRING_4));
		assert(controler.applyResourceToTask(TEST_STRING_3,TEST_STRING_4));
		assert(controler.checkForTimeCollisions() == false);
		assert(controler.checkForResourceUsageCollisions() == true);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_6));
		assert(controler.selectProject(TEST_STRING_1));
		assert(controler.addTask(TEST_STRING_2,"",TEST_TIME_2,TEST_TIME_3));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_4,TEST_TIME_5));
		assert(controler.addRessouce(TEST_STRING_4,"",TEST_TIME_1,TEST_TIME_6,TEST_USAGE_0));
		assert(controler.applyResourceToTask(TEST_STRING_2,TEST_STRING_4));
		assert(controler.applyResourceToTask(TEST_STRING_3,TEST_STRING_4));
		assert(controler.checkForTimeCollisions() == false);
		assert(controler.checkForResourceUsageCollisions() == true);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_6));
		assert(controler.selectProject(TEST_STRING_1));
		assert(controler.addTask(TEST_STRING_2,"",TEST_TIME_2,TEST_TIME_3));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_4,TEST_TIME_5));
		assert(controler.addRessouce(TEST_STRING_4,"",TEST_TIME_1,TEST_TIME_6,TEST_USAGE_0));
		assert(controler.applyResourceToTask(TEST_STRING_2,TEST_STRING_4));
		assert(controler.applyResourceToTask(TEST_STRING_3,TEST_STRING_4));
		assert(controler.checkForTimeCollisions() == false);
		assert(controler.checkForResourceUsageCollisions() == false);
	}
}

//--------------------------------------------------------------------------------------------
///
/// testControlUnit tests the following constructs in exactly this order:
///
/// try to add project while having a project selected - must not work
/// try to add project while having a resource selected - must not work
/// try to add task while having a resource selected - must not work
/// try to add task while having a project selected - must work
/// try to add resource while having a resource selected - must work
/// try to add project while having a task selected - must not work
/// try to add 2 projects with same name - must not work
/// try to add 2 tasks to 1 project with same name - must not work
/// try to add 2 resources with same name - must not work
/// try to add 2 tasks with same name to 2 different projects - must work
void testControlUnit()
{
	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_3));
		assert(controler.selectProject(TEST_STRING_1));
		assert(controler.addProject(TEST_STRING_2,"",TEST_TIME_4,TEST_TIME_6) == false);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addRessouce(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_6,TEST_USAGE_1));
		assert(controler.selectResource(TEST_STRING_1));
		assert(controler.addProject(TEST_STRING_2,"",TEST_TIME_4,TEST_TIME_6) == false);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addRessouce(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_6,TEST_USAGE_1));
		assert(controler.selectResource(TEST_STRING_1));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_4,TEST_TIME_5) == false);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_6));
		assert(controler.selectProject(TEST_STRING_1));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_4,TEST_TIME_5) == true);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addRessouce(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_6,TEST_USAGE_1));
		assert(controler.selectResource(TEST_STRING_1));
		assert(controler.addRessouce(TEST_STRING_2,"",TEST_TIME_1,TEST_TIME_6,TEST_USAGE_1)
			==true);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_6));
		assert(controler.selectProject(TEST_STRING_1));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_4,TEST_TIME_5));
		assert(controler.selectTask(TEST_STRING_3));
		assert(controler.addProject(TEST_STRING_2,"",TEST_TIME_4,TEST_TIME_6) == false);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_3));
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_2,TEST_TIME_6) == false);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_3));
		assert(controler.selectProject(TEST_STRING_1));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_4,TEST_TIME_5));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_5,TEST_TIME_6) == false);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addRessouce(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_3,TEST_USAGE_1));
		assert(controler.addRessouce(TEST_STRING_1,"",TEST_TIME_4,
			TEST_TIME_6,TEST_USAGE_0)==false);
	}

	
	{
		ControlUnit controler;
		assert(controler.selectNone());
		assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_3));
		assert(controler.addProject(TEST_STRING_2,"",TEST_TIME_4,TEST_TIME_6));
		assert(controler.selectProject(TEST_STRING_1));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_1,TEST_TIME_3));
		assert(controler.selectProject(TEST_STRING_2));
		assert(controler.addTask(TEST_STRING_3,"",TEST_TIME_5,TEST_TIME_6));
	}

}

//--------------------------------------------------------------------------------------------
void testCommands()
{
	Shell shell;
	ControlUnit control_unit;

	CommandFactory command_factory(&shell, &control_unit);
	CommandHandler command_handler(&command_factory);

	///////////////////////////////////////////////////////////////////
	//tests the Handler, for checking the syntax, to a Input Typ
	// checkSyntax interacts with nothing
	///////////////////////////////////////////////////////////////////

	//user story: possible commands
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND1, COMMAND) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND2, COMMAND) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND3, COMMAND) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND4, COMMAND) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND5, COMMAND) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND6, COMMAND) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND7, COMMAND) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND8, COMMAND) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND9, COMMAND) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND10, COMMAND) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND11, COMMAND) == false);

	assert(command_handler.checkSyntax(TEST_BAD_COMMAND1, PLAIN_TEXT) == true);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND2, PLAIN_TEXT) == true);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND3, PLAIN_TEXT) == true);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND4, PLAIN_TEXT) == true);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND5, PLAIN_TEXT) == true);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND6, PLAIN_TEXT) == true);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND7, PLAIN_TEXT) == true);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND8, PLAIN_TEXT) == true);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND9, PLAIN_TEXT) == true);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND10, PLAIN_TEXT) == true);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND11, PLAIN_TEXT) == true);

	assert(command_handler.checkSyntax(TEST_COMMAND_HELP, COMMAND) == true);

	assert(command_handler.checkSyntax(TEST_COMMAND_SELECT, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_SELECT2, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_SELECT_PROJECT, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_SELECT_TASK, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_SELECT_RESOURCE, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_SELECT_RESOURCETYP, COMMAND) == true);

	assert(command_handler.checkSyntax(TEST_COMMAND_DELETE, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_DELETE2, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_DELETE_PROJECT, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_DELETE_TASK, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_DELETE_RESOURCE, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_DELETE_RESOURCETYP, COMMAND) == true);

	assert(command_handler.checkSyntax(TEST_COMMAND_CREATE, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_CREATE2, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_CREATE_PROJECT, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_CREATE_TASK, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_CREATE_RESOURCE, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_CREATE_RESOURCETYP, COMMAND) == true);

	assert(command_handler.checkSyntax(TEST_COMMAND_VIEW, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_VIEW2, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_VIEW_PROJECT, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_VIEW_TASK, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_VIEW_RESOURCE, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_VIEW_RESOURCETYP, COMMAND) == true);

	assert(command_handler.checkSyntax(TEST_COMMAND_EDIT, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_EDIT2, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_EDIT_PROJECT, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_EDIT_TASK, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_EDIT_RESOURCE, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_EDIT_RESOURCETYP, COMMAND) == true);

	assert(command_handler.checkSyntax(TEST_COMMAND_EDIT_NAME, PLAIN_TEXT) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_EDIT_DESCRIPTION, PLAIN_TEXT) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_EDIT_STARTTIME, PLAIN_TEXT) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_EDIT_ENDTIME, PLAIN_TEXT) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_EDIT_AVAILABLE_FROM, PLAIN_TEXT) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_EDIT_AVAILABLE_TO, PLAIN_TEXT) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_EDIT_USAGE, PLAIN_TEXT) == true);

	assert(command_handler.checkSyntax(TEST_COMMAND_A_NAME, PLAIN_TEXT) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_A_PROJECT_NAME, PLAIN_TEXT) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_A_TASK_NAME, PLAIN_TEXT) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_A_USAGE, NUMBER) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_A_DESCRIPTION, PLAIN_TEXT) == true);

	assert(command_handler.checkSyntax(TEST_COMMAND_ANYTIME, TIME_DATE) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_ANYTIME2, TIME_DATE) == true);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND_TIME, TIME_DATE) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND_TIME2, TIME_DATE) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND_TIME3, TIME_DATE) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND_TIME4, TIME_DATE) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND_TIME5, TIME_DATE) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND_TIME6, TIME_DATE) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND_TIME7, TIME_DATE) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND_TIME8, TIME_DATE) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND_TIME9, TIME_DATE) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND_TIME10, TIME_DATE) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND_TIME11, TIME_DATE) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND_TIME12, TIME_DATE) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND_TIME13, TIME_DATE) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND_TIME14, TIME_DATE) == false);
	assert(command_handler.checkSyntax(TEST_BAD_COMMAND_TIME15, TIME_DATE) == false);

	assert(command_handler.checkSyntax(TEST_COMMAND_CHECK_TIMECOLLISIONS, COMMAND) == true);
	assert(command_handler.checkSyntax(TEST_COMMAND_CHECK_RESOURCE_USEAGE, COMMAND) == true);

	///////////////////////////////////////////////////////////////////
	//tests the Handler and the Factory, not the ControlUnit (Semantik)
	// the basic syntax have to be correct (like time format and commands)
	// thats checked in the checksyntax section
	//
	// executeCommand interacts with the Factory
	// after an error the factory and the handler waits for new inputs 
	// from the shell
	///////////////////////////////////////////////////////////////////

	//user story: create Project:
	assert(command_handler.executeCommand(TEST_COMMAND_CREATE, COMMAND) == true);
	assert(command_handler.executeCommand(TEST_COMMAND_PROJECT, PLAIN_TEXT) == true);
	assert(command_handler.executeCommand(TEST_COMMAND_A_PROJECT_NAME, PLAIN_TEXT) == true);
	assert(command_handler.executeCommand(TEST_COMMAND_A_DESCRIPTION, PLAIN_TEXT) == true);
	assert(command_handler.executeCommand(TEST_COMMAND_ANYTIME, TIME_DATE) == true);
	assert(command_handler.executeCommand(TEST_COMMAND_ANYTIME2, TIME_DATE) == true);

	//user story: task creation only possible in a project
	assert(command_handler.executeCommand(TEST_COMMAND_CREATE, COMMAND) == true);
	assert(command_handler.executeCommand(TEST_COMMAND_TASK, PLAIN_TEXT) == false);
	
	//thats the right way:
	assert(command_handler.executeCommand(TEST_COMMAND_VIEW_PROJECT, COMMAND) == true);
	assert(command_handler.executeCommand(TEST_COMMAND_A_PROJECT_NAME, PLAIN_TEXT) == true);
	assert(command_handler.executeCommand(TEST_COMMAND_CREATE, COMMAND) == true);
	assert(command_handler.executeCommand(TEST_COMMAND_A_TASK_NAME, PLAIN_TEXT) == true);
	assert(command_handler.executeCommand(TEST_COMMAND_ANYTIME, TIME_DATE) == true);
	assert(command_handler.executeCommand(TEST_COMMAND_ANYTIME2, TIME_DATE) == true);

	//user story: create resource everywere:
	assert(command_handler.executeCommand(TEST_COMMAND_CREATE_RESOURCE, COMMAND) == true);
	//not possible because resource typ doesn't exsists!
	assert(command_handler.executeCommand(TEST_COMMAND_A_RESOURCETYP_NAME, PLAIN_TEXT)
		==false);

	//user story: create a resource typ:
	assert(command_handler.executeCommand(TEST_COMMAND_CREATE_RESOURCETYP, PLAIN_TEXT)
		== true);
	assert(command_handler.executeCommand(TEST_COMMAND_A_RESOURCETYP_NAME, COMMAND) == true);
	assert(command_handler.executeCommand(TEST_COMMAND_A_DESCRIPTION, PLAIN_TEXT) == true);

	//now wie can use this resourcetyp:
	assert(command_handler.executeCommand(TEST_COMMAND_CREATE_RESOURCE, COMMAND) == true);
	assert(command_handler.executeCommand(TEST_COMMAND_A_RESOURCETYP_NAME, PLAIN_TEXT)
		== true);
	assert(command_handler.executeCommand(TEST_COMMAND_A_RESOURCE_NAME, PLAIN_TEXT) == true);
	assert(command_handler.executeCommand(TEST_COMMAND_A_DESCRIPTION, PLAIN_TEXT) == true);
	assert(command_handler.executeCommand(TEST_COMMAND_ANYTIME, TIME_DATE) == true);
	//not possible because te time/date is the same, do not abort here:
	assert(command_handler.executeCommand(TEST_COMMAND_ANYTIME, TIME_DATE) == false);
	//thats not possible because it have to checked in checkSyntax(..)!!!
	//assert(command_handler.executeCommand(TEST_COMMAND_A_DESCRIPTION, TIME_DATE) == false);
	//thats working:
	assert(command_handler.executeCommand(TEST_COMMAND_ANYTIME2, TIME_DATE) == true);
	assert(command_handler.executeCommand(TEST_COMMAND_A_USAGE, TIME_DATE) == true);

}

//--------------------------------------------------------------------------------------------
///
/// testShell tests the shell and all subkomponents for right behavior
/// espacially the shell for right output/input
void testShell()
{
	TestShell shell;
	ControlUnit control_unit;
	CommandFactory command_factory(&shell, &control_unit);
	CommandHandler command_handler(&command_factory);

	shell.startShell();
	shell.setCommand(TEST_COMMAND_A_DESCRIPTION);
	assert(shell.getPromptString() == TEST_OUTPUT_ERROR_MALFORMED);
	shell.setCommand(TEST_COMMAND_CREATE);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_OBJECT);
	shell.setCommand(TEST_COMMAND_PROJECT);
	assert(shell.getPromptString() == TEST_OUTPUT_CREATE_PROJECT);
	shell.setCommand(TEST_COMMAND_A_PROJECT_NAME);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_DESCRIPTION);
	shell.setCommand(TEST_COMMAND_A_DESCRIPTION);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_STARTTIME);
	shell.setCommand(TEST_COMMAND_ANYTIME);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_ENDTIME);
	shell.setCommand(TEST_COMMAND_ANYTIME2);
	assert(shell.getPromptString() == TEST_OUTPUT_PROJECT_CREATED);
}

//--------------------------------------------------------------------------------------------
void testMain()
{
	testDynamicProperty();
	testResourceType();
	testResource();
	testTask();
	testProject();
	testXmlIO();
	testDatabase();
	testControlUnit();
	testCollisionDetector();
	testCommands();
	testShell();
}
