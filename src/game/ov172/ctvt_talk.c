/*
 * file:     ctvt_talk.c
 * unit:     yes
 * function: CTVT_TALK_Create, CTVT_TALK_Delete, CTVT_TALK_Init, CTVT_TALK_Exit, CTVT_TALK_Main, CTVT_TALK_SetMicMode, CTVT_TALK_HandleInput, CTVT_TALK_UpdateVoiceSend, CTVT_TALK_UpdateVoiceIcon, CTVT_TALK_HandleLevelSlider, CTVT_TALK_DrawLine, CTVT_TALK_PlotPixel, CTVT_TALK_ShowMessage, CTVT_TALK_OpenConfirmMenu, CTVT_TALK_UpdateConfirmMenu, CTVT_TALK_CheckEnd, CTVT_TALK_BeginWaveform, CTVT_TALK_DrawWaveform, CTVT_TALK_HitCenter, CTVT_TALK_GetMic
 * address:  0x021B8C3C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from draw_system.c, ctvt_comm.c, ctvt_draw.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   COMM_TVT_SYS_GetArc 0x021BE010 thumb ov172
 *   COMM_TVT_SYS_GetComm 0x021BDFE4 thumb ov172
 *   COMM_TVT_SYS_GetMemberCount 0x021BE054 thumb ov172
 *   COMM_TVT_SYS_GetCamView 0x021BDFDC thumb ov172
 *   COMM_TVT_SYS_GetSelfSlot 0x021BE0A4 thumb ov172
 *   COMM_TVT_SYS_GetViewSwapped 0x021BE0B4 thumb ov172
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   COMM_TVT_SYS_GetHeapId 0x021BE00C thumb ov172
 *   COMM_TVT_SYS_PlaceSlotMarker 0x021BE210 thumb ov172
 *   COMM_TVT_SYS_GetTalkStatus 0x021BDFEC thumb ov172
 *   MIi_CpuCopy16 0x02082A60 arm
 *   d_021C7200 0x021C7200 data a4
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   COMM_TVT_SYS_GetResId 0x021BE018 thumb ov172
 *   COMM_TVT_SYS_GetClactUnit 0x021BE024 thumb ov172
 *   CTVT_MIC_IsCaptureDone 0x021BA270 thumb ov172
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   COMM_TVT_SYS_GetReturnedFromChild 0x021BE02C thumb ov172
 *   COMM_TVT_SYS_SetReturnedFromChild 0x021BE030 thumb ov172
 *   COMM_TVT_SYS_SetMessageActive 0x021BE0B0 thumb ov172
 *   COMM_TVT_SYS_GetPrintQue 0x021BE044 thumb ov172
 *   COMM_TVT_SYS_CreateTimeIcon 0x021BE318 thumb ov172
 *   COMM_TVT_SYS_DeleteTimeIcon 0x021BE34C thumb ov172
 *   CTVT_CAMVIEW_IsShutterIdle 0x021B7590 thumb ov172
 *   CTVT_CAMVIEW_StopCapture 0x021B7578 thumb ov172
 *   CTVT_MIC_GetPlayState 0x021BA244 thumb ov172
 *   CTVT_MIC_GetLength 0x021BA248 thumb ov172
 *   CTVT_MIC_GetPlayPos 0x021BA24C thumb ov172
 *   CTVT_MIC_GetPlayRatio 0x021BA254 thumb ov172
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   KEY_GetCont 0x0203630C arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetTrg 0x020362DC arm
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   COMM_TVT_SYS_ToggleViewSwapped 0x021BE0B8 thumb ov172
 *   CTVT_CAMVIEW_IsLayoutChanging 0x021B77B4 thumb ov172
 *   COMM_TVT_SYS_ToggleHalfRes 0x021BE08C thumb ov172
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   func_020355D8 0x020355D8 arm
 *   d_021C6F83 0x021C6F83 data a1
 *   d_021C6F77 0x021C6F77 data a1
 *   CTVT_ADPCM_ResetEncoder 0x021B69E0 thumb ov172
 *   CTVT_MIC_EncodeAdpcm 0x021BA174 thumb ov172
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   GFL_USE_PlaySeInSlot 0x0200616C thumb
 *   GFL_USE_SetSeSlotParams 0x02006268 thumb
 *   d_021C6F8F 0x021C6F8F data a1
 *   func_0209BDBC 0x0209BDBC arm
 *   func_0209C95C 0x0209C95C arm
 *   func_0209CB8C 0x0209CB8C arm
 *   func_0209C494 0x0209C494 arm
 *   func_0209C0A4 0x0209C0A4 arm
 *   d_021C6FA0 0x021C6FA0 data a2
 *   d_021C6F66 0x021C6F66 data a2
 *   COMM_TVT_SYS_GetFont 0x021BE034 thumb ov172
 *   COMM_TVT_SYS_GetMsgData 0x021BE03C thumb ov172
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   COMM_TVT_SYS_OpenConfirmMenu 0x021BE11C thumb ov172
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   COMM_TVT_SYS_GetEndRequested  0x021BE0D0  thumb  ov172
 *   BMP_GetPixels  0x020437D4  arm
 *   d_021C6F6E     0x021C6F6E  data
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   CTVT_CAMVIEW_RequestShutterSound1  0x021B7B80  thumb  ov172
 *   CTVT_CAMVIEW_SetCameraEffect  0x021B7B3C  thumb  ov172
 *   CTVT_COMM_StopSession  0x021B8084  thumb  ov172
 *   CTVT_COMM_SendCommand  0x021B8740  thumb  ov172
 *   CTVT_COMM_SetTimingSync  0x021B8B34  thumb  ov172
 *   CTVT_COMM_IsTimingSync  0x021B8B48  thumb  ov172
 *   CTVT_COMM_GetNetMode  0x021B80E4  thumb  ov172
 *   CTVT_TALK_Create 0x021B8C3C thumb ov172
 *   CTVT_TALK_Delete 0x021B8CB0 thumb ov172
 *   CTVT_TALK_Main  0x021B9044  thumb  ov172
 *   CTVT_TALK_SetMicMode  0x021B9574  thumb  ov172
 *   CTVT_TALK_Exit 0x021B8FB8 thumb ov172
 *   CTVT_TALK_Init 0x021B8CC8 thumb ov172
 *   CTVT_COMM_GetMarkerSlot 0x021B8B68 thumb ov172
 *   CTVT_TALK_GetMic  0x021B9F98  thumb
 *   CTVT_COMM_SendVoiceData 0x021B891C thumb ov172
 *   CTVT_COMM_GetHandleNetId 0x021B8B5C thumb ov172
 *   CTVT_COMM_IsPostBusy 0x021B8B74 thumb ov172
 *   CTVT_COMM_GetVoiceRecord 0x021B8B84 thumb ov172
 *   CTVT_COMM_GetVoiceStatePending 0x021B8C34 thumb ov172
 *   CTVT_MIC_Create 0x021B9F9C thumb ov172
 *   CTVT_MIC_Delete 0x021BA01C thumb ov172
 *   CTVT_MIC_Update 0x021BA050 thumb ov172
 *   CTVT_MIC_SetMode 0x021BA094 thumb ov172
 *   CTVT_MIC_StartCapture 0x021BA0BC thumb ov172
 *   CTVT_MIC_StopCapture 0x021BA120 thumb ov172
 *   CTVT_MIC_IsCapturing 0x021BA158 thumb ov172
 *   CTVT_MIC_GetReadyBytes 0x021BA15C thumb ov172
 *   CTVT_MIC_GetBuffer 0x021BA170 thumb ov172
 */
