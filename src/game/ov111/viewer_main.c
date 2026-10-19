/*
 * file:     viewer_main.c
 * unit:     yes
 * function: VIEWER_MAIN_Create, VIEWER_MAIN_InitInfo, VIEWER_MAIN_PlaySe, VIEWER_MAIN_Main, VIEWER_MAIN_Delete, VIEWER_MAIN_LoadResources, VIEWER_MAIN_FreeResources, VIEWER_MAIN_SetupBgSlot, VIEWER_MAIN_ClearBgSlot, VIEWER_MAIN_InitBg, VIEWER_MAIN_GetBgParamA, VIEWER_MAIN_GetBgParamB, VIEWER_MAIN_LoadBgResources, VIEWER_MAIN_ExitBg, VIEWER_MAIN_SetBgSlotKind, VIEWER_MAIN_ResetBgSlot, VIEWER_MAIN_Draw, VIEWER_MAIN_UpdateRowA, VIEWER_MAIN_UpdateRowB, VIEWER_MAIN_UpdateRowC, VIEWER_MAIN_UpdateRows, VIEWER_MAIN_Update, VIEWER_MAIN_SetWindowPlane, VIEWER_MAIN_UpdateWindows, VIEWER_MAIN_InitBrightness, VIEWER_MAIN_CheckInputModeSwitch, VIEWER_MAIN_HandleKey, VIEWER_MAIN_ToggleFavorite, VIEWER_MAIN_SetRowState, VIEWER_MAIN_SetRowDrawEnable, VIEWER_MAIN_DrawRowBg, VIEWER_MAIN_HitRow, VIEWER_MAIN_HandleRowTouch, VIEWER_MAIN_HandleRowKey, VIEWER_MAIN_HandlePageTouch, VIEWER_MAIN_HandlePageInput, VIEWER_MAIN_HandleInput, VIEWER_MAIN_UpdateInput, VIEWER_MAIN_DrawSelected, VIEWER_MAIN_VBlank, VIEWER_MAIN_InitLcdBrightness, VIEWER_MAIN_UploadBg, VIEWER_MAIN_SetWindowRect, VIEWER_MAIN_CopyBg3, VIEWER_MAIN_CopyBg6, VIEWER_MAIN_ClearBgBuf, VIEWER_MAIN_UploadBgBuf, VIEWER_MAIN_ClearBg, VIEWER_MAIN_UpdateBrightness, VIEWER_MAIN_CheckTouch, VIEWER_MAIN_HandleScrollTouch, VIEWER_MAIN_BlitRect, VIEWER_MAIN_BlitBrush, VIEWER_MAIN_CopyTouchPos, VIEWER_MAIN_DrawBrushStroke
 * address:  0x021C3CC0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb
 *   WIPE_ResetWndMask  0x02022224  thumb
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   UI_GetInputMode  0x020355C4  arm
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   PMS_DRAW_Create  0x0202DB0C  thumb
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   TCBL_Create  0x0203101C  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   VIEWER_TEXT_InitActors  0x021C6D9C  thumb  ov111
 *   VIEWER_TEXT_BuildRowList  0x021C6804  thumb  ov111
 *   VIEWER_TEXT_CreateActor  0x021C6E8C  thumb  ov111
 *   VIEWER_TEXT_Init  0x021C6000  thumb  ov111
 *   VIEWER_TEXT_NoOp  0x021C6D98  thumb  ov111
 *   d_021C8564     0x021C8564  data  a4
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   CLACT_DrawSystem  0x0204A600  arm
 *   PMS_DRAW_Main  0x0202DBC4  thumb
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   TCBL_Main  0x020310C4  arm
 *   GAME_DATA_GetTrainerCardSign  0x02012F5C  thumb
 *   TRCARD_SIGN_GetBitmap  0x020089CC  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_SetOutfit  0x02008558  thumb
 *   TRCARD_SIGN_SetColor  0x02008A14  thumb
 *   TRCARD_SIGN_SetStyle  0x02008A1C  thumb
 *   PMS_DRAW_Delete  0x0202DC08  thumb
 *   VIEWER_TEXT_DeleteActors  0x021C6F4C  thumb  ov111
 *   GFL_HEAP_Free  0x020307B0  arm
 *   VIEWER_TEXT_Exit  0x021C60A0  thumb  ov111
 *   TCB_DeleteTask  0x02030EAC  arm
 *   TCBL_Destroy  0x02031140  arm
 *   UI_SetInputMode  0x020355D8  arm
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   WORDSET_Delete  0x0201ED04  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive  0x02049F34  arm
 *   d_021C8E20     0x021C8E20  data  a4
 *   d_021C86E8     0x021C86E8  data  a4
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   d_021C85C8     0x021C85C8  data  a4
 *   d_021C85E8     0x021C85E8  data  a4
 *   d_021C8608     0x021C8608  data  a4
 *   d_021C8628     0x021C8628  data  a4
 *   d_021C8648     0x021C8648  data  a4
 *   d_021C8668     0x021C8668  data  a4
 *   ARC_UTIL_LoadBgCharDataFromArchive  0x02049DB4  arm
 *   ARC_UTIL_LoadPaletteDataFromArchive  0x02049EB4  arm
 *   ARC_UTIL_UploadBgCharFromArchive  0x02049624  arm
 *   ARC_UTIL_UploadBgPaletteFromArchive  0x0204989C  arm
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   APP_ICON_GetStatusFrameFileId  0x02027628  thumb
 *   APP_ICON_GetStatusDataFileId  0x0202762C  thumb
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   BG_SYS_ChangeScrollImmediate  0x02040618  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   d_021C85D8     0x021C85D8  data  a4
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   VIEWER_TEXT_Draw  0x021C60CC  thumb  ov111
 *   VIEWER_TEXT_DrawPage  0x021C6874  thumb  ov111
 *   VIEWER_TEXT_DrawWindow  0x021C636C  thumb  ov111
 *   VIEWER_TEXT_FlushWindow  0x021C631C  thumb  ov111
 *   VIEWER_TEXT_SetActorAnim  0x021C6FA0  thumb  ov111
 *   GAME_DATA_ContainsRecentId  0x02012BF8  thumb
 *   PMS_DRAW_SetDecoVisible  0x0202DCD4  thumb
 *   PMS_DRAW_SetVisible  0x0202DCB0  thumb
 *   _ll_mul          0x0209C054  arm
 *   FX_SinCosTable_  0x020A1B38  data
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   FX_Inv  0x0207C778  arm
 *   G2x_SetBGyAffine_  0x0207D59C  arm
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   KEY_GetCont  0x0203630C  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   GAME_DATA_SetRecentId  0x02012BE0  thumb
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   TOUCHPANEL_HitCont  0x02035BA4  arm
 *   d_021C8544     0x021C8544  data  a1
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   d_021C8554     0x021C8554  data  a1
 *   d_021C8594     0x021C8594  data  a1
 *   TRCARD_SIGN_SetSeenBefore  0x02008A00  thumb
 *   VIEWER_TEXT_DrawTable  0x021C61EC  thumb
 *   VIEWER_TEXT_DrawList  0x021C628C  thumb
 *   BG_SYS_Update  0x020419E4  arm
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   OS_WaitVBlankIntr  0x02087AE4  arm
 *   BG_SYS_LoadTileData  0x02040B1C  arm
 *   BG_SYS_DrawTileEx  0x020410D0  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   GXS_LoadBGPltt  0x0207E468  arm
 *   d_021C8534     0x021C8534  data  a1
 *   d_021C854C     0x021C854C  data  a1
 *   TOUCHPANEL_HitPoint  0x02035D40  arm
 *   d_021C852C     0x021C852C  data  a1
 *   d_021C853C     0x021C853C  data  a1
 *   d_021C86A8     0x021C86A8  data  a1
 */
#include "viewer_types.h"
#define REG_DB_DISPCNT  (*(volatile u32 *)0x04001000)
#define REG_DB_WIN0H    (*(volatile u16 *)0x04001040)
#define REG_DB_WIN0V    (*(volatile u16 *)0x04001044)
#define REG_DB_WININ    (*(volatile u16 *)0x04001048)
#define REG_DB_WINOUT   (*(volatile u16 *)0x0400104A)
#define REG_DB_BLDCNT   (*(volatile u16 *)0x04001050)
struct PmsDraw;
struct Proc;
struct Tcbl;
struct DispVram;
struct Actor;
struct PrintSys;
struct Node;
struct Obj;
struct Proc;
struct Sub0200852CObj;
struct Sub020089A8Obj;
struct S02031140;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Rec;
struct Ctx;



















































struct DispConfig {
    u32 w[4];
};

struct BgTemplate {
    u32 w[8];
};

struct BgTemplatePair {
    struct BgTemplate t[2];
};











typedef struct {
    u32 file[2][2];
} FileTable;




























struct Mtx {
    fx32 _00;
    fx32 _01;
    fx32 _10;
    fx32 _11;
};





















































































extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void WIPE_SetBrightnessFadeOut(u32 a, u32 b);
extern u32 WIPE_ResetWndMask(void *win);
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *p, u32 v, u32 n);
extern u8 UI_GetInputMode(void);
extern signed char MSG_SPEED_GetWait(void);
extern int GFL_NET_GetNegotiationNum(void);
extern void BG_SYS_Create(u16 heap);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern struct PmsDraw *PMS_DRAW_Create(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
extern void *GFL_USE_AddMainTask(void (*cb)(void *, ViewerWork *), void *ctx, int pri);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void WIPE_SYS_Start(void *divisionMode, u32 mainPattern, u32 subPattern, u32 color, u32 frames, u32 wait, u32 heapId);
extern void VIEWER_TEXT_InitActors(ViewerAnim *a, const void *cfg);
extern void VIEWER_TEXT_BuildRowList(ViewerWork *p, ViewerInfo *info);
extern void VIEWER_TEXT_CreateActor(ViewerAnim *a);
extern void VIEWER_TEXT_Init(ViewerWork *p);
extern void VIEWER_TEXT_NoOp(ViewerWork *p, void *bg, u32 a, void *b);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void CLACT_DrawSystem(void);
extern void PMS_DRAW_Main(u8 *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void TCBL_Main(struct Tcbl *p);
extern void *GAME_DATA_GetTrainerCardSign(void **h);
extern void *TRCARD_SIGN_GetBitmap(void *p);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void MYSTATUS_SetOutfit(struct Sub0200852CObj *obj, u8 value);
extern void TRCARD_SIGN_SetColor(void *p, u32 v);
extern void TRCARD_SIGN_SetStyle(struct Sub020089A8Obj *obj, u8 value);
extern void PMS_DRAW_Delete(struct Obj *p);
extern void VIEWER_TEXT_DeleteActors(ViewerAnim *a);
extern u32 GFL_HEAP_Free(void *p);
extern void VIEWER_TEXT_Exit(ViewerWork *p);
extern void TCB_DeleteTask(struct Node *n);
extern void TCBL_Destroy(struct S02031140 *p);
extern void UI_SetInputMode(u32 v);
extern void PROCSYS_FreeProcWork(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(u32 heap);
extern struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern u32 WORDSET_Delete(struct WordSet *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 archiveID, u32 memberIdx, u32 unpackedOut, u32 flags);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u32 bgId);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void *ARC_UTIL_LoadBgCharDataFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);
extern void *ARC_UTIL_LoadPaletteDataFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);
extern u32 ARC_UTIL_UploadBgCharFromArchive(void *archiveID, void *memberIdx, void *bgId, void *tileOffset, u32 size, u32 heapID, u16 allocFlags);
extern void ARC_UTIL_UploadBgPaletteFromArchive(u32 archiveID, u32 memberIdx, u32 channel, u32 offset, u32 size, u32 heapID, u16 flags);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetStatusFrameFileId(void);
extern u32 APP_ICON_GetStatusDataFileId(void);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BG_SYS_PushTile(u32 layer);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_ChangeScrollImmediate(u32 bgId, u32 which, u32 value);
extern void BG_SYS_FreeLayerBuf(u32 bgId);
extern void BG_SYS_Delete(void);
extern void BG_SYS_ClearSlot(u32 i);
extern void VIEWER_TEXT_Draw(ViewerWork *p, void **bg, ViewerInfo *info);
extern void VIEWER_TEXT_DrawPage(ViewerWork *p, int scroll, int flush, int idx);
extern void VIEWER_TEXT_DrawWindow(ViewerWork *p, void **bg, ViewerInfo *info);
extern void VIEWER_TEXT_FlushWindow(ViewerWork *p, void **bg);
extern void VIEWER_TEXT_SetActorAnim(ViewerAnim *a, int idx, u8 x, u8 y);
extern int GAME_DATA_ContainsRecentId(int gd, int id);
extern void PMS_DRAW_SetDecoVisible(struct PmsDraw *p, u32 i, u32 val);
extern void PMS_DRAW_SetVisible(struct PmsDraw *o, int i, u32 visible);
extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
extern fx32 FX_Inv(fx32 v);
extern void G2x_SetBGyAffine_(void *reg, struct Mtx *m, u32 a, u32 b, u32 x, u32 y);
extern int TOUCHPANEL_GetCont(void);
extern unsigned int KEY_GetCont(void);
extern u32 KEY_GetTrg(void);
extern void GAME_DATA_SetRecentId(void *p, u32 a, u32 b);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int TOUCHPANEL_HitCont(const void *p);
extern int TOUCHPANEL_HitTrg(const void *rect);
extern int TOUCHPANEL_GetTrg(void);
extern u32 TOUCHPANEL_GetPointTrg(u32 *x, u32 *y);
extern struct Sub020089A8Obj *TRCARD_SIGN_SetSeenBefore(struct Sub020089A8Obj *obj);
extern void VIEWER_TEXT_DrawTable(ViewerWork *p, int v, int a);
extern void VIEWER_TEXT_DrawList(ViewerWork *p, int v, int a);
extern void BG_SYS_Update(void);
extern void CLACT_VBlankSystem(void);
extern void OS_WaitVBlankIntr(void);
extern void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);
extern void BG_SYS_DrawTileEx(u32 index, u32 dx, u32 dy, u32 cw, u8 ch, u32 src, u8 sx, u8 sy, u8 sw, u8 sh);
extern void BG_SYS_SetTileEntry(u32 layer, int value, int x0, int y0, u8 w, u8 h, u8 mode);
extern u32 BG_SYS_GetBuf(int channel);
extern void BG_SYS_MarkTileDirty(u32 bit);
extern void GXS_LoadBGPltt(const void *src, u32 offset, u32 size);
extern u32 TOUCHPANEL_HitPoint(struct Ctx *ctx, u32 a, u32 b);
int VIEWER_MAIN_Create(void *man, int *state, ViewerArgs *args);
void VIEWER_MAIN_InitInfo(ViewerInfo *info);
void VIEWER_MAIN_PlaySe(ViewerWork *p, int speed);
int VIEWER_MAIN_Main(void *proc, int *seq, int c, ViewerWork *p);
int VIEWER_MAIN_Delete(void *man, int *state, ViewerArgs *args, ViewerWork *p);
void VIEWER_MAIN_LoadResources(ViewerWork *p);
void VIEWER_MAIN_FreeResources(ViewerWork *p);
void VIEWER_MAIN_SetupBgSlot(ViewerWork *p, int k, int alt);
void VIEWER_MAIN_ClearBgSlot(ViewerWork *p, int k);
void VIEWER_MAIN_InitBg(void);
int VIEWER_MAIN_GetBgParamA(int x);
int VIEWER_MAIN_GetBgParamB(int x);
void VIEWER_MAIN_LoadBgResources(ViewerWork *p);
void VIEWER_MAIN_ExitBg(void);
void VIEWER_MAIN_SetBgSlotKind(ViewerWork *p, int kind);
void VIEWER_MAIN_ResetBgSlot(ViewerWork *p);
void VIEWER_MAIN_Draw(ViewerWork *p);
void VIEWER_MAIN_UpdateRowA(ViewerWork *p, int flag);
void VIEWER_MAIN_UpdateRowB(ViewerWork *p, int flag);
void VIEWER_MAIN_UpdateRowC(ViewerWork *p, int flag);
void VIEWER_MAIN_UpdateRows(ViewerWork *p, int flag);
int VIEWER_MAIN_Update(ViewerWork *p);
void VIEWER_MAIN_SetWindowPlane(int side);
int VIEWER_MAIN_UpdateWindows(char *p);
void VIEWER_MAIN_InitBrightness(ViewerWork *p);
int VIEWER_MAIN_CheckInputModeSwitch(ViewerWork *p);
int VIEWER_MAIN_HandleKey(ViewerWork *p);
void VIEWER_MAIN_ToggleFavorite(ViewerWork *p);
void VIEWER_MAIN_SetRowState(ViewerWork *p, int flag, int v);
void VIEWER_MAIN_SetRowDrawEnable(ViewerWork *p, int flag);
void VIEWER_MAIN_DrawRowBg(ViewerWork *p, int flag);
int VIEWER_MAIN_HitRow(ViewerWork *p, int hit);
int VIEWER_MAIN_HandleRowTouch(ViewerWork *p, int hit);
int VIEWER_MAIN_HandleRowKey(ViewerWork *p, int hit);
void VIEWER_MAIN_HandlePageTouch(ViewerWork *p);
void VIEWER_MAIN_HandlePageInput(ViewerWork *p);
int VIEWER_MAIN_HandleInput(ViewerWork *p);
int VIEWER_MAIN_UpdateInput(ViewerWork *p);
void VIEWER_MAIN_DrawSelected(ViewerWork *p, int sel, int *seq);
void VIEWER_MAIN_VBlank(void *task, ViewerWork *p);
void VIEWER_MAIN_InitLcdBrightness(void);
void VIEWER_MAIN_UploadBg(ViewerWork *p);
void VIEWER_MAIN_SetWindowRect(void *p);
void VIEWER_MAIN_CopyBg3(const u8 *src, u8 *dst);
void VIEWER_MAIN_CopyBg6(const u8 *src, u8 *dst);
void VIEWER_MAIN_ClearBgBuf(u32 bg, int mode);
void VIEWER_MAIN_UploadBgBuf(u32 bg, const void *src, int mode);
void VIEWER_MAIN_ClearBg(ViewerWork *p);
void VIEWER_MAIN_UpdateBrightness(ViewerWork *p);
void VIEWER_MAIN_CheckTouch(ViewerWork *p);
void VIEWER_MAIN_HandleScrollTouch(ViewerWork *p, int side);
void VIEWER_MAIN_BlitRect(u8 *dst, const u8 *src, int x, int y, int w, int h, int mode, int sel);
int VIEWER_MAIN_BlitBrush(u8 *pix, const u8 *brush, int x1, int y1, int *px, int *py, int a, int b, int clip, int side);
void VIEWER_MAIN_CopyTouchPos(ViewerTouchPos *src, ViewerTouchPos *dst);
int VIEWER_MAIN_DrawBrushStroke(u8 *pix, ViewerTouchPos *cur, ViewerTouchPos *prev, int flush, const void *src, u8 clip, u8 side);
extern const u8 d_021C8564[];
extern const u32 d_021C8E20[][2];
extern const u32 d_021C86E8[][2];
extern const struct DispConfig d_021C85C8;
extern const struct BgTemplate d_021C85E8;
extern const struct BgTemplate d_021C8608;
extern const struct BgTemplate d_021C8628;
extern const struct BgTemplate d_021C8648;
extern const struct BgTemplatePair d_021C8668;
extern const FileTable d_021C85D8;
extern s16 FX_SinCosTable_[];
extern const u8 d_021C8544[];
extern const u8 d_021C8554[];
extern const u8 d_021C8594[];
extern const u8 d_021C8534[];
extern const u8 d_021C854C[];
extern const u8 d_021C852C[];
extern const u8 d_021C853C[];
extern const u8 d_021C86A8[2][2][16];









