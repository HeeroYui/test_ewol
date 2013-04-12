/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */


#include <appl/Debug.h>
#include <appl/TestButton.h>

#include <ewol/widget/Button.h>
#include <ewol/widget/CheckBox.h>
#include <ewol/widget/Sizer.h>
#include <ewol/widget/Label.h>
#include <ewol/widget/Entry.h>
#include <ewol/widget/List.h>
#include <ewol/widget/ContextMenu.h>
#include <ewol/widget/PopUp.h>
#include <ewol/widget/Slider.h>
#include <ewol/widget/Composer.h>
#include <ewol/widget/Menu.h>
#include <ewol/widget/meta/FileChooser.h>
#include <ewol/widget/meta/Parameter.h>
#include <ewol/widget/WidgetManager.h>


static const char * l_eventChangeExpendX     = "event-change-expend-X";
static const char * l_eventChangeExpendY     = "event-change-expend-Y";
static const char * l_eventChangeFillX       = "event-change-fill-X";
static const char * l_eventChangeFillY       = "event-change-fill-Y";
static const char * l_eventChangeToggle      = "event-change-toggle-mode";
static const char * l_eventChangeText        = "event-change-text";
static const char * l_eventChangeTextToggle  = "event-change-text-toggle";
static const char * l_eventChangeImage       = "event-change-image";
static const char * l_eventChangeImageToggle = "event-change-image-toggle";

#undef __class__
#define __class__	"TestButton"

