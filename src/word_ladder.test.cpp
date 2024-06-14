#include "word_ladder.h"

#include <catch2/catch.hpp>

TEST_CASE("word_ladder::read_lexicon works as expected") {
	auto const words = word_ladder::read_lexicon("./english.txt");
	REQUIRE_FALSE(words.empty());
	REQUIRE_FALSE(words.find("work") == words.end());
	REQUIRE(words.find("workk") == words.end());
}

TEST_CASE("word_ladder::generate works as expected") {
	SECTION( "word_ladder::generate works as expected in simple dictioanry" ) {
		auto const lexicon = std::unordered_set<std::string>{
			"at",
			"it"
		};
		const auto expected = std::vector<std::vector<std::string>>{
			{"at", "it"}
		};
		auto const ladders = word_ladder::generate("at", "it", lexicon);
		CHECK(ladders == expected);
	}

	SECTION( "word_ladder::generate works as expected with lexicon full dictionary" ) {
		auto const lexicon = word_ladder::read_lexicon("./english.txt");
		const auto expected = std::vector<std::vector<std::string>>{
			{"at", "it"}
		};
		auto const ladders = word_ladder::generate("at", "it", lexicon);
		CHECK(ladders == expected);
	}

	SECTION( "word_ladder::generate works when expected with mutiple path return" ) {
		auto const words = word_ladder::read_lexicon("./english.txt");
		const auto expected = std::vector<std::vector<std::string>>{
		{"awake", "aware", "sware", "share", "sharn", "shawn", "shewn", "sheen", "sheep", "sleep"},
		{"awake", "aware", "sware", "share", "shire", "shirr", "shier", "sheer", "sheep", "sleep"}
		};
	}
	SECTION( "word_ladder::generate works when no path return" ) {
		auto const words = word_ladder::read_lexicon("./english.txt");
		auto const ladders = word_ladder::generate("airplane", "tricycle", words);
		REQUIRE(ladders.empty());
	}
}