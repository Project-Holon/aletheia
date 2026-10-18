/*
 * file:     worldtrade_detail.c
 * unit:     yes
 * function: WORLDTRADE_DETAIL_Init, WORLDTRADE_DETAIL_CallStateHandler, WORLDTRADE_DETAIL_Exit, WORLDTRADE_DETAIL_SetupBgPlanes, WORLDTRADE_DETAIL_ExitBgPlanes, WORLDTRADE_DETAIL_LoadBgGraphics, WORLDTRADE_DETAIL_CreateActors, WORLDTRADE_DETAIL_DeleteActors, WORLDTRADE_DETAIL_CreateWindows, WORLDTRADE_DETAIL_DeleteWindows, WORLDTRADE_DETAIL_CreateStrings, WORLDTRADE_DETAIL_DeleteStrings, WORLDTRADE_DETAIL_StateStart, WORLDTRADE_DETAIL_StateMainInput, WORLDTRADE_DETAIL_StateStartWipeOut, WORLDTRADE_DETAIL_StateOpenConfirm, WORLDTRADE_DETAIL_StateConfirmYesNoInput, WORLDTRADE_DETAIL_StateCreateMenu, WORLDTRADE_DETAIL_StateMenuInput, WORLDTRADE_DETAIL_StateWaitMessage, WORLDTRADE_DETAIL_StateWaitMessageTimed, WORLDTRADE_DETAIL_PrintMessage, WORLDTRADE_DETAIL_GetModeColor, WORLDTRADE_DETAIL_PrintMonInfo, WORLDTRADE_DETAIL_PrintMonName, WORLDTRADE_DETAIL_LoadMonGraphics, WORLDTRADE_DETAIL_DrawRequestWindow
 * address:  0x021FC06C
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
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MI_CpuFill8 0x02082BCC arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   WORLDTRADE_TITLE_ScrollBg 0x021FFFE8 thumb ov135
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
 *   WORLDTRADE_TITLE_LoadSubBgSwap 0x02200B34 thumb ov135
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   WORLDTRADE_INPUT_PrintStringAlignedLine  0x021F91A0  thumb
 *   WORLDTRADE_TITLE_CreateMenuWindow  0x02200BAC  thumb
 *   WORLDTRADE_ADAPTER_DeletePrintStream 0x02202940 thumb ov135
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORLDTRADE_ADAPTER_IsStreamDone  0x02202840  thumb  ov135
 *   MSGDATA_AllocString   0x02045EC0  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   unit_02045730  0x02045730  arm
 *   BG_SYS_PushTile   0x020409B4  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   WORLDTRADE_ADAPTER_QueuePrintDefaultColor  0x02202858  thumb  ov135
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   WORLDTRADE_NoOp  0x0200ADB4  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   tbl_02202EB0   0x02202EB0  data
 *   WORLDTRADE_ADAPTER_CreateString  0x02202670  thumb
 *   BMP_MENUWORK_Create  0x0201F81C  thumb  arm9
 *   BMP_MENUWORK_Delete  0x0201F868  thumb  arm9
 *   BMP_MENUWORK_AddMsgItem  0x0201F878  thumb  arm9
 *   TOUCHPANEL_GetTrg  0x02035C60  arm  arm9
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   WORLDTRADE_ClearBusyFlag  0x021F4EC8  thumb  ov135
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm  arm9
 *   POKE_TOOL_Dummy 0x020185F0 thumb
 *   MYSTATUS_GetName 0x020084F4 thumb
 *   WORLDTRADE_DEPOSIT_GetConditionIndex 0x021F886C thumb ov135
 *   WORLDTRADE_DEPOSIT_DrawRequestWindowAlt 0x021F8290 thumb ov135
 *   g_02203CF0  0x02203CF0  data  ov135
 *   g_022034AC  0x022034AC  data  ov135
 *   g_022034DC  0x022034DC  data  ov135
 *   g_022034BC  0x022034BC  data  ov135
 *   g_022034FC  0x022034FC  data  ov135
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   tbl_0220351C 0x0220351C data a4
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_OpenTaskMenuYesNo  0x021F4BF8  thumb  ov135
 *   WORLDTRADE_ClearBlendRegs  0x021F5060  thumb  ov135
 *   WORLDTRADE_SetBrightnessOut  0x021F5034  thumb  ov135
 *   WORLDTRADE_UpdateTaskMenuYesNo 0x021F4D14 thumb ov135
 *   WORLDTRADE_CloseTaskMenu 0x021F4CE4 thumb ov135
 *   WORLDTRADE_OpenTaskMenuList 0x021F4D50 thumb ov135
 *   WORLDTRADE_UpdateTaskMenuList 0x021F4E30 thumb ov135
 *   WORLDTRADE_CloseTaskMenuList 0x021F4E64 thumb ov135
 *   WORLDTRADE_BOX_IsSpeciesFlagged 0x021F6DE8 thumb ov135
 *   WORDSET_SetSlotMonName  0x0201EE84  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   FILE_UTIL_ReadString  0x02020F84  thumb
 *   STRBUF_SetString  0x02045924  arm
 *   POKEGRA_LoadCharDataPP  0x0202D6F4  thumb
 *   DC_FlushRange  0x020862F0  arm
 *   GX_LoadOBJ  0x0207E780  arm
 *   POKEGRA_GetArcID  0x0202D060  thumb
 *   POKE_TOOL_IsShiny  0x02017EAC  thumb
 *   POKEGRA_GetPalArcIndex  0x0202D0D4  thumb
 */
