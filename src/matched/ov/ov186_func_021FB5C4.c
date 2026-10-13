/*
 * function: func_021FB5C4
 * address: 0x021FB5C4
 * packet: pkt_ov186_021FB5C4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B6F4 0x0204B6F4 arm
 *   BMP_OAM_SetPalette 0x02025A54 thumb
 */
#include "../include/Obj14459.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj;
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void BMP_OAM_SetPalette(u8 *g, u32 a);
void func_021FB5C4(char *p,int n) { func_0204B6F4(((struct Obj14459 *)p)->f0,(unsigned char)n,0);BMP_OAM_SetPalette(*(unsigned char * *)&((struct Obj14459 *)p)->f4,(unsigned char)(n+1)); }
