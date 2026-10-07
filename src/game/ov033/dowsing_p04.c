/*
 * file:     dowsing_p04.c
 * unit:     yes
 * function: func_021F08EC, func_021F0924, func_021F0A90, func_021F0AC4, func_021F0B74, func_021F0C0C
 * address:  0x021F08EC
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02024A20 0x02024A20 thumb
 *   func_020275E4 0x020275E4 thumb
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_020410D0 0x020410D0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020307B0 0x020307B0 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B954 0x0204B954 arm
 *   func_0204B878 0x0204B878 arm
 *   func_02049238 0x02049238 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_02024DCC 0x02024DCC thumb
 *   func_02035D20 0x02035D20 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020362DC 0x020362DC arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B98C 0x0204B98C arm
 *   func_021A0F30 0x021A0F30 thumb ov021
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030734 0x02030734 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_02021518 0x02021518 thumb
 *   func_02021EE4 0x02021EE4 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 *   d_021F0E60 0x021F0E60 data ov033 a1
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_02030DA4 0x02030DA4 arm
 */
#include "../../matched/include/Obj09803.h"
#include "../../matched/include/Obj20476.h"
#include "../../matched/include/Obj06143.h"
#include "../../matched/include/Obj01512.h"
#include "../../matched/include/Obj06144.h"

struct Obj;
struct Actor;
struct Ctx;
struct Obj02021EE4;
struct PalAnmSlot;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

struct Scr {
    u8 pad00[0xC];
    u16 data[0x300];
};

typedef struct {
    u16 heap;
    u16 heap2;
    u8 pad4[0x4];
    u32 f8;
    u32 fC;
    u8 pad10[0x4];
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    u32 f28;
} Obj;

typedef signed int     s32;

typedef struct {
    unsigned f00;
    unsigned f04;
    char pad[0x1C];
    unsigned f24;
    unsigned f28;
} T;

