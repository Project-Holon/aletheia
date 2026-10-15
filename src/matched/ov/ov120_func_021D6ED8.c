/*
 * function: GTSNEGO_MSG_DeleteCursorActor
 * address:  0x021D6ED8
 * packet:   pkt_021D6ED8
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00199.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void GTSNEGO_MSG_DeleteCursorActor(u8 *p)
{
    void *q = ((struct Obj00199 *)p)->f138;
    if (q)
        CLACT_DeleteActor(q);
    *(u32 *)&((struct Obj00199 *)p)->f138 = 0;
}