#include "ctvt_types.h"
#include "ctvt_talk_shared_types.h"

extern u32 GFL_HEAP_Free(void *p);

struct Bmp;

struct Rect { u16 x; u16 y; u16 z; u8 a; u8 b; };

extern void GFL_USE_PlaySeDefaultVolume(unsigned int);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void MIi_CpuCopy16(const void *, void *, u32);

extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void G2x_SetBlendAlpha_(void *, u32, u32, u32, u32);

extern void BG_SYS_PushTile(u32 layer);

extern struct ClActor *CLACT_CreateActor(void *, u32, u32, u32, const void *, u16, u16);

extern void CLACT_SetActorDrawEnable(struct ClActor *p, u32 v);

extern void CLACT_SetActorAutoAnim(struct ClActor *p, u32 v);

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern int CTVT_MIC_IsCaptureDone(void *p);

extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);

extern void BMP_WIN_ClearScreen(struct Descriptor *d);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern void CLACT_DeleteActor(struct ClActor *p);

extern void BG_SYS_ClearSlot(u32 i);

extern int CTVT_CAMVIEW_IsShutterIdle(int x, char *p);

extern void CTVT_CAMVIEW_StopCapture(int x, char *p);

extern u32 CTVT_MIC_GetPlayState(void *p);

extern int CTVT_MIC_GetLength(void *t);

extern int CTVT_MIC_GetPlayPos(void *t);

extern int CTVT_MIC_GetPlayRatio(void *t);

extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

extern u32 WIPE_SYS_EndCheck(void);

extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);

extern u32 CLACT_IsActorAnimActive(struct Actor *a);

extern void CLACT_SetActorAnimSeq(struct ClActor *p, u16 value);

extern u32 KEY_GetCont(void);

extern int TOUCHPANEL_GetTrg(void);

extern u32 KEY_GetTrg(void);

extern s32 NNS_GfdRegisterNewVramTransferTask(void *p, u32 a, u32 b, s32 size);

extern u32 CTVT_CAMVIEW_IsLayoutChanging(int unused, void *p);

extern int TOUCHPANEL_HitTrg(const void *);

extern void func_020355D8(u8 v);

extern void CTVT_ADPCM_ResetEncoder(void);

extern int CTVT_MIC_EncodeAdpcm(int unused, void *a, void *buf, unsigned n);

extern int TOUCHPANEL_HitCont(const void *);

extern void GFL_USE_PlaySeInSlot(void *, int);

extern void GFL_USE_SetSeSlotParams(int i, u32 a, u32 b, u32 c);

extern int func_0209BDBC(int a);

extern int func_0209C95C(int a, int b);

extern int func_0209CB8C(int a, int b);

extern int func_0209C494(int a);

extern void PRINTSYS_QUE_Clear(struct PrintSys *p);

extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void STRBUF_Delete(struct U16Vec *vec);

extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);

extern void APP_TASKMENU_UpdateMenu(void *p);

extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);

extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);

extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);

extern int func_0209C0A4(int a, u16 b);

extern void *BMP_GetPixels(const struct Bmp *bmp);

extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);

extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);

void CTVT_CAMVIEW_SetCameraEffect(int x, int y, int z);

void CTVT_CAMVIEW_RequestShutterSound1(int x, char *p);

void CTVT_COMM_StopSession(void *a, char *q);

u32 CTVT_COMM_GetNetMode(int unused, char *p);

u32 CTVT_COMM_SendCommand(int a, int b, u8 c, u32 d);

int CTVT_COMM_SendVoiceData(void *a, char *q, u16 *p);

void CTVT_COMM_SetTimingSync(void *p, u32 a, u32 b);

int CTVT_COMM_IsTimingSync(void *p, u32 a, u32 b);

u32 CTVT_COMM_GetHandleNetId(void *unused, u32 unused2);

u32 CTVT_COMM_GetMarkerSlot(int unused, char *p);

int CTVT_COMM_IsPostBusy(void *ctx, u8 *rec);

u32 CTVT_COMM_GetVoiceRecord(int unused, char *p);

u32 CTVT_COMM_GetVoiceStatePending(void *ctx, u8 *rec);

char *CTVT_TALK_Create(char *unused, u16 heap);

void CTVT_TALK_Delete(void *a0, char *a1);

void CTVT_TALK_Init(void *a, char *p);

void CTVT_TALK_Exit(void *a0, char *a1);

u32 CTVT_TALK_Main(void *p, CtvtTalk *s);

void CTVT_TALK_SetMicMode(int unused, char *p);

void CTVT_TALK_HandleInput(u8 *c, u8 *q);

void CTVT_TALK_UpdateVoiceSend(void *ctx, CtvtTalk *st);

void CTVT_TALK_UpdateVoiceIcon(void *a0, char *a1);

void CTVT_TALK_HandleLevelSlider(void *unused, u8 *q);

void CTVT_TALK_DrawLine(int a0, char *a1, u8 *p, u8 x0, u8 y0, u8 x1, u8 y1, u8 value);

void CTVT_TALK_PlotPixel(u8 *p, u8 x, u8 y, u8 value);

void CTVT_TALK_ShowMessage(void *p, char *q, int id);

void CTVT_TALK_OpenConfirmMenu(void *p, char *q);

void CTVT_TALK_UpdateConfirmMenu(int self, int *q);

int CTVT_TALK_CheckEnd(void *p, int *out);

void CTVT_TALK_BeginWaveform(void *p, char *q);

void CTVT_TALK_DrawWaveform(int a0, char *obj, s16 *tbl, u8 a3, int idx, u16 v);

int CTVT_TALK_HitCenter(int a, int b, int mode);

int CTVT_TALK_GetMic(int unused, int *p);

void *CTVT_MIC_Create(u32 heap);

void CTVT_MIC_Delete(char *p);

void CTVT_MIC_Update(u32 *p);

void CTVT_MIC_SetMode(int v);

int CTVT_MIC_StartCapture(u32 *p);

