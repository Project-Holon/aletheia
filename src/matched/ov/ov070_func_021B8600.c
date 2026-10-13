/*
 * function: func_021B8600
 * address:  0x021B8600
 * packet:   pkt_ov070_021B8600
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B97CC  0x021B97CC  thumb  ov070
 *   PALANM_TransferPalettes  0x02021D50  thumb
 *   func_0204A648  0x0204A648  arm
 */
#include "../include/Obj07689.h"

struct S02021D50;
extern void func_021B97CC(void *p, int v);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern void func_0204A648();

void func_021B8600(int u, int p)
{
    int s = ((struct Obj07689 *)p)->f840;
    if (s == 1) {
        func_021B97CC((void *)p, 1);
        ((struct Obj07689 *)p)->f840 = 0;
    } else if (s == 2) {
        func_021B97CC((void *)p, 0);
        ((struct Obj07689 *)p)->f840 = 0;
    }
    PALANM_TransferPalettes((struct S02021D50 *)(((struct Obj07689 *)p)->f854));
    func_0204A648();
}