#include "worldtrade_types.h"

extern void MI_CpuFill8(void *p, u32 v, u32 n);

extern u32 GFL_HEAP_Free(void *p);

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);

extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern void STRBUF_Delete(struct U16Vec *vec);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

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

extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);

extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

extern void CLACT_DeleteActor(struct Obj *p);

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern u32 KEY_GetTrg(void);

extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);

extern u32 BMP_MENUWORK_Delete(void *p);

extern u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);

extern u32 POKEPARTY_GetCount(void *p);

extern int TOUCHPANEL_GetTrg(void);

extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);


extern u8 unit_02045730(u32 a);

extern void BG_SYS_PushTile(u32 index);

extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);

extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

extern const u32 tbl_02202EB0[];

extern void *BMP_MENUWORK_Create(u32 n, u32 heap);

extern void WORLDTRADE_ClearBusyFlag(Work *p);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);


typedef struct {u32 x,y,w,h;} WinDef;

typedef struct {
    u8 pad0[0x14];
    void *data;
} PalFile;

extern void CLACT_SetActorDrawEnable(struct Obj *obj, unsigned int on);

extern void CLACT_SetActorAutoAnim(struct Obj *,u32);

extern void *WORLDTRADE_NoOp(void *);

extern void *POKE_TOOL_Dummy();

extern void *MYSTATUS_GetName(void *);

extern int WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);

extern int WORLDTRADE_DEPOSIT_GetConditionIndex(int,int,int);

extern void WORLDTRADE_DEPOSIT_DrawRequestWindowAlt(void *,void *,int,u8 *,u32,int,int,void *);

extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void ARC_TOOL_DeleteHandle(void *);

extern void CLACT_SetActorBgPriority(void *, int);

extern void WORLDTRADE_SetNextState(void *p, u32 a, u32 b);

extern void WORLDTRADE_SetStateAndReturn(void *p, u32 a, u32 b);

extern void GFL_USE_PlaySeDefaultVolume(unsigned);

extern void WORLDTRADE_OpenTaskMenuYesNo(Work *p, int b, int unused, int a, int c, u8 flag);

extern void WORLDTRADE_ClearBlendRegs(void);

extern void WORLDTRADE_SetBrightnessOut(u32 v);

extern int WORLDTRADE_UpdateTaskMenuYesNo(char *p);

extern void WORLDTRADE_CloseTaskMenu(char *p);

extern void BMP_MENUWORK_DrawWindowBorder(void *p, unsigned kind);

extern void WORLDTRADE_OpenTaskMenuList(Work *p, u16 a, int count, int b);

extern unsigned int WORLDTRADE_UpdateTaskMenuList(unsigned char *p);

extern void WORLDTRADE_CloseTaskMenuList(unsigned char *p);

extern int WORLDTRADE_BOX_IsSpeciesFlagged(unsigned int handle);

extern void WORDSET_SetSlotMonName(struct WordSet *p, u32 i, void *mon);





