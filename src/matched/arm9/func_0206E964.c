/*
 * function: func_0206E964
 * address:  0x0206E964
 * packet:   pkt_0206E964
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * BTX0 header walk: the halfword at +12 is the offset of the info block and
 * the halfword at +14 selects the entry form (1 = the 'BTX0' magic form).
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206E964.c \
 *       --func func_0206E964 --addr 0x0206E964 --cc 1.1p1 --arm
 */
#include "../include/Obj04802.h"
#include "../include/Obj11639.h"

typedef unsigned short u16;
typedef unsigned int   u32;

unsigned char *func_0206E964(unsigned char *p)
{
    unsigned char *q = p + ((struct Obj04802 *)p)->fC;

    if (((struct Obj04802 *)p)->fE == 1) {
        if (((struct Obj04802 *)p)->f0 == 0x30585442u)
            return p + ((struct Obj11639 *)q)->f0;
        return 0;
    }
    return p + ((struct Obj11639 *)q)->f4;
}
