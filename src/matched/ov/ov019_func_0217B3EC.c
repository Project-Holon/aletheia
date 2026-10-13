/*
 * function: UNION_CHARA_TickBeaconLife
 * address:  0x0217B3EC
 * packet:   pkt_ov019_0217B3EC
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj07379.h"
#include "../include/Obj07380.h"

typedef unsigned short u16;

int UNION_CHARA_TickBeaconLife(char *base, char *p)
{
    char *q = base + 0x2830;
    if (*(char * *)&((struct Obj07380 *)q)->f14 == p || *(char * *)&((struct Obj07380 *)q)->f18 == p ||
        *(char * *)&((struct Obj07380 *)q)->f1C == p || *(char * *)&((struct Obj07380 *)q)->f20 == p) {
        if (((struct Obj07379 *)p)->f6C == 0) {
            ((struct Obj07379 *)p)->f6C = 1;
        }
        return 1;
    }
    if (((struct Obj07379 *)p)->f6C == 0) {
        return 0;
    }
    ((struct Obj07379 *)p)->f6C -= 1;
    return 1;
}
