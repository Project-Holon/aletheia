/*
 * function: func_021B9A44
 * address:  0x021B9A44
 * packet:   pkt_ov069_021B9A44
 * region:   ov069
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call on the word loaded from offset 0x4.
 *
 * symbols:
 *   BGWINFRM_Delete  0x0202CA0C  thumb
 */
#include "../include/Obj01132.h"

struct WinMgr;
void func_021B9A44(void *p)
{
    void BGWINFRM_Delete(struct WinMgr *mgr);
    BGWINFRM_Delete(((struct Obj01132 *)p)->f4);
}
