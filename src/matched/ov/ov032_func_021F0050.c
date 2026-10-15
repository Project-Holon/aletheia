/*
 * function: BEACON_VIEW_GetContTouchedRow
 * address: 0x021F0050
 * packet: pkt_ov032_021F0050
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   BEACON_VIEW_HitTestIcon 0x021F096C thumb ov032
 */
typedef unsigned int u32;
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int BEACON_VIEW_HitTestIcon(unsigned char *,void *);
int BEACON_VIEW_GetContTouchedRow(unsigned char *p) { u32 pt[2]; if(TOUCHPANEL_GetPointCont(pt,pt+1)) return BEACON_VIEW_HitTestIcon(p,pt); return -1; }
