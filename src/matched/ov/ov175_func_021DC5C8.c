/*
 * function: func_021DC5C8
 * address:  0x021DC5C8
 * packet:   pkt_021DC5C8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note:     the listing extent (72 B) runs into the neighbour's `mov r8,r8`
 *           pad and pool word; all 48 compiled bytes match.
 *
 * symbols:
 *   NHTTP_RAP_DeleteConnection   0x021B9774  thumb  ov114
 *   NHTTP_RAP_Destroy   0x021B9838  thumb  ov114
 *   func_021DAE18   0x021DAE18  thumb  ov175
 *
 * Kind 3 or 6 teardown of the +0x121c sub-object: its handle is unregistered
 * from both pools, the slot cleared, and the object recomputed.
 */
#include "../include/Obj03320.h"

typedef unsigned int u32;

typedef unsigned char  u8;
extern void NHTTP_RAP_DeleteConnection(u8 *p);
extern void NHTTP_RAP_Destroy(u8 *p);
extern void func_021DAE18(char *obj);

void func_021DC5C8(void *p, int unused, int kind)
{
    if (kind != 3 && kind != 6)
        return;
    if (((struct Obj03320 *)p)->f121C != 0) {
        NHTTP_RAP_DeleteConnection((u8 *)(((struct Obj03320 *)p)->f121C));
        NHTTP_RAP_Destroy((u8 *)(((struct Obj03320 *)p)->f121C));
        ((struct Obj03320 *)p)->f121C = 0;
    }
    func_021DAE18(p);
}
