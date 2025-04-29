#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <tuple>
#include <utility>

// Interface for news database operations
class Database
{
public:
    // List all newsgroups; return vector of (id, title)
    virtual std::vector<std::pair<int, std::string>> listNewsgroups() const = 0;

    // Create a newsgroup; return true on success
    virtual bool createNewsgroup(const std::string &name) = 0;

    // Delete a newsgroup by id; return true if existed and was deleted
    virtual bool deleteNewsgroup(int id) = 0;

    // List articles in a newsgroup; return vector of (id, title)
    virtual std::vector<std::pair<int, std::string>> listArticles(int newsgroup_id) const = 0;

    // Create an article; return true on success
    virtual bool createArticle(int newsgroup_id, const std::string &title,
                               const std::string &author, const std::string &text) = 0;

    // Delete an article by id; return true if existed and was deleted
    virtual bool deleteArticle(int newsgroup_id, int article_id) = 0;

    // Get an article by id; return tuple of (title, author, text)
    virtual std::tuple<std::string, std::string, std::string>
    getArticle(int newsgroup_id, int article_id) const = 0;

    virtual ~Database() = default;
};

#endif 
