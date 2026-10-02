/*
 * function: func_021F27B4
 * address: 0x021F27B4
 * packet: pkt_ov032_021F27B4
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: extent follower 0x021F27CC is already filed separately.
 * symbols:
 *   func_021F03EC 0x021F03EC thumb ov032
 */
typedef unsigned char u8;
extern int func_021F03EC(u8 *);
int func_021F27B4(u8 *p)
{
    if (func_021F03EC(p) == 0)
        return 4;
    *(int *)(p + 0x6c) = 0;
    return 0;
}
