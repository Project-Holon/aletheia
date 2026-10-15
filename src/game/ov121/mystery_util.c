/*
 * file:     mystery_util.c
 * unit:     yes
 * function: MYSTERY_UTIL_CreateWindow, MYSTERY_UTIL_DeleteWindow, MYSTERY_UTIL_ClearWindow, MYSTERY_UTIL_ShowMessage, MYSTERY_UTIL_ShowString, MYSTERY_UTIL_SetColor, MYSTERY_UTIL_SetPosition, MYSTERY_UTIL_IsMessageDone, MYSTERY_UTIL_TransferWindowChars, MYSTERY_UTIL_ComputeTextPosition, MYSTERY_UTIL_AlignText, MYSTERY_UTIL_CreateMenuWindow, MYSTERY_UTIL_CreateMenuWindow2, MYSTERY_UTIL_DeleteMenuWindow, MYSTERY_UTIL_UpdateMenuWindow, MYSTERY_UTIL_SetMenuMessage, MYSTERY_UTIL_SetMenuMode, MYSTERY_UTIL_GetMenuState, MYSTERY_UTIL_DrawMenuWindow, MYSTERY_UTIL_ResetMenuWindow, MYSTERY_UTIL_CreateMenu, MYSTERY_UTIL_DeleteMenu, MYSTERY_UTIL_UpdateMenu, MYSTERY_UTIL_CreateWindowList, MYSTERY_UTIL_DeleteWindowList, MYSTERY_UTIL_ClearWindowList, MYSTERY_UTIL_IsWindowListDone, MYSTERY_UTIL_ClearListWindow, MYSTERY_UTIL_TransferWindowList, MYSTERY_UTIL_CreateBmpList, MYSTERY_UTIL_DeleteBmpList, MYSTERY_UTIL_DrawBmpList, MYSTERY_UTIL_CopyBmpList, MYSTERY_UTIL_CreateDetailWindow, MYSTERY_UTIL_DeleteDetailWindow, MYSTERY_UTIL_SetVoice, MYSTERY_UTIL_Update, MYSTERY_UTIL_SetListValue, MYSTERY_UTIL_CreateTask, MYSTERY_UTIL_DeleteTask, MYSTERY_UTIL_DispatchTask, MYSTERY_UTIL_GetTaskField04, MYSTERY_UTIL_SetTaskHandler, MYSTERY_UTIL_MarkTaskDone, MYSTERY_UTIL_SetTaskArg, MYSTERY_UTIL_GetTaskArg, MYSTERY_UTIL_CreateTaskEx, MYSTERY_UTIL_DeleteActorPair, MYSTERY_UTIL_UpdateActorPair, MYSTERY_UTIL_SetActorPairText, MYSTERY_UTIL_SetFlag, MYSTERY_UTIL_SetVec, MYSTERY_UTIL_IsMenuFinished, MYSTERY_UTIL_BuildPaletteRow, MYSTERY_UTIL_BlendPalette, MYSTERY_UTIL_BlendPaletteRange, MYSTERY_ALBUM_Create, MYSTERY_ALBUM_DeleteWork, MYSTERY_ALBUM_Update, MYSTERY_ALBUM_UpdateWindows, MYSTERY_ALBUM_GetWindowState, MYSTERY_ALBUM_Setup, MYSTERY_ALBUM_Cleanup, MYSTERY_ALBUM_SetCursor, MYSTERY_ALBUM_UpdateSlots, MYSTERY_ALBUM_SetupSlot, MYSTERY_ALBUM_DeleteSlotActor, MYSTERY_ALBUM_StartScroll, MYSTERY_ALBUM_UpdateScroll, MYSTERY_ALBUM_RemoveCard, MYSTERY_ALBUM_SwapCards, MYSTERY_ALBUM_GetColumnCount, MYSTERY_ALBUM_CountValidCards, MYSTERY_ALBUM_SetupEntry, MYSTERY_ALBUM_ClearEntry, MYSTERY_ALBUM_IsEntryValid, MYSTERY_ALBUM_GetEntryBmp, MYSTERY_ALBUM_CreateEntryArc, MYSTERY_ALBUM_GetEntryArcId, MYSTERY_ALBUM_GetEntryIconPalette, MYSTERY_ALBUM_GetEntryGraphicIndex, MYSTERY_ALBUM_GetEntrySpeciesId, MYSTERY_ALBUM_GetEntryFormId, MYSTERY_ALBUM_GetEntryKind, MYSTERY_ALBUM_GetEntryCard, MYSTERY_ALBUM_GetEntryEggFlag, MYSTERY_ALBUM_GetEntryIconX, MYSTERY_ALBUM_GetEntryIconY, MYSTERY_ALBUM_SelectHandler, MYSTERY_ALBUM_ConfirmHandler, MYSTERY_ALBUM_InfoHandler, MYSTERY_ALBUM_MoveHandler, MYSTERY_ALBUM_SaveHandler, MYSTERY_ALBUM_SingleHandler, MYSTERY_ALBUM_SetupIconSprite, MYSTERY_ALBUM_UpdateIconSprite, MYSTERY_ALBUM_CreateSlotWork, MYSTERY_ALBUM_DeleteSlotWork, MYSTERY_ALBUM_UpdateSlotWork, MYSTERY_ALBUM_CreateAlbumView
 * address:  0x021D99A4
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mystery_util.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 *   func_02040588 0x02040588 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   d_021DFBA0 0x021DFBA0 data a1
 *   BMP_WIN_Delete  0x020452E8  arm
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02045CAC 0x02045CAC arm
 *   STRBUF_Copy 0x02045838 arm
 *   func_02041B6C 0x02041B6C arm
 *   BMP_GetWidth 0x020437DC arm
 *   BMP_GetHeight 0x020437E4 arm
 *   TCBL_Create 0x0203101C arm
 *   PRINTSYS_CTRL_Init 0x02028470 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   TCBL_Main 0x020310C4 arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   d_021DF78C 0x021DF78C data a4
 *   BMP_MENULIST_Delete 0x0202020C thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_GetTileBytes 0x02043994 arm
 *   BMP_Create 0x02043678 arm
 *   BMP_Delete 0x020437AC arm
 *   BMP_CopyPixels 0x02043814 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Clone 0x02045874 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   d_021DF7C0 0x021DF7C0 data a4
 *   d_021DF76C 0x021DF76C data a4
 *   d_021DF770 0x021DF770 data a4
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetRepeat 0x0203633C arm
 *   _u32_div_f 0x0209C2B0 arm
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_OAM_UploadChars  0x020257D0  thumb
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   FX_SinCosTable_ 0x020A1B38 data a4
 *   func_02061CA4 0x02061CA4 arm
 *   func_02082A7C 0x02082A7C arm
 *   func_0203084C 0x0203084C arm
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   MYSTERY_ALBUM_RequestSetup 0x021DE0AC thumb ov121
 *   d_021DFBB0 0x021DFBB0 data a4
 *   d_021DF8FC 0x021DF8FC data a4
 *   d_021DF890 0x021DF890 data a4
 *   MYSTERY_ALBUM_Delete 0x021DD980 thumb ov121
 *   MYSTERY_DATA_GetCardSlotNum 0x0200A348 thumb
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   MYSTERY_ALBUM_ResetIntro 0x021DDF84 thumb ov121
 *   MYSTERY_ALBUM_HideScreen 0x021DE0DC thumb ov121
 *   MYSTERY_ALBUM_StepIntro 0x021DD9CC thumb ov121
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorFlip 0x0204B604 arm
 *   data_021DF86E 0x021DF86E data a1
 *   BG_SYS_SetTileUnit 0x02040DA8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   d_021DF86E 0x021DF86E data ov121 a2
 *   d_021DF86F 0x021DF86F data ov121 a1
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   MYSTERY_DATA_DeleteCard  0x0200A094  thumb
 *   MYSTERY_DATA_IsCardExist  0x0200A0E4  thumb
 *   MYSTERY_DATA_GetCard  0x0200A000  thumb
 *   MYSTERY_DATA_SwapCards  0x0200A254  thumb
 *   FILE_UTIL_Get 0x02020E60 thumb
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   d_021DF838 0x021DF838 data a4
 *   d_021DF848 0x021DF848 data a4
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   MYSTERY_ALBUM_StartIntro 0x021DDF5C thumb ov121
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   MYSTERY_DATA_HasAnyCard 0x0200A170 thumb
 *   func_0207D658 0x0207D658 arm
 *   MYSTERY_ALBUM_IsIntroIdle 0x021DE014 thumb ov121
 *   MYSTERY_DATA_HasCardSpace 0x0200A0C8 thumb
 *   MYSTERY_DATA_SaveStart 0x0200A2B8 thumb
 *   MYSTERY_DATA_SaveMain 0x0200A2D8 thumb
 *   func_02049F78 0x02049F78 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   POKEGRA_RegisterPalette 0x0202D7D8 thumb
 *   POKEGRA_RegisterCellAnim 0x0202D898 thumb
 *   POKEGRA_RegisterCgr 0x0202D81C thumb
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   d_021DF99C 0x021DF99C data a4
 *   STRBUF_SetStringN 0x02045994 arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   func_020056EC 0x020056EC thumb
 *   func_02012944 0x02012944 thumb
 *   func_02008530 0x02008530 thumb
 *   POKE_TOOL_Create 0x020173F0 thumb
 *   POKE_TOOL_CreatePersonalRnd 0x020186C8 thumb
 *   POKE_TOOL_SetupPartyParamEx 0x02017588 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   POKE_TOOL_SetDefaultMoves 0x02017FA8 thumb
 *   POKE_TOOL_AddMove 0x0201808C thumb
 *   POKE_TOOL_PushMove 0x020180F4 thumb
 *   func_02018A00 0x02018A00 thumb
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   func_020084F4 0x020084F4 thumb
 *   func_02008550 0x02008550 thumb
 *   func_020185F0 0x020185F0 thumb
 *   SAVE_EVENT_WriteWithDate 0x0202F2AC thumb
 *   POKE_TOOL_RecalcParam 0x020185C4 thumb
 *   POKEGRA_GetArcID 0x0202D060 thumb
 *   func_02017EAC 0x02017EAC thumb
 *   POKEGRA_GetPalArcIndex 0x0202D0D4 thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   POKEGRA_LoadCharDataPP 0x0202D6F4 thumb
 *   d_021DFA14 0x021DFA14 data a4
 *   d_021DF8C0 0x021DF8C0 data a4
 *   g0209DF08 0x0209DF08 data a1
 *   g0209DF0C 0x0209DF0C data a1
 *   gSpeciesNameBank 0x020A7370 data
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb  arm9
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb  arm9
 *   PRINTSYS_Print  0x0201C7A4  thumb  arm9
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   BMP_MENUWORK_Create  0x0201F81C  thumb  arm9
 *   BMP_MENUWORK_AddMsgItem  0x0201F878  thumb  arm9
 *   BMP_MENULIST_Create  0x0201FF30  thumb  arm9
 *   BMP_MENULIST_Main  0x020200CC  thumb  arm9
 *   BMP_OAM_Create  0x020255A0  thumb  arm9
 *   APP_KEYCURSOR_Delete  0x02028604  thumb  arm9
 *   APP_KEYCURSOR_Update  0x020286C4  thumb  arm9
 *   TIME_ICON_Create  0x0202EE30  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb  arm9
 *   MSG_SPEED_GetWait  0x02012FFC  thumb  arm9
 *   PRINTSYS_CTRL_Update  0x02028484  thumb  arm9
 *   APP_KEYCURSOR_CreateDefault  0x02028590  thumb  arm9
 */
#include "../../matched/include/Obj01929.h"
#include "../../matched/include/Obj13950.h"
#include "../../matched/include/Obj22875.h"
#include "../../matched/include/Obj01057.h"
#include "../../matched/include/Obj22876.h"
#include "../../matched/include/Obj02179.h"
#include "../../matched/include/Obj08092.h"
#include "../../matched/include/Obj02180.h"
#include "../../matched/include/Obj00909.h"
#include "../../matched/include/Obj00236.h"
#include "../../matched/include/Obj22877.h"
#include "../../matched/include/Obj22878.h"
#include "../../matched/include/Obj01542.h"
#include "../../matched/include/Obj01731.h"
#include "../../matched/include/Obj06448.h"
#include "../../matched/include/Obj04493.h"
#include "../../matched/include/Obj02469.h"
#include "../../matched/include/Obj04494.h"
#include "../../matched/include/Obj08093.h"
#include "../../matched/include/Obj22879.h"
#include "../../matched/include/Obj22880.h"
#include "../../matched/include/Obj22881.h"
#include "../../matched/include/Obj13951.h"
#include "../../matched/include/Obj22882.h"
#include "../../matched/include/Obj13952.h"
#include "../../matched/include/Obj13953.h"
#include "../../matched/include/Obj22883.h"
#include "../../matched/include/Obj22884.h"
#include "../../matched/include/Obj03262.h"
#include "../../matched/include/Obj06449.h"
#include "../../matched/include/Obj22885.h"
#include "../../matched/include/Obj22886.h"
#include "../../matched/include/Obj22887.h"
#include "../../matched/include/Obj22888.h"
#include "../../matched/include/Obj13954.h"
#include "../../matched/include/Obj22889.h"
#include "../../matched/include/Obj03786.h"
#include "../../matched/include/Obj00360.h"
#include "../../matched/include/Obj06450.h"
#include "../../matched/include/Obj22893.h"
#include "../../matched/include/Obj13955.h"
#include "../../matched/include/Obj06451.h"
#include "../../matched/include/Obj08095.h"
#include "../../matched/include/Obj10414.h"
#include "../../matched/include/Obj10415.h"
#include "../../matched/include/Obj03787.h"
#include "../../matched/include/Obj22897.h"
#include "../../matched/include/Obj05358.h"
#include "../../matched/include/Obj02470.h"
#include "../../matched/include/Obj00910.h"
#include "../../matched/include/Obj01058.h"
#include "../../matched/include/Obj01153.h"
#include "../../matched/include/Obj10417.h"
#include "../../matched/include/Obj22899.h"
#include "../../matched/include/Obj00828.h"
#include "../../matched/include/Obj13956.h"
#include "../../matched/include/Obj13957.h"
#include "../../matched/include/Obj02834.h"
#include "../../matched/include/Obj22900.h"
#include "../../matched/include/Obj03788.h"
#include "../../matched/include/Obj10418.h"
#include "../../matched/include/Obj13958.h"
#include "../../matched/include/Obj22903.h"
#include "../../matched/include/Obj08097.h"
#include "../../matched/include/Obj06452.h"
#include "../../matched/include/Obj22905.h"
#include "../../matched/include/Obj00061.h"
#include "../../matched/include/Obj00169.h"
#include "../../matched/include/Obj00253.h"
#include "../../matched/include/Obj01930.h"
#include "../../matched/include/Obj22906.h"
#include "../../matched/include/Obj00237.h"
#include "mystery_net_types.h"

/*
 * Text window drawn through the BMP_WIN subsystem (mystery_util.c). Allocated
 * 0x28 bytes by MYSTERY_UTIL_Create; shown and hidden through MYSTERY_UTIL_ShowMessage.
 */
typedef struct MysteryUtilWindow {
    void *bmpWin;           /* 0x00 BMP_WIN handle */
    unsigned char visible;  /* 0x04 set once the text has been queued */
    void *printOwner;       /* 0x08 owner passed to PRINTSYS_PrintQueColor */
    void *bmpWin2;          /* 0x0C second BMP_WIN handle (same as bmpWin) */
    void *textBuf;          /* 0x10 STRBUF text buffer */
    unsigned short textParam; /* 0x14 */
    unsigned short color;   /* 0x16 palette slot / colour word */
    int posX;               /* 0x18 */
    int posY;               /* 0x1C */
    int mode;               /* 0x20 layout mode for MYSTERY_UTIL_AlignText */
    unsigned int variant;   /* 0x24 window variant */
} MysteryUtilWindow;

/*
 * Scrollable text window with a TCBL renderer and a PRINTSYS print stream
 * (mystery_util.c). Allocated 0x40 bytes by MYSTERY_UTIL_CreateMenuWindow.
 */
typedef struct MysteryUtilMenuWindow {
    void *handler;          /* 0x00 handler/vtable slot (guess) */
    unsigned int printArg;    /* 0x04 */
    void *printStream;      /* 0x08 PRINTSYS_PrintStream handle */
    void *tcbl;             /* 0x0C TCBL text renderer */
    void *bmpWin;           /* 0x10 BMP_WIN handle */
    void *textBuf;          /* 0x14 STRBUF */
    unsigned short height;  /* 0x18 */
    unsigned short heapTag; /* 0x1A */
    void *bmpWin2;          /* 0x1C BMP_WIN handle used by PRINTSYS_PrintQue */
    unsigned char visible;  /* 0x20 */
    unsigned int elementSlot;   /* 0x24 */
    unsigned int state;     /* 0x28 */
    unsigned int result;   /* 0x2C */
    void *keyCursor;        /* 0x30 APP_KEYCURSOR handle */
    unsigned char ctrl[8];  /* 0x34 PRINTSYS_CTRL block */
    void *timeIcon;         /* 0x3C TIME_ICON handle */
} MysteryUtilMenuWindow;

/*
 * Table of text windows (mystery_util.c). Built by MYSTERY_UTIL_CreateWindowList; the
 * descriptor table is an array of MysteryUtilMenuEntry, 24 bytes each.
 */
typedef struct MysteryUtilWindowList {
    const char *desc;       /* 0x00 descriptor table */
    unsigned int count;     /* 0x04 number of windows */
    int printOwner;             /* 0x08 */
    int msgBank;             /* 0x0C */
    void *items[1];         /* 0x10 text windows */
} MysteryUtilWindowList;

/* One entry of the descriptor table read by MYSTERY_UTIL_CreateWindowList / MYSTERY_UTIL_DrawBmpList. */
typedef struct MysteryUtilMenuEntry {
    union {
        unsigned int flags;     /* 0x00 read as a u32 by MYSTERY_UTIL_DrawBmpList */
        unsigned char bytes[4]; /* 0x00 four u8 BMP parameters by MYSTERY_UTIL_CreateWindowList */
    } u0;
    int messageId;              /* 0x04 func_02045CAC index */
    int stringId;               /* 0x08 STRBUF source */
    int layoutMode;             /* 0x0C mode for MYSTERY_UTIL_AlignText */
    short posX;                 /* 0x10 */
    short posY;                 /* 0x12 */
    unsigned short color;       /* 0x14 palette slot */
} MysteryUtilMenuEntry;

/*
 * Table of BMP buffers copied from a MysteryUtilWindowList (mystery_util.c).
 * Built by MYSTERY_UTIL_CreateBmpList, 0x08 bytes of header then one BMP per window.
 */
typedef struct MysteryUtilBmpList {
    unsigned short heapId;  /* 0x00 */
    void *srcList;          /* 0x04 MysteryUtilWindowList */
    void *bmps[1];          /* 0x08 BMP buffers */
} MysteryUtilBmpList;

/*
 * Menu window with a BMP_MENULIST and a BMP_MENUWORK (mystery_util.c).
 * Allocated 0x18 bytes by MYSTERY_UTIL_CreateMenu.
 */
typedef struct MysteryUtilMenu {
    void *bmpWin;           /* 0x00 BMP_WIN handle */
    unsigned int printOwner;    /* 0x04 print owner */
    void *bmpWin2;          /* 0x08 BMP_WIN handle */
    unsigned char winFlag;   /* 0x0C */
    void *menuList;         /* 0x10 BMP_MENULIST handle */
    void *menuWork;         /* 0x14 BMP_MENUWORK handle */
} MysteryUtilMenu;

/* Read-only menu definition passed to MYSTERY_UTIL_CreateMenu. */
typedef struct MysteryUtilMenuDef {
    unsigned int menuTable;    /* 0x00 */
    unsigned int messageTable;    /* 0x04 */
    unsigned int printOwner;    /* 0x08 */
    unsigned char pad0C[12];
    unsigned int count;     /* 0x18 number of message items */
    unsigned short bgLayer; /* 0x1C */
    unsigned short palette; /* 0x1E */
    unsigned short windowX; /* 0x20 */
    unsigned short windowY; /* 0x22 */
} MysteryUtilMenuDef;

/* One Mystery Gift card as embedded in a MysteryAlbumEntry (0xCC bytes). */
typedef struct MysteryAlbumCard {
    unsigned int arcId;        /* 0x00 */
    unsigned char pad02[0x16];
    unsigned short species;     /* 0x1A */
    unsigned char form;         /* 0x1C */
    unsigned char pad1D[0x18];
    unsigned char gender;      /* 0x35 */
    unsigned char pad36[0x26];
    unsigned char isEgg;      /* 0x5C */
    unsigned char pad5D[0x56];
    unsigned char giftType;     /* 0xB3 */
    unsigned char padB4[0x18];
} MysteryAlbumCard;

/* One album slot on the Mystery Gift select screen (0xDC bytes). */
typedef struct MysteryAlbumEntry {
    int valid;                  /* 0x00 card present flag */
    MysteryAlbumCard card;      /* 0x04 card record */
    void *bmp;                  /* 0xD0 icon BMP */
    unsigned char padD4[8];     /* 0xD4 */
} MysteryAlbumEntry;

/*
 * Root work object of the Mystery Gift album select screen (mystery_album.c
 * original, held in this file). Allocated 0xC70 bytes by MYSTERY_ALBUM_Create.
 */
typedef struct MysteryAlbumWork {
    unsigned int mode;              /* 0x00 */
    unsigned int param4;            /* 0x04 */
    unsigned int param8;            /* 0x08 */
    void *cardList;                 /* 0x0C MYSTERY_DATA card list */
    void *windowParamA;                  /* 0x10 */
    void *windowParamB;                  /* 0x14 */
    unsigned int param18;           /* 0x18 */
    unsigned int bank;           /* 0x1C */
    unsigned int saveParam;           /* 0x20 */
    unsigned short heapId;          /* 0x24 */
    unsigned char pad26[2];
    MysteryAlbumEntry items[12];    /* 0x28 one per card slot */
    int refreshFlag;                /* 0xA78 */
    void *slots[12];                /* 0xA7C selected album handles */
    void *selectedAlbum;            /* 0xAAC */
    void *menuWork;                 /* 0xAB0 */
    void *infoWindow;                 /* 0xAB4 */
    void *windowList;               /* 0xAB8 MysteryUtilWindowList */
    void *menuWindow;                 /* 0xABC */
    void *menu;                 /* 0xAC0 */
    void *task;                 /* 0xAC4 */
    int cursorIndex;                /* 0xAC8 */
    unsigned int cursorMode;        /* 0xACC */
    unsigned int flipFlag;          /* 0xAD0 */
    unsigned int dirty;          /* 0xAD4 */
    unsigned int scrollTimer;          /* 0xAD8 */
    signed char scrollDir;           /* 0xADC */
    unsigned char padADD;
    unsigned short swapIndex;        /* 0xADE */
    int introActive;                   /* 0xAE0 */
    int introMode;                   /* 0xAE4 */
    unsigned char padAE8[4];
    void *actorA;                   /* 0xAEC */
    void *actorB;                   /* 0xAF0 */
    void *actorC;                   /* 0xAF4 */
    void *actorD;                   /* 0xAF8 */
    void *charHandle;                 /* 0xAFC */
    void *cellAnimHandle;                 /* 0xB00 */
    void *paletteHandle;                 /* 0xB04 */
    void *windows[8];               /* 0xB08 BMP_WIN handles */
    void *actors[8];                /* 0xB28 CLACT actors */
    unsigned int charHandles[8];    /* 0xB48 CLACT character handles */
    unsigned int cellAnimHandles[8];/* 0xB68 CLACT cell-anim handles */
    unsigned int paletteHandles[8]; /* 0xB88 CLACT palette handles */
    void *bgPaletteHandle;                 /* 0xBA8 */
    unsigned short angle;           /* 0xBAC */
    unsigned char tail[0xC70 - 0xBAE]; /* 0xBAE icon sprites */
} MysteryAlbumWork;

