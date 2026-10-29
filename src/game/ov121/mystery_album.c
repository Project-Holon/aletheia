/*
 * file:     mystery_album.c
 * unit:     yes
 * function: MYSTERY_ALBUM_Create, MYSTERY_ALBUM_DeleteWork, MYSTERY_ALBUM_Update, MYSTERY_ALBUM_UpdateWindows, MYSTERY_ALBUM_GetWindowState, MYSTERY_ALBUM_Setup, MYSTERY_ALBUM_Cleanup, MYSTERY_ALBUM_SetCursor, MYSTERY_ALBUM_DeleteSlotActors, MYSTERY_ALBUM_SetupSlot, MYSTERY_ALBUM_DeleteSlotActor, MYSTERY_ALBUM_StartScroll, MYSTERY_ALBUM_UpdateScroll, MYSTERY_ALBUM_RemoveCard, MYSTERY_ALBUM_SwapCards, MYSTERY_ALBUM_GetColumnCount, MYSTERY_ALBUM_CountValidCards, MYSTERY_ALBUM_SetupEntry, MYSTERY_ALBUM_ClearEntry, MYSTERY_ALBUM_IsEntryValid, MYSTERY_ALBUM_GetEntryBmp, MYSTERY_ALBUM_CreateEntryArc, MYSTERY_ALBUM_GetEntryPaletteResId, MYSTERY_ALBUM_GetEntryIconPalette, MYSTERY_ALBUM_GetEntryGraphicIndex, MYSTERY_ALBUM_GetEntryCellResId, MYSTERY_ALBUM_GetEntryCellAnimResId, MYSTERY_ALBUM_GetEntryKind, MYSTERY_ALBUM_GetEntryCard, MYSTERY_ALBUM_GetEntryEggFlag, MYSTERY_ALBUM_GetEntryIconX, MYSTERY_ALBUM_GetEntryIconY, MYSTERY_ALBUM_SelectHandler, MYSTERY_ALBUM_ConfirmHandler, MYSTERY_ALBUM_InfoHandler, MYSTERY_ALBUM_MoveHandler, MYSTERY_ALBUM_SaveHandler, MYSTERY_ALBUM_SingleHandler, MYSTERY_ALBUM_SetupIconSprite, MYSTERY_ALBUM_UpdateIconSprite, MYSTERY_ALBUM_CreateSlotWork, MYSTERY_ALBUM_DeleteSlotWork, MYSTERY_ALBUM_UpdateSlotWork, MYSTERY_ALBUM_CreateAlbumView, MYSTERY_ALBUM_Delete, MYSTERY_ALBUM_StepIntro, MYSTERY_ALBUM_SetBlendMain, MYSTERY_ALBUM_SetBlendSub, MYSTERY_ALBUM_LoadBgWithTilemap, MYSTERY_ALBUM_LoadBgPalette, MYSTERY_ALBUM_SetupIcons, MYSTERY_ALBUM_StartIntro, MYSTERY_ALBUM_ResetIntro, MYSTERY_ALBUM_IsIntroIdle, MYSTERY_ALBUM_SetupTask, MYSTERY_ALBUM_RequestSetup, MYSTERY_ALBUM_HideScreen, MYSTERY_ALBUM_PathAnimInit, MYSTERY_ALBUM_PathAnimStep
 * address:  0x021DAC18
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mystery_util.c, mystery_album.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   BMP_Create 0x02043678 arm
 *   BMP_Delete 0x020437AC arm
 *   BMP_CopyPixels 0x02043814 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetRepeat 0x0203633C arm
 *   MIi_CpuClear32 0x02082A7C arm
 *   GFL_HEAP_GetHeapHeadChecked 0x0203084C arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
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
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   POKE_TOOL_GetIconPaletteArcId 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorFlip 0x0204B604 arm
 *   data_021DF86E 0x021DF86E data a1
 *   BG_SYS_FreeTiles 0x02040DA8 arm
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
 *   POKE_TOOL_GetIconCellArcId 0x0201BC40 thumb
 *   POKE_TOOL_GetIconCellEntryId 0x0201BCB4 thumb
 *   d_021DF838 0x021DF838 data a4
 *   d_021DF848 0x021DF848 data a4
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   MYSTERY_ALBUM_StartIntro 0x021DDF5C thumb ov121
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   MYSTERY_DATA_HasAnyCard 0x0200A170 thumb
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   MYSTERY_ALBUM_IsIntroIdle 0x021DE014 thumb ov121
 *   MYSTERY_DATA_HasCardSpace 0x0200A0C8 thumb
 *   MYSTERY_DATA_SaveStart 0x0200A2B8 thumb
 *   MYSTERY_DATA_SaveMain 0x0200A2D8 thumb
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
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
 *   WORDSET_SetSlotMonth 0x0201F230 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   GFL_USE_GetRandom 0x020056EC thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   MYSTATUS_GetId 0x02008530 thumb
 *   POKE_TOOL_Create 0x020173F0 thumb
 *   POKE_TOOL_CreatePersonalRnd 0x020186C8 thumb
 *   POKE_TOOL_SetupPartyParamEx 0x02017588 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_SetDefaultMoves 0x02017FA8 thumb
 *   POKE_TOOL_AddMove 0x0201808C thumb
 *   POKE_TOOL_PushMove 0x020180F4 thumb
 *   POKE_TOOL_SetAbility 0x02018A00 thumb
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   MYSTATUS_GetName 0x020084F4 thumb
 *   MYSTATUS_GetSex 0x02008550 thumb
 *   POKE_TOOL_CastToBoxParam 0x020185F0 thumb
 *   SAVE_EVENT_WriteWithDate 0x0202F2AC thumb
 *   POKE_TOOL_RecalcParam 0x020185C4 thumb
 *   POKEGRA_GetArcID 0x0202D060 thumb
 *   POKE_TOOL_IsShiny 0x02017EAC thumb
 *   POKEGRA_GetPalArcIndex 0x0202D0D4 thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   POKEGRA_LoadCharDataPP 0x0202D6F4 thumb
 *   d_021DFA14 0x021DFA14 data a4
 *   d_021DF8C0 0x021DF8C0 data a4
 *   g0209DF08 0x0209DF08 data a1
 *   g0209DF0C 0x0209DF0C data a1
 *   gSpeciesNameBank 0x020A7370 data
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb  arm9
 *   PRINTSYS_Print  0x0201C7A4  thumb  arm9
 *   BMP_MENUWORK_AddMsgItem  0x0201F878  thumb  arm9
 *   TCB_DeleteTask 0x02030EAC arm
 *   MYSTERY_UTIL_DeleteBmpList 0x021DA3C0 thumb ov121
 *   MYSTERY_ALBUM_ClearEntry 0x021DBEE4 thumb ov121
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   MYSTERY_UTIL_BlendPaletteRange 0x021DAB50 thumb ov121
 *   PM_VOICE_Play 0x02006984 thumb
 *   CLACT_GetActorRotation 0x0204B5FC arm
 *   MYSTERY_ALBUM_PathAnimInit 0x021DE128 thumb ov121
 *   MYSTERY_ALBUM_PathAnimStep 0x021DE154 thumb ov121
 *   PM_VOICE_IsSlotActive 0x02006BD0 thumb
 *   MYSTERY_ALBUM_SetBlendMain 0x021DDC30 arm ov121
 *   MYSTERY_ALBUM_SetBlendSub 0x021DDC44 arm ov121
 *   MYSTERY_ALBUM_GetEntryIconY 0x021DC064 thumb ov121
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   MYSTERY_ALBUM_CreateEntryArc 0x021DBF10 thumb ov121
 *   MYSTERY_ALBUM_GetEntryPaletteResId 0x021DBF40 thumb ov121
 *   MYSTERY_ALBUM_GetEntryGraphicIndex 0x021DBF9C thumb ov121
 *   MYSTERY_ALBUM_GetEntryIconPalette 0x021DBF70 thumb ov121
 *   MYSTERY_ALBUM_GetEntryKind 0x021DC024 thumb ov121
 *   ARC_UTIL_LoadScreenDataFromHandle 0x02049E74 arm
 *   CLACT_TransferCharacterPart 0x0204AA94 arm
 *   CLACT_TransferPalette 0x0204ADEC arm
 *   MIi_CpuClear16 0x02082A48 arm
 *   CLACT_SetActorRotation 0x0204B5F4 arm
 *   CLACT_GetPaletteVramAddress 0x0204AEF4 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   MYSTERY_UTIL_CopyBmpList 0x021DA4A8 thumb ov121
 *   MYSTERY_UTIL_TransferWindowList 0x021DA318 thumb ov121
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   MYSTERY_ALBUM_PathFrameIds 0x021DF858 data a2
 *   MYSTERY_ALBUM_PathDirections 0x021DF822 data a1
 *   MYSTERY_ALBUM_PathDurations 0x021DF82D data a1
 *   MYSTERY_ALBUM_PathWaypoints 0x021DF944 data a4
 *   MYSTERY_UTIL_CreateWindow 0x021D99A4 thumb ov121
 *   MYSTERY_UTIL_DeleteWindow 0x021D9A40 thumb ov121
 *   MYSTERY_UTIL_ShowString 0x021D9AC8 thumb ov121
 *   MYSTERY_UTIL_SetColor 0x021D9B28 thumb ov121
 *   MYSTERY_UTIL_SetPosition 0x021D9B2C thumb ov121
 *   MYSTERY_UTIL_IsMessageDone 0x021D9B34 thumb ov121
 *   MYSTERY_UTIL_CreateMenuWindow 0x021D9CA4 thumb ov121
 *   MYSTERY_UTIL_CreateMenuWindow2 0x021D9D4C thumb ov121
 *   MYSTERY_UTIL_DeleteMenuWindow 0x021D9E04 thumb ov121
 *   MYSTERY_UTIL_UpdateMenuWindow 0x021D9E50 thumb ov121
 *   MYSTERY_UTIL_SetMenuMessage 0x021D9F08 thumb ov121
 *   MYSTERY_UTIL_GetMenuState 0x021D9FF8 thumb ov121
 *   MYSTERY_UTIL_DrawMenuWindow 0x021D9FFC thumb ov121
 *   MYSTERY_UTIL_CreateMenu 0x021DA038 thumb ov121
 *   MYSTERY_UTIL_DeleteMenu 0x021DA148 thumb ov121
 *   MYSTERY_UTIL_UpdateMenu 0x021DA178 thumb ov121
 *   MYSTERY_UTIL_CreateWindowList 0x021DA1BC thumb ov121
 *   MYSTERY_UTIL_DeleteWindowList 0x021DA280 thumb ov121
 *   MYSTERY_UTIL_ClearWindowList 0x021DA2A8 thumb ov121
 *   MYSTERY_UTIL_IsWindowListDone 0x021DA2C8 thumb ov121
 *   MYSTERY_UTIL_ClearListWindow 0x021DA2F0 thumb ov121
 *   MYSTERY_UTIL_CreateBmpList 0x021DA338 thumb ov121
 *   MYSTERY_UTIL_DrawBmpList 0x021DA3EC thumb ov121
 *   MYSTERY_UTIL_CreateTask 0x021DA854 thumb ov121
 *   MYSTERY_UTIL_DeleteTask 0x021DA890 thumb ov121
 *   MYSTERY_UTIL_DispatchTask 0x021DA898 thumb ov121
 *   MYSTERY_UTIL_IsTaskDone 0x021DA8AC thumb ov121
 *   MYSTERY_UTIL_SetTaskHandler 0x021DA8B0 thumb ov121
 *   MYSTERY_UTIL_MarkTaskDone 0x021DA8B8 thumb ov121
 *   PRINTSYS_MeasureWidestLine  0x0201D304  thumb  arm9
 *   PRINTSYS_CountLines  0x0201D42C  thumb  arm9
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "mystery_net_types.h"
#include "../version.h"

/* French, Italian and German print the month as a word; the others print its number. */
#if PM_LANG_MONTH_AS_NAME
#define MYSTERY_ALBUM_SET_MONTH(words, slot, month) WORDSET_SetSlotMonth(words, slot, month)
#else
#define MYSTERY_ALBUM_SET_MONTH(words, slot, month) WORDSET_SetSlotNumber(words, slot, month, 2, 0, 1)
#endif
#include "../arm9/item.h"
#include "../arm9/move.h"
#include "../sdk_ioreg.h"
#include "mystery_album_types.h"
#include "mystery_util_shared_types.h"

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
    unsigned char pad5D[0x4F];
    unsigned int flags;        /* 0xAC card flags read by MYSTERY_ALBUM_SetupEntry */
    unsigned char padB0[3];
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
    unsigned int reserved04;            /* 0x04 */
    void *clactUnit;                /* 0x08 */
    struct MysteryData *cardList;   /* 0x0C MYSTERY_DATA card list */
    struct GfFont *font;            /* 0x10 */
    struct PrintQueue *printQueue;  /* 0x14 */
    struct WordSet *wordSet;        /* 0x18 */
    struct MsgBank *msgBank;        /* 0x1C */
    struct GameData *gameData;      /* 0x20 */
    unsigned short heapId;          /* 0x24 */
    unsigned char pad26[2];
    MysteryAlbumEntry items[12];    /* 0x28 one per card slot */
    int refreshFlag;                /* 0xA78 */
    void *slots[12];                /* 0xA7C selected album handles */
    void *selectedAlbum;            /* 0xAAC */
    struct MysteryAlbumSlotWork *menuWork; /* 0xAB0 */
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
    unsigned int fadeTimer;         /* 0xAE8 */
    void *actorA;                   /* 0xAEC */
    void *actorB;                   /* 0xAF0 */
    union {
        struct {
            void *actorC;           /* 0xAF4 */
            void *actorD;           /* 0xAF8 */
        };
        void *actorCD[2];
    };
    int charHandle;                 /* 0xAFC */
    int cellAnimHandle;             /* 0xB00 */
    int paletteHandle;              /* 0xB04 */
    void *windows[8];               /* 0xB08 BMP_WIN handles */
    void *actors[8];                /* 0xB28 CLACT actors */
    unsigned int charHandles[8];    /* 0xB48 CLACT character handles */
    unsigned int cellAnimHandles[8];/* 0xB68 CLACT cell-anim handles */
    unsigned int paletteHandles[8]; /* 0xB88 CLACT palette handles */
    int bgPaletteHandle;            /* 0xBA8 */
    unsigned short angle;           /* 0xBAC */
    MysteryUtilBlendPalettes icons[2]; /* 0xBAE icon sprite palettes */
    unsigned char padC6E[2];
} MysteryAlbumWork;

/*
 * ARC resource header filled by ARC_UTIL_LoadPaletteBlockFromHandle; the loaded data pointer sits at
 * 0x0C. mystery_album.c reads the same header at +0x0C and +0x14, so the real
 * header is larger than this view.
 */
typedef struct MysteryUtilResData {
    unsigned char pad00[12];
    char *data;             /* 0x0C */
} MysteryUtilResData;




