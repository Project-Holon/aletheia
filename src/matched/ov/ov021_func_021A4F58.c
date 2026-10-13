/*
 * function: FIELD_PLAYER_GRID_StartHopFallOnFoot
 * address:  0x021A4F58
 * packet:   pkt_ov021_021A4F58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The function returns int: v.y when the height is already at or under the
 * limit, 7 (the new state) otherwise. The only caller (FIELD_PLAYER_GRID_ApplyMoveResultOnFoot, case 9)
 * discards the value. Returning v.y on the early path ties the cross-block
 * v.y value to r0 (the return register), so the block-2 constant 0x8000 goes
 * to r1 and the subtract reads `subs r0, r0, r1`; the void form colours the
 * constant first into r0 and gives `subs r0, r1, r0` (three earlier rounds,
 * dozens of spellings). Leaving the final `return 7` out recolours the 7 to r1.
 * See docs/idioms/a-value-returned-on-the-early-path-precolours-its-register-to-r0.md.
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 */
#include "../include/Obj00262.h"

typedef unsigned int u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A4F58;

void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
struct Actor;
struct VecFx32;
void FLDMMDL_GetPos(const struct Actor *h, struct VecFx32 *v);
void FLDMMDL_MOVE_GetMapHeight(void *h, Vec021A4F58 *v, int *lim);
char *FLDMMDL_ClearMoveBit(char *p, u32 v);
void FLDMMDL_SetPos(void *h, Vec021A4F58 *v);

int FIELD_PLAYER_GRID_StartHopFallOnFoot(u32 *p, void *a1, u32 a2)
{
    void *h = FIELD_PLAYER_CORE_GetMmdl(*(unsigned char * *)&((struct Obj00262 *)p)->fC);
    Vec021A4F58 v;
    int lim;

    FLDMMDL_GetPos(h, (struct VecFx32 *)&v);
    FLDMMDL_MOVE_GetMapHeight(h, &v, &lim);
    if (v.y > lim) {
        v.y -= 0x8000;
        if (v.y < lim) {
            v.y = lim;
            FLDMMDL_ClearMoveBit(h, 0x8000);
            p[7] = 1;
        }
        FLDMMDL_SetPos(h, &v);
        p[0] = 7;
        return 7;
    }
    return v.y;
}
