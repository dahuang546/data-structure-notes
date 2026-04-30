#include<stdio.h>
#include<stdlib.h>
//#include<stdbool.h>
#define MAXLEN 100

typedef struct Str
{
    char ch[MAXLEN];
    int length;
} Str;

// 先写清空函数
void clearStr(Str *s){
    s->length = 0;
    s->ch[0] = '\0';
}

// 再写拼接函数
void concatantionStr(Str *s, Str *t){
    if(s->length + t->length >= 100){
        printf("error, thats more");
    }
    else{
        int i = 0;
        while(t->ch[i] != '\0'){
            s->ch[s->length] = t->ch[i];
            s->length++;
            i++;
        }
        s->ch[s->length] = '\0';
    }
}

// 初始化函数**实际上就是全部化空哈哈
void initStr(Str *s){
    s->ch[0] = '\0';
    s->length = 0;
}

// 接下来是复制函数，实际上就是把一个串先清空再拼接，没啥好说的
void copyStr(Str *s, Str *t){
    clearStr(s);
    concatantionStr(s, t);
    printf("拼接完毕，你可以查看一下: ", &s);
}

// 接下来开始写查找函数，由于我看了 ai 的描述我觉得朴素查找太蠢了，我打算直接尝试开始写人类直觉类型的查找，然后
// 我再尝试在里面加入 kmp 算法看看，先尝试一下人类直觉查找，思路是先用第一个字母开始比对，第一个对来开始对第二个，然后依次往下，有一个不对就开始下一个首字母一样的地方开始比对
// 这是人类直觉函数，先实现人类直觉算法（暂且叫他 BF 算法吧），首字母查找先实现这个，接下来再尝试插入 kmp 和 bm 算法
int humanfind(Str s, Str t){
    // 这是在 s 里面找 t 的函数，先尝试实行首字母
    if(s.length < t.length){
        printf("主串更短，找不到");
        return -1;
    }
    else{
        int i = 0;
        while(i < s.length){
            int j; // 用来给循环里用的
            if(s.ch[i] == t.ch[0]){
                int m = i; // 创建了一个临时变量 m 用来作为 for 循环里遍历用的工具，不和 i 搞混。虽然好像有点没必要 hh
                for(j = 1; j < t.length; j++){
                    if(s.ch[m] == t.ch[j]){
                        m++;
                    }
                    else{
                        break;
                    }
                }
                if(j == t.length){ // 我想了半天才想到用 j 来作为成功判断哈哈哈哈，还是去问了一下豆包，豆包还是聪明
                    printf("找到了，在第%d个位置", i);
                    return i;
                }
            }
            i++;
        }
    }
    printf("遍历完了还是没找到\n");
    return -1;
}

// 直觉算法已经完毕，接下来开始尝试在直觉算法里插入 kmp，也就是中间那一步 for 循环遍历的时候能遍历 j 的时候多储存一步信息。

// 我突然发现在那之前我需要一个 next 数组函数，我写到 kmp 一半了我才发现的。这个 next 可谓是核心呢

// 2026年4月26日 修正：
// 原本搞错了 next 数组的使用位置，以为 getNext 里需要 k-1，最后才搞对。
// getNext 本身算的是 t[0..j] 的最长相等前后缀长度，配合 kmpfind 失配时用的是 next[j-1]，不是 next[j]。
void getNext(Str t, int next[]){
    int k = 0, j = 1;
    next[0] = 0;
    while(j < t.length){
        if(t.ch[k] == t.ch[j]){
            // 这里应该就是这个算法的核心了，一开始理解的时候也是花了一点时间，我让 ai 帮我把思路和想法解释给我，现在开始尝试自己写一下看看能不能做出来
            next[j] = k + 1;
            k++, j++;
        }
        else if(k != 0){
            // k 回退到前一个最长相等前缀的末尾
            k = next[k];
        }
        else{
            next[j] = 0;
            j++;
        }
    }
}

int kmpfind(Str s, Str t){
    // 写的方法是先写一个 BF 算法，然后再加上 kmp，不过这一次优化了一下 BF 的逻辑，没有上次那么乱了
    if(s.length < t.length){
        printf("主串更短没法找");
        return -1;
    }
    int next[MAXLEN];
    getNext(t, next);
    int i = 0, j = 0;
    // 前面部分和 BF 算法几乎一致，这些判断都一样几乎没怎么改
    // 2026年4月26日 修改，之前写的有问题，不需要用 BF，要完完全全改成 KMP 的 O（N）复杂度才对
    while(i < s.length && j < t.length){
        if(s.ch[i] == t.ch[j]){
            i++;
            j++;
        }
        else{
            if(j != 0){
                j = next[j - 1];
            }
            else{
                i++;
            }
        }
    }
    if(j == t.length){
        printf("找到了\n");
        return i - j + 1;
    }
    else{
        printf("no find\n");
        return -1;
    }
}


//接下来准备开始尝试一下 BM 算法，简单尝试即可，串花的时间有点久了

