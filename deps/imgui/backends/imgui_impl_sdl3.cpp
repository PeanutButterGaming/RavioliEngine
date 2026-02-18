#include "imgui_impl_sdl3.h"

bool ImGui_ImplSDL3_InitForSDLRenderer(SDL_Window*, SDL_Renderer*) {
    return true;
}

void ImGui_ImplSDL3_Shutdown() {}

void ImGui_ImplSDL3_NewFrame() {}

void ImGui_ImplSDL3_ProcessEvent(const SDL_Event*) {}