int CTVT_MIC_StopCapture(u32 *p);

u32 CTVT_MIC_IsCapturing(u32 *p);

u32 CTVT_MIC_GetReadyBytes(u32 *p);

u32 CTVT_MIC_GetBuffer(u32 *p);

extern const char d_021C7200[];

extern const u8 d_021C6F83[];

extern const u8 d_021C6F77[];

extern const u8 d_021C6F8F[];

extern const u16 d_021C6FA0[4], d_021C6F66[4];

extern u8 d_021C6F6E[];

char *CTVT_TALK_Create(char *unused, u16 heap)
{
    char *q;
    u8 i;
    q = GFL_HEAP_Alloc(heap, 0xac, 1, d_021C7200, 0xd7);
    ((CtvtTalk *)q)->mic = CTVT_MIC_Create(heap);
    ((CtvtTalk *)q)->packetPool = GFL_HEAP_Alloc(heap, 0x808, 1, d_021C7200, 0xda);
    ((CtvtTalk *)q)->packet = ((CtvtTalk *)q)->packetPool;
    ((CtvtTalk *)q)->packetPayload = (char *)((CtvtTalk *)q)->packetPool + 8;
    ((CtvtTalk *)q)->levelIndex = 4;
    MIi_CpuCopy16((void *)0x05000420, q + 0x5a, 32);
    for (i = 0; i < 16; i++) *(u16 *)(q + i * 2 + 0x3a) = 32767;
    return q;
}

void CTVT_TALK_Delete(void *a0, char *a1)
{
    GFL_HEAP_Free(((CtvtTalk *)a1)->packet);
    CTVT_MIC_Delete((char *)((CtvtTalk *)a1)->mic);
    GFL_HEAP_Free(a1);
}

/*
 * Sets up the BG layers and five OBJ sprites of the screen, then clears the state words.
 * 2026-10-05 (wD8 lane06): closed by statement order of the zero stores. mwcc keeps one constant
 *   of the join block in r7; with the zero stores in the order 0, 8, 0xA4 (address-temp store last)
 *   and 0x38, 0x34, 0x8C, 0xC the constant 1 wins r7 as in the image. Earlier lanes found the
 *   0x15/0x16 if/else for rc.z (holds &rc in r7 for the first block).
 */
void CTVT_TALK_Init(void *a, char *p)
{
    u16 h;
    void *g;
    struct Rect rc;

    h = COMM_TVT_SYS_GetHeapId(a);
    g = (void *)COMM_TVT_SYS_GetArc(a);
    ARC_UTIL_UploadBgCharFromHandle(g, 0xB, 6, 0, 0, 0, h);
    ARC_UTIL_UploadBgPaletteFromHandle(g, 0x11, 6, 0, 0, 0, h);
    ARC_UTIL_UploadBgCharFromHandle(g, 0xB, 5, 0, 0x5000, 0, h);
    ARC_UTIL_UploadBgPaletteFromHandle(g, 0xF, 5, 0, 0, 0, h);
    G2x_SetBlendAlpha_((void *)0x04001050, 2, 0x14, 5, 0xF);
    BG_SYS_PushTile(6);
    BG_SYS_PushTile(5);
    rc.x = 0x80;
    rc.y = 0x60;
    rc.z = ((CtvtTalk *)p)->levelIndex + 0x19;
    rc.a = 0;
    rc.b = 2;
    ((CtvtTalk *)p)->levelActor = CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a), COMM_TVT_SYS_GetResId(a, 5), COMM_TVT_SYS_GetResId(a, 1), COMM_TVT_SYS_GetResId(a, 9), &rc, 1, h);
    CLACT_SetActorDrawEnable(((CtvtTalk *)p)->levelActor, 1);
    if (COMM_TVT_SYS_GetViewSwapped(a) == 1)
        rc.z = 0x15;
    else
        rc.z = 0x16;
    ((CtvtTalk *)p)->swapActor = CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a), COMM_TVT_SYS_GetResId(a, 5), COMM_TVT_SYS_GetResId(a, 1), COMM_TVT_SYS_GetResId(a, 9), &rc, 1, h);
    CLACT_SetActorDrawEnable(((CtvtTalk *)p)->swapActor, 1);
    rc.z = 0x14;
    ((CtvtTalk *)p)->backActor = CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a), COMM_TVT_SYS_GetResId(a, 5), COMM_TVT_SYS_GetResId(a, 1), COMM_TVT_SYS_GetResId(a, 9), &rc, 1, h);
    CLACT_SetActorDrawEnable(((CtvtTalk *)p)->backActor, 1);
    rc.z = 0x18;
    ((CtvtTalk *)p)->voiceActor = CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a), COMM_TVT_SYS_GetResId(a, 5), COMM_TVT_SYS_GetResId(a, 1), COMM_TVT_SYS_GetResId(a, 9), &rc, 1, h);
    CLACT_SetActorDrawEnable(((CtvtTalk *)p)->voiceActor, 1);
    rc.x = 0xE8;
    rc.y = 0xA8;
    rc.z = 1;
    rc.a = 0;
    rc.b = 0;
    ((CtvtTalk *)p)->cancelActor = CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a), COMM_TVT_SYS_GetResId(a, 6), COMM_TVT_SYS_GetResId(a, 2), COMM_TVT_SYS_GetResId(a, 10), &rc, 1, h);
    CLACT_SetActorDrawEnable(((CtvtTalk *)p)->cancelActor, 1);
    CLACT_SetActorAutoAnim(((CtvtTalk *)p)->cancelActor, 1);
    ((CtvtTalk *)p)->state = 0;
    ((CtvtTalk *)p)->shutterPending = 0;
    ((CtvtTalk *)p)->voiceIconState = 0;
    ((CtvtTalk *)p)->voiceIconPrev = 3;
    ((CtvtTalk *)p)->waveformWin = (struct BmpWin *)BMP_WIN_Create(4, 8, 3, 0x10, 8, 0xA, 1);
    ((CtvtTalk *)p)->messageWin = (struct BmpWin *)BMP_WIN_Create(4, 1, 1, 0x1E, 4, 0xA, 1);
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)((CtvtTalk *)p)->waveformWin), 0);
    BMP_WIN_MakeScreen((struct Cfg *)((CtvtTalk *)p)->waveformWin);
    BMP_WIN_TransferChars((struct Descriptor *)((CtvtTalk *)p)->waveformWin);
    ((CtvtTalk *)p)->confirmMenu = 0;
    ((CtvtTalk *)p)->timeIconPending = 0;
    ((CtvtTalk *)p)->messagePending = 0;
    BG_SYS_PushTile(4);
    ((CtvtTalk *)p)->flashCounter = 0;
    ((CtvtTalk *)p)->flashActive = 0;
    ((CtvtTalk *)p)->voiceActive = 0;
    ((CtvtTalk *)p)->sendCooldown = 0;
    {
        u32 r = CTVT_COMM_GetMarkerSlot((int)a, (char *)COMM_TVT_SYS_GetComm(a));
        if (r != 0xFF) {
            /* The shared prototype narrows the slot to u8, but the original
             * CTVT_TALK_Init passes the full 32 bit value; the cast keeps the
             * u32 calling convention this function was matched with. */
            ((void (*)(void *, u32))COMM_TVT_SYS_PlaceSlotMarker)(a, r);
            ((CtvtTalk *)p)->voiceIconState = 2;
        }
    }
    if (CTVT_MIC_IsCaptureDone(((CtvtTalk *)p)->mic) == 0)
        ((CtvtTalk *)p)->voiceIconState = 2;
}

