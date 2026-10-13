/*
 * function: EVENT_COMM_COMMON_CmdGetObjCode
 * address: 0x0217F8A0
 * packet: pkt_ov018_0217F8A0
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding follow at 0x0217F8CE.
 * lever: stores in both arms keep the branch to the shared store.
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   GAMESYSTEM_GetGameComm 0x02012138 thumb
 *   INTRUDE_COMM_GetWorkIfRunning 0x02158344 thumb ov010
 */
#include "../include/Obj12499.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *, void *);
extern void *SCRCMD_WORK_GetGameSystem(void *);
struct Ctx;
extern unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
int EVENT_COMM_COMMON_CmdGetObjCode(void *a, void *vm)
{
    u16 *out;
    u8 *p;
    int v;
    out = SCRIPT_WORK_ReadWorkPointer(a, vm);
    p = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)((void *)GAMESYSTEM_GetGameComm(SCRCMD_WORK_GetGameSystem(vm))));
    if (p == 0 || ((struct Obj12499 *)p)->f88 == 0) {
        *out = 0;
    } else {
        *out = ((struct Obj12499 *)p)->f88;
    }
    return 0;
}
