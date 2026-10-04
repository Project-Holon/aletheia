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
#include "../include/Obj04466.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021D5C30(u8 *p, unsigned int a, int b);
void func_021D5C24(void *p, int b) { func_021D5C30(p, ((struct Obj04466 *)p)->f1C, b); }
