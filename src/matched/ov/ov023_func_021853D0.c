/*
 * function: OEKAKI_StepHideCursors
 * address:  0x021853D0
 * packet:   pkt_021853D0
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 */

typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);

int OEKAKI_StepHideCursors(char *p, int a1)
{
    int i;

    for (i = 0; i < 5; i++)
        CLACT_SetActorDrawEnable(*(void **)(p + 0x60 + i * 4), 0);
    return a1;
}
