/*
 * file:     intro_cmd_p05.c
 * unit:     yes
 * function: func_021BF204, func_021BF228, func_021BF23C, func_021BF2D4, func_021BF2E0, func_021BF2F4, func_021BF374, func_021BF384, func_021BF4E8, func_021BF528, func_021BF538, func_021BF55C, func_021BF560, func_021BF580, func_021BF594, func_021BF5E0, func_021BF610, func_021BF624
 * address:  0x021BF204
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045C04 0x02045C04 arm
 *   func_02045B38 0x02045B38 arm
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0203630C  0x0203630C  arm
 *   func_02035C38  0x02035C38  arm
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F898 0x0201F898 thumb
 *   func_0201FF30 0x0201FF30 thumb
 *   func_02020CF8 0x02020CF8 thumb
 *   func_020409B4 0x020409B4 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02020D10 0x02020D10 thumb
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_020200CC 0x020200CC thumb
 *   func_020056BC 0x020056BC thumb
 *   func_0202EF98 0x0202EF98 thumb
 *   func_0202F038 0x0202F038 thumb
 *   site 0x021C0AF0 data ov204
 *   func_02030734 0x02030734 arm
 *   func_02016024 0x02016024 thumb
 *   func_02015BF0 0x02015BF0 thumb
 *   func_02015BA4 0x02015BA4 thumb
 *   func_02014BA8 0x02014BA8 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02014C08 0x02014C08 thumb
 *   func_02014D2C 0x02014D2C thumb
 *   defaultPos 0x021C08F0 data ov204
 *   func_021BF7F0 0x021BF7F0 thumb ov204
 *   func_02015CAC 0x02015CAC thumb
 */
#include "../../matched/include/Obj08384.h"
#include "../../matched/include/Obj14621.h"
#include "../../matched/include/Obj02540.h"
#include "../../matched/include/Obj25385.h"
#include "../../matched/include/Obj25386.h"
#include "../../matched/include/Obj03358.h"
#include "../../matched/include/Obj14622.h"
#include "../../matched/include/Obj10880.h"
#include "../../matched/include/Obj14623.h"
#include "../../matched/include/Obj14624.h"
#include "../../matched/include/Obj25387.h"
#include "../../matched/include/Obj25389.h"
#include "../../matched/include/Obj14625.h"
#include "../../matched/include/Obj01292.h"
#include "../../matched/include/Obj14626.h"
#include "../../matched/include/Obj14627.h"
#include "../../matched/include/Obj25390.h"

struct Rec;
struct MsgBank;
struct Tcbl;
struct PrintSys;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct WordSet;
struct Ctx;
struct Rec3;
struct Obj;
struct Slot;
struct Src;
struct McssSys;
struct Sub150;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed int     s32;

typedef signed char s8;

typedef signed short s16;

typedef struct {
    void *arr,*b,*c,*obj;
    u16 count,rows;
    u8 f14,f15,f16;
    u8 f17lo:4,f17hi:4;
    u8 f18lo:4,f18hi:4;
    u8 f19;
    u16 f1Alo:3,f1Amid:4,f1Apad:2,f1Amid2:6,f1Atop:1;
    u32 f1c;
    u16 f20,f22;
    u32 f24;
    void *f28,*f2c,*f30;
} Config;

struct Vec { int v[3]; };

