/*
 * file:     pdwacc_state.c
 * unit:     yes
 * function: PDWACC_STATE_HandleHttpError, PDWACC_STATE_SetState, PDWACC_STATE_ChangeState, PDWACC_STATE_StateWaitFade, PDWACC_STATE_StateFadeOutBgm, PDWACC_STATE_StateWaitInputStream, PDWACC_STATE_StateSaveMainWait, PDWACC_STATE_StateSaveStart, PDWACC_STATE_StateRestartTimeIcon, PDWACC_STATE_StateWaitInputClearWindow, PDWACC_STATE_StateWaitInputPrintNumbers, PDWACC_STATE_StatePrintNumbersMessage, PDWACC_STATE_StateWaitInput, PDWACC_STATE_StatePrintError, PDWACC_STATE_StateWaitStreamThenSendRequest, PDWACC_STATE_StateTimeIconMessage, PDWACC_STATE_StateConfirmMenuSelect, PDWACC_STATE_StateOpenConfirmMenu, PDWACC_STATE_StatePrintIntroMessage, PDWACC_STATE_StateReceiveResponse, PDWACC_STATE_StateSendRequest, PDWACC_STATE_StateWaitFadeClearNumbers, PDWACC_STATE_StatePrintResultMessage, PDWACC_STATE_DestroyHttpConnection, PDWACC_STATE_ProcInit, PDWACC_STATE_ProcMain, PDWACC_STATE_ProcExit
 * address:  0x021D9FD4
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pdwacc_disp.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   KEY_GetTrg  0x020362DC  arm
 *   GAME_DATA_SaveCancel  0x02012E08  thumb
 *   NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   NHTTP_RAP_GetResultCode 0x021B99DC thumb ov114
 *   NHTTP_RAP_PollConnection 0x021B9790 thumb ov114
 *   NHTTP_RAP_GetRecvBuffer 0x021B97F4 thumb ov114
 *   NHTTP_RAP_CreateRequest 0x021B95D4 thumb ov114
 *   NHTTP_RAP_GetConnection 0x021B973C thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   NHTTP_AddPostDataRaw 0x021BE79C arm ov114
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BLOCK20_SAVEDATA_SetPending 0x020092E0 thumb
 *   SAVE_CONTROL_GetWorkArea 0x020071D8 thumb
 *   NHTTP_RAP_Destroy  0x021B9838  thumb  ov114
 *   ov114_id 0x00000072 data
 *   NHTTP_RAP_Create 0x021B9800 thumb ov114
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GAME_SYNC_GetBlock 0x02009448 thumb
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb  arm9
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb  arm9
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb  arm9
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb  arm9
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb  arm9
 *   PDWACC_MESSAGE_InitSystem 0x021D92CC thumb ov123
 *   PDWACC_MESSAGE_UpdateSystem 0x021D9404 thumb ov123
 *   PDWACC_MESSAGE_ExitSystem 0x021D941C thumb ov123
 *   PDWACC_MESSAGE_PrintStream 0x021D9514 thumb ov123
 *   PDWACC_MESSAGE_RestartTimeIcon 0x021D95B4 thumb ov123
 *   PDWACC_MESSAGE_UpdateStream 0x021D95F0 thumb ov123
 *   PDWACC_MESSAGE_ClearStream 0x021D9634 thumb ov123
 *   PDWACC_MESSAGE_OpenYesNoMenu 0x021D9670 thumb ov123
 *   PDWACC_MESSAGE_PrintInWindow 0x021D9730 thumb ov123
 *   PDWACC_MESSAGE_ClearWindow 0x021D97B0 thumb ov123
 *   PDWACC_MESSAGE_PrintNumberWindows 0x021D9844 thumb ov123
 *   PDWACC_MESSAGE_DeleteNumberWindows 0x021D9918 thumb ov123
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 *   MYSTATUS_GetProfileId  0x0200853C  thumb  arm9
 *   PDWACC_DISP_Init 0x021D9958 thumb ov123
 *   PDWACC_DISP_Draw 0x021D9A14 thumb ov123
 *   PDWACC_DISP_Exit 0x021D9A1C thumb ov123
 */
#include "pdwacc_disp_types.h"

#include "../arm9/wipe.h"

#include "../arm9/net.h"
struct TaskMenuWork;

#include "../arm9/app_taskmenu.h"



#include "../arm9/gfl_heap_wrap.h"

