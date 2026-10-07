/*
 * file:     p_sta_oam_p14.c
 * unit:     yes
 * function: func_021D77E8, func_021D77F8, func_021D7810
 * address:  0x021D77E8
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj06483.h"

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

struct hdr {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    int f4;
};

typedef struct
{
    u8 pad[0x94];
    u8 ring[5];
    u8 f99;
    u8 f9a;
} Ring;

void func_021D77E8(u8 *p, u32 a, u32 b);
void func_021D77F8(struct hdr *p, u8 a, u8 b, int c);
void func_021D7810(int unused, Ring *p, int mode);


void func_021D77E8(u8 *p, u32 a, u32 b)
{
    p[0] = 0;
    ((struct Obj06483 *)p)->f4 = 0;
    p[1] = 0;
    p[2] = a;
    p[3] = b;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D77F8(struct hdr *p, u8 a, u8 b, int c)
{
    p->f0 = p->f0 + 1;
    p->f4 = c;
    p->f1 = 0;
    p->f2 = a;
    p->f3 = b;
}


void func_021D7810(int unused, Ring *p, int mode)
{
    if (mode == 1)
    {
        u8 v = p->f99;
        p->ring[p->f9a] = v;
        p->f99 = 0;
        p->f9a = (u8)(p->f9a + 1);
        if (p->f9a >= 5)
            p->f9a = 0;
    }
    p->f99 = (u8)(p->f99 + 1);
}
