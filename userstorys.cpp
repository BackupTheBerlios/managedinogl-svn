#include "userstorys.h"
#include <vector>
#include <assert.h>
#include "datatypes.h"
#include "database.h"
#include "system.h"
#include "io.h"

#include "tests.h"

//--------------------------------------------------------------------------------------------
///
/// @param shell this shell is being used to apply commands to.
/// addStandardProject adds a standard project
void addStandardProject(TestShell shell)
{
	shell.startShell();
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
///
/// @param shell this shell is being used to apply commands to.
/// addTaskStandardProject adds a standard project and gives adds a task to it.
void addTaskToStandardProject(TestShell shell)
{
	shell.setCommand(TEST_COMMAND_VIEW_PROJECT);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_PROJECTNAME);
	shell.setCommand(TEST_COMMAND_CREATE_TASK);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_TASKNAME);
	shell.setCommand(TEST_COMMAND_A_TASK_NAME);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_DESCRIPTION);
	shell.setCommand(TEST_COMMAND_A_DESCRIPTION);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_STARTTIME);
	shell.setCommand(TEST_COMMAND_ANYTIME);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_ENDTIME);
	shell.setCommand(TEST_COMMAND_ANYTIME2);
	assert(shell.getPromptString() == TEST_OUTPUT_TASK_CREATED);
}

//--------------------------------------------------------------------------------------------
///
/// @param shell this shell is being used to apply commands to.
/// addResourceTyp adds a new resource.
void addResourceTyp(TestShell shell)
{
	shell.setCommand(TEST_COMMAND_CREATE_RESOURCETYP);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_RESOURCETYPENAME);
	shell.setCommand(TEST_COMMAND_A_RESOURCETYP_NAME);
	assert(shell.getPromptString() == TEST_OUTPUT_RESOURCETYP_CREATED);
}

