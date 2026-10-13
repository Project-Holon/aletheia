/*
 * function: POKE_REGULATION_Load
 * address:  0x0201A354
 * packet:   pkt_0201A354
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Witness leaf for ov021 SCRCMD_FLD_BATTLE_CheckPartyRegulation and SCRCMD_FLD_BATTLE_StoreAllowedSpeciesNames.
 *
 * symbols:
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 */

extern void *ARC_TOOL_LoadMember(unsigned int archive_id, unsigned int member, unsigned int heap);

void *POKE_REGULATION_Load(int a, int b)
{
    return ARC_TOOL_LoadMember(0x69, a, b);
}
