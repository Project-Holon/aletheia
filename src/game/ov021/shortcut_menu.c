/*
 * file:     shortcut_menu.c
 * unit:     yes
 * function: SHORTCUT_MENU_Create, SHORTCUT_MENU_Delete, SHORTCUT_MENU_Main, SHORTCUT_MENU_RunPrint, SHORTCUT_MENU_Start, SHORTCUT_MENU_RequestClose, SHORTCUT_MENU_IsWaitingInput, SHORTCUT_MENU_GetResult, SHORTCUT_MENU_InitList, SHORTCUT_MENU_FreeList, SHORTCUT_MENU_OnKeyUp, SHORTCUT_MENU_OnKeyDown, SHORTCUT_MENU_UpdateInput, SHORTCUT_MENU_FinishPrint, SHORTCUT_MENU_GetSelection, SHORTCUT_MENU_ListMoveCallback, SHORTCUT_MENU_UpdateCursorBg, SHORTCUT_MENU_ClampListWindow, SHORTCUT_MENU_CreateList, SHORTCUT_MENU_DeleteList, SHORTCUT_MENU_ScrollStep, SHORTCUT_MENU_SetActorsY
 * address:  0x021C4F7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldeff_splash.c at 0x021C4F7C (lane FXC, CL129: allocation with the shortcut_menu.c file string at 021C4F7C).
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   BG_SYS_Init  0x02040C14  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole  0x02049B68  arm
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PRINTSYS_QUE_CreateEx  0x0201C450  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   RECENT_ID_LIST_SAVEDATA_GetBlock  0x0200C40C  thumb
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   G2x_SetBlendAlpha_  0x0207D63C  arm
 *   BG_SYS_ChangeScrollImmediate  0x02040618  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   gShortcutMenuFileName     0x021DE498  data  ov021  a1
 *   gShortcutMenuBgTemplate     0x021DAA60  data  a4
 *   gShortcutMenuActorX     0x021DAA54  data  a4
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   BG_SYS_FreeTiles  0x02040DA8  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_MENULIST_GetPos  0x020202FC  thumb
 *   BMP_MENULIST_GetRowY  0x02020324  thumb
 *   UI_SetInputMode 0x020355D8 arm
 *   BMP_MENULIST_GetListIndex 0x020202EC thumb
 *   BMP_MENULIST_GetAttr 0x02020350 thumb
 *   KEY_GetRepeat 0x0203633C arm
 *   KEY_GetTrg 0x020362DC arm
 *   BMP_MENULIST_Main 0x020200CC thumb
 *   BMP_MENULIST_GetItemValue 0x02020344 thumb
 *   RECENT_ID_LIST_SAVEDATA_InsertId 0x0200C480 thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_MENULIST_GetCursorY 0x02020314 thumb
 *   RECENT_ID_LIST_SAVEDATA_CountIds 0x0200C468 thumb
 *   RECENT_ID_LIST_SAVEDATA_GetIdAt 0x0200C464 thumb
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   BMP_MENULIST_Create 0x0201FF30 thumb
 *   gShortcutMenuListTemplate    0x021DAA80 data  a4
 *   BMP_MENULIST_Delete  0x0202020C  thumb
 *   BMP_MENUWORK_Delete  0x0201F868  thumb
 *   abs_id_C2      0x000000C2  data
 *   ov171_id       0x000000AB  data  a1
 *   CLACT_GetActorSurfacePos  0x0204B454  arm  arm9
 *   CLACT_AddActorSurfacePos  0x0204B404  arm  arm9
 */
#include "field_effect_types.h"
#include "../sdk_ioreg.h"
#include "../ov010/fldmmdl_types.h"

struct BbActDesc;
struct BbActSys;
struct BbActRec;
#include "../arm9/billboard_act_types.h"
struct Actor;
struct IcaAnime;
struct Rec12;
struct Mtx33;
struct Big;
struct BgTemplate;
struct Bank;
struct GfFont;
struct MsgBank;
struct BmpMenuList;
struct PrintSys;
struct Rec;
struct Node;
struct Descriptor;
struct Cfg;
struct Slot;
struct MenuTemplate;
struct PtS;
struct Vec2;
struct Desc;
struct Evt;
struct BigObj;
struct Ctx;
struct Sub02008C20Obj;
struct Self;
struct S0201235C;

#include "../types.h"



