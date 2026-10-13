/*
 * function: FIELD_PLAYER_GRID_GetAttrAtDir
 * address:  0x021A5788
 * packet:   pkt_ov021_021A5788
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetPos  0x021A3898  thumb  ov021
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_MOVE_GetMapAttr  0x02163E34  thumb  ov010
 */
#include "../include/Obj09571.h"

typedef unsigned int u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A5788;

struct VecFx32;
void FIELD_PLAYER_CORE_GetPos(unsigned char *p, struct VecFx32 *out);
void FLDMMDL_MOVE_AddDirVector(int dir, int *p, int amt);
void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
void FLDMMDL_MOVE_GetMapAttr(void *h, Vec021A5788 *v, int *out);

void FIELD_PLAYER_GRID_GetAttrAtDir(u32 *p, int k, int *out)
{
    Vec021A5788 v;

    FIELD_PLAYER_CORE_GetPos(*(unsigned char * *)&((struct Obj09571 *)p)->fC, (struct VecFx32 *)&v);
    if (k != 9)
        FLDMMDL_MOVE_AddDirVector(k, (int *)(&v), 0x10000);
    FLDMMDL_MOVE_GetMapAttr(FIELD_PLAYER_CORE_GetMmdl(*(unsigned char * *)&((struct Obj09571 *)p)->fC), &v, out);
}
