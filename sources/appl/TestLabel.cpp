/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */


#include <appl/debug.h>
#include <appl/TestLabel.h>

#include <ewol/widget/Button.h>
#include <ewol/widget/CheckBox.h>
#include <ewol/widget/Sizer.h>
#include <ewol/widget/Label.h>
#include <ewol/widget/Entry.h>
#include <ewol/widget/List.h>
#include <ewol/widget/ContextMenu.h>
#include <ewol/widget/PopUp.h>
#include <ewol/widget/Slider.h>
#include <ewol/widget/Menu.h>
#include <ewol/widget/meta/FileChooser.h>
#include <ewol/widget/meta/Parameter.h>
#include <ewol/widget/Manager.h>


static const char * l_eventChangeExpendX     = "event-change-expend-X";
static const char * l_eventChangeExpendY     = "event-change-expend-Y";
static const char * l_eventChangeFillX       = "event-change-fill-X";
static const char * l_eventChangeFillY       = "event-change-fill-Y";
static const char * l_eventChangeMaxSize     = "event-change-maxSize";
static const char * l_eventChangeLabel       = "event-change-label";

#undef __class__
#define __class__	"TestButton"

appl::TestLabel::TestLabel() {
	addObjectType("appl::TestLabel");
}

void appl::TestLabel::init() {
	ewol::widget::Sizer::init(ewol::widget::Sizer::modeVert);
	APPL_DEBUG("CREATE " __class__ " ... ");
	std::shared_ptr<ewol::widget::Sizer> mySizerVert2;
	std::shared_ptr<ewol::widget::Sizer> mySizerHori;
	std::shared_ptr<ewol::widget::Button> myButton;
	
	mySizerHori = ewol::widget::Sizer::create(ewol::widget::Sizer::modeHori);
	if (nullptr == mySizerHori) {
		APPL_DEBUG("Allocation error mySizerHori");
		return;
	}
	subWidgetAdd(mySizerHori);
		myButton = ewol::widget::Button::create();
		if (nullptr != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      ewol::widget::Label::create("Expand X (false)"));
			myButton->setSubWidgetToggle(ewol::widget::Label::create("Expand X (true)"));
			myButton->registerOnEvent(shared_from_this(), "value", l_eventChangeExpendX);
			mySizerHori->subWidgetAdd(myButton);
		}
		myButton = ewol::widget::Button::create();
		if (nullptr != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      ewol::widget::Label::create("Expand Y (false)"));
			myButton->setSubWidgetToggle(ewol::widget::Label::create("Expand Y (true)"));
			myButton->registerOnEvent(shared_from_this(), "value", l_eventChangeExpendY);
			mySizerHori->subWidgetAdd(myButton);
		}
		myButton = ewol::widget::Button::create();
		if (nullptr != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      ewol::widget::Label::create("Fill X (false)"));
			myButton->setSubWidgetToggle(ewol::widget::Label::create("Fill X (true)"));
			myButton->registerOnEvent(shared_from_this(), "value", l_eventChangeFillX);
			mySizerHori->subWidgetAdd(myButton);
		}
		myButton = ewol::widget::Button::create();
		if (nullptr != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      ewol::widget::Label::create("Fill Y (false)"));
			myButton->setSubWidgetToggle(ewol::widget::Label::create("Fill Y (true)"));
			myButton->registerOnEvent(shared_from_this(), "value", l_eventChangeFillY);
			mySizerHori->subWidgetAdd(myButton);
		}
		myButton = ewol::widget::Button::create();
		if (nullptr != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      ewol::widget::Label::create("no Max size"));
			myButton->setSubWidgetToggle(ewol::widget::Label::create("maxSize (400,99999999)"));
			myButton->registerOnEvent(shared_from_this(), "value", l_eventChangeMaxSize);
			mySizerHori->subWidgetAdd(myButton);
		}
		myButton = ewol::widget::Button::create();
		if (nullptr != myButton) {
			myButton->setSubWidget(ewol::widget::Label::create("Next Label"));
			myButton->registerOnEvent(shared_from_this(), "pressed", l_eventChangeLabel);
			mySizerHori->subWidgetAdd(myButton);
		}
		
	std::shared_ptr<ewol::widget::Spacer> mySpacer = ewol::widget::Spacer::create();
	if (nullptr != mySpacer) {
		mySpacer->setExpand(bvec2(false,false));
		mySpacer->setFill(bvec2(true,false));
		mySpacer->setMinSize(vec2(10,10));
		mySpacer->setColor(etk::Color<>(0xFF, 0x00, 0x00, 0x80));
		subWidgetAdd(mySpacer);
	}
	
	mySizerHori = ewol::widget::Sizer::create(ewol::widget::Sizer::modeHori);
	if (nullptr == mySizerHori) {
		APPL_DEBUG("Allocation error mySizerHori");
		return;
	}
	subWidgetAdd(mySizerHori);
		mySpacer = ewol::widget::Spacer::create();
		if (nullptr != mySpacer) {
			mySpacer->setExpand(bvec2(false,false));
			mySpacer->setFill(bvec2(false,true));
			mySpacer->setMinSize(vec2(10,10));
			mySpacer->setColor(etk::Color<>(0x00, 0xFF, 0x00, 0x80));
			mySizerHori->subWidgetAdd(mySpacer);
		}
		
		m_testWidget = ewol::widget::Label::create("Basic label");
		if (nullptr != m_testWidget) {
			m_testWidget->setExpand(bvec2(false,false));
			m_testWidget->setFill(bvec2(false,false));
			//m_testWidget->registerOnEvent(shared_from_this(), ewolEventButtonColorChange);
			mySizerHori->subWidgetAdd(m_testWidget);
		}
		
		mySpacer = ewol::widget::Spacer::create();
		if (nullptr != mySpacer) {
			mySpacer->setExpand(bvec2(false,false));
			mySpacer->setFill(bvec2(false,true));
			mySpacer->setMinSize(vec2(10,10));
			mySpacer->setColor(etk::Color<>(0x00, 0x00, 0xFF, 0x80));
			mySizerHori->subWidgetAdd(mySpacer);
		}
		
	mySpacer = ewol::widget::Spacer::create();
	if (nullptr != mySpacer) {
		mySpacer->setExpand(bvec2(false,false));
		mySpacer->setFill(bvec2(true,false));
		mySpacer->setMinSize(vec2(10,10));
		mySpacer->setColor(etk::Color<>(0x00, 0xFF, 0xFF, 0x80));
		subWidgetAdd(mySpacer);
	}
}


