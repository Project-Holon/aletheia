/*
 * function: func_0203C774
 * address:  0x0203C774
 * packet:   pkt_0203C65C
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
 *   python tools/match.py one --src src/matched/func_0203C774.c \
 *       --func func_0203C774 --addr 0x0203C774 --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *g_021469DC;

extern void *func_0203D788(void);
struct NetState;
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
extern int func_020351A0(u32 v);

void func_0203C774(u32 v)
{
    u8 *s;

    if (((u8 *)g_021469DC) == 0)
        return;

    s = func_0203D788();
    func_020351A0(1);
    *(u32 *)(((u8 *)g_021469DC) + 0x28) = v;
    (*(void (**)(u32, u32))(*(u32 *)(s + 0x340) + 0x54))(1, 0);

    func_0203AD80((struct NetState *)((u8 *)g_021469DC), (void *)0x0203C710, 5, 0x719);
}
