/*
 * file:     wf2dmap_scene.c
 * unit:     yes
 * function: WF2DMAP_SCENE_Create, WF2DMAP_SCENE_Draw, WF2DMAP_SCENE_Delete, WF2DMAP_SCENE_InitBg, WF2DMAP_SCENE_VBlank, WF2DMAP_SCENE_SetSlot, WF2DMAP_SCENE_BuildGrid, WF2DMAP_SCENE_ResetState, WF2DMAP_SCENE_Start, WF2DMAP_SCENE_StepWipeIn, WF2DMAP_SCENE_StepWaitInput, WF2DMAP_SCENE_StepUpdate, WF2DMAP_SCENE_StepAnimate, WF2DMAP_SCENE_Dispatch, WF2DMAP_SCENE_HandleInput, WF2DMAP_SCENE_GetGridNumber, WF2DMAP_SCENE_CheckGridNumber, WF2DMAP_SCENE_BuildNumberList, WF2DMAP_SCENE_ClearSelection, WF2DMAP_SCENE_CreateButtons, WF2DMAP_SCENE_SetButtonCursor, WF2DMAP_SCENE_HandleButton, WF2DMAP_SCENE_ProcessPending, WF2DMAP_SCENE_ClearPending, WF2DMAP_SCENE_FindCellByValue, WF2DMAP_SCENE_FindLastCellByValue, WF2DMAP_SCENE_InitClact, WF2DMAP_SCENE_LoadActorAssets, WF2DMAP_SCENE_DeleteActors, WF2DMAP_SCENE_CreateCellActors, WF2DMAP_SCENE_CreateCursorActors, WF2DMAP_SCENE_CreateExtraActors, WF2DMAP_SCENE_SetCursorVisible, WF2DMAP_SCENE_MoveCursor, WF2DMAP_SCENE_SetCursorPos, WF2DMAP_SCENE_SetCursorPosBySlot, WF2DMAP_SCENE_UpdateCursorAnim, WF2DMAP_SCENE_SetOamPos, WF2DMAP_SCENE_UpdateOam, WF2DMAP_SCENE_GetCellAnim, WF2DMAP_SCENE_SetCellFlags, WF2DMAP_SCENE_LayoutCells, WF2DMAP_SCENE_UpdateCellRects, WF2DMAP_SCENE_CreateOam, WF2DMAP_SCENE_DeleteOam, WF2DMAP_SCENE_RegisterCompressedPalette, WF2DMAP_SCENE_CreateTextOams, WF2DMAP_SCENE_CreateTextOam, WF2DMAP_SCENE_CreateWindow, WF2DMAP_SCENE_DrawMessage, WF2DMAP_SCENE_ShowMessage
 * address:  0x021D85C0
 * region:   ov129
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   CODEIN_PARAM_Create 0x0202E4EC thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   PALANM_Create 0x02021518 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   d_021DA800 0x021DA800 data a4
 *   CLACT_DrawSystem  0x0204A600  arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   STRBUF_Delete 0x02045808 arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_02082A7C 0x02082A7C arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   d_021DA638 0x021DA638 data a4
 *   d_021DA698 0x021DA698 data a4
 *   PALANM_TransferPalettes  0x02021D50  thumb
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   d_021DA744 0x021DA744 data a4
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   BUTTON_MAN_UpdateSlots 0x02051C88 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   d_021DA830 0x021DA830 data a4
 *   d_021DA84C 0x021DA84C data a4
 *   d_021DA718 0x021DA718 data a4 ov129
 *   KEY_GetRepeat 0x0203633C arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   d_021DA75C 0x021DA75C data a4
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_FormatNumber 0x0201F35C thumb
 *   STRBUF_Append 0x02045AA8 arm
 *   d_021DA798 0x021DA798 data a2
 *   BUTTON_MAN_Create 0x02051B84 arm
 *   d_021DA72C 0x021DA72C data a4 ov129
 *   _u32_div_f 0x0209C2B0 arm
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   BMP_OAM_SetPos  0x0202590C  thumb
 *   BMP_OAM_CreateSys  0x02025538  thumb
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   BMP_Create 0x02043678 arm
 *   GF_FONT_MeasureWidestLine 0x0201D304 thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_OAM_Create 0x020255A0 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 *   BMP_Delete 0x020437AC arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */

struct GfFont;
struct PalAnmSlot;
struct PalAnmSlot;
struct Param;
struct Proc;
struct Node;
struct Proc;
struct U16Vec;
struct BgTemplate;
struct DispVram;
struct S02021D50;
struct Ctx;
struct Actor;
struct PtS;
struct Obj;
struct Vec2;
struct Pair;
struct Cfg;
struct Bank;
struct Descriptor;
struct Grid;
struct Bmp;
struct MsgBank;
struct Bmp;
struct Rec;
struct StrObj;
struct Sys;
struct CharBuf;
struct WordSet;

union Wf2dmapHandle { void *handle; int handleRaw; };

typedef struct {
    int state;
    int value;
    int flag;
    union Wf2dmapHandle actor;
    unsigned char pad_10[4];
    short stepX;
    short stepY;
    unsigned char stepFrames;
    unsigned char stepIndex;
    unsigned char pad_1A[310];
    int group0End;
    unsigned char pad_154[8];
    union Wf2dmapHandle extraActor;
    unsigned char pad_160[4];
    short extraStepX;
    short extraStepY;
    unsigned char extraStepFrames;
    unsigned char pad_169[15];
    int extraActor1;
    unsigned char pad_17C[12];
    int cursorIndex;
    unsigned char pad_18C[8];
    union Wf2dmapHandle cursorActor;
    unsigned char pad_198[12];
    int cursorMode;
    unsigned char pad_1A8[8];
    int cursorActor2;
    unsigned char pad_1B4[4];
    unsigned short cursorCol;
    unsigned short cursorRow;
    unsigned char pad_1BC[4];
    int cursorActor3;
    unsigned char pad_1C4[8];
    int cursorActor4;
    unsigned char pad_1D0[4];
    unsigned short cursorValue0;
    unsigned short cursorValue1;
    unsigned char pad_1D8[4];
    int cursorState;
    unsigned char pad_1E0[8];
    int cursorAnimActor;
    unsigned char pad_1EC[8];
    unsigned char cursorAnimFrame;
    unsigned char pad_1F5[3];
    int listActive;
    unsigned char pad_1FC[8];
    int cursorAnimActor2;
    unsigned char pad_208[8];
    unsigned char listTimer;
    unsigned char pad_211[11];
    unsigned short range0Start;
    unsigned short range0End;
    unsigned short range1Start;
    unsigned short range1End;
    unsigned short range2Start;
    unsigned short range2End;
    unsigned char pad_228[4];
    int stateId;
    int stateTimer;
    int step;
    int stepTimer;
    int cellCount;
    int groupIndex;
    int prevGroupIndex;
    int mainStart;
    int mainEnd;
    int subStart;
    int subEnd;
    void * arcHandle;
    union Wf2dmapHandle unit;
    int paletteA;
    int paletteB;
    int paletteC;
    int charA;
    int charB;
    int charC;
    unsigned char pad_278[12];
    int cellAnimA;
    int cellAnimB;
    int cellAnimC;
    union Wf2dmapHandle palAnm;
    void * buttonMan;
    unsigned char pad_298[88];
    unsigned char selY0;
    unsigned char selY1;
    unsigned char selX0;
    unsigned char selX1;
    unsigned char sel2Y0;
    unsigned char sel2Y1;
    unsigned char sel2X0;
    unsigned char sel2X1;
    unsigned char buttonCount;
    unsigned char pad_2F9[3];
    int gridActive;
    void * oamSys;
    void * oamA;
    void * oamB;
    unsigned int oamPalette;
    int windowHandle;
    union Wf2dmapHandle font;
    void * vblankTask;
    int pendingCmd;
    int pendingArg;
    int pendingFlag;
    int paramId;
    unsigned char pad_32C[4];
    int group0Size;
    int group1Size;
    int group2Size;
    unsigned char pad_33C[8];
    int paramSize;
    union Wf2dmapHandle strbuf;
} Wf2dmapScene;

typedef struct {
    int state;
    int value;
    int flag;
    void *handle;
    unsigned char pad_10[12];
} Wf2dmapCell;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct { unsigned words[9]; } Param;



typedef struct { unsigned words[8]; } BgTemplate;

typedef struct { BgTemplate rows[3]; } MainTemplates;

typedef struct { BgTemplate rows[4]; } SubTemplates;

typedef struct { int rows[2][3]; } Table;

typedef signed char s8;



typedef signed int s32;




typedef struct { short x,y; } Pair;

typedef struct { int x,y; } Scale;

typedef unsigned int   u32;

typedef struct { int v[3][5]; } Tbl;

typedef short s16;

typedef struct { s16 a,b,c,d; } Rect;

typedef struct { Rect rows[12]; } Rects;

typedef struct { u8 a,b; } Entry;






typedef struct  {
    unsigned words[7];
}
Config;


typedef struct { u16 x,y,frame; u8 speed,flag; } Params;



typedef struct {
    short x;
    short y;
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} L;


typedef struct { short x,y; } Wf2dmapPairS16;

typedef struct { u16 x,y; } Wf2dmapPairU16;





typedef struct { short x,y,z,w; } Position;







struct Param { void *bmp; short x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };


