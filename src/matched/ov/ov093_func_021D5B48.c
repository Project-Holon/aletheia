/*
 * function: BTL_POKEPARAM_IsHpFull
 * address: 0x021D5B48
 * packet: pkt_ov093_021D5B48
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D59B4 0x021D59B4 thumb ov093
 */
typedef unsigned char u8;
extern int func_021D59B4(u8 *p, int k);
int BTL_POKEPARAM_IsHpFull(u8 *p)
{
    if (func_021D59B4(p, 0xd) == func_021D59B4(p, 0xe)) return 1;
    return 0;
}
