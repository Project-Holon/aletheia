/*
 * function: BTL_REC_SEL_GRAPHIC_Draw3d
 * address: 0x021BB290
 * packet: pkt_ov214_021BB290
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_REC_SEL_GRAPHIC_DrawG3d 0x021BB458 thumb ov214
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BTL_REC_SEL_GRAPHIC_DrawG3d(u32 *);
void BTL_REC_SEL_GRAPHIC_Draw3d(u8 *p) { BTL_REC_SEL_GRAPHIC_DrawG3d((u32 *)(p+8)); }
