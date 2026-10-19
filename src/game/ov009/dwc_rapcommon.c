/*
 * file:     dwc_rapcommon.c
 * unit:     yes
 * function: DWC_RAPCOMMON_InitDwcWithNotice, DWC_RAPCOMMON_CreateSubHeapUnlimited, DWC_RAPCOMMON_CreateSubHeap, DWC_RAPCOMMON_DestroySubHeap, DWC_RAPCOMMON_ReleaseSubHeap, DWC_RAPCOMMON_SetHeapTag, DWC_RAPCOMMON_Alloc, DWC_RAPCOMMON_Free, DWC_RAPCOMMON_CreateHeap, DWC_RAPCOMMON_DestroyHeap, DWC_RAPCOMMON_RunDwcInit, DWC_RAPCOMMON_InitUserData, DWC_RAPCOMMON_ClearNetError, DWC_RAPCOMMON_HandleNetError
 * address:  0x02156DFC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from dwc_rap.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_NET_STATE_SetError  0x0203C9AC  arm
 *   GFL_NET_STATE_GetError  0x0203CA98  arm
 *   GF_PANIC_Fail  0x02034714  arm
 *   DWC_ClearError 0x02059F18 arm
 *   DWC_ClearDirtyFlag  0x02059870  arm
 *   abs_id_11  0x00000011  data
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   ERROR_SCREEN_ShowAndWait  0x021B6100  thumb  ov017
 *   _pRapHeap  0x021A8268  data  ov009  a4
 *   _sAssertEmptyCommon  0x021A1C78  data  ov009  a1
 *   _sDwcRapCommonFile  0x021A1C7C  data  ov009  a1
 *   NNS_FndCreateExpHeapEx  0x02060C5C  arm
 *   NNSi_FndSetAllocModeBit  0x02060F18  arm
 *   NNSi_FndSetGroupId  0x02060F40  arm
 *   NNSi_FndDestroyExpHeap  0x02060C94  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   NNS_FndAllocFromExpHeapEx  0x02060CA0  arm
 *   GFL_NET_ERR_ExitAndHalt  0x0200FB6C  thumb
 *   NNSi_FndGetMBlockAttribute  0x02060F98  arm  arm9
 *   NNS_FndFreeToExpHeap  0x02060E30  arm
 *   _sDwcGameName  0x021A1C8C  data  ov009  a1
 *   DWC_InitForProduction  0x02059F6C  arm
 *   MIi_CpuClearFast    0x02082AC0  arm
 *   DWC_CheckUserData       0x02059718  arm
 *   DWC_CreateUserData  0x020596FC  arm
 *   GFL_NET_STATE_SetWifiError 0x0203CA04 arm
 *   GFL_NET_STATE_ClearErrorMode 0x0203C968 arm
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   GFL_NET_ERR_ShowSimpleScreen  0x0200F83C  thumb
 *   GFL_NET_ERR_ResetState  0x0200FBA0  thumb
 *   GFL_NET_ERR_RequestScreen  0x0200FB38  thumb
 *   GFL_NET_ERR_RaiseFatal  0x0200FB4C  thumb
 *   GFL_NET_ERR_HaltWithMessage  0x0200F7C0  thumb
 *   GFL_NET_ERR_RecordError  0x0200FAAC  thumb
 *   GFL_NET_STATE_WifiDisconnect  0x0203C554  arm
 */
#include "dwc_rap_types.h"
#include "dwc_rap_shared_types.h"

struct ExpHeap;

void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

u32 GFL_HEAP_Free(void *block);

void GFL_NET_STATE_SetError(int errorCode, u32 errorType, u32 dwcError, u32 gameCode);

u32 GFL_NET_STATE_GetError(void);

void GF_PANIC_Fail(const char *expr, u32 line, const char *file);

extern void DWC_ClearError(void);
struct DWCstAccUserData;

void DWC_ClearDirtyFlag(struct DWCstAccUserData *userdata);

extern int GF_OVERLAY_Load(signed int id);

extern void GF_OVERLAY_Unload(int id);

extern void ERROR_SCREEN_ShowAndWait(void);

extern void *NNS_FndCreateExpHeapEx(void *start, u32 size, u16 attr);

extern u32 NNSi_FndSetAllocModeBit(char *p, u32 v);

extern u16 NNSi_FndSetGroupId(char *p, u16 v);

extern void NNSi_FndDestroyExpHeap(void *heap);

extern void GFL_HEAP_DeleteChecked(u32 heap);

extern u32 OS_DisableInterrupts(void);

extern void OS_RestoreInterrupts(u32 h);

extern void *NNS_FndAllocFromExpHeapEx(struct ExpHeap *heap, u32 size, int align);

extern void GFL_NET_ERR_ExitAndHalt(void);

