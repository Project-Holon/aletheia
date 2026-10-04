/*
 * function: func_021F4B24
 * address:  0x021F4B24
 * packet:   pkt_ov112_021F4B24
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F50D0  0x021F50D0  thumb  ov112
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_021F50D0(const unsigned char *p);
void func_021F4B24(u8 *p) { func_021F50D0((const unsigned char *)(*(u32 *)(p + 0x20))); }