int VIEWER_MAIN_Create(void *man, int *state, ViewerArgs *args)
{
    ViewerWork *p;
    int i;
    u16 mask;

    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)0x04000000 &= ~0x1F00;
    *(volatile u32 *)0x04001000 &= ~0x1F00;
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask((void *)1);
    GFL_HEAP_CreateChildHeap(1, 0x27, 0x50000);
    p = PROCSYS_AllocProcWork(man, sizeof(ViewerWork), 0x27);
    MI_CpuFill8(p, 0, sizeof(ViewerWork));
    p->heap = 0x27;
    p->anim.heap = 0x27;
    p->args = args;
    p->info = args->info;
    p->mode = UI_GetInputMode();
    p->msgSpeed = MSG_SPEED_GetWait();
    p->charVariant = 0;
    if (p->info->month2) {
        p->hasInfo = 1;
    } else {
        p->hasInfo = 0;
    }
    mask = 1;
    for (i = 0; i < 16; i++) {
        if (p->info->rowMask & mask) {
            p->flags[i] = 1;
        } else {
            p->flags[i] = 0;
        }
        mask <<= 1;
    }
    if (GFL_NET_GetNegotiationNum() > 0) {
        p->netActive = 1;
    }
    BG_SYS_Create(p->heap);
    VIEWER_MAIN_LoadResources((ViewerWork *)p);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021C8564);
    VIEWER_MAIN_InitBg();
    VIEWER_MAIN_LoadBgResources((ViewerWork *)p);
    VIEWER_TEXT_InitActors((ViewerAnim *)(&p->anim), d_021C8564);
    VIEWER_TEXT_BuildRowList(p, p->args->info);
    VIEWER_TEXT_CreateActor((ViewerAnim *)(&p->anim));
    VIEWER_TEXT_Init(p);
    p->pmsDraw = PMS_DRAW_Create((u32)p->anim.unit, 1, (u32)p->printQue, (u32)p->font, 8, 1, 0x27);
    VIEWER_TEXT_NoOp(p, p->bg[4], 1, p->strbuf1);
    if (p->args->decoMode == 2) {
        p->args->decoMode = 0;
        p->decoVisible = 1;
    } else {
        p->decoVisible = 0;
    }
    p->args->exitCode = 0;
    p->keyRepeat = 0;
    p->counter = 0;
    if (p->info->f4_4) {
        p->phase = 0;
    } else {
        p->phase = 2;
    }
    p->cx = 0x80;
    p->cy = 0x60;
    p->x = 0;
    p->y = 0;
    VIEWER_MAIN_InitLcdBrightness();
    VIEWER_MAIN_Draw((ViewerWork *)p);
    p->vblankTask = GFL_USE_AddMainTask(VIEWER_MAIN_VBlank, p, 1);
    p->tcbl = TCBL_Create(p->heap, p->heap, 3, 0);
    GFL_NET_RestartWithDefaultTimeout(1, p->heap);
    WIPE_SYS_Start((void *)1, 3, 3, 0, 6, 1, p->heap);
    return 1;
}









/*
 * Addresses are Black-image addresses.
 */
void VIEWER_MAIN_InitInfo(ViewerInfo *info)
{
    info->rowIndex++;
    if (info->rowIndex > (info->f4_1 + 1) * 8 - 1) {
        info->rowIndex = info->f4_1 * 8;
    }
}









void VIEWER_MAIN_PlaySe(ViewerWork *p, int speed)
{
    if (p->cooldown != 0) {
        p->cooldown--;
        return;
    }
    if (speed > 5) {
        p->cooldown = 5;
        if (p->size == 0) {
            GFL_USE_PlaySeDefaultVolume(0x65C);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x7CF);
        }
    }
}









int VIEWER_MAIN_Main(void *proc, int *seq, int c, ViewerWork *p)
{
    switch (*seq) {
    case 0:
        if (WIPE_SYS_EndCheck()) {
            *seq = 1;
        }
        break;
    case 1:
        VIEWER_MAIN_DrawSelected((ViewerWork *)p, VIEWER_MAIN_UpdateInput((ViewerWork *)p), (int *)seq);
        VIEWER_MAIN_ClearBg((ViewerWork *)p);
        if (p->args->info->f4_6) {
            VIEWER_MAIN_PlaySe((ViewerWork *)p, VIEWER_MAIN_DrawBrushStroke((u8 *)p->pix, (ViewerTouchPos *)(&p->cur), (ViewerTouchPos *)(&p->prev), 1, p->pix, p->inputMode, p->pane));
        }
        break;
    case 2:
        if (CLACT_IsActorAnimActive(p->anim.obj[0]) == 0) {
            WIPE_SYS_Start((void *)2, 4, 4, 0, 6, 1, p->heap);
            *seq = 4;
        }
        break;
    case 3:
        if (CLACT_IsActorAnimActive(p->anim.obj[1]) == 0) {
            WIPE_SYS_Start((void *)2, 4, 4, 0, 6, 1, p->heap);
            *seq = 4;
        }
        break;
    case 4:
        if (WIPE_SYS_EndCheck()) {
            return 1;
        }
        break;
    case 5:
        if (VIEWER_MAIN_Update((ViewerWork *)p)) {
            *seq = 1;
        }
        break;
    case 9:
        if (VIEWER_MAIN_UpdateWindows((char *)p)) {
            *seq = 1;
        }
        break;
    case 6:
        WIPE_SYS_Start((void *)2, 4, 4, 0, 6, 1, p->heap);
        p->args->exitCode = 1;
        *seq = 4;
        break;
    case 7:
        if (CLACT_IsActorAnimActive(p->anim.obj[2]) == 0) {
            WIPE_SYS_Start((void *)2, 4, 4, 0, 6, 1, p->heap);
            p->args->exitCode = 2;
            *seq = 4;
        }
        break;
    case 8:
        break;
    }
    p->shake++;
    if (p->shake >= 0x100) {
        p->shake = 0;
    }
    CLACT_DrawSystem();
    PMS_DRAW_Main(p->pmsDraw);
    PRINTSYS_QUE_Main(p->printQue);
    if (p->tcbl) {
        TCBL_Main(p->tcbl);
    }
    return 0;
}









/*
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * Addresses are Black-image addresses.
 */
int VIEWER_MAIN_Delete(void *man, int *state, ViewerArgs *args, ViewerWork *p)
{
    void *a;
    void *b;

    if (!p->info->f4_5) {
        VIEWER_MAIN_CopyBg6(p->pix, p->info->bitmap);
        MI_CpuCopy8(p->info->bitmap, TRCARD_SIGN_GetBitmap(GAME_DATA_GetTrainerCardSign(p->args->gameData)), 0x600);
    }
    if (args->editMode != 0) {
        a = GAME_DATA_GetMyStatus(p->args->gameData);
        b = GAME_DATA_GetTrainerCardSign(p->args->gameData);
        MYSTATUS_SetOutfit(a, p->info->rowIndex);
        TRCARD_SIGN_SetColor(b, p->info->listIndex);
        TRCARD_SIGN_SetStyle(b, p->info->f4_4);
    }
    PMS_DRAW_Delete(p->pmsDraw);
    VIEWER_MAIN_InitLcdBrightness();
    VIEWER_MAIN_FreeResources((ViewerWork *)p);
    VIEWER_TEXT_DeleteActors((ViewerAnim *)(&p->anim));
    GFL_HEAP_Free(p->chrHandle);
    GFL_HEAP_Free(p->scrnRes);
    GFL_HEAP_Free(p->plttRes);
    VIEWER_TEXT_Exit(p);
    VIEWER_MAIN_ExitBg();
    TCB_DeleteTask(p->vblankTask);
    TCBL_Destroy((struct S02031140 *)p->tcbl);
    UI_SetInputMode(p->mode);
    PROCSYS_FreeProcWork(man);
    GFL_HEAP_DeleteChecked(0x27);
    return 1;
}