extern u8 NNSi_FndGetMBlockAttribute(char *p);

extern void NNS_FndFreeToExpHeap(struct ExpHeap *heap, void *block);

extern int DWC_InitForProduction(void *a, u32 b, void *c, void *d);

extern void MIi_CpuClearFast(unsigned int data, void *destp, unsigned int size);

extern int DWC_CheckUserData(struct DWCstAccUserData *userdata);

extern void DWC_CreateUserData(void *userdata);

extern void GFL_NET_STATE_SetWifiError(void);

extern void GFL_NET_STATE_ClearErrorMode(void);

extern int GFL_NET_GetRunState(void);

extern u32 GFL_NET_ERR_GetErrorLevel(void);

extern void GFL_NET_ERR_ShowSimpleScreen(void);

extern void GFL_NET_ERR_ResetState(void);

extern void GFL_NET_ERR_RequestScreen(void);

extern void GFL_NET_ERR_RaiseFatal(unsigned int x);

extern void GFL_NET_ERR_HaltWithMessage(u32 value);

extern void GFL_NET_ERR_RecordError(void);

extern void GFL_NET_STATE_WifiDisconnect(u32 a);

void DWC_RAPCOMMON_InitDwcWithNotice(int heapId);

void DWC_RAPCOMMON_CreateSubHeapUnlimited(int ownerId, int size, int heapId);

void DWC_RAPCOMMON_CreateSubHeap(u32 ownerId, u32 size, u32 minRequestSize, u32 heapId);

void DWC_RAPCOMMON_DestroySubHeap(void);

void DWC_RAPCOMMON_ReleaseSubHeap(void);

void DWC_RAPCOMMON_SetHeapTag(int tag);

u32 DWC_RAPCOMMON_Alloc(u32 ownerId, u32 size, u32 align);

void DWC_RAPCOMMON_Free(u32 ownerId, void *block, int unused);

void DWC_RAPCOMMON_CreateHeap(u32 heapId, u32 size);

void DWC_RAPCOMMON_DestroyHeap(void);

int DWC_RAPCOMMON_RunDwcInit(u16 heapId);

void DWC_RAPCOMMON_InitUserData(void *userData);

void DWC_RAPCOMMON_ClearNetError(void);

int DWC_RAPCOMMON_HandleNetError(int hasSession, int keepError);

extern unsigned char abs_id_11[];

extern DwcRapHeap *_pRapHeap;

extern char _sAssertEmptyCommon[];

extern char _sDwcRapCommonFile[];

extern char _sDwcGameName[];

/*
 * Initialises the DWC library; when it reports that other settings were
 * destroyed (result 3) the notice screen of overlay 17 runs (the pooled 0x11
 * is the overlay id).
 */
void DWC_RAPCOMMON_InitDwcWithNotice(int heapId)
{
    if (DWC_RAPCOMMON_RunDwcInit(heapId) == 3) {
        GF_OVERLAY_Load((int)abs_id_11);
        ERROR_SCREEN_ShowAndWait();
        GF_OVERLAY_Unload((int)abs_id_11);
    }
}

/*
 * Calls DWC_RAPCOMMON_CreateSubHeap with a zero third argument.
 */
void DWC_RAPCOMMON_CreateSubHeapUnlimited(int ownerId, int size, int heapId)
{
    DWC_RAPCOMMON_CreateSubHeap(ownerId, size, 0, heapId);
}

/*
 * Creates the secondary expanded heap that serves allocations of one owner id
 * (ownerId) above minRequestSize; the heap is tagged 0xEA so that the free
 * function can tell its blocks from the main heap blocks.
 */
void DWC_RAPCOMMON_CreateSubHeap(u32 ownerId, u32 size, u32 minRequestSize, u32 heapId)
{
    if (_pRapHeap == 0) {
        GF_PANIC_Fail(_sAssertEmptyCommon, 0, _sAssertEmptyCommon);
    }
    if (_pRapHeap->subMem != 0) {
        GF_PANIC_Fail(_sAssertEmptyCommon, 0, _sAssertEmptyCommon);
    }
    if (_pRapHeap->subHeap != 0) {
        GF_PANIC_Fail(_sAssertEmptyCommon, 0, _sAssertEmptyCommon);
    }
    _pRapHeap->subMem = (u32)GFL_HEAP_Alloc(heapId, size - 0x80, 0, _sDwcRapCommonFile, 0x62);
    _pRapHeap->subHeap = (u32)NNS_FndCreateExpHeapEx((void *)((_pRapHeap->subMem + 0x1f) & ~0x1f), size - 0xc0, 0);
    _pRapHeap->subOwnerId = ownerId;
    NNSi_FndSetAllocModeBit((char *)_pRapHeap->subHeap, 1);
    NNSi_FndSetGroupId((char *)_pRapHeap->subHeap, 0xea);
    _pRapHeap->subMinRequest = minRequestSize;
}

