/*
 * function: COMM_BTL_DEMO_GRAPHIC_Draw3d
 * address: 0x021BAC7C
 * packet: pkt_ov213_021BAC7C
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMM_BTL_DEMO_GRAPHIC_DrawG3d 0x021BAE50 thumb ov213
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void COMM_BTL_DEMO_GRAPHIC_DrawG3d(int *);
void COMM_BTL_DEMO_GRAPHIC_Draw3d(char *p) { COMM_BTL_DEMO_GRAPHIC_DrawG3d((int *)(p+8)); }
