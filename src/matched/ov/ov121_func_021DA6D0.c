/*
 * function: func_021DA6D0
 * address: 0x021DA6D0
 * packet: pkt_ov121_021DA6D0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arithmetic: direct division helper uses quotient r0/remainder r1 as a scalar u64;
 *             the caller admits count zero, so ordinary C remainder is not used.
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetRepeat 0x0203633C arm
 *   _u32_div_f 0x0209C2B0 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_021DAAA4 0x021DAAA4 thumb ov121
 *   d_021DF76C 0x021DF76C data a4
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj00360.h"
#include "../include/Obj06450.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct {s16 x,y;} Position;
typedef struct {int x,y;} TablePair;
extern const TablePair d_021DF76C[];
extern u32 KEY_GetTrg(void);
extern u32 KEY_GetRepeat(void);
struct Obj;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern u64 _u32_div_f(u32,u32);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
typedef signed int     s32;
extern s32 func_021DAAA4(int a, u16 *p, int angle, int bank, u8 index, u16 c1, u16 c2);
int func_021DA6D0(u8 *p)
{
    u32 keys=KEY_GetTrg();
    u32 repeat=KEY_GetRepeat();
    int changed=0;
    int i;
    int phase;
    int oldphase;
    u32 index;
    Position pos;
    if(repeat&64) {
        index=((struct Obj00360 *)p)->f8==0 ? ((struct Obj00360 *)p)->fC-1 : ((struct Obj00360 *)p)->f8-1;
        ((struct Obj00360 *)p)->f8=index;
        if(((struct Obj00360 *)p)->fC!=1) GFL_USE_PlaySeDefaultVolume(0x548);
        changed=1;
    } else if(repeat&128) {
        if(((struct Obj00360 *)p)->fC!=1) GFL_USE_PlaySeDefaultVolume(0x548);
        ((struct Obj00360 *)p)->f8+=1;
        ((struct Obj00360 *)p)->f8=(u32)(_u32_div_f(((struct Obj00360 *)p)->f8,((struct Obj00360 *)p)->fC)>>32);
        changed=1;
    } else if(keys&1) {
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return ((struct Obj00360 *)p)->f8;
    } else if(keys&2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        if(((struct Obj00360 *)p)->fC==1) return -2;
        if(((struct Obj00360 *)p)->f8!=3) **(u32 * *)&((struct Obj00360 *)p)->f60=((struct Obj00360 *)p)->f8;
        ((struct Obj00360 *)p)->f8=((struct Obj00360 *)p)->fC-1;
        return ((struct Obj00360 *)p)->f8;
    }
    if(changed) {
        pos.x=d_021DF76C[*(u32 *)(p+8)].x;
        pos.y=d_021DF76C[*(u32 *)(p+8)].y+((struct Obj00360 *)p)->f2E*8;
        CLACT_AddActorSurfacePos(((struct Obj00360 *)p)->f4,(const struct Vec2 *)(&pos),0);
        if(((struct Obj00360 *)p)->f8==3) CLACT_SetActorAnimSeq(((struct Obj00360 *)p)->f4,2);
        else CLACT_SetActorAnimSeq(((struct Obj00360 *)p)->f4,((struct Obj00360 *)p)->f30);
        if(*(void (**)(u32))(p+0x34)) (*(void (**)(u32))(p+0x34))(((struct Obj00360 *)p)->f38);
    }
    oldphase=((struct Obj00360 *)p)->f24;
    phase=oldphase+0x400;
    if(phase>=0x10000) ((struct Obj00360 *)p)->f24=oldphase-0xfc00;
    else ((struct Obj00360 *)p)->f24=phase;
    for(i=0;i<4;i++) {
        u8 *v=p+i*4;
        if(((struct Obj06450 *)v)->f4C!=((struct Obj06450 *)v)->f3C && ((struct Obj00360 *)p)->f24>=0x7dff && ((struct Obj00360 *)p)->f24<=0x81ff)
            ((struct Obj06450 *)v)->f3C=((struct Obj06450 *)v)->f4C;
        if(((struct Obj06450 *)v)->f3C)
            func_021DAAA4((int)((void *)15),(u16 *)(p+0x1a+i*2),((struct Obj00360 *)p)->f24,(u8)(((struct Obj00360 *)p)->f2C),(u8)(i+10),*(u16 *)(p+0x12+i*2),((struct Obj00360 *)p)->f22);
    }
    return -1;
}