struct GameData;

#include "../arm9/game_data.h"

struct SaveControl;

struct Proc;

#include "../arm9/procsys.h"

#include "../version.h"
#include "../arm9/mi_memory.h"
#if LANGUAGE == LANGUAGE_JAPANESE
#include "../arm9/std_sprintf.h"
extern const char str_ja_021DAAD8[];
#endif




#include "../arm9/gf_overlay.h"


#include "../arm9/key.h"

struct _NHTTPRapSession;

#include "../ov114/nhttp_rap.h"

#include "../arm9/gfl_use.h"
struct GameSyncData;

#include "../arm9/game_sync.h"




struct _NHTTPConnection;



#include "../ov114/d_nhttp.h"
struct CgearSaveBlock;

#include "../arm9/block20_savedata.h"
struct MyStatus;


#include "../arm9/mystatus.h"

#include "../arm9/save_control.h"



#include "../ov009/dwc_rap.h"

#include "../arm9/net_err.h"

#include "../ov009/dwc_rapcommon.h"


#include "pdwacc_message.h"












#include "pdwacc_disp.h"



int PDWACC_STATE_HandleHttpError(PdwaccProc *proc, int httpStatus);

void PDWACC_STATE_SetState(PdwaccProc *proc, PdwaccStateFunc state, int line);

void PDWACC_STATE_ChangeState(PdwaccProc *proc, PdwaccStateFunc state, int line);

void PDWACC_STATE_StateWaitFade(PdwaccProc *proc);

void PDWACC_STATE_StateFadeOutBgm(PdwaccProc *proc);

void PDWACC_STATE_StateWaitInputStream(PdwaccProc *proc);

void PDWACC_STATE_StateSaveMainWait(PdwaccProc *proc);

void PDWACC_STATE_StateSaveStart(PdwaccProc *proc);

void PDWACC_STATE_StateRestartTimeIcon(PdwaccProc *proc);

void PDWACC_STATE_StateWaitInputClearWindow(PdwaccProc *proc);

void PDWACC_STATE_StateWaitInputPrintNumbers(PdwaccProc *proc);

void PDWACC_STATE_StatePrintNumbersMessage(PdwaccProc *proc);

void PDWACC_STATE_StateWaitInput(PdwaccProc *proc);

void PDWACC_STATE_StatePrintError(PdwaccProc *proc);

void PDWACC_STATE_StateWaitStreamThenSendRequest(PdwaccProc *proc);

void PDWACC_STATE_StateTimeIconMessage(PdwaccProc *proc);

void PDWACC_STATE_StateConfirmMenuSelect(PdwaccProc *proc);

void PDWACC_STATE_StateOpenConfirmMenu(PdwaccProc *proc);

void PDWACC_STATE_StatePrintIntroMessage(PdwaccProc *proc);

void PDWACC_STATE_StateReceiveResponse(PdwaccProc *proc);

void PDWACC_STATE_StateSendRequest(PdwaccProc *proc);

void PDWACC_STATE_StateWaitFadeClearNumbers(PdwaccProc *proc);

void PDWACC_STATE_StatePrintResultMessage(PdwaccProc *proc);

void PDWACC_STATE_DestroyHttpConnection(void *arg, u32 errorCode, u32 errorType, int dwcError);

int PDWACC_STATE_ProcInit(void *procSys, int unused, PdwaccProcParam *param);

int PDWACC_STATE_ProcMain(int unused0, int unused1, PdwaccProcParam *param, PdwaccProc *proc);

int PDWACC_STATE_ProcExit(void *procHandle, int unused0, int unused1, PdwaccProc *proc);

extern char ov114_id[];

/*
 * extent: lead with store-and-return follower 021DA030 and tailcall follower 021DA034.
 */
int PDWACC_STATE_HandleHttpError(PdwaccProc *proc, int resultCode)
{
    switch (resultCode) {
    case 503:
        proc->errorCode=0xfff1;
        PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StatePrintError,0x99);
        return 1;
    case 502:
        proc->errorCode=0xfff2;
        PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StatePrintError,0x9d);
        return 1;
    default:
        if (resultCode>=400) {
            proc->errorCode=0xfff3;
            PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StatePrintError,0xa3);
            return 1;
        }
        return 0;
    }
}

void PDWACC_STATE_SetState(PdwaccProc *proc, PdwaccStateFunc state, int line)
{
    proc->state=state;
}

