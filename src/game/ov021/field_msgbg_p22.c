/*
 * file:     field_msgbg_p22.c
 * unit:     yes
 * function: func_0218C490, func_0218C4A0
 * address:  0x0218C490
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021693D4  0x021693D4  thumb  ov010
 *   func_02169444  0x02169444  thumb  ov010
 */
#include "../../matched/include/Obj04988.h"

typedef struct {
    int a;
    int b;
    short c;
    short d;
    int e;
} S;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_021693D4(u8 *base, u8 *src, u32 idx);
extern u32 *func_02169444(u8 *base, u32 idx);
void func_0218C490(int unused, S *s);
u32 *func_0218C4A0(u8 *base, u32 a, u32 b, u16 c);


void func_0218C490(int unused, S *s)
{
    s->a = 0;
    s->b = -1;
    s->c = 0;
    s->d = 0;
    s->e = 0;
}


/*
 * Claims the first free 16-byte entry of the table at +0x1F8.
 *
 * Addresses are Black-image addresses.
 */
u32 *func_0218C4A0(u8 *base, u32 a, u32 b, u16 c)
{
    u32 *e = (u32 *)(base + 0x1F8);
    u32 i;

    for (i = 0; i < 0x120; i++) {
        e = (u32 *)(base + 0x1F8 + i * 16);
        if (e[0] == 0) {
            func_021693D4((u8 *)a, (u8 *)b, c);
            e[0] = a;
            e[1] = -1;
            ((struct Obj04988 *)e)->f8 = c;
            *((u16 *)(e + 2) + 1) = 1;
            e[3] = (u32)func_02169444((u8 *)a, c);
            return e;
        }
    }
    return 0;
}
