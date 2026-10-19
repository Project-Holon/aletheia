/*
 * file:     worldtrade_list.c
 * unit:     yes
 * function: WORLDTRADE_LIST_Init, WORLDTRADE_LIST_Main, WORLDTRADE_LIST_Exit, WORLDTRADE_LIST_SetupBgPlanes, WORLDTRADE_LIST_ExitBgPlanes, WORLDTRADE_LIST_LoadBgGraphics, WORLDTRADE_LIST_CreateActors, WORLDTRADE_LIST_DeleteActors, WORLDTRADE_LIST_CreateWindows, WORLDTRADE_LIST_DeleteWindows, WORLDTRADE_LIST_CreateStrings, WORLDTRADE_LIST_DeleteStrings, WORLDTRADE_LIST_StateWaitWipeIn, WORLDTRADE_LIST_SelectCursorEntry, WORLDTRADE_LIST_StateMainInput, WORLDTRADE_LIST_StateStartWipeOut, WORLDTRADE_LIST_StatePrintPrompt, WORLDTRADE_LIST_StateConfirmYesNoInput, WORLDTRADE_LIST_DrawSelectedRecord, WORLDTRADE_LIST_StateRedrawRecord, WORLDTRADE_LIST_StateWaitPageWipe, WORLDTRADE_LIST_StateScrollIn, WORLDTRADE_LIST_StateWaitMessage, WORLDTRADE_LIST_PrintMessage, WORLDTRADE_LIST_PrintLabel, WORLDTRADE_LIST_PrintHeader, WORLDTRADE_LIST_PrintRecordRow, WORLDTRADE_LIST_PrintNames, WORLDTRADE_LIST_VBlank
 * address:  0x021FCC40
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from worldtrade_box.c, worldtrade_enter.c, worldtrade_adapter.c, WORLDTRADE_ADAPTER_QueueMessagePrint.c by tools/splitfile.py.
 *
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MI_CpuFill8 0x02082BCC arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   WORLDTRADE_TITLE_ScrollBg 0x021FFFE8 thumb ov135
 *   GXx_GetMasterBrightness_ 0x0207D55C arm
 *   WORLDTRADE_TITLE_ExitBgPlanes 0x022000E4 thumb ov135
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BG_SYS_GetSubVisiblePlanes  0x02043668  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   BG_SYS_InitRun  0x02040B94  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   WORLDTRADE_INPUT_PrintStringAlignedLine  0x021F91A0  thumb
 *   WORLDTRADE_ADAPTER_DeletePrintStream 0x02202940 thumb ov135
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORLDTRADE_ADAPTER_IsStreamBusy  0x02202840  thumb  ov135
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   WORLDTRADE_ADAPTER_QueuePrintDefaultColor  0x02202858  thumb  ov135
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   ARC_UTIL_UploadBgPaletteFromArchive 0x0204989C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   WORLDTRADE_ADAPTER_CreateString  0x02202670  thumb
 *   TOUCHPANEL_HitTrg  0x02035C08  arm  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm  arm9
 *   WORLDTRADE_AdvanceScreenId  0x021F4EC8  thumb  ov135
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   WORLDTRADE_SetActorPos  0x021F4FF4  thumb
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm  arm9
 *   WORLDTRADE_DEPOSIT_FindLevelBracketIndex 0x021F886C thumb ov135
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_OpenTaskMenuYesNo  0x021F4BF8  thumb  ov135
 *   WORLDTRADE_UpdateTaskMenuYesNo 0x021F4D14 thumb ov135
 *   WORLDTRADE_CloseTaskMenu 0x021F4CE4 thumb ov135
 *   tbl_02203D14 0x02203D14 data a4
 *   WORLDTRADE_SetActorSurfacePos 0x021F4EA0 thumb ov135
 *   g_02203618  0x02203618  data  ov135
 *   g_02203628  0x02203628  data  ov135
 *   g_02203648  0x02203648  data  ov135
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   tbl_02203668   0x02203668  data  a4
 *   BMP_WIN_ClearScreen   0x020456F8  arm
 *   WORDSET_ClearAllSlots  0x0201F31C  thumb
 *   WORDSET_SetSlotFromMsgE7  0x0201F048  thumb
 *   WORDSET_SetSlotFromKeyedMessage  0x0201F094  thumb
 *   tbl_02203608 0x02203608 data a1
 *   tbl_022035FC 0x022035FC data a1
 *   WORLDTRADE_INPUT_PrintStringAlignedWrapped  0x021F91DC  thumb
 *   WORLDTRADE_DEPOSIT_PrintBankString  0x021F7FD4  thumb
 *   WORLDTRADE_DEPOSIT_PrintModeLabel  0x021F8104  thumb
 *   WORLDTRADE_DEPOSIT_PrintConditionLabel  0x021F8178  thumb
 *   BG_SYS_ChangeScrollImmediate  0x02040618  arm
 *   WORLDTRADE_DETAIL_PrintMonInfo 0x021FC8CC thumb ov135
 *   WORLDTRADE_DETAIL_PrintMonName 0x021FCA8C thumb ov135
 *   WORLDTRADE_DETAIL_LoadMonGraphics 0x021FCB54 thumb ov135
 *   WORLDTRADE_SUBLCD_CheckButtonTouch 0x021FFB00 thumb ov135
 *   WORLDTRADE_SUBLCD_MoveArrowToSlot 0x021FFD1C thumb ov135
 */