extern void GFL_HEAP_CreateChildHeap(unsigned a, unsigned b, unsigned c);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, unsigned size, unsigned heap);
extern void MI_CpuFill8(void *,int,unsigned);
extern struct Param *CODEIN_PARAM_Create(unsigned heap, unsigned a1, unsigned a2, unsigned a3, unsigned *src);
extern unsigned GFL_HEAP_Free(void *p);
extern void BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void);
extern void *ARC_TOOL_CreateHandle(unsigned id, unsigned heap);
extern void BG_SYS_Create(u16),BMP_WIN_Init(u16);
extern void * PALANM_Create(unsigned);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, unsigned heapId);
extern void PALANM_SetAutoTransfer(struct PalAnmSlot *o, int v);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, unsigned idx, unsigned size, unsigned heap);
extern void G2x_SetBlendAlpha_(void *,int,int,int,int);
extern void *GFL_USE_AddMainTask(unsigned,unsigned,unsigned);
extern void GFL_NET_RestartWithDefaultTimeout(unsigned,unsigned);
extern void CLACT_DrawSystem(void *);
extern void TCB_DeleteTask(struct Node *n);
extern unsigned GF_FONT_Delete(void *ptr);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_SetMainPlaneVisible(unsigned,unsigned);
extern void BG_SYS_SetSubPlaneVisible(unsigned,unsigned);
extern void BG_SYS_FreeLayerBuf(unsigned);
extern void BG_SYS_Delete(void);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, unsigned idx);
extern unsigned PALANM_Delete(void *a0);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BUTTON_MAN_Delete(void *);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PROCSYS_FreeProcWork(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned heap);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_02082A7C(unsigned,void *,unsigned);
extern void BG_SYS_InitBgLayer(unsigned bgId, const struct BgTemplate *tmpl, unsigned type);
extern void BG_SYS_ClearSlot(unsigned);
extern void BMP_SetDisplaySwap(unsigned);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern void CLACT_VBlankSystem(void);
extern void WIPE_SYS_Start(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern unsigned WIPE_SYS_EndCheck(void);
extern unsigned KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorScale(struct Obj *dst, struct Pair *src);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u32 KEY_GetRepeat(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_FormatNumber(void *ctx, s32 n, u32 kind, u32 mode, u32 flag);
extern void STRBUF_Append(struct U16Vec *dst, struct U16Vec *src);
extern void *BUTTON_MAN_Create(u8 *,int,int,int);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *,u32,u32,u32,u32,u32,u16);
extern void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *,u32,u32,u32,u32,u16);
extern int CLACT_RegisterPalette(void *,u32,u32,u32,u16);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern int CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void BMP_MENUWORK_LoadCharAndPltt(u32,u32,u32,u32,u16);
extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32,u32,u32,u32,u32,u16);
extern void CLACT_DeleteActor(struct Obj *p);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void BMP_OAM_SetPos(struct Grid *g, short x, short y);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
extern void BMP_OAM_Delete(struct Grid *);
extern void BMP_OAM_DeleteSys(void *);
extern int CLACT_RegisterPaletteCompressed(void *,u32,u32,u32,u16);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern u32 GF_FONT_MeasureWidestLine(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_PrintColor(void *,short,short,void *,void *,u16);
extern struct Grid *BMP_OAM_Create(struct Sys *sys, const struct Param *param);
extern void BMP_OAM_UploadChars(struct Obj *o);
extern void BMP_Delete(struct Bmp *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern unsigned int BMP_WIN_Create(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, u8 slot);
extern void BMP_MENUWORK_DrawWindow(void *,int,int,int);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_Print(void *,short,short,void *,void *);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BG_SYS_PushTile(u32);
int WF2DMAP_SCENE_Create(void *obj,void *unused,const Param *cfg);
int WF2DMAP_SCENE_Draw(int a, int b, int c, int d);
int WF2DMAP_SCENE_Delete(void *a,int b,int c,char *p);
void WF2DMAP_SCENE_InitBg(void);
void WF2DMAP_SCENE_VBlank(int a, char *p);
void WF2DMAP_SCENE_SetSlot(char *p,int v);
void WF2DMAP_SCENE_BuildGrid(char *p);
void WF2DMAP_SCENE_ResetState(char *p, int v);
int WF2DMAP_SCENE_Start(char *p);
int WF2DMAP_SCENE_StepWipeIn(char *p);
int WF2DMAP_SCENE_StepWaitInput(char *p);
int WF2DMAP_SCENE_StepUpdate(char *p);
int WF2DMAP_SCENE_StepAnimate(char *p);
int WF2DMAP_SCENE_Dispatch(char *p);
void WF2DMAP_SCENE_HandleInput(char *p);
int WF2DMAP_SCENE_GetGridNumber(u8 *p);
int WF2DMAP_SCENE_CheckGridNumber(u8 *p);
void WF2DMAP_SCENE_BuildNumberList(char *p);
void WF2DMAP_SCENE_ClearSelection(const Wf2dmapCell *p);
void WF2DMAP_SCENE_CreateButtons(char *p);
void WF2DMAP_SCENE_SetButtonCursor(u8 *p,int n);
void WF2DMAP_SCENE_HandleButton(u32 n, int touch, char *p);
void WF2DMAP_SCENE_ProcessPending(char *p);
void WF2DMAP_SCENE_ClearPending(char *p);
int WF2DMAP_SCENE_FindCellByValue(u8 *p,int value);
int WF2DMAP_SCENE_FindLastCellByValue(u8 *p,int value);
void WF2DMAP_SCENE_InitClact(char *p,unsigned a);
void WF2DMAP_SCENE_LoadActorAssets(char *p);
void WF2DMAP_SCENE_DeleteActors(char *p);
void WF2DMAP_SCENE_CreateCellActors(char *p);
void WF2DMAP_SCENE_CreateCursorActors(char *p);
void WF2DMAP_SCENE_CreateExtraActors(char *p);
void WF2DMAP_SCENE_SetCursorVisible(char *p, int i, int a);
void WF2DMAP_SCENE_MoveCursor(u8 *p,int n);
void WF2DMAP_SCENE_SetCursorPos(char *p,int i);
void WF2DMAP_SCENE_SetCursorPosBySlot(char *p,int i,int j);
void WF2DMAP_SCENE_UpdateCursorAnim(char *p);
void WF2DMAP_SCENE_SetOamPos(char *p, int a, int b);
void WF2DMAP_SCENE_UpdateOam(char *p);
int WF2DMAP_SCENE_GetCellAnim(int x,int flag);
void WF2DMAP_SCENE_SetCellFlags(void *p);
void WF2DMAP_SCENE_LayoutCells(char *p,int animate);
void WF2DMAP_SCENE_UpdateCellRects(char *p);
void WF2DMAP_SCENE_CreateOam(char *p);
void WF2DMAP_SCENE_DeleteOam(u8 *p);
void WF2DMAP_SCENE_RegisterCompressedPalette(u8 *p);
void WF2DMAP_SCENE_CreateTextOams(u8 *p);
void WF2DMAP_SCENE_CreateTextOam(u8 *p, int i, int a2, int a3, int a4);
void WF2DMAP_SCENE_CreateWindow(void **p,int a,int b,int c,int d,int e,int f,int g,int h);
void WF2DMAP_SCENE_DrawMessage(void *p,int a,void *b,u32 c);
void WF2DMAP_SCENE_ShowMessage(void *p, int sel, void *b, unsigned int c);
extern const unsigned d_021DA800[];
extern const MainTemplates d_021DA638;
extern const SubTemplates d_021DA698;
extern const Table d_021DA744;
extern const int d_021DA830[], d_021DA84C[];
extern const Tbl d_021DA75C;
extern const Rects d_021DA798;
extern Entry d_021DA72C[];
extern const Config gClActorInitParam;






static inline void GX_SetVisiblePlane(int plane) { *(volatile unsigned *)0x04000000=(*(volatile unsigned *)0x04000000 & ~0x1F00u)|((unsigned)plane<<8); }






static inline void GXS_SetVisiblePlane(int plane) { *(volatile unsigned *)0x04001000=(*(volatile unsigned *)0x04001000 & ~0x1F00u)|((unsigned)plane<<8); }






int WF2DMAP_SCENE_Create(void *obj,void *unused,const Param *cfg)
{
    u8 *scene;
    unsigned sizes[3];
    Param *param;
    GFL_HEAP_CreateChildHeap((unsigned)((void *)1),50,0x40000);
    scene=PROCSYS_AllocProcWork(obj,0x34C,50);
    MI_CpuFill8(scene,0,0x34C);
    if(cfg==0) {
        sizes[0]=4; sizes[1]=4; sizes[2]=4;
        param=(Param *)CODEIN_PARAM_Create(50,0,0,12,sizes);
        *(Param *)(scene+0x328)=*param;
        GFL_HEAP_Free(param);
    } else *(Param *)(scene+0x328)=*cfg;
    BG_SYS_ClearMainPlanes(); BG_SYS_ClearSubPlanes();
    GX_SetVisiblePlane(0); GXS_SetVisiblePlane(0);
    ((Wf2dmapScene *)scene)->arcHandle=ARC_TOOL_CreateHandle(59,50);
    BG_SYS_Create(50); BMP_WIN_Init(50);
    ((Wf2dmapScene *)scene)->palAnm.handle=PALANM_Create(50);
    ((Wf2dmapScene *)scene)->font.handle=GF_FONT_Create(23,0,0,0,50);
    PALANM_SetAutoTransfer(((Wf2dmapScene *)scene)->palAnm.handle,1);
    PALANM_AllocSlotBuffers(((Wf2dmapScene *)scene)->palAnm.handle,0,512,50);
    WF2DMAP_SCENE_InitBg();
    WF2DMAP_SCENE_InitClact((char *)scene,(unsigned int)d_021DA800); WF2DMAP_SCENE_BuildGrid((char *)scene); WF2DMAP_SCENE_CreateButtons((char *)scene);
    G2x_SetBlendAlpha_((void *)0x04000050,0,6,15,7);
    G2x_SetBlendAlpha_((void *)0x04001050,0,14,7,8);
    ((Wf2dmapScene *)scene)->vblankTask=GFL_USE_AddMainTask((unsigned)WF2DMAP_SCENE_VBlank,(unsigned)scene,16);
    GFL_NET_RestartWithDefaultTimeout(1,50);
    return 1;
}







/*
 * Addresses are Black-image addresses.
 */
int WF2DMAP_SCENE_Draw(int a, int b, int c, int scene)
{
    void *drawResult = (void *)WF2DMAP_SCENE_Dispatch((char *)scene);

    CLACT_DrawSystem(drawResult);
    return drawResult != 0;
}






/*
 * The caller supplies the pointer through the legacy argless 02021540 thunk.
 */
int WF2DMAP_SCENE_Delete(void *procWork,int b,int c,char *scene)
{
    TCB_DeleteTask(((Wf2dmapScene *)scene)->vblankTask);
    GF_FONT_Delete(((Wf2dmapScene *)scene)->font.handle);
    WF2DMAP_SCENE_DeleteActors(scene);
    BMP_WIN_Exit();
    BG_SYS_SetMainPlaneVisible(1,0); BG_SYS_SetMainPlaneVisible(2,0); BG_SYS_SetMainPlaneVisible(4,0); BG_SYS_SetMainPlaneVisible(8,0);
    BG_SYS_SetSubPlaneVisible(1,0); BG_SYS_SetSubPlaneVisible(2,0); BG_SYS_SetSubPlaneVisible(4,0); BG_SYS_SetSubPlaneVisible(8,0);
    BG_SYS_FreeLayerBuf(1); BG_SYS_FreeLayerBuf(2); BG_SYS_FreeLayerBuf(3); BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(5); BG_SYS_FreeLayerBuf(6); BG_SYS_FreeLayerBuf(7);
    BG_SYS_Delete();
    PALANM_FreeSlotBuffers(((Wf2dmapScene *)scene)->palAnm.handle,0);
    PALANM_Delete(((Wf2dmapScene *)scene)->palAnm.handle);
    ARC_TOOL_DeleteHandle(((Wf2dmapScene *)scene)->arcHandle);
    BUTTON_MAN_Delete(((Wf2dmapScene *)scene)->buttonMan);
    if(c==0) STRBUF_Delete(((Wf2dmapScene *)scene)->strbuf.handle);
    PROCSYS_FreeProcWork(procWork);
    GFL_HEAP_DeleteChecked(50);
    return 1;
}






void WF2DMAP_SCENE_InitBg(void)
{
    MainTemplates mainTmpl;
    SubTemplates subTmpl;
    BG_SYS_ClearMainPlanes();
    BG_SYS_SetVramBanks((const struct DispVram *)d_021DA800);
    func_02082A7C(0,(void *)0x06000000,0x80000);
    func_02082A7C(0,(void *)0x06200000,0x20000);
    func_02082A7C(0,(void *)0x06400000,0x40000);
    func_02082A7C(0,(void *)0x06600000,0x20000);
    mainTmpl=d_021DA638;
    BG_SYS_InitBgLayer(1,(const struct BgTemplate *)(&mainTmpl.rows[0]),0);
    BG_SYS_InitBgLayer(2,(const struct BgTemplate *)(&mainTmpl.rows[1]),0);
    BG_SYS_InitBgLayer(3,(const struct BgTemplate *)(&mainTmpl.rows[2]),0);
    BG_SYS_ClearSlot(1); BG_SYS_ClearSlot(2); BG_SYS_ClearSlot(3);
    BG_SYS_SetMainPlaneVisible(1,0); BG_SYS_SetMainPlaneVisible(2,1); BG_SYS_SetMainPlaneVisible(4,0); BG_SYS_SetMainPlaneVisible(8,0);
    subTmpl=d_021DA698;
    BG_SYS_InitBgLayer(4,(const struct BgTemplate *)(&subTmpl.rows[0]),0);
    BG_SYS_InitBgLayer(5,(const struct BgTemplate *)(&subTmpl.rows[1]),0);
    BG_SYS_InitBgLayer(6,(const struct BgTemplate *)(&subTmpl.rows[2]),0);
    BG_SYS_InitBgLayer(7,(const struct BgTemplate *)(&subTmpl.rows[3]),0);
    BG_SYS_ClearSlot(4); BG_SYS_ClearSlot(5); BG_SYS_ClearSlot(6); BG_SYS_ClearSlot(7);
    BG_SYS_SetSubPlaneVisible(1,1); BG_SYS_SetSubPlaneVisible(2,1); BG_SYS_SetSubPlaneVisible(4,0); BG_SYS_SetSubPlaneVisible(8,0);
    BMP_SetDisplaySwap(0);
    BG_SYS_SetMainPlaneVisible(16,1); BG_SYS_SetSubPlaneVisible(16,1);
}







void WF2DMAP_SCENE_VBlank(int a, char *scene)
{
    PALANM_TransferPalettes((struct S02021D50 *)(((Wf2dmapScene *)scene)->palAnm.handleRaw));
    CLACT_VBlankSystem();
}







/*
 * Extent ends with two bytes of zero alignment padding.
 */
void WF2DMAP_SCENE_SetSlot(char *scene,int slotId)  {
    ((Wf2dmapScene *)scene)->prevGroupIndex=((Wf2dmapScene *)scene)->groupIndex;
    ((Wf2dmapScene *)scene)->groupIndex=slotId;
    ((Wf2dmapScene *)scene)->mainStart=0;
    ((Wf2dmapScene *)scene)->mainEnd=0;
    ((Wf2dmapScene *)scene)->subStart=0;
    ((Wf2dmapScene *)scene)->subEnd=0;
    if(slotId)  {
        ((Wf2dmapScene *)scene)->mainStart=*(unsigned short *)(scene+(slotId-1)*4+0x21c);
        ((Wf2dmapScene *)scene)->mainEnd=*(unsigned short *)(scene+(slotId-1)*4+0x21e);
    }
    if(((Wf2dmapScene *)scene)->prevGroupIndex)  {
        slotId=((Wf2dmapScene *)scene)->prevGroupIndex;
        ((Wf2dmapScene *)scene)->subStart=*(unsigned short *)(scene+(slotId-1)*4+0x21c);
        ((Wf2dmapScene *)scene)->subEnd=*(unsigned short *)(scene+(slotId-1)*4+0x21e);
    }
}






/*
 * Lever: copy the table through a second aggregate, retain its indexed read,
 * and initialize i before selecting q. The copy folds into the existing slot.
 */
void WF2DMAP_SCENE_BuildGrid(char *scene)
{
    int row,col,count,sum;
    Table tbl;
    Table tblCopy;
    const int *rowPtr;
    ((Wf2dmapScene *)scene)->gridActive=1;
    ((Wf2dmapScene *)scene)->range0Start=0;
    count=((Wf2dmapScene *)scene)->group0Size;
    ((Wf2dmapScene *)scene)->range0End=count;
    ((Wf2dmapScene *)scene)->range1Start=count;
    count+=((Wf2dmapScene *)scene)->group1Size;
    ((Wf2dmapScene *)scene)->range1End=count;
    ((Wf2dmapScene *)scene)->range2Start=count;
    ((Wf2dmapScene *)scene)->range2End=((Wf2dmapScene *)scene)->group2Size+count;
    WF2DMAP_SCENE_SetSlot(scene,1);
    for(row=0;row<3;row++) ((Wf2dmapScene *)scene)->cellCount+=*(int *)(scene+row*4+0x330);
    tbl=d_021DA744;
    count=0;
    tblCopy=tbl;
    if(((Wf2dmapScene *)scene)->group0Size!=4) count=1;
    row=0;
    rowPtr=tblCopy.rows[count];
    for(;row<3;row++) *(u16 *)(scene+row*2+0x214)=tblCopy.rows[count][row];
    *(u16 *)(scene+row*2+0x214)=rowPtr[row-1];
    sum=0;
    for(row=0;row<2;row++) {
        sum+=*(int *)(scene+row*4+0x330);
        *(int *)(scene+row*28+0x150)=sum-1;
    }
    row=0;
    count=0;
    do {
        for(col=0;col<*(int *)(scene+row*4+0x330);col++) {
            *(int *)(scene+count*28+4)=row+1;
            count++;
        }
        row++;
    } while(count<((Wf2dmapScene *)scene)->cellCount);
}







void WF2DMAP_SCENE_ResetState(char *scene, int state)
{
    ((Wf2dmapScene *)scene)->stateId = state;
    ((Wf2dmapScene *)scene)->stateTimer = 0;
    ((Wf2dmapScene *)scene)->step = 0;
    ((Wf2dmapScene *)scene)->stepTimer = 0;
}






int WF2DMAP_SCENE_Start(char *scene)  {
    WF2DMAP_SCENE_LoadActorAssets(scene);
    WF2DMAP_SCENE_SetCellFlags(scene);
    WF2DMAP_SCENE_CreateCellActors(scene);
    WF2DMAP_SCENE_LayoutCells(scene,0);
    WF2DMAP_SCENE_CreateCursorActors(scene);
    WF2DMAP_SCENE_CreateExtraActors(scene);
    WF2DMAP_SCENE_UpdateCellRects(scene);
    WF2DMAP_SCENE_CreateOam(scene);
    WF2DMAP_SCENE_CreateTextOams((u8 *)scene);
    WF2DMAP_SCENE_CreateWindow((void **)(scene+0x310),((Wf2dmapScene *)scene)->paramId,4,2,19,27,4,((Wf2dmapScene *)scene)->font.handleRaw,((Wf2dmapScene *)scene)->paramSize);
    WF2DMAP_SCENE_ResetState(scene,1);
    WIPE_SYS_Start(0,1,1,0,6,1,50);
    return 0;
}






int WF2DMAP_SCENE_StepWipeIn(char *scene)  {
    switch(((Wf2dmapScene *)scene)->step)  {
        case 0: WIPE_SYS_Start(0,0,0,0,6,1,50);
        ((Wf2dmapScene *)scene)->step+=1;
        break;
        case 1: if(WIPE_SYS_EndCheck()==1) ((Wf2dmapScene *)scene)->step+=1;
        break;
        default: return 1;
    }
    return 0;
}






int WF2DMAP_SCENE_StepWaitInput(char *scene)  {
    switch(((Wf2dmapScene *)scene)->step)  {
        case 0: WF2DMAP_SCENE_ShowMessage((void *)(((Wf2dmapScene *)scene)->windowHandle),((Wf2dmapScene *)scene)->paramId,(void *)(((Wf2dmapScene *)scene)->font.handleRaw),((Wf2dmapScene *)scene)->paramSize);
        ((Wf2dmapScene *)scene)->step+=1;
        break;
        case 1: if((KEY_GetTrg() & 2) || (KEY_GetTrg() & 1) || TOUCHPANEL_GetTrg())  {
            WF2DMAP_SCENE_DrawMessage((void *)(((Wf2dmapScene *)scene)->windowHandle),((Wf2dmapScene *)scene)->paramId,(void *)(((Wf2dmapScene *)scene)->font.handleRaw),((Wf2dmapScene *)scene)->paramSize);
            WF2DMAP_SCENE_ResetState(scene,1);
        }
        break;
    }
    return 0;
}






int WF2DMAP_SCENE_StepUpdate(char *scene) {if(((Wf2dmapScene *)scene)->step==0){if(WIPE_SYS_EndCheck()==1)((Wf2dmapScene *)scene)->step+=1;}else {WF2DMAP_SCENE_ProcessPending(scene);BUTTON_MAN_UpdateSlots(((Wf2dmapScene *)scene)->buttonMan);WF2DMAP_SCENE_HandleInput(scene);}return 0;}






int WF2DMAP_SCENE_StepAnimate(char *scene)
{
    int cellIdx,animSeq;
    char *cell;
    Scale scale;
    Pair first,second;
    switch(((Wf2dmapScene *)scene)->step) {
    case 0:
        WF2DMAP_SCENE_SetCursorVisible(scene,0,0);
        for(cellIdx=0;cellIdx<((Wf2dmapScene *)scene)->cellCount;cellIdx++) {
            cell=scene+cellIdx*28;
            if(((Wf2dmapScene *)cell)->stepFrames) {
                CLACT_GetActorSurfacePos(((Wf2dmapScene *)cell)->actor.handle,(struct PtS *)&first,0);
                first.x+=((Wf2dmapScene *)cell)->stepX;
                first.y+=((Wf2dmapScene *)cell)->stepY;
                CLACT_AddActorSurfacePos(((Wf2dmapScene *)cell)->actor.handle,(const struct Vec2 *)(&first),0);
                (((Wf2dmapScene *)cell)->stepFrames)--;
                if(cellIdx>=((Wf2dmapScene *)scene)->mainStart && cellIdx<((Wf2dmapScene *)scene)->mainEnd) {
                    scale.x=d_021DA830[((Wf2dmapScene *)cell)->stepIndex];
                    scale.y=scale.x;
                    CLACT_SetActorScale(((Wf2dmapScene *)cell)->actor.handle,(struct Pair *)(&scale));
                    (((Wf2dmapScene *)cell)->stepIndex)++;
                }
                if(cellIdx>=((Wf2dmapScene *)scene)->subStart && cellIdx<((Wf2dmapScene *)scene)->subEnd) {
                    scale.x=d_021DA84C[((Wf2dmapScene *)cell)->stepIndex];
                    scale.y=scale.x;
                    CLACT_SetActorScale(((Wf2dmapScene *)cell)->actor.handle,(struct Pair *)(&scale));
                    (((Wf2dmapScene *)cell)->stepIndex)++;
                }
            }
        }
        for(cellIdx=0;cellIdx<2;cellIdx++) {
            cell=scene+cellIdx*28;
            if(((Wf2dmapScene *)cell)->extraStepFrames) {
                CLACT_GetActorSurfacePos(((Wf2dmapScene *)cell)->extraActor.handle,(struct PtS *)&second,0);
                second.x+=((Wf2dmapScene *)cell)->extraStepX;
                second.y+=((Wf2dmapScene *)cell)->extraStepY;
                CLACT_AddActorSurfacePos(((Wf2dmapScene *)cell)->extraActor.handle,(const struct Vec2 *)(&second),0);
                (((Wf2dmapScene *)cell)->extraStepFrames)--;
            }
        }
        if(((Wf2dmapScene *)scene)->stepFrames==0) {
            for(cellIdx=((Wf2dmapScene *)scene)->mainStart;cellIdx<((Wf2dmapScene *)scene)->mainEnd;cellIdx++) {
                cell=scene+cellIdx*28;
                CLACT_SetActorAnimSeq(((Wf2dmapScene *)cell)->actor.handle,WF2DMAP_SCENE_GetCellAnim(((Wf2dmapScene *)cell)->state,((Wf2dmapScene *)cell)->flag));
            }
            for(cellIdx=((Wf2dmapScene *)scene)->subStart;cellIdx<((Wf2dmapScene *)scene)->subEnd;cellIdx++) {
                cell=scene+cellIdx*28;
                CLACT_SetActorAnimSeq(((Wf2dmapScene *)cell)->actor.handle,WF2DMAP_SCENE_GetCellAnim(((Wf2dmapScene *)cell)->state,((Wf2dmapScene *)cell)->flag));
            }
            (((Wf2dmapScene *)scene)->step)++;
        }
        (((Wf2dmapScene *)scene)->stepTimer)++;
        break;
    case 1:
        for(cellIdx=((Wf2dmapScene *)scene)->mainStart;cellIdx<((Wf2dmapScene *)scene)->mainEnd;cellIdx++) {
            cell=scene+cellIdx*28;
            if(((Wf2dmapScene *)cell)->stepIndex!=6) {
                scale.x=d_021DA830[((Wf2dmapScene *)cell)->stepIndex];
                scale.y=scale.x;
                CLACT_SetActorScale(((Wf2dmapScene *)cell)->actor.handle,(struct Pair *)(&scale));
                (((Wf2dmapScene *)cell)->stepIndex)++;
            }
        }
        for(cellIdx=((Wf2dmapScene *)scene)->subStart;cellIdx<((Wf2dmapScene *)scene)->subEnd;cellIdx++) {
            cell=scene+cellIdx*28;
            if(((Wf2dmapScene *)cell)->stepIndex!=6) {
                scale.x=d_021DA84C[((Wf2dmapScene *)cell)->stepIndex];
                scale.y=scale.x;
                CLACT_SetActorScale(((Wf2dmapScene *)cell)->actor.handle,(struct Pair *)(&scale));
                (((Wf2dmapScene *)cell)->stepIndex)++;
            }
        }
        (((Wf2dmapScene *)scene)->stepTimer)++;
        if(((Wf2dmapScene *)scene)->stepTimer==6) (((Wf2dmapScene *)scene)->step)++;
        break;
    default:
        WF2DMAP_SCENE_UpdateCellRects(scene);
        if(((Wf2dmapScene *)scene)->pendingFlag==0) animSeq=WF2DMAP_SCENE_FindCellByValue((u8 *)scene,((Wf2dmapScene *)scene)->pendingArg);
        else animSeq=WF2DMAP_SCENE_FindLastCellByValue((u8 *)scene,((Wf2dmapScene *)scene)->pendingArg);
        WF2DMAP_SCENE_MoveCursor((u8 *)scene,animSeq);
        if(((Wf2dmapScene *)scene)->groupIndex) WF2DMAP_SCENE_SetCursorVisible(scene,0,1);
        WF2DMAP_SCENE_ClearPending(scene);
        WF2DMAP_SCENE_ResetState(scene,1);
        break;
    }
    return 0;
}






extern int (*d_021DA718[])(char *);






int WF2DMAP_SCENE_Dispatch(char *scene) { int result; result=d_021DA718[*(u32 *)(scene+0x22c)](scene); WF2DMAP_SCENE_UpdateCursorAnim(scene); WF2DMAP_SCENE_UpdateOam(scene); return result; }







/*
 * 2026-10-05 (wave P2 lane Q4, pengy share, user-approved for this function only): first draft, no twin found.
 * Earlier (824 B): the flag at [sp+4] is a member of a local struct with the table (struct { int flag; Tbl t; } L);
 * rec[idx] reads go through a const Wf2dmapCell pointer; up and left write the store in each arm.
 * 2026-10-05 (wave P2 lane Q4b, 25-compile cap): 836 bytes now, same size as the original, 21 bytes differ, all in
 * the head (first 0x34 bytes). Closed this lane: (b) the L-button block is EXACT: the store of idx - 1 is written in each
 * arm (if (idx == 0) { idx = n; p->188 = idx - 1; } else { p->188 = idx - 1; }); cross-jumping keeps the shared subs/str
 * and leaves the then-arm's b to the next instruction (docs/idioms/an-if-else-storing-to-one-target-keeps-the-empty-else-branch-to-next.md).
 * (c) the R-button block is EXACT: idx = p->188; if (idx == p->23C - 1) store 0 else store idx + 1, store in each arm.
 * Remaining residue (a): the original emits movs r0,#0; str r0,[sp,#4] right after the row ldrsh and movs r7,#0xbf late.
 * Here the flag store comes after the final ldr r4 (flag init after cur) or before ldr r6 / row ldrsh (row as a local, flag
 * init between row and col; a pointer to the row gives 18 bytes with the store after muls). scheduling off does not change
 * the head, so the order is IR order, not the scheduler. Pragmas tried this lane with no gain: opt_propagation,
 * opt_dead_assignments, peephole, scheduling (no change), opt_common_subs (836 B but 401 bytes differ),
 * opt_lifetimes (34 differ). Tried and rejected: empty else {}, a wrap helper with (n, cur) parameter order (no change).
 * d_021DA75C has no witness outside the function (the pool word is inside it): give it an overlay token
 * in the integrator step.
 *
 * 2026-10-05 (wave P2 lane Q4c): EXACT. The flag is a plain int local (spilled to [sp+4]), not a struct member:
 * row is read into a local, then flag = 0, then cur = T.v[row][col] (IR order puts the zero store right after the row load).
 * d_021DA75C resolves with the data hint without the ov129 token (data a4).
 */
void WF2DMAP_SCENE_HandleInput(char *scene)
{
    Tbl T = d_021DA75C;
    int changed;
    int row;
    int cellType;
    int index, cellValue, nextValue;
    const Wf2dmapCell *cells = (const Wf2dmapCell *)scene;

    row = *(short *)(scene + 0x1BA);
    changed = 0;
    cellType = T.v[row][*(short *)(scene + 0x1B8)];

    if (((Wf2dmapScene *)scene)->gridActive == 1 && KEY_GetTrg() != 0) {
        ((Wf2dmapScene *)scene)->gridActive = changed;
        WF2DMAP_SCENE_SetCursorPos(scene, cellType);
        if (cellType == 10 || cellType == 11) {
            if (((Wf2dmapScene *)scene)->cursorMode == 2) return;
            ((Wf2dmapScene *)scene)->cursorMode = 2;
            return;
        }
        if (((Wf2dmapScene *)scene)->cursorMode == 1) return;
        ((Wf2dmapScene *)scene)->cursorMode = 1;
        return;
    }
    if (KEY_GetRepeat() & 0x40) {
        int rowValue = *(short *)(scene + 0x1BA);
        if (rowValue > 0) *(short *)(scene + 0x1BA) = rowValue - 1; else *(short *)(scene + 0x1BA) = 2;
        changed = 1;
    } else if (KEY_GetRepeat() & 0x80) {
        *(short *)(scene + 0x1BA) += 1;
        *(short *)(scene + 0x1BA) %= 3;
        changed = 1;
    } else if (KEY_GetRepeat() & 0x10) {
        if (cellType == 10) *(short *)(scene + 0x1B8) = 3;
        else if (cellType == 11) *(short *)(scene + 0x1B8) = 0;
        else {
            *(short *)(scene + 0x1B8) += 1;
            *(short *)(scene + 0x1B8) %= 5;
        }
        changed = 1;
    } else if (KEY_GetRepeat() & 0x20) {
        if (cellType == 10) *(short *)(scene + 0x1B8) = 3;
        else if (cellType == 11) *(short *)(scene + 0x1B8) = 0;
        else {
            int rowValue = *(short *)(scene + 0x1B8);
            if (rowValue > 0) *(short *)(scene + 0x1B8) = rowValue - 1; else *(short *)(scene + 0x1B8) = 4;
        }
        changed = 1;
    } else if (KEY_GetTrg() & 1) {
        if (cellType == 10) {
            WF2DMAP_SCENE_ClearSelection((const Wf2dmapCell *)scene);
            GFL_USE_PlaySeDefaultVolume(1363);
        } else if (cellType == 11) {
            if (WF2DMAP_SCENE_CheckGridNumber((u8 *)scene)) {
                WF2DMAP_SCENE_BuildNumberList(scene);
                GFL_USE_PlaySeDefaultVolume(1357);
            } else {
                WF2DMAP_SCENE_ResetState(scene, 4);
            }
        } else {
            if (((Wf2dmapScene *)scene)->groupIndex == 0) return;
            index = ((Wf2dmapScene *)scene)->cursorIndex;
            ((Wf2dmapCell *)scene)[index].state = cellType + 1;
            WF2DMAP_SCENE_SetCursorVisible(scene, 1, 0);
            WF2DMAP_SCENE_SetCursorVisible(scene, 2, 1);
            WF2DMAP_SCENE_SetCursorPosBySlot(scene, cellType, 2);
            CLACT_SetActorAnimSeq(cells[index].handle, WF2DMAP_SCENE_GetCellAnim(cells[index].state, cells[index].flag));
            CLACT_SetActorAnimSeq(*(struct Obj **)(scene + 0x1CC), 3);
            cellValue = cells[index].value;
            if (index + 1 == ((Wf2dmapScene *)scene)->cellCount) {
                ((Wf2dmapScene *)scene)->pendingCmd = 1;
                ((Wf2dmapScene *)scene)->pendingArg = 0;
                *(short *)(scene + 0x1B8) = 3;
                *(short *)(scene + 0x1BA) = 2;
                changed = 1;
            } else {
                nextValue = cells[index + 1].value;
                if (cellValue != nextValue) {
                    ((Wf2dmapScene *)scene)->pendingCmd = 1;
                    ((Wf2dmapScene *)scene)->pendingArg = nextValue;
                } else {
                    ((Wf2dmapScene *)scene)->pendingCmd = 2;
                    ((Wf2dmapScene *)scene)->pendingArg = index + 1;
                }
                GFL_USE_PlaySeDefaultVolume(1356);
            }
        }
    } else if (KEY_GetTrg() & 2) {
        WF2DMAP_SCENE_ClearSelection((const Wf2dmapCell *)scene);
        GFL_USE_PlaySeDefaultVolume(1363);
    } else if (KEY_GetRepeat() & 0x200) {
        index = ((Wf2dmapScene *)scene)->cursorIndex;
        if (index == 0) {
            index = ((Wf2dmapScene *)scene)->cellCount;
            ((Wf2dmapScene *)scene)->cursorIndex = index - 1;
        } else {
            ((Wf2dmapScene *)scene)->cursorIndex = index - 1;
        }
        index = ((Wf2dmapScene *)scene)->cursorIndex;
        if (cells[index].flag == 1) {
            ((Wf2dmapScene *)scene)->pendingCmd = 2;
            ((Wf2dmapScene *)scene)->pendingArg = index;
        } else {
            ((Wf2dmapScene *)scene)->pendingCmd = 1;
            ((Wf2dmapScene *)scene)->pendingArg = cells[index].value;
            ((Wf2dmapScene *)scene)->pendingFlag = 1;
        }
        GFL_USE_PlaySeDefaultVolume(1352);
    } else if (KEY_GetRepeat() & 0x100) {
        index = ((Wf2dmapScene *)scene)->cursorIndex;
        if (index == ((Wf2dmapScene *)scene)->cellCount - 1) {
            ((Wf2dmapScene *)scene)->cursorIndex = 0;
        } else {
            ((Wf2dmapScene *)scene)->cursorIndex = index + 1;
        }
        index = ((Wf2dmapScene *)scene)->cursorIndex;
        if (cells[index].flag == 1) {
            ((Wf2dmapScene *)scene)->pendingCmd = 2;
            ((Wf2dmapScene *)scene)->pendingArg = index;
        } else {
            ((Wf2dmapScene *)scene)->pendingCmd = 1;
            ((Wf2dmapScene *)scene)->pendingArg = cells[index].value;
        }
        GFL_USE_PlaySeDefaultVolume(1352);
    }
    if (changed == 1) {
        GFL_USE_PlaySeDefaultVolume(1352);
        cellType = T.v[*(short *)(scene + 0x1BA)][*(short *)(scene + 0x1B8)];
        WF2DMAP_SCENE_SetCursorPos(scene, cellType);
        if (cellType == 10 || cellType == 11) {
            if (((Wf2dmapScene *)scene)->cursorMode == 2) return;
            ((Wf2dmapScene *)scene)->cursorMode = 2;
            return;
        }
        if (((Wf2dmapScene *)scene)->cursorMode != 1) ((Wf2dmapScene *)scene)->cursorMode = 1;
    }
}






/*
 * Lever: expand v reads while retaining its declaration/assignment, name n*28, and initialise sum before mul.
 * Permuter found this spelling after38 candidates; baseline DIFF30 bytes; intermediate expand-v DIFF5.
 * trailing: Two zero alignment bytes.
 */
int WF2DMAP_SCENE_GetGridNumber(u8 *scene)
{
  int cellIdx;
  int sum;
  u32 mul;
  u32 state;
  int offset;
  sum = 0;
  mul = 1;
  for (cellIdx = (*((int *) (scene + 0x23c))) - 1; cellIdx > (-1); cellIdx--)
  {
    state = *((int *) (scene + (cellIdx * 28)));
    offset = cellIdx * 28;
    if (*((int *) (scene + offset)))
      sum += ((*((int *) (scene + (cellIdx * 28)))) - 1) * mul;
    mul *= 10;
  }

  return sum;
}






/*
 * trailing: Two zero alignment bytes.
 */
int WF2DMAP_SCENE_CheckGridNumber(u8 *scene) { if(!((Wf2dmapScene *)scene)->paramId) return 1; if(WF2DMAP_SCENE_GetGridNumber(scene)<=((Wf2dmapScene *)scene)->paramSize) return 1; return 0; }






void WF2DMAP_SCENE_BuildNumberList(char *scene)  {
    int cellIdx;
    char *cell;
    void *strbuf=STRBUF_Create(100,50);
    ((Wf2dmapScene *)scene)->listActive=1;
    ((Wf2dmapScene *)scene)->listTimer=0;
    for(cellIdx=0;cellIdx<((Wf2dmapScene *)scene)->cellCount;cellIdx++)  {
        cell=scene+cellIdx*28;
        if(((Wf2dmapScene *)cell)->state==0)  {
            ((Wf2dmapScene *)cell)->state=1;
            CLACT_SetActorAnimSeq((struct Obj *)(((Wf2dmapScene *)cell)->actor.handleRaw),WF2DMAP_SCENE_GetCellAnim(1,((Wf2dmapScene *)cell)->flag));
        }
        WORDSET_FormatNumber(strbuf,((Wf2dmapScene *)cell)->state-1,1,1,1);
        STRBUF_Append((struct U16Vec *)(((Wf2dmapScene *)scene)->strbuf.handleRaw),strbuf);
    }
    STRBUF_Delete(strbuf);
    WF2DMAP_SCENE_ResetState(scene,3);
}





static inline unsigned clear_record(Wf2dmapCell *cell)  {
    cell->state=0;
    return WF2DMAP_SCENE_GetCellAnim(0,cell->flag);
}





void WF2DMAP_SCENE_ClearSelection(const Wf2dmapCell *cells)  {
    int index, value, nextValue;
    ((Wf2dmapScene *)cells)->cursorState=1;
    ((Wf2dmapScene *)cells)->cursorAnimFrame=0;
    if(((Wf2dmapScene *)cells)->groupIndex==0)  {
        index=((Wf2dmapScene *)cells)->cellCount-1;
        ((Wf2dmapScene *)cells)->cursorIndex=index;
        nextValue=cells[index].value;
        ((Wf2dmapScene *)cells)->pendingCmd=1;
        ((Wf2dmapScene *)cells)->pendingArg=nextValue;
        ((Wf2dmapScene *)cells)->pendingFlag=1;
        return;
    }
    index=((Wf2dmapScene *)cells)->cursorIndex;
    CLACT_SetActorAnimSeq((struct Obj *)cells[index].handle,clear_record(&((Wf2dmapCell *)cells)[index]));
    value=cells[index].value;
    if(index>0)  {
        CLACT_SetActorAnimSeq((struct Obj *)cells[index-1].handle,WF2DMAP_SCENE_GetCellAnim(cells[index-1].state,cells[index-1].flag));
        nextValue=cells[index-1].value;
        if(value!=nextValue)  {
            ((Wf2dmapScene *)cells)->pendingCmd=1;
            ((Wf2dmapScene *)cells)->pendingArg=nextValue;
            ((Wf2dmapScene *)cells)->pendingFlag=1;
            return;
        }
        ((Wf2dmapScene *)cells)->pendingCmd=2;
        ((Wf2dmapScene *)cells)->pendingArg=index-1;
    }
}





void WF2DMAP_SCENE_CreateButtons(char *scene)
{
    int index;
    Rects rects;
    for(index=0;index<12;index++) *(void **)(scene+index*28+16)=scene+0x298+index*4;
    rects=d_021DA798;
    for(;index<24;index++) {
        *(u8 *)(scene+index*4+0x298)=rects.rows[index-12].b-rects.rows[index-12].d;
        *(u8 *)(scene+index*4+0x29a)=rects.rows[index-12].a-rects.rows[index-12].c;
        *(u8 *)(scene+index*4+0x299)=rects.rows[index-12].b+rects.rows[index-12].d;
        *(u8 *)(scene+index*4+0x29b)=rects.rows[index-12].a+rects.rows[index-12].c;
    }
    ((Wf2dmapScene *)scene)->buttonCount=255;
    ((Wf2dmapScene *)scene)->buttonMan=BUTTON_MAN_Create((u8 *)(scene+0x298),(int)WF2DMAP_SCENE_HandleButton,(int)scene,50);
}





/*
 * lever: The two-byte table record has byte fields a and b; both pool words reference that record.
 */
void WF2DMAP_SCENE_SetButtonCursor(u8 *scene,int buttonIdx) { if(buttonIdx>=12 && buttonIdx<24) { ((Wf2dmapScene *)scene)->cursorCol=d_021DA72C[buttonIdx-12].a; ((Wf2dmapScene *)scene)->cursorRow=d_021DA72C[buttonIdx-12].b; } }





void WF2DMAP_SCENE_HandleButton(u32 buttonIdx, int isRelease, char *scene)
{
    Wf2dmapCell *cells = (Wf2dmapCell *)scene;
    int index, value, nextValue;
    int cellType;
    if (*(int *)(scene + 0x22C) != 1) return;
    if (((Wf2dmapScene *)scene)->gridActive != 1) ((Wf2dmapScene *)scene)->gridActive = 1;
    if (isRelease == 0) {
        {
            if (buttonIdx <= 11) {
                if (cells[buttonIdx].flag == 1) {
                    ((Wf2dmapScene *)scene)->pendingCmd = 2;
                    ((Wf2dmapScene *)scene)->pendingArg = buttonIdx;
                } else {
                    ((Wf2dmapScene *)scene)->pendingCmd = 1;
                    ((Wf2dmapScene *)scene)->pendingArg = cells[buttonIdx].value;
                }
                GFL_USE_PlaySeDefaultVolume(1352);
            } else if (buttonIdx == 22) {
                *(short *)(scene + 0x1B8) = 0;
                *(short *)(scene + 0x1BA) = 2;
                GFL_USE_PlaySeDefaultVolume(1363);
                WF2DMAP_SCENE_ClearSelection((const Wf2dmapCell *)scene);
            } else if (buttonIdx == 23) {
                *(short *)(scene + 0x1B8) = 3;
                *(short *)(scene + 0x1BA) = 2;
                if (WF2DMAP_SCENE_CheckGridNumber((u8 *)scene)) {
                    WF2DMAP_SCENE_BuildNumberList(scene);
                    GFL_USE_PlaySeDefaultVolume(1357);
                } else {
                    WF2DMAP_SCENE_ResetState(scene, 4);
                }
            } else if (buttonIdx >= 12 && buttonIdx <= 21) {
                if (((Wf2dmapScene *)scene)->groupIndex == 0) return;
                GFL_USE_PlaySeDefaultVolume(1356);
                index = ((Wf2dmapScene *)scene)->cursorIndex;
                cells[index].state = buttonIdx - 11;
                CLACT_SetActorAnimSeq(cells[index].handle, WF2DMAP_SCENE_GetCellAnim(cells[index].state, cells[index].flag));
                WF2DMAP_SCENE_SetCursorVisible(scene, 1, 1);
                cellType = buttonIdx - 12;
                WF2DMAP_SCENE_SetCursorPos(scene, cellType);
                WF2DMAP_SCENE_SetCursorVisible(scene, 1, 0);
                WF2DMAP_SCENE_SetCursorVisible(scene, 2, 1);
                WF2DMAP_SCENE_SetCursorPosBySlot(scene, cellType, 2);
                CLACT_SetActorAnimSeq(*(struct Obj **)(scene + 0x1CC), 3);
                value = cells[index].value;
                if (index + 1 == ((Wf2dmapScene *)scene)->cellCount) {
                    ((Wf2dmapScene *)scene)->pendingCmd = 1;
                    ((Wf2dmapScene *)scene)->pendingArg = 0;
                    ((Wf2dmapScene *)scene)->pendingFlag = 0;
                } else {
                    nextValue = cells[index + 1].value;
                    if (value != nextValue) {
                        ((Wf2dmapScene *)scene)->pendingCmd = 1;
                        ((Wf2dmapScene *)scene)->pendingArg = nextValue;
                        ((Wf2dmapScene *)scene)->pendingFlag = 0;
                    } else {
                        ((Wf2dmapScene *)scene)->pendingCmd = 2;
                        ((Wf2dmapScene *)scene)->pendingArg = index + 1;
                    }
                }
                WF2DMAP_SCENE_SetButtonCursor((u8 *)scene, buttonIdx);
            } else {
                *(short *)(scene + 0x1B8) = (buttonIdx - 12) % 5;
                *(short *)(scene + 0x1BA) = (buttonIdx - 12) / 5;
            }
        }
    }
}




void WF2DMAP_SCENE_ProcessPending(char *scene)  {
    switch(((Wf2dmapScene *)scene)->pendingCmd)  {
        case 0: break;
        case 1: WF2DMAP_SCENE_SetSlot(scene,((Wf2dmapScene *)scene)->pendingArg);
        WF2DMAP_SCENE_SetCellFlags(scene);
        WF2DMAP_SCENE_LayoutCells(scene,1);
        WF2DMAP_SCENE_ResetState(scene,2);
        ((Wf2dmapScene *)scene)->pendingCmd=255;
        break;
        case 2: WF2DMAP_SCENE_MoveCursor((u8 *)scene,((Wf2dmapScene *)scene)->pendingArg);
        WF2DMAP_SCENE_ClearPending(scene);
        break;
        case 255: break;
    }
}





void WF2DMAP_SCENE_ClearPending(char *scene)
{
    ((Wf2dmapScene *)scene)->pendingCmd = 0;
    ((Wf2dmapScene *)scene)->pendingArg = 0;
    ((Wf2dmapScene *)scene)->pendingFlag = 0;
}




int WF2DMAP_SCENE_FindCellByValue(u8 *scene,int value) { int index; int count; count=((Wf2dmapScene *)scene)->cellCount; for(index=0;index<count;index++) if(value==*(int *)(scene+index*28+4)) return index; return 0; }



/*
 * trailing: Two zero alignment bytes.
 * note: 2026-10-05 the count field is read in the loop condition and again at the return (as written by hand); this closed the count/flag register swap.
 */
int WF2DMAP_SCENE_FindLastCellByValue(u8 *scene,int value) { int index; int found=0; for(index=0;index<((Wf2dmapScene *)scene)->cellCount;index++) { if(value==*(int *)(scene+index*28+4)) found=1; else if(found==1) return index-1; } return ((Wf2dmapScene *)scene)->cellCount-1; }



void WF2DMAP_SCENE_InitClact(char *scene,unsigned heapId)  {
    Config cfg = gClActorInitParam;
    ((unsigned char *)&cfg)[8] = 16;
    ((unsigned char *)&cfg)[9] = 112;
    CLACT_InitSystem((const struct Cfg *)(&cfg),heapId,50);
    BG_SYS_SetMainPlaneVisible(16,1);
    ((Wf2dmapScene *)scene)->unit.handle=CLACT_CreateUnit(64,0,50);
    CLACT_SetUnitDefaultRenderer(((Wf2dmapScene *)scene)->unit.handle);
}



void WF2DMAP_SCENE_LoadActorAssets(char *scene)
{
    void *palAnm=((Wf2dmapScene *)scene)->palAnm.handle;
    void *arc=((Wf2dmapScene *)scene)->arcHandle;
    ARC_UTIL_UploadBgCharFromHandle(arc,6,1,0,0,0,50);
    ARC_UTIL_UploadBgPaletteFromHandle(arc,10,1,0,0,0,50);
    PALANM_LoadArcPaletteToSlot(palAnm,59,1,50,0,64,0);
    ARC_UTIL_UploadBgCharFromHandle(arc,7,5,0,0,0,50);
    ARC_UTIL_UploadBgPaletteFromHandle(arc,11,5,0,0,0,50);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc,2,4,0,0,50);
    ((Wf2dmapScene *)scene)->paletteA=CLACT_RegisterPalette(arc,0,0,0,50);
    ((Wf2dmapScene *)scene)->charA=CLACT_RegisterCharacter(arc,5,0,0,50);
    ((Wf2dmapScene *)scene)->cellAnimA=CLACT_RegisterCellAnim(arc,12,15,50);
    ((Wf2dmapScene *)scene)->paletteC=CLACT_RegisterPalette(arc,4,0,32,50);
    ((Wf2dmapScene *)scene)->charC=CLACT_RegisterCharacter(arc,9,0,0,50);
    ((Wf2dmapScene *)scene)->cellAnimC=CLACT_RegisterCellAnim(arc,14,17,50);
    ((Wf2dmapScene *)scene)->paletteB=CLACT_RegisterPalette(arc,3,0,64,50);
    ((Wf2dmapScene *)scene)->charB=CLACT_RegisterCharacter(arc,8,0,0,50);
    ((Wf2dmapScene *)scene)->cellAnimB=CLACT_RegisterCellAnim(arc,13,16,50);
    BMP_MENUWORK_LoadCharAndPltt(4,1,11,0,50);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,384,32,50);
}



