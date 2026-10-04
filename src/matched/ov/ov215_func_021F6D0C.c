/*
 * function: func_021F6D0C
 * address:  0x021F6D0C
 * packet:   pkt_021F6D0C
 * region:   ov215
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02015E04 0x02015E04 thumb
 *
 * blocker: 0x02015E04 is an unlabelled ARM9 leaf (no func_ label, no SDK
 *   entry), so neither label nor sole-ref/code can attest the bl site;
 *   byte-correct.
 */
#include "../include/Obj14711.h"

extern void func_02015E04(void *p);

int func_021F6D0C(char *a)
{
    func_02015E04((void *)(((struct Obj14711 *)a)->f34));
    ((struct Obj14711 *)a)->f38 = 1;
    return 1;
}