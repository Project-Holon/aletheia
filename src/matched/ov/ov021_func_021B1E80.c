/*
 * function: SCRCMD_FLDMMDL_TurnPlayerToFrontEvent
 * address:  0x021B1E80
 * packet:   pkt_ov021_021B1E80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_FLDMMDL_TurnPlayerToFrontEvent  0x021B1E80  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   EVENTDATA_SYSTEM_SearchPosEvent  0x021627C8  thumb  ov010
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   EVENT_FIELD_PROCLINK_CreateObjAnimEvent  0x021618A0  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   gScrcmdFldmmdlFacingCodes     0x021D93FC  data   a2
 *   gScrcmdFldmmdlTurnRightAcmdList     0x021D9404  data   a4
 *   gScrcmdFldmmdlTurnLeftAcmdList     0x021D940C  data   a4
 *   gScrcmdFldmmdlTurnDownAcmdList     0x021D9414  data   a4
 *   gScrcmdFldmmdlTurnUpAcmdList     0x021D941C  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { int x, y, z; } V;
typedef struct { u16 v[4]; } Ids;

extern Ids gScrcmdFldmmdlFacingCodes;
extern u8 gScrcmdFldmmdlTurnRightAcmdList[];
extern u8 gScrcmdFldmmdlTurnLeftAcmdList[];
extern u8 gScrcmdFldmmdlTurnDownAcmdList[];
extern u8 gScrcmdFldmmdlTurnUpAcmdList[];

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct BigObj;
extern u32 GAME_DATA_GetEventData(const struct BigObj *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *, struct VecFx32 *);
struct Ctx;
struct Rec;
extern struct Rec *EVENTDATA_SYSTEM_SearchPosEvent(struct Ctx *c, void *a, int key, int mode);
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
extern void *EVENT_FIELD_PROCLINK_CreateObjAnimEvent(void *p, int a1, int a2, int a3);
extern void SCRIPT_SYS_CallEvent(void *, void *);

int SCRCMD_FLDMMDL_TurnPlayerToFrontEvent(void *a, u32 b)
{
    void *o;
    int q;
    void *e;
    void *d;
    Ids ids;
    int i;
    u32 h, f;
    void *m;
    V pos;
    int id;
    int found;
    int k;
    u8 *tbl;

    o = SCRCMD_WORK_GetScriptWork((void *)b);
    q = ((int *)SCRIPT_WORK_ResetFieldParam((int)o))[1];
    e = SCRCMD_WORK_GetGameData((void *)b);
    d = SCRCMD_WORK_GetGameSystem((void *)b);
    ids = gScrcmdFldmmdlFacingCodes;
    h = GAME_DATA_GetEventData(e);
    f = GAME_DATA_GetEventWork(e);
    m = FIELDMAP_GetFieldPlayer((void *)q);
    FIELD_PLAYER_GetPos(m, (struct VecFx32 *)&pos);
    for (i = 0; i < 4; i++) {
        id = ids.v[i];
        if (EVENTDATA_SYSTEM_SearchPosEvent((struct Ctx *)h, (void *)f, (int)(&pos), id) != 0) {
            found = id;
            break;
        }
    }
    k = FIELD_PLAYER_GetDirDisp(m);
    if (k != found) {
        if (found == 0) {
            tbl = gScrcmdFldmmdlTurnUpAcmdList;
        } else if (found == 1) {
            tbl = gScrcmdFldmmdlTurnDownAcmdList;
        } else if (found == 2) {
            tbl = gScrcmdFldmmdlTurnLeftAcmdList;
        } else if (found == 3) {
            tbl = gScrcmdFldmmdlTurnRightAcmdList;
        } else {
            return 0;
        }
        SCRIPT_SYS_CallEvent(o, EVENT_FIELD_PROCLINK_CreateObjAnimEvent(d, q, 0xff, (int)tbl));
        return 1;
    }
    return 0;
}