//--------------------------------------------------------------------------------------------
///
/// @param shell this shell is being used to apply commands to.
/// addResourceToStandardTask creates a resource and add it to the standard task.
void addResourceToStandardTask(TestShell shell)
{
	shell.setCommand(TEST_COMMAND_CREATE_RESOURCE);
	shell.setCommand(TEST_COMMAND_A_RESOURCETYP_NAME);
	shell.setCommand(TEST_COMMAND_A_RESOURCE_NAME);
	shell.setCommand(TEST_COMMAND_A_DESCRIPTION);
	shell.setCommand(TEST_COMMAND_ANYTIME);
	shell.setCommand(TEST_COMMAND_ANYTIME2);
	shell.setCommand(TEST_COMMAND_A_USAGE);
	assert(shell.getPromptString() == TEST_OUTPUT_RESOURC_CREATED);
	
	shell.setCommand(TEST_COMMAND_VIEW_PROJECT);
	shell.setCommand(TEST_COMMAND_A_PROJECT_NAME);

	shell.setCommand(TEST_COMMAND_VIEW_TASK);
	shell.setCommand(TEST_COMMAND_A_TASK_NAME);
	shell.setCommand(TEST_COMMAND_ADD_RESOURCE_TO_TASK);
	shell.setCommand(TEST_COMMAND_A_RESOURCETYP_NAME);
	shell.setCommand(TEST_COMMAND_A_RESOURCE_NAME);
	assert(shell.getPromptString() == TEST_OUTPUT_RESOURCE_ADDED_TO_TASK);

}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich will kein Gui, sondern nur die Eingabe �ber Kommandozeilen.
/// Ich starte das Programm und m�chte freundlich begr��t werden.
/// Es soll eine Liste mit verf�gbaren Befehlen geben, welche z.b 
/// mit help aufgerufen werden kann. Ich will mit einfachen Befehlen 
/// arbeiten, diese sollen ein bestimmtes, intuitives Schema haben.
void testUserStory1()
{
	TestShell shell;
	ControlUnit control_unit;
	CommandFactory command_factory(&shell, &control_unit);
	CommandHandler command_handler(&command_factory);

	shell.startShell();
	assert(shell.getPromptString() == TEST_OUTPUT_WELCOME);
	shell.setCommand(TEST_COMMAND_HELP);
	assert(shell.getPromptString() == TEST_OUTPUT_COMMANDS_AVAILABLE);

}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich will ich ein neues Projekt erstellen k�nnen. Es soll mir 
/// nicht m�glich sein, ein zweites Projekt mit dem gleichen Namen 
/// zu erstellen.
void testUserStory2()
{
	ControlUnit controler;
	assert(controler.selectNone());
	assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_1,TEST_TIME_3));
	assert(controler.addProject(TEST_STRING_1,"",TEST_TIME_2,TEST_TIME_6) == false);

}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich will meinem Projekt eine zeitliche Begrenzung hinzuf�gen 
/// k�nnen, aber dies nicht m�ssen. Auch k�nnte sein, da� ich 
/// gerne nur eine Startzeit setze und noch gar keine Endzeit 
/// angebe. Das ist kein Fehler!. Das selbe gilt nat�rlich auch 
/// f�r die Endzeit in Bezug auf die Startzeit.
void testUserStory3()
{
	{
		TestShell shell;
		ControlUnit control_unit;
		CommandFactory command_factory(&shell, &control_unit);
		CommandHandler command_handler(&command_factory);

		addStandardProject(shell);
	}
	{
		TestShell shell;
		ControlUnit control_unit;
		CommandFactory command_factory(&shell, &control_unit);
		CommandHandler command_handler(&command_factory);

		shell.startShell();
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
		shell.setCommand(TEST_COMMAND_EMPTY_STRING);
		assert(shell.getPromptString() == TEST_OUTPUT_PROJECT_CREATED);
	}
	{
		TestShell shell;
		ControlUnit control_unit;
		CommandFactory command_factory(&shell, &control_unit);
		CommandHandler command_handler(&command_factory);

		shell.startShell();
		shell.setCommand(TEST_COMMAND_CREATE);
		assert(shell.getPromptString() == TEST_OUTPUT_ENTER_OBJECT);
		shell.setCommand(TEST_COMMAND_PROJECT);
		assert(shell.getPromptString() == TEST_OUTPUT_CREATE_PROJECT);
		shell.setCommand(TEST_COMMAND_A_PROJECT_NAME);
		assert(shell.getPromptString() == TEST_OUTPUT_ENTER_DESCRIPTION);
		shell.setCommand(TEST_COMMAND_A_DESCRIPTION);
		assert(shell.getPromptString() == TEST_OUTPUT_ENTER_STARTTIME);
		shell.setCommand(TEST_COMMAND_EMPTY_STRING);
		assert(shell.getPromptString() == TEST_OUTPUT_ENTER_ENDTIME);
		shell.setCommand(TEST_COMMAND_ANYTIME);
		assert(shell.getPromptString() == TEST_OUTPUT_PROJECT_CREATED);
	}


}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich m�chte die Eigenschaften meiner Projekte im nachhinein 
/// ver�ndern k�nnen. Dazu sollte ich das Projekt ausw�hlen und
/// die Eigenschaften austauschen.!
void testUserStory4()
{
	TestShell shell;
	ControlUnit control_unit;
	CommandFactory command_factory(&shell, &control_unit);
	CommandHandler command_handler(&command_factory);

	shell.startShell();
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

	shell.setCommand(TEST_COMMAND_EDIT_PROJECT);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_PROJECTNAME);
	shell.setCommand(TEST_COMMAND_A_PROJECT_NAME);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_PROPERTY);
	shell.setCommand(TEST_COMMAND_EDIT_DESCRIPTION);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_DESCRIPTION);
	shell.setCommand(TEST_COMMAND_A_DESCRIPTION);
	assert(shell.getPromptString() == TEST_OUTPUT_PROJECT_CHANGED);


}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich m�chte ein System haben, da� mich in meiner T�tigkeit 
/// unterst�tzt. Sollte ich nicht alle Parameter f�r eine Funktion 
/// angegeben haben � so fragt mich das System, was mit den anderen
/// Eingaben ist und fragt diese einzeln ab.
void testUserStory5()
{
	{
		TestShell shell;
		ControlUnit control_unit;
		CommandFactory command_factory(&shell, &control_unit);
		CommandHandler command_handler(&command_factory);

		shell.startShell();
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
	{
		TestShell shell;
		ControlUnit control_unit;
		CommandFactory command_factory(&shell, &control_unit);
		CommandHandler command_handler(&command_factory);

		shell.startShell();
		shell.setCommand(TEST_COMMAND_CREATE_PROJECT);
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

}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich m�chte erst innerhalb eines Projekts die M�glichkeit bekommen 
/// einen Task hinzuzuf�gen. Ist ein Task hinzugef�gt und ausgew�hlt 
/// kann ich ihm dort eine Ressource zuordnen.
void testUserStory6()
{
	TestShell shell;
	ControlUnit control_unit;
	CommandFactory command_factory(&shell, &control_unit);
	CommandHandler command_handler(&command_factory);

	addStandardProject(shell);

	shell.setCommand(TEST_COMMAND_CREATE_TASK);
	assert(shell.getPromptString() == TEST_OUTPUT_ERROR_NO_PROJECT_SELECTED);
	
	addTaskToStandardProject(shell);

	shell.setCommand(TEST_COMMAND_VIEW_TASK);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_TASKNAME);
	shell.setCommand(TEST_COMMAND_A_TASK_NAME);
	assert(shell.getPromptString() == TEST_OUTPUT_EMPTY_STRING);

	shell.setCommand(TEST_COMMAND_ADD_RESOURCE_TO_TASK);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_RESOURCETYPE);
	shell.setCommand(TEST_COMMAND_A_RESOURCETYP_NAME);
	assert(shell.getPromptString() == TEST_OUTPUT_RESOURCE_ADDED_TO_TASK);

}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich m�chte die Eigenschaften meiner Tasks im nachhinein ver�ndern 
/// k�nnen. Dazu sollte ich das Tasks ausw�hlen und die Eigenschaften 
/// austauschen. Sollte ich versuchen die Eigenschaften eines Tasks zu 
/// �ndern, obwohl ich es nicht ausgew�hlt habe, so ist das falsch!
void testUserStory7()
{
	TestShell shell;
	ControlUnit control_unit;
	CommandFactory command_factory(&shell, &control_unit);
	CommandHandler command_handler(&command_factory);

	addStandardProject(shell);
	addTaskToStandardProject(shell);

	shell.setCommand(TEST_COMMAND_VIEW_TASK);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_TASKNAME);
	shell.setCommand(TEST_COMMAND_A_TASK_NAME);
	assert(shell.getPromptString() == TEST_OUTPUT_EMPTY_STRING);
	

	shell.setCommand(TEST_COMMAND_EDIT_TASK);
	shell.setCommand(TEST_COMMAND_A_TASK_NAME);
	shell.setCommand(TEST_COMMAND_EDIT_DESCRIPTION);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_DESCRIPTION);
	shell.setCommand(TEST_COMMAND_A_DESCRIPTION);
	assert(shell.getPromptString() == TEST_OUTPUT_TASK_CHANGED);

	shell.setCommand(TEST_COMMAND_VIEW_TASK);
	shell.setCommand(TEST_COMMAND_A_TASK_NAME);
	assert(shell.getPromptString() == TEST_OUTPUT_TASK_CHANGED);

}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich m�chte, da� wenn ich einen Task l�sche, da� alle Ressourcen, 
/// die dieser Task in Beschlag genommen wurden wieder freigegeben werden.
void testUserStory8()
{
	TestShell shell;
	ControlUnit control_unit;
	CommandFactory command_factory(&shell, &control_unit);
	CommandHandler command_handler(&command_factory);

	addStandardProject(shell);
	addTaskToStandardProject(shell);
	addResourceTyp(shell);
	addResourceToStandardTask(shell);

	shell.setCommand(TEST_COMMAND_DELETE_TASK);
	shell.setCommand(TEST_COMMAND_VIEW_RESOURCE);
	shell.setCommand(TEST_COMMAND_A_RESOURCETYP_NAME);
	shell.setCommand(TEST_COMMAND_A_RESOURCE_NAME);
	
	assert(shell.getPromptString() == TEST_OUTPUT_STANDARD_RESOURCE_VIEW);
}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich brauche Personen nicht extra zu behandeln. Personen sind f�r 
/// mich Ressourcen und so werden sie auch behandelt. Es macht also 
/// keinen Unterschied, ob ich nun eine Person einem Task hinzuf�ge 
/// oder irgend eine andere Ressource. Abfragen nach Personen erfolgen 
/// also auch �ber Ressourcen-Abfragen � f�r eine genauere 
/// Spezifizierung m�chte ich einen Ressourcen-Typ haben.
void testUserStory9()
{
	TestShell shell;
	ControlUnit control_unit;
	CommandFactory command_factory(&shell, &control_unit);
	CommandHandler command_handler(&command_factory);

	addStandardProject(shell);
	addTaskToStandardProject(shell);
	addResourceTyp(shell);
	addResourceToStandardTask(shell);

	shell.setCommand(TEST_COMMAND_VIEW_RESOURCE);
	shell.setCommand(TEST_COMMAND_A_RESOURCETYP_NAME);
	shell.setCommand(TEST_COMMAND_A_RESOURCE_NAME);
	
	assert(shell.getPromptString() == TEST_OUTPUT_STANDARD_RESOURCE_VIEW);

}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich m�chte eine Ressource jederzeit und �berall aus dem System 
/// l�schen k�nnen. Ist ein Task von einer Ressource abh�ngig so 
/// werde ich durch einen Ressourcen-Check darauf aufmerksam gemacht, 
/// da� ein Task eine Ressource enth�lt, die scheinbar nicht existiert.
void testUserStory10()
{
	TestShell shell;
	ControlUnit control_unit;
	CommandFactory command_factory(&shell, &control_unit);
	CommandHandler command_handler(&command_factory);

	addStandardProject(shell);
	addTaskToStandardProject(shell);
	addResourceTyp(shell);
	addResourceToStandardTask(shell);	

	shell.setCommand(TEST_COMMAND_DELETE_RESOURCE);
	shell.setCommand(TEST_COMMAND_A_RESOURCETYP_NAME);
	shell.setCommand(TEST_COMMAND_A_RESOURCE_NAME);
	shell.setCommand(TEST_COMMAND_YES);

	shell.setCommand(TEST_COMMAND_CHECK_RESOURCE_USEAGE);
	assert(shell.getPromptString() == TEST_OUTPUT_CRITICAL);


}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich m�chte die Eigenschaften meiner Ressourcen im nachhinein 
/// ver�ndern k�nnen. Dazu sollte ich die Ressource ausw�hlen und
/// die Eigenschaften ersetzen k�nnen. 
void testUserStory11()
{
	TestShell shell;
	ControlUnit control_unit;
	CommandFactory command_factory(&shell, &control_unit);
	CommandHandler command_handler(&command_factory);

	addStandardProject(shell);
	addTaskToStandardProject(shell);
	addResourceTyp(shell);
	addResourceToStandardTask(shell);


	shell.setCommand(TEST_COMMAND_EDIT_RESOURCE);
	shell.setCommand(TEST_COMMAND_A_RESOURCE_NAME);
	shell.setCommand(TEST_COMMAND_EDIT_DESCRIPTION);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_DESCRIPTION);
	shell.setCommand(TEST_COMMAND_A_DESCRIPTION);
	assert(shell.getPromptString() == TEST_OUTPUT_RESOURC_CHANGEDD);

	shell.setCommand(TEST_COMMAND_VIEW_RESOURCE);
	shell.setCommand(TEST_COMMAND_A_RESOURCE_NAME);
	assert(shell.getPromptString() == TEST_OUTPUT_STANDARD_RESOURCE_VIEW);
}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich m�chte meine Einstellungen speichern k�nnen und sie zu einem 
/// beliebigen anderen Zeitpunkt wieder aufrufen k�nnen.

