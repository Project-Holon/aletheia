/*
 * file:     wih_dwc.c
 * unit:     yes
 * function: GFL_NET_ERR_GetMessageId, GFL_NET_ERR_DrawWindow, WIH_DWC_PollSystem, WIH_DWC_Create, WIH_DWC_Delete, WIH_DWC_PauseTimers, WIH_DWC_ResumeTimers, WIH_DWC_AddBeacon, WIH_DWC_TickTimers, WIH_DWC_IsSsidInFilterList, WIH_DWC_IsOpenTaggedBeacon, WIH_DWC_IsPrivacyBeacon, WIH_DWC_PollStatus, WIH_DWC_CreateFilterBuffer, WIH_DWC_ResetFilterState, WIH_DWC_FindSlotByKey, WIH_DWC_GetAlertLevel, WIH_DWC_RequestAlertLevel, WIH_DWC_Dummy, GFL_NET_SAVE_SetStep, GFL_NET_SAVE_Create, GFL_NET_SAVE_CreateWithCallback, GFL_NET_SAVE_CheckFinished, GFL_NET_SAVE_Delete, GFL_NET_SAVE_StepBegin, GFL_NET_SAVE_StepWaitSaveStart, GFL_NET_SAVE_StepWaitSync72, GFL_NET_SAVE_StepDelay, GFL_NET_SAVE_StepWaitSync73, GFL_NET_SAVE_StepProgress, GFL_NET_SAVE_StepFinish, GFL_NET_SAVE_InitWork, GFL_NET_SAVE_Main
 * address:  0x02010158
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * wih_dwc.c: the wireless/DWC helper unit, with net_err.c's error window in
 * front and net_save.c's save task at the end.  The wih_dwc state is one
 * global (gWihDwc): the 0x328-byte context object and a 0xA00-byte buffer.
 *
 * symbols:
 *   func_0202EB0C  0x0202EB0C  thumb
 *   gNetErrWork     0x0214617C  data
 *   sNetErrMessageIdsDS   0x0209DEB0  data  a2
 *   sNetErrMessageIdsTwl   0x0209DED0  data  a2
 *   G2_GetBG1ScrPtr   0x0207DFB4  arm
 *   G2_GetBG1CharPtr  0x0207E24C  arm
 *   MIi_CpuClear16    0x02082A48  arm
 *   BMP_CreateFromVram     0x02043754  arm
 *   GF_FONT_Create_EC64     0x0201EC64  thumb
 *   GF_FONT_Create     0x0201D7EC  thumb
 *   func_02045B38     0x02045B38  arm
 *   WORDSET_SetSlotNumber     0x0201EFA4  thumb
 *   func_02045EC0     0x02045EC0  arm
 *   STRBUF_Create     0x020457B0  arm
 *   WORDSET_CopyTaggedText     0x0201F250  thumb
 *   PRINTSYS_PrintColor     0x0201C7D0  thumb
 *   STRBUF_Delete     0x02045808  arm
 *   MSGDATA_Delete     0x02045C04  arm
 *   GF_FONT_Delete     0x0201D83C  thumb
 *   WORDSET_DeleteStrbufED04     0x0201ED04  thumb
 *   BMP_Delete     0x020437AC  arm
 *   gWihDwc     0x021461E0  data
 *   sWihDwcAssertArg        0x020A7240  data
 *   sWihDwcFile    0x020A7244  data
 *   func_02034714  0x02034714  arm
 *   GFL_NET_AllocAligned  0x0203D7C8  arm
 *   DWC_GetParseWMBssDescWorkSize  0x0205D010  arm
 *   func_02034AC4  0x02034AC4  arm
 *   WIH_SetBeaconFoundCallback  0x0217963C  thumb  ov014
 *   ov015_id       0x0000000F  data
 *   GFL_NET_FreeAligned  0x0203D7FC  arm
 *   func_02034A5C  0x02034A5C  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   GF_STANDARD_GetStringLength  0x0203F004  arm
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_GetScanResult  0x0203CF10  arm
 *   DWC_ParseWMBssDesc  0x0205D01C  arm
 *   NET_WHPIPE_GetEntryKind  0x02178098  thumb  ov014
 *   func_0205FAA8  0x0205FAA8  arm
 *   GFL_NET_GetRunState     0x0203CD98  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   NET_WHPIPE_GetEntryBeaconKind     0x02177B80  thumb  ov014
 *   sub_0202E8D8      0x0202E8D8  thumb
 *   sNetSaveFile       0x020A725C  data
 *   sWihBeaconSsidTag        0x020A7250  data
 *   func_02030734     0x02030734  arm
 *   GFL_NET_HANDLE_GetCurrentHandle     0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange     0x02039C68  arm
 *   func_020307B0     0x020307B0  arm
 *   func_0200FB24     0x0200FB24  thumb
 *   GAME_DATA_SaveCancel     0x02012E08  thumb
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   sub_020124F4   0x020124F4  thumb
 *   sub_02012EBC   0x02012EBC  thumb
 *   GAME_SYNC_GetBlock   0x02009448  thumb
 *   BLOCK20_SAVEDATA_GetPending   0x020092EC  thumb
 *   ov115_id       0x00000073  data  a1
 *   ov123_id       0x0000007B  data  a1
 *   gNetSaveMainProc     0x021D6338  data  ov115
 *   gNetSaveCheckProc     0x021DA9A8  data  ov123
 *   gNetSaveRetryProc     0x021D654C  data  ov115
 *   PROCSYS_PushGlobal  0x020312CC  arm
 *   GFL_NET_ERR_ShowScreen  0x0200F7B8  thumb
 *   GFL_USE_PollPowerExit  0x020053EC  thumb
 *   GFL_USE_UpdateSound  0x02005BC0  thumb
 *   PM_VOICE_StopFinished  0x020065FC  thumb
 *   GAME_DATA_SaveStart  0x02012DAC  thumb
 *   GAME_DATA_SaveMain  0x02012DD0  thumb
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
typedef signed short   s16;

struct Bmp;
struct GfFont;
struct MsgBank;
struct Strbuf;
struct U16Vec;
struct WordSet;
struct LinkHandle;
struct Link;
struct BmpWindow;
struct SaveControl;
struct GameSyncData;

/* net_err.c module state at 0x0214617C (only the fields used here) */
struct NetErrInfo {
    u32 errorCode;
    u32 errorType;
    u32 errorParam;
    u32 reasonCode;     /* 0x3EE..0x3F7 are mapped to message ids */
};

struct NetErrWork {
    u8 unused00[0x48];
    struct NetErrInfo errorInfo;    /* +0x48 */
    u8 netErrorFlag;
    u8 netType;
    u8 fatalRaised;
    u8 pad5B[5];
    u32 messageId;
};

/* One 0xC0-byte beacon record (a WMBssDesc) that the ov014 receive callback queues */
struct WihBssDesc {
    u8 bssid[6];
    u16 length;
    u16 rssi;
    u16 ssidLength;
    u8 ssid[0x20];      /* +0x0C */
    u16 capaInfo;       /* +0x2C, bit 0x10 is the privacy flag */
    u8 rest[0x92];
};

/* the 0xA00-byte buffer behind the global's second word */
struct WihFilterBuf {
    u8 scanWork[0x600];
    u8 filterState[0x40];
    u8 ssidSlot[3][0x100];  /* +0x640 */
    u8 pad940[0xC0];
};

/* the 0x328-byte context object WIH_DWC_Create allocates */
struct WihContext {
    struct WihBssDesc beacon[4];
    void *matchWork;                    /* +0x300 */
    struct WihFilterBuf *filterBuf;     /* +0x304 */
    u8 pad308[4];
    u16 paused;                         /* +0x30C, nonzero stops the timers */
    u16 alertCooldown;                  /* +0x30E */
    u16 maxBeacons;                     /* +0x310 */
    u16 alertLevel;                     /* +0x312 */
    u16 pendingAlertLevel;              /* +0x314 */
    u16 beaconCount;                    /* +0x316 */
    s32 knownGameTimer;                 /* +0x318 */
    s32 taggedGameTimer;                /* +0x31C */
    s32 openNetworkTimer;               /* +0x320 */
    s32 securedNetworkTimer;            /* +0x324 */
};

