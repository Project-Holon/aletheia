/*
 * function: FIELD_PLAYER_GRID_IsAtGroundHeight
 * address:  0x021A56C0
 * packet:   pkt_ov021_021A56C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 */
#include "../include/Obj12739.h"

typedef unsigned int u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A56C0;

void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
struct Actor;
struct VecFx32;
void FLDMMDL_GetPos(const struct Actor *h, struct VecFx32 *v);
void FLDMMDL_MOVE_GetMapHeight(void *h, Vec021A56C0 *v, int *lim);

u32 FIELD_PLAYER_GRID_IsAtGroundHeight(u32 *p, u32 a1, u32 a2, u32 a3)
{
    void *h = FIELD_PLAYER_CORE_GetMmdl(*(unsigned char * *)&((struct Obj12739 *)p)->fC);
    Vec021A56C0 v;
    int lim;

    FLDMMDL_GetPos(h, (struct VecFx32 *)&v);
    FLDMMDL_MOVE_GetMapHeight(h, &v, &lim);
    if (v.y <= lim)
        return 1;
    return 0;
}
