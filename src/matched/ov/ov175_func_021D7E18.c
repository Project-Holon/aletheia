/*
 * function: WIFIBATTLEMATCH_NET_CompStepF
 * address:  0x021D7E18
 * packet:   pkt_021D7E18
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   DWC_CloseAllConnectionsHard  0x0216B65C  arm  ov009
 *   WIFIBATTLEMATCH_UTIL_PrintMessage  0x021E8738  thumb  ov177
 *   WIFIBATTLEMATCH_UTIL_SetCallback  0x021E8AA0  thumb  ov177
 *   WIFIBATTLEMATCH_UTIL_ClearCallback  0x021E8AA8  thumb  ov177
 *   WIFIBATTLEMATCH_UTIL_SetRequest  0x021E8AB4  thumb  ov177
 *   WIFIBATTLEMATCH_UTIL_CommitRequest  0x021E8AB8  thumb  ov177
 *   WIFIBATTLEMATCH_UTIL_GetBusy  0x021E8844  thumb  ov177
 *   WIFIBATTLEMATCH_VIEW_SetActorVisible  0x021E7E0C  thumb  ov177
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   TRADE_HISTORY_GetFromSave  0x02009EC8  thumb
 *   REGULATION_NoOp  0x0200AE14  thumb
 *   REGULATION_Card_GetValue  0x0200B078  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   POKE_REGULATION_CheckParty  0x0201A090  thumb
 *   POKE_REGULATION_GetDataSize  0x0201A918  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   PMSI_PARAM_InitSentence  0x020242A4  thumb
 *   PMSI_PARAM_IsValid  0x020245D4  thumb
 *   BMP_OAM_Check5BEC  0x02025BEC  thumb
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   func_02040588  0x02040588  arm
 *   STRBUF_Delete  0x02045808  arm
 *   STRBUF_ToChars  0x02045A38  arm
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   func_02045B38  0x02045B38  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_02045EC0  0x02045EC0  arm
 *   BUTTON_MAN_ConvertUcs2ToSjis  0x02052274  arm
 *   DWC_RAPCOMMON_CreateSubHeap  0x02156E30  thumb
 *   DWC_RAPCOMMON_DestroySubHeap  0x02156ED0  thumb
 *   DWC_RAPCOMMON_SetHeapTag  0x02156F50  thumb
 *   WIFIBATTLEMATCH_NET_SetupCompRecord  0x021D965C  thumb
 *   WIFIBATTLEMATCH_NET_DeleteTradeIcon  0x021D97A4  thumb
 *   WIFIBATTLEMATCH_NET_IsTradeIconReady  0x021D97B8  thumb
 *   WIFIBATTLEMATCH_NET_IsTradeIconAnimDone  0x021D97C4  thumb
 *   WIFIBATTLEMATCH_NET_StartRegCardAnim  0x021D9804  thumb
 *   WIFIBATTLEMATCH_NET_IsCompCardReady  0x021D9868  thumb
 *   WIFIBATTLEMATCH_NET_SetupRegSprite  0x021D98E4  thumb
 *   WIFIBATTLEMATCH_NET_DeleteCompSprite  0x021D99F4  thumb
 *   WIFIBATTLEMATCH_NET_IsCompSpriteAnimDone  0x021D9A08  thumb
 *   WIFIBATTLEMATCH_NET_SetCompWaitCallback  0x021D9A1C  thumb
 *   WIFIBATTLEMATCH_NET_GetCompWaitResult  0x021D9A30  thumb
 *   WIFIBATTLEMATCH_NET_CopyCompSave  0x021D9A9C  thumb
 *   WIFIBATTLEMATCH_NET_VerifyCompSignature  0x021D9B2C  thumb
 *   WIFIBATTLEMATCH_NET_CompareParty  0x021D9BC4  thumb
 *   WIFIBATTLEMATCH_NET_CompHandleCancel  0x021D9C34  thumb
 *   WIFIBATTLEMATCH_NET_CompClearError  0x021D9D40  thumb
 *   WIFIBATTLEMATCH_NET_GetSetCompStat  0x021D9D50  thumb
 *   WIFIBATTLEMATCH_NET_SetTimingSyncRange  0x021D9ED4  thumb
 *   WIFIBATTLEMATCH_NET_IsTimingSyncRange  0x021D9EEC  thumb
 *   WIFIBATTLEMATCH_NET_HandleNetError  0x021D9F04  thumb
 *   WIFIBATTLEMATCH_NET_SetMatchKey  0x021DA0D4  thumb
 *   WIFIBATTLEMATCH_NET_StartMatchmaking  0x021DA1E4  thumb
 *   WIFIBATTLEMATCH_NET_DisconnectWifi  0x021DA36C  thumb
 *   WIFIBATTLEMATCH_NET_ClearCancelFlag  0x021DA384  thumb
 *   WIFIBATTLEMATCH_NET_StopMatchmaking  0x021DA390  thumb
 *   WIFIBATTLEMATCH_NET_SendSessionQuery  0x021DA434  thumb
 *   WIFIBATTLEMATCH_NET_TakeSessionResult  0x021DA45C  thumb
 *   WIFIBATTLEMATCH_NET_SetupMatchReport  0x021DA5B0  thumb
 *   WIFIBATTLEMATCH_NET_ScProcess  0x021DA6B8  thumb
 *   WIFIBATTLEMATCH_NET_GdbRequest  0x021DB3A4  thumb
 *   WIFIBATTLEMATCH_NET_GdbGetMyRecords  0x021DB478  thumb
 *   WIFIBATTLEMATCH_NET_SendRegData  0x021DC1A0  thumb
 *   WIFIBATTLEMATCH_NET_TakeRegData  0x021DC1E4  thumb
 *   WIFIBATTLEMATCH_NET_SendRegFlag  0x021DC268  thumb
 *   WIFIBATTLEMATCH_NET_TakeRegFlag  0x021DC2A0  thumb
 *   WIFIBATTLEMATCH_NET_CheckProfanity  0x021DCA28  thumb
 *   WIFIBATTLEMATCH_NET_ProfanityProcess  0x021DCAEC  thumb
 *   WIFIBATTLEMATCH_NET_CompStepE  0x021D7BE4  thumb
 *   WIFIBATTLEMATCH_NET_CompCleanup  0x021D9064  thumb
 *   WIFIBATTLEMATCH_NET_CompStepM  0x021D9090  thumb
 *   WIFIBATTLEMATCH_NET_CompStepK  0x021D8EC8  thumb
 *   WIFIBATTLEMATCH_NET_CompStepI  0x021D8CF0  thumb
 *   WIFIBATTLEMATCH_NET_CompStepG  0x021D8904  thumb
 *   WIFIBATTLEMATCH_NET_CompStepL  0x021D8FA8  thumb
 *
 * The ov175 link-battle main sequence: one step of a 54-state machine over
 *     *state (0..0x35) on the object in r2, with the frame's sys handle in r0.
 *     The listing cuts it at 0x021D885C, a bl-minted label on its own shared
 *     tail (the timeout and disconnect check); the real extent is
 *     0x021D7E18..0x021D8904, 2796 bytes.
 *
 * The six leaf calls that kept it at MATCH* (0x021E8AB4 x3, 0x021E8AB8,
 *     0x02156F50, 0x02009EC8) resolve since seeds_2 labelled and matched them.
 */
