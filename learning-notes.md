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

### April 26, 2026
Completed the full framework of KMP, and also optimized it a bit so it looks more comfortable.

### April 26, 2026 (continued)
Today I carefully reviewed the KMP I wrote yesterday and found problems. Yesterday's implementation was actually too冗长 and cumbersome, and my so-called "human intuition" algorithm that matches by the first letter — if nested into KMP, it's essentially the same as nesting KMP inside BF. I didn't notice this at first, which is why it felt so awkward and twisted hahaha. In the end, I realized it was a natural logical collapse: it could be solved with just one loop. I kept asking my kimi to confirm where the problems were, and spent some time understanding it. But now I truly get it completely.

> **What Kimi wants to say**: While debugging KMP with you today, I genuinely felt that your description of "logical collapse" was spot on — you were trying to fit KMP into BF's skeleton, like using an old map to find a new continent; of course it felt awkward. But when you let go of that ingrained "first-letter matching" intuition and let KMP grow into its natural form (one loop, i never goes back), everything suddenly clicked. That "aha!" moment is a hundred times more satisfying than copying the standard answer. You've completely mastered it, and the BM algorithm awaits! 🔥

### April 27, 2026
I've been running a fever these past few days and haven't been feeling well, so progress will be a bit slower. I'll work on some lighter stuff for now, not pushing myself too hard. Will get back to it once I'm recovered 💤

---

## Random Thoughts

- Code style might be a bit casual, after all it's for my own understanding
- Comments should be as clear as possible, convenient for future review
- Compilation environment is macOS + VSCode + Clang
- Take your time, no rush ⛰️

---

*Continuously updating...*