struct ClactActor;

struct ClactVec2;

struct Sub0200852CObj;


/* Raw 0xCC Mystery Gift card record (MYSTERY_DATA_GetCard, MYSTERY_ALBUM_SetupEntry). */
/* 48-byte album slot create descriptor (MYSTERY_ALBUM_CreateSlotWork). */

/* 8-byte album slot coordinate (data_021DF86E); h/s are the tile pair, b the byte view. */
typedef union MysteryAlbumSlotCoord { u16 h[4]; s16 s[4]; u8 b[8]; struct { u8 x, y, pad[6]; } c; } MysteryAlbumSlotCoord;

typedef struct { u8 b[16]; } MysteryAlbumScratch;

/* Bit view of the card flag byte at 0xB8 of a MysteryAlbumEntry. */
typedef struct { u8 low:1; u8 flag:1; u8 rest:6; } MysteryAlbumCardFlagBits;

/* 120-byte table of five MysteryUtilMenuEntry descriptors (d_021DF99C). */
/* 120-byte table of five MysteryUtilMenuEntry descriptors (d_021DF99C, d_021DFA14). */
typedef struct { MysteryUtilMenuEntry e[5]; } MysteryUtilMenuEntryTable;

/*
 * Slot work for the album card row (mystery_album.c original, allocated 0xD0
 * bytes by MYSTERY_ALBUM_CreateSlotWork). It owns the window list, the two
 * CLACT registrations and the input descriptor copied at 0xA0.
 */
typedef struct MysteryAlbumSlotWork {
    void *windowList;           /* 0x00 MYSTERY_UTIL_CreateWindowList */
    unsigned int palette;       /* 0x04 CLACT palette handle */
    unsigned int character;     /* 0x08 CLACT character handle */
    unsigned int cellAnim;      /* 0x0C CLACT cell anim handle */
    unsigned int pokePalette;   /* 0x10 POKEGRA palette handle */
    unsigned int pokeCharacter; /* 0x14 POKEGRA character handle */
    unsigned int pokeCellAnim;  /* 0x18 POKEGRA cell anim handle */
    void *actorA;               /* 0x1C first CLACT actor */
    void *actorB;               /* 0x20 second CLACT actor */
    unsigned char pad24[0x60];  /* 0x24 palette arrays (MysteryAlbumUi palFade/palBlack/palImage) */
    unsigned int isMainScreen;  /* 0x84 create kind below 4; MysteryAlbumUi.isMainScreen */
    unsigned int paletteBank;   /* 0x88 input w[5]; MysteryAlbumUi.paletteBank */
    unsigned int idleAnimId;    /* 0x8C input w[0] & 3; MysteryAlbumUi.idleAnimId */
    unsigned int introAnimId;   /* 0x90 input w[1] & 3; MysteryAlbumUi.introAnimId */
    unsigned short frontPlane;  /* 0x94 input w[0]; MysteryAlbumUi.frontPlane */
    unsigned short backPlane;   /* 0x96 input w[1]; MysteryAlbumUi.backPlane */
    unsigned int screenId;      /* 0x98 0 or 1; MysteryAlbumUi.screenId */
    unsigned int pokeBank;      /* 0x9C 0 or 4, written here, read by no function */
    MysteryAlbumDesc desc;         /* 0xA0 copy of the create input */
} MysteryAlbumSlotWork;

/* 24-byte raw menu entry as used by the album view descriptor (d_021DFA14). */
struct MysteryAlbumViewCard {
    u32 otIdOrItem;
    u32 originGame;
    u32 personality;
    u16 ribbonFlags;
    u16 ball;
    u16 heldItem;
    u16 mv[4];
    u16 species;
    u8 form;
    u8 language;
    u16 nickname;
    u8 pad20[0x14];
    u8 nature;
    u8 gender;
    u8 abilityMode;
    u8 shinyMode;
    u16 eggLocation;
    u16 metLocation;
    u8 metLevel;
    u8 contestCool;
    u8 contestBeauty;
    u8 contestCute;
    u8 contestSmart;
    u8 contestTough;
    u8 pad42;
    u8 iv0, iv1, iv2, iv6, iv7, iv3;
    u8 pad49;
    u16 otName;
    u8 pad4C[0xE];
    u8 otGender;
    u8 level;
    u8 isEgg;
    u8 pad5D[0x4F];
    u32 eventDate;
    u8 padB0[2];
    u8 messageIndex;
    u8 giftType;
    u8 reservedB4:1;
    u8 altMessageSet:1;
};


struct MysteryAlbumView {
    u8 pad0[0xE0];
    u32 isEgg;
    u16 species;
    u16 form;
    u8 padE8[0x118 - 0xE8];
    u16 heap;
    u8 pad11A[2];
    MysteryAlbumSlotWork *slotWork;
    struct MysteryAlbumViewCard *card;
    void *gameData;
    u8 pad128[0xC];
    void *pokeCharData;
    NNSG2dCharacterData *pokeCharBuf;
    void *pokePalette;
    void *pokePaletteData;
    void *bmpList;
};

int MYSTERY_ALBUM_PathAnimStep(MysteryAlbumPathAnim *anim, u16 *outFrameId, MysteryAlbumPathPoint *outPosition);
#include "../arm9/arc_util.h"
#ifdef __MWERKS__
#define BG_SYS_FillTileMap BG_SYS_FillTileMap_hdr
#endif
#include "../arm9/bg_sys.h"
#ifdef __MWERKS__
#undef BG_SYS_FillTileMap
void BG_SYS_FillTileMap(u32,u32,u32,u8,u8,u8);
#endif
#include "../arm9/bmp_win.h"
#ifdef __MWERKS__
#define CLACT_SetActorBgPriority CLACT_SetActorBgPriority_hdr
#define CLACT_AddActorSurfacePos CLACT_AddActorSurfacePos_hdr
#endif
#include "../arm9/clact.h"
#ifdef __MWERKS__
#undef CLACT_SetActorBgPriority
#undef CLACT_AddActorSurfacePos
void CLACT_SetActorBgPriority(void *actor,u8 animId);
void CLACT_AddActorSurfacePos(void *p, const void *delta, u16 which);
#endif
#ifdef __MWERKS__
#define FILE_UTIL_Get FILE_UTIL_Get_hdr
#endif
#include "../arm9/file_util.h"
#ifdef __MWERKS__
#undef FILE_UTIL_Get
u32 FILE_UTIL_Get(u16,u32);
#endif
#include "../arm9/game_data.h"
#include "../arm9/gfl_use.h"
#include "../arm9/mystatus.h"
#include "../arm9/mystery_data.h"
#ifdef __MWERKS__
#define POKE_TOOL_Create POKE_TOOL_Create_hdr
#endif
#include "../arm9/poke_tool.h"
#ifdef __MWERKS__
#undef POKE_TOOL_Create
void *POKE_TOOL_Create(u16 species, u16 level, u32 otId, u32 otIdHigh, u32 heap);
#endif
#ifdef __MWERKS__
#define POKEGRA_OpenHandle POKEGRA_OpenHandle_hdr
#endif
#include "../arm9/pokegra.h"
#ifdef __MWERKS__
#undef POKEGRA_OpenHandle
int POKEGRA_OpenHandle(int heapId);
#endif
#include "../arm9/printsys.h"
#include "../arm9/save_event.h"
#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/mi_memory.h"



#include "../arm9/strbuf.h"



typedef short s16_p07;
#include "../arm9/bmp.h"












#include "../arm9/msgdata.h"





#include "../arm9/key.h"









void MYSTERY_ALBUM_RequestSetup(MysteryAlbum *album,u32 mode);

void MYSTERY_ALBUM_Delete(MysteryAlbum *album);


void MYSTERY_ALBUM_ResetIntro(MysteryAlbum *album);

void MYSTERY_ALBUM_HideScreen(MysteryAlbumUi *ui);

void MYSTERY_ALBUM_StepIntro(MysteryAlbum *album);

#include "../arm9/arc_tool.h"






#include "../arm9/bmp_menuwork.h"

#include "../arm9/poke_tool_ext.h"












#include "../arm9/wordset.h"














#include "../arm9/touchpanel.h"

void MYSTERY_ALBUM_StartIntro(MysteryAlbum *album);


#include "../arm9/g2.h"

int MYSTERY_ALBUM_IsIntroIdle(MysteryAlbum *album);





































#ifdef __MWERKS__
#define MYSTERY_UTIL_CreateWindowList MYSTERY_UTIL_CreateWindowList_hdr
#endif
#include "mystery_util.h"
#ifdef __MWERKS__
#undef MYSTERY_UTIL_CreateWindowList
void * MYSTERY_UTIL_CreateWindowList();
#endif
















struct MsgBank;














MysteryAlbumWork *MYSTERY_ALBUM_Create(const MysteryAlbumCreateInput *src,u16 heap);

void MYSTERY_ALBUM_DeleteWork(MysteryAlbumWork *obj);

void MYSTERY_ALBUM_Update(MysteryAlbumWork *obj);

void MYSTERY_ALBUM_UpdateWindows(MysteryAlbumWork *p);

int MYSTERY_ALBUM_GetWindowState(MysteryAlbumWork *p);

void MYSTERY_ALBUM_Setup(MysteryAlbumWork *p, u16 heap);

void MYSTERY_ALBUM_Cleanup(MysteryAlbumWork *p);

void MYSTERY_ALBUM_SetCursor(MysteryAlbumWork *p,int a,int b,int c,u16 heap);

void MYSTERY_ALBUM_DeleteSlotActors(MysteryAlbumWork *p,int a);

void MYSTERY_ALBUM_SetupSlot(MysteryAlbumWork *p, int a, int b, int c, u16 index, u16 heap);

void MYSTERY_ALBUM_DeleteSlotActor(MysteryAlbumWork *p,int a,u16 index);

void MYSTERY_ALBUM_StartScroll(MysteryAlbumWork *p,int a);

int MYSTERY_ALBUM_UpdateScroll(MysteryAlbumWork *p);

void MYSTERY_ALBUM_RemoveCard(MysteryAlbumWork *o, int idx);

void MYSTERY_ALBUM_SwapCards(MysteryAlbumWork *o, u32 a, u32 b);

int MYSTERY_ALBUM_GetColumnCount(MysteryAlbumWork *p);

u32 MYSTERY_ALBUM_CountValidCards(MysteryAlbumWork *p);

void MYSTERY_ALBUM_SetupEntry(MysteryAlbumEntry *out,const MysteryAlbumCard *src,const MysteryAlbumCreateInput *p,u16 heap);

extern void MYSTERY_ALBUM_ClearEntry(MysteryAlbumEntry *p);

int MYSTERY_ALBUM_IsEntryValid(MysteryAlbumEntry *p);

void *MYSTERY_ALBUM_GetEntryBmp(void *p);

extern void *MYSTERY_ALBUM_CreateEntryArc(void *p,u16 heap);

extern u32 MYSTERY_ALBUM_GetEntryPaletteResId(void *p);

extern u32 MYSTERY_ALBUM_GetEntryIconPalette(void *p);

extern int MYSTERY_ALBUM_GetEntryGraphicIndex(void *p);

int MYSTERY_ALBUM_GetEntryCellResId(void *p);

int MYSTERY_ALBUM_GetEntryCellAnimResId(void *p);

extern int MYSTERY_ALBUM_GetEntryKind(void *p);

char *MYSTERY_ALBUM_GetEntryCard(void *p);

int MYSTERY_ALBUM_GetEntryEggFlag(MysteryAlbumEntry *p);

int MYSTERY_ALBUM_GetEntryIconX(void *p);

extern int MYSTERY_ALBUM_GetEntryIconY(void *p);

void MYSTERY_ALBUM_SelectHandler(void *task, int *state, void *pArg);

void MYSTERY_ALBUM_ConfirmHandler(void *task, int *state, void *pArg);

void MYSTERY_ALBUM_InfoHandler(void *task, int *state, void *pArg);

void MYSTERY_ALBUM_MoveHandler(void *task, int *state, void *pArg);

void MYSTERY_ALBUM_SaveHandler(void *arg, int *state, void *pArg);

void MYSTERY_ALBUM_SingleHandler(void *arg,int *state,MysteryAlbumWork *p);

void MYSTERY_ALBUM_SetupIconSprite(MysteryUtilBlendPalettes *p,void *arc,int id,int index,u8 other,u16 heap);

void MYSTERY_ALBUM_UpdateIconSprite(MysteryUtilBlendPalettes *p,int b,int c,u16 d);

void *MYSTERY_ALBUM_CreateSlotWork(const MysteryAlbumDesc *p,u16 heap);

void MYSTERY_ALBUM_DeleteSlotWork(MysteryAlbumSlotWork *p);

int MYSTERY_ALBUM_UpdateSlotWork(MysteryAlbumSlotWork *p);

struct MysteryAlbumView *MYSTERY_ALBUM_CreateAlbumView(MysteryAlbumCard *card, MysteryAlbumSlotWork *slotWork, void *gameData, u16 heap);

extern char d_021DFBB0[],d_021DF8FC[],d_021DF890[];

extern const MysteryAlbumSlotCoord data_021DF86E[];

extern const u8 d_021DF86E[];

extern const u8 d_021DF86F[];

extern const int d_021DF838[];

extern const int d_021DF848[];

extern char d_021DFBB0[];

extern const MysteryUtilMenuEntryTable d_021DF99C;

extern const MysteryUtilMenuEntryTable d_021DFA14;

extern const u32 d_021DF8C0[];

extern u8 g0209DF08;

extern u8 g0209DF0C;

extern void *gSpeciesNameBank;

