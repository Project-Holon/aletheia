/*
 * function: ISS_SYS_GetBgmMode
 * address:  0x0202B818
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the +4 field, and passes it and the low half of ISS_SYS_GetCurrentBgmId()'s
 * result to func_02006E7C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SYS_GetBgmMode.c \
 *       --func ISS_SYS_GetBgmMode --addr 0x0202B818 --thumb --cc 1.1p1
 *
 * symbols:
 *   GAME_DATA_GetBagCursor  0x0201295C  thumb
 *   ISS_SYS_GetCurrentBgmId  0x0202B810  thumb
 */
#include "../include/Obj15843.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

struct BigObj;
struct Sub02006E40Obj;
extern u32 GAME_DATA_GetBagCursor(const struct BigObj *p);
extern u32 ISS_SYS_GetCurrentBgmId(void);
extern u8 func_02006E7C(const struct Sub02006E40Obj *obj, u16 key);

u8 ISS_SYS_GetBgmMode(struct Obj *o)
{
    u32 r = GAME_DATA_GetBagCursor((const struct BigObj *)(((struct Obj15843 *)o)->f4));

    return func_02006E7C((const struct Sub02006E40Obj *)r, (u16)ISS_SYS_GetCurrentBgmId());
}