#include "worldtrade_types.h"

extern void MI_CpuFill8(void *p, u32 v, u32 n);

extern void *ARC_TOOL_CreateHandle(u32 archiveID, u16 heapID);
struct MsgBank;
struct Strbuf;

extern struct Strbuf *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern void STRBUF_Delete(struct Strbuf *strbuf);
struct BmpWin;

extern void BMP_WIN_MakeScreen(struct BmpWin *win);

extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);

extern void BG_SYS_SetSubVisiblePlanes(u32 a);

extern u32 BG_SYS_GetSubVisiblePlanes(void);

extern void BG_SYS_ClearSlot(u32 i);

extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);

extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);

extern void BG_SYS_FreeLayerBuf(u32 i);

extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);

extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern struct Actor *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
struct Actor;

extern void CLACT_SetActorAnimSeq(struct Actor *actor, u16 value);

extern void CLACT_DeleteActor(struct Actor *actor);

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Bmp;

extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *p);
struct Bmp;

extern void BMP_Clear(struct Bmp *bmp, u8 value);

extern void BMP_WIN_TransferChars(struct BmpWin *d);

extern u32 BMP_WIN_Delete(struct BmpWin *d);

extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);

extern u32 KEY_GetTrg(void);



extern void BG_SYS_PushTile(u32 index);

extern void BMP_MENUWORK_DrawWindow(struct BmpWin *win, s32 commitMode, u16 tileBase, u32 palette);

extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, struct Strbuf *dest);

extern void ARC_UTIL_UploadBgPaletteFromArchive(u32 archiveID, u32 memberIdx, u32 channel, u32 offset, u32 size, u32 heapID, u16 flags);

extern void WORLDTRADE_AdvanceScreenId(Work *p);

extern void GFL_NET_RefreshWmIconAtTopRight(u32 a, u32 b);


extern void WORLDTRADE_SetActorPos(u32 a, u32 b, u32 c);

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 bgPriority;
} ObjPos_vCFD8;

typedef struct {
    u32 x;
    u32 y;
    u32 w;
    u32 h;
    u32 bg;
} WinDefBg;

typedef struct {u8 left,right;} LRPair;

typedef struct {
    void *win;
} Pane;

extern void CLACT_SetActorDrawEnable(struct Actor *actor, u32 value);

extern void CLACT_SetActorAutoAnim(struct Actor *actor, u32 enable);

extern void WIPE_SYS_Start(void *divisionMode, u32 mainPattern, u32 subPattern, u16 color, u32 frames, u32 wait, u32 heapId);

extern int WORLDTRADE_DEPOSIT_FindLevelBracketIndex(int,int,int);

extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void ARC_TOOL_DeleteHandle(void *);

extern void WORLDTRADE_SetNextState(Work *p, u32 state, u32 returnState);

extern void WORLDTRADE_SetStateAndReturn(Work *p, u32 nextScreenId, u32 kind);

extern void GFL_USE_PlaySeDefaultVolume(unsigned);

extern void WORLDTRADE_OpenTaskMenuYesNo(Work *p, int b, int unused, int a, int c, u8 flag);

extern int WORLDTRADE_UpdateTaskMenuYesNo(char *p);

extern void WORLDTRADE_CloseTaskMenu(char *p);

extern void BMP_MENUWORK_DrawWindowBorder(void *p, unsigned kind);





extern s32 WORLDTRADE_INPUT_PrintStringAlignedLine(u8 *win, u32 str, u32 x, u32 y, u32 align, u16 color, u32 printer);

extern int GXx_GetMasterBrightness_(vu16 *reg);
struct PokemonParam;
struct BoxPokemon;

extern struct BoxPokemon *POKE_TOOL_GetBoxParam(struct PokemonParam *pp);

extern void WORLDTRADE_SetActorSurfacePos(void *, int, int);

