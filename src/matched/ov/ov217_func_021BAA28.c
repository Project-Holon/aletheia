/*
 * function: RESEARCH_TOP_DeleteUnits
 * address:  0x021BAA28
 * packet:   pkt_021BAA28
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *
 * Addresses are Black-image addresses.
 */

struct Bank;
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);

void RESEARCH_TOP_DeleteUnits(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        CLACT_DeleteUnit((struct Bank *)p[i + 0x1D]);
}
