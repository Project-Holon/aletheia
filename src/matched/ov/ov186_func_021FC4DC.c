/*
 * function: BR_GRAPHIC_GetActorUnit
 * address: 0x021FC4DC
 * packet: pkt_ov186_021FC4DC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_GRAPHIC_GetUnitFromActorSys 0x021FC60C thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 BR_GRAPHIC_GetUnitFromActorSys(u32 *p);
u32 BR_GRAPHIC_GetActorUnit(u8*p){return BR_GRAPHIC_GetUnitFromActorSys((u32 *)(p+4));}
