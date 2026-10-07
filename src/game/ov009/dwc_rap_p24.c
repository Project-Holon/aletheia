/*
 * file:     dwc_rap_p24.c
 * unit:     yes
 * function: func_02156F14, func_02156F50, func_02156F5C
 * address:  0x02156F14
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021A8268  0x021A8268  data  ov009  a4
 *   func_02060C94  0x02060C94  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020306F0  0x020306F0  arm
 *   d_021A1C78  0x021A1C78  data  ov009  a1
 *   d_021A1C7C  0x021A1C7C  data  ov009  a1
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02060CA0  0x02060CA0  arm
 *   func_0200FB6C  0x0200FB6C  thumb
 *   func_0203C9AC  0x0203C9AC  arm
 */
#include "../../matched/include/G_Obj.h"

struct ExpHeap;
typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {
    u32 f0; u32 f4; u32 f8; u32 fC; u32 f10; u32 f14; u32 f18; u32 f1C; u16 f20;
} Obj;

typedef signed int     s32;

extern void func_02060C94(void *heap);
extern u32 func_020307B0(void *p);
extern void func_020306F0(u32 heap);
extern u32 func_02087988(void);
extern void func_0208799C(u32 h);
extern void *func_02060CA0(struct ExpHeap *heap, u32 size, s32 align);
extern void func_0200FB6C(void);
extern void func_0203C9AC(int a, u32 b, u32 c, u32 d);
void func_02156F14(void);
void func_02156F50(int a);
u32 func_02156F5C(u32 a, u32 b, u32 c);
extern struct Obj *d_021A8268;
extern char d_021A1C78[];
extern char d_021A1C7C[];

void func_02156F14(void)
{
    if (d_021A8268->fC != 0) {
        func_02060C94((void *)d_021A8268->f8);
        func_020307B0((void *)d_021A8268->fC);
        d_021A8268->f8 = 0;
        d_021A8268->fC = 0;
        if (d_021A8268->f20 != 0) {
            func_020306F0(d_021A8268->f20);
            d_021A8268->f20 = 0;
        }
    }
}


/*
 * Setter after the function ending at pool 0x02156F4C, which stores to the
 * same halfword: writes its argument to +0x20 of the object d_021A8268
 * points to. Called from the ov175 root func_021D7E18 (0x021D85E0).
 */
void func_02156F50(int a)
{
    *(u16 *)(((char *)d_021A8268) + 0x20) = a;
}


u32 func_02156F5C(u32 a, u32 b, u32 c)
{
    u32 h;
    u32 r;

    if (d_021A8268->f8 != 0 && a == d_021A8268->f10 && b > d_021A8268->f18) {
        h = func_02087988();
        r = (u32)func_02060CA0((struct ExpHeap *)d_021A8268->f8, b, c);
        func_0208799C(h);
        d_021A8268->f14++;
    } else {
        h = func_02087988();
        r = (u32)func_02060CA0((struct ExpHeap *)d_021A8268->f0, b, c);
        func_0208799C(h);
    }
    if (r == 0) {
        func_0200FB6C();
        func_0203C9AC(0, 0, 0, 0x3EE);
        return 0;
    }
    return r;
}