#define W(k) (*(u32 *)(p+(k)))

#define P(k) (*(u8 **)(p+(k)))

#define H(k) (*(u16 *)(p+(k)))

struct CharBuf;

struct Descriptor;

struct U16Vec;

struct MsgBank;

struct PrintSys;

struct Bmp;

struct Tcbl;

struct Blk;

struct Ctx;

struct Src;

struct Obj020437AC;

struct Vec2;

struct Grid;

struct Param;

struct Actor;

struct PtS;

struct Sub0200852CObj;

typedef signed int     s32;

typedef signed short s16;

typedef struct { int x; int y; } Pair_021D9624;

typedef struct {u32 word[13];} Config_021D9BC0;

struct In {
    void *bank;
    u32 f4;
    u32 f8;
    u32 *fC_;
    u32 ids[4];
    u32 f20;
    u16 f24;
    u16 f26;
    u16 f28;
    u16 f2a;
    s16 f2c;
    s16 f2e;
    u16 f30;
    u16 pad32;
    u32 f34;
    u32 f38;
    u32 *f3c;
};

struct Out_021D9624 {
    void *f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u16 pad10;
    u16 pal[5];
    u16 pad1c[3];
    u16 f22;
    u16 f24;
    u16 f26;
    u16 f28;
    u16 f2a;
    u16 f2c;
    u16 f2e;
    u16 f30;
    u16 pad32;
    u32 f34;
    u32 f38;
    u8 pad3c[0x24];
    u32 *f60;
};

struct Rec_021D9624 {
    u8 a;
    u8 b;
    u8 pad[6];
    void *h;
    u8 rest[12];
};

struct Tbl { struct Rec_021D9624 r[4]; };

struct Pt { s16 x; s16 y; };

typedef struct {int x,y;} TablePair;

typedef unsigned long long u64;

typedef struct {s16 x,y;} Position_021D9624;

typedef struct { void *win; s16 x,y; int z; int pal; u8 a,b; u16 c; int d; } Desc_021DA3EC;

typedef struct {u32 w[9];} Input;

typedef struct {u32 w[51];} Record_021D9624;

typedef struct {u32 w[12];} Desc_021DAB50;

typedef struct Item_021D9624 { char raw[0xdc]; } Item_021D9624;

typedef struct Obj_021DAEF0 { char pad[0x28]; Item_021D9624 items[12]; char tail[0xacc-0x28-12*0xdc]; volatile int index; } Obj_021DAEF0;

typedef struct {u8 x,y,pad[6];} Coord_021DC08C;

typedef union { u16 h[4]; Coord_021DC08C c; } Row;

typedef struct { u8 b[16]; } Tmp;

typedef union Rect_021D9624 { s16 h[4]; u8 b[8]; } Rect_021D9624;

typedef struct Cur_021D9624 { s16 x; s16 y; } Cur_021D9624;

typedef struct Pos { s16 x; s16 y; u8 pad[3]; u8 flag; } Pos;

typedef union Rect_021DB938 { u16 h[4]; u8 b[8]; } Rect_021DB938;

typedef struct Item_021DB938 {
    unsigned char raw[0xDC];
} Item_021DB938;

typedef struct { u32 w[51]; } Record_021DB938;

typedef struct { u8 low:1; u8 flag:1; u8 rest:6; } Bits;

typedef struct {short x,y;} Position_021DC030;

typedef struct { u32 v[7]; u16 a,b,c,d; } Desc_021DC4F0;

typedef struct { short x,y; } Vec;

typedef struct {u32 v[7];u16 a,b,c,d;} Desc_021DC734;

typedef struct { u8 pad[0xAC8]; u32 row; u32 col; } Cur_021DC030;

typedef struct {u32 v[7];u16 a,b,c,d;} Desc_021DCCE4;

typedef struct {u32 w[12];} Desc_021DCFC8;

typedef struct {u32 w[30];} Config;

typedef struct {s16 x,y,z;u8 a,b;} Record_021DCFC8;

typedef signed int     s32_021DCFC8;

typedef int s32_021DD24C;

typedef struct { u32 w[51]; } Record_021DD24C;

typedef struct { u32 f0; u32 f4; void *f8; u32 fC; u16 f10; u16 f12; u16 f14; u16 pad; } DE;

typedef struct { DE e[5]; } Desc_021DD24C;

struct Rec_021DC030 {
    u32 f0;
    u32 f4;
    u32 f8;
    u16 fC;
    u16 fE;
    u16 f10;
    u16 mv[4];
    u16 species;
    u8 form;
    u8 f1D;
    u16 f1E;
    u8 pad20[0x14];
    u8 f34;
    u8 f35;
    u8 f36;
    u8 f37;
    u16 f38;
    u16 f3A;
    u8 f3C;
    u8 f3D;
    u8 f3E;
    u8 f3F;
    u8 f40;
    u8 f41;
    u8 pad42;
    u8 iv0, iv1, iv2, iv6, iv7, iv3;
    u8 pad49;
    u16 f4A;
    u8 pad4C[0xE];
    u8 f5A;
    u8 f5B;
    u8 f5C;
    u8 pad5D[0x4F];
    u32 fAC;
    u8 padB0[2];
    u8 fB2;
    u8 fB3;
    u8 fB4a:1;
    u8 fB4b:1;
};

struct Ctx {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
};

struct CtxB {
    u32 f0;
    u8 pad4[0xB4];
    u32 fB8;
    u32 fBC;
    u32 fC0;
    u32 fC4;
    u32 fC8;
    u32 fCC;
};

struct Out_021DC030 {
    u8 pad0[0xE0];
    u32 fE0;
    u16 fE4;
    u16 fE6;
    u8 padE8[0x118 - 0xE8];
    u16 heap;
    u8 pad11A[2];
    struct CtxB *b;
    struct Rec_021DC030 *a;
    void *c;
    u8 pad128[0xC];
    u32 f134;
    u32 f138;
    void *f13C;
    void *f140;
    void *f144;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const void *site, u16 tag);

extern void MI_CpuFill8(void *, int, u32);

extern u32 func_020307B0(void *p);

extern void func_02040588(unsigned char which, unsigned char enable);

extern void *STRBUF_Create(u32, u16);

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(void *p);

extern void BMP_Clear(void *buf, u8 value);

extern void BMP_WIN_TransferChars(void *d);

extern void BMP_WIN_MakeScreen(void *cfg);

extern u8 BMP_WIN_GetBgLayer(void *p);

extern void BG_SYS_PushTile(u32);

extern u32 BMP_WIN_Delete(void *d);

extern void STRBUF_Delete(void *vec);

extern void BMP_WIN_ClearScreen(void *d);

extern void func_02045CAC(void *bank, u32 index, void *dest);

extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void STRBUF_Copy(void *dst, void *src);

extern u32 PRINTSYS_QUE_IsExistTarget(void *p, void *v);

extern void func_02041B6C(unsigned);

extern u16 BMP_GetWidth(const void *bmp);

extern u16 BMP_GetHeight(const void *bmp);

extern u32 func_0201D304(void *s, u32 a, u32 b);

extern u32 func_0201D42C(void *s, void *font);

extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);

extern void PRINTSYS_CTRL_Init(void *p, u32 v);

extern void PRINTSYS_PrintStreamDelete(void *p);

extern void TIME_ICON_Delete(void *);

extern int APP_KEYCURSOR_Delete(int a0);

extern void TCBL_Destroy(void *p);

extern void BMP_MENUWORK_DrawWindowBorder(void *, u32);

extern void APP_KEYCURSOR_Update(void *ctx, void *p, void *cell);

extern s32 PRINTSYS_CTRL_Update(void *blk, void *h);

extern void TCBL_Main(void *p);

extern u32 func_020056BC(void);

extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);

extern void PRINTSYS_PrintQue(void *p, u32 a, u32 b, u32 c, void *s, u32 e);

extern void *APP_KEYCURSOR_CreateDefault(u32,u32,u32,u32);

extern signed char MSG_SPEED_GetWait(void);

extern void *PRINTSYS_PrintStream(void *,u32,u32,u32,u32,int, void *,u32,u16,u16);

extern void BMP_MENUWORK_DrawWindow(void *, int, int, int);

extern void *BMP_MENUWORK_Create(u32,u32);

extern void BMP_MENUWORK_AddMsgItem(void *table, u32 a, u32 b, u32 tag, u32 heap);

extern struct Obj *BMP_MENULIST_Create(void *src, u16 a, u16 b, u32 heap);

extern void func_02020CF8(void *p, int heap);

extern void func_02020D10(void *p, u32 v);

extern void BMP_MENULIST_Delete(void *o, void *a, void *b);

extern u32 BMP_MENUWORK_Delete(void *p);

extern s32 BMP_MENULIST_Main(void *o);

extern u32 func_02020350(void *obj, u32 what);

extern u8 BMP_GetTileBytes(void *b);

extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);

extern void BMP_Delete(void *p);

extern void BMP_CopyPixels(void *dst, const void *src);

extern void *func_02045EC0(void *bank, u32 index);

extern struct U16Vec *STRBUF_Clone(void *src, u32 heapId);

extern void CLACT_AddActorSurfacePos(void *p, const void *delta, u32 which);

extern void CLACT_SetActorDrawEnable(void *p, u32 v);

extern void CLACT_SetActorAnimSeq(void *p, u16 value);

extern void CLACT_SetActorAutoAnim(void *p, u32 v);

extern u32 KEY_GetTrg(void);

extern u32 KEY_GetRepeat(void);

extern void GFL_USE_PlaySeDefaultVolume(u32 a);

extern u64 _u32_div_f(u32,u32);

extern struct Grid *BMP_OAM_Create(void *sys, const void *param);

extern void BMP_OAM_Delete(void *g);

extern void BMP_OAM_UploadChars(void *o);

extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);

extern void func_02082A7C(int, void *,int);

extern void *func_0203084C(u32 heapId);

extern void BG_SYS_FillScrollArea(u32,u32,u32);

extern u32 MYSTERY_DATA_GetCardSlotNum(void *);

extern u32 MYSTERY_DATA_IsCardExist(void *p, u32 a);

extern int MYSTERY_DATA_GetCard(void *p, int idx, void *buf);

extern void MYSTERY_ALBUM_RequestSetup(void *p, u32 b);

extern void MYSTERY_ALBUM_Delete(void *);

extern void BG_SYS_ClearSlot(u32);

extern void MYSTERY_ALBUM_ResetIntro(void *);

extern void MYSTERY_ALBUM_HideScreen(void *p);

extern void MYSTERY_ALBUM_StepIntro(void *p);

extern void *func_020490F4(u32 id, u32 heap);

extern void func_02049B68(void *, u32, u32, u32, u32, u16);

extern unsigned int func_02049658(void *, u32, u32, u32, u32, u32, u16);

extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);

extern void ARC_TOOL_DeleteHandle(void *);

extern void BG_SYS_Init(u32, u32, u32, u32);

extern void BMP_MENUWORK_LoadCharAndPltt(u32, u32, u32, u32, u16);

extern int func_0201BC3C(void);

extern int CLACT_RegisterPaletteCompressed(void *, u32, u32, u32, u16);

extern s32 CLACT_RegisterPaletteEx(void *, u32, u32, u32, u16, u16, u16);

extern s32 CLACT_RegisterCellAnim(void *, u32, u32, u32);

extern s32 CLACT_RegisterCharacter(void *, u32, u32, u32, u16);

extern struct Obj *CLACT_CreateActor(void *, u32, u32, u32, const void *, u16, u16);

extern void CLACT_SetActorFlip(void *actor, u32 which, u32 set);

extern void BG_SYS_SetTileUnit(u32 idx, u32 count, u32 tile);

extern void CLACT_DeleteActor(void *p);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void CLACT_ReleasePalette(u32 i);

extern void WORDSET_SetSlotNumber(void *p, u32 i, u32 a, u32 b, u32 c, u32 d);

extern void WORDSET_CopyTaggedText(void *ws, void *dst, void *src);

extern void BG_SYS_SetTileEntry(u32,u16,u8,u8,u8,u8,u8);

extern void BG_SYS_FillTileMap(u32,u32,u32,u8,u8,u8);

extern void CLACT_SetActorPaletteOffset(void *o, u32 v, u32 flag);

extern void CLACT_GetActorSurfacePos(void *actor, void *out, u16 space);

extern void MYSTERY_DATA_DeleteCard(void *list, u32 idx);

extern void MYSTERY_DATA_SwapCards(void *, u32, u32);

extern void PRINTSYS_Print(void *,s16,s16, void *, void *);

extern u32 FILE_UTIL_Get(u16,u32);

extern u32 POKE_TOOL_CalcIconPalette(u32,u32,u32,u32);

extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);

extern int func_0201BC40(void);

extern int func_0201BCB4(void);

extern int TOUCHPANEL_GetTrg(void);

extern void MYSTERY_ALBUM_StartIntro(void *p);

extern int MYSTERY_DATA_HasAnyCard(void *p);

extern void func_0207D658(u32,int,int);

extern int MYSTERY_ALBUM_IsIntroIdle(void *p);

extern u32 MYSTERY_DATA_HasCardSpace(void *p);

extern void MYSTERY_DATA_SaveStart(void *a0, int a1);

extern int MYSTERY_DATA_SaveMain(void *a0, int a1);

extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);

extern void MI_CpuCopy8(const void *, void *,int);

extern s32_021DCFC8 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);

extern void CLACT_SetActorObjMode(void *actor, u32 value);

extern int POKEGRA_OpenHandle(int a0);

extern int POKEGRA_RegisterPalette(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned short a8, unsigned short a9);

extern int POKEGRA_RegisterCellAnim(u32,u32,u32,u32,u32,u32,u32,u32,u16);

extern int POKEGRA_RegisterCgr(void *,u32,u32,u32,u32,u32,u32,u32,u32,u16);

extern void CLACT_SetActorAffineMode(void *actor, u32 value);

extern void STRBUF_SetStringN(void *o, const void *src, u32 len);

extern u32 func_020056EC(u32 range);

extern u8 *func_02012944(void *p);

extern u32 func_02008530(const void *obj);

extern void *POKE_TOOL_Create(u16 species, u16 level, u32 otId, u32 a3, u32 heap);

extern u32 POKE_TOOL_CreatePersonalRnd(u32 a0, int a1, int a2, int a3, int a4, int a5);

extern void POKE_TOOL_SetupPartyParamEx(void *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);

extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);

extern u32 func_02017E1C(void *p, u32 id, u32 v);

extern u32 POKE_TOOL_SetDefaultMoves(void *p);

extern u32 POKE_TOOL_AddMove(void *p, u32 move);

extern void POKE_TOOL_PushMove(void *p, int move);

extern void func_02018A00(void *p, u32 species, u32 arg);

extern u16 STRBUF_GetEosChar(void);

extern const void *func_020084F4(const void *p);

extern u8 func_02008550(const void *obj);

extern void *func_020185F0(void *p);

extern void SAVE_EVENT_WriteWithDate(void *a0, u32 a1, u32 a2, u32 a3, u32 a4);

extern void POKE_TOOL_RecalcParam(void *p);

extern int POKEGRA_GetArcID(void);

extern u32 func_02017EAC(void *p);

extern s32_021DD24C POKEGRA_GetPalArcIndex(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);

extern void *POKE_TOOL_GetBoxParam(void *p);

extern u32 POKEGRA_LoadCharDataPP(void *a0, void *mon, u32 a2, u32 a3);

void *MYSTERY_UTIL_CreateWindow(u32 a, u32 b, u16 c, u16 d, u8 e, u8 f, u8 g, u32 h, u16 heap);

void MYSTERY_UTIL_DeleteWindow(u8 *p);

void MYSTERY_UTIL_ClearWindow(u8 *p);

void MYSTERY_UTIL_ShowMessage(u8 *p, u16 a, int b, int c);

void MYSTERY_UTIL_ShowString(u8 *p, int a, int b);

void MYSTERY_UTIL_SetColor(u8 *p,unsigned v);

void MYSTERY_UTIL_SetPosition(char *p, u32 a, u32 b, int c);

int MYSTERY_UTIL_IsMessageDone(u8 *p);

void MYSTERY_UTIL_TransferWindowChars(u8 *p);

void MYSTERY_UTIL_ComputeTextPosition(const u8 *p,int a,Pair_021D9624 *out);

void MYSTERY_UTIL_AlignText(u32 mode, const Pair_021D9624 *in, const void *bitmap, void *obj, int a, Pair_021D9624 *out);

void *MYSTERY_UTIL_CreateMenuWindow(int a, u8 b, void *c, void *d, u16 heap);

void *MYSTERY_UTIL_CreateMenuWindow2(int a, u8 b, void *c, void *d, u16 heap);

void MYSTERY_UTIL_DeleteMenuWindow(u8 *p);

void MYSTERY_UTIL_UpdateMenuWindow(u8 *p);

void MYSTERY_UTIL_SetMenuMessage(u8 *a, int b, int c, int d);

void MYSTERY_UTIL_SetMenuMode(u8 *p,int mode);

unsigned MYSTERY_UTIL_GetMenuState(u8 *p);

void MYSTERY_UTIL_DrawMenuWindow(u8 *p, int a, int b);

void MYSTERY_UTIL_ResetMenuWindow(u8 *p);

void *MYSTERY_UTIL_CreateMenu(const u8 *p,u16 heap);

void MYSTERY_UTIL_DeleteMenu(u8 *p);

int MYSTERY_UTIL_UpdateMenu(char *p);

void *MYSTERY_UTIL_CreateWindowList(void *a,const char *desc,u32 n,u16 b,u8 c,u32 d,u16 e,int f,u16 heap);

void MYSTERY_UTIL_DeleteWindowList(u8 *p);

void MYSTERY_UTIL_ClearWindowList(u8 *p);

int MYSTERY_UTIL_IsWindowListDone(u8 *p);

void MYSTERY_UTIL_ClearListWindow(u8 *p,u32 i);

void MYSTERY_UTIL_TransferWindowList(u8 *p);

void *MYSTERY_UTIL_CreateBmpList(char *p,u16 heap);

void MYSTERY_UTIL_DeleteBmpList(u8 *p);

void MYSTERY_UTIL_DrawBmpList(char *p,char *desc,void *dst);

void MYSTERY_UTIL_CopyBmpList(u8 *p);

struct Out_021D9624 *MYSTERY_UTIL_CreateDetailWindow(const struct In *in, u16 heap);

void MYSTERY_UTIL_DeleteDetailWindow(u8 *p);

int MYSTERY_UTIL_SetVoice(u8 *p);

int MYSTERY_UTIL_Update(void **p);

void MYSTERY_UTIL_SetListValue(u8 *p,u32 i,u32 value);

void *MYSTERY_UTIL_CreateTask(void *a,void *b,u16 heap);

void MYSTERY_UTIL_DeleteTask(void *p);

void MYSTERY_UTIL_DispatchTask(char *p);

int MYSTERY_UTIL_GetTaskField04(u32 *p);

void MYSTERY_UTIL_SetTaskHandler(u32 *p,u32 a);

void MYSTERY_UTIL_MarkTaskDone(u32 *p);

void MYSTERY_UTIL_SetTaskArg(u32 *p,u32 a);

void MYSTERY_UTIL_GetTaskArg(u32 *p);

void *MYSTERY_UTIL_CreateTaskEx(const char *p,u16 a,u16 b,int c,u8 d,int e,void *f,void *g,u16 heap);

void MYSTERY_UTIL_DeleteActorPair(u8 *p);

void MYSTERY_UTIL_UpdateActorPair(char *p);

void MYSTERY_UTIL_SetActorPairText(char *p,int a,int b,int c);

void MYSTERY_UTIL_SetFlag(u8 *p,int a);

void MYSTERY_UTIL_SetVec(u32 *p,u32 a,u32 b,u32 c);

int MYSTERY_UTIL_IsMenuFinished(u8 *p);

void MYSTERY_UTIL_BuildPaletteRow(char *p,int a,int *out);

s32 MYSTERY_UTIL_BlendPalette(int a,u16 *p,int angle,int bank,u8 index,u16 c1,u16 c2);

void MYSTERY_UTIL_BlendPaletteRange(void *a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last);

char *MYSTERY_ALBUM_Create(const Input *src,u16 heap);

void MYSTERY_ALBUM_DeleteWork(MysteryAlbumWork *obj);

void MYSTERY_ALBUM_Update(Obj_021DAEF0 *obj);

void MYSTERY_ALBUM_UpdateWindows(char *p);

int MYSTERY_ALBUM_GetWindowState(char *p);

void MYSTERY_ALBUM_Setup(u8 *p, u16 heap);

void MYSTERY_ALBUM_Cleanup(char *p);

void MYSTERY_ALBUM_SetCursor(char *p,int a,int b,int c,u16 heap);

void MYSTERY_ALBUM_UpdateSlots(char *p,int a);

void MYSTERY_ALBUM_SetupSlot(char *p, int a, int b, int c, u16 index, u16 heap);

void MYSTERY_ALBUM_DeleteSlotActor(char *p,int a,u16 index);

void MYSTERY_ALBUM_StartScroll(u8 *p,int a);

int MYSTERY_ALBUM_UpdateScroll(char *p);

void MYSTERY_ALBUM_RemoveCard(MysteryAlbumWork *o, int idx);

void MYSTERY_ALBUM_SwapCards(MysteryAlbumWork *o, u32 a, u32 b);

int MYSTERY_ALBUM_GetColumnCount(char *p);

u32 MYSTERY_ALBUM_CountValidCards(u32 p);

void MYSTERY_ALBUM_SetupEntry(char *out,const Record_021DB938 *src,char *p,u16 heap);

void MYSTERY_ALBUM_ClearEntry(u32 p);

int MYSTERY_ALBUM_IsEntryValid(int *p);

void *MYSTERY_ALBUM_GetEntryBmp(void *p);

void *MYSTERY_ALBUM_CreateEntryArc(void *p,u16 heap);

u32 MYSTERY_ALBUM_GetEntryArcId(void *p);

u32 MYSTERY_ALBUM_GetEntryIconPalette(void *p);

int MYSTERY_ALBUM_GetEntryGraphicIndex(void *p);

int MYSTERY_ALBUM_GetEntrySpeciesId(void *p);

int MYSTERY_ALBUM_GetEntryFormId(void *p);

int MYSTERY_ALBUM_GetEntryKind(void *p);

char *MYSTERY_ALBUM_GetEntryCard(void *p);

int MYSTERY_ALBUM_GetEntryEggFlag(u32 p);

int MYSTERY_ALBUM_GetEntryIconX(void *p);

int MYSTERY_ALBUM_GetEntryIconY(void *p);

