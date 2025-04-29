#ifndef DATABASE_INTERFACE_H
#define DATABASE_INTERFACE_H

#include "database.h"
#include "memory_database.h"
#include "disk_database.h"

#include <memory>
#include <string>


// Database storage modes
enum class DatabaseMode {
    MEMORY, // In-memory database (no persistence)
    DISK    // Disk-based database for persistent storage
};

// Create a Database instance based on mode and root directory. Default is "./newsdb".
inline std::unique_ptr<Database> createDatabase(DatabaseMode mode, const std::string& root = "./newsdb") {
    if (mode == DatabaseMode::MEMORY) {
        return std::make_unique<MemoryDatabase>();
    } else {
        return std::make_unique<DiskDatabase>(root);
    }
}

#endif
