/*
 * function: ZKND_TBAR_SetButtonVisible
 * address:  0x021BD378
 * packet:   pkt_021BD368
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKND_TBAR_FindButtonActor 0x021BD404  thumb  ov208
 *   ZKND_TBAR_SetActorDrawEnable 0x021BD7FC  thumb  ov208
 */

extern int ZKND_TBAR_FindButtonActor(int, int);
struct Obj;
extern void ZKND_TBAR_SetActorDrawEnable(struct Obj **p, unsigned int v);

void ZKND_TBAR_SetButtonVisible(int a, int b, int c)
{
    ZKND_TBAR_SetActorDrawEnable((struct Obj **)ZKND_TBAR_FindButtonActor(a, b), c);
}

