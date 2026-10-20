/*
 * file:     worldtrade_enter.c
 * unit:     yes
 * function: WORLDTRADE_ENTER_Init, WORLDTRADE_ENTER_CallStateHandler, WORLDTRADE_ENTER_Exit, WORLDTRADE_ENTER_EmptyInitHook, WORLDTRADE_ENTER_EmptyExitHook, WORLDTRADE_ENTER_SetState, WORLDTRADE_ENTER_StateStartServerCheck, WORLDTRADE_ENTER_StatePollServerCheck, WORLDTRADE_ENTER_InitDwcTrade, WORLDTRADE_ENTER_StateStartConnect, WORLDTRADE_ENTER_WaitServerCheck, WORLDTRADE_ENTER_SendProfile, WORLDTRADE_ENTER_WaitProfileResult, WORLDTRADE_ENTER_PushWifiSetup, WORLDTRADE_ENTER_StateWaitWifiSetup, WORLDTRADE_ENTER_PushWifiError, WORLDTRADE_ENTER_StateWaitWifiError, WORLDTRADE_ENTER_RunDialog, WORLDTRADE_ENTER_StateAbortConnect, WORLDTRADE_ENTER_StateExit, WORLDTRADE_ENTER_ShowErrorMessage, WORLDTRADE_ENTER_ShutdownDwcStep
 * address:  0x021F89B4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from worldtrade_deposit.c, worldtrade_enter.c, worldtrade_input.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   WORLDTRADE_AdvanceScreenId  0x021F4EC8  thumb  ov135
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   DPW_TR_Main 0x021C7C1C arm ov114
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   PROCSYS_Push  0x02031348  arm
 *   WORLDTRADE_ExitPlanes 0x021F50EC thumb ov135
 *   d_02203C1C 0x02203C1C data a4
 *   WORLDTRADE_ClearAndShowPlanes  0x021F5074  thumb  ov135
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   DWC_NASLoginAsync  0x02168064  arm
 *   DWC_NASLoginProcess 0x02168124 arm ov009
 *   MYSTATUS_SetProfileIdOnce 0x02008540 thumb
 *   MYSTATUS_GetProfileId 0x0200853C thumb
 *   DWC_CreateFriendKey 0x0205994C arm
 *   DPW_TR_Init 0x021C7BA0 arm ov114
 *   WORLDTRADE_CancelSave  0x021F513C  thumb  ov135
 *   WORLDTRADE_DeleteTimeIcon  0x021F4FC4  thumb  ov135
 *   DPW_TR_IsAsyncEnd  0x021C866C  arm
 *   DPW_TR_GetAsyncResult  0x021C86A8  arm
 *   NHTTP_RAP_InitTrainerInfo 0x021B9B00 thumb ov114
 *   DPW_TR_SetProfileAsync 0x021C8E18 arm ov114
 *   str_02203C34 0x02203C34 data a1
 *   gNetSaveMainProc 0x021D6338 data ov115 a4
 *   ov115_id 0x00000073 data
 *   GFL_NET_ERR_ShowScreen 0x0200F7B8 thumb
 *   tbl_021D654C 0x021D654C data ov115 a4
 *   WIFILOGIN_MSG_DrawWindow 0x021D5B5C thumb ov115
 *   WIFILOGIN_MSG_IsPrintDone 0x021D5C70 thumb ov115
 *   DPW_TR_End 0x021C8658 arm ov114
 *   DWC_ShutdownFriendsMatch 0x0216AD50 arm ov009
 *   DWC_CleanupInet 0x0205CC20 arm
 *   WIFILIST_GetGsProfileId  0x02009CC0  thumb  arm9
 *   WIFILIST_GetWork  0x02009860  thumb  arm9
 */
#include "worldtrade_types.h"
#include "../sdk_ioreg.h"

#include "../arm9/gfl_heap_wrap.h"

struct GameSystem;
struct GameData;

#include "../arm9/gamesystem.h"

struct Sub020097BCObj;

struct DWCstAccUserData;

#include "../types.h"

#include "worldtrade.h"



#include "../arm9/gfl_use.h"


#include "../ov009/dwc_nasfunc.h"

struct WifiList;

#include "../arm9/wifilist.h"

struct MyStatus;

#include "../arm9/mystatus.h"


#include "../arm9/dwc_account.h"

#include "../ov114/dpw_tr.h"






struct MYSTATUS;
struct _NHTTPRapTrainerInfo;

