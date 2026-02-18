#include "imgui.h"

#include <chrono>

namespace ImGui {
namespace {
ImGuiIO gIO{};
ImDrawData gDrawData{};
bool gInFrame = false;
std::chrono::high_resolution_clock::time_point gLastFrameTime;
}

void* CreateContext() {
    gLastFrameTime = std::chrono::high_resolution_clock::now();
    gIO = ImGuiIO{};
    return &gIO;
}

void DestroyContext(void*) {
    gInFrame = false;
}

ImGuiIO& GetIO() {
    return gIO;
}

void StyleColorsDark() {}

void NewFrame() {
    const auto now = std::chrono::high_resolution_clock::now();
    if (gLastFrameTime.time_since_epoch().count() != 0) {
        const auto dt = std::chrono::duration<float>(now - gLastFrameTime).count();
        if (dt > 0.0f) {
            gIO.Framerate = 1.0f / dt;
        }
    }
    gLastFrameTime = now;
    gInFrame = true;
}

void Render() {
    gInFrame = false;
}

ImDrawData* GetDrawData() {
    return &gDrawData;
}

bool Begin(const char*) {
    return gInFrame;
}

void End() {}

void Text(const char*, ...) {}

void Separator() {}

void ShowDemoWindow(bool*) {}
}  // namespace ImGui