void CTVT_TALK_Exit(void *a0, char *a1)
{
    void *p;

    if (((CtvtTalk *)a1)->confirmMenu != 0)
        APP_TASKMENU_CloseMenu(((CtvtTalk *)a1)->confirmMenu);

    p = ((CtvtTalk *)a1)->waveformWin;
    BMP_WIN_ClearScreen(p);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(p));

    p = ((CtvtTalk *)a1)->messageWin;
    BMP_WIN_ClearScreen(p);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(p));

    BMP_WIN_Delete((struct Descriptor *)((CtvtTalk *)a1)->waveformWin);
    BMP_WIN_Delete((struct Descriptor *)((CtvtTalk *)a1)->messageWin);
    CLACT_DeleteActor(((CtvtTalk *)a1)->cancelActor);
    CLACT_DeleteActor(((CtvtTalk *)a1)->voiceActor);
    CLACT_DeleteActor(((CtvtTalk *)a1)->backActor);
    CLACT_DeleteActor(((CtvtTalk *)a1)->swapActor);
    CLACT_DeleteActor(((CtvtTalk *)a1)->levelActor);
    BG_SYS_ClearSlot(6);
    BG_SYS_PushTile(6);
    *(u16 *)0x04001050 = 0;
}

u32 CTVT_TALK_Main(void *p, CtvtTalk *s)
{
    u32 heap;
    u32 a;
    u32 b;

    heap = COMM_TVT_SYS_GetHeapId(p);
    switch (s->state) {
    case 0:
        if (COMM_TVT_SYS_GetReturnedFromChild(p) == 1)
            WIPE_SYS_Start(0, 1, 1, 0, 6, 1, heap);
        else
            WIPE_SYS_Start((void *)4, 1, 1, 0, 6, 1, heap);
        s->state = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1)
            s->state = 5;
        break;
    case 2:
        WIPE_SYS_Start((void *)4, 0, 0, 0, 6, 1, heap);
        COMM_TVT_SYS_SetReturnedFromChild(p, 0);
        s->state = 4;
        break;
    case 3:
        if (s->substate == 6 && CLACT_IsActorAnimActive((struct Actor *)s->backActor) == 1)
            break;
        a = (u32)COMM_TVT_SYS_GetCamView(p);
        if (s->shutterPending != 0 && CTVT_CAMVIEW_IsShutterIdle((int)p, (char *)a) != 1)
            break;
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, heap);
        COMM_TVT_SYS_SetReturnedFromChild(p, 1);
        s->state = 4;
        break;
    case 4:
        if (WIPE_SYS_EndCheck() != 1)
            break;
        if (s->substate == 6)
            return 3;
        return 4;
    case 5:
        CTVT_TALK_HandleInput(p, (u8 *)s);
        break;
    case 6:
        if (CTVT_TALK_CheckEnd(p, (int *)s) != 0)
            break;
        if (CTVT_TALK_HitCenter((int)p, (int)s, 1) == 1 || (KEY_GetCont() & 0x101)) {
            if (CTVT_COMM_SendCommand((int)p, (int)COMM_TVT_SYS_GetComm(p), 6, 0) == 1)
                s->state = 7;
            break;
        }
        s->state = 5;
        break;
    case 7:
        if (CTVT_TALK_CheckEnd(p, (int *)s) != 0)
            break;
        b = (u32)COMM_TVT_SYS_GetComm(p);
        a = CTVT_COMM_GetMarkerSlot((int)p, (char *)b);
        b = CTVT_COMM_GetHandleNetId(p, b);
        if (CTVT_TALK_HitCenter((int)p, (int)s, 1) == 1 || (KEY_GetCont() & 0x101)) {
            if (a != 0xFF) {
                if (a == b) {
                    s->state = 8;
                    s->substate = 0;
                } else {
                    s->state = 5;
                }
            }
        } else {
            s->state = 5;
        }
        break;
    case 8:
        CTVT_TALK_UpdateVoiceSend(p, s);
        break;
    case 9:
        CTVT_TALK_OpenConfirmMenu(p, (char *)s);
        break;
    case 10:
        CTVT_TALK_UpdateConfirmMenu((int)p, (int *)s);
        break;
    case 11:
        if (CTVT_COMM_SendCommand((int)p, (int)COMM_TVT_SYS_GetComm(p), 10, 0) == 1)
            s->state = 12;
    case 12:
        if (COMM_TVT_SYS_GetMemberCount(p) > 1)
            break;
        a = (u32)COMM_TVT_SYS_GetCamView(p);
        s->substate = 7;
        s->state = 3;
        COMM_TVT_SYS_SetMessageActive(p, 1);
        CTVT_CAMVIEW_StopCapture((int)p, (char *)a);
        CTVT_CAMVIEW_RequestShutterSound1((int)p, (char *)a);
        s->shutterPending = 1;
        break;
    case 13:
        CTVT_COMM_StopSession(p, (char *)COMM_TVT_SYS_GetComm(p));
        COMM_TVT_SYS_SetMessageActive(p, 1);
        CTVT_TALK_ShowMessage(p, (char *)s, 0x24);
        s->state = 14;
        CTVT_CAMVIEW_RequestShutterSound1((int)p, (char *)COMM_TVT_SYS_GetCamView(p));
        s->shutterPending = 1;
        break;
    case 14:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3)) {
            s->substate = 7;
            s->state = 3;
            CTVT_CAMVIEW_StopCapture((int)p, (char *)COMM_TVT_SYS_GetCamView(p));
            s->shutterPending = 1;
        }
        break;
    case 15:
        if (CTVT_COMM_SendCommand((int)p, (int)COMM_TVT_SYS_GetComm(p), 10, 0) != 1)
            break;
        a = (u32)COMM_TVT_SYS_GetCamView(p);
        COMM_TVT_SYS_SetMessageActive(p, 1);
        CTVT_CAMVIEW_RequestShutterSound1((int)p, (char *)a);
        s->state = 18;
        break;
    case 16:
        CTVT_COMM_StopSession(p, (char *)COMM_TVT_SYS_GetComm(p));
        CTVT_TALK_ShowMessage(p, (char *)s, 0x25);
        s->state = 17;
        s->promptTimer = 0;
        COMM_TVT_SYS_SetMessageActive(p, 1);
        CTVT_CAMVIEW_RequestShutterSound1((int)p, (char *)COMM_TVT_SYS_GetCamView(p));
        s->shutterPending = 1;
        break;
    case 17:
        s->promptTimer++;
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3) || s->promptTimer >= 300)
            s->state = 18;
        break;
    case 18:
        CTVT_COMM_SetTimingSync(p, (int)COMM_TVT_SYS_GetComm(p), 0x2F);
        s->state = 19;
        break;
    case 19:
        if (CTVT_COMM_IsTimingSync(p, (int)COMM_TVT_SYS_GetComm(p), 0x2F) != 1)
            break;
        s->substate = 7;
        s->state = 3;
        COMM_TVT_SYS_DeleteTimeIcon(p);
        COMM_TVT_SYS_SetMessageActive(p, 1);
        CTVT_CAMVIEW_StopCapture((int)p, (char *)COMM_TVT_SYS_GetCamView(p));
        s->shutterPending = 1;
        break;
    case 20:
        CTVT_COMM_StopSession(p, (char *)COMM_TVT_SYS_GetComm(p));
        CTVT_TALK_ShowMessage(p, (char *)s, 0x26);
        s->state = 21;
        COMM_TVT_SYS_SetMessageActive(p, 1);
        CTVT_CAMVIEW_RequestShutterSound1((int)p, (char *)COMM_TVT_SYS_GetCamView(p));
        s->shutterPending = 1;
        break;
    case 21:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3)) {
            s->substate = 7;
            s->state = 3;
            COMM_TVT_SYS_SetMessageActive(p, 1);
            CTVT_CAMVIEW_StopCapture((int)p, (char *)COMM_TVT_SYS_GetCamView(p));
            s->shutterPending = 1;
        }
        break;
    }
    CTVT_TALK_UpdateVoiceIcon(p, (char *)s);
    CTVT_MIC_Update((u32 *)s->mic);
    if (s->messagePending == 1) {
        void *h = (void *)COMM_TVT_SYS_GetPrintQue(p);
        if (PRINTSYS_QUE_IsExistTarget(h, BMP_WIN_GetBmp((struct Descriptor *)s->messageWin)) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)s->messageWin);
            BMP_WIN_MakeScreen((struct Cfg *)s->messageWin);
            BG_SYS_PushTile(4);
            s->messagePending = 0;
            if (s->timeIconPending == 1) {
                s->timeIconPending = 0;
                COMM_TVT_SYS_CreateTimeIcon(p, s->messageWin);
            }
        }
    }
    if (s->flashActive == 1) {
        s->flashCounter++;
        if (s->flashCounter > 6) {
            s->flashActive = 0;
            NNS_GfdRegisterNewVramTransferTask((void *)0x1F, 0x20, (u32)s->savedPalette, 0x20);
        } else if (s->flashCounter % 12 < 6) {
            NNS_GfdRegisterNewVramTransferTask((void *)0x1F, 0x20, (u32)s->flashPalette, 0x20);
        } else {
            NNS_GfdRegisterNewVramTransferTask((void *)0x1F, 0x20, (u32)s->savedPalette, 0x20);
        }
    }
    if (s->voiceActive == 0 && s->state != 8 && s->state < 11 && CTVT_MIC_GetPlayState(s->mic) == 1) {
        CTVT_TALK_BeginWaveform(p, (char *)s);
        s->voiceActive = 1;
    }
    if (s->voiceActive == 1) {
        if (CTVT_MIC_GetPlayState(s->mic) == 0) {
            s->voiceActive = 0;
            BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)s->waveformWin), 0);
            BMP_WIN_TransferChars((struct Descriptor *)s->waveformWin);
        } else {
            short *base = (short *)(CTVT_COMM_GetVoiceRecord((int)p, (char *)COMM_TVT_SYS_GetComm(p)) + 0x800);
            int n = CTVT_MIC_GetPlayPos(s->mic);
            int max = CTVT_MIC_GetPlayRatio(s->mic);
            int w = CTVT_MIC_GetLength(s->mic);
            if (n > max)
                n = max;
            CTVT_TALK_DrawWaveform((int)p, (char *)s, base, 3, (u32)(w * n) / max, w);
        }
    }
    if (CLACT_IsActorAnimActive((struct Actor *)s->cancelActor) == 0) {
        if (s->state == 10)
            CLACT_SetActorAnimSeq(s->cancelActor, 0xF);
        else
            CLACT_SetActorAnimSeq(s->cancelActor, 1);
    }
    return 1;
}

