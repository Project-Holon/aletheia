/*
 * function: GTSNEGO_MSG_DeleteTileHandle
 * address:  0x021D6C64
 * packet:   pkt_021D6C64
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00199.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 func_020307B0(void *p);

void GTSNEGO_MSG_DeleteTileHandle(u8 *p)
{
    void *q = ((struct Obj00199 *)p)->f120;
    if (q) {
        func_020307B0(q);
        *(u32 *)&((struct Obj00199 *)p)->f120 = 0;
    }
}
