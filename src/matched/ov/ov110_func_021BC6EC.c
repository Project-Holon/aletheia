/*
 * function: PMSIV_EDIT_ReleaseCursor
 * address:  0x021BC6EC
 * packet:   pkt_ov110_021BC6EC
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PMSIV_EDIT_SetCursorPressed  0x021BC69C  thumb  ov110
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void PMSIV_EDIT_SetCursorPressed(u8 *p, int flag);
void PMSIV_EDIT_ReleaseCursor(void *p) { PMSIV_EDIT_SetCursorPressed(p, 0); }