// ==================== BM 算法（Boyer-Moore）====================
// 核心思想：从右往左比较，失配时利用"坏字符"和"好后缀"跳过大量不可能的位置
// 注释会写得详细一点，方便以后回看不费劲

// 坏字符表预处理
// badChar[c] = 字符 c 在模式串 t 中最右出现的位置下标，没出现过则为 -1
void buildBadCharTable(Str t, int badChar[]) {
    int i;
    for(i = 0; i < 256; i++) {
        badChar[i] = -1;
    }
    for(i = 0; i < t.length; i++) {
        badChar[(unsigned char)t.ch[i]] = i;
    }
}

// 好后缀移动距离表
// gs[j] 表示：当在模式串位置 j 失配时（即 t[j+1..m-1] 已匹配成功，是"好后缀"），
// 模式串应该向右移动多少位。
//
// 三种情况（从直观角度来理解）：
// 1. 在模式串 t[0..m-2] 中从右往左找一个与好后缀完全匹配的子串，移动使其对齐
// 2. 好后缀的某个后缀恰好是模式串的前缀，移动使前缀对齐
// 3. 上面两种都不满足，直接移动 m 位（整个模式串长度）
void buildGoodSuffix(Str t, int gs[]) {
    int m = t.length;
    int j, i, k;
    
    for(j = 0; j < m; j++) {
        gs[j] = m; // 默认情况 3：移动 m 位
        
        int goodLen = m - 1 - j; // 好后缀的长度
        if(goodLen <= 0) continue;
        
        // ---- 情况 1：在 t[0..m-2] 中从右往左找与好后缀匹配的子串 ----
        for(i = m - 2; i >= goodLen - 1; i--) {
            // 检查 t[i-goodLen+1..i] 是否等于好后缀 t[j+1..m-1]
            int match = 1;
            for(k = 0; k < goodLen; k++) {
                if(t.ch[i - k] != t.ch[m - 1 - k]) {
                    match = 0;
                    break;
                }
            }
            // 找到了，还要保证这个子串前面一个字符和失配位置字符不同
            // （否则对齐后仍然失配，白忙一场）
            if(match) {
                int prevI = i - goodLen;
                if(prevI < 0 || t.ch[prevI] != t.ch[j]) {
                    gs[j] = m - 1 - i; // 移动距离
                    break;
                }
            }
        }
        
        if(gs[j] != m) continue; // 情况 1 找到了，跳过情况 2
        
        // ---- 情况 2：好后缀的某个后缀是模式串的前缀 ----
        for(k = goodLen; k >= 1; k--) {
            int isPrefix = 1;
            for(i = 0; i < k; i++) {
                if(t.ch[i] != t.ch[m - k + i]) {
                    isPrefix = 0;
                    break;
                }
            }
            if(isPrefix) {
                gs[j] = m - k;
                break;
            }
        }
    }
}

// BM 查找函数
// 返回 t 在 s 中的起始位置，找不到返回 -1
int bmFind(Str s, Str t) {
    int n = s.length;
    int m = t.length;
    if(m > n) {
        printf("主串更短，找不到\n");
        return -1;
    }
    
    int badChar[256];
    int gs[MAXLEN];
    
    buildBadCharTable(t, badChar);
    buildGoodSuffix(t, gs);
    
    int i = 0; // 模式串在主串中的起始位置
    while(i <= n - m) {
        int j = m - 1; // 从模式串末尾开始比较
        
        // 从右往左匹配
        while(j >= 0 && s.ch[i + j] == t.ch[j]) {
            j--;
        }
        
        if(j < 0) {
            printf("找到了，在第 %d 个位置\n", i);
            return i;
        }
        
        // 坏字符规则：失配字符 s.ch[i+j] 在模式串中最右出现的位置
        int bcShift = j - badChar[(unsigned char)s.ch[i + j]];
        if(bcShift < 1) bcShift = 1; // 至少移动 1 位，避免死循环
        
        // 好后缀规则（如果失配位置就是最后一个字符，说明没有好后缀，此规则不适用）
        int gsShift = (j < m - 1) ? gs[j] : 0;
        
        // 取两者较大值，保证不会跳过可能匹配的位置
        int shift = bcShift > gsShift ? bcShift : gsShift;
        
        i += shift;
    }
    
    printf("遍历完了还是没找到\n");
    return -1;
}


// ==================== 测试入口 ====================
int main() {
    Str s, t;
    
    // 初始化主串：ABAAABCDABCABC
    initStr(&s);
    char strS[] = "ABAAABCDABCABC";
    int i = 0;
    while(strS[i] != '\0') {
        s.ch[i] = strS[i];
        s.length++;
        i++;
    }
    s.ch[s.length] = '\0';
    
    // 初始化模式串：ABCABC
    initStr(&t);
    char strT[] = "ABCABC";
    i = 0;
    while(strT[i] != '\0') {
        t.ch[i] = strT[i];
        t.length++;
        i++;
    }
    t.ch[t.length] = '\0';
    
    printf("主串: %s\n", s.ch);
    printf("模式串: %s\n", t.ch);
    printf("\n--- BM 查找 ---\n");
    bmFind(s, t);
    
    return 0;
}
