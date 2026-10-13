/*
 * function: ISS_ZONE_SYS_Delete
 * address:  0x0202BEA4
 * packet:   pkt_0202BE00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Releases the +8 pointer when set, then the object itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ZONE_SYS_Delete.c \
 *       --func ISS_ZONE_SYS_Delete --addr 0x0202BEA4 --thumb --cc 1.1p1
 */
#include "../include/Obj11316.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_020307B0(void *p);

void ISS_ZONE_SYS_Delete(u8 *p)
{
    if (*(u32 *)&((struct Obj11316 *)p)->f8 != 0) {
        func_020307B0(((struct Obj11316 *)p)->f8);
    }
    func_020307B0(p);
}
