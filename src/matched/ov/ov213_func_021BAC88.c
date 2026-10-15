/*
 * function: COMM_BTL_DEMO_GRAPHIC_DrawEnd
 * address: 0x021BAC88
 * packet: pkt_ov213_021BAC88
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMM_BTL_DEMO_GRAPHIC_DrawG3dEnd 0x021BAE64 thumb ov213
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void COMM_BTL_DEMO_GRAPHIC_DrawG3dEnd(void *);
void COMM_BTL_DEMO_GRAPHIC_DrawEnd(char *p) { COMM_BTL_DEMO_GRAPHIC_DrawG3dEnd(p+8); }
