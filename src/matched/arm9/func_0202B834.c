/*
 * function: ISS_SYS_HasBgmChanged
 * address:  0x0202B834
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Compares the +8 field against ISS_SYS_GetCurrentBgmId() (the +4 field by way of
 * GAME_DATA_GetMyPlayerWork) and returns 1 when they differ, 0 when they match.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SYS_HasBgmChanged.c \
 *       --func ISS_SYS_HasBgmChanged --addr 0x0202B834 --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_SYS_GetCurrentBgmId  0x0202B810  thumb
 */
#include "../include/Obj15844.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;

extern u32 ISS_SYS_GetCurrentBgmId(void);

u32 ISS_SYS_HasBgmChanged(struct Obj *o)
{
    if (((struct Obj15844 *)o)->f8 == ISS_SYS_GetCurrentBgmId()) {
        return 0;
    }
    return 1;
}
