/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#ifndef __TEST_CHECK_BOX_H__
#define __TEST_CHECK_BOX_H__

#include <appl/debug.h>
#include <ewol/widget/CheckBox.h>
#include <ewol/widget/Composer.h>

namespace appl {
	class TestCheckBox : public ewol::widget::Composer {
		private:
			std::shared_ptr<ewol::widget::CheckBox> m_testWidget;
		public:
			// Constructeur
			TestCheckBox();
			void init();
		public:
			DECLARE_FACTORY(TestCheckBox);
		public: // Derived function
			virtual void onReceiveMessage(const ewol::object::Message& _msg);
	};
};
#endif
