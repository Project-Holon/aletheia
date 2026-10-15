/*
 * function: DIGITALCARDCHECK_DeleteAlt
 * address:  0x0217D434
 * packet:   pkt_0217D434
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker:  every concrete byte reproduces; the single call to
 *   WIFIBATTLEMATCH_VIEW_UpdatePokeList (0x021E64C0) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 *
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_InvokeCallback  0x021E8A80  thumb  ov177
 *   WIFIBATTLEMATCH_VIEW_UpdatePokeList  0x021E64C0  thumb  ov177
 */
#include "../include/Obj08285.h"

extern void WIFIBATTLEMATCH_UTIL_InvokeCallback(int);
extern int WIFIBATTLEMATCH_VIEW_UpdatePokeList(unsigned char *, void *);

void DIGITALCARDCHECK_DeleteAlt(int *p)
{
    WIFIBATTLEMATCH_UTIL_InvokeCallback(((struct Obj08285 *)p)->f10);
    if (((struct Obj08285 *)p)->f8)
        WIFIBATTLEMATCH_VIEW_UpdatePokeList((unsigned char *)((struct Obj08285 *)p)->f8, (void *)((struct Obj08285 *)p)->f24);
}
