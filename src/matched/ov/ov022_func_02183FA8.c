/*
 * function: func_02183FA8
 * address: 0x02183FA8
 * packet: pkt_ov022_02183FA8
 * region: ov022
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Unlabelled bit-set leaf; follower 02183FB8 is separate labelled code.
 */
typedef unsigned char u8;
void func_02183FA8(u8 *p, u8 index)
{
    p[13] = p[13] | (u8)(1 << index);
}