extern unsigned int func_02045C04(struct Rec *rec);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_020310C4(struct Tcbl*);
extern u32 func_0201C4E4(struct PrintSys*);
extern signed char func_02012FFC(void);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(unsigned int, unsigned int, unsigned int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_0201CCE4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short, unsigned short);
extern void func_0201F73C(void *, int, int, int);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void func_0201F7A8(void*,u32);
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE38(void *p);
extern void func_020061E4(u32 a);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern unsigned int func_0203630C(void);
extern int func_02035C38(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void *func_02082BCC(void *,int,u32);
extern void *func_0201F81C(u32,u32);
extern void func_0201F898(struct Slot *table, u32 a, u32 b, u32 tag);
extern struct Obj *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);
extern void func_02020CF8(struct Obj *p, int heap);
extern void func_020409B4(u32 index);
extern void func_02020D10(u8 *p, u32 v);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern u32 func_0201F868(void *p);
extern int func_020200CC(struct Obj *);
extern u32 func_020056BC(void);
extern void func_0202EF98(u8 *,u32,u32,u8,u8);
extern void func_0202F038(u8 *);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern void *func_02014B08(u32 id, void *heap);
extern void func_02016020(void *, unsigned int);
extern void func_02016024(char *p, unsigned int v);
extern void func_02015BF0(void *);
extern void func_02015BA4(void *,void *);
extern void func_02014BA8(u8 *);
extern u32 func_020307B0(void *p);
extern void func_02014C08(char *);
extern void func_02014D2C(struct McssSys *);
extern struct Rec *func_020159C8(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);
extern void func_02015CAC(void *p, u32 *src);
extern void func_021BF7F0(u8 *p);
extern void func_02015F2C(void *, void *, void (*)(void *, void *), int);
void func_021BF204(char *p, void *a, void *b);
void func_021BF228(u8*p);
void func_021BF23C(char *p, void *a, int flag);
void func_021BF2D4(u8*p);
u32 func_021BF2E0(u8*p);
int func_021BF2F4(char *a);
int *func_021BF374(char *p, int v);
void func_021BF384(char *p,u32 *entries,u32 count,int flag);
void func_021BF4E8(char *p);
void func_021BF528(u8 *p);
int func_021BF538(u8 *p,int *out);
int func_021BF55C(u8 *p);
void func_021BF560(u8 *p);
void func_021BF580(u8 *p);
void *func_021BF594(unsigned int heap, int kind);
void func_021BF5E0(u8 *p);
void func_021BF610(u8 *p);
void func_021BF624(char *p, unsigned int a, unsigned int b, unsigned int c, void *d, unsigned char i);
extern const char site[];
extern const struct Vec defaultPos;


void func_021BF204(char *p, void *a, void *b)
{
    if (((struct Obj08384 *)p)->fC != 0)
    {
        func_02045C04(((struct Obj08384 *)p)->fC);
    }
    ((struct Obj08384 *)p)->fC = func_02045B38((u32)a, 2, (u32)b, ((struct Obj08384 *)p)->f0);
}

void func_021BF228(u8*p){func_020310C4(*(struct Tcbl* *)&((struct Obj14621 *)p)->f18);func_0201C4E4(*(struct PrintSys* *)&((struct Obj14621 *)p)->f4);}


/*
 * Caller consumes 0201CCE4's live r0 result; return declared pointer despite callee's void source.
 */
void func_021BF23C(char *p, void *a, int flag)
{
    unsigned int value = func_02012FFC();
    void *desc = ((struct Obj02540 *)p)->f1C;
    func_02043B5C(func_02045770(desc), 15);
    func_0201DD78(1, 2, 15);
    func_02045CAC(((struct Obj02540 *)p)->fC, (unsigned int)a, ((struct Obj02540 *)p)->f3C);
    func_0201F250(((struct Obj02540 *)p)->f8, ((struct Obj02540 *)p)->f40, ((struct Obj02540 *)p)->f3C);
    ((struct Obj02540 *)p)->f14 = func_0201CCE4((unsigned int)desc, 4, 0, *(unsigned int *)&((struct Obj02540 *)p)->f40, ((struct Obj02540 *)p)->f10, value, ((struct Obj02540 *)p)->f18, 0xFFFF, ((struct Obj02540 *)p)->f0, 15);
    if (flag == 0)
        func_0201F73C(desc, 1, 7, 9);
    else
        func_0201F73C(desc, 1, 16, 8);
    func_02045334(desc);
    func_02045374(desc);
    func_02041B6C(func_02045730(desc));
}

void func_021BF2D4(u8*p){func_0201F7A8(*(void* *)&((struct Obj25385 *)p)->f1C,0);}

u32 func_021BF2E0(u8*p){u32 a=((struct Obj25386 *)p)->f14;if(a==0){return 2;}else{return func_0201CE30((void *)a);}}