/* the global at 0x021461E0 */
struct WihGlobals {
    struct WihContext *context;
    struct WihFilterBuf *filterBuf;
};

struct WihSsidInfo {
    int kind;          /* +0x00 */
    u8  rest[0x3C];    /* +0x04 */
};

/* the connection state block GFL_NET_GetInitParam returns (fields used here) */
struct GFLNetInitializeStruct {
    u8 unused00[0x62];
    u8 slotCount;
    u8 unused63[4];
    u8 connectState;
};

/* the 0x14-byte net_save.c task object */
struct NetSaveTask {
    void (*progressCallback)(u32 arg);
    u32 callbackArg;
    void (*step)(struct NetSaveTask *task);
    u32 gameData;
    s32 delayFrames;
};

struct NetSaveScreenArgs {
    void *gameData;
    u32 mode;
    u32 enable;
    u32 waitFrames;
    void *saveBuf;
};

struct NetSaveCheckArgs {
    void *gameData;
    void *saveBuf;
    u16 heapId;
    u8 pad[2];
};

struct NetSaveRetryArgs {
    void *gameData;
    u32 mode;
    u32 enable;
};

/* the 0x1D8-byte net_save.c save task record */
struct NetSaveProcWork {
    struct NetSaveScreenArgs screenArgs;    /* +0x00 */
    u32 retryRequested;                     /* +0x14 */
    u8 pad18[4];
    u32 cancelled;                          /* +0x1C */
    u8 pad20[8];
    struct NetSaveRetryArgs retryArgs;      /* +0x28 */
    u8 pad34[0x10];
    void *gameData;                         /* +0x44 */
    struct NetSaveCheckArgs checkArgs;      /* +0x48 */
    u32 skipFinalSave;                      /* +0x54 */
    u32 saveFailed;                         /* +0x58 */
    u8 saveBuf[0x174];                      /* +0x5C */
    u16 heapId;                             /* +0x1D0 */
    u8 pad1D2[2];
    u32 state;                              /* +0x1D4 */
};

extern u32 func_0202EB0C(void);
extern u16 *G2_GetBG1ScrPtr(void);
extern u8  *G2_GetBG1CharPtr(void);
extern void MIi_CpuClear16(u16 data, void *dst, u32 size);
extern struct Bmp *BMP_CreateFromVram(void *pixels, u32 width, u32 height, u32 depth, u16 heapId);
extern struct WordSet *GF_FONT_Create_EC64(u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void WORDSET_SetSlotNumber(struct WordSet *wordSet, u32 index, u32 number, u32 digits, u32 padding, u32 flags);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_CopyTaggedText(struct WordSet *wordSet, void *dst, void *src);
extern void PRINTSYS_PrintColor(void *bmp, s16 x, s16 y, void *text, void *font, u16 color);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct MsgBank *bank);
extern u32 GF_FONT_Delete(void *font);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *wordSet);
extern void BMP_Delete(struct Bmp *bmp);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *GFL_NET_AllocAligned(u32 heapId, u32 size, const char *file, u16 line);
extern u32  DWC_GetParseWMBssDescWorkSize(void);
extern int func_02034AC4(int id);
extern void WIH_SetBeaconFoundCallback(u32 callback);
extern void GFL_NET_FreeAligned(void *p);
extern void func_02034A5C(int handle);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern u32 GF_STANDARD_GetStringLength(const u8 *s);
extern s32 GF_STANDARD_CompareBytes(const void *a, const void *b, u32 n);
extern void *GFL_NET_GetInitParam(void);
extern int  GFL_NET_GetNegotiationNum(void);
extern u32 GFL_NET_GetScanResult(u32 slot);
extern u8   NET_WHPIPE_GetEntryKind(u8 slot);
extern int  DWC_ParseWMBssDesc(void *work, struct WihBssDesc *beacon, struct WihSsidInfo *out);
extern void func_0205FAA8(u8 *filterState, u32 value);
extern int  GFL_NET_GetRunState(void);
extern void OS_GetMacAddress(u8 *mac);
extern u8 NET_WHPIPE_GetEntryBeaconKind(int slot);
extern int sub_0202E8D8(char *record, int key, char *mac);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern struct Link *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *link, u32 timingId, u32 size);
extern u32 func_020307B0(void *task);
extern u32  func_0200FB24(void);
extern void GAME_DATA_SaveCancel(u32 gameData);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *link, u32 timingId, u32 size);
extern int GAME_DATA_SaveStart(u32 gameData);
extern int  GAME_DATA_SaveMain(u32 gameData);
extern u32  func_020056EC(u32 frames);
extern void  GFL_HEAP_CreateChildHeap(u32 a, u32 heapId, u32 size);
extern void *PROCSYS_AllocProcWork(void *proc, u32 size, u32 heapId);
extern void  MI_CpuFill8(void *dst, int val, unsigned n);
extern void *sub_020124F4(u16 heapId);
extern struct SaveControl *sub_02012EBC(void *gameData);
extern struct GameSyncData *GAME_SYNC_GetBlock(struct SaveControl *saveControl);
extern u8 BLOCK20_SAVEDATA_GetPending(const struct GameSyncData *data);
extern void PROCSYS_PushGlobal(u32 overlayId, const void *procData, void *arg);
extern u32 GFL_NET_ERR_ShowScreen(u32 mode);
extern int GFL_USE_PollPowerExit(void);
extern int func_02034F5C(int a);
extern int GFL_USE_UpdateSound(int a);
extern int PM_VOICE_StopFinished(int a);

u32 GFL_NET_ERR_GetMessageId(struct NetErrInfo *info, u32 a);
void GFL_NET_ERR_DrawWindow(u32 messageVariant, u32 useGenericMessage);
int WIH_DWC_PollSystem(void);
struct WihContext *WIH_DWC_Create(int maxBeacons, void *heap);
void WIH_DWC_Delete(struct WihContext *context);
void WIH_DWC_PauseTimers(void);
void WIH_DWC_ResumeTimers(void);
void WIH_DWC_AddBeacon(const void *beacon);
void WIH_DWC_TickTimers(void);
int WIH_DWC_IsSsidInFilterList(struct WihBssDesc *beacon);
int WIH_DWC_IsOpenTaggedBeacon(const struct WihBssDesc *beacon);
u32 WIH_DWC_IsPrivacyBeacon(const struct WihBssDesc *beacon);
u32 WIH_DWC_PollStatus(void *searchKey);
void WIH_DWC_CreateFilterBuffer(u32 heapId);
void WIH_DWC_ResetFilterState(void);
int WIH_DWC_FindSlotByKey(void *searchKey);
u16 WIH_DWC_GetAlertLevel(void);
void WIH_DWC_RequestAlertLevel(u32 level);
void WIH_DWC_Dummy(void);
void GFL_NET_SAVE_SetStep(struct NetSaveTask *task, void (*step)(struct NetSaveTask *task));
struct NetSaveTask *GFL_NET_SAVE_Create(u32 heapId, u32 gameData);
struct NetSaveTask *GFL_NET_SAVE_CreateWithCallback(u32 heapId, u32 gameData, void (*callback)(u32 arg), u32 callbackArg);
u32 GFL_NET_SAVE_CheckFinished(struct NetSaveTask *task);
void GFL_NET_SAVE_Delete(struct NetSaveTask *task);
void GFL_NET_SAVE_StepBegin(struct NetSaveTask *task);
void GFL_NET_SAVE_StepWaitSaveStart(struct NetSaveTask *task);
void GFL_NET_SAVE_StepWaitSync72(struct NetSaveTask *task);
void GFL_NET_SAVE_StepDelay(struct NetSaveTask *task);
void GFL_NET_SAVE_StepWaitSync73(struct NetSaveTask *task);
void GFL_NET_SAVE_StepProgress(struct NetSaveTask *task);
void GFL_NET_SAVE_StepFinish(struct NetSaveTask *task);
int GFL_NET_SAVE_InitWork(void *proc);
int GFL_NET_SAVE_Main(u32 proc, u32 seq, u32 parentWork, struct NetSaveProcWork *work);
extern struct NetErrWork gNetErrWork;
extern const u16 sNetErrMessageIdsDS[];
extern const u16 sNetErrMessageIdsTwl[];
extern struct WihGlobals gWihDwc;
extern u8 sWihDwcAssertArg;
extern u8 sWihDwcFile[];
extern u8 ov015_id[];
extern u8 sNetSaveFile;
extern u8 sWihBeaconSsidTag[];
extern u8 ov115_id[];
extern u8 ov123_id[];
extern u8 gNetSaveMainProc[];
extern u8 gNetSaveCheckProc[];
extern u8 gNetSaveRetryProc[];


