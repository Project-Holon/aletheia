/*
 * file:     unit_02179824_p03.c
 * unit:     yes
 * function: func_0217993C, func_0217998C
 * address:  0x0217993C
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0217AAC0     0x0217AAC0  data   ov015  a4
 *   d_0217AB40     0x0217AB40  data   ov015  a4
 *   d_0217ABA0     0x0217ABA0  data   ov015  a4
 *   func_02082BCC  0x02082BCC  arm
 *   func_0208F1B4  0x0208F1B4  arm
 *   func_02179F74  0x02179F74  arm    ov015
 *   func_0217A584  0x0217A584  arm    ov015
 *   func_02179B38  0x02179B38  thumb  ov015
 *   func_020056EC  0x020056EC  thumb
 */
#include "../../matched/include/G_s_ab40.h"
#include "../../matched/include/G_s_aba0.h"

typedef unsigned char u8;

typedef unsigned int u32;

struct s_aac0 {
    u8 pad0[8];
    u32 f8;
    u8 pad1[4];
    u8 f10;
};

typedef unsigned short u16;

extern void func_02082BCC(void *p, int v, u32 n);
extern u16 func_0208F1B4(void);
extern void func_02179F74(u8 unitId);
extern void func_0217A584(void (*cb)(void));
extern void func_02179B38(u8 *pkt, u32 len, u32 type);
extern u32 func_020056EC(u32 x);
void func_0217993C(u32 a, u8 b);
void func_0217998C(int v);
extern struct s_aac0 d_0217AAC0;
extern struct s_ab40 d_0217AB40;
extern struct s_aba0 d_0217ABA0;


void func_0217993C(u32 a, u8 b)
{
    func_02082BCC(&d_0217AAC0, 0, 0xE8);
    d_0217AB40.f3c = a;
    d_0217ABA0.b6 = func_0208F1B4();
    func_02179F74(3);
    func_0217A584((void (*)(void))func_02179B38);
    d_0217AAC0.f8 = func_020056EC(0);
    if (d_0217AAC0.f8 == 0)
        d_0217AAC0.f8 = 1;
    d_0217AAC0.f10 = b;
}


/*
 * Unlabelled leaf setter (hidden in a .word run); helper for the call in
 * ov010 func_02157A78.
 */
void func_0217998C(int v)
{
    *(int *)(((u8 *)&d_0217AB40) + 0x3C) = v;
}
