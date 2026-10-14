/*
 * function: POKETRADE_SAVE_OpenMessageWindowTop
 * address:  0x021E1024
 * packet:   pkt_ov119_021E1024
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_SAVE_OpenMessageWindowAtPos  0x021E0FF4  thumb  ov119
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void POKETRADE_SAVE_OpenMessageWindowAtPos(void *, int, int);
void POKETRADE_SAVE_OpenMessageWindowTop(void *p) { POKETRADE_SAVE_OpenMessageWindowAtPos(p, 0, 0); }
