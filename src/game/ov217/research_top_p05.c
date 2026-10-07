/*
 * file:     research_top_p05.c
 * unit:     yes
 * function: func_021BA1D4, func_021BA1F8, func_021BA228, func_021BA254, func_021BA284, func_021BA2BC, func_021BA2FC, func_021BA31C, func_021BA328, func_021BA354, func_021BA364, func_021BA374, func_021BA37C, func_021BA380, func_021BA384
 * address:  0x021BA1D4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020270E0  0x020270E0  thumb
 *   func_021BA388  0x021BA388  thumb  ov217
 *   func_021BA3E8  0x021BA3E8  thumb  ov217
 *   func_021BA3B0  0x021BA3B0  thumb  ov217
 *   func_021C1038  0x021C1038  thumb  ov217
 *   func_021C09D8  0x021C09D8  thumb  ov217
 *   func_021BA3E0  0x021BA3E0  thumb  ov217
 */
#include "../../matched/include/Obj00511.h"
#include "../../matched/include/Obj25815.h"
#include "../../matched/include/Obj25816.h"
#include "../../matched/include/Obj25818.h"
#include "../../matched/include/Obj25819.h"
#include "../../matched/include/Obj25820.h"

struct Obj;
struct Actor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

extern u8 func_020270E0(void);
extern void func_020061E4(u32 a);
extern void func_021BA388(char *self, int d);
extern u32 func_021BA3E8();
extern void func_021BA3B0(void *p, u32 v);
extern void func_020413B0(int, int, int, int, int, int);
extern void func_020409B4(u32 index);
extern void func_021C1038(u8 *p, u8 palette);
extern void func_021C09D8(u8 *p, u32 i);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern u32 func_0204B8C4();
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern void func_0204B954(struct Actor *a, u32 v);
extern u32 func_021BA3E0(void *p, u32 i);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
void func_021BA1D4(u32 a0);
u32 func_021BA1F8(u32 a0);
u32 func_021BA228(u32 a0);
u32 func_021BA254(u32 a0, u32 a1);
void func_021BA284(int sel);
void func_021BA2BC(int sel);
u32 func_021BA2FC(u32 a0);
void func_021BA31C(u8 *a0);
u32 func_021BA328(u32 a0);
void func_021BA354(void);
void func_021BA364(void);
void func_021BA374(void *p);
u32 func_021BA37C(void *p);
void func_021BA380(void *p, u32 v);
u32 func_021BA384(void *p);

/*
 * One-shot latch on the +0x84 field.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA1D4(u32 a0)
{
    if (((struct Obj00511 *)((u8*)a0))->f84 == 0) {
    if (func_020270E0() == 1) {
    ((struct Obj00511 *)((u8*)a0))->f84 = 1;
    func_021BA328(a0);
    }
    }
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BA1F8(u32 a0)
{
    func_021BA2BC(((struct Obj00511 *)(((u8*)a0)))->f28);
    func_021BA388((char *)a0, -1);
    func_021BA284(((struct Obj00511 *)(((u8*)a0)))->f28);
    func_020061E4(1352);
    return func_021BA3E8(a0, 1);
}

u32 func_021BA228(u32 a0)
{
    func_021BA2BC(((struct Obj00511 *)(((u8*)a0)))->f28);
    func_021BA388((char *)a0, 1);
    func_021BA284(((struct Obj00511 *)(((u8*)a0)))->f28);
    func_020061E4(1352);
    return func_021BA3E8(a0, 1);
}

u32 func_021BA254(u32 a0, u32 a1)
{
    func_021BA2BC(((struct Obj00511 *)(((u8*)a0)))->f28);
    func_021BA3B0((void *)a0, a1);
    func_021BA284(((struct Obj00511 *)(((u8*)a0)))->f28);
    func_020061E4(1352);
    return func_021BA3E8(a0, 1);
}


void func_021BA284(int sel)
{
    int a, b, c, d, e, f;
    switch (sel) {
    case 0:
        a = 2; b = 3; c = 5; d = 0x1a; e = 5; f = 0xa;
        break;
    case 1:
        a = 2; b = 3; c = 0xc; d = 0x1a; e = 5; f = 0xa;
        break;
    default:
        return;
    }
    func_020413B0(a, b, c, d, e, f);
    func_020409B4(a);
}


void func_021BA2BC(int sel)
{
    int a, b, c, d, e, f;
    switch (sel) {
    case 0:
        a = 2; b = 3; c = 5; d = 0x1a; e = 5; f = 5;
        break;
    case 1:
        a = 2; b = 3; c = 0xc; d = 0x1a; e = 5; f = 6;
        break;
    default:
        return;
    }
    func_020413B0(a, b, c, d, e, f);
    func_020409B4(a);
}

u32 func_021BA2FC(u32 a0)
{
    func_021C1038((u8 *)(((struct Obj25815 *)(((u8*)a0)))->f54), 15);
    func_021BA3E8(a0, 3);
    return func_021BA3E8(a0, 4);
}

void func_021BA31C(u8 *a0)
{
    func_021C09D8((u8 *)(((struct Obj25816 *)((u8*)a0))->f0), 0);
}

u32 func_021BA328(u32 a0)
{
    u32 v1 = func_021BA3E0((void *)a0, 0);
    func_0204B3DC((struct Obj *)v1, 1);
    func_0204B92C((struct Obj *)v1, 1);
    func_0204B954((struct Actor *)v1, 4096);
    return func_0204B8C4(v1, 0);
}

void func_021BA354(void)
{
    func_0204E720(3, 0x10, 0, 0);
}

/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA364(void)
{
    func_0204E720(3, 0, 16, 0);
}


void func_021BA374(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x20);
    *c += 1;
}


u32 func_021BA37C(void *p)
{
    return ((struct Obj25818 *)p)->f20;
}


/*
 * Field setter, u32 at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA380(void *p, u32 v)
{
    ((struct Obj25819 *)p)->f24 = v;
}


u32 func_021BA384(void *p)
{
    return ((struct Obj25820 *)p)->f24;
}
