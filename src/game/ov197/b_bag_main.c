/*
 * file:     b_bag_main.c
 * unit:     yes
 * function: B_BAG_MAIN_InitWindows, B_BAG_MAIN_CreateWindows, B_BAG_MAIN_DeleteWindows, B_BAG_MAIN_ExitWindows, B_BAG_MAIN_DrawPage, B_BAG_MAIN_PrintLabel, B_BAG_MAIN_DrawLabels, B_BAG_MAIN_DrawItemName, B_BAG_MAIN_DrawItemInfo, B_BAG_MAIN_DrawSlot, B_BAG_MAIN_DrawPocket, B_BAG_MAIN_DrawHeader, B_BAG_MAIN_DrawInfoBox, B_BAG_MAIN_DrawItemsPage, B_BAG_MAIN_DrawDescription, B_BAG_MAIN_DrawItemUsage, B_BAG_MAIN_DrawOtherPage, B_BAG_MAIN_PrintItemMsg, B_BAG_MAIN_StartItemMsg, B_BAG_MAIN_UpdateTool, B_BAG_MAIN_ShowWindows, B_BAG_MAIN_CheckKeyItem, B_BAG_MAIN_SyncCursorToItem, B_BAG_MAIN_BuildPocketLists, B_BAG_MAIN_BuildOtherList, B_BAG_MAIN_InitOtherPage, B_BAG_MAIN_GetSlotItem, B_BAG_MAIN_GetItemFlag, B_BAG_MAIN_InitFrames, B_BAG_MAIN_DeleteFrames, B_BAG_MAIN_LayoutFrames, B_BAG_MAIN_StartFrameAnim, B_BAG_MAIN_StepFrameAnim, B_BAG_MAIN_CreateItemGraphics, B_BAG_MAIN_ClearHandles, B_BAG_MAIN_RegisterItemChars, B_BAG_MAIN_LoadItemGraphic, B_BAG_MAIN_LoadItemPalette, B_BAG_MAIN_RegisterCursorGraphics, B_BAG_MAIN_RegisterIconGraphics, B_BAG_MAIN_CreateItemActor, B_BAG_MAIN_CreateItemActors, B_BAG_MAIN_DeleteItemGraphics, B_BAG_MAIN_PlaceActor, B_BAG_MAIN_SetDisplayMode, B_BAG_MAIN_DisplaySingle, B_BAG_MAIN_DisplayList, B_BAG_MAIN_DisplaySelected, B_BAG_MAIN_CreateToolActors, B_BAG_MAIN_DeleteToolActors, B_BAG_MAIN_CreateFingerCursor, B_BAG_MAIN_DeleteFingerCursor, B_BAG_MAIN_StartFingerCursor, B_BAG_MAIN_DeleteFingerCursorActor, B_BAG_MAIN_DrawItemRow, B_BAG_MAIN_Create, B_BAG_MAIN_Main, B_BAG_MAIN_StateInit, B_BAG_MAIN_StateInitOther, B_BAG_MAIN_StateWaitPrintWipe, B_BAG_MAIN_StateWipeEnd, B_BAG_MAIN_StateSelectPocket, B_BAG_MAIN_StateSelectItem, B_BAG_MAIN_StateChangeCount, B_BAG_MAIN_StateWaitPrintRedraw, B_BAG_MAIN_StateChooseItem, B_BAG_MAIN_StateShowMessage, B_BAG_MAIN_StateShowPocket0, B_BAG_MAIN_StateShowPocket1, B_BAG_MAIN_StateShowPocket2, B_BAG_MAIN_StateWaitPrintSetMode, B_BAG_MAIN_StateStartMessage, B_BAG_MAIN_StateMessageInput, B_BAG_MAIN_StateMessageDone, B_BAG_MAIN_StateWaitKey, B_BAG_MAIN_StateFadeOut, B_BAG_MAIN_StateWaitFade, B_BAG_MAIN_StateExit, B_BAG_MAIN_StateOtherFlow, B_BAG_MAIN_InitBg, B_BAG_MAIN_ExitBg, B_BAG_MAIN_LoadBgGraphics, B_BAG_MAIN_CreateText, B_BAG_MAIN_DeleteText, B_BAG_MAIN_ResetBgSlot, B_BAG_MAIN_SwitchPage, B_BAG_MAIN_CheckCancel, B_BAG_MAIN_PlaySe, B_BAG_MAIN_PlaySe2, B_BAG_MAIN_CreateCursor, B_BAG_MAIN_DeleteCursor, B_BAG_MAIN_RecreateCursor, B_BAG_MAIN_SetCursorVisible, B_BAG_MAIN_LayoutCursor, B_BAG_MAIN_ShowCursorAt, B_BAG_MAIN_HandleSelection
 * address:  0x0220B120
 * region:   ov197
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   d_0220DA68 0x0220DA68 data a4
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   d_0220DA0D 0x0220DA0D data a1
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   WORDSET_Callback_EF40 0x0201EF40 thumb
 *   d_0220DA38 0x0220DA38 data a4
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   d_0220DA3C 0x0220DA3C data a4
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   d_0220DA28 0x0220DA28 data a1
 *   d_0220DA19 0x0220DA19 data a1
 *   STRBUF_Create 0x020457B0 arm
 *   FILE_UTIL_ReadStringAlt 0x02020FB4 thumb
 *   d_0220DA08 0x0220DA08 data a1
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   B_APP_TOOL_Update 0x0220B0B0 thumb
 *   B_APP_TOOL_ShowWindows  0x0220B094  thumb  ov196
 *   MYITEM_SAVEDATA_HasItem 0x02007F68 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 *   func_020081DC 0x020081DC thumb
 *   func_020307B0 0x020307B0 arm
 *   d_0220DB3C 0x0220DB3C data a4
 *   d_0220DB3F 0x0220DB3F data a4
 *   ITEM_GFX_IsFlagClear 0x0202F114 thumb
 *   ITEM_GFX_GetItemId 0x0202F138 thumb
 *   ITEM_GFX_GetExtraValue 0x0202F144 thumb
 *   BGWINFRM_Create 0x0202C9B4 thumb
 *   func_020490F4 0x020490F4 arm
 *   BGWINFRM_AddFrame 0x0202CA3C thumb
 *   BGWINFRM_SetClipArea 0x0202CFEC thumb
 *   BGWINFRM_SetFrameDataArcHandle 0x0202CB18 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   d_0220DB44 0x0220DB44 data a4
 *   BGWINFRM_Delete 0x0202CA0C thumb
 *   BGWINFRM_ChangePalette 0x0202CE50 thumb
 *   BGWINFRM_ShowFrame 0x0202CC58 thumb
 *   BGWINFRM_HideFrame 0x0202CC70 thumb
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   FILE_UTIL_GetItemCount 0x02020F08 thumb
 *   FILE_UTIL_Get 0x02020E60 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   FILE_UTIL_GetBankCount 0x02020F0C thumb
 *   FILE_UTIL_GetBaseIndex 0x02020F10 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_UTIL_LoadScreenDataFromHandle 0x02049E74 arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   PALANM_LoadHandlePaletteToSlot 0x020216B4 thumb
 *   func_02049B40 0x02049B40 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   PALANM_CopyToSlot 0x020215BC thumb
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   d_0220DBBC 0x0220DBBC data a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   d_0220DB7C 0x0220DB7C data a4
 *   d_0220DB88 0x0220DB88 data a4
 *   d_0220DB80 0x0220DB80 data a4
 *   B_APP_TOOL_CreateActors 0x0220AF6C thumb ov196
 *   B_APP_TOOL_SetActorsVisible 0x0220AFDC thumb ov196
 *   B_APP_TOOL_DeleteActors 0x0220AFC4 thumb ov196
 *   BTLV_FINGER_CURSOR_Create 0x02209A7C thumb
 *   BTLV_FINGER_CURSOR_Delete 0x02209B30 thumb
 *   BTLV_FINGER_CURSOR_Start  0x02209B60  thumb  ov094
 *   BTLV_FINGER_CURSOR_DeleteActor 0x02209C18 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   d_0220E0E0 0x0220E0E0 data a1
 *   func_02030734 0x02030734 arm
 *   BTLV_EFFECT_GetOwner 0x021F86D4 thumb ov094
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   func_02030DA8 0x02030DA8 arm
 *   func_0200829C 0x0200829C thumb
 *   func_020082B0 0x020082B0 thumb
 *   func_020082B4 0x020082B4 thumb
 *   TCBL_Main 0x020310C4 arm
 *   BGWINFRM_UpdateMoves 0x0202CD94 thumb
 *   d_0220DF40 0x0220DF40 data a4
 *   d_04001050 0x04001050 data a2
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   TCBL_Create 0x0203101C arm
 *   B_APP_TOOL_Create 0x0220AF40 thumb ov196
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   FILE_UTIL_Get_0FE4 0x02020FE4 thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetCont 0x0203630C arm
 *   KEY_GetTrg 0x020362DC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   WIPE_SYS_ExeEnd 0x020221B8 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   B_APP_TOOL_Delete 0x0220AF64 thumb ov196
 *   func_02030EAC 0x02030EAC arm
 *   BTLV_FINGER_CURSOR_IsActive 0x02209C2C thumb
 *   BG_SYS_ApplyGraphicsMode 0x0203FC6C arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   d_0220DEB0 0x0220DEB0 data a4
 *   d_0220DEE0 0x0220DEE0 data a4
 *   d_0220DF20 0x0220DF20 data a4
 *   d_0220DF00 0x0220DF00 data a4
 *   d_0220DEC0 0x0220DEC0 data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   func_02045B38 0x02045B38 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   BG_SYS_ClearLayerEx 0x02041570 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CURSOR_MOVE_Create 0x02025CD0 thumb
 *   CURSOR_MOVE_EnableInput 0x02025D1C thumb
 *   CURSOR_MOVE_SetMode 0x02025D24 thumb
 *   d_0220DF90 0x0220DF90 data a4
 *   d_0220DF9C 0x0220DF9C data a4
 *   CURSOR_MOVE_Delete  0x02025D14  thumb
 *   CURSOR_MOVE_GetEntry  0x0202616C  thumb
 *   B_APP_TOOL_LayoutActors  0x0220B000  thumb  ov196
 *   CURSOR_MOVE_SetCurrent  0x020260E4  thumb
 */
/* ---- local object definitions (replaces the ObjNNNNN views) ---- */
#define MGR(p) (((struct BagWork *)(p))->frameMgr)

struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct CharBuf;
struct WordSet;
struct Cfg;
struct Item;
struct WinMgr;
struct Obj;
struct PalAnmSlot;
struct PalAnmObj;
typedef struct PalAnmObj PalAnmObj;
struct Sub0204A9D0;
struct Bank;
struct Vec2;
struct MyItemSave;
struct Tcbl;
struct Node;
struct PrintSys;
struct Sound;
struct Rec;
struct Rec3;
struct S02031140;
struct CursorMove;



typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef short s16;
typedef signed char s8;

/* one entry of the bag window table: a BMP window handle and a redraw flag */
struct WinSlot {
    void *handle;
    unsigned char dirty;
    unsigned char pad[3];
};

/* a screen-space point, used by the item actor placement tables */
struct Pair {
    short x, y;
};

/* the bag menu data handed to B_BAG_MAIN_Create; the work struct keeps a pointer to it */
struct BagMenu {
    void *savedata;            /* 0x00 savedata block */
    unsigned int printWidth;   /* 0x04 width/limit passed to the printer and func_0201D304 */
    int mode;                  /* 0x08 menu mode 1/2/3 */
    unsigned short heapId;     /* 0x0C heap id used for every allocation */
    void *pocketMask;          /* 0x10 pocket membership bit table */
    unsigned char count;       /* 0x14 item count */
    unsigned char maxCount;    /* 0x15 maximum item count */
    unsigned short itemId;     /* 0x16 selected item id */
    unsigned char itemFlag;    /* 0x18 selected item flag */
    unsigned char done;        /* 0x19 set when the menu is finished */
    void *myItemSave;          /* 0x1C MyItemSave record */
    int cancel;                /* 0x20 cancel requested */
    int instant;               /* 0x24 instant close requested */
    unsigned char kind;        /* 0x28 item kind */
    unsigned char flag29;      /* 0x29 item flag 2 */
    unsigned char slot;        /* 0x2A selected slot */
    void *dirtyPtr;            /* 0x2C pointer to a flag byte to set or clear on exit */
    short cursorX[4];          /* 0x30 cursor column per pocket */
    short cursorY[4];          /* 0x38 cursor row per pocket */
    int soundOn;               /* 0x40 sound effects enabled */
};

