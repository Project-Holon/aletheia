/*
 * function: SCRCMD_TRIALHOUSE_FreeWork
 * address:  0x0216A420
 * packet:   pkt_0216A420
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 32 compiled 30 wild=4
 *
 * Overlay index, then the record's handle and one arm9 probe go to the
 * overlay's own pair call.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem   0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData   0x020120F4  thumb
 *   GAME_DATA_GetListCursor   0x02012F50  thumb
 *   TRIAL_HOUSE_DeleteWork   0x021D0A48  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetListCursor(void *base);
extern void TRIAL_HOUSE_DeleteWork(void *, void *);

int SCRCMD_TRIALHOUSE_FreeWork(void *a0, void *a1)
{
    void *p = SCRCMD_WORK_GetGameSystem(a1);

    TRIAL_HOUSE_DeleteWork(p, GAME_DATA_GetListCursor(GAMESYSTEM_GetGameData(p)));

    return 0;
}

