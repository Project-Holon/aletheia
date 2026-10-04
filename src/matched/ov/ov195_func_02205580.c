/*
 * function: func_02205580
 * address: 0x02205580
 * packet: pkt_ov195_02205580
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B709C 0x021B709C thumb ov067
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 */
#include "../include/Obj04595.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec;
extern void func_021B709C(u8 *);
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_02045C04(struct Rec *);
void func_02205580(void *unused,char *p) {func_021B709C(*(u8 * *)&((struct Obj04595 *)p)->f9C);*(u32 *)&((struct Obj04595 *)p)->f9C=0;if(((struct Obj04595 *)p)->f94)func_02045808((struct U16Vec *)(((struct Obj04595 *)p)->f94));if(((struct Obj04595 *)p)->f98)func_02045808((struct U16Vec *)(((struct Obj04595 *)p)->f98));func_02045C04(*(struct Rec * *)&((struct Obj04595 *)p)->f90);}