void MYSTERY_ALBUM_SelectHandler(void *task,u32 *state,char *p);

void MYSTERY_ALBUM_ConfirmHandler(void *task,u32 *state,u8 *p);

void MYSTERY_ALBUM_InfoHandler(void *task,u32 *state,char *p);

void MYSTERY_ALBUM_MoveHandler(void *task,u32 *state,char *p);

void MYSTERY_ALBUM_SaveHandler(void *arg,u32 *state,char *p);

void MYSTERY_ALBUM_SingleHandler(void *arg,int *state,char *p);

void MYSTERY_ALBUM_SetupIconSprite(char *p,void *arc,int id,int index,u8 other,u16 heap);

void MYSTERY_ALBUM_UpdateIconSprite(u8 *p,int b,int c,u16 d);

void *MYSTERY_ALBUM_CreateSlotWork(const Desc_021DCFC8 *p,u16 heap);

void MYSTERY_ALBUM_DeleteSlotWork(void **p);

int MYSTERY_ALBUM_UpdateSlotWork(void **p);

struct Out_021DC030 *MYSTERY_ALBUM_CreateAlbumView(Record_021DD24C *a, struct CtxB *b, void *c, u16 heap);

extern const char d_021DFBA0[];

extern const Config_021D9BC0 d_021DF78C;

extern const struct Tbl d_021DF7C0;

extern const TablePair d_021DF76C[];

extern const TablePair d_021DF770[];

extern const s16 FX_SinCosTable_[];

extern char d_021DFBB0[],d_021DF8FC[],d_021DF890[];

extern const Row data_021DF86E[];

extern const u8 d_021DF86E[];

extern const u8 d_021DF86F[];

extern const int d_021DF838[];

extern const int d_021DF848[];

extern char d_021DFBB0[];

extern const Config d_021DF99C;

extern const Desc_021DD24C d_021DFA14;

extern const u32 d_021DF8C0[];

extern u8 g0209DF08;

extern u8 g0209DF0C;

extern void *gSpeciesNameBank;

void *MYSTERY_UTIL_CreateWindow(u32 a, u32 b, u16 c, u16 d, u8 e, u8 f, u8 g, u32 h, u16 heap)
{
    u8 *p;
    void *q;
    p = func_02030734(heap, 0x28, 0, d_021DFBA0, 0x55);
    MI_CpuFill8(p, 0, 0x28);
    ((MysteryUtilWindow *)p)->printOwner = (void *)h;
    ((MysteryUtilWindow *)p)->textParam = b;
    ((MysteryUtilWindow *)p)->color = 0x440;
    ((MysteryUtilWindow *)p)->variant = a;
    ((MysteryUtilWindow *)p)->textBuf = STRBUF_Create(0x200, heap);
    q = (void *)BMP_WIN_Create((u8)b, (u16)c, (u16)d, (u8)e, f, g, 1);
    ((MysteryUtilWindow *)p)->bmpWin2 = q;
    ((MysteryUtilWindow *)p)->bmpWin = q;
    p[4] = 0;
    BMP_Clear(BMP_WIN_GetBmp(q), ((MysteryUtilWindow *)p)->color & 31);
    if (((MysteryUtilWindow *)p)->variant == 0) {
        BMP_WIN_TransferChars(((MysteryUtilWindow *)p)->bmpWin2);
        BMP_WIN_MakeScreen(((MysteryUtilWindow *)p)->bmpWin2);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(((MysteryUtilWindow *)p)->bmpWin2));
    }
    return p;
}

void MYSTERY_UTIL_DeleteWindow(u8 *p)
{
    BMP_WIN_Delete(((MysteryUtilWindow *)p)->bmpWin2);
    STRBUF_Delete(((MysteryUtilWindow *)p)->textBuf);
    func_020307B0(p);
}

void MYSTERY_UTIL_ClearWindow(u8 *p) { BMP_WIN_ClearScreen(((MysteryUtilWindow *)p)->bmpWin2); }

/*
 * extent: two zero padding bytes at 0x021D9AC6.
 */
void MYSTERY_UTIL_ShowMessage(u8 *p, u16 a, int b, int c)
{
    Pair_021D9624 xy;
    void *q;
    BMP_Clear(BMP_WIN_GetBmp(((MysteryUtilWindow *)p)->bmpWin2), ((MysteryUtilWindow *)p)->color & 31);
    func_02045CAC((struct MsgBank *)a, b, ((MysteryUtilWindow *)p)->textBuf);
    MYSTERY_UTIL_ComputeTextPosition(p, c, &xy);
    q = ((MysteryUtilWindow *)p)->printOwner;
    PRINTSYS_PrintQueColor(q, (u32)BMP_WIN_GetBmp(((MysteryUtilWindow *)p)->bmpWin), (s16)xy.x, (s16)xy.y,
                 (u32)(((MysteryUtilWindow *)p)->textBuf), c, ((MysteryUtilWindow *)p)->color);
    p[4] = 1;
}

/*
 * extent: two zero padding bytes at 0x021D9B26.
 */
void MYSTERY_UTIL_ShowString(u8 *p, int a, int b)
{
    Pair_021D9624 xy;
    void *q;
    BMP_Clear(BMP_WIN_GetBmp(((MysteryUtilWindow *)p)->bmpWin2), ((MysteryUtilWindow *)p)->color & 31);
    STRBUF_Copy(((MysteryUtilWindow *)p)->textBuf, (struct U16Vec *)a);
    MYSTERY_UTIL_ComputeTextPosition(p, b, &xy);
    q = ((MysteryUtilWindow *)p)->printOwner;
    PRINTSYS_PrintQueColor(q, (u32)BMP_WIN_GetBmp(((MysteryUtilWindow *)p)->bmpWin), (s16)xy.x, (s16)xy.y,
                 (u32)(((MysteryUtilWindow *)p)->textBuf), b, ((MysteryUtilWindow *)p)->color);
    p[4] = 1;
}

void MYSTERY_UTIL_SetColor(u8 *p,unsigned v) { ((MysteryUtilWindow *)p)->color=v; }

void MYSTERY_UTIL_SetPosition(char *p, u32 a, u32 b, int c)
{
    *(u32 *)(p + 0x18) = a;
    *(u32 *)(p + 0x1c) = b;
    *(u32 *)(p + 0x20) = c;
}

int MYSTERY_UTIL_IsMessageDone(u8 *p)
{
    u32 q;
    if (((MysteryUtilWindow *)p)->variant == 0) {
        q = (u32)((MysteryUtilWindow *)p)->printOwner;
        if (p[4]) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)q, (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((MysteryUtilWindow *)p)->bmpWin))) == 0) {
                BMP_WIN_TransferChars((struct Descriptor *)((MysteryUtilWindow *)p)->bmpWin);
                p[4] = 0;
            }
        }
        if (p[4] == 0) return 1;
        return 0;
    } else {
        if (p[4]) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)(((MysteryUtilWindow *)p)->printOwner), (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((MysteryUtilWindow *)p)->bmpWin))) == 0)
                p[4] = 0;
        }
        if (p[4] == 0) return 1;
        return 0;
    }
}

void MYSTERY_UTIL_TransferWindowChars(u8 *p) {
    BMP_WIN_TransferChars(((MysteryUtilWindow *)p)->bmpWin2);
    if(((MysteryUtilWindow *)p)->variant==1) {
        BMP_WIN_MakeScreen(((MysteryUtilWindow *)p)->bmpWin2);
        func_02041B6C(BMP_WIN_GetBgLayer(((MysteryUtilWindow *)p)->bmpWin2));
    }
}

/*
 * note: const record pointer settles stack-store schedule;
 *       two trailing zero alignment bytes.
 */
void MYSTERY_UTIL_ComputeTextPosition(const u8 *p,int a,Pair_021D9624 *out) {
    void *bitmap=BMP_WIN_GetBmp(((MysteryUtilWindow *)p)->bmpWin2);
    MYSTERY_UTIL_AlignText(((MysteryUtilWindow *)p)->mode,(const Pair_021D9624 *)(p+0x18),bitmap,((MysteryUtilWindow *)p)->textBuf,a,out);
}

/*
 * extent: two zero padding bytes at 0x021D9CA2.
 * lever: the two-coordinate copy in case 0 is a Pair_021D9624 assignment.
 */
void MYSTERY_UTIL_AlignText(u32 mode, const Pair_021D9624 *in, const void *bitmap, void *obj, int a, Pair_021D9624 *out)
{
    int x;
    int y;
    switch (mode) {
    case 0:
        *out = *in;
        return;
    case 1:
        x = (u32)BMP_GetWidth(bitmap) / 2;
        y = (u32)BMP_GetHeight(bitmap) / 2;
        x -= func_0201D304(obj, a, 0) / 2;
        y -= func_0201D42C(obj, (void *)a) / 2;
        out->x = x + in->x;
        out->y = y + in->y;
        return;
    case 2:
        y = (u32)BMP_GetHeight(bitmap) / 2;
        y -= func_0201D42C(obj, (void *)a) / 2;
        out->x = in->x;
        out->y = y + in->y;
        return;
    case 3:
        x = BMP_GetWidth(bitmap);
        x -= func_0201D304(obj, a, 0);
        if (x < 0) x = 0;
        out->x = x + in->x;
        out->y = in->y;
        break;
    }
}

static inline void *allocate(u16 heap, u32 size, const char *site, u16 line)
{
    return func_02030734(heap, size, 0, site, line);
}

/*
 * lever: final push 2026-10-05 G3L5. heap is a u16 parameter and every heap-taking callee
 *   (func_02030734 first parameter, STRBUF_Create second, TCBL_Create first two) declares it u16.
 *   The stack heap then loads as a word and the entry block keeps the original order
 *   (lsls of the line constant after the heap load). See
 *   docs/idioms/a-u16-heap-parameter-with-u16-callees-loads-as-a-word-and-keeps-the-entry-order.md.
 *   Twin: ov177 WIFIBATTLEMATCH_UTIL_Create.
 */
void *MYSTERY_UTIL_CreateMenuWindow(int a, u8 b, void *c, void *d, u16 heap)
{
    u8 *p;
    void *q;
    p = allocate(heap, 0x40, d_021DFBA0, 0x184);
    MI_CpuFill8(p, 0, 0x40);
    *(u16 *)(p + 0x18) = 15;
    *(void **)(p + 4) = d;
    *(void **)(p + 0x24) = c;
    *(u32 *)(p + 0x28) = 3;
    *(void **)(p + 0x14) = STRBUF_Create(0x300, heap);
    q = (void *)BMP_WIN_Create((u8)a, 1, 19, 30, 4, b, 1);
    *(void **)(p + 0x10) = q;
    *(void **)(p + 0x1c) = q;
    p[0x20] = 0;
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(p + 0x10)), *(u16 *)(p + 0x18));
    q = *(void **)(p + 0x10);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(q));
    *(void **)(p + 0xc) = TCBL_Create(heap, heap, 1, 32);
    return p;
}

/*
 * lever: final push 2026-10-05 G4L9. heap is a u16 parameter and every heap-taking callee
 *   (func_02030734 first parameter, STRBUF_Create second, TCBL_Create first two) declares it u16.
 *   The stack heap then loads as a word and the entry block keeps the original order. See
 *   docs/idioms/a-u16-heap-parameter-with-u16-callees-loads-as-a-word-and-keeps-the-entry-order.md.
 *   Twin: ov121 MYSTERY_UTIL_CreateMenuWindow.
 */
void *MYSTERY_UTIL_CreateMenuWindow2(int a, u8 b, void *c, void *d, u16 heap)
{
    u8 *p;
    struct Descriptor *q;
    p = func_02030734(heap, 0x40, 0, d_021DFBA0, 0x1ae);
    MI_CpuFill8(p, 0, 0x40);
    *(u16 *)(p + 0x18) = 15;
    *(void **)(p + 4) = d;
    *(void **)(p + 0x24) = c;
    *(u32 *)(p + 0x28) = 3;
    PRINTSYS_CTRL_Init(p + 0x34, 2);
    *(struct U16Vec **)(p + 0x14) = STRBUF_Create(0x200, heap);
    q = (struct Descriptor *)BMP_WIN_Create((u8)a, 1, 21, 30, 2, b, 1);
    *(struct Descriptor **)(p + 0x10) = q;
    *(struct Descriptor **)(p + 0x1c) = q;
    p[0x20] = 0;
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0x10)), *(u16 *)(p + 0x18));
    q = *(struct Descriptor **)(p + 0x10);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen((struct Cfg *)q);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(q));
    *(struct Tcbl **)(p + 0xc) = TCBL_Create(heap, heap, 1, 32);
    return p;
}

void MYSTERY_UTIL_DeleteMenuWindow(u8 *p)
{
    if (((MysteryUtilMenuWindow *)p)->printStream) {
        PRINTSYS_PrintStreamDelete(((MysteryUtilMenuWindow *)p)->printStream);
        ((MysteryUtilMenuWindow *)p)->printStream = 0;
    }
    if (((MysteryUtilMenuWindow *)p)->timeIcon) {
        TIME_ICON_Delete(((MysteryUtilMenuWindow *)p)->timeIcon);
        ((MysteryUtilMenuWindow *)p)->timeIcon = 0;
    }
    if (((MysteryUtilMenuWindow *)p)->keyCursor) APP_KEYCURSOR_Delete((int)(((MysteryUtilMenuWindow *)p)->keyCursor));
    TCBL_Destroy(((MysteryUtilMenuWindow *)p)->tcbl);
    BMP_MENUWORK_DrawWindowBorder(((MysteryUtilMenuWindow *)p)->bmpWin, 0);
    BMP_WIN_Delete(((MysteryUtilMenuWindow *)p)->bmpWin);
    STRBUF_Delete(((MysteryUtilMenuWindow *)p)->textBuf);
    func_020307B0(p);
}

/*
 * extent: two trailing zero padding bytes at 0x021D9F06.
 */
void MYSTERY_UTIL_UpdateMenuWindow(u8 *p)
{
    u32 q;
    switch (((MysteryUtilMenuWindow *)p)->state) {
    case 2:
        q = ((MysteryUtilMenuWindow *)p)->elementSlot;
        if (p[0x20]) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)q, (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((MysteryUtilMenuWindow *)p)->bmpWin2))) == 0) {
                BMP_WIN_TransferChars((struct Descriptor *)((MysteryUtilMenuWindow *)p)->bmpWin2);
                p[0x20] = 0;
            }
        }
        break;
    case 0:
        q = ((MysteryUtilMenuWindow *)p)->elementSlot;
        if (p[0x20]) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)q, (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((MysteryUtilMenuWindow *)p)->bmpWin2))) == 0) {
                BMP_WIN_TransferChars((struct Descriptor *)((MysteryUtilMenuWindow *)p)->bmpWin2);
                p[0x20] = 0;
            }
        }
        ((MysteryUtilMenuWindow *)p)->result = p[0x20] == 0 ? 1 : 0;
        break;
    case 1:
        if (((MysteryUtilMenuWindow *)p)->printStream) {
            if (((MysteryUtilMenuWindow *)p)->keyCursor)
                APP_KEYCURSOR_Update((struct Ctx *)(((MysteryUtilMenuWindow *)p)->keyCursor), (void *)(((MysteryUtilMenuWindow *)p)->printStream), (void *)(((MysteryUtilMenuWindow *)p)->bmpWin));
            if (PRINTSYS_CTRL_Update((struct Blk *)(p + 0x34), (void *)(((MysteryUtilMenuWindow *)p)->printStream)))
                ((MysteryUtilMenuWindow *)p)->result = 1;
        }
        break;
    case 3:
        break;
    }
    TCBL_Main((struct Tcbl *)(((MysteryUtilMenuWindow *)p)->tcbl));
}

void MYSTERY_UTIL_SetMenuMessage(u8 *a, int b, int c, int d)
{
    func_02045CAC((struct MsgBank *)b, c, ((MysteryUtilMenuWindow *)a)->textBuf);
    MYSTERY_UTIL_SetMenuMode(a, d);
}

void MYSTERY_UTIL_SetMenuMode(u8 *p,int mode)
{
    u32 q;
    BMP_Clear(BMP_WIN_GetBmp(((MysteryUtilMenuWindow *)p)->bmpWin),((MysteryUtilMenuWindow *)p)->height);
    if(((MysteryUtilMenuWindow *)p)->printStream) {
        PRINTSYS_PrintStreamDelete(((MysteryUtilMenuWindow *)p)->printStream);
        ((MysteryUtilMenuWindow *)p)->printStream=0;
    }
    if(((MysteryUtilMenuWindow *)p)->keyCursor) {
        APP_KEYCURSOR_Delete((int)(((MysteryUtilMenuWindow *)p)->keyCursor));
        ((MysteryUtilMenuWindow *)p)->keyCursor=0;
    }
    MYSTERY_UTIL_ResetMenuWindow(p);
    switch(mode) {
    case 2:
        ((MysteryUtilMenuWindow *)p)->timeIcon=TIME_ICON_Create((void *)func_020056BC(),((MysteryUtilMenuWindow *)p)->bmpWin,((MysteryUtilMenuWindow *)p)->height,16,((MysteryUtilMenuWindow *)p)->heapTag);
        q=((MysteryUtilMenuWindow *)p)->elementSlot;
        PRINTSYS_PrintQue((struct PrintSys *)q,(u32)BMP_WIN_GetBmp(((MysteryUtilMenuWindow *)p)->bmpWin2),0,0,((MysteryUtilMenuWindow *)p)->textBuf,((MysteryUtilMenuWindow *)p)->printArg);
        p[0x20]=1;
        ((MysteryUtilMenuWindow *)p)->state=0;
        break;
    case 0:
        q=((MysteryUtilMenuWindow *)p)->elementSlot;
        PRINTSYS_PrintQue((struct PrintSys *)q,(u32)BMP_WIN_GetBmp(((MysteryUtilMenuWindow *)p)->bmpWin2),0,0,((MysteryUtilMenuWindow *)p)->textBuf,((MysteryUtilMenuWindow *)p)->printArg);
        p[0x20]=1;
        ((MysteryUtilMenuWindow *)p)->state=0;
        break;
    case 1:
        PRINTSYS_CTRL_Init(p+0x34,2);
        ((MysteryUtilMenuWindow *)p)->keyCursor=APP_KEYCURSOR_CreateDefault(((MysteryUtilMenuWindow *)p)->height,1,0,((MysteryUtilMenuWindow *)p)->heapTag);
        ((MysteryUtilMenuWindow *)p)->printStream=PRINTSYS_PrintStream(((MysteryUtilMenuWindow *)p)->bmpWin,0,0,*(u32 *)&((MysteryUtilMenuWindow *)p)->textBuf,((MysteryUtilMenuWindow *)p)->printArg,MSG_SPEED_GetWait(),((MysteryUtilMenuWindow *)p)->tcbl,0,((MysteryUtilMenuWindow *)p)->heapTag,((MysteryUtilMenuWindow *)p)->height);
        ((MysteryUtilMenuWindow *)p)->state=1;
        break;
    }
    ((MysteryUtilMenuWindow *)p)->result=0;
}

unsigned MYSTERY_UTIL_GetMenuState(u8 *p) { return ((MysteryUtilMenuWindow *)p)->result; }

void MYSTERY_UTIL_DrawMenuWindow(u8 *p, int a, int b)
{
    BMP_MENUWORK_DrawWindow(((MysteryUtilMenuWindow *)p)->bmpWin, 0, a, b);
}

void MYSTERY_UTIL_ResetMenuWindow(u8 *p) { ((MysteryUtilMenuWindow *)p)->result=1; if(*(u8 * *)&((MysteryUtilMenuWindow *)p)->timeIcon) { TIME_ICON_Delete(*(u8 * *)&((MysteryUtilMenuWindow *)p)->timeIcon); *(u32 *)&((MysteryUtilMenuWindow *)p)->timeIcon=0; BMP_WIN_MakeScreen(((MysteryUtilMenuWindow *)p)->bmpWin); BG_SYS_PushTile(BMP_WIN_GetBgLayer(((MysteryUtilMenuWindow *)p)->bmpWin)); } }

/*
 * lever: const source parameter and the original heap stack argument to 0201F878.
 */
void *MYSTERY_UTIL_CreateMenu(const u8 *p,u16 heap)
{
    u8 *out;
    void *q;
    u32 i;
    Config_021D9BC0 cfg;
    out=func_02030734(heap,24,0,d_021DFBA0,0x2cb);
    MI_CpuFill8(out,0,24);
    ((MysteryUtilMenu *)out)->printOwner=((MysteryUtilMenuDef *)p)->printOwner;
    ((MysteryUtilMenu *)out)->bmpWin=(void *)BMP_WIN_Create((u8)(((MysteryUtilMenuDef *)p)->bgLayer),(u16)19,(u16)((u8)(17-(u8)(((MysteryUtilMenuDef *)p)->count*2))),(u8)12,(u8)(((MysteryUtilMenuDef *)p)->count*2),((MysteryUtilMenuDef *)p)->palette,1);
    BMP_MENUWORK_DrawWindow(((MysteryUtilMenu *)out)->bmpWin,2,((MysteryUtilMenuDef *)p)->windowY,(u8)(((MysteryUtilMenuDef *)p)->windowX));
    q=((MysteryUtilMenu *)out)->bmpWin;
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(q));
    ((MysteryUtilMenu *)out)->bmpWin2=((MysteryUtilMenu *)out)->bmpWin;
    out[12]=0;
    ((MysteryUtilMenu *)out)->menuWork=BMP_MENUWORK_Create(((MysteryUtilMenuDef *)p)->count,heap);
    for(i=0;i<((MysteryUtilMenuDef *)p)->count;i++)
        BMP_MENUWORK_AddMsgItem(((MysteryUtilMenu *)out)->menuWork,((MysteryUtilMenuDef *)p)->menuTable,*(u32 *)(p+12+i*4),i,(u16)heap);
    cfg=d_021DF78C;
    cfg.word[0]=*(u32 *)&((MysteryUtilMenu *)out)->menuWork;
    *(u16 *)((u8 *)&cfg+0x10)=((MysteryUtilMenuDef *)p)->count;
    *(u16 *)((u8 *)&cfg+0x12)=((MysteryUtilMenuDef *)p)->count;
    cfg.word[3]=*(u32 *)&((MysteryUtilMenu *)out)->bmpWin;
    cfg.word[9]=((MysteryUtilMenuDef *)p)->menuTable;
    cfg.word[10]=(u32)(out+8);
    cfg.word[11]=((MysteryUtilMenuDef *)p)->printOwner;
    cfg.word[12]=((MysteryUtilMenuDef *)p)->messageTable;
    ((MysteryUtilMenu *)out)->menuList=BMP_MENULIST_Create((struct Src *)(&cfg),0,0,heap);
    func_02020CF8(((MysteryUtilMenu *)out)->menuList,heap);
    func_02020D10(((MysteryUtilMenu *)out)->menuList,0);
    return out;
}

void MYSTERY_UTIL_DeleteMenu(u8 *p) { BMP_MENULIST_Delete(((MysteryUtilMenu *)p)->menuList,0,0); BMP_MENUWORK_Delete(((MysteryUtilMenu *)p)->menuWork); BMP_MENUWORK_DrawWindowBorder(((MysteryUtilMenu *)p)->bmpWin,0); BMP_WIN_ClearScreen(((MysteryUtilMenu *)p)->bmpWin); BMP_WIN_Delete(((MysteryUtilMenu *)p)->bmpWin); func_020307B0(p); }

