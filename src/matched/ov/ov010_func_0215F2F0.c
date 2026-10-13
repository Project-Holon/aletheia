/*
 * function: SCRCMD_NETWORK_CmdLoadNpcTable
 * address: 0x0215F2F0
 * packet: pkt_ov010_0215F2F0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRCMD_WORK_GetScriptWork 0x0215A5F4 thumb ov010
 *   ARC_UTIL_LoadMember 0x0204A1BC arm
 *   SCRIPT_WORK_SetReturnFlag 0x02159114 thumb ov010
 */

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int ARC_UTIL_LoadMember(int,int,int,int);
typedef unsigned int   u32;
extern void *SCRIPT_WORK_SetReturnFlag(void *p, u32 v);
int SCRCMD_NETWORK_CmdLoadNpcTable(void *a, void *b) { void *p = SCRCMD_WORK_GetScriptWork(b); SCRIPT_WORK_SetReturnFlag(p,ARC_UTIL_LoadMember(0xd1,0,0,0x8004)); return 0; }
