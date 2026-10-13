/*
 * function: PMSIV_EDIT_SlotPosToBoxOrigin
 * address: 0x021BC564
 * packet: pkt_ov110_021BC564
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after return.
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

void PMSIV_EDIT_SlotPosToBoxOrigin(s16 *p,s16 *out) { out[0]=p[0]-48; out[1]=p[1]-8; }
