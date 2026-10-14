/*
 * function: DENDOU_VIEW_SetActorVisible
 * address:  0x021DE064
 * packet:   pkt_021DE064
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 */

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);

void DENDOU_VIEW_SetActorVisible(int *p, int i, int a)
{
    int v = *(int *)((char *)p + i * 4 + 0xB74);

    if (v)
        CLACT_SetActorDrawEnable((struct Obj *)v, a);
}
