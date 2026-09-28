/*
 * function: func_021EAE44
 * address:  0x021EAE44
 * packet:   pkt_021EAE44
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EAE44   0x021EAE44  thumb  ov093
 *   func_0689B670   0x0689B670  thumb  ov095
 *
 * Resolved: func_0689B670 was matched (ov095), so the +0x0C ABS32 now
 * attests through the `matched` class and the thunk is byte-exact.
 *
 * Indexed-dispatch thunk, o18's 23-member shape: void func_021EAE44(E64 *p) { func_0689B670(p[0x6].f0); }
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

void func_021EAE44(E64 *p) { func_0689B670(p[0x6].f0); }