MysteryAlbumWork *MYSTERY_ALBUM_Create(const MysteryAlbumCreateInput *src,u16 heap)
{
    MysteryAlbumWork *out;
    int count=0;
    u32 i;
    int j;
    MysteryAlbumDesc d;
    MysteryAlbumCard record;
    const char *table;
    int n;
    void *callback;
    out=GFL_HEAP_Alloc(heap,sizeof(*out),0,d_021DFBB0,0x19f);
    MI_CpuFill8(out,0,sizeof(*out));
    out->flipFlag=1;
    *(MysteryAlbumCreateInput *)out=*src;
    out->heapId=heap;
    MIi_CpuClear32(-1,out->charHandles,32);
    MIi_CpuClear32(-1,out->paletteHandles,32);
    MIi_CpuClear32(-1,out->cellAnimHandles,32);
    for(i=0;i<MYSTERY_DATA_GetCardSlotNum(out->cardList);i++) {
        if(MYSTERY_DATA_IsCardExist(out->cardList,i)) {
            count++;
            MYSTERY_DATA_GetCard(out->cardList,i,&record);
            MYSTERY_ALBUM_SetupEntry(&out->items[i],(const MysteryAlbumCard *)&record,(const MysteryAlbumCreateInput *)out,heap);
        }
    }
    callback=(void *)MYSTERY_ALBUM_SelectHandler;
    if(out->mode) callback=(void *)MYSTERY_ALBUM_SingleHandler;
    out->task=MYSTERY_UTIL_CreateTask(out,callback,heap);
    MYSTERY_ALBUM_Setup(out,heap);
    MYSTERY_ALBUM_SetCursor(out,1,0,out->cursorIndex,heap);
    if(count) {table=d_021DF8FC;n=3;}
    else {table=d_021DF890;n=2;}
    /* stand-in: unprototyped call; the prototype's u16/u8 parameters narrow the arguments and change the bytes */
    out->windowList=MYSTERY_UTIL_CreateWindowList(0,table,n,1,3,out->printQueue,out->msgBank,out->font,heap);
    MI_CpuFill8(&d,0,sizeof(d));
    d.frontPlane=6;d.backPlane=4;d.reserved08=14;d.windowPalette=15;d.charPalette=11;d.paletteBank=14;
    d.clactUnit=out->clactUnit;d.cardList=out->cardList;d.msgBank=out->msgBank;
    d.font=out->font;d.printQueue=out->printQueue;d.wordSet=out->wordSet;
    out->menuWork=MYSTERY_ALBUM_CreateSlotWork(&d,heap);
    if(MYSTERY_ALBUM_CountValidCards(out)) {
        for(j=0;j<12;j++) {
            if(MYSTERY_ALBUM_IsEntryValid(&out->items[j]))
                out->slots[j]=MYSTERY_ALBUM_CreateAlbumView((MysteryAlbumCard *)MYSTERY_ALBUM_GetEntryCard(&out->items[j]),out->menuWork,src->gameData,heap);
        }
        MYSTERY_ALBUM_RequestSetup(out->slots[0],0);
        GFL_HEAP_GetHeapHeadChecked(29);
    }
    BG_SYS_ChangeScrollImmediate(3,3,0);
    BG_SYS_ChangeScrollImmediate(7,3,0);
    return out;
}

/*
 * lever: The slot array at +0xa7c is the same layout as MYSTERY_ALBUM_RemoveCard;
 * its member access keeps the offset loaded before the loop index.
 */
void MYSTERY_ALBUM_DeleteWork(MysteryAlbumWork *obj)
{
    int i;
    u32 j;
    for(i=0;i<12;i++) {
        if(obj->slots[i]) {
            MYSTERY_ALBUM_Delete(obj->slots[i]);
            obj->slots[i]=0;
        }
    }
    MYSTERY_ALBUM_DeleteSlotWork(obj->menuWork);
    if(obj->menuWindow) {
        MYSTERY_UTIL_DeleteMenuWindow(obj->menuWindow);
        obj->menuWindow=0;
    }
    BG_SYS_ChangeScrollImmediate(3,0,0);
    BG_SYS_ChangeScrollImmediate(2,0,0);
    MYSTERY_UTIL_ClearWindowList(obj->windowList);
    MYSTERY_UTIL_DeleteWindowList(obj->windowList);
    MYSTERY_ALBUM_DeleteSlotActors(obj,1);
    MYSTERY_ALBUM_DeleteSlotActors(obj,0);
    MYSTERY_ALBUM_Cleanup(obj);
    for(j=0;j<MYSTERY_DATA_GetCardSlotNum(obj->cardList);j++)
        MYSTERY_ALBUM_ClearEntry(&obj->items[j]);
    BG_SYS_ClearSlot(4);
    BG_SYS_ClearSlot(6);
    BG_SYS_MarkTileDirty(4);
    BG_SYS_MarkTileDirty(6);
    MYSTERY_UTIL_DeleteTask(obj->task);
    GFL_HEAP_Free(obj);
}

void MYSTERY_ALBUM_Update(MysteryAlbumWork *obj)
{
    char *p=(char *)obj;
    int flag;
    u16 old;
    int angle;
    MYSTERY_UTIL_DispatchTask(((MysteryAlbumWork *)p)->task);
    MYSTERY_ALBUM_UpdateSlotWork(((MysteryAlbumWork *)p)->menuWork);
    if(((MysteryAlbumWork *)p)->refreshFlag) {
        flag=0;
        if(((MysteryAlbumWork *)p)->selectedAlbum) {
            MYSTERY_ALBUM_ResetIntro((MysteryAlbum *)((MysteryAlbumWork *)p)->selectedAlbum);
            ((MysteryAlbumWork *)p)->selectedAlbum=0;
        }
        if(*(volatile int *)&((MysteryAlbumWork *)p)->cursorMode<4 && MYSTERY_ALBUM_IsEntryValid((MysteryAlbumEntry *)(&((MysteryAlbumWork *)p)->items[*(volatile int *)&((MysteryAlbumWork *)p)->cursorMode+((MysteryAlbumWork *)p)->cursorIndex*4]))) {
            flag=1;
            MYSTERY_ALBUM_RequestSetup(((MysteryAlbumWork *)p)->slots[((MysteryAlbumWork *)p)->cursorMode+((MysteryAlbumWork *)p)->cursorIndex*4],1);
        }
        if(flag==0) MYSTERY_ALBUM_HideScreen((MysteryAlbumUi *)((MysteryAlbumWork *)p)->menuWork);
        ((MysteryAlbumWork *)p)->refreshFlag=0;
    }
    old=((MysteryAlbumWork *)p)->angle;
    angle=old+0x400;
    if(angle>=0x10000)
        ((MysteryAlbumWork *)p)->angle=old-0xfc00;
    else
        ((MysteryAlbumWork *)p)->angle=angle;
    MYSTERY_ALBUM_UpdateIconSprite(&((MysteryAlbumWork *)p)->icons[0],14,0,((MysteryAlbumWork *)p)->angle);
    MYSTERY_ALBUM_UpdateIconSprite(&((MysteryAlbumWork *)p)->icons[1],14,2,((MysteryAlbumWork *)p)->angle);
}

static inline void update(void *p)
{
    if(p) MYSTERY_ALBUM_StepIntro(p);
}

/*
 * extent: unit includes tail-call follower MYSTERY_ALBUM_GetWindowState (function-start seed).
 */
void MYSTERY_ALBUM_UpdateWindows(MysteryAlbumWork *p)
{
    int i;
    MYSTERY_UTIL_IsWindowListDone(p->windowList);
    if(p->infoWindow) MYSTERY_UTIL_IsMessageDone(p->infoWindow);
    for(i=0;i<12;i++) {
        void *q=p->slots[i];
        if(q) update(q);
    }
}

int MYSTERY_ALBUM_GetWindowState(MysteryAlbumWork *p)
{
    return MYSTERY_UTIL_IsTaskDone(p->task);
}

#pragma opt_dead_assignments off