int func_021BF2F4(char *a)
{
    if (((struct Obj03358 *)a)->f14 != 0) {
        func_020286C4((struct Ctx *)(((struct Obj03358 *)a)->f20), (void *)(((struct Obj03358 *)a)->f14),
                      (void *)(((struct Obj03358 *)a)->f1C));

        switch (func_0201CE30((void *)(((struct Obj03358 *)a)->f14))) {
        case 2:
            func_0201CE48((struct Rec3 *)(((struct Obj03358 *)a)->f14));
            ((struct Obj03358 *)a)->f14 = 0;
            return 1;
        case 1:
            if (func_020362DC() == 1 || func_020362DC() == 2
                || func_02035C60() != 0) {
                func_0201CE38((void *)(((struct Obj03358 *)a)->f14));
                func_020061E4(0x547);
            }
            break;
        case 0:
            if ((func_0203630C() & 3) != 0 || func_02035C38() != 0)
                func_0201CE5C((struct Rec *)(((struct Obj03358 *)a)->f14), 0);
            break;
        }
        return 0;
    }
    return 0;
}


int *func_021BF374(char *p, int v)
{
    ((struct Obj14622 *)p)->f30 = v;
    ((struct Obj14622 *)p)->f34 = 0;
    return (int *)(p + 0x30);
}

/*
 * Owner unit_02045C44.c omits func_02045CAC from function:; singleton TU
 * --suggest-split leaves this caller out. Ilias owns that unit.
 * prior fixed-flag ARM9-45CAC.log, using the owner's unit declarations:
 * void func_02045CAC(struct MsgBank *bank, u32 index, void *dest) {
 *   u32 size; struct MsgEntry *e;
 *   if (index >= bank->file->count) { func_0204581C(dest); return; }
 *   func_02046180(bank);
 *   if (bank->resident == 0) {
 *     u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *     func_0204960C(bank->stream, pos + (index * 8 + 4));
 *     func_020495F4(bank->stream, 8, &bank->cache); e = &bank->cache;
 *   } else { e = (struct MsgEntry *)((u8 *)bank->base + 4) + index; }
 *   if (bank->resident == 0) {
 *     void *buf; size = e->len * 2;
 *     buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),
 *                       size, 0, g_020A7E8C, 0xd6);
 *     if (buf != 0) {
 *       func_0204960C(bank->stream, e->off + (bank->origin
 *                     + bank->file->langOff[bank->langIndex]));
 *       func_020495F4(bank->stream, size, buf);
 *       func_02045A00(dest, buf, e->len); func_020307B0(buf);
 *     }
 *   } else { func_02045A00(dest, (u8 *)bank->base + e->off, e->len); }
 *   func_02045E04(dest, index);
 * }
 * lever: u16 heap local places its word home at sp+8; u32 swaps it with
 * the entry pointer at sp+12, leaving seven differing concrete bytes.
 */
void func_021BF384(char *p,u32 *entries,u32 count,int flag)
{
    Config config;
    char *state;
    void *obj;
    u16 heap;
    u32 i;
    state=p+36;
    heap=*(u16 *)p;
    obj=*(void **)(p+56);
    func_02082BCC(state,0,12);
    *(void **)(state+4)=func_0201F81C(count,heap);
    for(i=0;i<count;i++){
        func_02045CAC(*(void **)(p+12),*(u32 *)((char *)entries+i*8),*(void **)(p+60));
        func_0201F898((struct Slot *)((char *)*(void **)(state+4)+i*8),*(u32 *)(p+60),*(u32 *)((char *)entries+i*8+4),heap);
    }
    func_02082BCC(&config,0,52);
    config.arr=*(void **)(state+4);config.obj=obj;
    config.count=count;config.rows=5;config.f14=0;config.f15=16;config.f16=0;
    config.f17lo=2;config.f17hi=1;config.f18lo=15;config.f18hi=2;
    config.f1Alo=0;config.f1Amid=0;config.f1Apad=1;config.f1Amid2=0;config.f1Atop=0;
    config.f1c=0;config.f20=16;config.f22=16;config.f24=0;
    config.f28=func_021BF374(p,(int)obj);config.f2c=*(void **)(p+4);config.f30=*(void **)(p+16);
    *(void **)state=func_0201FF30((struct Src *)(&config),0,0,heap);
    func_02020CF8(*(void **)state,(u32)heap);
    func_02045334(obj);func_02045374(obj);func_020409B4((u8)func_02045730(obj));
    func_0201F73C(obj,1,7,9);
    if(flag)func_02020D10(*(void **)state,0);
    else func_02020D10(*(void **)state,1);
}


