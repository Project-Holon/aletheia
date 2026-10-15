/*
 * function: ZKNSEARCH_MAIN_SetActorAnimAuto
 * address:  0x021BEDB8
 * packet:   pkt_ov210_021BEDB8
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKNSEARCH_MAIN_SetActorAnim 0x021BED98 thumb ov210
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 * Addresses are Black-image addresses.
 */

extern void ZKNSEARCH_MAIN_SetActorAnim(char *p, int idx, int v);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);

void ZKNSEARCH_MAIN_SetActorAnimAuto(int p, int i, int v)
{
    ZKNSEARCH_MAIN_SetActorAnim((char *)p, i, v);
    CLACT_SetActorAutoAnim((struct Obj *)((int *)(p + i * 4))[0xa], 1);
}
