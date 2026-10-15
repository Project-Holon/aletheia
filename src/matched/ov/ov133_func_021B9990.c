/*
 * function: DUP_FITTING_StepPoseRotate
 * address: 0x021B9990
 * packet: pkt_ov133_021B9990
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   DUP_FITTING_SetModelTransform 0x021B765C thumb ov133
 *   table 0x020A1B38 data a2
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _ffixu 0x0209C4C8 arm
 */
#include "../include/Obj00228.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void *DUP_FITTING_SetModelTransform(u8 *p, u16 base, s16 speed, u16 rx, u16 ry);
extern int _s32_div_f(int,int);
extern const s16 table[];
void DUP_FITTING_StepPoseRotate(u8 *p,u16 a,int delta,u16 duration)
{
    int step,index;
    ((struct Obj00228 *)p)->f18=0;
    ((struct Obj00228 *)p)->f14=0;
    CLACT_SetActorDrawEnable(((struct Obj00228 *)p)->f1854,1);
    step=_s32_div_f(delta,duration);
    index=((u16)((int)((unsigned)a-(unsigned)step*((struct Obj00228 *)p)->f1844+65536)%65536)>>4)*2;
    *(unsigned *)&((struct Obj00228 *)p)->f1C=(unsigned)((float)(72*table[index]+0x80000)/4096.0f);
    *(unsigned *)&((struct Obj00228 *)p)->f20=(unsigned)((float)(48*table[index+1]+0x50000)/4096.0f);
    ((struct Obj00228 *)p)->f182C-=(u16)step;
    DUP_FITTING_SetModelTransform(p,((struct Obj00228 *)p)->f182C,step,72,48);
    ++((struct Obj00228 *)p)->f1844;
    if(((struct Obj00228 *)p)->f1844>duration) {
        ((struct Obj00228 *)p)->f1844=0;
        ++p[0x1846];
    }
}
