/*
 * file:     palette_anime_p10.c
 * unit:     yes
 * function: func_021C2260, func_021C2288, func_021C253C, func_021C2550, func_021C256C, func_021C25A8, func_021C25B0, func_021C25C4, func_021C25D0, func_021C2614
 * address:  0x021C2260
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
 *   _ffixu  0x0209C4C8  arm
 *   _fadd   0x0209C95C  arm
 *   _fsub   0x0209CB8C  arm
 *   _fmul   0x0209C77C  arm
 *   _fdiv   0x0209CE10  arm
 *   _fflt   0x0209BDBC  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3B4  0x0204B3B4  arm
 */
#include "../../matched/include/Obj26021.h"
#include "../../matched/include/Obj04642.h"
#include "../../matched/include/Obj03378.h"
#include "../../matched/include/Obj04643.h"
#include "../../matched/include/Obj26022.h"
#include "../../matched/include/Obj08444.h"

struct Obj;
struct Bank;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

struct Arg { u16 a,b,c; u8 d,e; };

extern void func_0204B3DC(struct Obj *a, unsigned int b);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern u32 func_0204B1CC(struct Bank *bank);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3B4(struct Obj *p);
void func_021C2260(void *p);
void func_021C2288(u8 *p, int a, int b, int c, int d);
void func_021C253C(void *p, u8 a, u8 b, u32 c, u32 d);
u32 func_021C2550(u32 a0);
void func_021C256C(void *p, u16 v);
u32 func_021C25A8(void *a0);
void func_021C25B0(u8 *p);
void func_021C25C4(u8 *a0);
void func_021C25D0(u8 *p);
void func_021C2614(char *p);


void func_021C2260(void *p)
{
    s32 i;
    s32 n = ((struct Obj26021 *)p)->f298;
    for (i = 0; i < n; i++)
        func_0204B3DC((struct Obj *)*(u32 *)((char *)p + 0x3c + i * 0x18), 0);
}


/*
 * Element i of a 0x18-byte array at p+0x28; the half==0 flag stores are
 * written through that element base (p + 0x28 + i*0x18 + 8 / + 0xc). Colours
 * come from f += 1.0f (f first in _fadd), i declared before f with i = 0 as a
 * statement, half2 declared before w2, and y += 8 before f += 1.0f.
 * EXACT* = 690 bytes compiled, listing extent 692 (trailing pad).
 */
void func_021C2288(u8 *p, int a, int b, int c, int d)
{
    int i;
    float f = 0.0f;
    int j;
    int yb;
    int w = a - c;
    int half = (w - 4) / 8;
    int half2;
    int w2;
    int xx;
    int y;
    int r;

    i = 0;
    yb = b - 4;
    a -= 8;

    for (j = 0; j < half; j++) {
        func_021C253C(p + 0x28 + i * 0x18, a, yb, (u32)f, 0);
        a -= 8;
        f += 1.0f;
        i++;
    }
    if (half == 0) {
        if (w - 4 > 0) {
            func_021C253C(p + 0x28 + i * 0x18, a, yb, (u32)f, 0);
            if (w - 4 < 4) {
                *(u32 *)(p + 0x28 + i * 0x18 + 8) = 1;
                *(u16 *)(p + 0x28 + i * 0x18 + 0xc) = 1;
            }
            f = f + (2.0f * (float)(w - 4) / 8.0f - 1.0f);
            i++;
        }
    } else if ((w - 4) % 8 != 0) {
        r = (w - 4) - half * 8;
        f = f - (2.0f - 2.0f * (float)r / 8.0f);
        func_021C253C(p + 0x28 + i * 0x18, c + 4, yb, (u32)f, 0);
        f += 1.0f;
        i++;
    }
    func_021C253C(p + 0x28 + i * 0x18, c - 4, b - 4, (u32)f, 2);
    f += 1.0f;
    i++;
    w2 = d - b;
    half2 = (w2 - 4) / 8;
    xx = c - 4;
    y = b + 4;
    for (j = 0; j < half2; j++) {
        func_021C253C(p + 0x28 + i * 0x18, xx, y, (u32)f, 1);
        y += 8;
        f += 1.0f;
        i++;
    }
    if ((w2 - 4) % 8 != 0) {
        r = (w2 - 4) - half2 * 8;
        f = f - (2.0f - 2.0f * (float)r / 8.0f);
        func_021C253C(p + 0x28 + i * 0x18, xx, d - 8, (u32)f, 1);
        f += 1.0f;
        i++;
    }
    func_021C253C(p + 0x28 + i * 0x18, c - 4, d - 4, (u32)f, 3);
    p[0x298] = i + 1;
}


