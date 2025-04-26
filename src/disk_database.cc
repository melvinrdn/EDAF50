#include "disk_database.h"
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <algorithm>

namespace fs = std::filesystem;

DiskDatabase::DiskDatabase(const std::string& root_path)
    : rootPath(root_path) {
    if (!fs::exists(rootPath)) {
        fs::create_directory(rootPath);
    }
    if (!fs::exists(rootPath / "next_ng_id.txt")) {
        std::ofstream(rootPath / "next_ng_id.txt") << 1;
    }
}

int DiskDatabase::getAndUpdateNextId(const fs::path& file) const {
    int id = 1;
    std::ifstream in(file);
    if (in >> id) {
        in.close();
        std::ofstream out(file);
        out << (id + 1);
    } else {
        std::ofstream out(file);
        out << 2;
    }
    return id;
}

bool DiskDatabase::newsgroupExists(int id) const {
    return fs::exists(rootPath / std::to_string(id));
}

bool DiskDatabase::articleExists(int ngid, int artid) const {
    return fs::exists(rootPath / std::to_string(ngid) / (std::to_string(artid) + ".txt"));
}

std::vector<std::pair<int, std::string>> DiskDatabase::listNewsgroups() const {
    std::vector<std::pair<int, std::string>> result;

    for (const auto& entry : fs::directory_iterator(rootPath)) {
        if (fs::is_directory(entry)) {
            int id;
            try {
                id = std::stoi(entry.path().filename().string());
            } catch (...) {
                continue;
            }
            std::ifstream titleFile(entry.path() / "title.txt");
            std::string title;
            std::getline(titleFile, title);
            result.emplace_back(id, title);
        }
    }

    std::sort(result.begin(), result.end());
    return result;
}

bool DiskDatabase::createNewsgroup(const std::string& name) {
    for (const auto& [id, existing_name] : listNewsgroups()) {
        if (existing_name == name) {
            return false;
        }
    }

    int id = getAndUpdateNextId(rootPath / "next_ng_id.txt");
    fs::path ngPath = rootPath / std::to_string(id);
    fs::create_directory(ngPath);
    std::ofstream(ngPath / "title.txt") << name;
    std::ofstream(ngPath / "next_art_id.txt") << 1;
    return true;
}

bool DiskDatabase::deleteNewsgroup(int id) {
    fs::path ngPath = rootPath / std::to_string(id);
    if (!fs::exists(ngPath)) return false;
    fs::remove_all(ngPath);
    return true;
}

std::vector<std::pair<int, std::string>> DiskDatabase::listArticles(int newsgroup_id) const {
    if (!newsgroupExists(newsgroup_id)) {
        throw std::runtime_error("Newsgroup not found");
    }

    fs::path ngPath = rootPath / std::to_string(newsgroup_id);
    std::vector<std::pair<int, std::string>> articles;

    for (const auto& file : fs::directory_iterator(ngPath)) {
        if (file.path().extension() == ".txt" &&
            file.path().filename() != "title.txt" &&
            file.path().filename() != "next_art_id.txt") {
            int id = std::stoi(file.path().stem().string());
            std::ifstream in(file.path());
            std::string title;
            std::getline(in, title);
            articles.emplace_back(id, title);
        }
    }

    std::sort(articles.begin(), articles.end());
    return articles;
}

bool DiskDatabase::createArticle(int newsgroup_id, const std::string& title,
                                 const std::string& author, const std::string& text) {
    if (!newsgroupExists(newsgroup_id)) return false;

    fs::path ngPath = rootPath / std::to_string(newsgroup_id);
    int id = getAndUpdateNextId(ngPath / "next_art_id.txt");

    std::ofstream out(ngPath / (std::to_string(id) + ".txt"));
    out << title << '\n' << author << '\n' << text;
    return true;
}

bool DiskDatabase::deleteArticle(int newsgroup_id, int article_id) {
    if (!newsgroupExists(newsgroup_id)) return false;
    fs::path artPath = rootPath / std::to_string(newsgroup_id) / (std::to_string(article_id) + ".txt");
    return fs::remove(artPath);
}

std::tuple<std::string, std::string, std::string>
DiskDatabase::getArticle(int newsgroup_id, int article_id) const {
    if (!newsgroupExists(newsgroup_id)) {
        throw std::runtime_error("Newsgroup not found");
    }

    fs::path artPath = rootPath / std::to_string(newsgroup_id) / (std::to_string(article_id) + ".txt");
    if (!fs::exists(artPath)) {
        throw std::runtime_error("Article not found");
    }

    std::ifstream in(artPath);
    std::string title;
    std::string author;
    std::string text;

    std::getline(in, title);
    std::getline(in, author);

    std::ostringstream oss;
    oss << in.rdbuf();
    text = oss.str();

    return std::make_tuple(title, author, text);
}
