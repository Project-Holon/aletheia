/*
 * function: func_021FF248
 * address: 0x021FF248
 * packet: pkt_ov186_021FF248
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: int direction with explicit signed-char cast at use retains the original lsls/asrs byte truncation; a signed-char local folds it away and compiles 232/236 bytes.
 * Width: original caller truncates space and sine arguments to u16; full callee signatures otherwise copied.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_SetActorSurfacePosAxis 0x0204B49C arm
 *   CLACT_SetActorScaleAxis 0x0204B5D4 arm
 *   func_0203F684 0x0203F684 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../include/Obj00595.h"
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
struct Actor;
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void CLACT_SetActorSurfacePosAxis(struct Actor *actor, s16 value, u32 space, u32 axis);
extern void CLACT_SetActorScaleAxis(struct Actor *actor, u32 value, u32 which);
typedef signed int     s32;
extern short func_0203F684(unsigned short x);
void func_021FF248(char *p)
{
    int direction;
    int position;
    float value;
    ((struct Obj00595 *)p)->f28=(((struct Obj00595 *)p)->f28+1)%2;
    if(((struct Obj00595 *)p)->f28!=0)return;
    switch(((struct Obj00595 *)p)->f1C){
    case 0:
        func_0204B3DC(((struct Obj00595 *)p)->f4,1);
        CLACT_SetActorSurfacePosAxis(((struct Obj00595 *)p)->f4,((struct Obj00595 *)p)->f3C,(u16)(((struct Obj00595 *)p)->f44),0);
        if(((struct Obj00595 *)p)->f3C>0)value=0.5f+(float)(((struct Obj00595 *)p)->f3C<<12);
        else value=(float)(((struct Obj00595 *)p)->f3C<<12)-0.5f;
        ((struct Obj00595 *)p)->f10=(int)value;
        ((struct Obj00595 *)p)->f20=((struct Obj00595 *)p)->f40;
        ((struct Obj00595 *)p)->f1C=1;
        break;
    case 1:
        direction=-1;
        if(((struct Obj00595 *)p)->f48!=0)direction=1;
        position=((struct Obj00595 *)p)->f10+-(signed char)direction*(func_0203F684((u16)(((struct Obj00595 *)p)->f20*65535/360))*3);
        ((struct Obj00595 *)p)->f20+=((struct Obj00595 *)p)->f42;
        ((struct Obj00595 *)p)->f20%=360;
        CLACT_SetActorSurfacePosAxis(((struct Obj00595 *)p)->f4,position>>12,(u16)(((struct Obj00595 *)p)->f44),0);
        break;
    }
    if(((struct Obj00595 *)p)->f14>410){
        ((struct Obj00595 *)p)->f14-=410;
        CLACT_SetActorScaleAxis(((struct Obj00595 *)p)->f4,((struct Obj00595 *)p)->f14,0);
    }
}
