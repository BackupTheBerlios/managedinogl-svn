#ifndef TESTS_H_
#define TESTS_H_

#include <string>

static const std::string TEST_STRING_1 = "Test String 1";
static const std::string TEST_STRING_2 = "Test String 2";
static const std::string TEST_STRING_3 = "Test String 3";
static const std::string TEST_STRING_4 = "Test String 4";

static const unsigned int TEST_UINT_NUMBER_1 = 300;
static const unsigned int TEST_UINT_NUMBER_2 = 301;
static const unsigned int TEST_UINT_NUMBER_3 = 302;
static const unsigned int TEST_UINT_NUMBER_4 = 303;

static const unsigned int TEST_USAGE_0 = 0;
static const unsigned int TEST_USAGE_1 = 1;
static const unsigned int TEST_USAGE_2 = 2;

static const time_t TEST_TIME_1 = 1013120140;
static const time_t TEST_TIME_2 = 1013120150;
static const time_t TEST_TIME_3 = 1013120160;
static const time_t TEST_TIME_4 = 1013120170;
static const time_t TEST_TIME_5 = 1013120180;
static const time_t TEST_TIME_6 = 1013120190;

////////////////////////////////////////////
// Program input test strings
////////////////////////////////////////////

static const std::string TEST_BAD_COMMAND1 = "__---__";
static const std::string TEST_BAD_COMMAND2 = "1234564 678";
static const std::string TEST_BAD_COMMAND3 = ".";
static const std::string TEST_BAD_COMMAND4 = "!§$%&/%/()";
static const std::string TEST_BAD_COMMAND5 = "select anything";
static const std::string TEST_BAD_COMMAND6 = "delete anything";
static const std::string TEST_BAD_COMMAND7 = "select anything";
static const std::string TEST_BAD_COMMAND8 = "view anything";
static const std::string TEST_BAD_COMMAND9 = "create anything";
static const std::string TEST_BAD_COMMAND10 = "edit anything";
static const std::string TEST_BAD_COMMAND11 = "select project too many arguments";
static const std::string TEST_BAD_COMMAND12 = "select anything";

static const std::string TEST_COMMAND_HELP = "help";
static const std::string TEST_COMMAND_SHOW_CURRENT = "dir";
static const std::string  TEST_COMMAND_QUIT = "exit";

static const std::string TEST_COMMAND_SELECT = "select";
static const std::string TEST_COMMAND_SELECT2 = "select    ";
static const std::string TEST_COMMAND_SELECT_PROJECT = "select project";
static const std::string TEST_COMMAND_SELECT_TASK = "select task";
static const std::string TEST_COMMAND_SELECT_RESOURCE = "select resource";
static const std::string TEST_COMMAND_SELECT_RESOURCETYP = "select resourcetyp";

static const std::string TEST_COMMAND_DELETE = "delete";
static const std::string TEST_COMMAND_DELETE2 = "delete    ";
static const std::string TEST_COMMAND_DELETE_PROJECT = "delete project";
static const std::string TEST_COMMAND_DELETE_TASK = "delete task";
static const std::string TEST_COMMAND_DELETE_RESOURCE = "delete resource";
static const std::string TEST_COMMAND_DELETE_RESOURCETYP = "delete resourcetyp";

static const std::string TEST_COMMAND_CREATE = "create";
static const std::string TEST_COMMAND_CREATE2 = "create    ";
static const std::string TEST_COMMAND_CREATE_PROJECT = "create project";
static const std::string TEST_COMMAND_CREATE_TASK = "create task";
static const std::string TEST_COMMAND_CREATE_RESOURCE = "create resource";
static const std::string TEST_COMMAND_CREATE_RESOURCETYP = "create resourcetyp";

static const std::string TEST_COMMAND_VIEW = "view";
static const std::string TEST_COMMAND_VIEW2 = "view    ";
static const std::string TEST_COMMAND_VIEW_PROJECT = "view project";
static const std::string TEST_COMMAND_VIEW_TASK = "view task";
static const std::string TEST_COMMAND_VIEW_RESOURCE = "view resource";
static const std::string TEST_COMMAND_VIEW_RESOURCETYP = "view resourcetyp";