extern void BG_SYS_MarkTileDirty(u32 v);


extern void BMP_WIN_ClearScreen(struct BmpWin *win);

extern void WORDSET_ClearAllSlots(struct WordSet *p);

extern void WORDSET_SetSlotFromMsgE7(struct WordSet *p, u32 i, u32 n);

extern void WORDSET_SetSlotFromKeyedMessage(struct WordSet *p, u32 i, u32 a, u32 n);

extern int TOUCHPANEL_HitTrg(const void *);

extern unsigned WIPE_SYS_EndCheck(void);

extern s32 WORLDTRADE_INPUT_PrintStringAlignedWrapped(u8 *win, u32 str, u32 x, u32 y, u32 align, u16 color, u32 printer);

extern void WORLDTRADE_DEPOSIT_PrintBankString(void *win, void *bank, u32 index, u32 y, u16 color, void *g);

extern void WORLDTRADE_DEPOSIT_PrintModeLabel(void *win, void *bank, int mode, int force, u32 x, u32 y, u16 color, void *g);

extern void WORLDTRADE_DEPOSIT_PrintConditionLabel(void *win, void *bank, int idx, u32 e, u32 x, u32 y, u16 color, int alt, u32 g);

extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);


void WORLDTRADE_DETAIL_PrintMonInfo(void *bank, void *names, void *words, void **win, void *mon, Rec *rec, void *g);

void WORLDTRADE_DETAIL_PrintMonName(void *bank, Pane2 *pane, void *name, void *mon, Pane2 *pane2, void *g);

void WORLDTRADE_DETAIL_LoadMonGraphics(void *mon);

int WORLDTRADE_LIST_Init(Work *p);

int WORLDTRADE_LIST_Main(Work *p);

int WORLDTRADE_LIST_Exit(Work *p);

void WORLDTRADE_LIST_SetupBgPlanes(int y);

void WORLDTRADE_LIST_ExitBgPlanes(void);

void WORLDTRADE_LIST_LoadBgGraphics(Work *p);

void WORLDTRADE_LIST_CreateActors(Work *p);

void WORLDTRADE_LIST_DeleteActors(Work *p);

void WORLDTRADE_LIST_CreateWindows(Work *p);

void WORLDTRADE_LIST_DeleteWindows(u8 *p);

void WORLDTRADE_LIST_CreateStrings(Work *p);

void WORLDTRADE_LIST_DeleteStrings(Work *p);

int WORLDTRADE_LIST_StateWaitWipeIn(Work *p);

void WORLDTRADE_LIST_SelectCursorEntry(Work *p, int i);

int WORLDTRADE_LIST_StateMainInput(Work *p);

int WORLDTRADE_LIST_StateStartWipeOut(Work *p);

int WORLDTRADE_LIST_StatePrintPrompt(Work *p);

int WORLDTRADE_LIST_StateConfirmYesNoInput(Work *p);

void WORLDTRADE_LIST_DrawSelectedRecord(Work *p);

int WORLDTRADE_LIST_StateRedrawRecord(Work *p);

int WORLDTRADE_LIST_StateWaitPageWipe(Work *p);

int WORLDTRADE_LIST_StateScrollIn(Work *p);

int WORLDTRADE_LIST_StateWaitMessage(u8 *p);

void WORLDTRADE_LIST_PrintMessage(u8 *p, u32 k, u32 unused1, u32 unused2, u32 unused3);

void WORLDTRADE_LIST_PrintLabel(void *bank, Pane *pane, u32 index, void *g, u16 color);

void WORLDTRADE_LIST_PrintHeader(void *bank, Pane *pane, u32 index, void *g);

void WORLDTRADE_LIST_PrintRecordRow(Pane *pane, void *bank, void *names, Rec *rec, void *g);

void WORLDTRADE_LIST_PrintNames(Pane2 *pane, void *s1, void *s2, void *g);

void WORLDTRADE_LIST_VBlank(Work *p);

int WORLDTRADE_SUBLCD_CheckButtonTouch(int n);

void WORLDTRADE_SUBLCD_MoveArrowToSlot(Work *p, int i, int dy);

void WORLDTRADE_TITLE_ScrollBg(Work *p, u32 a, u32 b);

void WORLDTRADE_TITLE_ExitBgPlanes(Work *p);

u32 WORLDTRADE_ADAPTER_CreateString(u32 a, u32 b, u32 c, u32 d);

u32 WORLDTRADE_ADAPTER_IsStreamBusy(PrintStreamCtx *p);

u32 WORLDTRADE_ADAPTER_QueuePrintDefaultColor(void *p,u8 b,void *s,u32 x,u32 y,void *out);

