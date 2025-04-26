#ifndef DISK_DATABASE_H
#define DISK_DATABASE_H

#include "database.h"
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <utility>
#include <filesystem>

// Disk-based implementation of Database interface
class DiskDatabase : public Database {
public:
    // Initialize with root directory for storage
    explicit DiskDatabase(const std::string& root_path);

    // List existing newsgroups (id, title)
    std::vector<std::pair<int, std::string>> listNewsgroups() const override;
    // Create a new newsgroup with the given name, reutrn true if successful
    bool createNewsgroup(const std::string& name) override;
    // Delete a newsgroup by id, return true if successful
    bool deleteNewsgroup(int id) override;

    // List articles in a newsgroup (id, title)
    std::vector<std::pair<int, std::string>> listArticles(int newsgroup_id) const override;
    // Create an article; return true on success
    bool createArticle(int newsgroup_id, const std::string& title,
                       const std::string& author, const std::string& text) override;
    // Delete an article by id; return true if deleted
    bool deleteArticle(int newsgroup_id, int article_id) override;

    // Retrieve article (title, author, text)
    std::tuple<std::string, std::string, std::string>
    getArticle(int newsgroup_id, int article_id) const override;

private:
    std::filesystem::path rootPath; // Filesystem root for database files
    int getAndUpdateNextId(const std::filesystem::path& file) const; // Read next ID from file and increment it
    bool newsgroupExists(int id) const; // Check if a newsgroup directory exists
    bool articleExists(int newsgroup_id, int article_id) const; // Check if an article file exists in a newsgroup
};

#endif