#include "../include/Obj24253.h"
#include "../include/Obj24254.h"
#include "../include/Obj24255.h"
#include "../include/Obj24256.h"
#include "../include/Obj24260.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct Sub {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
};

struct W {
    u32 f00;
    u32 f04;
    u32 *f08;
    u32 f0c;
    u32 f10;
    u8 *f14;
    u8 *f18;
    u32 f1c;
    u32 *f20;
    u32 f24;
    u32 *f28;
    u32 f2c;
    u32 f30;
    struct Sub *f34;
    u32 f38;
    u32 f3c;
    u32 *f40;
};

struct Obj {
    u8 pad00[0x14];
    u32 f14;
    u8 pad18[0x10];
    u32 f28;
    u32 f2c;
    u32 pad30;
    void *f34;
    u8 pad38[0xa8];
    u32 fe0;
    u32 fe4;
    u32 fe8;
    u32 fec;
    u32 ff0;
    u32 ff4;
    u32 ff8;
    u32 ffc;
    u32 f100;
    struct W *f104;
    u32 f108;
};

struct Buf16 {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
};

extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void DWC_CloseAllConnectionsHard(void);

extern void GFL_USE_PlaySeDefaultVolume(u32 id);
typedef signed int     s32;
struct Big;
struct Reg2;
extern void *TRADE_HISTORY_GetFromSave(void *sys);
extern int REGULATION_NoOp(u32 a);
extern s32 REGULATION_Card_GetValue(struct Reg2 *p, u32 id);
struct MsgBank;
struct Rec;
struct T;
struct U16Vec;
extern u32 func_0200FB24(void);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern int POKE_REGULATION_CheckParty(void *rules, void *party, u32 *mask);
extern int POKE_REGULATION_GetDataSize(void);
extern unsigned int POKEPARTY_GetCount(void *list);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void PMSI_PARAM_InitSentence(void *obj, u32 id);
extern u32 PMSI_PARAM_IsValid(struct T *p, u32 a1);
extern u32 BMP_OAM_Check5BEC(u32 a, u32 b, u32 c);
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern int GFL_NET_GetRunState(void);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void STRBUF_Delete(struct U16Vec *vec);
struct U16Vec;
extern void STRBUF_ToChars(struct U16Vec *a, u16 *dst, unsigned int n);
extern u16 STRBUF_GetEosChar(void);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void BUTTON_MAN_ConvertUcs2ToSjis(u8 *a, u8 *b, u32 n);
extern void DWC_RAPCOMMON_CreateSubHeap(int a, int b, int c, int d);
extern void DWC_RAPCOMMON_DestroySubHeap(void);
extern void DWC_RAPCOMMON_SetHeapTag(int a);

