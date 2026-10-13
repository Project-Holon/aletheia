/*
 * function: MOVE_POKEMON_GetEntryIndexBySpecies
 * address: 0x0215E724
 * packet: pkt_ov010_0215E724
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
int MOVE_POKEMON_GetEntryIndexBySpecies(int species)
{
    switch(species) {
    case 642: return 0;
    case 641: return 1;
    }
    return 2;
}
