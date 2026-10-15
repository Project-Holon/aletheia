/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_GetMenuResult
 * address:  0x0217B368
 * packet:   pkt_0217B368
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * blocker:  every concrete byte reproduces; the single call to
 *   func_021E8A90 (0x021E8A90) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 *
 * symbols:
 *   func_021E8A90  0x021E8A90  thumb  ov177
 */
#include "../include/Obj14357.h"

extern int func_021E8A90(int **p);

int BATTLE_CHAMPIONSHIP_FLOW_GetMenuResult(int *p)
{
    if (func_021E8A90((int **)(((struct Obj14357 *)p)->f0)))
        return ((struct Obj14357 *)p)->f10;
    return 0;
}
