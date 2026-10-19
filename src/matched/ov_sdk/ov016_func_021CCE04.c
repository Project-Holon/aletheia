/*
 * function: button
 * address:  0x021CCE04
 * packet:   pkt_ov016_021CCE04
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      button (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CCE04.c \n *       --func button --addr 0x021CCE04 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   DWCi_BTNlGet  0x021BCB14  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   func_021CD108  0x021CD108  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gFocusState     0x021DE614  data
 *   func_021CCE58  0x021CCE58  arm  ov016
 */

#include "../include/G_FocusState.h"

extern signed char DWCi_BTNlGet(void);
extern void DWCi_SNDlPlay(unsigned int v);
extern void func_021CD108(void);
extern void DWCi_ChangeScene(unsigned int v);
typedef struct { signed char last; signed char cur; unsigned char flag; void *screen; } FocusState;
extern struct FocusState gFocusState;
extern void func_021CCE58(void);

void button(void)
{
    switch (DWCi_BTNlGet()) {
    case 0:
        DWCi_SNDlPlay(7);
        break;
    case 1:
        DWCi_SNDlPlay(6);
        func_021CD108();
        gFocusState.flag = 1;
        break;
    default:
        return;
    }
    DWCi_ChangeScene((unsigned int)func_021CCE58);
}