/* List menu template (0x34 bytes); the shortcut menu copies the const one and fills the pointers. */
typedef struct ShortcutListTemplate {
    void *items;                          /* 0x00 */
    void *moveCursorFunc;                 /* 0x04 */
    void *printFunc;                      /* 0x08 */
    struct Descriptor *window;            /* 0x0C */
    u16 totalItems;                       /* 0x10 */
    u16 maxShown;                         /* 0x12 */
    u8 headerX;                           /* 0x14 */
    u8 itemX;                             /* 0x15 */
    u8 cursorX;                           /* 0x16 */
    u8 upText;                            /* 0x17 */
    u8 cursorPal;                         /* 0x18 */
    u8 fillValue;                         /* 0x19 */
    u8 cursorShadowPal;                   /* 0x1A */
    u8 lettersSpacing;                    /* 0x1B */
    void *cbParam;                        /* 0x1C: the ShortcutMenu */
    u16 itemHeight;                       /* 0x20 */
    u16 scrollStep;                       /* 0x22 */
    struct MsgBank *msgBank;              /* 0x24 */
    struct Descriptor **windowRef;        /* 0x28 */
    struct PrintSys *printSys;            /* 0x2C */
    struct GfFont *font;                  /* 0x30 */
} ShortcutListTemplate;

/*
 * Work of the field shortcut menu (created at 0x021C4F7C, 0x88 bytes). The
 * first 0x4C bytes are cleared again by ShortcutMenu_InitList.
 */
typedef struct ShortcutMenu {
    void *listItems;                      /* 0x00: list entry table */
    struct BmpMenuList *list;                     /* 0x04: the list menu */
    struct Descriptor *window;            /* 0x08 */
    struct PrintSys *printSys;            /* 0x0C */
    struct Descriptor *printWindow;       /* 0x10 */
    u8 printBusy;                         /* 0x14 */
    u8 pad15[3];
    int selection;                        /* 0x18: -1 none, -2 cancelled */
    u16 savedScroll;                      /* 0x1C: list scroll when move mode started */
    u16 savedCursor;                      /* 0x1E: list cursor when move mode started */
    void *menuData;                       /* 0x20: the shortcut entries */
    u32 moveMode;                         /* 0x24: 1 while an entry is being moved */
    struct ClactActor *listActors[3];            /* 0x28: copy of actors, set by InitList */
    u16 heapId;                           /* 0x34 */
    u16 pad36;
    struct MsgBank *msgBank;              /* 0x38 */
    struct GfFont *font;                  /* 0x3C */
    u32 cursorWrapped;                    /* 0x40 */
    u32 redrawBg;                         /* 0x44 */
    u32 showActors;                       /* 0x48 */
    struct Unit *actorBank;               /* 0x4C */
    u16 charResId;                        /* 0x50 */
    u16 palResId;                         /* 0x52 */
    u16 cellResId;                        /* 0x54 */
    u16 pad56;
    struct ClactActor *actors[3];                /* 0x58: the three cursor actors */
    struct MsgBank *ownedMsgBank;         /* 0x64 */
    struct GfFont *ownedFont;             /* 0x68 */
    struct PrintSys *ownedPrintSys;       /* 0x6C */
    u16 state;                            /* 0x70 */
    u16 scrollFrame;                      /* 0x72 */
    u32 resultKind;                       /* 0x74: 0 none, 1 picked, 2 cancelled */
    int resultValue;                      /* 0x78 */
    const u16 *savedState;                /* 0x7C: {scroll, cursor} kept by the caller */
    u32 scrollDone;                       /* 0x80 */
    struct TcbTask *scrollTask;              /* 0x84 */
} ShortcutMenu;

