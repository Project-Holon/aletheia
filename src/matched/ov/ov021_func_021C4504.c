/*
 * function: SODATEYA_GetBaseSpecies
 * address:  0x021C4504
 * packet:   pkt_ov021_021C4504
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Maps a species to its base form via the evolution table (species below
 * 0x289).
 *
 * symbols:
 *   ARC_TOOL_ReadMemberRange  0x02048F74  arm  arm9
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void ARC_TOOL_ReadMemberRange(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);

u16 SODATEYA_GetBaseSpecies(u16 sp)
{
    u16 v;

    if (sp >= 0x289)
        return sp;
    ARC_TOOL_ReadMemberRange(&v, 0x14, sp, 0, (u32 *)2);
    return v;
}
