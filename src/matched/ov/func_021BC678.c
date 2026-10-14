/*
 * function: ZUKAN_DETAIL_COMMON_UpdatePaletteAnim
 * address:  0x021BC678
 * packet:   pkt_021BC678
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030D28 0x02030D28 arm
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *
 * Releases +0 and re-checks the handle at +8 for the two armed states at +0x10.
 */
#include "../include/Obj04893.h"


typedef unsigned int   u32;
struct Ctx;
extern void func_02030D28(struct Ctx *c);
extern u32 PALANM_GetFadeRequestBits(const char *ptr);

void ZUKAN_DETAIL_COMMON_UpdatePaletteAnim(char *p)
{
    func_02030D28((struct Ctx *)(((struct Obj04893 *)p)->f0));
    switch (((struct Obj04893 *)p)->f10) {
    case 0:
    case 1:
        break;
    case 2:
        if (PALANM_GetFadeRequestBits((const char *)(((struct Obj04893 *)p)->f8)) == 0)
            ((struct Obj04893 *)p)->f10 = 0;
        break;
    case 3:
        if (PALANM_GetFadeRequestBits((const char *)(((struct Obj04893 *)p)->f8)) == 0)
            ((struct Obj04893 *)p)->f10 = 1;
        break;
    }
}

