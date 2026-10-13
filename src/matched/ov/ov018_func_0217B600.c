/*
 * function: INTRUDE_FIELD_EventExitConfirm
 * address:  0x0217B600
 * packet:   pkt_ov018_0217B600
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct (528 of 528 bytes).  Sole blocker: the THM_CALL at +0x13C to
 * 0x02012798, an unlabelled arm9 leaf that disasm.py prints as .word data in
 * pool_02012794 (asm/arm9/main.s), after the pop at 0x02012790 and before
 * GAME_DATA_GetMyPlayerWork; no listing labels it and this call is its only witness, so
 * every class refuses it.  Verified EXACT at 0x02012798 (arm9, thumb, 10 B):
 *
 *     u8 *GAME_DATA_GetPlayerWork(u8 *p, int i) { return p + 4 + i * 0x44; }
 *
 * It is the Rec44 indexer that belongs beside GAME_DATA_GetPlayerStatus in
 * src/matched/arm9/unit_02012924.c; once it is labelled or matched this file
 * should verify EXACT unchanged.  The 12-byte scratch is a cast u8 buffer
 * (docs/idioms/a-declared-struct-local-folds-to-sp-relative-a-cast-buffer-does-not.md):
 * the stores go through r7, which a declared struct folds to sp.
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetPlayerWork  0x02012798  thumb
 *   GAME_DATA_SetPlayerPosition  0x02012A90  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   INTRUDE_FIELD_InitPlayerSpin  0x0217C658  thumb
 *   INTRUDE_FIELD_StepPlayerSpin  0x0217C688  thumb
 *   EVENT_MAPCHANGE_CreateIntrudeReturnEvent  0x02185214  thumb
 *   FIELDMAP_IsReady  0x02188BE8  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   FIELD_MSGBG_CreateBottomMsgWin  0x021907A8  thumb  ov021
 *   FIELD_MSGBG_MsgWinPrintMsg  0x02190740  thumb  ov021
 *   FIELD_MSGBG_IsMsgWinTransDone  0x0219077C  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb  ov021
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb
 *   FIELD_MSGBG_CreateYesNoMenu  0x02190BE4  thumb
 *   FIELD_MSGBG_YesNoMenuMain  0x02190C78  thumb
 *   FIELD_MSGBG_DeleteSysWin  0x02190E40  thumb
 *   FIELD_MSGBG_SysWinPrintMsg  0x02190E74  thumb
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb
 *   FIELD_MSGBG_CreateBottomSysWin  0x02190F64  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FIELD_PLAYER_CheckFormModel  0x021A3238  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int x, y, z;
} V12;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    u8 f10[0x18];
    u16 f28;
} Obj;


typedef unsigned int   u32;
struct Comm;
struct Ctx;
struct Evt;
struct Obj;
struct Rec;
struct Rec44;
struct Vec12;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetPlayerWork(u8 *p, int i);
extern void GAME_DATA_SetPlayerPosition(struct Rec44 *p, const struct Vec12 *src);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern u32 func_0200FB24(void);
extern u32 GAME_COMM_GetKind(void *obj);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern void FLDMMDL_SetAcmd(void *a0, u16 a1);
extern int FLDMMDL_EndAcmd(char *p);
extern void FLDMMDL_SysPauseMove(void *map);
extern u32 *FLDMMDL_SysResumeMove(void *c);
extern void INTRUDE_FIELD_InitPlayerSpin();
extern int INTRUDE_FIELD_StepPlayerSpin();
extern int EVENT_MAPCHANGE_CreateIntrudeReturnEvent();
extern int FIELDMAP_IsReady();
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern int FIELDMAP_GetFieldPlayer();
extern int FIELD_MSGBG_CreateMsgData(u32 a, u32 b);
extern int FIELD_MSGBG_CreateBottomMsgWin();
extern int FIELD_MSGBG_MsgWinPrintMsg(u32 a, u32 b, u32 c, u32 d);
extern int FIELD_MSGBG_IsMsgWinTransDone(u8 *p);
extern int FIELD_MSGBG_DeleteMsgWin(void *a);
extern void FIELD_MSGBG_DeleteMenuFunc();
extern int FIELD_MSGBG_CreateYesNoMenu();
extern int FIELD_MSGBG_YesNoMenuMain();
extern void FIELD_MSGBG_DeleteSysWin();
extern void FIELD_MSGBG_SysWinPrintMsg();
extern int FIELD_MSGBG_SysWinMain();
extern int FIELD_MSGBG_CreateBottomSysWin();
extern int FIELD_PLAYER_GetMmdl();
extern int FIELD_PLAYER_CheckFormModel();

int INTRUDE_FIELD_EventExitConfirm(int a0, int *state, Obj *o)
{
    int w;
    int g;
    int h;
    int t;
    int r;
    int ctx;
    int i;
    u8 v[12];
    V12 *pv;

    w = (int)GAME_EVENT_GetGameSystem((struct Obj *)a0);
    g = (int)GAMESYSTEM_GetFieldMap((const struct Ctx *)w);
    h = GAMESYSTEM_GetGameComm((const struct Ctx *)w);
    switch (*state) {
    case 0:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys((u8 *)g));
        t = FIELDMAP_GetMsgBg((u8 *)g);
        o->f0 = FIELD_MSGBG_CreateMsgData(t, 0x2D);
        o->f8 = FIELD_MSGBG_CreateBottomSysWin(t, o->f0);
        FIELD_MSGBG_SysWinPrintMsg(o->f8, 0, 0, 0x54);
        *state += 1;
        break;
    case 1:
        if (FIELD_MSGBG_SysWinMain(o->f8) == 1) {
            o->fc = FIELD_MSGBG_CreateYesNoMenu(FIELDMAP_GetMsgBg((u8 *)g), 0);
            *state += 1;
        }
        break;
    case 2:
        r = FIELD_MSGBG_YesNoMenuMain(o->fc);
        if (r != 2) {
            FIELD_MSGBG_DeleteMenuFunc(o->fc);
            FIELD_MSGBG_DeleteSysWin(o->f8);
            o->fc = 0;
            o->f8 = 0;
            if (r == 0)
                *state = 3;
            else
                *state = 11;
        }
        break;
    case 3:
        if (func_0200FB24() == 0 && GAME_COMM_GetKind((void *)h) == 2) {
            GAME_COMM_RequestExitNoCallback((struct Comm *)h);
            o->f4 = FIELD_MSGBG_CreateBottomMsgWin(FIELDMAP_GetMsgBg((u8 *)g), o->f0);
            FIELD_MSGBG_MsgWinPrintMsg(o->f4, 0, 0, 0x14);
        }
        *state += 1;
        break;
    case 4:
        if (o->f4 == 0 || FIELD_MSGBG_IsMsgWinTransDone((u8 *)o->f4) == 1)
            *state += 1;
        break;
    case 5:
        o->f28++;
        if (o->f4 != 0 && o->f28 <= 0x3C)
            break;
        if (GAME_COMM_GetKind((void *)h) == 2)
            break;
        ctx = (int)GAMESYSTEM_GetGameData((const struct Ctx *)w);
        pv = (V12 *)v;
        pv->x = 0;
        pv->y = 0;
        pv->z = 0;
        for (i = 0; i < 3; i++)
            GAME_DATA_SetPlayerPosition((struct Rec44 *)GAME_DATA_GetPlayerWork((u8 *)ctx, i), (const struct Vec12 *)pv);
        *state += 1;
        break;
    case 6:
        if (o->f4 != 0)
            FIELD_MSGBG_DeleteMsgWin((void *)o->f4);
        MSGDATA_Delete((struct Rec *)o->f0);
        *state += 1;
        break;
    case 7:
        g = (int)GAMESYSTEM_GetFieldMap((const struct Ctx *)w);
        if (FIELDMAP_IsReady(g) != 1)
            break;
        if (FIELD_PLAYER_CheckFormModel(FIELDMAP_GetFieldPlayer(g)) == 0) {
            INTRUDE_FIELD_InitPlayerSpin(o->f10, w, g, 0, 0, 0);
            *state += 1;
        } else {
            *state = 9;
        }
        break;
    case 8:
        if (INTRUDE_FIELD_StepPlayerSpin(o->f10, 0) == 1)
            *state += 1;
        break;
    case 9:
        GAME_EVENT_CallEvent((struct Evt *)a0, (struct Evt **)EVENT_MAPCHANGE_CreateIntrudeReturnEvent(w));
        *state += 1;
        break;
    case 10:
        *state = 14;
        break;
    case 11:
        MSGDATA_Delete((struct Rec *)o->f0);
        *state = 12;
        break;
    case 12:
        t = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(g));
        if (FLDMMDL_CheckPossibleAcmd(t) == 1) {
            FLDMMDL_SetAcmd((void *)t, 8);
            *state += 1;
        }
        break;
    case 13:
        if (FLDMMDL_EndAcmd((char *)FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(g))) == 1)
            *state = 14;
        break;
    case 14:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys((u8 *)g));
        return 1;
    }
    return 0;
}