/*
 * net_err.c's error-code mapper: the reason code of the module's error block
 * (0x3EE..0x3F7) maps to a fixed message id; anything else indexes one of two
 * sixteen-entry u16 tables by the module's +0x60 error number, picked by
 * func_0202EB0C().  The case 0x3F7 arm shares case 0x3EE's block.
 */
/*
 * The error-code mapper of net_err.c: a reason code at obj+0xc (obj is the
 * 16-byte block the module keeps at 0x0214617C+0x48) in 0x3EE..0x3F7 maps to
 * a fixed message id; anything else indexes one of two sixteen-entry u16
 * tables by the module's +0x60 error number, picked by func_0202EB0C().
 * Wave 13: the earlier DIFF note read the pools as 0x0202617C / 0x020109B0 /
 * 0x020109D0; the words are 0x0214617C / 0x0209DEB0 / 0x0209DED0, and the
 * case 0x3F7 arm shares case 0x3EE's block (both table slots 0x12).
 */
u32 GFL_NET_ERR_GetMessageId(struct NetErrInfo *info, u32 a)
{
    u32 errorNumber;

    switch (info->reasonCode) {
    case 0x3ee:
    case 0x3f7:
        return 0xd;
    case 0x3f1:
        return 0x28;
    case 0x3f2:
    case 0x3f3:
    case 0x3f4:
    case 0x3f5:
    case 0x3f6:
        return 0xe;
    case 0x3f0:
        return 0x28;
    }
    if (func_0202EB0C() != 0) {
        errorNumber = gNetErrWork.messageId;
        if (errorNumber >= 0x10) {
            return 0xb;
        }
        return sNetErrMessageIdsTwl[errorNumber];
    }
    errorNumber = gNetErrWork.messageId;
    if (errorNumber >= 0x10) {
        return 0xb;
    }
    return sNetErrMessageIdsDS[errorNumber];
}


/*
 * Draws net_err.c's error window: tiles BG1's screen with a running
 * character index, clears the character block to 0x7777, builds a surface,
 * a window object and a palette, picks the message (0x40 for a1 == 1; the
 * mapped error code from GFL_NET_ERR_GetMessageId or the stored +0x60 code in link
 * modes 1/2/6; else message 1, or 0 unless a0 == 1), prints it and frees
 * everything.  The non-link arm's message index is the same variable as the
 * constant 1 its two calls pass (idx = 1 kept unless a0 != 1).
 */
void GFL_NET_ERR_DrawWindow(u32 messageVariant, u32 useGenericMessage)
{
    struct NetErrWork *errWork = &gNetErrWork;
    u16 *screen;
    struct Bmp *bmp;
    struct WordSet *wordSet;
    s32 tileX;
    struct MsgBank *msgBank;
    u32 messageIndex;
    void *message;
    struct U16Vec *textBuf;
    s32 tileY;
    struct GfFont *font;
    u16 *bg1ScrPtr;
    u16 tileIndex;

    bg1ScrPtr = G2_GetBG1ScrPtr();
    screen = bg1ScrPtr;
    tileIndex = 0x20;
    for (tileY = 4; tileY < 0x14; tileY++) {
        for (tileX = 1; tileX < 0x1f; tileX++) {
            screen[tileY * 0x20 + tileX] = tileIndex;
            tileIndex = (u16)(tileIndex + 1);
        }
    }
    MIi_CpuClear16(0x7777, G2_GetBG1CharPtr() + 0x400, 0x3c00);
    bmp = BMP_CreateFromVram(G2_GetBG1CharPtr() + 0x400, 0x1e, 0x10, 0x20, 1);
    wordSet = GF_FONT_Create_EC64(1);
    font = GF_FONT_Create(0x17, 0, 0, 0, 1);

    if (useGenericMessage == 1) {
        msgBank = func_02045B38(0, 2, 0xe8, 1);
        messageIndex = 0x40;
    } else {
        u8 netType = errWork->netType;

        if (netType == 1 || netType == 2 || netType == 6) {
            WORDSET_SetSlotNumber(wordSet, 0, errWork->errorInfo.errorCode, 5, 2, 1);
            msgBank = func_02045B38(0, 2, 0xe8, 1);
            if (errWork->fatalRaised != 0) {
                messageIndex = errWork->messageId;
                errWork->fatalRaised = 0;
            } else {
                messageIndex = GFL_NET_ERR_GetMessageId(&errWork->errorInfo, errWork->messageId);
            }
        } else {
            WORDSET_SetSlotNumber(wordSet, 0, errWork->netErrorFlag, 5, 2, 1);
            msgBank = func_02045B38(0, 2, 0x52, 1);
            messageIndex = 1;
            if (messageVariant != 1) {
                messageIndex = 0;
            }
        }
    }

    message = func_02045EC0(msgBank, messageIndex);
    textBuf = STRBUF_Create(0x189, 1);
    WORDSET_CopyTaggedText(wordSet, textBuf, message);
    PRINTSYS_PrintColor(bmp, 0, 0, textBuf, font, 0x1167);
    STRBUF_Delete(textBuf);
    STRBUF_Delete(message);
    MSGDATA_Delete(msgBank);
    GF_FONT_Delete(font);
    WORDSET_DeleteStrbufED04(wordSet);
    BMP_Delete(bmp);
}


int WIH_DWC_PollSystem(void)
{
    int t0 = GFL_USE_PollPowerExit();
    int t1 = func_02034F5C(t0);
    int t2 = GFL_USE_UpdateSound(t1);
    int t3 = PM_VOICE_StopFinished(t2);

    return t3;
}


/*
 * wih_dwc.c constructor: allocates the 0x328-byte object (line 0x49), stores
 * the index at +0x310, allocates a second buffer sized by DWC_GetParseWMBssDescWorkSize
 * (line 0x4C) into +0x300, registers WIH_DWC_AddBeacon as the ov014 receive
 * callback, publishes the object in the global and copies the global's
 * second word into +0x304.  WIH_DWC_Delete is its destructor.
 */
/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * note:     rewritten 2026-09-23 (wave 14): every concrete byte right, 11 of
 *           12 relocation sites resolved.
 *
 *           Thumb leaf in ov014 (wih.c): 0x0217963C decodes as
 *           `ldr r1,[pc,#8]; ldr r2,[r1]; ldr r1,[pc,#8]; str r0,[r2,r1];
 *           bx lr`, a setter of word +0x1E88 of the object behind 0x021797A8
 *           (the same shape as the labelled WIH_SetConnectCallback just before it,
 *           which sets +0x1E84).  asm/overlays/ov014.s prints it as .word
 *           data, so attest_overlay_label() has no label to accept.  SEED
 *           REQUEST for the integrator: `ov014 0x0217963C thumb`, evidence
 *           the bl at arm9 0x020103B6 (this function) and 0x020103FE
 *           (WIH_DWC_Delete).  Once seeded, 0x020103FE is an outside witness
 *           for this file and 0x020103B6 for WIH_DWC_Delete: both go EXACT
 *           with no C change.
 *
 * wih_dwc.c constructor: allocates the 0x328-byte object (line 0x49), stores
 * the index at +0x310, allocates a second buffer sized by DWC_GetParseWMBssDescWorkSize
 * (line 0x4C) into +0x300, registers WIH_DWC_AddBeacon as the ov014 receive
 * callback, publishes the object in the global and copies the global's
 * second word into +0x304.  WIH_DWC_Delete is its destructor.
 * Two readings corrected from the previous file: the pool word is
 * 0x021461E0 (not 0x020461E0), and 0x0201045D is the Thumb address of
 * WIH_DWC_AddBeacon, a function pointer, not data.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/WIH_DWC_Create.c \
 *       --func WIH_DWC_Create --addr 0x02010360 --thumb
 */
