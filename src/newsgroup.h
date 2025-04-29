#ifndef NEWSGROUP_H
#define NEWSGROUP_H

#include <string>
#include <vector>
#include "article.h"

// Represents a collection of articles under a named group
class Newsgroup {
public:
    // Default for testing purposes
    Newsgroup() = default;
    // Construct a newsgroup with ID and title
    Newsgroup(int newsgroupId, const std::string &newsgroupTitle);

    // Get the unique newsgroup ID
    int getNewsgroupId() const;
    // Get the newsgroup title
    const std::string& getNewsgroupTitle() const;

    // Add an article; returns the assigned article ID
    int addArticle(const std::string &articleTitle,
                   const std::string &articleAuthor,
                   const std::string &articleText);

    // Delete an article by ID; returns true if found and removed
    bool deleteArticle(int articleId);

    // Access the list of articles (chronological order)
    const std::vector<Article>& getArticles() const;

    // Retrieve an article by ID (nullptr if not found)
    Article* getArticle(int articleId);
    const Article* getArticle(int articleId) const;

private:
    int newsgroupId_;                // Unique ID of the newsgroup
    std::string newsgroupTitle_;     // Title of the newsgroup
    std::vector<Article> articleList_; // Articles in this group
    int nextArticleId_;              // Next article ID to assign
};

#endif
