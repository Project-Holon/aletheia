/*
 * function: func_021F0D1C
 * address:  0x021F0D1C
 * packet:   pkt_ov107_021F0D1C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021F6EAC  0x021F6EAC  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u8 d_021F6EAC[];
void func_021F0D1C(u16 v) { *(u16 *)(d_021F6EAC + 8) = v; }
