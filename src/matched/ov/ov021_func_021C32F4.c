/*
 * function: SODATEYA_ReceiveEgg
 * address:  0x021C32F4
 * packet:   pkt_ov021_021C32F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_Create  0x020173F0  thumb
 *   DAYCARE_GetEggReady  0x0200BCA0  thumb
 *   GAME_BEACON_SEARCH_SetSymbolMapEnter  0x0216556C  thumb  ov010
 *   SODATEYA_ClearEggFlag  0x021C33E0  thumb  ov021
 *   SODATEYA_CreateEggMon  0x021C3898  thumb  ov021
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   DAYCARE_ClearEggReady  0x0200BC20  thumb
 *   func_020307B0  0x020307B0  arm
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   FORMCHANGE_UpdateSeasonForms  0x0216AAE4  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03142.h"

typedef unsigned short u16;
typedef unsigned int   u32;

typedef unsigned long long u64;
typedef unsigned char  u8;
struct BigObj;
struct Ctx;
extern void *POKE_TOOL_Create(u16 species, u16 level, unsigned long long id, u16 heap);
struct Obj11233;
extern int DAYCARE_GetEggReady(struct Obj11233 *p);
extern void GAME_BEACON_SEARCH_SetSymbolMapEnter(void);
extern void SODATEYA_ClearEggFlag(void *a);
extern void SODATEYA_CreateEggMon(u32 *, u32);
struct Party;
struct PartyMon;
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
struct Obj11232;
extern void DAYCARE_ClearEggReady(struct Obj11232 *p);
extern u32 func_020307B0(void *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern void FORMCHANGE_UpdateSeasonForms(void *sys, void *party, int season);

void SODATEYA_ReceiveEgg(u32 *p, u32 b)
{
    u32 m = (u32)POKE_TOOL_Create(1, 1, 1, ((struct Obj03142 *)p)->f0);
    u32 w;

    if (DAYCARE_GetEggReady((struct Obj11233 *)p[2]) == 1) {
        GAME_BEACON_SEARCH_SetSymbolMapEnter();
        SODATEYA_ClearEggFlag((void *)p[1]);
        SODATEYA_CreateEggMon(p, m);
        POKEPARTY_Add((void *)b, (void *)m);
        DAYCARE_ClearEggReady((struct Obj11232 *)p[2]);
        func_020307B0((void *)m);
        w = (u32)GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)p[1]));
        FORMCHANGE_UpdateSeasonForms((void *)w, (void *)b, GAME_DATA_GetSeason((const struct BigObj *)w));
    }
}
