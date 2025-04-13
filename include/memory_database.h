#ifndef MEMORY_DATABASE_H
#define MEMORY_DATABASE_H

#include "database.h"      
#include "newsgroup.h"     
#include "article.h"

#include <map>
#include <vector>
#include <string>
#include <tuple>
#include <utility> // for std::pair

class MemoryDatabase : public Database {
public:
    MemoryDatabase();

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
    std::map<int, Newsgroup> newsgroups_; 
    int nextNewsgroupId_;                   
};

#endif 