struct WihContext *WIH_DWC_Create(int maxBeacons, void *heap)
{
    struct WihContext *context;

    if (maxBeacons > 4) {
        func_02034714((const char *)(&sWihDwcAssertArg), 0, (const char *)(&sWihDwcAssertArg));
    }
    if (gWihDwc.context != 0) {
        func_02034714((const char *)(&sWihDwcAssertArg), 0, (const char *)(&sWihDwcAssertArg));
    }
    context = GFL_NET_AllocAligned((u32)heap, 0x328, (const char *)sWihDwcFile, 0x49);
    context->maxBeacons = maxBeacons;
    context->matchWork = GFL_NET_AllocAligned((u32)heap, DWC_GetParseWMBssDescWorkSize(), (const char *)sWihDwcFile, 0x4C);
    WIH_SetBeaconFoundCallback((u32)WIH_DWC_AddBeacon);
    gWihDwc.context = context;
    context->filterBuf = gWihDwc.filterBuf;
    func_02034AC4((int)ov015_id);
    return context;
}


/*
 * wih_dwc.c teardown, the counterpart of WIH_DWC_Create.  WIH_SetBeaconFoundCallback is an
 * unlabelled ov014 Thumb setter.
 */
/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 *           address in overlay space: two overlays overlap it (ov009, ov014)
 *           and NEITHER carries a func_ label there (ov009 decodes it as
 *           `moveq r0, #1` in the middle of a function, ov014 has the data
 *           word 0x680A4902).  attest_overlay_label() needs part 1 of the
 *           rule, a label in the overlay's own listing, so the site has no
 *           witness outside this range and no cut can give it one: the only
 *           branch to 0x0217963C in the image is the pair at 0x020103B6 and
 *           0x020103FE, and both are inside this packet.  `matched` cannot
 *           reach it either (0x0217963C is not matched).
 *           2026-09-23 (wave 14): 0x0217963C is an unlabelled ov014 Thumb
 *           setter (`ldr r1,[pc,#8]; ldr r2,[r1]; ldr r1,[pc,#8]; str r0,
 *           [r2,r1]; bx lr`), printed as .word data.  SEED REQUEST: `ov014
 *           0x0217963C thumb`; the two bl sites then witness each other and
 *           this file and WIH_DWC_Create go EXACT unchanged.
 *
 * "wih_dwc.c" teardown, the counterpart of func_02010360 (same packet):
 * both guard on the same pointer at 0x021461E0 being null before running
 * the 0x020A7240-argument call, both take the same (p, 0, p) argument
 * triple, and both end by clearing that pointer again.  The pool word is
 * the address of the four zero bytes immediately before the "wih_dwc.c"
 * string at 0x020A7244 - the file anchor the packet reports.
 *
 * The last call's argument arrives from a pool word holding 0x0000000F, not
 * from a `movs`, so it is a symbol rather than an integer: see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.  The
 * pool words on either side of this function (0x020103E0 and 0x02010428)
 * both hold 0x0F, and func_02034AC4 - the sibling entry point in
 * src/pending/unit_0200BA58.c - takes the same kind of value, so this is
 * the same linker-defined id, spelled ov015_id here.  It is `literal`-
 * attested by 0x020103E0, which is outside this function's range.
 *
 * The call at 0x0217963C is a branch into overlay space (it is why the
 * listing prints it as .inst.w "outside this region").  Its argument is a
 * literal zero, and that same zero is what the store at +0x30 writes: mwcc
 * materialises it once, keeps it in r4 across both GFL_NET_FreeAligned calls and
 * stores it, which is the `movs r4, #0` beside the `movs r0, #0`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/WIH_DWC_Delete.c \
 *       --func WIH_DWC_Delete --addr 0x020103E4 --cc 1.1p1 --thumb
 *   MATCH, 72 bytes, 7 relocation sites, 6 resolved, 1 wildcard:
 *     +001A THM_CALL WIH_SetBeaconFoundCallback - unresolved, no outside witness.
 */
void WIH_DWC_Delete(struct WihContext *context)
{
    if (gWihDwc.context == 0) {
        func_02034714((const char *)(&sWihDwcAssertArg), 0, (const char *)(&sWihDwcAssertArg));
    }
    WIH_SetBeaconFoundCallback(0);
    GFL_NET_FreeAligned(context->matchWork);
    GFL_NET_FreeAligned(context);
    gWihDwc.context = 0;
    func_02034A5C((int)ov015_id);
}


/*
 * Two mirror-image functions: set and clear the flag halfword at +0x30C of
 * the context object.
 */
/*
 * Two mirror-image four-word functions: set and clear one flag halfword of
 * entry 0xC3 in a table reached through the pointer variable at 0x0214617C's
 * neighbour, 0x021461E0.  0x021461E0 is a plain literal pool word (the same
 * address is loaded by nine other functions in this file's neighbourhood, at
 * 0x020103D4, 0x02010420 and so on), so it needed no relocation resolution,
 * the same situation documented in src/matched/GFL_NET_ERR_RestoreBrightness.c for 0x0214617C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201042C.c \
 *       --addr 0x0201042C --thumb
 */
void WIH_DWC_PauseTimers(void)
{
    struct WihContext *context = gWihDwc.context;

    if (context != 0) {
        context->paused = 1;
    }
}


void WIH_DWC_ResumeTimers(void)
{
    struct WihContext *context = gWihDwc.context;

    if (context != 0) {
        context->paused = 0;
    }
}


/*
 * wih_dwc.c: append one 0xC0-byte record to the four-slot table at the head
 * of the context object, guarded on the capacity at +0x310 and the fill
 * index at +0x316.  WIH_DWC_Create hands this function's address to the ov014
 * setter, so it is a receive callback.  MI_CpuCopy8 takes three arguments.
 */
void WIH_DWC_AddBeacon(const void *beacon)
{
    struct WihContext *context = gWihDwc.context;

    if (context->maxBeacons != 0 && context->beaconCount < context->maxBeacons && context->beaconCount < 4) {
        MI_CpuCopy8(beacon, &context->beacon[context->beaconCount], 0xC0);
        gWihDwc.context->beaconCount = gWihDwc.context->beaconCount + 1;
    }
}


/*
 * Per-frame countdown of the four timers at +0x318..+0x324 (the real
 * prologue is at 0x02010498).
 */
/*
 *           function_starts.txt line 337 seeds this leaf at 0x0201049C (4 bytes
 *           too high); the real prologue and byte-exact fit are at 0x02010498,
 *           per docs/notes/unit_0201045C.c.txt.
 * blocked:  +005C ABS32 gWihDwc : unresolved: no address for 'gWihDwc':
 *           not in the symbols: block, not an address-bearing name, not in
 *           layout/symbols_sdk.json
 */