static const std::string TEST_COMMAND_EDIT = "edit";
static const std::string TEST_COMMAND_EDIT2 = "edit    ";
static const std::string TEST_COMMAND_EDIT_PROJECT = "edit project";
static const std::string TEST_COMMAND_EDIT_TASK = "edit task";
static const std::string TEST_COMMAND_EDIT_RESOURCE = "edit resource";
static const std::string TEST_COMMAND_EDIT_RESOURCETYP = "edit resourcetyp";

static const std::string TEST_OUTPUT_ENTER_PROPERTY = "please enter property:";
static const std::string TEST_COMMAND_EDIT_NAME = "name";
static const std::string TEST_COMMAND_EDIT_DESCRIPTION = "description";
static const std::string TEST_COMMAND_EDIT_STARTTIME = "starttime";
static const std::string TEST_COMMAND_EDIT_ENDTIME = "endtime";
static const std::string TEST_COMMAND_EDIT_AVAILABLE_FROM = "from";
static const std::string TEST_COMMAND_EDIT_AVAILABLE_TO = "to";
static const std::string TEST_COMMAND_EDIT_USAGE = "usage";

static const std::string TEST_COMMAND_ADD_RESOURCE_TO_TASK = "add resource";

static const std::string TEST_COMMAND_PROJECT = "project";
static const std::string TEST_COMMAND_TASK = "task";
static const std::string TEST_COMMAND_RESOURCE = "resource";
static const std::string TEST_COMMAND_RESOURCETYP = "resourcetyp";

static const std::string TEST_COMMAND_APPLY = "apply";
static const std::string TEST_COMMAND_SAVE = "save";
static const std::string TEST_COMMAND_LOAD = "load";

static const std::string TEST_COMMAND_ANYADESCRIPTION = "this is a description of something...";
static const std::string TEST_COMMAND_ANYNAME = "hugo boss";
static const std::string TEST_COMMAND_A_NAME = "hugo boss";
static const std::string TEST_COMMAND_A_RESOURCE_NAME = "Java in 21 days";
static const std::string TEST_COMMAND_A_RESOURCE_NAME2 = "C++ in 21 days";
static const std::string TEST_COMMAND_A_RESOURCETYP_NAME = "book";
static const std::string TEST_COMMAND_A_PROJECT_NAME = "vis task3";
static const std::string TEST_COMMAND_A_TASK_NAME = "write the test";
static const std::string TEST_COMMAND_A_TASK_NAME2 = "implement the algorithmus";
static const std::string TEST_COMMAND_A_USAGE = "5";
static const std::string TEST_COMMAND_A_USAGE2 = "1";
static const std::string TEST_COMMAND_A_DESCRIPTION = "this is a description of something...";
static const std::string TEST_COMMAND_ANYTIME = "10:30 25.11.2005";
static const std::string TEST_COMMAND_ANYTIME2 = "19:30 26.11.2005";
static const std::string TEST_COMMAND_ANYTIME3 = "10:30 25.11.2006";
static const std::string TEST_COMMAND_ANYTIME4 = "19:30 26.11.2006";

static const std::string TEST_BAD_COMMAND_TIME = "19:3026.11.2005";
static const std::string TEST_BAD_COMMAND_TIME2 = "19:30 26.112005";
static const std::string TEST_BAD_COMMAND_TIME3 = "1930 26.11.2005";
static const std::string TEST_BAD_COMMAND_TIME4 = "19:30 d6.11.2005";
static const std::string TEST_BAD_COMMAND_TIME5 = "24:30 26.11.2005";
static const std::string TEST_BAD_COMMAND_TIME6 = "19:30 26.11.965";
static const std::string TEST_BAD_COMMAND_TIME7 = "19:30 30.02.2005";
static const std::string TEST_BAD_COMMAND_TIME8 = "19:30 0.02.2005";
static const std::string TEST_BAD_COMMAND_TIME9 = "19:30 10.0.2005";
static const std::string TEST_BAD_COMMAND_TIME10 = "19:3 10.10.2005";
static const std::string TEST_BAD_COMMAND_TIME11 = "19:30 32.10.2005";
static const std::string TEST_BAD_COMMAND_TIME12 = "19:30 26.13.2005";
static const std::string TEST_BAD_COMMAND_TIME13 = "19:30 26.10.20005";
static const std::string TEST_BAD_COMMAND_TIME14 = "26.10.2005 19:30";
static const std::string TEST_BAD_COMMAND_TIME15 = "19:30 26/11/2005";

