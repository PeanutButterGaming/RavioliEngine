# ImGui fallback shim

This repository environment cannot fetch upstream GitHub dependencies during CI runs,
so this folder contains a tiny compile-time shim that mimics the subset of Dear ImGui
APIs currently used by `test/dummyapp.cpp`.

## Important

- This is **not** a full Dear ImGui distribution.
- Replace this folder with upstream Dear ImGui sources (`imgui.cpp`, `imgui_draw.cpp`,
  `imgui_widgets.cpp`, `imgui_tables.cpp`, `imgui_demo.cpp`, and `backends/*`) to get
  full UI rendering and widgets.

The shim allows CMake target discovery and local startup target setup to work without
hard failures when external network access is unavailable.
