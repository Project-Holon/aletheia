/*
 * function: WF2DMAP_SCENE_VBlank
 * address:  0x021D893C
 * packet:   pkt_021D893C
 * region:   ov129
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PALANM_TransferPalettes  0x02021D50  thumb
 *   CLACT_VBlankSystem  0x0204A648  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23114.h"

struct S02021D50;
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern void CLACT_VBlankSystem(void);

void WF2DMAP_SCENE_VBlank(int a, char *p)
{
    PALANM_TransferPalettes((struct S02021D50 *)(((struct Obj23114 *)p)->f290));
    CLACT_VBlankSystem();
}
