/*
 * function: EVENT_RECOVERY_GetPartyBallCount
 * address:  0x021C0C94
 * packet:   pkt_021C0C94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 func_0201AA1C(void *);

u32 EVENT_RECOVERY_GetPartyBallCount(u32 a)
{
return func_0201AA1C(GAME_DATA_GetMyParty(GAMESYSTEM_GetGameData((const struct Ctx *)a)));
}