#include "../sdk_fx.h"

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/mi_memory.h"
#include "../arm9/bg_sys.h"
#include "../arm9/clact.h"
#include "../arm9/gfl_use.h"
#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
#include "../arm9/msgdata.h"
#include "../arm9/gf_font.h"
struct PrintQueue;
#include "../arm9/printsys.h"
struct GameData;
struct SaveControl;
#include "../arm9/game_data.h"
#include "../arm9/recent_id_list_savedata.h"
#include "../arm9/g2.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
struct BmpWin;
#include "../arm9/bmp_win.h"
struct BmpMenuList;
#include "../arm9/bmp_menulist.h"
#include "../arm9/ui.h"
#include "../arm9/key.h"
struct Bmp;
#include "../arm9/bmp_menuwork.h"
struct MenuTemplate;
/* Retain the mode used to store f59 for the helper's second argument. */
ShortcutMenu *SHORTCUT_MENU_Create(void *gameSystem, int mode, const u16 *savedState, u16 textHeapId, u16 heapId);
void SHORTCUT_MENU_Delete(ShortcutMenu *menu);
void SHORTCUT_MENU_Main(ShortcutMenu *menu);
int SHORTCUT_MENU_RunPrint(ShortcutMenu *menu);
void SHORTCUT_MENU_Start(ShortcutMenu *menu);
void SHORTCUT_MENU_RequestClose(ShortcutMenu *menu);
int SHORTCUT_MENU_IsWaitingInput(ShortcutMenu *menu);
u32 SHORTCUT_MENU_GetResult(ShortcutMenu *menu, u32 *outValue);
void SHORTCUT_MENU_InitList(ShortcutMenu *menu, const u16 *savedState, struct MsgBank *msgBank, struct GfFont *font, struct PrintSys *printSys, void *menuData, struct ClactActor **actors, u16 heapId);
void SHORTCUT_MENU_FreeList(ShortcutMenu *menu, u16 *savedState);
void SHORTCUT_MENU_OnKeyUp(ShortcutMenu *menu, int cursor, u32 itemCount, u32 *done);
void SHORTCUT_MENU_OnKeyDown(ShortcutMenu *menu, int cursor, int itemCount, int *done);
void SHORTCUT_MENU_UpdateInput(ShortcutMenu *menu);
int SHORTCUT_MENU_FinishPrint(ShortcutMenu *menu);
int SHORTCUT_MENU_GetSelection(ShortcutMenu *menu);
void SHORTCUT_MENU_ListMoveCallback(void *list);
void SHORTCUT_MENU_UpdateCursorBg(void *list, int unused0, int unused1);
void SHORTCUT_MENU_ClampListWindow(u16 *scroll, u16 *cursor, u16 itemCount);
void SHORTCUT_MENU_CreateList(ShortcutMenu *menu, u16 scroll, u16 cursor, u32 heapId);
int SHORTCUT_MENU_DeleteList(ShortcutMenu *menu, u16 *outScroll, u16 *outCursor);
void SHORTCUT_MENU_ScrollStep(void *task, ShortcutMenu *menu);
void SHORTCUT_MENU_SetActorsY(ShortcutMenu *menu, int offsetY);
extern char gShortcutMenuFileName[];
extern const u32 gShortcutMenuBgTemplate[];
extern const u32 gShortcutMenuActorX[];
extern const ShortcutListTemplate gShortcutMenuListTemplate;
extern unsigned char abs_id_C2[];
extern char ov171_id[];
/*
 * The heap id is a u16 stack parameter, and the callees it feeds take a u16
 * heap too (docs/idioms/narrow-stack-parameters-and-callee-prototype-free-
 * the-narrow-home-store.md): only then does the u16 textHeapId home store
 * `str r3, [sp, #0x18]` lead the prologue. With u32 heap it sank below
 * `ldr r7, [sp, #0x40]; str r0, [sp, #0x10]` (6 bytes). pos.y = 0x60 is
 * written once before the loop, and the element address is spelled
 * menu + i * 4 + 0x58 (r6 = menu + i*4 shared with the table index).
 */
