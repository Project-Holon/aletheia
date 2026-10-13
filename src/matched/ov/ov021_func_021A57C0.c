/*
 * function: FIELD_PLAYER_GRID_GetHeightStep
 * address:  0x021A57C0
 * packet:   pkt_ov021_021A57C0
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
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00262.h"

typedef unsigned char u8;

typedef struct Vec3 {
    int x;
    int y;
    int z;
} Vec3;

extern void *FIELD_PLAYER_CORE_GetMmdl(u8 *p);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
extern void FLDMMDL_MOVE_AddDirVector(int dir, int *p, int amt);
extern int  FLDMMDL_MOVE_GetMapHeight(u8 *a, Vec3 *p, int *out);

int FIELD_PLAYER_GRID_GetHeightStep(u8 *p, int dir)
{
    u8 *a;
    int y;
    Vec3 pos;
    int lim;

    a = FIELD_PLAYER_CORE_GetMmdl(*(u8 * *)&((struct Obj00262 *)p)->fC);
    FLDMMDL_GetPos((const struct Actor *)a, (struct VecFx32 *)&pos);
    y = pos.y;
    FLDMMDL_MOVE_AddDirVector(dir, (int *)(&pos), 0x10000);
    if (FLDMMDL_MOVE_GetMapHeight(a, &pos, &lim) == 1) {
        if (y < lim) {
            return 1;
        }
        if (y > lim) {
            return 2;
        }
    }
    return 0;
}
