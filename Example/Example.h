#pragma once

#include <QImguiWidget.h>
class Example : public QImGuiInterface {
	Q_OBJECT
public:
	Example();
	void OnImguiFrameShow() override;
	void preGlWidgetChange() override;
	void onGlWidgetChanged() override;
};