#include "../ov114/nhttp_rap_evilcheck.h"


#include "../arm9/mi_memory.h"

#include "../arm9/procsys.h"

#include "../arm9/net_err.h"


#include "../ov115/wifilogin_message.h"


#include "../ov009/dwc_main.h"

#include "../arm9/dwc_connectinet.h"

int WORLDTRADE_ENTER_Init(WorldtradeWork *p);

int WORLDTRADE_ENTER_CallStateHandler(WorldtradeWork *p);

u32 WORLDTRADE_ENTER_Exit(WorldtradeWork *p);

void WORLDTRADE_ENTER_EmptyInitHook(WorldtradeWork *p);

void WORLDTRADE_ENTER_EmptyExitHook(void);

int WORLDTRADE_ENTER_SetState(WorldtradeWork *p);

int WORLDTRADE_ENTER_StateStartServerCheck(WorldtradeWork *p);

int WORLDTRADE_ENTER_StatePollServerCheck(WorldtradeWork *p);

int WORLDTRADE_ENTER_InitDwcTrade(WorldtradeWork *p);

int WORLDTRADE_ENTER_StateStartConnect(WorldtradeWork *p);

int WORLDTRADE_ENTER_WaitServerCheck(WorldtradeWork *p);

int WORLDTRADE_ENTER_SendProfile(WorldtradeWork *p);

int WORLDTRADE_ENTER_WaitProfileResult(WorldtradeWork *p);

int WORLDTRADE_ENTER_PushWifiSetup(WorldtradeWork *p);

int WORLDTRADE_ENTER_StateWaitWifiSetup(WorldtradeWork *p);

int WORLDTRADE_ENTER_PushWifiError(WorldtradeWork *p);

int WORLDTRADE_ENTER_StateWaitWifiError(WorldtradeWork *p);

int WORLDTRADE_ENTER_RunDialog(void *dialog, WorldtradeWork *p);

u32 WORLDTRADE_ENTER_StateAbortConnect(WorldtradeWork *p);

int WORLDTRADE_ENTER_StateExit(WorldtradeWork *p);

int WORLDTRADE_ENTER_ShowErrorMessage(WorldtradeWork *p, void *dialog);

int WORLDTRADE_ENTER_ShutdownDwcStep(WorldtradeWork *p, void *dialog);

extern const char str_02203C34[], ov115_id[];

extern const u32 gNetSaveMainProc[];

extern u8 tbl_021D654C[];

/*
 * volatile: hardware read-modify-write at 021F89C6/021F89CA, 0x04000304.
 */
int WORLDTRADE_ENTER_Init(WorldtradeWork *p) {WORLDTRADE_ExitPlanes(p);WORLDTRADE_ENTER_EmptyInitHook(p);*(volatile u16 *)REG_POWCNT1_ADDR = (u16)(*(volatile u16 *)REG_POWCNT1_ADDR & ~0x8000);switch(p->kind){case 19:case 21:p->state=2;break;case 20:p->state=4;break;}return 1;}

extern int (*const d_02203C1C[])(WorldtradeWork *);

int WORLDTRADE_ENTER_CallStateHandler(WorldtradeWork *p) { int prevState,result;prevState=p->state_i;result=d_02203C1C[prevState](p);if(prevState!=p->state_i){p->subStep=0;p->stepTimer=0;}return result; }

/*
 * Run the three teardown steps, then report 4 while the +0x10 handle is gone.
 */
u32 WORLDTRADE_ENTER_Exit(WorldtradeWork *p)
{
    WORLDTRADE_ENTER_EmptyExitHook();
    WORLDTRADE_ClearAndShowPlanes(p);
    WORLDTRADE_AdvanceScreenId(p);
    if (p->screenId == 0) {
        return 4;
    }
    return 0;
}

/*
 * Empty stub.
 */
void WORLDTRADE_ENTER_EmptyInitHook(WorldtradeWork *p)
{
}

void WORLDTRADE_ENTER_EmptyExitHook(void)
{
}

int WORLDTRADE_ENTER_SetState(WorldtradeWork *p)
{
    GFL_USE_CancelChangeAndPlayBgm(0x486, 0xFFFF);
    p->state = 1;
    p->speciesCleared = 1;
    p->titleEntered = 0;
    WORLDTRADE_SetStateAndReturn(p, 1, 0);
    return 2;
}

/*
 * Call DWC_NASLoginAsync and report success.
 */
