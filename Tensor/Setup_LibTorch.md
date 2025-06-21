## Complete steps to set up LibTorch (C++ PyTorch) in Visual Studio from scratch —
-----------------------------------------------------------------------------------

- Step 1: Download LibTorch
    -  Go to the official site: https://pytorch.org/get-started/locally
       - Under "Language", choose C++.
       - Under "Compute Platform", choose: CPU for general development/CUDA for GPU acceleration (if you have an NVIDIA GPU with driver/toolkit)
       - Download the ZIP file: Release/Debug (depends upon you)

    -  After download, Extract to: -> C:\libtorch<br><br>

- Step 2: Configure Project Properties
    - Right-click on your project → Properties
        -C/C++ → General → Additional Include Directories

          - C:\libtorch\include
          - C:\libtorch\include\torch\csrc\api\include
    - Linker → General → Additional Library Directories
      - C:\libtorch\lib
    - Linker → Input → Additional Dependencies
      - Manually add these: torch.lib, c10.lib, torch_cpu.lib, if you're using CUDA, also add tourch_cuda.lib


    - C/C++ → Code Generation → Runtime Library
      - Use /MD for Release
      - Use /MDd for Debug
      - Make sure it matches the LibTorch version you downloaded.

    - C/C++ → Language → C++ Language Standard
      - Set to C++17 (or later)<br><br>

       
- Step 3: Copy .dll Files to your project Project output directory
    - For ex: C:\YourProject\x64\Release\
    -  Automate this using a Post-Build Event:
        - xcopy /Y /D "C:\libtorch\lib\*.dll" "$(OutDir)"
        - Paste it in:
        - Project Properties → Build Events → Post-Build Event → Command Line<br><br>

- Step 4: Build and Run

  - Run your project<br><br>
