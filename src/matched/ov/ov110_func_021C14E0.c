/*
 * function: PMS_SELECT_GRAPHIC_StepCloseRowMenu
 * address: 0x021C14E0
 * packet: pkt_ov110_021C14E0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent ends with zero padding at 0x021C154A.
 * symbols:
 *   PMS_SELECT_GRAPHIC_CloseRowMenu 0x021C0B44 thumb ov110
 *   func_020355C4 0x020355C4 arm
 *   BRIGHTNESS_Set 0x02023F60 thumb
 *   PMS_SELECT_GRAPHIC_ResetBgBlink 0x021C09E0 thumb ov110
 *   PMS_SELECT_GRAPHIC_RedrawRowsAfterInput 0x021C0C50 thumb ov110
 */
#include "../include/Obj03244.h"
typedef unsigned char u8;
struct TaskMenu;
extern void PMS_SELECT_GRAPHIC_CloseRowMenu(struct TaskMenu *);
extern u8 func_020355C4(void);
extern void BRIGHTNESS_Set(unsigned, unsigned, unsigned);
extern void PMS_SELECT_GRAPHIC_ResetBgBlink(u8 *);
extern void PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(u8 *);
int PMS_SELECT_GRAPHIC_StepCloseRowMenu(void *arg, u8 *p) {
    PMS_SELECT_GRAPHIC_CloseRowMenu(((struct Obj03244 *)p)->f68);
    ((struct Obj03244 *)p)->fA8 = func_020355C4()==1;
    if (((struct Obj03244 *)p)->fA0==4) {
        BRIGHTNESS_Set(0,30,1);
        PMS_SELECT_GRAPHIC_ResetBgBlink(p+0x24);
        p[0x44]=0;
        ((struct Obj03244 *)p)->f40=0;
        if (((struct Obj03244 *)p)->fA8!=0) {
            p[0x94]=p[0x95];
            p[0x95]=255;
            PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(p);
        }
    }
    return 1;
}