/*
 * extent: two bytes of zero alignment padding follow the return.
 */
int MYSTERY_UTIL_UpdateMenu(char *p)
{
    u32 q = ((MysteryUtilMenu *)p)->printOwner;
    int r;
    if (((MysteryUtilMenu *)p)->winFlag) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)q,(void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((MysteryUtilMenu *)p)->bmpWin2))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)((MysteryUtilMenu *)p)->bmpWin2);
            ((MysteryUtilMenu *)p)->winFlag=0;
        }
    }
    r=BMP_MENULIST_Main(((MysteryUtilMenu *)p)->menuList);
    if (r == -2) r=func_02020350(((MysteryUtilMenu *)p)->menuList,2)-1;
    return r;
}

/*
 * lever: b is u16; const descriptor input and an element slot pointer reproduce scheduling.
 */
void *MYSTERY_UTIL_CreateWindowList(void *a,const char *desc,u32 n,u16 b,u8 c,u32 d,u16 e,int f,u16 heap)
{
    u32 i;
    int size=n*4+16;
    char *out=func_02030734(heap,size,0,d_021DFBA0,0x374);
    MI_CpuFill8(out,0,size);
    *(const char * *)&((MysteryUtilWindowList *)out)->desc=desc;
    ((MysteryUtilWindowList *)out)->count=n;
    ((MysteryUtilWindowList *)out)->printOwner=f;
    ((MysteryUtilWindowList *)out)->msgBank=e;
    for(i=0;i<((MysteryUtilWindowList *)out)->count;i++) {
        const char *v=desc+i*24;
        char *slot=out+i*4;
        void *q=MYSTERY_UTIL_CreateWindow((u32)a,b,((MysteryUtilMenuEntry *)v)->u0.bytes[0],((MysteryUtilMenuEntry *)v)->u0.bytes[1],((MysteryUtilMenuEntry *)v)->u0.bytes[2],((MysteryUtilMenuEntry *)v)->u0.bytes[3],c,d,heap);
        ((struct Obj08093 *)slot)->f10=q;
        MYSTERY_UTIL_SetPosition(q,((MysteryUtilMenuEntry *)v)->posX,((MysteryUtilMenuEntry *)v)->posY,((MysteryUtilMenuEntry *)v)->layoutMode);
        MYSTERY_UTIL_SetColor(((struct Obj08093 *)slot)->f10,((MysteryUtilMenuEntry *)v)->color);
        if(((MysteryUtilMenuEntry *)v)->stringId) MYSTERY_UTIL_ShowString(((struct Obj08093 *)slot)->f10,((MysteryUtilMenuEntry *)v)->stringId,((MysteryUtilWindowList *)out)->printOwner);
        else MYSTERY_UTIL_ShowMessage(((struct Obj08093 *)slot)->f10,e,((MysteryUtilMenuEntry *)v)->messageId,((MysteryUtilWindowList *)out)->printOwner);
    }
    return out;
}

void MYSTERY_UTIL_DeleteWindowList(u8 *p) { u32 i; for(i=0;i<((MysteryUtilWindowList *)p)->count;i++) MYSTERY_UTIL_DeleteWindow(*(u8 **)(p+16+i*4)); func_020307B0(p); }

void MYSTERY_UTIL_ClearWindowList(u8 *p) { u32 i; for(i=0;i<((MysteryUtilWindowList *)p)->count;i++) MYSTERY_UTIL_ClearWindow(*(u8 **)(p+16+i*4)); }

int MYSTERY_UTIL_IsWindowListDone(u8 *p) { u32 i; int result=1; for(i=0;i<((MysteryUtilWindowList *)p)->count;i++) result &= MYSTERY_UTIL_IsMessageDone(*(u8 **)(p+16+i*4)); return result; }

void MYSTERY_UTIL_ClearListWindow(u8 *p,u32 i) { u8 *d=*(u8 **)(p+16+i*4); BMP_Clear(BMP_WIN_GetBmp(((MysteryUtilWindow *)d)->bmpWin2),((MysteryUtilWindow *)d)->color&31); BMP_WIN_TransferChars(*(void **)(*(u8 **)(p+16+i*4)+12)); }

void MYSTERY_UTIL_TransferWindowList(u8 *p) { u32 i; for(i=0;i<((MysteryUtilWindowList *)p)->count;i++) MYSTERY_UTIL_TransferWindowChars(*(u8 **)(p+16+i*4)); }

/*
 * lever: heap is u16 in this function and the two callees receiving it.
 */
void *MYSTERY_UTIL_CreateBmpList(char *p,u16 heap)
{
    u32 i;
    int size=((MysteryUtilWindowList *)p)->count*4+8;
    char *out=func_02030734(heap,size,0,d_021DFBA0,0x42e);
    MI_CpuFill8(out,0,size);
    *(char * *)&((MysteryUtilBmpList *)out)->srcList=p;
    ((MysteryUtilBmpList *)out)->heapId=heap;
    for(i=0;i<((MysteryUtilWindowList *)p)->count;i++) {
        void *win=BMP_WIN_GetBmp(*(void **)(*(char **)(p+16+i*4)+12));
        u32 x=BMP_GetWidth(win);
        u32 y=BMP_GetHeight(win);
        u32 type=BMP_GetTileBytes(win);
        *(void **)(out+i*4+8)=BMP_Create(x/8,y/8,type,heap);
    }
    return out;
}

void MYSTERY_UTIL_DeleteBmpList(u8 *p) { u32 i; for(i=0;i<((MysteryUtilWindowList *)(*(u8 * *)&((struct Obj22883 *)p)->f4))->count;i++) BMP_Delete(*(void **)(p+8+i*4)); func_020307B0(p); }

/*
 * extent: two bytes of zero alignment padding follow the return.
 */
void MYSTERY_UTIL_DrawBmpList(char *p,char *desc,void *dst)
{
    u32 i;
    Pair_021D9624 pos,out;
    void *text=STRBUF_Create(512,((MysteryUtilBmpList *)p)->heapId);
    for(i=0;i<((MysteryUtilWindowList *)(*(char * *)&((struct Obj06449 *)p)->f4))->count;i++) {
        char *d=desc+i*24;
        if(((MysteryUtilMenuEntry *)d)->u0.flags) {
            BMP_Clear(*(void **)(p+i*4+8),(u8)(((MysteryUtilMenuEntry *)d)->color&31));
            pos.x=((MysteryUtilMenuEntry *)d)->posX;
            pos.y=((MysteryUtilMenuEntry *)d)->posY;
            MYSTERY_UTIL_AlignText(((MysteryUtilMenuEntry *)d)->layoutMode,&pos,*(void **)(p+i*4+8),text,((MysteryUtilWindowList *)(*(char * *)&((struct Obj06449 *)p)->f4))->printOwner,&out);
            if(((MysteryUtilMenuEntry *)d)->stringId) STRBUF_Copy(text,(struct U16Vec *)(((MysteryUtilMenuEntry *)d)->stringId));
            else func_02045CAC((struct MsgBank *)(((MysteryUtilWindowList *)(*(char * *)&((struct Obj06449 *)p)->f4))->msgBank),((MysteryUtilMenuEntry *)d)->messageId,text);
            PRINTSYS_PrintQueColor(dst,(u32)(*(void **)(p+i*4+8)),(s16)out.x,(s16)out.y,(u32)text,((MysteryUtilWindowList *)(*(char * *)&((struct Obj06449 *)p)->f4))->printOwner,((MysteryUtilMenuEntry *)d)->color);
        }
    }
    func_020307B0(text);
}

void MYSTERY_UTIL_CopyBmpList(u8 *p) { u32 i; for(i=0;i<((MysteryUtilWindowList *)(*(u8 * *)&((struct Obj13954 *)p)->f4))->count;i++) { void *out=*(void **)(p+8+i*4); BMP_CopyPixels(out,BMP_WIN_GetBmp(*(void **)(*(u8 **)(*(u8 * *)&((MysteryUtilBmpList *)p)->srcList+16+i*4)+12))); } }

/*
 * note (2026-10-05, lane T7, pengy's share): written bottom-up from the listing.
 *   heap is u16 (callees take it as u16). The input record is const, the
 *   output field f60 is a pointer typed like in->f3c: with a u32 f60 the second
 *   read of in->f3c was merged (4 B short). Struct copy t = d_021DF7C0 (4 records of
 *   24 B). The caller passes a 0x38 B input record and heap.
 */
struct Out_021D9624 *MYSTERY_UTIL_CreateDetailWindow(const struct In *in, u16 heap)
{
    struct Tbl t;
    struct Pt pt;
    u32 i;
    u8 c;
    u16 w;
    struct Out_021D9624 *out = func_02030734(heap, 0x64, 0, d_021DFBA0, 0x4e7);
    MI_CpuFill8(out, 0, 0x64);
    out->fC = in->f20;
    out->f4 = (u32)in->fC_;
    out->f26 = in->f26;
    out->f2a = in->f28;
    out->f2c = in->f2a;
    out->f28 = in->f24;
    out->f34 = in->f34;
    out->f38 = in->f38;
    out->f2e = in->f2c;
    out->f30 = in->f30;
    out->f60 = in->f3c;
    if (in->f3c) {
        u32 v = *in->f3c;
        out->f8 = v;
        out->f8 = (v > out->fC - 1) ? out->fC - 1 : v;
    }
    for (i = 0; i < out->fC; i++)
        out->pal[i] = *(u16 *)(0x05000000 + in->f2a * 32 + (i + 10) * 2);
    out->f22 = *(u16 *)(0x0500001E + in->f2a * 32);
    t = d_021DF7C0;
    for (i = 0; i < out->fC; i++) {
        struct Rec_021D9624 *r = &t.r[i];
        r->b += (u8)in->f2c;
        r->a += (u8)in->f2e;
        if (in->bank) r->h = func_02045EC0(in->bank, in->ids[i]);
        else r->h = STRBUF_Clone((struct U16Vec *)in->ids[i], (u16)((heap & 0x7FFF) | 0x8000));
    }
    c = in->f26;
    w = in->f24;
    /* stand-in: unprototyped call; the prototype's u16/u8 parameters narrow the arguments and change the bytes */
    out->f0 = ((void *(*)())MYSTERY_UTIL_CreateWindowList)(0, (const char *)&t, out->fC, w, c, in->f8, (u32)in->bank, in->f4, heap);
    for (i = 0; i < out->fC; i++)
        if (t.r[i].h) STRBUF_Delete(t.r[i].h);
    pt.x = d_021DF76C[out->f8].x;
    pt.y = d_021DF770[out->f8].x + in->f2c * 8;
    CLACT_AddActorSurfacePos((void *)out->f4, (const struct Vec2 *)(&pt), 0);
    CLACT_SetActorDrawEnable((void *)out->f4, 1);
    CLACT_SetActorAnimSeq((void *)out->f4, out->f30);
    CLACT_SetActorAutoAnim((void *)out->f4, 1);
    return out;
}

void MYSTERY_UTIL_DeleteDetailWindow(u8 *p) { if(*(u32 * *)&((struct Obj03786 *)p)->f60 && ((struct Obj03786 *)p)->f8!=3) **(u32 * *)&((struct Obj03786 *)p)->f60=((struct Obj03786 *)p)->f8; CLACT_SetActorDrawEnable(((struct Obj03786 *)p)->f4,0); MYSTERY_UTIL_ClearWindowList(*(u8 * *)&((struct Obj03786 *)p)->f0); MYSTERY_UTIL_DeleteWindowList(*(u8 * *)&((struct Obj03786 *)p)->f0); BG_SYS_PushTile((u8)(((struct Obj03786 *)p)->f28)); func_020307B0(p); }

/*
 * arithmetic: direct division helper uses quotient r0/remainder r1 as a scalar u64;
 *             the caller admits count zero, so ordinary C remainder is not used.
 */
int MYSTERY_UTIL_SetVoice(u8 *p)
{
    u32 keys=KEY_GetTrg();
    u32 repeat=KEY_GetRepeat();
    int changed=0;
    int i;
    int phase;
    int oldphase;
    u32 index;
    Position_021D9624 pos;
    if(repeat&64) {
        index=((struct Obj00360 *)p)->f8==0 ? ((struct Obj00360 *)p)->fC-1 : ((struct Obj00360 *)p)->f8-1;
        ((struct Obj00360 *)p)->f8=index;
        if(((struct Obj00360 *)p)->fC!=1) GFL_USE_PlaySeDefaultVolume(0x548);
        changed=1;
    } else if(repeat&128) {
        if(((struct Obj00360 *)p)->fC!=1) GFL_USE_PlaySeDefaultVolume(0x548);
        ((struct Obj00360 *)p)->f8+=1;
        ((struct Obj00360 *)p)->f8=(u32)(_u32_div_f(((struct Obj00360 *)p)->f8,((struct Obj00360 *)p)->fC)>>32);
        changed=1;
    } else if(keys&1) {
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return ((struct Obj00360 *)p)->f8;
    } else if(keys&2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        if(((struct Obj00360 *)p)->fC==1) return -2;
        if(((struct Obj00360 *)p)->f8!=3) **(u32 * *)&((struct Obj00360 *)p)->f60=((struct Obj00360 *)p)->f8;
        ((struct Obj00360 *)p)->f8=((struct Obj00360 *)p)->fC-1;
        return ((struct Obj00360 *)p)->f8;
    }
    if(changed) {
        pos.x=d_021DF76C[*(u32 *)(p+8)].x;
        pos.y=d_021DF76C[*(u32 *)(p+8)].y+((struct Obj00360 *)p)->f2E*8;
        CLACT_AddActorSurfacePos(((struct Obj00360 *)p)->f4,(const struct Vec2 *)(&pos),0);
        if(((struct Obj00360 *)p)->f8==3) CLACT_SetActorAnimSeq(((struct Obj00360 *)p)->f4,2);
        else CLACT_SetActorAnimSeq(((struct Obj00360 *)p)->f4,((struct Obj00360 *)p)->f30);
        if(*(void (**)(u32))(p+0x34)) (*(void (**)(u32))(p+0x34))(((struct Obj00360 *)p)->f38);
    }
    oldphase=((struct Obj00360 *)p)->f24;
    phase=oldphase+0x400;
    if(phase>=0x10000) ((struct Obj00360 *)p)->f24=oldphase-0xfc00;
    else ((struct Obj00360 *)p)->f24=phase;
    for(i=0;i<4;i++) {
        u8 *v=p+i*4;
        if(((struct Obj06450 *)v)->f4C!=((struct Obj06450 *)v)->f3C && ((struct Obj00360 *)p)->f24>=0x7dff && ((struct Obj00360 *)p)->f24<=0x81ff)
            ((struct Obj06450 *)v)->f3C=((struct Obj06450 *)v)->f4C;
        if(((struct Obj06450 *)v)->f3C)
            MYSTERY_UTIL_BlendPalette((int)((void *)15),(u16 *)(p+0x1a+i*2),((struct Obj00360 *)p)->f24,(u8)(((struct Obj00360 *)p)->f2C),(u8)(i+10),*(u16 *)(p+0x12+i*2),((struct Obj00360 *)p)->f22);
    }
    return -1;
}

/*
 * Addresses are Black-image addresses.
 */
int MYSTERY_UTIL_Update(void **p)
{
    return MYSTERY_UTIL_IsWindowListDone(*p);
}

void MYSTERY_UTIL_SetListValue(u8 *p,u32 i,u32 value)
{
    *(u32 *)(p+i*4+76)=value;
}

void *MYSTERY_UTIL_CreateTask(void *a,void *b,u16 heap) { u8 *p; p=func_02030734(heap,20,0,d_021DFBA0,0x61c); MI_CpuFill8(p,0,20); ((struct Obj22893 *)p)->fC=a; MYSTERY_UTIL_SetTaskHandler((u32 *)p,(u32)b); return p; }

void MYSTERY_UTIL_DeleteTask(void *p) { func_020307B0(p); }

void MYSTERY_UTIL_DispatchTask(char *p)
{
    if (((struct Obj13955 *)p)->f4 == 0)
        (*(void (**)(char *, char *, u32))p)(p, p + 8, ((struct Obj13955 *)p)->fC);
}

int MYSTERY_UTIL_GetTaskField04(u32 *p) { return p[1]; }

void MYSTERY_UTIL_SetTaskHandler(u32 *p,u32 a) { p[0]=a; p[2]=0; }

void MYSTERY_UTIL_MarkTaskDone(u32 *p) { p[1]=1; }

void MYSTERY_UTIL_SetTaskArg(u32 *p,u32 a) { p[4]=a; }

void MYSTERY_UTIL_GetTaskArg(u32 *p) { p[2]=p[4]; }

/*
 * lever: a and b are u16; the descriptor input pointer is const.
 */
void *MYSTERY_UTIL_CreateTaskEx(const char *p,u16 a,u16 b,int c,u8 d,int e,void *f,void *g,u16 heap)
{
    Desc_021DA3EC desc;
    char *out=func_02030734(heap,36,0,d_021DFBA0,0x6b1);
    MI_CpuFill8(out,0,36);
    ((struct Obj06451 *)out)->f20=g;
    ((struct Obj06451 *)out)->f18=STRBUF_Create(128,heap);
    ((struct Obj06451 *)out)->f0=BMP_Create(a,b,32,heap);
    MI_CpuFill8(&desc,0,24);
    desc.win=((struct Obj06451 *)out)->f0;
    desc.x=((struct Obj08095 *)p)->f0;
    desc.y=((struct Obj08095 *)p)->f2;
    desc.z=c;
    desc.a=((struct Obj08095 *)p)->f6;
    desc.c=e;
    desc.d=e;
    desc.b=((struct Obj08095 *)p)->f7;
    desc.pal=d;
    ((struct Obj06451 *)out)->f1C=BMP_OAM_Create(f,(const struct Param *)(&desc));
    return out;
}

void MYSTERY_UTIL_DeleteActorPair(u8 *p) { BMP_OAM_Delete(((struct Obj10414 *)p)->f1C); BMP_Delete(((struct Obj10414 *)p)->f0); STRBUF_Delete(((struct Obj10414 *)p)->f18); func_020307B0(p); }

void MYSTERY_UTIL_UpdateActorPair(char *p)
{
    BMP_Clear((struct CharBuf *)(((struct Obj10415 *)p)->f0), (unsigned char)(((struct Obj10415 *)p)->f4 & 0x1f));
    BMP_OAM_UploadChars(((struct Obj10415 *)p)->f1C);
}

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void MYSTERY_UTIL_SetActorPairText(char *p,int a,int b,int c)
{
    int xy[2];
    BMP_Clear((struct CharBuf *)(((struct Obj03787 *)p)->f0),(u8)(((struct Obj03787 *)p)->f4&31));
    func_02045CAC((struct MsgBank *)a,b,((struct Obj03787 *)p)->f18);
    MYSTERY_UTIL_BuildPaletteRow(p,c,xy);
    PRINTSYS_PrintQueColor(((struct Obj03787 *)p)->f20,((struct Obj03787 *)p)->f0,(s16)xy[0],(s16)xy[1],(u32)(((struct Obj03787 *)p)->f18),c,((struct Obj03787 *)p)->f4);
    ((struct Obj03787 *)p)->f8=1;
}

void MYSTERY_UTIL_SetFlag(u8 *p,int a) { ((struct Obj22897 *)p)->f4=a; }

void MYSTERY_UTIL_SetVec(u32 *p,u32 a,u32 b,u32 c) { p[3]=a; p[4]=b; p[5]=c; }

int MYSTERY_UTIL_IsMenuFinished(u8 *p) { if(((struct Obj05358 *)p)->f8) { if(PRINTSYS_QUE_IsExistTarget((struct PrintSys *)(((struct Obj05358 *)p)->f20),(void *)(((struct Obj05358 *)p)->f0))==0) { BMP_OAM_UploadChars(((struct Obj05358 *)p)->f1C); ((struct Obj05358 *)p)->f8=0; } } if(((struct Obj05358 *)p)->f8==0) return 1; return 0; }

/*
 * extent: two bytes of zero alignment padding after the return.
 * lever: case 0 is an eight-byte aggregate copy (existing pair-copy idiom).
 */
void MYSTERY_UTIL_BuildPaletteRow(char *p,int a,int *out)
{
    int x,y;
    switch(((struct Obj02470 *)p)->f14) {
    case 0:
        *(Pair_021D9624 *)out=*(Pair_021D9624 *)(p+12);
        break;
    case 1:
        x=BMP_GetWidth((const struct Bmp *)(((struct Obj02470 *)p)->f0))/2;
        y=BMP_GetHeight((const struct Bmp *)(((struct Obj02470 *)p)->f0))/2;
        x-=func_0201D304(((struct Obj02470 *)p)->f18,a,0)/2;
        y-=func_0201D42C(((struct Obj02470 *)p)->f18,(void *)a)/2;
        out[0]=x+((struct Obj02470 *)p)->fC;
        out[1]=y+((struct Obj02470 *)p)->f10;
        break;
    case 2:
        x=BMP_GetHeight((const struct Bmp *)(((struct Obj02470 *)p)->f0))/2;
        x-=func_0201D42C(((struct Obj02470 *)p)->f18,(void *)a)/2;
        out[0]=((struct Obj02470 *)p)->fC;
        out[1]=x+((struct Obj02470 *)p)->f10;
        break;
    }
}

static inline u16 blend(u16 c1,u16 c2,s16 factor) {
 u8 g1,r1,b1; int db,dr,dg;
 g1=(c1&0x3e0)>>5;
 r1=c1&31;
 b1=(c1&0x7c00)>>10;
 db=(factor*((u8)((c2&0x7c00)>>10)-b1))>>12;
 dr=(factor*((u8)(c2&31)-r1))>>12;
 dg=(factor*((u8)((c2&0x3e0)>>5)-g1))>>12;
 return ((u8)(b1+db)<<10)|((u8)(r1+dr)|((u8)(g1+dg)<<5));
}

/*
 * lever: twin ov104 021B89DC blend spelling, first argument passed through to func_02061CA4.
 */
s32 MYSTERY_UTIL_BlendPalette(int a,u16 *p,int angle,int bank,u8 index,u16 c1,u16 c2) {
 *p=blend(c1,c2,(s16)((FX_SinCosTable_[((angle>>4)*2)+1]+0x1000)/2));
 return func_02061CA4((void *)a,bank*32+index*2,(u32)p,2);
}

#pragma opt_loop_invariants off

/*
 * lever: int factor before the loop, narrowed to s16 at the inline blend argument
 * inside the loop, with #pragma opt_loop_invariants off: the IR keeps the
 * conversion in the loop (no div+convert fold to lsls #0xf) and the backend
 * hoists it, giving asrs #1; lsls #0x10; asrs #0x10. Counter initialised at its
 * declaration (int i=0; for(;...)) sets the i/index birth order (r6/r4).
 * note pass 2 2026-10-06 P2L51: closed from 147/200 (h5 pragma form 7/200, i/index swap fixed by i=0 at declaration).
 */
void MYSTERY_UTIL_BlendPaletteRange(void *a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last) {
 int i=0;
 int factor=(FX_SinCosTable_[((angle>>4)*2)+1]+0x1000)/2;
 for(;i<16;i++) p[i]=blend(first[i],last[i],factor);
 func_02061CA4(a,bank*32,(u32)p,32);
}

#pragma opt_loop_invariants reset

