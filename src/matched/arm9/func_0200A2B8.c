/*
 * function: func_0200A2B8
 * address:  0x0200A2B8
 * packet:   pkt_0200A2B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocker:  021DFDC0 - overlay call with no branch anywhere in the image outside this range (ov228 carries a func_021DFDC0 label, so the region hint is satisfiable, but part 3 of attest_overlay_label has no site).  All 30 bytes right.
 * symbols:
 *   func_021DFDC0    0x021DFDC0  thumb
 */
#include "../include/Obj15586.h"

typedef unsigned char u8;

extern int   func_0200A350(void);
extern void  func_021DFDC0(void *p);
extern int func_02012DAC(int a0);

void func_0200A2B8(void *a0, int a1)
{
    if (func_0200A350() == 0) {
        func_021DFDC0(((struct Obj15586 *)a0)->f8);
    } else {
        func_02012DAC(a1);
    }
}
