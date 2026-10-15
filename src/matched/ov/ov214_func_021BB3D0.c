/*
 * function: BTL_REC_SEL_GRAPHIC_VBlankClact,BTL_REC_SEL_GRAPHIC_GetClactBank
 * address: 0x021BB3D0
 * packet: pkt_ov214_021BB3D0
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * unit: yes
 * follower: 021BB3D8 word getter, within handed extent.
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void CLACT_VBlankSystem(void);
void BTL_REC_SEL_GRAPHIC_VBlankClact(void) { CLACT_VBlankSystem(); }
u32 BTL_REC_SEL_GRAPHIC_GetClactBank(u32 *p) { return *p; }
