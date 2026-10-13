/*
 * function: func_0220BD14
 * address:  0x0220BD14
 * packet:   pkt_0220BD14
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BGWINFRM_Delete 0x0202CA0C thumb
 */
#include "../include/Obj25014.h"

struct WinMgr;
extern void BGWINFRM_Delete(struct WinMgr *mgr);

void func_0220BD14(char *a)
{
    BGWINFRM_Delete(*(struct WinMgr * *)&((struct Obj25014 *)a)->f520);
}