extern void FILE_UTIL_ReadString(void *dst, u32 entry, u32 heap);

extern void WORLDTRADE_INPUT_PrintStringAlignedLine(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);

extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);

extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);

extern u32 POKEGRA_LoadCharDataPP(void *a0, void *mon, u32 a2, u32 a3);

extern void DC_FlushRange(void *p, u32 n);

extern void GX_LoadOBJ(void *src, u32 dst, u32 n);

extern int POKEGRA_GetArcID(void);

extern u32 POKE_TOOL_IsShiny(void *mon);

extern s32 POKEGRA_GetPalArcIndex(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);


int WORLDTRADE_DETAIL_Init(Work *p);

void WORLDTRADE_DETAIL_CallStateHandler(u8 *p);

int WORLDTRADE_DETAIL_Exit(Work *p);

void WORLDTRADE_DETAIL_SetupBgPlanes(void);

void WORLDTRADE_DETAIL_ExitBgPlanes(void);

void WORLDTRADE_DETAIL_LoadBgGraphics(Work *p);

void WORLDTRADE_DETAIL_CreateActors(Work *p);

void WORLDTRADE_DETAIL_DeleteActors(Work *p);

void WORLDTRADE_DETAIL_CreateWindows(Work *p);

void WORLDTRADE_DETAIL_DeleteWindows(char *p);

void WORLDTRADE_DETAIL_CreateStrings(Work *p);

void WORLDTRADE_DETAIL_DeleteStrings(Work *p);

int WORLDTRADE_DETAIL_StateStart(Work *p);

int WORLDTRADE_DETAIL_StateMainInput(Work *p);

int WORLDTRADE_DETAIL_StateStartWipeOut(Work *p, int a1);

int WORLDTRADE_DETAIL_StateOpenConfirm(Work *p);

int WORLDTRADE_DETAIL_StateConfirmYesNoInput(Work *p);

int WORLDTRADE_DETAIL_StateCreateMenu(Work *p);

int WORLDTRADE_DETAIL_StateMenuInput(Work *p);

int WORLDTRADE_DETAIL_StateWaitMessage(u8 *p);

int WORLDTRADE_DETAIL_StateWaitMessageTimed(u8 *p);

void WORLDTRADE_DETAIL_PrintMessage(u8 *p, u32 b, u32 c, u32 d, u32 e, void *sel);

u16 WORLDTRADE_DETAIL_GetModeColor(int mode);

void WORLDTRADE_DETAIL_PrintMonInfo(void *bank, void *names, void *words, void **win, void *mon, Rec *rec, void *g);

void WORLDTRADE_DETAIL_PrintMonName(void *bank, Pane2 *pane, void *name, void *mon, Pane2 *pane2, void *g);

void WORLDTRADE_DETAIL_LoadMonGraphics(void *mon);

void WORLDTRADE_DETAIL_DrawRequestWindow(Work *p);

void WORLDTRADE_TITLE_ScrollBg(Work *p, u32 a, u32 b);

void WORLDTRADE_TITLE_ExitBgPlanes(Work *p);

void WORLDTRADE_TITLE_LoadSubBgSwap(Work *p);

void WORLDTRADE_TITLE_CreateMenuWindow(Work *p, u32 k);

u32 WORLDTRADE_ADAPTER_CreateString(u32 a, u32 b, u32 c, u32 d);

u32 WORLDTRADE_ADAPTER_IsStreamDone(PrintStreamCtx *p);

u32 WORLDTRADE_ADAPTER_QueuePrintDefaultColor(void *p,u8 b,void *s,u32 x,u32 y,void *out);

void WORLDTRADE_ADAPTER_DeletePrintStream(struct Obj *p);

extern void (*g_02203CF0[])(u8 *);

extern struct DispConfig g_022034AC;

extern struct BgTemplate g_022034DC;

extern struct BgTemplate g_022034BC;

extern struct BgTemplate g_022034FC;

extern const WinDef tbl_0220351C[];

/*
 * note: 2026-10-05 recoup: WIPE_SYS_Start declared with an int return (first-check lever). With void the
 *   literal 1 stayed in r4 for the stack store, r1, r2 and the return (4 B differ); with int the
 *   constants are rematerialised as in the original. The other callees stay void as in their matched files.
 */
