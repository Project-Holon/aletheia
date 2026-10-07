/*
 * function: func_0203C2B0
 * address:  0x0203C2B0
 * packet:   pkt_0203C0F4
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
 *   python tools/match.py one --src src/matched/func_0203C2B0.c \
 *       --func func_0203C2B0 --addr 0x0203C2B0 --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *g_021469DC;
struct NetState;
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
extern u32 func_0203778C(u32 p);

int func_0203C2B0(int a)
{
    if (a != -1) {
        if (func_0203778C((u32)a) == 0)
            return 0;
    }

    ((u8 *)g_021469DC)[0x48] = (u8)a;
    func_0203AD80((struct NetState *)((u8 *)g_021469DC), (void *)0x0203C238, 0, 0x5C4);
    return 1;
}
