/*
 * function: func_021B7C7C
 * address:  0x021B7C7C
 * packet:   pkt_021B7C7C
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * blocker:  every concrete byte reproduces; the single call to
 *   func_02025D14 (0x02025D14) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 *
 * symbols:
 *   func_02025D14  0x02025D14  thumb
 */
#include "../include/Obj24188.h"

typedef unsigned int   u32;
extern u32 func_02025D14(void *a0);

int func_021B7C7C(int *p)
{
    return func_02025D14((void *)(((struct Obj24188 *)p)->f1C8));
}
