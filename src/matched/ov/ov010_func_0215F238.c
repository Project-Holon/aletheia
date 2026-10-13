/*
 * function: SCRCMD_NETWORK_CmdRequestCommExit
 * address:  0x0215F238
 * packet:   pkt_ov010_0215F238
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAMESYSTEM_SetCommBlocked  0x0201213C  thumb
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 */

extern void *SCRCMD_WORK_GetGameSystem(void *p);
struct Ctx;
extern unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Comm;
struct Ctx;
extern u32 GAME_COMM_GetKind(void *obj);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern void GAMESYSTEM_SetCommBlocked(struct Ctx *p, u32 v);
extern void SCRIPT_WORK_SetCheckFlag(int v);

int SCRCMD_NETWORK_CmdRequestCommExit(void *a, void *b)
{
    void *t;
    void *s;

    t = SCRCMD_WORK_GetGameSystem(b);
    s = (void *)GAMESYSTEM_GetGameComm(t);
    switch (GAME_COMM_GetKind(s)) {
    case 1:
    case 2:
    case 5:
        GAME_COMM_RequestExitNoCallback(s);
        break;
    case 0:
    case 3:
    case 4:
        break;
    }
    GAMESYSTEM_SetCommBlocked(t, 1);
    SCRIPT_WORK_SetCheckFlag(0xb);
    return 1;
}
