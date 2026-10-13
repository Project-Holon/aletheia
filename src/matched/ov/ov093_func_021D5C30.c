/*
 * function: BTL_POKEPARAM_IsSemiInvulnerable
 * address: 0x021D5C30
 * packet: pkt_ov093_021D5C30
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are zero alignment padding.
 * symbols:
 *   BTL_POKEPARAM_GetSemiInvulnerableFlag 0x021D5C08 thumb ov093
 */
struct UtilWork;
extern unsigned int BTL_POKEPARAM_GetSemiInvulnerableFlag(struct UtilWork *);
int BTL_POKEPARAM_IsSemiInvulnerable(struct UtilWork *p)
{
    if (BTL_POKEPARAM_GetSemiInvulnerableFlag(p) != 16) return 1;
    return 0;
}
