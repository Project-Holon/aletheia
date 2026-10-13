/*
 * function: MYSTERY_DATA_SaveMain
 * address:  0x0200A2D8
 * packet:   pkt_0200A2B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  021DFE00 - same shape as MYSTERY_DATA_SaveStart's blocker: ov228 labels it, no branch outside this range reaches it.  All 40 bytes right.
 * symbols:
 *   func_021DFE00    0x021DFE00  thumb
 *   MYSTERY_DATA_IsMainSave  0x0200A350  thumb
 */
#include "../include/Obj15587.h"

typedef unsigned char u8;

struct Obj;
extern int MYSTERY_DATA_IsMainSave(struct Obj *a0);
extern int  func_021DFE00(void *p);
extern int func_02012DD0(u8 *p);

int MYSTERY_DATA_SaveMain(void *a0, int a1)
{
    if (MYSTERY_DATA_IsMainSave(a0) == 0) {
        if (func_021DFE00(((struct Obj15587 *)a0)->f8) != 0)
            return 2;
        return 0;
    }
    return func_02012DD0((u8 *)a1);
}
