/*
 * function: HAND_ITEM_FocusBand_CheckSurvive
 * address: 0x021DEAF4
 * packet: pkt_ov093_021DEAF4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: int n = (unsigned char)HAND_ITEM_GetParam(a,2) schedules the
 * narrowing in r0 then r1. An inline call cast costs an extra copy (62 B).
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   HAND_ITEM_GetParam 0x021DCFF8 thumb ov093
 *   HAND_ITEM_RollChance 0x021DCFD0 thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int,int);
extern int HAND_ITEM_GetParam(int,int);
extern int HAND_ITEM_RollChance(int *,unsigned int);
extern int BTL_EVENT_OverwriteVar(int,unsigned int);
void HAND_ITEM_FocusBand_CheckSurvive(int a,int *b,int c,int *p) { int n; if(c==BTL_EVENT_GetVar(4)) { n=(unsigned char)HAND_ITEM_GetParam(a,2); if(HAND_ITEM_RollChance(b,n)) *p=BTL_EVENT_OverwriteVar(58,3); else *p=0; } }
