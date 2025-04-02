#include <iostream>
#include "newsgroup.h"

int main() {
    bool allTestsPassed = true;

    // Test 1: Newsgroup Creation
    std::cout << "Test 1: Creating a newsgroup...\n";
    Newsgroup group(1, "Test Group");
    if (group.getNewsgroupId() != 1 || group.getNewsgroupTitle() != "Test Group") {
        std::cout << "Test 1 FAILED: Newsgroup properties not set correctly.\n";
        allTestsPassed = false;
    } else {
        std::cout << "Test 1 PASSED: Newsgroup created with ID = " 
                  << group.getNewsgroupId() 
                  << " and Title = " << group.getNewsgroupTitle() << "\n";
    }

    // Test 2: Adding Articles
    std::cout << "\nTest 2: Adding two articles...\n";
    int articleId1 = group.addArticle("First Article", "Author A", "This is the first article text.");
    int articleId2 = group.addArticle("Second Article", "Author B", "This is the second article text.");
    if (articleId1 <= 0 || articleId2 <= articleId1) {
        std::cout << "Test 2 FAILED: Invalid article IDs returned.\n";
        allTestsPassed = false;
    } else {
        std::cout << "Test 2 PASSED: Articles added with IDs " 
                  << articleId1 << " and " << articleId2 << "\n";
    }

    // Test 3: Retrieving Articles
    std::cout << "\nTest 3: Retrieving articles...\n";
    Article* article1 = group.getArticle(articleId1);
    Article* article2 = group.getArticle(articleId2);
    if (article1 == nullptr || article2 == nullptr) {
        std::cout << "Test 3 FAILED: One or more articles could not be retrieved.\n";
        allTestsPassed = false;
    } else {
        if (article1->getArticleTitle() != "First Article" || article1->getArticleAuthor() != "Author A") {
            std::cout << "Test 3 FAILED: First article details mismatch.\n";
            allTestsPassed = false;
        } else if (article2->getArticleTitle() != "Second Article" || article2->getArticleAuthor() != "Author B") {
            std::cout << "Test 3 FAILED: Second article details mismatch.\n";
            allTestsPassed = false;
        } else {
            std::cout << "Test 3 PASSED: Articles retrieved with correct details.\n";
        }
    }

    // Test 4: Deleting an Article
    std::cout << "\nTest 4: Deleting the first article...\n";
    bool deletionResult = group.deleteArticle(articleId1);
    if (!deletionResult) {
        std::cout << "Test 4 FAILED: Failed to delete the first article.\n";
        allTestsPassed = false;
    } else if (group.getArticle(articleId1) != nullptr) {
        std::cout << "Test 4 FAILED: First article is still retrievable after deletion.\n";
        allTestsPassed = false;
    } else {
        std::cout << "Test 4 PASSED: First article deleted successfully.\n";
    }

    // Test 5: Listing Remaining Articles
    std::cout << "\nTest 5: Listing remaining articles...\n";
    const auto& articles = group.getArticles();
    if (articles.size() != 1) {
        std::cout << "Test 5 FAILED: Expected 1 remaining article, found " 
                  << articles.size() << "\n";
        allTestsPassed = false;
    } else {
        std::cout << "Test 5 PASSED: 1 remaining article as expected.\n";
        std::cout << "Remaining Article - ID: " << articles[0].getArticleId() 
                  << ", Title: " << articles[0].getArticleTitle() << "\n";
    }


    std::cout << "\n";
    if (allTestsPassed) {
        std::cout << "ALL TESTS PASSED.\n";
        return 0;
    } else {
        std::cout << "SOME TESTS FAILED.\n";
        return 1;
    }
}
