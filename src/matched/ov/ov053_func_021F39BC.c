/*
 * function: GIMMICK53_LoadBgmFade
 * address: 0x021F39BC
 * packet: pkt_ov053_021F39BC
 * region: ov053
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_TOOL_ReadMemberRange 0x02048F74 arm
 */

typedef unsigned int   u32;
extern void ARC_TOOL_ReadMemberRange(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);

void GIMMICK53_LoadBgmFade(char *a)
{
    ARC_TOOL_ReadMemberRange(a + 0x58, 0x94, 0, 0, (u32 *)12);
}
