/*
 * function: INTRUDE_SUBDISP_DisconnectEventMain
 * address:  0x0217CAFC
 * packet:   pkt_ov018_0217CAFC
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_SUBDISP_CreateReturnPalaceEvent  0x0217CA40  thumb  ov018
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02026460  0x02026460  thumb
 *   func_02026454  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAMESYSTEM_IsFieldMapExist  0x02012114  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_IsReady  0x02188BE8  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   FIELD_MSGBG_CreateBottomSysWin  0x02190F64  thumb  ov021
 *   func_0202648C  0x0202648C  thumb
 *   FIELD_MSGBG_SysWinPrintMsg  0x02190E74  thumb  ov021
 *   FIELD_SOUND_SYSTEM_StartPushAndPlayTask  0x02029830  thumb
 *   func_02005F38  0x02005F38  thumb
 *   FIELD_SOUND_SYSTEM_StartPopAndWaitTask  0x02029620  thumb
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   FIELD_MSGBG_DeleteSysWin  0x02190E40  thumb  ov021
 *   MSGDATA_Delete  0x02045C04  arm
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_CheckFormModel  0x021A3238  thumb  ov021
 *   INTRUDE_FIELD_InitPlayerSpin  0x0217C658  thumb  ov018
 *   INTRUDE_FIELD_StepPlayerSpin  0x0217C688  thumb  ov018
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   GAMESYSTEM_IsNetOffBySleep  0x02012204  thumb
 *   GAMESYSTEM_GetFieldMapState  0x0201212C  thumb
 *   EVENT_COMM_ERROR_Create  0x021C06CC  thumb  ov021
 *   func_02026484  0x02026484  thumb
 *   GAME_COMM_ClearPlayerStatus  0x020264F4  thumb
 *   EVENT_MAPCHANGE_CreateIntrudeReturnEvent  0x02185214  thumb  ov020
 */

typedef unsigned short u16;
typedef unsigned int u32;

/* 0x28-byte task work, allocated by INTRUDE_SUBDISP_CreateDisconnectEvent through func_020122C0 */
typedef struct {
    void *f00;
    void *f04;
    unsigned char f08[0x18];
    int f20;
    int f24;
} Ov018Work;

struct Ctx;
typedef signed int     s32;
struct Comm;
struct Obj;
struct Rec;
void *func_020124E4(struct Obj *p);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
void *INTRUDE_SUBDISP_CreateReturnPalaceEvent(int a0);
typedef unsigned char  u8;
struct BigObj;
struct Evt;
void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
u32 func_0200FB24(void);
u32 func_02026460(void *obj);
u32 func_02026454(void *obj);
void GAME_COMM_RequestExitNoCallback(struct Comm *p);
u32 GAMESYSTEM_IsFieldMapExist(const struct Ctx *p);
void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
int FIELDMAP_IsReady(void *);
u32 FIELDMAP_GetMsgBg(u8 *p);
int FIELD_MSGBG_CreateMsgData(u32 a, u32 b);
struct Fx;
struct Obj2;
struct Obj2 *FIELD_MSGBG_CreateBottomSysWin(struct Fx *a, u32 b);
u32 func_0202648C(void *obj);
void FIELD_MSGBG_SysWinPrintMsg(u32 *p, u32 b, u32 c, u32 d);
void *FIELD_SOUND_SYSTEM_StartPushAndPlayTask(void *a, u32 b);
int func_02005F38(void);
void *FIELD_SOUND_SYSTEM_StartPopAndWaitTask(void *a, u32 b, u32 c);
u32 FIELD_MSGBG_SysWinMain(u32 *p);
u32 func_020362DC(void);
int FIELD_MSGBG_DeleteSysWin(u32 a);
u32 MSGDATA_Delete(struct Rec *rec);
struct Obj00020;
void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
int FIELD_PLAYER_CheckFormModel(u8 *p);
void INTRUDE_FIELD_InitPlayerSpin(void *, void *, void *, int, int, int);
int INTRUDE_FIELD_StepPlayerSpin(void *, int);
u32 GAME_DATA_GetEventWork(const struct BigObj *p);
u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
int SCRIPT_SYS_CallScriptEvent(void *p, u16 b, int c, int d, u16 e);
u8 GAME_DATA_GetExitMode(const struct BigObj *p);
u32 GAMESYSTEM_IsNetOffBySleep(const struct Ctx *p);
u8 GAMESYSTEM_GetFieldMapState(const struct Ctx *p);
int EVENT_COMM_ERROR_Create(void *, void *);
void func_02026484(void *);
void GAME_COMM_ClearPlayerStatus(u8 *p);
void *EVENT_MAPCHANGE_CreateIntrudeReturnEvent(void *a);