/*
 * Tail call passing the field at +0x10.
 *
 * evidence: CTVT_MIC_SetMode is ov172's own code (a 2-byte "bx lr" right after
 * the "pop {r4, pc}" at 0x021BA092), inside ov172's window, so only ov172 can
 * be resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference;
 * it attests as sole-ref/code from ov172's own listing.  The old hint ov217
 * named a different overlay's function mapped over the same address.
 *
 * Addresses are Black-image addresses.
 */
void CTVT_TALK_SetMicMode(int unused, char *p)
{
    CTVT_MIC_SetMode((int)((CtvtTalk *)p)->mic);
}

/*
 * note 2026-10-05 wD4 lane03: EXACT. The 0xa4 store is written in each arm (= 2, = 2, = 0)
 *   instead of a local x stored once; tail merging then keeps the later x=2 copy and the first
 *   arm becomes the b stub, as in the listing.
 */
void CTVT_TALK_HandleInput(u8 *c, u8 *q)
{
    u32 a = (u32)COMM_TVT_SYS_GetComm((CtvtWork *)c);
    u32 b = COMM_TVT_SYS_GetMemberCount((CtvtWork *)c);
    int r6;

    if (CTVT_TALK_CheckEnd(c, (int *)q) == 1)
        return;
    if (((CtvtTalk *)q)->state <= 8 && COMM_TVT_SYS_GetViewSwapped((CtvtWork *)c) == 0) {
        u32 s = (u32)COMM_TVT_SYS_GetCamView((CtvtWork *)c);
        if (KEY_GetTrg() & 0x40) CTVT_CAMVIEW_SetCameraEffect((int)c, s, 0);
        if (KEY_GetTrg() & 0x10) CTVT_CAMVIEW_SetCameraEffect((int)c, s, 5);
        if (KEY_GetTrg() & 0x80) CTVT_CAMVIEW_SetCameraEffect((int)c, s, 1);
        if (KEY_GetTrg() & 0x20) CTVT_CAMVIEW_SetCameraEffect((int)c, s, 3);
    }
    if (b == 1 || CTVT_MIC_IsCaptureDone((void *)((CtvtTalk *)q)->mic) == 0) {
        ((CtvtTalk *)q)->voiceIconState = 2;
    } else {
        u32 t = CTVT_COMM_GetHandleNetId(c, a);
        u32 u = CTVT_COMM_GetMarkerSlot((int)c, (char *)a);
        if (u != 0xff) {
            if (u == t) {
                u32 k = ((CtvtTalk *)q)->sendCooldown;
                if (k) {
                    k--;
                    ((CtvtTalk *)q)->sendCooldown = k;
                } else if (CTVT_COMM_SendCommand((int)c, a, 9, 0) == 1) {
                    ((CtvtTalk *)q)->sendCooldown = 8;
                }
            }
            ((CtvtTalk *)q)->voiceIconState = 2;
        } else {
            u32 r = CTVT_TALK_HitCenter((int)c, (int)q, 0);
            if ((KEY_GetTrg() & 0x101) || r == 1) {
                ((CtvtTalk *)q)->state = 6;
                GFL_USE_PlaySeDefaultVolume(0x66C);
                ((CtvtTalk *)q)->flashActive = 1;
                ((CtvtTalk *)q)->flashCounter = 0;
            }
            ((CtvtTalk *)q)->voiceIconState = 0;
        }
    }
    if (((CtvtTalk *)q)->state == 5) {
        if ((KEY_GetTrg() & 0x400) || (KEY_GetTrg() & 0x400) || TOUCHPANEL_HitTrg(d_021C6F83) != -1) {
            ((CtvtTalk *)q)->state = 3;
            ((CtvtTalk *)q)->substate = 6;
            CLACT_SetActorAnimSeq(((CtvtTalk *)q)->backActor, 0x14);
            CLACT_SetActorAutoAnim(((CtvtTalk *)q)->backActor, 1);
            GFL_USE_PlaySeDefaultVolume(0x66C);
        }
    }
    if (((CtvtTalk *)q)->state == 5) {
        r6 = TOUCHPANEL_HitTrg(d_021C6F77);
        if (r6 == 0 || (KEY_GetTrg() & 2)) {
            if (r6 == 0) func_020355D8(1); else func_020355D8(0);
            ((CtvtTalk *)q)->state = 9;
            GFL_USE_PlaySeDefaultVolume(0x551);
            CLACT_SetActorAnimSeq(((CtvtTalk *)q)->cancelActor, 9);
        } else if (r6 == 1 || (KEY_GetTrg() & 0xc)) {
            COMM_TVT_SYS_ToggleViewSwapped((CtvtWork *)c);
            GFL_USE_PlaySeDefaultVolume(0x66F);
            if (COMM_TVT_SYS_GetViewSwapped((CtvtWork *)c) == 1)
                CLACT_SetActorAnimSeq(((CtvtTalk *)q)->swapActor, 0x15);
            else
                CLACT_SetActorAnimSeq(((CtvtTalk *)q)->swapActor, 0x16);
        }
    }
    if (COMM_TVT_SYS_GetSelfSlot((CtvtWork *)c) == 0 && (KEY_GetTrg() & 0x200)) {
        if (CTVT_CAMVIEW_IsLayoutChanging((int)c, (void *)COMM_TVT_SYS_GetCamView((CtvtWork *)c)) == 0) {
            COMM_TVT_SYS_ToggleHalfRes((CtvtWork *)c);
            GFL_USE_PlaySeDefaultVolume(0x66C);
        }
    }
    CTVT_TALK_HandleLevelSlider(c, q);
}

