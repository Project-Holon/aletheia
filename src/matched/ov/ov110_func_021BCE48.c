/*
 * function: PMSIV_MENU_FinishBackItem
 * address:  0x021BCE48
 * packet:   pkt_ov110_021BCE48
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PMSIV_MENU_SetItemAnim  0x021BD0F8  thumb  ov110
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void PMSIV_MENU_SetItemAnim(u8 *p, int i, int flag);
void PMSIV_MENU_FinishBackItem(void *p, int a1, int a2) { PMSIV_MENU_SetItemAnim(p, 7, 0); }
