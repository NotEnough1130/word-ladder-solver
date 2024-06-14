# Word Ladder Project

### Learning Goals

- Explore C++’s value semantics.
- Understand modularity in managing data and providing functionality without exposing implementation details.
- Gain familiarity with C++'s type system.
- Leverage the C++ Standard Library, specifically `std::vector`, `std::queue`, and `std::unordered_set`.

### Example Word Ladders
work -> fork -> form -> foam -> flam -> flay -> play:
work -> pork -> perk -> peak -> pean -> plan -> play


 ## Implementation Details

### Breadth-First Search (BFS) Algorithm

BFS is used to find the shortest path from the start word to the end word. The algorithm proceeds by exploring all words that are one letter change away from the start word, then all words two changes away, and so on, until the end word is found.

### Key Points

- **Queue**: Used to maintain partial ladders in increasing order of length.
- **Set**: Used to track words that have been used in ladders to avoid redundancy and cycles.
- **Vector**: Used to store the sequence of words in a ladder.

### Assumptions

- Start and end words are of the same length.
- Both start and end words are in the lexicon.
- The start and end words are different.
- The lexicon file is valid and correctly formatted.
