/*
 * function: PSEL_DrawObjects
 * address: 0x021B97F8
 * packet: pkt_ov223_021B97F8
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 */
#include "../include/Obj03962.h"
#include "../include/Obj14786.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Arg;extern void *func_02048A18(u8 *,int);extern void G3D_SYSTEM_DrawObject(void *,struct Arg *);
void PSEL_DrawObjects(char *p) { u16 i;for(i=0;i<((struct Obj03962 *)p)->f3A;i++){char *q=(char *)(((struct Obj03962 *)p)->f3C+(u32)i*68);if(((struct Obj14786 *)q)->f40)G3D_SYSTEM_DrawObject(func_02048A18(*(u8 * *)&((struct Obj03962 *)p)->f28,((struct Obj14786 *)q)->f0),(struct Arg *)(q+4));} }
