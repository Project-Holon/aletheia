/*
 * function: BOX2_SEQ_SetWindow9
 * address:  0x021ED508
 * packet:   pkt_ov170_021ED508
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_SEQ_SetActorAnimSeq 0x021EBFA8 thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *
 * Sets window 9's frame and mode; outside modes 2, 3 and 4 the mode is
 * cleared again.
 */
#include "../include/Obj00000.h"
#include "../include/Obj24021.h"

extern void BOX2_SEQ_SetActorAnimSeq(char *w, int i, int v);
extern void BOX2_SEQ_SetActorDrawEnable(char *w, int i, int v);

#define WORK(p) (*(char **)((p) + 0x2C))

void BOX2_SEQ_SetWindow9(unsigned char *p, int a, int b)
{
    int kind;
    BOX2_SEQ_SetActorAnimSeq(WORK(p), 9, a);
    BOX2_SEQ_SetActorDrawEnable(WORK(p), 9, b);
    kind = ((struct Obj24021 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24;
    if (kind != 2 && kind != 4 && kind != 3)
        BOX2_SEQ_SetActorDrawEnable(WORK(p), 9, 0);
}
