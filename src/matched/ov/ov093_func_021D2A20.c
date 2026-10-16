/*
 * function: BTL_CLIENT_StepGiveExp
 * address: 0x021D2A20
 * packet: pkt_ov093_021D2A20
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: 43/43 relocations resolved after parent-coordinated overlay
 * leaf witnesses; all ARM9 calls resolve without new ARM9 files.
 * lever: int id loaded via (u8) cast fixes spill slots; widening the
 * BTL_MAIN_GetViewPosOfPoke third extern parameter removes absent call truncation.
 * StateData fields keep counter updates on one global base.
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_MAIN_GetViewPosOfPoke 0x021B8DC0 thumb ov093
 *   BTLV_EFFECT_GaugeIsSlotOccupied 0x021F8204 thumb ov094
 *   BTL_POKEPARAM_AddExp 0x021D69B8 thumb ov093
 *   BTLV_EFFECT_GaugeStartExpGain 0x021F8134 thumb ov094
 *   BTLV_EFFECT_GaugeIsAnimating 0x021F8180 thumb ov094
 *   BTL_EVENT_ReleaseClientHandle 0x021D6EA0 thumb ov093
 *   BTL_POKEPARAM_ReloadFromParam 0x021D6BFC thumb ov093
 *   BTLV_EFFECT_GaugeRefreshForLevelUp 0x021F8150 thumb ov094
 *   GFL_USE_IsAnySeBusy 0x02006238 thumb
 *   BTLV_CORE_StartViewEffect 0x021EA3B8 thumb ov093
 *   BTLV_CORE_WaitViewEffect 0x021EA3D4 thumb ov093
 *   BTLV_SCU_InitMessage 0x021EAF18 thumb ov093
 *   BTLV_SCU_AppendMessageArg 0x021EAF50 thumb ov093
 *   BTLV_CORE_BuildAndPrintMessage 0x021EA614 thumb ov093
 *   BTLV_CORE_ConsumeMessageFlag 0x021EA720 thumb ov093
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   BTLV_CORE_WaitMessage 0x021EA710 thumb ov093
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   BTL_MAIN_NotifyLevelUp 0x021BA238 thumb ov093
 *   BTLV_CORE_StartBallWindowOpen 0x021EADA4 thumb ov093
 *   BTLV_CORE_UpdateBallWindowOpen 0x021EADB4 thumb ov093
 *   BTLV_CORE_StartBallWindowRefresh 0x021EADC4 thumb ov093
 *   BTLV_CORE_UpdateBallWindowRefresh 0x021EADD4 thumb ov093
 *   BTLV_CORE_StartBallWindowClose 0x021EADE4 thumb ov093
 *   BTLV_CORE_UpdateBallWindowClose 0x021EADF4 thumb ov093
 *   BTL_CLIENT_StepLearnLevelUpMoves 0x021D2CA8 thumb ov093
 *   BTL_MAIN_CopyLiveToSnapshotPoke 0x021B9358 thumb ov093
 *   gExpGainWork 0x021F3B64 data a4
 */
