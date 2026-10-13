/*
 * function: func_021E0CE8
 * address:  0x021E0CE8
 * packet:   pkt_021E0CE8
 * region:   ov183
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

void func_021E0CE8(char *p, int index, int a2)
{
    CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + index * 0x1c + 0x194), (unsigned int)a2);
}
