/*
 * function: BOX2_SEQ_DrawActors
 * address:  0x021EBF74
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_AddActorAnimFrame  0x0204B8D4  arm  arm9
 *   CLACT_GetActorAutoAnim  0x0204B944  arm  arm9
 *   CLACT_DrawSystem  0x0204A600  arm  arm9
 *
 * Sweep 0x2d slots of the 0x9E74 array, restarting each live one.
 *   The element address must be a named `int *row = (int *)(p + i*4)`
 *   and the offset written as the WORD index row[0x279d]: that is what
 *   puts i in r4, the row in r5 and 0x9E74 in r7 (the flat spelling
 *   swaps r4/r5).
 */

typedef unsigned int   u32;
struct Obj;
extern u32 CLACT_GetActorAutoAnim(struct Obj *p);
extern void CLACT_AddActorAnimFrame(struct Obj *p, u32 arg);
extern void CLACT_DrawSystem(void);
extern u32 CLACT_GetActorAutoAnim(struct Obj *p);
extern void CLACT_AddActorAnimFrame(struct Obj *p, u32 arg);
extern void CLACT_DrawSystem(void);
void BOX2_SEQ_DrawActors(char *p)
{
    unsigned i;
    for (i = 0; i < 0x2d; i++) {
        int *row = (int *)(p + i * 4);
        if (row[0x279d] != 0 && CLACT_GetActorAutoAnim((struct Obj *)row[0x279d]) != 1)
            CLACT_AddActorAnimFrame((struct Obj *)row[0x279d], 0x1000);
    }
    CLACT_DrawSystem();
}