void WIH_DWC_TickTimers(void)
{
    struct WihContext *context = gWihDwc.context;

    if (context != 0 && context->paused != 0)
        return;
    if (context == 0)
        return;
    if (context->knownGameTimer > 0)
        context->knownGameTimer = context->knownGameTimer - 1;
    context = gWihDwc.context;
    if (context->taggedGameTimer > 0)
        context->taggedGameTimer = context->taggedGameTimer - 1;
    context = gWihDwc.context;
    if (context->openNetworkTimer > 0)
        context->openNetworkTimer = context->openNetworkTimer - 1;
    context = gWihDwc.context;
    if (context->securedNetworkTimer > 0)
        context->securedNetworkTimer = context->securedNetworkTimer - 1;
}


/*
 * Three 0x100-byte slots at +0x640 of the buffer behind the context's +0x304;
 * the first slot with a positive GF_STANDARD_GetStringLength whose GF_STANDARD_CompareBytes against
 * the record's name returns zero makes the function return 1.  GF_STANDARD_CompareBytes
 * takes THREE arguments, the third is the result of GF_STANDARD_GetStringLength (kept in
 * r2).  `i` must be initialised before `q`, and the loop-body local `n` must
 * be declared inside the loop.
 */
/*
 * Three 0x100-byte slots at +0x640 of the object hanging off +0x304 of the
 * global at 0x021461E0 (the same global WIH_DWC_AddBeacon reads); the first slot
 * with a positive GF_STANDARD_GetStringLength whose GF_STANDARD_CompareBytes against obj+0xC returns
 * zero makes the function return 1.
 *
 * Three spellings the previous pass (docs/notes/pkt_0201045C.c.txt) did not
 * have, and each is needed:
 *
 *  1. the pool word is 0x021461E0, not 0x020461E0, and it holds a POINTER,
 *     not the object: the original does one `ldr r1, [r7]` and then
 *     `ldr r1, [r1, r0]` with r0 = 0x304.  Reading it as `**` costs an extra
 *     dereference at both sites.  It is the same global WIH_DWC_AddBeacon reads.
 *  2. GF_STANDARD_CompareBytes takes THREE arguments, and the third is the result of
 *     GF_STANDARD_GetStringLength.  That is what the otherwise pointless `adds r2, r0, #0`
 *     at 0x02010518 is: r2 is set right after the first call and is still
 *     live, unwritten, at the `blx` to GF_STANDARD_CompareBytes twenty-four bytes
 *     later.  Two arguments plus a named local for the comparison folds the
 *     copy away (80 bytes); a function-scope or volatile local gives it a
 *     stack home (`str r0, [sp]` / `ldr r0, [sp]`) instead of r2.  The local
 *     must be declared inside the loop body.
 *     docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-arity.md
 *  3. `i` must be initialised before `q`: the original opens
 *     `movs r4, #0` then `adds r6, #0xc`, and writing the loop as a plain
 *     `for (i = 0; ...)` after `u8 *q = obj + 0xC;` emits those two the
 *     other way round.  That swap is the last two bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIH_DWC_IsSsidInFilterList.c \
 *       --func WIH_DWC_IsSsidInFilterList --addr 0x020104F8 --cc 1.1p1 --thumb
 */
int WIH_DWC_IsSsidInFilterList(struct WihBssDesc *beacon)
{
    int slotIndex = 0;
    u8 *ssid = beacon->ssid;

    for (; slotIndex < 3; slotIndex++) {
        u8 *slot = gWihDwc.context->filterBuf->ssidSlot[slotIndex];
        int slotLength = GF_STANDARD_GetStringLength(slot);

        if (slotLength > 0) {
            slot = gWihDwc.context->filterBuf->ssidSlot[slotIndex];
            if (GF_STANDARD_CompareBytes(slot, ssid, slotLength) == 0)
                return 1;
        }
    }
    return 0;
}


/*
 * Three gates on one record then `return 1`; all false paths share the single
 * `return 0` at the bottom.  The compare is against the 8 bytes at
 * 0x020A7250, GF_STANDARD_CompareBytes is a memcmp-shaped helper whose zero means equal.
 */
/*
 * Three gates on one object then `return 1`.  All three false paths share the
 * single `return 0` at the bottom, which is what puts the `bne`/`beq` on the
 * shared epilogue instead of inlining two `movs r0, #0`: the source is a nest
 * of three `if`s with one `return 1` inside and one `return 0` after them.
 * The compare is against the 8 bytes at 0x020A7250, a cast address constant
 * (no relocation), and `GF_STANDARD_CompareBytes` is a memcmp-shaped helper whose zero
 * means equal.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIH_DWC_IsOpenTaggedBeacon.c \
 *       --func WIH_DWC_IsOpenTaggedBeacon --addr 0x0201054C --cc 1.1p1 --thumb
 */
int WIH_DWC_IsOpenTaggedBeacon(const struct WihBssDesc *beacon)
{
    if (beacon->ssidLength == 8) {
        if (GF_STANDARD_CompareBytes(sWihBeaconSsidTag, beacon->ssid, 8) != 0) {
            if ((beacon->capaInfo & 0x10) == 0) {
                return 1;
            }
        }
    }
    return 0;
}


/*
 * A boolean test of bit 0x10 of the halfword at +0x2C of a record.
 */
/*
 * Sixteen bytes: a boolean test of bit 0x10 of a halfword field at +0x2C of
 * its argument.  The functions on both sides of it are not matched yet, so
 * it is a file of its own, the same situation documented for
 * src/matched/unit_02011F24.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201057C.c \
 *       --func WIH_DWC_IsPrivacyBeacon --addr 0x0201057C --cc 1.1p1
 */
u32 WIH_DWC_IsPrivacyBeacon(const struct WihBssDesc *beacon)
{
    if (beacon->capaInfo & 0x10) {
        return 1;
    }
    return 0;
}


/*
 * wih_dwc.c per-frame status poll: returns a flag word (bit 1 always set)
 * built from the lookup in WIH_DWC_FindSlotByKey, the connection state byte +0x67
 * and slot count +0x62 of the GFL_NET_GetInitParam state block, the ov014 per-slot
 * state (0x14..0x1B, 9), then drains the 0xC0-byte record queue that
 * WIH_DWC_AddBeacon fills, arming the four countdowns at +0x318..+0x324 that
 * WIH_DWC_TickTimers decrements (600 or 400 frames), and finally derives bits
 * 0x40..0x200 from those countdowns.  DWC_ParseWMBssDesc's third argument is a
 * 0x40-byte out record whose first word is the switch key; the switch has
 * explicit empty arms for 7 and 9 so the 13-entry halfword table exists.
 */