/*
 * closed 2026-10-05 (recoup integrator): ARC_UTIL_UploadBgCharFromHandle returns u32 (its matched definition tail-returns ARC_UTIL_UploadBgChar); with the void declaration the later register zeros were copied from the pooled zero; with the real return type the
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
 *   adds it in each arm. A ternary for the x store and a real MysteryAlbumScratch struct were worse.
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
void MYSTERY_ALBUM_Setup(MysteryAlbumWork *p, u16 heap)
{
    MysteryAlbumScratch t;
    void *arc;
    int i, j;
    u32 k;
    arc = ARC_TOOL_CreateHandle(34, heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc, 1, 0, 0, 320, heap);
    ARC_UTIL_UploadBgCharFromHandle(arc, 10, 3, 0, 0, 0, heap);
    ARC_UTIL_UploadBgPaletteFromHandle(arc, 17, 3, 0, 0, 0, heap);
    ARC_UTIL_UploadBgCharFromHandle(arc, 10, 1, 0, 0, 0, heap);
    ARC_UTIL_UploadBgPaletteFromHandle(arc, 19, 1, 0, 0, 0, heap);
    BG_SYS_PushTile(3);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc, 1, 4, 0, 320, heap);
    ARC_UTIL_UploadBgCharFromHandle(arc, 10, 7, 0, 0, 0, heap);
    ARC_UTIL_UploadBgPaletteFromHandle(arc, 18, 7, 0, 0, 0, heap);
    ARC_TOOL_DeleteHandle(arc);
    arc = ARC_TOOL_CreateHandle(23, heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc, 5, 0, 480, 32, heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc, 5, 4, 480, 32, heap);
    ARC_TOOL_DeleteHandle(arc);
    BG_SYS_Init(1, 0, 1, 0);
    BG_SYS_Init(2, 0, 1, 0);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 13, 0, heap);
    arc = ARC_TOOL_CreateHandle(7, heap);
    p->bgPaletteHandle = CLACT_RegisterPaletteCompressed(arc, POKE_TOOL_GetIconPaletteArcId(), 0, 384, heap);
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
        p->windows[i] = BMP_WIN_Create(2, t.b[10], t.b[11], 10, 2, 15, 0);
        BMP_WIN_MakeScreen(p->windows[i]);
        BG_SYS_PushTile(2);
    }
    p->infoWindow = MYSTERY_UTIL_CreateWindow(0, 1, 13, 22, 6, 2, 3, p->printQueue, heap);
    arc = ARC_TOOL_CreateHandle(34, heap);
    p->paletteHandle = CLACT_RegisterPaletteEx(arc, 0, 0, 0, 0, 6, heap);
    p->cellAnimHandle = CLACT_RegisterCellAnim(arc, 32, 35, heap);
    p->charHandle = CLACT_RegisterCharacter(arc, 9, 0, 0, heap);
    MYSTERY_ALBUM_SetupIconSprite(&p->icons[0], arc, 0, 0, 1, heap);
    MYSTERY_ALBUM_SetupIconSprite(&p->icons[1], arc, 0, 2, 3, heap);
    ARC_TOOL_DeleteHandle(arc);
    MI_CpuFill8(&t, 0, 8);
    *(u16 *)(t.b) = 0;
    *(u16 *)(t.b + 2) = 24;
    t.b[7] = 1;
    t.b[6] = 1;
    {
        struct ClactActor *o = CLACT_CreateActor(p->clactUnit, p->charHandle, p->paletteHandle, p->cellAnimHandle, (const struct ActorInitParam *)&t, 0, heap);
        p->actorA = o;
        *(u16 *)(t.b + 4) = 2;
        o = CLACT_CreateActor(p->clactUnit, p->charHandle, p->paletteHandle, p->cellAnimHandle, (const struct ActorInitParam *)&t, 0, heap);
        p->actorB = o;
        CLACT_SetActorDrawEnable(o, 0);
    }
    t.b[6] = 0;
    k = 0;
    for (j = 0; j < 2; j++) {
        struct ClactActor *o;
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
        q = (u8 *)p + j * (int)sizeof(void *);
        o = CLACT_CreateActor(p->clactUnit, p->charHandle, p->paletteHandle, p->cellAnimHandle, (const struct ActorInitParam *)&t, k, heap);
        ((MysteryAlbumWork *)q)->actorCD[0] = o;
        CLACT_SetActorAutoAnim(((MysteryAlbumWork *)q)->actorCD[0], 1);
        CLACT_SetActorDrawEnable(((MysteryAlbumWork *)q)->actorCD[0], k);
        if (j == 0) CLACT_SetActorFlip(((MysteryAlbumWork *)q)->actorCD[0], 1, 1);
        else CLACT_SetActorFlip(((MysteryAlbumWork *)q)->actorCD[0], 1, 0);
    }
    BG_SYS_SetPlaneVisible(2, 1);
}

#pragma opt_dead_assignments reset

void MYSTERY_ALBUM_Cleanup(MysteryAlbumWork *p)
{
    int i;
    BG_SYS_FreeTiles(2,1,0);
    BG_SYS_FreeTiles(1,1,0);
    for(i=0;i<2;i++) CLACT_DeleteActor(p->actorCD[i]);
    CLACT_DeleteActor(p->actorB);
    CLACT_DeleteActor(p->actorA);
    CLACT_ReleaseCharacter(p->charHandle);
    CLACT_ReleaseCellAnim(p->cellAnimHandle);
    CLACT_ReleasePalette(p->paletteHandle);
    MYSTERY_UTIL_DeleteWindow(p->infoWindow);
    p->infoWindow=0;
    CLACT_ReleasePalette(p->bgPaletteHandle);
    for(i=0;i<8;i++) BMP_WIN_Delete(p->windows[i]);
}

void MYSTERY_ALBUM_SetCursor(MysteryAlbumWork *p,int a,int b,int c,u16 heap)
{
    int i;
    void *text,*other;
    for(i=0;i<4;i++) MYSTERY_ALBUM_SetupSlot(p,a,b,c,(u16)i,heap);
    text=STRBUF_Create(128,heap);
    other=MSGDATA_AllocString((void *)p->msgBank,150);
    WORDSET_SetSlotNumber(p->wordSet,0,c+1,1,1,1);
    WORDSET_SetSlotNumber(p->wordSet,1,MYSTERY_ALBUM_GetColumnCount(p),1,1,1);
    WORDSET_CopyTaggedText(p->wordSet,text,other);
    MYSTERY_UTIL_SetColor(p->infoWindow,0x39ea);
    MYSTERY_UTIL_SetPosition(p->infoWindow,0,0,1);
    MYSTERY_UTIL_ShowString(p->infoWindow,text,p->font);
    STRBUF_Delete(text);
    STRBUF_Delete(other);
    BG_SYS_PushTile(3);
}

void MYSTERY_ALBUM_DeleteSlotActors(MysteryAlbumWork *p,int a) { int i; for(i=0;i<4;i++) MYSTERY_ALBUM_DeleteSlotActor(p,a,i); BG_SYS_PushTile(3); }

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
void MYSTERY_ALBUM_SetupSlot(MysteryAlbumWork *p, int a, int b, int c, u16 index, u16 heap)
{
    void *obj;
    int off;
    char *tab;
    int idx;
    int y, y2, y3;
    int m;
    const MysteryAlbumSlotCoord *src;
    int k, ry;
    int x, rx, yy, tile, tile2, tile3;
    s16 dx, dy;
    void *dsc;
    MysteryAlbumSlotCoord r;
    struct ActorInitParam pos;
    MysteryUtilVec2 cur;
    k = index + c * 4;
    tab = (char *)p->items;
    off = k * (int)sizeof(MysteryAlbumEntry);
    idx = index;
    src = (const MysteryAlbumSlotCoord *)d_021DF86E + index;
    r = *src;
    if ((a && p->flipFlag == 0) || (a == 0 && p->flipFlag)) {
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
    if (MYSTERY_ALBUM_IsEntryValid((MysteryAlbumEntry *)(tab + off)) == 0) {
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
        BMP_Clear(BMP_WIN_GetBmp((*(void * *)((char *)p->windows + idx * (int)sizeof(void *)))), 0);
        BMP_WIN_TransferChars((*(void * *)((char *)p->windows + idx * (int)sizeof(void *))));
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
    BMP_CopyPixels(dsc, BMP_WIN_GetBmp((*(void * *)((char *)p->windows + idx * (int)sizeof(void *)))));
    BMP_WIN_TransferChars((*(void * *)((char *)p->windows + idx * (int)sizeof(void *))));
    obj = MYSTERY_ALBUM_CreateEntryArc(tab + off, heap);
    if (MYSTERY_ALBUM_GetEntryKind(tab + off) != 1)
        (*(unsigned int *)((char *)p->paletteHandles + idx * (int)sizeof(unsigned int))) = CLACT_RegisterPaletteEx(obj, MYSTERY_ALBUM_GetEntryPaletteResId(tab + off), 0, (u16)((idx + 4) << 5), 0, 1, heap);
    (*(unsigned int *)((char *)p->cellAnimHandles + idx * (int)sizeof(unsigned int))) = CLACT_RegisterCellAnim(obj, MYSTERY_ALBUM_GetEntryCellResId(tab + off), MYSTERY_ALBUM_GetEntryCellAnimResId(tab + off), heap);
    (*(unsigned int *)((char *)p->charHandles + idx * (int)sizeof(unsigned int))) = CLACT_RegisterCharacter(obj, MYSTERY_ALBUM_GetEntryGraphicIndex(tab + off), 0, 0, heap);
    dx = 0;
    ARC_TOOL_DeleteHandle(obj);
    dy = 0;
    MI_CpuFill8(&pos, 0, 8);
    pos.y = r.s[3];
    pos.bg_priority = 1;
    if (MYSTERY_ALBUM_GetEntryKind(tab + off) == 2) {
        dx = 4;
        dy = 8;
    }
    if (a)
        pos.x = r.s[2];
    else if (b)
        pos.x = r.s[2] - 0x100;
    else if (b == 0)
        pos.x = r.s[2] + 0x100;
    else
        pos.x = r.s[2];
    pos.x += dx;
    pos.y += dy;
    (*(void * *)((char *)p->actors + idx * (int)sizeof(void *))) = CLACT_CreateActor(p->clactUnit, (*(unsigned int *)((char *)p->charHandles + idx * (int)sizeof(unsigned int))),
        MYSTERY_ALBUM_GetEntryKind(tab + off) == 1 ? p->bgPaletteHandle : (*(unsigned int *)((char *)p->paletteHandles + idx * (int)sizeof(unsigned int))),
        (*(unsigned int *)((char *)p->cellAnimHandles + idx * (int)sizeof(unsigned int))), &pos, 0, p->heapId);
    CLACT_SetActorPaletteOffset((*(void * *)((char *)p->actors + idx * (int)sizeof(void *))), (u8)MYSTERY_ALBUM_GetEntryIconPalette(tab + off), 0);
    CLACT_SetActorDrawEnable((*(void * *)((char *)p->actors + idx * (int)sizeof(void *))), 1);
    if (p->introActive && p->swapIndex == k) {
        cur.x = src->b[0] * 8 - 0x18;
        cur.y = d_021DF86F[index * 8] * 8 - 8;
        if (a == 0) {
            if (b)
                cur.x -= 0x100;
            else if (b == 0)
                cur.x += 0x100;
        }
        CLACT_AddActorSurfacePos(p->actorB, (const void *)(&cur), 0);
    }
}

#pragma opt_lifetimes reset

#pragma opt_loop_invariants reset

void MYSTERY_ALBUM_DeleteSlotActor(MysteryAlbumWork *p,int a,u16 index)
{
    MysteryAlbumSlotCoord rect;
    int y,x,tile;
    int yy;
    rect=*(const MysteryAlbumSlotCoord *)((const MysteryAlbumSlotCoord *)d_021DF86E + index);
    if((a && p->flipFlag==0) || (a==0 && p->flipFlag)) {
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
    BMP_Clear(BMP_WIN_GetBmp(p->windows[index]),0);
    BMP_WIN_TransferChars(p->windows[index]);
    if(p->actors[index]) {
        CLACT_DeleteActor((struct ClactActor *)(p->actors[index]));
        p->actors[index]=0;
        if(p->paletteHandles[index]!=-1) {
            CLACT_ReleasePalette(p->paletteHandles[index]);
            p->paletteHandles[index]=-1;
        }
        if(p->charHandles[index]!=-1) {
            CLACT_ReleaseCharacter(p->charHandles[index]);
            p->charHandles[index]=-1;
        }
        if(p->cellAnimHandles[index]!=-1) {
            CLACT_ReleaseCellAnim(p->cellAnimHandles[index]);
            p->cellAnimHandles[index]=-1;
        }
    }
}

void MYSTERY_ALBUM_StartScroll(MysteryAlbumWork *p,int a) { int v; if(a) v=-1; else v=1; p->scrollDir=v; p->scrollTimer=0; }

int MYSTERY_ALBUM_UpdateScroll(MysteryAlbumWork *p)
{
    int amount,i;
    s16 xy[4];
    if(p->scrollDir==0) goto idle;
    amount=(p->scrollDir*256)/16;
    for(i=0;i<8;i++) {
        if(p->actors[i]) {
            CLACT_GetActorSurfacePos(p->actors[i],(struct ClactVec2 *)(xy+2),0);
            xy[2]-=(s16)amount;
            CLACT_AddActorSurfacePos((struct ClactActor *)(p->actors[i]), (const struct ClactVec2 *)(xy+2), 0);
            CLACT_GetActorSurfacePos(p->actors[i],(struct ClactVec2 *)xy,0);
            if(xy[0]>=-16 && xy[0]<=272 && xy[1]>=-16 && xy[1]<=208)
                CLACT_SetActorDrawEnable((struct ClactActor *)(p->actors[i]), 1);
            else CLACT_SetActorDrawEnable((struct ClactActor *)(p->actors[i]), 0);
        }
    }
    if(p->introActive) {
        CLACT_GetActorSurfacePos(p->actorB,(struct ClactVec2 *)(xy+2),0);
        xy[2]-=(s16)amount;
        CLACT_AddActorSurfacePos((struct ClactActor *)(p->actorB), (const struct ClactVec2 *)(xy+2), 0);
        if(xy[2]>=-96 && xy[2]<=352 && xy[3]>=-96 && xy[3]<=288)
            CLACT_SetActorDrawEnable((struct ClactActor *)(p->actorB), 1);
        else CLACT_SetActorDrawEnable((struct ClactActor *)(p->actorB), 0);
    }
    BG_SYS_ChangeScrollImmediate(3,1,amount);
    BG_SYS_ChangeScrollImmediate(2,1,amount);
    if((p->scrollTimer)++>=15) {
        p->flipFlag^=1;
        p->scrollDir=0;
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
        MYSTERY_ALBUM_ClearEntry(&o->items[i]);
    for (i = 0; i < MYSTERY_DATA_GetCardSlotNum(o->cardList); i++) {
        if (MYSTERY_DATA_IsCardExist(o->cardList, i)) {
            MYSTERY_DATA_GetCard(o->cardList, i, buf);
            MYSTERY_ALBUM_SetupEntry(&o->items[i], (const MysteryAlbumCard *)buf, (const MysteryAlbumCreateInput *)o, o->heapId);
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
        MYSTERY_ALBUM_ClearEntry(&o->items[i]);
    for (i = 0; i < MYSTERY_DATA_GetCardSlotNum(o->cardList); i++) {
        if (MYSTERY_DATA_IsCardExist(o->cardList, i)) {
            MYSTERY_DATA_GetCard(o->cardList, i, buf);
            MYSTERY_ALBUM_SetupEntry(&o->items[i], (const MysteryAlbumCard *)buf, (const MysteryAlbumCreateInput *)o, o->heapId);
        }
    }
    MYSTERY_ALBUM_Delete(o->slots[a]);
    MYSTERY_ALBUM_Delete(o->slots[b]);
    o->slots[a] = MYSTERY_ALBUM_CreateAlbumView((MysteryAlbumCard *)MYSTERY_ALBUM_GetEntryCard(&o->items[a]), o->menuWork, o->gameData, o->heapId);
    o->slots[b] = MYSTERY_ALBUM_CreateAlbumView((MysteryAlbumCard *)MYSTERY_ALBUM_GetEntryCard(&o->items[b]), o->menuWork, o->gameData, o->heapId);
    o->dirty = 1;
}

int MYSTERY_ALBUM_GetColumnCount(MysteryAlbumWork *p) { return 3; }

/*
 * lever: Declare the index before the count, but initialise count first; this places index in r4 and count in r5.
 * prototype: MYSTERY_DATA_GetCardSlotNum returns the value used by the bound. Its forwarding target 0200A400 reads only r0, so legacy trailing arguments are omitted.
 */
u32 MYSTERY_ALBUM_CountValidCards(MysteryAlbumWork *p) { u32 i; u32 count=0; for (i=0;i<MYSTERY_DATA_GetCardSlotNum(p->cardList);i++) { if (MYSTERY_ALBUM_IsEntryValid(&p->items[i])) count++; } return count; }

void MYSTERY_ALBUM_SetupEntry(MysteryAlbumEntry *out,const MysteryAlbumCard *src,const MysteryAlbumCreateInput *p,u16 heap)
{
    int flags;
    void *text,*other;
    s16 x,y;
    MI_CpuFill8(out,0,sizeof(*out));
    if(src) {
        out->valid=1;
        out->card=*src;
        out->bmp=BMP_Create(10,2,32,heap);
        flags=src->flags;
        text=STRBUF_Create(128,heap);
        other=MSGDATA_AllocString(p->msgBank,151);
        WORDSET_SetSlotNumber(p->wordSet,0,(u16)(flags>>16),4,1,1);
        MYSTERY_ALBUM_SET_MONTH(p->wordSet,1,(u8)(flags>>8));
        WORDSET_SetSlotNumber(p->wordSet,2,(u8)flags,2,0,1);
        WORDSET_CopyTaggedText(p->wordSet,text,other);
        x=40;
        x-=(s16)(PRINTSYS_MeasureWidestLine(text,p->font,0)/2);
        y=8-(s16)(PRINTSYS_CountLines(text,p->font)/2);
        PRINTSYS_Print(out->bmp,x,y,text,p->font);
        STRBUF_Delete(text);
        STRBUF_Delete(other);
    }
}

void MYSTERY_ALBUM_ClearEntry(MysteryAlbumEntry *p) { if (p->valid) { BMP_Delete(p->bmp); MI_CpuFill8(p,0,sizeof(*p)); } }

int MYSTERY_ALBUM_IsEntryValid(MysteryAlbumEntry *p) { return p->valid; }

void *MYSTERY_ALBUM_GetEntryBmp(void *p) { return ((MysteryAlbumEntry *)p)->bmp; }

void *MYSTERY_ALBUM_CreateEntryArc(void *p,u16 heap) { switch(MYSTERY_ALBUM_GetEntryKind(p)) { case 1:return ARC_TOOL_CreateHandle(7,heap); case 2:return ARC_TOOL_CreateHandle(25,heap); default:return ARC_TOOL_CreateHandle(34,heap); } }

/*
 * prototype: FILE_UTIL_Get item is u16 here, matching caller truncation before the call.
 */
u32 MYSTERY_ALBUM_GetEntryPaletteResId(void *p) { switch(MYSTERY_ALBUM_GetEntryKind(p)) { case 1:return POKE_TOOL_GetIconPaletteArcId(); case 2:return FILE_UTIL_Get(*(u32 *)MYSTERY_ALBUM_GetEntryCard(p),2); default:return 3; } }

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

int MYSTERY_ALBUM_GetEntryCellResId(void *p) { switch(MYSTERY_ALBUM_GetEntryKind(p)) { case 1: return POKE_TOOL_GetIconCellArcId(); case 2: return 1; default:return 33; } }

int MYSTERY_ALBUM_GetEntryCellAnimResId(void *p) { switch(MYSTERY_ALBUM_GetEntryKind(p)) { case 1: return POKE_TOOL_GetIconCellEntryId(); case 2: return 0; default:return 36; } }

int MYSTERY_ALBUM_GetEntryKind(void *p) { return ((MysteryAlbumEntry *)p)->card.giftType; }

char *MYSTERY_ALBUM_GetEntryCard(void *p) { return (char *)p+4; }

int MYSTERY_ALBUM_GetEntryEggFlag(MysteryAlbumEntry *p) { return ((MysteryAlbumCardFlagBits *)((char *)p+184))->flag; }

int MYSTERY_ALBUM_GetEntryIconX(void *p) { int i,add; i=MYSTERY_ALBUM_GetEntryKind(p); add=MYSTERY_ALBUM_GetEntryEggFlag(p) ? 0 : 5; return add+d_021DF838[i]; }

