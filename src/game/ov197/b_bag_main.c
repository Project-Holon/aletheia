/*
 * file:     b_bag_main.c
 * unit:     yes
 * function: B_BAG_MAIN_InitWindows, B_BAG_MAIN_CreateWindows, B_BAG_MAIN_DeleteWindows, B_BAG_MAIN_ExitWindows, B_BAG_MAIN_DrawPage, B_BAG_MAIN_PrintLabel, B_BAG_MAIN_DrawLabels, B_BAG_MAIN_DrawItemName, B_BAG_MAIN_DrawItemInfo, B_BAG_MAIN_DrawSlot, B_BAG_MAIN_DrawPocket, B_BAG_MAIN_DrawHeader, B_BAG_MAIN_DrawInfoBox, B_BAG_MAIN_DrawItemsPage, B_BAG_MAIN_DrawDescription, B_BAG_MAIN_DrawItemUsage, B_BAG_MAIN_DrawOtherPage, B_BAG_MAIN_PrintItemMsg, B_BAG_MAIN_StartItemMsg, B_BAG_MAIN_UpdateTool, B_BAG_MAIN_ShowWindows, B_BAG_MAIN_CheckKeyItem, B_BAG_MAIN_SyncCursorToItem, B_BAG_MAIN_BuildPocketLists, B_BAG_MAIN_BuildOtherList, B_BAG_MAIN_InitOtherPage, B_BAG_MAIN_GetSlotItem, B_BAG_MAIN_GetItemFlag, B_BAG_MAIN_InitFrames, B_BAG_MAIN_DeleteFrames, B_BAG_MAIN_LayoutFrames, B_BAG_MAIN_StartFrameAnim, B_BAG_MAIN_StepFrameAnim, B_BAG_MAIN_CreateItemGraphics, B_BAG_MAIN_ClearHandles, B_BAG_MAIN_RegisterItemChars, B_BAG_MAIN_LoadItemGraphic, B_BAG_MAIN_LoadItemPalette, B_BAG_MAIN_RegisterCursorGraphics, B_BAG_MAIN_RegisterIconGraphics, B_BAG_MAIN_CreateItemActor, B_BAG_MAIN_CreateItemActors, B_BAG_MAIN_DeleteItemGraphics, B_BAG_MAIN_PlaceActor, B_BAG_MAIN_SetDisplayMode, B_BAG_MAIN_DisplaySingle, B_BAG_MAIN_DisplayList, B_BAG_MAIN_DisplaySelected, B_BAG_MAIN_CreateToolActors, B_BAG_MAIN_DeleteToolActors, B_BAG_MAIN_CreateFingerCursor, B_BAG_MAIN_DeleteFingerCursor, B_BAG_MAIN_StartFingerCursor, B_BAG_MAIN_DeleteFingerCursorActor, B_BAG_MAIN_DrawItemRow, B_BAG_MAIN_Create, B_BAG_MAIN_Main, B_BAG_MAIN_StateInit, B_BAG_MAIN_StateInitOther, B_BAG_MAIN_StateWaitPrintWipe, B_BAG_MAIN_StateWipeEnd, B_BAG_MAIN_StateSelectPocket, B_BAG_MAIN_StateSelectItem, B_BAG_MAIN_StateChangeCount, B_BAG_MAIN_StateWaitPrintRedraw, B_BAG_MAIN_StateChooseItem, B_BAG_MAIN_StateShowMessage, B_BAG_MAIN_StateShowPocket0, B_BAG_MAIN_StateShowPocket1, B_BAG_MAIN_StateShowPocket2, B_BAG_MAIN_StateWaitPrintSetMode, B_BAG_MAIN_StateStartMessage, B_BAG_MAIN_StateMessageInput, B_BAG_MAIN_StateMessageDone, B_BAG_MAIN_StateWaitKey, B_BAG_MAIN_StateFadeOut, B_BAG_MAIN_StateWaitFade, B_BAG_MAIN_StateExit, B_BAG_MAIN_StateOtherFlow, B_BAG_MAIN_InitBg, B_BAG_MAIN_ExitBg, B_BAG_MAIN_LoadBgGraphics, B_BAG_MAIN_CreateText, B_BAG_MAIN_DeleteText, B_BAG_MAIN_ResetBgSlot, B_BAG_MAIN_SwitchPage, B_BAG_MAIN_CheckCancel, B_BAG_MAIN_PlaySe, B_BAG_MAIN_PlaySe2, B_BAG_MAIN_CreateCursor, B_BAG_MAIN_DeleteCursor, B_BAG_MAIN_RecreateCursor, B_BAG_MAIN_SetCursorVisible, B_BAG_MAIN_LayoutCursor, B_BAG_MAIN_ShowCursorAt, B_BAG_MAIN_HideCursor, B_BAG_MAIN_HideCursor2, B_BAG_MAIN_LayoutCursorOnly, B_BAG_MAIN_HandleSelection
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
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   d_0220DA0D 0x0220DA0D data a1
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   WORDSET_SetSlotFromMsg36 0x0201EF40 thumb
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
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   B_APP_TOOL_Update 0x0220B0B0 thumb
 *   B_APP_TOOL_ShowWindows  0x0220B094  thumb  ov196
 *   MYITEM_SAVEDATA_HasItem 0x02007F68 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 *   MYITEM_SAVEDATA_GetSlot 0x020081DC thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   d_0220DB3C 0x0220DB3C data a4
 *   d_0220DB3F 0x0220DB3F data a4
 *   ITEM_GFX_IsFlagClear 0x0202F114 thumb
 *   ITEM_GFX_GetItemId 0x0202F138 thumb
 *   ITEM_GFX_GetExtraValue 0x0202F144 thumb
 *   BGWINFRM_Create 0x0202C9B4 thumb
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
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
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
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
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BTLV_EFFECT_GetOwner 0x021F86D4 thumb ov094
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   TCB_AddTask 0x02030DA8 arm
 *   MYITEM_SAVEDATA_GetBattlePocketCursor 0x0200829C thumb
 *   MYITEM_SAVEDATA_GetLastBattleItem 0x020082B0 thumb
 *   MYITEM_SAVEDATA_GetLastBattleItemPocket 0x020082B4 thumb
 *   TCBL_Main 0x020310C4 arm
 *   BGWINFRM_UpdateMoves 0x0202CD94 thumb
 *   d_0220DF40 0x0220DF40 data a4
 *   d_04001050 0x04001050 data a2
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   TCBL_Create 0x0203101C arm
 *   B_APP_TOOL_Create 0x0220AF40 thumb ov196
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   FILE_UTIL_GetItemParam 0x02020FE4 thumb
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
 *   TCB_DeleteTask 0x02030EAC arm
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
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
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
struct ClactActor;
struct PaletteFade;
struct PalAnmObj;
typedef struct PalAnmObj PalAnmObj;
struct Sub0204A9D0;
struct Unit;
struct ClactVec2;
struct MyItemSave;
struct Tcbl;
struct Node;
struct PrintSys;
struct Sound;
struct Rec;
struct Rec3;
struct S02031140;
struct CursorMove;

#include "../types.h"

/* one entry of the bag window table: a BMP window handle and a redraw flag */
struct WinSlot {
    void *handle;
    unsigned char dirty;
    unsigned char pad[3];
};

/* a screen-space point, used by the item actor placement tables */
struct BBagMainPair {
    short x, y;
};

/* the bag menu data handed to B_BAG_MAIN_Create; the work struct keeps a pointer to it */
struct BagMenu {
    void *savedata;            /* 0x00 savedata block */
    struct GfFont *font;       /* 0x04 font of the bag text */
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
    struct BagMenu *itemData;          /* 0x000 */
    void *tcbl;                        /* 0x004 Tcbl task */
    void *palAnm;                      /* 0x008 PaletteFade */
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
    unsigned char pad528[8];           /* 0x528 */
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
    int actorsVisible;                 /* 0x598 tool actors visible flag */
    const u8 *textPtr;                 /* 0x59C label string pointer */
    int initialized;                   /* 0x5A0 initialised flag */
};

/* palette/screen block loaded by ARC_UTIL_LoadPaletteBlockFromHandle */
struct BBagMainScreenData {
    unsigned char pad[0xC];
    char *data;
};

typedef struct {unsigned short entry[36][2];} Row;

typedef struct {u16 member;u8 w,h;} WinCfg;

typedef struct {u16 a,b,c;unsigned char d,e;} BBagMainConfig;


#include "../arm9/bg_sys.h"
#include "../arm9/arc_tool.h"
struct BmpWin;

#include "../arm9/bmp_win.h"
struct Strbuf;
#include "../arm9/msgdata.h"
struct GfFont;
#include "../arm9/printsys.h"
struct Bmp;
struct PrintQueue;
#include "../arm9/strbuf.h"
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/wordset.h"
#include "../arm9/file_util.h"
#include "../arm9/bmp_menuwork.h"
#include "../arm9/gf_font.h"
#include "../arm9/msg_speed.h"
#include "../ov196/b_app_tool.h"
struct MyItem;
#include "../arm9/myitem_savedata.h"
struct BagSlot;
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/item_gfx.h"
struct BgWinFrmWork;
#include "../arm9/bgwinfrm.h"
#include "../arm9/clact.h"
#include "../arm9/arc_util.h"
struct NNSG2dCharacterData;
#include "../arm9/palanm.h"
/* palanm.h does not declare these yet */
/* palanm.h does not declare these yet */
struct ClactActor;
struct ClactActor;
struct ClactVec2;
struct BtlvFingerCursor;
#include "../ov094/btlv_effect.h"
#include "../arm9/tcb_list.h"
struct BagCursor;
struct TcblSystem;
#include "../arm9/tcbl.h"
#include "../arm9/gx.h"
#include "../arm9/net.h"
#include "../arm9/wipe.h"
struct Cursor;
#include "../arm9/cursor_move.h"
struct TextPrinter;
#include "../arm9/touchpanel.h"
#include "../arm9/key.h"
struct TcbTask;
#include "../arm9/gfl_use.h"
#include "../ov094/btlv_finger_cursor.h"
struct CursorVtbl;
struct CursorEntry;
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
void B_BAG_MAIN_UpdateTool(char *a);
void B_BAG_MAIN_ShowWindows(u8 *p);
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
struct ClactActor *B_BAG_MAIN_CreateItemActor(char *p,const int *indices);
void B_BAG_MAIN_CreateItemActors(char *p);
void B_BAG_MAIN_DeleteItemGraphics(char *p);
void B_BAG_MAIN_PlaceActor(struct ClactActor *a, struct ClactVec2 *b);
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
void B_BAG_MAIN_DrawItemRow(char *p,u16 slot,u8 a,u8 b,const struct BBagMainPair *src);
void B_BAG_MAIN_Create(u8 *arg);
void B_BAG_MAIN_Main(struct TcbTask *task, void *arg);
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
int B_BAG_MAIN_StateExit(struct TcbTask *task, char *p);
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
extern const u8 d_0220DA0D[];
extern const char d_0220DA38[];
extern const char d_0220DA3C[];
extern const u8 d_0220DA28[];
extern const u8 d_0220DA19[];
extern const u8 d_0220DA08[];
extern const u8 d_0220DB3C[];
extern const u8 d_0220DB3F[];
extern const WinCfg d_0220DB44[14];
extern const int d_0220DBBC[];
extern const int d_0220DB7C[];
extern const struct BBagMainPair d_0220DB88[];
extern const struct BBagMainPair d_0220DB80[];
extern const char d_0220E0E0[];
extern u16 d_04001050[];
extern const struct DispConfig d_0220DEB0;
extern const struct BgTemplate d_0220DEE0,d_0220DF20,d_0220DF00,d_0220DEC0;
extern struct CursorVtbl *const d_0220DF90[];
extern struct CursorEntry *const d_0220DF9C[];

