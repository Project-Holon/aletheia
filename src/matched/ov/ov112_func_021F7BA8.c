/*
 * function: STA_ACT_LIGHT_AnimB
 * address: 0x021F7BA8
 * packet: pkt_ov112_021F7BA8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_MCSS_GetRenderElem 0x021F5450 thumb ov112
 *   MUSICAL_MCSS_GetRenderMatrix 0x021F5464 thumb ov112
 *   MUSICAL_MCSS_SetElemScale 0x021F4EA4 thumb ov112
 *   VEC_Add 0x0207C9D0 arm
 *   STA_ACT_EFFECT_SetEmitterPos 0x021F9FD0 thumb ov132
 *   STA_ACTING_GetAnimHandle 0x021F9DC0 thumb ov132
 *   STA_ACT_EFFECT_KillEffect 0x021F9FB4 thumb ov132
 *   STA_ACT_EFFECT_KillSystem 0x021F9F58 thumb ov132
 *   GFL_USE_StopSeSlot 0x020061F8 thumb
 */
#include "../include/Obj06409.h"
#include "../include/Obj08028.h"
#include "../include/Obj22562.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x,y,z; } Vec;
typedef struct { u16 count,pad; int index,a,b; } Tail;
extern u8 *MUSICAL_MCSS_GetRenderElem(u8 *,int);
extern char *MUSICAL_MCSS_GetRenderMatrix(char *);
typedef unsigned int   u32;
extern void MUSICAL_MCSS_SetElemScale(u32 unused, u32 p, u32 q);
extern void VEC_Add(const Vec *,const Vec *,Vec *);
extern void STA_ACT_EFFECT_SetEmitterPos(char *,int,int);
extern void *STA_ACTING_GetAnimHandle(void *p);
extern void STA_ACT_EFFECT_KillEffect(char *,int);
extern void STA_ACT_EFFECT_KillSystem(u8 *unused, u8 *p);
extern void GFL_USE_StopSeSlot(int);
void STA_ACT_LIGHT_AnimB(u8 *p,u8 *q)
{
    Tail *t=(Tail *)(q+240);
    u8 *r=MUSICAL_MCSS_GetRenderElem(*(u8 * *)&((struct Obj06409 *)q)->f58,((struct Obj06409 *)q)->fF4);
    Vec v;
    int a;
    if(((struct Obj06409 *)q)->f8==1 && ((struct Obj22562 *)r)->f0==1) {
        MUSICAL_MCSS_SetElemScale(((struct Obj08028 *)p)->f10,*(int *)(q+132+t->index*4),(u32)(&v));
        v.x/=16;
        v.y=(0xc0000-v.y)/16;
        v.z+=0x1000;
    } else {
        VEC_Add((Vec *)(q+24),(Vec *)MUSICAL_MCSS_GetRenderMatrix(*(char * *)&((struct Obj06409 *)q)->f58),&v);
        v.x/=16;
        v.y=(0xc0000-v.y)/16;
        v.z-=0x1c000;
    }
    STA_ACT_EFFECT_SetEmitterPos((char *)t->a,0,(int)&v);
    t->count++;
    if(t->count>=180) {
        a=(int)STA_ACTING_GetAnimHandle((void *)(((struct Obj08028 *)p)->f4));
        STA_ACT_EFFECT_KillEffect((char *)t->a,0);
        STA_ACT_EFFECT_KillSystem((void *)a,(void *)t->a);
        ((struct Obj06409 *)q)->f104=0;
        ((struct Obj08028 *)p)->f43C-=1;
        if(((struct Obj08028 *)p)->f43C==0) GFL_USE_StopSeSlot(2);
    }
}