static const std::string TEST_COMMAND_CHECK_TIMECOLLISIONS = "check time";
static const std::string TEST_COMMAND_CHECK_RESOURCE_USEAGE = "check usage";
static const std::string TEST_COMMAND_EMPTY_STRING = "";

static const std::string TEST_COMMAND_YES = "y";
static const std::string TEST_COMMAND_NO = "n";

////////////////////////////////////////////
// Program output test strings
////////////////////////////////////////////

static const std::string TEST_OUTPUT_CREATE_PROJECT = "name of new project:";
static const std::string TEST_OUTPUT_CREATE_RESOURCETYP = "name of new resourcetyp:";
static const std::string TEST_OUTPUT_CREATE_RESOURCE = "name of new resource:";
static const std::string TEST_OUTPUT_CREATE_TASK = "name of new task:";

static const std::string TEST_OUTPUT_ERROR_NO_PROJECT_SELECTED = "please select a project first!";

static const std::string TEST_OUTPUT_ENTER_RESOURCETYPE = "type of resource:";
static const std::string TEST_OUTPUT_ENTER_DESCRIPTION = "description:";
static const std::string TEST_OUTPUT_ENTER_STARTTIME = "starttime (hh:ss dd:mm:yyyy):";
static const std::string TEST_OUTPUT_ENTER_ENDTIME = "endtime (hh:ss dd:mm:yyyy):";
static const std::string TEST_OUTPUT_ENTER_MAX_USAGE = "maximum usage:";
static const std::string TEST_OUTPUT_ENTER_TO_PROJECT = "to project:";
static const std::string TEST_OUTPUT_ENTER_TO_TASK = "to task:";

static const std::string TEST_OUTPUT_ENTER_OBJECT = "project, task, resource, resourcetyp?:";
static const std::string TEST_OUTPUT_ENTER_PROJECTNAME = "project name?:";
static const std::string TEST_OUTPUT_ENTER_TASKNAME = "task name?:";
static const std::string TEST_OUTPUT_ENTER_RESOURCENAME = "resource name?:";
static const std::string TEST_OUTPUT_ENTER_RESOURCETYPENAME = "resourcetyp name?:";

static const std::string TEST_OUTPUT_ENTER_SURE = "are you sure?(y/n):";
static const std::string TEST_OUTPUT_ENTER_SURE_DELETING_TASKS = "are you sure to delete the remaining tasks?(y/n):";
static const std::string TEST_OUTPUT_COLLISIONS = "there are collisions...";
static const std::string TEST_OUTPUT_CRITICAL = "there are critical collisions!";
static const std::string TEST_OUTPUT_USAGE_COLLISIONS = "there are usage collisions...";
static const std::string TEST_OUTPUT_NO_COLLISIONS = "no collisions";

static const std::string TEST_OUTPUT_ENTER_ABORT = "abort?(y/n):";

static const std::string TEST_OUTPUT_RESOURCE_AVAILABLE = "resources available:";
static const std::string TEST_OUTPUT_AVAILABLE = "available:";

static const std::string TEST_OUTPUT_RESOURCE_NAME = "resource name:";
static const std::string TEST_OUTPUT_RESOURCE_TYP = "resource typ:";
static const std::string TEST_OUTPUT_RESOURCE_DESCRIPTION = "resource description:";
static const std::string TEST_OUTPUT_RESOURCE_MAX_USAGE = "max. usage:";
static const std::string TEST_OUTPUT_RESOURCE_AVAILABLE_FROM = "available from:";
static const std::string TEST_OUTPUT_RESOURCE_AVAILABLE_TO = "available to:";

