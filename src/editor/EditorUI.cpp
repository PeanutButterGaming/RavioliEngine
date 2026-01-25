#include "EditorUI.hpp"

#include <imgui.h>

// NOTE:
// This file assumes the ImGui core (imgui target) is compiled (deps/imgui).
// You still need a platform + renderer backend (e.g. imgui_impl_sdl + imgui_impl_opengl3 or a custom RGL renderer).
// If you use SDL + OpenGL: compile deps/imgui/backends/imgui_impl_sdl.cpp and imgui_impl_opengl3.cpp into the imgui target
// and call the corresponding ImGui_Impl..._Init / NewFrame / RenderDrawData functions from your app.
// If you have a custom renderer (RGL), implement ImGui->RGL rendering in a small bridge and call it from Render().

namespace RavEngine {

static bool s_showDemo = true;

void EditorUI::Initialize() {
    // Nothing in core wrapper; backend init must be called from the platform/renderer integration:
    // e.g. ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    //       ImGui_ImplOpenGL3_Init("#version 150");
    // If you have an RGL backend, init it here.
}

void EditorUI::Shutdown() {
    // Backend shutdown must be performed from platform/renderer integration:
    // e.g. ImGui_ImplOpenGL3_Shutdown();
    //       ImGui_ImplSDL2_Shutdown();
}

void EditorUI::NewFrame() {
    // The backend layer must provide its NewFrame calls (ImGui_ImplSDL2_NewFrame + ImGui_ImplOpenGL3_NewFrame)
    // Call those from your main loop before this, or augment this function to call them if you compile backends into the imgui target.
    ImGui::NewFrame();
}

void EditorUI::Render() {
    // Example simple editor window
    if (s_showDemo) {
        ImGui::ShowDemoWindow(&s_showDemo);
    }

    // Place any editor-specific windows here
    if (ImGui::Begin("Editor")) {
        ImGui::Text("RavEngine Editor running");
        ImGui::Separator();
        ImGui::Text("Frame time: TODO");
    }
    ImGui::End();

    ImGui::Render();
    // After ImGui::Render() you must call your backend renderer to actually draw:
    // e.g. ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    // or your ImGui->RGL bridge renderer here.
}

void EditorUI::ShowDemoWindow(bool show) {
    s_showDemo = show;
}

} // namespace RavEngine