ShortcutMenu *SHORTCUT_MENU_Create(void *gameSystem, int mode, const u16 *savedState, u16 textHeapId, u16 heapId)
{
    struct ActorInitParam pos;
    int tileBase;
    ShortcutMenu *menu;
    void *resArchive;
    int i;

    i = 0;
    menu = GFL_HEAP_Alloc(heapId, 0x88, 0, gShortcutMenuFileName, 0xFC);
    MI_CpuFill8(menu, 0, 0x88);
    menu->resultKind = 0;
    menu->resultValue = 25;
    menu->savedState = savedState;
    BG_SYS_InitBgLayer(1, (const struct BgTemplate *)gShortcutMenuBgTemplate, 0);
    BG_SYS_FreeSlot(1);
    BG_SYS_Init(1, 0, 1, 0);
    menu->actorBank = CLACT_CreateUnit(8, 0, heapId);
    tileBase = 0x80;
    resArchive = ARC_TOOL_CreateHandle(0x80, heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(resArchive, 0, 0, tileBase + 0xE0, 0x40, heapId);
    menu->charResId = CLACT_RegisterPalette(resArchive, 4, 0, 0x40, heapId);
    menu->palResId = CLACT_RegisterCharacter(resArchive, 3, 0, 0, heapId);
    menu->cellResId = CLACT_RegisterCellAnim(resArchive, 2, 1, heapId);
    tileBase += 0xC0;
    ARC_UTIL_UploadPaletteFromHandleWhole(resArchive, 6, 0, tileBase, 0x20, heapId);
    ARC_UTIL_UploadBgCharFromHandle(resArchive, 5, 1, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(resArchive, 7, 1, 0, 0, 0, heapId);
    BG_SYS_FillTileMap(1, 0, 11, 32, 1, 10);
    ARC_TOOL_DeleteHandle(resArchive);
    MI_CpuFill8(&pos, 0, 8);
    pos.y = 0x60;
    for (i = 0; i < 3; i++) {
        pos.anim_seq = i;
        pos.x = gShortcutMenuActorX[i];
        menu->actors[i] = CLACT_CreateActor(menu->actorBank, menu->palResId, menu->charResId, menu->cellResId, &pos, 0, heapId);
        CLACT_SetActorDrawEnable(menu->actors[i], 0);
        CLACT_SetActorAutoAnim(menu->actors[i], 1);
    }
    menu->ownedMsgBank = MSGDATA_CreateFromArchive(0, 2, 0xAD, heapId);
    menu->ownedFont = GF_FONT_Create(0x17, 0, 0, 0, textHeapId);
    menu->ownedPrintSys = (struct PrintSys *)PRINTSYS_QUE_CreateEx(0x1000, heapId);
    SHORTCUT_MENU_InitList(menu, menu->savedState, menu->ownedMsgBank, menu->ownedFont,
        menu->ownedPrintSys, RECENT_ID_LIST_SAVEDATA_GetBlock(GAME_DATA_GetSaveControl(gameSystem)), menu->actors, textHeapId);
    BG_SYS_MarkTileDirty(1);
    G2x_SetBlendAlpha_((u32 *)REG_BLDCNT_ADDR, 2, 1, 12, 4);
    switch (mode) {
    case 0:
        BG_SYS_ChangeScrollImmediate(1, 3, -0xC0);
        BG_SYS_SetPlaneVisible(1, 0);
        menu->state = 0;
        break;
    case 1:
        BG_SYS_ChangeScrollImmediate(1, 3, 0);
        BG_SYS_SetPlaneVisible(1, 1);
        menu->state = 3;
        break;
    }
    return menu;
}

void SHORTCUT_MENU_Delete(ShortcutMenu *menu)
{
    int i = 0;

    *(volatile u16 *)0x04000050 = 0;
    BG_SYS_SetPlaneVisible(1, 0);
    SHORTCUT_MENU_FreeList(menu, (u16 *)menu->savedState);
    for (i = 0; i < 3; i++) {
        CLACT_DeleteActor(menu->actors[i]);
    }
    PRINTSYS_QUE_Clear((struct PrintQueue *)menu->ownedPrintSys);
    PRINTSYS_QUE_Delete((struct PrintQueue *)menu->ownedPrintSys);
    GF_FONT_Delete(menu->ownedFont);
    MSGDATA_Delete((struct MsgBank *)menu->ownedMsgBank);
    CLACT_ReleasePalette(menu->charResId);
    CLACT_ReleaseCharacter(menu->palResId);
    CLACT_ReleaseCellAnim(menu->cellResId);
    CLACT_DeleteUnit(menu->actorBank);
    BG_SYS_FreeTiles(1, 1, 0);
    BG_SYS_FreeLayerBuf(1);
    GFL_HEAP_Free(menu);
}

void SHORTCUT_MENU_Main(ShortcutMenu *menu)
{
    int selection;
    int i;

    if (SHORTCUT_MENU_RunPrint(menu) == 0) {
        return;
    }
    switch (menu->state) {
    case 0:
        break;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        menu->scrollFrame = 0;
        menu->scrollDone = 0;
        menu->scrollTask = GFL_USE_AddMainTask((void *)SHORTCUT_MENU_ScrollStep, menu, 0);
        menu->state = 2;
        break;
    case 2:
        if (menu->scrollDone != 0) {
            TCB_DeleteTask((struct TcbTask *)menu->scrollTask);
            menu->state = 3;
        }
        break;
    case 3:
        SHORTCUT_MENU_UpdateInput(menu);
        selection = SHORTCUT_MENU_GetSelection(menu);
        switch (selection) {
        case -1:
            menu->resultKind = 0;
            break;
        case -2:
            menu->resultKind = 2;
            break;
        default:
            menu->resultKind = 1;
            menu->resultValue = selection;
            break;
        }
        break;
    case 4:
        for (i = 0; i < 3; i++) {
            CLACT_SetActorDrawEnable(menu->actors[i], 0);
        }
        menu->scrollFrame = 4;
        menu->state = 5;
        break;
    case 5:
        BG_SYS_ChangeScrollImmediate(1, 3, menu->scrollFrame * 0xC0 / 4 - 0xC0);
        if ((menu->scrollFrame)-- == 0) {
            menu->state = 0;
        }
        break;
    }
}

int SHORTCUT_MENU_RunPrint(ShortcutMenu *menu)
{
    PRINTSYS_QUE_Main((struct PrintQueue *)menu->ownedPrintSys);
    return SHORTCUT_MENU_FinishPrint(menu);
}

/*
 * Starts the fade sequence once (state 0 to 1).
 */
void SHORTCUT_MENU_Start(ShortcutMenu *menu)
{
    if (menu->state == 0) {
        menu->resultKind = 0;
        menu->resultValue = 0x19;
        BG_SYS_SetPlaneVisible(1, 1);
        menu->state = 1;
    }
}

/*
 * Advances the sequence from state 3 to 4 (EXACT*: pad).
 */
void SHORTCUT_MENU_RequestClose(ShortcutMenu *menu)
{
    if (menu->state == 3)
        menu->state = 4;
}

/*
 * Returns 1 in states 2 and 5.
 */
int SHORTCUT_MENU_IsWaitingInput(ShortcutMenu *menu)
{
    int waiting = 1;

    if (menu->state != 2 && menu->state != 5)
        waiting = 0;
    return waiting;
}

/*
 * Returns the result word and optionally its argument.
 */
u32 SHORTCUT_MENU_GetResult(ShortcutMenu *menu, u32 *outValue)
{
    if (outValue != 0)
        *outValue = menu->resultValue;
    return menu->resultKind;
}

void SHORTCUT_MENU_InitList(ShortcutMenu *menu, const u16 *savedState, struct MsgBank *msgBank, struct GfFont *font, struct PrintSys *printSys, void *menuData, struct ClactActor **actors, u16 heapId)
{
    int i = 0;
    struct Descriptor *window;

    MI_CpuFill8(menu, 0, 0x4c);
    menu->printSys = printSys;
    menu->menuData = menuData;
    menu->heapId = heapId;
    menu->msgBank = msgBank;
    menu->font = font;
    for (i = 0; i < 3; i++) {
        menu->listActors[i] = actors[i];
    }
    window = (struct Descriptor *)BMP_WIN_Create(1, 1, 0xc, 0x1e, 0xc, 0xb, 1);
    menu->window = window;
    BMP_WIN_TransferChars((struct BmpWin *)window);
    BMP_WIN_MakeScreen((struct BmpWin *)window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)window));
    menu->printWindow = menu->window;
    menu->printBusy = 0;
    SHORTCUT_MENU_CreateList(menu, savedState[0], savedState[1], heapId);
}

