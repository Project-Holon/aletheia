/*
 * function: SCRCMD_NETWORK_CmdClearAlwaysNet
 * address: 0x0215F2DC
 * packet: pkt_ov010_0215F2DC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   GAMESYSTEM_SetAlwaysNetFlag 0x02012158 thumb
 */

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void GAMESYSTEM_SetAlwaysNetFlag(char *p, unsigned int v);
int SCRCMD_NETWORK_CmdClearAlwaysNet(void *a, void *b) { GAMESYSTEM_SetAlwaysNetFlag(SCRCMD_WORK_GetGameSystem(b), 0); return 0; }