char *MYSTERY_ALBUM_Create(const Input *src,u16 heap)
{
    char *out;
    int count=0;
    u32 i;
    int j;
    Desc_021DAB50 d;
    Record_021D9624 record;
    const char *table;
    int n;
    void *callback;
    out=func_02030734(heap,0xc70,0,d_021DFBB0,0x19f);
    MI_CpuFill8(out,0,0xc70);
    ((MysteryAlbumWork *)out)->flipFlag=1;
    *(Input *)out=*src;
    ((MysteryAlbumWork *)out)->heapId=heap;
    func_02082A7C(-1,out+0xb48,32);
    func_02082A7C(-1,out+0xb88,32);
    func_02082A7C(-1,out+0xb68,32);
    for(i=0;i<MYSTERY_DATA_GetCardSlotNum(((MysteryAlbumWork *)out)->cardList);i++) {
        if(MYSTERY_DATA_IsCardExist(((MysteryAlbumWork *)out)->cardList,i)) {
            count++;
            MYSTERY_DATA_GetCard(((MysteryAlbumWork *)out)->cardList,i,&record);
            MYSTERY_ALBUM_SetupEntry(out+40+i*0xdc,(const Record_021DB938 *)&record,out,heap);
        }
    }
    callback=(void *)MYSTERY_ALBUM_SelectHandler;
    if(((MysteryAlbumWork *)out)->mode) callback=(void *)MYSTERY_ALBUM_SingleHandler;
    ((MysteryAlbumWork *)out)->task=MYSTERY_UTIL_CreateTask(out,callback,heap);
    MYSTERY_ALBUM_Setup((u8 *)out,heap);
    MYSTERY_ALBUM_SetCursor(out,1,0,((MysteryAlbumWork *)out)->cursorIndex,heap);
    if(count) {table=d_021DF8FC;n=3;}
    else {table=d_021DF890;n=2;}
    /* stand-in: unprototyped call; the prototype's u16/u8 parameters narrow the arguments and change the bytes */
    ((MysteryAlbumWork *)out)->windowList=((void *(*)())MYSTERY_UTIL_CreateWindowList)(0,table,n,1,3,((MysteryAlbumWork *)out)->windowParamB,((MysteryAlbumWork *)out)->bank,*(int *)&((MysteryAlbumWork *)out)->windowParamA,heap);
    MI_CpuFill8(&d,0,48);
    d.w[0]=6;d.w[1]=4;d.w[2]=14;d.w[3]=15;d.w[4]=11;d.w[5]=14;
    d.w[6]=((MysteryAlbumWork *)out)->param8;d.w[7]=*(u32 *)&((MysteryAlbumWork *)out)->cardList;d.w[8]=((MysteryAlbumWork *)out)->bank;
    d.w[9]=(u32)((MysteryAlbumWork *)out)->windowParamA;d.w[10]=(u32)((MysteryAlbumWork *)out)->windowParamB;d.w[11]=((MysteryAlbumWork *)out)->param18;
    ((MysteryAlbumWork *)out)->menuWork=MYSTERY_ALBUM_CreateSlotWork((const Desc_021DCFC8 *)&d,heap);
    if(MYSTERY_ALBUM_CountValidCards((u32)out)) {
        for(j=0;j<12;j++) {
            if(MYSTERY_ALBUM_IsEntryValid((int *)(out+40+j*0xdc)))
                *(void **)(out+0xa7c+j*4)=MYSTERY_ALBUM_CreateAlbumView((Record_021DD24C *)MYSTERY_ALBUM_GetEntryCard(out+40+j*0xdc),((MysteryAlbumWork *)out)->menuWork,(void *)src->w[8],heap);
        }
        MYSTERY_ALBUM_RequestSetup(((MysteryAlbumWork *)out)->slots[0],0);
        func_0203084C(29);
    }
    BG_SYS_FillScrollArea(3,3,0);
    BG_SYS_FillScrollArea(7,3,0);
    return out;
}

/*
 * lever: The slot array at +0xa7c is the same layout as MYSTERY_ALBUM_RemoveCard;
 * its member access keeps the offset loaded before the loop index.
 */
void MYSTERY_ALBUM_DeleteWork(MysteryAlbumWork *obj)
{
    char *p=(char *)obj;
    int i;
    u32 j;
    for(i=0;i<12;i++) {
        if(obj->slots[i]) {
            MYSTERY_ALBUM_Delete(obj->slots[i]);
            obj->slots[i]=0;
        }
    }
    MYSTERY_ALBUM_DeleteSlotWork(*(void ** *)&((MysteryAlbumWork *)p)->menuWork);
    if(((MysteryAlbumWork *)p)->menuWindow) {
        MYSTERY_UTIL_DeleteMenuWindow(((MysteryAlbumWork *)p)->menuWindow);
        ((MysteryAlbumWork *)p)->menuWindow=0;
    }
    BG_SYS_FillScrollArea(3,0,0);
    BG_SYS_FillScrollArea(2,0,0);
    MYSTERY_UTIL_ClearWindowList(((MysteryAlbumWork *)p)->windowList);
    MYSTERY_UTIL_DeleteWindowList(((MysteryAlbumWork *)p)->windowList);
    MYSTERY_ALBUM_UpdateSlots(p,1);
    MYSTERY_ALBUM_UpdateSlots(p,0);
    MYSTERY_ALBUM_Cleanup(p);
    for(j=0;j<MYSTERY_DATA_GetCardSlotNum(((MysteryAlbumWork *)p)->cardList);j++)
        MYSTERY_ALBUM_ClearEntry((u32)(p+0x28+j*0xdc));
    BG_SYS_ClearSlot(4);
    BG_SYS_ClearSlot(6);
    func_02041B6C(4);
    func_02041B6C(6);
    MYSTERY_UTIL_DeleteTask(((MysteryAlbumWork *)p)->task);
    func_020307B0(p);
}

void MYSTERY_ALBUM_Update(Obj_021DAEF0 *obj)
{
    char *p=(char *)obj;
    int flag;
    u16 old;
    int angle;
    MYSTERY_UTIL_DispatchTask(*(char * *)&((MysteryAlbumWork *)p)->task);
    MYSTERY_ALBUM_UpdateSlotWork(((MysteryAlbumWork *)p)->menuWork);
    if(((MysteryAlbumWork *)p)->refreshFlag) {
        flag=0;
        if(*(char * *)&((MysteryAlbumWork *)p)->selectedAlbum) {
            MYSTERY_ALBUM_ResetIntro(*(char * *)&((MysteryAlbumWork *)p)->selectedAlbum);
            *(char * *)&((MysteryAlbumWork *)p)->selectedAlbum=0;
        }
        if(obj->index<4 && MYSTERY_ALBUM_IsEntryValid((int *)(&obj->items[obj->index+((MysteryAlbumWork *)p)->cursorIndex*4]))) {
            flag=1;
            MYSTERY_ALBUM_RequestSetup(*(void **)(p+0xa7c+(((MysteryAlbumWork *)p)->cursorMode+((MysteryAlbumWork *)p)->cursorIndex*4)*4),1);
        }
        if(flag==0) MYSTERY_ALBUM_HideScreen(((MysteryAlbumWork *)p)->menuWork);
        ((MysteryAlbumWork *)p)->refreshFlag=0;
    }
    old=((MysteryAlbumWork *)p)->angle;
    angle=old+0x400;
    if(angle>=0x10000)
        ((MysteryAlbumWork *)p)->angle=old-0xfc00;
    else
        ((MysteryAlbumWork *)p)->angle=angle;
    MYSTERY_ALBUM_UpdateIconSprite((u8 *)(p+0xbae),14,0,((MysteryAlbumWork *)p)->angle);
    MYSTERY_ALBUM_UpdateIconSprite((u8 *)(p+0xc0e),14,2,((MysteryAlbumWork *)p)->angle);
}

static inline void update(void *p)
{
    if(p) MYSTERY_ALBUM_StepIntro(p);
}

/*
 * extent: unit includes tail-call follower MYSTERY_ALBUM_GetWindowState (function-start seed).
 */
void MYSTERY_ALBUM_UpdateWindows(char *p)
{
    int i;
    MYSTERY_UTIL_IsWindowListDone(((MysteryAlbumWork *)p)->windowList);
    if(((MysteryAlbumWork *)p)->infoWindow) MYSTERY_UTIL_IsMessageDone(((MysteryAlbumWork *)p)->infoWindow);
    for(i=0;i<12;i++) {
        void *q=*(void **)(p+i*4+0xa7c);
        if(q) update(q);
    }
}

int MYSTERY_ALBUM_GetWindowState(char *p)
{
    return MYSTERY_UTIL_GetTaskField04(((MysteryAlbumWork *)p)->task);
}

#pragma opt_dead_assignments off

/*
 * closed 2026-10-05 (recoup integrator): func_02049658 returns u32 (its matched definition tail-returns ARC_UTIL_UploadBgChar); with the void declaration the later register zeros were copied from the pooled zero; with the real return type the
 *   bytes are EXACT in c99 and c.
 * note (2026-10-05, lane P10): full body written; size is exact (976 bytes), 110 bytes differ.
 *   Fixed: heap is u16 with the matched u16 callee prototypes (no lsls/lsrs pairs); 0xAB4, 0xBA8
 *   and 320 held as int locals (off, off2, w) so the pool words and derived offsets matched.
 *   Residue 1: colour swap. Original has the early zero (and loop counter i) in r6 and arc in r4;
 *   the build has them swapped (j then takes r6 vs r4 the same way). Tried, no change: i,j and arc
 *   declaration order, separate arc names, loop-scoped i and j, named zero z (propagated),
 *   j = 0 at the top (worse). Pragmas opt_lifetimes/propagation/common_subs/dead_assignments/
 *   scheduling/peephole off: no help.
 *   Residue 2: the original uses movs for zero arguments in r0-r3 between 0xCC and 0x140 (before
 *   the first loop); the build copies the zero register there.
 *   Residue 3: in loop 2 the original forms add r0,sp,#0x44 once before the j test; the build
 *   adds it in each arm. A ternary for the x store and a real Tmp struct were worse.
 * note (2026-10-05, lane P10b): 110 -> 85 bytes, size exact (976). Fixed: loop 2 now writes
 *   the t stores in each if/else arm (x, y=0x10 and z=9 in both arms), so the &t add is hoisted
 *   above the j test and the tail shape matches (residue 3 closed, 110 -> 94). The locals off, off2
 *   and w were stand-ins (literals give identical bytes) and are gone. opt_dead_assignments off
 *   fixes the r0/r1 table-base colours in the i < 4 arm (94 -> 85).
 *   Left: the colour swap. Original W1 = early zero and loop-1 counter i in r6, arcs r4, W2 = copy
 *   of it (`adds r4,r6,#0` before loop 1) = zero args after the loop and loop-2 counter j in r4.
 *   Build: W1 r4, arcs and W2 r6. Likely W1 is coloured before W2 because W1 has about ten extra
 *   uses: between 0xCC and 0x140 the build copies zeros off W1 (adds rN,r4,#0) where the original
 *   has movs. Tried (no help): i=0 at the top of the function (hoists the movs above the first
 *   call, +12 B), `i = 0; j = i;` before loop 1 with empty for inits (+12 B, worse regs), pointer
 *   local for &t in loop 2 (hoisted to r7, worse), j/i and arc declaration order again with the
 *   new loop 2, pragmas opt_lifetimes, opt_propagation, scheduling, peephole (no change),
 *   opt_common_subs (much worse), lifetimes+dead_assignments (85, same), propagation+dead (worse).
 *   Parked per the human-written rule: not tried, a human-spelled zero local reused as the
 *   stack zero arguments (i passed as args 5 and 6) could explain r6 holding a live variable.
 * note (2026-10-05, lane P10c): still 85 B, no change kept. The pragma opt_dead_assignments off
 *   lines are present (the 85 B state). Callee prototypes already match the matched callers (u32
 *   args, u16 heap), so no argument type differs between the stack zeros and the register zeros.
 *   Facts: mine already uses movs for register zeros before +0xB0 and copies only from the last
 *   02049658/020498F4 pair on (+0xB0, +0xD0, +0xF6..+0x134); the original uses movs everywhere in
 *   W1's range, and the copy count raises W1's use count, which colours W1 before the arcs.
 *   Loop 2 original: k is a separate fresh `movs r7,#0`, j is r4.
 *   Tried (each one compile): (1) coordinator lead: i = 0 before the first call, i passed only as
 *   the two stack zero args of 02049658/020498F4, literal 0 for r1-r3 (87 B; the compiler folds
 *   i to 0 so register zeros still copy); (2) i = 0 early with `for (; i < 8; i++)` as in the
 *   matched twin ov099 021BE040 (87 B); (3) static inline helper pair(arc, x, y, heap) for the
 *   three 02049658/020498F4 pairs (85 B, +0xB0 now movs, others unchanged); (4) late zeros
 *   (02049B68 r2, 02040C14 r1/r3, 0201F5BC r0/r3, 0204ACEC r2) spelled 0u (85 B, no change);
 *   (5) first 23 lines of calls inside a static inline setup1(heap) helper (85 B); (6) helper
 *   variant with opt_propagation off (901 B) and opt_lifetimes off (85 B). Idea not done: a
 *   source where W1 is not provably 0 after the first loop-free section.
 */
void MYSTERY_ALBUM_Setup(u8 *p, u16 heap)
{
    Tmp t;
    void *arc;
    int i, j;
    u32 k;
    arc = func_020490F4(34, heap);
    func_02049B68(arc, 1, 0, 0, 320, heap);
    func_02049658(arc, 10, 3, 0, 0, 0, heap);
    func_020498F4(arc, 17, 3, 0, 0, 0, heap);
    func_02049658(arc, 10, 1, 0, 0, 0, heap);
    func_020498F4(arc, 19, 1, 0, 0, 0, heap);
    BG_SYS_PushTile(3);
    func_02049B68(arc, 1, 4, 0, 320, heap);
    func_02049658(arc, 10, 7, 0, 0, 0, heap);
    func_020498F4(arc, 18, 7, 0, 0, 0, heap);
    ARC_TOOL_DeleteHandle(arc);
    arc = func_020490F4(23, heap);
    func_02049B68(arc, 5, 0, 480, 32, heap);
    func_02049B68(arc, 5, 4, 480, 32, heap);
    ARC_TOOL_DeleteHandle(arc);
    BG_SYS_Init(1, 0, 1, 0);
    BG_SYS_Init(2, 0, 1, 0);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 13, 0, heap);
    arc = func_020490F4(7, heap);
    *(int *)(p + 0xBA8) = CLACT_RegisterPaletteCompressed(arc, func_0201BC3C(), 0, 384, heap);
    ARC_TOOL_DeleteHandle(arc);
    for (i = 0; i < 8; i++) {
        if (i >= 4) {
            *(u16 *)(t.b + 8) = data_021DF86E[i - 4].h[0];
            *(u16 *)(t.b + 10) = data_021DF86E[i - 4].h[1];
            *(u16 *)(t.b + 12) = data_021DF86E[i - 4].h[2];
            *(u16 *)(t.b + 14) = data_021DF86E[i - 4].h[3];
            t.b[8] += 0x20;
            t.b[10] += 0x20;
        } else {
            *(u16 *)(t.b + 8) = data_021DF86E[i].h[0];
            *(u16 *)(t.b + 10) = data_021DF86E[i].h[1];
            *(u16 *)(t.b + 12) = data_021DF86E[i].h[2];
            *(u16 *)(t.b + 14) = data_021DF86E[i].h[3];
        }
        *(u32 *)(p + i * 4 + 0xBA8 - 0xA0) = BMP_WIN_Create(2, t.b[10], t.b[11], 10, 2, 15, 0);
        BMP_WIN_MakeScreen(*(void **)(p + i * 4 + 0xBA8 - 0xA0));
        BG_SYS_PushTile(2);
    }
    *(void **)(p + 0xAB4) = MYSTERY_UTIL_CreateWindow(0, 1, 13, 22, 6, 2, 3, *(u32 *)(p + 0x14), heap);
    arc = func_020490F4(34, heap);
    *(s32 *)(p + 0xAB4 + 0x50) = CLACT_RegisterPaletteEx(arc, 0, 0, 0, 0, 6, heap);
    *(s32 *)(p + 0xAB4 + 0x4C) = CLACT_RegisterCellAnim(arc, 32, 35, heap);
    *(s32 *)(p + 0xAB4 + 0x48) = CLACT_RegisterCharacter(arc, 9, 0, 0, heap);
    MYSTERY_ALBUM_SetupIconSprite((char *)p + 0xBAE, arc, 0, 0, 1, heap);
    MYSTERY_ALBUM_SetupIconSprite((char *)p + 0xC0E, arc, 0, 2, 3, heap);
    ARC_TOOL_DeleteHandle(arc);
    MI_CpuFill8(&t, 0, 8);
    *(u16 *)(t.b) = 0;
    *(u16 *)(t.b + 2) = 24;
    t.b[7] = 1;
    t.b[6] = 1;
    {
        struct Obj *o = CLACT_CreateActor(*(void **)(p + 8), *(u32 *)(p + 0xAB4 + 0x48), *(u32 *)(p + 0xAB4 + 0x50), *(u32 *)(p + 0xAB4 + 0x4C), &t, 0, heap);
        *(struct Obj **)(p + 0xAB4 + 0x38) = o;
        *(u16 *)(t.b + 4) = 2;
        o = CLACT_CreateActor(*(void **)(p + 8), *(u32 *)(p + 0xAB4 + 0x48), *(u32 *)(p + 0xAB4 + 0x50), *(u32 *)(p + 0xAB4 + 0x4C), &t, 0, heap);
        *(struct Obj **)(p + 0xAB4 + 0x3C) = o;
        CLACT_SetActorDrawEnable(o, 0);
    }
    t.b[6] = 0;
    k = 0;
    for (j = 0; j < 2; j++) {
        struct Obj *o;
        u8 *q;
        if (j == 0) {
            *(u16 *)(t.b) = 0x10;
            *(u16 *)(t.b + 2) = 0x10;
            *(u16 *)(t.b + 4) = 9;
        } else {
            *(u16 *)(t.b) = 0xF0;
            *(u16 *)(t.b + 2) = 0x10;
            *(u16 *)(t.b + 4) = 9;
        }
        q = p + j * 4;
        o = CLACT_CreateActor(*(void **)(p + 8), *(u32 *)(p + 0xAB4 + 0x48), *(u32 *)(p + 0xAB4 + 0x50), *(u32 *)(p + 0xAB4 + 0x4C), &t, k, heap);
        *(struct Obj **)(q + 0xAB4 + 0x40) = o;
        CLACT_SetActorAutoAnim(*(struct Obj **)(q + 0xAB4 + 0x40), 1);
        CLACT_SetActorDrawEnable(*(struct Obj **)(q + 0xAB4 + 0x40), k);
        if (j == 0) CLACT_SetActorFlip((struct Actor *)(*(struct Obj **)(q + 0xAB4 + 0x40)), 1, 1);
        else CLACT_SetActorFlip((struct Actor *)(*(struct Obj **)(q + 0xAB4 + 0x40)), 1, 0);
    }
    func_02040588(2, 1);
}

#pragma opt_dead_assignments reset

void MYSTERY_ALBUM_Cleanup(char *p)
{
    int i;
    BG_SYS_SetTileUnit(2,1,0);
    BG_SYS_SetTileUnit(1,1,0);
    for(i=0;i<2;i++) CLACT_DeleteActor(*(void **)(p+0xaf4+i*4));
    CLACT_DeleteActor(((MysteryAlbumWork *)p)->actorB);
    CLACT_DeleteActor(((MysteryAlbumWork *)p)->actorA);
    CLACT_ReleaseCharacter((u32)(((MysteryAlbumWork *)p)->charHandle));
    CLACT_ReleaseCellAnim((u32)(((MysteryAlbumWork *)p)->cellAnimHandle));
    CLACT_ReleasePalette((u32)(((MysteryAlbumWork *)p)->paletteHandle));
    MYSTERY_UTIL_DeleteWindow(((MysteryAlbumWork *)p)->infoWindow);
    ((MysteryAlbumWork *)p)->infoWindow=0;
    CLACT_ReleasePalette((u32)(((MysteryAlbumWork *)p)->bgPaletteHandle));
    for(i=0;i<8;i++) BMP_WIN_Delete(*(void **)(p+0xb08+i*4));
}

void MYSTERY_ALBUM_SetCursor(char *p,int a,int b,int c,u16 heap)
{
    int i;
    void *text,*other;
    for(i=0;i<4;i++) MYSTERY_ALBUM_SetupSlot(p,a,b,c,(u16)i,heap);
    text=STRBUF_Create(128,heap);
    other=func_02045EC0(((struct Obj00828 *)p)->f1C,150);
    WORDSET_SetSlotNumber(((struct Obj00828 *)p)->f18,0,c+1,1,1,1);
    WORDSET_SetSlotNumber(((struct Obj00828 *)p)->f18,1,MYSTERY_ALBUM_GetColumnCount(p),1,1,1);
    WORDSET_CopyTaggedText(((struct Obj00828 *)p)->f18,text,other);
    MYSTERY_UTIL_SetColor(((struct Obj00828 *)p)->fAB4,0x39ea);
    MYSTERY_UTIL_SetPosition(((struct Obj00828 *)p)->fAB4,0,0,1);
    MYSTERY_UTIL_ShowString(((struct Obj00828 *)p)->fAB4,(int)text,((struct Obj00828 *)p)->f10);
    STRBUF_Delete(text);
    STRBUF_Delete(other);
    BG_SYS_PushTile(3);
}

void MYSTERY_ALBUM_UpdateSlots(char *p,int a) { int i; for(i=0;i<4;i++) MYSTERY_ALBUM_DeleteSlotActor(p,a,i); BG_SYS_PushTile(3); }

#pragma opt_loop_invariants off

#pragma opt_lifetimes off

