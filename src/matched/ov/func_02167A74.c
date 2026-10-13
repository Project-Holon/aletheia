/*
 * function: COMM_PLAYER_CreateSys
 * address:  0x02167A74
 * packet:   pkt_02167A74
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_IsReady  0x02188BE8  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb
 *   FIELD_COMM_ACTOR_CTRL_Create  0x02194284  thumb
 */
#include "../include/Obj00020.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_IsReady(void *a);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern void *FIELD_COMM_ACTOR_CTRL_Create(int a, void *b, int heap, int c);

void COMM_PLAYER_CreateSys(int a0, int a1)
{
    int a2;
    int a3;
    int t4;
    void *res;
    void *v0;
    void *v1;

t4 = a1 + 0;
a1 = *(int *)&((struct Obj00020 *)t4)->f4;
    if (a1 != 0) goto loc_02167AAE;
loc_02167A7E:
    v0 = GAMESYSTEM_GetFieldMap((void *)a0);
loc_02167A82:
    if (v0 == 0) goto loc_02167AAE;
loc_02167A86:
    a0 = FIELDMAP_IsReady(v0);
loc_02167A8A:
    if (a0 == 0) goto loc_02167AAE;
loc_02167A8E:
    v1 = FIELDMAP_GetMmdlSys(v0);
loc_02167A94:
a0 = t4 + 0;
a2 = t4 + 0;
a3 = t4 + 0;
a0 = a0 + 0x8e;
a2 = a2 + 0x8c;
a3 = a3 + 0x90;
a0 = *(u8 *)&((struct Obj00020 *)((char *)a0))->f0;
a2 = *(u16 *)&((struct Obj00020 *)((char *)a2))->f0;
a3 = *(u8 *)&((struct Obj00020 *)((char *)a3))->f0;
    res = FIELD_COMM_ACTOR_CTRL_Create(a0, v1, a2, a3);
loc_02167AAC:
((struct Obj00020 *)t4)->f4 = res;
loc_02167AAE:
    return;}