void VIEWER_MAIN_LoadResources(ViewerWork *p)
{
    int i;

    p->font = GF_FONT_Create(0x17, 0, 0, 0, p->heap);
    p->msgBank = MSGDATA_CreateFromArchive(0, 2, 0xBB, p->heap);
    p->strbuf0 = STRBUF_Create(4, p->heap);
    p->strbuf2 = STRBUF_Create(0x20, p->heap);
    p->strbuf3 = STRBUF_Create(0x21, p->heap);
    p->strbuf1 = STRBUF_Create(5, p->heap);
    MSGDATA_ReadString(p->msgBank, 0x17, p->strbuf1);
    for (i = 0; i < 3; i++) {
        p->headerText[i] = MSGDATA_AllocString(p->msgBank, i + 0x1A);
    }
    for (i = 0; i < 2; i++) {
        p->footerText[i] = MSGDATA_AllocString(p->msgBank, i + 0x1D);
    }
    for (i = 0; i < 26; i++) {
        p->msgText[i] = MSGDATA_AllocString(p->msgBank, i);
    }
    for (i = 0; i < 5; i++) {
        p->taggedText[i] = MSGDATA_AllocString(p->msgBank, i + 0x38);
    }
    p->wordSet = WORDSET_CreateDefault(p->heap);
}









void VIEWER_MAIN_FreeResources(ViewerWork *p)
{
    int i;

    WORDSET_Delete(p->wordSet);
    for (i = 0; i < 5; i++) {
        STRBUF_Delete(p->taggedText[i]);
    }
    for (i = 0; i < 26; i++) {
        STRBUF_Delete(p->msgText[i]);
    }
    STRBUF_Delete(p->footerText[1]);
    STRBUF_Delete(p->footerText[0]);
    STRBUF_Delete(p->headerText[2]);
    STRBUF_Delete(p->headerText[1]);
    STRBUF_Delete(p->headerText[0]);
    STRBUF_Delete(p->strbuf1);
    STRBUF_Delete(p->strbuf3);
    STRBUF_Delete(p->strbuf2);
    STRBUF_Delete(p->strbuf0);
    MSGDATA_Delete(p->msgBank);
    GF_FONT_Delete(p->font);
}









void VIEWER_MAIN_SetupBgSlot(ViewerWork *p, int k, int alt)
{
    int j = 1;
    u32 file;

    if (p->info->kind == 0x14) {
        j = 0;
    } else if (p->info->kind != 0x15) {
        k = 6;
    }
    file = d_021C8E20[k][j];
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x28, file, 4, 0, 0x200, p->heap);
    p->plttRes = ARC_UTIL_LoadPaletteBlockFromArchive(0x28, file, (u32)(&p->pltt), p->heap);
}









void VIEWER_MAIN_ClearBgSlot(ViewerWork *p, int k)
{
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x29, d_021C86E8[k][1], 4, 0x80, 0x20, p->heap);
}









void VIEWER_MAIN_InitBg(void)
{
    *(volatile u16 *)0x04000304 |= 0x8000;
    {
        struct DispConfig disp = d_021C85C8;
        BG_SYS_SetGraphicsMode(&disp);
    }
    {
        struct BgTemplate t = d_021C85E8;
        BG_SYS_InitBgLayer(7, &t, 2);
        BG_SYS_FreeSlot(7);
        BG_SYS_SetPlaneVisible(7, 1);
    }
    {
        struct BgTemplatePair t = d_021C8668;
        BG_SYS_InitBgLayer(4, &t.t[0], 0);
        BG_SYS_FreeSlot(4);
        BG_SYS_SetPlaneVisible(4, 1);
        BG_SYS_InitBgLayer(5, &t.t[1], 0);
        BG_SYS_FreeSlot(5);
        BG_SYS_SetPlaneVisible(5, 1);
    }
    {
        struct BgTemplate t = d_021C8608;
        BG_SYS_InitBgLayer(6, &t, 2);
        BG_SYS_FreeSlot(6);
        BG_SYS_SetPlaneVisible(6, 1);
    }
    {
        struct BgTemplate t = d_021C8628;
        BG_SYS_InitBgLayer(2, &t, 0);
        BG_SYS_FreeSlot(2);
        BG_SYS_SetPlaneVisible(2, 0);
    }
    {
        struct BgTemplate t = d_021C8648;
        BG_SYS_InitBgLayer(3, &t, 0);
        BG_SYS_FreeSlot(3);
        BG_SYS_SetPlaneVisible(3, 1);
    }
}








/*
 * Two ternaries selecting between two constants.
 */
int VIEWER_MAIN_GetBgParamA(int x)
{
    return x == 0x14 ? 0x20 : 0x1C;
}









int VIEWER_MAIN_GetBgParamB(int x)
{
    return x == 0x14 ? 0x2A : 0x29;
}









void VIEWER_MAIN_LoadBgResources(ViewerWork *p)
{
    VIEWER_MAIN_SetupBgSlot((ViewerWork *)p, p->info->bgSlot, p->info->f4_2);
    if (p->info->f4_7 == 0) {
        p->chrHandle = ARC_UTIL_LoadBgCharDataFromArchive(0x28, 0x1F, 0, (u32)(&p->chr), p->heap);
        if (p->info->f4_1 == 0) {
            p->scrnRes = ARC_UTIL_LoadPaletteDataFromArchive(0x28, 0x2B, 0, (u32)(&p->scrn), p->heap);
        } else {
            p->scrnRes = ARC_UTIL_LoadPaletteDataFromArchive(0x28, 0x2C, 0, (u32)(&p->scrn), p->heap);
        }
    } else {
        p->chrHandle = ARC_UTIL_LoadBgCharDataFromArchive(0x29, d_021C86E8[p->info->rowIndex][0], 0, (u32)(&p->chr), p->heap);
        p->scrnRes = ARC_UTIL_LoadPaletteDataFromArchive(0x29, 0x20, 0, (u32)(&p->scrn), p->heap);
        VIEWER_MAIN_ClearBgSlot((ViewerWork *)p, p->info->rowIndex);
    }
    VIEWER_MAIN_UploadBg((ViewerWork *)p);
    ARC_UTIL_UploadBgCharFromArchive((void *)0x28, (void *)VIEWER_MAIN_GetBgParamA(p->info->kind), (void *)6, 0, 0, 0, p->heap);
    ARC_UTIL_UploadBgPaletteFromArchive(0x28, VIEWER_MAIN_GetBgParamB(p->info->kind), 6, 0, 0, 0, p->heap);
    ARC_UTIL_UploadBgCharFromArchive((void *)0x28, (void *)0x1E, (void *)5, 0, 0, 0, p->heap);
    ARC_UTIL_UploadBgPaletteFromArchive(0x28, 0x28, 5, 0, 0, 0, p->heap);
    ARC_UTIL_UploadBgCharFromArchive((void *)0x28, (void *)0x1E, (void *)3, 0, 0, 0, p->heap);
    ARC_UTIL_UploadBgPaletteFromArchive(0x28, 0x28, 3, 0, 0, 0, p->heap);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x28, 0xF, 0, 0, 0x20, p->heap);
    VIEWER_MAIN_CopyBg3(p->info->bitmap, p->pix);
    ARC_UTIL_UploadBgCharFromArchive((void *)APP_ICON_GetArchiveId(), (void *)APP_ICON_GetStatusFrameFileId(), (void *)4, 0, 0, 0, p->heap);
    ARC_UTIL_UploadBgPaletteFromArchive(APP_ICON_GetArchiveId(), APP_ICON_GetStatusDataFileId(), 4, 0, 0, 0, p->heap);
    BG_SYS_FillTileMap(4, 0, 0x15, 0x20, 3, 0xC);
    BG_SYS_PushTile(4);
}









void VIEWER_MAIN_ExitBg(void)
{
    BG_SYS_SetMainPlaneVisible(0x1F, 0);
    BG_SYS_SetSubPlaneVisible(0x1F, 0);
    BG_SYS_ChangeScrollImmediate(5, 0, 0);
    BG_SYS_ChangeScrollImmediate(5, 3, 0);
    BG_SYS_ChangeScrollImmediate(3, 0, 0);
    BG_SYS_ChangeScrollImmediate(3, 3, 0);
    BG_SYS_FreeLayerBuf(7);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_Delete();
}








void VIEWER_MAIN_SetBgSlotKind(ViewerWork *p, int kind)
{
    FileTable t = d_021C85D8;
    int j = 1;

    if (kind == 0x14) {
        j = 0;
    }
    ARC_UTIL_UploadBgPaletteFromArchive(0x28, t.file[p->info->f4_4][j], 6, 0, 0, 0, p->heap);
}








void VIEWER_MAIN_ResetBgSlot(ViewerWork *p)
{
    if (p->decoVisible == 0) {
        ARC_UTIL_UploadBgPaletteFromArchive(0x28, VIEWER_MAIN_GetBgParamB(p->info->kind), 6, 0, 0, 0, p->heap);
        BG_SYS_ClearSlot(7);
    } else {
        VIEWER_MAIN_SetBgSlotKind((ViewerWork *)p, p->info->kind);
        VIEWER_MAIN_SetWindowRect(p);
        BG_SYS_ClearSlot(7);
    }
}







