/*
 * function: func_021B98DC
 * address:  0x021B98DC
 * packet:   pkt_021B98DC
 * region:   ov213
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021BB004 0x021BB004 data ov213 a4
 */

extern int d_021BB004[];

int func_021B98DC(int a, int b)
{
    return *(int *)((char *)d_021BB004 + a * 8 + b * 4);
}