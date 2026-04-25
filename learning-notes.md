# Data Structure Study Notes

> **Author**: An ordinary 985 university student  
> **Purpose**: To record my process of learning data structures, as a study diary 📚  
> **Note**: This notebook and repository are mainly managed by my Agent

---

## About This Repository

This repository is used to store the code I write while learning data structures. Nothing special, just typing along with courses/textbooks bit by bit. Some are finished, some are not; slowly filling them in.

## Current Progress

| Chapter | Status | Description |
|-----|------|---------|
| Sequential List | ✅ Completed | Linear list based on array |
| Linked List | ✅ Completed | Basic operations of singly linked list |
| Stack | ✅ Completed | Array implementation + Linked implementation |
| Queue | ✅ Completed | Linked queue |
| String | 🚧 In Progress | String operations, currently studying search algorithms |

## Code Structure

```
.
├── 顺序表/          # Linear list implemented by array
├── 链表/            # Linked list related
├── 栈/              # Stack (sequential + linked)
├── 队列/            # Queue
├── 串/              # String (incomplete)
├── 学习笔记.md   # Chinese version
└── learning-notes.md   # This file
```

## Study Log

### April 23, 2026
Today I added the `copyStr` function to the string part, and also added some comments. The string operations are slowly becoming clearer, keep going 💪

### April 24, 2026
Today while thinking about string searching, I suddenly felt that the KMP algorithm is still a bit complex. Then I thought: can I skip some obviously mismatched positions based on specific characters, which should make the search much faster.

I took this idea and asked an AI, and it turned out that this is also a very famous algorithm — **BM algorithm (Boyer-Moore)**! Exactly what I was thinking 😄

It seems "human intuition" is sometimes quite reliable. Tomorrow I'll try to implement it in code.

### April 24, 2026 (continued)
Finally tried to translate my logic into code! Harder than I imagined. The first version I wrote was harshly criticized by Doubao (AI) hahaha, but slowly I fixed it. The `humanfind` function runs successfully now, although it's still just a naive first-character matching version, it's considered the first step 💪

### April 25, 2026
Today I spent more than an hour and finally completely understood the next array in the KMP algorithm, and also knew how to write it. I wrote it by myself and then let AI modify it a little bit and optimize it. So satisfying haha, this feeling is really great

---

## Random Thoughts

- Code style might be a bit casual, after all it's for my own understanding
- Comments should be as clear as possible, convenient for future review
- Compilation environment is macOS + VSCode + Clang
- Take your time, no rush ⛰️

---

*Continuously updating...*
