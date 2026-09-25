/*
 * function: func_021D5C24
 * address:  0x021D5C24
 * packet:   pkt_ov115_021D5C24
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5C30  0x021D5C30  thumb  ov115
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021D5C30(void *, u32, int);
void func_021D5C24(void *p, int b) { func_021D5C30(p, *(u32 *)((u8 *)p + 0x1c), b); }