void WORLDTRADE_ADAPTER_DeletePrintStream(struct Actor *p);

extern struct DispConfig g_02203618;

extern struct BgTemplate g_02203628;

extern struct BgTemplate g_02203648;

extern const WinDefBg tbl_02203668[];

extern const LRPair tbl_02203608[];

extern const u8 tbl_022035FC[];

int WORLDTRADE_LIST_Init(Work *p)
{
    WORLDTRADE_LIST_CreateStrings(p);
    WORLDTRADE_LIST_SetupBgPlanes(-32 - p->scroll);
    if (GXx_GetMasterBrightness_((vu16 *)0x0400106C) == 0) {
        WORLDTRADE_TITLE_ScrollBg(p, -32 - p->scroll, 1);
    } else {
        WORLDTRADE_TITLE_ScrollBg(p, -32 - p->scroll, 0);
    }
    WORLDTRADE_LIST_LoadBgGraphics(p);
    WORLDTRADE_LIST_CreateWindows(p);
    WORLDTRADE_LIST_CreateActors(p);
    WORLDTRADE_DETAIL_PrintMonInfo(p->bank, p->names, p->words, p->win_p7, POKE_TOOL_GetBoxParam((struct PokemonParam *)(&p->arr[p->cur])), (Rec *)(p->arr[p->cur].rec), p->printerBlock);
    WORLDTRADE_DETAIL_PrintMonName(p->bank, (Pane2 *)(&p->win_p7[7]), p->arr[p->cur].name, &p->arr[p->cur], (Pane2 *)p->pane3, p->printerBlock);
    WORLDTRADE_DETAIL_LoadMonGraphics(&p->arr[p->cur]);
    WORLDTRADE_LIST_PrintLabel(p->bank, (Pane *)&p->pane3[2], 0x53, p->printerBlock, 0x440);
    WORLDTRADE_LIST_PrintLabel(p->bank, (Pane *)&p->title, 0x57, p->printerBlock, 0x3C40);
    if (p->flag == 0) {
        WORLDTRADE_LIST_PrintHeader(p->bank, (Pane *)&p->side_p2[0], 0x5E, p->printerBlock);
        WORLDTRADE_LIST_PrintHeader(p->bank, (Pane *)&p->side_p2[1], 0x73, p->printerBlock);
    }
    WORLDTRADE_LIST_DrawSelectedRecord(p);
    WORLDTRADE_SUBLCD_MoveArrowToSlot(p, p->cur, -p->scroll);
    p->vblank = WORLDTRADE_LIST_VBlank;
    *(vu16 *)0x04000304 |= 0x8000;
    GFL_NET_RefreshWmIconAtTopRight(1, 0x48);
    if (p->kind == 0x11) {
        if (GXx_GetMasterBrightness_((vu16 *)0x0400006C) == -16 && GXx_GetMasterBrightness_((vu16 *)0x0400106C) != -16) {
            WIPE_SYS_Start((void *)3, 1, 1, 0, 6, 1, 0x48);
        } else if (GXx_GetMasterBrightness_((vu16 *)0x0400006C) != -16 && GXx_GetMasterBrightness_((vu16 *)0x0400106C) == -16) {
            WIPE_SYS_Start((void *)4, 1, 1, 0, 6, 1, 0x48);
        } else {
            WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x48);
        }
    }
    p->state = 0;
    p->keepBgLayers = 0;
    p->flag = 0;
    return 1;
}

extern int (*const tbl_02203D14[])(void *);

int WORLDTRADE_LIST_Main(Work *p)
{
    int r;
    int i;
    r = tbl_02203D14[p->state_i]((char *)p);
    for (i = 0; i < 8; i++) {
        WORLDTRADE_SetActorSurfacePos(*(void **)((char *)p + i * 4 + 0xd0c), *(s16 *)((char *)p + i * 4 + 0xec4), *(s16 *)((char *)p + i * 4 + 0xec6) + p->scroll + 0x20);
    }
    WORLDTRADE_SetActorPos((*(unsigned int *)&p->obj), 0xd0, 0x3a - p->scroll);
    WORLDTRADE_SUBLCD_MoveArrowToSlot((Work *)p, p->cur, p->scroll);
    return r;
}

int WORLDTRADE_LIST_Exit(Work *p)
{
    (*(int *)&p->every) = 0;
    WORLDTRADE_LIST_DeleteActors(p);
    WORLDTRADE_LIST_DeleteStrings(p);
    WORLDTRADE_LIST_DeleteWindows((u8 *)p);
    WORLDTRADE_LIST_ExitBgPlanes();
    WORLDTRADE_TITLE_ExitBgPlanes(p);
    CLACT_SetActorDrawEnable((struct Actor *)p->scrollBarObj, 0);
    WORLDTRADE_AdvanceScreenId(p);
    if (*(int *)&p->flag == 0)
        GFL_NET_RefreshWmIconAtTopRight(0, 0x48);
    return 0;
}