#pragma opt_propagation off

void CTVT_TALK_UpdateVoiceSend(void *ctx, CtvtTalk *st)
{
    int mode = CTVT_TALK_HitCenter((int)ctx, (int)st, 1);
    u32 id;
    u32 pos;
    int busy;
    u32 v;
    u32 off;

    if (CTVT_TALK_CheckEnd(ctx, (int *)st) == 1)
        return;
    switch (st->substate) {
    case 0:
        if (CTVT_MIC_StartCapture((u32 *)st->mic) == 1) {
            st->voiceIconState = 1;
            st->substate = 1;
            st->packetCount = 0;
            st->packetReady = 0;
            CTVT_ADPCM_ResetEncoder();
            CTVT_TALK_BeginWaveform(ctx, (char *)st);
            return;
        }
        break;
    case 1:
        if (mode != 1 && (KEY_GetCont() & 0x101) == 0)
            CTVT_MIC_StopCapture((u32 *)st->mic);
        if (CTVT_MIC_IsCapturing((u32 *)st->mic) == 0) {
            st->substate = 2;
            st->voiceIconState = 2;
        }
        v = CTVT_MIC_GetBuffer((u32 *)st->mic);
        pos = CTVT_MIC_GetReadyBytes((u32 *)st->mic);
        off = 0x800;
        CTVT_TALK_DrawWaveform((int)ctx, (char *)st, (short *)(v + off), 9, pos, 0xC000);
    case 2:
        id = (u32)COMM_TVT_SYS_GetComm(ctx);
        if (CTVT_COMM_GetVoiceStatePending(ctx, (u8 *)id) != 1)
            break;
        busy = CTVT_COMM_IsPostBusy(ctx, (u8 *)id);
        pos = CTVT_MIC_GetReadyBytes((u32 *)st->mic);
        if (st->packetReady == 0 && busy == 0) {
            if (pos >= (u32)(st->packetCount + 1) << 11 || st->substate == 2) {
                int n = CTVT_MIC_EncodeAdpcm((int)st->mic, (u8 *)CTVT_MIC_GetBuffer((u32 *)st->mic) + (st->packetCount << 11), st->packetPayload, 0x800);
                st->packet->index = st->packetCount;
                st->packet->length = n;
                st->packet->position = pos;
                st->packet->level = st->levelIndex;
                st->packet->last = (st->substate == 2 && pos <= (u32)(st->packetCount + 1) << 11) ? 1 : 0;
                st->packetReady = 1;
            }
        }
        if (st->packetReady == 1) {
            if (CTVT_COMM_SendVoiceData(ctx, (char *)id, (u16 *)st->packet) == 1) {
                st->packetCount++;
                st->packetReady = 0;
                if (st->packet->last == 1) {
                    st->substate = 3;
                    return;
                }
            }
        }
        break;
    case 3:
        id = (u32)COMM_TVT_SYS_GetComm(ctx);
        if (CTVT_COMM_IsPostBusy(ctx, (u8 *)id) != 0)
            break;
        if (CTVT_COMM_SendCommand((int)ctx, id, 7, 0) == 1) {
            st->substate = 4;
            BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)st->waveformWin), 0);
            BMP_WIN_TransferChars((struct Descriptor *)st->waveformWin);
            return;
        }
        break;
    case 4:
        if (st->packet->position > 0x20) {
            if (CTVT_MIC_GetPlayState((void *)COMM_TVT_SYS_GetTalkStatus(ctx)) == 1) {
                st->substate = 5;
                return;
            }
        } else {
            st->state = 5;
            return;
        }
        break;
    case 5:
        id = (u32)COMM_TVT_SYS_GetComm(ctx);
        if (CTVT_MIC_GetPlayState((void *)COMM_TVT_SYS_GetTalkStatus(ctx)) == 0) {
            if (CTVT_COMM_SendCommand((int)ctx, id, 8, 0) == 1)
                st->state = 5;
        }
        break;
    }
}

