/*
 * function: P_STA_RIBBON_GetRibbonDescMsg
 * address: 0x021DBF94
 * packet: pkt_ov131_021DBF94
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   P_STA_RIBBON_InfoTable 0x021DC2F8 data
 */
#include "../p_status_types.h"
/* Same table as P_STA_RIBBON_GetRibbonInfo in p_sta_oam.c; this reads the description message of one row. */
extern const StaRibbonInfo P_STA_RIBBON_InfoTable[];
unsigned int P_STA_RIBBON_GetRibbonDescMsg(int ribbonNo) {
 return P_STA_RIBBON_InfoTable[ribbonNo].descMsg;
}
