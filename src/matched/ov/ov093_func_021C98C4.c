/*
 * function: func_021C98C4
 * address: 0x021C98C4
 * packet: pkt_ov093_021C98C4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EF8E8 0x021EF8E8 thumb ov093
 *   func_021C4C50 0x021C4C50 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021EF8E8(int);
extern void func_021C4C50(u8 *, int);
int func_021C98C4(u8 *p, u8 *q)
{
    if (func_021EF8E8(*(int *)(q + 4))) {
        func_021C4C50(p, *(int *)(q + 4));
        return 1;
    }
    return 0;
}