/*
 * note 2026-10-05 (lane P9): first draft, no source existed. DIFF, 1024 vs 1004 bytes.
 *   Structure matches the listing (loops, tail, callee arguments). Separate locals
 *   for rect/pos/cur (not one struct) give the right heap/index prologue; a static
 *   inline ents(p) = p + 0x28 gives the double store of the table base.
 *   Residue: the original keeps the two signed divisions by 3 inside the y loop
 *   (dividend (u8)k hoisted to a spill slot, rem first, quot second); every form
 *   tried hoists the whole tile base out of the loop (parenthesised, one expression,
 *   u8 m, inline cast, cols=3 local: 12 compiles). Spill slot numbers and register
 *   colours (rx r5, x r4, yy r7) follow from that. The 0x100 in the final block is
 *   built as r4(=1)+0xff in the original, not reproduced. Pool-base adds (p+0xb08
 *   etc.) are shared in the draft but recomputed in the original.
 *   Idioms checked: a-u16-stack-parameter-reloaded-per-call-means-u16-callee-parameters
 *   (heap already u16 in all prototypes), narrow-stack-parameters-and-callee-prototype-
 *   free-the-narrow-home-store (prologue now matches for 14 bytes).
 * note 2026-10-05 (lane P9b): still DIFF, 1028 vs 1004 bytes. 13 more compiles, none changed
 *   the size. Tried: tile base as a static inline tb(k, y) called in the y body; separate
 *   rem/quo locals (rem first); tile expression written inside the x loop call argument;
 *   y loop as do/while; m = (u8)k assigned inside the y body instead of before the loop
 *   (mwcc hoists the cast AND both divisions out of the y loop in every form, so LICM
 *   hoists in one step through the whole chain); per-function pragmas opt_loop_invariants,
 *   opt_lifetimes, opt_propagation, opt_common_subs off (size 1028/1028/1064/1100, no help).
 *   The original hoists the (u8)k cast but keeps both calls in the y body: the divisions
 *   must be loop-variant or non-hoistable at IR level for a reason no source form tried
 *   shows. Untested guesses: a hoist budget limit, or a different dividend source.
 *   Idioms checked: signed-modulo-magic-reappears-when-the-source-divides-by-the-same-
 *   constant-twice (not applicable, divisor 3 is a real call here); matched twin ov217
 *   021BD178 has the divisions inside the loop only because its operands depend on i, j.
 * note 2026-10-05 final push G10L1: DIFF, 53 of 1004 bytes off (was 470 of 1028 at the start of
 *   the push). Size now equals the original. What closed most of the residue:
 *   (1) the tail pos.x chain is `if (a) x = h2; else if (b) x = h2 - 0x100; else if (b == 0)
 *   x = h2 + 0x100; else x = h2;` (the original tests a once; 1028 -> 1016 bytes);
 *   (2) the cur block is `if (a == 0) { if (b) x -= 0x100; else if (b == 0) x += 0x100; }`
 *   (1016 -> 1004); (3) `#pragma opt_loop_invariants off` keeps both /3 and %3 calls inside the
 *   y loop (the old lane tried it only while the size was still wrong); (4) do-while loops with
 *   `x = 0;` first in the y body and `y = 0;` before the loops give the original head order;
 *   (5) a local for MYSTERY_ALBUM_GetEntryBmp's result puts that call before the idx*4 address work;
 *   (6) declaration order off, tab, idx, y, y2, y3 (one counter per loop), m, src, k, ry, rx
 *   gives the original spill slots for most locals; tab = p + 0x28 plain (no inline helper);
 *   (7) dy = 0 before MI_CpuFill8.
 *   Residue (53 bytes): rx and x swapped (original x r4, rx r5; mine rx r4, x r5; decl order of
 *   x/rx did not move it, 2 compiles); index and ry slots swapped (original index sp+0x18, ry
 *   sp+0x1c); obj and the p+0xb88 base temp slots swapped (original obj sp+0x48, temp sp+0x44);
 *   `dx = 0` (movs r6) sits before the call to MYSTERY_ALBUM_GetEntryGraphicIndex in mine, just before the blx of
 *   CLACT_RegisterCharacter in the original.
 *   Idioms checked: of-two-equal-temps-the-later-born-one-gets-the-lower-register (no source
 *   order found that flips x/rx), a-separate-index-local-per-loop-reorders-spill-slots (y per
 *   loop: moved y2/y3 next to y), function-scope-versus-block-scope-decides-spill-slot-order,
 *   div-and-mod-are-two-calls, a-reloaded-loop-invariant-means-the-loop-was-not-rotated
 *   (goto loops still hoist). Twin: ov121 021DB938 (same top condition and loops).
 * note 2026-10-05 final push G10L1 round 2: DIFF, 28 of 1004 bytes off. `dx = 0;` moved to just
 *   after the CLACT_RegisterCharacter statement (53 -> 28; this also fixed the obj/temp slot swap).
 *   Remaining: x in r5 and rx in r4 (original x r4, rx r5), and the index/ry spill slots swapped
 *   (original index sp+0x18, ry sp+0x1c). Tried without effect: dx = 0 as a call argument (251),
 *   u8 rx/ry, a y=x=0 head, separate x2/x3 per loop, decl order of x/rx/tile; opt_propagation off
 *   (91), opt_common_subs off (758), opt_lifetimes off (25 but x r4, rx r6, tile r5, index/ry swap
 *   stays); callee prototypes re-grepped in src/matched (all match the draft). Without the
 *   pragma and with direct r.b[0]/r.b[1] reads (like matched 021DB938) the slots all match but
 *   both /3 and %3 are hoisted (84); `(u8)k` inline, `cols = 3` local did not stop the hoist.
 * note pass 2 2026-10-06 P2L41: EXACT (c99 and c). Closed with `#pragma opt_lifetimes off` (beside
 *   opt_loop_invariants off), one tile local per loop (tile, tile2, tile3, like y/y2/y3), x declared
 *   before rx, int ry passed straight to BG_SYS_FillTileMap with the u32 x/y prototype used by matched
 *   callers (ov217 021BA284, ov088 021BB810). Under lifetimes off the colour order follows degree
 *   then declaration order: per-loop tiles make the tiles drop out first, then rx, then x, giving
 *   x r4, rx r5, tile r6. Passing ry (not r.b[1]) keeps ry itself as the spilled web, so it takes
 *   the slot after k (sp+0x1c) and index takes sp+0x18.
 */
void MYSTERY_ALBUM_SetupSlot(char *p, int a, int b, int c, u16 index, u16 heap)
{
    void *obj;
    int off;
    char *tab;
    int idx;
    int y, y2, y3;
    int m;
    const Rect_021D9624 *src;
    int k, ry;
    int x, rx, yy, tile, tile2, tile3;
    s16 dx, dy;
    void *dsc;
    Rect_021D9624 r;
    Pos pos;
    Cur_021D9624 cur;
    k = index + c * 4;
    tab = p + 0x28;
    off = k * 0xdc;
    idx = index;
    src = (const Rect_021D9624 *)d_021DF86E + index;
    r = *src;
    if ((a && *(u32 *)(p + 0xad0) == 0) || (a == 0 && *(u32 *)(p + 0xad0))) {
        idx += 4;
        r.b[0] += 32;
        r.b[2] += 32;
    }
    y = 0;
    ry = r.b[1];
    rx = r.b[0];
    m = (u8)k;
    do {
        x = 0;
        yy = ry + y;
        tile = y * 32 + ((m % 3) * 64 + 0x58 + (m / 3) * 2);
        do {
            BG_SYS_SetTileEntry(3, (u16)(x + tile), (u8)(rx + x - 2), (u8)yy, 1, 1, 3);
            x++;
        } while (x < 2);
        y++;
    } while (y < 2);
    if (MYSTERY_ALBUM_IsEntryValid((int *)(tab + off)) == 0) {
        y2 = 0;
        do {
            x = 0;
            yy = ry + y2;
            tile2 = y2 * 32 + 384;
            do {
                BG_SYS_SetTileEntry(3, (u16)(x + tile2), (u8)(rx + x), (u8)yy, 1, 1, 3);
                x++;
            } while (x < 12);
            y2++;
        } while (y2 < 7);
        BMP_Clear(BMP_WIN_GetBmp(*(void **)(p + 0xb08 + idx * 4)), 0);
        BMP_WIN_TransferChars(*(void **)(p + 0xb08 + idx * 4));
        return;
    }
    y3 = 0;
    do {
        x = 0;
        yy = ry + y3;
        tile3 = y3 * 32 + 0x40;
        do {
            BG_SYS_SetTileEntry(3, (u16)(x + tile3), (u8)(rx + x), (u8)yy, 1, 1, 5);
            x++;
        } while (x < 12);
        y3++;
    } while (y3 < 7);
    BG_SYS_FillTileMap(3, r.b[0], ry, 12, 7, (u8)MYSTERY_ALBUM_GetEntryIconX(tab + off));
    dsc = MYSTERY_ALBUM_GetEntryBmp(tab + off);
    BMP_CopyPixels(dsc, BMP_WIN_GetBmp(*(void **)(p + 0xb08 + idx * 4)));
    BMP_WIN_TransferChars(*(void **)(p + 0xb08 + idx * 4));
    obj = MYSTERY_ALBUM_CreateEntryArc(tab + off, heap);
    if (MYSTERY_ALBUM_GetEntryKind(tab + off) != 1)
        *(int *)(p + 0xb88 + idx * 4) = CLACT_RegisterPaletteEx(obj, MYSTERY_ALBUM_GetEntryArcId(tab + off), 0, (u16)((idx + 4) << 5), 0, 1, heap);
    *(int *)(p + 0xb68 + idx * 4) = CLACT_RegisterCellAnim(obj, MYSTERY_ALBUM_GetEntrySpeciesId(tab + off), MYSTERY_ALBUM_GetEntryFormId(tab + off), heap);
    *(int *)(p + 0xb48 + idx * 4) = CLACT_RegisterCharacter(obj, MYSTERY_ALBUM_GetEntryGraphicIndex(tab + off), 0, 0, heap);
    dx = 0;
    ARC_TOOL_DeleteHandle(obj);
    dy = 0;
    MI_CpuFill8(&pos, 0, 8);
    pos.y = r.h[3];
    pos.flag = 1;
    if (MYSTERY_ALBUM_GetEntryKind(tab + off) == 2) {
        dx = 4;
        dy = 8;
    }
    if (a)
        pos.x = r.h[2];
    else if (b)
        pos.x = r.h[2] - 0x100;
    else if (b == 0)
        pos.x = r.h[2] + 0x100;
    else
        pos.x = r.h[2];
    pos.x += dx;
    pos.y += dy;
    *(void **)(p + 0xb28 + idx * 4) = CLACT_CreateActor(*(void **)(p + 8), *(u32 *)(p + 0xb48 + idx * 4),
        MYSTERY_ALBUM_GetEntryKind(tab + off) == 1 ? *(u32 *)(p + 0xba8) : *(u32 *)(p + 0xb88 + idx * 4),
        *(u32 *)(p + 0xb68 + idx * 4), &pos, 0, *(u16 *)(p + 0x24));
    CLACT_SetActorPaletteOffset(*(void **)(p + 0xb28 + idx * 4), (u8)MYSTERY_ALBUM_GetEntryIconPalette(tab + off), 0);
    CLACT_SetActorDrawEnable(*(void **)(p + 0xb28 + idx * 4), 1);
    if (*(u32 *)(p + 0xae0) && *(u16 *)(p + 0xade) == k) {
        cur.x = src->b[0] * 8 - 0x18;
        cur.y = d_021DF86F[index * 8] * 8 - 8;
        if (a == 0) {
            if (b)
                cur.x -= 0x100;
            else if (b == 0)
                cur.x += 0x100;
        }
        CLACT_AddActorSurfacePos(*(void **)(p + 0xaf0), (const struct Vec2 *)(&cur), 0);
    }
}

#pragma opt_lifetimes reset

#pragma opt_loop_invariants reset

void MYSTERY_ALBUM_DeleteSlotActor(char *p,int a,u16 index)
{
    Rect_021DB938 rect;
    int y,x,tile;
    int yy;
    rect=*(const Rect_021DB938 *)((const Rect_021D9624 *)d_021DF86E + index);
    if((a && ((MysteryAlbumWork *)p)->flipFlag==0) || (a==0 && ((MysteryAlbumWork *)p)->flipFlag)) {
        index+=4;
        rect.b[0]+=32;
        rect.b[2]+=32;
    }
    for(y=0;y<7;y++) {
        yy=rect.b[1]+y;
        tile=y*32+384;
        for(x=0;x<12;x++)
            BG_SYS_SetTileEntry(3,(u16)(x+tile),(u8)(rect.b[0]+x),yy,1,1,3);
    }
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(p+0xb08+index*4)),0);
    BMP_WIN_TransferChars(*(void **)(p+0xb08+index*4));
    if(*(void **)(p+0xb28+index*4)) {
        CLACT_DeleteActor((struct Obj *)(*(void **)(p+0xb28+index*4)));
        *(void **)(p+0xb28+index*4)=0;
        if(*(u32 *)(p+0xb88+index*4)!=-1) {
            CLACT_ReleasePalette(*(u32 *)(p+0xb88+index*4));
            *(u32 *)(p+0xb88+index*4)=-1;
        }
        if(*(u32 *)(p+0xb48+index*4)!=-1) {
            CLACT_ReleaseCharacter(*(u32 *)(p+0xb48+index*4));
            *(u32 *)(p+0xb48+index*4)=-1;
        }
        if(*(u32 *)(p+0xb68+index*4)!=-1) {
            CLACT_ReleaseCellAnim(*(u32 *)(p+0xb68+index*4));
            *(u32 *)(p+0xb68+index*4)=-1;
        }
    }
}

void MYSTERY_ALBUM_StartScroll(u8 *p,int a) { int v; if(a) v=-1; else v=1; ((MysteryAlbumWork *)p)->scrollDir=v; ((MysteryAlbumWork *)p)->scrollTimer=0; }

int MYSTERY_ALBUM_UpdateScroll(char *p)
{
    int amount,i;
    s16 xy[4];
    if(((MysteryAlbumWork *)p)->scrollDir==0) goto idle;
    amount=(((MysteryAlbumWork *)p)->scrollDir*256)/16;
    for(i=0;i<8;i++) {
        if(*(void **)(p+i*4+0xb28)) {
            CLACT_GetActorSurfacePos(*(void **)(p+i*4+0xb28),(struct PtS *)(xy+2),0);
            xy[2]-=(s16)amount;
            CLACT_AddActorSurfacePos((struct Obj *)(*(void **)(p+i*4+0xb28)), (const struct Vec2 *)(xy+2), 0);
            CLACT_GetActorSurfacePos(*(void **)(p+i*4+0xb28),(struct PtS *)xy,0);
            if(xy[0]>=-16 && xy[0]<=272 && xy[1]>=-16 && xy[1]<=208)
                CLACT_SetActorDrawEnable((struct Obj *)(*(void **)(p+i*4+0xb28)), 1);
            else CLACT_SetActorDrawEnable((struct Obj *)(*(void **)(p+i*4+0xb28)), 0);
        }
    }
    if(((MysteryAlbumWork *)p)->introActive) {
        CLACT_GetActorSurfacePos(((MysteryAlbumWork *)p)->actorB,(struct PtS *)(xy+2),0);
        xy[2]-=(s16)amount;
        CLACT_AddActorSurfacePos((struct Obj *)(((MysteryAlbumWork *)p)->actorB), (const struct Vec2 *)(xy+2), 0);
        if(xy[2]>=-96 && xy[2]<=352 && xy[3]>=-96 && xy[3]<=288)
            CLACT_SetActorDrawEnable((struct Obj *)(((MysteryAlbumWork *)p)->actorB), 1);
        else CLACT_SetActorDrawEnable((struct Obj *)(((MysteryAlbumWork *)p)->actorB), 0);
    }
    BG_SYS_FillScrollArea(3,1,amount);
    BG_SYS_FillScrollArea(2,1,amount);
    if((((MysteryAlbumWork *)p)->scrollTimer)++>=15) {
        ((MysteryAlbumWork *)p)->flipFlag^=1;
        ((MysteryAlbumWork *)p)->scrollDir=0;
    }
    return 0;
idle:
    return 1;
}

/*
 * Rebuild every entry from the list, free slot idx, then pull each later
 * slot down one place (swap into an empty slot), and mark the table dirty.
 */
void MYSTERY_ALBUM_RemoveCard(MysteryAlbumWork *o, int idx)
{
    unsigned char buf[0xCC];
    u32 i;

    MYSTERY_DATA_DeleteCard(o->cardList, idx);
    for (i = 0; i < MYSTERY_DATA_GetCardSlotNum(o->cardList); i++)
        MYSTERY_ALBUM_ClearEntry((u32)(&o->items[i]));
    for (i = 0; i < MYSTERY_DATA_GetCardSlotNum(o->cardList); i++) {
        if (MYSTERY_DATA_IsCardExist(o->cardList, i)) {
            MYSTERY_DATA_GetCard(o->cardList, i, buf);
            MYSTERY_ALBUM_SetupEntry((char *)(&o->items[i]), (const Record_021DB938 *)buf, (char *)o, o->heapId);
        }
    }
    if (o->slots[idx] != 0) {
        MYSTERY_ALBUM_Delete(o->slots[idx]);
        o->slots[idx] = 0;
    }
    for (; idx < 11; idx++) {
        void *tmp = o->slots[idx];
        if (tmp == 0) {
            o->slots[idx] = o->slots[idx + 1];
            o->slots[idx + 1] = tmp;
        }
    }
    o->dirty = 1;
}

/*
 * note 2026-10-05 (lane Y6): no source existed. Same shape as matched sibling
 *   MYSTERY_ALBUM_RemoveCard (rebuild entries from the list), then two slot teardowns and rebuilds from
 *   the descriptor. EXACT on the first compile with plain struct fields.
 */
void MYSTERY_ALBUM_SwapCards(MysteryAlbumWork *o, u32 a, u32 b)
{
    unsigned char buf[0xCC];
    u32 i;

    MYSTERY_DATA_SwapCards(o->cardList, a, b);
    for (i = 0; i < MYSTERY_DATA_GetCardSlotNum(o->cardList); i++)
        MYSTERY_ALBUM_ClearEntry((u32)(&o->items[i]));
    for (i = 0; i < MYSTERY_DATA_GetCardSlotNum(o->cardList); i++) {
        if (MYSTERY_DATA_IsCardExist(o->cardList, i)) {
            MYSTERY_DATA_GetCard(o->cardList, i, buf);
            MYSTERY_ALBUM_SetupEntry((char *)(&o->items[i]), (const Record_021DB938 *)buf, (char *)o, o->heapId);
        }
    }
    MYSTERY_ALBUM_Delete(o->slots[a]);
    MYSTERY_ALBUM_Delete(o->slots[b]);
    o->slots[a] = MYSTERY_ALBUM_CreateAlbumView((Record_021DD24C *)MYSTERY_ALBUM_GetEntryCard(&o->items[a]), o->menuWork, (void *)o->saveParam, o->heapId);
    o->slots[b] = MYSTERY_ALBUM_CreateAlbumView((Record_021DD24C *)MYSTERY_ALBUM_GetEntryCard(&o->items[b]), o->menuWork, (void *)o->saveParam, o->heapId);
    o->dirty = 1;
}

int MYSTERY_ALBUM_GetColumnCount(char *p) { return 3; }

/*
 * lever: Declare the index before the count, but initialise count first; this places index in r4 and count in r5.
 * prototype: MYSTERY_DATA_GetCardSlotNum returns the value used by the bound. Its forwarding target 0200A400 reads only r0, so legacy trailing arguments are omitted.
 */
u32 MYSTERY_ALBUM_CountValidCards(u32 p) { u32 i; u32 count=0; for (i=0;i<MYSTERY_DATA_GetCardSlotNum((struct Obj *)(((MysteryAlbumWork *)p)->cardList));i++) { if (MYSTERY_ALBUM_IsEntryValid((int *)(p+40+i*220))) count++; } return count; }

void MYSTERY_ALBUM_SetupEntry(char *out,const Record_021DB938 *src,char *p,u16 heap)
{
    int flags;
    void *text,*other;
    s16 x,y;
    MI_CpuFill8(out,0,0xdc);
    if(src) {
        ((MysteryAlbumEntry *)out)->valid=1;
        *(Record_021DB938 *)(out+4)=*src;
        ((MysteryAlbumEntry *)out)->bmp=BMP_Create(10,2,32,heap);
        flags=src->w[43];
        text=STRBUF_Create(128,heap);
        other=func_02045EC0((void *)((MysteryAlbumWork *)p)->bank,151);
        WORDSET_SetSlotNumber((void *)((MysteryAlbumWork *)p)->param18,0,(u16)(flags>>16),4,1,1);
        WORDSET_SetSlotNumber((void *)((MysteryAlbumWork *)p)->param18,1,(u8)(flags>>8),2,0,1);
        WORDSET_SetSlotNumber((void *)((MysteryAlbumWork *)p)->param18,2,(u8)flags,2,0,1);
        WORDSET_CopyTaggedText((void *)((MysteryAlbumWork *)p)->param18,text,other);
        x=40;
        x-=(s16)(func_0201D304(text,*(u32 *)&((MysteryAlbumWork *)p)->windowParamA,0)/2);
        y=8-(s16)(func_0201D42C(text,((MysteryAlbumWork *)p)->windowParamA)/2);
        PRINTSYS_Print(((MysteryAlbumEntry *)out)->bmp,x,y,text,((MysteryAlbumWork *)p)->windowParamA);
        STRBUF_Delete(text);
        STRBUF_Delete(other);
    }
}

void MYSTERY_ALBUM_ClearEntry(u32 p) { if (((MysteryAlbumEntry *)p)->valid) { BMP_Delete(*(struct Obj020437AC * *)&((MysteryAlbumEntry *)p)->bmp); MI_CpuFill8((void *)p,0,220); } }

int MYSTERY_ALBUM_IsEntryValid(int *p) { return *p; }

void *MYSTERY_ALBUM_GetEntryBmp(void *p) { return ((MysteryAlbumEntry *)p)->bmp; }

void *MYSTERY_ALBUM_CreateEntryArc(void *p,u16 heap) { switch(MYSTERY_ALBUM_GetEntryKind(p)) { case 1:return func_020490F4(7,heap); case 2:return func_020490F4(25,heap); default:return func_020490F4(34,heap); } }

/*
 * prototype: FILE_UTIL_Get item is u16 here, matching caller truncation before the call.
 */
u32 MYSTERY_ALBUM_GetEntryArcId(void *p) { switch(MYSTERY_ALBUM_GetEntryKind(p)) { case 1:return func_0201BC3C(); case 2:return FILE_UTIL_Get(*(u32 *)MYSTERY_ALBUM_GetEntryCard(p),2); default:return 3; } }

u32 MYSTERY_ALBUM_GetEntryIconPalette(void *p) { char *q; if (MYSTERY_ALBUM_GetEntryKind(p)==1) { q=MYSTERY_ALBUM_GetEntryCard(p); return POKE_TOOL_CalcIconPalette(((MysteryAlbumCard *)q)->species,((MysteryAlbumCard *)q)->form,((MysteryAlbumCard *)q)->gender,((MysteryAlbumCard *)q)->isEgg); } return 0; }

int MYSTERY_ALBUM_GetEntryGraphicIndex(void *p)
{
    char *q;
    switch(MYSTERY_ALBUM_GetEntryKind(p)) {
    case 1:
        q=MYSTERY_ALBUM_GetEntryCard(p);
        return POKE_TOOL_CalcGraphicIndex(((MysteryAlbumCard *)q)->species,((MysteryAlbumCard *)q)->form,((MysteryAlbumCard *)q)->gender,((MysteryAlbumCard *)q)->isEgg);
    case 2:
        q=MYSTERY_ALBUM_GetEntryCard(p);
        return FILE_UTIL_Get((u16)((MysteryAlbumCard *)q)->arcId,1);
    default: return 12;
    }
}

int MYSTERY_ALBUM_GetEntrySpeciesId(void *p) { switch(MYSTERY_ALBUM_GetEntryKind(p)) { case 1: return func_0201BC40(); case 2: return 1; default:return 33; } }

int MYSTERY_ALBUM_GetEntryFormId(void *p) { switch(MYSTERY_ALBUM_GetEntryKind(p)) { case 1: return func_0201BCB4(); case 2: return 0; default:return 36; } }

int MYSTERY_ALBUM_GetEntryKind(void *p) { return ((MysteryAlbumEntry *)p)->card.giftType; }

char *MYSTERY_ALBUM_GetEntryCard(void *p) { return (char *)p+4; }

int MYSTERY_ALBUM_GetEntryEggFlag(u32 p) { return ((Bits *)(p+184))->flag; }

