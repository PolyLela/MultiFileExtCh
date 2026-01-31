#include "core.hpp"

void changeFilesExtensions(const fs::path& directory, const std::string &oldExtension, const std::string &newExtension) {
    for (const auto& entry : fs::directory_iterator(directory)) {
        fs::path path = entry.path();

        if (!entry.is_regular_file()) {
            if (entry.is_directory() && !entry.is_symlink())
                changeFilesExtensions(path, oldExtension, newExtension);
            continue;
        }
        
        if (path.extension() != oldExtension)
            continue;

        fs::path newPath = path;
        newPath.replace_extension(newExtension);
        
        std::error_code erc;
        fs::rename(path, newPath, erc);
    }
}