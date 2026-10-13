/*
 * function: func_021B746C
 * address:  0x021B746C
 * packet:   pkt_021B746C
 * region:   ov180
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
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);

void func_021B746C(int *p, int i, int a)
{
    int v = *(int *)((char *)p + i * 4 + 0x9048);

    if (v)
        CLACT_SetActorDrawEnable((struct Obj *)v, a);
}
