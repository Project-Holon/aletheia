/*
 * function: func_021F6EF8
 * address: 0x021F6EF8
 * packet: pkt_ov215_021F6EF8
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   G3D_UTIL_Create 0x02047CFC arm
 */
#include "../include/Obj00317.h"
typedef unsigned short u16;
struct Util;
extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned,unsigned);
extern struct Util *G3D_UTIL_Create(u16,u16,u16);
void func_021F6EF8(char *p){unsigned z=0;G3D_SYSTEM_SetSwapBuffersMode(1,z);*(struct Util * *)&((struct Obj00317 *)p)->f48=G3D_UTIL_Create(4,1,((struct Obj00317 *)p)->f0);((struct Obj00317 *)p)->f50=z;}
