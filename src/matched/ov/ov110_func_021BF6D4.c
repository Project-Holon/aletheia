/*
 * function: PMS_INPUT_GetUiInputModePtr
 * address:  0x021BF6D4
 * packet:   pkt_ov110_021BF6D4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

u8 *PMS_INPUT_GetUiInputModePtr(u8 *p) { return p + 0x70; }
