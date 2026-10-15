/*
 * unit: yes
 * function: STA_ACT_LIGHT_AnimF, STA_ACT_LIGHT_AnimG
 * address: 0x021F7ECC
 * packet: pkt_ov112_021F7ECC
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: 220-byte lead, 7FA8 two-byte return stub; 7FAA zero alignment padding.
 * function_starts: 0x021F7FA8
 * symbols:
 *   MUSICAL_MCSS_SetElemScale 0x021F4EA4 thumb ov112
 *   MUSICAL_MCSS_SetElemPos 0x021F4E8C thumb ov112
 *   MUSICAL_MCSS_SetElemRot 0x021F4EC4 thumb ov112
 *   MUSICAL_MCSS_SetElemRotZ 0x021F4EB4 thumb ov112
 *   MUSICAL_MCSS_SetElemVisible 0x021F4E6C thumb ov112
 *   GFL_USE_StopSeSlot 0x020061F8 thumb
 */
#include "../include/Obj04463.h"
#include "../include/Obj22565.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x,y,z; } Vec;
typedef struct { u16 count,pad; int index,a,b; } Tail;
typedef struct { short y,x; } Scale;
extern void MUSICAL_MCSS_SetElemScale(unsigned int unused, unsigned int p, unsigned int q);
extern void MUSICAL_MCSS_SetElemPos(int,int,Vec *);
typedef signed short   s16;
typedef unsigned int   u32;
extern void MUSICAL_MCSS_SetElemRot(u32 unused, u32 p, s16 *a, s16 *b);
extern void MUSICAL_MCSS_SetElemRotZ(u32 unused, u32 p, s16 a, s16 b);
extern void MUSICAL_MCSS_SetElemVisible(u8 *p, u8 *e, u32 value);
extern void GFL_USE_StopSeSlot(int);
void STA_ACT_LIGHT_AnimF(char *p,char *q)
{
    Tail *t=(Tail *)(q+0xf0);
    Vec v;
    Scale s;
    MUSICAL_MCSS_SetElemScale(((struct Obj04463 *)p)->f10,*(int *)(q+0x84+t->index*4),(unsigned int)(&v));
    t->b+=164;
    v.x-=2867;
    v.y+=t->b;
    v.z=0xc8000;
    MUSICAL_MCSS_SetElemPos(((struct Obj04463 *)p)->f10,*(int *)(q+0x84+t->index*4),&v);
    MUSICAL_MCSS_SetElemRot(((struct Obj04463 *)p)->f10,*(int *)(q+0x84+t->index*4),&s.x,&s.y);
    s.x+=12;
    s.y+=12;
    MUSICAL_MCSS_SetElemRotZ(((struct Obj04463 *)p)->f10,*(int *)(q+0x84+t->index*4),s.x,s.y);
    t->count++;
    if(t->count>=180) {
        MUSICAL_MCSS_SetElemVisible((u8 *)(((struct Obj04463 *)p)->f10),(u8 *)(*(int *)(q+0x84+t->index*4)),0);
        ((struct Obj22565 *)q)->f104=0;
        ((struct Obj04463 *)p)->f43C-=1;
        if(((struct Obj04463 *)p)->f43C==0) GFL_USE_StopSeSlot(2);
    }
}
void STA_ACT_LIGHT_AnimG(char *a0, char *a1)
{
}
