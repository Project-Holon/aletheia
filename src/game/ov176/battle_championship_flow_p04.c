/*
 * file:     battle_championship_flow_p04.c
 * unit:     yes
 * function: func_0217B55C, func_0217B594, func_0217B620, func_0217B6AC, func_0217B768, func_0217B7A0, func_0217B7D8, func_0217B924, func_0217B930, func_0217B93C, func_0217B950, func_0217B964
 * address:  0x0217B55C
 * region:   ov176
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217B4A0 0x0217B4A0 thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_02082BCC 0x02082BCC arm
 *   func_0217D398 0x0217D398 thumb ov176
 *   func_0217D434 0x0217D434 thumb ov176
 *   func_0217D44C 0x0217D44C thumb ov176
 *   func_0217D410 0x0217D410 thumb ov176
 *   func_0217B970 0x0217B970 thumb ov176
 *   func_0217B3C0 0x0217B3C0 thumb ov176
 *   func_0202EB44 0x0202EB44 thumb
 *   func_0200B480 0x0200B480 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_0200B1D4 0x0200B1D4 thumb
 *   func_021E88B0 0x021E88B0 thumb ov177
 *   func_021E89D0 0x021E89D0 thumb ov177
 *   func_021E8A00 0x021E8A00 thumb ov177
 *   func_021E8738  0x021E8738  thumb  ov177
 *   func_021E8844 0x021E8844 thumb ov177
 */
#include "../../matched/include/Obj02221.h"
#include "../../matched/include/Obj02222.h"
#include "../../matched/include/Obj01762.h"
#include "../../matched/include/Obj24405.h"

struct Big;
struct Rec160;
typedef unsigned char  u8;

typedef struct { int mode; int a,b,c,d,e,f,g; } Config;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef struct {
    u32 f00,f04,f08,option0,option1,f14,f18,count;
    u16 f20,f22,f24,f26;
    u32 f28;
    u16 f2c,f2e;
} Menu;

extern void func_0217B4A0(int p, unsigned *state, int *q);
extern void func_021E8AA0(int *p, int v);
extern void func_02082BCC(void *,int,int);
extern int func_0217D398(Config *,int);
extern void func_0217D434(int *p);
extern int func_0217D44C(int *p);
extern void func_0217D410(int *p);
extern void func_0217B970(int *,int);
extern void func_0217B3C0(int p, unsigned *state, int *q);
extern int func_0202EB44(void);
extern void func_0200B480(void);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200B358(void *);
extern struct Rec160 *func_0200B1D4(struct Rec160 *arr, u32 index);
extern void *func_021E88B0(Menu *,u8,u8,u8,u32,int);
extern void func_021E89D0(int);
extern int func_021E8A00(int);
extern void func_021E8738(int *p, int a, int b, int c);
extern int func_021E8844(const int *);
void func_0217B55C(int p,int *state,int *q);
void func_0217B594(int p, int *state, char *q);
void func_0217B620(int p, int *state, char *q);
void func_0217B6AC(int p,unsigned *state,int *q);
void func_0217B768(int *p,int *state,u8 *q);
void func_0217B7A0(int *p,int *state,u8 *q);
void func_0217B7D8(int *p, int index);
void func_0217B924(int *p);
unsigned func_0217B930(int *p);
void func_0217B93C(int *p, int b);
void func_0217B950(int *p, int b);
int func_0217B964(int *p);

void func_0217B55C(int p,int *state,int *q)
{
    switch(*state) {
    case 0: func_0217B93C(q,8); *state=1; break;
    case 1: if(func_0217B964((int *)q)==1) func_021E8AA0((int *)p,(int)func_0217B4A0); break;
    }
}

void func_0217B594(int p, int *state, char *q)
{
    Config config;
    switch (*state) {
    case 0:
        func_02082BCC(&config, 0, 32);
        config.mode = 0;
        config.a = ((struct Obj02221 *)q)->f18;
        config.b = ((struct Obj02221 *)q)->f1C;
        config.c = ((struct Obj02221 *)q)->f20;
        config.d = ((struct Obj02221 *)q)->f24;
        config.e = ((struct Obj02221 *)q)->f28;
        config.f = ((struct Obj02221 *)q)->f2C;
        config.g = ((struct Obj02221 *)q)->f30;
        ((struct Obj02221 *)q)->f38 = func_0217D398(&config, ((struct Obj02221 *)q)->f34);
        (*state)++;
        break;
    case 1:
        func_0217D434((int *)(((struct Obj02221 *)q)->f38));
        if (func_0217D44C((int *)(((struct Obj02221 *)q)->f38))) (*state)++;
        break;
    case 2:
        func_0217D410((int *)(((struct Obj02221 *)q)->f38));
        func_021E8AA0((int *)p, (int)func_0217B4A0);
        break;
    }
}

