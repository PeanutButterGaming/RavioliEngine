#pragma once

// Offline fallback shim for Dear ImGui API used by RavEngine DummyApp.
// Replace this directory with upstream Dear ImGui sources for full functionality.

#include <cstdarg>

#define IMGUI_CHECKVERSION() ((void)0)

enum ImGuiConfigFlags_ {
    ImGuiConfigFlags_None = 0,
    ImGuiConfigFlags_NavEnableKeyboard = 1 << 0,
};

struct ImDrawData {};

namespace ImGui {
struct ImGuiIO {
    float Framerate = 60.0f;
    int ConfigFlags = ImGuiConfigFlags_None;
};

void* CreateContext();
void DestroyContext(void* ctx = nullptr);
ImGuiIO& GetIO();

void StyleColorsDark();
void NewFrame();
void Render();
ImDrawData* GetDrawData();

bool Begin(const char* name);
void End();
void Text(const char* fmt, ...);
void Separator();
void ShowDemoWindow(bool* p_open = nullptr);
}  // namespace ImGui
