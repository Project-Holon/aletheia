/*
 * function: FLD_FACEUP_UpdateTaskMain
 * address:  0x021F5748
 * packet:   pkt_ov082_021F5748
 * region:   ov082
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_CheckFlag  0x02159190  thumb  ov010
 *   SCRCMD_WORK_GetMsgWindow  0x0215A61C  thumb  ov010
 *   FIELD_MSGBG_GetPlainWinStreamState  0x021917C0  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 *   FLD_FACEUP_StepAnim  0x021F5840  thumb  ov082
 *   gFldFaceupMouthFrames     0x021F58D0  data  a4
 *   gFldFaceupBlinkFrames     0x021F58E0  data  a4
 */
#include "../include/Obj02425.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern int  SCRIPT_WORK_CheckFlag(int a);
extern int  SCRCMD_WORK_GetMsgWindow(int a);
extern int FIELD_MSGBG_GetPlainWinStreamState(int *p);
extern u32 func_020056EC(u32 range);
extern void FLD_FACEUP_StepAnim(void *tbl, u32 a, u32 b, u32 c, u32 d, void *e);
extern char gFldFaceupMouthFrames[];
extern char gFldFaceupBlinkFrames[];

void FLD_FACEUP_UpdateTaskMain(int a0, char *p)
{
    int t;
    int r;

    if (((struct Obj02425 *)p)->f1C == 0 && SCRIPT_WORK_CheckFlag(3) != 0) {
        t = SCRCMD_WORK_GetMsgWindow(((struct Obj02425 *)p)->f10);
        if (t != 0) {
            r = FIELD_MSGBG_GetPlainWinStreamState((int *)t);
            if (r == 0) {
                ((struct Obj02425 *)p)->f4C = 0;
                ((struct Obj02425 *)p)->f74 = 0;
            } else if (r == 2 && ((struct Obj02425 *)p)->f74 == 0) {
                ((struct Obj02425 *)p)->f1C = 1;
            }
        }
    }
    FLD_FACEUP_StepAnim(gFldFaceupMouthFrames, 4, 0x184, 8, 4, p + 0x4C);
    if (((struct Obj02425 *)p)->f26 == 0) {
        ((struct Obj02425 *)p)->f28 = 0;
        ((struct Obj02425 *)p)->f26 = func_020056EC(0x14) + 0x50;
    } else {
        ((struct Obj02425 *)p)->f26 = ((struct Obj02425 *)p)->f26 - 1;
    }
    FLD_FACEUP_StepAnim(gFldFaceupBlinkFrames, 5, 0x160, 0xC, 6, p + 0x28);
}
