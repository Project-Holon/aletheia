/*
 * function: BEACON_VIEW_ShowNextHistoryPower
 * address: 0x021F0114
 * packet: pkt_ov032_021F0114
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BEACON_VIEW_PopHistoryId 0x021F07D4 thumb ov032
 *   GPOWER_GetActiveIdOfSameType 0x02010EA0 thumb
 *   BEACON_VIEW_ShowPowerAnim 0x021F1A18 thumb ov032
 */
#include "../include/Obj05120.h"
typedef unsigned char u8;
extern unsigned BEACON_VIEW_PopHistoryId(u8 *);
extern u8 GPOWER_GetActiveIdOfSameType(int,u8 *);
extern void BEACON_VIEW_ShowPowerAnim(char *p, int b);
int BEACON_VIEW_ShowNextHistoryPower(u8 *p) { unsigned n; n=BEACON_VIEW_PopHistoryId(p); if(n==0x30) return 0; if(n==GPOWER_GetActiveIdOfSameType(n,*(u8 * *)&((struct Obj05120 *)p)->f24)) return 0; BEACON_VIEW_ShowPowerAnim((char *)p,n); return 1; }
