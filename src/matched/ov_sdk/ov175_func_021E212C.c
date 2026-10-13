/*
 * function: DWCi_GdbSetAsyncStatus
 * address:  0x021E212C
 * packet:   pkt_021E212C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Leaf: writes the triple (2, argument, 0) into the ov175 bss descriptor
 *  *  at 0x021E5334 and reports success.  No lr save: no calls at all.
 */

typedef unsigned long u32;

void DWCi_GdbSetAsyncStatus(u32 v)
{
    u32 *p = (u32 *)0x021E5334;
    p[2] = 2;
    p[3] = v;
    p[4] = 0;
}

