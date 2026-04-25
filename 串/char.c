#include<stdio.h>
#include<stdlib.h>
//#include<stdbool.h>
#define MAXLEN 100
typedef struct Str
{
    char ch[MAXLEN];
    int length;
}Str;
//先写清空函数
void clearStr(Str *s){
    s->length=0;
    s->ch[0]='\0';
}
//再写拼接函数
void concatantionStr(Str *s,Str *t){
    if(s->length+t->length>=100){
        printf("error,thats more");
    }
    else{

    
        int i=0;
        while(t->ch[i]!='\0'){
            
            s->ch[s->length]=t->ch[i];
            s->length++;
            i++;     
        }
        s->ch[s->length]='\0';
        }

}
//初始化函数**实际上就是全部化空哈哈
void initStr(Str *s){
    s->ch[0]='\0';
    s->length=0;
}
//接下来是复制函数，实际上就是把一个串先清空再拼接，没啥好说的
void copyStr(Str *s,Str *t){
    clearStr(s);
    concatantionStr(s,t);
    printf("拼接完毕，你可以查看一下: ",&s);
}
//接下来开始写查找函数，由于我看了 ai 的描述我觉得朴素查找太蠢了，我打算直接尝试开始写人类直觉类型的查找，然后
//我再尝试在里面加入 kmp 算法看看，先尝试一下人类直觉查找，思路是先用第一个字母开始比对，第一个对来开始对第二个，然后依次往下，有一个不对就开始下一个首字母一样的地方开始比对
//这是人类直觉函数，先实现人类直觉算法（暂且叫他 BF 算法吧），首字母查找先实现这个，接下来再尝试插入 kmp 和 bm 算法
int humanfind(Str s, Str t){
    //这是在 s 里面找 t 的函数，先尝试实行首字母
    if(s.length<t.length){
        printf("主串更短，找不到");
        return -1;
    }
    else{
        int i=0;
        while(i<s.length){
            int j;//用来给循环里用的
            if(s.ch[i]==t.ch[0]){
                int m=i;//创建了一个临时变量 m 用来作为 for 循环里遍历用的工具，不和 i 搞混。虽然好像有点没必要 hh
                for(j=1;j<t.length;j++){
                    if(s.ch[m]==t.ch[j]){
                        m++;
                    }
                    else{
                        break;
                    }
            }
            if(j==t.length){//我想了半天才想到用 j 来作为成功判断哈哈哈哈，还是去问了一下豆包，豆包还是聪明
                printf("找到了，在第%d个位置",i);
                return i;
                }
            }
            i++;
            }
            
        }
        printf("遍历完了还是没找到\n");
        return -1;
    }

//直觉算法已经完毕，接下来开始尝试在直觉算法里插入 kmp，也就是中间那一步 for 循环遍历的时候能遍历 j 的时候多储存一步信息。

//我突然发现在那之前我需要一个 next 数组函数，我写到 kmp 一半了我才发现的。这个 next 可谓是核心呢
void getNext(Str t,int next[]){
    int k=0,j=1;
    next[0]=0;
    while(j<t.length){
        if (t.ch[k]==t.ch[j])
        {
            /*  这里应该就是这个算法的核心了，一开始理解的时候也是花了一点时间，我让 ai 帮我把思路和想法解释给我，现在开始
            尝试自己写一下看看能不能做出来 */
            next[j]=k+1;
            k++,j++;
        }
        else if(k!=0){
            k=next[k];
            //j++;//这里是不是不需要 j++？好像不需要诶？我把他注释掉了
        }
        else{
            next[j]=0;
            j++;
            printf("当前无公共约束往下找才对\n");
        }
    }
}

int kmpfind(Str s,Str t){
    if(s.length<t.length){
        printf("主串更短没法找");
        return -1;
    }
    int i=0;
    while(i<s.length){//前面部分和 BF 算法几乎一致，这些判断都一样几乎没怎么改
        if(s.ch[i]==t.ch[0]){

        }
    }
}