void VIEWER_MAIN_Draw(ViewerWork *p)
{
    VIEWER_MAIN_ResetBgSlot((ViewerWork *)p);
    VIEWER_TEXT_Draw(p, p->bg, p->info);
    PMS_DRAW_Main(p->pmsDraw);
    if (p->decoVisible == 0) {
        VIEWER_TEXT_DrawPage(p, p->scroll, 0, 0);
        VIEWER_MAIN_UploadBg((ViewerWork *)p);
    } else {
        VIEWER_TEXT_DrawWindow(p, p->bg, p->info);
        VIEWER_MAIN_UploadBgBuf(7, p->pix, p->phase);
    }
    VIEWER_MAIN_UpdateRows((ViewerWork *)p, p->decoVisible);
    VIEWER_TEXT_FlushWindow(p, p->bg);
}










void VIEWER_MAIN_UpdateRowA(ViewerWork *p, int flag)
{
    if (flag == 0) {
        VIEWER_TEXT_SetActorAnim(&p->anim, 0, 1, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 4, 0x12, 0);
        VIEWER_TEXT_SetActorAnim(&p->anim, 5, 6, 0);
        VIEWER_TEXT_SetActorAnim(&p->anim, 2, 0x10, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 7, GAME_DATA_ContainsRecentId((int)p->args->gameData, 0x15) + 6, 1);
    } else if (p->inputMode == 0) {
        VIEWER_TEXT_SetActorAnim(&p->anim, 0, 1, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 1, 0, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 6, 0x16, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 4, 0x12, p->info->f4_4 ^ 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 5, 8 - p->size * 2, p->info->f4_4 ^ 1);
        VIEWER_MAIN_SetRowState((ViewerWork *)p, p->info->f4_4, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 7, GAME_DATA_ContainsRecentId((int)p->args->gameData, 0x16) + 6, 1);
    } else {
        VIEWER_TEXT_SetActorAnim(&p->anim, 0, 0xF, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 1, 0xE, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 4, 0x14, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 5, 8 - p->size * 2, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 6, 0x16, 0);
        VIEWER_TEXT_SetActorAnim(&p->anim, 2, 10, 0);
    }
}










void VIEWER_MAIN_UpdateRowB(ViewerWork *p, int flag)
{
    if (flag == 0) {
        VIEWER_TEXT_SetActorAnim(&p->anim, 0, 1, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 4, 0x12, 0);
        VIEWER_TEXT_SetActorAnim(&p->anim, 5, 6, 0);
        VIEWER_TEXT_SetActorAnim(&p->anim, 2, 0x10, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 7, GAME_DATA_ContainsRecentId((int)p->args->gameData, 0x15) + 6, 1);
    } else {
        VIEWER_TEXT_SetActorAnim(&p->anim, 0, 1, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 1, 0, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 4, 0x12, 0);
        VIEWER_TEXT_SetActorAnim(&p->anim, 6, 0x16, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 5, 8 - p->size * 2, 0);
        VIEWER_MAIN_SetRowState((ViewerWork *)p, p->info->f4_4, 0);
        VIEWER_TEXT_SetActorAnim(&p->anim, 7, GAME_DATA_ContainsRecentId((int)p->args->gameData, 0x16) + 6, 1);
    }
}










void VIEWER_MAIN_UpdateRowC(ViewerWork *p, int flag)
{
    if (flag == 0) {
        VIEWER_TEXT_SetActorAnim(&p->anim, 0, 1, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 1, 0xE, 0);
        VIEWER_TEXT_SetActorAnim(&p->anim, 2, 0x10, 0);
        VIEWER_TEXT_SetActorAnim(&p->anim, 5, 6, 0);
        VIEWER_TEXT_SetActorAnim(&p->anim, 7, 6, 0);
        VIEWER_TEXT_SetActorAnim(&p->anim, 4, 0, 0);
    } else {
        VIEWER_TEXT_SetActorAnim(&p->anim, 0, 1, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 1, 0, 0);
        VIEWER_TEXT_SetActorAnim(&p->anim, 4, 0x12, 0);
        VIEWER_TEXT_SetActorAnim(&p->anim, 6, 0x16, 1);
        VIEWER_TEXT_SetActorAnim(&p->anim, 5, 8 - p->size * 2, 0);
        VIEWER_MAIN_SetRowState((ViewerWork *)p, p->info->f4_4, 0);
        VIEWER_TEXT_SetActorAnim(&p->anim, 7, 6, 0);
    }
}










void VIEWER_MAIN_UpdateRows(ViewerWork *p, int flag)
{
    if (p->info->f4_7 == 1) {
        VIEWER_MAIN_UpdateRowC((ViewerWork *)p, flag);
    } else if (p->args->editMode == 0) {
        VIEWER_MAIN_UpdateRowB((ViewerWork *)p, flag);
    } else {
        VIEWER_MAIN_UpdateRowA((ViewerWork *)p, flag);
    }
}









static inline fx32 FX_Mul(fx32 v1, fx32 v2)
{
    return (fx32)(((fx64)v1 * v2 + 0x800LL) >> 12);
}









int VIEWER_MAIN_Update(ViewerWork *p)
{
    int done = 0;

    switch (p->state) {
    case 0:
        p->angle = 0;
        p->scaleX = 0x103D;
        p->scaleY = 0x103D;
        GFL_USE_PlaySeDefaultVolume(0x65A);
        if (p->decoVisible == 0) {
            PMS_DRAW_SetDecoVisible(p->pmsDraw, 0, 0);
        }
        p->state++;
        break;
    case 1:
        p->scaleX = FX_Mul(FX_SinCosTable_[(p->angle >> 4) * 2 + 1], 0x103D);
        if (p->scaleX <= 0x80) {
            p->scaleX = 0x80;
            p->state++;
        }
        p->angle += 0x400;
        if (p->angle >= 0x4000) {
            p->angle = 0x4000;
        }
        break;
    case 2:
        p->decoVisible ^= 1;
        VIEWER_MAIN_ResetBgSlot((ViewerWork *)p);
        VIEWER_MAIN_UpdateRows((ViewerWork *)p, p->decoVisible);
        p->state++;
        break;
    case 3:
        if (p->decoVisible == 0) {
            VIEWER_MAIN_UploadBg((ViewerWork *)p);
        } else {
            VIEWER_MAIN_UploadBgBuf(7, p->pix, p->phase);
        }
        p->state++;
        break;
    case 4:
        VIEWER_TEXT_FlushWindow((ViewerWork *)p, p->bg);
        p->state++;
        break;
    case 5:
        p->angle -= 0x400;
        if (p->angle <= 0) {
            p->angle = 0;
        }
        p->scaleX = FX_Mul(FX_SinCosTable_[(p->angle >> 4) * 2 + 1], 0x103D);
        if (p->scaleX <= 0x80) {
            p->scaleX = 0x80;
        }
        if (p->angle == 0) {
            p->scaleX = 0x1000;
            p->scaleY = 0x1000;
            done = 1;
            if (p->decoVisible == 0) {
                PMS_DRAW_SetVisible(p->pmsDraw, 0, 1);
                PMS_DRAW_SetDecoVisible(p->pmsDraw, 0, 1);
            }
        }
        break;
    }
    p->dirty = 1;
    return done;
}









static inline void SetWnd0InsidePlane(int wnd, int effect)
{
    u32 tmp = (REG_DB_WININ & ~0x3F) | wnd;
    if (effect) {
        tmp |= 0x20;
    }
    REG_DB_WININ = (u16)tmp;
}









static inline void SetWndOutsidePlane(int wnd, int effect)
{
    u32 tmp = (REG_DB_WINOUT & ~0x3F) | wnd;
    if (effect) {
        tmp |= 0x20;
    }
    REG_DB_WINOUT = (u16)tmp;
}









void VIEWER_MAIN_SetWindowPlane(int side)
{
    if (side < 0) {
        REG_DB_BLDCNT = 0;
        REG_DB_DISPCNT &= ~0xE000;
    } else if (side == 0) {
        G2x_SetBlendBrightness_(0x04001050, 0xC, -8);
        REG_DB_WIN0H = 0xE000;
        REG_DB_WIN0V = 0xA8;
        SetWnd0InsidePlane(0x1C, 1);
        SetWndOutsidePlane(0x1F, 0);
        REG_DB_DISPCNT = (REG_DB_DISPCNT & ~0xE000) | 0x2000;
    } else if (side == 1) {
        G2x_SetBlendBrightness_(0x04001050, 0xC, -8);
        REG_DB_WIN0H = 0x20;
        REG_DB_WIN0V = 0xA8;
        SetWnd0InsidePlane(0x1C, 1);
        SetWndOutsidePlane(0x1F, 0);
        REG_DB_DISPCNT = (REG_DB_DISPCNT & ~0xE000) | 0x2000;
    }
}








/*
 * note 2026-10-05 (wave D4 lane 02): case 0 writes both stores (0x304C and 0x3050) in each
 * if/else arm. The compiler sinks the common stores into the join block and keeps the 0x305C
 * constant live, so 0x304C/0x3050 come out as 0x305C-0x10 / 0x305C-0xC.
 */