#include "../include/Obj00268.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 data[0x24]; } MsgParam;
typedef struct {
    void *battle;
    void *party;
    u8 unk008[0x4c];
    void *msgWin;
    MsgParam msg;
    u8 unk07C[0x11e];
    u16 level;
    u8 unk19C[0xa];
    u8 side;
} LearnSeq;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern unsigned char BTL_MAIN_GetViewPosOfPoke(unsigned char *p, void *a, unsigned int b);
extern int BTLV_EFFECT_GaugeIsSlotOccupied(int);
struct H;
struct L;
struct Obj;
struct Result;
extern int BTL_POKEPARAM_AddExp(struct Obj *p, u32 *remaining, struct Result *r);
extern void BTLV_EFFECT_GaugeStartExpGain(int, u32);
extern int BTLV_EFFECT_GaugeIsAnimating(void);
extern void BTL_EVENT_ReleaseClientHandle(void *);
extern void BTL_POKEPARAM_ReloadFromParam(u8 *p);
extern void BTLV_EFFECT_GaugeRefreshForLevelUp(int, void *);
extern int GFL_USE_IsAnySeBusy(void);
extern void BTLV_CORE_StartViewEffect(char *ctx, int a, int b);
extern int BTLV_CORE_WaitViewEffect(void *);
struct L;
extern void BTLV_SCU_InitMessage(struct L *p, int kind, int id);
extern void BTLV_SCU_AppendMessageArg(struct L *p, u32 val);
extern void BTLV_CORE_BuildAndPrintMessage(char *p, struct H *h);
extern int BTLV_CORE_ConsumeMessageFlag(u32 *p);
extern void GFL_USE_SetBgmPlayerParam(void *);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u32);
extern int BTLV_CORE_WaitMessage(u32 *p);
extern int GFL_USE_IsBgmPlaying(void);
extern int GFL_USE_PopBgm(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void BTL_MAIN_NotifyLevelUp(char *p, void *m);
struct T;
extern void BTLV_CORE_StartBallWindowOpen(u8 *, int, struct T *);
extern int BTLV_CORE_UpdateBallWindowOpen(u8 *);
extern void BTLV_CORE_StartBallWindowRefresh(u8 *);
extern int BTLV_CORE_UpdateBallWindowRefresh(u8 *);
extern void BTLV_CORE_StartBallWindowClose(u8 *);
extern int BTLV_CORE_UpdateBallWindowClose(u8 *);
extern int BTL_CLIENT_StepLearnLevelUpMoves(LearnSeq *, int *, void *);
extern void BTL_MAIN_CopyLiveToSnapshotPoke(char *p, int i);
struct StateData { u8 pad0[8]; int counter; u32 remaining; u32 pad10; u8 result[14]; };
extern struct StateData gExpGainWork;
int BTL_CLIENT_StepGiveExp(u8 *p, int *state, u32 *args)
{
    void *obj;
    int id;
    int index;
    int enabled;
    u32 remaining;
    id = (u8)args[0];
    obj = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00268 *)p)->f4, id);
    index = BTL_MAIN_GetViewPosOfPoke(((struct Obj00268 *)p)->f0, ((struct Obj00268 *)p)->f4, id);
    enabled = 0;
    if (index != 0xff && BTLV_EFFECT_GaugeIsSlotOccupied(index)) enabled = 1;
    switch (*state) {
    case 0:
        gExpGainWork.remaining = args[1];
        gExpGainWork.counter = 0;
        *state = 1;
    case 1:
        if (gExpGainWork.remaining) {
            remaining = gExpGainWork.remaining;
            if (BTL_POKEPARAM_AddExp(obj, &remaining, (struct Result *)gExpGainWork.result)) {
                *state = 3;
            } else {
                if (enabled) {
                    BTLV_EFFECT_GaugeStartExpGain(index, gExpGainWork.remaining);
                    *state = 2;
                } else *state = 13;
                remaining = 0;
            }
            gExpGainWork.remaining = remaining;
        } else *state = 13;
        break;
    case 2:
        if (!BTLV_EFFECT_GaugeIsAnimating()) *state = 13;
        break;
    case 3:
        BTL_EVENT_ReleaseClientHandle(obj);
        BTL_POKEPARAM_ReloadFromParam(obj);
        if (enabled) {
            BTLV_EFFECT_GaugeRefreshForLevelUp(index, obj);
            *state = 4;
        } else *state = 6;
        break;
    case 4:
        if (!BTLV_EFFECT_GaugeIsAnimating() && !GFL_USE_IsAnySeBusy()) {
            BTLV_CORE_StartViewEffect(((struct Obj00268 *)p)->f54, index, 0x25d);
            *state = 5;
        }
        break;
    case 5:
        if (BTLV_CORE_WaitViewEffect(((struct Obj00268 *)p)->f54)) *state = 6;
        break;
    case 6:
        BTLV_SCU_InitMessage((struct L *)(p + 0x58), 1, 0x3c);
        BTLV_SCU_AppendMessageArg((struct L *)(p + 0x58), (int)id);
        BTLV_SCU_AppendMessageArg((struct L *)(p + 0x58), (int)gExpGainWork.result[0]);
        BTLV_CORE_BuildAndPrintMessage(((struct Obj00268 *)p)->f54, (struct H *)(p + 0x58));
        *state = 7;
        break;
    case 7:
        if (BTLV_CORE_ConsumeMessageFlag(((struct Obj00268 *)p)->f54)) {
            GFL_USE_SetBgmPlayerParam((void *)1);
            GFL_USE_PushBgm();
            GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
        }
        if (BTLV_CORE_WaitMessage(((struct Obj00268 *)p)->f54) && !GFL_USE_IsBgmPlaying()) {
            GFL_USE_PopBgm();
            GFL_USE_SetBgmPlayerParam(0);
            gExpGainWork.counter = 0;
            *state = 8;
        }
        break;
    case 8:
        gExpGainWork.counter++;
        if ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg() || gExpGainWork.counter > 80) {
            gExpGainWork.counter = 0;
            BTL_MAIN_NotifyLevelUp(((struct Obj00268 *)p)->f0, obj);
            BTLV_CORE_StartBallWindowOpen(*(u8 * *)&((struct Obj00268 *)p)->f54, (int)obj, (struct T *)gExpGainWork.result);
            *state = 9;
        }
        break;
    case 9:
        if (BTLV_CORE_UpdateBallWindowOpen(((struct Obj00268 *)p)->f54) && ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg())) {
            BTLV_CORE_StartBallWindowRefresh(((struct Obj00268 *)p)->f54);
            *state = 10;
        }
        break;
    case 10:
        if (BTLV_CORE_UpdateBallWindowRefresh(((struct Obj00268 *)p)->f54) && ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg())) {
            BTLV_CORE_StartBallWindowClose(((struct Obj00268 *)p)->f54);
            *state = 11;
        }
        break;
    case 11:
        if (BTLV_CORE_UpdateBallWindowClose(((struct Obj00268 *)p)->f54)) {
            gExpGainWork.counter = 0;
            *state = 12;
        }
        break;
    case 12:
        if (BTL_CLIENT_StepLearnLevelUpMoves((LearnSeq *)p, &gExpGainWork.counter, obj)) *state = 1;
        break;
    case 13:
        BTL_MAIN_CopyLiveToSnapshotPoke(((struct Obj00268 *)p)->f0, id);
        return 1;
    }
    return 0;
}
