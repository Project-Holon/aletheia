/*
 * function: P_STA_SKILL_RefreshMoveDetail
 * address: 0x021D9EE8
 * packet: pkt_ov131_021D9EE8
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   P_STA_SKILL_PrintMoveDetail 0x021DA488 thumb ov131
 */
typedef unsigned char u8;
extern void P_STA_SKILL_PrintMoveDetail(u8 *,u8 *);
void P_STA_SKILL_RefreshMoveDetail(u8 *a,u8 *p)
{
    P_STA_SKILL_PrintMoveDetail(a,p);
}