int MYSTERY_ALBUM_GetEntryIconX(void *p) { int i,add; i=MYSTERY_ALBUM_GetEntryKind(p); add=MYSTERY_ALBUM_GetEntryEggFlag((u32)p) ? 0 : 5; return add+d_021DF838[i]; }

int MYSTERY_ALBUM_GetEntryIconY(void *p) { int i,add; i=MYSTERY_ALBUM_GetEntryKind(p); add=MYSTERY_ALBUM_GetEntryEggFlag((u32)p) ? 3 : 0; return add+d_021DF848[i]; }

static inline int wrap(int value,int low,int high)
{
    if(value>high) return low;
    if(value<low) return high;
    return value;
}

/*
 * spelling: BF04 uses char-pointer arithmetic and a signed acc read, retaining the post-switch acc reload; raw integer address arithmetic was four bytes short.
 * interfaces: 02035C60's live r0 is consumed by this caller despite its legacy void definition.
 */
void MYSTERY_ALBUM_SelectHandler(void *task,u32 *state,char *p)
{
    u32 repeat;
    int delta,changed,count,next,direction;
    Position_021DC030 pos;
    switch(*state) {
    case 0:
        CLACT_SetActorDrawEnable(((MysteryAlbumWork *)p)->actorC,1);
        CLACT_SetActorDrawEnable(((MysteryAlbumWork *)p)->actorD,1);
        CLACT_SetActorDrawEnable(((MysteryAlbumWork *)p)->actorA,1);
        repeat=KEY_GetRepeat();
        changed=0;delta=0;
        if(TOUCHPANEL_GetTrg()) {
            ((MysteryAlbumWork *)p)->selectedAlbum=*(void **)((u32)p+0xa7c+(u16)(((MysteryAlbumWork *)p)->cursorMode+*(u32 *)&((MysteryAlbumWork *)p)->cursorIndex*4)*4);
            if(((MysteryAlbumWork *)p)->selectedAlbum) MYSTERY_ALBUM_StartIntro(((MysteryAlbumWork *)p)->selectedAlbum);
        }
        if(repeat==512) delta=-1;
        else if(repeat==256) delta=1;
        else if(repeat&64) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            switch(((MysteryAlbumWork *)p)->cursorMode) {
            case 0:
                if(((MysteryAlbumWork *)p)->introActive) ((MysteryAlbumWork *)p)->cursorMode=2;
                else {((MysteryAlbumWork *)p)->introMode=1;((MysteryAlbumWork *)p)->cursorMode=4;}
                break;
            case 1:
                if(((MysteryAlbumWork *)p)->introActive) ((MysteryAlbumWork *)p)->cursorMode=3;
                else {((MysteryAlbumWork *)p)->introMode=0;((MysteryAlbumWork *)p)->cursorMode=4;}
                break;
            case 2: ((MysteryAlbumWork *)p)->cursorMode=0;break;
            case 3: ((MysteryAlbumWork *)p)->cursorMode=1;break;
            case 4:
                if(((MysteryAlbumWork *)p)->introMode) ((MysteryAlbumWork *)p)->cursorMode=2;
                else ((MysteryAlbumWork *)p)->cursorMode=3;
                break;
            }
            changed=1;
        } else if(repeat&128) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            switch(((MysteryAlbumWork *)p)->cursorMode) {
            case 0: ((MysteryAlbumWork *)p)->cursorMode=2;break;
            case 1: ((MysteryAlbumWork *)p)->cursorMode=3;break;
            case 2:
                if(((MysteryAlbumWork *)p)->introActive) ((MysteryAlbumWork *)p)->cursorMode=0;
                else {((MysteryAlbumWork *)p)->introMode=1;((MysteryAlbumWork *)p)->cursorMode=4;}
                break;
            case 3:
                if(((MysteryAlbumWork *)p)->introActive) ((MysteryAlbumWork *)p)->cursorMode=1;
                else {((MysteryAlbumWork *)p)->introMode=0;((MysteryAlbumWork *)p)->cursorMode=4;}
                break;
            case 4:
                if(((MysteryAlbumWork *)p)->introMode) ((MysteryAlbumWork *)p)->cursorMode=0;
                else ((MysteryAlbumWork *)p)->cursorMode=1;
                break;
            }
            changed=1;
        } else if(repeat&32) {
            MYSTERY_ALBUM_GetColumnCount(p);
            if(((MysteryAlbumWork *)p)->cursorMode==0 || ((MysteryAlbumWork *)p)->cursorMode==2) delta=-1;
            else if(((MysteryAlbumWork *)p)->cursorMode!=4) GFL_USE_PlaySeDefaultVolume(0x548);
            if(((MysteryAlbumWork *)p)->cursorMode!=4) {
                if(((MysteryAlbumWork *)p)->cursorMode<=1) {
                    --((MysteryAlbumWork *)p)->cursorMode;
                    ((MysteryAlbumWork *)p)->cursorMode=wrap(((MysteryAlbumWork *)p)->cursorMode,0,1);
                } else {
                    --((MysteryAlbumWork *)p)->cursorMode;
                    ((MysteryAlbumWork *)p)->cursorMode=wrap(((MysteryAlbumWork *)p)->cursorMode,2,3);
                }
                changed=1;
            }
        } else if(repeat&16) {
            MYSTERY_ALBUM_GetColumnCount(p);
            if(((MysteryAlbumWork *)p)->cursorMode==1 || ((MysteryAlbumWork *)p)->cursorMode==3) delta=1;
            else if(((MysteryAlbumWork *)p)->cursorMode!=4) GFL_USE_PlaySeDefaultVolume(0x548);
            if(((MysteryAlbumWork *)p)->cursorMode!=4) {
                if(((MysteryAlbumWork *)p)->cursorMode<=1) {
                    ++((MysteryAlbumWork *)p)->cursorMode;
                    ((MysteryAlbumWork *)p)->cursorMode=wrap(((MysteryAlbumWork *)p)->cursorMode,0,1);
                } else {
                    ++((MysteryAlbumWork *)p)->cursorMode;
                    ((MysteryAlbumWork *)p)->cursorMode=wrap(((MysteryAlbumWork *)p)->cursorMode,2,3);
                }
                changed=1;
            }
        } else if(KEY_GetTrg()&1) {
            if(((MysteryAlbumWork *)p)->cursorMode==4) {
                if(((MysteryAlbumWork *)p)->introActive==0) {
                    CLACT_SetActorDrawEnable(((MysteryAlbumWork *)p)->actorC,0);
                    CLACT_SetActorDrawEnable(((MysteryAlbumWork *)p)->actorD,0);
                    GFL_USE_PlaySeDefaultVolume(0x54c);
                    MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_SaveHandler);
                }
            } else if(MYSTERY_ALBUM_IsEntryValid((int *)(p+40+220*((u32)*(int *)&((MysteryAlbumWork *)p)->cursorMode+*(u32 *)&((MysteryAlbumWork *)p)->cursorIndex*4)))) {
                CLACT_SetActorDrawEnable(((MysteryAlbumWork *)p)->actorC,0);
                CLACT_SetActorDrawEnable(((MysteryAlbumWork *)p)->actorD,0);
                GFL_USE_PlaySeDefaultVolume(0x54c);
                if(((MysteryAlbumWork *)p)->introActive) MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_MoveHandler);
                else MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_ConfirmHandler);
            }
        } else if(KEY_GetTrg()&2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            if(((MysteryAlbumWork *)p)->introActive) {
                if(*(u8 * *)&((MysteryAlbumWork *)p)->menuWindow) {MYSTERY_UTIL_DeleteMenuWindow(*(u8 * *)&((MysteryAlbumWork *)p)->menuWindow);((MysteryAlbumWork *)p)->menuWindow=0;}
                CLACT_SetActorDrawEnable(((MysteryAlbumWork *)p)->actorB,0);
                ((MysteryAlbumWork *)p)->introActive=0;
            } else {
                CLACT_SetActorDrawEnable(((MysteryAlbumWork *)p)->actorC,0);
                CLACT_SetActorDrawEnable(((MysteryAlbumWork *)p)->actorD,0);
                MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_SaveHandler);
            }
        }
        if(delta) {
            count=MYSTERY_ALBUM_GetColumnCount(p);
            if(delta<0) {
                if(((MysteryAlbumWork *)p)->cursorIndex) next=((MysteryAlbumWork *)p)->cursorIndex-1;
                else next=count-1;
                direction=1;
            } else if(delta>0) {
                if(((MysteryAlbumWork *)p)->cursorIndex<count-1) next=((MysteryAlbumWork *)p)->cursorIndex+1;
                else next=0;
                direction=0;
            }
            GFL_USE_PlaySeDefaultVolume(0x642);
            MYSTERY_ALBUM_StartScroll((u8 *)p,direction);
            MYSTERY_ALBUM_UpdateSlots(p,0);
            MYSTERY_ALBUM_SetCursor(p,0,direction,next,((MysteryAlbumWork *)p)->heapId);
            ((MysteryAlbumWork *)p)->cursorIndex=next;
            CLACT_SetActorDrawEnable(((MysteryAlbumWork *)p)->actorA,0);
            CLACT_SetActorDrawEnable(((MysteryAlbumWork *)p)->actorC,0);
            CLACT_SetActorDrawEnable(((MysteryAlbumWork *)p)->actorD,0);
            ((MysteryAlbumWork *)p)->angle=0;
            ((MysteryAlbumWork *)p)->refreshFlag=1;
            *state=1;
        }
        if(changed) {
            if((int)((MysteryAlbumWork *)p)->cursorMode<4) {
                pos.x=data_021DF86E[*(u32 *)(p+0xacc)].c.x*8-24;
                pos.y=data_021DF86E[*(u32 *)(p+0xacc)].c.y*8-8;
                CLACT_SetActorAnimSeq(((MysteryAlbumWork *)p)->actorA,0);
            } else {
                pos.x=176;pos.y=152;
                CLACT_SetActorAnimSeq(((MysteryAlbumWork *)p)->actorA,11);
            }
            CLACT_AddActorSurfacePos(((MysteryAlbumWork *)p)->actorA,(const struct Vec2 *)(&pos),0);
            ((MysteryAlbumWork *)p)->angle=0;
            ((MysteryAlbumWork *)p)->refreshFlag=1;
        }
        break;
    case 1:
        if(MYSTERY_ALBUM_UpdateScroll(p)) *state=0;
        break;
    }
}

void MYSTERY_ALBUM_ConfirmHandler(void *task,u32 *state,u8 *p)
{
    Desc_021DC4F0 d;
    Vec v;
    int result;
    switch (*state) {
    case 0:
        if (!((MysteryAlbumWork *)p)->menuWindow) {
            ((MysteryAlbumWork *)p)->menuWindow=MYSTERY_UTIL_CreateMenuWindow(0,15,((MysteryAlbumWork *)p)->windowParamB,((MysteryAlbumWork *)p)->windowParamA,29);
            MYSTERY_UTIL_DrawMenuWindow(((MysteryAlbumWork *)p)->menuWindow,1,13);
        }
        MYSTERY_UTIL_SetMenuMessage(((MysteryAlbumWork *)p)->menuWindow,((MysteryAlbumWork *)p)->bank,116,0);
        *state=1;
        break;
    case 1:
        MI_CpuFill8(&d,0,36);
        d.v[0]=*(u32 *)&((MysteryAlbumWork *)p)->bank; d.v[1]=*(u32 *)&((MysteryAlbumWork *)p)->windowParamA; d.v[2]=*(u32 *)&((MysteryAlbumWork *)p)->windowParamB;
        d.v[3]=117;d.v[4]=118;d.v[5]=119;d.v[6]=3;
        d.a=0;d.b=15;d.c=13;d.d=1;
        ((MysteryAlbumWork *)p)->menu=MYSTERY_UTIL_CreateMenu((const u8 *)(&d),((MysteryAlbumWork *)p)->heapId);
        *state=2;
        break;
    case 2:
        result=MYSTERY_UTIL_UpdateMenu(((MysteryAlbumWork *)p)->menu);
        ((MysteryAlbumWork *)p)->angle=0x7fff;
        if (result==-1) break;
        if (result==0) {
            ((MysteryAlbumWork *)p)->introActive=1;
            v.x=data_021DF86E[*(u32 *)(p+0xacc)].c.x*8-24;
            v.y=data_021DF86E[*(u32 *)(p+0xacc)].c.y*8-8;
            CLACT_AddActorSurfacePos(((MysteryAlbumWork *)p)->actorB,(const struct Vec2 *)(&v),0);
            CLACT_SetActorDrawEnable(((MysteryAlbumWork *)p)->actorB,1);
            ((MysteryAlbumWork *)p)->swapIndex=((MysteryAlbumWork *)p)->cursorMode+((MysteryAlbumWork *)p)->cursorIndex*4;
            if (((MysteryAlbumWork *)p)->menu) {MYSTERY_UTIL_DeleteMenu(((MysteryAlbumWork *)p)->menu);((MysteryAlbumWork *)p)->menu=0;}
            if (*(u8 * *)&((MysteryAlbumWork *)p)->menuWindow) {MYSTERY_UTIL_DeleteMenuWindow(*(u8 * *)&((MysteryAlbumWork *)p)->menuWindow);((MysteryAlbumWork *)p)->menuWindow=0;}
            if (!((MysteryAlbumWork *)p)->menuWindow) {
                ((MysteryAlbumWork *)p)->menuWindow=MYSTERY_UTIL_CreateMenuWindow2(0,15,((MysteryAlbumWork *)p)->windowParamB,((MysteryAlbumWork *)p)->windowParamA,29);
                MYSTERY_UTIL_DrawMenuWindow(((MysteryAlbumWork *)p)->menuWindow,1,13);
            }
            MYSTERY_UTIL_SetMenuMessage(((MysteryAlbumWork *)p)->menuWindow,((MysteryAlbumWork *)p)->bank,122,0);
            *state=6;
        } else if (result==1) {
            if (MYSTERY_ALBUM_GetEntryEggFlag((u32)((void *)((u32)p+40+220*(((MysteryAlbumWork *)p)->cursorMode+((MysteryAlbumWork *)p)->cursorIndex*4))))) *state=7;
            else *state=3;
        } else if (result==2) *state=5;
        break;
    case 3:
        if (((MysteryAlbumWork *)p)->menu) {MYSTERY_UTIL_DeleteMenu(((MysteryAlbumWork *)p)->menu);((MysteryAlbumWork *)p)->menu=0;}
        MYSTERY_UTIL_SetMenuMessage(((MysteryAlbumWork *)p)->menuWindow,((MysteryAlbumWork *)p)->bank,120,1);
        *state=4;
        break;
    case 4:
        if (MYSTERY_UTIL_GetMenuState(((MysteryAlbumWork *)p)->menuWindow)) *state=5;
        break;
    case 5:
        if (*(u8 * *)&((MysteryAlbumWork *)p)->menuWindow) {MYSTERY_UTIL_DeleteMenuWindow(*(u8 * *)&((MysteryAlbumWork *)p)->menuWindow);((MysteryAlbumWork *)p)->menuWindow=0;}
        if (((MysteryAlbumWork *)p)->menu) {MYSTERY_UTIL_DeleteMenu(((MysteryAlbumWork *)p)->menu);((MysteryAlbumWork *)p)->menu=0;}
        MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_SelectHandler);
        break;
    case 6:
        MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_SelectHandler);
        break;
    case 7:
        MYSTERY_UTIL_DeleteMenu(((MysteryAlbumWork *)p)->menu);((MysteryAlbumWork *)p)->menu=0;
        MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_InfoHandler);
        break;
    }
    if (*(u8 * *)&((MysteryAlbumWork *)p)->menuWindow) MYSTERY_UTIL_UpdateMenuWindow(*(u8 * *)&((MysteryAlbumWork *)p)->menuWindow);
}

static inline void window0(int x,int y,int xx,int yy)
{
    *(volatile u16 *)0x04000040=((x<<8)&0xff00)|(xx&255);
    *(volatile u16 *)0x04000044=((y<<8)&0xff00)|(yy&255);
}

static inline void inside(int planes,int effect)
{
    u32 v=(*(volatile u16 *)0x04000048&~0x3f)|(u32)planes;
    if(effect) v|=32;
    *(volatile u16 *)0x04000048=v;
}

static inline void outside(int planes,int effect)
{
    u32 v=(*(volatile u16 *)0x0400004a&~0x3f)|(u32)planes;
    if(effect) v|=32;
    *(volatile u16 *)0x0400004a=v;
}

/*
 * lever: int coordinate locals retain table loads before SDK window plane writes; u8 locals were 4 bytes short.
 * volatile: display control 021DC82C/838/950/958; window registers 021DC84E..892.
 */
void MYSTERY_ALBUM_InfoHandler(void *task,u32 *state,char *p)
{
    Desc_021DC734 d;
    u32 index=W(0xac8)*4+W(0xacc);
    int result;
    int x,y;
    switch(*state) {
    case 0:MYSTERY_UTIL_SetMenuMessage(P(0xabc),W(28),123,1);*state=1;break;
    case 1:
        if(MYSTERY_UTIL_GetMenuState(P(0xabc))) {
            MI_CpuFill8(&d,0,36);
            d.v[0]=W(28);d.v[1]=W(16);d.v[2]=W(20);
            d.v[3]=124;d.v[4]=125;d.v[6]=2;
            d.a=0;d.b=15;d.c=13;d.d=1;
            P(0xac0)=MYSTERY_UTIL_CreateMenu((const u8 *)&d,H(36));
            *state=2;
        }
        break;
    case 2:
        result=MYSTERY_UTIL_UpdateMenu((char *)P(0xac0));
        H(0xbac)=0x7fff;
        if(result!=-1) {
            MYSTERY_UTIL_DeleteMenu(P(0xac0));P(0xac0)=0;
            if(!result) *state=3;
            else {
                if(P(0xabc)) {MYSTERY_UTIL_DeleteMenuWindow(P(0xabc));P(0xabc)=0;}
                MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_SelectHandler);
            }
        }
        break;
    case 3:
        *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000&~0xe000)|0x2000;
        x=d_021DF86E[(u8)(index&3)*8];
        y=d_021DF86F[(u8)(index&3)*8];
        inside(30,1);
        window0(x*8,y*8,(x+12)*8,(y+7)*8);
        outside(30,0);*state=4;break;
    case 4:
        func_0207D658(0x04000050,30,W(0xae8)*16/30);
        if(W(0xae8)++>30) {W(0xae8)=0;*state=5;}
        break;
    case 5:
        MYSTERY_ALBUM_RemoveCard((MysteryAlbumWork *)p, index);
        MYSTERY_ALBUM_UpdateSlots(p,1);
        MYSTERY_ALBUM_SetCursor(p,1,0,W(0xac8),H(36));
        W(0xa78)=1;*state=6;break;
    case 6:
        func_0207D658(0x04000050,30,16-W(0xae8)*16/30);
        if(W(0xae8)++>30) {W(0xae8)=0;*state=7;}
        break;
    case 7:
        if(!MYSTERY_DATA_HasAnyCard((char *)P(12))) MYSTERY_UTIL_ClearListWindow(P(0xab8),1);
        *(volatile u32 *)0x04000000 &= ~0xe000;
        *state=8;break;
    case 8:MYSTERY_UTIL_SetMenuMessage(P(0xabc),W(28),121,1);*state=9;break;
    case 9:if(MYSTERY_UTIL_GetMenuState(P(0xabc))) *state=10;break;
    case 10:
        if(P(0xabc)) {MYSTERY_UTIL_DeleteMenuWindow(P(0xabc));P(0xabc)=0;}
        MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_SelectHandler);break;
    }
    if(P(0xabc)) MYSTERY_UTIL_UpdateMenuWindow(P(0xabc));
}

static inline void window1(int x,int y,int xx,int yy)
{
    *(volatile u16 *)0x04000042=((x<<8)&0xff00)|(xx&255);
    *(volatile u16 *)0x04000046=((y<<8)&0xff00)|(yy&255);
}

static inline void inside0(int planes,int effect)
{
    u32 v=(*(volatile u16 *)0x04000048&~0x3f)|(u32)planes;
    if(effect) v|=32;
    *(volatile u16 *)0x04000048=v;
}

static inline void inside1(int planes,int effect)
{
    u32 v=(*(volatile u16 *)0x04000048&~0x3f00)|((u32)planes<<8);
    if(effect) v|=32<<8;
    *(volatile u16 *)0x04000048=v;
}

/*
 * lever: index read through a two-field struct, but the row field is re-read as a plain int in the cases (a different type stops the CSE across the switch); previous-cell value shifted unsigned; col declared before row for the slot order. Twin shape: ov121 021DC734.
 * note: 2026-10-05 recoup P23L5: 8 B DIFF first form (asrs for lsrs and row/col slots swapped), then EXACT. Real extent 792 B, not the 46 B of the lane list.
 * volatile: display control 04000000, window registers 04000040..4A.
 */
void MYSTERY_ALBUM_MoveHandler(void *task,u32 *state,char *p)
{
    u32 index=((Cur_021DC030 *)p)->col+((Cur_021DC030 *)p)->row*4;
    int here,there,mask;
    int x,y;
    u8 now,old;
    int col,row;
    switch(*state) {
    case 0:
        if(P(0xabc)) {MYSTERY_UTIL_DeleteMenuWindow(P(0xabc));P(0xabc)=0;}
        W(0xae0)=0;
        if(index==H(0xade)) {
            CLACT_SetActorDrawEnable((struct Obj *)P(0xaf0),0);
            MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_SelectHandler);
            return;
        }
        *state=1;break;
    case 1:
        now=index&3;
        old=H(0xade)%4;
        here=((*(int *)(p+0xac8))==(index>>2));
        there=((*(int *)(p+0xac8))==((u32)H(0xade)>>2));
        mask=0;if(here) mask|=1;if(there) mask|=2;
        *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000&~0xe000)|(mask<<13);
        if(here) {
            x=d_021DF86E[now*8];y=d_021DF86F[now*8];
            inside0(30,1);window0(x*8,y*8,(x+12)*8,(y+7)*8);
        }
        if(there) {
            x=d_021DF86E[old*8];y=d_021DF86F[old*8];
            inside1(30,1);window1(x*8,y*8,(x+12)*8,(y+7)*8);
        }
        outside(30,0);*state=2;break;
    case 2:
        func_0207D658(0x04000050,30,W(0xae8)*16/30);
        if(W(0xae8)++>30) {W(0xae8)=0;*state=3;}break;
    case 3:
        MYSTERY_ALBUM_SwapCards((MysteryAlbumWork *)p,index,H(0xade));GFL_USE_PlaySeDefaultVolume(0x670);
        row=(u32)H(0xade)>>2;col=H(0xade)%4;
        there=((*(int *)(p+0xac8))==row);
        here=((*(int *)(p+0xac8))==(index>>2));
        if(here) {
            MYSTERY_ALBUM_DeleteSlotActor(p,1,W(0xacc));
            MYSTERY_ALBUM_SetupSlot(p,1,0,(*(int *)(p+0xac8)),W(0xacc),H(36));
        }
        if(there) {
            MYSTERY_ALBUM_DeleteSlotActor(p,1,col);
            MYSTERY_ALBUM_SetupSlot(p,1,0,row,col,H(36));
        }
        BG_SYS_PushTile(3);W(0xa78)=1;*state=4;break;
    case 4:
        func_0207D658(0x04000050,30,16-W(0xae8)*16/30);
        if(W(0xae8)++>30) {W(0xae8)=0;*state=5;}break;
    case 5:*(volatile u32 *)0x04000000 &=~0xe000;*state=6;break;
    case 6:
        W(0xae0)=0;CLACT_SetActorDrawEnable((struct Obj *)P(0xaf0),0);
        if(P(0xabc)) {MYSTERY_UTIL_DeleteMenuWindow(P(0xabc));P(0xabc)=0;}
        MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_SelectHandler);break;
    }
}

