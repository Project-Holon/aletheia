/*
 * function: SCRCMD_NETWORK_CmdStartAutoComm
 * address:  0x0215F228
 * packet:   pkt_0215F228
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct IcaAnime;
extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);

int SCRCMD_NETWORK_CmdStartAutoComm(int a0, int a1)
{
    void *v0;

a0 = a1 + 0;
    v0 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0215F230:
    a0 = GAMESYSTEM_TryStartAutoComm(v0);
loc_0215F234:
a0 = 1;
    return a0;}
