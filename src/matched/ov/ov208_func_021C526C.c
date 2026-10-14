/*
 * function: ZUKAN_DETAIL_FORM_ToggleModelVisibility
 * address: 0x021C526C
 * packet: pkt_ov208_021C526C
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   MCSS_ResetVanishFlag 0x02015EB0 thumb
 *   ZUKAN_DETAIL_FORM_RebuildModelsSwapped 0x021C595C thumb ov208
 */
#include "../include/Obj00147.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void MCSS_SetVanishFlag(void *p);
extern void MCSS_ResetVanishFlag(void *p);
extern void ZUKAN_DETAIL_FORM_RebuildModelsSwapped(u16 *heap,u8 *p,int key);
void ZUKAN_DETAIL_FORM_ToggleModelVisibility(u16 *heap,u8 *p,int key)
{
    if(*(int *)&((struct Obj00147 *)p)->f124) {
        MCSS_SetVanishFlag(((struct Obj00147 *)p)->fC);
        if(((struct Obj00147 *)p)->f94)MCSS_SetVanishFlag(((struct Obj00147 *)p)->f94);
        *(int *)&((struct Obj00147 *)p)->f124=0;
    } else {
        MCSS_SetVanishFlag(((struct Obj00147 *)p)->f50);
        if(((struct Obj00147 *)p)->fD8)MCSS_SetVanishFlag(((struct Obj00147 *)p)->fD8);
        *(int *)&((struct Obj00147 *)p)->f124=1;
    }
    ZUKAN_DETAIL_FORM_RebuildModelsSwapped(heap,p,key);
    if(*(int *)&((struct Obj00147 *)p)->f124) {
        MCSS_ResetVanishFlag(((struct Obj00147 *)p)->fC);
        if(((struct Obj00147 *)p)->f94)MCSS_ResetVanishFlag(((struct Obj00147 *)p)->f94);
    } else {
        MCSS_ResetVanishFlag(((struct Obj00147 *)p)->f50);
        if(((struct Obj00147 *)p)->fD8)MCSS_ResetVanishFlag(((struct Obj00147 *)p)->fD8);
    }
}
