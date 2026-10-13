/*
 * function: GIMMICK_OBJ_ELBOARD_Delete
 * address: 0x021F474C
 * packet: pkt_ov048_021F474C
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GF_FONT_Delete 0x0201D83C thumb
 *   GIMMICK_OBJ_ELBOARD_DeleteLine 0x021F4B40 thumb ov048
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj06156.h"
extern unsigned int GF_FONT_Delete(void *ptr);
extern void GIMMICK_OBJ_ELBOARD_DeleteLine(int *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void GIMMICK_OBJ_ELBOARD_Delete(unsigned char *p) { int i; GF_FONT_Delete((void *)(((struct Obj06156 *)p)->f14)); for(i=0;i<p[2];i++) GIMMICK_OBJ_ELBOARD_DeleteLine(((int **)((struct Obj06156 *)p)->f8)[i]); func_020307B0(((struct Obj06156 *)p)->f8); func_020307B0(((struct Obj06156 *)p)->fC); func_020307B0(p); }
