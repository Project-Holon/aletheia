/*
 * function: SCRCMD_PROC_CallFieldCloseEvent
 * address:  0x0215C610
 * packet:   pkt_0215C610
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern int SCRIPT_SYS_CallEvent();

int SCRCMD_PROC_CallFieldCloseEvent(int a0, int a1)
{
    int t4;
    void *v0;
    void *v1;
    void *v2;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0215C61A:
a0 = t4 + 0;
    v1 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0215C622:
    v2 = GAMESYSTEM_GetFieldMap(v1);
loc_0215C628:
    a0 = FIELD_STATUS_CreateFieldCloseEvent((int)v1, (int)v2);
loc_0215C630:
a1 = a0 + 0;
    a0 = SCRIPT_SYS_CallEvent(v0, a1);
loc_0215C638:
a0 = 1;
    return a0;}
