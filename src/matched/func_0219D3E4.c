/*
 * function: func_0219D3E4
 * address:  0x0219D3E4
 * packet:   pkt_0219D3E4
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Indexes an array of 8-byte records based at 0x021D7F68.
 *
 * symbols:
 *   d_021D7F68  0x021D7F68  data  ov021
 */

extern char d_021D7F68[];

char *func_0219D3E4(int i)
{
    return d_021D7F68 + i * 8;
}
