/*
 * function: SCRCMD_MUSICAL_WaitSetMemberCount
 * address:  0x0215E068
 * packet:   pkt_0215E068
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 72 compiled 70
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetExternalWork  0x02012F80  thumb
 *   MUSICAL_EVENT_CheckNetError  0x02156BAC  thumb  ov010
 *   MUSICAL_EVENT_IsAborted  0x02156BCC  thumb  ov010
 *   MUS_COMM_FUNC_CheckTimingSync  0x021FCE00  thumb
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern int GAME_DATA_GetExternalWork(char *base);
extern void MUSICAL_EVENT_CheckNetError(void *p);
extern u32 MUSICAL_EVENT_IsAborted(void *p);
extern int MUS_COMM_FUNC_CheckTimingSync();

int SCRCMD_MUSICAL_WaitSetMemberCount(int a0, int a1)
{
    int t4;
    void *v0;
    void *v1;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0215E072:
a0 = t4 + 0;
    v1 = SCRCMD_WORK_GetGameData((void *)a0);
loc_0215E078:
    a0 = GAME_DATA_GetExternalWork(v1);
loc_0215E07C:
t4 = a0 + 0;
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    if (a0 == 0) goto loc_0215E096;
loc_0215E084:
    MUSICAL_EVENT_CheckNetError((void *)a0);
loc_0215E088:
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    a0 = MUSICAL_EVENT_IsAborted((void *)a0);
loc_0215E08E:
    if (a0 != 1) goto loc_0215E096;
loc_0215E092:
a0 = 1;
    return a0;
loc_0215E096:
a1 = ((struct Obj00005 *)t4)->f34;
a0 = *(int *)&((struct Obj00005 *)t4)->f4;
a1 = a1 << 0x18;
a1 = (unsigned)a1 >> 0x18;
    a0 = MUS_COMM_FUNC_CheckTimingSync(a0, a1);
loc_0215E0A2:
    if (a0 != 1) goto loc_0215E0AA;
loc_0215E0A6:
a0 = 1;
    return a0;
loc_0215E0AA:
a0 = 0;
    return a0;}
