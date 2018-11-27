CPSC4110-FinalProject

Download VS Code

In VS Code install the following extrensions
- C/C++ by Microsoft
- Code Runner

Install MinGW onto Windows computer.
- Install the gcc-g++ bin

Update Environment Variables to point to MinGW/bin.

File -> Preferences -> Keyboard Shortcuts -> Keybindings.json
    Place the following:
    // Place your key bindings in this file to overwrite the defaults
    [
        { "key": "f8",          "command": "workbench.action.tasks.build" }
    ]

Now when running the main.cc, the Makefile will execute everything and run the build.