/*
 * Three-layer bring-up: the saved display config, layers 2 and 1 enabled
 * (only 2 020414EC'd) and layer 2's 0x20x0x48 tilemap cleared.
 */
void WORLDTRADE_LIST_SetupBgPlanes(int unused1)
{
    struct DispConfig c = g_02203618;
    u32 v = BG_SYS_GetSubVisiblePlanes();

    BG_SYS_SetGraphicsMode(&c);
    BG_SYS_SetSubVisiblePlanes(v);
    {
        struct BgTemplate t = g_02203628;

        BG_SYS_InitBgLayer(2, &t, 0);
    }
    BG_SYS_ClearSlot(2);
    BG_SYS_SetPlaneVisible(2, 1);
    {
        struct BgTemplate t = g_02203648;

        BG_SYS_InitBgLayer(1, &t, 0);
    }
    BG_SYS_SetPlaneVisible(1, 1);
    BG_SYS_InitRun(2, 0x20, 0, 0x48);
    BG_SYS_SetMainPlaneVisible(8, 0);
}

/*
 * Poke channel 1 then channel 2.
 */
void WORLDTRADE_LIST_ExitBgPlanes(void)
{
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(2);
}

/*
 * The 0x12fc-field variant: opens the 0x60x0x48 handle, then only when
 * *(u32 *)(p + 0x12fc) == 0 adds the 0xf/0x23 pair through 49658/498F4 and
 * the second 49B40 window.  Both tests reload the same field.
 */
void WORLDTRADE_LIST_LoadBgGraphics(Work *p)
{
    void *h;

    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(4, 1, 2, 0, 0x48);
    h = ARC_TOOL_CreateHandle(0x60, 0x48);
    ARC_UTIL_UploadBgCharFromHandle(h, 0x10, 1, 0, 0xc00, 1, 0x48);
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 6, 0, 0, 0x60, 0x48);
    if (p->flag == 0) {
        ARC_UTIL_UploadBgCharFromHandle(h, 0xf, 6, 0, 0, 0, 0x48);
        ARC_UTIL_UploadBgPaletteFromHandle(h, 0x23, 6, 0, 0, 0, 0x48);
    }
    ARC_TOOL_DeleteHandle(h);
    if (p->flag == 0) {
        ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x20, 0x20, 0x48);
    }
}

void WORLDTRADE_LIST_CreateActors(Work *p)
{
    ObjPos_vCFD8 pos;

    MI_CpuFill8(&pos, 0, sizeof(pos));
    pos.x = 0xD0;
    pos.y = 0x3A;
    p->obj = CLACT_CreateActor(p->res, (u32)p->set[0], (u32)p->set[1], (u32)p->set[2], &pos, 0, 0x48);
    CLACT_SetActorAutoAnim(p->obj, 1);
    CLACT_SetActorAnimSeq(p->obj, 0x24);
    CLACT_SetActorDrawEnable(p->obj, 1);
    GFL_NET_RefreshWmIconAtTopRight(0, 0x48);
}

/*
 * Tail call into CLACT_DeleteActor with the pointer held at +0xd08.
 */
void WORLDTRADE_LIST_DeleteActors(Work *p)
{
    CLACT_DeleteActor((struct Actor *)((*(unsigned int *)&p->obj)));
}

void WORLDTRADE_LIST_CreateWindows(Work *p)
{
    int i;
    const WinDefBg *d;
    u32 v;

    p->frame = BMP_WIN_Create((u8)4, (u8)2, (u8)0x13, (u8)0x1b, 4, 1, (u16)1);
    if (p->flag == 0) {
        p->side_u2[0] = BMP_WIN_Create((u8)4, (u8)1, (u8)0x15, (u8)0xd, 2, 1, (u16)1);
        p->side_u2[1] = BMP_WIN_Create((u8)4, (u8)0x11, (u8)0x15, (u8)0xd, 2, 1, (u16)1);
    }
    for (i = 0; i < 16; i++) {
        d = &tbl_02203668[i];
        if (d->bg == 2) {
            p->win_u16[i] = BMP_WIN_Create((u8)d->bg, (u8)d->x, (u8)d->y, (u8)d->w, d->h, 0xd, (u16)1);
        } else {
            p->win_u16[i] = BMP_WIN_Create((u8)d->bg, (u8)d->x, (u8)d->y, (u8)d->w, d->h, 1, (u16)1);
        }
        v = p->win_u16[i];
        BMP_WIN_TransferChars((struct BmpWin *)v);
        BMP_WIN_MakeScreen((struct BmpWin *)v);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)v));
    }
}