int WORLDTRADE_ENTER_StateStartServerCheck(WorldtradeWork *p)
{
    DWC_NASLoginAsync();
    return 1;
}

/*
 * Extent remainder: 2-byte zero alignment padding.
 */
int WORLDTRADE_ENTER_StatePollServerCheck(WorldtradeWork *p) { switch(DWC_NASLoginProcess()) {case 3:return 1;case 0:case 4:case 5:return 2;default:return 0;} }

/*
 * extent: 0x021F8AF2..0x021F8AF4 is two zero alignment bytes.
 */
int WORLDTRADE_ENTER_InitDwcTrade(WorldtradeWork *p)
{
    void *handle;
    u32 id;
    u64 key;
    handle = WIFILIST_GetWork(p->ctx->wifiList);
    MYSTATUS_SetProfileIdOnce(p->ctx->myStatus, WIFILIST_GetGsProfileId(p->ctx->wifiList));
    id = MYSTATUS_GetProfileId(p->ctx->myStatus);
    key = DWC_CreateFriendKey(handle);
    DPW_TR_Init(id, (u32)key, (u32)(key >> 32), 0);
    return 1;
}

/*
 * Hand the object over, clear the +0xf8c slot and latch 1.
 */
int WORLDTRADE_ENTER_StateStartConnect(WorldtradeWork *p)
{
    DPW_TR_GetServerStateAsync();
    p->timer = 0;
    return 1;
}

/*
 * 18-slot switch on the 0x021C86A8 index (case value = index + 15, bound 17):
 * index 14 returns 1, and four separate case groups (15, 13+16, 0+3, 1+12)
 * each call WORLDTRADE_DeleteTimeIcon and archive n at +0x38 before returning 2; the
 * remaining indexes fall through to the shared tail (one more WORLDTRADE_DeleteTimeIcon)
 * and the function returns 0.  DPW_TR_Main() runs first, unconditionally.
 * Concrete bytes are identical to the image; the only wildcards are the two
 * BLX sites to 0x021C866C and 0x021C86A8, which carry no func_ label in any
 * overlay listing (match.py's `label` class needs exactly one listing to
 * carry the label, so no region hint can witness them).  One-line fix:
 * trace 0x021C866C / 0x021C86A8 in layout/function_starts.txt and this
 * promotes automatically.
 *
 * UNBLOCKED: DPW_TR_IsAsyncEnd(0x021C866C) and DPW_TR_GetAsyncResult
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int WORLDTRADE_ENTER_WaitServerCheck(WorldtradeWork *p)
{
    s32 asyncResult;

    DPW_TR_Main();
    if (DPW_TR_IsAsyncEnd() != 0) {
        asyncResult = DPW_TR_GetAsyncResult();
        p->timer = 0;
        switch (asyncResult + 15) {
        case 15:
            return 1;
        case 16:
            WORLDTRADE_DeleteTimeIcon(p);
            p->err = asyncResult;
            return 2;
        case 14:
        case 17:
            WORLDTRADE_DeleteTimeIcon(p);
            p->err = asyncResult;
            return 2;
        case 0:
        case 3:
            WORLDTRADE_DeleteTimeIcon(p);
            p->err = asyncResult;
            return 2;
        case 1:
        case 13:
            WORLDTRADE_DeleteTimeIcon(p);
            p->err = asyncResult;
            return 2;
        }
        WORLDTRADE_DeleteTimeIcon(p);
        WORLDTRADE_CancelSave(p);
    } else {
        if (++p->timer == 0xe10) {
            WORLDTRADE_CancelSave(p);
        }
    }
    return 0;
}

int WORLDTRADE_ENTER_SendProfile(WorldtradeWork *p) { NHTTP_RAP_InitTrainerInfo((struct _NHTTPRapTrainerInfo *)p->trInfo,p->ctx->myStatus);DPW_TR_SetProfileAsync((unsigned char *)p->trInfo,(unsigned char *)(&p->state_iF7C));p->timer=0;return 1; }

/*
 * note: 2026-10-05 wave P19: the sub switch exit (state 0, sub out of range) is a cross-jumped copy of the tail, `b 0x021F8CEC` in the image. Written as `WORLDTRADE_CancelSave(p); goto done;` after the sub switch, with `done: return 0;` at the end. EXACT in c99 and c (296 bytes). Idiom: a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy.
 */
