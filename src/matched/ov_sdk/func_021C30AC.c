/*
 * function: moveFocus
 * address:  0x021C30AC
 * packet:   pkt_021C30AC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Advances the flag byte gSceneOptMenuWork.f0 and dispatches the indexed record.
 *
 * symbols:
 *   FX_ModS32  0x0207C994  arm
 *   DWCi_SNDlPlay  0x021CFFAC  arm
 *   DWCi_FOCUSlDisp4  0x021BD4C8  arm
 *   gSceneOptMenuWork     0x021DE5A8  data
 *   sSceneOptMenuFocusX0     0x021DA4D0  data
 *   sSceneOptMenuFocusY0     0x021DA4D2  data
 *   sSceneOptMenuFocusX1     0x021DA4D4  data
 *   sSceneOptMenuFocusY1     0x021DA4D6  data
 */

#include "../include/G_FocusPosT.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern int  FX_ModS32(int a, int b);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_FOCUSlDisp4(int a, int b, int c, int d);
extern struct FocusPosT gSceneOptMenuWork;
extern u16 sSceneOptMenuFocusX0[][4];
extern u16 sSceneOptMenuFocusY0[][4];
extern u16 sSceneOptMenuFocusX1[][4];
extern u16 sSceneOptMenuFocusY1[][4];

void moveFocus(int a)
{
    u8 i;

    if (a == 1)
        gSceneOptMenuWork.idx = (u8)FX_ModS32(gSceneOptMenuWork.idx + 2, 3);
    else
        gSceneOptMenuWork.idx = (u8)FX_ModS32(gSceneOptMenuWork.idx + 1, 3);
    DWCi_SNDlPlay(8);
    i = gSceneOptMenuWork.idx;
    DWCi_FOCUSlDisp4(sSceneOptMenuFocusX0[i][0], sSceneOptMenuFocusX1[i][0],
                  sSceneOptMenuFocusY0[i][0], sSceneOptMenuFocusY1[i][0]);
}
