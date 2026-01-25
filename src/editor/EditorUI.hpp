#pragma once

// Minimal EditorUI wrapper for ImGui
// Put this in src/editor/ and include/instantiate it in your main loop or engine subsystems.

#include <memory>

namespace RavEngine {
class EditorUI {
public:
    static void Initialize();    // call once after window/graphics subsystem are ready
    static void Shutdown();      // call on exit
    static void NewFrame();      // call at start of each frame (after platform event processing)
    static void Render();        // call after ImGui windows have been created; will call ImGui::Render internally

    // Helper to show the demo window so you can confirm ImGui is working quickly
    static void ShowDemoWindow(bool show = true);

private:
    EditorUI() = delete;
    ~EditorUI() = delete;
};
}