int MYSTERY_ALBUM_GetEntryIconY(void *p) { int i,add; i=MYSTERY_ALBUM_GetEntryKind(p); add=MYSTERY_ALBUM_GetEntryEggFlag(p) ? 3 : 0; return add+d_021DF848[i]; }

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
void MYSTERY_ALBUM_SelectHandler(void *task, int *state, void *pArg)
{
    MysteryAlbumWork *p = pArg;
    u32 repeat;
    int delta,changed,count,next,direction;
    MysteryUtilVec2 pos;
    switch(*state) {
    case 0:
        CLACT_SetActorDrawEnable(p->actorC,1);
        CLACT_SetActorDrawEnable(p->actorD,1);
        CLACT_SetActorDrawEnable(p->actorA,1);
        repeat=KEY_GetRepeat();
        changed=0;delta=0;
        if(TOUCHPANEL_GetTrg()) {
            p->selectedAlbum=p->slots[(u16)(p->cursorMode+p->cursorIndex*4)];
            if(p->selectedAlbum) MYSTERY_ALBUM_StartIntro(p->selectedAlbum);
        }
        if(repeat==512) delta=-1;
        else if(repeat==256) delta=1;
        else if(repeat&64) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            switch(p->cursorMode) {
            case 0:
                if(p->introActive) p->cursorMode=2;
                else {p->introMode=1;p->cursorMode=4;}
                break;
            case 1:
                if(p->introActive) p->cursorMode=3;
                else {p->introMode=0;p->cursorMode=4;}
                break;
            case 2: p->cursorMode=0;break;
            case 3: p->cursorMode=1;break;
            case 4:
                if(p->introMode) p->cursorMode=2;
                else p->cursorMode=3;
                break;
            }
            changed=1;
        } else if(repeat&128) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            switch(p->cursorMode) {
            case 0: p->cursorMode=2;break;
            case 1: p->cursorMode=3;break;
            case 2:
                if(p->introActive) p->cursorMode=0;
                else {p->introMode=1;p->cursorMode=4;}
                break;
            case 3:
                if(p->introActive) p->cursorMode=1;
                else {p->introMode=0;p->cursorMode=4;}
                break;
            case 4:
                if(p->introMode) p->cursorMode=0;
                else p->cursorMode=1;
                break;
            }
            changed=1;
        } else if(repeat&32) {
            MYSTERY_ALBUM_GetColumnCount(p);
            if(p->cursorMode==0 || p->cursorMode==2) delta=-1;
            else if(p->cursorMode!=4) GFL_USE_PlaySeDefaultVolume(0x548);
            if(p->cursorMode!=4) {
                if(p->cursorMode<=1) {
                    --p->cursorMode;
                    p->cursorMode=wrap(p->cursorMode,0,1);
                } else {
                    --p->cursorMode;
                    p->cursorMode=wrap(p->cursorMode,2,3);
                }
                changed=1;
            }
        } else if(repeat&16) {
            MYSTERY_ALBUM_GetColumnCount(p);
            if(p->cursorMode==1 || p->cursorMode==3) delta=1;
            else if(p->cursorMode!=4) GFL_USE_PlaySeDefaultVolume(0x548);
            if(p->cursorMode!=4) {
                if(p->cursorMode<=1) {
                    ++p->cursorMode;
                    p->cursorMode=wrap(p->cursorMode,0,1);
                } else {
                    ++p->cursorMode;
                    p->cursorMode=wrap(p->cursorMode,2,3);
                }
                changed=1;
            }
        } else if(KEY_GetTrg()&1) {
            if(p->cursorMode==4) {
                if(p->introActive==0) {
                    CLACT_SetActorDrawEnable(p->actorC,0);
                    CLACT_SetActorDrawEnable(p->actorD,0);
                    GFL_USE_PlaySeDefaultVolume(0x54c);
                    MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_ALBUM_SaveHandler);
                }
            } else if(MYSTERY_ALBUM_IsEntryValid(&p->items[(u32)*(int *)&p->cursorMode+p->cursorIndex*4])) {
                CLACT_SetActorDrawEnable(p->actorC,0);
                CLACT_SetActorDrawEnable(p->actorD,0);
                GFL_USE_PlaySeDefaultVolume(0x54c);
                if(p->introActive) MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_ALBUM_MoveHandler);
                else MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_ALBUM_ConfirmHandler);
            }
        } else if(KEY_GetTrg()&2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            if(p->introActive) {
                if(*(u8 * *)&p->menuWindow) {MYSTERY_UTIL_DeleteMenuWindow(*(u8 * *)&p->menuWindow);p->menuWindow=0;}
                CLACT_SetActorDrawEnable(p->actorB,0);
                p->introActive=0;
            } else {
                CLACT_SetActorDrawEnable(p->actorC,0);
                CLACT_SetActorDrawEnable(p->actorD,0);
                MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_ALBUM_SaveHandler);
            }
        }
        if(delta) {
            count=MYSTERY_ALBUM_GetColumnCount(p);
            if(delta<0) {
                if(p->cursorIndex) next=p->cursorIndex-1;
                else next=count-1;
                direction=1;
            } else if(delta>0) {
                if(p->cursorIndex<count-1) next=p->cursorIndex+1;
                else next=0;
                direction=0;
            }
            GFL_USE_PlaySeDefaultVolume(0x642);
            MYSTERY_ALBUM_StartScroll(p,direction);
            MYSTERY_ALBUM_DeleteSlotActors(p,0);
            MYSTERY_ALBUM_SetCursor(p,0,direction,next,p->heapId);
            p->cursorIndex=next;
            CLACT_SetActorDrawEnable(p->actorA,0);
            CLACT_SetActorDrawEnable(p->actorC,0);
            CLACT_SetActorDrawEnable(p->actorD,0);
            p->angle=0;
            p->refreshFlag=1;
            *state=1;
        }
        if(changed) {
            if((int)p->cursorMode<4) {
                pos.x=data_021DF86E[p->cursorMode].c.x*8-24;
                pos.y=data_021DF86E[p->cursorMode].c.y*8-8;
                CLACT_SetActorAnimSeq(p->actorA,0);
            } else {
                pos.x=176;pos.y=152;
                CLACT_SetActorAnimSeq(p->actorA,11);
            }
            CLACT_AddActorSurfacePos(p->actorA,(const struct ClactVec2 *)(&pos),0);
            p->angle=0;
            p->refreshFlag=1;
        }
        break;
    case 1:
        if(MYSTERY_ALBUM_UpdateScroll(p)) *state=0;
        break;
    }
}

void MYSTERY_ALBUM_ConfirmHandler(void *task, int *state, void *pArg)
{
    MysteryAlbumWork *p = pArg;
    MysteryUtilMenuDef d;
    MysteryUtilVec2 v;
    int result;
    switch (*state) {
    case 0:
        if (!p->menuWindow) {
            p->menuWindow=MYSTERY_UTIL_CreateMenuWindow(0,15,p->printQueue,p->font,29);
            MYSTERY_UTIL_DrawMenuWindow(p->menuWindow,1,13);
        }
        MYSTERY_UTIL_SetMenuMessage(p->menuWindow,p->msgBank,116,0);
        *state=1;
        break;
    case 1:
        MI_CpuFill8(&d,0,sizeof(d));
        d.menuTable=p->msgBank; d.messageTable=p->font; d.printOwner=p->printQueue;
        d.menuItems[0]=117;d.menuItems[1]=118;d.menuItems[2]=119;d.count=3;
        d.bgLayer=0;d.palette=15;d.windowX=13;d.windowY=1;
        p->menu=MYSTERY_UTIL_CreateMenu(&d,p->heapId);
        *state=2;
        break;
    case 2:
        result=MYSTERY_UTIL_UpdateMenu(p->menu);
        p->angle=0x7fff;
        if (result==-1) break;
        if (result==0) {
            p->introActive=1;
            v.x=data_021DF86E[p->cursorMode].c.x*8-24;
            v.y=data_021DF86E[p->cursorMode].c.y*8-8;
            CLACT_AddActorSurfacePos(p->actorB,(const struct ClactVec2 *)(&v),0);
            CLACT_SetActorDrawEnable(p->actorB,1);
            p->swapIndex=p->cursorMode+p->cursorIndex*4;
            if (p->menu) {MYSTERY_UTIL_DeleteMenu(p->menu);p->menu=0;}
            if (*(u8 * *)&p->menuWindow) {MYSTERY_UTIL_DeleteMenuWindow(*(u8 * *)&p->menuWindow);p->menuWindow=0;}
            if (!p->menuWindow) {
                p->menuWindow=MYSTERY_UTIL_CreateMenuWindow2(0,15,p->printQueue,p->font,29);
                MYSTERY_UTIL_DrawMenuWindow(p->menuWindow,1,13);
            }
            MYSTERY_UTIL_SetMenuMessage(p->menuWindow,p->msgBank,122,0);
            *state=6;
        } else if (result==1) {
            if (MYSTERY_ALBUM_GetEntryEggFlag(&p->items[p->cursorMode+p->cursorIndex*4])) *state=7;
            else *state=3;
        } else if (result==2) *state=5;
        break;
    case 3:
        if (p->menu) {MYSTERY_UTIL_DeleteMenu(p->menu);p->menu=0;}
        MYSTERY_UTIL_SetMenuMessage(p->menuWindow,p->msgBank,120,1);
        *state=4;
        break;
    case 4:
        if (MYSTERY_UTIL_GetMenuState(p->menuWindow)) *state=5;
        break;
    case 5:
        if (*(u8 * *)&p->menuWindow) {MYSTERY_UTIL_DeleteMenuWindow(*(u8 * *)&p->menuWindow);p->menuWindow=0;}
        if (p->menu) {MYSTERY_UTIL_DeleteMenu(p->menu);p->menu=0;}
        MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_ALBUM_SelectHandler);
        break;
    case 6:
        MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_ALBUM_SelectHandler);
        break;
    case 7:
        MYSTERY_UTIL_DeleteMenu(p->menu);p->menu=0;
        MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_ALBUM_InfoHandler);
        break;
    }
    if (*(u8 * *)&p->menuWindow) MYSTERY_UTIL_UpdateMenuWindow(*(u8 * *)&p->menuWindow);
}

static inline void window0(int x,int y,int xx,int yy)
{
    *(volatile u16 *)REG_WIN0H_ADDR=((x<<8)&0xff00)|(xx&255);
    *(volatile u16 *)REG_WIN0V_ADDR=((y<<8)&0xff00)|(yy&255);
}

static inline void inside(int planes,int effect)
{
    u32 v=(*(volatile u16 *)REG_WININ_ADDR&~0x3f)|(u32)planes;
    if(effect) v|=32;
    *(volatile u16 *)REG_WININ_ADDR=v;
}

static inline void outside(int planes,int effect)
{
    u32 v=(*(volatile u16 *)REG_WINOUT_ADDR&~0x3f)|(u32)planes;
    if(effect) v|=32;
    *(volatile u16 *)REG_WINOUT_ADDR=v;
}

/*
 * lever: int coordinate locals retain table loads before SDK window plane writes; u8 locals were 4 bytes short.
 * volatile: display control 021DC82C/838/950/958; window registers 021DC84E..892.
 */
void MYSTERY_ALBUM_InfoHandler(void *task, int *state, void *pArg)
{
    MysteryAlbumWork *p = pArg;
    MysteryUtilMenuDef d;
    u32 index=p->cursorIndex*4+p->cursorMode;
    int result;
    int x,y;
    switch(*state) {
    case 0:MYSTERY_UTIL_SetMenuMessage(p->menuWindow,p->msgBank,123,1);*state=1;break;
    case 1:
        if(MYSTERY_UTIL_GetMenuState(p->menuWindow)) {
            MI_CpuFill8(&d,0,sizeof(d));
            d.menuTable=p->msgBank;d.messageTable=p->font;d.printOwner=p->printQueue;
            d.menuItems[0]=124;d.menuItems[1]=125;d.count=2;
            d.bgLayer=0;d.palette=15;d.windowX=13;d.windowY=1;
            p->menu=MYSTERY_UTIL_CreateMenu(&d,p->heapId);
            *state=2;
        }
        break;
    case 2:
        result=MYSTERY_UTIL_UpdateMenu((char *)p->menu);
        p->angle=0x7fff;
        if(result!=-1) {
            MYSTERY_UTIL_DeleteMenu(p->menu);p->menu=0;
            if(!result) *state=3;
            else {
                if(p->menuWindow) {MYSTERY_UTIL_DeleteMenuWindow(p->menuWindow);p->menuWindow=0;}
                MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_ALBUM_SelectHandler);
            }
        }
        break;
    case 3:
        *(volatile u32 *)REG_DISPCNT_ADDR=(*(volatile u32 *)REG_DISPCNT_ADDR&~0xe000)|0x2000;
        x=d_021DF86E[(u8)(index&3)*8];
        y=d_021DF86F[(u8)(index&3)*8];
        inside(30,1);
        window0(x*8,y*8,(x+12)*8,(y+7)*8);
        outside(30,0);*state=4;break;
    case 4:
        G2x_SetBlendBrightness_(REG_BLDCNT_ADDR,30,p->fadeTimer*16/30);
        if(p->fadeTimer++>30) {p->fadeTimer=0;*state=5;}
        break;
    case 5:
        MYSTERY_ALBUM_RemoveCard((MysteryAlbumWork *)p, index);
        MYSTERY_ALBUM_DeleteSlotActors(p,1);
        MYSTERY_ALBUM_SetCursor(p,1,0,p->cursorIndex,p->heapId);
        p->refreshFlag=1;*state=6;break;
    case 6:
        G2x_SetBlendBrightness_(REG_BLDCNT_ADDR,30,16-p->fadeTimer*16/30);
        if(p->fadeTimer++>30) {p->fadeTimer=0;*state=7;}
        break;
    case 7:
        if(!MYSTERY_DATA_HasAnyCard((struct MysteryData *)p->cardList)) MYSTERY_UTIL_ClearListWindow(p->windowList,1);
        *(volatile u32 *)REG_DISPCNT_ADDR &= ~0xe000;
        *state=8;break;
    case 8:MYSTERY_UTIL_SetMenuMessage(p->menuWindow,p->msgBank,121,1);*state=9;break;
    case 9:if(MYSTERY_UTIL_GetMenuState(p->menuWindow)) *state=10;break;
    case 10:
        if(p->menuWindow) {MYSTERY_UTIL_DeleteMenuWindow(p->menuWindow);p->menuWindow=0;}
        MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_ALBUM_SelectHandler);break;
    }
    if(p->menuWindow) MYSTERY_UTIL_UpdateMenuWindow(p->menuWindow);
}

static inline void window1(int x,int y,int xx,int yy)
{
    *(volatile u16 *)REG_WIN1H_ADDR=((x<<8)&0xff00)|(xx&255);
    *(volatile u16 *)REG_WIN1V_ADDR=((y<<8)&0xff00)|(yy&255);
}

static inline void inside0(int planes,int effect)
{
    u32 v=(*(volatile u16 *)REG_WININ_ADDR&~0x3f)|(u32)planes;
    if(effect) v|=32;
    *(volatile u16 *)REG_WININ_ADDR=v;
}

static inline void inside1(int planes,int effect)
{
    u32 v=(*(volatile u16 *)REG_WININ_ADDR&~0x3f00)|((u32)planes<<8);
    if(effect) v|=32<<8;
    *(volatile u16 *)REG_WININ_ADDR=v;
}

/*
 * lever: index read through a two-field struct, but the row field is re-read as a plain int in the cases (a different type stops the CSE across the switch); previous-cell value shifted unsigned; col declared before row for the slot order. Twin shape: ov121 021DC734.
 * note: 2026-10-05 recoup P23L5: 8 B DIFF first form (asrs for lsrs and row/col slots swapped), then EXACT. Real extent 792 B, not the 46 B of the lane list.
 * volatile: display control 04000000, window registers 04000040..4A.
 */