static const std::string TEST_OUTPUT_ERROR_MALFORMED = "malformed, please re-enter";
static const std::string TEST_OUTPUT_ERROR_RESOURCE_EXSISTS = "sorry, resource name already exsists";
static const std::string TEST_OUTPUT_ERROR_TASK_EXSISTS = "sorry, task name already exsists in this project";
static const std::string TEST_OUTPUT_ERROR_PROJECT_EXSISTS = "sorry, project name already exsists";
static const std::string TEST_OUTPUT_ERROR_RESOURCETYP_EXSISTS = "sorry, resourcetyp name already exsists";

static const std::string TEST_OUTPUT_RESOURCETYP_CREATED = "resourcetyp created";
static const std::string TEST_OUTPUT_RESOURC_CREATED = "resource created";
static const std::string TEST_OUTPUT_PROJECT_CREATED = "project created";
static const std::string TEST_OUTPUT_TASK_CREATED = "task created";

static const std::string TEST_OUTPUT_RESOURCETYP_CHANGED = "resourcetyp changed";
static const std::string TEST_OUTPUT_RESOURC_CHANGEDD = "resource changed";
static const std::string TEST_OUTPUT_PROJECT_CHANGED = "project changed";
static const std::string TEST_OUTPUT_TASK_CHANGED = "task changed";

static const std::string TEST_OUTPUT_RESOURCE_ADDED_TO_TASK = "resource add to task!";

static const std::string TEST_OUTPUT_EMPTY_STRING = ""; 

static const std::string TEST_OUTPUT_WELCOME = 
"Welcome to the ultimate resourcemanager!\n (c)2005\n>";
static const std::string TEST_OUTPUT_COMMANDS_AVAILABLE = 
"available commands:\n view ...\n edit ...\n select ...\n delete ...\n ...\n>";

static const std::string TEST_OUTPUT_CURRENT_IN_ROOT = "/";
static const std::string TEST_OUTPUT_CURRENT_IN_PROJECT =  "/" + TEST_COMMAND_A_PROJECT_NAME;
static const std::string TEST_OUTPUT_CURRENT_IN_TASK = "/" + TEST_COMMAND_A_PROJECT_NAME + "/" + TEST_COMMAND_A_TASK_NAME;

static const std::string TEST_OUTPUT_STANDARD_TASK_VIEW = 
"name: " + TEST_COMMAND_A_TASK_NAME +"\n"+ 
"description: " + TEST_COMMAND_A_DESCRIPTION +"\n"+
"from: " + TEST_COMMAND_ANYTIME + 
"to: " + TEST_COMMAND_ANYTIME2; 

static const std::string TEST_OUTPUT_STANDARD_RESOURCE_VIEW = 
"resourcetyp: " + TEST_COMMAND_A_RESOURCETYP_NAME +"\n"+ 
"name: " + TEST_COMMAND_A_RESOURCE_NAME +"\n"+ 
"description: " + TEST_COMMAND_A_DESCRIPTION +"\n"+
"from: " + TEST_COMMAND_ANYTIME + 
"to: " + TEST_COMMAND_ANYTIME2 +
"usage: " + TEST_COMMAND_A_USAGE; 

static const std::string TEST_OUTPUT_DEFAULT_PROJECT_VIEW = 
"name: " + TEST_COMMAND_A_PROJECT_NAME +"\n"+ 
"description: n/a \n"+
"from: n/a " + 
"to: n/a \n" +
"tasks: no tasks"; 

static const std::string TEST_OUTPUT_GOODBYE =
"see you later, bye!";


void testDynamicProperty();
void testResourceType();
void testResource();
void testTask();
void testProject();
void testXmlIO();
void testDatabase();
void testControlUnit();
void testCollisionDetector();
void testCommands();
void testShell();
void testMain();

#endif TESTS_H_
