/*
 * unit:     no
 * function: POKEGRA_LoadCharDataPP
 * address:  0x0202D6F4
 * packet:   pkt_0202D6F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unpacks a party mon into the nine-argument sprite request of
 * POKEGRA_LoadCharData: species (5), form (0x6F), gender (0x6E), the shiny
 * predicate POKE_TOOL_IsBoxShiny, isEgg (0x4C) and the personality word (id 0)
 * are read in that order, then forwarded along with the caller's own
 * a2/a3 pass-throughs.
 *
 * symbols:
 *   POKE_TOOL_GetBoxValue   0x02017E88  thumb
 *   POKE_TOOL_IsBoxShiny   0x02017EB4  thumb
 *   POKEGRA_LoadCharData   0x0202D760  thumb
 */

typedef unsigned int u32;

extern u32 POKE_TOOL_GetBoxValue(void *mon, u32 id, u32 v);
extern u32 POKE_TOOL_IsBoxShiny(void *mon);
extern u32 POKEGRA_LoadCharData(void *a0, u32 species, u32 form, u32 gender,
                         u32 shiny, u32 a2, u32 isEgg, u32 pid, u32 a3);

u32 POKEGRA_LoadCharDataPP(void *a0, void *mon, u32 a2, u32 a3)
{
    u32 species;
    u32 form;
    u32 gender;
    u32 shiny;
    u32 isEgg;

    species = POKE_TOOL_GetBoxValue(mon, 5, 0);
    form = POKE_TOOL_GetBoxValue(mon, 0x6F, 0);
    gender = POKE_TOOL_GetBoxValue(mon, 0x6E, 0);
    shiny = POKE_TOOL_IsBoxShiny(mon);
    isEgg = POKE_TOOL_GetBoxValue(mon, 0x4C, 0);
    return POKEGRA_LoadCharData(a0, species, form, gender, shiny, a2, isEgg,
                         POKE_TOOL_GetBoxValue(mon, 0, 0), a3);
}
