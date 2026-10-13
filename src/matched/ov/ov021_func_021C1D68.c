/*
 * function: FLD3D_CI_StartPartyMemberSequence
 * address:  0x021C1D68
 * packet:   pkt_ov021_021C1D68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_IsShiny  0x02017EAC  thumb
 *   FLD3D_CI_StartPokemonSequence  0x021C1D18  thumb  ov021
 */

typedef unsigned int u32;

struct Ctx;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *func_0201AB28(void *p, u32 idx);
u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
u32 POKE_TOOL_IsShiny(void *p);
int FLD3D_CI_StartPokemonSequence(int a, char *b, int c, int d, int e, int f, int g);

int FLD3D_CI_StartPartyMemberSequence(int a, int b, int c)
{
    int p;
    int x5;
    int x6f;
    int x6e;
    int xe;
    int x4c;

    p = (int)func_0201AB28(GAME_DATA_GetMyParty(GAMESYSTEM_GetGameData((const struct Ctx *)a)), c);
    x5 = POKE_TOOL_GetPartyValue((void *)p, 5, 0);
    x6f = POKE_TOOL_GetPartyValue((void *)p, 0x6f, 0);
    x6e = POKE_TOOL_GetPartyValue((void *)p, 0x6e, 0);
    xe = POKE_TOOL_IsShiny((void *)p);
    x4c = POKE_TOOL_GetPartyValue((void *)p, 0x4c, 0);
    return FLD3D_CI_StartPokemonSequence(a, (char *)b, x5, x6f, x6e, xe, x4c);
}
