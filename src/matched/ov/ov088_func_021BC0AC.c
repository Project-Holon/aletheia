/*
 * function: func_021BC0AC
 * address:  0x021BC0AC
 * packet:   pkt_ov088_021BC0AC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf after func_021BC080 (function_starts seed); called by
 * func_021BA338.
 */

typedef unsigned char u8;

int func_021BC0AC(char *p, int v)
{
    *(u8 *)(p + 0x12e) = 0;
    *(u8 *)(p + 0x12d) = 0;
    *(int *)(p + 0x140) = v;
    return 3;
}