void B_BAG_MAIN_InitWindows(char *p) { ((struct BagWork *)p)->itemMsgWin=(void *)BMP_WIN_Create(4,1,19,30,4,12,1); B_BAG_MAIN_CreateWindows(p,((struct BagWork *)p)->page); }

/*
 * Declaring the table pointer before the counter restores r4/r5 allocation.
 */
void B_BAG_MAIN_CreateWindows(char *p,u8 unused) { const u8 *q; u32 i; q=d_0220DA68; for(i=0;i<35;i++,q+=6) ((struct BagWork *)p)->win[i].handle=BMP_WIN_Create((unsigned int)q[0],(unsigned int)q[1],(unsigned int)q[2],q[3],q[4],q[5],1); }

void B_BAG_MAIN_DeleteWindows(char *a)
{
    unsigned int i;

    for (i = 0; i < 0x23; i++)
        BMP_WIN_Delete(((struct BagWork *)a)->win[i].handle);
}

void B_BAG_MAIN_ExitWindows(char *a)
{
    B_BAG_MAIN_DeleteWindows(a);
    BMP_WIN_Delete((struct BmpWin *)(((struct BagWork *)a)->itemMsgWin));
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
    struct BmpWin *handle = (*(struct BmpWin **)((char *)&((struct BagWork *)p)->win[0].handle + i * (int)sizeof(struct WinSlot)));
    struct Strbuf *text = MSGDATA_AllocString((struct MsgBank *)(((struct BagWork *)p)->msgBank),id);
    int width=PRINTSYS_MeasureWidestLine((struct Strbuf *)text,(((struct BagWork *)p)->itemData)->font,0);
    int x=(BMP_WIN_GetWidth((struct BmpWin *)handle)*8-width)>>1;
    void *font=((struct BagWork *)p)->printSys;
    struct Bmp *surface = BMP_WIN_GetBmp((*(struct BmpWin **)((char *)&((struct BagWork *)p)->win[0].handle + i * (int)sizeof(struct WinSlot))));
    PRINTSYS_PrintQueColor(font,(struct Bmp *)surface,(s16)x,(s16)y,(struct Strbuf *)text,(struct GfFont *)(((((struct BagWork *)p)->itemData)->font)),colour);
    *((u8 *)&((struct BagWork *)p)->win[0].dirty + i * (int)sizeof(struct WinSlot))=1;
    STRBUF_Delete((struct Strbuf *)text);
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
    for(i=0;i<=4;i++)BMP_Clear(BMP_WIN_GetBmp(((struct BagWork *)p)->win[i].handle),0);
    B_BAG_MAIN_PrintLabel(p,0,0,0,0x3C40);
    B_BAG_MAIN_PrintLabel(p,0,1,16,0x3C40);
    B_BAG_MAIN_PrintLabel(p,1,2,0,0x3C40);
    B_BAG_MAIN_PrintLabel(p,1,3,16,0x3C40);
    B_BAG_MAIN_PrintLabel(p,2,7,0,0x3C40);
    B_BAG_MAIN_PrintLabel(p,3,6,0,0x3C40);
    if(((struct BagWork *)p)->keyItem!=0){
        text=MSGDATA_AllocString(((struct BagWork *)p)->msgBank,8);
        font=((struct BagWork *)p)->printSys;
        surface=BMP_WIN_GetBmp(((struct BagWork *)p)->win[4].handle);
        PRINTSYS_PrintQueColor(font,surface,0,0,text,(((struct BagWork *)p)->itemData)->font,0x3C40);
        ((struct BagWork *)p)->win[4].dirty=1;
        STRBUF_Delete(text);
    }else{
        BMP_WIN_TransferChars(((struct BagWork *)p)->win[4].handle);
    }
    ((struct BagWork *)p)->textPtr=d_0220DA0D;
}

/*
 * Width: printer x truncates to signed halfword in original; extern keeps s16 despite owner u32.
 */
void B_BAG_MAIN_DrawItemName(char *p,u32 i,int id,int w,int unused,int unused2)
{
    char *windows=(char *)((struct BagWork *)p)->win;
    void *handle=*(void **)(windows+w*(int)sizeof(struct WinSlot));
    void *text;
    void *font;
    void *surface;
    u32 width;
    sptr page;
    BMP_Clear(BMP_WIN_GetBmp(handle),0);
    page=(uptr)p+((struct BagWork *)p)->pocket*(int)sizeof(((struct BagWork *)p)->rows[0]);
    if(((struct BagWork *)page)->rows[0][i][0]!=0){
        text=MSGDATA_AllocString(((struct BagWork *)p)->msgBank,*(u32 *)(d_0220DA38+id*8));
        page=(uptr)p+((struct BagWork *)p)->pocket*(int)sizeof(((struct BagWork *)p)->rows[0]);
        WORDSET_SetSlotFromMsg36(((struct BagWork *)p)->wordSet,0,((struct BagWork *)page)->rows[0][i][0]);
        WORDSET_CopyTaggedText(((struct BagWork *)p)->wordSet,((struct BagWork *)p)->strBuf,text);
        width=PRINTSYS_MeasureWidestLine(((struct BagWork *)p)->strBuf,(((struct BagWork *)p)->itemData)->font,0);
        width=BMP_WIN_GetWidth(handle)*8-width;
        font=((struct BagWork *)p)->printSys;
        surface=BMP_WIN_GetBmp(*(void **)(windows+w*(int)sizeof(struct WinSlot)));
        PRINTSYS_PrintQueColor(font,surface,(s16)(width/2),(s16)7,(((struct BagWork *)p)->strBuf),(((struct BagWork *)p)->itemData)->font,0x3C40);
        ((struct BagWork *)(p+w*(int)sizeof(struct WinSlot)))->win[0].dirty=1;
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
  char *windows = (char *)((struct BagWork *)p)->win;
  void *handle = *((void **) (windows + (w * (int)sizeof(struct WinSlot))));
  void *text;
  void *font;
  void *surface;
  sptr page;
  char *strBufPrint;
  u16 pad;
  struct GfFont **printWidthPtr;
  char *strBufDst;
  BMP_Clear(BMP_WIN_GetBmp(handle), 0);
  page = ((uptr) p) + (((struct BagWork *)p)->pocket * 0x90);
  if (((((struct BagWork *)page)->rows[0][i][1]) != 0) && (((struct BagWork *)p)->itemData->mode != 1))
  {
    text = MSGDATA_AllocString(((struct BagWork *)p)->msgBank, *((u32 *) (d_0220DA3C + (id * 8))));
    page = ((uptr) p) + (((struct BagWork *)p)->pocket * 0x90);
    WORDSET_SetSlotNumber(((struct BagWork *)p)->wordSet, 0, ((struct BagWork *)page)->rows[0][i][1], 3, 0, 1);
    strBufDst = (char *)&((struct BagWork *)p)->strBuf;
    WORDSET_CopyTaggedText(((struct BagWork *)p)->wordSet, *((void **) strBufDst), text);
    font = ((struct BagWork *)p)->printSys;
    surface = BMP_WIN_GetBmp(*((void **) (windows + (w * (int)sizeof(struct WinSlot)))));
    strBufPrint = (char *)&((struct BagWork *)p)->strBuf;
    printWidthPtr = &((struct BagWork *)p)->itemData->font;
    PRINTSYS_PrintQueColor(font, surface, (s16)0, (s16)y, (*((void **) strBufPrint)), *printWidthPtr, 0x3C40);
    ((struct BagWork *)(p+w*(int)sizeof(struct WinSlot)))->win[0].dirty=1;
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
    int base=((struct BagWork *)p)->itemData->cursorY[((struct BagWork *)p)->pocket]*6;
    int row=5;
    int twice;
    if(((struct BagWork *)p)->pocketSide!=0)row=0x11;
    twice=i*2;
    B_BAG_MAIN_DrawItemName(p,i+base,i,row+twice,0,0);
    B_BAG_MAIN_DrawItemInfo(p,i+base,i,row+1+twice,0,4,0);
}

void B_BAG_MAIN_DrawPocket(char *p)
{
    u16 i;
    BG_SYS_SetTileEntry(5,0,0,0,0x20,0x13,0x11);
    for(i=0;i<6;i++)B_BAG_MAIN_DrawSlot(p,i);
    if(((struct BagWork *)p)->pocketSide==0)
        ((struct BagWork *)p)->textPtr=d_0220DA28;
    else
        ((struct BagWork *)p)->textPtr=d_0220DA19;
    ((struct BagWork *)p)->pocketSide^=1;
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
    text=MSGDATA_AllocString(((struct BagWork *)p)->msgBank,28);
    width=PRINTSYS_MeasureWidestLine(text,(((struct BagWork *)p)->itemData)->font,0);
    x=(BMP_WIN_GetWidth(handle)*8-width)/2;
    PRINTSYS_PrintQueColor(((struct BagWork *)p)->printSys,surface,(s16)x,(s16)4,text,(((struct BagWork *)p)->itemData)->font,0x3C40);
    STRBUF_Delete(text);
    text=MSGDATA_AllocString(((struct BagWork *)p)->msgBank,29);
    WORDSET_SetSlotNumber(((struct BagWork *)p)->wordSet,0,((struct BagWork *)p)->pagePerPocket[((struct BagWork *)p)->pocket]+1,2,0,1);
    WORDSET_CopyTaggedText(((struct BagWork *)p)->wordSet,((struct BagWork *)p)->strBuf,text);
    PRINTSYS_PrintQueColor(((struct BagWork *)p)->printSys,surface,(s16)(x+width),(s16)4,(((struct BagWork *)p)->strBuf),(((struct BagWork *)p)->itemData)->font,0x3C40);
    STRBUF_Delete(text);
    text=MSGDATA_AllocString(((struct BagWork *)p)->msgBank,30);
    WORDSET_SetSlotNumber(((struct BagWork *)p)->wordSet,0,((struct BagWork *)p)->itemData->cursorY[((struct BagWork *)p)->pocket]+1,2,0,1);
    WORDSET_CopyTaggedText(((struct BagWork *)p)->wordSet,((struct BagWork *)p)->strBuf,text);
    width=PRINTSYS_MeasureWidestLine(((struct BagWork *)p)->strBuf,(((struct BagWork *)p)->itemData)->font,0);
    font=((struct BagWork *)p)->printSys;
    lastSurface=BMP_WIN_GetBmp(((struct BagWork *)p)->win[30].handle);
    PRINTSYS_PrintQueColor(font,lastSurface,(s16)(x-width),(s16)4,(((struct BagWork *)p)->strBuf),(((struct BagWork *)p)->itemData)->font,0x3C40);
    ((struct BagWork *)p)->win[30].dirty=1;
    STRBUF_Delete(text);
}

void B_BAG_MAIN_DrawInfoBox(char *p)
{
    BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)((struct BagWork *)p)->win[29].handle)),0);
    if((((struct BagWork *)p)->itemData)->mode!=1) {
        switch(((struct BagWork *)p)->pocket) {
        case 0:B_BAG_MAIN_PrintLabel(p,29,22,4,0x3c40);B_BAG_MAIN_PrintLabel(p,29,23,20,0x3c40);break;
        case 1:B_BAG_MAIN_PrintLabel(p,29,24,4,0x3c40);B_BAG_MAIN_PrintLabel(p,29,25,20,0x3c40);break;
        case 2:B_BAG_MAIN_PrintLabel(p,29,26,12,0x3c40);break;
        case 3:B_BAG_MAIN_PrintLabel(p,29,27,12,0x3c40);break;
        }
    } else BMP_WIN_TransferChars((struct BmpWin *)((struct BagWork *)p)->win[29].handle);
}