void WF2DMAP_SCENE_DeleteActors(char *scene)  {
    int index;
    char *cell;
    for(index=0;index<((Wf2dmapScene *)scene)->cellCount;index++) CLACT_DeleteActor((struct Obj *)(*(int *)(scene+index*28+12)));
    for(index=0;index<2;index++)  {
        cell=scene+index*28;
        CLACT_DeleteActor((struct Obj *)(((Wf2dmapScene *)cell)->extraActor.handleRaw));
        CLACT_DeleteActor((struct Obj *)(((Wf2dmapScene *)cell)->cursorAnimActor));
    }
    for(index=0;index<3;index++) CLACT_DeleteActor((struct Obj *)(*(int *)(scene+index*28+0x194)));
    WF2DMAP_SCENE_DeleteOam((u8 *)scene);
    BMP_WIN_Delete((struct Descriptor *)(((Wf2dmapScene *)scene)->windowHandle));
    for(index=0;index<3;index++)  {
        cell=scene+index*4;
        CLACT_ReleasePalette(((Wf2dmapScene *)cell)->paletteA);
        CLACT_ReleaseCharacter(((Wf2dmapScene *)cell)->charA);
        CLACT_ReleaseCellAnim(((Wf2dmapScene *)cell)->cellAnimA);
    }
    CLACT_DeleteUnit((struct Bank *)(((Wf2dmapScene *)scene)->unit.handleRaw));
    CLACT_ExitSystem();
}