/* the per-instance bag work struct (size 0x5A4) */
struct BagWork {
    void *itemData;                    /* 0x000 BagMenu */
    void *tcbl;                        /* 0x004 Tcbl task */
    void *palAnm;                      /* 0x008 PalAnmSlot */
    void *msgBank;                     /* 0x00C MsgBank */
    void *wordSet;                     /* 0x010 WordSet */
    void *strBuf;                      /* 0x014 U16Vec string buffer */
    void *printSys;                    /* 0x018 PrintSys */
    void *printStream;                 /* 0x01C Rec print stream */
    int msgInputFlag;                  /* 0x020 message input state flag */
    void *itemMsgWin;                  /* 0x024 item message window */
    struct WinSlot win[35];            /* 0x028 bag window table */
    unsigned char pad140;              /* 0x140 alignment */
    unsigned char pocketSide;          /* 0x141 pocket side flag */
    unsigned char pad142[2];           /* 0x142 alignment */
    void *cursor;                      /* 0x144 CURSOR_MOVE object */
    void *toolActors;                  /* 0x148 B_APP_TOOL actor block */
    void *fingerCursor;                  /* 0x14C finger cursor handle */
    unsigned short rows[4][36][2];     /* 0x150 item rows, 4 pockets of 36 entries */
    unsigned char pad390[0x90];        /* 0x390 alignment */
    void *itemUnit;                    /* 0x420 CLACT unit */
    void *itemActors[63];              /* 0x424 item actors */
    void *frameMgr;                    /* 0x520 BGWINFRM manager */
    unsigned char animState;           /* 0x524 frame animation state */
    unsigned char animTimer;           /* 0x525 frame animation timer */
    unsigned char animIndex;           /* 0x526 frame animation index */
    unsigned char animActive;          /* 0x527 frame animation active */
    unsigned char state;               /* 0x530 current state */
    unsigned char nextState;           /* 0x531 next state */
    unsigned char page;                /* 0x532 current page */
    unsigned char pocket;              /* 0x533 selected pocket */
    signed char countDelta;            /* 0x534 count change step */
    unsigned char countPerPocket[4];   /* 0x535 item count per pocket */
    unsigned char pagePerPocket[4];    /* 0x539 page per pocket */
    unsigned char otherStep;           /* 0x53D other page step */
    unsigned char pad53E[2];           /* 0x53E alignment */
    unsigned short keyItem;            /* 0x540 selected key item */
    unsigned char keyItemSlot;         /* 0x542 selected key item slot */
    int charHandles[9];                /* 0x544 CLACT character handles */
    int paletteHandles[9];             /* 0x568 CLACT palette handles */
    int cellAnims[3];                  /* 0x58C CLACT cell animation handles */
    void *actorsVisible;                 /* 0x598 tool actors visible */
    const void *textPtr;               /* 0x59C label string pointer */
    int initialized;                   /* 0x5A0 initialised flag */
};

/* palette/screen block loaded by ARC_UTIL_LoadPaletteBlockFromHandle */
struct ScreenData {
    unsigned char pad[0xC];
    char *data;
};

typedef struct {unsigned short entry[36][2];} Row;

typedef struct {u16 member;u8 w,h;} WinCfg;

typedef struct {u16 a,b,c;unsigned char d,e;} Config;

struct BgVramReq {u32 a,b,c,d;};

struct BgTemplate {u32 a,b,size,c;u8 d,e,f,g;u32 h;u8 i,j,k,l;u32 m;};

extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *owner, unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_Callback_EF40(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BG_SYS_SetTileEntry(unsigned,int,int,int,u8,u8,u8);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void FILE_UTIL_ReadStringAlt(void *,unsigned,unsigned);
extern void BMP_MENUWORK_DrawWindow(void *, int, int, int);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern signed char MSG_SPEED_GetWait(void);
extern void *PRINTSYS_PrintStream(void *a0, u32 a1, u32 a2, void *a3, u32 a4, u32 a5, void *a6, u32 a7, u16 a8, u32 a9);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern int B_APP_TOOL_Update(void *, int, int);
extern u32 B_APP_TOOL_ShowWindows(u8 *, u32);
extern u32 MYITEM_SAVEDATA_HasItem(u8 *,u16,u16,u16);
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern struct Item *func_020081DC(u8 *base, u32 id, u32 index);
extern u32 func_020307B0(void *p);
extern unsigned ITEM_GFX_IsFlagClear(const unsigned char *,unsigned);
extern unsigned short ITEM_GFX_GetItemId(unsigned);
extern u32 ITEM_GFX_GetExtraValue(u32);
extern struct WinMgr *BGWINFRM_Create(u32,u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void BGWINFRM_SetClipArea(struct Obj *o, u32 i, u8 a, u8 b, s8 c, s8 d);
extern void BGWINFRM_SetFrameDataArcHandle(struct WinMgr *mgr,u32,void *,u32,u32);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr,u32,s8,s8);
extern void BGWINFRM_Delete(struct WinMgr *mgr);
extern void BGWINFRM_ChangePalette(struct WinMgr *mgr, u32 idx, s32 x, s32 y, u8 w, u8 h, u8 pal);
extern void BGWINFRM_ShowFrame(struct WinMgr *mgr, u32 idx);
extern void BGWINFRM_HideFrame(struct WinMgr *mgr, u32 idx);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern unsigned FILE_UTIL_GetItemCount(void);
extern unsigned FILE_UTIL_Get(unsigned,unsigned);
extern int CLACT_RegisterCharacter(void *,unsigned,unsigned,unsigned,u16);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern int FILE_UTIL_GetBankCount(void);
extern int FILE_UTIL_GetBaseIndex(void);
extern int CLACT_RegisterCellAnim(void *,unsigned,unsigned,unsigned);
extern void *ARC_UTIL_LoadScreenDataFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void CLACT_TransferCharacter(int a, struct Sub0204A9D0 *b);
extern void PALANM_LoadHandlePaletteToSlot(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned short);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern struct Bank *CLACT_CreateUnit(int,u8,u32);
extern void CLACT_DeleteActor(struct Obj *);
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleasePalette(unsigned);
extern void CLACT_ReleaseCellAnim(unsigned);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void B_APP_TOOL_CreateActors(char *,int,int,int,int);
extern void B_APP_TOOL_SetActorsVisible(char *,void *);
extern void B_APP_TOOL_DeleteActors(u8 *p);
extern int BTLV_FINGER_CURSOR_Create(int, int, int);
extern void BTLV_FINGER_CURSOR_Delete(int);
extern void BTLV_FINGER_CURSOR_Start(u32, u32, u32, u32, u32, u32);
extern void BTLV_FINGER_CURSOR_DeleteActor(int);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *BTLV_EFFECT_GetOwner(void);
extern int BTLV_EFFECT_GetPalanm(void);
extern void *func_02030DA8(void *, u32, void *, u32);
extern void func_0200829C(const struct MyItemSave *p, int i, s16 *a, s16 *b);
extern u16 func_020082B0(const struct MyItemSave *p);
extern u16 func_020082B4(const struct MyItemSave *p);
extern void TCBL_Main(struct Tcbl *);
extern void BGWINFRM_UpdateMoves(struct WinMgr *mgr);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u8 *B_APP_TOOL_Create(u16 v);
extern void GFL_NET_RestartWithDefaultTimeout(unsigned,unsigned);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern int PALANM_RequestFade(void *,u16,u16,short,u8,u8,u16,void *);
extern unsigned PRINTSYS_QUE_IsFinished(const struct PrintSys *);
extern void WIPE_SYS_Start(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern unsigned WIPE_SYS_EndCheck(void);
extern u32 PALANM_GetFadeRequestBits(const char *ptr);
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *obj);
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern unsigned FILE_UTIL_Get_0FE4(void *, unsigned, unsigned);
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern unsigned PRINTSYS_PrintStreamGetState(void *);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *, int);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *);
extern int TOUCHPANEL_GetTrg(void);
extern unsigned int KEY_GetCont(void);
extern u32 KEY_GetTrg(void);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void WIPE_SYS_ExeEnd(void);
extern void TCBL_Destroy(struct S02031140 *);
extern void B_APP_TOOL_Delete(void *);
extern void func_02030EAC(struct Node *);
extern int BTLV_FINGER_CURSOR_IsActive(void *);
extern void BG_SYS_ApplyGraphicsMode(const struct BgVramReq *,u32);
extern void BG_SYS_InitBgLayer(u32,const struct BgTemplate *,u32);
extern void BG_SYS_ClearSlot(u32);
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void BMP_MENUWORK_LoadCharAndPltt(u32, u32, u32, u32, u16);
extern void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *, u32, u32, u32, u32, u32, u16);
extern struct MsgBank *func_02045B38(unsigned,unsigned,unsigned,unsigned);
extern struct WordSet *WORDSET_CreateDefault(unsigned);
extern unsigned PRINTSYS_QUE_Create(void *);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);
extern void BG_SYS_ResetSlot(unsigned int, unsigned int, unsigned int);
extern void BG_SYS_ClearLayerEx(int channel, u16 val);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern struct CursorMove *CURSOR_MOVE_Create(u32, u32, u32, u32, u8, u16);
extern void CURSOR_MOVE_EnableInput(struct CursorMove *);
extern void CURSOR_MOVE_SetMode(struct CursorMove *);
extern u32 CURSOR_MOVE_Delete(void *a0);
extern void *CURSOR_MOVE_GetEntry(void **obj, u32 idx);
extern void B_APP_TOOL_LayoutActors(int *p, u8 *q);
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
void B_BAG_MAIN_InitWindows(char *p);
void B_BAG_MAIN_CreateWindows(char *p,u8 unused);
void B_BAG_MAIN_DeleteWindows(char *a);
void B_BAG_MAIN_ExitWindows(char *a);
void B_BAG_MAIN_DrawPage(char *a, int which);
void B_BAG_MAIN_PrintLabel(char *p,int i,int id,int y,u16 colour);
void B_BAG_MAIN_DrawLabels(char *p);
void B_BAG_MAIN_DrawItemName(char *p,u32 i,int id,int w,int unused,int unused2);
void B_BAG_MAIN_DrawItemInfo(char *p, u32 i, int id, int w, int unused, int y, int unused2);
void B_BAG_MAIN_DrawSlot(char *p,u16 i);
void B_BAG_MAIN_DrawPocket(char *p);
void B_BAG_MAIN_DrawHeader(char *p);
void B_BAG_MAIN_DrawInfoBox(char *p);
void B_BAG_MAIN_DrawItemsPage(char *a);
void B_BAG_MAIN_DrawDescription(u8 *p, u32 idx);
void B_BAG_MAIN_DrawItemUsage(char *p,int n);
void B_BAG_MAIN_DrawOtherPage(char *p);
void B_BAG_MAIN_PrintItemMsg(char *p);
void B_BAG_MAIN_StartItemMsg(char *p);
int B_BAG_MAIN_UpdateTool(char *a);
u32 B_BAG_MAIN_ShowWindows(u8 *p);
int B_BAG_MAIN_CheckKeyItem(char *p);
void B_BAG_MAIN_SyncCursorToItem(u8 *p);
void B_BAG_MAIN_BuildPocketLists(u8 *p);
void B_BAG_MAIN_BuildOtherList(char *p);
void B_BAG_MAIN_InitOtherPage(char *p);
u16 B_BAG_MAIN_GetSlotItem(const char *p, unsigned n);
int B_BAG_MAIN_GetItemFlag(u32 key);
void B_BAG_MAIN_InitFrames(char *p);
void B_BAG_MAIN_DeleteFrames(char *a);
void B_BAG_MAIN_LayoutFrames(char *p, int mode);
void B_BAG_MAIN_StartFrameAnim(char *p, int v);
void B_BAG_MAIN_StepFrameAnim(char *p);
void B_BAG_MAIN_CreateItemGraphics(char *p);
void B_BAG_MAIN_ClearHandles(char *p);
void B_BAG_MAIN_RegisterItemChars(char *p);
void B_BAG_MAIN_LoadItemGraphic(char *p,u16 item,unsigned slot,unsigned offset);
void B_BAG_MAIN_LoadItemPalette(char *p,unsigned item,unsigned slot);
void B_BAG_MAIN_RegisterCursorGraphics(char *p);
void B_BAG_MAIN_RegisterIconGraphics(char *p);
struct Obj *B_BAG_MAIN_CreateItemActor(char *p,const int *indices);
void B_BAG_MAIN_CreateItemActors(char *p);
void B_BAG_MAIN_DeleteItemGraphics(char *p);
void B_BAG_MAIN_PlaceActor(int a, int b);
void B_BAG_MAIN_SetDisplayMode(char *p, int mode);
void B_BAG_MAIN_DisplaySingle(char *p);
void B_BAG_MAIN_DisplayList(char *p);
void B_BAG_MAIN_DisplaySelected(char *p);
void B_BAG_MAIN_CreateToolActors(char *p);
void B_BAG_MAIN_DeleteToolActors(char *a);
void B_BAG_MAIN_CreateFingerCursor(char *a);
void B_BAG_MAIN_DeleteFingerCursor(char *a);
void B_BAG_MAIN_StartFingerCursor(u8 *p, u32 a, u32 b);
void B_BAG_MAIN_DeleteFingerCursorActor(char *a);
void B_BAG_MAIN_DrawItemRow(char *p,u16 slot,u8 a,u8 b,const struct Pair *src);
void B_BAG_MAIN_Create(u8 *arg);
void B_BAG_MAIN_Main(void *task, char *p);
int B_BAG_MAIN_StateInit(char *p);
int B_BAG_MAIN_StateInitOther(char *p);
int B_BAG_MAIN_StateWaitPrintWipe(char *p);
int B_BAG_MAIN_StateWipeEnd(char *p);
int B_BAG_MAIN_StateSelectPocket(char *p);
int B_BAG_MAIN_StateSelectItem(char *p);
int B_BAG_MAIN_StateChangeCount(char *p);
int B_BAG_MAIN_StateWaitPrintRedraw(char *p);
int B_BAG_MAIN_StateChooseItem(char *p);
int B_BAG_MAIN_StateShowMessage(char *p);
int B_BAG_MAIN_StateShowPocket0(char *p);
int B_BAG_MAIN_StateShowPocket1(char *p);
int B_BAG_MAIN_StateShowPocket2(char *p);
int B_BAG_MAIN_StateWaitPrintSetMode(char *p);
int B_BAG_MAIN_StateStartMessage(char *a);
int B_BAG_MAIN_StateMessageInput(char *p);
int B_BAG_MAIN_StateMessageDone(char *p);
int B_BAG_MAIN_StateWaitKey(char *p);
int B_BAG_MAIN_StateFadeOut(char *p);
int B_BAG_MAIN_StateWaitFade(char *a);
int B_BAG_MAIN_StateExit(struct Node *task, char *p);
int B_BAG_MAIN_StateOtherFlow(char *p);
void B_BAG_MAIN_InitBg(char *p);
void B_BAG_MAIN_ExitBg(void);
void B_BAG_MAIN_LoadBgGraphics(char *p);
void B_BAG_MAIN_CreateText(char *p);
void B_BAG_MAIN_DeleteText(char *p);
void B_BAG_MAIN_ResetBgSlot(void *unused, int mode);
void B_BAG_MAIN_SwitchPage(char *p,int mode);
int B_BAG_MAIN_CheckCancel(char **p);
void B_BAG_MAIN_PlaySe(char **a, int b);
void B_BAG_MAIN_PlaySe2(char **a, int b);
void B_BAG_MAIN_CreateCursor(u8 *p, u32 index, u32 value);
u32 B_BAG_MAIN_DeleteCursor(u8 *p);
void B_BAG_MAIN_RecreateCursor(u8 *p, int state, int value);
void B_BAG_MAIN_SetCursorVisible(char *a, int b);
void B_BAG_MAIN_LayoutCursor(u8 *p, u32 idx);
void B_BAG_MAIN_ShowCursorAt(u8 *p,u32 i);
void B_BAG_MAIN_HideCursor(char *p);
void B_BAG_MAIN_HideCursor2(char *p);
void B_BAG_MAIN_LayoutCursorOnly(u8 *p,u32 i);
void B_BAG_MAIN_HandleSelection(char *p, int b);
extern const u8 d_0220DA68[];
extern const char d_0220DA0D[];
extern const char d_0220DA38[];
extern const char d_0220DA3C[];
extern const char d_0220DA28[];
extern const char d_0220DA19[];
extern const u8 d_0220DA08[];
extern const u8 d_0220DB3C[];
extern const u8 d_0220DB3F[];
extern const WinCfg d_0220DB44[14];
extern const int d_0220DBBC[];
extern const int d_0220DB7C[];
extern const struct Pair d_0220DB88[];
extern const struct Pair d_0220DB80[];
extern const char d_0220E0E0[];
extern u16 d_04001050[];
extern const struct BgVramReq d_0220DEB0;
extern const struct BgTemplate d_0220DEE0,d_0220DF20,d_0220DF00,d_0220DEC0;
extern const u32 d_0220DF90[];
extern const u32 d_0220DF9C[];


