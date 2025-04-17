#ifndef DATABASE_INTERFACE_H
#define DATABASE_INTERFACE_H

#include "database.h"
#include "memory_database.h"
#include "disk_database.h"

#include <memory>
#include <string>

enum class DatabaseMode { MEMORY, DISK };

inline std::unique_ptr<Database> createDatabase(DatabaseMode mode, const std::string& root = "./newsdb") {
    if (mode == DatabaseMode::MEMORY) {
        return std::make_unique<MemoryDatabase>();
    } else {
        return std::make_unique<DiskDatabase>(root);
    }
}

#endif
