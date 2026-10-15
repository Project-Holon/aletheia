/*
 * function: BR_UTIL_StartEffect
 * address: 0x021FD860
 * packet: pkt_ov186_021FD860
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * follower: 021FD938 already filed separately; lead excludes that existing accessor.
 * symbols:
 *   BR_UTIL_IsTaskStep 0x021FD750 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BR_UTIL_EffectFlyIn 0x021FDE88 thumb ov186
 *   BR_UTIL_EffectIdle 0x021FD964 thumb ov186
 *   BR_UTIL_EffectSpiral 0x021FD9A0 thumb ov186
 *   BR_UTIL_EffectFollow12 0x021FDA7C thumb ov186
 *   BR_UTIL_EffectFollow6 0x021FDBF4 thumb ov186
 *   BR_UTIL_EffectFlyInSlow 0x021FDF40 thumb ov186
 *   BR_UTIL_EffectNoop 0x021FDFF0 thumb ov186
 *   BR_UTIL_EffectToTarget 0x021FDFF4 thumb ov186
 *   BR_UTIL_EffectToPoint 0x021FE1C4 thumb ov186
 */
#include "../include/Obj02236.h"
typedef unsigned int u32;
typedef struct { int x,y; } Pair;
extern int BR_UTIL_IsTaskStep(int *,int);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
typedef unsigned char  u8;
extern void BR_UTIL_EffectFlyIn(void);
extern void BR_UTIL_EffectIdle(void *unused, int *state, u8 *p);
extern void BR_UTIL_EffectSpiral(void);
extern void BR_UTIL_EffectFollow12(void);
extern void BR_UTIL_EffectFollow6(void);
extern void BR_UTIL_EffectFlyInSlow(void);
extern void BR_UTIL_EffectNoop(void);
extern void BR_UTIL_EffectToTarget(void);
extern void BR_UTIL_EffectToPoint(int *task, int *state, char *p);
void BR_UTIL_StartEffect(char *p,u32 mode,const Pair *pair)
{
    if(pair) {
        *(Pair *)p=*pair;
        *(const Pair * *)&((struct Obj02236 *)p)->f8=pair;
    }
    ((struct Obj02236 *)p)->f22C=0;
    if(mode==0 && BR_UTIL_IsTaskStep(*(int * *)&((struct Obj02236 *)p)->f10,(int)BR_UTIL_EffectFlyIn)) GFL_USE_PlaySeDefaultVolume(0x701);
    switch(mode) {
    case 0: BR_UTIL_SetTaskStep(*(int * *)&((struct Obj02236 *)p)->f10,(int)BR_UTIL_EffectIdle);break;
    case 1: BR_UTIL_SetTaskStep(*(int * *)&((struct Obj02236 *)p)->f10,(int)BR_UTIL_EffectSpiral);break;
    case 2: BR_UTIL_SetTaskStep(*(int * *)&((struct Obj02236 *)p)->f10,(int)BR_UTIL_EffectFollow12);break;
    case 3: BR_UTIL_SetTaskStep(*(int * *)&((struct Obj02236 *)p)->f10,(int)BR_UTIL_EffectFollow6);break;
    case 4: BR_UTIL_SetTaskStep(*(int * *)&((struct Obj02236 *)p)->f10,(int)BR_UTIL_EffectFlyIn);break;
    case 5: BR_UTIL_SetTaskStep(*(int * *)&((struct Obj02236 *)p)->f10,(int)BR_UTIL_EffectFlyInSlow);break;
    case 6: BR_UTIL_SetTaskStep(*(int * *)&((struct Obj02236 *)p)->f10,(int)BR_UTIL_EffectNoop);break;
    case 7: BR_UTIL_SetTaskStep(*(int * *)&((struct Obj02236 *)p)->f10,(int)BR_UTIL_EffectToTarget);break;
    case 8: BR_UTIL_SetTaskStep(*(int * *)&((struct Obj02236 *)p)->f10,(int)BR_UTIL_EffectToPoint);break;
    }
}
