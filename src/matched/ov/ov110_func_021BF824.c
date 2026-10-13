/*
 * function: PMS_INPUT_CanConfirm
 * address:  0x021BF824
 * packet:   pkt_ov110_021BF824
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PMS_INPUT_IsComplete  0x021BF680  thumb  ov110
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int PMS_INPUT_IsComplete(u8 *p);
int PMS_INPUT_CanConfirm(u8 *a0) { return PMS_INPUT_IsComplete(a0); }
