/*
 * function: POKETRADE_3D_Update3DScene
 * address:  0x021E31B4
 * packet:   pkt_ov119_021E31B4
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_3D_Draw3DScene  0x021E32EC  thumb  ov119
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void POKETRADE_3D_Draw3DScene(char *p);
void POKETRADE_3D_Update3DScene(void *p) { POKETRADE_3D_Draw3DScene(p); }