void PDWACC_STATE_ChangeState(PdwaccProc *proc, PdwaccStateFunc state, int line)
{
    PDWACC_STATE_SetState(proc,state,line);
}

void PDWACC_STATE_StateWaitFade(PdwaccProc *proc)
{
    if (WIPE_SYS_EndCheck() != 0)
        PDWACC_STATE_ChangeState(proc, 0, 0xd5);
}

void PDWACC_STATE_StateFadeOutBgm(PdwaccProc *proc) { WIPE_SYS_Start(0,0,0,0x7fff,6,1,proc->heap); GFL_USE_FadeOutBgm(6); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateWaitFade,0xe7); }

void PDWACC_STATE_StateWaitInputStream(PdwaccProc *proc) { if(PDWACC_MESSAGE_UpdateStream(proc->message) && KEY_GetTrg()!=0) PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateFadeOutBgm,0xf1); }

/*
 * lever: Unsigned result-minus-two range test emits subs/cmp/bhi.
 */
void PDWACC_STATE_StateSaveMainWait(PdwaccProc *proc) { if((unsigned int)(GAME_DATA_SaveMain(proc->gameData)-2)<=1) { proc->saving=0; PDWACC_MESSAGE_PrintStream(proc->message,11); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateWaitInputStream,0xfe); } }

void PDWACC_STATE_StateSaveStart(PdwaccProc *proc) { if(PDWACC_MESSAGE_UpdateStream(proc->message)) { proc->saving=1; GAME_DATA_SaveStart(proc->gameData); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateSaveMainWait,0x109); } }

void PDWACC_STATE_StateRestartTimeIcon(PdwaccProc *proc) { PDWACC_MESSAGE_PrintStream(proc->message,6); PDWACC_MESSAGE_RestartTimeIcon(proc->message); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateSaveStart,0x112); }

void PDWACC_STATE_StateWaitInputClearWindow(PdwaccProc *proc) { if(KEY_GetTrg()) { PDWACC_MESSAGE_ClearWindow(proc->message); BLOCK20_SAVEDATA_SetPending((struct CgearSaveBlock *)GAME_SYNC_GetBlock(proc->saveControl),1); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateRestartTimeIcon,0x11a); } }

void PDWACC_STATE_StateWaitInputPrintNumbers(PdwaccProc *proc) { if(KEY_GetTrg()) { PDWACC_MESSAGE_PrintNumberWindows(proc->message,proc->profileId,proc->profileId); PDWACC_MESSAGE_PrintInWindow(proc->message,9); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateWaitInputClearWindow,0x12a); } }

void PDWACC_STATE_StatePrintNumbersMessage(PdwaccProc *proc) { PDWACC_MESSAGE_PrintNumberWindows(proc->message,proc->profileId,proc->profileId); PDWACC_MESSAGE_PrintInWindow(proc->message,8); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateWaitInputPrintNumbers,0x13c); }

void PDWACC_STATE_StateWaitInput(PdwaccProc *proc) { if(KEY_GetTrg() & 3) PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateFadeOutBgm,0x14b); }

void PDWACC_STATE_StatePrintError(PdwaccProc *proc)
{
    unsigned messageId;
    messageId = proc->errorCode + 11;
    if (proc->connection) NHTTP_RAP_DeleteConnection(proc->connection);
    if (proc->errorCode == 0xfff1) messageId = 22;
    else if (proc->errorCode == 0xfff2) messageId = 23;
    else if (proc->errorCode == 0xfff3) messageId = 20;
    else if (proc->errorCode >= 10) messageId = 20;
    PDWACC_MESSAGE_PrintInWindow(proc->message,messageId);
    PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateWaitInput,0x167);
}

void PDWACC_STATE_StateWaitStreamThenSendRequest(PdwaccProc *proc) { if(PDWACC_MESSAGE_UpdateStream(proc->message)) PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateSendRequest,0x172); }

void PDWACC_STATE_StateTimeIconMessage(PdwaccProc *proc) { PDWACC_MESSAGE_PrintStream(proc->message,3); PDWACC_MESSAGE_RestartTimeIcon(proc->message); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateWaitStreamThenSendRequest,0x17b); }

