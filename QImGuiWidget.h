#pragma once

#include <imgui.h>

#include <QColor>
#include <QElapsedTimer>
#include <QMouseEvent>
#include <QOpenGLExtraFunctions>
#include <QOpenGLWidget>
#include <QScopedPointer>
#include <QSharedPointer>
#include <QWidget>

#include <functional>

class QImGuiWidget;
class QImGuiInterface : public QObject {
	Q_OBJECT
	friend class QImGuiWidget;

public:
	static ImFontAtlas *GetFontAtlas();
	virtual ~QImGuiInterface();
	void moveToImguiGlWidget(QImGuiWidget *);

protected:
	QImGuiInterface();
	virtual void OnImguiFrameShow() = 0;
	virtual void preGlWidgetChange() = 0;
	virtual void onGlWidgetChanged() = 0;

private: /*qt event override functions for input*/
	void impl_mousePressEvent(QMouseEvent *event);
	void impl_mouseReleaseEvent(QMouseEvent *event);
	void impl_mouseDoubleClickEvent(QMouseEvent *event);
	void impl_mouseMoveEvent(QMouseEvent *event);
	void impl_leaveEvent(QEvent *event);
#if QT_CONFIG(wheelevent)
	void impl_wheelEvent(QWheelEvent *event);
#endif
	void impl_keyPressEvent(QKeyEvent *event);
	void impl_keyReleaseEvent(QKeyEvent *event);
	void impl_inputMethodEvent(QInputMethodEvent *event);

private:
	void InitImguiCtx();

private:
	ImGuiContext *imgui = nullptr;
	int im_width = 0;
	int im_height = 0;
	bool frame_drawing = false;
	QVector<ImDrawList *> draw_data;
	QElapsedTimer im_timer;
};

class QImGuiWidget : public QOpenGLWidget {
public:
	QImGuiWidget(QObject *parent);
	~QImGuiWidget();
	void DeleteTexture(GLuint t);
	GLuint CreateTexture(const uint8_t *data, int w, int h, int fmt);
	void setFrame(QImGuiInterface *);

private:
	// override functions
	void initializeGL() override;
	void resizeGL(int w, int h) override;
	void paintGL() override;

private:
	// opengl utils
	void QtOpenGlDevicesCreate();
	void QtOpenGlDevicesClean();
	void QtImguiImplNewFarme();
	void QtOpenGlNewFarme();
	void QtOpenGlSetClearRenderTarget();
	void QtOpenGlRenderData();

private: /*qt event override functions for input*/
	void closeEvent(QCloseEvent *event) override;
	void mousePressEvent(QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;
	void mouseDoubleClickEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;
	void leaveEvent(QEvent *event) override;
#if QT_CONFIG(wheelevent)
	void wheelEvent(QWheelEvent *event) override;
#endif
	void keyPressEvent(QKeyEvent *event) override;
	void keyReleaseEvent(QKeyEvent *event) override;
	void inputMethodEvent(QInputMethodEvent *event) override;
	QVariant inputMethodQuery(Qt::InputMethodQuery query) const override;

private:
	QColor ClearColor = {20, 20, 20, 20};
	QImGuiInterface *FrameInterface = nullptr;
	GLuint FontTex = {};
	int ShaderHandle = 0, VertHandle = 0, FragHandle = 0;
	int AttribLocationTex = 0, AttribLocationProjMtx = 0;
	int AttribLocationPosition = 0, AttribLocationUV = 0, AttribLocationColor = 0;
	unsigned int VboHandle = 0, VaoHandle = 0, ElementsHandle = 0;
	// IME 输入位置（供 Platform_SetImeDataFn 回调使用）
	QPointF ImeInputPos = {0, 0};
	float ImeInputLineHeight = 20.0f;
};

// 简易包装类，只需提供 std::function 即可使用 ImGui
class QSimpleImGuiWidget : public QImGuiWidget {
public:
	using ImGuiFrameCallback = std::function<void()>;

	explicit QSimpleImGuiWidget(QObject *parent = nullptr);
	explicit QSimpleImGuiWidget(ImGuiFrameCallback callback, QObject *parent = nullptr);
	~QSimpleImGuiWidget();

	// 设置 ImGui 渲染回调
	void setFrameCallback(ImGuiFrameCallback callback);

private:
	class SimpleInterface;
	SimpleInterface *m_interface = nullptr;
};