void DWC_RAPCOMMON_DestroySubHeap(void)
{
    if (_pRapHeap == 0) {
        GF_PANIC_Fail(_sAssertEmptyCommon, 0, _sAssertEmptyCommon);
    }
    if (_pRapHeap->subLiveBlocks != 0) {
        GFL_NET_STATE_SetError(0, 0, 0, DWC_RAP_RESULT_FATAL);
        _pRapHeap->allocFailed = 1;
        return;
    }
    DWC_RAPCOMMON_ReleaseSubHeap();
}

void DWC_RAPCOMMON_ReleaseSubHeap(void)
{
    if (_pRapHeap->subMem != 0) {
        NNSi_FndDestroyExpHeap((void *)_pRapHeap->subHeap);
        GFL_HEAP_Free((void *)_pRapHeap->subMem);
        _pRapHeap->subHeap = 0;
        _pRapHeap->subMem = 0;
        if (_pRapHeap->tag != 0) {
            GFL_HEAP_DeleteChecked(_pRapHeap->tag);
            _pRapHeap->tag = 0;
        }
    }
}

/*
 * Setter after the function ending at pool 0x02156F4C, which stores to the
 * same halfword: writes its argument to +0x20 of the object _pRapHeap
 * points to. Called from the ov175 root WIFIBATTLEMATCH_NET_CompStepF (0x021D85E0).
 */
void DWC_RAPCOMMON_SetHeapTag(int tag)
{
    _pRapHeap->tag = tag;
}

u32 DWC_RAPCOMMON_Alloc(u32 ownerId, u32 size, u32 align)
{
    u32 irqState;
    u32 block;

    if (_pRapHeap->subHeap != 0 && ownerId == _pRapHeap->subOwnerId && size > _pRapHeap->subMinRequest) {
        irqState = OS_DisableInterrupts();
        block = (u32)NNS_FndAllocFromExpHeapEx((struct ExpHeap *)_pRapHeap->subHeap, size, align);
        OS_RestoreInterrupts(irqState);
        _pRapHeap->subLiveBlocks++;
    } else {
        irqState = OS_DisableInterrupts();
        block = (u32)NNS_FndAllocFromExpHeapEx((struct ExpHeap *)_pRapHeap->mainHeap, size, align);
        OS_RestoreInterrupts(irqState);
    }
    if (block == 0) {
        GFL_NET_ERR_ExitAndHalt();
        GFL_NET_STATE_SetError(0, 0, 0, DWC_RAP_RESULT_FATAL);
        return 0;
    }
    return block;
}

/*
 * witness:  callee 0x02060F98 is witnessed by its ARM9 entry
 *           (src/matched/arm9/NNSi_FndGetMBlockAttribute.c, pkt_02060F98).
 */
void DWC_RAPCOMMON_Free(u32 ownerId, void *block, int unused)
{
    u32 irqState;

    if (block == 0) {
        return;
    }
    if (NNSi_FndGetMBlockAttribute(block) == 0xEA) {
        if (_pRapHeap->subHeap != 0) {
            irqState = OS_DisableInterrupts();
            NNS_FndFreeToExpHeap((struct ExpHeap *)_pRapHeap->subHeap, block);
            OS_RestoreInterrupts(irqState);
            _pRapHeap->subLiveBlocks--;
            return;
        }
        GFL_NET_STATE_SetError(0, 0, 0, DWC_RAP_RESULT_FATAL);
        return;
    }
    irqState = OS_DisableInterrupts();
    NNS_FndFreeToExpHeap((struct ExpHeap *)_pRapHeap->mainHeap, block);
    OS_RestoreInterrupts(irqState);
}

void DWC_RAPCOMMON_CreateHeap(u32 heapId, u32 size)
{
    if (_pRapHeap != 0) {
        GF_PANIC_Fail(_sAssertEmptyCommon, 0, _sAssertEmptyCommon);
    }
    _pRapHeap = (DwcRapHeap *)GFL_HEAP_Alloc(0, 0x24, 1, _sDwcRapCommonFile, 0x14C);
    _pRapHeap->mainMem = (u32)GFL_HEAP_Alloc(heapId, size - 0x80, 0, _sDwcRapCommonFile, 0x14D);
    _pRapHeap->mainHeap = (u32)NNS_FndCreateExpHeapEx((void *)((_pRapHeap->mainMem + 0x1f) & ~0x1f), size - 0xc0, 0);
    _pRapHeap->tag = 0;
}