int WORLDTRADE_DETAIL_Init(Work *p)
{
    void *mon;
    int index;
    mon=WORLDTRADE_NoOp(*(void **)(*(u8 **)p));
    WORLDTRADE_DETAIL_CreateStrings(p);
    WORLDTRADE_DETAIL_SetupBgPlanes();
    WORLDTRADE_TITLE_ScrollBg(p,0,0);
    WORLDTRADE_DETAIL_LoadBgGraphics(p);
    WORLDTRADE_DETAIL_CreateWindows((Work *)p);
    WORLDTRADE_DETAIL_CreateActors(p);
    WORLDTRADE_DETAIL_PrintMonInfo(*(void **)((u8 *)p+0xB6C),*(void **)((u8 *)p+0xB70),*(void **)((u8 *)p+0xB68),(void **)((u8 *)p+0xD90),POKE_TOOL_Dummy(mon),(Rec *)((u8 *)p+0x1D0),(u8 *)p+0xFA0);
    WORLDTRADE_DETAIL_PrintMonName(*(void **)((u8 *)p+0xB6C),(Pane2 *)((u8 *)p+0xDAC),MYSTATUS_GetName(*(void **)(*(u8 **)(u8 *)p+0x1C)),mon,(Pane2 *)((u8 *)p+0xDC0),(u8 *)p+0xFA0);
    index=WORLDTRADE_DEPOSIT_GetConditionIndex(*(s8 *)((u8 *)p+0x1D7),*(s8 *)((u8 *)p+0x1D8),0);
    WORLDTRADE_DEPOSIT_DrawRequestWindowAlt(*(void **)((u8 *)p+0xB6C),*(void **)((u8 *)p+0xB70),*(int *)((u8 *)p+0xB68),(u8 *)p+0xDB4,*(s16 *)((u8 *)p+0x1D4),*(s8 *)((u8 *)p+0x1D6),index,(u8 *)p+0xFA0);
    WORLDTRADE_DETAIL_LoadMonGraphics(mon);
    WIPE_SYS_Start((void *)3,1,1,0,6,1,0x48);
    p->state=0;
    p->f12E4=0;
    return 1;
}

/*
 * State-table dispatch through the table at 0x02203CF0.
 */
void WORLDTRADE_DETAIL_CallStateHandler(u8 *p)
{
    g_02203CF0[*(u32 *)(p + 0x28)](p);
}

int WORLDTRADE_DETAIL_Exit(Work *p) {WORLDTRADE_DETAIL_DeleteActors(p);WORLDTRADE_DETAIL_DeleteStrings(p);WORLDTRADE_DETAIL_DeleteWindows((char *)p);WORLDTRADE_DETAIL_ExitBgPlanes();WORLDTRADE_TITLE_ExitBgPlanes(p);CLACT_SetActorDrawEnable((*(void * *)&p->fD38),0);WORLDTRADE_ClearBusyFlag(p);return 0;}

/*
 * Three-layer bring-up after the display restore, with engine-B plane 0x16
 * toggled and layers 2 and 3 both 020414EC'd and tilemap-cleared.
 */
void WORLDTRADE_DETAIL_SetupBgPlanes(void)
{
    struct DispConfig c = g_022034AC;
    u32 v = BG_SYS_GetSubVisiblePlanes();

    BG_SYS_SetGraphicsMode(&c);
    BG_SYS_SetSubVisiblePlanes(v);
    BG_SYS_SetSubPlaneVisible(0x16, 1);
    {
        struct BgTemplate t = g_022034DC;
        BG_SYS_InitBgLayer(2, &t, 0);
    }
    BG_SYS_ClearSlot(2);
    BG_SYS_SetPlaneVisible(2, 1);
    {
        struct BgTemplate t = g_022034BC;
        BG_SYS_InitBgLayer(1, &t, 0);
    }
    BG_SYS_SetPlaneVisible(1, 1);
    {
        struct BgTemplate t = g_022034FC;
        BG_SYS_InitBgLayer(3, &t, 0);
    }
    BG_SYS_ClearSlot(3);
    BG_SYS_SetPlaneVisible(3, 1);
    BG_SYS_InitRun(2, 0x20, 0, 0x48);
    BG_SYS_InitRun(3, 0x20, 0, 0x48);
}