/*
 * Initialise the header: two mode bytes, two u16 fields, three cleared words.
 *
 * Addresses are Black-image addresses.
 */
void func_021C253C(void *p, u8 a, u8 b, u32 c, u32 d)
{
    ((struct Obj04642 *)p)->fE = a;
    ((struct Obj04642 *)p)->f0 = 0;
    ((struct Obj04642 *)p)->f8 = 0;
    ((struct Obj04642 *)p)->fC = 0;
    ((struct Obj04642 *)p)->fF = b;
    ((struct Obj04642 *)p)->f4 = c;
    ((struct Obj04642 *)p)->f10 = d;
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C2550(u32 a0)
{
    return (u32)func_02030734(a0, 668, 0, (const char *)0x21C4074, 558);
}


/*
 * Initialise the container and clear its 0x1a 0x18-byte records.
 *
 * Addresses are Black-image addresses.
 */
void func_021C256C(void *p, u16 v)
{
    int i;
    ((struct Obj03378 *)p)->f0 = v;
    ((struct Obj03378 *)p)->f20 = 0;
    ((struct Obj03378 *)p)->f24 = 0;
    ((struct Obj03378 *)p)->f298 = 0;
    ((struct Obj03378 *)p)->f4 = 0;
    for (i = 0; i < 0x1a; i++) {
        u8 *e = (u8 *)p + i * 0x18;
        ((struct Obj04643 *)e)->f28 = 0;
        ((struct Obj04643 *)e)->f2C = 0;
        ((struct Obj04643 *)e)->f30 = 0;
        ((struct Obj04643 *)e)->f34 = 0;
        ((struct Obj04643 *)e)->f36 = 0;
        ((struct Obj04643 *)e)->f37 = 0;
        ((struct Obj04643 *)e)->f3C = 0;
    }
}


/*
 * Tail-call veneer: branch to func_020307B0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C25A8(void *a0)
{
    return func_020307B0(a0);
}

/*
 * Store the result of functional call func_0204B100(0x1a, 0, p->h0) into p->w4.
 *
 * Addresses are Black-image addresses.
 */
void func_021C25B0(u8 *p)
{
    ((struct Obj03378 *)p)->f4 = (u32)func_0204B100(0x1a, 0, ((struct Obj03378 *)p)->f0);
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 4)) to func_0204B1CC.
 *
 * Addresses are Black-image addresses.
 */
void func_021C25C4(u8 *a0)
{
    func_0204B1CC((struct Bank *)((u32)(((struct Obj26022 *)a0)->f4)));
}

/*
 * tail: two zero padding bytes at 0x021C2612, not a follower.
 * ABI: 0204B294's legacy source says void; original caller stores returned
 *      r0 at 021C2608. Preserve that observable return and its seven inputs.
 */
void func_021C25D0(u8 *p)
{
    struct Arg arg;
    u32 *q=(u32 *)(p+8);
    int i=0;
    arg.a=0;
    arg.b=0;
    arg.c=0;
    arg.d=0;
    arg.e=0;
    for (;i<26;i++) {
        *(u32 *)(p+i*24+0x3c)=(u32)func_0204B294((void *)((struct Obj03378 *)p)->f4,q[0],q[1],q[2],&arg,((struct Obj08444 *)q)->fC,((struct Obj03378 *)p)->f0);
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C2614(char *p)
{
    int i;
    for (i = 0; i < 0x1A; i++)
        func_0204B3B4((struct Obj *)(*(int *)(p + 0x3c + i * 0x18)));
}
