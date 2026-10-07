/*
 * function: func_0203CA04
 * address:  0x0203CA04
 * packet:   pkt_0203CA04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC      0x021469DC  data
 *   g_020A7BA8      0x020A7BA8  data
 *   g_020A7BEC      0x020A7BEC  data
 *   func_0203D798   0x0203D798  arm
 *   func_02034714   0x02034714  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CA04.c \
 *       --func func_0203CA04 --addr 0x0203CA04 --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Sys *g_021469DC;
extern u8  g_020A7BA8[];
extern u8  g_020A7BEC[];

extern void *func_0203D798(void);
extern void func_02034714(const char *expr, u32 line, const char *file);

void func_0203CA04(void)
{
    u8 *q;
    u32 t;

    if (((u8 *)g_021469DC) == 0)
        return;

    q = func_0203D798();

    t = 0;
    if ((u8)(q[0x65] + 0xFF) <= 5) {
        if (((1 << (u8)(q[0x65] + 0xFF)) & 0x23) != 0)
            t = 1;
    }

    if (t == 0)
        func_02034714((const char *)((u32)g_020A7BA8), 0x8B7, (const char *)((u32)g_020A7BEC));

    *(u32 *)(((u8 *)g_021469DC) + 0x30) = 0;
    *(u32 *)(((u8 *)g_021469DC) + 0x34) = 0;
    *(u32 *)(((u8 *)g_021469DC) + 0x38) = 0;
    *(u32 *)(((u8 *)g_021469DC) + 0x3C) = 0;
}
