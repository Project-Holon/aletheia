/*
 * function: func_021D5B50
 * address:  0x021D5B50
 * packet:   pkt_ov115_021D5B50
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5B5C  0x021D5B5C  thumb  ov115
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021D5B5C(void *, u32, int);
void func_021D5B50(void *p, int b) { func_021D5B5C(p, *(u32 *)((u8 *)p + 0x1c), b); }