void B_BAG_MAIN_InitWindows(char *p) { ((struct BagWork *)p)->itemMsgWin=(void *)BMP_WIN_Create(4,1,19,30,4,12,1); B_BAG_MAIN_CreateWindows(p,*(unsigned char *)(p + 0x532)); }


/*
 * Declaring the table pointer before the counter restores r4/r5 allocation.
 */
void B_BAG_MAIN_CreateWindows(char *p,u8 unused) { const u8 *q; u32 i; q=d_0220DA68; for(i=0;i<35;i++,q+=6) *(u32 *)(p+i*8+0x28)=BMP_WIN_Create(q[0],q[1],q[2],q[3],q[4],q[5],1); }



void B_BAG_MAIN_DeleteWindows(char *a)
{
    unsigned int i;

    for (i = 0; i < 0x23; i++)
        BMP_WIN_Delete((struct Descriptor *)(*(int *)(a + i * 8 + 0x28)));
}



void B_BAG_MAIN_ExitWindows(char *a)
{
    B_BAG_MAIN_DeleteWindows(a);
    BMP_WIN_Delete((struct Descriptor *)(((struct BagWork *)a)->itemMsgWin));
}



void B_BAG_MAIN_DrawPage(char *a, int which)
{
    switch (which)
    {
    case 0:
        B_BAG_MAIN_DrawLabels(a);
        break;
    case 1:
        B_BAG_MAIN_DrawItemsPage(a);
        break;
    case 2:
        B_BAG_MAIN_DrawOtherPage(a);
        break;
    }
}


