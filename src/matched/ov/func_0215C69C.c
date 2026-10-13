/*
 * function: SCRCMD_PROC_WaitOverlayProc
 * address:  0x0215C69C
 * packet:   pkt_0215C69C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetUserWork  0x02158FB8  thumb  ov010
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   func_020307B0  0x020307B0  arm
 *   SCRIPT_WORK_FreeUserWork  0x02158FBC  thumb  ov010
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
struct Ctx;
extern u32 SCRIPT_WORK_GetUserWork(void *p);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern u32 func_020307B0(void *p);
extern int SCRIPT_WORK_FreeUserWork();

int SCRCMD_PROC_WaitOverlayProc(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;

t4 = a1 + 0;
a0 = t4 + 0;
    t6 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0215C6A6:
a0 = t4 + 0;
    a0 = (int)SCRCMD_WORK_GetScriptWork((void *)a0); /* int-typed on purpose: pointer local changes codegen */
loc_0215C6AE:
t4 = a0 + 0;
    a0 = SCRIPT_WORK_GetUserWork((void *)a0);
loc_0215C6B4:
t5 = a0 + 0;
    a0 = GAMESYSTEM_GetProcStatus(t6);
loc_0215C6BC:
    if (a0 == 0) goto loc_0215C6C4;
loc_0215C6C0:
a0 = 0;
    return a0;
loc_0215C6C4:
a1 = *(int *)&((struct Obj00005 *)t5)->f8;
    if (a1 == 0) goto loc_0215C6D0;
loc_0215C6CA:
a0 = t5 + 0;
    a0 = ((int (*)())a1)(a0);
loc_0215C6CE:
    goto loc_0215C6E4;
loc_0215C6D0:
a0 = *(int *)&((struct Obj00005 *)((char *)t5))->f0;
    if (a0 == 0) goto loc_0215C6DA;
loc_0215C6D6:
    func_020307B0((void *)a0);
loc_0215C6DA:
a0 = *(int *)&((struct Obj00005 *)t5)->f4;
    if (a0 == 0) goto loc_0215C6E4;
loc_0215C6E0:
    func_020307B0((void *)a0);
loc_0215C6E4:
a0 = t4 + 0;
    a0 = SCRIPT_WORK_FreeUserWork(a0);
loc_0215C6EA:
a0 = 1;
    return a0;}
