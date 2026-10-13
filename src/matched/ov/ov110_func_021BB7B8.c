/*
 * unit: yes
 * function: PMSIV_CATEGORY_StepClose, PMSIV_CATEGORY_ResetBgScroll
 * address: 0x021BB7B8
 * packet: pkt_ov110_021BB7B8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: includes the unlabelled tail-call stub at 0x021BB804.
 * symbols:
 *   PMSIV_BGSCROLL_Step 0x021BC7DC thumb ov110
 *   PMSIV_FADE_StartBrightness 0x021BC8FC thumb ov110
 *   PMSIV_FADE_IsBrightnessDone 0x021BC93C thumb ov110
 *   func_02040618 0x02040618 arm
 */
#include "../include/Obj13779.h"
typedef unsigned char u8;
extern int PMSIV_BGSCROLL_Step(u8 *p);
extern void PMSIV_FADE_StartBrightness(u8 *p, int a, int start, int end, int n);
extern int PMSIV_FADE_IsBrightnessDone(u8 *p);
extern void func_02040618(unsigned, unsigned, unsigned);
int PMSIV_CATEGORY_StepClose(u8 *p)
{
    switch (((struct Obj13779 *)p)->f10) {
    case 0:
        if (PMSIV_BGSCROLL_Step(p + 0x38)) {
            PMSIV_FADE_StartBrightness(p + 0x18, 2, 0, -10, 16);
            ++((struct Obj13779 *)p)->f10;
        }
        break;
    case 1:
        return PMSIV_FADE_IsBrightnessDone(p + 0x18);
    }
    return 0;
}
void PMSIV_CATEGORY_ResetBgScroll(u8 *a0)
{
    func_02040618(1, 3, 16);
}
