#ifndef NEWSGROUP_H
#define NEWSGROUP_H

#include <string>
#include <vector> // Good because it maintains the chronological order of articles
#include "article.h"

class Newsgroup {
public:
    // Constructor
    Newsgroup(int newsgroupId, const std::string &newsgroupTitle);

    // Getters
    int getNewsgroupId() const;
    const std::string& getNewsgroupTitle() const;

    // Adds a new article to the newsgroup and returns the assigned article ID.
    int addArticle(const std::string &articleTitle, const std::string &articleAuthor, const std::string &articleText);

    // Deletes an article by its article ID. Returns true if deletion was successful.
    bool deleteArticle(int articleId);

    // Returns a constant reference to the list of articles.
    const std::vector<Article>& getArticles() const;

    // Retrieves a pointer to an article by its article ID, or nullptr if not found.
    Article* getArticle(int articleId);
    const Article* getArticle(int articleId) const;

private:
    int newsgroupId_;                          // Unique ID of the newsgroup.
    std::string newsgroupTitle_;               // Title of the newsgroup.
    std::vector<Article> articleList_;         // Collection of articles in this newsgroup.
    int nextArticleId_;                        // Next available article ID.
};

#endif // NEWSGROUP_H
