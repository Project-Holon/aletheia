/*
 * function: DENDOU_VIEW_StateLeaveDetail
 * address: 0x021DD38C
 * packet: pkt_ov171_021DD38C
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DENDOU_VIEW_InitPaletteFade 0x021DE76C thumb ov171
 *   DENDOU_VIEW_ApplyPaletteFade 0x021DCBA4 thumb ov171
 *   DENDOU_VIEW_IsPaletteFadeBusy 0x021DCBE8 thumb ov171
 *   DENDOU_VIEW_SetActorAnim 0x021DE080 thumb ov171
 *   DENDOU_VIEW_ClearInfoWindow 0x021DDFBC thumb ov171
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 */
#include "../include/Obj10659.h"
extern void DENDOU_VIEW_InitPaletteFade(unsigned char *p, int mode);
extern void DENDOU_VIEW_ApplyPaletteFade(char *);
extern int DENDOU_VIEW_IsPaletteFadeBusy(unsigned char *p);
typedef unsigned char  u8;
extern void DENDOU_VIEW_SetActorAnim(u8 *p, int i, int value);
extern void DENDOU_VIEW_ClearInfoWindow(u8 *p);
typedef unsigned int   u32;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
int DENDOU_VIEW_StateLeaveDetail(char *p)
{
    switch (((struct Obj10659 *)p)->fC70) {
    case 0:
        DENDOU_VIEW_InitPaletteFade((unsigned char *)p, 0);
        DENDOU_VIEW_ApplyPaletteFade(p);
        BG_SYS_SetMainPlaneVisible(2, 0);
        ++((struct Obj10659 *)p)->fC70;
        break;
    case 1:
        if (!DENDOU_VIEW_IsPaletteFadeBusy((unsigned char *)p)) {
            DENDOU_VIEW_SetActorAnim((u8 *)p, 12, 4);
            DENDOU_VIEW_SetActorAnim((u8 *)p, 13, 5);
            DENDOU_VIEW_SetActorAnim((u8 *)p, 14, 0);
            DENDOU_VIEW_ClearInfoWindow((u8 *)p);
            ((struct Obj10659 *)p)->fC70 = 0;
            return 4;
        }
        break;
    }
    return 8;
}
