/*
 * function: BTLV_SCD_WaitBackTouchStep
 * address: 0x0689A84C
 * packet: pkt_ov095_0689A84C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Callee result remains live on return; extent ends with two-byte alignment padding.
 * symbols:
 *   func_0689A868 0x0689A868 thumb ov095
 */
#include "../include/Obj13635.h"
typedef unsigned int u32;
extern int func_0689A868(u32);

int BTLV_SCD_WaitBackTouchStep(u32 unused, u32 p)
{
    int result;
    result = func_0689A868(((struct Obj13635 *)p)->fB0);
    if (result == 1) {
        ((struct Obj13635 *)p)->f98 = 1;
    }
    return result;
}
