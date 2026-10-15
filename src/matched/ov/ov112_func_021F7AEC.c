/*
 * function: STA_ACT_LIGHT_AnimA
 * address: 0x021F7AEC
 * packet: pkt_ov112_021F7AEC
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero padding before 021F7BA8.
 * symbols:
 *   STA_ACTING_GetAnimHandle 0x021F9DC0 thumb ov132
 *   STA_ACT_EFFECT_StartSystem 0x021F9EDC thumb ov132
 *   STA_ACT_EFFECT_StartEffect 0x021F9F74 thumb ov132
 *   MUSICAL_MCSS_GetRenderElem 0x021F5450 thumb ov112
 *   MUSICAL_MCSS_GetRenderMatrix 0x021F5464 thumb ov112
 *   VEC_Add 0x0207C9D0 arm
 *   MUSICAL_MCSS_SetElemScale 0x021F4EA4 thumb ov112
 */
#include "../include/Obj08027.h"
#include "../include/Obj13843.h"
#include "../include/Obj22561.h"
typedef struct { int x, y, z; } Vec;
typedef struct { short count, pad; int index, a, b; } Tail;
typedef unsigned short u16;
extern void *STA_ACTING_GetAnimHandle(void *p);
typedef unsigned int   u32;
extern char *STA_ACT_EFFECT_StartSystem(char *p, u32 a);
extern void STA_ACT_EFFECT_StartEffect(int, int, Vec *);
extern char *MUSICAL_MCSS_GetRenderElem(char *, int);
extern char *MUSICAL_MCSS_GetRenderMatrix(char *p);
extern void VEC_Add(Vec *, Vec *, Vec *);
extern void MUSICAL_MCSS_SetElemScale(u32 unused, u32 p, u32 q);
void STA_ACT_LIGHT_AnimA(char *p, char *q) {
    Tail *t = (Tail *)(q + 0xf0);
    int a = (int)STA_ACTING_GetAnimHandle((void *)(((struct Obj13843 *)p)->f4));
    char *r = MUSICAL_MCSS_GetRenderElem(*(char * *)&((struct Obj08027 *)q)->f58, ((struct Obj08027 *)q)->fF4);
    Vec v;
    t->a = (int)STA_ACT_EFFECT_StartSystem((char *)a, 0x35);
    if (((struct Obj08027 *)q)->f8 == 1 && ((struct Obj22561 *)r)->f0 == 1) {
        MUSICAL_MCSS_SetElemScale(((struct Obj13843 *)p)->f10, *(int *)(q + 0x84 + t->index * 4), (u32)(&v));
        v.x /= 16;
        v.y = (0xc0000 - v.y) / 16;
        v.z += 0x1000;
    } else {
        VEC_Add((Vec *)(q + 0x18), (Vec *)MUSICAL_MCSS_GetRenderMatrix(*(char * *)&((struct Obj08027 *)q)->f58), &v);
        v.x /= 16;
        v.y = (0xc0000 - v.y) / 16;
        v.z -= 0x1c000;
    }
    STA_ACT_EFFECT_StartEffect(t->a, 0, &v);
}
