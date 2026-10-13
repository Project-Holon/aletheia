/*
 * function: PMS_WORDLIST_GetCellOffset
 * address:  0x021BEDC4
 * packet:   pkt_ov110_021BEDC4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

u32 PMS_WORDLIST_GetCellOffset(u8 *p) { return p[6] + p[7] * 2; }