/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 *           unlabelled Thumb function in ov014 (wih.c); asm/overlays/ov014.s
 *           prints 0x02178098 as .word data (0x680B4909), and this call is
 *           the only branch to it in the image.  SEED REQUEST: `ov014
 *           0x02178098 thumb`, evidence the bl at arm9 0x020105E8.  Every
 *           other site resolves and every concrete byte matches (520 of 520).
 *
 * wih_dwc.c per-frame status poll: returns a flag word (bit 1 always set)
 * built from the lookup in WIH_DWC_FindSlotByKey, the connection state byte +0x67
 * and slot count +0x62 of the GFL_NET_GetInitParam context, the ov014 per-slot
 * state (0x14..0x1B, 9), then drains the 0xC0-byte record queue that
 * WIH_DWC_AddBeacon fills, arming the four countdowns at +0x318..+0x324 that
 * WIH_DWC_TickTimers decrements (600 or 400 frames), and finally derives bits
 * 0x40..0x200 from those countdowns.
 *
 * Two declaration facts close it: DWC_ParseWMBssDesc's third argument is a
 * 0x40-byte out record whose first word is the switch key (the frame is
 * sub sp,#0x60 plus the r3 pad; an `int *` gives sub sp,#0x24), and the
 * switch has explicit empty arms for 7 and 9 so the 13-entry halfword table
 * exists (docs/idioms/empty-switch-arms-are-what-make-the-table.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/WIH_DWC_PollStatus.c \
 *       --func WIH_DWC_PollStatus --addr 0x0201058C --thumb
 */
u32 WIH_DWC_PollStatus(void *searchKey)
{
    u32 flags = 0;
    struct GFLNetInitializeStruct *netState = GFL_NET_GetInitParam();
    int slot;
    int beaconIndex;
    struct WihBssDesc *beacon;
    struct WihSsidInfo ssidInfo;
    u8 slotState;

    if (gWihDwc.context == 0)
        return flags;

    if (WIH_DWC_FindSlotByKey(searchKey) != -1)
        flags |= 8;
    if (netState->connectState == 2 && GFL_NET_GetNegotiationNum() > 1)
        flags |= 4;

    for (slot = 0; slot < netState->slotCount; slot++) {
        if (GFL_NET_GetScanResult(slot) != 0) {
            slotState = NET_WHPIPE_GetEntryKind(slot);
            if (slotState >= 0x14 && slotState <= 0x1B)
                flags |= 0x10;
            else if (slotState == 9)
                flags |= 0x20;
        }
    }

    for (beaconIndex = 0; beaconIndex < gWihDwc.context->beaconCount; beaconIndex++) {
        beacon = &gWihDwc.context->beacon[beaconIndex];
        if (WIH_DWC_IsSsidInFilterList(beacon)) {
            gWihDwc.context->knownGameTimer = 600;
        } else if (WIH_DWC_IsOpenTaggedBeacon(beacon)) {
            gWihDwc.context->taggedGameTimer = 600;
        } else if (DWC_ParseWMBssDesc(gWihDwc.context->matchWork, beacon, &ssidInfo)) {
            switch (ssidInfo.kind) {
            case 0: case 1: case 2: case 3:
            case 10: case 11: case 12:
                gWihDwc.context->knownGameTimer = 600;
                break;
            case 4: case 5: case 6: case 8:
                gWihDwc.context->taggedGameTimer = 600;
                break;
            case 7: case 9:
                break;
            }
        } else if (beacon->ssidLength != 0) {
            if (WIH_DWC_IsPrivacyBeacon(beacon) == 0)
                gWihDwc.context->openNetworkTimer = 400;
            else
                gWihDwc.context->securedNetworkTimer = 400;
        }
    }

    if (gWihDwc.context->knownGameTimer > 0)
        flags |= 0x40;
    if (gWihDwc.context->taggedGameTimer > 0)
        flags |= 0x80;
    if (gWihDwc.context->openNetworkTimer > 0)
        flags |= 0x100;
    if (gWihDwc.context->securedNetworkTimer > 0)
        flags |= 0x200;
    if (gWihDwc.context->alertCooldown != 0)
        gWihDwc.context->alertCooldown = gWihDwc.context->alertCooldown - 1;

    if (flags == 0) {
        gWihDwc.context->alertLevel = 0;
    } else if (gWihDwc.context->pendingAlertLevel != 0 && gWihDwc.context->alertCooldown == 0) {
        gWihDwc.context->alertLevel = gWihDwc.context->pendingAlertLevel;
        gWihDwc.context->alertCooldown = 400;
        gWihDwc.context->pendingAlertLevel = 0;
    }
    gWihDwc.context->beaconCount = 0;
    return flags | 2;
}


/*
 * wih_dwc.c: (re)build the second field of the global.  The guard fires when
 * the pointer is ALREADY set (a re-initialisation warning).  The allocator
 * takes a heap id, a size, a __FILE__ string and a line number.
 */
/*
 * wih_dwc.c: (re)build the second field of the object at 0x021461E0.  The
 * guard is the same file-name call the rest of this file makes - here the
 * polarity is inverted, so it fires when the pointer is ALREADY set (a
 * re-initialisation warning rather than an uninitialised one).
 *
 * The tail calls GFL_NET_AllocAligned(heap, 0xA00, "wih_dwc.c", 0x1C0), which is the
 * debug/allocator shape this SDK uses: a heap ID, a size, a __FILE__
 * string and a line number.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIH_DWC_CreateFilterBuffer.c \
 *       --func WIH_DWC_CreateFilterBuffer --addr 0x02010794 --cc 1.1p1 --thumb
 */
void WIH_DWC_CreateFilterBuffer(u32 heapId)
{
    if (gWihDwc.filterBuf != 0) {
        func_02034714((const char *)(&sWihDwcAssertArg), 0, (const char *)(&sWihDwcAssertArg));
    }
    gWihDwc.filterBuf = GFL_NET_AllocAligned(heapId, 0xA00, (const char *)sWihDwcFile, 0x1C0);
}


/*
 * wih_dwc.c: the sibling of WIH_DWC_CreateFilterBuffer, same guard on the buffer (here it
 * fires when it is unset); the field is re-read afterwards.  The tail is
 * func_0205FAA8(buf + 0x600, 0).
 */
/*
 * wih_dwc.c: the sibling of WIH_DWC_CreateFilterBuffer in the same packet - same guard on
 * the +0x04 field of the object at 0x021461E0, same file-name call, and the
 * field is re-read afterwards (a second pool load), so the callee is allowed
 * to have set it.  The tail is func_0205FAA8(f4 + 0x600, 0).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/WIH_DWC_ResetFilterState.c \
 *       --func WIH_DWC_ResetFilterState --addr 0x020107CC --cc 1.1p1 --thumb
 *
 *           and no branch anywhere else in the image reaches that address -
 *           this function is its only caller - so the site has no witness
 *           outside the compared range and no cut can give it one (shrinking
 *           the range to this one function keeps the call inside it).  The
 *           target is not in an EXACT manifest entry either, so the `matched`
 *           class does not reach it.  Byte-correct as it stands.
 */
void WIH_DWC_ResetFilterState(void)
{
    if (gWihDwc.filterBuf == 0) {
        func_02034714((const char *)(&sWihDwcAssertArg), 0, (const char *)(&sWihDwcAssertArg));
    }
    func_0205FAA8(gWihDwc.filterBuf->filterState, 0);
}


/*
 * wih_dwc.c: find the first of 16 slots whose ov014 state is 0x20 and whose
 * GFL_NET_GetScanResult record sub_0202E8D8 accepts against (key, own MAC address);
 * -1 when none, or when GFL_NET_GetRunState reports the layer inactive.  The guard
 * is a wrapping `if` (it branches forward over the whole body to the shared
 * -1 exit) and the two loop tests are joined by &&.
 */
/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 *           unlabelled Thumb function in ov014 (wih.c); asm/overlays/ov014.s
 *           prints 0x02177B80 as .word data (0x680B4909, `ldr r1,[pc,#0x24];
 *           ldr r3,[r1]`...), and this call is the only branch to it in the
 *           image.  SEED REQUEST: `ov014 0x02177B80 thumb`, evidence the bl at
 *           arm9 0x0201081A.  Once labelled, `sole-ref/code` (or `label`, if a
 *           second referrer turns up in ov014) can carry the site.
 *           The MATCH is also starred: the listing extent runs to 0x02010888
 *           over three unlabelled leaves, filed as src/matched/unit_02010848.c.
 *
 * wih_dwc.c: find the first of 16 slots whose ov014 state is 0x20 and whose
 * GFL_NET_GetScanResult record COMM_PLAYER_SUPPORT_FindPeerRecord accepts against (key, own MAC address);
 * -1 when none, or when GFL_NET_GetRunState reports the layer inactive.  The
 * closing lever over docs/notes/pkt_020107CC.c.txt was the wrapping `if`
 * instead of an early return (the original's guard branches forward over
 * the whole body to the shared -1 exit) plus the two loop tests joined by &&.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/WIH_DWC_FindSlotByKey.c \
 *       --func WIH_DWC_FindSlotByKey --addr 0x020107FC --thumb
 */
int WIH_DWC_FindSlotByKey(void *searchKey)
{
    u8 mac[8];
    int slot;

    if (GFL_NET_GetRunState() != 0) {
        GFL_NET_GetInitParam();
        OS_GetMacAddress(mac);
        for (slot = 0; slot < 0x10; slot++) {
            if (NET_WHPIPE_GetEntryBeaconKind(slot) == 0x20 && sub_0202E8D8((void *)GFL_NET_GetScanResult(slot), (int)searchKey, (char *)mac) != 0) {
                return slot;
            }
        }
    }
    return -1;
}


/*
 * Three unlabelled leaves: a getter of the halfword at +0x312 of the context
 * object (0 when there is none), a raising setter of the halfword at +0x314
 * (only upward, and only below 4; the first compare is signed, the bound
 * unsigned, so the parameter is u32 and the field is compared as int), and
 * an empty function.
 */
/*
 * wih_dwc.c: three unlabelled leaves after WIH_DWC_FindSlotByKey (whose listing extent
 * runs to 0x02010888 because none of them saves lr): a getter of the halfword
 * at +0x312 of the object behind 0x021461E0 (0 when there is none), a raising
 * setter of the halfword at +0x314 (only upward, and only below 4; the first
 * compare is signed, the bound unsigned, so the parameter is u32 and the
 * field is compared as int), and an empty function.  GFL_NET_SAVE_SetStep
 * (src/matched/GFL_NET_SAVE_SetStep.c) follows.
 *
 * SEED REQUEST for the integrator: arm9 0x02010848 thumb, 0x02010864 thumb,
 * 0x02010884 thumb (witness: this unit).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02010848.c \
 *       --addr 0x02010848 --thumb
 */
u16 WIH_DWC_GetAlertLevel(void)
{
    if (gWihDwc.context != 0)
        return gWihDwc.context->alertLevel;
    return 0;
}


void WIH_DWC_RequestAlertLevel(u32 level)
{
    struct WihContext *context = gWihDwc.context;

    if (context != 0 && (int)context->pendingAlertLevel < (int)level && level < 4)
        context->pendingAlertLevel = level;
}


void WIH_DWC_Dummy(void)
{
}


/*
 * Stores the step callback at the task's +8 field.
 */
/*
 * Stores the value at the object's +8 field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_SetStep.c \
 *       --func GFL_NET_SAVE_SetStep --addr 0x02010888 --thumb --cc 1.1p1
 */
void GFL_NET_SAVE_SetStep(struct NetSaveTask *task, void (*step)(struct NetSaveTask *task))
{
    task->step = step;
}


/*
 * net_save.c task constructors for the 0x14-byte task object, its poll, and
 * the eight-byte tail-call stub GFL_NET_SAVE_Delete (a tail call into the ARM
 * function 0x020307B0).  Both constructors end with the same two statements:
 * the debug allocator func_02030734(heap, 0x14, 1, "net_save.c", line)
 * (0x020A725C is two bytes into the "net_save.c" string at 0x020A7258) and
 * GFL_NET_SAVE_SetStep(p, GFL_NET_SAVE_StepBegin).  GFL_NET_SAVE_CheckFinished calls the callback with
 * the object in r0, then tests func_0200FB24()'s result; that call has no
 * argument of its own (r0 still holds the callback's return value).  The
 * two `return 1` arms are written separately and the +0x08 load is re-read
 * after the calls.
 */
/*
 * The whole range 0x0201088C..0x0201093C: two constructors for the same
 * 0x14-byte object, its destructor-or-poll, and the eight-byte tail-call
 * stub that sits between them and GFL_NET_SAVE_StepBegin.
 *
 *   GFL_NET_SAVE_Create   allocator + one stored field (+0x0C)
 *   GFL_NET_SAVE_CreateWithCallback   allocator + three stored fields (+0x00, +0x04, +0x0C)
 *   GFL_NET_SAVE_CheckFinished   fire the +0x08 callback, then two liveness tests
 *   (0x02010934)    `ldr r3, [pc, #0]; bx r3; .word func_020307B0`
 *
 * The stub is a real function: `ov119` at 0x021E0C5C and `ov137` at
 * 0x021DF696 both `bl` it.  It carries no label because it has no prologue
 * (disasm.py only labels a function that saves lr), so it is written here as
 * the tail call it is - a void function whose body is one call to the ARM
 * function 0x020307B0 with the object passed through in r0, which is what
 * puts the pool word and the `bx r3` there and what makes the unit's extent
 * end at 0x0201093C.  Since then seeded as a start in
 * layout/function_starts.txt (both callers set r0 to the object at +0xEF8 /
 * their own field before the bl), so the listing labels it GFL_NET_SAVE_Delete.
 *
 * Both constructors end with the same two statements: the SDK debug
 * allocator func_02030734(heap, 0x14, 1, "net_save.c", line) - 0x020A725C is
 * two bytes into the "net_save.c" string at 0x020A7258, so the file anchor is
 * net_save.c - and then GFL_NET_SAVE_SetStep(p, GFL_NET_SAVE_StepBegin), which stores the
 * callback into +0x08.  The two pool words per constructor are the file
 * string and that callback address with its Thumb bit, 0x0201093D.
 *
 * GFL_NET_SAVE_CheckFinished calls the callback with the object in r0, then tests
 * func_0200FB24()'s result.  That call is left with no argument of its own:
 * r0 still holds whatever the callback returned, which is what the original
 * does and what a no-argument call in the source produces.  The two `return
 * 1` arms are written separately (two `movs r0, #1` epilogues in the
 * original) and the +0x08 load is re-read after the calls.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201088C.c \
 *       --addr 0x0201088C --thumb
 */
struct NetSaveTask *GFL_NET_SAVE_Create(u32 heapId, u32 gameData)
{
    struct NetSaveTask *task;

    task = func_02030734(heapId, 0x14, 1, (const char *)&sNetSaveFile, 0x75);
    task->gameData = gameData;
    GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x71, 8);
    GFL_NET_SAVE_SetStep(task, GFL_NET_SAVE_StepBegin);
    return task;
}


struct NetSaveTask *GFL_NET_SAVE_CreateWithCallback(u32 heapId, u32 gameData, void (*callback)(u32 arg), u32 callbackArg)
{
    struct NetSaveTask *task;

    task = func_02030734(heapId, 0x14, 1, (const char *)&sNetSaveFile, 0x87);
    task->progressCallback = callback;
    task->callbackArg = callbackArg;
    task->gameData = gameData;
    GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x71, 8);
    GFL_NET_SAVE_SetStep(task, GFL_NET_SAVE_StepBegin);
    return task;
}


