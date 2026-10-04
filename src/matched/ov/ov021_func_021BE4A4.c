/*
 * function: func_021BE4A4
 * address:  0x021BE4A4
 * packet:   pkt_ov021_021BE4A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: store v into slot j (stride 0x44) of the array whose
 * pointer sits at +0xC of element i (stride 0x10).
 *
 * symbols:
 *   func_021BE4A4  0x021BE4A4  thumb
 */
#include "../include/Obj20142.h"

void func_021BE4A4(char *p, int i, int j, int v)
{
    char *e = p + i * 0x10;

    *(int *)(*(char * *)&((struct Obj20142 *)e)->fC + j * 0x44) = v;
}
