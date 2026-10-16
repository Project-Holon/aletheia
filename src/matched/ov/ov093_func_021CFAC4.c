/*
 * function: BTL_CLIENT_CanShadowTagTrap
 * address: 0x021CFAC4
 * packet: pkt_ov093_021CFAC4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 */
typedef unsigned char u8;
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
int BTL_CLIENT_CanShadowTagTrap(void *p, void *q)
{
    if (BTL_POKEPARAM_GetValue(q, 17) != 23) return 1;
    return 0;
}
