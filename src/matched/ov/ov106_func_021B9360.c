/*
 * function: func_021B9360
 * address: 0x021B9360
 * packet: pkt_ov106_021B9360
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_02045808 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10256.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Grid;
struct Obj020437AC;
struct U16Vec;
extern void func_0202570C(struct Grid *g);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020307B0(void *p);
void func_021B9360(u8 *p) { func_0202570C(((struct Obj10256 *)p)->f1C); func_020437AC(((struct Obj10256 *)p)->f0); func_02045808(((struct Obj10256 *)p)->f18); func_020307B0(p); }