/*
 * lever: separate case-1 guard tests preserve the branch to the shared state store; a short-circuit guard gives DIFF404.
 */
void MYSTERY_ALBUM_SaveHandler(void *arg,u32 *state,char *p)
{
    Desc_021DCCE4 d;
    int result;
    int ready;
    switch (*state) {
    case 0:
        *state=1;
        break;
    case 1:
        if (!((MysteryAlbumWork *)p)->mode) *state=5;
        else if (MYSTERY_DATA_HasCardSpace(((MysteryAlbumWork *)p)->cardList)) *state=5;
        else *state=2;
        break;
    case 2:
        if (!((MysteryAlbumWork *)p)->menuWindow) {
            ((MysteryAlbumWork *)p)->menuWindow=MYSTERY_UTIL_CreateMenuWindow(0,15,((MysteryAlbumWork *)p)->windowParamB,((MysteryAlbumWork *)p)->windowParamA,29);
            MYSTERY_UTIL_DrawMenuWindow(((MysteryAlbumWork *)p)->menuWindow,1,13);
        }
        MYSTERY_UTIL_SetMenuMessage(((MysteryAlbumWork *)p)->menuWindow,((MysteryAlbumWork *)p)->bank,93,1);
        *state=3;
        break;
    case 3:
        if (MYSTERY_UTIL_GetMenuState(((MysteryAlbumWork *)p)->menuWindow)) {
            MI_CpuFill8(&d,0,36);
            d.v[0]=*(u32 *)&((MysteryAlbumWork *)p)->bank;
            d.v[1]=*(u32 *)&((MysteryAlbumWork *)p)->windowParamA;
            d.v[2]=*(u32 *)&((MysteryAlbumWork *)p)->windowParamB;
            d.v[3]=124;
            d.v[4]=125;
            d.v[6]=2;
            d.a=0; d.b=15; d.c=13; d.d=1;
            ((MysteryAlbumWork *)p)->menu=MYSTERY_UTIL_CreateMenu((const u8 *)(&d),((MysteryAlbumWork *)p)->heapId);
            *state=4;
        }
        break;
    case 4:
        result=MYSTERY_UTIL_UpdateMenu(((MysteryAlbumWork *)p)->menu);
        ((MysteryAlbumWork *)p)->angle=0x7fff;
        if (result!=-1) {
            MYSTERY_UTIL_DeleteMenu(((MysteryAlbumWork *)p)->menu);
            ((MysteryAlbumWork *)p)->menu=0;
            if (!result) *state=5;
            else {
                if (((MysteryAlbumWork *)p)->menuWindow) {
                    MYSTERY_UTIL_DeleteMenuWindow(((MysteryAlbumWork *)p)->menuWindow);
                    ((MysteryAlbumWork *)p)->menuWindow=0;
                }
                MYSTERY_UTIL_SetTaskHandler(arg,(u32)MYSTERY_ALBUM_SelectHandler);
            }
        }
        break;
    case 5:
        if (((MysteryAlbumWork *)p)->dirty) *state=6;
        else *state=10;
        break;
    case 6:
        if (!((MysteryAlbumWork *)p)->menuWindow) {
            ((MysteryAlbumWork *)p)->menuWindow=MYSTERY_UTIL_CreateMenuWindow(0,15,((MysteryAlbumWork *)p)->windowParamB,((MysteryAlbumWork *)p)->windowParamA,29);
            MYSTERY_UTIL_DrawMenuWindow(((MysteryAlbumWork *)p)->menuWindow,1,13);
        }
        MYSTERY_UTIL_SetMenuMessage(((MysteryAlbumWork *)p)->menuWindow,((MysteryAlbumWork *)p)->bank,115,2);
        *state=7;
        break;
    case 7:
        if (MYSTERY_UTIL_GetMenuState(((MysteryAlbumWork *)p)->menuWindow)) *state=8;
        break;
    case 8:
        ready=1;
        if (((MysteryAlbumWork *)p)->selectedAlbum && !MYSTERY_ALBUM_IsIntroIdle(((MysteryAlbumWork *)p)->selectedAlbum)) ready=0;
        if (ready) {
            MYSTERY_DATA_SaveStart(((MysteryAlbumWork *)p)->cardList,(int)(((MysteryAlbumWork *)p)->saveParam));
            *state=9;
        }
        break;
    case 9:
        if (MYSTERY_DATA_SaveMain(((MysteryAlbumWork *)p)->cardList,(int)(((MysteryAlbumWork *)p)->saveParam))==2) *state=10;
        break;
    case 10:
        if (((MysteryAlbumWork *)p)->menuWindow) {
            MYSTERY_UTIL_DeleteMenuWindow(((MysteryAlbumWork *)p)->menuWindow);
            ((MysteryAlbumWork *)p)->menuWindow=0;
        }
        MYSTERY_UTIL_MarkTaskDone(arg);
        break;
    }
    if (((MysteryAlbumWork *)p)->menuWindow) MYSTERY_UTIL_UpdateMenuWindow(((MysteryAlbumWork *)p)->menuWindow);
}

void MYSTERY_ALBUM_SingleHandler(void *arg,int *state,char *p)
{
    switch (*state) {
    case 0:
        if (!((MysteryAlbumWork *)p)->menuWindow)
            ((MysteryAlbumWork *)p)->menuWindow=MYSTERY_UTIL_CreateMenuWindow(0,15,((MysteryAlbumWork *)p)->windowParamB,((MysteryAlbumWork *)p)->windowParamA,29);
        MYSTERY_UTIL_DrawMenuWindow(((MysteryAlbumWork *)p)->menuWindow,1,13);
        MYSTERY_UTIL_SetMenuMessage(((MysteryAlbumWork *)p)->menuWindow,((MysteryAlbumWork *)p)->bank,92,1);
        *state=1; break;
    case 1:
        if (MYSTERY_UTIL_GetMenuState(((MysteryAlbumWork *)p)->menuWindow)) *state=2;
        break;
    case 2:
        if (((MysteryAlbumWork *)p)->menuWindow) {
            MYSTERY_UTIL_DeleteMenuWindow(((MysteryAlbumWork *)p)->menuWindow);
            ((MysteryAlbumWork *)p)->menuWindow=0;
        }
        MYSTERY_UTIL_SetTaskHandler(arg,(u32)MYSTERY_ALBUM_SelectHandler);
        break;
    }
    if (((MysteryAlbumWork *)p)->menuWindow) MYSTERY_UTIL_UpdateMenuWindow(((MysteryAlbumWork *)p)->menuWindow);
}

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void MYSTERY_ALBUM_SetupIconSprite(char *p,void *arc,int id,int index,u8 other,u16 heap)
{
    void *res;
    void *allocation;
    char *data;
    MI_CpuFill8(p,0,0x60);
    allocation=func_02049F78(arc,id,(u32)(&res),heap);
    data=*(char * *)&((struct Obj22906 *)res)->fC;
    MI_CpuCopy8(data+index*32,p+0x40,32);
    MI_CpuCopy8(data+other*32,p+0x20,32);
    func_020307B0(allocation);
}

void MYSTERY_ALBUM_UpdateIconSprite(u8 *p,int b,int c,u16 d) {MYSTERY_UTIL_BlendPaletteRange((void *)b,(u16 *)p,d,c,(const u16 *)(p+32),(const u16 *)(p+64));}

/*
 * lever: const descriptor input places its loads before the outgoing heap store.
 * interfaces: D81C/D898 scalar stack words reproduce the aggregate layout; complete bodies and forwarding targets read no padding, key only low halfword.
 */
void *MYSTERY_ALBUM_CreateSlotWork(const Desc_021DCFC8 *p,u16 heap)
{
    char *out;
    Config config;
    Record_021DCFC8 first;
    Record_021DCFC8 second;
    void *arc;
    void *arc2;
    out=func_02030734(heap,208,0,d_021DFBB0,0xcff);
    ((struct Obj00237 *)out)->f88=p->w[5];
    ((struct Obj00237 *)out)->f94=p->w[0];
    ((struct Obj00237 *)out)->f96=p->w[1];
    *(Desc_021DCFC8 *)(out+0xa0)=*p;
    if(p->w[0]<4) {
        ((struct Obj00237 *)out)->f9C=0;
        ((struct Obj00237 *)out)->f98=0;
        ((struct Obj00237 *)out)->f84=1;
    } else {
        ((struct Obj00237 *)out)->f9C=4;
        ((struct Obj00237 *)out)->f98=1;
        ((struct Obj00237 *)out)->f84=0;
    }
    config=d_021DF99C;
    /* stand-in: unprototyped call; the prototype's u16/u8 parameters narrow the arguments and change the bytes */
    ((struct Obj00237 *)out)->f0=((void *(*)())MYSTERY_UTIL_CreateWindowList)((void *)1,(const char *)&config,5,(u16)((struct Obj00237 *)out)->fA4,(u8)((struct Obj00237 *)out)->fAC,((struct Obj00237 *)out)->fC8,((struct Obj00237 *)out)->fC0,((struct Obj00237 *)out)->fC4,heap);
    arc=func_020490F4(34,heap);
    *(int *)&((struct Obj00237 *)out)->f4=CLACT_RegisterPalette(arc,3,((struct Obj00237 *)out)->f98,(u16)(p->w[4]<<5),heap);
    *(int *)&((struct Obj00237 *)out)->fC=CLACT_RegisterCellAnim(arc,33,36,heap);
    *(int *)&((struct Obj00237 *)out)->f8=CLACT_RegisterCharacter(arc,12,0,((struct Obj00237 *)out)->f98,heap);
    ARC_TOOL_DeleteHandle(arc);
    MI_CpuFill8(&first,0,8);
    first.x=216;first.y=22;
    ((struct Obj00237 *)out)->f1C=CLACT_CreateActor((void *)p->w[6],((struct Obj00237 *)out)->f8,((struct Obj00237 *)out)->f4,((struct Obj00237 *)out)->fC,&first,((struct Obj00237 *)out)->f98,heap);
    CLACT_SetActorObjMode(((struct Obj00237 *)out)->f1C,0);
    CLACT_SetActorDrawEnable(((struct Obj00237 *)out)->f1C,0);
    arc2=(void *)POKEGRA_OpenHandle(heap);
    *(int *)&((struct Obj00237 *)out)->f10=POKEGRA_RegisterPalette((int)arc2,1,0,0,0,0,0,((struct Obj00237 *)out)->f98,p->w[5]<<5,heap);
    *(int *)&((struct Obj00237 *)out)->f18=POKEGRA_RegisterCellAnim(1,0,0,0,0,0,2,((struct Obj00237 *)out)->f98,heap);
    *(int *)&((struct Obj00237 *)out)->f14=POKEGRA_RegisterCgr(arc2,1,0,0,0,0,0,0,((struct Obj00237 *)out)->f98,heap);
    ARC_TOOL_DeleteHandle(arc2);
    MI_CpuFill8(&second,0,8);
    second.x=184;second.y=112;second.b=p->w[0]&3;
    ((struct Obj00237 *)out)->f8C=second.b;
    ((struct Obj00237 *)out)->f90=p->w[1]&3;
    ((struct Obj00237 *)out)->f20=CLACT_CreateActor((void *)p->w[6],((struct Obj00237 *)out)->f14,((struct Obj00237 *)out)->f10,((struct Obj00237 *)out)->f18,&second,((struct Obj00237 *)out)->f98,heap);
    CLACT_SetActorAffineMode(((struct Obj00237 *)out)->f20,2);
    CLACT_SetActorObjMode(((struct Obj00237 *)out)->f20,1);
    CLACT_SetActorDrawEnable(((struct Obj00237 *)out)->f20,0);
    return out;
}

void MYSTERY_ALBUM_DeleteSlotWork(void **p)
{
    CLACT_DeleteActor(p[8]);
    CLACT_ReleaseCharacter((u32)p[5]);
    CLACT_ReleaseCellAnim((u32)p[6]);
    CLACT_ReleasePalette((u32)p[4]);
    CLACT_DeleteActor(p[7]);
    CLACT_ReleaseCharacter((u32)p[2]);
    CLACT_ReleaseCellAnim((u32)p[3]);
    CLACT_ReleasePalette((u32)p[1]);
    MYSTERY_UTIL_DeleteWindowList(p[0]);
    func_020307B0(p);
}

int MYSTERY_ALBUM_UpdateSlotWork(void **p) {return MYSTERY_UTIL_IsWindowListDone(*p);}

struct Out_021DC030 *MYSTERY_ALBUM_CreateAlbumView(Record_021DD24C *a, struct CtxB *b, void *c, u16 heap)
{
    struct Out_021DC030 *out;
    struct Ctx ctx;
    Desc_021DD24C desc;
    void *res;
    u16 idx;
    void *t4;
    int flags;
    void *mon;
    void *gs;
    u8 day;
    u32 month;
    u16 year;
    u32 mode;
    u32 gender;
    u64 rnd;
    u32 species;
    u16 level;
    u16 hid;
    u32 id16;
    u32 id;
    u64 id64;

    out = func_02030734(heap, 0x148, 0, d_021DFBB0, 0xDD4);
    MI_CpuFill8(out, 0, 0x148);
    out->heap = heap;
    out->a = (struct Rec_021DC030 *)a;
    out->b = b;
    out->c = c;
    MI_CpuFill8(&ctx, 0, 0x24);
    ctx.f0 = 0;
    ctx.f8 = b->fB8;
    ctx.fC = b->fBC;
    ctx.f10 = b->fC4;
    ctx.f14 = b->fC8;
    ctx.f18 = b->fCC;
    ctx.f1C = b->fC0;
    ctx.f20 = (u32)c;
    MYSTERY_ALBUM_SetupEntry((char *)out, (const Record_021DB938 *)a, (char *)&ctx, heap);
    desc = d_021DFA14;
    id16 = (heap & 0x7fff) | 0x8000;
    desc.e[1].f8 = STRBUF_Create(0x25, (u16)id16);
    STRBUF_SetStringN(desc.e[1].f8, (const u16 *)((char *)out->a + 0x60), 0x24);
    if (out->a->fB4b)
        idx = out->a->fB2 + 0x19d;
    else
        idx = out->a->fB2 + 0x9d;
    desc.e[2].f8 = func_02045EC0((void *)b->fC0, idx);
    desc.e[4].f8 = STRBUF_Create(0x80, heap);
    flags = out->a->fAC;
    t4 = func_02045EC0((void *)b->fC0, 0x9a);
    res = 0;
    WORDSET_SetSlotNumber((void *)b->fCC, 0, (u16)(flags >> 16), 4, 1, 1);
    WORDSET_SetSlotNumber((void *)b->fCC, 1, (u8)(flags >> 8), 2, 0, 1);
    WORDSET_SetSlotNumber((void *)b->fCC, 2, (u8)flags, 2, 0, 1);
    WORDSET_CopyTaggedText((void *)b->fCC, desc.e[4].f8, t4);
    out->f144 = MYSTERY_UTIL_CreateBmpList(*(void **)b, heap);
    MYSTERY_UTIL_DrawBmpList(out->f144, (char *)(&desc), (void *)b->fC8);
    STRBUF_Delete(desc.e[1].f8);
    STRBUF_Delete(desc.e[2].f8);
    STRBUF_Delete(desc.e[4].f8);
    STRBUF_Delete(t4);
    if (MYSTERY_ALBUM_GetEntryKind(out) == 1) {
        struct Rec_021DC030 *r = out->a;
        u16 mv[4];
        u8 iv[6];
        int i;
        u32 k;
        u32 ivs;

        gs = out->c;
        hid = id16;
        level = r->f5B;
        id = r->f0;
        species = r->species;
        gender = r->f35;
        mode = r->f36;

        iv[0] = r->iv0;
        iv[1] = r->iv1;
        iv[2] = r->iv2;
        iv[3] = r->iv7;
        iv[4] = r->iv3;
        iv[5] = r->iv6;
        mv[0] = r->mv[0];
        mv[1] = r->mv[1];
        mv[2] = r->mv[2];
        mv[3] = r->mv[3];
        if (r->fB3 == 1 && species <= 0x289 && species != 0 && level <= 0x64 && r->f10 <= 0x289 - 0x17) {
            if (level == 0)
                level = (u16)(func_020056EC(0x64) + 1);
            if (r->f0 == 0)
                id = func_02008530((const struct Sub0200852CObj *)func_02012944(gs));
            if (gender == 0xff)
                gender = 2;
            for (i = 0; i < 6; i++) {
                if (iv[i] == 0xff)
                    iv[i] = func_020056EC(0x20);
            }
            id64 = id;
            mon = POKE_TOOL_Create((u16)species, level, id, 0, hid);
            ivs = (iv[0] & 31) | ((iv[1] & 31) << 5) | ((iv[2] & 31) << 10) | ((iv[3] & 31) << 15) | ((iv[4] & 31) << 20) | ((iv[5] & 31) << 25);
            if (mode == 4)
                mode = (u8)func_020056EC(3);
            switch (mode) {
            case 0:
                i = 0;
                break;
            case 1:
                i = 1;
                break;
            case 2:
                i = 0;
                break;
            case 3:
                i = 2;
                break;
            default:
                res = 0;
                goto end;
            }
            if (r->f8 != 0)
                rnd = r->f8;
            else {
                if (r->f37 == 0)
                    rnd = POKE_TOOL_CreatePersonalRnd(id, (u16)species, r->form, gender, i, 0);
                else if (r->f37 == 1)
                    rnd = POKE_TOOL_CreatePersonalRnd(id, (u16)species, r->form, gender, i, 2);
                else if (r->f37 == 2)
                    rnd = POKE_TOOL_CreatePersonalRnd(id, (u16)species, r->form, gender, i, 1);
            }
            POKE_TOOL_SetupPartyParamEx(mon, r->species, level, id64, ivs, rnd);
            POKE_TOOL_SetPartyValue(mon, 6, r->f10);
            POKE_TOOL_SetDefaultMoves(mon);
            for (i = 0; i < 4; i++) {
                u16 m = mv[i];
                if (m != 0 && m < 0x230) {
                    if (POKE_TOOL_AddMove(mon, m) == 0xffff)
                        POKE_TOOL_PushMove(mon, m);
                }
            }
            if (r->f8 == 0 && mode == 2)
                func_02018A00(mon, species, r->form);
            POKE_TOOL_SetPartyValue(mon, 0x6f, r->form);
            if (r->fE != 0 && r->fE <= 0x19)
                POKE_TOOL_SetPartyValue(mon, 0x98, r->fE);
            else
                POKE_TOOL_SetPartyValue(mon, 0x98, 4);
            if (r->f3C != 0)
                POKE_TOOL_SetPartyValue(mon, 0x99, r->f3C);
            POKE_TOOL_SetPartyValue(mon, 0x13, r->f3D);
            POKE_TOOL_SetPartyValue(mon, 0x14, r->f3E);
            POKE_TOOL_SetPartyValue(mon, 0x15, r->f3F);
            POKE_TOOL_SetPartyValue(mon, 0x16, r->f40);
            POKE_TOOL_SetPartyValue(mon, 0x17, r->f41);
            POKE_TOOL_SetPartyValue(mon, 0x18, r->f41);
            for (k = 0; k < 15; k++) {
                if (r->fC & (1 << k))
                    POKE_TOOL_SetPartyValue(mon, d_021DF8C0[k], 1);
            }
            if (r->f4 == 0)
                POKE_TOOL_SetPartyValue(mon, 0x77, g0209DF08);
            else
                POKE_TOOL_SetPartyValue(mon, 0x77, r->f4);
            if (r->f1D == 0)
                POKE_TOOL_SetPartyValue(mon, 0xc, g0209DF0C);
            else
                POKE_TOOL_SetPartyValue(mon, 0xc, r->f1D);
            if (r->f1E == 0) {
                func_020307B0(mon);
                res = 0;
                goto end;
            }
            if (r->f1E != STRBUF_GetEosChar())
                POKE_TOOL_SetPartyValue(mon, 0x74, (u32)&r->f1E);
            {
                u32 v = r->f34;
                if (v == 0xff)
                    v = (u8)func_020056EC(0x19);
                POKE_TOOL_SetPartyValue(mon, 0x70, v);
            }
            POKE_TOOL_SetPartyValue(mon, 0x95, r->f38);
            POKE_TOOL_SetPartyValue(mon, 0x96, r->f3A);
            if (r->f4A == 0) {
                func_020307B0(mon);
                res = 0;
                goto end;
            }
            if (r->f4A == STRBUF_GetEosChar())
                POKE_TOOL_SetPartyValue(mon, 0x8e, (u32)func_020084F4(func_02012944(gs)));
            else
                POKE_TOOL_SetPartyValue(mon, 0x8e, (u32)&r->f4A);
            {
                u32 v = r->f5A;
                if (v <= 2)
                    POKE_TOOL_SetPartyValue(mon, 0x9a, v);
                else {
                    v = func_02008550((const struct Sub0200852CObj *)func_02012944(gs));
                    POKE_TOOL_SetPartyValue(mon, 0x9a, v);
                }
            }
            if (r->f5C != 0) {
                void *s;
                POKE_TOOL_SetPartyValue(mon, 0x4c, 1);
                s = func_02045EC0(gSpeciesNameBank, 0x28a);
                POKE_TOOL_SetPartyValue(mon, 0x73, (u32)s);
                STRBUF_Delete(s);
                POKE_TOOL_SetPartyValue(mon, 9, 10);
            }
            {
                int w = r->fAC;
                u32 loc;
                year = w >> 16;
                month = (u8)(w >> 8);
                day = w;
                loc = r->f5C ? r->f38 : r->f3A;
                SAVE_EVENT_WriteWithDate(func_020185F0(mon), loc, year - 2000, month, day);
            }
            POKE_TOOL_RecalcParam(mon);
            res = 0;
            if (func_02017E1C(mon, 3, 0) != 0)
                func_020307B0(mon);
            else
                res = mon;
            goto end;
        }
    end:
        {
            void *arc = (void *)POKEGRA_OpenHandle((u16)id16);
            u32 a0, a1, a2, a3;
            out->fE4 = r->species;
            out->fE6 = r->form;
            out->fE0 = r->f5C;
            a0 = POKEGRA_GetArcID();
            a1 = func_02017E1C(res, 5, 0);
            a2 = func_02017E1C(res, 0x6f, 0);
            a3 = func_02017E1C(res, 0x6e, 0);
            idx = POKEGRA_GetPalArcIndex(a0, a1, a2, a3, func_02017EAC(res), 0, func_02017E1C(res, 0x4c, 0));
            out->f13C = func_02049F78(arc, idx, (u32)(&out->f140), out->heap);
            out->f134 = (u32)POKEGRA_LoadCharDataPP(&out->f138, POKE_TOOL_GetBoxParam(res), 0, out->heap);
            func_020307B0(res);
            ARC_TOOL_DeleteHandle(arc);
        }
    }
    return out;
}
