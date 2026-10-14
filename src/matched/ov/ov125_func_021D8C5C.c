/*
 * function: GDS_SOCKET_FreeSslServerName
 * address:  0x021D8C5C
 * packet:   pkt_021D8C5C
 * region:   ov125
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * If the object's 0x800 field is set, hand it to GDS_SOCKET_Free and clear it.
 *
 * symbols:
 *   GDS_SOCKET_Free  0x021D7C90  arm  ov125
 */
#include "../include/Obj14014.h"

void GDS_SOCKET_Free(int x);

void GDS_SOCKET_FreeSslServerName(void *p)
{
    int v;

    v = ((struct Obj14014 *)p)->f800;
    if (v == 0)
        return;
    GDS_SOCKET_Free(v);
    ((struct Obj14014 *)p)->f800 = 0;
}