void PDWACC_STATE_StateConfirmMenuSelect(PdwaccProc *proc)
{
    if (APP_TASKMENU_IsFinish(proc->yesNoMenu)) {
        if (!APP_TASKMENU_GetCursorPos(proc->yesNoMenu))
            PDWACC_STATE_ChangeState(proc, PDWACC_STATE_StateTimeIconMessage, 0x18d);
        else
            PDWACC_STATE_ChangeState(proc, PDWACC_STATE_StateFadeOutBgm, 0x190);
        PDWACC_MESSAGE_ClearStream(proc->message);
        APP_TASKMENU_CloseMenu(proc->yesNoMenu);
        proc->yesNoMenu = 0;
    }
}

void PDWACC_STATE_StateOpenConfirmMenu(PdwaccProc *proc) { if(PDWACC_MESSAGE_UpdateStream(proc->message)) { proc->yesNoMenu=PDWACC_MESSAGE_OpenYesNoMenu(proc->message,0); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateConfirmMenuSelect,0x1a6); } }

void PDWACC_STATE_StatePrintIntroMessage(PdwaccProc *proc) { PDWACC_MESSAGE_PrintStream(proc->message,2); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateOpenConfirmMenu,0x1b7); }

void PDWACC_STATE_StateReceiveResponse(PdwaccProc *proc)
{
    int *response;
    if (GFL_NET_GetRunState() && !PDWACC_STATE_HandleHttpError(proc,NHTTP_RAP_GetResultCode(proc->connection)) && !NHTTP_RAP_PollConnection(proc->connection)) {
        response = (int *)(char *)NHTTP_RAP_GetRecvBuffer((struct _NHTTPRapSession *)(proc->connection));
        PDWACC_MESSAGE_ClearStream(proc->message);
        if (*response == 2) { PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StatePrintNumbersMessage,0x1d4); return; }
        if (*response == 0) { PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StatePrintNumbersMessage,0x1d7); return; }
        proc->errorCode = *response;
        PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StatePrintError,0x1db);
    }
}

/*
 *   in scratch blocker071d8-r1.log, 12 bytes. the integrator owns filing it.
 *   extern unsigned BACKUP_SYSTEM_GetWork(void *, unsigned *);
 * evidence: 0x021B973C ov114 Thumb leaf now has S23's verified EXACT
 *   pkt_ov114_021B973C shard; no caller retry because ARM9 still blocks it.
 */
#if LANGUAGE == LANGUAGE_JAPANESE
void PDWACC_STATE_StateSendRequest(PdwaccProc *proc)
{
    u32 profileId;
    if (GFL_NET_GetRunState()) {
        if (NHTTP_RAP_CreateRequest(4,proc->connection)) {
            profileId = proc->profileId;
            MI_CpuFill8(proc->postData,0,0x1e);
            STD_TSNPrintf((char *)proc->postData,0x1e,str_ja_021DAAD8,profileId);
            NHTTP_AddPostDataRaw((void *)NHTTP_RAP_GetConnection(proc->connection),(void *)proc->postData,0xc);
            if (!NHTTP_RAP_StartConnection(proc->connection)) {
                PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateReceiveResponse,0x1f8);
                return;
            }
        }
    } else if (KEY_GetTrg()) {
        PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateReceiveResponse,0x1fe);
    }
}
#else
void PDWACC_STATE_StateSendRequest(PdwaccProc *proc)
{
    int workAreaSize;
    void *workArea;
    if (GFL_NET_GetRunState()) {
        if (NHTTP_RAP_CreateRequest(9,proc->connection)) {
            workArea = SAVE_CONTROL_GetWorkArea(proc->saveControl,(u32 *)(&workAreaSize));
            NHTTP_AddPostDataRaw((void *)NHTTP_RAP_GetConnection(proc->connection),workArea,0x80000);
            if (!NHTTP_RAP_StartConnection(proc->connection)) {
                PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateReceiveResponse,0x1f6);
                return;
            }
        }
    } else if (KEY_GetTrg()) {
        PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateReceiveResponse,0x1fc);
    }
}
#endif

void PDWACC_STATE_StateWaitFadeClearNumbers(PdwaccProc *proc) { if(WIPE_SYS_EndCheck() && KEY_GetTrg()) { PDWACC_MESSAGE_DeleteNumberWindows(proc->message); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateFadeOutBgm,PM_SRC_LINE(0x22c, 0x216)); } }

