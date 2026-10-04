/*
 * function: func_0217D434
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
 *   func_021E64C0 (0x021E64C0) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 *
 * symbols:
 *   func_021E8A80  0x021E8A80  thumb  ov177
 *   func_021E64C0  0x021E64C0  thumb  ov177
 */
#include "../include/Obj08285.h"

extern void func_021E8A80(int);
extern int func_021E64C0(unsigned char *, void *);

void func_0217D434(int *p)
{
    func_021E8A80(((struct Obj08285 *)p)->f10);
    if (((struct Obj08285 *)p)->f8)
        func_021E64C0((unsigned char *)((struct Obj08285 *)p)->f8, (void *)((struct Obj08285 *)p)->f24);
}
