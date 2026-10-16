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
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 */
typedef unsigned char u8;
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
int BTL_POKEPARAM_IsHpFull(u8 *p)
{
    if (BTL_POKEPARAM_GetValue(p, 0xd) == BTL_POKEPARAM_GetValue(p, 0xe)) return 1;
    return 0;
}