void testUserStory12()
{
	{
		TestShell shell;
		ControlUnit control_unit;
		CommandFactory command_factory(&shell, &control_unit);
		CommandHandler command_handler(&command_factory);

		addStandardProject(shell);
		addTaskToStandardProject(shell);
		addResourceTyp(shell);
		addResourceToStandardTask(shell);
		shell.setCommand(TEST_COMMAND_SAVE);
	}

	{
		TestShell shell;
		ControlUnit control_unit;
		CommandFactory command_factory(&shell, &control_unit);
		CommandHandler command_handler(&command_factory);

		shell.setCommand(TEST_COMMAND_LOAD);
		shell.setCommand(TEST_COMMAND_VIEW_RESOURCE);
		shell.setCommand(TEST_COMMAND_A_RESOURCE_NAME);
		assert(shell.getPromptString() == TEST_OUTPUT_STANDARD_RESOURCE_VIEW);
	}
	
}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich will zeitliche Ungereimtheiten mit einem Befehl herausfinden 
/// k�nnen.
void testUserStory13()
{
	TestShell shell;
	ControlUnit control_unit;
	CommandFactory command_factory(&shell, &control_unit);
	CommandHandler command_handler(&command_factory);

	addStandardProject(shell);
	addTaskToStandardProject(shell);
	
	shell.setCommand(TEST_COMMAND_VIEW_PROJECT);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_PROJECTNAME);
	shell.setCommand(TEST_COMMAND_CREATE_TASK);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_TASKNAME);
	shell.setCommand(TEST_COMMAND_A_TASK_NAME2);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_DESCRIPTION);
	shell.setCommand(TEST_COMMAND_A_DESCRIPTION);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_STARTTIME);
	shell.setCommand(TEST_COMMAND_ANYTIME);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_ENDTIME);
	shell.setCommand(TEST_COMMAND_ANYTIME2);
	assert(shell.getPromptString() == TEST_OUTPUT_TASK_CREATED);


	shell.setCommand(TEST_COMMAND_CHECK_TIMECOLLISIONS);
	assert(shell.getPromptString() == TEST_OUTPUT_COLLISIONS);
}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich will Ungereimtheiten bei den Ressourcen mit einem Befehl 
/// herausfinden k�nnen.
void testUserStory14()
{
	TestShell shell;
	ControlUnit control_unit;
	CommandFactory command_factory(&shell, &control_unit);
	CommandHandler command_handler(&command_factory);

	addStandardProject(shell);
	addTaskToStandardProject(shell);
	addResourceTyp(shell);
	addResourceToStandardTask(shell);

	shell.setCommand(TEST_COMMAND_CREATE_RESOURCE);
	shell.setCommand(TEST_COMMAND_A_RESOURCETYP_NAME);
	shell.setCommand(TEST_COMMAND_A_RESOURCE_NAME2);
	shell.setCommand(TEST_COMMAND_A_DESCRIPTION);
	shell.setCommand(TEST_COMMAND_ANYTIME);
	shell.setCommand(TEST_COMMAND_ANYTIME2);
	shell.setCommand(TEST_COMMAND_A_USAGE2);
	assert(shell.getPromptString() == TEST_OUTPUT_RESOURC_CREATED);
	
	shell.setCommand(TEST_COMMAND_VIEW_PROJECT);
	shell.setCommand(TEST_COMMAND_A_PROJECT_NAME);

	shell.setCommand(TEST_COMMAND_VIEW_TASK);
	shell.setCommand(TEST_COMMAND_A_TASK_NAME);
	shell.setCommand(TEST_COMMAND_ADD_RESOURCE_TO_TASK);
	shell.setCommand(TEST_COMMAND_A_RESOURCETYP_NAME);
	shell.setCommand(TEST_COMMAND_A_RESOURCE_NAME);
	assert(shell.getPromptString() == TEST_OUTPUT_RESOURCE_ADDED_TO_TASK);

	shell.setCommand(TEST_COMMAND_CHECK_RESOURCE_USEAGE);
	assert(shell.getPromptString() == TEST_OUTPUT_COLLISIONS);
}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich m�chte, da� mir mein System nicht !nur! Vorschriften setzt: 
/// wenn ich will m�chte ich einen Task auch so ansetzen k�nne, da� 
/// er sich nicht im Projekt befindet und das soll nur durch eine 
/// Funktion erkannt werden � ich mag daf�r nicht st�ndig gewarnt 
/// werden.
void testUserStory15()
{
	TestShell shell;
	ControlUnit control_unit;
	CommandFactory command_factory(&shell, &control_unit);
	CommandHandler command_handler(&command_factory);

	addStandardProject(shell);

	shell.setCommand(TEST_COMMAND_CREATE_TASK);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_TASKNAME);
	shell.setCommand(TEST_COMMAND_A_TASK_NAME);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_DESCRIPTION);
	shell.setCommand(TEST_COMMAND_A_DESCRIPTION);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_STARTTIME);
	shell.setCommand(TEST_COMMAND_ANYTIME3);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_ENDTIME);
	shell.setCommand(TEST_COMMAND_ANYTIME4);
	assert(shell.getPromptString() == TEST_OUTPUT_TASK_CREATED);

	shell.setCommand(TEST_COMMAND_CHECK_TIMECOLLISIONS);
	assert(shell.getPromptString() == TEST_OUTPUT_COLLISIONS);



}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich will meinen Ressourcen eine maximale Verf�gbarkeit hinzuf�gen 
/// k�nnen. Dh. ich kann eine Ressource ev. Gleichzeitig in verschiedenen 
/// Tasks benutzen.
void testUserStory16()
{
	TestShell shell;
	ControlUnit control_unit;
	CommandFactory command_factory(&shell, &control_unit);
	CommandHandler command_handler(&command_factory);

	addStandardProject(shell);
	addTaskToStandardProject(shell);
	addResourceTyp(shell);

	shell.setCommand(TEST_COMMAND_VIEW_PROJECT);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_PROJECTNAME);
	shell.setCommand(TEST_COMMAND_CREATE_TASK);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_TASKNAME);
	shell.setCommand(TEST_COMMAND_A_TASK_NAME2);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_DESCRIPTION);
	shell.setCommand(TEST_COMMAND_A_DESCRIPTION);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_STARTTIME);
	shell.setCommand(TEST_COMMAND_ANYTIME);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_ENDTIME);
	shell.setCommand(TEST_COMMAND_ANYTIME2);
	assert(shell.getPromptString() == TEST_OUTPUT_TASK_CREATED);

	shell.setCommand(TEST_COMMAND_CREATE_RESOURCE);
	shell.setCommand(TEST_COMMAND_A_RESOURCETYP_NAME);
	shell.setCommand(TEST_COMMAND_A_RESOURCE_NAME);
	shell.setCommand(TEST_COMMAND_A_DESCRIPTION);
	shell.setCommand(TEST_COMMAND_ANYTIME);
	shell.setCommand(TEST_COMMAND_ANYTIME2);
	shell.setCommand(TEST_COMMAND_A_USAGE);
	assert(shell.getPromptString() == TEST_OUTPUT_RESOURC_CREATED);

	shell.setCommand(TEST_COMMAND_VIEW_TASK);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_TASKNAME);
	shell.setCommand(TEST_COMMAND_A_TASK_NAME);
	assert(shell.getPromptString() == TEST_OUTPUT_EMPTY_STRING);

	shell.setCommand(TEST_COMMAND_ADD_RESOURCE_TO_TASK);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_RESOURCETYPE);
	shell.setCommand(TEST_COMMAND_A_RESOURCETYP_NAME);
	assert(shell.getPromptString() == TEST_OUTPUT_RESOURCE_ADDED_TO_TASK);

	shell.setCommand(TEST_COMMAND_VIEW_TASK);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_TASKNAME);
	shell.setCommand(TEST_COMMAND_A_TASK_NAME2);
	assert(shell.getPromptString() == TEST_OUTPUT_EMPTY_STRING);

	shell.setCommand(TEST_COMMAND_ADD_RESOURCE_TO_TASK);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_RESOURCETYPE);
	shell.setCommand(TEST_COMMAND_A_RESOURCETYP_NAME);
	assert(shell.getPromptString() == TEST_OUTPUT_RESOURCE_ADDED_TO_TASK);

}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich m�chte f�r Werte, die ich in meinen Projekten nicht eingetragen 
/// habe anst�ndige Default-Werte bekommen.
void testUserStory17()
{
	TestShell shell;
	ControlUnit control_unit;
	CommandFactory command_factory(&shell, &control_unit);
	CommandHandler command_handler(&command_factory);

	shell.startShell();
	shell.setCommand(TEST_COMMAND_CREATE);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_OBJECT);
	shell.setCommand(TEST_COMMAND_PROJECT);
	assert(shell.getPromptString() == TEST_OUTPUT_CREATE_PROJECT);
	shell.setCommand(TEST_COMMAND_A_PROJECT_NAME);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_DESCRIPTION);
	shell.setCommand(TEST_COMMAND_EMPTY_STRING);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_STARTTIME);
	shell.setCommand(TEST_COMMAND_EMPTY_STRING);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_ENDTIME);
	shell.setCommand(TEST_COMMAND_EMPTY_STRING);
	assert(shell.getPromptString() == TEST_OUTPUT_PROJECT_CREATED);

	shell.setCommand(TEST_COMMAND_VIEW_PROJECT);
	shell.setCommand(TEST_COMMAND_A_PROJECT_NAME);
	assert(shell.getPromptString() == TEST_OUTPUT_DEFAULT_PROJECT_VIEW);

}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich will, da� ein Projekt l�schbar ist und wenn dies geschieht, 
/// ich gefragt werde, ob auch die entsprechenden Tasks gel�scht 
/// werden sollen.
void testUserStory18()
{
	TestShell shell;
	ControlUnit control_unit;
	CommandFactory command_factory(&shell, &control_unit);
	CommandHandler command_handler(&command_factory);

	addStandardProject(shell);
	addTaskToStandardProject(shell);

	shell.setCommand(TEST_COMMAND_DELETE_PROJECT);
	shell.setCommand(TEST_COMMAND_A_PROJECT_NAME);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_SURE);
	shell.setCommand(TEST_COMMAND_YES);
	assert(shell.getPromptString() == TEST_OUTPUT_ENTER_SURE_DELETING_TASKS);
	shell.setCommand(TEST_COMMAND_YES);

}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Wenn mich das System nach einer weiteren Eingabe fragt, die sich 
/// auf bestehende Ressourcen bezieht, m�chte ich die M�glichkeit haben 
/// die bestehenden Ressourcen einzusehen um diese leichter ausw�hlen zu
/// k�nnen.
void testUserStory19()
{
	TestShell shell;
	ControlUnit control_unit;
	CommandFactory command_factory(&shell, &control_unit);
	CommandHandler command_handler(&command_factory);

	addStandardProject(shell);
	addTaskToStandardProject(shell);
	addResourceTyp(shell);

	shell.setCommand(TEST_COMMAND_CREATE_RESOURCE);
	shell.setCommand(TEST_COMMAND_A_RESOURCETYP_NAME);
	
	shell.setCommand(TEST_COMMAND_VIEW_RESOURCE);
	shell.setCommand(TEST_COMMAND_A_RESOURCETYP_NAME);
	shell.setCommand(TEST_COMMAND_A_RESOURCE_NAME);
	assert(shell.getPromptString() == TEST_OUTPUT_STANDARD_RESOURCE_VIEW);

	shell.setCommand(TEST_COMMAND_A_RESOURCE_NAME);
	shell.setCommand(TEST_COMMAND_A_DESCRIPTION);
	shell.setCommand(TEST_COMMAND_ANYTIME);
	shell.setCommand(TEST_COMMAND_ANYTIME2);
	shell.setCommand(TEST_COMMAND_A_USAGE);
	assert(shell.getPromptString() == TEST_OUTPUT_RESOURC_CREATED);

}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich m�chte angenehm verabschiedet werden, wenn ich das System mit 
/// einem entsprechendem Befehl verlasse.
void testUserStory20()
{
	TestShell shell;
	ControlUnit control_unit;
	CommandFactory command_factory(&shell, &control_unit);
	CommandHandler command_handler(&command_factory);

	shell.startShell();
	shell.setCommand(TEST_COMMAND_QUIT);
	assert(shell.getPromptString() == TEST_OUTPUT_GOODBYE);
}

