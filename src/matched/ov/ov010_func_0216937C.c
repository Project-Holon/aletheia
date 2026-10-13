/*
 * function: FIELD_G3D_MAP_OpenArchive
 * address: 0x0216937C
 * packet: pkt_ov010_0216937C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELD_G3D_MAP_Reset 0x0216990C thumb ov010
 *   FIELD_G3D_MAP_CloseArchive 0x021693A0 thumb ov010
 *   func_020490F4 0x020490F4 arm
 */
#include "../include/Obj00306.h"
#include "../include/Obj19036.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void FIELD_G3D_MAP_Reset(u8 *);
extern void FIELD_G3D_MAP_CloseArchive(int a0);
extern void *func_020490F4(unsigned int id, unsigned int heap);
void FIELD_G3D_MAP_OpenArchive(u8 *p,int a,int b) { FIELD_G3D_MAP_Reset(p); FIELD_G3D_MAP_CloseArchive((int)p); ((struct Obj19036 *)(*(u8 * *)&((struct Obj00306 *)p)->f2C))->f4=0; ((struct Obj00306 *)p)->f10=func_020490F4(a,b); }
