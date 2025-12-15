#include "Example.h"

Example::Example() { ImGui::StyleColorsDark(); }

void Example::OnImguiFrameShow() {
	ImGui::Begin("HELLO IMGUI", 0, 0);
	ImGui::End();
	ImGui::ShowDemoWindow();
}
void Example::preGlWidgetChange() {
	// release image texture
}
void Example::onGlWidgetChanged() {
	// create image texture
}