void WF2DMAP_SCENE_CreateCellActors(char *scene)
{
    Params param;
    int cellIdx=0;
    int unit=((Wf2dmapScene *)scene)->unit.handleRaw;
    int index,extraIdx=0;
    unsigned cell;
    param.x=0; param.y=0; param.frame=0; param.speed=10; param.flag=0;
    for(index=0;index<(int)((unsigned)((Wf2dmapScene *)scene)->cellCount+2);index++) {
        cell=(unsigned)scene+(unsigned)extraIdx*28;
        if(index==(int)((unsigned)extraIdx+(unsigned)((Wf2dmapScene *)cell)->group0End+1)) {
            param.x=76+(unsigned)index*8; param.y=24; param.frame=22;
            ((Wf2dmapScene *)cell)->extraActor.handleRaw=(int)CLACT_CreateActor((void *)unit,((Wf2dmapScene *)scene)->charA,((Wf2dmapScene *)scene)->paletteA,((Wf2dmapScene *)scene)->cellAnimA,&param,0,50);
            extraIdx++;
        } else {
            param.x=76+(unsigned)index*8; param.y=24;
            cell=(unsigned)scene+(unsigned)cellIdx*28;
            param.frame=WF2DMAP_SCENE_GetCellAnim(((Wf2dmapScene *)cell)->state,((Wf2dmapScene *)cell)->flag);
            ((Wf2dmapScene *)cell)->actor.handleRaw=(int)CLACT_CreateActor((void *)unit,((Wf2dmapScene *)scene)->charA,((Wf2dmapScene *)scene)->paletteA,((Wf2dmapScene *)scene)->cellAnimA,&param,0,50);
            cellIdx++;
        }
    }
    if(((Wf2dmapScene *)scene)->group1Size==0 && ((Wf2dmapScene *)scene)->group2Size==0) {
        CLACT_SetActorDrawEnable((struct Obj *)((Wf2dmapScene *)scene)->extraActor.handleRaw,0);
        CLACT_SetActorDrawEnable((struct Obj *)((Wf2dmapScene *)scene)->extraActor1,0);
    }
}



