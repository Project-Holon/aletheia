/*
 * function: EVENT_COMM_COMMON_CmdGetIntrudeDistance
 * address:  0x0217FAE0
 * packet:   pkt_ov018_0217FAE0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * What closed it: the store through `out` is written in each arm of the
 * if/else (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md)
 * rather than once after it through a shared `v`; the single store made
 * `v` live across the join and coloured out/q/temp as r6/r4/r5 instead of
 * r5/r6/r4 (docs/notes/pkt_ov018_0217FAE0.c.txt has the earlier miss).
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAME_DATA_GetIntrudeIdByte  0x0215841C  thumb  ov010
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
void *SCRCMD_WORK_GetGameSystem(void *a0);
typedef unsigned int   u32;
struct BigObj;
struct Ctx;
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
u8 GAME_DATA_GetIntrudeIdByte(void *p);
u8 GAME_DATA_GetOwnNetId(const struct BigObj *p);

int EVENT_COMM_COMMON_CmdGetIntrudeDistance(void *unused, int a)
{
    u16 *out;
    void *t;
    void *q;
    int v;

    out = SCRIPT_WORK_ReadWorkPointer(unused, (void *)a);
    t = SCRCMD_WORK_GetGameSystem((void *)a);
    GAMESYSTEM_GetGameComm(t);
    q = GAMESYSTEM_GetGameData(t);
    if (GAME_DATA_GetIntrudeIdByte(q) == GAME_DATA_GetOwnNetId(q)) {
        *out = 0;
    } else {
        v = GAME_DATA_GetIntrudeIdByte(q) - GAME_DATA_GetOwnNetId(q);
        if (v < 0) {
            v += 3;
        }
        *out = v;
    }
    return 0;
}