void B_BAG_MAIN_DrawItemsPage(char *a)
{
    B_BAG_MAIN_DrawPocket(a);
    B_BAG_MAIN_DrawInfoBox(a);
    B_BAG_MAIN_DrawHeader(a);
}

void B_BAG_MAIN_DrawDescription(u8 *p, u32 idx)
{
    void *win = ((struct BagWork *)p)->win[31].handle;
    void *msg = MSGDATA_AllocString(((struct BagWork *)p)->msgBank, 9);
    u8 sel = ((struct BagWork *)p)->pocket;
    u8 *row = (u8 *)((struct BagWork *)p)->rows[sel];
    void *w;
    WORDSET_SetSlotFromMsg36(((struct BagWork *)p)->wordSet, 0, *(u16 *)(row + idx * 4));
    WORDSET_CopyTaggedText(((struct BagWork *)p)->wordSet, ((struct BagWork *)p)->strBuf, msg);
    BMP_Clear(BMP_WIN_GetBmp(win), 0);
    w = ((struct BagWork *)p)->printSys;
    PRINTSYS_PrintQueColor(w, BMP_WIN_GetBmp(((struct BagWork *)p)->win[31].handle), 0, 0,
                  ((struct BagWork *)p)->strBuf, ((struct BagWork *)p)->itemData->font, 0x3C40);
    ((struct BagWork *)p)->win[31].dirty = 1;
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
    void *buf=STRBUF_Create(130,(((struct BagWork *)p)->itemData)->heapId);
    index=((struct BagWork *)p)->pocket;
    row=(Row *)(((void *)&((struct BagWork *)p)->rows));
    FILE_UTIL_ReadStringAlt(buf,row[index].entry[n][0],(((struct BagWork *)p)->itemData)->heapId);
    owner=((struct BagWork *)p)->printSys;
    PRINTSYS_PrintQueColor(owner,BMP_WIN_GetBmp(((struct BagWork *)p)->win[33].handle),4,0,buf,(((struct BagWork *)p)->itemData)->font,0x3c40);
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
    for (i = 31; i <= 34; i++)
        BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)(((struct BagWork *)p)->win[i].handle)), 0);
    x = ((struct BagWork *)p)->itemData->cursorX[((struct BagWork *)p)->pocket];
    y = ((struct BagWork *)p)->itemData->cursorY[((struct BagWork *)p)->pocket] * 6;
    B_BAG_MAIN_DrawDescription((u8 *)p, x + y);
    B_BAG_MAIN_DrawItemInfo(p, x + y, 0, 32, 0, 0, 0);
    B_BAG_MAIN_DrawItemUsage(p, x + y);
    B_BAG_MAIN_PrintLabel(p, 34, 31, 0, 0x3c40);
    ((struct BagWork *)p)->textPtr = d_0220DA08;
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
    ((struct BagWork *)p)->printStream = PRINTSYS_PrintStream((struct BmpWin *)(((struct BagWork *)p)->itemMsgWin), 0, 0, (struct Strbuf *)(((struct BagWork *)p)->strBuf),
        ((struct BagWork *)p)->itemData->font, MSG_SPEED_GetWait(), (struct Tcbl *)((struct BagWork *)p)->tcbl, 10,
        ((struct BagWork *)p)->itemData->heapId, 15);
    d = ((struct BagWork *)p)->itemMsgWin;
    BMP_WIN_TransferChars(d);
    BMP_WIN_MakeScreen(d);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(d));
}

void B_BAG_MAIN_UpdateTool(char *a)
{
    B_APP_TOOL_Update((BAppToolEntry *)&((struct BagWork *)a)->win[0], (struct PrintSys *)(((struct BagWork *)a)->printSys), 0x23);
}

/*
 * Addresses are Black-image addresses.
 */
void B_BAG_MAIN_ShowWindows(u8 *p)
{
    B_APP_TOOL_ShowWindows((char *)(((void *)&((struct BagWork *)p)->win)), (unsigned char *)((struct BagWork *)p)->textPtr);
}

/*
 * EXACT* tail: two zero alignment bytes after the function.
 */
int B_BAG_MAIN_CheckKeyItem(char *p) { struct BagMenu *q; if(((struct BagWork *)p)->keyItem==0) return 0; q=((struct BagWork *)p)->itemData; if(MYITEM_SAVEDATA_HasItem((struct MyItem *)(*(u8 * *)&((struct BagMenu *)q)->savedata),((struct BagWork *)p)->keyItem,1,((struct BagMenu *)q)->heapId)==0) { ((struct BagWork *)p)->keyItem=0; ((struct BagWork *)p)->keyItemSlot=0; return 0; } return 1; }

