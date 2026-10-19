/*
 * function: DWCi_SceneSetSelectWayDispPush
 * address:  0x021CD108
 * packet:   pkt_ov016_021CD108
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dispPush (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD108.c \n *       --func DWCi_SceneSetSelectWayDispPush --addr 0x021CD108 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   DWCi_SCREENlCopyPalette  0x021CE7B0  arm  ov016
 *   sSceneSetSelectWayPalette     0x021DA7D4  data
 *   gFocusState     0x021DE614  data
 */

#include "../include/G_FocusState.h"

typedef struct { signed char last; signed char cur; unsigned char flag; void *screen; } FocusState;
extern struct FocusState gFocusState;
typedef struct { unsigned char b[4]; } Palette4;
extern Palette4 sSceneSetSelectWayPalette;
extern void DWCi_SCREENlCopyPalette(void *src, int sColor, int dColor);

void DWCi_SceneSetSelectWayDispPush(void)
{
    Palette4 palette = sSceneSetSelectWayPalette;
    DWCi_SCREENlCopyPalette(gFocusState.screen, palette.b[gFocusState.cur], palette.b[gFocusState.cur]);
}
