/*
 * function: BEACON_DETAIL_GRA_VBlankClact, BEACON_DETAIL_GRA_ReadPtr
 * address: 0x021BCB98
 * packet: pkt_ov216_021BCB98
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * unit: yes
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void CLACT_VBlankSystem(void);
void BEACON_DETAIL_GRA_VBlankClact(void *a0){CLACT_VBlankSystem();}
u32 BEACON_DETAIL_GRA_ReadPtr(u32*p){return *p;}
