/*
 * function: func_021DD2CC
 * address:  0x021DD2CC
 * packet:   pkt_021DD2CC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Symbols:
 *   (none)
 *
 * ARM leaf getter: returns the word at +0x48 of the ov175 object (the
 * handle func_021DD2D4 stashes there from its callback).
 */

typedef unsigned long u32;

u32 func_021DD2CC(char *obj)
{
    return *(u32 *)(obj + 0x48);
}
