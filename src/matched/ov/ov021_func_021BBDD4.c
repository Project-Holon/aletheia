/*
 * function: FLDEFF_FOOTMARK_SetMMdl
 * address:  0x021BBDD4
 * packet:   pkt_ov021_021BBDD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_GetDirDispOld  0x0216D5FC  thumb  ov010
 *   FLDEFF_FOOTMARK_GetSlotIndex  0x021BBD84  thumb  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_GetGridOldX  0x0216D804  thumb  ov010
 *   FLDMMDL_GetGridOldZ  0x0216D81C  thumb  ov010
 *   FLDMMDL_MOVE_GridToVectorPos  0x02164280  thumb  ov010
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   gFootmarkTaskHeader     0x021D9AF8  data  a4
 */
#include "../include/Obj20103.h"

typedef unsigned short u16;

typedef struct Vec {
    int x;
    int y;
    int z;
} Vec;

typedef struct Arg {
    int a;
    u16 h;
} Arg;

extern int gFootmarkTaskHeader;

typedef unsigned int   u32;
int FIELD_EFFECT_GetResource(u32 a, u32 b);
u16 FLDMMDL_GetDirDisp(void *p);
u16 FLDMMDL_GetDirDispOld(void *p);
int FLDEFF_FOOTMARK_GetSlotIndex(int a, int n, int x, int y);
struct Actor;
struct VecFx32;
void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
int FLDMMDL_GetGridOldX(void *p);
int FLDMMDL_GetGridOldZ(void *p);
void FLDMMDL_MOVE_GridToVectorPos(int x, int y, int *p);
void FIELD_EFFECT_AddObject(int a, void *b, Vec *c, int d, Arg *e, int f);

void FLDEFF_FOOTMARK_SetMMdl(int a, int b, int c)
{
    int x;
    int t;
    int u;
    int w;
    Vec v;
    Arg s;

    x = FIELD_EFFECT_GetResource(b, 5);
    s.a = x;
    t = FLDMMDL_GetDirDisp((void *)a);
    u = FLDMMDL_GetDirDispOld((void *)a);
    w = (u16)FLDEFF_FOOTMARK_GetSlotIndex(x, c, t, u);
    FLDMMDL_GetPos((const struct Actor *)a, (struct VecFx32 *)&v);
    t = FLDMMDL_GetGridOldX((void *)a);
    FLDMMDL_MOVE_GridToVectorPos(t, FLDMMDL_GetGridOldZ((void *)a), (int *)(&v));
    if (c == 0 && (u16)(w + 0xFFFE) <= 1) {
        v.z -= 0x2000;
    } else if (c == 4 && (u16)(w + 0xFFFE) <= 1) {
        v.z -= 0x2000;
    }
    if (c == 4) {
        v.y -= ((struct Obj20103 *)x)->f3C;
    }
    s.h = w;
    FIELD_EFFECT_AddObject(b, &gFootmarkTaskHeader, &v, 0, &s, 0);
}