void MYSTERY_ALBUM_MoveHandler(void *task, int *state, void *pArg)
{
    MysteryAlbumWork *p = pArg;
    u32 index=((const u32 *)&p->cursorIndex)[1]+((const u32 *)&p->cursorIndex)[0]*4;
    int here,there,mask;
    int x,y;
    u8 now,old;
    int col,row;
    switch(*state) {
    case 0:
        if(p->menuWindow) {MYSTERY_UTIL_DeleteMenuWindow(p->menuWindow);p->menuWindow=0;}
        p->introActive=0;
        if(index==p->swapIndex) {
            CLACT_SetActorDrawEnable((struct ClactActor *)p->actorB,0);
            MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_ALBUM_SelectHandler);
            return;
        }
        *state=1;break;
    case 1:
        now=index&3;
        old=p->swapIndex%4;
        here=((p->cursorIndex)==(index>>2));
        there=((p->cursorIndex)==((u32)p->swapIndex>>2));
        mask=0;if(here) mask|=1;if(there) mask|=2;
        *(volatile u32 *)REG_DISPCNT_ADDR=(*(volatile u32 *)REG_DISPCNT_ADDR&~0xe000)|(mask<<13);
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
        G2x_SetBlendBrightness_(REG_BLDCNT_ADDR,30,p->fadeTimer*16/30);
        if(p->fadeTimer++>30) {p->fadeTimer=0;*state=3;}break;
    case 3:
        MYSTERY_ALBUM_SwapCards((MysteryAlbumWork *)p,index,p->swapIndex);GFL_USE_PlaySeDefaultVolume(0x670);
        row=(u32)p->swapIndex>>2;col=p->swapIndex%4;
        there=((p->cursorIndex)==row);
        here=((p->cursorIndex)==(index>>2));
        if(here) {
            MYSTERY_ALBUM_DeleteSlotActor(p,1,p->cursorMode);
            MYSTERY_ALBUM_SetupSlot(p,1,0,(p->cursorIndex),p->cursorMode,p->heapId);
        }
        if(there) {
            MYSTERY_ALBUM_DeleteSlotActor(p,1,col);
            MYSTERY_ALBUM_SetupSlot(p,1,0,row,col,p->heapId);
        }
        BG_SYS_PushTile(3);p->refreshFlag=1;*state=4;break;
    case 4:
        G2x_SetBlendBrightness_(REG_BLDCNT_ADDR,30,16-p->fadeTimer*16/30);
        if(p->fadeTimer++>30) {p->fadeTimer=0;*state=5;}break;
    case 5:*(volatile u32 *)REG_DISPCNT_ADDR &=~0xe000;*state=6;break;
    case 6:
        p->introActive=0;CLACT_SetActorDrawEnable((struct ClactActor *)p->actorB,0);
        if(p->menuWindow) {MYSTERY_UTIL_DeleteMenuWindow(p->menuWindow);p->menuWindow=0;}
        MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_ALBUM_SelectHandler);break;
    }
}

/*
 * lever: separate case-1 guard tests preserve the branch to the shared state store; a short-circuit guard gives DIFF404.
 */
void MYSTERY_ALBUM_SaveHandler(void *arg, int *state, void *pArg)
{
    MysteryAlbumWork *p = pArg;
    MysteryUtilMenuDef d;
    int result;
    int ready;
    switch (*state) {
    case 0:
        *state=1;
        break;
    case 1:
        if (!p->mode) *state=5;
        else if (MYSTERY_DATA_HasCardSpace(p->cardList)) *state=5;
        else *state=2;
        break;
    case 2:
        if (!p->menuWindow) {
            p->menuWindow=MYSTERY_UTIL_CreateMenuWindow(0,15,p->printQueue,p->font,29);
            MYSTERY_UTIL_DrawMenuWindow(p->menuWindow,1,13);
        }
        MYSTERY_UTIL_SetMenuMessage(p->menuWindow,p->msgBank,93,1);
        *state=3;
        break;
    case 3:
        if (MYSTERY_UTIL_GetMenuState(p->menuWindow)) {
            MI_CpuFill8(&d,0,sizeof(d));
            d.menuTable=p->msgBank;
            d.messageTable=p->font;
            d.printOwner=p->printQueue;
            d.menuItems[0]=124;
            d.menuItems[1]=125;
            d.count=2;
            d.bgLayer=0; d.palette=15; d.windowX=13; d.windowY=1;
            p->menu=MYSTERY_UTIL_CreateMenu(&d,p->heapId);
            *state=4;
        }
        break;
    case 4:
        result=MYSTERY_UTIL_UpdateMenu(p->menu);
        p->angle=0x7fff;
        if (result!=-1) {
            MYSTERY_UTIL_DeleteMenu(p->menu);
            p->menu=0;
            if (!result) *state=5;
            else {
                if (p->menuWindow) {
                    MYSTERY_UTIL_DeleteMenuWindow(p->menuWindow);
                    p->menuWindow=0;
                }
                MYSTERY_UTIL_SetTaskHandler(arg,MYSTERY_ALBUM_SelectHandler);
            }
        }
        break;
    case 5:
        if (p->dirty) *state=6;
        else *state=10;
        break;
    case 6:
        if (!p->menuWindow) {
            p->menuWindow=MYSTERY_UTIL_CreateMenuWindow(0,15,p->printQueue,p->font,29);
            MYSTERY_UTIL_DrawMenuWindow(p->menuWindow,1,13);
        }
        MYSTERY_UTIL_SetMenuMessage(p->menuWindow,p->msgBank,115,2);
        *state=7;
        break;
    case 7:
        if (MYSTERY_UTIL_GetMenuState(p->menuWindow)) *state=8;
        break;
    case 8:
        ready=1;
        if (p->selectedAlbum && !MYSTERY_ALBUM_IsIntroIdle(p->selectedAlbum)) ready=0;
        if (ready) {
            MYSTERY_DATA_SaveStart(p->cardList,(struct GameData *)(p->gameData));
            *state=9;
        }
        break;
    case 9:
        if (MYSTERY_DATA_SaveMain(p->cardList,(struct GameData *)(p->gameData))==2) *state=10;
        break;
    case 10:
        if (p->menuWindow) {
            MYSTERY_UTIL_DeleteMenuWindow(p->menuWindow);
            p->menuWindow=0;
        }
        MYSTERY_UTIL_MarkTaskDone(arg);
        break;
    }
    if (p->menuWindow) MYSTERY_UTIL_UpdateMenuWindow(p->menuWindow);
}

void MYSTERY_ALBUM_SingleHandler(void *arg,int *state,MysteryAlbumWork *p)
{
    switch (*state) {
    case 0:
        if (!p->menuWindow)
            p->menuWindow=MYSTERY_UTIL_CreateMenuWindow(0,15,p->printQueue,p->font,29);
        MYSTERY_UTIL_DrawMenuWindow(p->menuWindow,1,13);
        MYSTERY_UTIL_SetMenuMessage(p->menuWindow,p->msgBank,92,1);
        *state=1; break;
    case 1:
        if (MYSTERY_UTIL_GetMenuState(p->menuWindow)) *state=2;
        break;
    case 2:
        if (p->menuWindow) {
            MYSTERY_UTIL_DeleteMenuWindow(p->menuWindow);
            p->menuWindow=0;
        }
        MYSTERY_UTIL_SetTaskHandler(arg,MYSTERY_ALBUM_SelectHandler);
        break;
    }
    if (p->menuWindow) MYSTERY_UTIL_UpdateMenuWindow(p->menuWindow);
}

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void MYSTERY_ALBUM_SetupIconSprite(MysteryUtilBlendPalettes *p,void *arc,int id,int index,u8 other,u16 heap)
{
    void *res;
    void *allocation;
    char *data;
    MI_CpuFill8(p,0,0x60);
    allocation=ARC_UTIL_LoadPaletteBlockFromHandle(arc,id,&res,heap);
    data=((MysteryUtilResData *)res)->data;
    MI_CpuCopy8(data+index*32,p->blendTo,32);
    MI_CpuCopy8(data+other*32,p->blendFrom,32);
    GFL_HEAP_Free(allocation);
}

void MYSTERY_ALBUM_UpdateIconSprite(MysteryUtilBlendPalettes *p,int b,int c,u16 d) {MYSTERY_UTIL_BlendPaletteRange(b,p->current,d,c,p->blendFrom,p->blendTo);}

/*
 * lever: const descriptor input places its loads before the outgoing heap store.
 * interfaces: D81C/D898 scalar stack words reproduce the aggregate layout; complete bodies and forwarding targets read no padding, key only low halfword.
 */
void *MYSTERY_ALBUM_CreateSlotWork(const MysteryAlbumDesc *p,u16 heap)
{
    char *out;
    MysteryUtilMenuEntryTable config;
    struct ActorInitParam first;
    struct ActorInitParam second;
    void *arc;
    void *arc2;
    out=GFL_HEAP_Alloc(heap,sizeof(MysteryAlbumSlotWork),0,d_021DFBB0,0xcff);
    ((MysteryAlbumSlotWork *)out)->paletteBank=p->paletteBank;
    ((MysteryAlbumSlotWork *)out)->frontPlane=p->frontPlane;
    ((MysteryAlbumSlotWork *)out)->backPlane=p->backPlane;
    ((MysteryAlbumSlotWork *)out)->desc=*p;
    if(p->frontPlane<4) {
        ((MysteryAlbumSlotWork *)out)->pokeBank=0;
        ((MysteryAlbumSlotWork *)out)->screenId=0;
        ((MysteryAlbumSlotWork *)out)->isMainScreen=1;
    } else {
        ((MysteryAlbumSlotWork *)out)->pokeBank=4;
        ((MysteryAlbumSlotWork *)out)->screenId=1;
        ((MysteryAlbumSlotWork *)out)->isMainScreen=0;
    }
    config=d_021DF99C;
    /* stand-in: unprototyped call; the prototype's u16/u8 parameters narrow the arguments and change the bytes */
    ((MysteryAlbumSlotWork *)out)->windowList=MYSTERY_UTIL_CreateWindowList((void *)1,(const char *)&config,5,(u16)((MysteryAlbumSlotWork *)out)->desc.backPlane,(u8)((MysteryAlbumSlotWork *)out)->desc.windowPalette,((MysteryAlbumSlotWork *)out)->desc.printQueue,((MysteryAlbumSlotWork *)out)->desc.msgBank,((MysteryAlbumSlotWork *)out)->desc.font,heap);
    arc=ARC_TOOL_CreateHandle(34,heap);
    ((MysteryAlbumSlotWork *)out)->palette=CLACT_RegisterPalette(arc,3,((MysteryAlbumSlotWork *)out)->screenId,(u16)(p->charPalette<<5),heap);
    ((MysteryAlbumSlotWork *)out)->cellAnim=CLACT_RegisterCellAnim(arc,33,36,heap);
    ((MysteryAlbumSlotWork *)out)->character=CLACT_RegisterCharacter(arc,12,0,((MysteryAlbumSlotWork *)out)->screenId,heap);
    ARC_TOOL_DeleteHandle(arc);
    MI_CpuFill8(&first,0,8);
    first.x=216;first.y=22;
    ((MysteryAlbumSlotWork *)out)->actorA=CLACT_CreateActor(p->clactUnit,((MysteryAlbumSlotWork *)out)->character,((MysteryAlbumSlotWork *)out)->palette,((MysteryAlbumSlotWork *)out)->cellAnim,&first,((MysteryAlbumSlotWork *)out)->screenId,heap);
    CLACT_SetActorObjMode(((MysteryAlbumSlotWork *)out)->actorA,0);
    CLACT_SetActorDrawEnable(((MysteryAlbumSlotWork *)out)->actorA,0);
    arc2=(void *)POKEGRA_OpenHandle(heap);
    ((MysteryAlbumSlotWork *)out)->pokePalette=POKEGRA_RegisterPalette(arc2,1,0,0,0,0,0,((MysteryAlbumSlotWork *)out)->screenId,p->paletteBank<<5,heap);
    ((MysteryAlbumSlotWork *)out)->pokeCellAnim=POKEGRA_RegisterCellAnim(1,0,0,0,0,0,2,((MysteryAlbumSlotWork *)out)->screenId,heap);
    ((MysteryAlbumSlotWork *)out)->pokeCharacter=POKEGRA_RegisterCgr(arc2,1,0,0,0,0,0,0,((MysteryAlbumSlotWork *)out)->screenId,heap);
    ARC_TOOL_DeleteHandle(arc2);
    MI_CpuFill8(&second,0,8);
    second.x=184;second.y=112;second.bg_priority=p->frontPlane&3;
    ((MysteryAlbumSlotWork *)out)->idleAnimId=second.bg_priority;
    ((MysteryAlbumSlotWork *)out)->introAnimId=p->backPlane&3;
    ((MysteryAlbumSlotWork *)out)->actorB=CLACT_CreateActor(p->clactUnit,((MysteryAlbumSlotWork *)out)->pokeCharacter,((MysteryAlbumSlotWork *)out)->pokePalette,((MysteryAlbumSlotWork *)out)->pokeCellAnim,&second,((MysteryAlbumSlotWork *)out)->screenId,heap);
    CLACT_SetActorAffineMode(((MysteryAlbumSlotWork *)out)->actorB,2);
    CLACT_SetActorObjMode(((MysteryAlbumSlotWork *)out)->actorB,1);
    CLACT_SetActorDrawEnable(((MysteryAlbumSlotWork *)out)->actorB,0);
    return out;
}

void MYSTERY_ALBUM_DeleteSlotWork(MysteryAlbumSlotWork *p)
{
    CLACT_DeleteActor(p->actorB);
    CLACT_ReleaseCharacter(p->pokeCharacter);
    CLACT_ReleaseCellAnim(p->pokeCellAnim);
    CLACT_ReleasePalette(p->pokePalette);
    CLACT_DeleteActor(p->actorA);
    CLACT_ReleaseCharacter(p->character);
    CLACT_ReleaseCellAnim(p->cellAnim);
    CLACT_ReleasePalette(p->palette);
    MYSTERY_UTIL_DeleteWindowList(p->windowList);
    GFL_HEAP_Free(p);
}

int MYSTERY_ALBUM_UpdateSlotWork(MysteryAlbumSlotWork *p) {return MYSTERY_UTIL_IsWindowListDone(p->windowList);}

struct MysteryAlbumView *MYSTERY_ALBUM_CreateAlbumView(MysteryAlbumCard *card, MysteryAlbumSlotWork *slotWork, void *gameData, u16 heap)
{
    struct MysteryAlbumView *out;
    MysteryAlbumCreateInput ctx;
    MysteryUtilMenuEntryTable desc;
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

