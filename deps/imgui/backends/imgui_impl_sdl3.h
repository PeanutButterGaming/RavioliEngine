#pragma once

struct SDL_Window;
struct SDL_Renderer;
union SDL_Event;

namespace ImGui {
struct ImDrawData;
}

bool ImGui_ImplSDL3_InitForSDLRenderer(SDL_Window* window, SDL_Renderer* renderer);
void ImGui_ImplSDL3_Shutdown();
void ImGui_ImplSDL3_NewFrame();
void ImGui_ImplSDL3_ProcessEvent(const SDL_Event* event);
