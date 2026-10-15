/*
 * function: BEACON_DETAIL_GRA_AddTimerTask
 * address: 0x021BD6F0
 * packet: pkt_ov216_021BD6F0
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BEACON_DETAIL_GRA_AddTimerTaskEx 0x021BD6FC thumb ov216
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BEACON_DETAIL_GRA_AddTimerTaskEx(char*,int*);
void BEACON_DETAIL_GRA_AddTimerTask(char*p){BEACON_DETAIL_GRA_AddTimerTaskEx(p,(int*)(p+12));}
