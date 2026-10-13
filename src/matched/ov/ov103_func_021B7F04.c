/*
 * function: func_021B7F04
 * address: 0x021B7F04
 * packet: pkt_ov103_021B7F04
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: Verified against the ov103 Thumb image.
 * symbols:
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 *   G3D_SYSTEM_GetObjectAnimeFrame 0x02047828 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 */
#include "../include/Obj06366.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount); extern void G3D_SYSTEM_GetObjectAnimeFrame(int,int,int *); extern void G3D_SYSTEM_DrawObject(int,void *);
void func_021B7F04(u8 *p) { int i,x,y; if(((struct Obj06366 *)p)->f58) { for(i=0;i<2;i++) G3D_SYSTEM_LoopObjectAnimeFrame((void *)(((struct Obj06366 *)p)->f10),(u16)i,4096); G3D_SYSTEM_GetObjectAnimeFrame(((struct Obj06366 *)p)->f10,0,&x); y=0; if(x==0)y=1; ((struct Obj06366 *)p)->f5C=y; G3D_SYSTEM_DrawObject(((struct Obj06366 *)p)->f10,p+0x1c); } }
