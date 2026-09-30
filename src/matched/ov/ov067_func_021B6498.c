/*
 * function: func_021B6498
 * address: 0x021B6498
 * packet: pkt_ov067_021B6498
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: getter ends 0x021B64A6, two zero padding bytes, larger follower 0x021B64A8.
 */
typedef unsigned char u8;
int func_021B6498(u8 *p)
{
    if (*(int *)(p + 8))
        return 1;
    return 0;
}
