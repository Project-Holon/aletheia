/*
 * function: SCRCMD_WarpToPosition3D
 * address:  0x021AFEFC
 * packet:   pkt_ov021_021AFEFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   VM_GetU16  0x02011330  thumb
 *   GAMESYSTEM_GetEvent  0x02012104  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   EVENT_MAPCHANGE_CreateWarpEventDefaultTransition  0x021854B0  thumb  ov020
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
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern void *EVENT_MAPCHANGE_CreateWarpEventDefaultTransition();

int SCRCMD_WarpToPosition3D(int a0, int a1)
{
    void *h;
    void *a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int arr[3];
    int w;

    h = (void *)SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork((void *)a1));
    a = GAMESYSTEM_GetFieldMap(h);
    b = VM_GetU16((struct Stream *)a0);
    c = VM_GetU16((struct Stream *)a0);
    d = VM_GetU16((struct Stream *)a0);
    e = VM_GetU16((struct Stream *)a0);
    f = VM_GetU16((struct Stream *)a0);
    FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((void *)a));
    arr[0] = c << 16;
    arr[1] = d << 16;
    arr[2] = e << 16;
    w = GAMESYSTEM_GetEvent(h);
    GAME_EVENT_CallEvent((struct Evt *)w, EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(h, a, b, arr, f));
    return 1;
}
