#include "word_ladder.h"
#include <iostream>

auto main() -> int
{
    auto const english_lexicon = word_ladder::read_lexicon("./english.txt");
    auto const ladders = word_ladder::generate("fly", "sky", english_lexicon);
    // debug here
    for(const auto& path:ladders){
            for (const auto& word:path){
                std::cout<<word<<" ";
            }
            std::cout<<std::endl;
        }
    return 0;
}
