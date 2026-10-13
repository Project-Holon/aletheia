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
 *   func_021D59B4 0x021D59B4 thumb ov093
 */
typedef unsigned char u8;
extern int func_021D59B4(u8 *p, int k);
int BTL_CLIENT_CanShadowTagTrap(void *p, void *q)
{
    if (func_021D59B4(q, 17) != 23) return 1;
    return 0;
}
