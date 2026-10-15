/*
 * function: COMM_BTL_DEMO_GRAPHIC_DrawG3dEnd
 * address: 0x021BAE64
 * packet: pkt_ov213_021BAE64
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * leaf: parent-cleared sole ov213 blocker of COMM_BTL_DEMO_GRAPHIC_DrawEnd; eight-byte tail stub.
 * symbols:
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void G3D_SYSTEM_DrawEnd(void);
void COMM_BTL_DEMO_GRAPHIC_DrawG3dEnd(void *unused) { G3D_SYSTEM_DrawEnd(); }