extern void func_0204B3B4(struct Obj *p);
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern void func_02024A20(u8 a0, u8 a1, void *a2, u16 heap);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void *func_02049EF4(void *o, u32 a, u32 b, void **out, u16 e);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02041B6C(u32 bit);
extern u32 func_020307B0(void *p);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B954(struct Actor *a, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_02049238(void *);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern int func_02024DCC(void);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
extern void func_020061E4(unsigned);
extern u32 func_0204B98C(struct Actor *a);
extern int func_021A0F30(u32 a, u32 b);
extern unsigned func_02030CB0(unsigned);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void *func_02021518(u32 heap);
extern void func_02021EE4(struct Obj02021EE4 *o, int v);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern void func_02030DA4(void *);
void func_021F08EC(char *p);
void func_021F0924(Obj *p);
void func_021F0A90(char *p);
void func_021F0AC4(T *p);
void func_021F0B74(char *p);
void func_021F0C0C(char *p);
extern const char d_021F0E60[];

void func_021F08EC(char *p) { unsigned char i; char *q; for(i=0;i<4;i++) { q=p+i*12; func_0204B3B4((struct Obj *)(((struct Obj09803 *)q)->f38)); if(i!=1) { func_0204AFD8(((struct Obj09803 *)q)->f34); func_0204A8D4(((struct Obj09803 *)q)->f30); } } func_0204ADA4(((struct Obj20476 *)p)->f2C); }


/*
 * note:     the four `strh #0` after func_02024A20 are `Local s = {0};`
 *           opening an inner block there; declared at the top they land
 *           before the first call.
 */
void func_021F0924(Obj *p)
{
    struct Scr *ptr;
    u32 heap2;

    heap2 = p->heap2;
    func_02024A20(4, 3, func_020120F4(func_02188C80((void *)p->f8)), p->heap);
    {
        Local s = {0};
        void *h;
        void *arc;
        u16 *d;
        u16 i;
        u16 base;

        arc = func_020490F4(func_020275E4(), heap2);
        func_02049B68(arc, func_02027624(), 4, 0x40, 0x20, heap2);
        p->f14 = func_02049740(arc, func_02027628(), 4, 0, 0, heap2);
        h = func_02049EF4(arc, func_0202762C(), 0, (void **)&ptr, heap2);
        base = p->f14;
        d = ptr->data;
        for (i = 0; i < 0x300; i++) {
            d[i] &= 0xFFF;
            d[i] = (base + d[i]) | 0x2000;
        }
        func_020410D0(4, 0, 0x15, 0x20, 3, (u32)ptr->data, 0, 0x15, 0x20, 0x18);
        func_02041B6C(4);
        func_020307B0(h);
        p->f18 = func_0204AC18(arc, func_02027614(), 1, 0x20, 0, 3, p->heap);
        p->f1C = func_0204A6C8(arc, func_02027618(), 0, 1, p->heap);
        p->f20 = func_0204AF28(arc, func_0202761C(0), func_02027620(0), p->heap);
        s.a = 0xE8;
        s.b = 0xA8;
        p->f24 = (u32)func_0204B294((void *)p->fC, p->f1C, p->f18, p->f20, &s, 1, p->heap);
        func_0204B92C((struct Obj *)p->f24, 1);
        func_0204B954((struct Actor *)p->f24, 0x2000);
        func_0204B878((struct Obj *)p->f24, 0);
        func_02049238(arc);
        p->f28 = 0;
    }
}

void func_021F0A90(char *p) { unsigned v; func_0204B3B4((struct Obj *)(((struct Obj06143 *)p)->f24)); func_0204AFD8(((struct Obj06143 *)p)->f20); func_0204A8D4(((struct Obj06143 *)p)->f1C); func_0204ADA4(((struct Obj06143 *)p)->f18); v=((struct Obj06143 *)p)->f14; func_0203FB44(4,(unsigned short)v,(unsigned short)(v>>16)); func_02024DCC(); }


void func_021F0AC4(T *p)
{
    unsigned x;
    unsigned y;
    int hit;

    switch (p->f28) {
    case 0:
        hit = 0;
        if (func_02035D20(&x, &y) != 0) {
            if (x >= 0xE8 && x < 0x100 && y >= 0xA8 && y < 0xC0) {
                func_020355D8(1);
                hit = 1;
            }
        }
        if (hit == 0) {
            if (func_020362DC() & 0x400) {
                func_020355D8(0);
                hit = 1;
            }
        }
        if (hit != 0) {
            p->f28 = 1;
            func_0204B878((struct Obj *)p->f24, 8);
            func_020061E4(0x556);
            return;
        }
        break;
    case 1:
        if (func_0204B98C((struct Actor *)p->f24) == 0) {
            p->f28 = 2;
            func_0204B878((struct Obj *)p->f24, 0);
            return;
        }
        break;
    case 2:
        func_021A0F30(p->f04, 0);
        p->f28 = 3;
        break;
    case 3:
        break;
    }
}


/*
 * note:     func_02030CBC takes (n, mem) (sub_0200545C): the 0xB8 result
 *           left in r1 before `blx func_02030CBC` is its second argument.
 */
void func_021F0B74(char *p)
{
    ((struct Obj01512 *)p)->fB8 = func_02030734(((struct Obj01512 *)p)->f0, func_02030CB0(2), 1, d_021F0E60, 0x6DF);
    ((struct Obj01512 *)p)->fB4 = func_02030CBC(2, ((struct Obj01512 *)p)->fB8);
    ((struct Obj01512 *)p)->fBC = (unsigned int)func_02021518(((struct Obj01512 *)p)->f0);
    func_02021EE4((struct Obj02021EE4 *)(((struct Obj01512 *)p)->fBC), 1);
    func_0202155C((struct PalAnmSlot *)(((struct Obj01512 *)p)->fBC), 1, 0x60, ((struct Obj01512 *)p)->f0);
    func_0202155C((struct PalAnmSlot *)(((struct Obj01512 *)p)->fBC), 3, 0x80, ((struct Obj01512 *)p)->f0);
    func_020216D4((struct PalAnmSlot *)(((struct Obj01512 *)p)->fBC), 1, 0, 0x60);
    func_020216D4((struct PalAnmSlot *)(((struct Obj01512 *)p)->fBC), 3, 0, 0x80);
    ((struct Obj01512 *)p)->fC0 = 0;
    ((struct Obj01512 *)p)->fC4 = 0;
}

void func_021F0C0C(char *p) { func_020215A0(((struct Obj06144 *)p)->fBC,1); func_020215A0(((struct Obj06144 *)p)->fBC,3); func_02021540(((struct Obj06144 *)p)->fBC); func_02030DA4(((struct Obj06144 *)p)->fB4); func_020307B0(((struct Obj06144 *)p)->fB8); }