void B_BAG_MAIN_PrintLabel(char *p,int i,int id,int y,u16 colour)
{
    int handle=*(int *)(p+0x28+i*8);
    int text=(int)func_02045EC0((struct MsgBank *)(((struct BagWork *)p)->msgBank),id);
    int width=func_0201D304((struct StrObj *)text,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->printWidth,0);
    int x=(BMP_WIN_GetWidth((struct Descriptor *)handle)*8-width)>>1;
    int font=(int)((struct BagWork *)p)->printSys;
    int surface=(int)BMP_WIN_GetBmp((struct Descriptor *)*(int *)(p+0x28+i*8));
    PRINTSYS_PrintQueColor((void *)font,(int)surface,(s16)x,(s16)y,(int)text,(int)(((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->printWidth),colour);
    (p+i*8)[0x2c]=1;
    STRBUF_Delete((struct U16Vec *)text);
}


/*
 * matching: unsigned loop bound i<=4 preserves the original cmp4/bls; i<5 differs in two bytes.
 */
void B_BAG_MAIN_DrawLabels(char *p)
{
    unsigned i;
    void *text;
    void *font;
    void *surface;
    for(i=0;i<=4;i++)BMP_Clear(BMP_WIN_GetBmp(*(void **)(p+i*8+0x28)),0);
    B_BAG_MAIN_PrintLabel(p,0,0,0,0x3C40);
    B_BAG_MAIN_PrintLabel(p,0,1,16,0x3C40);
    B_BAG_MAIN_PrintLabel(p,1,2,0,0x3C40);
    B_BAG_MAIN_PrintLabel(p,1,3,16,0x3C40);
    B_BAG_MAIN_PrintLabel(p,2,7,0,0x3C40);
    B_BAG_MAIN_PrintLabel(p,3,6,0,0x3C40);
    if(*(unsigned short *)(p + 0x540)!=0){
        text=func_02045EC0(((struct BagWork *)p)->msgBank,8);
        font=((struct BagWork *)p)->printSys;
        surface=BMP_WIN_GetBmp(((struct BagWork *)p)->win[4].handle);
        PRINTSYS_PrintQueColor(font,(u32)surface,0,0,(u32)text,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->printWidth,0x3C40);
        p[0x4C]=1;
        STRBUF_Delete(text);
    }else{
        BMP_WIN_TransferChars(((struct BagWork *)p)->win[4].handle);
    }
    *(const char * *)&*(const void * *)(p + 0x59C)=d_0220DA0D;
}




/*
 * Width: printer x truncates to signed halfword in original; extern keeps s16 despite owner u32.
 */
void B_BAG_MAIN_DrawItemName(char *p,u32 i,int id,int w,int unused,int unused2)
{
    char *windows=p+0x28;
    void *handle=*(void **)(windows+w*8);
    void *text;
    void *font;
    void *surface;
    u32 width;
    int page;
    BMP_Clear(BMP_WIN_GetBmp(handle),0);
    page=(u32)p+((u8 *)p)[0x533]*0x90;
    if(*(u16 *)(page+i*4+0x150)!=0){
        text=func_02045EC0(((struct BagWork *)p)->msgBank,*(u32 *)(d_0220DA38+id*8));
        page=(u32)p+((u8 *)p)[0x533]*0x90;
        WORDSET_Callback_EF40(((struct BagWork *)p)->wordSet,0,*(u16 *)(page+i*4+0x150));
        WORDSET_CopyTaggedText(((struct BagWork *)p)->wordSet,((struct BagWork *)p)->strBuf,text);
        width=func_0201D304(((struct BagWork *)p)->strBuf,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->printWidth,0);
        width=BMP_WIN_GetWidth(handle)*8-width;
        font=((struct BagWork *)p)->printSys;
        surface=BMP_WIN_GetBmp(*(void **)(windows+w*8));
        PRINTSYS_PrintQueColor(font,(u32)surface,(s16)(width/2),(s16)7,(u32)(((struct BagWork *)p)->strBuf),((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->printWidth,0x3C40);
        (p+w*8)[0x2C]=1;
        STRBUF_Delete(text);
    }else{
        BMP_WIN_TransferChars(handle);
    }
}




/*
 * Width: original narrows y to signed halfword before printer; corresponding extern keeps s16 despite owner u32.
 */
void B_BAG_MAIN_DrawItemInfo(char *p, u32 i, int id, int w, int unused, int y, int unused2)
{
  char *windows = p + 0x28;
  void *handle = *((void **) (windows + (w * 8)));
  void *text;
  void *font;
  void *surface;
  int page;
  char *tmp;
  u16 pad;
  u32 *tmp1;
  char *tmp2;
  BMP_Clear(BMP_WIN_GetBmp(handle), 0);
  page = ((u32) p) + (((u8 *) p)[0x533] * 0x90);
  if (((*((u16 *) ((page + (i * 4)) + 0x152))) != 0) && ((*((int *) ((*((char **) p)) + 8))) != 1))
  {
    text = func_02045EC0(*((void **) (p + 0xC)), *((u32 *) (d_0220DA3C + (id * 8))));
    page = ((u32) p) + (((u8 *) p)[0x533] * 0x90);
    WORDSET_SetSlotNumber(*((void **) (p + 0x10)), 0, *((u16 *) (((u32) (page + (i * 4))) + 0x152)), 3, 0, 1);
    tmp2 = p + 0x14;
    WORDSET_CopyTaggedText(*((void **) (p + 0x10)), *((void **) tmp2), text);
    font = *((void **) (p + 0x18));
    surface = BMP_WIN_GetBmp(*((void **) (windows + (w * 8))));
    tmp = p + 0x14;
    tmp1 = (u32 *) ((*((char **) p)) + 4);
    PRINTSYS_PrintQueColor(font, (u32)surface, (s16)0, (s16)y, (u32)(*((void **) tmp)), *tmp1, 0x3C40);
    (p + (w * 8))[0x2C] = 1;
    STRBUF_Delete(text);
  }
  else
  {
    BMP_WIN_TransferChars(handle);
  }
}




/*
 * lever: assign the doubled index after the flag branch; the flag is unsigned byte evidence.
 */
void B_BAG_MAIN_DrawSlot(char *p,u16 i)
{
    int base=*(short *)(*(char * *)&((struct BagWork *)p)->itemData+((u8 *)p)[0x533]*2+0x38)*6;
    int row=5;
    int twice;
    if(((u8 *)p)[0x141]!=0)row=0x11;
    twice=i*2;
    B_BAG_MAIN_DrawItemName(p,i+base,i,row+twice,0,0);
    B_BAG_MAIN_DrawItemInfo(p,i+base,i,row+1+twice,0,4,0);
}




void B_BAG_MAIN_DrawPocket(char *p)
{
    u16 i;
    BG_SYS_SetTileEntry(5,0,0,0,0x20,0x13,0x11);
    for(i=0;i<6;i++)B_BAG_MAIN_DrawSlot(p,i);
    if(((u8 *)p)[0x141]==0)
        *(const char * *)&*(const void * *)(p + 0x59C)=d_0220DA28;
    else
        *(const char * *)&*(const void * *)(p + 0x59C)=d_0220DA19;
    ((u8 *)p)[0x141]^=1;
}




/*
 * matching: parenthesised byte-pointer plus page keeps the page load before the far-field add; a flat offset sum differs in two bytes.
 * Width: original narrows x to signed 16 bits before each 0201C724 call; s16 extern preserves those caller truncations despite owner u32 x.
 */
void B_BAG_MAIN_DrawHeader(char *p)
{
    void *handle=((struct BagWork *)p)->win[30].handle;
    void *surface=BMP_WIN_GetBmp(handle);
    void *text;
    u32 width;
    u32 x;
    void *font;
    void *lastSurface;
    BMP_Clear(surface,0);
    text=func_02045EC0(((struct BagWork *)p)->msgBank,28);
    width=func_0201D304(text,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->printWidth,0);
    x=(BMP_WIN_GetWidth(handle)*8-width)/2;
    PRINTSYS_PrintQueColor(((struct BagWork *)p)->printSys,(u32)surface,(s16)x,(s16)4,(u32)text,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->printWidth,0x3C40);
    STRBUF_Delete(text);
    text=func_02045EC0(((struct BagWork *)p)->msgBank,29);
    WORDSET_SetSlotNumber(((struct BagWork *)p)->wordSet,0,((u8 *)p+((u8 *)p)[0x533])[0x539]+1,2,0,1);
    WORDSET_CopyTaggedText(((struct BagWork *)p)->wordSet,((struct BagWork *)p)->strBuf,text);
    PRINTSYS_PrintQueColor(((struct BagWork *)p)->printSys,(u32)surface,(s16)(x+width),(s16)4,(u32)(((struct BagWork *)p)->strBuf),((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->printWidth,0x3C40);
    STRBUF_Delete(text);
    text=func_02045EC0(((struct BagWork *)p)->msgBank,30);
    WORDSET_SetSlotNumber(((struct BagWork *)p)->wordSet,0,*(s16 *)(*(char * *)&((struct BagWork *)p)->itemData+((u8 *)p)[0x533]*2+0x38)+1,2,0,1);
    WORDSET_CopyTaggedText(((struct BagWork *)p)->wordSet,((struct BagWork *)p)->strBuf,text);
    width=func_0201D304(((struct BagWork *)p)->strBuf,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->printWidth,0);
    font=((struct BagWork *)p)->printSys;
    lastSurface=BMP_WIN_GetBmp(((struct BagWork *)p)->win[30].handle);
    PRINTSYS_PrintQueColor(font,(u32)lastSurface,(s16)(x-width),(s16)4,(u32)(((struct BagWork *)p)->strBuf),((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->printWidth,0x3C40);
    ((u8 *)p)[0x11C]=1;
    STRBUF_Delete(text);
}




void B_BAG_MAIN_DrawInfoBox(char *p)
{
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct BagWork *)p)->win[29].handle)),0);
    if(((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->mode!=1) {
        switch(((unsigned char *)p)[0x533]) {
        case 0:B_BAG_MAIN_PrintLabel(p,29,22,4,0x3c40);B_BAG_MAIN_PrintLabel(p,29,23,20,0x3c40);break;
        case 1:B_BAG_MAIN_PrintLabel(p,29,24,4,0x3c40);B_BAG_MAIN_PrintLabel(p,29,25,20,0x3c40);break;
        case 2:B_BAG_MAIN_PrintLabel(p,29,26,12,0x3c40);break;
        case 3:B_BAG_MAIN_PrintLabel(p,29,27,12,0x3c40);break;
        }
    } else BMP_WIN_TransferChars((struct Descriptor *)((struct BagWork *)p)->win[29].handle);
}





void B_BAG_MAIN_DrawItemsPage(char *a)
{
    B_BAG_MAIN_DrawPocket(a);
    B_BAG_MAIN_DrawInfoBox(a);
    B_BAG_MAIN_DrawHeader(a);
}





void B_BAG_MAIN_DrawDescription(u8 *p, u32 idx)
{
    void *win = *(void **)(p + 0x120);
    void *msg = func_02045EC0(*(void **)(p + 0xc), 9);
    u8 sel = *(u8 *)(p + 0x533);
    u8 *row = p + sel * 0x90;
    void *w;
    WORDSET_Callback_EF40(*(void **)(p + 0x10), 0, *(u16 *)(row + 0x150 + idx * 4));
    WORDSET_CopyTaggedText(*(void **)(p + 0x10), *(void **)(p + 0x14), msg);
    BMP_Clear(BMP_WIN_GetBmp(win), 0);
    w = *(void **)(p + 0x18);
    PRINTSYS_PrintQueColor(w, (u32)BMP_WIN_GetBmp(*(void **)(p + 0x120)), 0, 0,
                  *(u32 *)(p + 0x14), *(u32 *)(*(u8 **)p + 4), 0x3C40);
    *(u8 *)(p + 0x124) = 1;
    STRBUF_Delete(msg);
}




/*
 * matching: named row index in Row[36][2] restores base-add-before-column-shift; raw byte row differs in seven bytes.
 */
void B_BAG_MAIN_DrawItemUsage(char *p,int n)
{
    void *owner;
    int index;
    Row *row;
    void *buf=STRBUF_Create(130,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    index=*(unsigned char *)(p + 0x533);
    row=(Row *)(p+0x150);
    FILE_UTIL_ReadStringAlt(buf,row[index].entry[n][0],((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    owner=((struct BagWork *)p)->printSys;
    PRINTSYS_PrintQueColor(owner,(unsigned)BMP_WIN_GetBmp(((struct BagWork *)p)->win[33].handle),4,0,(unsigned)buf,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->printWidth,0x3c40);
    ((struct BagWork *)p)->win[33].dirty=1;
    STRBUF_Delete(buf);
}




/*
 * lever: the scaled index is its own int local added after each field
 *   offset (`*(short *)(*(char **)p + 0x30 + off)`), which puts the ldrb and
 *   lsls ahead of the `ldr r0,[r4]` base load (0220B8A4..0220B8AA). A row
 *   pointer `q = *(char **)p + idx*2` (either operand order, or as a short
 *   element address) loads the base first: 9 bytes.
 * prototype: B_BAG_MAIN_DrawDescription has no matched definition; (char *, unsigned) and
 *   void taken from its listing (r1 scaled by 4 as an index, no r0 use after).
 */
void B_BAG_MAIN_DrawOtherPage(char *p)
{
    unsigned i;
    int x, y;
    int off;
    for (i = 31; i <= 34; i++)
        BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0x28 + i * 8)), 0);
    off = *(u8 *)(p + 0x533) * 2;
    x = *(short *)(*(char **)p + 0x30 + off);
    y = *(short *)(*(char **)p + 0x38 + off) * 6;
    B_BAG_MAIN_DrawDescription((u8 *)p, x + y);
    B_BAG_MAIN_DrawItemInfo(p, x + y, 0, 32, 0, 0, 0);
    B_BAG_MAIN_DrawItemUsage(p, x + y);
    B_BAG_MAIN_PrintLabel(p, 34, 31, 0, 0x3c40);
    *(const u8 **)(p + 0x59c) = d_0220DA08;
}





void B_BAG_MAIN_PrintItemMsg(char *p)
{
    BMP_MENUWORK_DrawWindow(((struct BagWork *)p)->itemMsgWin, 2, 1, 0xb);
    BMP_Clear(BMP_WIN_GetBmp(((struct BagWork *)p)->itemMsgWin), 0xf);
    B_BAG_MAIN_StartItemMsg(p);
}




/*
 * lever: MSG_SPEED_GetWait() called inside the argument list (as the ov010
 *   0x02169EBC twin does) with its real signed char return; a font local
 *   computed before the call let mwcc CSE the two *p reads (DIFF 42).
 * prototypes: from the matched arm9 definitions, except PRINTSYS_PrintStream,
 *   whose definition is declared void although it forwards PRINTSYS_PrintStreamCallBack's
 *   r0; the return type is the ov010 twin's void *.
 */
void B_BAG_MAIN_StartItemMsg(char *p)
{
    void *d;
    GF_FONT_SetTextColor(1, 2, 0);
    *(void **)(p + 0x1c) = PRINTSYS_PrintStream(*(void **)(p + 0x24), 0, 0, *(void **)(p + 0x14),
        *(u32 *)(*(char **)p + 4), MSG_SPEED_GetWait(), *(void **)(p + 4), 10,
        *(u16 *)(*(char **)p + 0xc), 15);
    d = *(void **)(p + 0x24);
    BMP_WIN_TransferChars(d);
    BMP_WIN_MakeScreen(d);
    func_02041B6C(BMP_WIN_GetBgLayer(d));
}





int B_BAG_MAIN_UpdateTool(char *a)
{
    return B_APP_TOOL_Update(a + 0x28, (int)((struct BagWork *)a)->printSys, 0x23);
}





/*
 * Addresses are Black-image addresses.
 */
u32 B_BAG_MAIN_ShowWindows(u8 *p)
{
    return B_APP_TOOL_ShowWindows(p + 0x28, (u32)*(const void * *)(p + 0x59C));
}




/*
 * EXACT* tail: two zero alignment bytes after the function.
 */
int B_BAG_MAIN_CheckKeyItem(char *p) { char *q; if(*(unsigned short *)(p + 0x540)==0) return 0; q=*(char * *)&((struct BagWork *)p)->itemData; if(MYITEM_SAVEDATA_HasItem(*(u8 * *)&((struct BagMenu *)q)->savedata,*(unsigned short *)(p + 0x540),1,((struct BagMenu *)q)->heapId)==0) { *(unsigned short *)(p + 0x540)=0; *(unsigned char *)(p + 0x542)=0; return 0; } return 1; }




void B_BAG_MAIN_SyncCursorToItem(u8 *p)
{
    unsigned int i = 0;
    u8 sel = *(u8 *)(p + 0x533);
    u8 *row = p + sel * 0x90;
    u16 cur = *(u16 *)(p + 0x533 + 0xd);
    for (; i < 36; i++) {
        if (cur == *(u16 *)(row + 0x150 + i * 4)) {
            *(u16 *)(*(u8 **)p + sel * 2 + 0x30) = i % 6;
            *(u16 *)(*(u8 **)p + *(u8 *)(p + 0x533) * 2 + 0x38) = i / 6;
            return;
        }
    }
}





/*
 * 2026-10-05 (wD9r lane05): EXACT. The record address is an integer local reused for the row offset:
 *   `u32 e = c * 0x90; e = q[0x535] * 4 + (u32)(p + e);`. The mul stays first (e is defined in its own
 *   statement and used once more), and idx*4 is the first operand of the final add, so e shares idx*4's
 *   register (r0) and row takes r4 as in the original.
 */
void B_BAG_MAIN_BuildPocketLists(u8 *p)
{
    u8 *tbl;
    u16 *r;
    u32 i, j, k;

    tbl = ARC_TOOL_LoadMember(0xE8, 0, *(u16 *)(*(u8 **)p + 0xC));
    i = 0;
    do {
        j = 0;
        for (;;) {
            r = (u16 *)func_020081DC(**(void ***)p, d_0220DB3C[i], (u16)j);
            if (r == 0)
                break;
            if (r[0] != 0 && r[1] != 0) {
                u32 m = tbl[r[0]];
                for (k = 0; k < 4; k++) {
                    if (m & (1 << k)) {
                        int c = d_0220DB3F[k];
                        u8 *q = p + c;
                        u32 e = c * 0x90;
                        e = q[0x535] * 4 + (u32)(p + e);
                        *(u16 *)(e + 0x150) = r[0];
                        *(u16 *)(e + 0x152) = r[1];
                        q[0x535]++;
                    }
                }
            }
            j++;
        }
        i++;
    } while (i < 3);
    func_020307B0(tbl);
    for (i = 0; i < 4; i++) {
        u8 v = p[i + 0x535];
        u8 *s;
        if (v == 0)
            p[i + 0x539] = 0;
        else
            p[i + 0x539] = (v - 1) / 6;
        s = *(u8 **)p + i * 2;
        if (p[i + 0x539] < *(s16 *)(s + 0x38))
            *(s16 *)(s + 0x38) = p[i + 0x539];
    }
}




void B_BAG_MAIN_BuildOtherList(char *p)
{
    unsigned i;
    for(i=0;i<46;i++) {
        if(ITEM_GFX_IsFlagClear(*(const unsigned char * *)&((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->pocketMask,i)==1) {
            *(unsigned short *)(p+0x150+*(unsigned char *)(p + 0x535)*4)=ITEM_GFX_GetItemId(i);
            *(unsigned short *)(p+0x152+*(unsigned char *)(p + 0x535)*4)=1;
            (*(unsigned char *)(p + 0x535))++;
        }
    }
    *(unsigned char *)(p + 0x539)=(*(unsigned char *)(p + 0x535)-1)/6;
}





void B_BAG_MAIN_InitOtherPage(char *p)
{
    ((struct BagWork *)p)->rows[2][0][0] = 4;
    ((struct BagWork *)p)->rows[2][0][1] = 0x1e;
    *(unsigned char *)(p + 0x537) = 1;
    *(unsigned char *)(p + 0x53B) = 0;
}




/*
 * lever: one statement n = (n + k * 6) << 2, then p += index * 0x90 and a
 *   const u16 pointer s = p + n read as s[0xa8] / s[0xa9]; the byte-offset
 *   spelling (n += ..; n *= 4; slot + 0x150) sank the shift after the
 *   0x90 multiply (13 bytes), and a typed row struct folded 0x150 (60 bytes).
 */
u16 B_BAG_MAIN_GetSlotItem(const char *p, unsigned n)
{
    unsigned index = *(u8 *)(p + 0x533);
    const u16 *s;
    n = (n + *(short *)(*(char **)p + 0x38 + index * 2) * 6) << 2;
    p += index * 0x90;
    s = (const u16 *)(p + n);
    if (s[0xa8] != 0 && s[0xa9] != 0) return s[0xa8];
    return 0;
}




/*
 * Forward entry r0 as the key. The explicit result truncation requires a wide extern return.
 */
int B_BAG_MAIN_GetItemFlag(u32 key) { return (u16)ITEM_GFX_GetExtraValue(key); }




void B_BAG_MAIN_InitFrames(char *p)
{
    void *arc;
    unsigned i;
    ((struct BagWork *)p)->frameMgr=BGWINFRM_Create(2,14,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    arc=func_020490F4(99,(u16)((((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId&0x7FFF)|0x8000));
    for(i=0;i<14;i++){
        BGWINFRM_AddFrame(((struct BagWork *)p)->frameMgr,i,6,d_0220DB44[i].w,d_0220DB44[i].h);
        BGWINFRM_SetClipArea(((struct BagWork *)p)->frameMgr,i,0,64,0,64);
        BGWINFRM_SetFrameDataArcHandle(((struct BagWork *)p)->frameMgr,i,arc,d_0220DB44[i].member,1);
    }
    ARC_TOOL_DeleteHandle(arc);
    BGWINFRM_PutFrame(((struct BagWork *)p)->frameMgr,0,0,1);
    BGWINFRM_PutFrame(((struct BagWork *)p)->frameMgr,1,0,10);
    BGWINFRM_PutFrame(((struct BagWork *)p)->frameMgr,2,16,1);
    BGWINFRM_PutFrame(((struct BagWork *)p)->frameMgr,3,16,10);
    BGWINFRM_PutFrame(((struct BagWork *)p)->frameMgr,4,32,1);
    BGWINFRM_PutFrame(((struct BagWork *)p)->frameMgr,5,48,1);
    BGWINFRM_PutFrame(((struct BagWork *)p)->frameMgr,6,32,7);
    BGWINFRM_PutFrame(((struct BagWork *)p)->frameMgr,7,48,7);
    BGWINFRM_PutFrame(((struct BagWork *)p)->frameMgr,8,32,13);
    BGWINFRM_PutFrame(((struct BagWork *)p)->frameMgr,9,48,13);
    BGWINFRM_PutFrame(((struct BagWork *)p)->frameMgr,11,32,19);
    BGWINFRM_PutFrame(((struct BagWork *)p)->frameMgr,12,37,19);
}







void B_BAG_MAIN_DeleteFrames(char *a)
{
    BGWINFRM_Delete(*(struct WinMgr * *)&((struct BagWork *)a)->frameMgr);
}






/*
 * note 2026-10-05 (wave D4 lane 02): the two window calls 11/12 are written in each if/else
 *   arm with literal arguments. Tail merging sinks the common call parts into the join and keeps
 *   r4 = 0x533 live, so 0x520 comes out as 0x533 - 0x13.
 */
void B_BAG_MAIN_LayoutFrames(char *p, int mode)
{
    u32 i;
    for (i = 0; i < 14; i++) BGWINFRM_HideFrame(MGR(p), i);
    switch (mode) {
    case 0:
        BGWINFRM_PutFrame(MGR(p), 10, 27, 19);
        BGWINFRM_PutFrame(MGR(p), 13, 1, 19);
        if (*(u16 *)(p + 0x540) == 0)
            BGWINFRM_ChangePalette(MGR(p), 13, 0, 0, 25, 5, 3);
        else
            BGWINFRM_ChangePalette(MGR(p), 13, 0, 0, 25, 5, 1);
        BGWINFRM_ShowFrame(MGR(p), 0);
        BGWINFRM_ShowFrame(MGR(p), 1);
        BGWINFRM_ShowFrame(MGR(p), 2);
        BGWINFRM_ShowFrame(MGR(p), 3);
        BGWINFRM_ShowFrame(MGR(p), 10);
        BGWINFRM_ShowFrame(MGR(p), 13);
        break;
    case 1: {
        struct WinMgr **pm;
        BGWINFRM_PutFrame(MGR(p), 10, 59, 19);
        pm = (struct WinMgr **)(p + 0x520);
        for (i = 0; i < 6; i++) {
            if (B_BAG_MAIN_GetSlotItem(p, i) == 0)
                BGWINFRM_ChangePalette(MGR(p), i + 4, 0, 0, d_0220DB44[i + 4].w, d_0220DB44[i + 4].h, 6);
            else
                BGWINFRM_ChangePalette(*pm, i + 4, 0, 0, d_0220DB44[i + 4].w, d_0220DB44[i + 4].h, 4);
        }
        {
            struct BagWork *q = (struct BagWork *)p;
            if (*(unsigned char *)(p + 0x539 + *(unsigned char *)(p + 0x533)) == 0) {
                BGWINFRM_ChangePalette(*(struct WinMgr **)(p + 0x520), 11, 0, 0, 5, 5, 3);
                BGWINFRM_ChangePalette(*(struct WinMgr **)(p + 0x520), 12, 0, 0, 5, 5, 3);
            } else {
                BGWINFRM_ChangePalette(*(struct WinMgr **)(p + 0x520), 11, 0, 0, 5, 5, 1);
                BGWINFRM_ChangePalette(*(struct WinMgr **)(p + 0x520), 12, 0, 0, 5, 5, 1);
            }
        }
        BGWINFRM_ShowFrame(MGR(p), 4);
        BGWINFRM_ShowFrame(MGR(p), 5);
        BGWINFRM_ShowFrame(MGR(p), 6);
        BGWINFRM_ShowFrame(MGR(p), 7);
        BGWINFRM_ShowFrame(MGR(p), 8);
        BGWINFRM_ShowFrame(MGR(p), 9);
        BGWINFRM_ShowFrame(MGR(p), 11);
        BGWINFRM_ShowFrame(MGR(p), 12);
        BGWINFRM_ShowFrame(MGR(p), 10);
        break;
    }
    case 2:
        BGWINFRM_ChangePalette(MGR(p), 13, 0, 0, 25, 5, 1);
        BGWINFRM_PutFrame(MGR(p), 10, 27, 51);
        BGWINFRM_PutFrame(MGR(p), 13, 1, 51);
        BGWINFRM_ShowFrame(MGR(p), 10);
        BGWINFRM_ShowFrame(MGR(p), 13);
        break;
    }
}







void B_BAG_MAIN_StartFrameAnim(char *p, int v)
{
    ((struct BagWork *)p)->animState = 0;
    ((struct BagWork *)p)->animTimer = 0;
    ((struct BagWork *)p)->animIndex = v;
    ((struct BagWork *)p)->animActive = 1;
}






/*
 * matching: naming unsigned index before the u8 palette settles r0/r2;
 *   unnamed repeated index loads differ in18 bytes. Callee uses u8 palette.
 */
void B_BAG_MAIN_StepFrameAnim(char *p)
{
    if(((struct BagWork *)p)->animActive) {
        switch(((struct BagWork *)p)->animState) {
        case 0: {
            unsigned index=((struct BagWork *)p)->animIndex;
            u8 color;
            color=2;
            if(index<10) color=5;
            BGWINFRM_ChangePalette(((struct BagWork *)p)->frameMgr,index,0,0,d_0220DB44[index].w,d_0220DB44[index].h,color);
            BGWINFRM_ShowFrame(((struct BagWork *)p)->frameMgr,((struct BagWork *)p)->animIndex);
            (((struct BagWork *)p)->animState)++;
            break;
        }
        case 1: {
            unsigned index;
            u8 color;
            if(((struct BagWork *)p)->animTimer==4) {
                index=((struct BagWork *)p)->animIndex;
                color=1;
                if(index<10) color=4;
                BGWINFRM_ChangePalette(((struct BagWork *)p)->frameMgr,index,0,0,d_0220DB44[index].w,d_0220DB44[index].h,color);
                BGWINFRM_ShowFrame(((struct BagWork *)p)->frameMgr,((struct BagWork *)p)->animIndex);
                ((struct BagWork *)p)->animTimer=0;
                (((struct BagWork *)p)->animState)++;
            } else (((struct BagWork *)p)->animTimer)++;
            break;
        }
        case 2:
            if(((struct BagWork *)p)->animTimer==1) {
                ((struct BagWork *)p)->animTimer=0;
                ((struct BagWork *)p)->animState=0;
                ((struct BagWork *)p)->animActive=0;
            } else (((struct BagWork *)p)->animTimer)++;
            break;
        }
    }
}






void B_BAG_MAIN_CreateItemGraphics(char *p) { B_BAG_MAIN_ClearHandles(p); B_BAG_MAIN_RegisterItemChars(p); B_BAG_MAIN_RegisterCursorGraphics(p); B_BAG_MAIN_RegisterIconGraphics(p); B_BAG_MAIN_CreateItemActors(p); B_BAG_MAIN_CreateToolActors(p); B_BAG_MAIN_CreateFingerCursor(p); BG_SYS_SetSubPlaneVisible(16,1); }






void B_BAG_MAIN_ClearHandles(char *p)
{
    unsigned i;
    for(i=0;i<9;i++) *(int *)(p+0x544+i*4)=-1;
    for(i=0;i<9;i++) *(int *)(p+0x568+i*4)=-1;
    for(i=0;i<3;i++) *(int *)(p+0x58c+i*4)=-1;
}






/*
 * matching: arc declared before first/second fixes the three spill homes.
 *   0204ABF0 argument4 is u16: caller explicitly truncates i*32.
 *   0202F138 result widened to reproduce caller's explicit u16 narrowing;
 *   its own ITEM_GFX_GetItemId returns u16, which removed the observed shifts.
 */
void B_BAG_MAIN_RegisterItemChars(char *p)
{
    u16 item,i;
    void *arc;
    unsigned first,second;
    int a;
    if(((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->mode==1) {item=(unsigned)ITEM_GFX_GetItemId(0);first=3;second=4;}
    else {first=1;item=1;second=2;}
    arc=func_020490F4(FILE_UTIL_GetItemCount(),(u16)((((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId&0x7fff)|0x8000));
    for(i=0;i<7;i++) {
        *(int *)(p+i*4+0x544)=CLACT_RegisterCharacter(arc,FILE_UTIL_Get(item,first),0,1,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
        *(int *)(p+i*4+0x568)=CLACT_RegisterPalette(arc,FILE_UTIL_Get(item,second),1,(u16)(i*32),((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    }
    a=FILE_UTIL_GetBankCount();
    *(int *)(p + 0x58C)=CLACT_RegisterCellAnim(arc,a,FILE_UTIL_GetBaseIndex(),((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    ARC_TOOL_DeleteHandle(arc);
}






/*
 * matching: u16 item restores entry spill order without extra truncation; unsigned item differs in eight bytes.
 */
void B_BAG_MAIN_LoadItemGraphic(char *p,u16 item,unsigned slot,unsigned offset)
{
    char *q=*(char * *)&((struct BagWork *)p)->itemData;
    unsigned first, second;
    void *arc;
    void *data,*buffer;
    if(((struct BagMenu *)q)->mode==1) {first=3;second=4;} else {first=1;second=2;}
    arc=func_020490F4(FILE_UTIL_GetItemCount(),(u16)((((struct BagMenu *)q)->heapId&0x7fff)|0x8000));
    buffer=ARC_UTIL_LoadScreenDataFromHandle(arc,FILE_UTIL_Get(item,first),0,(u32)(&data),((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    CLACT_TransferCharacter(*(int *)(p+slot*4+0x544),data);
    func_020307B0(buffer);
    PALANM_LoadHandlePaletteToSlot(((struct BagWork *)p)->palAnm,(void *)((unsigned)arc),FILE_UTIL_Get(item,second),((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId,3,32,offset*16);
    ARC_TOOL_DeleteHandle(arc);
}






void B_BAG_MAIN_LoadItemPalette(char *p,unsigned item,unsigned slot)
{
    char *q=*(char * *)&((struct BagWork *)p)->itemData;
    unsigned archive;
    if(((struct BagMenu *)q)->mode==1) {
        archive=FILE_UTIL_GetItemCount();
        func_02049B40(archive,FILE_UTIL_Get(item,4),5,slot*32,32,((struct BagMenu *)q)->heapId);
    } else {
        archive=FILE_UTIL_GetItemCount();
        func_02049B40(archive,FILE_UTIL_Get(item,2),5,slot*32,32,((struct BagMenu *)q)->heapId);
    }
}






void B_BAG_MAIN_RegisterCursorGraphics(char *p)
{
    void *arc = func_020490F4(99,(u16)((((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId&0x7fff)|0x8000));
    *(int *)(p + 0x560)=CLACT_RegisterCharacter(arc,13,1,1,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    *(int *)(p + 0x584)=CLACT_RegisterPalette(arc,14,1,224,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    *(int *)(p + 0x590)=CLACT_RegisterCellAnim(arc,15,16,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    PALANM_LoadHandlePaletteToSlot(((struct BagWork *)p)->palAnm,(void *)((unsigned)arc),14,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId,3,32,112);
    ARC_TOOL_DeleteHandle(arc);
}






void B_BAG_MAIN_RegisterIconGraphics(char *p)
{
    void *arc = func_020490F4(11,(u16)((((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId&0x7fff)|0x8000));
    char *data;
    void *buf;
    *(int *)(p + 0x564)=CLACT_RegisterCharacter(arc,119,0,1,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    *(int *)(p + 0x588)=CLACT_RegisterPaletteEx(arc,116,1,256,4,1,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    *(int *)(p + 0x594)=CLACT_RegisterCellAnim(arc,120,121,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    buf=ARC_UTIL_LoadPaletteBlockFromHandle(arc,116,(u32)(&data),(u16)((((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId&0x7fff)|0x8000));
    PALANM_CopyToSlot(((struct BagWork *)p)->palAnm,((struct ScreenData *)data)->data+128,3,128,32);
    func_020307B0(buf);
    ARC_TOOL_DeleteHandle(arc);
}






/*
 * matching: const indices restores the load/store scheduling; mutable indices differ in 29 bytes.
 */
struct Obj *B_BAG_MAIN_CreateItemActor(char *p,const int *indices)
{
    Config c;
    c.a=0;c.b=0;c.c=0;c.d=1;c.e=1;
    return CLACT_CreateActor((void *)*(unsigned *)&((struct BagWork *)p)->itemUnit,*(unsigned *)(p+indices[0]*4+0x544),*(unsigned *)(p+indices[1]*4+0x568),*(unsigned *)(p+indices[2]*4+0x58c),&c,1,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
}






/*
 * Raw byte stride i*12 emits muls rather than the flat word-index shift/add.
 * The caller stores live r0 from C3B4; its owner declaration is void.
 */
void B_BAG_MAIN_CreateItemActors(char *p) { u32 i; *(struct Bank * *)&((struct BagWork *)p)->itemUnit=CLACT_CreateUnit(67,0,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId); for(i=0;i<63;i++) *(u32 *)(p+i*4+0x424)=(u32)B_BAG_MAIN_CreateItemActor(p,(const int *)((u32)d_0220DBBC+i*12)); }






void B_BAG_MAIN_DeleteItemGraphics(char *p)
{
    unsigned i;
    B_BAG_MAIN_DeleteFingerCursor(p);
    for (i = 0; i < 63; i++) CLACT_DeleteActor(*(struct Obj **)(p + i * 4 + 0x424));
    B_BAG_MAIN_DeleteToolActors(p);
    for (i = 0; i < 9; i++) if (*(int *)(p + i * 4 + 0x544) != -1) CLACT_ReleaseCharacter(*(int *)(p + i * 4 + 0x544));
    for (i = 0; i < 9; i++) if (*(int *)(p + i * 4 + 0x568) != -1) CLACT_ReleasePalette(*(int *)(p + i * 4 + 0x568));
    for (i = 0; i < 3; i++) if (*(int *)(p + i * 4 + 0x58c) != -1) CLACT_ReleaseCellAnim(*(int *)(p + i * 4 + 0x58c));
    CLACT_DeleteUnit(*(struct Bank * *)&((struct BagWork *)p)->itemUnit);
}







void B_BAG_MAIN_PlaceActor(int a, int b)
{
    CLACT_SetActorDrawEnable((struct Obj *)a, 1);
    CLACT_AddActorSurfacePos((struct Obj *)a, (const struct Vec2 *)b, 1);
}






void B_BAG_MAIN_SetDisplayMode(char *p, int mode)
{
    unsigned int i;
    for (i = 0; i < 63; i++) CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x424), 0);
    B_BAG_MAIN_DeleteFingerCursorActor(p);
    switch (mode) {
    case 0: B_BAG_MAIN_DisplaySingle(p); break;
    case 1: B_BAG_MAIN_DisplayList(p); break;
    case 2: B_BAG_MAIN_DisplaySelected(p); break;
    }
}




void B_BAG_MAIN_DisplaySingle(char *p) { if(*(unsigned short *)(p + 0x540)!=0) { B_BAG_MAIN_LoadItemGraphic(p,*(unsigned short *)(p + 0x540),6,6); B_BAG_MAIN_PlaceActor((int)((struct BagWork *)p)->itemActors[6],(int)d_0220DB7C); } if(((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->mode==2) B_BAG_MAIN_StartFingerCursor((u8 *)p,192,24); }





void B_BAG_MAIN_DisplayList(char *p)
{
    unsigned i;
    for (i = 0; i < 6; i++) {
        u16 item = B_BAG_MAIN_GetSlotItem(p, i);
        if (item) {
            B_BAG_MAIN_LoadItemGraphic(p, item, i, i);
            B_BAG_MAIN_LoadItemPalette(p, item, i);
            B_BAG_MAIN_PlaceActor(*(int *)(p + i * 4 + 0x424), (int)&d_0220DB88[i]);
            if (((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->mode == 1)
                B_BAG_MAIN_DrawItemRow(p, i * 8 + 7, B_BAG_MAIN_GetItemFlag(item), 0, (const struct Pair *)(&d_0220DB88[i + 6]));
        }
    }
    if (((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->mode == 1)
        B_BAG_MAIN_DrawItemRow(p, 55, ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->count, ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->maxCount, (const struct Pair *)(&d_0220DB88[i + 6]));
    if (((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->mode == 2) B_BAG_MAIN_StartFingerCursor((u8 *)p, 64, 16);
}





/*
 * caller-width: BB98 takes full signed short promotion; no u16 truncation in this caller.
 */
void B_BAG_MAIN_DisplaySelected(char *p)
{
    u16 item = B_BAG_MAIN_GetSlotItem(p, *(short *)(*(char * *)&((struct BagWork *)p)->itemData + *(unsigned char *)(p + 0x533) * 2 + 0x30));
    B_BAG_MAIN_LoadItemGraphic(p, item, 6, 6);
    B_BAG_MAIN_PlaceActor((int)((struct BagWork *)p)->itemActors[6], (int)&d_0220DB80[0]);
    if (((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->mode == 1)
        B_BAG_MAIN_DrawItemRow(p, 7, B_BAG_MAIN_GetItemFlag(item), 0, (const struct Pair *)(&d_0220DB80[1]));
    if (((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->mode == 2) B_BAG_MAIN_StartFingerCursor((u8 *)p, 0x68, 0x98);
}





void B_BAG_MAIN_CreateToolActors(char *p){B_APP_TOOL_CreateActors(*(char * *)&((struct BagWork *)p)->toolActors,*(int *)&((struct BagWork *)p)->itemUnit,*(int *)(p + 0x564),*(int *)(p + 0x588),*(int *)(p + 0x594));B_APP_TOOL_SetActorsVisible(*(char * *)&((struct BagWork *)p)->toolActors,0);}






void B_BAG_MAIN_DeleteToolActors(char *a)
{
    B_APP_TOOL_DeleteActors((u8 *)(((struct BagWork *)a)->toolActors));
}






void B_BAG_MAIN_CreateFingerCursor(char *a)
{
    ((struct BagWork *)a)->fingerCursor = (void *)BTLV_FINGER_CURSOR_Create(*(int *)&((struct BagWork *)a)->palAnm, 9,
                                         *(unsigned short *)(*(int *)&((struct BagWork *)a)->itemData + 0xc));
}





void B_BAG_MAIN_DeleteFingerCursor(char *a)
{
    BTLV_FINGER_CURSOR_Delete((int)((struct BagWork *)a)->fingerCursor);
}





void B_BAG_MAIN_StartFingerCursor(u8 *p, u32 a, u32 b)
{
    BTLV_FINGER_CURSOR_Start((u32)((struct BagWork *)p)->fingerCursor, a, b, 2, 6, 0x14);
}





void B_BAG_MAIN_DeleteFingerCursorActor(char *a)
{
    BTLV_FINGER_CURSOR_DeleteActor((int)((struct BagWork *)a)->fingerCursor);
}




/*
 * matching: pair aggregate copy emits two unsigned halfword transfers;
 *   explicit objects base keeps the first indexed address split correctly.
 */
void B_BAG_MAIN_DrawItemRow(char *p,u16 slot,u8 a,u8 b,const struct Pair *src)
{
    struct Pair v;
    u16 i;
    s8 left,right;
    void **objects=(void **)(p+0x424);
    B_BAG_MAIN_PlaceActor((int)objects[slot],(int)src);
    CLACT_SetActorAnimSeq(objects[slot],a);
    slot++;
    left=a;
    right=b;
    v=*src;
    v.x+=12;
    for(i=0;i<7;i++) {
        if(left<=0) {
            if(right<=0) CLACT_SetActorAnimSeq(*(void **)(p+slot*4+0x424),15);
            else if(right==1) {CLACT_SetActorAnimSeq(*(void **)(p+slot*4+0x424),19);right--;}
            else {CLACT_SetActorAnimSeq(*(void **)(p+slot*4+0x424),20);right-=2;}
        } else if(left==1) {
            if(right==0) CLACT_SetActorAnimSeq(*(void **)(p+slot*4+0x424),16);
            else if(right>0) {CLACT_SetActorAnimSeq(*(void **)(p+slot*4+0x424),18);right--;}
            left--;
        } else {CLACT_SetActorAnimSeq(*(void **)(p+slot*4+0x424),17);left-=2;}
        B_BAG_MAIN_PlaceActor(*(int *)(p+slot*4+0x424),(int)&v);
        v.x+=8;
        slot++;
    }
}





/*
 * lever: Size constant held in a local (offsets derived from it), the 0x533 store repeated in each arm instead of one shared tail, and no row-pointer local in the first loop (*(u8 **)p re-read per argument).
 */
void B_BAG_MAIN_Create(u8 *arg)
{
    u8 *p;
    u8 *q;
    int z;
    u32 i;
    int v;
    int sz = 0x5A4;
    p = func_02030734(*(u16 *)(arg + 0xc), sz, 1, d_0220E0E0, 0xB1);
    q = func_02030DA8(BTLV_EFFECT_GetOwner(), (u32)B_BAG_MAIN_Main, p, 0x64);
    *(u8 **)p = arg;
    *(void **)(p + 8) = (void *)BTLV_EFFECT_GetPalanm();
    z = 0;
    *(int *)(p + sz - 4) = z;
    if (*(int *)(*(u8 **)p + 8) == 1) {
        p[sz - 0x72] = 1;
        p[sz - 0x74] = 1;
        p[sz - 0x71] = z;
    } else if (*(int *)(*(u8 **)p + 8) == 3) {
        p[sz - 0x72] = 1;
        p[sz - 0x74] = z;
        z = 2;
        p[sz - 0x71] = z;
    } else {
        p[sz - 0x72] = z;
        p[sz - 0x74] = z;
        p[sz - 0x71] = z;
    }
    if (*(int *)(*(u8 **)p + 8) != 1) {
        for (i = 0; i < 4; i++) {
            func_0200829C((const struct MyItemSave *)(*(u32 *)(*(u8 **)p + 0x1c)), (u16)i, (s16 *)(*(u8 **)p + 0x30 + i * 2), (s16 *)(*(u8 **)p + 0x38 + i * 2));
        }
        *(u16 *)(p + 0x540) = func_020082B0((const struct MyItemSave *)(*(u32 *)(*(u8 **)p + 0x1c)));
        p[0x542] = func_020082B4((const struct MyItemSave *)(*(u32 *)(*(u8 **)p + 0x1c)));
        B_BAG_MAIN_CheckKeyItem((char *)p);
    } else {
        for (i = 0; i < 4; i++) {
            *(u16 *)(*(u8 **)p + i * 2 + 0x30) = 0;
            *(u16 *)(*(u8 **)p + i * 2 + 0x38) = 0;
        }
    }
}




extern int (*const d_0220DF40[])(char *);




void B_BAG_MAIN_Main(void *task, char *p)
{
    if (((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->instant == 1) {
        ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->itemId = 0;
        ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->itemFlag = 0;
        *(unsigned char *)(p + 0x530) = 20;
    }
    if (*(unsigned char *)(p + 0x530) != 20) *(unsigned char *)(p + 0x530) = d_0220DF40[*(u8 *)(p + 0x530)](p);
    if (*(unsigned char *)(p + 0x530) == 20 && B_BAG_MAIN_StateExit(task, p) == 1) return;
    TCBL_Main(*(struct Tcbl * *)&((struct BagWork *)p)->tcbl);
    B_BAG_MAIN_StepFrameAnim(p);
    BGWINFRM_UpdateMoves(*(struct WinMgr * *)&((struct BagWork *)p)->frameMgr);
    B_BAG_MAIN_UpdateTool(p);
}




/*
 * lever: word-address arithmetic reuses the MMIO pool base, as in matched ov197 0220CAAC.
 */
int B_BAG_MAIN_StateInit(char *p)
{
    d_04001050[0]=0;
    GXx_SetMasterBrightness_((u16 *)((unsigned)d_04001050+0x1c),-16);
    ((struct BagWork *)p)->tcbl=TCBL_Create(((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId,1,4);
    ((struct BagWork *)p)->toolActors=B_APP_TOOL_Create(((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    B_BAG_MAIN_InitBg(p);
    B_BAG_MAIN_LoadBgGraphics(p);
    B_BAG_MAIN_CreateText(p);
    if(((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->mode==2) B_BAG_MAIN_InitOtherPage(p);
    else B_BAG_MAIN_BuildPocketLists((u8 *)p);
    B_BAG_MAIN_InitWindows(p);
    B_BAG_MAIN_DrawPage(p,*(unsigned char *)(p + 0x532));
    B_BAG_MAIN_ShowWindows((u8 *)p);
    B_BAG_MAIN_InitFrames(p);
    B_BAG_MAIN_LayoutFrames(p,*(unsigned char *)(p + 0x532));
    B_BAG_MAIN_CreateItemGraphics(p);
    B_BAG_MAIN_SetDisplayMode(p,*(unsigned char *)(p + 0x532));
    if(**(u8 * *)&((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->dirtyPtr==1) *(void * *)(p + 0x598)=(void *)1;
    else *(void * *)(p + 0x598)=0;
    B_APP_TOOL_SetActorsVisible(*(char * *)&((struct BagWork *)p)->toolActors,*(void * *)(p + 0x598));
    if(*(unsigned char *)(p + 0x532)==0) B_BAG_MAIN_CreateCursor((u8 *)p,*(unsigned char *)(p + 0x532),*(unsigned char *)(p + 0x542));
    else B_BAG_MAIN_CreateCursor((u8 *)p,*(unsigned char *)(p + 0x532),0);
    GFL_NET_RestartWithDefaultTimeout(0,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    PALANM_CopyHwPaletteToSlot(((struct BagWork *)p)->palAnm,3,224,32);
    PALANM_RequestFade(((struct BagWork *)p)->palAnm,10,65535,0,16,0,0,BTLV_EFFECT_GetOwner());
    if(((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->mode==3) B_BAG_MAIN_ResetBgSlot(p,*(unsigned char *)(p + 0x532));
    *(int *)(p + 0x5A0)=1;
    return 2;
}




/*
 * lever: word-address arithmetic reuses MMIO pool base for +0x1c; typed pointer addition pools a second word.
 */
int B_BAG_MAIN_StateInitOther(char *p)
{
    d_04001050[0] = 0;
    GXx_SetMasterBrightness_((u16 *)((unsigned)d_04001050 + 0x1c), -16);
    ((struct BagWork *)p)->tcbl = TCBL_Create(((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId, ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId, 1, 4);
    ((struct BagWork *)p)->toolActors = B_APP_TOOL_Create(((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    B_BAG_MAIN_InitBg(p);
    B_BAG_MAIN_LoadBgGraphics(p);
    B_BAG_MAIN_CreateText(p);
    B_BAG_MAIN_BuildOtherList(p);
    B_BAG_MAIN_ResetBgSlot(p, *(unsigned char *)(p + 0x532));
    B_BAG_MAIN_InitWindows(p);
    B_BAG_MAIN_DrawPage(p, *(unsigned char *)(p + 0x532));
    B_BAG_MAIN_ShowWindows((u8 *)p);
    B_BAG_MAIN_InitFrames(p);
    B_BAG_MAIN_LayoutFrames(p, *(unsigned char *)(p + 0x532));
    B_BAG_MAIN_CreateItemGraphics(p);
    B_BAG_MAIN_SetDisplayMode(p, *(unsigned char *)(p + 0x532));
    if (**(u8 * *)&((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->dirtyPtr == 1) *(void * *)(p + 0x598) = (void *)1;
    else *(void * *)(p + 0x598) = 0;
    B_APP_TOOL_SetActorsVisible(*(char * *)&((struct BagWork *)p)->toolActors, *(void * *)(p + 0x598));
    B_BAG_MAIN_CreateCursor((u8 *)p, *(unsigned char *)(p + 0x532), 0);
    GFL_NET_RestartWithDefaultTimeout(0, ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    PALANM_CopyHwPaletteToSlot(((struct BagWork *)p)->palAnm, 3, 0xe0, 0x20);
    PALANM_RequestFade(((struct BagWork *)p)->palAnm, 0xa, 0xffff, 0, 0x10, 0, 0, BTLV_EFFECT_GetOwner());
    *(int *)(p + 0x5A0) = 1;
    return 2;
}




int B_BAG_MAIN_StateWaitPrintWipe(char *p){if(PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct BagWork *)p)->printSys)==1){WIPE_SYS_Start((void *)4,1,1,0,6,1,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);return 3;}return 2;}




int B_BAG_MAIN_StateWipeEnd(char *p){if(WIPE_SYS_EndCheck()==1){if(((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->mode==2)return 17;if(((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->mode==1)return 5;if(((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->mode==3)return 5;return 4;}return 3;}




int B_BAG_MAIN_StateSelectPocket(char *p)
{
    unsigned sel;
    if (PALANM_GetFadeRequestBits(((struct BagWork *)p)->palAnm) != 0) goto done;
    if (B_BAG_MAIN_CheckCancel((char **)p) == 1) return 0x12;
    sel = CURSOR_MOVE_PollRepeatInput(((struct BagWork *)p)->cursor);
    switch (sel) {
    case 0: case 1: case 2: case 3:
        B_BAG_MAIN_PlaySe((char **)p, 0x54d);
        *(unsigned char *)(p + 0x533) = (u8)sel;
        *(unsigned char *)(p + 0x531) = 8;
        B_BAG_MAIN_StartFrameAnim(p, (u8)sel);
        return 0x10;
    case 4:
        if (*(unsigned short *)(p + 0x540) != 0) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            *(unsigned char *)(p + 0x533) = *(unsigned char *)(p + 0x542);
            *(unsigned char *)(p + 0x531) = 9;
            B_BAG_MAIN_SyncCursorToItem((u8 *)p);
            B_BAG_MAIN_StartFrameAnim(p, 0xd);
            return 0x10;
        }
        break;
    case 5:
        B_BAG_MAIN_PlaySe((char **)p, 0x552);
        ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->itemId = 0;
        ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->slot = 4;
        B_BAG_MAIN_StartFrameAnim(p, 0xa);
        return 0x12;
    case (unsigned)-2:
        B_BAG_MAIN_PlaySe((char **)p, 0x552);
        ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->itemId = 0;
        ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->slot = 4;
        B_BAG_MAIN_StartFrameAnim(p, 0xa);
        return 0x12;
    case (unsigned)-4: case (unsigned)-3:
        B_BAG_MAIN_PlaySe((char **)p, 0x548);
        break;
    case (unsigned)-8: case (unsigned)-7: case (unsigned)-6:
    case (unsigned)-5: case (unsigned)-1:
        break;
    }
done:
    return 4;
}




int B_BAG_MAIN_StateSelectItem(char *p)
{
    unsigned sel;
    if (PALANM_GetFadeRequestBits(((struct BagWork *)p)->palAnm) != 0) goto done;
    if (B_BAG_MAIN_CheckCancel((char **)p) == 1) return 0x12;
    sel = CURSOR_MOVE_PollRepeatInput(((struct BagWork *)p)->cursor);
    switch (sel) {
    case 0: case 1: case 2: case 3: case 4: case 5:
        if (B_BAG_MAIN_GetSlotItem(p, sel) != 0) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            *(u16 *)(*(char * *)&((struct BagWork *)p)->itemData + *(unsigned char *)(p + 0x533) * 2 + 0x30) = (u8)sel;
            *(unsigned char *)(p + 0x531) = 9;
            B_BAG_MAIN_StartFrameAnim(p, (u8)(sel + 4));
            return 0x10;
        }
        break;
    case 6:
        B_BAG_MAIN_PlaySe((char **)p, 0x552);
        B_BAG_MAIN_StartFrameAnim(p, 0xa);
        if (((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->mode == 1 || ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->mode == 3) {
            ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->itemId = 0;
            ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->slot = 4;
            return 0x12;
        }
        *(unsigned char *)(p + 0x531) = 7;
        return 0x10;
    case (unsigned)-2:
        B_BAG_MAIN_PlaySe((char **)p, 0x552);
        B_BAG_MAIN_StartFrameAnim(p, 0xa);
        if (((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->mode == 1 || ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->mode == 3) {
            ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->itemId = 0;
            ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->slot = 4;
            return 0x12;
        }
        *(unsigned char *)(p + 0x531) = 7;
        return 0x10;
    case 7:
        if (*(u8 *)(p + *(unsigned char *)(p + 0x533) + 0x539) != 0) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            *(u16 *)(*(char * *)&((struct BagWork *)p)->itemData + *(unsigned char *)(p + 0x533) * 2 + 0x30) = 0;
            *(unsigned char *)(p + 0x531) = 0xb;
            *(signed char *)&*(signed char *)(p + 0x534) = -1;
            B_BAG_MAIN_StartFrameAnim(p, 0xb);
            return 0x10;
        }
        break;
    case 8:
        if (*(u8 *)(p + *(unsigned char *)(p + 0x533) + 0x539) != 0) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            *(u16 *)(*(char * *)&((struct BagWork *)p)->itemData + *(unsigned char *)(p + 0x533) * 2 + 0x30) = 0;
            *(unsigned char *)(p + 0x531) = 0xb;
            *(signed char *)(p + 0x534) = 1;
            B_BAG_MAIN_StartFrameAnim(p, 0xc);
            return 0x10;
        }
        break;
    case (unsigned)-4: case (unsigned)-3:
        B_BAG_MAIN_PlaySe((char **)p, 0x548);
        break;
    case (unsigned)-6:
        CURSOR_MOVE_GetCurrent(((struct BagWork *)p)->cursor);
        if (*(u8 *)(p + *(unsigned char *)(p + 0x533) + 0x539) != 0) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            *(unsigned char *)(p + 0x531) = 0xb;
            *(signed char *)&*(signed char *)(p + 0x534) = -1;
            B_BAG_MAIN_StartFrameAnim(p, 0xb);
            return 0x10;
        }
        break;
    case (unsigned)-5:
        CURSOR_MOVE_GetCurrent(((struct BagWork *)p)->cursor);
        if (*(u8 *)(p + *(unsigned char *)(p + 0x533) + 0x539) != 0) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            *(unsigned char *)(p + 0x531) = 0xb;
            *(signed char *)(p + 0x534) = 1;
            B_BAG_MAIN_StartFrameAnim(p, 0xc);
            return 0x10;
        }
        break;
    case (unsigned)-8: case (unsigned)-7: case (unsigned)-1:
        break;
    }
done:
    return 5;
}




/*
 * lever: narrow value load then compound add before reading maximum fixes r0/r6 swap.
 */
int B_BAG_MAIN_StateChangeCount(char *p)
{
    unsigned index = *(unsigned char *)(p + 0x533);
    short *values = (short *)(*(char * *)&((struct BagWork *)p)->itemData + 0x38);
    s8 value = (s8)values[index];
    u8 maximum;
    value += *(signed char *)(p + 0x534);
    maximum = *(u8 *)(p + index + 0x539);
    if (value > maximum) value = 0;
    else if (value < 0) {
        values[index] = maximum;
        goto done;
    }
    values[index] = value;
done:
    B_BAG_MAIN_DrawPocket(p);
    B_BAG_MAIN_DrawHeader(p);
    return 12;
}




int B_BAG_MAIN_StateWaitPrintRedraw(char *p){if(PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct BagWork *)p)->printSys)==1){B_BAG_MAIN_ShowWindows((unsigned char *)p);B_BAG_MAIN_SetDisplayMode(p,*(unsigned char *)(p + 0x532));B_BAG_MAIN_LayoutFrames(p,*(unsigned char *)(p + 0x532));return 5;}return 12;}




int B_BAG_MAIN_StateChooseItem(char *p)
{
    if (B_BAG_MAIN_CheckCancel((char **)p) == 1) return 0x12;
    switch ((unsigned)CURSOR_MOVE_PollRepeatInput(((struct BagWork *)p)->cursor)) {
    case 0:
        B_BAG_MAIN_PlaySe((char **)p, 0x54d);
        ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->itemId = B_BAG_MAIN_GetSlotItem(p, *(short *)(*(char * *)&((struct BagWork *)p)->itemData + *(unsigned char *)(p + 0x533) * 2 + 0x30));
        ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->slot = *(unsigned char *)(p + 0x533);
        if (((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->mode == 1)
            ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->itemFlag = B_BAG_MAIN_GetItemFlag(((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->itemId);
        else
            ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->itemFlag = 0;
        B_BAG_MAIN_StartFrameAnim(p, 0xd);
        return B_BAG_MAIN_StateShowMessage(p);
    case 1:
        B_BAG_MAIN_PlaySe((char **)p, 0x552);
        *(unsigned char *)(p + 0x531) = 8;
        B_BAG_MAIN_StartFrameAnim(p, 0xa);
        return 0x10;
    case (unsigned)-2:
        B_BAG_MAIN_PlaySe((char **)p, 0x552);
        *(unsigned char *)(p + 0x531) = 8;
        B_BAG_MAIN_StartFrameAnim(p, 0xa);
        return 0x10;
    case (unsigned)-4:
    case (unsigned)-3:
        B_BAG_MAIN_PlaySe((char **)p, 0x548);
        break;
    case (unsigned)-8:
    case (unsigned)-7:
    case (unsigned)-6:
    case (unsigned)-5:
    case (unsigned)-1:
        break;
    }
    return 6;
}




/*
 * Owner unit_02045C44.c omits MSGDATA_ReadString in function:. Verified EXACT344 C
 * below copied from ov173_func_021B71C4.c, prior ov070 fixed-flag --arm one.
 * abi: BBD8 returns a zero-extended u16; int extern preserves the original signed bge against the u8 field, unlike older unsigned caller externs.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char MSGDATA_AllocSite[];
 * extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void ARC_TOOL_ReadHandle(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void STRBUF_Clear(void *);
 * extern void STRBUF_SetChars(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void MSGDATA_ReadString(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = GFL_HEAP_Alloc((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,MSGDATA_AllocSite,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream,size,buf);
 *             STRBUF_SetChars(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 */
int B_BAG_MAIN_StateShowMessage(char *p)
{
    char *q = *(char **)p;
    if (*(int *)(q + 8) == 1 && *(u8 *)(q + 0x14) < B_BAG_MAIN_GetItemFlag(*(u16 *)(q + 0x16))) {
        MSGDATA_ReadString(*(void **)(p + 0xc), 0x31, *(void **)(p + 0x14));
        B_BAG_MAIN_PrintItemMsg(p);
        *(u8 *)(p + 0x531) = 0xd;
        return 0xe;
    }
    if (*(u8 *)(p + 0x533) == 2) {
        if (*(u8 *)(q + 0x28) == 1) {
            MSGDATA_ReadString(*(void **)(p + 0xc), 0x2d, *(void **)(p + 0x14));
            B_BAG_MAIN_PrintItemMsg(p);
            *(u8 *)(p + 0x531) = 0xd;
            return 0xe;
        }
        if (*(u8 *)(q + 0x28) == 2) {
            MSGDATA_ReadString(*(void **)(p + 0xc), 0x2c, *(void **)(p + 0x14));
            B_BAG_MAIN_PrintItemMsg(p);
            *(u8 *)(p + 0x531) = 0xd;
            return 0xe;
        }
        if (*(u8 *)(q + 0x28) == 3) {
            MSGDATA_ReadString(*(void **)(p + 0xc), 0x33, *(void **)(p + 0x14));
            B_BAG_MAIN_PrintItemMsg(p);
            *(u8 *)(p + 0x531) = 0xd;
            return 0xe;
        }
        if (*(u8 *)(q + 0x28) == 4) {
            MSGDATA_ReadString(*(void **)(p + 0xc), 0x2f, *(void **)(p + 0x14));
            B_BAG_MAIN_PrintItemMsg(p);
            *(u8 *)(p + 0x531) = 0xd;
            return 0xe;
        }
    }
    if (*(u8 *)(q + 0x29) == 0 && FILE_UTIL_Get_0FE4((void *)(unsigned)*(u16 *)(q + 0x16), 7, *(u16 *)(q + 0xc)) == 3) {
        MSGDATA_ReadString(*(void **)(p + 0xc), 0x32, *(void **)(p + 0x14));
        B_BAG_MAIN_PrintItemMsg(p);
        *(u8 *)(p + 0x531) = 0xd;
        return 0xe;
    }
    return 0x12;
}




int B_BAG_MAIN_StateShowPocket0(char *p){B_BAG_MAIN_DrawPage(p,0);*(unsigned char *)(p + 0x532)=0;*(unsigned char *)(p + 0x531)=4;return 10;}




int B_BAG_MAIN_StateShowPocket1(char *p){B_BAG_MAIN_DrawPage(p,1);*(unsigned char *)(p + 0x532)=1;*(unsigned char *)(p + 0x531)=5;return 10;}




int B_BAG_MAIN_StateShowPocket2(char *p){B_BAG_MAIN_DrawPage(p,2);*(unsigned char *)(p + 0x532)=2;*(unsigned char *)(p + 0x531)=6;return 10;}




int B_BAG_MAIN_StateWaitPrintSetMode(char *p){if(PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct BagWork *)p)->printSys)==1){B_BAG_MAIN_SwitchPage(p,*(unsigned char *)(p + 0x532));return *(unsigned char *)(p + 0x531);}return 10;}





int B_BAG_MAIN_StateStartMessage(char *a)
{
    BMP_MENUWORK_DrawWindowBorder((void *)(((struct BagWork *)a)->itemMsgWin), 0);
    return 6;
}




int B_BAG_MAIN_StateMessageInput(char *p)
{
    switch (PRINTSYS_PrintStreamGetState(*(struct Rec * *)&((struct BagWork *)p)->printStream)) {
    case 0:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetCont() & 3)) PRINTSYS_PrintStreamShortWait(*(struct Rec * *)&((struct BagWork *)p)->printStream, 0);
        ((struct BagWork *)p)->msgInputFlag = 0;
        break;
    case 1:
        if (!((struct BagWork *)p)->msgInputFlag && (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3))) {
            B_BAG_MAIN_PlaySe2((char **)p, 0x547);
            PRINTSYS_PrintStreamReleasePause(*(struct Rec * *)&((struct BagWork *)p)->printStream);
            ((struct BagWork *)p)->msgInputFlag = 1;
        }
        break;
    case 2:
        PRINTSYS_PrintStreamDelete(*(struct Rec3 * *)&((struct BagWork *)p)->printStream);
        *(int *)&((struct BagWork *)p)->printStream = 0;
        ((struct BagWork *)p)->msgInputFlag = 0;
        return 15;
    }
    return 14;
}




/*
 * trailing: larger follower filed as ov197_func_0220D358.c (parent cleared).
 */
int B_BAG_MAIN_StateMessageDone(char *p)
{
    if (B_BAG_MAIN_CheckCancel((char **)p) == 1) return 18;
    if ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg() == 1)
        return *(unsigned char *)(p + 0x531);
    return 15;
}




/*
 * lever: explicit else preserves the nonzero arm after the field-return arm.
 * leaf: parent-cleared 24-byte follower in D328 extent.
 */
int B_BAG_MAIN_StateWaitKey(char *p)
{
    if (((struct BagWork *)p)->animActive == 0) {
        return *(unsigned char *)(p + 0x531);
    } else {
        return 16;
    }
}




int B_BAG_MAIN_StateFadeOut(char *p){PALANM_RequestFade(*(PalAnmObj * *)&((struct BagWork *)p)->palAnm,10,65535,0,0,16,0,BTLV_EFFECT_GetOwner());return 19;}





int B_BAG_MAIN_StateWaitFade(char *a)
{
    if (PALANM_GetFadeRequestBits((const char *)(((struct BagWork *)a)->palAnm)) == 0)
        return 0x14;
    return 0x13;
}




/*
 * lever: explicit if/else field stores preserve one-first branch and shared store.
 */
int B_BAG_MAIN_StateExit(struct Node *task, char *p)
{
    if (*(int *)(p + 0x5A0) == 1) {
        if (PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct BagWork *)p)->printSys) == 0) {
            if (((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->instant == 1) PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct BagWork *)p)->printSys);
            else return 0;
        }
        if (WIPE_SYS_EndCheck() == 0) {
            if (((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->instant == 1) WIPE_SYS_ExeEnd();
            else return 0;
        }
        if (*(struct Rec3 * *)&((struct BagWork *)p)->printStream) PRINTSYS_PrintStreamDelete(*(struct Rec3 * *)&((struct BagWork *)p)->printStream);
        B_BAG_MAIN_DeleteFrames(p);
        B_BAG_MAIN_DeleteItemGraphics(p);
        B_BAG_MAIN_ExitWindows(p);
        B_BAG_MAIN_DeleteText(p);
        B_BAG_MAIN_ExitBg();
        TCBL_Destroy(*(struct S02031140 * *)&((struct BagWork *)p)->tcbl);
        B_BAG_MAIN_DeleteCursor((u8 *)p);
        B_APP_TOOL_Delete(((struct BagWork *)p)->toolActors);
        if (*(void * *)(p + 0x598) == (void *)1) {
            **(u8 * *)&((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->dirtyPtr = 1;
        } else {
            **(u8 * *)&((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->dirtyPtr = 0;
        }
    }
    ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->done = 1;
    func_02030EAC(task);
    func_020307B0(p);
    return 1;
}




int B_BAG_MAIN_StateOtherFlow(char *p)
{
    switch (*(unsigned char *)(p + 0x53D)) {
    case 0:
        if (BTLV_FINGER_CURSOR_IsActive(((struct BagWork *)p)->fingerCursor) == 1) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            *(unsigned char *)(p + 0x533) = 2;
            *(unsigned char *)(p + 0x531) = 0x11;
            B_BAG_MAIN_StartFrameAnim(p, 2);
            ++*(unsigned char *)(p + 0x53D);
            return 0x10;
        }
        break;
    case 1:
        if (BTLV_FINGER_CURSOR_IsActive(((struct BagWork *)p)->fingerCursor) == 0) {
            B_BAG_MAIN_StateShowPocket1(p);
            ++*(unsigned char *)(p + 0x53D);
            *(unsigned char *)(p + 0x531) = 0x11;
            return 0xa;
        }
        break;
    case 2:
        if (BTLV_FINGER_CURSOR_IsActive(((struct BagWork *)p)->fingerCursor) == 1) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            *(u16 *)(*(char * *)&((struct BagWork *)p)->itemData + *(unsigned char *)(p + 0x533) * 2 + 0x30) = 0;
            *(unsigned char *)(p + 0x531) = 0x11;
            B_BAG_MAIN_StartFrameAnim(p, 4);
            ++*(unsigned char *)(p + 0x53D);
            return 0x10;
        }
        break;
    case 3:
        if (BTLV_FINGER_CURSOR_IsActive(((struct BagWork *)p)->fingerCursor) == 0) {
            B_BAG_MAIN_StateShowPocket2(p);
            ++*(unsigned char *)(p + 0x53D);
            *(unsigned char *)(p + 0x531) = 0x11;
            return 0xa;
        }
        break;
    case 4:
        if (BTLV_FINGER_CURSOR_IsActive(((struct BagWork *)p)->fingerCursor) == 1) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->itemId = B_BAG_MAIN_GetSlotItem(p, *(short *)(*(char * *)&((struct BagWork *)p)->itemData + *(unsigned char *)(p + 0x533) * 2 + 0x30));
            ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->slot = *(unsigned char *)(p + 0x533);
            ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->itemFlag = 0;
            B_BAG_MAIN_StartFrameAnim(p, 0xd);
            ++*(unsigned char *)(p + 0x53D);
        }
        break;
    case 5:
        if (BTLV_FINGER_CURSOR_IsActive(((struct BagWork *)p)->fingerCursor) == 0) return B_BAG_MAIN_StateShowMessage(p);
        break;
    }
    return 0x11;
}




void B_BAG_MAIN_InitBg(char *p)
{
 struct BgVramReq req=d_0220DEB0;
 struct BgTemplate b7,b6,b5,b4;
 BG_SYS_ApplyGraphicsMode(&req,1);
 b7=d_0220DEE0;BG_SYS_InitBgLayer(7,&b7,0);
 b6=d_0220DF20;BG_SYS_InitBgLayer(6,&b6,0);
 b5=d_0220DF00;BG_SYS_InitBgLayer(5,&b5,0);BG_SYS_ClearSlot(5);
 b4=d_0220DEC0;BG_SYS_InitBgLayer(4,&b4,0);BG_SYS_ClearSlot(4);
 BG_SYS_InitRun(5,32,0,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
 BG_SYS_InitRun(4,32,0,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
 func_02041B6C(5);func_02041B6C(4);BG_SYS_SetSubPlaneVisible(15,1);
}





void B_BAG_MAIN_ExitBg(void)
{
    BG_SYS_SetSubPlaneVisible(0x1f, 0);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(7);
}




void B_BAG_MAIN_LoadBgGraphics(char *p)
{
    void *handle = func_020490F4(99,(u16)((((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId & 0x7fff) | 0x8000));
    func_02049658(handle, 0, 6, 0, 0, 1, ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    func_020498F4(handle, 3, 6, 0, 0, 1, ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    func_020498F4(handle, 2, 7, 0, 0, 1, ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    PALANM_LoadHandlePaletteToSlot(*(struct PalAnmSlot * *)&((struct BagWork *)p)->palAnm, (void *)((u32)handle), 1, ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId, 1, 224, 0);
    ARC_TOOL_DeleteHandle(handle);
    BMP_MENUWORK_LoadCharAndPltt(4, 1, 11, 0, ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot * *)&((struct BagWork *)p)->palAnm, 1, 176, 32);
    PALANM_LoadArcPaletteToSlot(*(struct PalAnmSlot * *)&((struct BagWork *)p)->palAnm, 23, 5, ((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId, 1, 32, 192);
}




void B_BAG_MAIN_CreateText(char *p){*(struct MsgBank * *)&((struct BagWork *)p)->msgBank=func_02045B38(0,2,17,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);*(struct WordSet * *)&((struct BagWork *)p)->wordSet=WORDSET_CreateDefault(((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);((struct BagWork *)p)->printSys=(void *)PRINTSYS_QUE_Create((void *)((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);*(struct U16Vec * *)&((struct BagWork *)p)->strBuf=STRBUF_Create(512,((struct BagMenu *)(*(char * *)&((struct BagWork *)p)->itemData))->heapId);}




/*
 * Tail: two zero alignment bytes at 0x0220D7EE.
 */
void B_BAG_MAIN_DeleteText(char *p){MSGDATA_Delete(((struct BagWork *)p)->msgBank);WORDSET_DeleteStrbufED04(*(struct WordSet * *)&((struct BagWork *)p)->wordSet);PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct BagWork *)p)->printSys);STRBUF_Delete(((struct BagWork *)p)->strBuf);}




/*
 * trailing: 2 zero alignment bytes at 0x0220D846.
 */
void B_BAG_MAIN_ResetBgSlot(void *unused, int mode)
{
    switch (mode) {
    case 0:
        BG_SYS_ResetSlot(6, 0, 0);
        BG_SYS_ResetSlot(6, 3, 0);
        break;
    case 1:
        BG_SYS_ResetSlot(6, 0, 256);
        BG_SYS_ResetSlot(6, 3, 0);
        break;
    case 2:
        BG_SYS_ResetSlot(6, 0, 0);
        BG_SYS_ResetSlot(6, 3, 256);
        break;
    }
}




void B_BAG_MAIN_SwitchPage(char *p,int mode){B_BAG_MAIN_ResetBgSlot(p,mode);BG_SYS_ClearLayerEx(4,0);BG_SYS_ClearLayerEx(5,0);B_BAG_MAIN_ShowWindows((unsigned char *)p);B_BAG_MAIN_LayoutFrames(p,mode);B_BAG_MAIN_RecreateCursor((unsigned char *)p,mode,0);B_BAG_MAIN_SetDisplayMode(p,mode);}





int B_BAG_MAIN_CheckCancel(char **p)
{
    if (((struct BagMenu *)(*p))->cancel == 1) {
        ((struct BagMenu *)(*p))->itemId = 0;
        ((struct BagMenu *)(*p))->itemFlag = 0;
        return 1;
    }
    return 0;
}





void B_BAG_MAIN_PlaySe(char **a, int b)
{
    if (((struct BagMenu *)(*a))->soundOn == 1)
        GFL_USE_PlaySeDefaultVolume(b);
}





void B_BAG_MAIN_PlaySe2(char **a, int b)
{
    if (((struct BagMenu *)(*a))->soundOn == 1)
        GFL_USE_PlaySeDefaultVolume(b);
}




void B_BAG_MAIN_CreateCursor(u8 *p, u32 index, u32 value)
{
    *(struct CursorMove * *)&((struct BagWork *)p)->cursor = CURSOR_MOVE_Create(d_0220DF9C[index], d_0220DF90[index], (u32)p, (u32)*(void * *)(p + 0x598), (u8)value, ((struct BagMenu *)(*(u8 * *)&((struct BagWork *)p)->itemData))->heapId);
    CURSOR_MOVE_EnableInput(*(struct CursorMove * *)&((struct BagWork *)p)->cursor);
    CURSOR_MOVE_SetMode(*(struct CursorMove * *)&((struct BagWork *)p)->cursor);
    B_BAG_MAIN_LayoutCursor(p, value);
}





/*
 *   traced func_ label), so neither label nor sole-ref/code can attest it;
 *   byte-correct otherwise.  Not resolvable from this packet.
 *
 * Addresses are Black-image addresses.
 */
u32 B_BAG_MAIN_DeleteCursor(u8 *p)
{
    return CURSOR_MOVE_Delete((void *)(((struct BagWork *)p)->cursor));
}




/*
 * lever: an outer switch preserves the unconditional default-arm branch.
 */
void B_BAG_MAIN_RecreateCursor(u8 *p, int state, int value)
{
    switch (*(int *)&*(void * *)(p + 0x598)) {
    case 0: value = 0; break;
    default:
        switch (state) {
        case 0: value = p[0x533]; break;
        case 1: value = *(s16 *)(*(char * *)&((struct BagWork *)p)->itemData + p[0x533] * 2 + 0x30); break;
        case 2: value = 0; break;
        }
        break;
    }
    B_BAG_MAIN_DeleteCursor(p);
    B_BAG_MAIN_CreateCursor(p, state, value);
}





void B_BAG_MAIN_SetCursorVisible(char *a, int b)
{
    *(void * *)(a + 0x598) = (void *)b;
    B_APP_TOOL_SetActorsVisible((char *)(*(int *)&((struct BagWork *)a)->toolActors), (void *)b);
}





void B_BAG_MAIN_LayoutCursor(u8 *p, u32 idx)
{
    void *t = CURSOR_MOVE_GetEntry(*(void ** *)&((struct BagWork *)p)->cursor, idx);

    B_APP_TOOL_LayoutActors((int *)(((struct BagWork *)p)->toolActors), (u8 *)((u32)t));
}




void B_BAG_MAIN_ShowCursorAt(u8 *p,u32 i){B_BAG_MAIN_LayoutCursor(p,i);B_BAG_MAIN_SetCursorVisible((char *)p,1);}




void B_BAG_MAIN_HideCursor(char *p){B_BAG_MAIN_SetCursorVisible(p,0);}




void B_BAG_MAIN_HideCursor2(char *p){B_BAG_MAIN_SetCursorVisible(p,0);}




void B_BAG_MAIN_LayoutCursorOnly(u8 *p,u32 i){B_BAG_MAIN_LayoutCursor(p,i);}


void B_BAG_MAIN_HandleSelection(char *p, int b)
{
    if ((unsigned int)(b - 7) <= 1) {
        CURSOR_MOVE_SetCurrent((struct Sound *)(*(int *)&((struct BagWork *)p)->cursor), 0);
        b = 0;
    }
    B_BAG_MAIN_LayoutCursor((u8 *)p, b);
    B_BAG_MAIN_SetCursorVisible(p, 1);
}
