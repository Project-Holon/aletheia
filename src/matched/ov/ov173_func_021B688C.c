/*
 * function: func_021B688C
 * address: 0x021B688C
 * packet: pkt_ov173_021B688C
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj06565.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec;
struct U16Vec;
struct WordSet;
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02045808(struct U16Vec *vec);
void func_021B688C(char *p) { func_02045C04(((struct Obj06565 *)p)->f44); func_0201ED04(((struct Obj06565 *)p)->f48); func_02045808(((struct Obj06565 *)p)->f4C); func_02045808(((struct Obj06565 *)p)->f50); func_02045808(((struct Obj06565 *)p)->f54); }
