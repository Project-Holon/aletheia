/*
 * function: POKETRADE_3D_AddPokemonMcssFlipped
 * address:  0x021E36A8
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Force the third argument to one when the sixth is set and the third is clear.
 *
 * symbols:
 *   POKETRADE_3D_AddPokemonMcss  0x021E35A0  thumb
 */

extern void POKETRADE_3D_AddPokemonMcss(void *a, int b, int c, void *d, int e);

void POKETRADE_3D_AddPokemonMcssFlipped(void *a, int b, int c, void *d, int e, int f)
{
    if (f != 0 && c == 0) {
        c = 1;
        e = 0;
    }
    POKETRADE_3D_AddPokemonMcss(a, b, c, d, e);
}