/*
 * Trailing two bytes are zero alignment padding.
 */
void func_021BF4E8(char *p)
{
    char *block = p + 0x24;
    func_0201F7A8(((struct Obj10880 *)p)->f38, 0);
    func_02043B5C(func_02045770(((struct Obj10880 *)p)->f38), 0);
    func_02045334(((struct Obj10880 *)p)->f38);
    func_0202020C(((struct Obj14623 *)block)->f0, 0, 0);
    func_0201F868(((struct Obj14623 *)block)->f4);
    func_02082BCC(block, 0, 12);
}

void func_021BF528(u8 *p)
{
    u8 *q=p+36;
    ((struct Obj14624 *)q)->f8=func_020200CC(*(struct Obj * *)&((struct Obj14624 *)q)->f0);
}


/*
 * lever: A switch with -1 before -2 preserves the outlined return order.
 */
int func_021BF538(u8 *p,int *out)
{
    int v=((struct Obj25387 *)p)->f2C;
    switch(v){case -1:return 0;case -2:return 2;}
    if(out!=0)*out=v;
    return 1;
}


int func_021BF55C(u8 *p)
{
    return ((struct Obj25389 *)p)->f8;
}

void func_021BF560(u8 *p)
{
    func_0202EF98(*(u8 * *)&((struct Obj14625 *)p)->f44,func_020056BC(),((struct Obj14625 *)p)->f1C,15,16);
}

void func_021BF580(u8 *p)
{
    if(*(u8 * *)&((struct Obj01292 *)p)->f44!=0){func_0202F038(*(u8 * *)&((struct Obj01292 *)p)->f44);*(u8 * *)&((struct Obj01292 *)p)->f44=0;}
}


void *func_021BF594(unsigned int heap, int kind)
{
    char *p = func_02030734(heap, 108, 1, site, 98);
    *(void **)(p + 4) = func_02014B08(8, (void *)heap);
    *(unsigned short *)p = heap;
    if (kind != 7)
        func_02016020(*(void **)(p + 4), 7 << 16);
    func_02016024(*(void **)(p + 4), 1 << 14);
    func_02015BF0(*(void **)(p + 4));
    return p;
}

void func_021BF5E0(u8 *p)
{
    int i;
    for(i=0;i<8;i++)if(*(void **)((u32)p+(u32)i*12+8)!=0)func_02015BA4(((struct Obj14626 *)p)->f4,*(void **)((u32)p+(u32)i*12+8));
    func_02014BA8(*(u8 * *)&((struct Obj14626 *)p)->f4);
    func_020307B0(p);
}

void func_021BF610(u8 *p)
{
    func_02014C08(*(char * *)&((struct Obj14627 *)p)->f4);
    func_02014D2C(*(struct McssSys * *)&((struct Obj14627 *)p)->f4);
}


/*
 * Enum zero preserves the clear before the indexed base add.
 */
void func_021BF624(char *p, unsigned int a, unsigned int b, unsigned int c, void *d, unsigned char i)
{
    struct Vec pos = defaultPos;
    char *base = p + 8;
    unsigned int off = i * 12;
    enum { Zero } zero;
    *(void **)(base + off) = func_020159C8(((struct Obj25390 *)p)->f4, a, b, c, d);
    func_02015CAC(*(void **)(base + off), (u32 *)(&pos));
    zero = Zero;
    *(unsigned int *)(p + off + 12) = zero;
    *(unsigned int *)(p + off + 16) = 1;
    func_02015F2C(*(void **)(base + off), base + off, (void (*)(void *, void *))func_021BF7F0, 0);
}
