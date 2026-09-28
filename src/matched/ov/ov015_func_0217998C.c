/*
 * function: func_0217998C
 * address:  0x0217998C
 * packet:   pkt_ov015_0217998C
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf setter (hidden in a .word run); helper for the call in
 * ov010 func_02157A78.
 *
 * symbols:
 *   d_0217AB40  0x0217AB40  data ov015
 */

typedef unsigned char u8;

extern u8 d_0217AB40[];

void func_0217998C(int v)
{
    *(int *)(d_0217AB40 + 0x3C) = v;
}