u32 GFL_NET_SAVE_CheckFinished(struct NetSaveTask *task)
{
    if (task->step != 0)
        task->step(task);
    if (func_0200FB24() != 0) {
        if (task->gameData != 0)
            GAME_DATA_SaveCancel(task->gameData);
        return 1;
    }
    if (task->step == 0)
        return 1;
    return 0;
}

void GFL_NET_SAVE_Delete(struct NetSaveTask *task)
{
    func_020307B0(task);
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepBegin.c \
 *       --func GFL_NET_SAVE_StepBegin --addr 0x0201093C --thumb --cc 1.1p1
 */
void GFL_NET_SAVE_StepBegin(struct NetSaveTask *task)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x71, 8) != 0) {
        GAME_DATA_SaveStart(task->gameData);
        GFL_NET_SAVE_SetStep(task, GFL_NET_SAVE_StepWaitSaveStart);
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepWaitSaveStart.c \
 *       --func GFL_NET_SAVE_StepWaitSaveStart --addr 0x02010964 --thumb --cc 1.1p1
 */
void GFL_NET_SAVE_StepWaitSaveStart(struct NetSaveTask *task)
{
    if (GAME_DATA_SaveMain(task->gameData) == 1) {
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x72, 8);
        task->delayFrames = func_020056EC(0x3c);
        GFL_NET_SAVE_SetStep(task, GFL_NET_SAVE_StepWaitSync72);
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepWaitSync72.c \
 *       --func GFL_NET_SAVE_StepWaitSync72 --addr 0x02010994 --thumb --cc 1.1p1
 */
void GFL_NET_SAVE_StepWaitSync72(struct NetSaveTask *task)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x72, 8) != 0) {
        GFL_NET_SAVE_SetStep(task, GFL_NET_SAVE_StepDelay);
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepDelay.c \
 *       --func GFL_NET_SAVE_StepDelay --addr 0x020109B8 --thumb --cc 1.1p1
 */
void GFL_NET_SAVE_StepDelay(struct NetSaveTask *task)
{
    s32 framesLeft = task->delayFrames - 1;

    task->delayFrames = framesLeft;
    if (framesLeft < 0) {
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x73, 8);
        GFL_NET_SAVE_SetStep(task, GFL_NET_SAVE_StepWaitSync73);
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepWaitSync73.c \
 *       --func GFL_NET_SAVE_StepWaitSync73 --addr 0x020109E0 --thumb --cc 1.1p1
 */
void GFL_NET_SAVE_StepWaitSync73(struct NetSaveTask *task)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x73, 8) != 0) {
        GFL_NET_SAVE_SetStep(task, GFL_NET_SAVE_StepProgress);
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepProgress.c \
 *       --func GFL_NET_SAVE_StepProgress --addr 0x02010A04 --thumb --cc 1.1p1
 */
void GFL_NET_SAVE_StepProgress(struct NetSaveTask *task)
{
    if (task->progressCallback != 0) {
        task->progressCallback(task->callbackArg);
    }
    if (GAME_DATA_SaveMain(task->gameData) == 2) {
        task->gameData = 0;
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x74, 8);
        GFL_NET_SAVE_SetStep(task, GFL_NET_SAVE_StepFinish);
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepFinish.c \
 *       --func GFL_NET_SAVE_StepFinish --addr 0x02010A3C --thumb --cc 1.1p1
 */
void GFL_NET_SAVE_StepFinish(struct NetSaveTask *task)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x74, 8) != 0) {
        GFL_NET_SAVE_SetStep(task, 0);
    }
}


