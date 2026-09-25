/*
 * function: func_021BC740
 * address:  0x021BC740
 * packet:   pkt_021BC740
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Scaling index into the d_021C3068 word table, then a field read at
 * base + (table[i] << 2) + 0x130.
 *
 * symbols:
 *   d_021C3068  0x021C3068  data  ov217  a4
 *
 * Addresses are Black-image addresses.
 */

extern int d_021C3068[];

int func_021BC740(char *p, int i)
{
    return *(int *)(p + (d_021C3068[i] << 2) + 0x130);
}