TestButton::TestButton(void) : 
	widget::Sizer(widget::Sizer::modeVert),
	m_testWidget(NULL)
{
	APPL_CRITICAL("Create "__class__" (start)");
	widget::Sizer* mySizerVert2 = NULL;
	widget::Sizer* mySizerHori = NULL;
	widget::Button*    myButton = NULL;
	
	mySizerHori = new widget::Sizer(widget::Sizer::modeHori);
	if (NULL == mySizerHori) {
		APPL_DEBUG("Allocation error mySizerHori");
		return;
	}
	SubWidgetAdd(mySizerHori);
		myButton = new widget::Button();
		if (NULL != myButton) {
			myButton->SetToggleMode(true);
			myButton->SetSubWidget(      new widget::Label("Expend X <br/> (false)"));
			myButton->SetSubWidgetToggle(new widget::Label("Expend X <br/><b>(true)</b>"));
			myButton->RegisterOnEvent(this, ewolEventButtonValue, l_eventChangeExpendX);
			mySizerHori->SubWidgetAdd(myButton);
		}
		myButton = new widget::Button();
		if (NULL != myButton) {
			myButton->SetToggleMode(true);
			myButton->SetSubWidget(      new widget::Label("Expend Y <br/> (false)"));
			myButton->SetSubWidgetToggle(new widget::Label("Expend Y <br/><b>(true)</b>"));
			myButton->RegisterOnEvent(this, ewolEventButtonValue, l_eventChangeExpendY);
			mySizerHori->SubWidgetAdd(myButton);
		}
		myButton = new widget::Button();
		if (NULL != myButton) {
			myButton->SetToggleMode(true);
			myButton->SetSubWidget(      new widget::Label("Toggle<br/>(false)"));
			myButton->SetSubWidgetToggle(new widget::Label("Toggle<br/><b>(true)</b>"));
			myButton->RegisterOnEvent(this, ewolEventButtonValue, l_eventChangeToggle);
			mySizerHori->SubWidgetAdd(myButton);
		}
		myButton = new widget::Button();
		if (NULL != myButton) {
			myButton->SetToggleMode(true);
			myButton->SetSubWidget(      new widget::Label("Text On toggle state<br/>(false)"));
			myButton->SetSubWidgetToggle(new widget::Label("Text On toggle state<br/><b>(true)</b>"));
			myButton->RegisterOnEvent(this, ewolEventButtonValue, l_eventChangeTextToggle);
			mySizerHori->SubWidgetAdd(myButton);
		}
	
	mySizerHori = new widget::Sizer(widget::Sizer::modeHori);
	if (NULL == mySizerHori) {
		APPL_DEBUG("Allocation error mySizerHori");
		return;
	}
	SubWidgetAdd(mySizerHori);
		
		myButton = new widget::Button();
		if (NULL != myButton) {
			myButton->SetToggleMode(true);
			myButton->SetSubWidget(      new widget::Label("Fill X <br/> (false)"));
			myButton->SetSubWidgetToggle(new widget::Label("Fill X <br/> (true)"));
			myButton->RegisterOnEvent(this, ewolEventButtonValue, l_eventChangeFillX);
			mySizerHori->SubWidgetAdd(myButton);
		}
		myButton = new widget::Button();
		if (NULL != myButton) {
			myButton->SetToggleMode(true);
			myButton->SetSubWidget(      new widget::Label("Fill Y <br/> (false)"));
			myButton->SetSubWidgetToggle(new widget::Label("Fill Y <br/> (true)"));
			myButton->RegisterOnEvent(this, ewolEventButtonValue, l_eventChangeFillY);
			mySizerHori->SubWidgetAdd(myButton);
		}
		myButton = new widget::Button();
		if (NULL != myButton) {
			myButton->SetSubWidget(new widget::Label("Change Text<br/> and other ..."));
			myButton->RegisterOnEvent(this, ewolEventButtonPressed, l_eventChangeText);
			mySizerHori->SubWidgetAdd(myButton);
		}
	widget::Spacer* mySpacer = new widget::Spacer();
	if (NULL != mySpacer) {
		mySpacer->SetExpand(bvec2(false,false));
		mySpacer->SetFill(bvec2(true,false));
		mySpacer->SetSize(10);
		mySpacer->SetColor(0xFF000080);
		SubWidgetAdd(mySpacer);
	}
	
	mySizerHori = new widget::Sizer(widget::Sizer::modeHori);
	if (NULL == mySizerHori) {
		APPL_DEBUG("Allocation error mySizerHori");
		return;
	}
	SubWidgetAdd(mySizerHori);
	
		mySpacer = new widget::Spacer();
		if (NULL != mySpacer) {
			mySpacer->SetExpand(bvec2(false,false));
			mySpacer->SetFill(bvec2(false,true));
			mySpacer->SetSize(10);
			mySpacer->SetColor(0x00FF0080);
			mySizerHori->SubWidgetAdd(mySpacer);
		}
		
		m_testWidget = new widget::Button();
		if (NULL != m_testWidget) {
			m_testWidget->SetSubWidget(new widget::Label("My <font color=\"#FF0000\">Button</font> <br/> And Some under line<br/> plop <br/> and an other super long line ..."));
			m_testWidget->SetExpand(bvec2(false,false));
			m_testWidget->SetFill(bvec2(false,false));
			m_testWidget->RegisterOnEvent(this, ewolEventButtonPressed);
			m_testWidget->RegisterOnEvent(this, ewolEventButtonDown);
			m_testWidget->RegisterOnEvent(this, ewolEventButtonUp);
			m_testWidget->RegisterOnEvent(this, ewolEventButtonEnter);
			m_testWidget->RegisterOnEvent(this, ewolEventButtonLeave);
			m_testWidget->RegisterOnEvent(this, ewolEventButtonValue);
			mySizerHori->SubWidgetAdd(m_testWidget);
		}
		
		mySpacer = new widget::Spacer();
		if (NULL != mySpacer) {
			mySpacer->SetExpand(bvec2(false,false));
			mySpacer->SetFill(bvec2(false,true));
			mySpacer->SetSize(10);
			mySpacer->SetColor(0x0000FF80);
			mySizerHori->SubWidgetAdd(mySpacer);
		}
		
	mySpacer = new widget::Spacer();
	if (NULL != mySpacer) {
		mySpacer->SetExpand(bvec2(false,false));
		mySpacer->SetFill(bvec2(true,false));
		mySpacer->SetSize(10);
		mySpacer->SetColor(0x00FFFF80);
		SubWidgetAdd(mySpacer);
	}
	APPL_CRITICAL("Create "__class__" (end)");
}


TestButton::~TestButton(void)
{
	APPL_CRITICAL("Remove "__class__" ...");
}


