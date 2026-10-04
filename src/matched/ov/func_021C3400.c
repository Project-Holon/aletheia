/*
 * function: func_021C3400
 * address:  0x021C3400
 * packet:   pkt_021C3400
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf in ov021 (the listing prints it as a `.word` run at
 * 0x021C3400, next to ov010's field-VM code); ov010's func_0215CE98 reaches
 * it across the overlay pair.  Eight-byte thunk: load [a+8] and tail-call
 * the ARM9 helper.
 *
 * symbols:
 *   func_0200BCA0  0x0200BCA0  thumb
 */
#include "../include/Obj18300.h"

typedef int s32;

extern int func_0200BCA0(int);

int func_021C3400(void *a)
{
    return func_0200BCA0(((struct Obj18300 *)a)->f8);
}
