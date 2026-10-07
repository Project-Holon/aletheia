/*
 * function: func_0203C9AC
 * address:  0x0203C9AC
 * packet:   pkt_0203C9AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C9AC.c \
 *       --func func_0203C9AC --addr 0x0203C9AC --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *g_021469DC;
extern void func_02039548(void);

void func_0203C9AC(int a, u32 b, u32 c, u32 d)
{
    if (((u8 *)g_021469DC) == 0)
        return;

    if ((u32)(a - 0x3ED) > 1)
        a = -a;

    *(u32 *)(((u8 *)g_021469DC) + 0x30) = (u32)a;
    *(u32 *)(((u8 *)g_021469DC) + 0x34) = b;
    *(u32 *)(((u8 *)g_021469DC) + 0x38) = c;
    *(u32 *)(((u8 *)g_021469DC) + 0x3C) = d;

    if (d != 0)
        func_02039548();
}
