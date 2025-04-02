#ifndef ARTICLE_H
#define ARTICLE_H

#include <string>

class Article {
public:
    // Constructor: 
    Article(int articleId, const std::string &articleTitle, const std::string &articleAuthor, const std::string &articleText)
        : articleId_(articleId), articleTitle_(articleTitle), articleAuthor_(articleAuthor), articleText_(articleText) {}

    // Getters
    int getArticleId() const { return articleId_; }
    const std::string& getArticleTitle() const { return articleTitle_; }
    const std::string& getArticleAuthor() const { return articleAuthor_; }
    const std::string& getArticleText() const { return articleText_; }

private:
    int articleId_;                // Unique ID for the article.
    std::string articleTitle_;     // Title of the article.
    std::string articleAuthor_;    // Author of the article.
    std::string articleText_;      // Content of the article.
};

#endif // ARTICLE_H
