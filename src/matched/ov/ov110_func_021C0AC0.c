/*
 * function: PMS_SELECT_GRAPHIC_UpdateTouchBar
 * address:  0x021C0AC0
 * packet:   pkt_ov110_021C0AC0
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Resolved by the TOUCHBAR_Update label in ov067 (thumb); cross-overlay target.
 *
 * symbols:
 *   TOUCHBAR_Update  0x021B63D0  thumb  ov067
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct S;
extern void TOUCHBAR_Update(struct S *p);
void PMS_SELECT_GRAPHIC_UpdateTouchBar(void *a0) { TOUCHBAR_Update(a0); }
