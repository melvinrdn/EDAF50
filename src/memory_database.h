#ifndef MEMORY_DATABASE_H
#define MEMORY_DATABASE_H

#include "database.h"
#include "newsgroup.h"
#include "article.h"

#include <map>
#include <vector>
#include <string>
#include <tuple>
#include <utility>

// In-memory implementation of the Database interface
class MemoryDatabase : public Database {
public:
    // Initialize with empty database
    MemoryDatabase();

    // List all newsgroups (id, title)
    std::vector<std::pair<int, std::string>> listNewsgroups() const override;
    // Create a newsgroup; return true on success
    bool createNewsgroup(const std::string& name) override;
    // Delete a newsgroup by id; return true if deleted
    bool deleteNewsgroup(int id) override;

    // List articles in a newsgroup (id, title)
    std::vector<std::pair<int, std::string>> listArticles(int newsgroup_id) const override;
    // Create an article; return true on success
    bool createArticle(int newsgroup_id,
                       const std::string& title,
                       const std::string& author,
                       const std::string& text) override;
    // Delete an article by id; return true if deleted
    bool deleteArticle(int newsgroup_id, int article_id) override;
    // Retrieve an article (title, author, text)
    std::tuple<std::string, std::string, std::string>
    getArticle(int newsgroup_id, int article_id) const override;

private:
    std::map<int, Newsgroup> newsgroups_; // Map newsgroup ID to data
    int nextNewsgroupId_;                 // ID to assign next
};

#endif