void func_0217B620(int p, int *state, char *q)
{
    Config config;
    switch (*state) {
    case 0:
        func_02082BCC(&config, 0, 32);
        config.mode = 1;
        config.a = ((struct Obj02222 *)q)->f18;
        config.b = ((struct Obj02222 *)q)->f1C;
        config.c = ((struct Obj02222 *)q)->f20;
        config.d = ((struct Obj02222 *)q)->f24;
        config.e = ((struct Obj02222 *)q)->f28;
        config.f = ((struct Obj02222 *)q)->f2C;
        config.g = ((struct Obj02222 *)q)->f30;
        ((struct Obj02222 *)q)->f38 = func_0217D398(&config, ((struct Obj02222 *)q)->f34);
        (*state)++;
        break;
    case 1:
        func_0217D434((int *)(((struct Obj02222 *)q)->f38));
        if (func_0217D44C((int *)(((struct Obj02222 *)q)->f38))) (*state)++;
        break;
    case 2:
        func_0217D410((int *)(((struct Obj02222 *)q)->f38));
        func_021E8AA0((int *)p, (int)func_0217B6AC);
        break;
    }
}

void func_0217B6AC(int p,unsigned *state,int *q)
{
    unsigned result;
    switch (*state) {
    case 0: func_0217B93C(q,14); *state=1; break;
    case 1: if(func_0217B964(q)==1) *state=2; break;
    case 2: func_0217B7D8(q,2); *state=3; break;
    case 3:
        result=func_0217B930(q);
        if(result!=-1) {
            switch(result) {
            case 0:
                if(func_0202EB44()==0) func_021E8AA0((int *)p,(int)func_0217B7A0);
                else {func_0200B480(); func_0217B970(q,3);}
                break;
            case 1: func_021E8AA0((int *)p,(int)func_0217B768); break;
            case 2: func_021E8AA0((int *)p,(int)func_0217B620); break;
            case 3: func_021E8AA0((int *)p,(int)func_0217B3C0); break;
            }
            func_0217B924(q);
        }
        break;
    }
}

void func_0217B768(int *p,int *state,u8 *q) {switch(*state) {case 0:func_0217B93C((int *)q,15);*state=1;break;case 1:if(func_0217B964((int *)q)==1) func_021E8AA0(p,(int)func_0217B6AC);break;}}

void func_0217B7A0(int *p,int *state,u8 *q) {switch(*state) {case 0:func_0217B950((int *)q,22);*state=1;break;case 1:if(func_0217B964((int *)q)==1) func_021E8AA0(p,(int)func_0217B3C0);break;}}

static inline void selected(Menu *rec,void *base,int index)
{
    char *mon;
    mon=(char *)func_0200B1D4(base,index);
    rec->option0=7;
    rec->option1=5;
    if((u8)(s8)(((struct Obj24405 *)mon)->f15B-1)<=1) rec->f14=13;
    else rec->f14=4;
    rec->f18=6;
    rec->count=4;
    rec->f28=1;
    rec->f2c=3;
}

/*
 * extent: following 0217B924 and 0217B930 tail-call stubs already have separate matched shards; lead only.
 * lever: descriptor assignments in member order fix constant scheduling; coordinates are u8, height u32 with logical shift and no outgoing truncation.
 * abi: E88B0 height widened from its narrow body spelling because original stores the full computed register into the outgoing slot.
 */
void func_0217B7D8(int *p, int index)
{
    Menu rec;
    void *base;
    int layout;
    u8 x,y,width;
    u32 height;
    base=func_0200B358((void *)func_02012EBC(((struct Obj01762 *)p)->f30));
    func_02082BCC(&rec,0,48);
    rec.f00=((struct Obj01762 *)p)->f20;
    rec.f04=((struct Obj01762 *)p)->f1C;
    rec.f08=((struct Obj01762 *)p)->f24;
    switch(index) {
    case 0:
        rec.option0=2;rec.option1=3;rec.f14=5;rec.f18=6;rec.count=4;rec.f28=1;rec.f2c=3;layout=0;break;
    case 1: selected(&rec,base,0);layout=0;break;
    case 2: selected(&rec,base,1);layout=0;break;
    case 3:
        rec.option0=11;rec.option1=12;rec.count=2;layout=1;rec.f28=1;rec.f2c=1;break;
    }
    rec.f20=0;rec.f22=15;rec.f24=13;rec.f26=1;
    switch(layout) {
    case 0: width=28;height=(rec.count&127)*2;x=2;y=9-(height>>1);break;
    case 1: width=12;height=(rec.count&127)*2;x=19;y=17-height;break;
    }
    ((struct Obj01762 *)p)->f4=func_021E88B0(&rec,x,y,width,height,((struct Obj01762 *)p)->f34);
    ((struct Obj01762 *)p)->f8=index;
}

void func_0217B924(int *p) {func_021E89D0(p[1]);}

unsigned func_0217B930(int *p) {return func_021E8A00(p[1]);}


void func_0217B93C(int *p, int b)
{
    func_021E8738((int *)(*(int *)&((struct Obj01762 *)p)->f18), *(int *)&((struct Obj01762 *)p)->f20, b, 1);
}


void func_0217B950(int *p, int b)
{
    func_021E8738((int *)(*(int *)&((struct Obj01762 *)p)->f18), ((struct Obj01762 *)p)->fC, b, 1);
}

int func_0217B964(int *p) {return func_021E8844(*(int * *)&((struct Obj01762 *)p)->f18);}
