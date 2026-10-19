/*
 * function: EVENT_FIELD_MENU_GetProcKindOfButton
 * address:  0x0215FEC8
 * packet:   pkt_ov010_0215FEC8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf after SCRCMD_NETWORK_BattleRecordLinkEventMain (bl from 0x0215FDD0).
 *
 * symbols:
 *   SCRCMD_NETWORK_sRecordKindByFrameRate     0x021712AC  data
 */

typedef unsigned int u32;

extern const u32 SCRCMD_NETWORK_sRecordKindByFrameRate[];

u32 EVENT_FIELD_MENU_GetProcKindOfButton(u32 n)
{
    return SCRCMD_NETWORK_sRecordKindByFrameRate[n];
}
