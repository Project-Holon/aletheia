/*
 * function: EVENT_FIELD_PROCLINK_StartSeasonCommProc
 * address: 0x02161D18
 * packet: pkt_ov010_02161D18
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Padding: two zero alignment bytes after the 74-byte function.
 * Lever: c and d are u8, as in matched caller EVENT_FIELD_PROCLINK_CreateCommExitEvent.c;
 * this puts the c home store before r0 is assigned b for the first call.
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetSeason 0x02012984 thumb
 *   FIELD_CLOCK_GetHour 0x02169100 thumb ov010
 *   FIELD_CLOCK_GetMinute 0x02169110 thumb ov010
 *   EVENT_FIELD_PROCLINK_SetCommProcParam 0x02161C84 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern int FIELD_CLOCK_GetHour(int);
extern int FIELD_CLOCK_GetMinute(int);
extern void EVENT_FIELD_PROCLINK_SetCommProcParam(int, int, int, u8, u32, u8, u8, int);
void EVENT_FIELD_PROCLINK_StartSeasonCommProc(int a, int b, u8 c, u8 d)
{
    int r4 = (int)GAMESYSTEM_GetGameData((const struct Ctx *)b);
    int r6 = FIELD_CLOCK_GetHour(r4);
    int r7 = FIELD_CLOCK_GetMinute(r4);
    int r0 = GAME_DATA_GetSeason((const struct BigObj *)r4);
    EVENT_FIELD_PROCLINK_SetCommProcParam(a, b, c, d, 0, (u8)r6, (u8)r7, r0);
}