    out = GFL_HEAP_Alloc(heap, sizeof(*out), 0, d_021DFBB0, 0xDD4);
    MI_CpuFill8(out, 0, sizeof(*out));
    out->heap = heap;
    out->card = (struct MysteryAlbumViewCard *)card;
    out->slotWork = slotWork;
    out->gameData = gameData;
    MI_CpuFill8(&ctx, 0, sizeof(ctx));
    ctx.mode = 0;
    ctx.clactUnit = slotWork->desc.clactUnit;
    ctx.cardList = slotWork->desc.cardList;
    ctx.font = slotWork->desc.font;
    ctx.printQueue = slotWork->desc.printQueue;
    ctx.wordSet = slotWork->desc.wordSet;
    ctx.msgBank = slotWork->desc.msgBank;
    ctx.gameData = gameData;
    MYSTERY_ALBUM_SetupEntry((MysteryAlbumEntry *)out, (const MysteryAlbumCard *)card, &ctx, heap);
    desc = d_021DFA14;
    id16 = (heap & 0x7fff) | 0x8000;
    desc.e[1].str.stringPtr = STRBUF_Create(0x25, (u16)id16);
    STRBUF_SetStringN(desc.e[1].str.stringPtr, (const u16 *)((char *)out->card + 0x60), 0x24);
    if (out->card->altMessageSet)
        idx = out->card->messageIndex + 0x19d;
    else
        idx = out->card->messageIndex + 0x9d;
    desc.e[2].str.stringPtr = MSGDATA_AllocString(slotWork->desc.msgBank, idx);
    desc.e[4].str.stringPtr = STRBUF_Create(0x80, heap);
    flags = out->card->eventDate;
    t4 = MSGDATA_AllocString(slotWork->desc.msgBank, 0x9a);
    res = 0;
    WORDSET_SetSlotNumber(slotWork->desc.wordSet, 0, (u16)(flags >> 16), 4, 1, 1);
    MYSTERY_ALBUM_SET_MONTH(slotWork->desc.wordSet, 1, (u8)(flags >> 8));
    WORDSET_SetSlotNumber(slotWork->desc.wordSet, 2, (u8)flags, 2, 0, 1);
    WORDSET_CopyTaggedText(slotWork->desc.wordSet, desc.e[4].str.stringPtr, t4);
    out->bmpList = MYSTERY_UTIL_CreateBmpList((char *)slotWork->windowList, heap);
    MYSTERY_UTIL_DrawBmpList(out->bmpList, (char *)(&desc), slotWork->desc.printQueue);
    STRBUF_Delete(desc.e[1].str.stringPtr);
    STRBUF_Delete(desc.e[2].str.stringPtr);
    STRBUF_Delete(desc.e[4].str.stringPtr);
    STRBUF_Delete(t4);
    if (MYSTERY_ALBUM_GetEntryKind(out) == 1) {
        struct MysteryAlbumViewCard *r = out->card;
        u16 mv[4];
        u8 iv[6];
        int i;
        u32 k;
        u32 ivs;

        gs = out->gameData;
        hid = id16;
        level = r->level;
        id = r->otIdOrItem;
        species = r->species;
        gender = r->gender;
        mode = r->abilityMode;

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
        if (r->giftType == 1 && species <= SPECIES_LAST && species != 0 && level <= 0x64 && r->heldItem <= ITEM_LAST) {
            if (level == 0)
                level = (u16)(GFL_USE_GetRandom(0x64) + 1);
            if (r->otIdOrItem == 0)
                id = MYSTATUS_GetId(GAME_DATA_GetMyStatus(gs));
            if (gender == 0xff)
                gender = 2;
            for (i = 0; i < 6; i++) {
                if (iv[i] == 0xff)
                    iv[i] = GFL_USE_GetRandom(0x20);
            }
            id64 = id;
#ifdef __MWERKS__
            mon = POKE_TOOL_Create((u16)species, level, id, 0, hid);
#else
            mon = POKE_TOOL_Create((u16)species, level, id, hid);
#endif
            ivs = (iv[0] & 31) | ((iv[1] & 31) << 5) | ((iv[2] & 31) << 10) | ((iv[3] & 31) << 15) | ((iv[4] & 31) << 20) | ((iv[5] & 31) << 25);
            if (mode == 4)
                mode = (u8)GFL_USE_GetRandom(3);
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
            if (r->personality != 0)
                rnd = r->personality;
            else {
                if (r->shinyMode == 0)
                    rnd = POKE_TOOL_CreatePersonalRnd(id, (u16)species, r->form, gender, i, 0);
                else if (r->shinyMode == 1)
                    rnd = POKE_TOOL_CreatePersonalRnd(id, (u16)species, r->form, gender, i, 2);
                else if (r->shinyMode == 2)
                    rnd = POKE_TOOL_CreatePersonalRnd(id, (u16)species, r->form, gender, i, 1);
            }
            POKE_TOOL_SetupPartyParamEx(mon, r->species, level, id64, ivs, rnd);
            POKE_TOOL_SetPartyValue(mon, 6, r->heldItem);
            POKE_TOOL_SetDefaultMoves(mon);
            for (i = 0; i < 4; i++) {
                u16 m = mv[i];
                if (m != 0 && m < MOVE_LAST + 1) {
                    if (POKE_TOOL_AddMove(mon, m) == 0xffff)
                        POKE_TOOL_PushMove(mon, m);
                }
            }
            if (r->personality == 0 && mode == 2)
                POKE_TOOL_SetAbility(mon, species, r->form);
            POKE_TOOL_SetPartyValue(mon, 0x6f, r->form);
            if (r->ball != 0 && r->ball <= 0x19)
                POKE_TOOL_SetPartyValue(mon, 0x98, r->ball);
            else
                POKE_TOOL_SetPartyValue(mon, 0x98, 4);
            if (r->metLevel != 0)
                POKE_TOOL_SetPartyValue(mon, 0x99, r->metLevel);
            POKE_TOOL_SetPartyValue(mon, 0x13, r->contestCool);
            POKE_TOOL_SetPartyValue(mon, 0x14, r->contestBeauty);
            POKE_TOOL_SetPartyValue(mon, 0x15, r->contestCute);
            POKE_TOOL_SetPartyValue(mon, 0x16, r->contestSmart);
            POKE_TOOL_SetPartyValue(mon, 0x17, r->contestTough);
            POKE_TOOL_SetPartyValue(mon, 0x18, r->contestTough);
            for (k = 0; k < 15; k++) {
                if (r->ribbonFlags & (1 << k))
                    POKE_TOOL_SetPartyValue(mon, d_021DF8C0[k], 1);
            }
            if (r->originGame == 0)
                POKE_TOOL_SetPartyValue(mon, 0x77, g0209DF08);
            else
                POKE_TOOL_SetPartyValue(mon, 0x77, r->originGame);
            if (r->language == 0)
                POKE_TOOL_SetPartyValue(mon, 0xc, g0209DF0C);
            else
                POKE_TOOL_SetPartyValue(mon, 0xc, r->language);
            if (r->nickname == 0) {
                GFL_HEAP_Free(mon);
                res = 0;
                goto end;
            }
            if (r->nickname != STRBUF_GetEosChar())
                POKE_TOOL_SetPartyValue(mon, 0x74, (uptr)&r->nickname);
            {
                u32 v = r->nature;
                if (v == 0xff)
                    v = (u8)GFL_USE_GetRandom(0x19);
                POKE_TOOL_SetPartyValue(mon, 0x70, v);
            }
            POKE_TOOL_SetPartyValue(mon, 0x95, r->eggLocation);
            POKE_TOOL_SetPartyValue(mon, 0x96, r->metLocation);
            if (r->otName == 0) {
                GFL_HEAP_Free(mon);
                res = 0;
                goto end;
            }
            if (r->otName == STRBUF_GetEosChar())
                POKE_TOOL_SetPartyValue(mon, 0x8e, (uptr)MYSTATUS_GetName(GAME_DATA_GetMyStatus(gs)));
            else
                POKE_TOOL_SetPartyValue(mon, 0x8e, (uptr)&r->otName);
            {
                u32 v = r->otGender;
                if (v <= 2)
                    POKE_TOOL_SetPartyValue(mon, 0x9a, v);
                else {
                    v = MYSTATUS_GetSex(GAME_DATA_GetMyStatus(gs));
                    POKE_TOOL_SetPartyValue(mon, 0x9a, v);
                }
            }
            if (r->isEgg != 0) {
                void *s;
                POKE_TOOL_SetPartyValue(mon, 0x4c, 1);
                s = MSGDATA_AllocString(gSpeciesNameBank, 0x28a);
                POKE_TOOL_SetPartyValue(mon, 0x73, (uptr)s);
                STRBUF_Delete(s);
                POKE_TOOL_SetPartyValue(mon, 9, 10);
            }
            {
                int w = r->eventDate;
                u32 loc;
                year = w >> 16;
                month = (u8)(w >> 8);
                day = w;
                loc = r->isEgg ? r->eggLocation : r->metLocation;
                SAVE_EVENT_WriteWithDate((struct SaveData *)POKE_TOOL_CastToBoxParam(mon), loc, year - 2000, month, day);
            }
            POKE_TOOL_RecalcParam(mon);
            res = 0;
            if (POKE_TOOL_GetPartyValue(mon, 3, 0) != 0)
                GFL_HEAP_Free(mon);
            else
                res = mon;
            goto end;
        }
    end:
        {
            void *arc = (void *)POKEGRA_OpenHandle((u16)id16);
            u32 arcId, speciesId, formId, genderId;
            out->species = r->species;
            out->form = r->form;
            out->isEgg = r->isEgg;
            arcId = POKEGRA_GetArcID();
            speciesId = POKE_TOOL_GetPartyValue(res, 5, 0);
            formId = POKE_TOOL_GetPartyValue(res, 0x6f, 0);
            genderId = POKE_TOOL_GetPartyValue(res, 0x6e, 0);
            idx = POKEGRA_GetPalArcIndex(arcId, speciesId, formId, genderId, POKE_TOOL_IsShiny(res), 0, POKE_TOOL_GetPartyValue(res, 0x4c, 0));
            out->pokePalette = ARC_UTIL_LoadPaletteBlockFromHandle(arc, idx, &out->pokePaletteData, out->heap);
            out->pokeCharData = POKEGRA_LoadCharDataPP(&out->pokeCharBuf, POKE_TOOL_GetBoxParam(res), 0, out->heap);
            GFL_HEAP_Free(res);
            ARC_TOOL_DeleteHandle(arc);
        }
    }
    return out;
}

struct Node;

#include "../types.h"

typedef struct { s16 frameId,x,y; } MysteryAlbumPathOut;

#include "../arm9/tcb_list.h"



#include "../arm9/pm_voice.h"


extern void MYSTERY_ALBUM_PathAnimInit(MysteryAlbumPathAnim *anim,u16 frameId,int x,int y);


#pragma thumb off

extern void MYSTERY_ALBUM_SetBlendMain(int eva, int evb);

extern void MYSTERY_ALBUM_SetBlendSub(int eva, int evb);

#pragma thumb on

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void MYSTERY_ALBUM_Delete(MysteryAlbum *album)
{
    if (album->setupTask) {
        TCB_DeleteTask(album->setupTask);
        album->setupTask=0;
    }
    if (album->paletteBuffer) GFL_HEAP_Free(album->paletteBuffer);
    if (album->bgDataBuffer) GFL_HEAP_Free(album->bgDataBuffer);
    MYSTERY_UTIL_DeleteBmpList(album->cardView);
    MYSTERY_ALBUM_ClearEntry((MysteryAlbumEntry *)album);
    GFL_HEAP_Free(album);
}

/*
 * verdict: 612-byte lead; the rest of the 652-byte extent is the two ARM
 *   followers 021DDC30 and 021DDC44 (20 bytes each), filed as their own
 *   ARM leaves (pkt_ov121_021DDC30, pkt_ov121_021DDC44, W82 R11), which
 *   also resolve the ABS32 blend callbacks at +0x258/+0x25C.
 * lever: case 5 seeds the result flag with its own constant and ANDs the
 *   call in (done = 1; done &= f(...)); "f(...) & 1" or "1 & f(...)" CSEs
 *   the 1 with ok's r6 (11 bytes).
 */
void MYSTERY_ALBUM_StepIntro(MysteryAlbum *album)
{
    MysteryAlbumUi *ui=album->ui;
    sptr fadeLayer; int blendEva, blendEvb, done, soundDone;
    u16 tick;
    void (*setBlend)(int,int);
    struct ClactVec2 cursorStart;
    int position[2];
    MysteryAlbumPathOut pathOut;
    if(ui->isMainScreen) { fadeLayer=14; setBlend=MYSTERY_ALBUM_SetBlendMain; }
    else { setBlend=MYSTERY_ALBUM_SetBlendSub; fadeLayer=30; }
    switch(album->introPhase) {
    case 1:
        CLACT_SetActorBgPriority(ui->cursorActor,ui->introAnimId);
        album->introPhase=2;
        break;
    case 2:
        MYSTERY_UTIL_BlendPaletteRange(fadeLayer,ui->palFade,(album->introTick*0x7fff)/60,(u8)(ui->paletteBank),ui->palImage,ui->palBlack);
        tick=album->introTick;
        blendEva=tick*14/60;
        blendEvb=tick*-12/60;
        setBlend(blendEva+2,blendEvb+12);
        if(album->introTick++>60) {
            album->introTick=0;
            album->introPhase=3;
        }
        break;
    case 3: album->introPhase=4; break;
    case 4:
        if(!album->skipSound)
            album->soundHandle=PM_VOICE_Play(album->soundId,album->soundPlayerId,64,0,0,0,0,0);
        CLACT_GetActorSurfacePos(ui->cursorActor,(struct ClactVec2 *)(&cursorStart),ui->screenId);
        MYSTERY_ALBUM_PathAnimInit(&album->pathAnim,CLACT_GetActorRotation(ui->cursorActor),cursorStart.x,cursorStart.y);
        album->introPhase=5;
        break;
    case 5:
        soundDone=1;
        done=1;
        done&=MYSTERY_ALBUM_PathAnimStep(&album->pathAnim,(u16 *)&pathOut,(MysteryAlbumPathPoint *)position);
        pathOut.x=position[0];
        pathOut.y=position[1];
        CLACT_AddActorSurfacePos(ui->cursorActor,(struct ClactVec2 *)&pathOut.x,ui->screenId);
        if(!album->skipSound) {
            if(PM_VOICE_IsSlotActive(album->soundHandle)) soundDone=0;
            done &= soundDone;
        }
        if(done) album->introPhase=6;
        break;
    case 6:
        MYSTERY_UTIL_BlendPaletteRange(fadeLayer,ui->palFade,0x7fff-(album->introTick*0x7fff)/60,(u8)(ui->paletteBank),ui->palImage,ui->palBlack);
        tick=album->introTick;
        blendEva=tick*-14/60;
        blendEvb=tick*12/60;
        setBlend(blendEva+16,blendEvb);
        if(album->introTick++>60) {
            album->introTick=0;
            album->introPhase=7;
        }
        break;
    case 7: album->introPhase=8; break;
    case 8:
        CLACT_SetActorBgPriority(ui->cursorActor,ui->idleAnimId);
        album->introPhase=0;
        break;
    }
}

#pragma thumb off

/*
 * Unlabelled ARM follower of MYSTERY_ALBUM_StepIntro, referenced by its ABS32 pool
 * word at +0x258: main-screen blend callback writing BLDALPHA (0x04000052)
 * as eva | evb << 8.
 */
void MYSTERY_ALBUM_SetBlendMain(int eva, int evb)
{
    *(volatile u16 *)REG_BLDALPHA_ADDR = eva | (evb << 8);
}

void MYSTERY_ALBUM_SetBlendSub(int eva, int evb)
{
    *(volatile u16 *)REG_DB_BLDALPHA_ADDR = eva | (evb << 8);
}

struct ClactActor;

struct ClactActor;




struct PaletteData;





#pragma thumb on





void MYSTERY_ALBUM_LoadBgWithTilemap(const MysteryAlbumBgSetup *bgSetup,MysteryAlbum *album,u16 heapId);

void MYSTERY_ALBUM_LoadBgPalette(MysteryAlbumBgSetup *bgSetup,MysteryAlbum *album,u16 heapId);

void MYSTERY_ALBUM_SetupIcons(MysteryAlbum *album,MysteryAlbumUi *ui,u16 heapId);