/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void SHORTCUT_MENU_FreeList(ShortcutMenu *menu, u16 *savedState)
{
    SHORTCUT_MENU_DeleteList(menu, savedState, savedState + 1);
    BMP_WIN_Delete((struct BmpWin *)menu->window);
    MI_CpuFill8(menu, 0, 76);
}

/*
 * Message-window step: opens the window and plays SE 0x548, or scrolls to
 * the cursor line. Load-bearing: int-typed line count (stops (c-1)-(n-1)
 * folding) and the u16 local for the line index.
 */
void SHORTCUT_MENU_OnKeyUp(ShortcutMenu *menu, int cursor, u32 itemCount, u32 *done)
{
    int lastIndex;
    u16 cursorIndex;
    u16 row;

    if (cursor == 0) {
        lastIndex = BMP_MENULIST_GetAttr((struct BmpMenuList *)menu->list, 3);
        SHORTCUT_MENU_DeleteList(menu, 0, 0);
        SHORTCUT_MENU_CreateList(menu, (itemCount - 1) - (lastIndex - 1), lastIndex - 1, menu->heapId);
        if (menu->moveMode == 1)
            menu->cursorWrapped = 1;
        GFL_USE_PlaySeDefaultVolume(0x548);
        *done = 1;
    } else if (menu->cursorWrapped == 1 && menu->moveMode == 1) {
        BMP_MENULIST_GetPos((struct BmpMenuList *)menu->list, 0, &cursorIndex);
        row = BMP_MENULIST_GetRowY((struct BmpMenuList *)menu->list, cursorIndex) >> 3;
        SHORTCUT_MENU_SetActorsY(menu, (row + 0xC) * 8);
        menu->cursorWrapped = 0;
        *done = 1;
    }
}

