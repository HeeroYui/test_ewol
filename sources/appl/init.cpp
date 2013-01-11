/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#include <etk/types.h>
#include <etk/UString.h>
#include <etk/os/FSNode.h>
#include <ewol/ewol.h>
#include <ewol/config.h>
#include <ewol/commandLine.h>
#include <ewol/eObject/EObject.h>
#include <ewol/widget/WidgetManager.h>

#include <appl/Debug.h>
#include <appl/MainWindows.h>

MainWindows * basicWindows = NULL;


/**
 * @brief Main of the program (This can be set in every case, but it is not used in Andoid...).
 * @param std IO
 * @return std IO
 */
int main(int argc, const char *argv[])
{
	// only one things to do : 
	return ewol::Run(argc, argv);
}


/**
 * @brief main application function Initialisation
 */
void APP_Init(void)
{
	#ifdef MODE_RELEASE
		char * debugMode = "Release";
	#else
		char * debugMode = "Debug";
	#endif
	#ifdef __TARGET_OS__Linux
		char * osMode = "Linux";
	#elif defined(__TARGET_OS__Android)
		char * osMode = "Android";
	#elif defined(__TARGET_OS__Windows)
		char * osMode = "Windows";
	#elif defined(__TARGET_OS__IOs)
		char * osMode = "IOs";
	#elif defined(__TARGET_OS__MacOs)
		char * osMode = "MacOs";
	#else
		char * osMode = "Unknown";
	#endif
	APPL_INFO("==> Init "PROJECT_NAME" (START) [" << osMode << "] (" << debugMode << ")");
	
	etk::InitDefaultFolder(PROJECT_NAME);
	ewol::ChangeSize(ivec2(800, 300));
	#ifdef __TARGET_OS__Android
		ewol::config::FontSetDefault("FreeSerif", 19);
	#else
		ewol::config::FontSetDefault("FreeSerif", 14);
	#endif
	// set the application icon ...
	ewol::SetIcon("DATA:icon.png");
	
	basicWindows = new MainWindows();
	
	if (NULL == basicWindows) {
		APPL_ERROR("Can not allocate the basic windows");
		ewol::Stop();
		return;
	}
	// create the specific windows
	ewol::WindowsSet(basicWindows);
	
	
	// add files
	APPL_INFO("show list of command line input : ");
	for( int32_t iii=0 ; iii<ewol::commandLine::Size(); iii++) {
		APPL_INFO("parameter [" << iii << "] is \"" << ewol::commandLine::Get(iii) << "\"");
	}
	
	APPL_INFO("==> Init "PROJECT_NAME" (END)");
}




/**
 * @brief main application function Un-Initialisation
 */
void APP_UnInit(void)
{
	APPL_INFO("==> Un-Init "PROJECT_NAME" (START)");
	// Remove windows :
	ewol::WindowsSet(NULL);
	
	if (NULL != basicWindows) {
		delete(basicWindows);
		basicWindows = NULL;
	}
	APPL_INFO("==> Un-Init "PROJECT_NAME" (END)");
}

