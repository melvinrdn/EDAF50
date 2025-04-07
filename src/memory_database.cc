#include "memory_database.h"
#include <stdexcept> // for std::runtime_error
#include <algorithm> // for std::find_if

MemoryDatabase::MemoryDatabase() : nextNewsgroupId_(1) {}

std::vector<std::pair<int, std::string>> MemoryDatabase::listNewsgroups() const {
    std::vector<std::pair<int, std::string>> result;
    for (const auto& [id, ng] : newsgroups_) {
        result.emplace_back(id, ng.getNewsgroupTitle());
    }
    return result;
}

bool MemoryDatabase::createNewsgroup(const std::string& name) {
    // Check if a newsgroup with the same name exists
    for (const auto& [id, ng] : newsgroups_) {
        if (ng.getNewsgroupTitle() == name) {
            return false; // Already exists
        }
    }

    Newsgroup ng(nextNewsgroupId_, name);
    newsgroups_[nextNewsgroupId_] = ng;
    nextNewsgroupId_++;
    return true;
}

bool MemoryDatabase::deleteNewsgroup(int id) {
    auto it = newsgroups_.find(id);
    if (it == newsgroups_.end()) {
        return false; // Not found
    }
    newsgroups_.erase(it);
    return true;
}

std::vector<std::pair<int, std::string>> MemoryDatabase::listArticles(int newsgroup_id) const {
    auto it = newsgroups_.find(newsgroup_id);
    if (it == newsgroups_.end()) {
        throw std::runtime_error("Newsgroup not found");
    }

    const auto& articles = it->second.getArticles();
    std::vector<std::pair<int, std::string>> result;
    for (const auto& article : articles) {
        result.emplace_back(article.getArticleId(), article.getArticleTitle());
    }
    return result;
}

bool MemoryDatabase::createArticle(int newsgroup_id, const std::string& title,
                                   const std::string& author, const std::string& text) {
    auto it = newsgroups_.find(newsgroup_id);
    if (it == newsgroups_.end()) {
        return false;
    }

    it->second.addArticle(title, author, text);
    return true;
}

bool MemoryDatabase::deleteArticle(int newsgroup_id, int article_id) {
    auto it = newsgroups_.find(newsgroup_id);
    if (it == newsgroups_.end()) {
        return false;
    }

    return it->second.deleteArticle(article_id);
}

std::tuple<std::string, std::string, std::string>
MemoryDatabase::getArticle(int newsgroup_id, int article_id) const {
    auto it = newsgroups_.find(newsgroup_id);
    if (it == newsgroups_.end()) {
        throw std::runtime_error("Newsgroup not found");
    }

    const Article* article = it->second.getArticle(article_id);
    if (article == nullptr) {
        throw std::runtime_error("Article not found");
    }

    return std::make_tuple(article->getArticleTitle(),
                           article->getArticleAuthor(),
                           article->getArticleText());
}
