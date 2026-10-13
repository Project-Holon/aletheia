/*
 * function: SODATEYA_SetEggFlag
 * address:  0x021C33A4
 * packet:   pkt_ov021_021C33A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets event flag 0x4139 when the party is not full.
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb  arm9
 *   GAME_DATA_GetMyParty  0x02012934  thumb  arm9
 *   GAME_DATA_GetEventWork  0x0201296C  thumb  arm9
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *FIELDMAP_GetGameSystem(void *p);
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern u32 func_0201AA14(void *p);
extern u32 func_020143CC(u32 a, u32 b);

void SODATEYA_SetEggFlag(void *a)
{
    void *g = GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(a));
    void *ev = (void *)GAME_DATA_GetEventWork(g);
    void *party = GAME_DATA_GetMyParty(g);

    if ((int)func_0201AA18(party) < (int)func_0201AA14(party))
        *((u16 *)func_020143CC((u32)ev, 0x4139)) = 1;
}
