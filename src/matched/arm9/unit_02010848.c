/*
 * unit:     yes
 * address:  0x02010848
 * packet:   pkt_020107FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: WIH_DWC_GetAlertLevel, WIH_DWC_RequestAlertLevel, WIH_DWC_Dummy
 * symbols:
 *   gWihDwc     0x021461E0  data
 *
 * wih_dwc.c: three unlabelled leaves after WIH_DWC_FindSlotByKey (whose listing extent
 * runs to 0x02010888 because none of them saves lr): a getter of the halfword
 * at +0x312 of the object behind 0x021461E0 (0 when there is none), a raising
 * setter of the halfword at +0x314 (only upward, and only below 4; the first
 * compare is signed, the bound unsigned, so the parameter is u32 and the
 * field is compared as int), and an empty function.  func_02010888
 * (src/matched/func_02010888.c) follows.
 *
 * SEED REQUEST for the integrator: arm9 0x02010848 thumb, 0x02010864 thumb,
 * 0x02010884 thumb (witness: this unit).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02010848.c \
 *       --addr 0x02010848 --thumb
 */
#include "../include/Obj11819.h"
#include "../include/G_WihCtx.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern struct WihCtx gWihDwc;

u16 WIH_DWC_GetAlertLevel(void)
{
    if ((*(u8 * *)&gWihDwc) != 0)
        return *(u16 *)((*(u8 * *)&gWihDwc) + 0x312);
    return 0;
}

void WIH_DWC_RequestAlertLevel(u32 v)
{
    u8 *o = (*(u8 * *)&gWihDwc);

    if (o != 0 && (int)((struct Obj11819 *)o)->f314 < (int)v && v < 4)
        ((struct Obj11819 *)o)->f314 = v;
}

void WIH_DWC_Dummy(void)
{
}
