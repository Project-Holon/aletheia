/*
 * function: BR_GRAPHIC_VBlankActors, BR_GRAPHIC_GetUnitFromActorSys
 * address: 0x021FC604
 * packet: pkt_ov186_021FC604
 * region: ov186
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
void BR_GRAPHIC_VBlankActors(void *a0){CLACT_VBlankSystem();}
u32 BR_GRAPHIC_GetUnitFromActorSys(u32*p){return *p;}
