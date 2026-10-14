/*
 * function: POKETRADE_SAVE_CloseSummaryPage
 * address:  0x021E1CE8
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_SAVE_DeleteOfferStatusIcons  0x021E1CA8  thumb  ov119
 *   POKETRADE_SAVE_DeleteTypeIcons  0x021E1CC8  thumb  ov119
 *   POKETRADE_3D_DeleteMcssSlot  0x021E36D8  thumb  ov119
 *   POKETRADE_2D_NoOp  0x021E3F70  thumb  ov119
 *   POKETRADE_2D_DeleteTouchbarActors  0x021E5BE4  thumb  ov119
 *   POKETRADE_2D_DeleteMarkingIcon  0x021E5EF8  thumb  ov119
 *   POKETRADE_2D_DeleteSummaryIcons  0x021E625C  thumb  ov119
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 */
#include "../include/Obj00001.h"

extern void POKETRADE_SAVE_DeleteOfferStatusIcons(char *p);
extern void POKETRADE_SAVE_DeleteTypeIcons(char *p);
extern void POKETRADE_3D_DeleteMcssSlot(void *p, int a);
extern void POKETRADE_2D_NoOp(void *p);
struct Descriptor;
extern void POKETRADE_2D_DeleteTouchbarActors(int a);
extern void POKETRADE_2D_DeleteMarkingIcon(void *p);
extern void POKETRADE_2D_DeleteSummaryIcons(void *p);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);

void POKETRADE_SAVE_CloseSummaryPage(void *p, int a1)
{
    unsigned int v;

    POKETRADE_2D_DeleteMarkingIcon((char *)p + 0x964);
    POKETRADE_2D_DeleteMarkingIcon((char *)p + 0x978);
    POKETRADE_2D_DeleteSummaryIcons(p);
    if (a1 != 0) {
        v = *(volatile unsigned int *)0x04001000;
        v &= 0xFFFF1FFF;
        *(volatile unsigned int *)0x04001000 = v;
    }
    POKETRADE_SAVE_DeleteOfferStatusIcons(p);
    POKETRADE_SAVE_DeleteTypeIcons(p);
    POKETRADE_2D_DeleteMarkingIcon((char *)p + 0x950);
    POKETRADE_2D_DeleteTouchbarActors((int)p);
    POKETRADE_3D_DeleteMcssSlot(p, 0);
    POKETRADE_3D_DeleteMcssSlot(p, 1);
    BMP_WIN_ClearScreen((struct Descriptor *)(*(int *)&((struct Obj00001 *)p)->f6B4));
    BMP_WIN_Delete((struct Descriptor *)(*(int *)&((struct Obj00001 *)p)->f6B4));
    *(int *)&((struct Obj00001 *)p)->f6B4 = 0;
    POKETRADE_2D_NoOp(p);
}
