/*
 * function: INTRUDE_FIELD_EventOfferInfo
 * address:  0x0217C4D0
 * packet:   pkt_ov018_0217C4D0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback registered by INTRUDE_FIELD_CreateOfferInfoEvent (0x88-byte work, state word
 * in the second argument).
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   EVENT_COMM_COMMON_SetupListWindowB  0x0217F528  thumb  ov018
 *   INTRUDE_COMM_SetWordSetRequest  0x021762D8  thumb  ov011
 *   EVENT_COMM_COMMON_PrintListWindowB  0x0217F574  thumb  ov018
 *   FIELD_SOUND_SYSTEM_StartPushAndPlayTask  0x02029830  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb
 *   FIELD_SOUND_SYSTEM_StartPopAndWaitTask  0x02029620  thumb
 *   EVENT_COMM_COMMON_DeleteListWindowB  0x0217F58C  thumb  ov018
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   INTRUDE_FIELD_InitPlayerSpin  0x0217C658  thumb  ov018
 *   INTRUDE_FIELD_StepPlayerSpin  0x0217C688  thumb  ov018
 *   INTRUDE_CMD_SendRecordAccept  0x02173FC0  thumb  ov011
 *   INTRUDE_COMM_IsSessionTimeLimitSet  0x02175A24  thumb  ov011
 *   EVENT_COMM_COMMON_ExitMsgBox  0x0217F318  thumb  ov018
 *   INTRUDE_COMM_SetState  0x02174E14  thumb  ov011
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct {
    void *f0;
    int f4;
    s16 f8;
    s16 fA;
    u16 fC;
    u8 fE;
    u8 fF;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    int f14;
} Rec;

typedef struct {
    u32 lo : 4;
    u32 mid : 14;
    u32 hi : 11;
    u32 top : 3;
} Bits;

typedef struct {
    u8 mask : 3;
    u8 rest : 5;
} Mask;

typedef struct {
    int f00;
    Bits f04;
    Mask f08;
    u8 pad09;
    u16 f0A[3];
    u8 f10[8];
    u8 f18[0x1C];
} Info;

typedef struct {
    u16 f00;
    int f04;
    u8 f08[0x30];
    Info f38;
    Rec f6C;
    u8 f84;
} Work;

struct Ctx;
struct Evt;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern void EVENT_COMM_COMMON_SetupListWindowB(void *, void *, int, int, int, int);
extern void INTRUDE_COMM_SetWordSetRequest(Info *, void *, int, u16);
struct BigObj;
extern void EVENT_COMM_COMMON_PrintListWindowB(void **p, unsigned int index, int a, int b);
extern void *FIELD_SOUND_SYSTEM_StartPushAndPlayTask(void *a, u32 b);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int GFL_USE_IsBgmPlaying(void);
extern void *FIELD_SOUND_SYSTEM_StartPopAndWaitTask(void *a, u32 b, u32 c);
extern void EVENT_COMM_COMMON_DeleteListWindowB(void *);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 GAME_DATA_GetOwnNetId(const struct BigObj *p);
extern void INTRUDE_FIELD_InitPlayerSpin(Rec *, void *, int, u16, u8, u8);
extern int INTRUDE_FIELD_StepPlayerSpin(Rec *, void *);
extern int INTRUDE_CMD_SendRecordAccept(int a, u8 *b);
extern int INTRUDE_COMM_IsSessionTimeLimitSet(u8 *);
extern void EVENT_COMM_COMMON_ExitMsgBox(void *);
extern void INTRUDE_COMM_SetState(u8 *, int);

int INTRUDE_FIELD_EventOfferInfo(void *task, int *state, Work *w)
{
    void *sys;
    u8 *peer;
    u16 hi;
    u8 t;

    sys = GAME_EVENT_GetGameSystem(task);
    peer = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)((void *)GAMESYSTEM_GetGameComm(sys)));
    if (peer == 0 && *state == 0)
        *state = 8;

    switch (*state) {
    case 0:
        if (w->f84 == 0) {
            *state = 4;
            break;
        }
        EVENT_COMM_COMMON_SetupListWindowB(w->f08, sys, 1, 1, 0x1E, 0x10);
        INTRUDE_COMM_SetWordSetRequest(&w->f38, w->f38.f18, *(int *)w->f08, w->f00);
        hi = w->f38.f04.hi;
        EVENT_COMM_COMMON_PrintListWindowB((void **)w->f08, (u16)w->f38.f04.lo, 8, 0);
        EVENT_COMM_COMMON_PrintListWindowB((void **)w->f08, (u16)hi, 8, 0x10);
        (*state)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(task, FIELD_SOUND_SYSTEM_StartPushAndPlayTask(sys, 0x52B));
        (*state)++;
        break;
    case 2:
        if (GFL_USE_IsBgmPlaying() == 0) {
            GAME_EVENT_CallEvent(task, FIELD_SOUND_SYSTEM_StartPopAndWaitTask(sys, 0, 6));
            (*state)++;
        }
        break;
    case 3:
        EVENT_COMM_COMMON_DeleteListWindowB(w->f08);
        (*state)++;
        break;
    case 4:
        t = (int)GAME_DATA_GetOwnNetId(GAMESYSTEM_GetGameData(sys));
        INTRUDE_FIELD_InitPlayerSpin(&w->f6C, sys, w->f04, w->f38.f0A[t], w->f38.f10[t],
                      w->f38.f08.mask & (1 << t));
        (*state)++;
        break;
    case 5:
        if (INTRUDE_FIELD_StepPlayerSpin(&w->f6C, peer) == 1)
            (*state)++;
        break;
    case 6:
        if (peer != 0) {
            if (INTRUDE_CMD_SendRecordAccept((int)peer, peer + 0x1AC) == 1)
                (*state)++;
        } else {
            (*state)++;
        }
        break;
    case 7:
        if (peer != 0) {
            if (INTRUDE_COMM_IsSessionTimeLimitSet(peer + 0x1AC) == 1)
                (*state)++;
        } else {
            (*state)++;
        }
        break;
    case 8:
        EVENT_COMM_COMMON_ExitMsgBox(w->f08);
        if (peer != 0)
            INTRUDE_COMM_SetState(peer, 0);
        return 1;
    }
    return 0;
}
