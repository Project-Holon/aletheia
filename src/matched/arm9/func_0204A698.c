/*
 * function: func_0204A698
 * address:  0x0204A698
 * packet:   pkt_0204A600
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A74     0x02146A74  data
 *   func_0204BAEC  0x0204BAEC  arm
 *   func_0204BB54  0x0204BB54  arm
 *
 * Cell-actor latch-only tick: latch off, flush the actor bank list, latch
 * back on.  No render update compared with func_0204A600.
 */

#include "../include/G_Mgr.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Mgr *g_02146A74;

extern void func_0204BAEC(u32 v);
extern void func_0204BB54(void);

void func_0204A698(void)
{
    if (((u8 *)g_02146A74) == 0) {
        return;
    }
    func_0204BAEC(0);
    func_0204BB54();
    func_0204BAEC(1);
}
