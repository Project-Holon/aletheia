/*
 * function: INTRUDE_FIELD_EventNotice
 * address:  0x0217B82C
 * packet:   pkt_ov018_0217B82C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   FIELD_MSGBG_CreateBottomSysWin  0x02190F64  thumb  ov021
 *   FIELD_MSGBG_SysWinPrintMsg  0x02190E74  thumb  ov021
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb  ov021
 *   FIELD_MSGBG_DeleteSysWin  0x02190E40  thumb  ov021
 *   MSGDATA_Delete  0x02045C04  arm
 *   FIELDMAP_IsReady  0x02188BE8  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_CheckFormModel  0x021A3238  thumb  ov021
 *   INTRUDE_FIELD_InitPlayerSpin  0x0217C658  thumb  ov018
 *   INTRUDE_FIELD_StepPlayerSpin  0x0217C688  thumb  ov018
 *   EVENT_MAPCHANGE_CreateIntrudeReturnEvent  0x02185214  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 */

typedef unsigned char u8;

typedef struct {
    int f0;
    int f4;
    u8 f8[1];
} Work;

struct Evt;
struct Obj;
struct Rec;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
typedef unsigned int   u32;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern void FLDMMDL_SysPauseMove(void *);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern int FIELD_MSGBG_CreateMsgData(u32 a, u32 b);
struct Fx;
struct Obj2;
extern struct Obj2 *FIELD_MSGBG_CreateBottomSysWin(struct Fx *a, u32 b);
extern void FIELD_MSGBG_SysWinPrintMsg(u32 *p, u32 b, u32 c, u32 d);
extern u32 FIELD_MSGBG_SysWinMain(u32 *p);
extern int FIELD_MSGBG_DeleteSysWin(u32 a);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern int FIELDMAP_IsReady(void *);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern int FIELD_PLAYER_CheckFormModel(u8 *p);
extern void INTRUDE_FIELD_InitPlayerSpin(void *, int, void *, int, int, int);
extern int INTRUDE_FIELD_StepPlayerSpin(void *, int);
extern int EVENT_MAPCHANGE_CreateIntrudeReturnEvent(int);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern u32 *FLDMMDL_SysResumeMove(void *c);

int INTRUDE_FIELD_EventNotice(int a0, int *state, Work *w)
{
    int sys;
    void *obj;
    int hnd;

    sys = (int)GAME_EVENT_GetGameSystem((struct Obj *)a0);
    obj = GAMESYSTEM_GetFieldMap((void *)sys);
    GAMESYSTEM_GetGameComm((const struct Ctx *)sys);
    switch (*state) {
    case 0:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(obj));
        hnd = FIELDMAP_GetMsgBg(obj);
        w->f0 = FIELD_MSGBG_CreateMsgData(hnd, 0x2D);
        w->f4 = (int)FIELD_MSGBG_CreateBottomSysWin((struct Fx *)hnd, w->f0);
        FIELD_MSGBG_SysWinPrintMsg((u32 *)w->f4, 0, 0, 0x60);
        (*state)++;
        break;
    case 1:
        if (FIELD_MSGBG_SysWinMain((u32 *)w->f4) == 1) {
            FIELD_MSGBG_DeleteSysWin(w->f4);
            MSGDATA_Delete((struct Rec *)w->f0);
            (*state)++;
        }
        break;
    case 2:
        obj = GAMESYSTEM_GetFieldMap((void *)sys);
        if (FIELDMAP_IsReady(obj) == 1) {
            if (FIELD_PLAYER_CheckFormModel(FIELDMAP_GetFieldPlayer((void *)obj)) == 0) {
                INTRUDE_FIELD_InitPlayerSpin(w->f8, sys, obj, 0, 0, 0);
                (*state)++;
            } else {
                *state = 4;
            }
        }
        break;
    case 3:
        if (INTRUDE_FIELD_StepPlayerSpin(w->f8, 0) == 1)
            (*state)++;
        break;
    case 4:
        GAME_EVENT_CallEvent((struct Evt *)a0, (struct Evt **)EVENT_MAPCHANGE_CreateIntrudeReturnEvent(sys));
        (*state)++;
        break;
    case 5:
        if (obj != 0 && FIELDMAP_IsReady(obj) == 1) {
            FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys((void *)obj));
            return 1;
        }
        break;
    }
    return 0;
}