#pragma opt_propagation reset

/*
 * Translates the +0xa4 state into a +0xa0 buffer code, doing nothing when the
 * state already equals the +0xa8 one.
 *
 * Addresses are Black-image addresses.
 */
void CTVT_TALK_UpdateVoiceIcon(void *a0, char *a1)
{
    u32 v = ((CtvtTalk *)a1)->voiceIconState;
    u32 w = ((CtvtTalk *)a1)->voiceIconPrev;

    if (v == w)
        return;
    if (v == 1) {
        CLACT_SetActorAnimSeq(((CtvtTalk *)a1)->voiceActor, 0x17);
        return;
    }
    if (v == 2) {
        CLACT_SetActorAnimSeq(((CtvtTalk *)a1)->voiceActor, 0x23);
        return;
    }
    CLACT_SetActorAnimSeq(((CtvtTalk *)a1)->voiceActor, 0x18);
}

void CTVT_TALK_HandleLevelSlider(void *unused, u8 *q)
{
    u32 a = TOUCHPANEL_HitTrg(d_021C6F8F);
    u32 b = TOUCHPANEL_HitCont(d_021C6F8F);
    int flag = -1;
    int changed = 0;
    if (a != -1) {
        q[15] = 0;
        if (a <= 1) { q[14] = 0; flag = 0; }
        else { q[14] = 1; flag = 1; }
    } else if (b != -1) {
        int agree = 0;
        if (b <= 1) { if (q[14] == 0) agree = 1; }
        else { if (q[14] == 1) agree = 1; }
        if (agree == 1) {
            q[15]++;
            if (*(volatile u8 *)&((CtvtTalk *)q)->sliderHold >= 25) {
                flag = q[14];
                q[15] = 10;
            }
        } else q[14] = 255;
    } else q[14] = 255;
    if (flag == 0) {
        if (q[13] < 8) {
            changed = 1; q[13]++;
            CLACT_SetActorAnimSeq(((CtvtTalk *)q)->levelActor, (u16)(*(volatile u8 *)&((CtvtTalk *)q)->levelIndex + 25));
        }
    } else if (flag == 1) {
        if (q[13] > 0) {
            changed = 1; q[13]--;
            CLACT_SetActorAnimSeq(((CtvtTalk *)q)->levelActor, (u16)(*(volatile u8 *)&((CtvtTalk *)q)->levelIndex + 25));
        }
    }
    if (changed == 1) {
        int angle;
        angle = (q[13] - 4) * 64;
        GFL_USE_PlaySeInSlot((void *)1644, 1);
        GFL_USE_SetSeSlotParams(1, -1, angle, -1);
    }
}

static inline int Abs(int a)
{
    return a < 0 ? -a : a;
}

/*
 * note: Draws a line from (x0, y0) to (x1, y1) into a 4bpp tile buffer with CTVT_TALK_PlotPixel, in
 *   n = max(|dx|, |dy|) + 1 fixed-point steps (step = round(d << 12) / n).
 * lever (2026-10-05, wD9r lane157): value is a narrow parameter (u8 colour index) passed straight
 *   to a u8 callee parameter. With int value the stack-argument copy came first at entry; the narrow
 *   type puts the x0 spill store first (str r3; ldr value; str r2; str value), as in ov127 021C5C8C.
 *   Earlier levers kept: u8 x0 (reloaded at each use), Abs as a static inline ternary, y1/y0 copied
 *   into locals after the dx abs, the y0 read `*(u8 *)&y0` before the loop in an explicit
 *   `if (n > 0)` do/while, stepy declared before stepx.
 */
void CTVT_TALK_DrawLine(int a0, char *a1, u8 *p, u8 x0, u8 y0, u8 x1, u8 y1, u8 value)
{
    int stepx, stepy;
    int dx = Abs(x0 - x1);
    int dy;
    int n, i;
    int accx, accy;
    int d, r;
    int ay; int by; int yb;
    by = y1; ay = y0; dy = Abs(ay - by);
    if (dx <= dy)
        dx = dy;
    n = dx + 1;
    d = x1 - x0;
    if (d > 0)
        r = func_0209C95C(0x3f000000, func_0209BDBC(d << 12));
    else
        r = func_0209CB8C(func_0209BDBC(d << 12), 0x3f000000);
    stepx = func_0209C494(r) / n;
    d = by - ay;
    if (d > 0)
        r = func_0209C95C(0x3f000000, func_0209BDBC(d << 12));
    else
        r = func_0209CB8C(func_0209BDBC(d << 12), 0x3f000000);
    stepy = func_0209C494(r) / n;
    accx = 0;
    accy = 0;
    i = 0;
    if (n > 0) {
        yb = *(u8 *)&y0;
        do {
            CTVT_TALK_PlotPixel(p, x0 + (accx >> 12), yb + (accy >> 12), value);
            accx += stepx;
            accy += stepy;
            i++;
        } while (i < n);
    }
}

/*
 * lever: Explicit weights pointer retains the array base in r1 and cell in r3.
 */
void CTVT_TALK_PlotPixel(u8 *p, u8 x, u8 y, u8 value)
{
    u8 subx = x % 8;
    u8 shift = subx % 4;
    u16 *cell = (u16 *)(p + (u16)((u32)x / 8 + (u32)y / 8 * 16) * 32 + (subx / 4 + (u8)(y % 8) * 2) * 2);
    u16 weights[4];
    u16 *w = weights;
    weights[0] = d_021C6FA0[0];
    weights[1] = d_021C6FA0[1];
    weights[2] = d_021C6FA0[2];
    weights[3] = d_021C6FA0[3];
    if ((u8 *)cell < p + 4096 && (u8 *)cell >= p)
        *cell = (*cell & d_021C6F66[shift]) + w[shift] * value;
}

