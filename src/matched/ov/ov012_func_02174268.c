/*
 * function: func_02174268
 * address: 0x02174268
 * packet: pkt_ov012_02174268
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
int func_02174268(u8 *p)
{
    if (*(int *)(p + 0x354c) == 0 && *(int *)(p + 0x3548) == 0)
        return 0;
    return 1;
}
