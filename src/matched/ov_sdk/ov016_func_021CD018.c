/*
 * function: func_021CD018
 * address:  0x021CD018
 * packet:   pkt_ov016_021CD018
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      moveFocus (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD018.c \n *       --func func_021CD018 --addr 0x021CD018 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   DWCi_Flag  0x021C0EF0  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_FOCUSlDisp4  0x021BD4C8  arm  ov016
 *   gFocusState     0x021DE614  data
 *   sSceneSetSelectWayFocusNext     0x021DA7DF  data
 *   sSceneSetSelectWayFocusRects     0x021DA858  data
 *   g_021DA85A     0x021DA85A  data
 *   g_021DA85C     0x021DA85C  data
 *   g_021DA85E     0x021DA85E  data
 */

#include "../include/G_FocusState.h"

typedef struct { signed char last; signed char cur; unsigned char flag; void *screen; } FocusState;
typedef struct { unsigned short left, top, right, bottom; } Rect;

extern struct FocusState gFocusState;
extern signed char sSceneSetSelectWayFocusNext[2][4][4];
extern Rect sSceneSetSelectWayFocusRects[2][4];
extern int DWCi_Flag(unsigned long flag);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_FOCUSlDisp4(int x0, int x1, int y0, int y1);

void func_021CD018(int dir)
{
    signed char prev = gFocusState.cur;
    signed char next = sSceneSetSelectWayFocusNext[DWCi_Flag(1)][prev][dir];
    if (next == -1)
        return;
    if (next == 0)
        gFocusState.last = prev;
    if (next == -2)
        gFocusState.cur = gFocusState.last;
    else
        gFocusState.cur = next;
    DWCi_SNDlPlay(8);
    DWCi_FOCUSlDisp4(sSceneSetSelectWayFocusRects[DWCi_Flag(1)][gFocusState.cur].left,
                  sSceneSetSelectWayFocusRects[DWCi_Flag(1)][gFocusState.cur].right,
                  sSceneSetSelectWayFocusRects[DWCi_Flag(1)][gFocusState.cur].top,
                  sSceneSetSelectWayFocusRects[DWCi_Flag(1)][gFocusState.cur].bottom);
}
