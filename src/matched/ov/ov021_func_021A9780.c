/*
 * function: FIELD_ENCOUNT_InitRoamerPokemon
 * address:  0x021A9780
 * packet:   pkt_ov021_021A9780
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MOVE_POKEMON_SAVE_GetEntryField  0x0200D4B8  thumb
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 * Addresses are Black-image addresses.
 *
 * Lever: `const struct Unit *u` settles the argument scheduling before the
 * POKE_TOOL_SetupPartyParamEx call (as in ov021_func_021A96B8.c).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef unsigned long long u64;

struct Unit {
    u8 pad00[0x20];
    u32 f20;
};

struct GdsEnt;
struct Mon;
extern u32 MOVE_POKEMON_SAVE_GetEntryField(const struct GdsEnt *e, u32 i);
extern void POKE_TOOL_SetupPartyParamEx(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_RecalcParam(void *p);

void FIELD_ENCOUNT_InitRoamerPokemon(void *mon, const struct Unit *u, void *src)
{
    u16 species = MOVE_POKEMON_SAVE_GetEntryField(src, 4);
    u8 level = MOVE_POKEMON_SAVE_GetEntryField(src, 6);
    u32 pow = MOVE_POKEMON_SAVE_GetEntryField(src, 2);

    POKE_TOOL_SetupPartyParamEx(mon, species, level, u->f20, pow, MOVE_POKEMON_SAVE_GetEntryField(src, 3));
    POKE_TOOL_SetPartyValue(mon, 0x70, MOVE_POKEMON_SAVE_GetEntryField(src, 10));
    POKE_TOOL_SetPartyValue(mon, 0x9D, MOVE_POKEMON_SAVE_GetEntryField(src, 7));
    POKE_TOOL_SetPartyValue(mon, 0xA0, MOVE_POKEMON_SAVE_GetEntryField(src, 5));
    POKE_TOOL_RecalcParam(mon);
}
