/*
 * function: func_021BD7FC
 * address:  0x021BD7FC
 * packet:   pkt_021BD7FC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *   (none)
 *
 * Loads the word at [p] and tail-calls the function at 0x0204B3DC with it and
 * the second argument.
 */

struct Obj;

extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

void func_021BD7FC(struct Obj **p, unsigned int v)
{
    CLACT_SetActorDrawEnable(*p, v);
}
