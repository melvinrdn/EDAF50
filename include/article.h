#ifndef ARTICLE_H
#define ARTICLE_H

#include <string>

// Represents a single news article
class Article {
public:
    // Construct an article with ID, title, author, and content
    Article(int articleId, const std::string &articleTitle, const std::string &articleAuthor, const std::string &articleText)
        : articleId_(articleId), articleTitle_(articleTitle), articleAuthor_(articleAuthor), articleText_(articleText) {}

    // Get the unique article ID
    int getArticleId() const { return articleId_; }
    // Get the article title
    const std::string& getArticleTitle() const { return articleTitle_; }
    // Get the article author
    const std::string& getArticleAuthor() const { return articleAuthor_; }
    // Get the article text
    const std::string& getArticleText() const { return articleText_; }

private:
    int articleId_;                // Unique ID for the article.
    std::string articleTitle_;     // Title of the article.
    std::string articleAuthor_;    // Author of the article.
    std::string articleText_;      // Content of the article.
};

#endif
