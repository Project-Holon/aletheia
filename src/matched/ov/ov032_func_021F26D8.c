/*
 * function: func_021F26D8
 * address: 0x021F26D8
 * packet: pkt_ov032_021F26D8
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F02C4 0x021F02C4 thumb ov032
 */
typedef unsigned char u8;
extern int func_021F02C4(u8 *);
int func_021F26D8(u8 *p)
{
    if (func_021F02C4(p) == 0)
        return 1;
    *(int *)(p + 0x6c) = 0;
    return 2;
}
