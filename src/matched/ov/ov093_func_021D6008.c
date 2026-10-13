/*
 * function: BTL_POKEPARAM_ClearContFlag
 * address: 0x021D6008
 * packet: pkt_ov093_021D6008
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: index the offset base (p + 0x155), preserving its separate add.
 */
typedef unsigned char u8;
void BTL_POKEPARAM_ClearContFlag(u8 *p, unsigned int n)
{
    (p + 0x155)[(u8)(n >> 3)] &= (u8)~(u8)(1 << (n & 7));
}
