/*
 * function: BTL_CLIENT_CanMagnetPullTrap
 * address: 0x021CFB8C
 * packet: pkt_ov093_021CFB8C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: follower 0x021CFBA4 already has its own matched source/shard.
 * symbols:
 *   BTL_POKEPARAM_HasType 0x021D5814 thumb ov093
 */
extern int BTL_POKEPARAM_HasType(void *, int);
int BTL_CLIENT_CanMagnetPullTrap(void *p, void *q)
{
    if (BTL_POKEPARAM_HasType(q, 8)) return 1;
    return 0;
}
