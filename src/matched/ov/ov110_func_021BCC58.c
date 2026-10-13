/*
 * function: PMSIV_MENU_ShowWordEntries
 * address: 0x021BCC58
 * packet: pkt_ov110_021BCC58
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PMSIV_MENU_HideAll 0x021BCAD8 thumb ov110
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   PMSIV_MENU_ShowBackButton 0x021BD248 thumb ov110
 *   PMSIV_MENU_ShowListEntries 0x021BD264 thumb ov110
 */
#include "../include/Obj00295.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void PMSIV_MENU_HideAll(void *);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern u8 PMS_INPUT_GetBrowseMode(u8 *);
extern void PMSIV_MENU_ShowBackButton(u8 *);
extern void PMSIV_MENU_ShowListEntries(void *);
void PMSIV_MENU_ShowWordEntries(u8 *p)
{
    PMSIV_MENU_HideAll(p);
    CLACT_SetActorDrawEnable(((struct Obj00295 *)p)->f8C, 1);
    if (PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj00295 *)p)->f4) == 0) PMSIV_MENU_ShowBackButton(p);
    else PMSIV_MENU_ShowListEntries(p);
}