int GFL_NET_SAVE_InitWork(void *proc)
{
    struct NetSaveProcWork *work;
    void *gameData;

    GFL_HEAP_CreateChildHeap(1, 0x67, 0x78000);
    work = PROCSYS_AllocProcWork(proc, 0x1d8, 0x67);
    MI_CpuFill8(work, 0, 0x1d8);
    work->heapId = 0x67;
    gameData = sub_020124F4(0x67);
    work->gameData = gameData;
    if (BLOCK20_SAVEDATA_GetPending(GAME_SYNC_GetBlock(sub_02012EBC(gameData))) != 0) {
        work->state = 1;
        work->skipFinalSave = 1;
    } else {
        work->state = 0;
        work->skipFinalSave = 0;
    }
    return 1;
}


/*
 * The net_save.c save task's per-frame step (state word at +0x1D4): case 0
 * starts overlay 0x73's proc 0x021D6338 on the record, case 1 starts overlay
 * 0x7B's proc on +0x48 unless +0x1C says finished, case 2 hands off to
 * GFL_NET_ERR_ShowScreen(0), case 3 restarts overlay 0x73 with proc 0x021D654C on +0x28
 * or ends the task.  gNetSaveCheckProc lies in the windows of several overlays; the
 * ov123 hint is supported by the proc table bytes there (three Thumb
 * pointers into ov123).
 */
/*
 * history:  was MATCH on evidence only (every concrete byte matched).  Wave 17:
 *           the pooled overlay ids 0x73 / 0x7B (ov115_id, ov123_id) now
 *           resolve as `overlay_id` (id argument of PROCSYS_PushGlobal).  Two
 *           ABS32 sites are left, the overlay-resident proc pointers
 *           0x021D6338 / 0x021D654C, whose only other pool words sit in
 *           GFL_NET_SAVE_ScreenMain's pool (0x02010D84..), which disasm.py prints as
 *           Thumb code, so the literal index misses them.  Seeding those
 *           pools as .word, or a matched referrer, would close both.
 *           Seed round 10: both words are ov115 proc tables (three Thumb
 *           function pointers each, 0x021D6338 -> func_021D4BFC/4CE4/4D10,
 *           0x021D654C -> func_021D603C/6104/60D4), loaded with overlay id
 *           0x73 = ov115, not ov021 (docs/sessions/2026-09-23/reports/
 *           wave17_evidence.md).  ov115 declares both starts in
 *           layout/data_objects.txt and the symbols lines carry the ov115
 *           token.  0x021D654C resolves as sole-ref/data (ov115 is the only
 *           overlay with a start there).  0x021D6338 resolves as
 *           sole-ref/self on the ov115 hint; ov021's listing also starts a
 *           block there, so sole-ref/data refuses the contested hint, and the
 *           choice rests on the hint plus the overlay_id 0x73 site in this
 *           same function.  EXACT, seed round 10.
 * evidence: gNetSaveCheckProc lies in the windows of ov016, ov021, ov123, ov125
 *           and ov175, so the ov123 hint needs outside support.  Case 1
 *           passes ov123_id (0x7B, attested `overlay_id`) and this pointer
 *           in one PROCSYS_PushGlobal call; PROCSYS_PushInternal -> PROCSYS_NewProc stores
 *           the id at Proc+4 and the pointer at Proc+0 (ProcData), and
 *           PROCSYS_StepProc loads overlay Proc+4 (func_02034AC4) before it
 *           calls any ProcData callback.  So ov123 is resident whenever the
 *           pointer is dereferenced.  Independently, ov123's bytes at
 *           0x021DA9A8 are three Thumb pointers 0x021DA479/0x021DA54D/
 *           0x021DA5D1, each a func_ label in ov123's own listing, while
 *           ov125 has bss there and ov016/ov021/ov175 hold non-pointer
 *           words.  With the hint the site attests as `sole-ref` in ov123.
 *
 * The net_save.c save task's per-frame step (the task record of
 * GFL_NET_SAVE_InitWork; state word at +0x1D4): case 0 starts overlay 0x73's proc
 * 0x021D6338 on the record, case 1 starts overlay 0x7B's proc on +0x48
 * unless +0x1C says finished, case 2 hands off to GFL_NET_ERR_ShowScreen(0), case 3
 * restarts overlay 0x73 with proc 0x021D654C on +0x28 or ends the task.
 * Wave 13: the earlier DIFF read both small pool words as distinct symbols
 * and the size argument as 0x1A8; they are the arguments (0x73, proc, arg).
 */
int GFL_NET_SAVE_Main(u32 proc, u32 seq, u32 parentWork, struct NetSaveProcWork *work)
{
    switch (work->state) {
    case 0:
        work->screenArgs.gameData = work->gameData;
        work->screenArgs.mode = 0;
        work->screenArgs.enable = 1;
        work->screenArgs.waitFrames = 0x32;
        work->screenArgs.saveBuf = work->saveBuf;
        PROCSYS_PushGlobal((u32)ov115_id, gNetSaveMainProc, work);
        work->state += 1;
        break;
    case 1:
        if (work->cancelled == 1) {
            work->state = 4;
            break;
        }
        work->checkArgs.gameData = work->gameData;
        work->checkArgs.heapId = work->heapId;
        work->checkArgs.saveBuf = work->saveBuf;
        PROCSYS_PushGlobal((u32)ov123_id, gNetSaveCheckProc, &work->checkArgs);
        work->state += 1;
        break;
    case 2:
        if (work->skipFinalSave == 1) {
            work->state = 4;
            break;
        }
        GFL_NET_ERR_ShowScreen(0);
        work->state += 1;
        break;
    case 3:
        if (GFL_NET_GetRunState() == 0 || work->saveFailed == 1) {
            work->retryRequested = 1;
            work->state = 0;
            break;
        }
        work->retryArgs.gameData = work->gameData;
        work->retryArgs.mode = 0;
        work->retryArgs.enable = 1;
        PROCSYS_PushGlobal((u32)ov115_id, gNetSaveRetryProc, &work->retryArgs);
        work->state += 1;
        break;
    default:
        return 1;
    }
    return 0;
}
