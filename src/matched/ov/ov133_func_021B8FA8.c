/*
 * function: DUP_FITTING_UpdateHeldVisible
 * address: 0x021B8FA8
 * packet: pkt_ov133_021B8FA8
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DUP_FITTING_ITEM_ElemGetData 0x021BA20C thumb ov133
 *   DUP_FITTING_ITEM_ElemGetRenderElem 0x021BA218 thumb ov133
 *   MUSICAL_MCSS_SetElemVisible 0x021F4E6C thumb ov112
 *   MUSICAL_MCSS_CopyElem 0x021F4E2C thumb ov112
 */
#include "../include/Obj00004.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 DUP_FITTING_ITEM_ElemGetData(u8 *p);
extern u32 DUP_FITTING_ITEM_ElemGetRenderElem(u8 *p);
extern void MUSICAL_MCSS_SetElemVisible(u8 *p, u8 *e, u32 value);
extern void MUSICAL_MCSS_CopyElem(void *unused, u8 *s, u8 *d);
void DUP_FITTING_UpdateHeldVisible(u8 *p)
{
    if (*(u8 * *)&((struct Obj00004 *)p)->f38 == 0) {
        MUSICAL_MCSS_SetElemVisible(((struct Obj00004 *)p)->f1884, ((struct Obj00004 *)p)->f4C, 0);
        return;
    }
    if (((struct Obj00004 *)p)->f50 == *(u16 *)DUP_FITTING_ITEM_ElemGetData(*(u8 * *)&((struct Obj00004 *)p)->f38)) {
        MUSICAL_MCSS_SetElemVisible(((struct Obj00004 *)p)->f1884, ((struct Obj00004 *)p)->f4C, 1);
        MUSICAL_MCSS_CopyElem(((struct Obj00004 *)p)->f1884, (u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f38), ((struct Obj00004 *)p)->f4C);
    }
}
