#pragma once

struct SDL_Renderer;

namespace ImGui {
struct ImDrawData;
}

bool ImGui_ImplSDLRenderer3_Init(SDL_Renderer* renderer);
void ImGui_ImplSDLRenderer3_Shutdown();
void ImGui_ImplSDLRenderer3_NewFrame();
void ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::ImDrawData* draw_data, SDL_Renderer* renderer);
