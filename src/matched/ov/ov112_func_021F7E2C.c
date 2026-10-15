/*
 * function: STA_ACT_LIGHT_AnimE
 * address: 0x021F7E2C
 * packet: pkt_ov112_021F7E2C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_MCSS_GetRenderElem 0x021F5450 thumb ov112
 *   MUSICAL_MCSS_GetRenderMatrix 0x021F5464 thumb ov112
 *   VEC_Add 0x0207C9D0 arm
 *   MUSICAL_MCSS_SetElemPos 0x021F4E8C thumb ov112
 *   MUSICAL_MCSS_SetElemVisible 0x021F4E6C thumb ov112
 *   MUSICAL_MCSS_SetElemField 0x021F4ED4 thumb ov112
 *   MUSICAL_MCSS_SetElemRotZ 0x021F4EB4 thumb ov112
 */
#include "../include/Obj06411.h"
#include "../include/Obj08031.h"
#include "../include/Obj22564.h"
typedef struct { int x, y, z; } Vec;
typedef struct { short count, pad; int index, a, b; } Tail;
extern char *MUSICAL_MCSS_GetRenderElem(char *, int);
extern char *MUSICAL_MCSS_GetRenderMatrix(char *p);
extern void VEC_Add(Vec *, Vec *, Vec *);
extern void MUSICAL_MCSS_SetElemPos(int, int, Vec *);
typedef unsigned char  u8;
extern void MUSICAL_MCSS_SetElemVisible(u8 *p, u8 *e, unsigned int value);
typedef signed short   s16;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void MUSICAL_MCSS_SetElemField(u32 unused, u32 p, u16 v);
extern void MUSICAL_MCSS_SetElemRotZ(u32 unused, u32 p, s16 a, s16 b);
void STA_ACT_LIGHT_AnimE(char *p, char *q) {
    Tail *t = (Tail *)(q + 0xf0);
    char *r = MUSICAL_MCSS_GetRenderElem(*(char * *)&((struct Obj06411 *)q)->f58, ((struct Obj06411 *)q)->fF4);
    Vec v;
    *(int *)(q + 0xcc + ((struct Obj06411 *)q)->fF4 * 4) = 0;
    if (((struct Obj06411 *)q)->f8 == 0 || ((struct Obj22564 *)r)->f0 == 0) {
        VEC_Add((Vec *)(q + 0x18), (Vec *)MUSICAL_MCSS_GetRenderMatrix(*(char * *)&((struct Obj06411 *)q)->f58), &v);
        MUSICAL_MCSS_SetElemPos(((struct Obj08031 *)p)->f10, *(int *)(q + 0x84 + t->index * 4), &v);
    }
    t->b = -0x3000;
    MUSICAL_MCSS_SetElemVisible((u8 *)(((struct Obj08031 *)p)->f10), (u8 *)(*(int *)(q + 0x84 + t->index * 4)), 1);
    MUSICAL_MCSS_SetElemField(((struct Obj08031 *)p)->f10, *(int *)(q + 0x84 + t->index * 4), 0);
    MUSICAL_MCSS_SetElemRotZ(((struct Obj08031 *)p)->f10, *(int *)(q + 0x84 + t->index * 4), 1024, 1024);
}