int INTRUDE_SUBDISP_DisconnectEventMain(void *a, int *seq, Ov018Work *work)
{
    void *x;
    void *s2;
    void *s1;
    void *y;
    void *z;
    void *t;
    int flag;
    int msg;
    int v;
    int r;

    x = func_020124E4(a);
    s2 = GAMESYSTEM_GetGameData(x);
    s1 = (void *)GAMESYSTEM_GetGameComm(x);
    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(a, (struct Evt **)INTRUDE_SUBDISP_CreateReturnPalaceEvent((int)x));
        (*seq)++;
        break;
    case 1:
        if (func_0200FB24() == 0 && (int)func_02026460(s1) != 0) {
            break;
        }
        if (func_0200FB24() == 0 && ((int)func_02026454(s1) == 2 || (int)func_02026454(s1) == 1)) {
            GAME_COMM_RequestExitNoCallback(s1);
        }
        (*seq)++;
        break;
    case 2:
        if (func_0200FB24() == 0 && (int)func_02026454(s1) != 0) {
            break;
        }
        if (work->f24 == 1) {
            *seq = 7;
        } else {
            (*seq)++;
        }
        break;
    case 3:
        if (GAMESYSTEM_IsFieldMapExist(x) != 1) {
            break;
        }
        flag = 0;
        y = GAMESYSTEM_GetFieldMap(x);
        if (FIELDMAP_IsReady(y) != 1) {
            break;
        }
        z = (void *)FIELDMAP_GetMsgBg(y);
        work->f00 = t = (void *)FIELD_MSGBG_CreateMsgData((u32)z, 0x2D);
        work->f04 = FIELD_MSGBG_CreateBottomSysWin(z, (u32)t);
        switch (work->f20) {
        case 1:
        case 2:
            msg = 0x5C;
            goto set;
        default:
            msg = 0x59;
        set:
            flag = 1;
            break;
        case 0:
            switch ((int)func_0202648C(s1)) {
            case 1:
                msg = 0x5A;
                break;
            case 2:
                msg = 0x56;
                break;
            case 3:
                msg = 0x57;
                flag = 1;
                break;
            case 4:
                msg = 0x58;
                flag = 1;
                break;
            case 0:
            case 5:
            default:
                msg = 0x59;
                break;
            }
            break;
        }
        FIELD_MSGBG_SysWinPrintMsg(work->f04, (int)0, (int)0, (int)msg);
        if (flag == 1) {
            GAME_EVENT_CallEvent(a, FIELD_SOUND_SYSTEM_StartPushAndPlayTask(x, 0x52D));
            *seq = 4;
        } else {
            *seq = 5;
        }
        break;
    case 4:
        if (func_02005F38() == 0) {
            GAME_EVENT_CallEvent(a, FIELD_SOUND_SYSTEM_StartPopAndWaitTask(x, 0, 6));
            *seq = 5;
        }
        break;
    case 5:
        if ((int)FIELD_MSGBG_SysWinMain(work->f04) == 1) {
            (*seq)++;
        }
        break;
    case 6:
        if (func_020362DC() & 0xF3) {
            FIELD_MSGBG_DeleteSysWin((u32)work->f04);
            MSGDATA_Delete(work->f00);
            (*seq)++;
        }
        break;
    case 7:
        y = GAMESYSTEM_GetFieldMap(x);
        if (FIELDMAP_IsReady(y) == 1) {
            if (FIELD_PLAYER_CheckFormModel(FIELDMAP_GetFieldPlayer(y)) == 0) {
                INTRUDE_FIELD_InitPlayerSpin(work->f08, x, y, 0, 0, 0);
                (*seq)++;
            } else {
                *seq = 10;
            }
        }
        break;
    case 8:
        if (INTRUDE_FIELD_StepPlayerSpin(work->f08, 0) == 1) {
            if (work->f24 == 1) {
                *seq = 10;
            } else {
                (*seq)++;
            }
        }
        break;
    case 9:
        if ((int)ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(s2), 0x980) == 0) {
            r = (int)func_0202648C(s1);
            v = 0;
            switch (r) {
            case 0:
            case 1:
                break;
            case 2:
                v = 0xC;
                break;
            case 3:
            case 4:
                v = 0xD;
                break;
            case 5:
                break;
            }
            SCRIPT_SYS_CallScriptEvent(a, (u16)v, 0, 0, (int)0x8015);
        }
        *seq = 10;
        break;
    case 10:
        if ((GAME_DATA_GetExitMode(s2) != 0 || (int)GAMESYSTEM_IsNetOffBySleep(x) == 1) && GAMESYSTEM_GetFieldMapState(x) == 1) {
            GAME_EVENT_CallEvent(a, (struct Evt **)EVENT_COMM_ERROR_Create(x, GAMESYSTEM_GetFieldMap(x)));
        }
        (*seq)++;
        break;
    case 11:
        func_02026484(s1);
        GAME_COMM_ClearPlayerStatus(s1);
        if (GAME_DATA_GetExitMode(s2) != 0 || (int)GAMESYSTEM_IsNetOffBySleep(x) == 1) {
            GAME_EVENT_CallEvent(a, EVENT_MAPCHANGE_CreateIntrudeReturnEvent(x));
        }
        (*seq)++;
        break;
    case 12:
        return 1;
    }
    return 0;
}
