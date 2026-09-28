/*
 * function: func_021B816C
 * address:  0x021B816C
 * packet:   pkt_ov104_021B816C
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Zeroes +0x0c/+0x10 and stores 1 at +0x14.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

void func_021B816C(u8 *p) { *(u32 *)(p + 0xc) = 0; *(u32 *)(p + 0x10) = 0; *(u32 *)(p + 0x14) = 1; }