void SHORTCUT_MENU_OnKeyDown(ShortcutMenu *menu, int cursor, int itemCount, int *done)
{
    u16 cursorIndex;
    u16 row;

    if (cursor == itemCount - 1) {
        if (menu->moveMode == 1) {
            BMP_MENULIST_GetPos((struct BmpMenuList *)menu->list, 0, &cursorIndex);
            row = BMP_MENULIST_GetRowY((struct BmpMenuList *)menu->list, (u16)(cursorIndex + 1)) >> 3;
            SHORTCUT_MENU_SetActorsY(menu, (row + 0xc) << 3);
            menu->cursorWrapped ^= 1;
        }
        if (menu->cursorWrapped == 0) {
            SHORTCUT_MENU_DeleteList(menu, 0, 0);
            SHORTCUT_MENU_CreateList(menu, 0, 0, menu->heapId);
        }
        GFL_USE_PlaySeDefaultVolume(0x548);
        *done = 1;
        return;
    }
    menu->cursorWrapped = 0;
}

void SHORTCUT_MENU_UpdateInput(ShortcutMenu *menu)
{
    int wrapped;
    u16 pickCursor[2];
    u16 moveCursor[2];
    u16 listWindow[2];
    int toggleMode;
    int selection;
    u32 itemCount;
    int i;

    selection = -1;
    toggleMode = 0;
    wrapped = 0;
    UI_SetInputMode(0);
    BMP_MENULIST_GetListIndex((struct BmpMenuList *)menu->list, &pickCursor[1]);
    itemCount = BMP_MENULIST_GetAttr((struct BmpMenuList *)menu->list, 2);
    if (KEY_GetRepeat() & 0x40) {
        SHORTCUT_MENU_OnKeyUp(menu, pickCursor[1], itemCount, (u32 *)&wrapped);
    } else if (KEY_GetRepeat() & 0x80) {
        SHORTCUT_MENU_OnKeyDown(menu, pickCursor[1], itemCount, &wrapped);
    }
    if (wrapped == 0) {
        selection = BMP_MENULIST_Main((struct BmpMenuList *)menu->list);
    }
    if (selection == -1) {
        if (KEY_GetTrg() & 0x400) {
            selection = -2;
            GFL_USE_PlaySeDefaultVolume(0x551);
        } else if (KEY_GetTrg() & 0x800) {
            BMP_MENULIST_GetListIndex((struct BmpMenuList *)menu->list, &pickCursor[0]);
            selection = BMP_MENULIST_GetItemValue((struct BmpMenuList *)menu->list, pickCursor[0]);
            GFL_USE_PlaySeDefaultVolume(0x54C);
        } else if ((KEY_GetTrg() & 4) && menu->moveMode == 1) {
            BMP_MENULIST_GetListIndex((struct BmpMenuList *)menu->list, &moveCursor[1]);
            selection = BMP_MENULIST_GetItemValue((struct BmpMenuList *)menu->list, moveCursor[1]);
            GFL_USE_PlaySeDefaultVolume(0x54C);
        }
    }
    if (menu->moveMode == 0) {
        menu->selection = selection;
    } else if (menu->moveMode == 1) {
        if (selection == -2) {
            toggleMode = 1;
        } else if (selection != -1) {
            selection = BMP_MENULIST_GetItemValue((struct BmpMenuList *)menu->list, (u16)(menu->savedScroll + menu->savedCursor));
            BMP_MENULIST_GetListIndex((struct BmpMenuList *)menu->list, &moveCursor[0]);
            if (menu->cursorWrapped != 0) {
                selection = RECENT_ID_LIST_SAVEDATA_InsertId(menu->menuData, selection, 0xFF);
            } else {
                selection = RECENT_ID_LIST_SAVEDATA_InsertId(menu->menuData, selection, moveCursor[0]);
            }
            SHORTCUT_MENU_DeleteList(menu, &listWindow[0], &listWindow[1]);
            if (moveCursor[0] - 1 == selection) {
                listWindow[1]--;
            }
            SHORTCUT_MENU_CreateList(menu, listWindow[0], listWindow[1], menu->heapId);
            toggleMode = 1;
        }
    }
    if ((KEY_GetTrg() & 4) && menu->moveMode == 0 && BMP_MENULIST_GetAttr((struct BmpMenuList *)menu->list, 2) > 1) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        toggleMode = 1;
    }
    if (toggleMode) {
        menu->moveMode ^= 1;
        if (menu->moveMode == 0) {
            menu->cursorWrapped = 0;
            for (i = 0; i < 3; i++) {
                CLACT_SetActorDrawEnable(menu->listActors[i], 0);
            }
            SHORTCUT_MENU_UpdateCursorBg(menu->list, 0, 0);
            return;
        }
        if (menu->moveMode == 1) {
            BMP_MENULIST_GetPos((struct BmpMenuList *)menu->list, &menu->savedScroll, &menu->savedCursor);
            menu->showActors = 1;
        }
    }
}

