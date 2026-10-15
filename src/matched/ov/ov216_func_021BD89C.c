/*
 * function: BEACON_DETAIL_GRA_AddSlotSlideTask
 * address: 0x021BD89C
 * packet: pkt_ov216_021BD89C
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BEACON_DETAIL_GRA_AddSlotSlideTaskEx 0x021BD8A8 thumb ov216
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BEACON_DETAIL_GRA_AddSlotSlideTaskEx(char*,int,int*);
void BEACON_DETAIL_GRA_AddSlotSlideTask(char*p,int a){BEACON_DETAIL_GRA_AddSlotSlideTaskEx(p,a,(int*)(p+12));}
