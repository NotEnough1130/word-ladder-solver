#include "word_ladder.h"
#include<vector>
#include<queue>
#include<unordered_set>
#include <fstream>
#include <string>
#include <unordered_map>


auto word_ladder::read_lexicon(const std::string &path) -> std::unordered_set<std::string> {
	(void) path;
    std::ifstream file(path);
	std::string word;
    auto words = std::unordered_set<std::string>{};

    while (std::getline(file, word)) {
        words.insert(word);
	}
    file.close(); 
	return words;
}


auto word_ladder::generate(
	const std::string &from,
	const std::string &to,
	const std::unordered_set<std::string> &lexicon
) -> std::vector<std::vector<std::string>> {
	(void)from;
	(void)to;
	(void)lexicon;
	std::queue<std::string> bfsQueue;
	std::unordered_map<std::string, std::unordered_set<std::string>> neighboursDict;

	bfsQueue.push(from);
	int loop = 1;
	while(!bfsQueue.empty()){
		size_t sizeOfQueue = bfsQueue.size();
		for(size_t i =0; i<sizeOfQueue;i++){
			std::string currentWord = bfsQueue.front();
			for (size_t j = 0; j < currentWord.length(); j++) {
				std::string keyWord = currentWord;
				for (char c = 'a'; c <= 'z'; c++) {
					if (currentWord[j] != c) {
						currentWord[j] = c;
						std::string newWord = currentWord;
						if (lexicon.contains(newWord) and !neighboursDict[keyWord].contains(newWord)) {
							neighboursDict[keyWord].insert(newWord);
							bfsQueue.push(newWord);
						}
					}
					currentWord= keyWord;
				}
			}
			bfsQueue.pop();
		}
		loop++;
	}

	std::vector<std::vector<std::string>> resultSet;
    std::unordered_set<std::string> visited;
    std::queue<std::vector<std::string>> paths;
    paths.push({from});
    visited.insert(from);
    bool found = false;
	try{
		while (!paths.empty() && !found) {
			size_t levelSize = paths.size();
			std::unordered_set<std::string> levelVisited;
			for (size_t i = 0; i < levelSize; ++i) {
				auto currentPath = paths.front();
				paths.pop();
				std::string lastWord = currentPath.back();
				for (auto const& word : neighboursDict.at(lastWord)) {
					if (visited.find(word) == visited.end()) {
						std::vector<std::string> newPath = currentPath;
						newPath.push_back(word);
						if (word == to) {
							found = true;
							resultSet.push_back(newPath);
						} else {
							paths.push(newPath);
							levelVisited.insert(word);
						}
					}
				}
			}
			visited.insert(levelVisited.begin(), levelVisited.end());
		}
	}catch(const std::exception& e){
		return {};
	}
    return resultSet;
}