void MYSTERY_ALBUM_SetupTask(struct TcbTask *unused,void *work);

int MYSTERY_ALBUM_PathAnimStep(MysteryAlbumPathAnim *anim, u16 *outFrameId, MysteryAlbumPathPoint *outPosition);

extern u16 MYSTERY_ALBUM_PathFrameIds[];

extern const s8 MYSTERY_ALBUM_PathDirections[];

extern s8 MYSTERY_ALBUM_PathDurations[];

extern const MysteryAlbumPathPoint MYSTERY_ALBUM_PathWaypoints[];

/*
 * extent: two bytes of zero alignment padding after the return.
 * lever: initialize resource after the first guard; const source orders loads before stack argument stores.
 */
void MYSTERY_ALBUM_LoadBgWithTilemap(const MysteryAlbumBgSetup *bgSetup,MysteryAlbum *album,u16 heapId)
{
    int screenOffset=0;
    int tilemapFile;
    u16 imageId;
    void *arc;
    if (bgSetup->bgLayer>=4) screenOffset=4;
    tilemapFile=26;
    if (bgSetup->bgLayer<=3) tilemapFile=27;
    imageId=MYSTERY_ALBUM_GetEntryIconY(album);
    arc=ARC_TOOL_CreateHandle(34,heapId);
    ARC_UTIL_UploadPaletteFromHandle(arc,4,screenOffset,imageId*32,bgSetup->paletteNumber*32,32,heapId);
    ARC_UTIL_UploadBgCharFromHandle(arc,13,bgSetup->bgLayer,0,0,0,heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(arc,(u16)tilemapFile,bgSetup->bgLayer,0,0,0,heapId);
    BG_SYS_FillTileMap((u8)bgSetup->bgLayer,0,0,34,24,bgSetup->paletteNumber);
    BG_SYS_PushTile((u8)bgSetup->bgLayer);
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void MYSTERY_ALBUM_LoadBgPalette(MysteryAlbumBgSetup *bgSetup,MysteryAlbum *album,u16 heapId)
{
    int screenOffset=0;
    u16 imageId;
    void *arc;
    if (bgSetup->bgLayer>=4) screenOffset=4;
    imageId=MYSTERY_ALBUM_GetEntryIconY(album);
    arc=ARC_TOOL_CreateHandle(34,heapId);
    ARC_UTIL_UploadPaletteFromHandle(arc,4,screenOffset,imageId*32,bgSetup->paletteNumber*32,32,heapId);
    BG_SYS_FillTileMap((u8)bgSetup->bgLayer,0,0,34,24,bgSetup->paletteNumber);
    BG_SYS_PushTile((u8)bgSetup->bgLayer);
    ARC_TOOL_DeleteHandle(arc);
}

static inline void *MYSTERY_ALBUM_GetPaletteRam(uptr byteOffset, int screenId)
{
    if (screenId==0) return (void *)(byteOffset+HW_OBJ_PLTT);
    else return (void *)(byteOffset+HW_DB_OBJ_PLTT);
}

/*
 * lever (wave 82, lane R10, retry): the palette base is an inline that adds
 *   the byte offset inside each arm (`if (mode==0) return off+0x05000200;
 *   else return off+0x05000600;`); the shared add cross-jumps into the
 *   `adds r1,r0,r1` join. A base-only inline plus `+ offset` at the call site,
 *   or a ternary on the base, if-converts to a default load plus override and
 *   misschedules the q+0xb0/q+0x98 loads (431 B). The heap stays u16 as in
 *   matched ov121 MYSTERY_ALBUM_CreateEntryArc and matched caller MYSTERY_ALBUM_SetupTask: the earlier
 *   u32-heap owner gate does not apply.
 */
void MYSTERY_ALBUM_SetupIcons(MysteryAlbum *album,MysteryAlbumUi *ui,u16 heapId)
{
    void *arc;
    void *iconPalAlloc;
    void *iconGfxAlloc;
    NNSG2dPaletteData *iconPalRes;
    NNSG2dCharacterData *iconGfxRes;
    struct ClactVec2 iconPos;
    u16 *paletteRam;
    u32 offset;
    int i;
    arc=MYSTERY_ALBUM_CreateEntryArc(album,heapId);
    iconPalAlloc=ARC_UTIL_LoadPaletteBlockFromHandle(arc,(int)MYSTERY_ALBUM_GetEntryPaletteResId(album),&iconPalRes,(u16)(album->heapId));
    offset=ui->iconPaletteNumber*32;
    MI_CpuCopy8(iconPalRes->pRawData,MYSTERY_ALBUM_GetPaletteRam(offset,ui->screenId),96);
    GFL_HEAP_Free(iconPalAlloc);
    iconGfxAlloc=ARC_UTIL_LoadScreenDataFromHandle(arc,(int)MYSTERY_ALBUM_GetEntryGraphicIndex(album),(int)0,&iconGfxRes,album->heapId);
    CLACT_TransferCharacterPart(ui->bgHandleA,iconGfxRes->pRawData,512,0,ui->screenId);
    GFL_HEAP_Free(iconGfxAlloc);
    ARC_TOOL_DeleteHandle(arc);
    iconPos.x=216; iconPos.y=22;
    if (MYSTERY_ALBUM_GetEntryKind(album)==2) {iconPos.x+=4;iconPos.y+=8;}
    CLACT_SetActorPaletteOffset(ui->iconActor,(u8)MYSTERY_ALBUM_GetEntryIconPalette(album),0);
    CLACT_AddActorSurfacePos(ui->iconActor, (const struct ClactVec2 *)&iconPos, ui->screenId);
    CLACT_SetActorDrawEnable(ui->iconActor,1);
    if (MYSTERY_ALBUM_GetEntryKind(album)==1) {
        CLACT_TransferPalette(ui->paletteHandle,(struct PaletteData *)album->paletteRes->pRawData,1);
        MI_CpuCopy8(album->paletteRes->pRawData,ui->palImage,32);
        MIi_CpuClear16(0,ui->palBlack,32);
        CLACT_TransferCharacterPart(ui->bgHandleB,album->bgDataRes->pRawData,0x1200,0,ui->screenId);
        CLACT_SetActorRotation(ui->cursorActor,0);
        CLACT_SetActorDrawEnable(ui->cursorActor,1);
        if (ui->bgSetup.bgLayer<4) paletteRam=(u16 *)((u32)CLACT_GetPaletteVramAddress(ui->paletteHandle,ui->screenId)+HW_OBJ_PLTT);
        else paletteRam=(u16 *)((u32)CLACT_GetPaletteVramAddress(ui->paletteHandle,ui->screenId)+HW_DB_OBJ_PLTT);
        for(i=0;i<16;i++) paletteRam[i]=ui->palBlack[i];
        if (ui->bgSetup.bgLayer<4)
            G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR,0,(1<<(u8)ui->bgSetup.bgLayer)|(1<<(u8)ui->bgSetup.overlayLayer),2,12);
        else
            G2x_SetBlendAlpha_((void *)REG_DB_BLDCNT_ADDR,0,(1<<(u8)(ui->bgSetup.bgLayer-4))|(1<<(u8)(ui->bgSetup.overlayLayer-4)),2,12);
    } else CLACT_SetActorDrawEnable(ui->cursorActor,0);
}

void MYSTERY_ALBUM_StartIntro(MysteryAlbum *album) { if(MYSTERY_ALBUM_GetEntryKind(album)==1 && album->introPhase==0) { album->introPhase=1; album->introTick=0; } }

void MYSTERY_ALBUM_ResetIntro(MysteryAlbum *album)
{
    char *paletteRam;
    void (*setBlend)(int,int);
    if (MYSTERY_ALBUM_GetEntryKind(album)==1) {
        album->introPhase=0;
        album->introTick=0;
        CLACT_SetActorBgPriority(album->ui->cursorActor,album->ui->idleAnimId);
        if (album->ui->isMainScreen) {
            paletteRam=(char *)(CLACT_GetPaletteVramAddress(album->ui->paletteHandle,album->ui->screenId)+HW_OBJ_PLTT);
            setBlend=MYSTERY_ALBUM_SetBlendMain;
        } else {
            paletteRam=(char *)(CLACT_GetPaletteVramAddress(album->ui->paletteHandle,album->ui->screenId)+HW_DB_OBJ_PLTT);
            setBlend=MYSTERY_ALBUM_SetBlendSub;
        }
        setBlend(2,12);
        MIi_CpuClear16(0,album->ui->palBlack,32);
        MIi_CpuCopy16(album->ui->palBlack,paletteRam,32);
    }
}

int MYSTERY_ALBUM_IsIntroIdle(MysteryAlbum *album)
{
    if (album->introPhase==0) return 1;
    return 0;
}

void MYSTERY_ALBUM_SetupTask(struct TcbTask *unused,void *work)
{
    MysteryAlbum *album=work;
    if (album->isSetupDone) return;
    album->isSetupDone=1;
    switch (album->setupMode) {
    case 0: MYSTERY_ALBUM_LoadBgWithTilemap(&album->ui->bgSetup,album,album->heapId); break;
    case 1: MYSTERY_ALBUM_LoadBgPalette(&album->ui->bgSetup,album,album->heapId); break;
    }
    MYSTERY_ALBUM_SetupIcons(album,album->ui,album->heapId);
    MYSTERY_UTIL_CopyBmpList(album->cardView);
    MYSTERY_UTIL_TransferWindowList(album->ui->albumData);
    BG_SYS_SetPlaneVisible((u8)(album->ui->backPlane),(int)1);
    BG_SYS_SetPlaneVisible((u8)(album->ui->frontPlane),(int)1);
}

void MYSTERY_ALBUM_RequestSetup(MysteryAlbum *album,u32 mode) { album->setupMode=mode; if(album->setupTask==0) album->setupTask=GFL_USE_AddMainTask(MYSTERY_ALBUM_SetupTask,album,0); else album->isSetupDone=0; }

void MYSTERY_ALBUM_HideScreen(MysteryAlbumUi *ui)
{
    struct ClactVec2 cursorPos;
    BG_SYS_ClearSlot(4);
    BG_SYS_PushTile(4);
    CLACT_SetActorDrawEnable(ui->iconActor,0);
    cursorPos.x=184;
    cursorPos.y=112;
    CLACT_AddActorSurfacePos(ui->cursorActor, (const struct ClactVec2 *)&cursorPos, ui->screenId);
    CLACT_SetActorDrawEnable(ui->cursorActor,0);
    BG_SYS_SetPlaneVisible(6,0);
}

/*
 * note pass 2 2026-10-06 P2L16: closed from 7/44. The function returns void (the only
 *   caller, ov121 021DD9CC, declares it void) and the +0 halfword is a direct copy
 *   `*(u16 *)p = *(u16 *)(p+2)` at its store position; the scheduler hoists the ldrh.
 *   The 11 store after the two b stores gives the image colours (b r7, c r4, d r6).
 *   The earlier u16 t local and return form stayed at 7 for every variant.
 */
void MYSTERY_ALBUM_PathAnimInit(MysteryAlbumPathAnim *anim,u16 frameId,int x,int y)
{
    MI_CpuFill8(anim,0,44);
    anim->prevFrameId=frameId;
    anim->nextFrameId=frameId;
    anim->waypointCount=11;
    anim->startX=x;
    anim->startY=y;
    anim->target.x=x;
    anim->target.y=y;
    anim->frameId=anim->prevFrameId;
    anim->current.x=x;
    anim->current.y=y;
}

#pragma opt_propagation off

/*
 * prior-checks: 1 runtime quotient helpers take two full-word arguments; no residual call setup; 2 ov121 search found no interpolation twin; 3 const char table reduced 13 to 9 bytes, MysteryAlbumPathAnim mutable and widths decoded from loads; 4 aggregate/cast/struct-copy idioms did not resolve residue; 5 fresh directory and ov121/ov122 neighbours reread, no stack aggregate residue.
 * pass 3 2026-10-06 P3L10: EXACT. The direction table is read through a named const table pointer
 *   assigned after x = p->target.x and before the startx store, under opt_propagation off, with the
 *   direction table extern declared const. The live table pointer holds r1 at the startx store, so x
 *   takes r2 and the index*8 shift waits for the store. Non-const table or pointer: 8 B; no pointer: 9 B.
 *   (Earlier attempt logs, 40+ compiles that stayed at 9 B, were removed from this comment.)
 * division: explicit runtime quotient preserves admitted zero-delta division.
 */
int MYSTERY_ALBUM_PathAnimStep(MysteryAlbumPathAnim *anim, u16 *outFrameId, MysteryAlbumPathPoint *outPosition)
{
    int result = 0;
    switch (anim->phase) {
    case 0: {
        const s8 *directionTable;
        int x;
        anim->frame = 0;
        anim->prevFrameId = anim->nextFrameId;
        anim->nextFrameId = MYSTERY_ALBUM_PathFrameIds[anim->waypointIndex];
        x = anim->target.x;
        directionTable = MYSTERY_ALBUM_PathDirections;
        anim->startX = x;
        anim->direction = directionTable[anim->waypointIndex];
        anim->durationFrames = MYSTERY_ALBUM_PathDurations[anim->waypointIndex];
        anim->startY = anim->target.y;
        anim->target = MYSTERY_ALBUM_PathWaypoints[anim->waypointIndex];
        if (anim->direction > 0) {
            anim->prevFrameId = anim->prevFrameId == 0xffff ? 0 : anim->prevFrameId;
            anim->nextFrameId = anim->nextFrameId == 0 ? 0xffff : anim->nextFrameId;
        } else {
            anim->prevFrameId = anim->prevFrameId == 0 ? 0xffff : anim->prevFrameId;
            anim->nextFrameId = anim->nextFrameId == 0xffff ? 0 : anim->nextFrameId;
        }
        anim->phase++;
        break;
    }
    case 1: {
        int startX = anim->startX;
        int deltaX = anim->target.x - startX;
        int sign = (deltaX < 0 ? -deltaX : deltaX) / deltaX;
        int startY, deltaY;
        if (deltaX < 0) deltaX = -deltaX;
        anim->current.x = startX + sign * ((u32)(anim->frame * deltaX) / anim->durationFrames);
        startY = anim->startY;
        deltaY = anim->target.y - startY;
        if (deltaY < 0) deltaY = -deltaY;
        anim->current.y = startY + sign * ((u32)(anim->frame * deltaY) / anim->durationFrames);
        if (anim->frame++ >= anim->durationFrames) {
            anim->frameId = anim->nextFrameId;
            anim->current = anim->target;
            anim->phase++;
        }
        break;
    }
    case 2:
        anim->waypointIndex++;
        if (anim->waypointIndex < anim->waypointCount) anim->phase = 0;
        else anim->phase++;
        break;
    case 3:
        result = 1;
        break;
    }
    if (outFrameId) *outFrameId = anim->frameId;
    if (outPosition) *outPosition = anim->current;
    return result;
}