/*
 * Tears down the p+0xd90 array of sixteen window handles, each a 020456F8/
 * 02045730/020409B4/020452E8 group, plus the two p+0xd50/p+0xd54 handles
 * and the p+0xd40 window when *(u32 *)(p + 0x12fc) is clear.
 */
void WORLDTRADE_LIST_DeleteWindows(u8 *p)
{
    u32 h;
    s32 i;

    WORLDTRADE_ADAPTER_DeletePrintStream((struct Actor *)(p + 0xfa0));
    BMP_WIN_Delete((struct BmpWin *)(((Work *)p)->frame));
    if (((Work *)p)->flag == 0) {
        h = ((Work *)p)->win[1];
        BMP_WIN_ClearScreen((struct BmpWin *)h);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)h));
        h = ((Work *)p)->win[0];
        BMP_WIN_ClearScreen((struct BmpWin *)h);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)h));
        BMP_WIN_Delete((struct BmpWin *)(((Work *)p)->win[1]));
        BMP_WIN_Delete((struct BmpWin *)(((Work *)p)->win[0]));
    }
    for (i = 0; i < 0x10; i++) {
        h = *(u32 *)(p + i * 4 + 0xd90);
        BMP_WIN_ClearScreen((struct BmpWin *)h);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)h));
        BMP_WIN_Delete((struct BmpWin *)(*(u32 *)(p + i * 4 + 0xd90)));
    }
}

void WORLDTRADE_LIST_CreateStrings(Work *p)
{
    Entry *e = &p->arr[p->cur];

    p->str = STRBUF_Create(0xB4, 0x48);
    WORDSET_ClearAllSlots(p->words);
    if (e->nation != 0) {
        WORDSET_SetSlotFromMsgE7(p->words, 8, e->nation);
    }
    if (e->area != 0) {
        WORDSET_SetSlotFromKeyedMessage(p->words, 9, e->nation, e->area);
    }
    p->name0 = (void *)WORLDTRADE_ADAPTER_CreateString((u32)p->words, (u32)p->bank, 0x58, 0x48);
    p->name1 = (void *)WORLDTRADE_ADAPTER_CreateString((u32)p->words, (u32)p->bank, 0x59, 0x48);
}

/*
 * Release the +0xb90, +0xb94 and +0xb88 handles.
 */
void WORLDTRADE_LIST_DeleteStrings(Work *p)
{
    STRBUF_Delete((struct Strbuf *)((*(unsigned int *)&p->name0)));
    STRBUF_Delete((struct Strbuf *)((*(unsigned int *)&p->name1)));
    STRBUF_Delete((struct Strbuf *)((*(unsigned int *)&p->str)));
}

int WORLDTRADE_LIST_StateWaitWipeIn(Work *p)
{
    CLACT_SetActorDrawEnable((struct Actor *)p->scrollBarObj, 0);
    if (p->kind == 16) {
        WIPE_SYS_Start(0, 1, 1, 0, 16, 1, 0x48);
        p->state_i = 7;
    } else {
        p->state_i = 1;
        CLACT_SetActorDrawEnable((struct Actor *)p->arrow, 1);
    }
    return 2;
}

void WORLDTRADE_LIST_SelectCursorEntry(Work *p, int slot)
{
    if (slot != p->cur && slot >= 0) {
        CLACT_SetActorAnimSeq((struct Actor *)(*(u32 *)((unsigned char *)p + (slot + 1) * 4 + 0xd0c)), slot * 4 + 16);
        p->state_i = 2;
        WORLDTRADE_SetStateAndReturn(p, 3, 17);
        p->cur = slot;
        WORLDTRADE_SUBLCD_MoveArrowToSlot((Work *)p, slot, 0);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        (*(int *)&p->keepBgLayers) = 1;
        (*(int *)&p->flag) = 1;
    }
}

/*
 * prototype: 021FD6F4 retains r2=1,r3=0,sp=0xF0F visibly loaded by this caller.
 */
