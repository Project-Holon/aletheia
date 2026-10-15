/*
 * function: INTRO_G3D_SetAnimFrame
 * address: 0x021BFBC8
 * packet: pkt_ov204_021BFBC8
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_SetObjectAnimeFrame 0x0204784C arm
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../include/Obj14629.h"
typedef unsigned short u16;
typedef unsigned char  u8;
extern unsigned int func_02048A18(u8 *a0, int i);
typedef signed int     s32;
typedef unsigned int   u32;
struct AnmCtl;
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);
void INTRO_G3D_SetAnimFrame(char *p,unsigned value)
{
    void *ctl;
    int frame;
    float f;
    ctl=(void *)func_02048A18(((struct Obj14629 *)p)->f8,((struct Obj14629 *)p)->f10);
    if(value!=0) f=0.5f+(float)(value<<12);
    else f=(float)(value<<12)-0.5f;
    frame=(int)f;
    G3D_SYSTEM_SetObjectAnimeFrame(ctl,0,&frame);
    G3D_SYSTEM_SetObjectAnimeFrame(ctl,1,&frame);
    G3D_SYSTEM_SetObjectAnimeFrame(ctl,2,&frame);
}
