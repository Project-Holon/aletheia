/*
 * function: BOX2_SEQ_SetActorDrawEnable
 * address:  0x021EC000
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *
 * Release slot i of the 0x9E74 array when it is non-null.
 */


struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v)
{
    int x = *(int *)(p + i * 4 + 0x9E74);
    if (x != 0)
        CLACT_SetActorDrawEnable((struct Obj *)x, v);
}
