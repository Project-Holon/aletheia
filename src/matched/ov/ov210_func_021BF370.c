/*
 * function: ZKNSEARCH_MAIN_DeleteActors
 * address:  0x021BF370
 * packet:   pkt_ov210_021BF370
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKNSEARCH_MAIN_DeleteActorAt 0x021BF358 thumb ov210
 *   CLACT_DeleteUnit 0x0204B1CC arm
 * Addresses are Black-image addresses.
 */

extern void ZKNSEARCH_MAIN_DeleteActorAt(int p, int i);
struct Bank;
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);

void ZKNSEARCH_MAIN_DeleteActors(int p)
{
    unsigned i;

    for (i = 0; i < 0x39; i++)
        ZKNSEARCH_MAIN_DeleteActorAt(p, i);
    CLACT_DeleteUnit((struct Bank *)(((int *)p)[9]));
}
