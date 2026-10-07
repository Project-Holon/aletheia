/*
 * function: CTRDGi_IsTaskAvailable
 * address:  0x0206DB24
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_0214BAB4      0x0214BAB4  data  a4
 *
 * Original (28 bytes):
 *   ldr  r0, [pc, #0x10]   ; &d_0214BAB4
 *   ldr  r0, [r0]
 *   cmp  r0, #0
 *   movne r0, #1
 *   moveq r0, #0
 *   bx   lr
 */

#include "../include/G_GeState.h"

extern struct GeState d_0214BAB4;

int CTRDGi_IsTaskAvailable(void)
{
    return *(void **)&(*(char *)&d_0214BAB4) != 0;
}
