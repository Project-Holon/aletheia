/*
 * function: BOX2_SEQ_SetCursorDraw
 * address:  0x021ED55C
 * packet:   pkt_ov170_021ED55C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CURSOR_MOVE_GetState 0x020260F0 thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 */
#include "../include/Obj24022.h"

typedef unsigned int   u32;
struct Sound;
extern u32 CURSOR_MOVE_GetState(struct Sound *obj);
extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);

void BOX2_SEQ_SetCursorDraw(char **p, int flag)
{
    if (flag == 1) {
        if (CURSOR_MOVE_GetState(((struct Obj24022 *)(p[11]))->f70) == 1)
            BOX2_SEQ_SetActorDrawEnable(p[11], 4, 1);
    } else {
        BOX2_SEQ_SetActorDrawEnable(p[11], 4, 0);
    }
}
