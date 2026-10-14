/*
 * function: POKETRADE_SAVE_CloseSummaryWindow
 * address: 0x021E2484
 * packet: pkt_ov119_021E2484
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   POKETRADE_SAVE_DeleteStatusIconActor 0x021E0E4C thumb ov119
 *   POKETRADE_2D_DeleteMarkingIcon 0x021E5EF8 thumb ov119
 */
#include "../include/Obj05331.h"
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
typedef unsigned char  u8;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void BMP_WIN_TransferChars(struct Descriptor *);
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void POKETRADE_SAVE_DeleteStatusIconActor(char *p);
extern void POKETRADE_2D_DeleteMarkingIcon(void *);
void POKETRADE_SAVE_CloseSummaryWindow(char *p,int a)
{
    POKETRADE_SAVE_DeleteStatusIconActor(p+0x8c4);
    POKETRADE_2D_DeleteMarkingIcon(p+0x950);
    POKETRADE_2D_DeleteMarkingIcon(p+0x964);
    POKETRADE_2D_DeleteMarkingIcon(p+0x978);
    if (((struct Obj05331 *)p)->f6B4) {
        BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)((struct Obj05331 *)p)->f6B4),0);
        if(a) {
            BMP_WIN_ClearScreen((struct Descriptor *)(((struct Obj05331 *)p)->f6B4));
            BMP_WIN_TransferChars((struct Descriptor *)((struct Obj05331 *)p)->f6B4);
        }
        BMP_WIN_Delete((struct Descriptor *)(((struct Obj05331 *)p)->f6B4));
        ((struct Obj05331 *)p)->f6B4=0;
    }
}