int VIEWER_MAIN_UpdateWindows(char *p)
{
    switch (*(u8 *)(p + 0x32C6)) {
    case 0:
        if (*(u16 *)(p + 0x305C) == 0) {
            *(u32 *)(p + 0x304C) = 0x20;
            *(u32 *)(p + 0x3050) = 0x98;
        } else {
            *(u32 *)(p + 0x304C) = 0xE0;
            *(u32 *)(p + 0x3050) = 0x98;
        }
        *(u32 *)(p + 0x303C) = 0x103D;
        *(u32 *)(p + 0x3040) = 0x103D;
        *(u8 *)(p + 0x32C6) = 1;
        break;
    case 1:
        *(int *)(p + 0x303C) += 0x100;
        *(int *)(p + 0x3040) += 0x100;
        if (*(int *)(p + 0x303C) >= 0x2000) {
            *(int *)(p + 0x303C) = 0x2000;
            *(int *)(p + 0x3040) = 0x2000;
            *(u8 *)(p + 0x32C6) = 2;
        }
        break;
    case 2:
        *(u16 *)(p + 0x305E) = 1;
        VIEWER_MAIN_UpdateRows((ViewerWork *)p, *(int *)(p + 0x3034));
        VIEWER_MAIN_SetWindowPlane(*(u16 *)(p + 0x305C));
        return 1;
    case 3:
        *(u8 *)(p + 0x32C6) = 4;
        break;
    case 4:
        *(int *)(p + 0x303C) -= 0x100;
        *(int *)(p + 0x3040) -= 0x100;
        if (*(int *)(p + 0x303C) <= 0x1000) {
            *(int *)(p + 0x303C) = 0x1000;
            *(int *)(p + 0x3040) = 0x1000;
            *(u8 *)(p + 0x32C6) = 5;
        }
        break;
    case 5:
        *(int *)(p + 0x304C) = 0x80;
        *(int *)(p + 0x3050) = 0x60;
        *(u16 *)(p + 0x305E) = 0;
        VIEWER_MAIN_UpdateRows((ViewerWork *)p, *(int *)(p + 0x3034));
        VIEWER_MAIN_SetWindowPlane(-1);
        return 1;
    case 6:
        *(u8 *)(p + 0x32C6) = 7;
        break;
    case 7:
        *(int *)(p + 0x304C) -= 8;
        if (*(int *)(p + 0x304C) < 0x20) {
            *(int *)(p + 0x304C) = 0x20;
            *(u8 *)(p + 0x32C6) = 8;
        }
        break;
    case 8:
        *(u16 *)(p + 0x305C) ^= 1;
        VIEWER_MAIN_SetWindowPlane(*(u16 *)(p + 0x305C));
        return 1;
    case 9:
        *(u8 *)(p + 0x32C6) = 10;
        break;
    case 10:
        *(int *)(p + 0x304C) += 8;
        if (*(int *)(p + 0x304C) > 0xE0) {
            *(int *)(p + 0x304C) = 0xE0;
            *(u8 *)(p + 0x32C6) = 11;
        }
        break;
    case 11:
        *(u16 *)(p + 0x305C) ^= 1;
        VIEWER_MAIN_SetWindowPlane(*(u16 *)(p + 0x305C));
        return 1;
    }
    *(u8 *)(p + 0x32CA) |= 4;
    return 0;
}








void VIEWER_MAIN_InitBrightness(ViewerWork *p)
{
    struct Mtx m;

    m._00 = FX_Inv(p->scaleX);
    m._01 = 0;
    m._10 = 0;
    m._11 = FX_Inv(p->scaleY);
    G2x_SetBGyAffine_((void *)0x04001020, &m, p->cx, p->cy, p->x, p->y);
    G2x_SetBGyAffine_((void *)0x04001030, &m, p->cx, p->cy, p->x, p->y);
    p->dirty = 0;
}








int VIEWER_MAIN_CheckInputModeSwitch(ViewerWork *p)
{
    if (p->mode == 1) {
        if (TOUCHPANEL_GetCont()) {
            return 0;
        }
        if (KEY_GetCont()) {
            p->mode = 0;
            return 1;
        }
    } else {
        if (KEY_GetCont()) {
            return 0;
        }
        if (TOUCHPANEL_GetCont()) {
            p->mode = 1;
            return 0;
        }
    }
    return 0;
}







int VIEWER_MAIN_HandleKey(ViewerWork *p)
{
    u32 key = KEY_GetTrg();

    if (key & 2) {
        if (p->inputMode == 0) {
            VIEWER_TEXT_SetActorAnim(&p->anim, 0, 9, 1);
            GFL_USE_PlaySeDefaultVolume(0x551);
            UI_SetInputMode((u32)0);
            return 4;
        }
    } else if (key & 0x400) {
        if (p->inputMode == 0 && !p->info->f4_7) {
            VIEWER_TEXT_SetActorAnim(&p->anim, 1, 8, 1);
            GFL_USE_PlaySeDefaultVolume(0x556);
            return 5;
        }
    } else if (key & 0x30) {
        if (p->inputMode == 0) {
            VIEWER_TEXT_SetActorAnim(&p->anim, 6, 0x17, 1);
            return 3;
        }
    } else if (key & 0x800) {
        if (!p->info->f4_7) {
            VIEWER_MAIN_ToggleFavorite(p);
        }
    } else if (key & 1) {
        if (!p->info->f4_7 && p->decoVisible == 0) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            VIEWER_TEXT_SetActorAnim(&p->anim, 2, 0x11, 1);
            return 10;
        }
    }
    return 0;
}







void VIEWER_MAIN_ToggleFavorite(ViewerWork *p)
{
    int v;

    GFL_USE_PlaySeDefaultVolume(0x646);
    if (p->decoVisible == 0) {
        v = GAME_DATA_ContainsRecentId((int)p->args->gameData, 0x15) ^ 1;
        VIEWER_TEXT_SetActorAnim(&p->anim, 7, v + 6, 1);
        GAME_DATA_SetRecentId(p->args->gameData, 0x15, v);
    } else {
        v = GAME_DATA_ContainsRecentId((int)p->args->gameData, 0x16) ^ 1;
        VIEWER_TEXT_SetActorAnim(&p->anim, 7, v + 6, 1);
        GAME_DATA_SetRecentId(p->args->gameData, 0x16, v);
    }
}







void VIEWER_MAIN_SetRowState(ViewerWork *p, int flag, int v)
{
    if (flag == 0) {
        VIEWER_TEXT_SetActorAnim((ViewerAnim *)((ViewerAnim *)((ViewerAnim *)(&p->anim))), 2, 10, v);
    } else {
        VIEWER_TEXT_SetActorAnim((ViewerAnim *)((ViewerAnim *)((ViewerAnim *)(&p->anim))), 2, 12, v);
    }
}








void VIEWER_MAIN_SetRowDrawEnable(ViewerWork *p, int flag)
{
    if (flag == 0) {
        VIEWER_TEXT_SetActorAnim((ViewerAnim *)((ViewerAnim *)((ViewerAnim *)(&p->anim))), 2, 0xB, 1);
        CLACT_SetActorDrawEnable(p->anim.obj[4], 0);
        CLACT_SetActorDrawEnable(p->anim.obj[5], 0);
    } else {
        VIEWER_TEXT_SetActorAnim((ViewerAnim *)((ViewerAnim *)((ViewerAnim *)(&p->anim))), 2, 0xD, 1);
        CLACT_SetActorDrawEnable(p->anim.obj[4], 1);
        CLACT_SetActorDrawEnable(p->anim.obj[5], 1);
    }
}








void VIEWER_MAIN_DrawRowBg(ViewerWork *p, int flag)
{
    if (flag) {
        p->phase = 0;
        p->blink = 0;
    } else {
        p->phase = 2;
    }
    VIEWER_MAIN_ClearBgBuf(7, p->phase);
}






int VIEWER_MAIN_HitRow(ViewerWork *p, int hit)
{
    if (p->info->f4_5 && hit >= 3 && hit <= 9) {
        return 1;
    }
    return 0;
}





