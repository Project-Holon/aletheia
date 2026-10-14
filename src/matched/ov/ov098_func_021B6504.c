/*
 * function: PDC_MAIN_StepConfirm
 * address:  0x021B6504
 * packet:   pkt_ov098_021B6504
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PDC_MSG_PrintMessage3  0x021B694C  thumb  ov098
 *   PDC_MSG_Update  0x021B6A3C  thumb  ov098
 *   BTLV_INPUT_ChangeScreen  0x0220270C  thumb  ov094
 *   BTLV_INPUT_ProcessTouchInput  0x02202DC4  thumb  ov094
 *   PDC_MAIN_SetStep  0x021B6364  thumb  ov098
 *   PDC_MAIN_StepDeclined  0x021B6750  thumb  ov098
 *   PDC_MAIN_StepChooseItem  0x021B6578  thumb  ov098
 *   gPdcMenuLayoutA     0x021B6D98  data   ov098  a4
 *   gPdcMenuLayoutB     0x021B6DC0  data   ov098  a4
 */
#include "../include/Obj00381.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern char gPdcMenuLayoutA[];
extern char gPdcMenuLayoutB[];
extern void PDC_MSG_PrintMessage3(u8 *p, u8 *q);
extern int PDC_MSG_Update(u8 *p);
extern void BTLV_INPUT_ChangeScreen(char *s, int mode, void *arg);
extern int BTLV_INPUT_ProcessTouchInput(int a, char *b, char *c);
extern void PDC_MAIN_SetStep(u8 *p, u32 v);
extern int PDC_MAIN_StepDeclined(char *p);
struct P;
extern int PDC_MAIN_StepChooseItem(struct P *p);

int PDC_MAIN_StepConfirm(char *p)
{
    int r;

    switch (((struct Obj00381 *)p)->f60) {
    case 0:
        PDC_MSG_PrintMessage3((u8 *)(((struct Obj00381 *)p)->f14), (u8 *)(*(int *)&((struct Obj00381 *)p)->f0));
        ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        break;
    case 1:
        if (PDC_MSG_Update((u8 *)(((struct Obj00381 *)p)->f14)) != 0) {
            BTLV_INPUT_ChangeScreen((char *)(((struct Obj00381 *)p)->f10), 7, 0);
            ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        }
        break;
    case 2:
        r = BTLV_INPUT_ProcessTouchInput(((struct Obj00381 *)p)->f10, gPdcMenuLayoutA, gPdcMenuLayoutB);
        if (r != -1) {
            if (r != 0)
                PDC_MAIN_SetStep((u8 *)p, (u32)PDC_MAIN_StepDeclined);
            else
                PDC_MAIN_SetStep((u8 *)p, (u32)PDC_MAIN_StepChooseItem);
        }
        break;
    }
    return 0;
}