void CTVT_TALK_ShowMessage(void *p, char *q, int id)
{
    u32 font = COMM_TVT_SYS_GetFont(p);
    u32 msgs = (u32)COMM_TVT_SYS_GetMsgData(p);
    u32 sys = (u32)COMM_TVT_SYS_GetPrintQue(p);
    u32 text;
    PRINTSYS_QUE_Clear((struct PrintSys *)sys);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((CtvtTalk *)q)->messageWin)), 15);
    text = (u32)MSGDATA_AllocString((struct MsgBank *)msgs, id);
    PRINTSYS_PrintQueColor((void *)sys, (u32)BMP_WIN_GetBmp((struct Descriptor *)((CtvtTalk *)q)->messageWin), 0, 0, text, font, 1088);
    STRBUF_Delete((struct U16Vec *)text);
    BMP_WIN_TransferChars((struct Descriptor *)((CtvtTalk *)q)->messageWin);
    BMP_WIN_MakeScreen((struct Cfg *)((CtvtTalk *)q)->messageWin);
    BMP_MENUWORK_DrawWindow((void *)((CtvtTalk *)q)->messageWin, 1, 320, 9);
    ((CtvtTalk *)q)->messagePending = 1;
}

void CTVT_TALK_OpenConfirmMenu(void *p, char *q)
{
    if (CTVT_COMM_GetNetMode((int)p, (char *)COMM_TVT_SYS_GetComm(p)) == 5) {
        CTVT_TALK_ShowMessage(p, q, 32);
    } else if (COMM_TVT_SYS_GetSelfSlot(p) == 0 && COMM_TVT_SYS_GetMemberCount(p) > 1) {
        CTVT_TALK_ShowMessage(p, q, 33);
    } else {
        CTVT_TALK_ShowMessage(p, q, 32);
    }
    ((CtvtTalk *)q)->confirmMenu = COMM_TVT_SYS_OpenConfirmMenu(p);
    ((CtvtTalk *)q)->state = 10;
    if (CLACT_IsActorAnimActive((struct Actor *)((CtvtTalk *)q)->cancelActor) == 0)
        CLACT_SetActorAnimSeq(((CtvtTalk *)q)->cancelActor, 15);
}

void CTVT_TALK_UpdateConfirmMenu(int self, int *q)
{
    int r6;
    u32 r7;

    if (CTVT_TALK_CheckEnd((void *)self, q) == 1) {
        APP_TASKMENU_CloseMenu((void *)q[0x20]);
        q[0x20] = 0;
        return;
    }
    APP_TASKMENU_UpdateMenu((void *)q[0x20]);
    if (APP_TASKMENU_IsFinish((void *)q[0x20]) != 1)
        return;
    if (APP_TASKMENU_GetCursorPos((const u8 *)q[0x20]) == 0) {
        if (CTVT_COMM_GetNetMode(self, (char *)COMM_TVT_SYS_GetComm((void *)self)) == 5) {
            q[0] = 0xF;
            q[0x21] = 1;
            CTVT_TALK_ShowMessage((void *)self, (char *)q, 0x2A);
        } else if (COMM_TVT_SYS_GetSelfSlot((void *)self) == 0 && COMM_TVT_SYS_GetMemberCount((void *)self) > 1) {
            q[0] = 0xB;
        } else {
            q[1] = 7;
            q[0] = 3;
            r6 = 1;
            COMM_TVT_SYS_SetMessageActive((void *)self, 1);
            r7 = (u32)COMM_TVT_SYS_GetCamView((void *)self);
            CTVT_CAMVIEW_StopCapture(self, (char *)r7);
            CTVT_CAMVIEW_RequestShutterSound1(self, (char *)r7);
            q[2] = r6;
        }
    } else {
        q[0] = 5;
        BMP_MENUWORK_DrawWindowBorder((void *)q[0x1F], 1);
        BMP_WIN_ClearScreen((struct Descriptor *)q[0x1F]);
        BMP_WIN_MakeScreen((struct Cfg *)q[0xB]);
        BG_SYS_PushTile(4);
        CLACT_SetActorAnimSeq((struct ClActor *)q[0x26], 1);
    }
    APP_TASKMENU_CloseMenu((void *)q[0x20]);
    q[0x20] = 0;
}

/*
 * Maps the +4 state to an output code through the two ARM9 probes.
 *
 * Addresses are Black-image addresses.
 */
int CTVT_TALK_CheckEnd(void *p, int *out)
{
    if (COMM_TVT_SYS_GetEndRequested(p) == 1) {
        int v = CTVT_COMM_GetNetMode((int)p, (char *)COMM_TVT_SYS_GetComm(p));

        *out = (v == 5) ? 0x10 : 0xd;
        return 1;
    }
    if (COMM_TVT_SYS_GetMemberCount(p) <= 1) {
        *out = 0x14;
        return 1;
    }
    return 0;
}

void CTVT_TALK_BeginWaveform(void *p, char *q)
{
    q[0x30] = 3;
    q[0x31] = 0x20;
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)((CtvtTalk *)q)->waveformWin)), 0);
}

void CTVT_TALK_DrawWaveform(int a0, char *obj, s16 *tbl, u8 a3, int idx, u16 v)
{
    u32 n;
    void *dev;
    int flag;
    u8 c;
    int h;
    int x;
    u32 c1;

    if (idx < 0)
        return;
    n = func_0209C0A4(idx * 0x7B, v);
    dev = BMP_GetPixels(BMP_WIN_GetBmp((struct Descriptor *)((CtvtTalk *)obj)->waveformWin));
    flag = 0;
    c = ((CtvtTalk *)obj)->waveX;
    if (c < n) {
        flag = 1;
        while (c < n) {
            c1 = c + 1;
            x = c1 * v;
            h = ((tbl[x / 128 / 2] + 0x8000) << 6) / 0x10000;
            if (c < 0xB) {
                u32 t = 0x20 - d_021C6F6E[c - 3];
                if (h < t)
                    h = t;
            }
            if (c > 0x72) {
                u32 t = 0x20 - d_021C6F6E[(u8)(0x7A - c)];
                if (h < t)
                    h = t;
            }
            CTVT_TALK_DrawLine(a0, obj, dev, c, ((CtvtTalk *)obj)->waveY, (u8)c1, (u8)h, a3);
            ((CtvtTalk *)obj)->waveX += 1;
            ((CtvtTalk *)obj)->waveY = (u8)h;
            c = ((CtvtTalk *)obj)->waveX;
        }
    }
    if (flag == 1)
        BMP_WIN_TransferChars((struct Descriptor *)((CtvtTalk *)obj)->waveformWin);
}

/*
 * extent: Two bytes of zero alignment padding follow the return.
 */
int CTVT_TALK_HitCenter(int a, int b, int mode)
{
    u32 x, y;
    int dx, dy, d;
    if (mode == 0) TOUCHPANEL_GetPointTrg(&x, &y);
    else TOUCHPANEL_GetPointCont(&x, &y);
    if (y >= 104) {
        dx = 128 - x;
        dy = 104 - y;
        d = dx * dx + dy * dy;
        if (d > 256 && d < 5184) return 1;
    }
    return 0;
}

int CTVT_TALK_GetMic(int unused, int *p)
{
    return p[4];
}
