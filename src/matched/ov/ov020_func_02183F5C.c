/*
 * function: EVENT_MAPCHANGE_CreateContinueEvent
 * address:  0x02183F5C
 * packet:   pkt_ov020_02183F5C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   ZONEDATA_ResetEventFlag  0x0201433C  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02008B08  0x02008B08  thumb
 *   POKEPARTY_GetSaveData  0x0201AD0C  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   func_02008B4C  0x02008B4C  thumb
 *   func_02008B78  0x02008B78  thumb
 *   func_02008B14  0x02008B14  thumb
 *   func_02008C00  0x02008C00  thumb
 *   FORMCHANGE_RevertShayminAndRegister  0x0216A390  thumb  ov010
 *   GF_STANDARD_GetRtcTimestamp  0x0203F524  arm
 *   BEACON_SetLastTime  0x0200C384  thumb
 *   func_02008B20  0x02008B20  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   FORMCHANGE_UpdateSeasonForms  0x0216AAE4  thumb  ov010
 *   EVENT_MAPCHANGE_RefreshUnionInfo  0x02183DD4  thumb  ov020
 *   EVENT_MAPCHANGE_ContinueEvent  0x02183DE4  thumb  ov020
 *   PALANM_StartTimer  0x02021444  thumb
 *   func_0208068C  0x0208068C  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   GX_DisableBankForLCDC  0x02080B98  arm
 */
#include "../include/Obj02684.h"
#include "../include/Obj19450.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;

typedef signed int     s32;
struct Big;
struct BigObj;
struct Blk34;
struct Ctx;
struct Desc;
struct Obj;
struct Sub02008AECObj;
struct Sub02008AECSession;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
extern void ZONEDATA_ResetEventFlag(char *a0, int a1);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008AECObj *func_02008B08(void *sys);
extern void *POKEPARTY_GetSaveData(void *sys);
extern void *GAME_DATA_GetMiscSave(int *p);
extern int func_02008B4C(const struct Sub02008AECObj *obj);
extern int func_02008B78(const struct Sub02008AECObj *obj);
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern void func_02008C00(struct Sub02008AECSession *s);
extern void FORMCHANGE_RevertShayminAndRegister(int a, int b);
extern u64 GF_STANDARD_GetRtcTimestamp();
extern void BEACON_SetLastTime(struct Blk34 *p, u32 lo, u32 hi);
extern void func_02008B20(struct Sub02008AECObj *obj);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern void FORMCHANGE_UpdateSeasonForms(void *sys, void *party, int season);
extern void EVENT_MAPCHANGE_RefreshUnionInfo(void *p);
extern int EVENT_MAPCHANGE_ContinueEvent(int ctx, int *state, u8 *p);
extern void PALANM_StartTimer(void);
extern void func_0208068C(int a);
extern void MIi_CpuClearFast(int v, int dst, int size);
extern void GX_DisableBankForLCDC(void);

int EVENT_MAPCHANGE_CreateContinueEvent(int a0, u8 *a1)
{
    int t0;
    int *s;
    int r5;
    int r7;
    int r6;
    int h;
    u64 t;

    t0 = (int)func_020122C0((void *)a0, 0, (void *)((int)EVENT_MAPCHANGE_ContinueEvent), 0x10);
    s = func_020124E8((struct Obj *)t0);
    s[0] = a0;
    s[1] = (int)GAMESYSTEM_GetGameData((const struct Ctx *)a0);
    ((struct Obj02684 *)s)->f8 = ((struct Obj19450 *)a1)->f10;
    r5 = GAME_DATA_GetEventWork((const struct BigObj *)s[1]);
    s[3] = ZONEDATA_CheckEventFlag((void *)r5, 0x966);
    ZONEDATA_ResetEventFlag((char *)r5, 0x966);
    r7 = (int)GAME_DATA_GetSaveControl((struct Big *)s[1]);
    r5 = (int)func_02008B08((void *)r7);
    r6 = (int)POKEPARTY_GetSaveData((void *)r7);
    h = (int)GAME_DATA_GetMiscSave((int *)s[1]);
    if (!func_02008B4C((const struct Sub02008AECObj *)r5) || !func_02008B78((const struct Sub02008AECObj *)r5)) {
        func_02008C00(func_02008B14((void *)r7));
        FORMCHANGE_RevertShayminAndRegister(s[1], r6);
        t = GF_STANDARD_GetRtcTimestamp();
        BEACON_SetLastTime((struct Blk34 *)h, (u32)t, (u32)(t >> 32));
    }
    func_02008B20((struct Sub02008AECObj *)r5);
    FORMCHANGE_UpdateSeasonForms((void *)s[1], (void *)r6, GAME_DATA_GetSeason((const struct BigObj *)s[1]));
    EVENT_MAPCHANGE_RefreshUnionInfo((void *)a0);
    PALANM_StartTimer();
    func_0208068C(0x1FF);
    MIi_CpuClearFast(0, 0x06800000, 0xA4000);
    GX_DisableBankForLCDC();
    return t0;
}