int SHORTCUT_MENU_FinishPrint(ShortcutMenu *menu)
{
    struct PrintSys *printSys = menu->printSys;
    int i;
    int finished;

    if (menu->printBusy != 0) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)printSys, (void *)((sptr)BMP_WIN_GetBmp((struct BmpWin *)menu->printWindow))) == 0) {
            BMP_WIN_TransferChars((struct BmpWin *)menu->printWindow);
            menu->printBusy = 0;
        }
    }
    finished = 1;
    if (menu->printBusy != 0) {
        finished = 0;
    }
    if (finished != 0) {
        if (menu->redrawBg != 0) {
            SHORTCUT_MENU_UpdateCursorBg(menu->list, 0, 0);
            menu->redrawBg = 0;
        }
        if (menu->showActors != 0) {
            for (i = 0; i < 3; i++) {
                CLACT_SetActorDrawEnable(menu->listActors[i], 1);
            }
            menu->showActors = 0;
        }
    }
    return finished;
}

/*
 * Unlabelled leaf (no lr save): returns the selection SHORTCUT_MENU_UpdateInput
 * stores at +0x18. Called from SHORTCUT_MENU_Main.
 */
int SHORTCUT_MENU_GetSelection(ShortcutMenu *menu)
{
    return menu->selection;
}

/*
 * Raises the redraw flag on the menu stored as the list's user pointer
 * (EXACT*: pad).
 */
void SHORTCUT_MENU_ListMoveCallback(void *list)
{
    *(u32 *)(BMP_MENULIST_GetAttr(list, 0x13) + 0x44) = 1;
}

void SHORTCUT_MENU_UpdateCursorBg(void *list, int unused0, int unused1)
{
    u16 listPos[2];
    ShortcutMenu *menu;
    u16 cursorRow;
    u32 rowHeightTiles;
    u32 baseY;
    u32 rowHeight;
    u32 cursorOffset;
    u16 row;

    menu = (ShortcutMenu *)BMP_MENULIST_GetAttr(list, 0x13);
    cursorRow = BMP_MENULIST_GetCursorY(list) >> 3;
    rowHeightTiles = BMP_MENULIST_GetAttr(list, 9) >> 3;
    if (menu->moveMode == 0) {
        BG_SYS_FillTileMap(1, 1, 12, 30, 12, 11);
        BG_SYS_FillTileMap(1, 1, cursorRow + 12, 30, rowHeightTiles, 12);
        BG_SYS_FillTileMap(1, 0, 11, 32, 1, 10);
        BG_SYS_MarkTileDirty(1);
    } else if (menu->moveMode == 1) {
        BG_SYS_FillTileMap(1, 1, 12, 30, 12, 11);
        BMP_MENULIST_GetPos(list, &listPos[1], &listPos[0]);
        baseY = BMP_MENULIST_GetAttr(list, 8);
        rowHeight = BMP_MENULIST_GetAttr(list, 9);
        cursorOffset = menu->savedCursor + menu->savedScroll - listPos[1];
        baseY = baseY + cursorOffset * rowHeight;
        BG_SYS_FillTileMap(1, 1, (baseY >> 3) + 12, 30, rowHeightTiles, 12);
        BG_SYS_FillTileMap(1, 0, 11, 32, 1, 10);
        BG_SYS_MarkTileDirty(1);
    }
    if (menu->cursorWrapped == 1) {
        row = BMP_MENULIST_GetAttr((struct BmpMenuList *)menu->list, 3);
        row = BMP_MENULIST_GetRowY((struct BmpMenuList *)menu->list, row) >> 3;
        SHORTCUT_MENU_SetActorsY(menu, (row + 12) << 3);
    } else {
        SHORTCUT_MENU_SetActorsY(menu, (cursorRow + 12) << 3);
    }
}