void WF2DMAP_SCENE_CreateCursorActors(char *scene)
{
    Params param;
    int unit=((Wf2dmapScene *)scene)->unit.handleRaw;
    param.x=0; param.y=0; param.frame=0; param.speed=0; param.flag=0;
    ((Wf2dmapScene *)scene)->cursorActor.handleRaw=(int)CLACT_CreateActor((void *)unit,((Wf2dmapScene *)scene)->charC,((Wf2dmapScene *)scene)->paletteC,((Wf2dmapScene *)scene)->cellAnimC,&param,0,50);
    ((Wf2dmapScene *)scene)->cursorActor2=(int)CLACT_CreateActor((void *)unit,((Wf2dmapScene *)scene)->charC,((Wf2dmapScene *)scene)->paletteC,((Wf2dmapScene *)scene)->cellAnimC,&param,0,50);
    ((Wf2dmapScene *)scene)->cursorActor4=(int)CLACT_CreateActor((void *)unit,((Wf2dmapScene *)scene)->charC,((Wf2dmapScene *)scene)->paletteC,((Wf2dmapScene *)scene)->cellAnimC,&param,0,50);
    WF2DMAP_SCENE_MoveCursor((u8 *)scene,0);
    CLACT_SetActorAnimSeq((struct Obj *)(((Wf2dmapScene *)scene)->cursorActor.handleRaw),0);
    CLACT_SetActorAutoAnim((struct Obj *)((Wf2dmapScene *)scene)->cursorActor.handleRaw,1);
    ((Wf2dmapScene *)scene)->cursorCol=0; ((Wf2dmapScene *)scene)->cursorRow=0;
    ((Wf2dmapScene *)scene)->cursorMode=1;
    WF2DMAP_SCENE_SetCursorPos(scene,0);
    CLACT_SetActorAnimSeq((struct Obj *)(((Wf2dmapScene *)scene)->cursorActor2),((Wf2dmapScene *)scene)->cursorMode);
    CLACT_SetActorAutoAnim((struct Obj *)((Wf2dmapScene *)scene)->cursorActor2,1);
    CLACT_SetActorObjMode((struct Actor *)(((Wf2dmapScene *)scene)->cursorActor2),1);
    ((Wf2dmapScene *)scene)->cursorValue0=0; ((Wf2dmapScene *)scene)->cursorValue1=0;
    ((Wf2dmapScene *)scene)->cursorActor3=1;
    WF2DMAP_SCENE_SetCursorPos(scene,0);
    CLACT_SetActorAnimSeq((struct Obj *)(((Wf2dmapScene *)scene)->cursorActor4),((Wf2dmapScene *)scene)->cursorActor3);
    CLACT_SetActorObjMode((struct Actor *)(((Wf2dmapScene *)scene)->cursorActor4),1);
    CLACT_SetActorAutoAnim((struct Obj *)((Wf2dmapScene *)scene)->cursorActor4,1);
    WF2DMAP_SCENE_SetCursorVisible(scene,1,0);
    WF2DMAP_SCENE_SetCursorVisible(scene,2,0);
}




