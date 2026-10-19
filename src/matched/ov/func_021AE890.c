/*
 * function: EVENT_TRAINER_EYE_IsTrainerDefeated
 * address:  0x021AE890
 * packet:   pkt_021AE890
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   EVENT_TRAINER_EYE_GetTrainerId  0x021AE884  thumb  ov021
 *   EVENT_TRAINER_CheckDefeatedFlag  0x0215A4D8  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern unsigned EVENT_TRAINER_CheckDefeatedFlag(void *a, unsigned b);
extern void *FIELDMAP_GetGameSystem(void *p);
extern int EVENT_TRAINER_EYE_GetTrainerId(u32 a);

int EVENT_TRAINER_EYE_IsTrainerDefeated(u32 a, u32 b)
{
return EVENT_TRAINER_CheckDefeatedFlag((void *)GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData((const struct Ctx *)FIELDMAP_GetGameSystem((void *)a))), EVENT_TRAINER_EYE_GetTrainerId(b));
}