void B_BAG_MAIN_SyncCursorToItem(u8 *p)
{
    unsigned int i = 0;
    u8 sel = ((struct BagWork *)p)->pocket;
    u8 *row = p + sel * sizeof(((struct BagWork *)p)->rows[0]);
    u16 cur = ((struct BagWork *)p)->keyItem;
    for (; i < 36; i++) {
        if (cur == ((struct BagWork *)row)->rows[0][i][0]) {
            ((struct BagWork *)p)->itemData->cursorX[sel] = i % 6;
            ((struct BagWork *)p)->itemData->cursorY[((struct BagWork *)p)->pocket] = i / 6;
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

    tbl = ARC_TOOL_LoadMember(0xE8, 0, ((struct BagWork *)p)->itemData->heapId);
    i = 0;
    do {
        j = 0;
        for (;;) {
            r = (u16 *)MYITEM_SAVEDATA_GetSlot(((struct BagWork *)p)->itemData->savedata, d_0220DB3C[i], (u16)j);
            if (r == 0)
                break;
            if (r[0] != 0 && r[1] != 0) {
                u32 m = tbl[r[0]];
                for (k = 0; k < 4; k++) {
                    if (m & (1 << k)) {
                        int c = d_0220DB3F[k];
                        u8 *q = p + c;
                        uptr e = c * sizeof(((struct BagWork *)p)->rows[0]);
                        e = ((struct BagWork *)q)->countPerPocket[0] * 4 + (uptr)(p + e);
                        ((struct BagWork *)e)->rows[0][0][0] = r[0];
                        ((struct BagWork *)e)->rows[0][0][1] = r[1];
                        ((struct BagWork *)q)->countPerPocket[0]++;
                    }
                }
            }
            j++;
        }
        i++;
    } while (i < 3);
    GFL_HEAP_Free(tbl);
    for (i = 0; i < 4; i++) {
        u8 v = ((struct BagWork *)p)->countPerPocket[i];
        if (v == 0)
            ((struct BagWork *)p)->pagePerPocket[i] = 0;
        else
            ((struct BagWork *)p)->pagePerPocket[i] = (v - 1) / 6;
        if (((struct BagWork *)p)->pagePerPocket[i] < ((struct BagWork *)p)->itemData->cursorY[i])
            ((struct BagWork *)p)->itemData->cursorY[i] = ((struct BagWork *)p)->pagePerPocket[i];
    }
}

void B_BAG_MAIN_BuildOtherList(char *p)
{
    unsigned i;
    for(i=0;i<46;i++) {
        if(ITEM_GFX_IsFlagClear(*(const unsigned char * *)&(((struct BagWork *)p)->itemData)->pocketMask,i)==1) {
            ((struct BagWork *)p)->rows[0][((struct BagWork *)p)->countPerPocket[0]][0]=ITEM_GFX_GetItemId(i);
            ((struct BagWork *)p)->rows[0][((struct BagWork *)p)->countPerPocket[0]][1]=1;
            (((struct BagWork *)p)->countPerPocket[0])++;
        }
    }
    ((struct BagWork *)p)->pagePerPocket[0]=(((struct BagWork *)p)->countPerPocket[0]-1)/6;
}

void B_BAG_MAIN_InitOtherPage(char *p)
{
    ((struct BagWork *)p)->rows[2][0][0] = 4;
    ((struct BagWork *)p)->rows[2][0][1] = 0x1e;
    ((struct BagWork *)p)->countPerPocket[2] = 1;
    ((struct BagWork *)p)->pagePerPocket[2] = 0;
}

/*
 * lever: one statement n = (n + k * 6) << 2, then p += index * 0x90 and a
 *   const u16 pointer s = p + n read as s[0xa8] / s[0xa9]; the byte-offset
 *   spelling (n += ..; n *= 4; slot + 0x150) sank the shift after the
 *   0x90 multiply (13 bytes), and a typed row struct folded 0x150 (60 bytes).
 */
u16 B_BAG_MAIN_GetSlotItem(const char *p, unsigned n)
{
    unsigned index = ((struct BagWork *)p)->pocket;
    const u16 *s;
    n = (n + ((struct BagWork *)p)->itemData->cursorY[index] * 6) << 2;
    p += index * 0x90;
    s = (const u16 *)(p + n);
    if (((const struct BagWork *)s)->rows[0][0][0] != 0 && ((const struct BagWork *)s)->rows[0][0][1] != 0) return ((const struct BagWork *)s)->rows[0][0][0];
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
    ((struct BagWork *)p)->frameMgr=BGWINFRM_Create(2,14,(((struct BagWork *)p)->itemData)->heapId);
    arc=ARC_TOOL_CreateHandle(99,(u16)(((((struct BagWork *)p)->itemData)->heapId&0x7FFF)|0x8000));
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
    BGWINFRM_Delete((struct BgWinFrmWork *)(*(struct WinMgr * *)&((struct BagWork *)a)->frameMgr));
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
        if (((struct BagWork *)p)->keyItem == 0)
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
        pm = (struct WinMgr **)(((void *)&((struct BagWork *)p)->frameMgr));
        for (i = 0; i < 6; i++) {
            if (B_BAG_MAIN_GetSlotItem(p, i) == 0)
                BGWINFRM_ChangePalette(MGR(p), i + 4, 0, 0, d_0220DB44[i + 4].w, d_0220DB44[i + 4].h, 6);
            else
                BGWINFRM_ChangePalette((struct BgWinFrmWork *)(*pm), i + 4, 0, 0, d_0220DB44[i + 4].w, d_0220DB44[i + 4].h, 4);
        }
        {
            struct BagWork *q = (struct BagWork *)p;
            if (((struct BagWork *)p)->pagePerPocket[((struct BagWork *)p)->pocket] == 0) {
                BGWINFRM_ChangePalette((struct BgWinFrmWork *)(((struct BagWork *)p)->frameMgr), 11, 0, 0, 5, 5, 3);
                BGWINFRM_ChangePalette((struct BgWinFrmWork *)(((struct BagWork *)p)->frameMgr), 12, 0, 0, 5, 5, 3);
            } else {
                BGWINFRM_ChangePalette((struct BgWinFrmWork *)(((struct BagWork *)p)->frameMgr), 11, 0, 0, 5, 5, 1);
                BGWINFRM_ChangePalette((struct BgWinFrmWork *)(((struct BagWork *)p)->frameMgr), 12, 0, 0, 5, 5, 1);
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
    for(i=0;i<9;i++) ((struct BagWork *)p)->charHandles[i]=-1;
    for(i=0;i<9;i++) ((struct BagWork *)p)->paletteHandles[i]=-1;
    for(i=0;i<3;i++) ((struct BagWork *)p)->cellAnims[i]=-1;
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
    if((((struct BagWork *)p)->itemData)->mode==1) {item=(unsigned)ITEM_GFX_GetItemId(0);first=3;second=4;}
    else {first=1;item=1;second=2;}
    arc=ARC_TOOL_CreateHandle(FILE_UTIL_GetItemCount(),(u16)(((((struct BagWork *)p)->itemData)->heapId&0x7fff)|0x8000));
    for(i=0;i<7;i++) {
        ((struct BagWork *)p)->charHandles[i]=CLACT_RegisterCharacter(arc,FILE_UTIL_Get(item,first),0,1,(((struct BagWork *)p)->itemData)->heapId);
        ((struct BagWork *)p)->paletteHandles[i]=CLACT_RegisterPalette(arc,FILE_UTIL_Get(item,second),1,(u16)(i*32),(((struct BagWork *)p)->itemData)->heapId);
    }
    a=FILE_UTIL_GetBankCount();
    ((struct BagWork *)p)->cellAnims[0]=CLACT_RegisterCellAnim(arc,a,FILE_UTIL_GetBaseIndex(),(((struct BagWork *)p)->itemData)->heapId);
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * matching: u16 item restores entry spill order without extra truncation; unsigned item differs in eight bytes.
 */
void B_BAG_MAIN_LoadItemGraphic(char *p,u16 item,unsigned slot,unsigned offset)
{
    struct BagMenu *q=((struct BagWork *)p)->itemData;
    unsigned first, second;
    void *arc;
    void *data,*buffer;
    if(((struct BagMenu *)q)->mode==1) {first=3;second=4;} else {first=1;second=2;}
    arc=ARC_TOOL_CreateHandle(FILE_UTIL_GetItemCount(),(u16)((((struct BagMenu *)q)->heapId&0x7fff)|0x8000));
    buffer=ARC_UTIL_LoadScreenDataFromHandle((void *)arc,FILE_UTIL_Get(item,first),0,(&data),(((struct BagWork *)p)->itemData)->heapId);
    CLACT_TransferCharacter(((struct BagWork *)p)->charHandles[slot],data);
    GFL_HEAP_Free(buffer);
    PALANM_LoadHandlePaletteToSlot(((struct BagWork *)p)->palAnm,(void *)(arc),FILE_UTIL_Get(item,second),(((struct BagWork *)p)->itemData)->heapId,3,32,offset*16);
    ARC_TOOL_DeleteHandle(arc);
}

void B_BAG_MAIN_LoadItemPalette(char *p,unsigned item,unsigned slot)
{
    struct BagMenu *q=((struct BagWork *)p)->itemData;
    unsigned archive;
    if(((struct BagMenu *)q)->mode==1) {
        archive=FILE_UTIL_GetItemCount();
        ARC_UTIL_UploadPaletteFromArchiveWhole(archive,FILE_UTIL_Get(item,4),5,slot*32,32,((struct BagMenu *)q)->heapId);
    } else {
        archive=FILE_UTIL_GetItemCount();
        ARC_UTIL_UploadPaletteFromArchiveWhole(archive,FILE_UTIL_Get(item,2),5,slot*32,32,((struct BagMenu *)q)->heapId);
    }
}

void B_BAG_MAIN_RegisterCursorGraphics(char *p)
{
    void *arc = ARC_TOOL_CreateHandle(99,(u16)(((((struct BagWork *)p)->itemData)->heapId&0x7fff)|0x8000));
    ((struct BagWork *)p)->charHandles[7]=CLACT_RegisterCharacter(arc,13,1,1,(((struct BagWork *)p)->itemData)->heapId);
    ((struct BagWork *)p)->paletteHandles[7]=CLACT_RegisterPalette(arc,14,1,224,(((struct BagWork *)p)->itemData)->heapId);
    ((struct BagWork *)p)->cellAnims[1]=CLACT_RegisterCellAnim(arc,15,16,(((struct BagWork *)p)->itemData)->heapId);
    PALANM_LoadHandlePaletteToSlot(((struct BagWork *)p)->palAnm,(void *)(arc),14,(((struct BagWork *)p)->itemData)->heapId,3,32,112);
    ARC_TOOL_DeleteHandle(arc);
}

void B_BAG_MAIN_RegisterIconGraphics(char *p)
{
    void *arc = ARC_TOOL_CreateHandle(11,(u16)(((((struct BagWork *)p)->itemData)->heapId&0x7fff)|0x8000));
    char *data;
    void *buf;
    ((struct BagWork *)p)->charHandles[8]=CLACT_RegisterCharacter(arc,119,0,1,(((struct BagWork *)p)->itemData)->heapId);
    ((struct BagWork *)p)->paletteHandles[8]=CLACT_RegisterPaletteEx(arc,116,1,256,4,1,(((struct BagWork *)p)->itemData)->heapId);
    ((struct BagWork *)p)->cellAnims[2]=CLACT_RegisterCellAnim(arc,120,121,(((struct BagWork *)p)->itemData)->heapId);
    buf=ARC_UTIL_LoadPaletteBlockFromHandle((void *)arc,116,(&data),(u16)(((((struct BagWork *)p)->itemData)->heapId&0x7fff)|0x8000));
    PALANM_CopyToSlot(((struct BagWork *)p)->palAnm,((struct BBagMainScreenData *)data)->data+128,3,128,32);
    GFL_HEAP_Free(buf);
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * matching: const indices restores the load/store scheduling; mutable indices differ in 29 bytes.
 */
struct ClactActor *B_BAG_MAIN_CreateItemActor(char *p,const int *indices)
{
    BBagMainConfig c;
    c.a=0;c.b=0;c.c=0;c.d=1;c.e=1;
    return CLACT_CreateActor((struct Unit *)(*(void **)&((struct BagWork *)p)->itemUnit),((struct BagWork *)p)->charHandles[indices[0]],((struct BagWork *)p)->paletteHandles[indices[1]],((struct BagWork *)p)->cellAnims[indices[2]],(const struct ActorInitParam *)&c,1,(((struct BagWork *)p)->itemData)->heapId);
}

/*
 * Raw byte stride i*12 emits muls rather than the flat word-index shift/add.
 * The caller stores live r0 from C3B4; its owner declaration is void.
 */
void B_BAG_MAIN_CreateItemActors(char *p) { u32 i; *(struct Unit * *)&((struct BagWork *)p)->itemUnit=CLACT_CreateUnit(67,0,(((struct BagWork *)p)->itemData)->heapId); for(i=0;i<63;i++) ((struct BagWork *)p)->itemActors[i]=B_BAG_MAIN_CreateItemActor(p,(const int *)((char *)d_0220DBBC+i*12)); }

void B_BAG_MAIN_DeleteItemGraphics(char *p)
{
    unsigned i;
    B_BAG_MAIN_DeleteFingerCursor(p);
    for (i = 0; i < 63; i++) CLACT_DeleteActor((struct ClactActor *)(((struct BagWork *)p)->itemActors[i]));
    B_BAG_MAIN_DeleteToolActors(p);
    for (i = 0; i < 9; i++) if (((struct BagWork *)p)->charHandles[i] != -1) CLACT_ReleaseCharacter(((struct BagWork *)p)->charHandles[i]);
    for (i = 0; i < 9; i++) if (((struct BagWork *)p)->paletteHandles[i] != -1) CLACT_ReleasePalette(((struct BagWork *)p)->paletteHandles[i]);
    for (i = 0; i < 3; i++) if (((struct BagWork *)p)->cellAnims[i] != -1) CLACT_ReleaseCellAnim(((struct BagWork *)p)->cellAnims[i]);
    CLACT_DeleteUnit(*(struct Unit * *)&((struct BagWork *)p)->itemUnit);
}

void B_BAG_MAIN_PlaceActor(struct ClactActor *a, struct ClactVec2 *b)
{
    CLACT_SetActorDrawEnable((struct ClactActor *)a, 1);
    CLACT_AddActorSurfacePos((struct ClactActor *)a, (struct ClactVec2 *)b, 1);
}

void B_BAG_MAIN_SetDisplayMode(char *p, int mode)
{
    unsigned int i;
    for (i = 0; i < 63; i++) CLACT_SetActorDrawEnable(((struct BagWork *)p)->itemActors[i], 0);
    B_BAG_MAIN_DeleteFingerCursorActor(p);
    switch (mode) {
    case 0: B_BAG_MAIN_DisplaySingle(p); break;
    case 1: B_BAG_MAIN_DisplayList(p); break;
    case 2: B_BAG_MAIN_DisplaySelected(p); break;
    }
}

void B_BAG_MAIN_DisplaySingle(char *p) { if(((struct BagWork *)p)->keyItem!=0) { B_BAG_MAIN_LoadItemGraphic(p,((struct BagWork *)p)->keyItem,6,6); B_BAG_MAIN_PlaceActor(((struct BagWork *)p)->itemActors[6],(struct ClactVec2 *)d_0220DB7C); } if((((struct BagWork *)p)->itemData)->mode==2) B_BAG_MAIN_StartFingerCursor((u8 *)p,192,24); }

void B_BAG_MAIN_DisplayList(char *p)
{
    unsigned i;
    for (i = 0; i < 6; i++) {
        u16 item = B_BAG_MAIN_GetSlotItem(p, i);
        if (item) {
            B_BAG_MAIN_LoadItemGraphic(p, item, i, i);
            B_BAG_MAIN_LoadItemPalette(p, item, i);
            B_BAG_MAIN_PlaceActor(((struct BagWork *)p)->itemActors[i], (struct ClactVec2 *)&d_0220DB88[i]);
            if ((((struct BagWork *)p)->itemData)->mode == 1)
                B_BAG_MAIN_DrawItemRow(p, i * 8 + 7, B_BAG_MAIN_GetItemFlag(item), 0, (const struct BBagMainPair *)(&d_0220DB88[i + 6]));
        }
    }
    if ((((struct BagWork *)p)->itemData)->mode == 1)
        B_BAG_MAIN_DrawItemRow(p, 55, (((struct BagWork *)p)->itemData)->count, (((struct BagWork *)p)->itemData)->maxCount, (const struct BBagMainPair *)(&d_0220DB88[i + 6]));
    if ((((struct BagWork *)p)->itemData)->mode == 2) B_BAG_MAIN_StartFingerCursor((u8 *)p, 64, 16);
}

/*
 * caller-width: BB98 takes full signed short promotion; no u16 truncation in this caller.
 */
void B_BAG_MAIN_DisplaySelected(char *p)
{
    u16 item = B_BAG_MAIN_GetSlotItem(p, ((struct BagWork *)p)->itemData->cursorX[((struct BagWork *)p)->pocket]);
    B_BAG_MAIN_LoadItemGraphic(p, item, 6, 6);
    B_BAG_MAIN_PlaceActor(((struct BagWork *)p)->itemActors[6], (struct ClactVec2 *)&d_0220DB80[0]);
    if ((((struct BagWork *)p)->itemData)->mode == 1)
        B_BAG_MAIN_DrawItemRow(p, 7, B_BAG_MAIN_GetItemFlag(item), 0, (const struct BBagMainPair *)(&d_0220DB80[1]));
    if ((((struct BagWork *)p)->itemData)->mode == 2) B_BAG_MAIN_StartFingerCursor((u8 *)p, 0x68, 0x98);
}

void B_BAG_MAIN_CreateToolActors(char *p){B_APP_TOOL_CreateActors(*(char * *)&((struct BagWork *)p)->toolActors,*(struct Unit **)&((struct BagWork *)p)->itemUnit,((struct BagWork *)p)->charHandles[8],((struct BagWork *)p)->paletteHandles[8],((struct BagWork *)p)->cellAnims[2]);B_APP_TOOL_SetActorsVisible(*(char * *)&((struct BagWork *)p)->toolActors,0);}

void B_BAG_MAIN_DeleteToolActors(char *a)
{
    B_APP_TOOL_DeleteActors((u8 *)(((struct BagWork *)a)->toolActors));
}

void B_BAG_MAIN_CreateFingerCursor(char *a)
{
    ((struct BagWork *)a)->fingerCursor = (void *)BTLV_FINGER_CURSOR_Create(*(void **)&((struct BagWork *)a)->palAnm, 9,
                                         ((struct BagMenu *)((struct BagWork *)a)->itemData)->heapId);
}

void B_BAG_MAIN_DeleteFingerCursor(char *a)
{
    BTLV_FINGER_CURSOR_Delete(((struct BagWork *)a)->fingerCursor);
}

void B_BAG_MAIN_StartFingerCursor(u8 *p, u32 a, u32 b)
{
    BTLV_FINGER_CURSOR_Start((struct BtlvFingerCursor *)((struct BagWork *)p)->fingerCursor, a, b, 2, 6, 0x14);
}

void B_BAG_MAIN_DeleteFingerCursorActor(char *a)
{
    BTLV_FINGER_CURSOR_DeleteActor(((struct BagWork *)a)->fingerCursor);
}

/*
 * matching: pair aggregate copy emits two unsigned halfword transfers;
 *   explicit objects base keeps the first indexed address split correctly.
 */
void B_BAG_MAIN_DrawItemRow(char *p,u16 slot,u8 a,u8 b,const struct BBagMainPair *src)
{
    struct BBagMainPair v;
    u16 i;
    s8 left,right;
    void **objects=(void **)(((void *)&((struct BagWork *)p)->itemActors));
    B_BAG_MAIN_PlaceActor(objects[slot],(struct ClactVec2 *)src);
    CLACT_SetActorAnimSeq(objects[slot],a);
    slot++;
    left=a;
    right=b;
    v=*src;
    v.x+=12;
    for(i=0;i<7;i++) {
        if(left<=0) {
            if(right<=0) CLACT_SetActorAnimSeq(((struct BagWork *)p)->itemActors[slot],15);
            else if(right==1) {CLACT_SetActorAnimSeq(((struct BagWork *)p)->itemActors[slot],19);right--;}
            else {CLACT_SetActorAnimSeq(((struct BagWork *)p)->itemActors[slot],20);right-=2;}
        } else if(left==1) {
            if(right==0) CLACT_SetActorAnimSeq(((struct BagWork *)p)->itemActors[slot],16);
            else if(right>0) {CLACT_SetActorAnimSeq(((struct BagWork *)p)->itemActors[slot],18);right--;}
            left--;
        } else {CLACT_SetActorAnimSeq(((struct BagWork *)p)->itemActors[slot],17);left-=2;}
        B_BAG_MAIN_PlaceActor(((struct BagWork *)p)->itemActors[slot],(struct ClactVec2 *)&v);
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
    int sz = sizeof(struct BagWork);
    p = GFL_HEAP_Alloc(((struct BagMenu *)arg)->heapId, sz, 1, d_0220E0E0, 0xB1);
    q = (unsigned char *)TCB_AddTask((struct TcbSystem *)BTLV_EFFECT_GetOwner(), B_BAG_MAIN_Main, p, 0x64);
    ((struct BagWork *)p)->itemData = (struct BagMenu *)arg;
    ((struct BagWork *)p)->palAnm = (void *)BTLV_EFFECT_GetPalanm();
    z = 0;
    ((struct BagWork *)p)->initialized = z;
    if (((struct BagWork *)p)->itemData->mode == 1) {
        ((struct BagWork *)p)->page = 1;
        ((struct BagWork *)p)->state = 1;
        ((struct BagWork *)p)->pocket = z;
    } else if (((struct BagWork *)p)->itemData->mode == 3) {
        ((struct BagWork *)p)->page = 1;
        ((struct BagWork *)p)->state = z;
        z = 2;
        ((struct BagWork *)p)->pocket = z;
    } else {
        ((struct BagWork *)p)->page = z;
        ((struct BagWork *)p)->state = z;
        ((struct BagWork *)p)->pocket = z;
    }
    if (((struct BagWork *)p)->itemData->mode != 1) {
        for (i = 0; i < 4; i++) {
            MYITEM_SAVEDATA_GetBattlePocketCursor(((struct BagWork *)p)->itemData->myItemSave, (u16)i, &((struct BagWork *)p)->itemData->cursorX[i], &((struct BagWork *)p)->itemData->cursorY[i]);
        }
        ((struct BagWork *)p)->keyItem = MYITEM_SAVEDATA_GetLastBattleItem(((struct BagWork *)p)->itemData->myItemSave);
        ((struct BagWork *)p)->keyItemSlot = MYITEM_SAVEDATA_GetLastBattleItemPocket(((struct BagWork *)p)->itemData->myItemSave);
        B_BAG_MAIN_CheckKeyItem((char *)p);
    } else {
        for (i = 0; i < 4; i++) {
            ((struct BagWork *)p)->itemData->cursorX[i] = 0;
            ((struct BagWork *)p)->itemData->cursorY[i] = 0;
        }
    }
}

extern int (*const d_0220DF40[])(char *);

void B_BAG_MAIN_Main(struct TcbTask *task, void *arg)
{
    char *p = arg;
    if ((((struct BagWork *)p)->itemData)->instant == 1) {
        (((struct BagWork *)p)->itemData)->itemId = 0;
        (((struct BagWork *)p)->itemData)->itemFlag = 0;
        ((struct BagWork *)p)->state = 20;
    }
    if (((struct BagWork *)p)->state != 20) ((struct BagWork *)p)->state = d_0220DF40[((struct BagWork *)p)->state](p);
    if (((struct BagWork *)p)->state == 20 && B_BAG_MAIN_StateExit(task, p) == 1) return;
    TCBL_Main((struct TcblSystem *)(*(struct Tcbl * *)&((struct BagWork *)p)->tcbl));
    B_BAG_MAIN_StepFrameAnim(p);
    BGWINFRM_UpdateMoves((struct BgWinFrmWork *)(*(struct WinMgr * *)&((struct BagWork *)p)->frameMgr));
    B_BAG_MAIN_UpdateTool(p);
}

/*
 * lever: word-address arithmetic reuses the MMIO pool base, as in matched ov197 0220CAAC.
 */
int B_BAG_MAIN_StateInit(char *p)
{
    d_04001050[0]=0;
    GXx_SetMasterBrightness_((u16 *)((char *)d_04001050+0x1c),-16);
    ((struct BagWork *)p)->tcbl=TCBL_Create((((struct BagWork *)p)->itemData)->heapId,(((struct BagWork *)p)->itemData)->heapId,1,4);
    ((struct BagWork *)p)->toolActors=B_APP_TOOL_Create((((struct BagWork *)p)->itemData)->heapId);
    B_BAG_MAIN_InitBg(p);
    B_BAG_MAIN_LoadBgGraphics(p);
    B_BAG_MAIN_CreateText(p);
    if((((struct BagWork *)p)->itemData)->mode==2) B_BAG_MAIN_InitOtherPage(p);
    else B_BAG_MAIN_BuildPocketLists((u8 *)p);
    B_BAG_MAIN_InitWindows(p);
    B_BAG_MAIN_DrawPage(p,((struct BagWork *)p)->page);
    B_BAG_MAIN_ShowWindows((u8 *)p);
    B_BAG_MAIN_InitFrames(p);
    B_BAG_MAIN_LayoutFrames(p,((struct BagWork *)p)->page);
    B_BAG_MAIN_CreateItemGraphics(p);
    B_BAG_MAIN_SetDisplayMode(p,((struct BagWork *)p)->page);
    if(**(u8 * *)&(((struct BagWork *)p)->itemData)->dirtyPtr==1) ((struct BagWork *)p)->actorsVisible=1;
    else ((struct BagWork *)p)->actorsVisible=0;
    B_APP_TOOL_SetActorsVisible(*(char * *)&((struct BagWork *)p)->toolActors,((struct BagWork *)p)->actorsVisible);
    if(((struct BagWork *)p)->page==0) B_BAG_MAIN_CreateCursor((u8 *)p,((struct BagWork *)p)->page,((struct BagWork *)p)->keyItemSlot);
    else B_BAG_MAIN_CreateCursor((u8 *)p,((struct BagWork *)p)->page,0);
    GFL_NET_RefreshWmIconAtTopRight(0,(((struct BagWork *)p)->itemData)->heapId);
    PALANM_CopyHwPaletteToSlot(((struct BagWork *)p)->palAnm,3,224,32);
    PALANM_RequestFade(((struct BagWork *)p)->palAnm,10,65535,0,16,0,0,BTLV_EFFECT_GetOwner());
    if((((struct BagWork *)p)->itemData)->mode==3) B_BAG_MAIN_ResetBgSlot(p,((struct BagWork *)p)->page);
    ((struct BagWork *)p)->initialized=1;
    return 2;
}

/*
 * lever: word-address arithmetic reuses MMIO pool base for +0x1c; typed pointer addition pools a second word.
 */
int B_BAG_MAIN_StateInitOther(char *p)
{
    d_04001050[0] = 0;
    GXx_SetMasterBrightness_((u16 *)((char *)d_04001050 + 0x1c), -16);
    ((struct BagWork *)p)->tcbl = TCBL_Create((((struct BagWork *)p)->itemData)->heapId, (((struct BagWork *)p)->itemData)->heapId, 1, 4);
    ((struct BagWork *)p)->toolActors = B_APP_TOOL_Create((((struct BagWork *)p)->itemData)->heapId);
    B_BAG_MAIN_InitBg(p);
    B_BAG_MAIN_LoadBgGraphics(p);
    B_BAG_MAIN_CreateText(p);
    B_BAG_MAIN_BuildOtherList(p);
    B_BAG_MAIN_ResetBgSlot(p, ((struct BagWork *)p)->page);
    B_BAG_MAIN_InitWindows(p);
    B_BAG_MAIN_DrawPage(p, ((struct BagWork *)p)->page);
    B_BAG_MAIN_ShowWindows((u8 *)p);
    B_BAG_MAIN_InitFrames(p);
    B_BAG_MAIN_LayoutFrames(p, ((struct BagWork *)p)->page);
    B_BAG_MAIN_CreateItemGraphics(p);
    B_BAG_MAIN_SetDisplayMode(p, ((struct BagWork *)p)->page);
    if (**(u8 * *)&(((struct BagWork *)p)->itemData)->dirtyPtr == 1) ((struct BagWork *)p)->actorsVisible = 1;
    else ((struct BagWork *)p)->actorsVisible = 0;
    B_APP_TOOL_SetActorsVisible(*(char * *)&((struct BagWork *)p)->toolActors, ((struct BagWork *)p)->actorsVisible);
    B_BAG_MAIN_CreateCursor((u8 *)p, ((struct BagWork *)p)->page, 0);
    GFL_NET_RefreshWmIconAtTopRight(0, (((struct BagWork *)p)->itemData)->heapId);
    PALANM_CopyHwPaletteToSlot(((struct BagWork *)p)->palAnm, 3, 0xe0, 0x20);
    PALANM_RequestFade(((struct BagWork *)p)->palAnm, 0xa, 0xffff, 0, 0x10, 0, 0, BTLV_EFFECT_GetOwner());
    ((struct BagWork *)p)->initialized = 1;
    return 2;
}

int B_BAG_MAIN_StateWaitPrintWipe(char *p){if(PRINTSYS_QUE_IsFinished((struct PrintQueue *)(*(struct PrintSys * *)&((struct BagWork *)p)->printSys))==1){WIPE_SYS_Start((void *)4,1,1,0,6,1,(((struct BagWork *)p)->itemData)->heapId);return 3;}return 2;}

int B_BAG_MAIN_StateWipeEnd(char *p){if(WIPE_SYS_EndCheck()==1){if((((struct BagWork *)p)->itemData)->mode==2)return 17;if((((struct BagWork *)p)->itemData)->mode==1)return 5;if((((struct BagWork *)p)->itemData)->mode==3)return 5;return 4;}return 3;}

int B_BAG_MAIN_StateSelectPocket(char *p)
{
    unsigned sel;
    if (PALANM_GetFadeRequestBits(((struct BagWork *)p)->palAnm) != 0) goto done;
    if (B_BAG_MAIN_CheckCancel((char **)p) == 1) return 0x12;
    sel = CURSOR_MOVE_PollRepeatInput(((struct BagWork *)p)->cursor);
    switch (sel) {
    case 0: case 1: case 2: case 3:
        B_BAG_MAIN_PlaySe((char **)p, 0x54d);
        ((struct BagWork *)p)->pocket = (u8)sel;
        ((struct BagWork *)p)->nextState = 8;
        B_BAG_MAIN_StartFrameAnim(p, (u8)sel);
        return 0x10;
    case 4:
        if (((struct BagWork *)p)->keyItem != 0) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            ((struct BagWork *)p)->pocket = ((struct BagWork *)p)->keyItemSlot;
            ((struct BagWork *)p)->nextState = 9;
            B_BAG_MAIN_SyncCursorToItem((u8 *)p);
            B_BAG_MAIN_StartFrameAnim(p, 0xd);
            return 0x10;
        }
        break;
    case 5:
        B_BAG_MAIN_PlaySe((char **)p, 0x552);
        (((struct BagWork *)p)->itemData)->itemId = 0;
        (((struct BagWork *)p)->itemData)->slot = 4;
        B_BAG_MAIN_StartFrameAnim(p, 0xa);
        return 0x12;
    case (unsigned)-2:
        B_BAG_MAIN_PlaySe((char **)p, 0x552);
        (((struct BagWork *)p)->itemData)->itemId = 0;
        (((struct BagWork *)p)->itemData)->slot = 4;
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
            ((struct BagWork *)p)->itemData->cursorX[((struct BagWork *)p)->pocket] = (u8)sel;
            ((struct BagWork *)p)->nextState = 9;
            B_BAG_MAIN_StartFrameAnim(p, (u8)(sel + 4));
            return 0x10;
        }
        break;
    case 6:
        B_BAG_MAIN_PlaySe((char **)p, 0x552);
        B_BAG_MAIN_StartFrameAnim(p, 0xa);
        if ((((struct BagWork *)p)->itemData)->mode == 1 || (((struct BagWork *)p)->itemData)->mode == 3) {
            (((struct BagWork *)p)->itemData)->itemId = 0;
            (((struct BagWork *)p)->itemData)->slot = 4;
            return 0x12;
        }
        ((struct BagWork *)p)->nextState = 7;
        return 0x10;
    case (unsigned)-2:
        B_BAG_MAIN_PlaySe((char **)p, 0x552);
        B_BAG_MAIN_StartFrameAnim(p, 0xa);
        if ((((struct BagWork *)p)->itemData)->mode == 1 || (((struct BagWork *)p)->itemData)->mode == 3) {
            (((struct BagWork *)p)->itemData)->itemId = 0;
            (((struct BagWork *)p)->itemData)->slot = 4;
            return 0x12;
        }
        ((struct BagWork *)p)->nextState = 7;
        return 0x10;
    case 7:
        if (((struct BagWork *)p)->pagePerPocket[((struct BagWork *)p)->pocket] != 0) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            ((struct BagWork *)p)->itemData->cursorX[((struct BagWork *)p)->pocket] = 0;
            ((struct BagWork *)p)->nextState = 0xb;
            *(signed char *)&((struct BagWork *)p)->countDelta = -1;
            B_BAG_MAIN_StartFrameAnim(p, 0xb);
            return 0x10;
        }
        break;
    case 8:
        if (((struct BagWork *)p)->pagePerPocket[((struct BagWork *)p)->pocket] != 0) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            ((struct BagWork *)p)->itemData->cursorX[((struct BagWork *)p)->pocket] = 0;
            ((struct BagWork *)p)->nextState = 0xb;
            ((struct BagWork *)p)->countDelta = 1;
            B_BAG_MAIN_StartFrameAnim(p, 0xc);
            return 0x10;
        }
        break;
    case (unsigned)-4: case (unsigned)-3:
        B_BAG_MAIN_PlaySe((char **)p, 0x548);
        break;
    case (unsigned)-6:
        CURSOR_MOVE_GetCurrent(((struct BagWork *)p)->cursor);
        if (((struct BagWork *)p)->pagePerPocket[((struct BagWork *)p)->pocket] != 0) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            ((struct BagWork *)p)->nextState = 0xb;
            *(signed char *)&((struct BagWork *)p)->countDelta = -1;
            B_BAG_MAIN_StartFrameAnim(p, 0xb);
            return 0x10;
        }
        break;
    case (unsigned)-5:
        CURSOR_MOVE_GetCurrent(((struct BagWork *)p)->cursor);
        if (((struct BagWork *)p)->pagePerPocket[((struct BagWork *)p)->pocket] != 0) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            ((struct BagWork *)p)->nextState = 0xb;
            ((struct BagWork *)p)->countDelta = 1;
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
    unsigned index = ((struct BagWork *)p)->pocket;
    short *values = ((struct BagWork *)p)->itemData->cursorY;
    s8 value = (s8)values[index];
    u8 maximum;
    value += ((struct BagWork *)p)->countDelta;
    maximum = ((struct BagWork *)p)->pagePerPocket[index];
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

int B_BAG_MAIN_StateWaitPrintRedraw(char *p){if(PRINTSYS_QUE_IsFinished((struct PrintQueue *)(*(struct PrintSys * *)&((struct BagWork *)p)->printSys))==1){B_BAG_MAIN_ShowWindows((unsigned char *)p);B_BAG_MAIN_SetDisplayMode(p,((struct BagWork *)p)->page);B_BAG_MAIN_LayoutFrames(p,((struct BagWork *)p)->page);return 5;}return 12;}

int B_BAG_MAIN_StateChooseItem(char *p)
{
    if (B_BAG_MAIN_CheckCancel((char **)p) == 1) return 0x12;
    switch ((unsigned)CURSOR_MOVE_PollRepeatInput(((struct BagWork *)p)->cursor)) {
    case 0:
        B_BAG_MAIN_PlaySe((char **)p, 0x54d);
        (((struct BagWork *)p)->itemData)->itemId = B_BAG_MAIN_GetSlotItem(p, ((struct BagWork *)p)->itemData->cursorX[((struct BagWork *)p)->pocket]);
        (((struct BagWork *)p)->itemData)->slot = ((struct BagWork *)p)->pocket;
        if ((((struct BagWork *)p)->itemData)->mode == 1)
            (((struct BagWork *)p)->itemData)->itemFlag = B_BAG_MAIN_GetItemFlag((((struct BagWork *)p)->itemData)->itemId);
        else
            (((struct BagWork *)p)->itemData)->itemFlag = 0;
        B_BAG_MAIN_StartFrameAnim(p, 0xd);
        return B_BAG_MAIN_StateShowMessage(p);
    case 1:
        B_BAG_MAIN_PlaySe((char **)p, 0x552);
        ((struct BagWork *)p)->nextState = 8;
        B_BAG_MAIN_StartFrameAnim(p, 0xa);
        return 0x10;
    case (unsigned)-2:
        B_BAG_MAIN_PlaySe((char **)p, 0x552);
        ((struct BagWork *)p)->nextState = 8;
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
 * below copied from POKE_SUMMARY_MAIN_DrawMoveDetail.c, prior ov070 fixed-flag --arm one.
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
 * extern void GFL_HEAP_Free(void *);
 * extern void ARC_TOOL_ReadHandle(void *,u32,void *);
 * extern void ARC_TOOL_SeekHandle(void *,u32);
 * extern void STRBUF_Clear(void *);
 * extern void STRBUF_SetChars(void *,const void *,u16);
 * extern void MSGDATA_DecryptStrbuf(void *,u32);
 * extern void MSGDATA_RefreshLanguage(struct MsgBank *);
 * void MSGDATA_ReadString(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *     MSGDATA_RefreshLanguage(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         ARC_TOOL_SeekHandle(bank->stream,pos + (index * 8 + 4));
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
 *             ARC_TOOL_SeekHandle(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream,size,buf);
 *             STRBUF_SetChars(dest,buf,e->len);
 *             GFL_HEAP_Free(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     MSGDATA_DecryptStrbuf(dest,index);
 * }
 */
int B_BAG_MAIN_StateShowMessage(char *p)
{
    struct BagMenu *q = ((struct BagWork *)p)->itemData;
    if (q->mode == 1 && q->count < B_BAG_MAIN_GetItemFlag(q->itemId)) {
        MSGDATA_ReadString(((struct BagWork *)p)->msgBank, 0x31, ((struct BagWork *)p)->strBuf);
        B_BAG_MAIN_PrintItemMsg(p);
        ((struct BagWork *)p)->nextState = 0xd;
        return 0xe;
    }
    if (((struct BagWork *)p)->pocket == 2) {
        if (q->kind == 1) {
            MSGDATA_ReadString(((struct BagWork *)p)->msgBank, 0x2d, ((struct BagWork *)p)->strBuf);
            B_BAG_MAIN_PrintItemMsg(p);
            ((struct BagWork *)p)->nextState = 0xd;
            return 0xe;
        }
        if (q->kind == 2) {
            MSGDATA_ReadString(((struct BagWork *)p)->msgBank, 0x2c, ((struct BagWork *)p)->strBuf);
            B_BAG_MAIN_PrintItemMsg(p);
            ((struct BagWork *)p)->nextState = 0xd;
            return 0xe;
        }
        if (q->kind == 3) {
            MSGDATA_ReadString(((struct BagWork *)p)->msgBank, 0x33, ((struct BagWork *)p)->strBuf);
            B_BAG_MAIN_PrintItemMsg(p);
            ((struct BagWork *)p)->nextState = 0xd;
            return 0xe;
        }
        if (q->kind == 4) {
            MSGDATA_ReadString(((struct BagWork *)p)->msgBank, 0x2f, ((struct BagWork *)p)->strBuf);
            B_BAG_MAIN_PrintItemMsg(p);
            ((struct BagWork *)p)->nextState = 0xd;
            return 0xe;
        }
    }
    if (q->flag29 == 0 && FILE_UTIL_GetItemParam((unsigned int)(unsigned)q->itemId, 7, q->heapId) == 3) {
        MSGDATA_ReadString(((struct BagWork *)p)->msgBank, 0x32, ((struct BagWork *)p)->strBuf);
        B_BAG_MAIN_PrintItemMsg(p);
        ((struct BagWork *)p)->nextState = 0xd;
        return 0xe;
    }
    return 0x12;
}

int B_BAG_MAIN_StateShowPocket0(char *p){B_BAG_MAIN_DrawPage(p,0);((struct BagWork *)p)->page=0;((struct BagWork *)p)->nextState=4;return 10;}

int B_BAG_MAIN_StateShowPocket1(char *p){B_BAG_MAIN_DrawPage(p,1);((struct BagWork *)p)->page=1;((struct BagWork *)p)->nextState=5;return 10;}

int B_BAG_MAIN_StateShowPocket2(char *p){B_BAG_MAIN_DrawPage(p,2);((struct BagWork *)p)->page=2;((struct BagWork *)p)->nextState=6;return 10;}

int B_BAG_MAIN_StateWaitPrintSetMode(char *p){if(PRINTSYS_QUE_IsFinished((struct PrintQueue *)(*(struct PrintSys * *)&((struct BagWork *)p)->printSys))==1){B_BAG_MAIN_SwitchPage(p,((struct BagWork *)p)->page);return ((struct BagWork *)p)->nextState;}return 10;}

int B_BAG_MAIN_StateStartMessage(char *a)
{
    BMP_MENUWORK_DrawWindowBorder((void *)(((struct BagWork *)a)->itemMsgWin), 0);
    return 6;
}

int B_BAG_MAIN_StateMessageInput(char *p)
{
    switch (PRINTSYS_PrintStreamGetState((struct TextPrinter *)(*(struct Rec * *)&((struct BagWork *)p)->printStream))) {
    case 0:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetCont() & 3)) PRINTSYS_PrintStreamShortWait((struct TextPrinter *)(*(struct Rec * *)&((struct BagWork *)p)->printStream), 0);
        ((struct BagWork *)p)->msgInputFlag = 0;
        break;
    case 1:
        if (!((struct BagWork *)p)->msgInputFlag && (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3))) {
            B_BAG_MAIN_PlaySe2((char **)p, 0x547);
            PRINTSYS_PrintStreamReleasePause((struct TextPrinter *)(*(struct Rec * *)&((struct BagWork *)p)->printStream));
            ((struct BagWork *)p)->msgInputFlag = 1;
        }
        break;
    case 2:
        PRINTSYS_PrintStreamDelete((struct TextPrinter *)(*(struct Rec3 * *)&((struct BagWork *)p)->printStream));
        *(int *)&((struct BagWork *)p)->printStream = 0;
        ((struct BagWork *)p)->msgInputFlag = 0;
        return 15;
    }
    return 14;
}

/*
 * trailing: larger follower filed as B_BAG_MAIN_StateWaitKey.c (parent cleared).
 */
int B_BAG_MAIN_StateMessageDone(char *p)
{
    if (B_BAG_MAIN_CheckCancel((char **)p) == 1) return 18;
    if ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg() == 1)
        return ((struct BagWork *)p)->nextState;
    return 15;
}

/*
 * lever: explicit else preserves the nonzero arm after the field-return arm.
 * leaf: parent-cleared 24-byte follower in D328 extent.
 */
int B_BAG_MAIN_StateWaitKey(char *p)
{
    if (((struct BagWork *)p)->animActive == 0) {
        return ((struct BagWork *)p)->nextState;
    } else {
        return 16;
    }
}

int B_BAG_MAIN_StateFadeOut(char *p){PALANM_RequestFade((struct PaletteFade *)(const struct PaletteFade *)(struct PaletteFade *)*(PalAnmObj * *)&((struct BagWork *)p)->palAnm,10,65535,0,0,16,0,BTLV_EFFECT_GetOwner());return 19;}

int B_BAG_MAIN_StateWaitFade(char *a)
{
    if (PALANM_GetFadeRequestBits((const struct PaletteFade *)(const char *)(((struct BagWork *)a)->palAnm)) == 0)
        return 0x14;
    return 0x13;
}

/*
 * lever: explicit if/else field stores preserve one-first branch and shared store.
 */
int B_BAG_MAIN_StateExit(struct TcbTask *task, char *p)
{
    if (((struct BagWork *)p)->initialized == 1) {
        if (PRINTSYS_QUE_IsFinished((struct PrintQueue *)(*(struct PrintSys * *)&((struct BagWork *)p)->printSys)) == 0) {
            if ((((struct BagWork *)p)->itemData)->instant == 1) PRINTSYS_QUE_Clear((struct PrintQueue *)(*(struct PrintSys * *)&((struct BagWork *)p)->printSys));
            else return 0;
        }
        if (WIPE_SYS_EndCheck() == 0) {
            if ((((struct BagWork *)p)->itemData)->instant == 1) WIPE_SYS_ExeEnd();
            else return 0;
        }
        if (*(struct Rec3 * *)&((struct BagWork *)p)->printStream) PRINTSYS_PrintStreamDelete((struct TextPrinter *)(*(struct Rec3 * *)&((struct BagWork *)p)->printStream));
        B_BAG_MAIN_DeleteFrames(p);
        B_BAG_MAIN_DeleteItemGraphics(p);
        B_BAG_MAIN_ExitWindows(p);
        B_BAG_MAIN_DeleteText(p);
        B_BAG_MAIN_ExitBg();
        TCBL_Destroy((struct TcblSystem *)(*(struct S02031140 * *)&((struct BagWork *)p)->tcbl));
        B_BAG_MAIN_DeleteCursor((u8 *)p);
        B_APP_TOOL_Delete(((struct BagWork *)p)->toolActors);
        if (((struct BagWork *)p)->actorsVisible == 1) {
            **(u8 * *)&(((struct BagWork *)p)->itemData)->dirtyPtr = 1;
        } else {
            **(u8 * *)&(((struct BagWork *)p)->itemData)->dirtyPtr = 0;
        }
    }
    (((struct BagWork *)p)->itemData)->done = 1;
    TCB_DeleteTask((struct TcbTask *)task);
    GFL_HEAP_Free(p);
    return 1;
}

int B_BAG_MAIN_StateOtherFlow(char *p)
{
    switch (((struct BagWork *)p)->otherStep) {
    case 0:
        if (BTLV_FINGER_CURSOR_IsActive(((struct BagWork *)p)->fingerCursor) == 1) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            ((struct BagWork *)p)->pocket = 2;
            ((struct BagWork *)p)->nextState = 0x11;
            B_BAG_MAIN_StartFrameAnim(p, 2);
            ++((struct BagWork *)p)->otherStep;
            return 0x10;
        }
        break;
    case 1:
        if (BTLV_FINGER_CURSOR_IsActive(((struct BagWork *)p)->fingerCursor) == 0) {
            B_BAG_MAIN_StateShowPocket1(p);
            ++((struct BagWork *)p)->otherStep;
            ((struct BagWork *)p)->nextState = 0x11;
            return 0xa;
        }
        break;
    case 2:
        if (BTLV_FINGER_CURSOR_IsActive(((struct BagWork *)p)->fingerCursor) == 1) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            ((struct BagWork *)p)->itemData->cursorX[((struct BagWork *)p)->pocket] = 0;
            ((struct BagWork *)p)->nextState = 0x11;
            B_BAG_MAIN_StartFrameAnim(p, 4);
            ++((struct BagWork *)p)->otherStep;
            return 0x10;
        }
        break;
    case 3:
        if (BTLV_FINGER_CURSOR_IsActive(((struct BagWork *)p)->fingerCursor) == 0) {
            B_BAG_MAIN_StateShowPocket2(p);
            ++((struct BagWork *)p)->otherStep;
            ((struct BagWork *)p)->nextState = 0x11;
            return 0xa;
        }
        break;
    case 4:
        if (BTLV_FINGER_CURSOR_IsActive(((struct BagWork *)p)->fingerCursor) == 1) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            (((struct BagWork *)p)->itemData)->itemId = B_BAG_MAIN_GetSlotItem(p, ((struct BagWork *)p)->itemData->cursorX[((struct BagWork *)p)->pocket]);
            (((struct BagWork *)p)->itemData)->slot = ((struct BagWork *)p)->pocket;
            (((struct BagWork *)p)->itemData)->itemFlag = 0;
            B_BAG_MAIN_StartFrameAnim(p, 0xd);
            ++((struct BagWork *)p)->otherStep;
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
 struct DispConfig req=d_0220DEB0;
 struct BgTemplate b7,b6,b5,b4;
 BG_SYS_ApplyGraphicsMode(&req,1);
 b7=d_0220DEE0;BG_SYS_InitBgLayer(7,&b7,0);
 b6=d_0220DF20;BG_SYS_InitBgLayer(6,&b6,0);
 b5=d_0220DF00;BG_SYS_InitBgLayer(5,&b5,0);BG_SYS_ClearSlot(5);
 b4=d_0220DEC0;BG_SYS_InitBgLayer(4,&b4,0);BG_SYS_ClearSlot(4);
 BG_SYS_InitRun(5,32,0,(((struct BagWork *)p)->itemData)->heapId);
 BG_SYS_InitRun(4,32,0,(((struct BagWork *)p)->itemData)->heapId);
 BG_SYS_MarkTileDirty(5);BG_SYS_MarkTileDirty(4);BG_SYS_SetSubPlaneVisible(15,1);
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
    void *handle = ARC_TOOL_CreateHandle(99,(u16)(((((struct BagWork *)p)->itemData)->heapId & 0x7fff) | 0x8000));
    ARC_UTIL_UploadBgCharFromHandle(handle, 0, 6, 0, 0, 1, (((struct BagWork *)p)->itemData)->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(handle, 3, 6, 0, 0, 1, (((struct BagWork *)p)->itemData)->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(handle, 2, 7, 0, 0, 1, (((struct BagWork *)p)->itemData)->heapId);
    PALANM_LoadHandlePaletteToSlot(*(struct PaletteFade * *)&((struct BagWork *)p)->palAnm, (void *)(handle), 1, (((struct BagWork *)p)->itemData)->heapId, 1, 224, 0);
    ARC_TOOL_DeleteHandle(handle);
    BMP_MENUWORK_LoadCharAndPltt(4, 1, 11, 0, (((struct BagWork *)p)->itemData)->heapId);
    PALANM_CopyHwPaletteToSlot(*(struct PaletteFade * *)&((struct BagWork *)p)->palAnm, 1, 176, 32);
    PALANM_LoadArcPaletteToSlot(*(struct PaletteFade * *)&((struct BagWork *)p)->palAnm, 23, 5, (((struct BagWork *)p)->itemData)->heapId, 1, 32, 192);
}

void B_BAG_MAIN_CreateText(char *p){*(struct MsgBank * *)&((struct BagWork *)p)->msgBank=MSGDATA_CreateFromArchive(0,2,17,(((struct BagWork *)p)->itemData)->heapId);*(struct WordSet * *)&((struct BagWork *)p)->wordSet=WORDSET_CreateDefault((((struct BagWork *)p)->itemData)->heapId);((struct BagWork *)p)->printSys=(void *)PRINTSYS_QUE_Create((unsigned int)(((struct BagWork *)p)->itemData)->heapId);*(struct U16Vec * *)&((struct BagWork *)p)->strBuf=(struct U16Vec *)STRBUF_Create((unsigned int)512,(unsigned int)((((struct BagWork *)p)->itemData)->heapId));}

/*
 * Tail: two zero alignment bytes at 0x0220D7EE.
 */
void B_BAG_MAIN_DeleteText(char *p){MSGDATA_Delete(((struct BagWork *)p)->msgBank);WORDSET_Delete(*(struct WordSet * *)&((struct BagWork *)p)->wordSet);PRINTSYS_QUE_Delete((struct PrintQueue *)(*(struct PrintSys * *)&((struct BagWork *)p)->printSys));STRBUF_Delete(((struct BagWork *)p)->strBuf);}

/*
 * trailing: 2 zero alignment bytes at 0x0220D846.
 */
void B_BAG_MAIN_ResetBgSlot(void *unused, int mode)
{
    switch (mode) {
    case 0:
        BG_SYS_ChangeScroll(6, 0, 0);
        BG_SYS_ChangeScroll(6, 3, 0);
        break;
    case 1:
        BG_SYS_ChangeScroll(6, 0, 256);
        BG_SYS_ChangeScroll(6, 3, 0);
        break;
    case 2:
        BG_SYS_ChangeScroll(6, 0, 0);
        BG_SYS_ChangeScroll(6, 3, 256);
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
    *(struct CursorMove * *)&((struct BagWork *)p)->cursor = (struct CursorMove *)CURSOR_MOVE_Create(d_0220DF9C[index], d_0220DF90[index], p, ((struct BagWork *)p)->actorsVisible, (u8)value, (((struct BagWork *)p)->itemData)->heapId);
    CURSOR_MOVE_EnableInput((struct Cursor *)(*(struct CursorMove * *)&((struct BagWork *)p)->cursor));
    CURSOR_MOVE_SetMode((struct Cursor *)(*(struct CursorMove * *)&((struct BagWork *)p)->cursor));
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
    switch (((struct BagWork *)p)->actorsVisible) {
    case 0: value = 0; break;
    default:
        switch (state) {
        case 0: value = ((struct BagWork *)p)->pocket; break;
        case 1: value = ((struct BagWork *)p)->itemData->cursorX[((struct BagWork *)p)->pocket]; break;
        case 2: value = 0; break;
        }
        break;
    }
    B_BAG_MAIN_DeleteCursor(p);
    B_BAG_MAIN_CreateCursor(p, state, value);
}

void B_BAG_MAIN_SetCursorVisible(char *a, int b)
{
    ((struct BagWork *)a)->actorsVisible = b;
    B_APP_TOOL_SetActorsVisible(*(char **)&((struct BagWork *)a)->toolActors, b);
}

void B_BAG_MAIN_LayoutCursor(u8 *p, u32 idx)
{
    void *t = CURSOR_MOVE_GetEntry((struct Cursor *)(*(void ** *)&((struct BagWork *)p)->cursor), idx);

    B_APP_TOOL_LayoutActors((struct ClactActor **)(((struct BagWork *)p)->toolActors), (u8 *)(t));
}

void B_BAG_MAIN_ShowCursorAt(u8 *p,u32 i){B_BAG_MAIN_LayoutCursor(p,i);B_BAG_MAIN_SetCursorVisible((char *)p,1);}

void B_BAG_MAIN_HideCursor(char *p){B_BAG_MAIN_SetCursorVisible(p,0);}

void B_BAG_MAIN_HideCursor2(char *p){B_BAG_MAIN_SetCursorVisible(p,0);}

void B_BAG_MAIN_LayoutCursorOnly(u8 *p,u32 i){B_BAG_MAIN_LayoutCursor(p,i);}

void B_BAG_MAIN_HandleSelection(char *p, int b)
{
    if ((unsigned int)(b - 7) <= 1) {
        CURSOR_MOVE_SetCurrent(*(struct Cursor **)&((struct BagWork *)p)->cursor, 0);
        b = 0;
    }
    B_BAG_MAIN_LayoutCursor((u8 *)p, b);
    B_BAG_MAIN_SetCursorVisible(p, 1);
}
