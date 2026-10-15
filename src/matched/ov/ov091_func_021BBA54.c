/*
 * function: PLIST_MESSAGE_LoadWindowFrame
 * address: 0x021BBA54
 * packet: pkt_ov091_021BBA54
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);
void PLIST_MESSAGE_LoadWindowFrame(unsigned short *a, u32 b) {BMP_MENUWORK_LoadCharAndPltt(0,1,12,0,*a);}
