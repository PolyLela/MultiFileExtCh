# Multi File Extension Changer ✅

A small, cross-platform C++ CLI tool to recursively change file extensions in a directory using C++17's `std::filesystem`.

---

## 🔧 Features

- Recursively traverses directories starting from the current working directory
- Renames files that match a specified extension to a new extension
- Skips non-regular files and symbolic links
- Accepts extensions with or without a leading dot (e.g., `txt` or `.txt`)

---

## ⚙️ Requirements

- A C++ compiler with **C++17** support (for `std::filesystem`)
  - On Windows: MSVC (Visual Studio 2017+), MinGW-w64, or other compatible toolchains

---

## 🔨 Build

### Build directly with g++ (MinGW / GCC)

```bash
g++ -std=c++17 -O2 -Wall main.cpp core.cpp -o change_ext.exe
```

### Build with CMake

```bash
mkdir build && cd build
cmake ..
cmake --build . --config Release
```

(Use the generator appropriate for your environment, e.g. Visual Studio or MinGW Makefiles.)

---

## ▶️ Usage

Run the compiled binary from the directory where you want to start renaming, or pass a path if you modify the code.

```bash
# Interactive (prompts for both extensions)
./change_ext.exe

# Provide the source extension, will prompt for target
./change_ext.exe txt

# Provide both source and target extensions (non-interactive)
./change_ext.exe txt md
```

Notes:
- The program will add a leading `.` automatically if you omit it.
- It operates on the **current working directory** (`fs::current_path()` in the code).

---

## 📝 Behavior & Limitations

- Files are renamed using `std::filesystem::rename`.
- Errors during rename are suppressed in the current implementation (no logging or rollback).
- No dry-run mode; consider adding `--dry-run` to preview changes before applying them.

---

## 💡 Suggestions / TODO

- Add logging and a `--verbose` mode
- Add `--dry-run` and `--path` options
- Add unit tests and edge case handling (e.g., name collisions)

---

## Contributing

Feel free to open issues or PRs. Keep changes small and focused; add tests for new behavior.

---

## License

Distributed under the MIT License. See `LICENSE` or add one if desired.

---

If you'd like, I can add command-line parsing (e.g., via `getopt` or `cxxopts`), a dry-run mode, and logging — tell me which you'd prefer and I’ll add it. ✨