extern void WIFIBATTLEMATCH_NET_CompStepE(u32 sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_CompCleanup(void *obj, int unused, u8 *p);
extern void WIFIBATTLEMATCH_NET_CompStepM(u32 sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_CompStepK(u32 sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_CompStepI(u32 sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_CompStepG(u32 sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_CompStepL(u32 sys, int *state, char *ctx);

extern void WIFIBATTLEMATCH_NET_SetupCompRecord(struct Obj *obj);
extern void WIFIBATTLEMATCH_NET_DeleteTradeIcon(char *obj);
extern u32 WIFIBATTLEMATCH_NET_IsTradeIconReady(char *obj);
extern int WIFIBATTLEMATCH_NET_IsTradeIconAnimDone(char *obj);
extern void WIFIBATTLEMATCH_NET_StartRegCardAnim(u32 *obj, u32 arg);
extern u32 WIFIBATTLEMATCH_NET_IsCompCardReady(char *obj);
extern void WIFIBATTLEMATCH_NET_SetupRegSprite(u32 *p, int mode);
extern void WIFIBATTLEMATCH_NET_DeleteCompSprite(char *obj);
extern int WIFIBATTLEMATCH_NET_IsCompSpriteAnimDone(char *obj);
extern void WIFIBATTLEMATCH_NET_SetCompWaitCallback(char *obj, void *fn);
extern u32 WIFIBATTLEMATCH_NET_GetCompWaitResult(char *obj);
extern void WIFIBATTLEMATCH_NET_CopyCompSave(char *dst, char *obj);
extern u32 WIFIBATTLEMATCH_NET_VerifyCompSignature(char *obj, void *list, u32 heapId);
extern int WIFIBATTLEMATCH_NET_CompareParty(u32 a, u32 b);
extern int WIFIBATTLEMATCH_NET_CompHandleCancel(char *obj, int trigger, int go);
extern void WIFIBATTLEMATCH_NET_CompClearError(char *obj);
extern int WIFIBATTLEMATCH_NET_GetSetCompStat(char *obj, u32 *rec);
extern void WIFIBATTLEMATCH_NET_SetTimingSyncRange(char *obj, u32 v);
extern int WIFIBATTLEMATCH_NET_IsTimingSyncRange(char *obj);
extern int WIFIBATTLEMATCH_NET_HandleNetError(char *ctx, void *a, void *b);
extern void WIFIBATTLEMATCH_NET_SetMatchKey(char *obj, int mode, int extra, int group, int *rec);
extern int WIFIBATTLEMATCH_NET_StartMatchmaking(char *obj);
extern void WIFIBATTLEMATCH_NET_DisconnectWifi(void *ctx);
extern void WIFIBATTLEMATCH_NET_ClearCancelFlag(char *obj);
extern int WIFIBATTLEMATCH_NET_StopMatchmaking(char *obj);
extern int WIFIBATTLEMATCH_NET_SendSessionQuery(void *ctx);
extern u32 WIFIBATTLEMATCH_NET_TakeSessionResult(char *obj);
extern void WIFIBATTLEMATCH_NET_SetupMatchReport(char *obj, int mode, int kind, u32 a3, u32 *rec, u32 slot);
extern int WIFIBATTLEMATCH_NET_ScProcess(char *p, u32 *out);
extern void WIFIBATTLEMATCH_NET_GdbRequest(char *obj, u32 target, int kind, u32 arg);
extern int WIFIBATTLEMATCH_NET_GdbGetMyRecords(char *obj);
extern u32 WIFIBATTLEMATCH_NET_SendRegData(char *obj, u32 data);
extern u32 WIFIBATTLEMATCH_NET_TakeRegData(char *obj, char **out);
extern int WIFIBATTLEMATCH_NET_SendRegFlag(char *obj, u32 data);
extern u32 WIFIBATTLEMATCH_NET_TakeRegFlag(char *obj, u32 arg);
extern void WIFIBATTLEMATCH_NET_CheckProfanity(char *obj, u32 win, u16 tag);
extern int WIFIBATTLEMATCH_NET_ProfanityProcess(char *obj, int *out);

extern void WIFIBATTLEMATCH_VIEW_SetActorVisible(void **p, int on);
extern void WIFIBATTLEMATCH_UTIL_PrintMessage(int *p, int a, int b, int c);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
extern void WIFIBATTLEMATCH_UTIL_ClearCallback(int a);
extern void WIFIBATTLEMATCH_UTIL_SetRequest(u32 sys, u32 v);
extern void WIFIBATTLEMATCH_UTIL_CommitRequest(u32 sys);
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *p);

static inline void TouchParty(u8 *rec, u8 *buf)
{
    int i;

    BUTTON_MAN_ConvertUcs2ToSjis(rec, buf, 8);
    {
        void *p = rec + 0xd4;

        for (i = 0; i < (int)POKEPARTY_GetCount(p); i++)
            POKEPARTY_GetMember(p, i);
    }
}

void WIFIBATTLEMATCH_NET_CompStepF(u32 sys, int *state, struct Obj *obj)
{
    struct Buf16 buf;
    char *rec38;
    u32 mask;
    u32 out;
    u8 b28[8];
    u8 b20[8];
    void *str;
    struct W *w18;
    int flag;
    int fresh;
    int bad;
    int s;
    int res;
    int i;
    int trig = 0;
    u8 *r;
    void *msg;

    w18 = obj->f104;
    flag = 0;
    s = *state;
    if (s >= 0xc && s < 0x1b)
        trig = 1;
    res = WIFIBATTLEMATCH_NET_CompHandleCancel((char *)obj, trig,
                        !((s >= 0x19 && s <= 0x1a) || (s >= 0x11 && s <= 0x12)));
    if (res == 3) {
        *state = 0x28;
        return;
    }

    switch (*state) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)obj->f2c, obj->f14, 0x18, 2);
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 1);
        *state = 0x35;
        break;
    case 1:
        switch (WIFIBATTLEMATCH_NET_HandleNetError(obj->f34, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepE);
            WIFIBATTLEMATCH_NET_CompClearError((char *)obj);
            break;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        case 0:
            WIFIBATTLEMATCH_NET_SetCompWaitCallback((char *)obj, WIFIBATTLEMATCH_NET_CompStepM);
            *state = 2;
            break;
        }
        break;
    case 2:
        i = WIFIBATTLEMATCH_NET_GetCompWaitResult((char *)obj);
        if (i == 0)
            *state = 4;
        else if (i == 1 || i == 2)
            *state = 3;
        else if (i == 3)
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
        switch (WIFIBATTLEMATCH_NET_HandleNetError(obj->f34, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepE);
            WIFIBATTLEMATCH_NET_CompClearError((char *)obj);
            break;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        }
        break;
    case 3:
        WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepK);
        break;
    case 4:
        if (*obj->f104->f20 == 0) {
            WIFIBATTLEMATCH_NET_GdbRequest(obj->f34, -1, 1, (u32)obj->f104->f34);
            *state = 5;
        }
        break;
    case 5:
        i = WIFIBATTLEMATCH_NET_GdbGetMyRecords(obj->f34);
        if (i == 1) {
            r = w18->f14;
            *obj->f104->f20 = 0;
            WIFIBATTLEMATCH_NET_CopyCompSave((char *)r, (char *)obj);
            *obj->f104->f28 = obj->f104->f34->f14;
            if (WIFIBATTLEMATCH_NET_GetSetCompStat((char *)obj, (u32 *)obj->f104->f34) != 0)
                *state = 6;
            else
                *state = 0xa;
        }
        if (i != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(obj->f34, 0, 0)) {
            case 1:
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepE);
                WIFIBATTLEMATCH_NET_CompClearError((char *)obj);
                break;
            case 2:
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
                break;
            }
        }
        break;
    case 6:
        *state = 7;
        break;
    case 7:
        if (WIFIBATTLEMATCH_NET_IsTradeIconAnimDone((char *)obj) != 0) {
            WIFIBATTLEMATCH_NET_DeleteTradeIcon((char *)obj);
            *state = 8;
        }
        break;
    case 8:
        WIFIBATTLEMATCH_NET_SetupCompRecord(obj);
        *state = 9;
        break;
    case 9:
        if (WIFIBATTLEMATCH_NET_IsTradeIconReady((char *)obj) != 0)
            *state = 0xa;
        break;
    case 0xa:
        obj->fec = 0;
        WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)obj->f28, 1);
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)obj->f2c, obj->f14, 0x55, 0);
        *state = 0x35;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 0xb);
        break;
    case 0xb:
        i = obj->f108;
        MI_CpuFill8(&buf, 0, sizeof(buf));
        buf.a = obj->f104->f34->f10;
        buf.b = obj->f104->f34->f04;
        buf.c = REGULATION_Card_GetValue((struct Reg2 *)i, 2);
        buf.d = obj->f104->f34->f08 + obj->f104->f34->f0c;
        WIFIBATTLEMATCH_NET_SetMatchKey(obj->f34, 0, 0, w18->f08[1], (int *)(&buf));
        obj->fe4 = 0;
        obj->fe8 = 0;
        *state = 0xc;
        break;
    case 0xc:
        switch (WIFIBATTLEMATCH_NET_HandleNetError(obj->f34, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)obj->f28, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepI);
            WIFIBATTLEMATCH_NET_CompClearError((char *)obj);
            break;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)obj->f28, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        }
        i = WIFIBATTLEMATCH_NET_StartMatchmaking(obj->f34);
        if (i == 1)
            *state = 0xd;
        else if (i == 2)
            *state = 0xb;
        break;
    case 0xd:
        if (res == 0) {
            if (WIFIBATTLEMATCH_NET_SendRegData(obj->f34, (u32)w18->f14) != 0) {
                *state = 0xe;
                obj->ff0 = 0;
            }
        } else {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(obj->f34, 0, (void *)1)) {
            case 1:
            case 4:
                obj->fec = 0;
                WIFIBATTLEMATCH_NET_DeleteCompSprite((char *)obj);
                WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)obj->f28, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepI);
                WIFIBATTLEMATCH_NET_CompClearError((char *)obj);
                break;
            case 2:
                WIFIBATTLEMATCH_NET_DeleteCompSprite((char *)obj);
                WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)obj->f28, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
                break;
            }
        }
        break;
    case 0xe:
        if (WIFIBATTLEMATCH_NET_TakeRegData(obj->f34, &rec38) != 0) {
            MI_CpuCopy8(rec38, w18->f18, POKE_REGULATION_GetDataSize() + 0xd4);
            r = w18->f18;
            bad = 0;
            fresh = 1;
            for (i = 0; i < 8; i++) {
                if (((u16 *)r)[i] == STRBUF_GetEosChar())
                    fresh = 0;
            }
            if (fresh) {
                bad++;
                msg = func_02045B38(0, 2, 0xd2, 0x8057);
                str = func_02045EC0(msg, 0x8057);
                STRBUF_ToChars(str, (u16 *)r, 8);
                STRBUF_Delete(str);
                MSGDATA_Delete(msg);
            }
            if (r[0x1d] != 0 && r[0x1d] != 1) {
                r[0x1d] = 0;
                bad++;
            }
            if ((u8)r[0x1c] >= 0x10) {
                r[0x1c] = r[0x1d] == 0 ? 0 : 8;
                bad++;
            }
            if (BMP_OAM_Check5BEC(r[0x18], r[0x19], r[0x1a]) == 0) {
                r[0x18] = 0;
                r[0x19] = 0;
                bad++;
            }
            if (PMSI_PARAM_IsValid((struct T *)(r + 0x38), 0x8057) == 0) {
                PMSI_PARAM_InitSentence(r + 0x38, 1);
                bad++;
            }
            if (bad == 0)
                TRADE_HISTORY_GetFromSave(GAME_DATA_GetSaveControl((struct Big *)(*w18->f08)));
            *state = 0xf;
        }
        flag = 1;
        break;
    case 0xf:
        TouchParty(w18->f14, b28);
        TouchParty(w18->f18, b20);
        if (((struct Obj24253 *)(w18->f14))->f40 == ((struct Obj24254 *)(w18->f18))->f40
            && ((struct Obj24255 *)(w18->f14))->f50 == ((struct Obj24256 *)(w18->f18))->f50)
            *state = 0x10;
        else
            *state = 0x33;
        break;
    case 0x10:
        mask = 0;
        if (POKE_REGULATION_CheckParty((void *)REGULATION_NoOp(obj->f108), w18->f18 + 0xd4, &mask) == 0) {
            *state = 0x11;
        } else {
            obj->fe4++;
            *state = 0x16;
        }
        break;
    case 0x11:
        if (*obj->f104->f20 == 0) {
            WIFIBATTLEMATCH_NET_GdbRequest(obj->f34, ((struct Obj24260 *)(obj->f104->f18))->f4C, 3, obj->ffc);
            *state = 0x12;
        }
        break;
    case 0x12:
        i = WIFIBATTLEMATCH_NET_GdbGetMyRecords(obj->f34);
        if (i == 1) {
            *obj->f104->f20 = 0xe10;
            *state = 0x13;
        }
        if (i != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(obj->f34, 0, (void *)1)) {
            case 1:
            case 4:
                WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)obj->f28, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepI);
                WIFIBATTLEMATCH_NET_CompClearError((char *)obj);
                break;
            case 2:
                WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)obj->f28, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
                break;
            }
        }
        break;
    case 0x13:
        WIFIBATTLEMATCH_NET_SetTimingSyncRange(obj->f34, 0x17);
        *state = 0x14;
        break;
    case 0x14:
        if (WIFIBATTLEMATCH_NET_IsTimingSyncRange(obj->f34) != 0)
            *state = 0x15;
        switch (WIFIBATTLEMATCH_NET_HandleNetError(obj->f34, 0, (void *)1)) {
        case 1:
        case 4:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)obj->f28, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepI);
            WIFIBATTLEMATCH_NET_CompClearError((char *)obj);
            break;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)obj->f28, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        }
        break;
    case 0x15:
        if (WIFIBATTLEMATCH_NET_CompareParty(obj->ffc, (u32)(obj->f104->f18 + 0xd4)) == 0)
            obj->fe4++;
        if (WIFIBATTLEMATCH_NET_VerifyCompSignature((char *)obj->f104->f18, obj->f104->f18 + 0xd4, 0x57) == 0)
            obj->fe4++;
        *state = 0x16;
        break;
    case 0x16:
        if (res == 0) {
            if (WIFIBATTLEMATCH_NET_SendRegFlag(obj->f34, (u32)(&obj->fe4)) != 0) {
                *state = 0x17;
                obj->ff0 = 0;
            }
        } else {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(obj->f34, 0, (void *)1)) {
            case 1:
            case 4:
                obj->fec = 0;
                WIFIBATTLEMATCH_NET_DeleteCompSprite((char *)obj);
                WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)obj->f28, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepI);
                WIFIBATTLEMATCH_NET_CompClearError((char *)obj);
                break;
            case 2:
                WIFIBATTLEMATCH_NET_DeleteCompSprite((char *)obj);
                WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)obj->f28, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
                break;
            }
        }
        break;
    case 0x17:
        if (WIFIBATTLEMATCH_NET_TakeRegFlag(obj->f34, (u32)(&obj->fe8)) != 0)
            *state = 0x18;
        else
            flag = 1;
        break;
    case 0x18:
        if (obj->fe8 == 0 && obj->fe4 == 0)
            *state = 0x19;
        else
            *state = 0x33;
        break;
    case 0x19:
        WIFIBATTLEMATCH_NET_CheckProfanity(obj->f34, (u32)w18->f18, 0x57);
        *state = 0x1a;
        break;
    case 0x1a:
        if (WIFIBATTLEMATCH_NET_ProfanityProcess(obj->f34, (int *)(&out)) != 0) {
            *obj->f104->f40 = out;
            *state = 0x1b;
        }
        switch (WIFIBATTLEMATCH_NET_HandleNetError(obj->f34, 0, (void *)1)) {
        case 1:
        case 4:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)obj->f28, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepI);
            WIFIBATTLEMATCH_NET_CompClearError((char *)obj);
            break;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)obj->f28, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        }
        break;
    case 0x1b:
        if (res == 0) {
            WIFIBATTLEMATCH_NET_SetTimingSyncRange(obj->f34, 0x15);
            obj->ff0 = 0;
            *state = 0x1c;
        }
        break;
    case 0x1c:
        if (WIFIBATTLEMATCH_NET_TakeSessionResult(obj->f34) == 0 && WIFIBATTLEMATCH_NET_IsTimingSyncRange(obj->f34) != 0)
            *state = 0x1d;
        flag = 1;
        break;
    case 0x1d:
        WIFIBATTLEMATCH_NET_SetTimingSyncRange(obj->f34, 0x16);
        *state = 0x1e;
        obj->ff0 = 0;
        break;
    case 0x1e:
        if (WIFIBATTLEMATCH_NET_IsTimingSyncRange(obj->f34) != 0)
            *state = 0x1f;
        flag = 1;
        break;
    case 0x1f:
        WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)obj->f28, 0);
        GFL_USE_PlaySeDefaultVolume(0x63a);
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)obj->f2c, obj->f14, 0x57, 1);
        *state = 0x35;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 0x20);
        obj->fe0 = 0;
        break;
    case 0x20:
        if (obj->fe0++ > 0x78) {
            obj->fe0 = 0;
            func_02040588(0, 0);
            WIFIBATTLEMATCH_NET_StartRegCardAnim((u32 *)obj, (u32)w18->f18);
            *state = 0x21;
        }
        break;
    case 0x21:
        if (WIFIBATTLEMATCH_NET_IsCompCardReady((char *)obj) != 0)
            *state = 0x22;
        break;
    case 0x22:
        if (obj->fe0++ != 0) {
            obj->fe0 = 0;
            *state = 0x23;
        }
        break;
    case 0x23:
        GFL_HEAP_CreateChildHeap(1, 0x86, 0x60000);
        DWC_RAPCOMMON_CreateSubHeap(9, 0x60000, 1000, 0x86);
        DWC_RAPCOMMON_SetHeapTag(0x86);
        WIFIBATTLEMATCH_NET_SetupMatchReport(obj->f34, 0, 0, 0, 0, 0);
        obj->ff4 = 0;
        *state = 0x24;
        obj->ff8 = 0;
        break;
    case 0x24:
        if (obj->ff8 == 0)
            obj->ff8 = WIFIBATTLEMATCH_NET_ScProcess(obj->f34, &obj->ff4);
        if (obj->ff8 == 1)
            *state = 0x25;
        if (obj->ff8 != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(obj->f34, 0, (void *)1)) {
            case 1:
                WIFIBATTLEMATCH_NET_DisconnectWifi(obj->f34);
            case 2:
            case 4:
                DWC_RAPCOMMON_DestroySubHeap();
                WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)obj->f28, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
                break;
            }
        }
        break;
    case 0x25:
        DWC_RAPCOMMON_DestroySubHeap();
        func_02040588(0, 1);
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)obj->f2c, obj->f14, 0x24, 2);
        *state = 0x35;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 0x26);
        break;
    case 0x26:
        if (obj->fe0++ > 0x3c) {
            obj->fe0 = 0;
            w18->f04 = 1;
            WIFIBATTLEMATCH_UTIL_ClearCallback(sys);
        }
        break;
    case 0x27:
        WIFIBATTLEMATCH_NET_DisconnectWifi(obj->f34);
        WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)obj->f28, 0);
        w18->f0c = 2;
        obj->f100 = 1;
        if (obj->ff4 != 0)
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepG);
        else
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepI);
        break;
    case 0x28:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)obj->f2c, obj->f14, 0x4e, 1);
        *state = 0x35;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 0x29);
        break;
    case 0x29:
        WIFIBATTLEMATCH_NET_SetupRegSprite((u32 *)obj, 0);
        *state = 0x2a;
        break;
    case 0x2a:
        i = WIFIBATTLEMATCH_NET_IsCompSpriteAnimDone((char *)obj);
        if (i != -1) {
            WIFIBATTLEMATCH_NET_DeleteCompSprite((char *)obj);
            switch (i) {
            case 0:
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepL);
                break;
            case 1:
                *state = 0x2b;
                break;
            }
        }
        break;
    case 0x2b:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)obj->f2c, obj->f14, 0x26, 1);
        *state = 0x35;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 0x2c);
        break;
    case 0x2c:
        WIFIBATTLEMATCH_NET_SetupRegSprite((u32 *)obj, 0);
        *state = 0x2d;
        break;
    case 0x2d:
        i = WIFIBATTLEMATCH_NET_IsCompSpriteAnimDone((char *)obj);
        if (i != -1) {
            WIFIBATTLEMATCH_NET_DeleteCompSprite((char *)obj);
            switch (i) {
            case 0:
                *state = 0x2e;
                break;
            case 1:
                *state = 0x28;
                break;
            }
        }
        break;
    case 0x2e:
        *state = 0x2f;
        break;
    case 0x2f:
        switch (WIFIBATTLEMATCH_NET_HandleNetError(obj->f34, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepE);
            break;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        case 0:
            WIFIBATTLEMATCH_NET_SetCompWaitCallback((char *)obj, WIFIBATTLEMATCH_NET_CompStepM);
            *state = 0x30;
            break;
        }
        break;
    case 0x30:
        i = WIFIBATTLEMATCH_NET_GetCompWaitResult((char *)obj);
        if (i == 0)
            *state = 0xa;
        else if (i == 1 || i == 2)
            *state = 3;
        else if (i == 3)
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
        switch (WIFIBATTLEMATCH_NET_HandleNetError(obj->f34, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepE);
            WIFIBATTLEMATCH_NET_CompClearError((char *)obj);
            break;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        }
        break;
    case 0x31:
        if (WIFIBATTLEMATCH_NET_SendSessionQuery(obj->f34) != 0)
            *state = 0x32;
        break;
    case 0x32:
        WIFIBATTLEMATCH_NET_DisconnectWifi(obj->f34);
        *state = 0xa;
        break;
    case 0x33:
        WIFIBATTLEMATCH_NET_ClearCancelFlag(obj->f34);
        *state = 0x34;
        obj->ff0 = 0;
        break;
    case 0x34:
        flag = 1;
        if (WIFIBATTLEMATCH_NET_StopMatchmaking(obj->f34) != 0)
            *state = 0xb;
        break;
    case 0x35:
        if (WIFIBATTLEMATCH_UTIL_GetBusy((const int *)obj->f2c) != 0)
            WIFIBATTLEMATCH_UTIL_CommitRequest(sys);
        break;
    }

    if (flag) {
        i = 0;
        if (obj->ff0++ > 0x4b0) {
            obj->ff0 = 0;
            i = 1;
        }
        if (WIFIBATTLEMATCH_NET_TakeSessionResult(obj->f34) != 0)
            i = 1;
        if (i) {
            WIFIBATTLEMATCH_NET_DisconnectWifi(obj->f34);
            if (func_0200FB24() == 0 && GFL_NET_GetRunState() != 0)
                DWC_CloseAllConnectionsHard();
            *state = 0xa;
        }
        switch (WIFIBATTLEMATCH_NET_HandleNetError(obj->f34, 0, (void *)1)) {
        case 1:
        case 4:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)obj->f28, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepI);
            WIFIBATTLEMATCH_NET_CompClearError((char *)obj);
            break;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)obj->f28, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        }
    }
}