void appl::TestLabel::onReceiveMessage(const ewol::object::Message& _msg) {
	ewol::widget::Sizer::onReceiveMessage(_msg);
	//APPL_INFO("Receive Event from the main windows ... : \"" << eventId << "\" ==> data=\"" << data << "\"" );
	if (m_testWidget == _msg.getCaller()) {
		APPL_WARNING("Receive Event from tested Button ... : " << _msg );
	}
	if (_msg.getMessage() == l_eventChangeExpendX) {
		if (nullptr!=m_testWidget) {
			if (_msg.getData()=="true") {
				m_testWidget->setExpand(bvec2(true,m_testWidget->getExpand().y()));
			} else {
				m_testWidget->setExpand(bvec2(true,m_testWidget->getExpand().y()));
			}
		}
	} else if (_msg.getMessage() == l_eventChangeExpendY) {
		if (nullptr!=m_testWidget) {
			if (_msg.getData()=="true") {
				m_testWidget->setExpand(bvec2(m_testWidget->getExpand().x(),true));
			} else {
				m_testWidget->setExpand(bvec2(m_testWidget->getExpand().x(),false));
			}
		}
	} else if (_msg.getMessage() == l_eventChangeFillX) {
		if (nullptr!=m_testWidget) {
			if (_msg.getData()=="true") {
				m_testWidget->setFill(bvec2(true,m_testWidget->getFill().y()));
			} else {
				m_testWidget->setFill(bvec2(false,m_testWidget->getFill().y()));
			}
		}
	} else if (_msg.getMessage() == l_eventChangeFillY) {
		if (nullptr!=m_testWidget) {
			if (_msg.getData()=="true") {
				m_testWidget->setFill(bvec2(m_testWidget->getFill().x(),true));
			} else {
				m_testWidget->setFill(bvec2(m_testWidget->getFill().x(),false));
			}
		}
	} else if (_msg.getMessage() == l_eventChangeMaxSize) {
		if (nullptr!=m_testWidget) {
			if (_msg.getData()=="true") {
				m_testWidget->setMaxSize(vec2(400,9999999999));
			} else {
				m_testWidget->setNoMaxSize();
			}
		}
	} else if (_msg.getMessage() == l_eventChangeLabel) {
		if (nullptr!=m_testWidget) {
			m_labelId++;
			switch(m_labelId)
			{
				default:
					m_labelId=0;
				case 0:
					m_testWidget->setLabel("Basic label");
					break;
				case 1:
					m_testWidget->setLabel("Basic <bold>label</bold>");
					break;
				case 2:
					m_testWidget->setLabel("<center>\n"
					                       "	Un jour Cosette se <b>regarda</b> par hasard dans son miroir et se dit: Tiens! <b>Il lui semblait presque <i>qu'elle était jolie.</i></b> Ceci la jeta dans un trouble singulier. <font color=\"#FF0000\">Jusqu'à ce moment elle <b>n'avait</b> point <i>songé</i> à sa figure.</font> Elle se voyait dans son miroir, mais elle ne s'y regardait pas. Et puis, on lui avait souvent dit qu'elle était laide;<br/> Jean Valjean seul disait doucement : <br/> Mais non!<br/>  mais non!<br/>  Quoi qu'il en fut, Cosette s'était toujours crue laide, et avait grandi dans cette idée avec la résignation facile de l'enfance. Voici que tout d'un coup son miroir lui disait comme Jean Valjean : Mais non! Elle ne dormit pas de la nuit. Si j'étais jolie ? pensait-elle, comme cela serait drole que je fusse jolie! Et elle se rappelait celles de ses compagnes dont la beauté faisait effet dans le couvent, et elle se disait : Comment! je serais comme mademoiselle une telle!\n"
					                       "</center>\n");
					break;
				case 3:
					m_testWidget->setLabel("<left>\n"
					                       "	Un jour Cosette se <b>regarda</b> par hasard dans son miroir et se dit: Tiens! <b>Il lui semblait presque <i>qu'elle était jolie.</i></b> Ceci la jeta dans un trouble singulier. <font color=\"#0F0\">Jusqu'à ce moment elle <b>n'avait</b> point <i>songé</i> à sa figure.</font> Elle se voyait dans son miroir, mais elle ne s'y regardait pas. Et puis, on lui avait souvent dit qu'elle était laide;<br/> Jean Valjean seul disait doucement :<br/>  Mais non!<br/>  mais non!<br/>  Quoi qu'il en fut, Cosette s'était toujours crue laide, et avait grandi dans cette idée avec la résignation facile de l'enfance. Voici que tout d'un coup son miroir lui disait comme Jean Valjean : Mais non! Elle ne dormit pas de la nuit. Si j'étais jolie ? pensait-elle, comme cela serait drole que je fusse jolie! Et elle se rappelait celles de ses compagnes dont la beauté faisait effet dans le couvent, et elle se disait : Comment! je serais comme mademoiselle une telle!\n"
					                       "</left>\n");
					break;
				case 4:
					m_testWidget->setLabel("<right>\n"
					                       "	Un jour Cosette se <b>regarda</b> par hasard dans son miroir et se dit: Tiens! <b>Il lui semblait presque <i>qu'elle était jolie.</i></b> Ceci la jeta dans un trouble singulier. <font color=\"#00F\">Jusqu'à ce moment elle<b> n'avait</b> point <i>songé</i> à sa figure.</font> Elle se voyait dans son miroir, mais elle ne s'y regardait pas. Et puis, on lui avait souvent dit qu'elle était laide;<br/> Jean Valjean seul disait doucement :<br/>  Mais non! <br/> mais non!<br/>  Quoi qu'il en fut, Cosette s'était toujours crue laide, et avait grandi dans cette idée avec la résignation facile de l'enfance. Voici que tout d'un coup son miroir lui disait comme Jean Valjean : Mais non! Elle ne dormit pas de la nuit. Si j'étais jolie ? pensait-elle, comme cela serait drole que je fusse jolie! Et elle se rappelait celles de ses compagnes dont la beauté faisait effet dans le couvent, et elle se disait : Comment! je serais comme mademoiselle une telle!\n"
					                       "</right>\n");
					break;
				case 5:
					m_testWidget->setLabel("<justify>\n"
					                       "	Un jour Cosette se <b>regarda</b> par hasard dans son miroir et se dit: Tiens! <b>Il lui semblait presque <i>qu'elle était jolie.</i></b> Ceci la jeta dans un trouble singulier. <font color=\"#FF0\">Jusqu'à ce moment elle <b>n'avait</b> point <i>songé</i> à sa figure.</font> Elle se voyait dans son miroir, mais elle ne s'y regardait pas. Et puis, on lui avait souvent dit qu'elle était laide;<br/> Jean Valjean seul disait doucement :<br/>  Mais non!<br/>  mais non!<br/>  Quoi qu'il en fut, Cosette s'était toujours crue laide, et avait grandi dans cette idée avec la résignation facile de l'enfance. Voici que tout d'un coup son miroir lui disait comme Jean Valjean : Mais non! Elle ne dormit pas de la nuit. Si j'étais jolie ? pensait-elle, comme cela serait drole que je fusse jolie! Et elle se rappelait celles de ses compagnes dont la beauté faisait effet dans le couvent, et elle se disait : Comment! je serais comme mademoiselle une telle!\n"
					                       "</justify>\n");
					break;
			}
		}
	}
	
	return;
}

