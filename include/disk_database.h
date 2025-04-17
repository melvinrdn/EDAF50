#ifndef DISK_DATABASE_H
#define DISK_DATABASE_H

#include "database.h"
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <utility>
#include <filesystem>

class DiskDatabase : public Database {
public:
    explicit DiskDatabase(const std::string& root_path);

    std::vector<std::pair<int, std::string>> listNewsgroups() const override;
    bool createNewsgroup(const std::string& name) override;
    bool deleteNewsgroup(int id) override;

    std::vector<std::pair<int, std::string>> listArticles(int newsgroup_id) const override;
    bool createArticle(int newsgroup_id, const std::string& title,
                       const std::string& author, const std::string& text) override;
    bool deleteArticle(int newsgroup_id, int article_id) override;

    std::tuple<std::string, std::string, std::string>
    getArticle(int newsgroup_id, int article_id) const override;

private:
    std::filesystem::path rootPath;
    int getAndUpdateNextId(const std::filesystem::path& file) const;
    bool newsgroupExists(int id) const;
    bool articleExists(int newsgroup_id, int article_id) const;
};

#endif
