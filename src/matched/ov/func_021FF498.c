/*
 * function: func_021FF498
 * address:  0x021FF498
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020160C4  0x020160C4  thumb
 *   func_022019F4  0x022019F4  thumb  ov094
 *
 * Byte-identical to the original; parked because the call to 0x020160C4
 * (an unlabelled ARM9 leaf, no traced label) has no witness outside the
 * compared range.  The call to 0x022019F4 is an ov094 Thumb function.
 */
#include "../include/Obj12220.h"


extern int  func_022019F4(char *p, int key);
extern void func_020160C4(char *p, int v);

void func_021FF498(char *p, int key, void *v)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return;
    e = p + i * 0x5c;
    if (((struct Obj12220 *)e)->f8 == 0)
        return;
    func_020160C4((char *)(((struct Obj12220 *)e)->f8), (int)v);
}

