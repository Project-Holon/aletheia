/*
 * function: HALL_OF_FAME_OnMonAnimDone
 * address:  0x021B69E8
 * packet:   pkt_021B69E8
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker:  every concrete byte reproduces; the single call to
 *   MCSS_SetAnmStopFlag (0x02015E04) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 *
 * symbols:
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 */
#include "../include/Obj14403.h"

extern void MCSS_SetAnmStopFlag(void *p);

void HALL_OF_FAME_OnMonAnimDone(int *p)
{
    MCSS_SetAnmStopFlag((void *)(((struct Obj14403 *)p)->f1C));
    ((struct Obj14403 *)p)->f24 = 1;
}
