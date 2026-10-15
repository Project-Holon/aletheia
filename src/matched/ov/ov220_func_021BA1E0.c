/*
 * function: TH_AWARD_GRAPHIC_GetActor
 * address: 0x021BA1E0
 * packet: pkt_ov220_021BA1E0
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TH_AWARD_GRAPHIC_GetValue 0x021BA310 thumb ov220
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 TH_AWARD_GRAPHIC_GetValue(u32*);
u32 TH_AWARD_GRAPHIC_GetActor(u8*p){return TH_AWARD_GRAPHIC_GetValue((u32*)(p+4));}
