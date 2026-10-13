/*
 * function: ITEMMENU_VBlankCallback
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
 *   ITEMMENU_SetLayersVisible  0x021B97CC  thumb  ov070
 *   PALANM_TransferPalettes  0x02021D50  thumb
 *   CLACT_VBlankSystem  0x0204A648  arm
 */
#include "../include/Obj07689.h"

struct S02021D50;
extern void ITEMMENU_SetLayersVisible(void *p, int v);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern void CLACT_VBlankSystem();

void ITEMMENU_VBlankCallback(int u, int p)
{
    int s = ((struct Obj07689 *)p)->f840;
    if (s == 1) {
        ITEMMENU_SetLayersVisible((void *)p, 1);
        ((struct Obj07689 *)p)->f840 = 0;
    } else if (s == 2) {
        ITEMMENU_SetLayersVisible((void *)p, 0);
        ((struct Obj07689 *)p)->f840 = 0;
    }
    PALANM_TransferPalettes((struct S02021D50 *)(((struct Obj07689 *)p)->f854));
    CLACT_VBlankSystem();
}
