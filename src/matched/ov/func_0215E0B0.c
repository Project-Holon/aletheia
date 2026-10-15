/*
 * function: SCRCMD_MUSICAL_WaitSessionReady
 * address:  0x0215E0B0
 * packet:   pkt_0215E0B0
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
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetExternalWork  0x02012F80  thumb
 *   MUSICAL_EVENT_CheckNetError  0x02156BAC  thumb  ov010
 *   MUSICAL_EVENT_IsAborted  0x02156BCC  thumb  ov010
 *   STA_NET_GetIndexedWord5E  0x021FD844  thumb
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern int GAME_DATA_GetExternalWork(char *base);
extern int MUSICAL_EVENT_CheckNetError();
extern u32 MUSICAL_EVENT_IsAborted(void *p);
extern int STA_NET_GetIndexedWord5E();

int SCRCMD_MUSICAL_WaitSessionReady(int a0, int a1)
{
    int t4;
    void *v0;
    void *v1;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0215E0BA:
a0 = t4 + 0;
    v1 = SCRCMD_WORK_GetGameData((void *)a0);
loc_0215E0C0:
    a0 = GAME_DATA_GetExternalWork(v1);
loc_0215E0C4:
t4 = a0 + 0;
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    a0 = MUSICAL_EVENT_CheckNetError(a0);
loc_0215E0CC:
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    a0 = MUSICAL_EVENT_IsAborted((void *)a0);
loc_0215E0D2:
    if (a0 != 1) goto loc_0215E0DA;
loc_0215E0D6:
a0 = 1;
    return a0;
loc_0215E0DA:
a0 = *(int *)&((struct Obj00005 *)t4)->f4;
    a0 = STA_NET_GetIndexedWord5E(a0);
loc_0215E0E0:
    if (a0 != 1) goto loc_0215E0E8;
loc_0215E0E4:
a0 = 1;
    return a0;
loc_0215E0E8:
a0 = 0;
    return a0;}
