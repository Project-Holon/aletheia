/*
 * function: BTL_REC_SEL_GRAPHIC_GetCamera
 * address: 0x021BB2A8
 * packet: pkt_ov214_021BB2A8
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_REC_SEL_GRAPHIC_GetClactBank 0x021BB3D8 thumb ov214
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 BTL_REC_SEL_GRAPHIC_GetClactBank(u32 *);
u32 BTL_REC_SEL_GRAPHIC_GetCamera(u8 *p) { return BTL_REC_SEL_GRAPHIC_GetClactBank((u32 *)(p+4)); }
