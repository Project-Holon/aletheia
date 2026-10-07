/*
 * function: func_0203BF4C
 * address:  0x0203BF4C
 * packet:   pkt_0203BEC8
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
 *   python tools/match.py one --src src/matched/func_0203BF4C.c \
 *       --func func_0203BF4C --addr 0x0203BF4C --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *g_021469DC;

extern void *func_0203D788(void);
struct NetState;
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);

void func_0203BF4C(void)
{
    u8 *s = func_0203D788();

    if ((*(u32 (**)(u32, u32))(*(u32 *)(s + 0x340) + 0x10))(1, 0) == 0)
        return;

    func_0203AD80((struct NetState *)((u8 *)g_021469DC), (void *)0x0203BEC8, 0, 0x4A4);
}
