/*
 * function: POKETRADE_3D_AddPokemonMcssPlain
 * address:  0x021E36C8
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Five-argument forwarder to the shared sender.
 *
 * symbols:
 *   POKETRADE_3D_AddPokemonMcss  0x021E35A0  thumb  ov119
 */

extern void POKETRADE_3D_AddPokemonMcss(void *a, int b, int c, void *d, int e);

void POKETRADE_3D_AddPokemonMcssPlain(void *a, int b, int c, void *d, int e)
{
    POKETRADE_3D_AddPokemonMcss(a, b, c, d, e);
}

