/*
 * function: ITEMMENU_HideMoveInfo
 * address:  0x021B9AAC
 * packet:   pkt_ov070_021B9AAC
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ITEMMENU_SetMoveTypeIconsVisible  0x021B97E8  thumb  ov070
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 */
#include "../include/Obj20672.h"

extern void ITEMMENU_SetMoveTypeIconsVisible(char *, int);
struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

void ITEMMENU_HideMoveInfo(char *p)
{
    unsigned i;
    unsigned j;
    ITEMMENU_SetMoveTypeIconsVisible(p, 0);
    BMP_WIN_ClearScreen((struct Descriptor *)(((struct Obj20672 *)p)->f734));
    for (i = 0; i < 3; i++) {
        CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x6C0), 0);
    }
    for (j = 0; j < 0x11; j++) {
        CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + j * 4 + 0x6CC), 0);
    }
}
