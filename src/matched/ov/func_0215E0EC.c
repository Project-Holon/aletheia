/*
 * function: SCRCMD_MUSICAL_WaitCommAttach
 * address:  0x0215E0EC
 * packet:   pkt_0215E0EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:  
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_DATA_GetExternalWork  0x02012F80  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int GAME_DATA_GetExternalWork(char *base);
extern u32 func_02026454(void *obj);
extern u32 func_02026474(void *obj);

int SCRCMD_MUSICAL_WaitCommAttach(int a0, int a1)
{
    int t4;
    int t5;
    void *v0;
    void *v1;
    void *v2;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0215E0F6:
a0 = t4 + 0;
    v1 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0215E0FC:
a0 = t4 + 0;
    v2 = SCRCMD_WORK_GetGameData((void *)a0);
loc_0215E104:
    a0 = GAMESYSTEM_GetGameComm(v1);
loc_0215E10C:
t5 = a0 + 0;
    a0 = GAME_DATA_GetExternalWork(v2);
loc_0215E114:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02026454((void *)a0);
loc_0215E11C:
    if (a0 != 4) goto loc_0215E12C;
loc_0215E120:
a0 = t5 + 0;
    a0 = func_02026474((void *)a0);
loc_0215E126:
*(int *)&((struct Obj00005 *)t4)->f4 = a0;
a0 = 1;
    return a0;
loc_0215E12C:
a0 = 0;
    return a0;}
