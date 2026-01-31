#include <filesystem>
#include <string>

namespace fs = std::filesystem;

void changeFilesExtensions(const fs::path& directory, const std::string &oldExtension, const std::string &newExtension);