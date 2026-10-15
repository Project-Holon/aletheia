/*
 * function: MANUAL_COMMON_GetGroupValue1
 * address: 0x021B9C34
 * packet: pkt_ov225_021B9C34
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MANUAL_COMMON_GetEntry 0x021B9CFC thumb ov225
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern int MANUAL_COMMON_GetEntry(char *,int);
u16 MANUAL_COMMON_GetGroupValue1(char *p,int index) {return *(u16 *)(MANUAL_COMMON_GetEntry(p,index)+4);}
