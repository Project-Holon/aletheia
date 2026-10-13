/*
 * function: SCRCMD_NETWORK_CmdRestartAutoComm
 * address:  0x0215F280
 * packet:   pkt_0215F280
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Frame teardown on the handle the overlay index returned, then the
 * overlay's own mode setter.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem   0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_SetCommBlocked   0x0201213C  thumb
 *   GAMESYSTEM_TryStartAutoComm   0x020121CC  thumb
 *   SCRIPT_WORK_ResetCheckFlag   0x02159168  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
struct IcaAnime;
extern void GAMESYSTEM_SetCommBlocked(struct Ctx *p, u32 v);
extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);
extern void SCRIPT_WORK_ResetCheckFlag(int);

int SCRCMD_NETWORK_CmdRestartAutoComm(void *a0, void *a1)
{
    void *p = SCRCMD_WORK_GetGameSystem(a1);

    GAMESYSTEM_SetCommBlocked(p, 0);
    GAMESYSTEM_TryStartAutoComm(p);
    SCRIPT_WORK_ResetCheckFlag(0xB);

    return 1;
}

