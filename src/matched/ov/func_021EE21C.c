/*
 * function: func_021EE21C
 * address:  0x021EE21C
 * packet:   pkt_021EA478
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE21C   0x021EE21C  thumb  ov093
 *   func_021ECF68   0x021ECF68  thumb  ov093

 * Untraced mid-stream entry point: a plain tail thunk, `ldr r3,=T; bx r3`, whose pool word names func_021ECF68.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

struct T;
extern int func_021ECF68(struct T *p);

int func_021EE21C(u8 *p) { return func_021ECF68((struct T *)p); }

