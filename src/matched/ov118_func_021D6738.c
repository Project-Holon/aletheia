/*
 * function: func_021D6738
 * address:  0x021D6738
 * packet:   pkt_ov118_021D6738
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores v at +0xf2c (pooled field offset).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

void func_021D6738(u8 *p, u32 v) { *(u32 *)(p + 0xf2c) = v; }
