/*
 * function: FIELD_PLAYER_GRID_PlayStepSound
 * address:  0x021A43D8
 * packet:   pkt_ov021_021A43D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   COMM_PLAYER_SUPPORT_GetInfoCode  0x0202E83C  thumb
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_PLAYER_GRID_PlayTileSound  0x021A428C  thumb  ov021
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 */
#include "../include/Obj00656.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern int COMM_PLAYER_SUPPORT_GetInfoCode(void *a0);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern int FIELD_PLAYER_GRID_PlayTileSound(u8 *o, int unused, int c, int flag, int kind);
extern void FLDMMDL_MOVE_AddDirVector(int dir, int *p, int amt);

void FIELD_PLAYER_GRID_PlayStepSound(u8 *p, int k, int dir)
{
    u32 buf[3];
    void *a;
    u32 r;

    if (k != 2) {
        ((struct Obj00656 *)p)->f18 = 0x546;
        ((struct Obj00656 *)p)->f1A = 0;
        return;
    }
    a = FIELD_PLAYER_CORE_GetMmdl(((struct Obj00656 *)p)->fC);
    r = COMM_PLAYER_SUPPORT_GetInfoCode(FIELDMAP_GetGameSystem((void *)(((struct Obj00656 *)p)->f10)));
    FLDMMDL_GetPos(a, (struct VecFx32 *)buf);
    if (FIELD_PLAYER_GRID_PlayTileSound(p, k, (int)buf, 0, r) == 0) {
        FLDMMDL_MOVE_AddDirVector(dir, (int *)buf, 0x10000);
        FIELD_PLAYER_GRID_PlayTileSound(p, k, (int)buf, 1, r);
    }
}
