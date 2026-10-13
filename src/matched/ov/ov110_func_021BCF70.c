/*
 * function: PMSIV_MENU_FinishPress
 * address:  0x021BCF70
 * packet:   pkt_ov110_021BCF70
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PMSIV_MENU_FinishBackItem  0x021BCE48  thumb  ov110
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void PMSIV_MENU_FinishBackItem(void *, int, int);
void PMSIV_MENU_FinishPress(void *p, int i, int j) { if (i == 1) { PMSIV_MENU_FinishBackItem(p, i, j); } }