/*
 * Poke the channel-selection helper with 0, 1, 2, 3 in turn.
 */
void WORLDTRADE_DETAIL_ExitBgPlanes(void)
{
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(3);
}

void WORLDTRADE_DETAIL_LoadBgGraphics(Work *p)
{
    void *h;
    h = ARC_TOOL_CreateHandle(0x60, 0x48);
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 6, 0, 0, 0x60, 0x48);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(2, 1, 0xe, 0, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(2, 0x1f, 0xb, 0, 0x48);
    ARC_UTIL_UploadBgCharFromHandle(h, 0x10, 1, 0, 0, 1, 0x48);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 0x16, 1, 0, 0x600, 1, 0x48);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x20, 0x20, 0x48);
    WORLDTRADE_TITLE_LoadSubBgSwap(p);
    ARC_TOOL_DeleteHandle(h);
}

void WORLDTRADE_DETAIL_CreateActors(Work *p)
{
    ObjPos pos;
    MI_CpuFill8(&pos, 0, sizeof(pos));
    pos.x = 0xd0;
    pos.y = 0x3a;
    p->obj = CLACT_CreateActor(p->res, (unsigned int)p->set[0], (unsigned int)p->set[1], (unsigned int)p->set[2], &pos, 0, 0x48);
    CLACT_SetActorAutoAnim(p->obj, 1);
    CLACT_SetActorAnimSeq(p->obj, 0x24);
    CLACT_SetActorBgPriority(p->obj, 1);
    CLACT_SetActorDrawEnable(p->obj, 1);
    GFL_NET_RestartWithDefaultTimeout(0, 0x48);
}

/*
 * Tail call into CLACT_DeleteActor with the pointer held at +0xd08.
 */
void WORLDTRADE_DETAIL_DeleteActors(Work *p)
{
    CLACT_DeleteActor((struct Obj *)((*(unsigned int *)&p->obj)));
}

void WORLDTRADE_DETAIL_CreateWindows(Work *p)
{
    int i;
    u32 w;
    p->frame=BMP_WIN_Create(2,(u8)2,(u8)21,(u8)27,2,13,(u16)1);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->frame)),0);
    w=p->frame;
    BMP_WIN_TransferChars((struct Descriptor *)w);
    BMP_WIN_MakeScreen((struct Cfg *)w);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)w));
    p->side=BMP_WIN_Create(2,(u8)21,(u8)15,(u8)10,4,13,(u16)1);
    w=p->side;
    BMP_WIN_TransferChars((struct Descriptor *)w);
    BMP_WIN_MakeScreen((struct Cfg *)w);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)w));
    for(i=0;i<14;i++) {
        p->item_u14[i]=BMP_WIN_Create(3,(u8)tbl_0220351C[i].x,(u8)tbl_0220351C[i].y,(u8)tbl_0220351C[i].w,tbl_0220351C[i].h,13,(u16)1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->item_u14[i])),0);
        w=p->item_u14[i];
        BMP_WIN_TransferChars((struct Descriptor *)w);
        BMP_WIN_MakeScreen((struct Cfg *)w);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)w));
    }
    WORLDTRADE_TITLE_CreateMenuWindow(p,2);
}

/*
 * tail: 021FC526..021FC528 is two zero alignment bytes.
 */
void WORLDTRADE_DETAIL_DeleteWindows(char *p)
{
    int i;
    WORLDTRADE_ADAPTER_DeletePrintStream((struct Obj *)(p + 0xfa0));
    BMP_WIN_Delete(((Work *)p)->fDE0);
    BMP_WIN_Delete(((Work *)p)->d40);
    BMP_WIN_Delete(((Work *)p)->side_p2[0]);
    for (i = 0; i < 14; i++) {
        BMP_WIN_Delete(*(void **)(p + i * 4 + 0xd90));
    }
}

void WORLDTRADE_DETAIL_CreateStrings(Work *p)
{
    int i;
    p->str = STRBUF_Create(0xb4, 0x48);
    p->fB8C = MSGDATA_AllocString(p->bank, 0x2d);
    for (i = 0; i < 10; i++) {
        *(void **)((char *)p + i * 4 + 0xb90) = STRBUF_Create(0x14, 0x48);
    }
}

