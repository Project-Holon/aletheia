/*
 * function: NAMEIN_SETUP_StartNameBalloonFromHistory
 * address:  0x0216CB48
 * packet:   pkt_ov010_0216CB48
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The third parameter is u8: with it declared int the body is byte-identical
 * except that the w->owner store and the next call's argument move swap
 * places (4 bytes); the u8 spill to [sp,#8] changes nothing visible but the
 * schedule.  Found by tools/permuter.py --types.  The call to arm9
 * 0x0202435C (an unlabelled two-slot wrapper) is attested by its shard.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   GAME_EVENT_Create   0x020122C0  thumb
 *   GAME_EVENT_GetWork   0x020124E8  thumb
 *   GAME_DATA_GetOccupyInfo  0x02012964  thumb
 *   FLDMMDL_SysSearchPlayer  0x0216DEE0  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   SCRCMD_MSGWIN_GetBalloonSide  0x021B0A40  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   SCRCMD_MSGWIN_GetBalloonOffset  0x021B09D8  thumb  ov021
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_020071CC  0x020071CC  thumb
 *   BSUBWAY_SAVEDATA_AllocHistoryCopy  0x0200DF58  thumb
 *   PMSI_PARAM_ToString  0x0202435C  thumb
 *   func_020307B0  0x020307B0  arm
 *   SCRCMD_MSGWIN_GetBalloonTailParams  0x021B09EC  thumb  ov021
 *   FIELD_MSGBG_AddTalkWin  0x0219129C  thumb  ov021
 *   NAMEIN_SETUP_RunNameBalloonWaitEvent  0x0216CAF4  thumb  ov010
 *
 * evidence: 0x0202435C is an unlabelled ARM9 thunk ("ldr r3, =PMSI_PARAM_ToStringWords; movs r2, #2; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov069 0x021BA21A, ov093 0x021D1894, ov010 0x02168138), so the call
 * attests as `label`.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;
typedef s32            fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Work {
    void   *owner;      /* 0x00 */
    u32     field04;    /* 0x04 */
    VecFx32 pos;        /* 0x08 */
    u32     field14;    /* 0x14 */
    void   *field18;    /* 0x18 */
} Work;

struct Actor;
struct Big;
struct Ctx;
struct Desc;
struct Obj;
struct Sub020071CCCtrl;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct BigObj;
struct Ent;
struct Q;
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern struct Desc *GAME_EVENT_Create(void *owner, void *a, void *b, u32 size);
extern void *GAME_EVENT_GetWork(struct Obj *p);
extern u32 GAME_DATA_GetOccupyInfo(const struct BigObj *p);
extern void *FLDMMDL_SysSearchPlayer(void *a0);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
extern int SCRCMD_MSGWIN_GetBalloonSide(u32 a, struct Q *q);
extern void *FIELDMAP_GetCamera(void *p);
extern u32 FIELD_CAMERA_GetG3dCamera(u8 *p);
extern void  SCRCMD_MSGWIN_GetBalloonOffset(VecFx32 *pos, VecFx32 *out, void *a, void *b, void *c);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
struct Buf3FC;
struct RecSlot;
extern struct Buf3FC *BSUBWAY_SAVEDATA_AllocHistoryCopy(struct RecSlot *p, u32 heap);
extern void *PMSI_PARAM_ToString(void *slots, unsigned int heap);
extern u32 func_020307B0(void *p);
extern void SCRCMD_MSGWIN_GetBalloonTailParams(int sel, int *a, int *b);
extern struct Ent *FIELD_MSGBG_AddTalkWin(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
extern int NAMEIN_SETUP_RunNameBalloonWaitEvent(int a0, int a1, int a2);

void *NAMEIN_SETUP_StartNameBalloonFromHistory(void *owner, int idx, u8 arg)
{
    void *sys;
    void *anm;
    void *ctx;
    void *task;
    Work *w;
    void *mdl;
    void *m2;
    void *cam;
    VecFx32 ofs;
    s32 b;
    s32 c;
    u8 *tbl;

    sys = GAMESYSTEM_GetGameData(owner);
    anm = GAMESYSTEM_GetFieldMap(owner);
    ctx = (void *)FIELDMAP_GetMsgBg(anm);
    task = GAME_EVENT_Create(owner, 0, NAMEIN_SETUP_RunNameBalloonWaitEvent, sizeof(Work));
    w = GAME_EVENT_GetWork(task);
    w->owner = owner;
    mdl = (void *)GAME_DATA_GetOccupyInfo(sys);
    m2 = FLDMMDL_SysSearchPlayer(mdl);
    FLDMMDL_GetPos(FLDMMDL_SysSearchObjId(mdl, arg), &w->pos);
    mdl = (void *)SCRCMD_MSGWIN_GetBalloonSide((u32)m2, (struct Q *)(&w->pos));
    cam = FIELDMAP_GetCamera(anm);
    SCRCMD_MSGWIN_GetBalloonOffset(&w->pos, &ofs, (void *)FIELD_CAMERA_GetG3dCamera(cam), cam, mdl);
    w->pos.x += ofs.x;
    w->pos.y += ofs.y;
    w->pos.z += ofs.z;
    tbl = (u8 *)BSUBWAY_SAVEDATA_AllocHistoryCopy(func_020071CC(GAME_DATA_GetSaveControl(sys), 0x3b), 4);
    w->field18 = PMSI_PARAM_ToString(tbl + idx * 0x22 + 0x18, 4);
    func_020307B0(tbl);
    SCRCMD_MSGWIN_GetBalloonTailParams((int)mdl, &b, &c);
    w->field14 = (u32)FIELD_MSGBG_AddTalkWin(ctx, b, (u32)(&w->pos), (u32)w->field18, 0, c);
    return task;
}
