/*
 * function: INTRUDE_FIELD_TaskAreaChange
 * address:  0x0217B214
 * packet:   pkt_ov018_0217B214
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_DATA_GetPlayerStatus  0x02012950  thumb
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_020362DC  0x020362DC  arm
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_IsStepToOwnArea  0x021584A4  thumb
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   INTRUDE_COMM_IsSessionBusy  0x02175BE4  thumb  ov011
 *   INTRUDE_COMM_PickDefaultObjCode  0x02175548  thumb
 *   INTRUDE_FIELD_InitMmdlCopyAnime  0x0217C758  thumb
 *   INTRUDE_FIELD_MainMmdlCopyAnime  0x0217C820  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   FIELD_MSGBG_CreateBottomMsgWin  0x021907A8  thumb  ov021
 *   FIELD_MSGBG_MsgWinPrintMsg  0x02190740  thumb  ov021
 *   FIELD_MSGBG_MsgWinPrintStr  0x02190758  thumb
 *   FIELD_MSGBG_IsMsgWinTransDone  0x0219077C  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb  ov021
 *   func_021BC5A0  0x021BC5A0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Obj;
struct Ctx;
struct Sub24;
struct Rec44;
struct WordSet;
struct U16Vec;
struct MsgBank;

typedef struct {
    unsigned char *f0;
    int f4;
    int f8;
    int fc;
    struct WordSet *f10;
    u16 f14;
    u8 f16;
    u8 f17;
    int f18;
} Obj;

typedef struct {
    u8 pad0[0x86];
    u16 slot : 3;
    u16 rest : 13;
} Peer;

typedef struct {
    u8 b0;
    u8 b1;
    u16 h2;
} Tmp;

extern void *func_020124E4(struct Obj *p);
struct BigObj;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern struct Rec44 *GAME_DATA_GetPlayerStatus(struct Sub24 *p, u32 i);
extern u8 GAME_DATA_GetExitMode(const struct BigObj *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201ED04(struct WordSet *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
struct Rec;
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 func_020362DC(void);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern int INTRUDE_COMM_IsStepToOwnArea();
extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern void FLDMMDL_SysPauseMove(void *map);
extern u32 *FLDMMDL_SysResumeMove(void *c);
extern int INTRUDE_COMM_IsSessionBusy(void *a);
extern void INTRUDE_COMM_PickDefaultObjCode();
extern void INTRUDE_FIELD_InitMmdlCopyAnime();
extern int INTRUDE_FIELD_MainMmdlCopyAnime();
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern int FIELDMAP_GetPlaceName();
extern int FIELDMAP_GetZoneId();
extern int FIELD_MSGBG_CreateMsgData(u32 a, u32 b);
extern int FIELD_MSGBG_CreateBottomMsgWin();
extern int FIELD_MSGBG_MsgWinPrintMsg(u32 a, u32 b, u32 c, u32 d);
extern void FIELD_MSGBG_MsgWinPrintStr();
extern int FIELD_MSGBG_IsMsgWinTransDone(u8 *p);
extern int FIELD_MSGBG_DeleteMsgWin(void *a);
extern void func_021BC5A0();

int INTRUDE_FIELD_TaskAreaChange(int a0, int *state, Obj *o)
{
    void *w;
    int h;
    void *ctx;
    Peer *p;
    int t;
    struct U16Vec *a;
    void *b;
    Tmp tmp;

    w = func_020124E4((struct Obj *)a0);
    h = GAMESYSTEM_GetGameComm(w);
    ctx = GAMESYSTEM_GetGameData(w);
    p = (Peer *)INTRUDE_COMM_GetWorkIfRunning(h);
    switch (*state) {
    case 0:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(o->f0));
        *state += 1;
        break;
    case 1:
        if (FLDMMDL_CheckPossibleAcmd(o->f4) == 0)
            break;
        if (p == 0) {
            *state = 6;
            break;
        }
        if (INTRUDE_COMM_IsSessionBusy((u8 *)p + 0x1AC) == 1) {
            o->f16 = 1;
            INTRUDE_FIELD_InitMmdlCopyAnime(&o->f18, w, o->f0, p, 0, 0, 0, o->f14, 0);
        } else if (INTRUDE_COMM_IsStepToOwnArea(h, ctx, o->f14) == 1) {
            INTRUDE_FIELD_InitMmdlCopyAnime(&o->f18, w, o->f0, p, 0, 0, 0, o->f14, 1);
        } else {
            INTRUDE_COMM_PickDefaultObjCode(GAME_DATA_GetMyStatus(ctx), &tmp.h2, &tmp.b1, &tmp.b0);
            INTRUDE_FIELD_InitMmdlCopyAnime(&o->f18, w, o->f0, p, tmp.h2, tmp.b1, tmp.b0, o->f14, 1);
        }
        *state += 1;
        break;
    case 2:
        if (INTRUDE_FIELD_MainMmdlCopyAnime(&o->f18, p) == 1)
            *state += 1;
        break;
    case 3:
        if (p == 0) {
            *state = 6;
            break;
        }
        t = FIELDMAP_GetMsgBg(o->f0);
        o->f8 = FIELD_MSGBG_CreateMsgData(t, 0x2D);
        o->fc = FIELD_MSGBG_CreateBottomMsgWin(t, o->f8);
        o->f10 = func_0201EC64(4);
        if (p->slot == GAME_DATA_GetExitMode(ctx)) {
            if (o->f16 == 1)
                FIELD_MSGBG_MsgWinPrintMsg(o->fc, 0, 0, 0x4F);
            else
                FIELD_MSGBG_MsgWinPrintMsg(o->fc, 0, 0, 0x4E);
        } else {
            a = STRBUF_Create(0x100, 0x15);
            func_0201F02C(o->f10, 0, GAME_DATA_GetPlayerStatus(ctx, p->slot));
            if (o->f16 == 1)
                b = func_02045EC0((struct MsgBank *)o->f8, 0x50);
            else
                b = func_02045EC0((struct MsgBank *)o->f8, 0x51);
            func_0201F250(o->f10, a, b);
            FIELD_MSGBG_MsgWinPrintStr(o->fc, 0, 0, a);
            STRBUF_Delete(b);
            STRBUF_Delete(a);
        }
        *state += 1;
        break;
    case 4:
        if (FIELD_MSGBG_IsMsgWinTransDone((u8 *)o->fc) == 1) {
            t = FIELDMAP_GetPlaceName(o->f0);
            func_021BC5A0(t, FIELDMAP_GetZoneId(o->f0));
            *state += 1;
        }
        break;
    case 5:
        if (func_020362DC() & 0xF3)
            *state += 1;
        break;
    case 6:
        if (o->fc != 0) {
            FIELD_MSGBG_DeleteMsgWin((void *)o->fc);
            MSGDATA_Delete((struct Rec *)o->f8);
            func_0201ED04(o->f10);
        }
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(o->f0));
        return 1;
    }
    return 0;
}