void WORLDTRADE_DETAIL_DeleteStrings(Work *p) {int i;for(i=0;i<10;i++) STRBUF_Delete(*(struct U16Vec **)((unsigned)(char *)p+i*4+0xb90));STRBUF_Delete(*(struct U16Vec * *)&p->str);STRBUF_Delete(*(struct U16Vec * *)&p->fB8C);}

int WORLDTRADE_DETAIL_StateStart(Work *p) {p->state=1;return 2;}

int WORLDTRADE_DETAIL_StateMainInput(Work *p)
{
    void *q;
    q = WORLDTRADE_NoOp(**(void ** *)(void **)&p->ctx);
    if ((KEY_GetTrg() & 1) || TOUCHPANEL_GetTrg()) {
        WORLDTRADE_DETAIL_PrintMessage((u8 *)p, 5, 1, 0, 0xf0f, q);
        WORLDTRADE_SetNextState(p, 3, 7);
        GFL_USE_PlaySeDefaultVolume(0x54c);
    } else if (KEY_GetTrg() & 2) {
        *(int *)&p->state = 2;
        WORLDTRADE_SetStateAndReturn(p, 1, 0);
        GFL_USE_PlaySeDefaultVolume(0x551);
    }
    return 2;
}

int WORLDTRADE_DETAIL_StateStartWipeOut(Work *p, int a1)
{
    WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, 0x48);
    p->state = 0;
    return 3;
}

/*
 * Build, kick the two fixed helpers and latch state 6.
 */
int WORLDTRADE_DETAIL_StateOpenConfirm(Work *p)
{
    WORLDTRADE_OpenTaskMenuYesNo(p, 0x14, 0x16a, 8, 2, 1);
    WORLDTRADE_ClearBlendRegs();
    WORLDTRADE_SetBrightnessOut(1);
    p->state = 6;
    return 2;
}

/*
 * spelling: if/else keeps the first arm before the second compare; switch moved both compares ahead.
 */
int WORLDTRADE_DETAIL_StateConfirmYesNoInput(Work *p)
{
    unsigned r;
    r = WORLDTRADE_UpdateTaskMenuYesNo((char *)p);
    if (r == 1) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        p->state_i = 2;
        (*(int *)&p->eb4) = 1;
        WORLDTRADE_SetStateAndReturn(p, 7, 8);
        WORLDTRADE_DETAIL_DrawRequestWindow(p);
    } else if (r == 2) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        p->state_i = 0;
        BMP_MENUWORK_DrawWindowBorder(p->d40, 0);
        WORLDTRADE_DETAIL_DrawRequestWindow(p);
    }
    return 2;
}

int WORLDTRADE_DETAIL_StateCreateMenu(Work *p)
{
    p->de8 = BMP_MENUWORK_Create(2, 0x48);
    BMP_MENUWORK_AddMsgItem(p->de8, (u32)(p->bank), 0x3d, 1, 0x48);
    BMP_MENUWORK_AddMsgItem(p->de8, (u32)(p->bank), 0x3e, 2, 0x48);
    WORLDTRADE_OpenTaskMenuList(p, 2, 2, 0x14);
    WORLDTRADE_SetBrightnessOut(1);
    *(int *)&p->state = 8;
    return 2;
}

int WORLDTRADE_DETAIL_StateMenuInput(Work *p)
{
    int r;
    void *q;
    r = WORLDTRADE_UpdateTaskMenuList((unsigned char *)p);
    if (r == 1) {
        WORLDTRADE_CloseTaskMenuList((unsigned char *)p);
        BMP_MENUWORK_Delete(p->de8);
        q = WORLDTRADE_NoOp(**(void ** *)(void **)&p->ctx);
        if (WORLDTRADE_BOX_IsSpeciesFlagged((unsigned int)q) && POKEPARTY_GetCount(p->ctx->party) == 6) {
            WORLDTRADE_DETAIL_PrintMessage((u8 *)p, 0x2a, 1, 0, 0xf0f, q);
            WORLDTRADE_SetNextState(p, 3, 1);
            return 2;
        }
        WORLDTRADE_DETAIL_PrintMessage((u8 *)p, 6, 1, 0, 0xf0f, q);
        WORLDTRADE_SetNextState(p, 3, 5);
        WORLDTRADE_DETAIL_DrawRequestWindow(p);
    } else if (r == 2 || r == -2) {
        WORLDTRADE_CloseTaskMenuList((unsigned char *)p);
        BMP_MENUWORK_Delete(p->de8);
        *(int *)&p->state = 2;
        WORLDTRADE_SetStateAndReturn(p, 1, 0);
        WORLDTRADE_DETAIL_DrawRequestWindow(p);
    }
    return 2;
}

