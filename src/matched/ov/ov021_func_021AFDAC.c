/*
 * function: SCRCMD_WarpToPositionEvent
 * address:  0x021AFDAC
 * packet:   pkt_ov021_021AFDAC
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
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   EVENTDATA_SYSTEM_SearchPosEventIgnoreHeight  0x0216282C  thumb  ov010
 *   EVENTDATA_SYSTEM_GetPosEventCenterPosThunk  0x02162A6C  thumb  ov010
 *   EVENT_MAPCHANGE_CreateWarpEventWithTargetPos  0x02184E40  thumb  ov020
 *   FLDEFF_GYOE_StartHeld  0x021BB578  thumb  ov021
 */

struct Ctx;
struct Rec;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
extern void *SCRIPT_WORK_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
typedef unsigned short u16;
struct Evt;
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern u32 GAMESYSTEM_GetEvent(const struct Ctx *p);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventData(const struct BigObj *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u32 FIELDMAP_GetEffect(u8 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern struct Rec *EVENTDATA_SYSTEM_SearchPosEventIgnoreHeight(struct Ctx *c, void *a, int *key, int mode);
extern void EVENTDATA_SYSTEM_GetPosEventCenterPosThunk(int a, int b);
extern void *EVENT_MAPCHANGE_CreateWarpEventWithTargetPos();
extern void FLDEFF_GYOE_StartHeld(int a, int b, int c, int d);

int SCRCMD_WarpToPositionEvent(int a0, int a1)
{
    void *h;
    void *a;
    int b;
    int c;
    int d;
    void *e;
    int f;
    void *g;
    int w;
    struct Rec *r;
    int out[3];
    int arr[3];
    int buf[3];

    h = (void *)SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork((void *)a1));
    a = GAMESYSTEM_GetFieldMap(h);
    b = VM_GetU16((struct Stream *)a0);
    c = VM_GetU16((struct Stream *)a0);
    d = VM_GetU16((struct Stream *)a0);
    e = GAMESYSTEM_GetGameData(h);
    f = GAME_DATA_GetEventData(e);
    g = (void *)GAME_DATA_GetEventWork(e);
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer((void *)a), (struct VecFx32 *)buf);
    r = EVENTDATA_SYSTEM_SearchPosEventIgnoreHeight((struct Ctx *)f, (void *)g, buf, 9);
    if (r != 0)
        EVENTDATA_SYSTEM_GetPosEventCenterPosThunk((int)r, (int)out);
    arr[0] = c << 16;
    arr[1] = 0;
    arr[2] = d << 16;
    w = GAMESYSTEM_GetEvent(h);
    GAME_EVENT_CallEvent((struct Evt *)w, EVENT_MAPCHANGE_CreateWarpEventWithTargetPos(h, a, out, b, arr));
    g = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((void *)a));
    FLDEFF_GYOE_StartHeld(FIELDMAP_GetEffect(a), (int)g, 0, 1);
    return 1;
}