int VIEWER_MAIN_HandleRowTouch(ViewerWork *p, int hit)
{
    if (VIEWER_MAIN_HitRow((ViewerWork *)p, hit) == 1) {
        return 0;
    }
    switch (hit) {
    case 0:
        VIEWER_TEXT_SetActorAnim((ViewerAnim *)((ViewerAnim *)((ViewerAnim *)(&p->anim))), 0, 9, 1);
        GFL_USE_PlaySeDefaultVolume(0x551);
        UI_SetInputMode((u32)1);
        return 4;
    case 1:
        VIEWER_TEXT_SetActorAnim((ViewerAnim *)((ViewerAnim *)((ViewerAnim *)(&p->anim))), 1, 8, 1);
        GFL_USE_PlaySeDefaultVolume(0x556);
        return 5;
    case 2:
        TOUCHPANEL_GetPointCont(&p->touchX, &p->touchY);
        VIEWER_TEXT_SetActorAnim((ViewerAnim *)((ViewerAnim *)((ViewerAnim *)(&p->anim))), 6, 0x17, 1);
        return 3;
    case 3:
        if (p->decoVisible != 0) {
            if (p->args->info->f4_6) {
                VIEWER_MAIN_SetRowDrawEnable((ViewerWork *)p, p->info->f4_4);
                p->info->f4_4 ^= 1;
                VIEWER_MAIN_SetBgSlotKind((ViewerWork *)p, p->info->kind);
                VIEWER_MAIN_DrawRowBg((ViewerWork *)p, p->info->f4_4);
                GFL_USE_PlaySeDefaultVolume(0x548);
            }
        } else {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            VIEWER_TEXT_SetActorAnim((ViewerAnim *)((ViewerAnim *)((ViewerAnim *)(&p->anim))), 2, 0x11, 1);
            return 10;
        }
        break;
    case 4:
        if (p->decoVisible != 0 && !p->info->f4_4 && p->args->info->f4_6) {
            if (p->inputMode == 0) {
                VIEWER_TEXT_SetActorAnim((ViewerAnim *)((ViewerAnim *)((ViewerAnim *)(&p->anim))), 4, 0x13, 1);
                GFL_USE_PlaySeDefaultVolume(0x648);
                p->state = 0;
            } else {
                VIEWER_TEXT_SetActorAnim((ViewerAnim *)((ViewerAnim *)((ViewerAnim *)(&p->anim))), 4, 0x15, 1);
                GFL_USE_PlaySeDefaultVolume(0x649);
                p->state = 3;
            }
            return 8;
        }
        break;
    case 5:
        if (p->decoVisible != 0 && p->args->info->f4_6 && !p->info->f4_4) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            VIEWER_TEXT_SetActorAnim((ViewerAnim *)((ViewerAnim *)((ViewerAnim *)(&p->anim))), 5, 9 - p->size * 2, 1);
            p->size ^= 1;
        }
        break;
    case 6:
        VIEWER_MAIN_ToggleFavorite((ViewerWork *)p);
        break;
    case 7:
        if (p->decoVisible == 0) {
            return 6;
        }
        break;
    case 8:
        if (p->decoVisible == 0) {
            return 7;
        }
        break;
    case 9:
        if (p->decoVisible == 0) {
            return 9;
        }
        break;
    }
    return 0;
}





int VIEWER_MAIN_HandleRowKey(ViewerWork *p, int hit)
{
    switch (hit) {
    case 4:
        if (p->decoVisible != 0) {
            VIEWER_TEXT_SetActorAnim((ViewerAnim *)(&p->anim), 4, 0x15, 1);
            GFL_USE_PlaySeDefaultVolume(0x649);
            p->state = 3;
            return 8;
        }
        break;
    case 5:
        if (p->decoVisible != 0) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            VIEWER_TEXT_SetActorAnim((ViewerAnim *)(&p->anim), 5, 9 - p->size * 2, 1);
            p->size ^= 1;
        }
        break;
    case 6:
        VIEWER_MAIN_ToggleFavorite((ViewerWork *)p);
        break;
    case 10:
        if (p->pane == 0) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            p->state = 9;
            return 8;
        }
        break;
    case 11:
        if (p->pane == 1) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            p->state = 6;
            return 8;
        }
        break;
    }
    return 0;
}





void VIEWER_MAIN_HandlePageTouch(ViewerWork *p)
{
    if (p->decoVisible != 0 && TOUCHPANEL_HitCont(d_021C8544) && p->pageDirty == 1) {
        VIEWER_TEXT_DrawPage((ViewerWork *)p, p->scroll, 1, 0);
        p->pageDirty = 0;
        p->pageDirty2 = 0;
        p->pageInputArmed = 0;
    }
}




void VIEWER_MAIN_HandlePageInput(ViewerWork *p)
{
    u32 x, y;
    int lim;

    if (!TOUCHPANEL_HitTrg(d_021C8544)) {
        p->pageInputArmed = 1;
    }
    if (p->pageInputArmed != 0 && !TOUCHPANEL_HitCont(d_021C8544)) {
        if (TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg(&x, &y);
            p->grabY = y;
            p->grabScroll = p->scroll;
        }
        if (TOUCHPANEL_GetCont()) {
            TOUCHPANEL_GetPointCont(&x, &y);
            p->scroll = p->grabScroll - (p->grabY - y);
        }
        lim = -(p->rowCount - 4) << 4;
        if (p->scroll < lim) {
            p->scroll = lim;
        } else if (p->scroll > 0) {
            p->scroll = 0;
        }
        if (p->prevScroll != p->scroll) {
            p->pageDirty = 1;
            VIEWER_TEXT_DrawPage((ViewerWork *)p, p->scroll, 1, 1);
            GFL_USE_PlaySeDefaultVolume(0x645);
        }
        p->prevScroll = p->scroll;
    }
}




int VIEWER_MAIN_HandleInput(ViewerWork *p)
{
    int hit;
    int r;

    if (p->info->f4_7 == 0) {
        hit = TOUCHPANEL_HitTrg(d_021C8594);
    } else {
        hit = TOUCHPANEL_HitTrg(d_021C8554);
    }
    if (p->inputMode == 0) {
        r = VIEWER_MAIN_HandleRowTouch((ViewerWork *)p, hit);
    } else {
        r = VIEWER_MAIN_HandleRowKey((ViewerWork *)p, hit);
    }
    if (r != 0) {
        return r;
    }
    if (p->decoVisible != 0) {
        if (p->inputMode == 0) {
            VIEWER_MAIN_HandlePageInput((ViewerWork *)p);
            VIEWER_MAIN_HandleScrollTouch((ViewerWork *)p, 0);
        } else {
            VIEWER_MAIN_HandleScrollTouch((ViewerWork *)p, 1);
        }
    }
    return 0;
}





int VIEWER_MAIN_UpdateInput(ViewerWork *p)
{
    VIEWER_MAIN_CheckInputModeSwitch((ViewerWork *)p);
    VIEWER_MAIN_HandlePageTouch((ViewerWork *)p);
    VIEWER_MAIN_CheckTouch((ViewerWork *)p);
    if (p->mode == 1) {
        return VIEWER_MAIN_HandleInput((ViewerWork *)p);
    }
    return VIEWER_MAIN_HandleKey((ViewerWork *)p);
}





void VIEWER_MAIN_DrawSelected(ViewerWork *p, int sel, int *seq)
{
    switch (sel) {
    case 3:
        p->state = 0;
        *seq = 5;
        break;
    case 8:
        if (p->args->info->f4_6) {
            *seq = 9;
        }
        break;
    case 9:
        if (p->args->info->f4_6) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            p->state = 0;
            *seq = 6;
        }
        break;
    case 4:
        *seq = 2;
        p->args->exitCode = 0;
        p->args->nextScreen = 0;
        break;
    case 5:
        *seq = 3;
        p->args->exitCode = 0;
        p->args->nextScreen = 1;
        break;
    case 6:
        if (p->args->info->f4_6) {
            TRCARD_SIGN_SetSeenBefore(GAME_DATA_GetTrainerCardSign(p->args->gameData));
            GFL_USE_PlaySeDefaultVolume(0x548);
            VIEWER_MAIN_InitInfo((ViewerInfo *)p->info);
            VIEWER_TEXT_DrawTable(p, p->info->rowIndex, 1);
        }
        break;
    case 7:
        if (p->args->info->f4_6) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            p->info->listIndex++;
            if (p->info->listIndex > 0x18) {
                p->info->listIndex = 0;
            }
            VIEWER_TEXT_DrawList(p, p->info->listIndex, 1);
        }
        break;
    case 10:
        p->state = 0;
        *seq = 7;
        break;
    }
}





void VIEWER_MAIN_VBlank(void *task, ViewerWork *p)
{
    int ofs;

    VIEWER_MAIN_UpdateBrightness((ViewerWork *)p);
    ofs = -(p->shake / 2);
    BG_SYS_ChangeScrollImmediate(5, 0, ofs);
    BG_SYS_ChangeScrollImmediate(5, 3, ofs);
    BG_SYS_ChangeScrollImmediate(3, 0, ofs);
    BG_SYS_ChangeScrollImmediate(3, 3, ofs);
    if (p->dirty) {
        VIEWER_MAIN_InitBrightness((ViewerWork *)p);
    }
    BG_SYS_Update();
    CLACT_VBlankSystem();
}





void VIEWER_MAIN_InitLcdBrightness(void)
{
    struct Mtx m;
    fx32 a, d;

    a = FX_Inv(0x1000);
    d = FX_Inv(0x1000);
    m._00 = a;
    m._01 = 0;
    m._10 = 0;
    m._11 = d;
    OS_WaitVBlankIntr();
    G2x_SetBGyAffine_((void *)0x04001020, &m, 0x80, 0x60, 0, 0);
    G2x_SetBGyAffine_((void *)0x04001030, &m, 0x80, 0x60, 0, 0);
    OS_WaitVBlankIntr();
    G2x_SetBGyAffine_((void *)0x04000030, &m, 0x80, 0, 0, 0);
}




void VIEWER_MAIN_UploadBg(ViewerWork *p)
{
    ViewerScrnData *s;

    BG_SYS_LoadTileData(7, p->chr->data, p->chr->size, 0);
    s = p->scrn;
    BG_SYS_DrawTileEx(7, 0x15, 2, 10, 11, (u32)s + 0xC, 0x15, 2, s->w >> 3, s->h >> 3);
    BG_SYS_PushTile(7);
}




