/*
 * function: endScene1
 * address:  0x021CCE78
 * packet:   pkt_ov016_021CCE78
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CCE78.c \n *       --func endScene1 --addr 0x021CCE78 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm  ov016
 *   DWCi_BTNlEnd  0x021BCAE4  arm  ov016
 *   DWCi_EFFlFade  0x021D55A4  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gFocusState     0x021DE614  data
 *   func_021CCEE4  0x021CCEE4  arm  ov016
 */

#include "../include/G_FocusState.h"

extern int DWCi_EFFlCheck(int lcd);
extern void DWCi_BTNlEnd(void);
extern int DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_ChangeScene(unsigned int v);
typedef struct { signed char last; signed char cur; unsigned char flag; void *screen; } FocusState;
extern struct FocusState gFocusState;
extern void func_021CCEE4(void);

void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (gFocusState.flag)
        DWCi_BTNlEnd();
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 20, 8);
    DWCi_ChangeScene((unsigned int)func_021CCEE4);
}
