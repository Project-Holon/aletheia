/*
 * function: func_021C3370
 * address: 0x021C3370
 * packet: pkt_ov093_021C3370
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5B7C 0x021D5B7C thumb ov093
 *   func_021D5B48 0x021D5B48 thumb ov093
 */
typedef unsigned char u8;
extern int func_021D5B7C(void *);
extern int func_021D5B48(u8 *p);
int func_021C3370(u8 *p, void *q)
{
    if (func_021D5B7C(q) == 0) return 1;
    if (func_021D5B48(q) != 0) return 1;
    return 0;
}