void WF2DMAP_SCENE_CreateExtraActors(char *scene)
{
    L param;
    int unit = ((Wf2dmapScene *)scene)->unit.handleRaw;
    param.a = 0;
    param.b = 0;
    param.c = 0;
    param.d = 10;
    param.e = 0;
    ((Wf2dmapScene *)scene)->cursorAnimActor = (int)CLACT_CreateActor((void *)unit, ((Wf2dmapScene *)scene)->charB, ((Wf2dmapScene *)scene)->paletteB, ((Wf2dmapScene *)scene)->cellAnimB, &param.a, 0, 0x32);
    ((Wf2dmapScene *)scene)->cursorAnimActor2 = (int)CLACT_CreateActor((void *)unit, ((Wf2dmapScene *)scene)->charB, ((Wf2dmapScene *)scene)->paletteB, ((Wf2dmapScene *)scene)->cellAnimB, &param.a, 0, 0x32);
    param.x = (((Wf2dmapScene *)scene)->selX0 + ((Wf2dmapScene *)scene)->selX1) / 2;
    param.y = (((Wf2dmapScene *)scene)->selY0 + ((Wf2dmapScene *)scene)->selY1) / 2;
    CLACT_AddActorSurfacePos((struct Obj *)(((Wf2dmapScene *)scene)->cursorAnimActor), (const struct Vec2 *)(&param), 0);
    CLACT_SetActorAnimSeq((struct Obj *)(((Wf2dmapScene *)scene)->cursorAnimActor), 0);
    param.x = (((Wf2dmapScene *)scene)->sel2X0 + ((Wf2dmapScene *)scene)->sel2X1) / 2;
    param.y = (((Wf2dmapScene *)scene)->sel2Y0 + ((Wf2dmapScene *)scene)->sel2Y1) / 2;
    CLACT_AddActorSurfacePos((struct Obj *)(((Wf2dmapScene *)scene)->cursorAnimActor2), (const struct Vec2 *)(&param), 0);
    CLACT_SetActorAnimSeq((struct Obj *)(((Wf2dmapScene *)scene)->cursorAnimActor2), 0);
}