int WORLDTRADE_DETAIL_StateWaitMessage(u8 *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamDone((PrintStreamCtx *)(p + 0xfa0)) == 0) {
        ((Work *)p)->state = ((Work *)p)->returnState;
    }
    return 2;
}

/*
 * When the build query answers 0, bump the countdown at +0xdfc and roll state when it passes 0x2d.
 */
int WORLDTRADE_DETAIL_StateWaitMessageTimed(u8 *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamDone((PrintStreamCtx *)(p + 0xfa0)) == 0) {
        if (++((Work *)p)->cnt > 0x2d) {
            ((Work *)p)->cnt = 0;
            ((Work *)p)->state = ((Work *)p)->returnState;
        }
    }
    return 2;
}

/*
 * The two-parameter member of the 021F7538 family: an extra 0201EE84 call
 * keyed by the sixth argument, the same 0xb6c/0xb88 fields and the same
 * p+0xd40 window group in the other order.
 */
void WORLDTRADE_DETAIL_PrintMessage(u8 *p, u32 b, u32 c, u32 d, u32 e, void *sel)
{
    u32 v;
    u32 h;

    WORDSET_SetSlotMonName(((Work *)p)->words, 0, (void *)sel);
    v = (u32)MSGDATA_AllocString((struct MsgBank *)(*(u32 *)&((Work *)p)->bank_u), b);
    WORDSET_CopyTaggedText((struct WordSet *)(*(u32 *)&((Work *)p)->words), (void *)(((Work *)p)->str), (void *)v);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((Work *)p)->frame)), 0xf);
    BMP_MENUWORK_DrawWindow((void *)(((Work *)p)->frame), 0, 1, 0xe);
    h = ((Work *)p)->frame;
    BMP_WIN_TransferChars((struct Descriptor *)h);
    BMP_WIN_MakeScreen((struct Cfg *)h);
    BG_SYS_PushTile(unit_02045730(h));
    WORLDTRADE_ADAPTER_QueuePrintDefaultColor((void *)(((Work *)p)->frame), 0, (void *)(((Work *)p)->str), 0, 0, p + 0xfa0);
    STRBUF_Delete((struct U16Vec *)v);
}

/*
 * Mode table: 0 -> 0, 1 -> 0x14c0, 2 -> 0xc80, anything else 0.
 */
u16 WORLDTRADE_DETAIL_GetModeColor(int mode)
{
    switch (mode) {
    case 0:
        return 0;
    case 1:
        return 0x53 << 6;
    case 2:
        return 0x32 << 6;
    default:
        return 0;
    }
}

