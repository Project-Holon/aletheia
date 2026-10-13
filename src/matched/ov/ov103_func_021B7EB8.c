/*
 * function: func_021B7EB8
 * address: 0x021B7EB8
 * packet: pkt_ov103_021B7EB8
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: 2-byte zero padding before the next labelled function.
 * symbols:
 *   G3D_SYSTEM_DeleteObject 0x02047738 arm
 *   G3D_SYSTEM_DeleteAnime 0x0204762C arm
 *   G3D_SYSTEM_DeleteRender 0x02047504 arm
 *   func_02046EFC 0x02046EFC arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj10242.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
struct Rec;
extern void G3D_SYSTEM_DeleteObject(struct Rec *p); extern void G3D_SYSTEM_DeleteAnime(int); extern void G3D_SYSTEM_DeleteRender(int); extern void func_02046EFC(int); extern void func_02082BCC(void *,int,int);
void func_021B7EB8(u8 *p) { int i; G3D_SYSTEM_DeleteObject((struct Rec *)(((struct Obj10242 *)p)->f10)); for(i=0;i<2;i++) {if(*(int *)(p+20+i*4))G3D_SYSTEM_DeleteAnime(*(int *)(p+20+i*4));} G3D_SYSTEM_DeleteRender(((struct Obj10242 *)p)->fC); for(i=0;i<2;i++)func_02046EFC(*(int *)(p+4+i*4)); func_02046EFC(((struct Obj10242 *)p)->f0); func_02082BCC(p,0,0x60); }
