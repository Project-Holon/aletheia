/*
 * function: DWC_RAP_GetVchatState
 * address: 0x02156B68
 * packet: pkt_ov009_02156B68
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: 8-byte thunk; larger accessor followers 02156B70 and 02156B8C excluded.
 * symbols:
 *   VCT_MAIN_GetVoiceLevel 0x021AF210 thumb ov013
 */
extern int VCT_MAIN_GetVoiceLevel(void);
int DWC_RAP_GetVchatState(char *a0)
{
    return VCT_MAIN_GetVoiceLevel();
}