void SHORTCUT_MENU_ClampListWindow(u16 *scroll, u16 *cursor, u16 itemCount)
{
    int total = *scroll + *cursor;

    if (itemCount <= 5) {
        *cursor = total;
        *scroll = 0;
        return;
    }
    if (total <= 3) {
        *cursor = total;
        *scroll = 0;
        return;
    }
    if (total <= (int)itemCount - 2 && total > 3) {
        *scroll = total - 3;
        *cursor = 3;
        return;
    }
    if (total == (int)itemCount - 1) {
        *scroll = total - 4;
        *cursor = 4;
    }
}

void SHORTCUT_MENU_CreateList(ShortcutMenu *menu, u16 scroll, u16 cursor, u32 heapId)
{
    ShortcutListTemplate tmpl;
    u32 itemCount;
    u32 i;

    itemCount = RECENT_ID_LIST_SAVEDATA_CountIds(menu->menuData);
    menu->listItems = BMP_MENUWORK_Create(itemCount, heapId);
    for (i = 0; i < itemCount; i++) {
        u8 entryId = RECENT_ID_LIST_SAVEDATA_GetIdAt(menu->menuData, (u8)i);
        BMP_MENUWORK_AddMsgItem(menu->listItems, menu->msgBank, (int)entryId, (int)entryId, heapId);
    }
    while (cursor + scroll >= itemCount) {
        if (cursor != 0) {
            cursor--;
        } else if (scroll != 0) {
            scroll--;
        }
    }
    SHORTCUT_MENU_ClampListWindow(&scroll, &cursor, itemCount);
    tmpl = gShortcutMenuListTemplate;
    tmpl.items = menu->listItems;
    tmpl.totalItems = itemCount;
    tmpl.moveCursorFunc = (void *)SHORTCUT_MENU_ListMoveCallback;
    tmpl.printFunc = 0;
    tmpl.window = menu->window;
    tmpl.cbParam = menu;
    tmpl.msgBank = menu->msgBank;
    tmpl.windowRef = &menu->printWindow;
    tmpl.printSys = menu->printSys;
    tmpl.font = menu->font;
    menu->list = BMP_MENULIST_Create((struct BmpMenuListTemplate *)(&tmpl), scroll, cursor, heapId);
}

/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int SHORTCUT_MENU_DeleteList(ShortcutMenu *menu, u16 *outScroll, u16 *outCursor)
{
    BMP_MENULIST_Delete((struct BmpMenuList *)menu->list, outScroll, outCursor);
    return BMP_MENUWORK_Delete(menu->listItems);
}

/*
 * Scroll step: slides the BG by 0xC0/4 per frame and flags the end after 4.
 */
void SHORTCUT_MENU_ScrollStep(void *task, ShortcutMenu *menu)
{
    u16 frame = menu->scrollFrame;
    int offset = frame * 0xC0 / 4 - 0xC0;

    (menu->scrollFrame)++;
    if (frame >= 4) {
        offset = 0;
        menu->scrollDone = 1;
    }
    BG_SYS_ChangeScrollImmediate(1, 3, offset);
}

/*
 * Sets the y offset of the three sprite handles (EXACT*: pad). The split i =
 * 0; y = v; ordering is what schedules the zero before the sign extension.
 */
void SHORTCUT_MENU_SetActorsY(ShortcutMenu *menu, int offsetY)
{
    s16 y;
    int i;
    struct ClactVec2 offset;

    i = 0;
    y = offsetY;
    for (; i < 3; i++) {
        CLACT_GetActorSurfacePos(menu->listActors[i], &offset, 0);
        offset.y = y;
        CLACT_AddActorSurfacePos(menu->listActors[i], &offset, 0);
    }
}
