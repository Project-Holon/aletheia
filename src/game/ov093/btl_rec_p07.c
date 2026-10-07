/*
 * file:     btl_rec_p07.c
 * unit:     yes
 * function: func_021EEBA4, func_021EEBDC, func_021EEBE8
 * address:  0x021EEBA4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D4B98  0x021D4B98  thumb  ov093
 *   func_021D4BD4  0x021D4BD4  thumb  ov093
 *   func_021D4C60  0x021D4C60  thumb  ov093
 *   func_021D4C6C  0x021D4C6C  thumb  ov093
 */
#include "../../matched/include/Obj21627.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 pad00[4];
    u32 w4;
    u32 w8;
    u8 st : 4;
    u8 hi : 4;
    u8 f0d;
    u8 mode;
    u8 f0f;
    u16 h10;
    u16 h12;
    u8 d[1];
} W;

extern int func_021D4B98(void);
extern u16 func_021D4BD4(int a, u8 **q);
extern u8 func_021D4C60(void);
extern u16 func_021D4C6C(u8 **out);
u32 func_021EEBA4(W *p);
void func_021EEBDC(W *p);
u8 func_021EEBE8(W *p);


u32 func_021EEBA4(W *p)
{
    if (p->hi != 0) {
        if (func_021D4B98() != 0) {
            p->w8 = func_021D4BD4(p->f0d, (u8 **)(&p->w4));
            p->st = 1;
            return 1;
        }
        return 0;
    }
    return p->st;
}


void func_021EEBDC(W *p)
{
    p->h10 = 0;
    p->h12 = 4;
}


u8 func_021EEBE8(W *p)
{
    u8 *q;

    if (p->hi != 0) {
        if (func_021D4C60() != 0) {
            func_021D4C6C(&q);
            return ((struct Obj21627 *)q)->f0;
        }
        return 0;
    }
    if (p->st == 0)
        return p->h10;
    return 0;
}
