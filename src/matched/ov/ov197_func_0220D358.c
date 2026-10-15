/*
 * function: B_BAG_MAIN_StateWaitKey
 * address: 0x0220D358
 * packet: pkt_ov197_0220D358
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: explicit else preserves the nonzero arm after the field-return arm.
 * leaf: parent-cleared 24-byte follower in D328 extent.
 */
#include "../include/Obj14551.h"
int B_BAG_MAIN_StateWaitKey(char *p)
{
    if (((struct Obj14551 *)p)->f527 == 0) {
        return ((struct Obj14551 *)p)->f531;
    } else {
        return 16;
    }
}