int WORLDTRADE_LIST_StateMainInput(Work *p)
{
    int next, r;
    if(KEY_GetTrg()&1) {
        WORLDTRADE_LIST_PrintMessage((u8 *)p,16,1,0,0xF0F);
        WORLDTRADE_SetNextState(p,3,4);
        GFL_USE_PlaySeDefaultVolume(0x54C);
    } else if(KEY_GetTrg()&2) {
        WIPE_SYS_Start(0,0,0,0,16,1,0x48);
        p->state_i=8;
        GFL_USE_PlaySeDefaultVolume(0x551);
    } else if(KEY_GetTrg()&32) {
        next=tbl_02203608[(u32)p->cur].left;
        if(p->cur!=next && (*(int *)&p->d0)>=next+1)
            WORLDTRADE_LIST_SelectCursorEntry(p,next);
    } else if(KEY_GetTrg()&16) {
        next=tbl_02203608[(u32)p->cur].right;
        if(p->cur!=next && (*(int *)&p->d0)>=next+1)
            WORLDTRADE_LIST_SelectCursorEntry(p,next);
    } else {
        r=WORLDTRADE_SUBLCD_CheckButtonTouch((*(int *)&p->d0));
        if(r!=-1) WORLDTRADE_LIST_SelectCursorEntry(p,r);
        r=TOUCHPANEL_HitTrg(tbl_022035FC);
        if(r==0) {
            WORLDTRADE_LIST_PrintMessage((u8 *)p,16,1,0,0xF0F);
            WORLDTRADE_SetNextState(p,3,4);
            GFL_USE_PlaySeDefaultVolume(0x54C);
        } else if(r==1) {
            WIPE_SYS_Start(0,0,0,0,16,1,0x48);
            p->state_i=8;
            GFL_USE_PlaySeDefaultVolume(0x551);
        }
    }
    return 2;
}

int WORLDTRADE_LIST_StateStartWipeOut(Work *p)
{
    CLACT_SetActorDrawEnable((struct Actor *)p->arrow, 0);
    if (p->kind != 15) {
        if (p->kind == 6)
            WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x48);
        else
            WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    p->state_i = 0;
    return 3;
}

/*
 * Build with the fixed 0x12/0x12e/3/4/1 argument pair and latch state 5.
 */
int WORLDTRADE_LIST_StatePrintPrompt(Work *p)
{
    WORLDTRADE_OpenTaskMenuYesNo(p, 0x12, 0x12e, 3, 4, 1);
    p->state = 5;
    return 2;
}

int WORLDTRADE_LIST_StateConfirmYesNoInput(Work *p)
{
    unsigned r = WORLDTRADE_UpdateTaskMenuYesNo((char *)p);
    if (r == 1) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        *(int *)&p->state = 2;
        WORLDTRADE_SetStateAndReturn(p, 5, 6);
        WORLDTRADE_LIST_PrintLabel(p->bank, (Pane *)((unsigned char *)p + 0xdc8), 0x53, (unsigned char *)p + 0xfa0, 0x440);
        WORLDTRADE_LIST_PrintLabel(p->bank, (Pane *)((unsigned char *)p + 0xdb4), 0x57, (unsigned char *)p + 0xfa0, 0x3c40);
        WORLDTRADE_LIST_DrawSelectedRecord((Work *)p);
    } else if (r == 2) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        BMP_MENUWORK_DrawWindowBorder(p->d40, 0);
        *(int *)&p->state = 1;
        WORLDTRADE_LIST_PrintHeader(p->bank, (Pane *)((unsigned char *)p + 0xd50), 0x5e, (unsigned char *)p + 0xfa0);
        WORLDTRADE_LIST_PrintHeader(p->bank, (Pane *)((unsigned char *)p + 0xd54), 0x73, (unsigned char *)p + 0xfa0);
    }
    return 2;
}

void WORLDTRADE_LIST_DrawSelectedRecord(Work *p)
{
    ARC_UTIL_UploadBgPaletteFromArchive(0x60, 0x1E, 1, 0, 0x800, 1, 0x48);
    WORLDTRADE_LIST_PrintNames((Pane2 *)p->pane2_p5, p->name0, p->name1, p->printerBlock);
    WORLDTRADE_LIST_PrintRecordRow((Pane *)(&p->pane), p->bank, p->names, (Rec *)(p->arr[p->cur].key), p->printerBlock);
}

/*
 * Reset the sub-state and report 2.
 */
int WORLDTRADE_LIST_StateRedrawRecord(Work *p)
{
    WORLDTRADE_LIST_DrawSelectedRecord((Work *)p);
    p->state = 1;
    return 2;
}

int WORLDTRADE_LIST_StateWaitPageWipe(Work *p) { (p->pageNum)++; if(WIPE_SYS_EndCheck()) {p->pageNum=0; p->state=1; CLACT_SetActorDrawEnable(*(struct Actor * *)(void * *)&p->arrow,1);} return 2; }

/*
 * volatile: 021FD6B0 reads hardware register 04000304.
 */
int WORLDTRADE_LIST_StateScrollIn(Work *p)
{
    --p->scroll;
    if (WIPE_SYS_EndCheck()) {
        *(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000);
        p->state_i = 2;
        WORLDTRADE_SetStateAndReturn(p, 4, 15);
        p->scroll = 16;
    }
    return 2;
}