//--------------------------------------------------------------------------------------------
///
/// from user story:
/// Ich m�chte anhand der Shell genau wissen, an welcher Stelle des Systems 
/// ich mich wirklich befinde.
void testUserStory21()
{
	TestShell shell;
	ControlUnit control_unit;
	CommandFactory command_factory(&shell, &control_unit);
	CommandHandler command_handler(&command_factory);

	shell.setCommand(TEST_COMMAND_SHOW_CURRENT);
	assert(shell.getPromptString() == TEST_OUTPUT_CURRENT_IN_ROOT);

	addStandardProject(shell);
	shell.setCommand(TEST_COMMAND_VIEW_PROJECT);
	shell.setCommand(TEST_COMMAND_A_PROJECT_NAME);
	shell.setCommand(TEST_COMMAND_SHOW_CURRENT);
	assert(shell.getPromptString() == TEST_OUTPUT_CURRENT_IN_PROJECT);

	addTaskToStandardProject(shell);
	shell.setCommand(TEST_COMMAND_VIEW_TASK);
	shell.setCommand(TEST_COMMAND_A_TASK_NAME);
	shell.setCommand(TEST_COMMAND_SHOW_CURRENT);
	assert(shell.getPromptString() == TEST_OUTPUT_CURRENT_IN_TASK);

}