void PDWACC_STATE_StatePrintResultMessage(PdwaccProc *proc) { PDWACC_MESSAGE_PrintNumberWindows(proc->message,proc->profileId,proc->profileId); PDWACC_MESSAGE_PrintInWindow(proc->message,7); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateWaitFadeClearNumbers,PM_SRC_LINE(0x23c, 0x226)); }

void PDWACC_STATE_DestroyHttpConnection(void *arg, u32 errorCode, u32 errorType, int dwcError) { PdwaccProc *proc = arg; if(proc->connection) { NHTTP_RAP_DeleteConnection(proc->connection); NHTTP_RAP_Destroy(proc->connection); proc->connection=0; } }

/*
 * interface: 0203159C retains the allocator result in r0; caller consumes that return.
 */
int PDWACC_STATE_ProcInit(void *procSys,int unused,PdwaccProcParam *param)
{
    PdwaccProc *proc;
    GF_OVERLAY_Load((sptr)ov114_id);
    proc=(PdwaccProc *) PROCSYS_AllocProcWork(procSys,sizeof(PdwaccProc),param->heap);
    MI_CpuFill8(proc,0,sizeof(PdwaccProc));
    proc->heap=param->heap;
    proc->saveControl=GAME_DATA_GetSaveControl(param->gameData);
    proc->gameData=param->gameData;
    proc->profileId=MYSTATUS_GetProfileId((struct MyStatus *)GAME_DATA_GetMyStatus(param->gameData));
    if(GFL_NET_GetRunState()) {
        proc->connection=NHTTP_RAP_Create(param->heap,proc->profileId,(char *)param->connectionArg);
        DWC_RAP_SetErrorCallback(PDWACC_STATE_DestroyHttpConnection, proc);
    }
    proc->disp=PDWACC_DISP_Init(proc->heap);
    proc->message=PDWACC_MESSAGE_InitSystem(proc->heap,87);
    WIPE_SYS_Start(0,1,1,0,6,1,proc->heap);
    GFL_USE_CancelChangeAndPlayBgm(0x483,0xffff);
    switch(param->startMode) {
    case 0: PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StatePrintIntroMessage,PM_SRC_LINE(0x276, 0x260)); break;
    case 1: PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StatePrintResultMessage,PM_SRC_LINE(0x279, 0x263)); break;
    }
    param->finished=0;
    return 1;
}

int PDWACC_STATE_ProcMain(int unused0,int unused1,PdwaccProcParam *param,PdwaccProc *proc)
{
    PdwaccStateFunc state;
    int result;
    state = proc->state;
    result = 1;
    if (state) {
        if (!GFL_NET_ERR_GetErrorLevel()) state(proc);
        result = 0;
    }
    if (proc->yesNoMenu) APP_TASKMENU_UpdateMenu(proc->yesNoMenu);
    PDWACC_DISP_Draw(proc->disp);
    PDWACC_MESSAGE_UpdateSystem(proc->message);
    if (WIPE_SYS_EndCheck()) {
        if (GFL_NET_ERR_GetErrorLevel()) {
            NHTTP_RAP_DeleteConnection(proc->connection);
            if (proc->saving) {
                GAME_DATA_SaveCancel(proc->gameData);
                proc->saving = 0;
            }
            WIPE_SetBrightnessFadeOut(0,0);
            WIPE_SetBrightnessFadeOut(1,0);
            result = 1;
            DWC_RAPCOMMON_HandleNetError(1,0);
            param->finished = 1;
        }
    } else if (GFL_NET_ERR_GetErrorLevel()) result = 1;
    return result;
}

int PDWACC_STATE_ProcExit(void *procHandle, int unused0, int unused1, PdwaccProc *proc)
{
    if (proc->yesNoMenu)
        APP_TASKMENU_CloseMenu(proc->yesNoMenu);
    PDWACC_MESSAGE_ExitSystem(proc->message);
    PDWACC_DISP_Exit(proc->disp);
    if (proc->unusedAlloc04)
        GFL_HEAP_Free(proc->unusedAlloc04);
    if (proc->unusedAlloc24)
        GFL_HEAP_Free(proc->unusedAlloc24);
    if (proc->connection) {
        NHTTP_RAP_Destroy(proc->connection);
        proc->connection = 0;
    }
    if (GFL_NET_GetRunState())
        DWC_RAP_SetErrorCallback(0, 0);
    PROCSYS_FreeProcWork(procHandle);
    GF_OVERLAY_Unload((sptr)ov114_id);
    return 1;
}
