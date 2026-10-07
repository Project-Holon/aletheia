/*
 * function: func_0203B758
 * address:  0x0203B758
 * packet:   pkt_0203B6EC
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
 *   python tools/match.py one --src src/matched/func_0203B758.c \
 *       --func func_0203B758 --addr 0x0203B758 --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *g_021469DC;

extern void *func_0203D798(void);
struct NetState;
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
extern int func_02039ACC(void);

void func_0203B758(void)
{
    func_0203D798();
    if (func_02039ACC() == 0)
        return;

    func_0203AD80((struct NetState *)((u8 *)g_021469DC), (void *)0x0203B794, 0, 0x30E);
}