void WF2DMAP_SCENE_SetCursorVisible(char *scene, int cursorIdx, int visible)
{
    CLACT_SetActorDrawEnable(*(void **)(scene + cursorIdx * 0x1c + 0x194), visible);
}



/*
 * lever: Load actor into a local before the current-index store.
 */
void WF2DMAP_SCENE_MoveCursor(u8 *scene,int cellIdx) { Wf2dmapPairS16 pos; void *actor; actor=*(void **)(scene+cellIdx*28+12); ((Wf2dmapScene *)scene)->cursorIndex=cellIdx; CLACT_GetActorSurfacePos(actor,(struct PtS *)&pos,0); pos.y+=16; CLACT_AddActorSurfacePos(((Wf2dmapScene *)scene)->cursorActor.handle,(const struct Vec2 *)(&pos),0); }



void WF2DMAP_SCENE_SetCursorPos(char *scene,int cellIdx)
{
    Wf2dmapPairU16 pos;
    unsigned char *rect = (unsigned char *)scene + (cellIdx+12)*4;
    pos.x = (rect[0x29a] + rect[0x29b])/2;
    pos.y = (rect[0x298] + rect[0x299])/2;
    CLACT_AddActorSurfacePos((struct Obj *)(((Wf2dmapScene *)scene)->cursorActor2),(const struct Vec2 *)(&pos),0);
    CLACT_SetActorAnimFrame((struct Obj *)(((Wf2dmapScene *)scene)->cursorActor2),0);
}



void WF2DMAP_SCENE_SetCursorPosBySlot(char *scene,int cellIdx,int cursorIdx)
{
    Wf2dmapPairU16 pos;
    unsigned char *rect = (unsigned char *)scene + (cellIdx+12)*4;
    pos.x = (rect[0x29a] + rect[0x29b])/2;
    pos.y = (rect[0x298] + rect[0x299])/2;
    CLACT_AddActorSurfacePos((struct Obj *)(*(int *)((scene+0x194)+cursorIdx*0x1c)),(const struct Vec2 *)(&pos),0);
    CLACT_SetActorAnimFrame((struct Obj *)(*(int *)((scene+0x194)+cursorIdx*0x1c)),0);
}



void WF2DMAP_SCENE_UpdateCursorAnim(char *scene)
{
    int cursorIdx;
    for(cursorIdx=1;cursorIdx<3;cursorIdx++){
        int animSeq=CLACT_GetActorAnimSeq(*(void **)(scene+cursorIdx*0x1c+0x194));
        if(animSeq==3){
            if(CLACT_IsActorAnimActive(*(void **)(scene+cursorIdx*0x1c+0x194))==0){
                CLACT_SetActorAnimSeq(*(void **)(scene+cursorIdx*0x1c+0x194),*(int *)(scene+cursorIdx*0x1c+0x188));
                if(((Wf2dmapScene *)scene)->gridActive==1) WF2DMAP_SCENE_SetCursorVisible(scene,1,0);
                else WF2DMAP_SCENE_SetCursorVisible(scene,1,1);
                WF2DMAP_SCENE_SetCursorVisible(scene,2,0);
            }
        }else{
            if(animSeq!=*(int *)(scene+cursorIdx*0x1c+0x188)) CLACT_SetActorAnimSeq(*(void **)(scene+cursorIdx*0x1c+0x194),*(int *)(scene+cursorIdx*0x1c+0x188));
            if(CLACT_GetActorAnimSeq(*(void **)(scene+cursorIdx*0x1c+0x194))!=3){
                if(((Wf2dmapScene *)scene)->gridActive==1) WF2DMAP_SCENE_SetCursorVisible(scene,1,0);
                else WF2DMAP_SCENE_SetCursorVisible(scene,1,1);
            }
        }
    }
}




void WF2DMAP_SCENE_SetOamPos(char *oam, int x, int y)
{
    if (oam != 0)
        BMP_OAM_SetPos((struct Grid *)oam, (short)x, (short)y);
}



/*
 * Extent ends with two bytes of zero alignment padding.
 * Lever: declare the 4-byte-stride pointer before the 28-byte-stride pointer.
 */
void WF2DMAP_SCENE_UpdateOam(char *scene)
{
    int cursorIdx;
    char *byteRow,*cell;
    short x,y;
    for(cursorIdx=0;cursorIdx<2;cursorIdx++) {
        byteRow=scene+cursorIdx*4;
        x=((Wf2dmapScene *)byteRow)->selX0+20;
        y=(((Wf2dmapScene *)byteRow)->selY0+((Wf2dmapScene *)byteRow)->selY1)/2;
        y-=7;
        cell=scene+cursorIdx*28;
        switch(((Wf2dmapScene *)cell)->cursorState) {
        case 0:
            ((Wf2dmapScene *)cell)->cursorAnimFrame=0;
            break;
        case 1:
            ((Wf2dmapScene *)cell)->cursorAnimFrame+=1;
            if(((Wf2dmapScene *)cell)->cursorAnimFrame==1) {
                CLACT_SetActorAnimSeq((struct Obj *)(((Wf2dmapScene *)cell)->cursorAnimActor),1);
                WF2DMAP_SCENE_SetOamPos(*(char * *)&((Wf2dmapScene *)byteRow)->oamA,x,y);
            } else if(((Wf2dmapScene *)cell)->cursorAnimFrame==2) {
                CLACT_SetActorAnimSeq((struct Obj *)(((Wf2dmapScene *)cell)->cursorAnimActor),2);
                WF2DMAP_SCENE_SetOamPos(*(char * *)&((Wf2dmapScene *)byteRow)->oamA,x,y);
            } else if(((Wf2dmapScene *)cell)->cursorAnimFrame==10) {
                CLACT_SetActorAnimSeq((struct Obj *)(((Wf2dmapScene *)cell)->cursorAnimActor),0);
                WF2DMAP_SCENE_SetOamPos(*(char * *)&((Wf2dmapScene *)byteRow)->oamA,x,y);
                ((Wf2dmapScene *)cell)->cursorState+=1;
            }
            break;
        default:
            CLACT_SetActorAnimSeq((struct Obj *)(((Wf2dmapScene *)cell)->cursorAnimActor),0);
            WF2DMAP_SCENE_SetOamPos(*(char * *)&((Wf2dmapScene *)byteRow)->oamA,x,y);
            ((Wf2dmapScene *)cell)->cursorState=0;
            break;
        }
    }
}



