/*
 * function: GAME_BEACON_UpdateActionTime
 * address:  0x02026824
 * packet:   pkt_020266E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAME_BEACON_ActionTable  0x0209FC20  data
 *
 */
#include "../include/Obj05716.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

struct Obj;

extern const u32 GAME_BEACON_ActionTable[];

void GAME_BEACON_UpdateActionTime(struct Obj *o)
{
    u16 n = ((struct Obj05716 *)o)->f30;

    if (n == 1) {
        return;
    }
    ((struct Obj05716 *)o)->f5C += 1;
    if ((u32)((struct Obj05716 *)o)->f5C > (GAME_BEACON_ActionTable[n] >> 8)) {
        *(u16 *)&((struct Obj05716 *)o)->f5C = 0;
        ((struct Obj05716 *)o)->f30 = 1;
    }
}