void DWC_RAPCOMMON_DestroyHeap(void)
{
    if (_pRapHeap == 0) {
        GF_PANIC_Fail(_sAssertEmptyCommon, 0, _sAssertEmptyCommon);
    }
    if (_pRapHeap->allocFailed == 1 || _pRapHeap->subMem != 0) {
        DWC_RAPCOMMON_ReleaseSubHeap();
    }
    NNSi_FndDestroyExpHeap((void *)_pRapHeap->mainHeap);
    GFL_HEAP_Free((void *)_pRapHeap->mainMem);
    GFL_HEAP_Free(_pRapHeap);
    _pRapHeap = 0;
}

int DWC_RAPCOMMON_RunDwcInit(u16 heapId)
{
    int initResult;
    DWC_RAPCOMMON_CreateHeap(heapId, 0x40000);
    initResult = DWC_InitForProduction(_sDwcGameName, 0x4952414A, DWC_RAPCOMMON_Alloc, DWC_RAPCOMMON_Free);
    DWC_RAPCOMMON_DestroyHeap();
    return initResult;
}

/*
 * Clears the 0x40-byte DWC account user-data block, then rebuilds it when
 * the check at DWC_CheckUserData (CRC validation) fails: DWC_CreateUserData,
 * then the veneer at 0x02059870 into DWCi_Acc_ClearDirty (DWCi_Acc_ClearDirty).
 * Called from arm9 WIFILIST_Init (bl at 0x0200982C), the save-table
 * constructor at 0x0209DB98.
 */
void DWC_RAPCOMMON_InitUserData(void *userData)
{
    MIi_CpuClearFast(0, userData, 0x40);
    if (DWC_CheckUserData(userData) == 0) {
        DWC_CreateUserData(userData);
        DWC_ClearDirtyFlag((struct DWCstAccUserData *)userData);
    }
}

void DWC_RAPCOMMON_ClearNetError(void)
{
    GFL_NET_STATE_SetWifiError();
    GFL_NET_STATE_ClearErrorMode();
    DWC_ClearError();
}

/*
 * Decides what the error screen does after a network error: returns 0 for
 * nothing, 1 reset and show the connection lost screen, 2 show the message,
 * 3 show the special message, 4 reset and return to the title.
 */
int DWC_RAPCOMMON_HandleNetError(int hasSession, int keepError)
{
    NetErrorInfo *errorInfo;
    int gameCode;

    if (GFL_NET_GetRunState() != 0) {
        errorInfo = (NetErrorInfo *)GFL_NET_STATE_GetError();
        if (GFL_NET_ERR_GetErrorLevel() != 0) {
            switch (errorInfo->errorType) {
            case 0:
                break;
            case 1:
            case 2:
                if (hasSession == 0) {
                    DWC_RAPCOMMON_ClearNetError();
                    GFL_NET_ERR_ShowSimpleScreen();
                    GFL_NET_ERR_ResetState();
                    return 1;
                }
                DWC_ClearError();
            case 3:
            case 4:
            case 5:
                GFL_NET_ERR_RequestScreen();
                GFL_NET_ERR_RaiseFatal(13);
                return 2;
            case 6:
                GFL_NET_ERR_RequestScreen();
                return 2;
            case 7:
                GFL_NET_ERR_HaltWithMessage(15);
                return 3;
            }
        }
        gameCode = errorInfo->gameCode;
        if (gameCode == DWC_RAP_RESULT_TIMEOUT_ERROR || gameCode == DWC_RAP_RESULT_DISCONNECT_ERROR) {
            if (keepError != 0) {
                GFL_NET_ERR_RecordError();
                DWC_RAPCOMMON_ClearNetError();
                GFL_NET_STATE_WifiDisconnect(1);
                GFL_NET_ERR_ShowSimpleScreen();
                GFL_NET_ERR_ResetState();
                return 4;
            }
            GFL_NET_STATE_SetWifiError();
            GFL_NET_ERR_ResetState();
            GFL_NET_STATE_ClearErrorMode();
            GFL_NET_STATE_WifiDisconnect(1);
            return 0;
        }
        if (gameCode == 0x3F2 || gameCode == 0x3F3 || gameCode == 0x3F4 || gameCode == 0x3F6) {
            if (hasSession == 0) {
                DWC_RAPCOMMON_ClearNetError();
                GFL_NET_ERR_ShowSimpleScreen();
                GFL_NET_ERR_ResetState();
                return 1;
            }
            GFL_NET_ERR_RequestScreen();
            GFL_NET_ERR_RaiseFatal(13);
            return 2;
        }
        if (gameCode == DWC_RAP_RESULT_FATAL || gameCode == 0x3F7) {
            GFL_NET_ERR_RequestScreen();
            GFL_NET_ERR_RaiseFatal(13);
            return 2;
        }
    }
    return 0;
}
