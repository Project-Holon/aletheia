/*
 * function: EVENT_FIELD_PROCLINK_CreateTrainerCardView
 * address:  0x0216117C
 * packet:   pkt_ov010_0216117C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   FIELD_SOUND_SYSTEM_LowerVolume  0x02029DBC  thumb
 *   ZONEDATA_IsUnionRoom  0x02013CC8  thumb
 *   ZONEDATA_IsZone96Pair  0x02013CE0  thumb
 *   TRCARD_SYS_CreateViewWork  0x0216F7BC  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;

extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u16 *GAME_DATA_GetMyPlayerWork();
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern u32 GAMESYSTEM_GetIssSystem(u32 *p);
extern void FIELD_SOUND_SYSTEM_LowerVolume(u8 *a, u32 b);
extern u32 ZONEDATA_IsUnionRoom(u32 id);
extern u32 ZONEDATA_IsZone96Pair(u32 id);
extern int *TRCARD_SYS_CreateViewWork();

void EVENT_FIELD_PROCLINK_CreateTrainerCardView(int *a0, int a1)
{
    void *h = GAMESYSTEM_GetGameData((const struct Ctx *)*(int *)a0[6]);
    u32 v = *GAME_DATA_GetMyPlayerWork(h);
    int f = 1;
    int s;
    int *r;

    s = GAME_DATA_GetBgmInfo(h);
    FIELD_SOUND_SYSTEM_LowerVolume((u8 *)s, GAMESYSTEM_GetIssSystem((u32 *)(*(int *)a0[6])));
    if (ZONEDATA_IsUnionRoom(v) != 0 || (int)ZONEDATA_IsZone96Pair((u16)v) != 0) {
        f = 0;
    }
    r = TRCARD_SYS_CreateViewWork(h, 4, f);
    if (a1 != -1) {
        r[5] = a1;
    }
}