void VIEWER_MAIN_SetWindowRect(void *p)
{
    BG_SYS_SetTileEntry(7, 0, 0x14, 6, 6, 9, 0x10);
}




void VIEWER_MAIN_CopyBg3(const u8 *src, u8 *dst)
{
    int i;

    for (i = 0; i < 0x3000; i++) {
        if ((src[i / 64 * 8 + (u8)(i / 8 % 8)] >> (u8)(i % 8)) & 1) {
            dst[i] = 7;
        }
    }
}




void VIEWER_MAIN_CopyBg6(const u8 *src, u8 *dst)
{
    int i, j;
    int v;

    for (i = 0; i < 0x600; i++) {
        v = 0;
        for (j = 0; j < 8; j++) {
            v |= (src[i * 8 + j] & 1) << j;
        }
        dst[i] = v;
    }
}




void VIEWER_MAIN_ClearBgBuf(u32 bg, int mode)
{
    u16 *map = (u16 *)BG_SYS_GetBuf((u8)bg);
    u8 x, y;
    u16 n;

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 24; x++) {
            map[(y + 11) * 32 + 4 + x] = 0;
        }
    }
    n = 0;
    switch (mode) {
    case 2:
        for (y = 0; y < 8; y++) {
            for (x = 0; x < 24; x++) {
                n++;
                map[(y + 11) * 32 + 4 + x] = n;
            }
        }
        break;
    case 0:
        for (y = 0; y < 8; y++) {
            for (x = 0; x < 12; x++) {
                n++;
                map[(y + 11) * 32 + 10 + x] = n;
            }
            n += 12;
        }
        break;
    case 1:
        n += 12;
        for (y = 0; y < 8; y++) {
            for (x = 0; x < 12; x++) {
                n++;
                map[(y + 11) * 32 + 10 + x] = n;
            }
            n += 12;
        }
        break;
    }
    BG_SYS_MarkTileDirty((u8)bg);
}




void VIEWER_MAIN_UploadBgBuf(u32 bg, const void *src, int mode)
{
    BG_SYS_LoadTileData((u8)bg, src, 0x3000, 1);
    VIEWER_MAIN_ClearBgBuf(bg, mode);
}




void VIEWER_MAIN_ClearBg(ViewerWork *p)
{
    if (p->decoVisible != 0 && p->info->f4_4) {
        p->blink++;
        if (p->blink > 20) {
            p->phase ^= 1;
            VIEWER_MAIN_ClearBgBuf(7, p->phase);
            p->blink = 0;
        }
    }
}




void VIEWER_MAIN_UpdateBrightness(ViewerWork *p)
{
    u16 *pal = p->pltt->data;

    p->frame++;
    if (p->frame > 8) {
        p->frame = 0;
    }
    if (p->frame == 0) {
        GXS_LoadBGPltt(pal + 3, 6, 4);
    } else if (p->frame == 4) {
        GXS_LoadBGPltt(pal + 5, 6, 4);
    }
}




void VIEWER_MAIN_CheckTouch(ViewerWork *p)
{
    if ((p->decoVisible != 0 && p->inputMode == 0 && TOUCHPANEL_HitCont(d_021C8534))
        || (p->inputMode == 1 && TOUCHPANEL_HitCont(d_021C854C))) {
        p->scrollTouchArmed = 0;
    }
}




void VIEWER_MAIN_HandleScrollTouch(ViewerWork *p, int side)
{
    u32 x, y;

    if (p->info->f4_5 || p->info->f4_4 == 1) {
        return;
    }
    if (TOUCHPANEL_GetPointCont(&x, &y)) {
        if (side == 0) {
            if (!TOUCHPANEL_HitTrg(d_021C852C)) {
                p->scrollTouchArmed = 1;
            }
            if (p->scrollTouchArmed != 0 && !TOUCHPANEL_HitPoint((struct Ctx *)d_021C852C, x, y)) {
                p->raw.x = x;
                p->raw.y = y;
                p->raw.size = p->size;
                p->raw.active = 1;
                if (x < 0x80) {
                    p->pane = 0;
                } else {
                    p->pane = 1;
                }
            } else {
                p->raw.active = 0;
            }
        } else {
            if (!TOUCHPANEL_HitTrg(d_021C853C)) {
                p->scrollTouchArmed = 1;
            }
            if (p->scrollTouchArmed != 0 && !TOUCHPANEL_HitPoint((struct Ctx *)d_021C853C, x, y)) {
                p->raw.x = ((x - 0x20) + p->pane * 0xC0) / 2 + 0x20;
                p->raw.y = (y - 0x18) / 2 + 0x58;
                p->raw.size = p->size;
                p->raw.active = 1;
            } else {
                p->raw.active = 0;
            }
        }
    } else {
        p->raw.active = 0;
    }
    p->cur.x = p->raw.x;
    p->cur.y = p->raw.y;
    p->cur.size = p->raw.size;
    p->cur.active = p->raw.active;
}



/*
 * 4x4 tile blit into an 8x8-tile layout, 24 tiles per row.
 * The `b skip` stubs are `n++; continue;` repeated in each rejection arm
 * (tail merging leaves a lone branch per arm). xx and yy declared at the top,
 * before j, k, n, give the image colours (xx r2, k r3, n r4).
 */
void VIEWER_MAIN_BlitRect(u8 *dst, const u8 *src, int x, int y, int w, int h, int mode, int sel)
{
    int xx, yy;
    int j, k, n = 0;
    for (j = 0; j < 4; j++) {
        for (k = 0; k < 4; k++) {
            xx = x + k;
            yy = y + j;
            if (xx < 0 || yy < 0) {
                n++;
                continue;
            }
            if (xx >= w || yy >= h) {
                n++;
                continue;
            }
            if (mode == 1 && ((sel == 0 && xx >= 0x60) || (sel == 1 && xx <= 0x5f))) {
                n++;
                continue;
            }
            {
                int idx = xx % 8 + ((yy % 8) * 8 + ((yy / 8) * 24 + xx / 8) * 64);
                int c = src[n];
                if (c == 1) dst[idx] = 7;
                else if (c == 2) dst[idx] = 0;
            }
            n++;
        }
    }
}




int VIEWER_MAIN_BlitBrush(u8 *pix, const u8 *brush, int x1, int y1, int *px, int *py, int a, int b, int clip, int side)
{
    int n = 0;
    int x = *px;
    int y = *py;
    int ex = x1;
    int dx, dy;
    int ey = y1;
    int e, s;

    if (a == 0 && b == 0) {
        *px = x1;
        *py = y1;
        return n;
    }
    dx = x1 - x;
    if (dx < 0) {
        dx = -dx;
    }
    dy = y1 - y;
    if (dy < 0) {
        dy = -dy;
    }
    if (dx > dy) {
        if (x > x1) {
            s = (y > y1) ? 1 : -1;
            ex = x;
            x = x1;
            y = y1;
        } else {
            s = (y < y1) ? 1 : -1;
        }
        VIEWER_MAIN_BlitRect(pix, brush, x, y, 0xC0, 0x40, clip, side);
        x++;
        e = dx >> 1;
        n++;
        for (; x <= ex; x++) {
            e -= dy;
            if (e < 0) {
                e += dx;
                y += s;
            }
            VIEWER_MAIN_BlitRect(pix, brush, x, y, 0xC0, 0x40, clip, side);
            n++;
        }
    } else {
        if (y > y1) {
            s = (x > x1) ? 1 : -1;
            ey = y;
            y = y1;
            x = x1;
        } else {
            s = (x < x1) ? 1 : -1;
        }
        VIEWER_MAIN_BlitRect(pix, brush, x, y, 0xC0, 0x40, clip, side);
        y++;
        e = dy >> 1;
        n++;
        for (; y <= ey; y++) {
            e -= dx;
            if (e < 0) {
                e += dy;
                x += s;
            }
            VIEWER_MAIN_BlitRect(pix, brush, x, y, 0xC0, 0x40, clip, side);
            n++;
        }
    }
    *px = x1;
    *py = y1;
    return n;
}




void VIEWER_MAIN_CopyTouchPos(ViewerTouchPos *src, ViewerTouchPos *dst)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->size = src->size;
    dst->active = src->active;
}




int VIEWER_MAIN_DrawBrushStroke(u8 *pix, ViewerTouchPos *cur, ViewerTouchPos *prev, int flush, const void *src, u8 clip, u8 side)
{
    int drew = 0;
    int n = 0;
    int ofs;
    int px, py;

    if (clip == 0) {
        ofs = 4;
    } else {
        ofs = 2;
    }
    if (cur->active) {
        if (prev->active) {
            px = prev->x - 0x20 - ofs;
            py = prev->y - 0x5A;
        }
        n = VIEWER_MAIN_BlitBrush(pix, d_021C86A8[clip][cur->size], cur->x - 0x20 - ofs, cur->y - 0x5A, &px, &py, 0, prev->active, clip, side);
        drew = 1;
    }
    if (drew && flush) {
        BG_SYS_LoadTileData(7, src, 0x3000, 1);
    }
    VIEWER_MAIN_CopyTouchPos(cur, prev);
    cur->active = 0;
    return n;
}