void WORLDTRADE_DETAIL_PrintMonInfo(void *bank, void *names, void *words, void **win, void *mon, Rec *rec, void *g)
{
    u32 lv;
    void *sname;
    void *smode;
    void *s70;
    void *s71;
    void *s4f;
    void *s41;
    void *nick;
    void *ot;
    int mode;
    int name;
    u32 flag;
    int key;
    int i;

    nick = STRBUF_Create(0x1a, 0x48);
    ot = STRBUF_Create(0x26, 0x48);
    POKE_TOOL_GetBoxValue(mon, 0x73, (u32)nick);
    name = rec->name;
    mode = rec->mode;
    key = rec->key;
    lv = POKE_TOOL_GetBoxValue(mon, 6, 0);
    flag = POKE_TOOL_GetBoxValue(mon, 0xAD, 0);
    s4f = MSGDATA_AllocString(bank, 0x4F);
    smode = MSGDATA_AllocString(bank, tbl_02202EB0[mode]);
    s70 = MSGDATA_AllocString(bank, 0x70);
    WORDSET_SetSlotNumber(words, 3, key, 3, 0, 1);
    s71 = (void *)WORLDTRADE_ADAPTER_CreateString((u32)words, (u32)bank, 0x71, 0x48);
    sname = MSGDATA_AllocString(names, name);
    FILE_UTIL_ReadString(ot, (u16)lv, 0x48);
    s41 = MSGDATA_AllocString(bank, 0x41);
    for (i = 0; i < 6; i++) {
        BMP_Clear(BMP_WIN_GetBmp(win[i]), 0);
    }
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[0], nick, 0, 0, 0, 0x440, g);
    if (mode != 3 && flag != 0) {
        WORLDTRADE_INPUT_PrintStringAlignedLine(win[0], smode, 0x40, 0, 0, WORLDTRADE_DETAIL_GetModeColor(mode), g);
    }
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[1], sname, 1, 0, 0, 0x440, g);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[2], s70, 0, 0, 0, 0x440, g);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[3], s71, 0, 0, 0, 0x440, g);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[4], s4f, 0, 0, 0, 0x3C40, g);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[5], ot, 1, 0, 0, 0x440, g);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[6], s41, 0, 0, 0, 0x3C40, g);
    STRBUF_Delete(s4f);
    STRBUF_Delete(ot);
    STRBUF_Delete(s70);
    STRBUF_Delete(s71);
    STRBUF_Delete(smode);
    STRBUF_Delete(nick);
    STRBUF_Delete(sname);
    STRBUF_Delete(s41);
}

void WORLDTRADE_DETAIL_PrintMonName(void *bank, Pane2 *pane, void *name, void *mon, Pane2 *pane2, void *g)
{
    void *s0;
    void *s1;
    void *t0;
    void *t1;

    s0 = STRBUF_Create(0x22, 0x48);
    s1 = STRBUF_Create(0x22, 0x48);
    t0 = MSGDATA_AllocString(bank, 0x37);
    STRBUF_SetString(s0, name);
    t1 = MSGDATA_AllocString(bank, 0xC2);
    POKE_TOOL_GetPartyValue(mon, 0x8D, (u32)s1);
    WORLDTRADE_INPUT_PrintStringAlignedLine(pane->win0, t0, 0, 0, 0, 0x3C40, g);
    WORLDTRADE_INPUT_PrintStringAlignedLine(pane->win1, s0, 0, 0, 0, 0x440, g);
    WORLDTRADE_INPUT_PrintStringAlignedLine(pane2->win0, t1, 0, 0, 0, 0x3C40, g);
    WORLDTRADE_INPUT_PrintStringAlignedLine(pane2->win1, s1, 1, 0, 0, 0x440, g);
    STRBUF_Delete(t0);
    STRBUF_Delete(s0);
    STRBUF_Delete(t1);
    STRBUF_Delete(s1);
}

void WORLDTRADE_DETAIL_LoadMonGraphics(void *mon)
{
    PalFile *pal;
    void *h;
    u32 arc;
    u32 species;
    u32 form;
    u32 shiny;
    u32 id;

    h = (void *)POKEGRA_LoadCharDataPP(&pal, POKE_TOOL_Dummy(), 0, 0x48);
    DC_FlushRange(pal->data, 0x1200);
    GX_LoadOBJ(pal->data, 0x3F80, 0x1200);
    GFL_HEAP_Free(h);
    arc = POKEGRA_GetArcID();
    species = POKE_TOOL_GetPartyValue(mon, 5, 0);
    form = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
    shiny = POKE_TOOL_GetPartyValue(mon, 0x6E, 0);
    id = POKEGRA_GetPalArcIndex(arc, species, form, shiny, POKE_TOOL_IsShiny(mon), 0, 0);
    ARC_UTIL_UploadPaletteFromArchiveWhole(POKEGRA_GetArcID(), id, 1, 0x1A0, 0x20, 0x48);
}

void WORLDTRADE_DETAIL_DrawRequestWindow(Work *p)
{
    int n;
    n = WORLDTRADE_DEPOSIT_GetConditionIndex(((Deposit *)&p->single)->want.b3, ((Deposit *)&p->single)->want.b4, 0);
    WORLDTRADE_DEPOSIT_DrawRequestWindowAlt(p->bank, p->names, (int)(p->words), (u8 *)((char *)p + 0xdb4), ((Deposit *)&p->single)->want.species, ((Deposit *)&p->single)->want.form, n, (char *)p + 0xfa0);
}