int WORLDTRADE_LIST_StateWaitMessage(u8 *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamBusy((PrintStreamCtx *)(p + 0xfa0)) == 0) {
        ((Work *)p)->state = ((Work *)p)->returnState;
    }
    return 2;
}

/*
 * Tear the object down: unhook the two sub-objects, release the +0xd40 resource, wire the 0/1/2 quad, then drain the four engine hooks.
 */
void WORLDTRADE_LIST_PrintMessage(u8 *p, u32 msgId, u32 unused1, u32 unused2, u32 unused3)
{
    u32 v;

    MSGDATA_ReadString((struct MsgBank *)(((Work *)p)->bank_u), msgId, (void *)(*(u32 *)(p + 0xb6c + 0x1c)));
    BMP_Clear((struct Bmp *)((u32)BMP_WIN_GetBmp((struct BmpWin *)((Work *)p)->frame)), 0xf);
    BMP_MENUWORK_DrawWindow((void *)(((Work *)p)->frame), 0, 1, 0x2);
    WORLDTRADE_ADAPTER_QueuePrintDefaultColor((void *)(((Work *)p)->frame), 0, (void *)(*(u32 *)(p + 0xb6c + 0x1c)), 0, 0, p + 0xfa0);
    v = ((Work *)p)->frame;
    BMP_WIN_TransferChars((struct BmpWin *)v);
    BMP_WIN_MakeScreen((struct BmpWin *)v);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)v));
}

void WORLDTRADE_LIST_PrintLabel(void *bank, Pane *pane, u32 index, void *printer, u16 color)
{
    void *str = MSGDATA_AllocString(bank, index);

    WORLDTRADE_INPUT_PrintStringAlignedLine(pane->win, (u32)str, (u32)0, (u32)2, (u32)0, color, (u32)printer);
    STRBUF_Delete(str);
}

void WORLDTRADE_LIST_PrintHeader(void *bank, Pane *pane, u32 index, void *printer)
{
    void *str = MSGDATA_AllocString(bank, index);
    void *win;

    WORLDTRADE_INPUT_PrintStringAlignedWrapped(pane->win, (u32)str, (u32)0, (u32)0, (u32)1, 0x3C40, (u32)printer);
    win = pane->win;
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(win));
    STRBUF_Delete(str);
}

void WORLDTRADE_LIST_PrintRecordRow(Pane *pane, void *bank, void *names, Rec *rec, void *printer)
{
    BMP_Clear(BMP_WIN_GetBmp(pane->win), 0);
    WORLDTRADE_DEPOSIT_PrintBankString(pane->win, names, rec->name, 0, 0x440, printer);
    WORLDTRADE_DEPOSIT_PrintModeLabel(pane->win, bank, rec->mode, 0, 0x49, 0, 0x440, printer);
    WORLDTRADE_DEPOSIT_PrintConditionLabel(pane->win, bank, WORLDTRADE_DEPOSIT_FindLevelBracketIndex(rec->key, rec->val, 0), 0, 0x68, 0, 0x440, 0, (u32)printer);
}

void WORLDTRADE_LIST_PrintNames(Pane2 *pane, void *s1, void *s2, void *printer)
{
    BMP_Clear(BMP_WIN_GetBmp(pane->win0), 0);
    BMP_Clear(BMP_WIN_GetBmp(pane->win1), 0);
    if (s1 != 0) {
        WORLDTRADE_INPUT_PrintStringAlignedLine(pane->win0, (u32)s1, (u32)0, (u32)0, (u32)0, 0x440, (u32)printer);
    }
    if (s2 != 0) {
        WORLDTRADE_INPUT_PrintStringAlignedLine(pane->win1, (u32)s2, (u32)0, (u32)0, (u32)0, 0x440, (u32)printer);
    }
}

void WORLDTRADE_LIST_VBlank(Work *p)
{
    BG_SYS_ChangeScrollImmediate(0, 3, p->scroll);
    BG_SYS_ChangeScrollImmediate(1, 3, p->scroll);
    BG_SYS_ChangeScrollImmediate(2, 3, p->scroll);
    BG_SYS_ChangeScrollImmediate(3, 3, p->scroll);
    BG_SYS_ChangeScrollImmediate(4, 3, -p->scroll);
    BG_SYS_ChangeScrollImmediate(5, 3, -32 - p->scroll);
    BG_SYS_ChangeScrollImmediate(6, 3, -p->scroll);
    BG_SYS_ChangeScrollImmediate(7, 3, -p->scroll);
}
