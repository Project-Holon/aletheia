/*
 * function: func_021BC484
 * address:  0x021BC484
 * packet:   pkt_ov110_021BC484
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

struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
void func_021BC484(u8 *p) { func_02045808((struct U16Vec *)(*(u32 *)p)); }
