/*
 * function: MANUAL_COMMON_GetEntryValue2
 * address: 0x021B9BE0
 * packet: pkt_ov225_021B9BE0
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MANUAL_COMMON_GetGroupEntry 0x021B9CE0 thumb ov225
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern int MANUAL_COMMON_GetGroupEntry(char *,int);
u16 MANUAL_COMMON_GetEntryValue2(char *p,int index) {return *(u16 *)(MANUAL_COMMON_GetGroupEntry(p,index)+10);}
