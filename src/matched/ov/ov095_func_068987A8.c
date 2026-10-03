/*
 * unit: yes
 * function: func_068987A8
 * address: 0x068987A8
 * packet: pkt_ov095_068987A8
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: 12-byte store-and-return follower after non-C veneer 06898798.
 * symbols:
 *   d_0689D6A8 0x0689D6A8 data a4
 */
extern unsigned char d_0689D6A8[];
void *func_068987A8(unsigned int *state)
{
    *state = 2;
    return d_0689D6A8;
}