void TestButton::OnReceiveMessage(ewol::EObject * CallerObject, const char * eventId, const etk::UString& data)
{
	widget::Sizer::OnReceiveMessage(CallerObject, eventId, data);
	
	//APPL_INFO("Receive Event from the main windows ... : \"" << eventId << "\" ==> data=\"" << data << "\"" );
	if (m_testWidget == CallerObject) {
		APPL_WARNING("Receive Event from tested Button ... : \"" << eventId << "\" ==> data=\"" << data << "\"" );
	}
	if (eventId == l_eventChangeExpendX) {
		if (NULL!=m_testWidget) {
			if (data=="1") {
				m_testWidget->SetExpand(bvec2(true,m_testWidget->GetExpand().y()));
			} else {
				m_testWidget->SetExpand(bvec2(false,m_testWidget->GetExpand().y()));
			}
		}
	} else if (eventId == l_eventChangeExpendY) {
		if (NULL!=m_testWidget) {
			if (data=="1") {
				m_testWidget->SetExpand(bvec2(m_testWidget->GetExpand().x(),true));
			} else {
				m_testWidget->SetExpand(bvec2(m_testWidget->GetExpand().x(),false));
			}
		}
	} else if (eventId == l_eventChangeFillX) {
		if (NULL!=m_testWidget) {
			if (data=="1") {
				m_testWidget->SetFill(bvec2(true,m_testWidget->GetFill().y()));
			} else {
				m_testWidget->SetFill(bvec2(false,m_testWidget->GetFill().y()));
			}
		}
	} else if (eventId == l_eventChangeFillY) {
		if (NULL!=m_testWidget) {
			if (data=="1") {
				m_testWidget->SetFill(bvec2(m_testWidget->GetFill().x(),true));
			} else {
				m_testWidget->SetFill(bvec2(m_testWidget->GetFill().x(),false));
			}
		}
	} else if (eventId == l_eventChangeToggle) {
		if (NULL!=m_testWidget) {
			if (data=="1") {
				m_testWidget->SetToggleMode(true);
			} else {
				m_testWidget->SetToggleMode(false);
			}
		}
	} else if (eventId == l_eventChangeTextToggle) {
		if (NULL!=m_testWidget) {
			if (data=="1") {
				m_testWidget->SetSubWidgetToggle(new widget::Label("A stupid very long text on toggle <br/><br/> and on multiple lines"));
			} else {
				m_testWidget->SetSubWidgetToggle(NULL);
			}
		}
	} else if (eventId == l_eventChangeImage) {
		if (NULL!=m_testWidget) {
			if (data=="1") {
				//m_testWidget->SetImage("THEME:GUI:icon.png");
				//m_testWidget->SetImageSize(50);
			} else {
				//m_testWidget->SetImage("");
			}
		}
	} else if (eventId == l_eventChangeImageToggle) {
		if (NULL!=m_testWidget) {
			if (data=="1") {
				//m_testWidget->SetImageToggle("THEME:GUI:icon.png");
			} else {
				//m_testWidget->SetImageToggle("");
			}
		}
	} else if (eventId == l_eventChangeText) {
		if (NULL!=m_testWidget) {
			static int32_t countTextID = 1;
			switch (countTextID)
			{
				case 0:
					m_testWidget->SetSubWidget(new widget::Label("simple Text"));
					break;
				case 1:
					m_testWidget->SetSubWidget(new widget::Label("<left>Align Left</left>"));
					break;
				case 2:
					m_testWidget->SetSubWidget(new widget::Label("<right>Align right</right>"));
					break;
				case 3:
					m_testWidget->SetSubWidget(new widget::Label("<center>Align center</center>"));
					break;
				case 4:
					m_testWidget->SetSubWidget(new widget::Label("simple Text<br/> With Some Other Lines<br/> and more if you want ...<br/> plop"));
					break;
				case 5:
					m_testWidget->SetSubWidget(new widget::Label("simple <bold>Text</bold> with bold"));
					break;
				case 6:
					m_testWidget->SetSubWidget(new widget::Label("simple <italic>Text</italic> with italic"));
					break;
				case 7:
					m_testWidget->SetSubWidget(new widget::Label("simple <italic><bold>Text</bold></italic> with italic bold"));
					break;
				case 8:
					m_testWidget->SetSubWidget(NULL);
					break;
				case 9:
					m_testWidget->SetSubWidget(new widget::Label("simple <font color=\"#FFFF0088\">Text</font> with colored text"));
					break;
				case 10:
					m_testWidget->SetSubWidget(
					    new widget::Composer(widget::Composer::String,
					        "<composer>\n"
					        "	<label>ploppp</label>\n"
					        "</composer\n"));
					break;
				case 11:
					m_testWidget->SetSubWidget(
					    new widget::Composer(widget::Composer::String,
					        "<composer>\n"
					        "	<sizer mode=\"vert\" addmode=\"invert\">\n"
					        "		<label>ploppp</label>\n"
					        "		<label expand=\"true,true\"><![CDATA[<center>** ** * *<br/>** * * * *</center>]]></label>\n"
					        "	</sizer>\n"
					        "	\n"
					        "	\n"
					        "</composer\n"));
					break;
				default:
					m_testWidget->SetSubWidget(new widget::Label("My <font color=\"#FF0000\">Button</font> <br/> And Some under line<br/> plop <br/> and an other super long line ..."));
					countTextID=-1;
					break;
			}
			// set at the subWidget all the space they can ...
			if (NULL != m_testWidget->GetSubWidget()){
				m_testWidget->GetSubWidget()->SetFill(bvec2(true,true));
				m_testWidget->GetSubWidget()->SetExpand(bvec2(true,true));
			}
			countTextID++;
		}
	}
	
	return;
}

void TestButton::OnObjectRemove(ewol::EObject * removeObject)
{
	widget::Sizer::OnObjectRemove(removeObject);
	if (m_testWidget == removeObject) {
		m_testWidget = NULL;
	}
}
