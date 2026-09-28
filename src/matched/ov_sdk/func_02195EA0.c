/*
 * function: func_02195EA0
 * address:  0x02195EA0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores a word big-endian at p[i].
 */

void func_02195EA0(char *p, int i, int v)
{
    p[i] = (char)(v >> 8);
    p[i + 1] = (char)v;
}
