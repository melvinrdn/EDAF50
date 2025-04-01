#ifndef ARTICLE_H
#define ARTICLE_H

#include <string>

// Here we directly define the class inside the header since it is only consitued of getters.

class Article {
public:
    // Constructor
    Article(int id, const std::string &title, const std::string &author, const std::string &text)
        : id_(id), title_(title), author_(author), text_(text) {}

    // Getters
    int getId() const { return id_; }
    const std::string& getTitle() const { return title_; }
    const std::string& getAuthor() const { return author_; }
    const std::string& getText() const { return text_; }

private:
    int id_;                // ID of the article
    std::string title_;     // Title of the article
    std::string author_;    // Author of the article
    std::string text_;      // The content of the article
};

#endif