int WF2DMAP_SCENE_GetCellAnim(int state,int flag) { int base; base=0; if(!flag) base=11; return base+state; }




void WF2DMAP_SCENE_SetCellFlags(void *scene)
{
    unsigned char *sceneBytes = (unsigned char *)scene;
    int cellIdx;

    for (cellIdx = 0; cellIdx < ((Wf2dmapScene *)sceneBytes)->cellCount; cellIdx++)
    {
        if (cellIdx >= ((Wf2dmapScene *)sceneBytes)->mainStart && cellIdx < ((Wf2dmapScene *)sceneBytes)->mainEnd)
            *(int *)(sceneBytes + cellIdx * 0x1c + 8) = 1;
        else
            *(int *)(sceneBytes + cellIdx * 0x1c + 8) = 0;
    }
}



/*
 * Lever: declare i before y, initialise j after loading y, and keep the equality arm separate.
 */
void WF2DMAP_SCENE_LayoutCells(char *scene,int animate)
{
    Position pos;
    int cellIdx,extraIdx;
    short yPos=*(short *)((unsigned)scene+(unsigned)((Wf2dmapScene *)scene)->groupIndex*2+0x214);
    unsigned cell;
    extraIdx=0;
    for(cellIdx=0;cellIdx<((Wf2dmapScene *)scene)->cellCount;cellIdx++) {
        if(cellIdx>=((Wf2dmapScene *)scene)->mainStart && cellIdx<((Wf2dmapScene *)scene)->mainEnd) {
            if(cellIdx==((Wf2dmapScene *)scene)->mainStart) yPos+=20;
            else yPos+=32;
        } else {
            if(cellIdx==0) yPos+=20;
            else yPos+=8;
        }
        cell=(unsigned)scene+(unsigned)cellIdx*28;
        CLACT_GetActorSurfacePos((struct Actor *)((Wf2dmapScene *)cell)->actor.handleRaw,(struct PtS *)&pos.z,0);
        if(animate==0) {
            pos.z=yPos;
            CLACT_AddActorSurfacePos((struct Obj *)(((Wf2dmapScene *)cell)->actor.handleRaw),(const struct Vec2 *)(&pos.z),0);
        } else {
            ((Wf2dmapScene *)cell)->stepX=(yPos-pos.z)/4;
            ((Wf2dmapScene *)cell)->stepY=0;
            ((Wf2dmapScene *)cell)->stepFrames=4;
            ((Wf2dmapScene *)cell)->stepIndex=0;
        }
        cell=(unsigned)scene+(unsigned)extraIdx*28;
        if(cellIdx==((Wf2dmapScene *)cell)->group0End && extraIdx!=2) {
            CLACT_GetActorSurfacePos((struct Actor *)((Wf2dmapScene *)cell)->extraActor.handleRaw,(struct PtS *)&pos,0);
            if(((Wf2dmapScene *)scene)->mainStart==((Wf2dmapScene *)scene)->mainEnd) yPos+=8;
            else {
                if(cellIdx>((Wf2dmapScene *)scene)->mainStart && cellIdx<((Wf2dmapScene *)scene)->mainEnd) yPos+=20;
                else yPos+=8;
            }
            if(animate==0) {
                pos.x=yPos;
                CLACT_AddActorSurfacePos((struct Obj *)(((Wf2dmapScene *)cell)->extraActor.handleRaw),(const struct Vec2 *)(&pos),0);
            } else {
                ((Wf2dmapScene *)cell)->extraStepX=(yPos-pos.x)/4;
                ((Wf2dmapScene *)cell)->extraStepY=0;
                ((Wf2dmapScene *)cell)->extraStepFrames=4;
            }
            extraIdx++;
        }
    }
}



void WF2DMAP_SCENE_UpdateCellRects(char *scene)
{
    int cellIdx;
    int halfW,halfH;
    Wf2dmapPairS16 pos;
    for(cellIdx=0;cellIdx<((Wf2dmapScene *)scene)->cellCount;cellIdx++){
        if(cellIdx>=((Wf2dmapScene *)scene)->mainStart && cellIdx<((Wf2dmapScene *)scene)->mainEnd){
            halfW=16;
            halfH=16;
        }else{
            halfW=4;
            halfH=8;
        }
        CLACT_GetActorSurfacePos(*(void **)(scene+cellIdx*0x1c+12),(struct PtS *)&pos,0);
        (*(u8 **)(scene+cellIdx*0x1c+16))[0]=pos.y-halfH;
        (*(u8 **)(scene+cellIdx*0x1c+16))[2]=pos.x-halfW;
        (*(u8 **)(scene+cellIdx*0x1c+16))[1]=pos.y+halfH;
        (*(u8 **)(scene+cellIdx*0x1c+16))[3]=pos.x+halfW;
    }
}




void WF2DMAP_SCENE_CreateOam(char *scene)
{
    void *oamSys = BMP_OAM_CreateSys(0x32, ((Wf2dmapScene *)scene)->unit.handle);

    ((Wf2dmapScene *)scene)->oamSys = oamSys;
}



void WF2DMAP_SCENE_DeleteOam(u8 *scene) { CLACT_ReleasePalette(((Wf2dmapScene *)scene)->oamPalette); BMP_OAM_Delete(*(struct Grid * *)&((Wf2dmapScene *)scene)->oamA); BMP_OAM_Delete(*(struct Grid * *)&((Wf2dmapScene *)scene)->oamB); BMP_OAM_DeleteSys(((Wf2dmapScene *)scene)->oamSys); }



void WF2DMAP_SCENE_RegisterCompressedPalette(u8 *scene) { void *arc; arc=ARC_TOOL_CreateHandle(23,50); ((Wf2dmapScene *)scene)->oamPalette=CLACT_RegisterPaletteCompressed(arc,5,0,128,50); ARC_TOOL_DeleteHandle(arc); }



/*
 * prototype: Original calls visibly load r2/r3 and outgoing stack zero; retain those arguments despite the matched callee declaring only two.
 */
void WF2DMAP_SCENE_CreateTextOams(u8 *scene) { int zero; WF2DMAP_SCENE_RegisterCompressedPalette(scene); zero=0; WF2DMAP_SCENE_CreateTextOam(scene,0,78,165,zero); WF2DMAP_SCENE_CreateTextOam(scene,1,172,165,zero); }



/*
 * lever: Expand each coordinate base at its read; binding the base to a
 * pointer local swaps r2/r3 and leaves six bytes different.
 */
void WF2DMAP_SCENE_CreateTextOam(u8 *scene, int index, int argX, int argY, int unused)
{
    void *bank,*msg,*bmp;
    struct Param param;
    short yPos;
    u16 xPos;
    int zero=0;
    bank=MSGDATA_CreateFromArchive(0,2,25,50);
    msg=MSGDATA_AllocString(bank,index+3);
    bmp=BMP_Create(10,2,32,50);
    PRINTSYS_PrintColor(bmp,(80-(int)GF_FONT_MeasureWidestLine(msg,*(u32 *)&((Wf2dmapScene *)scene)->font.handle,0))/2,0,msg,((Wf2dmapScene *)scene)->font.handle,0x3dc0);
    xPos=(scene+(index+22)*4)[0x29a]+20;
    yPos=((scene+(index+22)*4)[0x298]+(scene+(index+22)*4)[0x299])/2;
    param.bmp=bmp;
    param.x=xPos;
    param.y=yPos-7;
    param.f8=((Wf2dmapScene *)scene)->paletteB;
    param.fc=zero;
    param.f10=zero;
    param.f11=zero;
    param.f12=zero;
    param.f14=zero;
    *(void **)(scene+0x304+index*4)=BMP_OAM_Create(((Wf2dmapScene *)scene)->oamSys,&param);
    BMP_OAM_UploadChars(*(void **)(scene+0x304+index*4));
    BMP_Delete(bmp);
    STRBUF_Delete(msg);
    MSGDATA_Delete(bank);
}



/*
 * extent: Two zero alignment bytes at 0x021DA576; next labelled function is 0x021DA578.
 */
void WF2DMAP_SCENE_CreateWindow(void **windowOut,int msgId,int x,int y,int w,int tiles,int palette,int msgBank,int number)
{
    *windowOut=(void *)BMP_WIN_Create((u8)x,(u8)y,(u8)w,(u8)tiles,palette,12,1);
    BMP_MENUWORK_DrawWindow(*windowOut,2,1,11);
    BMP_WIN_MakeScreen(*windowOut);
    WF2DMAP_SCENE_DrawMessage(*windowOut,msgId,(void *)msgBank,number);
}



void WF2DMAP_SCENE_DrawMessage(void *window,int msgId,void *msgBank,u32 number)
{
    void *ws=WORDSET_CreateDefault(50);
    void *bank=MSGDATA_CreateFromArchive(0,2,25,50);
    void *msg=MSGDATA_AllocString(bank,msgId);
    void *out=STRBUF_Create(88,50);
    WORDSET_SetSlotNumber(ws,0,number,2,2,1);
    WORDSET_CopyTaggedText(ws,out,msg);
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    PRINTSYS_Print(BMP_WIN_GetBmp(window),0,0,out,msgBank);
    STRBUF_Delete(out);
    STRBUF_Delete(msg);
    MSGDATA_Delete(bank);
    WORDSET_DeleteStrbufED04(ws);
    BMP_WIN_TransferChars(window);
    BG_SYS_PushTile(4);
}


void WF2DMAP_SCENE_ShowMessage(void *window, int sel, void *msgBank, unsigned int number)
{
    if (sel == 1) {
        WF2DMAP_SCENE_DrawMessage(window, 5, msgBank, number);
        return;
    }
    if (sel == 2)
        WF2DMAP_SCENE_DrawMessage(window, 6, msgBank, number);
}