int WORLDTRADE_ENTER_WaitProfileResult(WorldtradeWork *p)
{
    int code;

    DPW_TR_Main();
    if (DPW_TR_IsAsyncEnd() != 0) {
        code = DPW_TR_GetAsyncResult();
        p->wait = 0;
        switch (code) {
        case 0:
            switch (p->state_iF7C) {
            case 0:
                switch (p->sub_i) {
                case 0:
                    WORLDTRADE_SetStateAndReturn(p, 1, 0);
                    return 1;
                case 3:
                    p->err = -5003;
                    return 2;
                case 1:
                    p->err = -5000;
                    return 2;
                case 2:
                    p->err = -5001;
                    return 2;
                }
                WORLDTRADE_CancelSave(p);
                goto done;
            case 1:
                p->err = -5004;
                return 2;
            case 2:
                p->err = -5005;
                return 2;
            default:
                WORLDTRADE_DeleteTimeIcon(p);
                break;
            }
            break;
        case 1:
            WORLDTRADE_DeleteTimeIcon(p);
            p->err = code;
            return 2;
        case -1:
        case 2:
            WORLDTRADE_DeleteTimeIcon(p);
            p->err = code;
            return 2;
        case -15:
        case -12:
            WORLDTRADE_DeleteTimeIcon(p);
            p->err = code;
            return 2;
        case -14:
        case -2:
            WORLDTRADE_DeleteTimeIcon(p);
            p->err = code;
            return 2;
        default:
            WORLDTRADE_DeleteTimeIcon(p);
            break;
        }
        WORLDTRADE_CancelSave(p);
    } else if (++p->wait == 0xE10) {
        WORLDTRADE_CancelSave(p);
    }
done:
    return 0;
}

/*
 * lever: ov115 data hint is witnessed by this function loading ov115 via PROCSYS_Push; no hint remains MATCH.
 */
int WORLDTRADE_ENTER_PushWifiSetup(WorldtradeWork *p)
{
    NetSaveProcArgs *args;
    p->saveArgs = GFL_HEAP_Alloc(0x48, sizeof(NetSaveProcArgs), 0, str_02203C34, 0x263);
    MI_CpuFill8(p->saveArgs, 0, sizeof(NetSaveProcArgs));
    args = p->saveArgs;
    args->handle = GAMESYSTEM_GetGameData(p->ctx->gameData);
    args->mode = 0;
    args->enabled = 1;
    args->buf = p->netBuf;
    args->timeout = 30;
    args->callback = WORLDTRADE_ENTER_RunDialog;
    args->user = p;
    p->connectStep = 0;
    if ((u32)p->kind == 21) args->isTrade = 1;
    else args->isTrade = 0;
    PROCSYS_Push((ProcSys *)p->procSys, (uptr)ov115_id, (const ProcData *)gNetSaveMainProc, (void *)p->saveArgs);
    GFL_NET_ERR_ShowScreen(0);
    p->state = 3;
    return 2;
}

int WORLDTRADE_ENTER_StateWaitWifiSetup(WorldtradeWork *p)
{
    NetSaveProcArgs *args = p->saveArgs;
    if (p->busy_u == 0) {
        switch (args->result) {
        case 0: p->state = 0; break;
        case 1:
            WORLDTRADE_SetStateAndReturn(p, 0, 0);
            p->state = 1;
            break;
        }
        GFL_HEAP_Free((void *)p->req);
    }
    return 2;
}

int WORLDTRADE_ENTER_PushWifiError(WorldtradeWork *p)
{
    NetProcArgs *args;
    p->netArgs = GFL_HEAP_Alloc(72, sizeof(NetProcArgs), 0, str_02203C34, 689);
    MI_CpuFill8(p->netArgs, 0, sizeof(NetProcArgs));
    args = p->netArgs;
    args->save = GAMESYSTEM_GetGameData(p->ctx->gameData);
    args->zero = 0;
    args->enabled = 1;
    args->callback = WORLDTRADE_ENTER_StateAbortConnect;
    args->context = p;
    PROCSYS_Push((ProcSys *)p->procSys, (uptr)ov115_id, (const ProcData *)tbl_021D654C, (void *)p->netArgs);
    p->state_i = 5;
    GFL_NET_ERR_ShowScreen(0);
    return 2;
}

int WORLDTRADE_ENTER_StateWaitWifiError(WorldtradeWork *p)
{
    if (p->busy_u == 0) {
        GFL_HEAP_Free(p->req);
        WORLDTRADE_SetStateAndReturn(p, 0, 0);
        p->state = 1;
    }
    return 2;
}

