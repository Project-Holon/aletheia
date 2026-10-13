/*
 * function: SCRCMD_WarpToPositionPlain
 * address:  0x021AFD44
 * packet:   pkt_ov021_021AFD44
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   VM_GetU16  0x02011330  thumb
 *   GAMESYSTEM_GetEvent  0x02012104  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   EVENT_MAPCHANGE_CreateWarpEventPlain  0x02185534  thumb  ov020
 */

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned int   u32;
struct Ctx;
extern void *SCRIPT_WORK_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
typedef unsigned short u16;
struct Evt;
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern u32 GAMESYSTEM_GetEvent(const struct Ctx *p);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void *EVENT_MAPCHANGE_CreateWarpEventPlain();

int SCRCMD_WarpToPositionPlain(int a0, int a1)
{
    void *h;
    void *a;
    int b;
    int c;
    int d;
    int e;
    int arr[3];
    int w;

    h = (void *)SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork((void *)a1));
    a = GAMESYSTEM_GetFieldMap(h);
    b = VM_GetU16((struct Stream *)a0);
    c = VM_GetU16((struct Stream *)a0);
    d = VM_GetU16((struct Stream *)a0);
    e = VM_GetU16((struct Stream *)a0);
    arr[0] = c << 16;
    arr[1] = 0;
    arr[2] = d << 16;
    w = GAMESYSTEM_GetEvent(h);
    GAME_EVENT_CallEvent((struct Evt *)w, EVENT_MAPCHANGE_CreateWarpEventPlain(h, a, b, arr, e));
    return 1;
}
