#include "../include/newsgroup.h"


// Constructor
Newsgroup::Newsgroup(int newsgroupId, const std::string &newsgroupTitle)
    : newsgroupId_(newsgroupId), newsgroupTitle_(newsgroupTitle), nextArticleId_(1) {} // TODO: This 1 should be defined in a constant

// Getters
int Newsgroup::getNewsgroupId() const {
    return newsgroupId_;
}
const std::string& Newsgroup::getNewsgroupTitle() const {
    return newsgroupTitle_;
}
const std::vector<Article>& Newsgroup::getArticles() const {
    return articleList_;
}

// Adds a new article, assigning it the next available article ID.
int Newsgroup::addArticle(const std::string &articleTitle, const std::string &articleAuthor, const std::string &articleText) {
    int currentId = nextArticleId_;
    articleList_.emplace_back(currentId, articleTitle, articleAuthor, articleText);
    ++nextArticleId_; // Increment the ID for the next article, ensureing uniqueness
    return currentId;
}

// Searches for an article by its ID and deletes it if found.
bool Newsgroup::deleteArticle(int articleId) {
    for (auto it = articleList_.begin(); it != articleList_.end(); ++it) {
        if (it->getArticleId() == articleId) {
            articleList_.erase(it);
            return true;
        }
    }
    return false;
}

// Returns a pointer to the article with the given ID, or nullptr if not found.
Article* Newsgroup::getArticle(int articleId) {
    for (auto &article : articleList_) {
        if (article.getArticleId() == articleId)
            return &article;
    }
    return nullptr;
}

// Const version of getArticle
const Article* Newsgroup::getArticle(int articleId) const {
    for (const auto &article : articleList_) {
        if (article.getArticleId() == articleId)
            return &article;
    }
    return nullptr;
}