int WORLDTRADE_ENTER_RunDialog(void *dialog, WorldtradeWork *p)
{
    int result;
    switch (p->connectStep) {
    case 0:
        if (WORLDTRADE_ENTER_StateStartServerCheck(p))
            p->connectStep++;
        break;
    case 1:
        result = WORLDTRADE_ENTER_StatePollServerCheck(p);
        switch (result) {
        case 1: p->connectStep++; break;
        case 2: p->connectStep = 9; break;
        }
        break;
    case 2:
        if (WORLDTRADE_ENTER_InitDwcTrade(p)) p->connectStep++;
        break;
    case 3:
        if (WORLDTRADE_ENTER_StateStartConnect(p)) p->connectStep++;
        break;
    case 4:
        result = WORLDTRADE_ENTER_WaitServerCheck(p);
        switch (result) {
        case 1: p->connectStep++; break;
        case 2: p->connectStep = 7; break;
        }
        break;
    case 5:
        if (WORLDTRADE_ENTER_SendProfile(p)) p->connectStep++;
        break;
    case 6:
        result = WORLDTRADE_ENTER_WaitProfileResult(p);
        switch (result) {
        case 1: p->connectStep = 0; return 0;
        case 2: p->connectStep = 7; break;
        }
        break;
    case 7:
        if (WORLDTRADE_ENTER_ShowErrorMessage(p, dialog)) p->connectStep++;
        break;
    case 8:
        if (WORLDTRADE_ENTER_ShutdownDwcStep(p, dialog)) p->connectStep++;
        break;
    case 9:
        p->connectStep = 0;
        return 1;
    }
    return 2;
}

/*
 * Every concrete byte is reproduced.  The one wildcard is the BLX at +0002 to
 * DPW_TR_End, which has no independent witness outside 021F8F5C..021F8F66;
 * the resolver reports "(arm, from name) ... 8 overlays overlap this address
 * (ov016, ov021, ov093, ov111, ov114, ov128, ov172, ov208), none resolvable
 * without a region hint on the symbols: line".  Same blocker as WORLDTRADE_SERVER_StateCheckAsyncEnd
 * and WORLDTRADE_SEARCH_StateStartWipeOutDisconnect/WORLDTRADE_SERVER_StateStartWipeOutDisconnect: naming one of those eight regions would be
 * a guess, so the site stays parked until the region that owns 0x021C8658 is
 * established.
 */
u32 WORLDTRADE_ENTER_StateAbortConnect(WorldtradeWork *p)
{
    DPW_TR_End();
    return 0;
}

/*
 * Reset the object, latch state 0 and set the +0xeb4 slot to 1.
 */
int WORLDTRADE_ENTER_StateExit(WorldtradeWork *p)
{
    WORLDTRADE_DeleteTimeIcon(p);
    p->state = 0;
    p->eb4 = 1;
    return 3;
}

int WORLDTRADE_ENTER_ShowErrorMessage(WorldtradeWork *p, void *dialog)
{
    int text;
    switch (p->err) {
    case 1: text = 166; break;
    case 2: text = 167; break;
    case -1: text = 157; break;
    case -2: text = 169; break;
    case -3: text = 162; break;
    case -4: text = 164; break;
    case -5: text = 163; break;
    case -6: text = 27; break;
    case -7: text = 28; break;
    case -8: text = 29; break;
    case -9: text = 30; break;
    case -10: text = 31; break;
    case -11: text = 32; break;
    case -12: text = 160; break;
    case -13: text = 165; break;
    case -14: text = 170; break;
    case -15: text = 161; break;
    default: text = 159; break;
    }
    WIFILOGIN_MSG_DrawWindow(dialog, p->bank, text);
    p->subStep = 0;
    return 1;
}

int WORLDTRADE_ENTER_ShutdownDwcStep(WorldtradeWork *p, void *dialog)
{
    switch (p->subStep) {
    case 0:
        (p->subStep)++;
        break;
    case 1:
        if (WIFILOGIN_MSG_IsPrintDone(dialog)) (p->subStep)++;
        break;
    case 2:
        (p->subStep)++;
        break;
    case 3:
        DPW_TR_End();
        DWC_ShutdownFriendsMatch();
        DWC_CleanupInet();
        (p->subStep)++;
        break;
    default:
        (p->stepTimer)++;
        if (p->stepTimer > 60) return 1;
        break;
    }
    return 0;
}
