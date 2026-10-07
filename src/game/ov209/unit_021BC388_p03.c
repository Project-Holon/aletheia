/*
 * file:     unit_021BC388_p03.c
 * unit:     yes
 * function: func_021BD3E0, func_021BD3FC, func_021BD440, func_021BD488, func_021BD4DC, func_021BD4F4, func_021BD5D4, func_021BD628, func_021BD704, func_021BD75C, func_021BD7F8, func_021BD824, func_021BD838, func_021BD86C, func_021BD890, func_021BD8B0, func_021BD8C4, func_021BD8D8, func_021BD8F4
 * address:  0x021BD3E0
 * region:   ov209
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_0201F250 0x0201F250 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045748 0x02045748 arm
 *   func_02045750 0x02045750 arm
 *   func_02045758 0x02045758 arm
 *   func_02045760 0x02045760 arm
 *   func_020437D4 0x020437D4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_02049DF4 0x02049DF4 arm
 *   func_02049238 0x02049238 arm
 *   func_02082A90 0x02082A90 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0200CA70 0x0200CA70 thumb
 *   func_0200D0CC 0x0200D0CC thumb
 *   func_0200CF28 0x0200CF28 thumb
 *   func_0200D0F8 0x0200D0F8 thumb
 *   func_0200CF54 0x0200CF54 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_021B9394 0x021B9394 thumb ov067
 *   func_021BD984 0x021BD984 thumb ov209
 *   func_021BD9B4 0x021BD9B4 thumb ov209
 *   func_021BDC08 0x021BDC08 thumb ov209
 *   func_021BE010 0x021BE010 thumb ov209
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_021BDD5C 0x021BDD5C thumb
 *   func_021BDBA8 0x021BDBA8 thumb
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204B944 0x0204B944 arm
 *   func_0204B8D4 0x0204B8D4 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3F4 0x0204B3F4 arm
 */
#include "../../matched/include/Obj08409.h"
#include "../../matched/include/Obj00123.h"
#include "../../matched/include/Obj25560.h"
#include "../../matched/include/Obj25561.h"
#include "../../matched/include/Obj25562.h"
#include "../../matched/include/Obj25563.h"
#include "../../matched/include/Obj25564.h"
#include "../../matched/include/Obj25565.h"
#include "../../matched/include/Obj25566.h"
#include "../../matched/include/Obj02924.h"
#include "../../matched/include/Obj25567.h"

struct Descriptor;
struct PrintSys;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Cfg;
struct Bmp;
struct Blk37;
struct R;
struct Actor;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Context { char pad[72]; int ps; };

typedef struct WordSet WordSet;

extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern unsigned func_0201C4E4(struct PrintSys *);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
extern void *func_02045EC0(struct MsgBank *, unsigned);
extern void func_02045808(struct U16Vec *);
extern void func_021B6AE4(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern void func_0201F250(struct WordSet *, void *, void *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(u32);
extern u8 func_02045748(struct Descriptor *p);
extern u8 func_02045750(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern void *func_020437D4(const struct Bmp *bmp);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02049EF4(void *, u32, u32, void **, u16);
extern void *func_02049DF4(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02049238(void *h);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern u32 func_020307B0(void *p);
extern u32 func_0200CA70(struct Blk37 *p);
extern u16 func_0200D0CC(struct Blk37 *p);
extern u16 func_0200CF28(struct Blk37 *p);
extern u16 func_0200D0F8(struct Blk37 *p, u32 heap);
extern u16 func_0200CF54(struct Blk37 *p, u32 heap);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern unsigned func_021B9394(char *);
extern void func_021BD984(char *);
extern void func_021BD9B4(struct R *p);
extern void func_021BDC08(char *);
extern void func_021BE010(char *);
extern void func_020434DC(u32,u32),func_02043598(u32,u32);
extern void func_021BDD5C(char *p);
extern void func_021BDBA8(char *p);
extern void func_0204A5AC(void);
extern u32 func_0204B944(struct Actor *);
extern void func_0204B8D4(struct Obj *,u32);
extern void func_0204A600(void);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *,unsigned int);
extern u16 func_0204B898(struct Obj *p);
extern u32 func_0204B98C(struct Actor *);
extern void func_0204B3DC(struct Obj *,u32);
extern u32 func_0204B3F4(struct Obj *);
void func_021BD3E0(char *p);
void func_021BD3FC(const struct Context *p);
void func_021BD440(char *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode);
void func_021BD488(char *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode);
void func_021BD4DC(void **p);
void func_021BD4F4(u8 *p, u32 idx);
void func_021BD5D4(char *p);
void func_021BD628(char *p);
void func_021BD704(char *p);
void func_021BD75C(char *p, unsigned char *dest, unsigned text0, unsigned index);
void func_021BD7F8(char *p);
void func_021BD824(char *a);
void func_021BD838(char *p);
void func_021BD86C(char *p, int idx, int v);
void func_021BD890(char *p,int idx,int value);
int func_021BD8B0(char *a, int b);
u32 func_021BD8C4(char *p,u32 idx);
void func_021BD8D8(char *p,u32 idx,u32 value);
u32 func_021BD8F4(char *p,u32 idx);

void func_021BD3E0(char *p) { u32 i;for(i=0;i<3;i++)func_020452E8(*(struct Descriptor **)((u32)p+i*8+32));func_020450C8(); }

/*
 * extent: 021BD43E..021BD440 is two zero alignment bytes before matched D440.
 * lever: first types search hoisted the initialized full-word ps load before entry arithmetic.
 * checks: 1 own C4E4, C6C4, 45770, 45334 bodies prove 1/2/1/1 arity; 2 ov0679344 and ov208C0740 confirm full-word handles; 3 carried two compiles exhausted; 4 carried two order/extraction probes exhausted; 5 fresh idioms/neighbours read, no stack object. Wave32 I4 pointer ps unchanged5; types search9 candidates exact after ps hoist, all inputs and call/store order preserved.
 */
void func_021BD3FC(const struct Context *p)
{
    int ps;
    long i;
    char *entry;
    func_0201C4E4((struct PrintSys *)p->ps);
    for (i = 0; i < 3u; i++) {
        ps = p->ps;
        entry = (char *)p + i * 8;
        if (((struct Obj08409 *)entry)->f24) {
            if (func_0201C6C4((struct PrintSys *)ps, func_02045770(*(struct Descriptor * *)&((struct Obj08409 *)entry)->f20)) == 0) {
                func_02045334(*(struct Descriptor * *)&((struct Obj08409 *)entry)->f20);
                ((struct Obj08409 *)entry)->f24 = 0;
            }
        }
    }
}

/*
 * extent: 021BD486 two-byte alignment padding before 021BD488.
 */
void func_021BD440(char *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode)
{
    void *text;
    text = func_02045EC0(*(struct MsgBank * *)&((struct Obj00123 *)p)->f3C, msg);
    func_021B6AE4((unsigned char *)(p + 32 + index * 8), (void *)(((struct Obj00123 *)p)->f48), x, y, (unsigned)text, *(unsigned *)&((struct Obj00123 *)p)->f38, color, mode);
    func_02045808(text);
}

/*
 * extent: 021BD4DA two-byte alignment padding before existing labelled 021BD4DC.
 */
void func_021BD488(char *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode)
{
    void *text;
    text = func_02045EC0(*(struct MsgBank * *)&((struct Obj00123 *)p)->f3C, msg);
    func_0201F250(*(struct WordSet * *)&((struct Obj00123 *)p)->f40, ((struct Obj00123 *)p)->f44, text);
    func_021B6AE4((unsigned char *)(p + 32 + index * 8), (void *)(((struct Obj00123 *)p)->f48), x, y, *(unsigned *)&((struct Obj00123 *)p)->f44, *(unsigned *)&((struct Obj00123 *)p)->f38, color, mode);
    func_02045808(text);
}

void func_021BD4DC(void **p) {func_02045374(*p);func_02041B6C(func_02045730(*p));}


void func_021BD4F4(u8 *p, u32 idx)
{
    void *o2;
    void *o1;
    void *t2;
    u8 *gfx;
    void *t1;
    u8 *dst;
    u16 j;
    u8 *row;
    int y;
    int h;
    u8 w;
    int x;
    u8 *map;
    struct Descriptor **ent = (struct Descriptor **)(p + 0x20);
    void *arc;
    u16 i;

    w = func_02045748(*(struct Descriptor **)((u8 *)ent + idx * 8));
    h = func_02045750(*(struct Descriptor **)((u8 *)ent + idx * 8));
    x = func_02045758(*(struct Descriptor **)((u8 *)ent + idx * 8));
    y = func_02045760(*(struct Descriptor **)((u8 *)ent + idx * 8));
    dst = func_020437D4(func_02045770(*(struct Descriptor **)((u8 *)ent + idx * 8)));
    arc = func_020490F4(0x9F, 0x6B);
    t1 = func_02049EF4(arc, 0x45, 0, &o1, 0x806B);
    map = (u8 *)o1 + 0xC;
    t2 = func_02049DF4(arc, 0x39, 0, (u32)(&o2), 0x806B);
    gfx = *(u8 **)((u8 *)o2 + 0x14);
    func_02049238(arc);
    if (h > 0) {
        row = map + x * 2;
        j = 0;
        do {
            for (i = 0; i < w; i++) {
                u16 c = *(u16 *)(row + (y + j) * 64 + i * 2);
                func_02082A90(gfx + (c & 0x3FF) * 32, dst + (i + j * w) * 32, 0x20);
            }
            j++;
        } while (j < h);
    }
    func_020307B0(t2);
    func_020307B0(t1);
}

void func_021BD5D4(char *p)
{
    func_021BD4F4((u8 *)p, 0);
    if (func_0200CA70(((struct Obj25560 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4) == 1)
        func_021BD440(p, 0, 1, 0, 4, 0x39e0, 0);
    else
        func_021BD440(p, 0, 0, 0, 4, 0x39e0, 0);
    func_021BD4DC((void **)(p + 32));
}

void func_021BD628(char *p)
{
    unsigned a, b;
    if (func_0200CA70(((struct Obj25561 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4) == 1) {
        a = func_0200D0CC(((struct Obj25562 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4);
        b = func_0200CF28(((struct Obj25563 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4);
    } else {
        a = func_0200D0F8(((struct Obj25564 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4, 0x806b);
        b = func_0200CF54(((struct Obj25565 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4, 0x806b);
    }
    func_021BD4F4((u8 *)p, 1);
    func_021BD4F4((u8 *)p, 2);
    func_021BD440(p, 1, 2, 0x48, 4, 0x31a0, 1);
    func_0201EFA4(*(WordSet * *)&((struct Obj00123 *)p)->f40, 0, a, 3, 0, 1);
    func_021BD488(p, 1, 5, 0x68, 4, 0x31a0, 1);
    func_021BD440(p, 2, 3, 0x58, 4, 0x31a0, 1);
    func_0201EFA4(*(WordSet * *)&((struct Obj00123 *)p)->f40, 0, b, 3, 0, 1);
    func_021BD488(p, 2, 5, 0x78, 4, 0x31a0, 1);
    func_021BD4DC((void **)(p + 0x28));
    func_021BD4DC((void **)(p + 0x30));
}

void func_021BD704(char *p)
{
    func_021BD4F4((u8 *)p, 2);
    func_021BD440(p, 2, 4, 88, 4, 0x31a0, 1);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj00123 *)p)->f40, 0, ((struct Obj25566 *)(*(char * *)&((struct Obj00123 *)p)->f0))->fA, 3, 0, 1);
    func_021BD488(p, 2, 5, 120, 4, 0x31a0, 1);
    func_021BD4DC((void **)(p + 48));
}

void func_021BD75C(char *p, unsigned char *dest, unsigned text0, unsigned index)
{
    unsigned ps;
    void *text;
    ps = func_021B9394(*(char * *)&((struct Obj02924 *)p)->fC2C);
    if (func_0200CA70(*(struct Blk37 * *)&((struct Obj25567 *)(*(char * *)&((struct Obj02924 *)p)->f0))->f4) == 0)
        index = (*(u16 **)(p + 0xc38))[index];
    text = func_02045EC0(*(struct MsgBank * *)&((struct Obj02924 *)p)->f3C, 8);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj02924 *)p)->f40, 0, index, 3, 2, 1);
    func_0201F250(*(struct WordSet * *)&((struct Obj02924 *)p)->f40, ((struct Obj02924 *)p)->f44, text);
    func_02045808(text);
    func_021B6AE4(dest, (void *)ps, 0, 4, *(unsigned *)&((struct Obj02924 *)p)->f44, ((struct Obj02924 *)p)->f38, 0x39e0, 0);
    func_021B6AE4(dest, (void *)ps, 28, 4, text0, ((struct Obj02924 *)p)->f38, 0x39e0, 0);
}

void func_021BD7F8(char *p) {func_021BD984(p);func_021BD9B4((struct R *)p);func_021BDC08(p);func_021BE010(p);func_020434DC(16,1);func_02043598(16,1);}


void func_021BD824(char *a)
{
    func_021BDD5C(a);
    func_021BDBA8(a);
    func_0204A5AC();
}

void func_021BD838(char *p) {u32 i;for(i=0;i<60;i++) {if(*(void **)(p+i*4+0xa74)) {if(func_0204B944(*(struct Actor **)(p+i*4+0xa74))!=1) func_0204B8D4(*(struct Obj **)(p+i*4+0xa74),0x1000);}}func_0204A600();}


void func_021BD86C(char *p, int idx, int v)
{
    func_0204B8C4(*(void **)(p + 0xa74 + idx * 4), 0);
    func_0204B878(*(void **)(p + 0xa74 + idx * 4), (unsigned short)v);
}

void func_021BD890(char *p,int idx,int value) {func_021BD86C(p,idx,value);func_0204B92C((struct Obj *)*(struct Actor **)(p+idx*4+0xa74),1);}


int func_021BD8B0(char *a, int b)
{
    return func_0204B898((struct Obj *)(*(int *)(a + b * 4 + 0xa74)));
}

u32 func_021BD8C4(char *p,u32 idx) {return func_0204B98C(*(struct Actor **)(p+idx*4+0xa74));}

void func_021BD8D8(char *p,u32 idx,u32 value) {struct Obj *o;o=*(struct Obj **)(p+idx*4+0xa74);if(o) func_0204B3DC(o,value);}

u32 func_021BD8F4(char *p,u32 idx) {return func_0204B3F4(*(struct Obj **)(p+idx*4+0xa74));}
