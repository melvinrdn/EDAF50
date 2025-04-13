#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <tuple>
#include <utility>

class Database
{
public:
    virtual std::vector<std::pair<int, std::string>> listNewsgroups() const = 0;
    virtual bool createNewsgroup(const std::string &name) = 0;
    virtual bool deleteNewsgroup(int id) = 0;

    virtual std::vector<std::pair<int, std::string>> listArticles(int newsgroup_id) const = 0;
    virtual bool createArticle(int newsgroup_id, const std::string &title,
                               const std::string &author, const std::string &text) = 0;
    virtual bool deleteArticle(int newsgroup_id, int article_id) = 0;
    virtual std::tuple<std::string, std::string, std::string>
    getArticle(int newsgroup_id, int article_id) const = 0;

    virtual ~Database() = default;
};

#endif 
