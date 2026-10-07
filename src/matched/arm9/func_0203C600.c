/*
 * function: func_0203C600
 * address:  0x0203C600
 * packet:   pkt_0203C600
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM predicate: the callback at +8 of the card task object is func_0203C0F4.
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *   func_0203C0F4  0x0203C0F4  arm
 */

#include "../include/G_Sys.h"

extern struct Sys *g_021469DC;
extern void func_0203C0F4(void *p);

int func_0203C600(void)
{
    return g_021469DC->cb == (void *)func_0203C0F4;
}
