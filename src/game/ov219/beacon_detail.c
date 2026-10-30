/*
 * file:     beacon_detail.c
 * unit:     yes
 * function: BEACON_DETAIL_Init, BEACON_DETAIL_Main, BEACON_DETAIL_WinActivate, BEACON_DETAIL_WinUpdate, BEACON_DETAIL_Update, BEACON_DETAIL_Exit, BEACON_DETAIL_InitVram, BEACON_DETAIL_InitGraphics, BEACON_DETAIL_ExitGraphics, BEACON_DETAIL_LoadRecords, BEACON_DETAIL_SetRecord, BEACON_DETAIL_MarkCurrentRecord, BEACON_DETAIL_GetRecordIndex, BEACON_DETAIL_ReadTouchInput, BEACON_DETAIL_CalcTouchDelta, BEACON_DETAIL_CreateBmpWin, BEACON_DETAIL_InitMainScreen, BEACON_DETAIL_CreateTaskMenu, BEACON_DETAIL_CreateTaskMenuWin, BEACON_DETAIL_DeleteTaskMenuWin, BEACON_DETAIL_DeleteMainScreen, BEACON_DETAIL_DrawTextRecord, BEACON_DETAIL_PrintMessage, BEACON_DETAIL_OnMessageDone, BEACON_DETAIL_CreateMenuList, BEACON_DETAIL_SetupMenuList, BEACON_DETAIL_CreateMenuItems, BEACON_DETAIL_CreateMenuItemsFromIds, BEACON_DETAIL_CloseMenu, BEACON_DETAIL_DrawCurrentArea, BEACON_DETAIL_DrawEntryDetail, BEACON_DETAIL_CloseDetailWin, BEACON_DETAIL_FindNearestRecord, BEACON_DETAIL_DrawCurrentInfo, BEACON_DETAIL_Create3DObjects, BEACON_DETAIL_Delete3DObjects, BEACON_DETAIL_Init3DParams, BEACON_DETAIL_CreateCamera, BEACON_DETAIL_SetupCamera, BEACON_DETAIL_CreateLight, BEACON_DETAIL_SetupCalc, BEACON_DETAIL_SetupRecordCalc, BEACON_DETAIL_MoveCursor, BEACON_DETAIL_UpdateCamera, BEACON_DETAIL_Draw3D, BEACON_DETAIL_GetEntryText, BEACON_DETAIL_HasEntry, BEACON_DETAIL_WrapAngle, BEACON_DETAIL_CalcDistance
 * address:  0x02183B60
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   WIFI_HISTORY_GetBlock 0x02009470 thumb
 *   GAME_LANGUAGE_Code 0x0209DF0C data a1
 *   MYSTATUS_GetNation 0x0200856C thumb
 *   MYSTATUS_GetArea 0x02008570 thumb
 *   WIFI_HISTORY_GetMode 0x02009524 thumb
 *   WORDSET_Create 0x0201EC74 thumb
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   TCBL_Create 0x0203101C arm
 *   APP_KEYCURSOR_CreateDefault 0x02028590 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetCont 0x0203630C arm
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_MENULIST_Main 0x020200CC thumb
 *   BMP_MENU_CreateYesNo 0x0201FDA0 thumb
 *   BMP_MENU_ProcessYesNo 0x0201FEBC thumb
 *   NATION_AREA_GetDefaultNation 0x02025BE8 thumb
 *   NATION_AREA_GetAreaTable 0x02025C44 thumb
 *   NATION_AREA_GetAreaMsgBank 0x02025B94 thumb
 *   WIFI_HISTORY_InitLanguageRegion 0x0200947C thumb
 *   GAME_BEACON_SetNationArea 0x02027120 thumb
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   d_02185DE6 0x02185DE6 data a1
 *   d_02185DB6 0x02185DB6 data ov219 a1
 *   d_02185E98 0x02185E98 data ov219 a4
 *   d_02185E28 0x02185E28 data ov219 a4
 *   d_02185DB0 0x02185DB0 data ov219 a1
 *   d_02185DC4 0x02185DC4 data ov219 a1
 *   d_02185ECC 0x02185ECC data ov219 a4
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GX_SetBankForLCDC 0x0208068C arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   GX_DisableBankForLCDC 0x02080B98 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   d_02185F4C 0x02185F4C data ov219 a4
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   BG_SYS_EnableBg0WithPriority 0x0204044C arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   d_02185F18 0x02185F18 data ov219 a4
 *   BMP_WIN_Exit  0x020450C8  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   ARC_UTIL_LoadHandleMemberWithSize 0x0204A39C arm
 *   _u32_div_f 0x0209C2B0 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   NATION_AREA_GetNationRecordCount 0x02025B38 thumb
 *   NATION_AREA_GetAreaListArcMember 0x02025BD0 thumb
 *   NATION_AREA_GetNationIdByIndex 0x02025BB8 thumb
 *   d_02185F28 0x02185F28 data a4
 *   WIFI_HISTORY_GetCountryRegionState 0x0200949C thumb
 *   NATION_AREA_FindRecordIndex 0x02025B3C thumb
 *   d_02185E00 0x02185E00 data a4
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   GF_FONT_GetTextColor 0x0201DE00 thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   BG_SYS_LoadPlttEntry 0x02040EBC arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   d_02185E58 0x02185E58 data a4
 *   d_02185E78 0x02185E78 data a4
 *   d_02185DBD 0x02185DBD data a1
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   APP_TASKMENU_WIN_Create 0x02027FEC thumb
 *   d_02185E40 0x02185E40 data ov219 a4
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   GF_FONT_GetLineHeight 0x0201DC80 thumb
 *   BMP_MENULIST_Create 0x0201FF30 thumb
 *   BMP_MENULIST_ResetCursorTile 0x02020CF8 thumb
 *   d_02185F7C 0x02185F7C data a4
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_MENULIST_Delete 0x0202020C thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   WORDSET_SetSlotFromMsgE7 0x0201F048 thumb
 *   WORDSET_SetSlotFromKeyedMessage 0x0201F094 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   d_02185DCB 0x02185DCB data ov219 a1
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   G3D_SYSTEM_CreateResourceArc 0x02046DB8 arm
 *   G3D_SYSTEM_TransVramTexture 0x02046FF8 arm
 *   G3D_SYSTEM_CreateRender 0x02047400 arm
 *   G3D_SYSTEM_CreateObject 0x0204767C arm
 *   d_02185E18 0x02185E18 data a2
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_LIGHT_DeleteSlots 0x02048C4C arm
 *   G3D_SYSTEM_DeleteObject 0x02047738 arm
 *   G3D_SYSTEM_DeleteRender 0x02047504 arm
 *   G3D_SYSTEM_FreeVramTexture 0x020470D0 arm
 *   G3D_SYSTEM_DeleteResource 0x02046EFC arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   d_02185F00 0x02185F00 data a4
 *   d_02185E0C 0x02185E0C data a4
 *   d_02185DF4 0x02185DF4 data a4
 *   d_020A1EB8 0x020A1EB8 data a4
 *   G3D_CAMERA_SetEye 0x02048AFC arm
 *   G3D_CAMERA_SetCamTarget 0x02048B44 arm
 *   G3D_CAMERA_SetFovySin 0x02048B80 arm
 *   G3D_CAMERA_SetFovyCos 0x02048B94 arm
 *   G3D_CAMERA_SetNear 0x02048B60 arm
 *   G3D_CAMERA_SetFar 0x02048B6C arm
 *   d_020A1C78 0x020A1C78 data
 *   G3D_LIGHT_CreateSlots 0x02048BC4 arm
 *   G3D_LIGHT_ApplySlots 0x02048C58 arm
 *   d_02185DD4    0x02185DD4 data ov219
 *   MTX_RotY33_ 0x0207AF1C thumb
 *   MTX_RotX33_ 0x0207AF00 thumb
 *   MTX_RotZ33_ 0x0207AF38 thumb
 *   MTX_Concat33 0x0207B388 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   G3D_CAMERA_GetEye 0x02048AE8 arm
 *   G3D_CAMERA_GetCamTarget 0x02048B30 arm
 *   VEC_Subtract 0x0207CA00 arm
 *   VEC_Mag 0x0207CBD0 arm
 *   VEC_Normalize 0x0207CCA4 arm
 *   VEC_MultAdd 0x0207CEE4 arm
 *   G3D_SYSTEM_DrawStart  0x02047964  arm
 *   G3D_SYSTEM_DrawEnd  0x02047970  arm
 *   G3D_SYSTEM_ApplyLookAt  0x020479D8  arm
 *   MTX_Identity33_  0x0207ADC4  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 *   NATION_AREA_GetAreaMsgBankByIndex 0x02025BA0 thumb
 *   FX_Sqrt  0x0207C7B4  arm  arm9
 *   GF_STANDARD_DegToAngle  0x0203F734  arm  arm9
 */

struct Big;
struct Sub0200852CObj;
struct Sub02009470Obj;
struct Tcbl;
struct Proc;
struct WordSet;
struct PrintQueue;
struct BmpMenuList;
struct BeaconDetailMenuTemplate;
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct Rec;
struct S02031140;
struct Proc;
struct BeaconLightCfg;
struct GfFont;
struct TaskMenuRes;
struct TaskMenuState;
struct Strbuf;
struct Ctx;
struct Rec3;
struct Font;
struct Slot;
struct Tagged;
struct Light;
struct LightSet;
struct LightSlot;
struct Arg;
#include "../arm9/arc_tool.h"
#include "../sdk_ioreg.h"
#include "../arm9/arc_util.h"
#include "../arm9/bmp_menu.h"
#include "../arm9/bmp_menulist.h"
#include "../types.h"
#include "../version.h"

/* The globe starts turned toward the cartridge's home region. */
#if LANGUAGE == LANGUAGE_JAPANESE
#define BEACON_DETAIL_START_ANGLE_X 0x1980
#define BEACON_DETAIL_START_ANGLE_Y 0xCFE0
#elif LANGUAGE == LANGUAGE_FRENCH
#define BEACON_DETAIL_START_ANGLE_X 0x2300
#define BEACON_DETAIL_START_ANGLE_Y 0x3100
#elif LANGUAGE == LANGUAGE_GERMAN
#define BEACON_DETAIL_START_ANGLE_X 0x2580
#define BEACON_DETAIL_START_ANGLE_Y 0x2A00
#elif LANGUAGE == LANGUAGE_ITALIAN
#define BEACON_DETAIL_START_ANGLE_X 0x1DE0
#define BEACON_DETAIL_START_ANGLE_Y 0x2A00
#elif LANGUAGE == LANGUAGE_SPANISH
#define BEACON_DETAIL_START_ANGLE_X 0x1CA0
#define BEACON_DETAIL_START_ANGLE_Y 0x35E0
#else
#define BEACON_DETAIL_START_ANGLE_X 0x1A40
#define BEACON_DETAIL_START_ANGLE_Y 0x7C00
#endif

union MtxFx33;
union TouchHitTable;
struct BmpMenuWork;
struct VecFx32;
#include "../arm9/g3d_camera.h"
#include "../arm9/bg_sys_types.h"

#include "../sdk_gx.h"

typedef struct {int words[9];} Matrix;

struct BeaconWinLayout {unsigned x,y,z;};

#include "../arm9/bmp_menulist_types.h"
struct BeaconDetailMenuTemplate {struct BmpMenuListTemplate t;};

typedef struct {u32 bank,id;} BeaconMenuItem;

typedef struct {const void *str;unsigned param;} BeaconMenuWork;

typedef struct {u16 index,member;} BeaconRowRef;

typedef struct {unsigned x,y,z;} BeaconVec3;

typedef struct {BeaconVec3 vec;short x,y;} BeaconCameraCfg;

typedef struct {char pad[0x30]; short a, b;} BeaconLightCfg;

typedef struct {long x,y,z;} BeaconDetailVec;

typedef struct { int x, y, z; } V3;

typedef struct { V3 a; V3 b; } BeaconDetailPair;

typedef struct { int m[9]; } M33;

/* One 0x30-byte beacon entry in BeaconDetailWork.records. */
typedef struct {
    short x;
    short y;
    Matrix matrix;
    u16 state;
    u16 a;
    u16 b;
    u16 pad;
} BeaconRecord;

/* A bmp window plus its drawn flag, at 0xC020/0xC02C/0xC038/0xC044/0xC078. */
typedef struct {
    void *bmp;
    u8 active;
} BeaconMessage;

/* One 12-byte APP_TASKMENU_WIN descriptor at 0xC08C/0xC098. */
typedef struct {
    void *text;
    u16 tag;
    u16 pad;
    u32 value;
} BeaconTaskMenuWin;

typedef struct TaskMenuRes *TaskMenuResRef;
typedef struct GfFont *FontRef;
typedef struct MsgBank *MsgBankRef;
typedef struct PrintQueue *PrintQueRef;
typedef struct KeyCursor *KeyCursorRef;

/* The 0xC3BC-byte beacon detail screen work area. */
typedef struct {
    u32 heapId;                  /* 0x0000 */
    void *ctx;                   /* 0x0004 */
    void *saveCtl;               /* 0x0008 */
    void *sub0852C;              /* 0x000C */
    void *sub09470;              /* 0x0010 */
    u32 recordCount;             /* 0x0014 */
    BeaconRecord records[1024];  /* 0x0018 */
    void *bmp18;                 /* 0xC018 */
    void *bmp1C;                 /* 0xC01C */
    BeaconMessage msg20;         /* 0xC020 */
    u32 padC028;                 /* 0xC028 */
    BeaconMessage msg2C;         /* 0xC02C */
    u32 padC034;                 /* 0xC034 */
    BeaconMessage msg38;         /* 0xC038 */
    void *bmp40;                 /* 0xC040 */
    BeaconMessage msg44;         /* 0xC044 */
    void *menuList;              /* 0xC04C */
    void *menuWork;              /* 0xC050 */
    void *yesNo;                 /* 0xC054 */
    TaskMenuResRef taskMenu;     /* 0xC058 */
    void *win[2];                /* 0xC05C */
    void *strbufA;               /* 0xC064 */
    void *strbufB;               /* 0xC068 */
    FontRef font;                /* 0xC06C */
    MsgBankRef msgBank;          /* 0xC070 */
    struct TextPrinter *printHandle;             /* 0xC074 */
    BeaconMessage msg78;         /* 0xC078 */
    PrintQueRef printQue;        /* 0xC080 */
    u8 textColorR;               /* 0xC084 */
    u8 textColorG;               /* 0xC085 */
    u8 textColorB;               /* 0xC086 */
    u8 padC087;                  /* 0xC087 */
    KeyCursorRef keyCursor;      /* 0xC088 */
    BeaconTaskMenuWin winData[2];/* 0xC08C */
    void *tcbl;                  /* 0xC0A4 */
    void *wordSet;               /* 0xC0A8 */
    void *printBuf;              /* 0xC0AC */
    u32 printState;              /* 0xC0B0 */
    u8 padC0B4[0x228];           /* 0xC0B4 */
    V3 light0;                   /* 0xC2DC */
    V3 light1;                   /* 0xC2E8 */
    union {                      /* 0xC2F4 light/rotation triple */
        struct { int angleX; int angleY; int angleZ; };
        int angles[3];
    };
    V3 light2;                   /* 0xC300 */
    u16 zoomMode;                /* 0xC30C */
    u16 padC30E;                 /* 0xC30E */
    u32 drawState;               /* 0xC310 */
    u32 wipeState;               /* 0xC314 */
    u32 japaneseFlag;            /* 0xC318 */
    u16 viewMode;                /* 0xC31C */
    u16 padC31E;                 /* 0xC31E */
    u32 inputFlag;               /* 0xC320 */
    int touchPhase;              /* 0xC324 */
    int dragStartX;              /* 0xC328 */
    int dragStartY;              /* 0xC32C */
    int moveX;                   /* 0xC330 */
    int moveY;                   /* 0xC334 */
    int touchTimer;              /* 0xC338 */
    u32 nation;                  /* 0xC33C */
    u32 area;                    /* 0xC340 */
    u32 selNation;               /* 0xC344 */
    u32 selArea;                 /* 0xC348 */
    u32 sub09470State;           /* 0xC34C */
    u32 detailOpen;              /* 0xC350 */
    u32 keyTrg;                  /* 0xC354 */
    u32 keyCont;                 /* 0xC358 */
    u32 touchTrg;                /* 0xC35C */
    int touchHit;                /* 0xC360 */
    int lastTouchX;              /* 0xC364 */
    int lastTouchY;              /* 0xC368 */
    void *camera;                /* 0xC36C */
    void *lightSet;              /* 0xC370 */
    void *resArc[6];             /* 0xC374 */
    void *render[6];             /* 0xC38C */
    void *object[6];             /* 0xC3A4 */
} BeaconDetailWork;

#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
struct GameData;
struct SaveControl;
#include "../arm9/game_data.h"
struct MyStatus;
struct WifiHistory;
#include "../arm9/mystatus.h"
#include "../arm9/wordset.h"
extern void BG_SYS_SetLcdSwap(u32);
struct TcblSystem;
#include "../arm9/tcbl.h"
struct KeyCursor;
#include "../arm9/app_keycursor.h"
struct PrintQueue;
#include "../arm9/printsys.h"
#include "../arm9/net.h"
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
struct TaskMenuWin;
#include "../arm9/app_taskmenu.h"
#include "../arm9/key.h"
extern int TOUCHPANEL_HitCont(const union TouchHitTable *a);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int TOUCHPANEL_GetTrg(void);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
/* The DS code was built against other parameter widths for MSGDATA_CreateFromArchive (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
#define MSGDATA_CreateFromArchive MSGDATA_CreateFromArchive_header
#endif
#include "../arm9/msgdata.h"
#ifdef __MWERKS__
#undef MSGDATA_CreateFromArchive
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u16 fileId, u16 heapId);
#endif
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
struct Bmp;
#include "../arm9/bmp.h"
struct BmpWin;
#include "../arm9/bmp_win.h"
#include "../arm9/wipe.h"
struct BmpMenuList;
#include "../arm9/bmp_oam.h"
/* The DS code was built against other parameter widths for WIFI_HISTORY_InitLanguageRegion (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
#define WIFI_HISTORY_InitLanguageRegion WIFI_HISTORY_InitLanguageRegion_header
#endif
#include "../arm9/wifi_history.h"
#ifdef __MWERKS__
#undef WIFI_HISTORY_InitLanguageRegion
extern void WIFI_HISTORY_InitLanguageRegion(struct WifiHistory *a, struct MyStatus *b, u32 c, u32 d);
#endif
#include "../arm9/game_beacon.h"
#include "../arm9/gfl_use.h"
extern void BEACON_DETAIL_ExitGraphics(int),PROCSYS_FreeProcWork(struct Proc *),GFL_HEAP_DeleteChecked(unsigned int);
extern void GX_SetBankForLCDC(unsigned),MIi_CpuClearFast(unsigned,void *,unsigned),GX_DisableBankForLCDC(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void BG_SYS_Create(unsigned),BG_SYS_SetGraphicsMode(struct DispConfig *);
/* The DS code was built against other parameter widths for G3D_SYSTEM_Init (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
#define G3D_SYSTEM_Init G3D_SYSTEM_Init_header
#endif
#include "../arm9/g3d_system.h"
#ifdef __MWERKS__
#undef G3D_SYSTEM_Init
extern void G3D_SYSTEM_Init(unsigned,unsigned,unsigned,unsigned,u16,unsigned,void (*)(void));
#endif
extern void BG_SYS_EnableBg0WithPriority(unsigned),BMP_WIN_Init(unsigned),BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_Delete(void);
#include "../arm9/gfl_heap_wrap.h"
extern u32 NATION_AREA_GetAreaListArcMember(u32),NATION_AREA_GetNationIdByIndex(u32);
extern int TOUCHPANEL_HitTrg(const union TouchHitTable *);
#include "../arm9/gf_font.h"
extern void GF_FONT_GetTextColor(u8 *,u8 *,u8 *),GF_FONT_SetTextColor(u32,u32,u32);
extern void BG_SYS_InitBgLayer(u32,const struct BgTemplate *,u32),BG_SYS_ClearSlot(u32);
#include "../arm9/bmp_menuwork.h"
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
extern void BG_SYS_LoadPlttEntry(u32,u32);
struct Strbuf;
struct GFont;
struct TaskMenuItem;
extern void BG_SYS_MarkTileDirty(u32);
extern void BG_SYS_FreeLayerBuf(unsigned);
#include "../arm9/strbuf.h"
#include "../arm9/msg_speed.h"
struct TextPrinter;
struct TextPrinter;
struct BeaconDetailMenuTemplate;
extern void WORDSET_SetSlotFromMsgE7(struct WordSet *,unsigned,unsigned),WORDSET_SetSlotFromKeyedMessage(struct WordSet *,unsigned,unsigned,unsigned);
struct G3dResource;
#include "../arm9/g3d_light.h"
struct G3dObject;
struct G3dRender;
struct G3dCamera;
struct LightSetDesc;
struct LightSlotValue;
extern void MTX_RotY33_(Matrix *,int,int),MTX_RotX33_(Matrix *,int,int),MTX_RotZ33_(Matrix *,int,int);
extern void MTX_Concat33(const union MtxFx33 *,const union MtxFx33 *,union MtxFx33 *);
extern void VEC_Subtract(const BeaconDetailVec *,const BeaconDetailVec *,BeaconDetailVec *),VEC_Normalize(const BeaconDetailVec *,BeaconDetailVec *),VEC_MultAdd(long,const BeaconDetailVec *,const BeaconDetailVec *,BeaconDetailVec *);
extern long VEC_Mag(const struct VecFx32 *);
extern void MTX_Identity33_(M33 *);
struct G3dObjectStatus;
extern unsigned BEACON_DETAIL_GetRecordIndex(unsigned),NATION_AREA_GetAreaMsgBankByIndex(unsigned);
#include "../arm9/gf_standard.h"
#include "../arm9/fx_cp.h"
int BEACON_DETAIL_Init(void *obj,void *unused,void *ctx);
int BEACON_DETAIL_Main(void *unused, char *state, int unused2, char *ctx);
void BEACON_DETAIL_WinActivate(u8 *p,u32 i);
void BEACON_DETAIL_WinUpdate(u8 *p);
int BEACON_DETAIL_Update(u8 *p, int *state);
int BEACON_DETAIL_Exit(struct Proc *controller,void *unused1,void *unused2,char *p);
void BEACON_DETAIL_InitVram(void);
void BEACON_DETAIL_InitGraphics(unsigned heap);
void BEACON_DETAIL_ExitGraphics(int a);
void BEACON_DETAIL_LoadRecords(char *p);
void BEACON_DETAIL_SetRecord(BeaconDetailWork *p,int index,int x,int y,u16 a,u16 b);
void BEACON_DETAIL_MarkCurrentRecord(BeaconDetailWork *p);
u32 BEACON_DETAIL_GetRecordIndex(u32 key);
void BEACON_DETAIL_ReadTouchInput(char *p);
void BEACON_DETAIL_CalcTouchDelta(const char *p,int x,int y,int *xflag,int *xdistance,int *yflag,int *ydistance);
struct Descriptor *BEACON_DETAIL_CreateBmpWin(const u8 *p,int flag);
void BEACON_DETAIL_InitMainScreen(char *p,void *arc);
void BEACON_DETAIL_CreateTaskMenu(char *p);
void BEACON_DETAIL_CreateTaskMenuWin(char *p,int i);
void BEACON_DETAIL_DeleteTaskMenuWin(u8 *p,u32 i);
void BEACON_DETAIL_DeleteMainScreen(char *p);
void BEACON_DETAIL_DrawTextRecord(char *p,BeaconMessage *out,struct Descriptor *d,void *text,u8 x,u8 y);
int BEACON_DETAIL_PrintMessage(char *p,u32 message,int force);
void BEACON_DETAIL_OnMessageDone(struct BmpMenuList *a, u32 b, void *c);
void BEACON_DETAIL_CreateMenuList(char *p,const unsigned char *descriptor,const struct BeaconDetailMenuTemplate *source,const BeaconMenuItem *entries);
void BEACON_DETAIL_SetupMenuList(char *p,const struct BeaconDetailMenuTemplate *source,unsigned count);
void BEACON_DETAIL_CreateMenuItems(u8 *p, const u8 *a, uptr b, u32 c);
void BEACON_DETAIL_CreateMenuItemsFromBank(u8 *p, const u8 *a, uptr b, u32 c);
void BEACON_DETAIL_CreateMenuItemsFromIds(char *p,const unsigned char *descriptor,const struct BeaconDetailMenuTemplate *cfg,unsigned file,const unsigned char *ids,unsigned count);
void BEACON_DETAIL_CloseMenu(u8*p);
void BEACON_DETAIL_DrawCurrentArea(char *p);
void BEACON_DETAIL_DrawEntryDetail(char *p,unsigned key,unsigned member);
void BEACON_DETAIL_CloseDetailWin(char *p);
int BEACON_DETAIL_FindNearestRecord(char *p, u32 *out);
void BEACON_DETAIL_DrawCurrentInfo(char *p);
void BEACON_DETAIL_Create3DObjects(char *p, void *arc);
void BEACON_DETAIL_Delete3DObjects(char *p);
void BEACON_DETAIL_Init3DParams(u8 *p);
void BEACON_DETAIL_CreateCamera(char *p);
void BEACON_DETAIL_SetupCamera(char *p);
void BEACON_DETAIL_CreateLight(char *p);
void BEACON_DETAIL_SetupCalc(Matrix *p,int *angles);
void BEACON_DETAIL_SetupRecordCalc(Matrix *p,int *angles);
int BEACON_DETAIL_MoveCursor(u8 *p, u32 a, u32 b);
int BEACON_DETAIL_UpdateCamera(char *p);
void BEACON_DETAIL_Draw3D(char *p);
int BEACON_DETAIL_GetEntryText(unsigned key,unsigned optional,void *first,void *second,unsigned heap);
int BEACON_DETAIL_HasEntry(int a);
void BEACON_DETAIL_WrapAngle(int *p);
int BEACON_DETAIL_CalcDistance(int *p, int *q);
extern const u8 GAME_LANGUAGE_Code;
extern const u8 d_02185DE6[];
extern const u8 d_02185DB6[];
extern const struct BeaconDetailMenuTemplate d_02185E98;
extern const u8 d_02185E28[];
extern const u8 d_02185DB0[];
extern const u8 d_02185DC4[];
extern const u8 d_02185ECC[];
extern const struct DispVram d_02185F4C;
extern const struct DispConfig d_02185F18;
extern const Matrix d_02185F28;
extern const char d_02185E00[];
extern const struct BgTemplate d_02185E58,d_02185E78;
extern const u8 d_02185DBD[];
extern const struct BeaconWinLayout d_02185E40[];
extern const u32 d_02185F7C[];
extern const unsigned char d_02185DCB[];
extern const BeaconRowRef d_02185E18[];
extern BeaconVec3 d_02185E0C;
extern BeaconVec3 d_02185DF4;
extern BeaconVec3 d_02185F00;
extern BeaconCameraCfg d_020A1EB8;
extern BeaconLightCfg d_020A1C78;
extern char d_02185DD4[];
extern short FX_SinCosTable_[];

int BEACON_DETAIL_Init(void *obj,void *unused,void *ctx)
{
    char *p;
    GFL_HEAP_CreateChildHeap((uptr)((void *)1),0x7c,0x80000);
    p=PROCSYS_AllocProcWork(obj,sizeof(BeaconDetailWork),0x7c);
    MI_CpuFill8(p,0,sizeof(BeaconDetailWork));
    ((BeaconDetailWork *)p)->heapId=0x7c;
    ((BeaconDetailWork *)p)->ctx=ctx;
    ((BeaconDetailWork *)p)->saveCtl=GAME_DATA_GetSaveControl(ctx);
    ((BeaconDetailWork *)p)->sub0852C=GAME_DATA_GetMyStatus(((BeaconDetailWork *)p)->ctx);
    ((BeaconDetailWork *)p)->sub09470=WIFI_HISTORY_GetBlock(((BeaconDetailWork *)p)->saveCtl);
    if(GAME_LANGUAGE_Code==1)((BeaconDetailWork *)p)->japaneseFlag=1;
    else ((BeaconDetailWork *)p)->japaneseFlag=0;
    ((BeaconDetailWork *)p)->nation=MYSTATUS_GetNation(((BeaconDetailWork *)p)->sub0852C);
    ((BeaconDetailWork *)p)->area=MYSTATUS_GetArea(((BeaconDetailWork *)p)->sub0852C);
    ((BeaconDetailWork *)p)->sub09470State=WIFI_HISTORY_GetMode(((BeaconDetailWork *)p)->sub09470);
    ((BeaconDetailWork *)p)->win[0]=0;
    ((BeaconDetailWork *)p)->win[1]=0;
    BEACON_DETAIL_InitVram();
    BEACON_DETAIL_InitGraphics((u16)(((BeaconDetailWork *)p)->heapId));
    ((BeaconDetailWork *)p)->wordSet=WORDSET_Create(8,0x40,((BeaconDetailWork *)p)->heapId);
    ((BeaconDetailWork *)p)->drawState=0;
    BG_SYS_SetLcdSwap(0);
    ((BeaconDetailWork *)p)->tcbl=TCBL_Create((u16)(((BeaconDetailWork *)p)->heapId),((BeaconDetailWork *)p)->heapId,0x20,0x20);
    ((BeaconDetailWork *)p)->keyCursor=APP_KEYCURSOR_CreateDefault(0xf,1,0,((BeaconDetailWork *)p)->heapId);
    ((BeaconDetailWork *)p)->printQue=PRINTSYS_QUE_Create((unsigned int)(u16)((BeaconDetailWork *)p)->heapId);
    GFL_NET_RefreshWmIconAtTopRight(1,(u16)(((BeaconDetailWork *)p)->heapId));
    BG_SYS_SetSubPlaneVisible(0x10,1);
    BEACON_DETAIL_LoadRecords(p);
    return 1;
}

int BEACON_DETAIL_Main(void *unused, char *state, int unused2, char *ctx)
{
    int result;
    TCBL_Main(((BeaconDetailWork *)ctx)->tcbl);
    result = BEACON_DETAIL_Update((u8 *)ctx, (int *)state);
    if (((BeaconDetailWork *)ctx)->object[0] != 0)
        BEACON_DETAIL_Draw3D(ctx);
    BEACON_DETAIL_WinUpdate((u8 *)ctx);
    PRINTSYS_QUE_Main(((BeaconDetailWork *)ctx)->printQue);
    return result;
}

void BEACON_DETAIL_WinActivate(u8 *p,u32 i){if(((BeaconDetailWork *)p)->win[i]){if(i==0){APP_TASKMENU_WIN_SetActive(((BeaconDetailWork *)p)->win[0],1);return;}if(i==1)APP_TASKMENU_WIN_SetDecide(((BeaconDetailWork *)p)->win[1],1);}}

void BEACON_DETAIL_WinUpdate(u8 *p){if(((BeaconDetailWork *)p)->win[0])APP_TASKMENU_WIN_Update(((BeaconDetailWork *)p)->win[0]);if(((BeaconDetailWork *)p)->win[1])APP_TASKMENU_WIN_Update(((BeaconDetailWork *)p)->win[1]);}

static inline void close_win(u8 *p, BeaconMessage *msg)
{
    void *win = ((BeaconDetailWork *)p)->printQue;
    if (msg->active != 0 && (int)PRINTSYS_QUE_IsExistTarget(win, BMP_WIN_GetBmp(msg->bmp)) == 0) {
        BMP_WIN_TransferChars(msg->bmp);
        msg->active = 0;
    }
}

/*
 * note:     2026-10-04 wave D3 lane 04: complete draft, same size (1884 bytes). The
 *           remaining residue is cross-jump (tail merge) direction only. In the original
 *           every "*state = X; SE(0x54C); break" tail (case 4 arms, case 9, case 17) jumps
 *           into the case 12 copy at 0x218400C, and the 0x551 tails jump into the case 9
 *           copy at 0x2183F8E. Natural C keeps the FIRST copy (case 4) instead. The draft
 *           uses gotos (n = X; goto snd54c / snd551) in case 4, which fixes case 4, but the
 *           case 9 0x54C tail still stays a full copy (case 12 then jumps to it); a goto in
 *           case 9 too lets the compiler thread the 0xA arm past the hop at 0x2183F8A.
 *           Tried: inner switch arm orders (case 0/default first, last, split), case 9 with
 *           SE in each arm, reversed outer case order (layout follows source, worse).
 *           Found and fixed: switch value u32 (compare tree, 0xFFFFFFFE case), switch on
 *           BMP_MENU_ProcessYesNo result cast to u32 in cases 6 and 15, case 19 written before
 *           case 18 (original block order), stack locals ids, count, tmp, old (int).
 *           d_02185xxx data words are sole references (MATCH at best once bytes agree).
 *           2026-10-05 wave D4 lane 08: still DIFF (84 lines, the draft above is unchanged). The original keeps
 *           ONE copy of `str r0,[r5]; ldr =0x54C; bl SE; b end` in case 12 (0x218400C) and every other 0x54C, 0x551,
 *           0x648, 0x649 tail jumps into it (case 17 to 0x218400E, 0x648/0x649 and case 9's 0x551 to the bl at
 *           0x2184010); case 9's arms join at a hop (0x2183F8A b 0x218400C), so case 9 had its own copy at threading
 *           time and lost it to cross-jumping later. Tried: case 9 arms `*state = X; goto se54c` (per arm, or one goto
 *           after the if) with a label on the SE call in case 12: case 12's label block then merges into case 17's
 *           copy instead (530 lines, worse). The survivor rule seems to drop the multi-predecessor label block.
 *           2026-10-05 wave D5 lane 05: unchanged DIFF (154 bytes, 84 lines). The original keeps case 12's
 *           copy for EVERY shared tail (0x54C store+call, the case 9 0x551 call, case 17), i.e. the LAST copy in
 *           source order, while every form here keeps the first. Tried: case 9 as an inner switch (default
 *           arm, case 0xFFFFFFFE arm): byte-identical output; fully natural C (no gotos): case 4 copies survive
 *           (381 bytes); case 9 arms `*state = X; goto se54c` plus case 17 `goto se54c` with se54c on the SE
 *           call in case 12: case 12 survives for 0x54C but case 9 arms skip the hop and case 12's call merges
 *           into case 9's 0x551 copy (291 bytes); case 9 arms `n = X; goto snd54c`: 6 bytes short (1004).
 *           2026-10-05 wave D6 lane 03: MATCH (0 concrete bytes differ). Two fixes. (1) Logic: the
 *           0x400 branches of case 17 test and set ((BeaconDetailWork *)p)->detailOpen, not ((BeaconDetailWork *)p)->nation (the pool word read is
 *           0xC350; the old draft differed by one pool slot only). (2) Tail shape: case 9 sets n in each
 *           arm, then `*state = n; goto se54c;` (one store after the join; cross-jumping later turns
 *           that join into the hop at 0x2183F8A); se54c sits on `m = 0x54C;` in case 12, followed by
 *           a `call:` label on `GFL_USE_PlaySeDefaultVolume(m)`; the case 9 0x551 path does `m = 0x551; goto call;`;
 *           case 17 writes `if (((BeaconDetailWork *)p)->detailOpen != 1) break; goto se54c;`. The 0x648/0x649 calls then
 *           merge into case 12's call by themselves. d_02185DE6 hint token dropped (contested).
 *           Remaining: three callees with no witness: arm9 NATION_AREA_GetDefaultNation and GAME_BEACON_SetNationArea and ov219
 *           BEACON_DETAIL_Init3DParams. This lane filed all three EXACT (src/matched/arm9/NATION_AREA_GetDefaultNation.c,
 *           src/matched/arm9/GAME_BEACON_SetNationArea.c, src/matched/ov/BEACON_DETAIL_Init3DParams.c); after the
 *           manifest picks them up this should verify EXACT.
 */
int BEACON_DETAIL_Update(u8 *p, int *state)
{
    int ret = 0;
    int n;
    u32 m;
    void *arc;
    u32 r;
#if LANGUAGE != LANGUAGE_JAPANESE
    u8 *ids;
    u32 count;
#endif
    u32 tmp;
    int old;
    u32 v;
    u32 w;

    ((BeaconDetailWork *)p)->keyTrg = KEY_GetTrg();
    ((BeaconDetailWork *)p)->keyCont = KEY_GetCont();
    if (TOUCHPANEL_HitCont((union TouchHitTable *)d_02185DE6) != -1) {
        ((BeaconDetailWork *)p)->touchHit = (int)TOUCHPANEL_GetPointCont((u32 *)&((BeaconDetailWork *)p)->lastTouchX, (u32 *)&((BeaconDetailWork *)p)->lastTouchY);
    } else {
        ((BeaconDetailWork *)p)->touchHit = 0;
    }
    if (((BeaconDetailWork *)p)->touchHit == 1) {
        ((BeaconDetailWork *)p)->touchTrg = TOUCHPANEL_GetTrg();
    } else {
        ((BeaconDetailWork *)p)->touchTrg = (int)TOUCHPANEL_GetPointTrg((u32 *)&((BeaconDetailWork *)p)->lastTouchX, (u32 *)&((BeaconDetailWork *)p)->lastTouchY);
    }
    switch (*state) {
    case 0:
        ((BeaconDetailWork *)p)->msgBank = MSGDATA_CreateFromArchive(0, 2, (u16)0xCF, (u16)((BeaconDetailWork *)p)->heapId);
        arc = ARC_TOOL_CreateHandle(0xC5, (u16)((BeaconDetailWork *)p)->heapId);
        BEACON_DETAIL_Create3DObjects((char *)p, arc);
        BEACON_DETAIL_InitMainScreen((char *)p, arc);
        ARC_TOOL_DeleteHandle(arc);
        ((BeaconDetailWork *)p)->wipeState = 0;
        WIPE_SYS_Start(0, (int)1, (int)1, (int)0, (int)6, (int)1, ((BeaconDetailWork *)p)->heapId);
        BG_SYS_SetPlaneVisible(6, 1);
        BG_SYS_SetPlaneVisible(2, 1);
        BG_SYS_SetPlaneVisible(7, 1);
        BG_SYS_SetPlaneVisible(3, 1);
        *state = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (BEACON_DETAIL_PrintMessage((char *)p, 0, 1) == 1) {
            if (((BeaconDetailWork *)p)->nation == 0) {
                *state = 3;
            } else {
                *state = 0x10;
            }
        }
        break;
    case 3:
        if (BEACON_DETAIL_PrintMessage((char *)p, 1, 1) == 1) {
            BEACON_DETAIL_CreateMenuList((char *)p, d_02185DB6, (const struct BeaconDetailMenuTemplate *)&d_02185E98, (const BeaconMenuItem *)d_02185E28);
            *state = 4;
        }
        break;
    case 4:
        if ((int)PRINTSYS_QUE_IsFinished(((BeaconDetailWork *)p)->printQue) == 0) {
            break;
        }
        r = BMP_MENULIST_Main(((BeaconDetailWork *)p)->menuList);
        if (r == -1) {
            break;
        }
        BEACON_DETAIL_CloseMenu(p);
        switch (r) {
        case 0:
        default:
            n = 0x10;
            goto snd54c;
        case 1:
            n = 5;
            goto snd54c;
        case 2:
        case 0xFFFFFFFE:
            n = 0x14;
            goto snd551;
        }
        break;
    case 5:
        if (BEACON_DETAIL_PrintMessage((char *)p, 2, 1) == 1) {
            ((BeaconDetailWork *)p)->yesNo = BMP_MENU_CreateYesNo((struct WinDat *)d_02185DB0, 0x22, 7, 0, ((BeaconDetailWork *)p)->heapId);
            *state = 6;
        }
        break;
    case 6:
        switch ((u32)(int)BMP_MENU_ProcessYesNo(((BeaconDetailWork *)p)->yesNo)) {
        case 0:
            if (((BeaconDetailWork *)p)->japaneseFlag == 1) {
                ((BeaconDetailWork *)p)->selNation = (u32)NATION_AREA_GetDefaultNation();
                *state = 0xA;
            } else {
                *state = 7;
            }
            break;
        case 0xFFFFFFFE:
            *state = 3;
            break;
        }
        break;
    case 7:
        ((BeaconDetailWork *)p)->selNation = 0;
        BEACON_DETAIL_CreateMenuItems(p, d_02185DC4, (uptr)d_02185ECC, 0xE7);
        *state = 8;
        break;
    case 8:
        if (BEACON_DETAIL_PrintMessage((char *)p, 3, 1) == 1) {
            *state = 9;
        }
        break;
    case 9:
        if ((int)PRINTSYS_QUE_IsFinished(((BeaconDetailWork *)p)->printQue) == 0) {
            break;
        }
        r = BMP_MENULIST_Main(((BeaconDetailWork *)p)->menuList);
        if (r == -1) {
            break;
        }
        BEACON_DETAIL_CloseMenu(p);
        if (r != -2) {
            ((BeaconDetailWork *)p)->selNation = r;
            if (BEACON_DETAIL_HasEntry(r) == 1) {
                n = 0xA;
            } else {
                ((BeaconDetailWork *)p)->selArea = 0;
                n = 0xD;
            }
            *state = n;
            goto se54c;
        } else {
            n = 3;
        snd551:
            *state = n;
            m = 0x551;
            goto call;
        }
        break;
    case 10:
        ((BeaconDetailWork *)p)->selArea = 0;
#if LANGUAGE == LANGUAGE_JAPANESE
        BEACON_DETAIL_CreateMenuItemsFromBank(p, d_02185DC4, (uptr)d_02185ECC, NATION_AREA_GetAreaMsgBank((u32)((BeaconDetailWork *)p)->selNation));
#else
        NATION_AREA_GetAreaTable((u32)((u32)((BeaconDetailWork *)p)->selNation), (u32 *)(&ids), &count);
        BEACON_DETAIL_CreateMenuItemsFromIds((char *)p, d_02185DC4, (const struct BeaconDetailMenuTemplate *)((const struct BeaconDetailMenuTemplate *)d_02185ECC), NATION_AREA_GetAreaMsgBank((u32)((u32)((BeaconDetailWork *)p)->selNation)), ids, count);
#endif
        *state = 0xB;
        break;
    case 11:
        if (BEACON_DETAIL_PrintMessage((char *)p, 4, 1) == 1) {
            *state = 0xC;
        }
        break;
    case 12:
        if ((int)PRINTSYS_QUE_IsFinished(((BeaconDetailWork *)p)->printQue) == 0) {
            break;
        }
        r = BMP_MENULIST_Main(((BeaconDetailWork *)p)->menuList);
        if (r == -1) {
            break;
        }
        BEACON_DETAIL_CloseMenu(p);
        if (r != -2) {
            ((BeaconDetailWork *)p)->selArea = r;
            n = 0xD;
        snd54c:
            *state = n;
        se54c:
            m = 0x54C;
        call:
            GFL_USE_PlaySeDefaultVolume(m);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x551);
            if (((BeaconDetailWork *)p)->japaneseFlag == 1) {
                *state = 3;
            } else {
                *state = 7;
            }
        }
        break;
    case 13:
        BEACON_DETAIL_DrawEntryDetail((char *)p, ((BeaconDetailWork *)p)->selNation, ((BeaconDetailWork *)p)->selArea);
        *state = 0xE;
        break;
    case 14:
        if (BEACON_DETAIL_PrintMessage((char *)p, 5, 1) == 1) {
            ((BeaconDetailWork *)p)->yesNo = BMP_MENU_CreateYesNo((struct WinDat *)d_02185DB0, 0x22, 7, 0, ((BeaconDetailWork *)p)->heapId);
            *state = 0xF;
        }
        break;
    case 15:
        switch ((u32)(int)BMP_MENU_ProcessYesNo(((BeaconDetailWork *)p)->yesNo)) {
        case 0:
            BEACON_DETAIL_CloseDetailWin((char *)p);
            WIFI_HISTORY_InitLanguageRegion(((BeaconDetailWork *)p)->sub09470, ((BeaconDetailWork *)p)->sub0852C, ((BeaconDetailWork *)p)->selNation, ((BeaconDetailWork *)p)->selArea);
            GAME_BEACON_SetNationArea(((BeaconDetailWork *)p)->selNation, ((BeaconDetailWork *)p)->selArea);
            ((BeaconDetailWork *)p)->nation = ((BeaconDetailWork *)p)->selNation;
            ((BeaconDetailWork *)p)->area = ((BeaconDetailWork *)p)->selArea;
            *state = 0x10;
            break;
        case 0xFFFFFFFE:
            BEACON_DETAIL_CloseDetailWin((char *)p);
            *state = 3;
            break;
        }
        break;
    case 16:
        if (((BeaconDetailWork *)p)->japaneseFlag == 1 && ((BeaconDetailWork *)p)->sub09470State == 0) {
            ((BeaconDetailWork *)p)->viewMode = 0;
        } else {
            ((BeaconDetailWork *)p)->viewMode = 1;
        }
        BEACON_DETAIL_Init3DParams(p);
        BEACON_DETAIL_MarkCurrentRecord((BeaconDetailWork *)p);
        BEACON_DETAIL_SetupCamera((char *)p);
        BMP_Clear(BMP_WIN_GetBmp(((BeaconDetailWork *)p)->bmp1C), 0xF);
        BMP_WIN_TransferChars(((BeaconDetailWork *)p)->bmp1C);
        BEACON_DETAIL_CreateTaskMenuWin((char *)p, 1);
        if (((BeaconDetailWork *)p)->nation != 0) {
            BEACON_DETAIL_DrawCurrentArea((char *)p);
        }
        BEACON_DETAIL_DrawCurrentInfo((char *)p);
        ((BeaconDetailWork *)p)->detailOpen = 0;
        ((BeaconDetailWork *)p)->drawState = 1;
        *state = 0x11;
        break;
    case 17:
        old = ((BeaconDetailWork *)p)->zoomMode;
        if ((int)PRINTSYS_QUE_IsFinished(((BeaconDetailWork *)p)->printQue) == 0) {
            break;
        }
        BEACON_DETAIL_ReadTouchInput((char *)p);
        if (BEACON_DETAIL_FindNearestRecord((char *)p, &tmp)) {
            BEACON_DETAIL_CreateTaskMenuWin((char *)p, 0);
        } else {
            BEACON_DETAIL_DeleteTaskMenuWin(p, 0);
        }
        v = ((BeaconDetailWork *)p)->keyTrg;
        if ((v & 2) || ((w = ((BeaconDetailWork *)p)->inputFlag) & 2)) {
            BEACON_DETAIL_DeleteTaskMenuWin(p, 0);
            BEACON_DETAIL_WinActivate(p, 1);
            GFL_USE_PlaySeDefaultVolume(0x551);
            BMP_Clear(BMP_WIN_GetBmp(((BeaconDetailWork *)p)->bmp1C), 0xF);
            BMP_WIN_TransferChars(((BeaconDetailWork *)p)->bmp1C);
            *state = 0x13;
            break;
        }
        if (((v & 0x400) || (w & 0x400)) && ((BeaconDetailWork *)p)->detailOpen == 0) {
            ((BeaconDetailWork *)p)->detailOpen = 1;
            BEACON_DETAIL_WinActivate(p, 0);
            BEACON_DETAIL_DrawCurrentInfo((char *)p);
            if (((BeaconDetailWork *)p)->detailOpen != 1) {
                break;
            }
            goto se54c;
        }
        if (((v & 0x403) || (w & 0x400)) && ((BeaconDetailWork *)p)->detailOpen == 1) {
            ((BeaconDetailWork *)p)->detailOpen = 0;
            BEACON_DETAIL_DrawCurrentInfo((char *)p);
            break;
        }
        if (BEACON_DETAIL_MoveCursor(p, v, ((BeaconDetailWork *)p)->keyCont) == 1 && ((BeaconDetailWork *)p)->detailOpen == 1) {
            ((BeaconDetailWork *)p)->detailOpen = 0;
            BEACON_DETAIL_DrawCurrentInfo((char *)p);
        }
        if (old != ((BeaconDetailWork *)p)->zoomMode) {
            *state = 0x12;
            if (((BeaconDetailWork *)p)->zoomMode == 0) {
                GFL_USE_PlaySeDefaultVolume(0x649);
            } else {
                GFL_USE_PlaySeDefaultVolume(0x648);
            }
        }
        break;
    case 19:
        if ((int)APP_TASKMENU_WIN_IsFinish(((BeaconDetailWork *)p)->win[1]) == 0) {
            break;
        }
        if (((BeaconDetailWork *)p)->nation == 0) {
            ((BeaconDetailWork *)p)->drawState = 2;
            *state = 3;
        } else {
            BEACON_DETAIL_CloseDetailWin((char *)p);
            *state = 0x14;
        }
        BEACON_DETAIL_DeleteTaskMenuWin(p, 1);
        break;
    case 18:
        if (BEACON_DETAIL_UpdateCamera((char *)p) == 1) {
            *state = 0x11;
        }
        break;
    case 20:
        ((BeaconDetailWork *)p)->wipeState = 0;
        WIPE_SYS_Start(0, (int)0, (int)0, (int)0, (int)6, (int)1, ((BeaconDetailWork *)p)->heapId);
        *state = 0x15;
        break;
    case 21:
        if (WIPE_SYS_EndCheck() == 1) {
            ret = 1;
            ((BeaconDetailWork *)p)->drawState = 1;
            BEACON_DETAIL_DeleteMainScreen((char *)p);
            BEACON_DETAIL_Delete3DObjects((char *)p);
            MSGDATA_Delete(((BeaconDetailWork *)p)->msgBank);
            *state = 0;
        }
        break;
    }
    close_win(p, &((BeaconDetailWork *)p)->msg78);
    close_win(p, &((BeaconDetailWork *)p)->msg44);
    close_win(p, &((BeaconDetailWork *)p)->msg38);
    close_win(p, &((BeaconDetailWork *)p)->msg2C);
    close_win(p, &((BeaconDetailWork *)p)->msg20);
    return ret;
}

int BEACON_DETAIL_Exit(struct Proc *controller,void *unused1,void *unused2,char *p)
{
    unsigned heap=((BeaconDetailWork *)p)->heapId;
    PRINTSYS_QUE_Clear(((BeaconDetailWork *)p)->printQue);
    PRINTSYS_QUE_Delete(((BeaconDetailWork *)p)->printQue);
    BG_SYS_SetPlaneVisible(6,0);BG_SYS_SetPlaneVisible(2,0);BG_SYS_SetPlaneVisible(7,0);BG_SYS_SetPlaneVisible(3,0);
    BG_SYS_SetLcdSwap(1);
    APP_KEYCURSOR_Delete((struct KeyCursor *)(((BeaconDetailWork *)p)->keyCursor));
    TCBL_Destroy(((BeaconDetailWork *)p)->tcbl);
    BEACON_DETAIL_ExitGraphics(WORDSET_Delete(((BeaconDetailWork *)p)->wordSet));
    PROCSYS_FreeProcWork(controller);GFL_HEAP_DeleteChecked((u16)heap);
    return 1;
}

/*
 * prototype: 82AC0 SDK asm source reads r0 fill/r1 destination/r2 size;
 * preserve all three observed inputs despite legacy asm void(void).
 */
void BEACON_DETAIL_InitVram(void)
{
    struct DispVram cfg=d_02185F4C;
    GX_SetBankForLCDC(0x1ff);
    MIi_CpuClearFast(0,(void *)HW_LCDC_VRAM,0xa4000);GX_DisableBankForLCDC();
    MIi_CpuClearFast(0xc0,(void *)HW_OAM,0x400);
    MIi_CpuClearFast(0,(void *)HW_BG_PLTT,0x400);
    MIi_CpuClearFast(0xc0,(void *)HW_DB_OAM,0x400);
    MIi_CpuClearFast(0,(void *)HW_DB_BG_PLTT,0x400);
    BG_SYS_SetVramBanks(&cfg);
}

/*
 * prototype: heap forwarded full-width without caller truncation to 3F8F4,
 * 46440 and 45088; widen their legacy narrow parameters accordingly.
 */
void BEACON_DETAIL_InitGraphics(unsigned heap)
{
    struct DispConfig cfg=d_02185F18;
    BG_SYS_Create(heap);BG_SYS_SetGraphicsMode(&cfg);
    G3D_SYSTEM_Init(0,3,0,2,0,heap,0);
    BG_SYS_EnableBg0WithPriority(1);BMP_WIN_Init(heap);BG_SYS_ResetSubDisplay();
}

/*
 * Addresses are Black-image addresses.
 */
void BEACON_DETAIL_ExitGraphics(int a)
{
    BMP_WIN_Exit();
    G3D_SYSTEM_Exit();
    BG_SYS_Delete();
}

/*
 * lever: permuter split-assign(count2) moves the otherwise swapped outer/inner count spill slots; fixed-flag one validates MATCH*258B; trailing2B alignment excluded.
 * blocker C: int NATION_AREA_GetNationRecordCount(void){return 19;} typedef unsigned int u32; extern const unsigned char d_0209FA34[],d_0209FA35[]; u32 NATION_AREA_GetNationIdByIndex(u32 i){if(i<19)return d_0209FA34[i*12];return 0;} u32 NATION_AREA_GetAreaListArcMember(u32 i){if(i<19)return d_0209FA35[i*12];return 18;}
 * note 2026-10-04 (D2): still MATCH*; the three arm9 leaves 02025B38, 02025BB8, 02025BD0 are now filed EXACT in
 *   src/matched/arm9/func_<ADDR>.c (D2 lane 11). Rerun after the integrator regenerates shards: expected EXACT*.
 */
void BEACON_DETAIL_LoadRecords(char *p)
{
    void *arc,*data,*data2;
    u32 size,size2;
    short *cursor;
    long count2;
    long count;
    int firstcount,i,j;
    arc=ARC_TOOL_CreateHandle(0x35,(u16)(((BeaconDetailWork *)p)->heapId));
    ((BeaconDetailWork *)p)->recordCount=0;
    data=ARC_UTIL_LoadHandleMemberWithSize(arc,0x12,0,((BeaconDetailWork *)p)->heapId,&size);
    firstcount=size/6u;
    cursor=(short *)((char *)data+6);
    for(i=1;i<firstcount;i++,cursor+=3){
        if(*(u16 *)cursor!=2){
            BEACON_DETAIL_SetRecord((BeaconDetailWork *)p, ((BeaconDetailWork *)p)->recordCount, cursor[1], cursor[2], i, 0);
            (((BeaconDetailWork *)p)->recordCount)++;
        }
    }
    GFL_HEAP_Free(data);
    j=1;
    count=NATION_AREA_GetNationRecordCount();
    for(;j<count;j++){
        data2=ARC_UTIL_LoadHandleMemberWithSize(arc,NATION_AREA_GetAreaListArcMember(j),0,((BeaconDetailWork *)p)->heapId,&size2);
        count2=size2;
        count2=count2/4u;
        cursor=(short *)((char *)data2+4);
        for(i=1;i<count2;i++,cursor+=2){
            BEACON_DETAIL_SetRecord((BeaconDetailWork *)p, ((BeaconDetailWork *)p)->recordCount, cursor[0], cursor[1], NATION_AREA_GetNationIdByIndex(j), i);
            (((BeaconDetailWork *)p)->recordCount)++;
        }
        GFL_HEAP_Free(data2);
    }
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * extent: lead124B followed by separately matched92B BEACON_DETAIL_MarkCurrentRecord; no unit, follower has its own shard.
 * lever: typed48-byte record members keep byte offset live rather than caching p+offset as a raw pointer.
 */
void BEACON_DETAIL_SetRecord(BeaconDetailWork *p,int index,int x,int y,u16 a,u16 b)
{
    Matrix matrix=d_02185F28;
    int angles[3];
    p->records[index].x=x;
    p->records[index].y=y;
    angles[0]=x;angles[1]=y;angles[2]=0;
    BEACON_DETAIL_SetupRecordCalc((Matrix *)&matrix, angles);
    p->records[index].matrix=matrix;
    p->records[index].state=WIFI_HISTORY_GetCountryRegionState(p->sub09470,a,b);
    p->records[index].a=a;
    p->records[index].b=b;
}

/*
 * lever: full context member offsets preserve the c2f4 pool base; a cast Tail pointer instead hoists p+c2f4 and raw scalar offsets pool c33c.
 * extent: unlabelled92-byte follower inside handed021846B8 extent; next labelled stub02184790 excluded.
 */
void BEACON_DETAIL_MarkCurrentRecord(BeaconDetailWork *p)
{
    unsigned i;
    for(i=0;i<p->recordCount;i++){
        if(((BeaconDetailWork *)p)->records[i].a==p->nation && ((BeaconDetailWork *)p)->records[i].b==p->area){
            ((BeaconDetailWork *)p)->records[i].state=3;
            p->angleX=((BeaconDetailWork *)p)->records[i].x;
            p->angleY=((BeaconDetailWork *)p)->records[i].y;
        }
    }
}

u32 BEACON_DETAIL_GetRecordIndex(u32 key){return NATION_AREA_FindRecordIndex(key);}

void BEACON_DETAIL_ReadTouchInput(char *p)
{
    int flag=0;
    int result;
    int xf,dx,yf,dy;
    ((BeaconDetailWork *)p)->inputFlag=0;
    result=TOUCHPANEL_HitTrg((union TouchHitTable *)d_02185E00);
    if(result==0)flag=0x400;
    else if(result==1)flag=2;
    if(((BeaconDetailWork *)p)->touchTrg!=0){
        if(flag!=0){((BeaconDetailWork *)p)->inputFlag=flag;return;}
        ((BeaconDetailWork *)p)->touchPhase=0;
        ((BeaconDetailWork *)p)->moveX=0;
        ((BeaconDetailWork *)p)->moveY=0;
        ((BeaconDetailWork *)p)->touchTimer=0;
        ((BeaconDetailWork *)p)->inputFlag=0;
        ((BeaconDetailWork *)p)->dragStartX=((BeaconDetailWork *)p)->lastTouchX;
        ((BeaconDetailWork *)p)->dragStartY=((BeaconDetailWork *)p)->lastTouchY;
        ((BeaconDetailWork *)p)->touchTimer=4;
    }
    if(((BeaconDetailWork *)p)->touchHit!=0){
        switch(((BeaconDetailWork *)p)->touchPhase){
        case 0:
            if(((BeaconDetailWork *)p)->touchTimer==0)(((BeaconDetailWork *)p)->touchPhase)++;
            else (((BeaconDetailWork *)p)->touchTimer)--;
        case 1:
            if(flag!=0)return;
            BEACON_DETAIL_CalcTouchDelta(p,((BeaconDetailWork *)p)->dragStartX,((BeaconDetailWork *)p)->dragStartY,&xf,&dx,&yf,&dy);
            ((BeaconDetailWork *)p)->inputFlag=xf|yf;
            ((BeaconDetailWork *)p)->moveX=dx;
            ((BeaconDetailWork *)p)->moveY=dy;
            ((BeaconDetailWork *)p)->dragStartX=((BeaconDetailWork *)p)->lastTouchX;
            ((BeaconDetailWork *)p)->dragStartY=((BeaconDetailWork *)p)->lastTouchY;
            return;
        default:return;
        }
    }else{
        if(flag==0 && ((BeaconDetailWork *)p)->touchTimer!=0 && ((BeaconDetailWork *)p)->moveX<4 && ((BeaconDetailWork *)p)->moveY<4)
            ((BeaconDetailWork *)p)->inputFlag=1;
        ((BeaconDetailWork *)p)->touchPhase=0;
        ((BeaconDetailWork *)p)->moveX=0;
        ((BeaconDetailWork *)p)->moveY=0;
        ((BeaconDetailWork *)p)->touchTimer=0;
    }
}

/*
 * lever: declare oldx before a named base pointer; this puts oldx in r5
 * and base in r6. Const on the parameter alone left their five-byte swap.
 */
void BEACON_DETAIL_CalcTouchDelta(const char *p,int x,int y,int *xflag,int *xdistance,int *yflag,int *ydistance)
{
    int oldx;
    const char *base=p;
    int xf=0,yf=0,dx=0,dy=0;
    oldx=((BeaconDetailWork *)base)->lastTouchX;
    if(oldx!=0xffff){
        dx=oldx-x;
        if(dx<0){dx^=-1;xf=0x10;}
        else if(dx>0)xf=0x20;
    }
    *xflag=xf;*xdistance=dx&63;
    if(((BeaconDetailWork *)base)->lastTouchY!=0xffff){
        dy=((BeaconDetailWork *)base)->lastTouchY-y;
        if(dy<0){dy^=-1;yf=0x80;}
        else if(dy>0)yf=0x40;
    }
    *yflag=yf;*ydistance=dy&63;
}

struct Descriptor *BEACON_DETAIL_CreateBmpWin(const u8 *p,int flag){struct BmpWin *q;q=BMP_WIN_Create((unsigned int)p[0],(unsigned int)p[1],(unsigned int)p[2],p[3],p[4],p[5],1);BMP_Clear((struct Bmp *)BMP_WIN_GetBmp(q),15);if(flag==1)BMP_WIN_MakeScreen(q);return (struct Descriptor *)q;}

/*
 * prototype: explicit original heap shift pairs require narrow extern parameters for D7EC/40B94 despite their full-width own declarations;84968 returns descriptor pointer.
 */
void BEACON_DETAIL_InitMainScreen(char *p,void *arc)
{
    ((BeaconDetailWork *)p)->font=GF_FONT_Create(0x17,0,0,0,(u16)(((BeaconDetailWork *)p)->heapId));
    GF_FONT_GetTextColor(&((BeaconDetailWork *)p)->textColorR,&((BeaconDetailWork *)p)->textColorG,&((BeaconDetailWork *)p)->textColorB);
    GF_FONT_SetTextColor(1,2,0xf);
    BG_SYS_InitBgLayer(6,&d_02185E58,0);
    BG_SYS_ClearSlot(6);
    BG_SYS_InitBgLayer(7,&d_02185E78,0);
    ARC_UTIL_UploadBgCharFromHandle(arc,5,7,0,0,0,((BeaconDetailWork *)p)->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc,6,4,0,0x80,((BeaconDetailWork *)p)->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(arc,7,7,0,0,0,((BeaconDetailWork *)p)->heapId);
    BMP_MENUWORK_LoadCharAndPltt(6,4,6,0,((BeaconDetailWork *)p)->heapId);
    BMP_MENUWORK_LoadCharAndPltt(6,0x22,7,0,((BeaconDetailWork *)p)->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17,5,4,0x80,0x20,((BeaconDetailWork *)p)->heapId);
    BG_SYS_InitRun(6,0x20,0,(u16)(((BeaconDetailWork *)p)->heapId));
    BG_SYS_LoadPlttEntry(6,0x4753);
    ((BeaconDetailWork *)p)->bmp1C=(void *)BEACON_DETAIL_CreateBmpWin(d_02185DBD,1);
    BMP_MENUWORK_DrawWindow(((BeaconDetailWork *)p)->bmp1C,0,4,6);
    BMP_WIN_TransferChars(((BeaconDetailWork *)p)->bmp1C);
    ((BeaconDetailWork *)p)->printState=0;
    BG_SYS_InitBgLayer(2,&d_02185E58,0);
    BG_SYS_ClearSlot(2);
    BG_SYS_EnableBg0WithPriority(1);
    BG_SYS_InitBgLayer(3,&d_02185E78,0);
    ARC_UTIL_UploadBgCharFromHandle(arc,5,3,0,0,0,((BeaconDetailWork *)p)->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc,6,0,0,0x80,((BeaconDetailWork *)p)->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(arc,7,3,0,0,0,((BeaconDetailWork *)p)->heapId);
    BMP_MENUWORK_LoadCharAndPltt(2,0x22,7,0,((BeaconDetailWork *)p)->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17,5,0,0x80,0x20,((BeaconDetailWork *)p)->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17,5,0,0x100,0x20,((BeaconDetailWork *)p)->heapId);
    BG_SYS_InitRun(2,0x20,0,(u16)(((BeaconDetailWork *)p)->heapId));
    BG_SYS_LoadPlttEntry(2,0);
    BEACON_DETAIL_CreateTaskMenu(p);
}

void BEACON_DETAIL_CreateTaskMenu(char *p)
{
    ((BeaconDetailWork *)p)->strbufA=MSGDATA_AllocString(((BeaconDetailWork *)p)->msgBank,13);
    ((BeaconDetailWork *)p)->strbufB=MSGDATA_AllocString(((BeaconDetailWork *)p)->msgBank,16);
    ((BeaconDetailWork *)p)->taskMenu=APP_TASKMENU_RES_Create(2,9,(struct GFont *)(((BeaconDetailWork *)p)->font),(struct PrintQueue *)(((BeaconDetailWork *)p)->printQue),(u16)((BeaconDetailWork *)p)->heapId);
    ((BeaconDetailWork *)p)->winData[0].text=((BeaconDetailWork *)p)->strbufA;
    ((BeaconDetailWork *)p)->winData[0].tag=0x39e3;((BeaconDetailWork *)p)->winData[0].value=0;
    ((BeaconDetailWork *)p)->winData[1].text=((BeaconDetailWork *)p)->strbufB;
    ((BeaconDetailWork *)p)->winData[1].tag=0x39e3;((BeaconDetailWork *)p)->winData[1].value=1;
}

void BEACON_DETAIL_CreateTaskMenuWin(char *p,int i)
{
    if(*(void **)&((BeaconDetailWork *)p)->win[i]==0){
        *(void **)&((BeaconDetailWork *)p)->win[i]=(void *)(APP_TASKMENU_WIN_Create((struct TaskMenuRes *)(((BeaconDetailWork *)p)->taskMenu),(struct TaskMenuItem *)(&((BeaconDetailWork *)p)->winData[i]),(u8)d_02185E40[i].x,(u8)d_02185E40[i].y,(u8)d_02185E40[i].z,(u16)((BeaconDetailWork *)p)->heapId));
    }
}

void BEACON_DETAIL_DeleteTaskMenuWin(u8 *p,u32 i){u32 off=i*sizeof(void *);u8 *slots=(u8 *)((BeaconDetailWork *)p)->win;if(*(void**)(slots+off)){APP_TASKMENU_WIN_Delete(*(void**)(slots+off));BG_SYS_MarkTileDirty(2);*(void**)(slots+off)=0;}}

void BEACON_DETAIL_DeleteMainScreen(char *p)
{
    BEACON_DETAIL_DeleteTaskMenuWin((u8 *)p,0);BEACON_DETAIL_DeleteTaskMenuWin((u8 *)p,1);
    APP_TASKMENU_RES_Delete((struct TaskMenuRes *)(((BeaconDetailWork *)p)->taskMenu));
    STRBUF_Delete((struct Strbuf *)(*(struct Strbuf * *)&((BeaconDetailWork *)p)->strbufA));STRBUF_Delete((struct Strbuf *)(*(struct Strbuf * *)&((BeaconDetailWork *)p)->strbufB));
    ((BeaconDetailWork *)p)->win[0]=0;((BeaconDetailWork *)p)->win[1]=0;
    BMP_WIN_Delete((struct BmpWin *)(*(struct Descriptor * *)&((BeaconDetailWork *)p)->bmp1C));
    BG_SYS_FreeLayerBuf(2);BG_SYS_FreeLayerBuf(6);BG_SYS_FreeLayerBuf(3);BG_SYS_FreeLayerBuf(7);
    GF_FONT_Delete(((BeaconDetailWork *)p)->font);
    GF_FONT_SetTextColor(((BeaconDetailWork *)p)->textColorR,((BeaconDetailWork *)p)->textColorG,((BeaconDetailWork *)p)->textColorB);
}

void BEACON_DETAIL_DrawTextRecord(char *p,BeaconMessage *out,struct Descriptor *d,void *text,u8 x,u8 y)
{
    struct PrintQueue *print;
    out->bmp=d;out->active=0;
    print=((BeaconDetailWork *)p)->printQue;
    PRINTSYS_PrintQue(print,BMP_WIN_GetBmp((struct BmpWin *)d),x,y,text,(struct GfFont *)((BeaconDetailWork *)p)->font);
    out->active=1;
}

/*
 * blocker-C: 02045CAC verified EXACT, 344B, scratch arm9-blocker.log;
 * copied unchanged from unit_02045C44.c, using dsi/1.1p1 -O4,p --arm.
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
 *
 * prototype: 0201CCE4's legacy void return is live r0 stored to p+C074; retain u32 return. Heap truncation at call sites uses u16.
 */
int BEACON_DETAIL_PrintMessage(char *p,u32 message,int force)
{
    int result;
    u32 mode;
    result=0;
    switch(((BeaconDetailWork *)p)->printState) {
    case 0:
        BMP_Clear(BMP_WIN_GetBmp(((BeaconDetailWork *)p)->bmp1C),15);
        ((BeaconDetailWork *)p)->printBuf=STRBUF_Create(1024,(u16)(((BeaconDetailWork *)p)->heapId));
        MSGDATA_ReadString(((BeaconDetailWork *)p)->msgBank,message,((BeaconDetailWork *)p)->printBuf);
        ((BeaconDetailWork *)p)->printHandle=PRINTSYS_PrintStream(((BeaconDetailWork *)p)->bmp1C,0,0,((BeaconDetailWork *)p)->printBuf,(struct GfFont *)(((BeaconDetailWork *)p)->font),MSG_SPEED_GetWait(),((BeaconDetailWork *)p)->tcbl,(u32)0,((BeaconDetailWork *)p)->heapId,15);
        ((BeaconDetailWork *)p)->printState=1;
        break;
    case 1:
        mode=PRINTSYS_PrintStreamGetState((void *)((BeaconDetailWork *)p)->printHandle);
        APP_KEYCURSOR_Update(((BeaconDetailWork *)p)->keyCursor,(void *)((BeaconDetailWork *)p)->printHandle,((BeaconDetailWork *)p)->bmp1C);
        switch(mode) {
        case 0:
            if(KEY_GetCont()&1)PRINTSYS_PrintStreamShortWait(((BeaconDetailWork *)p)->printHandle,0);
            break;
        case 1:
            if((((BeaconDetailWork *)p)->keyTrg&1)||(((BeaconDetailWork *)p)->keyTrg&2)) {
                PRINTSYS_PrintStreamReleasePause((void *)((BeaconDetailWork *)p)->printHandle);
                GFL_USE_PlaySeDefaultVolume(0x547);
            }
            break;
        case 2: ((BeaconDetailWork *)p)->printState=2;break;
        }
        break;
    case 2:
        if(force!=0 || (((BeaconDetailWork *)p)->keyTrg&1)) {
            STRBUF_Delete(((BeaconDetailWork *)p)->printBuf);
            PRINTSYS_PrintStreamDelete(((BeaconDetailWork *)p)->printHandle);
            ((BeaconDetailWork *)p)->printState=0;
            result=1;
        }
        break;
    }
    return result;
}

void BEACON_DETAIL_OnMessageDone(struct BmpMenuList *a, u32 b, void *c)
{
    if (c == 0)
        GFL_USE_PlaySeDefaultVolume(0x547);
}

/*
 * prototype: retain 1F878 fifth u16 stack argument loaded by this caller, absent from legacy callee declaration; 1FF30 heap explicitly narrowed in caller.
 */
void BEACON_DETAIL_CreateMenuList(char *p,const unsigned char *descriptor,const struct BeaconDetailMenuTemplate *source,const BeaconMenuItem *entries)
{
    int i;
    struct BeaconDetailMenuTemplate cfg;
    *(struct Descriptor * *)&((BeaconDetailWork *)p)->bmp18=(struct Descriptor *)BEACON_DETAIL_CreateBmpWin(descriptor,1);
    ((BeaconDetailWork *)p)->menuWork=BMP_MENUWORK_Create(source->t.count,((BeaconDetailWork *)p)->heapId);
    for(i=0;i<source->t.count;i++)
        BMP_MENUWORK_AddMsgItem(*(struct BmpMenuWork * *)&((BeaconDetailWork *)p)->menuWork,(struct MsgBank *)(((BeaconDetailWork *)p)->msgBank),entries[i].bank,entries[i].id,(u16)(((BeaconDetailWork *)p)->heapId));
    ((BeaconDetailWork *)p)->msg78.bmp=((BeaconDetailWork *)p)->bmp18;
    ((BeaconDetailWork *)p)->msg78.active=0;
    cfg=*source;
    cfg.t.items=(struct BmpMenuListItem *)((BeaconDetailWork *)p)->menuWork;
    cfg.t.win=(struct BmpWin *)((BeaconDetailWork *)p)->bmp18;
    cfg.t.onCursor=BEACON_DETAIL_OnMessageDone;
    cfg.t.cursorW=12;
    cfg.t.rowH=GF_FONT_GetLineHeight((struct GfFont *)(((BeaconDetailWork *)p)->font));
#ifdef __MWERKS__
    *(u32 *)cfg.t.reserved24=(uptr)((BeaconDetailWork *)p)->msgBank;
#endif
    cfg.t.target=(struct MenuTarget *)&((BeaconDetailWork *)p)->msg78;
    cfg.t.printer=(struct PrintQueue *)((BeaconDetailWork *)p)->printQue;
    cfg.t.font=(struct GfFont *)((BeaconDetailWork *)p)->font;
    *(struct BmpMenuList * *)&((BeaconDetailWork *)p)->menuList=BMP_MENULIST_Create((struct BmpMenuListTemplate *)&cfg, 0, 0, (u16)(((BeaconDetailWork *)p)->heapId));
    BMP_MENULIST_ResetCursorTile(*(struct BmpMenuList * *)&((BeaconDetailWork *)p)->menuList,((BeaconDetailWork *)p)->heapId);
    BMP_MENUWORK_DrawWindow(((BeaconDetailWork *)p)->bmp18,0,34,7);
    BMP_WIN_TransferChars(((BeaconDetailWork *)p)->bmp18);
}

/*
 * prototype: 20CF8 legacy one parameter; original also visibly sets r1
 * to full-width heap, retained as a second input even though body ignores it.
 */
void BEACON_DETAIL_SetupMenuList(char *p,const struct BeaconDetailMenuTemplate *source,unsigned count)
{
    struct BeaconDetailMenuTemplate cfg;
    ((BeaconDetailWork *)p)->msg78.bmp=((BeaconDetailWork *)p)->bmp18;((BeaconDetailWork *)p)->msg78.active=0;
    cfg=*source;
    cfg.t.items=(struct BmpMenuListItem *)((BeaconDetailWork *)p)->menuWork;
    cfg.t.count=count;
    cfg.t.win=(struct BmpWin *)((BeaconDetailWork *)p)->bmp18;
    cfg.t.onCursor=BEACON_DETAIL_OnMessageDone;
    cfg.t.cursorW=12;
    cfg.t.rowH=GF_FONT_GetLineHeight((struct GfFont *)(((BeaconDetailWork *)p)->font));
    cfg.t.target=(struct MenuTarget *)&((BeaconDetailWork *)p)->msg78;
    cfg.t.printer=(struct PrintQueue *)((BeaconDetailWork *)p)->printQue;
    cfg.t.font=(struct GfFont *)((BeaconDetailWork *)p)->font;
    *(struct BmpMenuList * *)&((BeaconDetailWork *)p)->menuList=BMP_MENULIST_Create((struct BmpMenuListTemplate *)&cfg, 0, 0, (u16)((BeaconDetailWork *)p)->heapId);
    BMP_MENULIST_ResetCursorTile(*(struct BmpMenuList * *)&((BeaconDetailWork *)p)->menuList,((BeaconDetailWork *)p)->heapId);
    BMP_MENUWORK_DrawWindow(((BeaconDetailWork *)p)->bmp18,0,34,7);
    BMP_WIN_TransferChars((struct BmpWin *)(*(struct Descriptor * *)&((BeaconDetailWork *)p)->bmp18));
}

static inline u32 menuMsgIdAt(int i) { return *(const u32 *)((const u8 *)d_02185F7C + i * 4); }

static inline u32 menuMsgIdGet(u32 idx) { return d_02185F7C[idx]; }

#if LANGUAGE == LANGUAGE_JAPANESE
void BEACON_DETAIL_CreateMenuItemsFromBank(u8 *p, const u8 *a, uptr b, u32 c)
{
    struct MsgBank *t;
    u32 count;
    u32 i;
    ((BeaconDetailWork *)p)->bmp18 = (void *)BEACON_DETAIL_CreateBmpWin(a, 1);
    t = MSGDATA_CreateFromArchive(0, 2, (u16)c, (u16)((BeaconDetailWork *)p)->heapId);
    count = MSGDATA_GetMessageCount(t);
    ((BeaconDetailWork *)p)->menuWork = BMP_MENUWORK_Create(count, ((BeaconDetailWork *)p)->heapId);
    for (i = 1; i < count; i++) {
        BMP_MENUWORK_AddMsgItem(((BeaconDetailWork *)p)->menuWork, t, i, i, (u16)((BeaconDetailWork *)p)->heapId);
    }
    MSGDATA_Delete(t);
    BEACON_DETAIL_SetupMenuList((char *)p, (const struct BeaconDetailMenuTemplate *)b, count - 1);
}
#endif

/*
 * 2026-10-05 (user decision): the two spellings of one table read (accessor for one argument, direct index for the other) are accepted as a real source quirk.
 * 2026-10-05 (wD9r lane130): still DIFF 17 bytes, source unchanged. New tries, all compiled: (1) a walking
 *   pointer `e = d; for (...; i++, e++) f(.., *e, *e, h)`: 43 (needs a register the image does not have; the image
 *   rematerialises the pool word and scales i every iteration, so there is no walking pointer); (2) a copy
 *   counter `j = i; f(.., d[i], d[j], h)`: 17 (copy propagation runs before the early CSE); (3) `d[i]` and
 *   `i[d]`: 17; (4) a volatile read for the fifth argument: 17 (no barrier for the CSE); (5) an assignment in
 *   the fifth argument `h = (u16)*p`: 17; (6) sized table with a sizeof bound: 46 (loop shape lost);
 *   (7) `((u32 *)d)[i]` for one argument: 61 (two loads survive). Diagnostic: with one table read and a
 *   literal fourth argument the h load comes first (10 bytes, schedule only), which confirms that the two
 *   reads are merged by the early CSE in every same-tree spelling. No real source form found.
 * 2026-10-05 (wD9r lane122): still DIFF 17 bytes, source unchanged. Data check: d_02185F7C is one u32
 *   array of 0x82 message ids (0x01..0xE3, two out of order), followed by the overlay .sinit; no pair table, no
 *   second symbol (one pool word), so both arguments really are one element. New tries: (1) pointer-typed callee
 *   parameters (void * for the index or the tag, with the table as u32 or void *const): the early CSE ignores
 *   the conversion, 17; (2) the table as a union of two same-typed members (msg/tag, also nested struct and
 *   one-element array members), one member per argument: 17 (same tree); (3) a union {u32 msg; unsigned long
 *   tag;} (or int/long), one member per argument: 4 bytes (only the lsls r3,r4,#2 / lsls r0,r0,#16 pair is
 *   swapped); a union {u32; int;} gives 61 (two loads). Finding: the early CSE keys on the element type and
 *   the address tree; any source that splits them is two spellings of one read (the D8 byte-offset form is
 *   EXACT, the u32/unsigned long view is 4 bytes). Not filed under the stand-in rule.
 * 2026-10-05 (wD9r lane113): still DIFF 17 bytes, source unchanged. New tries, all compiled: (1) loop body as a
 *   static inline taking the index, `AddOne(p, t, i)` and `AddOne(p, t, tbl, i)` reading tbl[i] twice inside (17);
 *   (2) the whole loop as a static inline `AddList(p, t, ids, n)` called with (d_02185F7C, 0x82): ternary bound 17,
 *   plain int or unsigned bound 46; (3) inline `Add(l, t, i, h)` / `Add(h, l, t, i)` / `Add(l, t, tbl, i, h)` with
 *   the table read inside the helper after the h parameter (u16 and u32 h): 17 (inline parameters are propagated, so
 *   the helper is transparent to the early CSE); (4) inline `Add(p, t, const u32 *e)` called with `d + i` and
 *   `&d[i]`, reading *e twice: 17; (5) one-word struct element copy `E e = tbl[i]; f(.., e.id, e.id, ..)`: 21;
 *   (6) loop shapes: goto loop with bottom test 46, while(1)/break 30, do-while 46, call in the for increment
 *   as a comma expression 17, `(void)` call and `if (1)` wrapper 17; (7) function-local static table
 *   (const and non-const): 17. Diagnostic only: a struct-cast read for one argument and d[i] for the other gives
 *   4 bytes (another two-spellings stand-in, not filed).
 * 2026-10-05 (wD9r lane66): still DIFF 17 bytes, source unchanged. Tried: (1) the table as a file
 *   static `static const u32 d_02185F7C[130]` defined in this unit: same CSE temp (and the data word
 *   has no witness); (2) the full shape of the matched twin ov219 021850EC (unsigned i, `(unsigned)bank`
 *   argument, prototype (Slot *, unsigned, unsigned, unsigned, u16)): the twin itself has the CSE temp
 *   form (ids load first), so the copy also gives it, plus a plain loop; (3) this function as the twin's
 *   body in a static inline Build(p, a, b, c, const u32 *ids, int count) called with (d_02185F7C, 0x82):
 *   46 bytes, CSE temp still first and the loop loses its branch to the bottom test.
 * 2026-10-05 (wD8 lane10): EXACT found but parked as DIFF under the stand-in rule. Writing the two table
 *   arguments in two different forms, `BMP_MENUWORK_AddMsgItem(..., t, d_02185F7C[i], tb(i), (u16)((BeaconDetailWork *)p)->heapId)` (or tb(i)
 *   third and d_02185F7C[i] fourth), gives EXACT 120 bytes: the early CSE no longer merges the two reads, so the
 *   stack argument is computed first and the late CSE shares the load. `d[i]` with `*(d + i)` does not (same
 *   tree), and tb as `return d[i]` does not. The two-form trick only exists to defeat CSE, so the integrator or
 *   the user must decide if it is acceptable. Source below is unchanged (17 bytes).
 * 2026-10-05 (wD7 lane14): still DIFF 17 bytes. Reading: the image computes the table address in r2/r3 because h (r0) and t (r1) are
 *   already live, so the table chain comes after the h load in the IR; ours computes the CSE'd table value first (temps r0/r1), so
 *   the scheduler cannot interleave. Tried: non-const extern table (same), u16 h local before the call (same, propagated),
 *   f(q, t, v, v = tb(i), h) (same), static inline Add(q, t, i, u16 h / int h) (same). The arm9 callee BMP_MENUWORK_AddMsgItem reads only
 *   four arguments (the fifth is a dead stack argument, kept as in the matched sibling 02184EC0).
 * 2026-10-05 (wD6 lane16): still DIFF 17 bytes. Tried: static inline wrappers W(a, t, v, h) and W(h, a, t, v) calling
 *   f(a, t, v, v, h); Add(p, t, id) reading p inside; `v = d[i]` as the third argument with v as the fourth; a block
 *   with u16 h then u32 v locals. All keep the table load (CSE temp) before the stack argument.
 * 2026-10-05 (wD4 lane19): still DIFF 17 bytes, no new hypothesis beyond the 2026-10-04 notes closed it.
 * note 2026-10-04: DIFF, 17 bytes, loop body only. Original loads the u16 stack argument ((u16)*p) first,
 *   then the table pool address into r2 and indexes in r2; here the table base goes to r0 and the table
 *   load comes before the *p load. Everything else matches (u32 param c with (u16) casts in the call, loop
 *   as (i < 0x82) ? 1 : 0). Tried: locals k/w in both orders, static inline table reader, byte-offset read.
 *   2026-10-04 (D2): also tried plain d_02185F7C[i] twice, k local, callee last param u16 with u32 arg, local
 *   table pointer (59 bytes worse: hoists the pool load). Still 17 bytes: u16 stack arg must load before the table pool word.
 * 2026-10-05 (wD5 lane20): no new hypothesis closed it; the 17 byte residue is unchanged.
 * 2026-10-05 (wD9 lane11): still DIFF 17 bytes. Tried: callee prototype with mixed int/u32 index and tag
 *   parameters (int,u32 / u32,int / int,int) so the two table arguments carry different conversions; the early CSE
 *   still merges them (17 bytes, unchanged). Matched sibling 02184EC0 (same overlay) passes entries[i].bank /
 *   entries[i].id to the same callee, so a struct-table reading does not apply here (one load feeds both).
 * 2026-10-05 (wD9r lane03): still DIFF 17 bytes. Tried: the fifth argument through a static inline getter
 *   `u16 Hid(u8 *p)` (with plain d[i] twice, and with tb(i) twice): unchanged; `f(q, t, v = d[i], v, h)`
 *   (assignment in the third argument; the fourth-argument form was tried before): unchanged. The early
 *   CSE still places the table read before the stack argument.
 * 2026-10-05 (wD9r lane24): still DIFF 17 bytes. Tried an unprototyped callee `extern void BMP_MENUWORK_AddMsgItem();`
 *   (default argument promotions): unchanged. Reading kept: the image order (h load, table load, C050 load)
 *   is right-to-left argument evaluation, so in the original the two table reads were not one CSE candidate
 *   at the early stage; only the two-form D8 source reproduces that so far.
 * 2026-10-05 (wD9r lane40): still DIFF 17 bytes, source unchanged. Tried: a real struct for p (heap at 0,
 *   msg at 0xC018, list at 0xC050, as the matched sibling 02184EC0) with implicit u16 conversion of w->heap and
 *   plain d[i] twice: unchanged; an element pointer local `e = &d[i]; f(.., *e, *e, h)`: unchanged. Reading kept:
 *   the image has no statement-level CSE temp (table read after the h load, before the C050 load, i.e. in
 *   argument position); every single-tree spelling gets the temp.
 * 2026-10-05 (wD9r lane101): still DIFF 17 bytes, source unchanged. Rechecked every block against the
 *   listing: prologue, the three setup calls, the 0xC018/0xC050 offsets and the tail are byte-identical;
 *   the loop body has the same operands (q at p+0xC050, t, d[i] twice, (u16)p[0]), so no logic error.
 *   New tries, all with plain d[i] twice: sized extern `d[0x82]` (17); table as a global struct with
 *   one `ids[0x82]` member (17); `d[i], d[i++]` in the arguments (79); a bound local `n = 0x82` used in all
 *   three places, and a file-scope `const int` bound (46: the first test folds, the loop loses its branch
 *   to the bottom test); `i = 0` hoisted above the calls with a plain for (46 to 69); variadic callee
 *   prototypes `(void *, void *, u32, u32, ...)`, `(void *, void *, ...)`, `(void *, ...)` (17); a static
 *   inline 5-parameter pass-through `Add(l, m, s, v, h)` called with d[i] twice (17 with u16 h, 59 with
 *   u32 h). Diagnostic only (not filed): the plain `i < 0x82` loop at -O2,p is also 17 bytes, so the early
 *   CSE of the two table reads is present at -O2 too. Reading: the image has no early CSE temp and no
 *   loop rotation; both are global-optimizer effects, so the original may contain something that
 *   restricted that optimizer for this function. No real source form found.
 */
void BEACON_DETAIL_CreateMenuItems(u8 *p, const u8 *a, uptr b, u32 c)
{
    void *t;
    int i;
    ((BeaconDetailWork *)p)->bmp18 = (void *)BEACON_DETAIL_CreateBmpWin(a, 1);
    t = MSGDATA_CreateFromArchive(0, 2, (u16)c, (u16)((BeaconDetailWork *)p)->heapId);
    ((BeaconDetailWork *)p)->menuWork = BMP_MENUWORK_Create(0x82, ((BeaconDetailWork *)p)->heapId);
    for (i = 0; (i < 0x82) ? 1 : 0; i++) {
        BMP_MENUWORK_AddMsgItem(((BeaconDetailWork *)p)->menuWork, t, menuMsgIdGet(i), d_02185F7C[i], (u16)((BeaconDetailWork *)p)->heapId);
    }
    MSGDATA_Delete(t);
    BEACON_DETAIL_SetupMenuList((char *)p, (const struct BeaconDetailMenuTemplate *)b, 0x82);
}

#if LANGUAGE != LANGUAGE_JAPANESE
/*
 * prototype: 45B38 third/fourth original inputs explicitly narrowed u16;
 * 1F878 retains original fifth stack heap input absent from legacy source.
 */
void BEACON_DETAIL_CreateMenuItemsFromIds(char *p,const unsigned char *descriptor,const struct BeaconDetailMenuTemplate *cfg,unsigned file,const unsigned char *ids,unsigned count)
{
    struct MsgBank *bank;
    unsigned i;
    *(struct Descriptor * *)&((BeaconDetailWork *)p)->bmp18=(struct Descriptor *)BEACON_DETAIL_CreateBmpWin(descriptor,1);
    bank=MSGDATA_CreateFromArchive(0,2,(u16)file,(u16)(((BeaconDetailWork *)p)->heapId));
    *(BeaconMenuWork * *)&((BeaconDetailWork *)p)->menuWork=BMP_MENUWORK_Create(130,((BeaconDetailWork *)p)->heapId);
    for(i=0;i<count;i++)BMP_MENUWORK_AddMsgItem(((BeaconDetailWork *)p)->menuWork,bank,ids[i],ids[i],(u16)((BeaconDetailWork *)p)->heapId);
    MSGDATA_Delete((struct MsgBank *)bank);
    BEACON_DETAIL_SetupMenuList(p, (const struct BeaconDetailMenuTemplate *)cfg, count);
}
#endif

void BEACON_DETAIL_CloseMenu(u8*p){BMP_MENUWORK_DrawWindowBorder(*(void* *)&((BeaconDetailWork *)p)->bmp18,0);BMP_WIN_Delete((struct BmpWin *)(*(struct Descriptor* *)&((BeaconDetailWork *)p)->bmp18));BMP_MENULIST_Delete((struct BmpMenuList *)(*(struct BmpMenuList* *)&((BeaconDetailWork *)p)->menuList),0,0);BMP_MENUWORK_Delete(*(void* *)&((BeaconDetailWork *)p)->menuWork);}

/*
 * prototype: 457B0 heap input is explicitly narrowed to u16 in original;
 * retain all observed narrow inputs to matching4D30 stack-byte interface.
 */
void BEACON_DETAIL_DrawCurrentArea(char *p)
{
    struct Strbuf *dst,*src;
    dst=STRBUF_Create(1024,(u16)(((BeaconDetailWork *)p)->heapId));src=STRBUF_Create(1024,(u16)(((BeaconDetailWork *)p)->heapId));
    *(struct Descriptor * *)&((BeaconDetailWork *)p)->bmp40=(struct Descriptor *)BEACON_DETAIL_CreateBmpWin(d_02185DCB,1);
    WORDSET_SetSlotFromMsgE7(*(struct WordSet * *)&((BeaconDetailWork *)p)->wordSet,0,((BeaconDetailWork *)p)->nation);
    WORDSET_SetSlotFromKeyedMessage(*(struct WordSet * *)&((BeaconDetailWork *)p)->wordSet,1,((BeaconDetailWork *)p)->nation,((BeaconDetailWork *)p)->area);
    MSGDATA_ReadString(((BeaconDetailWork *)p)->msgBank,14,src);
    WORDSET_CopyTaggedText(*(struct WordSet * *)&((BeaconDetailWork *)p)->wordSet,dst,src);
    BEACON_DETAIL_DrawTextRecord(p,&((BeaconDetailWork *)p)->msg44,*(struct Descriptor * *)&((BeaconDetailWork *)p)->bmp40,dst,0,0);
    STRBUF_Delete((struct Strbuf *)src);STRBUF_Delete((struct Strbuf *)dst);
    BMP_MENUWORK_DrawWindow(((BeaconDetailWork *)p)->bmp40,0,34,7);
    BMP_WIN_TransferChars((struct BmpWin *)(*(struct Descriptor * *)&((BeaconDetailWork *)p)->bmp40));
}

/*
 * prototype: original truncates heap before 020457B0, and stack bytes before 02184D30; extern narrow widths preserve those visible operations.
 */
void BEACON_DETAIL_DrawEntryDetail(char *p,unsigned key,unsigned member)
{
    void *first,*second,*object;
    first=STRBUF_Create(64,(u16)(((BeaconDetailWork *)p)->heapId));
    second=STRBUF_Create(64,(u16)(((BeaconDetailWork *)p)->heapId));
    ((BeaconDetailWork *)p)->bmp40=(void *)BEACON_DETAIL_CreateBmpWin(d_02185DCB,1);
    BEACON_DETAIL_GetEntryText(key,member,first,second,((BeaconDetailWork *)p)->heapId);
    if(member!=0) BEACON_DETAIL_DrawTextRecord(p,&((BeaconDetailWork *)p)->msg44,((BeaconDetailWork *)p)->bmp40,second,0,16);
    BEACON_DETAIL_DrawTextRecord(p,&((BeaconDetailWork *)p)->msg44,((BeaconDetailWork *)p)->bmp40,first,0,0);
    STRBUF_Delete(second);
    STRBUF_Delete(first);
    BMP_MENUWORK_DrawWindow(((BeaconDetailWork *)p)->bmp40,0,34,7);
    object=((BeaconDetailWork *)p)->bmp40;
    BMP_WIN_TransferChars(object);
    BMP_WIN_MakeScreen(object);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(object));
}

void BEACON_DETAIL_CloseDetailWin(char *p)
{
    void **q = &((BeaconDetailWork *)p)->bmp40;
    BMP_MENUWORK_DrawWindowBorder(*q, 0);
    BMP_WIN_Delete(*q);
}

/*
 * 2026-10-05 (wD9 lane12): EXACT. The wrap value was a ternary local t merged at a join and stored
 *   to ylo and yhi after it. Writing the stores in each arm (`if (lo2 > 0) yhi = ylo = lo2 - 0x10000;
 *   else yhi = ylo = lo2 + 0x10000;`) gives lo2 r6 and spills yhi, as in the image (tail merging
 *   rebuilds the shared two-store join). See docs/idioms/two-long-lived-values-in-each-others-registers.md.
 * 2026-10-05 (wD8 lane10): still DIFF 91 bytes. Re-read the listing: semantics match (ylo [sp,#0x10], yhi
 *   [sp,#0xc], hi2 [sp,#8], lo2 r6; wrap order lo2-=, hi2+=, ylo-=, yhi+=). No new test closed the r6 swap.
 * 2026-10-05 (wD7 lane14): still DIFF 91 bytes. Re-derived the middle part: no logic error found. Tried: ylo = ternary; yhi = ylo
 *   (no t local, same 91); ylo/yhi as a two-element local array (mwcc scalarises it, 98).
 * 2026-10-05 (wD6 lane16): still DIFF 91 bytes. Tried: else arm as lo2 = ylo; hi2 = yhi (order swap) and the abs test
 *   as a ternary inside the if: no change. Callee 02185D08 reads only r0 (no missing argument).
 * 2026-10-05 (wD5 lane05): DIFF 91 bytes (was 163). Fixes: no e record pointer local (each
 *   field read as *(T *)(p + i * 0x30 + K), loop colours now exact); no cx/cy locals; every use reads
 *   *(int *)(p + 0xC2F4/0xC2F8) directly (CSE gives the original load order; prologue now exact up to
 *   +0x3A). Residue: yhi takes r6 and lo2 is spilled to [sp,#0xc]; the original has lo2 in r6 and yhi
 *   in [sp,#0xc] (a pure swap of the two, all else follows). No change from: lo2 assigned directly
 *   (no y16 temp), declaring lo2 last or before yhi, `yhi = ylo = t`, the ternary as an if/else on
 *   ylo, a struct Ent array for the 0x30 records (worse, hoists p+0x18). lo2/hi2 set before the if
 *   (no else) does give lo2 r6 but loses the else block (257).
 * 2026-10-05 (wD4 lane19): still DIFF 163 bytes. Tried the constant in a local (int off = 0xC2F4; p[off], p[off+4], and for the reload): mwcc folds it, no change.
 * 2026-10-04 (wD2 lane 09): 284 vs 288 bytes, 163 bytes differ, same frame.
 * Semantics read from the listing (x,y at +0xC2F4/+0xC2F8, count at +0x14,
 * 0x30-byte records, s16 fields +0x18/+0x1a, u16 flag +0x40). Residue: the
 * original keeps only lo2 (r6) in a register and spills ylo/yhi/hi2; ours puts
 * yhi in r6, so the wrap test and the range test swap order, and the loop
 * colours ex/ey/e as r1/r2/r0 instead of r0/r1/r2. Tried: lo2/hi2 set through
 * y16 before the temp (89->163 bytes better than the first draft), declaring
 * lo2/hi2 first (169, worse). Not tried: wrap test through different locals.
 */
int BEACON_DETAIL_FindNearestRecord(char *p, u32 *out)
{
    int ret = 0;
    int xlo, xhi, ylo, yhi, lo2, hi2;
    u32 i;
    u32 best;
    u32 bestd;
    int cur[2];

    xlo = (s16)(((BeaconDetailWork *)p)->angleX - 0x80);
    xhi = (s16)(((BeaconDetailWork *)p)->angleX + 0x80);
    ylo = (s16)(((BeaconDetailWork *)p)->angleY - 0x80);
    yhi = (s16)(((BeaconDetailWork *)p)->angleY + 0x80);
    best = ((BeaconDetailWork *)p)->recordCount;
    bestd = 0x100;
    cur[0] = ((BeaconDetailWork *)p)->angleX;
    cur[1] = ((BeaconDetailWork *)p)->angleY;
    BEACON_DETAIL_WrapAngle(cur);
    {
        int d = yhi - ylo;
        if (d < 0) d = -d;
        if (d > 0x100) {
            lo2 = (s16)((BeaconDetailWork *)p)->angleY;
            hi2 = lo2;
            if (lo2 > 0)
                yhi = ylo = lo2 - 0x10000;
            else
                yhi = ylo = lo2 + 0x10000;
            lo2 -= 0x80;
            hi2 += 0x80;
            ylo -= 0x80;
            yhi += 0x80;
        } else {
            hi2 = yhi;
            lo2 = ylo;
        }
    }
    for (i = 0; i < ((BeaconDetailWork *)p)->recordCount; i++) {
        int ex = ((BeaconDetailWork *)p)->records[i].x;
        if (ex > xlo && ex < xhi) {
            int ey = ((BeaconDetailWork *)p)->records[i].y;
            if ((ey > ylo && ey < yhi) || (ey > lo2 && ey < hi2)) {
                if (((BeaconDetailWork *)p)->records[i].state != 0) {
                    int pt[2];
                    u32 dd;
                    pt[0] = ex;
                    pt[1] = ((BeaconDetailWork *)p)->records[i].y;
                    BEACON_DETAIL_WrapAngle(pt);
                    dd = BEACON_DETAIL_CalcDistance(cur, pt);
                    if (dd < bestd) {
                        bestd = dd;
                        best = i;
                    }
                }
            }
        }
    }
    *out = best;
    if (best != ((BeaconDetailWork *)p)->recordCount)
        ret = 1;
    return ret;
}

/*
 * lever: distinct outer buffer and block-scoped first/second buffers settle the eight-byte r4/r6 swap.
 * blocker-C: 02045CAC verified EXACT, 344B, scratch arm9-blocker.log;
 * copied unchanged from unit_02045C44.c, using dsi/1.1p1 -O4,p --arm.
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
 *
 * prototype: caller narrows allocation heap to u16 immediately before each call.
 */
void BEACON_DETAIL_DrawCurrentInfo(char *p)
{
    struct Strbuf *buffer;
    u32 selected;
    if(((BeaconDetailWork *)p)->detailOpen==0) {
        buffer=STRBUF_Create(1024,(u16)(((BeaconDetailWork *)p)->heapId));
        BMP_Clear(BMP_WIN_GetBmp(((BeaconDetailWork *)p)->bmp1C),15);
        MSGDATA_ReadString(((BeaconDetailWork *)p)->msgBank,15,buffer);
        BEACON_DETAIL_DrawTextRecord(p,&((BeaconDetailWork *)p)->msg20,((BeaconDetailWork *)p)->bmp1C,buffer,0,0);
        STRBUF_Delete((struct Strbuf *)buffer);
    } else {
        struct Strbuf *first,*second;
        if(BEACON_DETAIL_FindNearestRecord(p,&selected)) {
            first=STRBUF_Create(64,(u16)(((BeaconDetailWork *)p)->heapId));
            second=STRBUF_Create(64,(u16)(((BeaconDetailWork *)p)->heapId));
            BMP_Clear(BMP_WIN_GetBmp(((BeaconDetailWork *)p)->bmp1C),15);
            BEACON_DETAIL_GetEntryText(((BeaconDetailWork *)p)->records[selected].a,((BeaconDetailWork *)p)->records[selected].b,first,second,((BeaconDetailWork *)p)->heapId);
            if(((BeaconDetailWork *)p)->records[selected].b!=0)
                BEACON_DETAIL_DrawTextRecord(p,&((BeaconDetailWork *)p)->msg20,((BeaconDetailWork *)p)->bmp1C,second,0,16);
            BEACON_DETAIL_DrawTextRecord(p,&((BeaconDetailWork *)p)->msg20,((BeaconDetailWork *)p)->bmp1C,first,0,0);
            STRBUF_Delete((struct Strbuf *)second);
            STRBUF_Delete((struct Strbuf *)first);
            ((BeaconDetailWork *)p)->angleX=((BeaconDetailWork *)p)->records[selected].x;
            ((BeaconDetailWork *)p)->angleY=((BeaconDetailWork *)p)->records[selected].y;
        } else ((BeaconDetailWork *)p)->detailOpen=0;
    }
    BMP_WIN_TransferChars(((BeaconDetailWork *)p)->bmp1C);
}

void BEACON_DETAIL_Create3DObjects(char *p, void *arc)
{
    unsigned i;
    char *row;
    ((BeaconDetailWork *)p)->resArc[0]=G3D_SYSTEM_CreateResourceArc(197,0);
    G3D_SYSTEM_TransVramTexture((struct G3dResource *)(*(int * *)&((BeaconDetailWork *)p)->resArc[0]));
    ((BeaconDetailWork *)p)->render[0]=G3D_SYSTEM_CreateRender(((BeaconDetailWork *)p)->resArc[0],0,((BeaconDetailWork *)p)->resArc[0]);
    ((BeaconDetailWork *)p)->object[0]=G3D_SYSTEM_CreateObject((G3dRender *)((BeaconDetailWork *)p)->render[0],0,0);
    for(i=0;i<4;i++) {
        row=p+d_02185E18[i].index*sizeof(void *);
        ((BeaconDetailWork *)row)->resArc[1]=G3D_SYSTEM_CreateResourceArc(197,d_02185E18[i].member);
        G3D_SYSTEM_TransVramTexture((struct G3dResource *)(*(int * *)&((BeaconDetailWork *)row)->resArc[1]));
        ((BeaconDetailWork *)row)->render[1]=G3D_SYSTEM_CreateRender(((BeaconDetailWork *)row)->resArc[1],0,((BeaconDetailWork *)row)->resArc[1]);
        ((BeaconDetailWork *)row)->object[1]=G3D_SYSTEM_CreateObject((G3dRender *)((BeaconDetailWork *)row)->render[1],0,0);
    }
    BEACON_DETAIL_CreateCamera(p);
    BEACON_DETAIL_CreateLight(p);
}

void BEACON_DETAIL_Delete3DObjects(char *p)
{
    u32 i;
    char *row;
    G3D_CAMERA_Delete(((BeaconDetailWork *)p)->camera);
    G3D_LIGHT_DeleteSlots(((BeaconDetailWork *)p)->lightSet);
    G3D_SYSTEM_DeleteObject(((BeaconDetailWork *)p)->object[0]);
    G3D_SYSTEM_DeleteRender(((BeaconDetailWork *)p)->render[0]);
    G3D_SYSTEM_FreeVramTexture(((BeaconDetailWork *)p)->resArc[0]);
    G3D_SYSTEM_DeleteResource(((BeaconDetailWork *)p)->resArc[0]);
    for(i=0;i<4;i++) {
        G3D_SYSTEM_DeleteObject(((BeaconDetailWork *)p)->object[d_02185E18[i].index+1]);
        G3D_SYSTEM_DeleteRender(((BeaconDetailWork *)p)->render[d_02185E18[i].index+1]);
        G3D_SYSTEM_FreeVramTexture((struct G3dResource *)(((BeaconDetailWork *)p)->resArc[d_02185E18[i].index+1]));
        G3D_SYSTEM_DeleteResource(((BeaconDetailWork *)p)->resArc[d_02185E18[i].index+1]);
    }
    ((BeaconDetailWork *)p)->object[0]=0;
}

void BEACON_DETAIL_Init3DParams(u8 *p)
{
    ((BeaconDetailWork *)p)->light0.x = 0;
    ((BeaconDetailWork *)p)->light0.y = 0;
    ((BeaconDetailWork *)p)->light0.z = 0;
    ((BeaconDetailWork *)p)->light1.x = 0x1000;
    ((BeaconDetailWork *)p)->light1.y = 0x1000;
    ((BeaconDetailWork *)p)->light1.z = 0x1000;
    ((BeaconDetailWork *)p)->angleX = BEACON_DETAIL_START_ANGLE_X;
    ((BeaconDetailWork *)p)->angleY = BEACON_DETAIL_START_ANGLE_Y;
    ((BeaconDetailWork *)p)->angleZ = 0;
    ((BeaconDetailWork *)p)->light2.x = 0x1000;
    ((BeaconDetailWork *)p)->light2.y = 0x1000;
    ((BeaconDetailWork *)p)->light2.z = 0x1000;
}

void BEACON_DETAIL_CreateCamera(char *p)
{
    BeaconVec3 vec;
    u16 heap;
    heap=((BeaconDetailWork *)p)->heapId;
    vec=d_02185F00;
    ((BeaconDetailWork *)p)->camera=G3D_CAMERA_Create(0,d_020A1EB8.x,d_020A1EB8.y,5461,0,4096,4194304,0,(struct VecFx32 *)(((BeaconVec3 *)&d_02185E0C)),(struct VecFx32 *)(&vec),(struct VecFx32 *)(((BeaconVec3 *)&d_02185DF4)),heap);
    G3D_CAMERA_Reset(((BeaconDetailWork *)p)->camera);
}

/*
 * note 2026-10-05 (wD6 lane16): EXACT. The flag block is an if/else-if chain with h == 0 first; tail merging of the duplicate stores gives the bne/b pairs.
 */
void BEACON_DETAIL_SetupCamera(char *p)
{
    u32 a = 0;
    u32 b = 0x19 << 14;
    G3D_CAMERA_SetEye(((BeaconDetailWork *)p)->camera, (struct VecFx32 *)(((BeaconVec3 *)&d_02185E0C)));
    G3D_CAMERA_SetCamTarget(((BeaconDetailWork *)p)->camera, (struct VecFx32 *)(((BeaconVec3 *)&d_02185DF4)));
    G3D_CAMERA_SetFovySin(((BeaconDetailWork *)p)->camera, d_020A1C78.a);
    G3D_CAMERA_SetFovyCos(((BeaconDetailWork *)p)->camera, d_020A1C78.b);
    G3D_CAMERA_SetNear(((BeaconDetailWork *)p)->camera, &a);
    G3D_CAMERA_SetFar(((BeaconDetailWork *)p)->camera, &b);
    if (((BeaconDetailWork *)p)->viewMode == 0)
        ((BeaconDetailWork *)p)->zoomMode = 1;
#if LANGUAGE == LANGUAGE_JAPANESE
    else
        ((BeaconDetailWork *)p)->zoomMode = 0;
#else
#if LANGUAGE == LANGUAGE_ENGLISH
    else if (((BeaconDetailWork *)p)->nation == 0)
        ((BeaconDetailWork *)p)->zoomMode = 0;
#endif
    else if (((BeaconDetailWork *)p)->nation == 0xdc)
        ((BeaconDetailWork *)p)->zoomMode = 0;
    else
        ((BeaconDetailWork *)p)->zoomMode = 1;
#endif
    while (BEACON_DETAIL_UpdateCamera(p) != 1)
        ;
}

void BEACON_DETAIL_CreateLight(char *p)
{
    ((BeaconDetailWork *)p)->lightSet = G3D_LIGHT_CreateSlots((struct LightSetDesc *)d_02185DD4, (unsigned short)((BeaconDetailWork *)p)->heapId);
    G3D_LIGHT_ApplySlots(((BeaconDetailWork *)p)->lightSet);
}

static inline int sine(u16 a) {return FX_SinCosTable_[(a>>4)*2];}

static inline int cosine(u16 a) {return FX_SinCosTable_[(a>>4)*2+1];}

void BEACON_DETAIL_SetupCalc(Matrix *p,int *angles)
{
    Matrix temp;
    MTX_RotY33_(p,sine(angles[1]),cosine(angles[1]));
    MTX_RotX33_(&temp,sine(angles[0]),cosine(angles[0]));
    MTX_Concat33((union MtxFx33 *)p,(union MtxFx33 *)(&temp),(union MtxFx33 *)p);
    MTX_RotZ33_(&temp,sine(angles[2]),cosine(angles[2]));
    MTX_Concat33((union MtxFx33 *)p,(union MtxFx33 *)(&temp),(union MtxFx33 *)p);
}

void BEACON_DETAIL_SetupRecordCalc(Matrix *p,int *angles)
{
    Matrix temp;
    MTX_RotY33_(p,sine(angles[0]),cosine(angles[0]));
    MTX_RotX33_(&temp,sine(-angles[1]),cosine(-angles[1]));
    MTX_Concat33((union MtxFx33 *)p,(union MtxFx33 *)(&temp),(union MtxFx33 *)p);
    MTX_RotZ33_(&temp,cosine(angles[2]),sine(angles[2]));
    MTX_Concat33((union MtxFx33 *)p,(union MtxFx33 *)(&temp),(union MtxFx33 *)p);
}

int BEACON_DETAIL_MoveCursor(u8 *p, u32 a, u32 b)
{
    int d0, d1;
    int res = 0;
    int x = (short)((BeaconDetailWork *)p)->angleX;
    int y = (short)((BeaconDetailWork *)p)->angleY;

    if ((a & 1) || (((BeaconDetailWork *)p)->inputFlag & 1)) {
        if (((BeaconDetailWork *)p)->viewMode == 1) {
            if (((BeaconDetailWork *)p)->zoomMode == 0)
                ((BeaconDetailWork *)p)->zoomMode = 1;
            else
                ((BeaconDetailWork *)p)->zoomMode = 0;
        }
        return 1;
    }
    if (((BeaconDetailWork *)p)->zoomMode == 0) {
        if (((BeaconDetailWork *)p)->moveX != 0 || ((BeaconDetailWork *)p)->moveY != 0) {
            d0 = (u16)(0x55 * ((BeaconDetailWork *)p)->moveX);
            d1 = (u16)(0x55 * ((BeaconDetailWork *)p)->moveY);
        } else {
            d0 = 0x200;
            d1 = 0x200;
        }
    } else {
        if (((BeaconDetailWork *)p)->moveX != 0 || ((BeaconDetailWork *)p)->moveY != 0) {
            d0 = (u16)(0xa * ((BeaconDetailWork *)p)->moveX);
            d1 = (u16)(0xa * ((BeaconDetailWork *)p)->moveY);
        } else {
            d0 = 0x20;
            d1 = 0x20;
        }
    }
    if ((b & 0x20) || (((BeaconDetailWork *)p)->inputFlag & 0x20)) {
        if (((BeaconDetailWork *)p)->viewMode == 1) {
            ((BeaconDetailWork *)p)->angleY += d0;
        } else if (y < -10208) {
            ((BeaconDetailWork *)p)->angleY += d0;
        }
        res = 1;
    }
    if ((b & 0x10) || (((BeaconDetailWork *)p)->inputFlag & 0x10)) {
        if (((BeaconDetailWork *)p)->viewMode == 1) {
            ((BeaconDetailWork *)p)->angleY -= d0;
        } else if (y > -13184) {
            ((BeaconDetailWork *)p)->angleY -= d0;
        }
        res = 1;
    }
    if ((b & 0x40) || (((BeaconDetailWork *)p)->inputFlag & 0x40)) {
        if (((BeaconDetailWork *)p)->viewMode == 1) {
            if (x + d1 < 0x3E00)
                ((BeaconDetailWork *)p)->angleX += d1;
            else
                ((BeaconDetailWork *)p)->angleX = 0x3E00;
        } else if (x < 0x2020) {
            ((BeaconDetailWork *)p)->angleX += d1;
        }
        res = 1;
    }
    if ((b & 0x80) || (((BeaconDetailWork *)p)->inputFlag & 0x80)) {
        if (((BeaconDetailWork *)p)->viewMode == 1) {
            if (x - d1 > -15872)
                ((BeaconDetailWork *)p)->angleX -= d1;
            else
                ((BeaconDetailWork *)p)->angleX = -15872;
        } else if (x > 0x1300) {
            ((BeaconDetailWork *)p)->angleX -= d1;
        }
        res = 1;
    }
    return res;
}

int BEACON_DETAIL_UpdateCamera(char *p)
{
    BeaconDetailVec position,target,direction;
    long distance;
    int done;
    done=0;
    G3D_CAMERA_GetEye(((BeaconDetailWork *)p)->camera,(struct VecFx32 *)(&position));
    G3D_CAMERA_GetCamTarget(((BeaconDetailWork *)p)->camera,(struct VecFx32 *)(&target));
    VEC_Subtract(&position,&target,&direction);
    distance=VEC_Mag((struct VecFx32 *)(&direction));
    VEC_Normalize(&direction,&direction);
    switch(((BeaconDetailWork *)p)->zoomMode) {
    case 1:
        if(distance>360448) {
            distance-=32768;
            ((BeaconDetailWork *)p)->light2.x-=128;
            ((BeaconDetailWork *)p)->light2.y=((BeaconDetailWork *)p)->light2.x;
        } else {distance=327680;done=1;}
        break;
    case 0:
        if(distance<1179648) {
            distance+=32768;
            ((BeaconDetailWork *)p)->light2.x+=128;
            ((BeaconDetailWork *)p)->light2.y=((BeaconDetailWork *)p)->light2.x;
        } else {distance=1212416;done=1;}
        break;
    }
    VEC_MultAdd(distance,&direction,&target,&position);
    G3D_CAMERA_SetEye(((BeaconDetailWork *)p)->camera,(struct VecFx32 *)&position);
    return done;
}

void BEACON_DETAIL_Draw3D(char *p)
{
    int state = ((BeaconDetailWork *)p)->drawState;

    switch (state) {
    case 0:
        break;
    case 2:
        G3D_SYSTEM_DrawStart();
        G3D_SYSTEM_DrawEnd();
        ((BeaconDetailWork *)p)->drawState = 0;
        break;
    case 1: {
        M33 m;
        BeaconDetailPair s;
        M33 m2;
        BeaconDetailPair s2;
        u32 i;

        G3D_LIGHT_ApplySlots(((BeaconDetailWork *)p)->lightSet);
        G3D_CAMERA_Reset(((BeaconDetailWork *)p)->camera);
        G3D_SYSTEM_DrawStart();
        G3D_SYSTEM_ApplyLookAt();
        s.a = ((BeaconDetailWork *)p)->light0;
        MTX_Identity33_(&m);
        s.b = ((BeaconDetailWork *)p)->light2;
        G3D_SYSTEM_DrawObject((void *)(((BeaconDetailWork *)p)->object[5]), (struct G3dObjectStatus *)(&s));
        s.b = ((BeaconDetailWork *)p)->light1;
        BEACON_DETAIL_SetupCalc((Matrix *)&m, ((BeaconDetailWork *)p)->angles);
        G3D_SYSTEM_DrawObject((void *)(((BeaconDetailWork *)p)->object[0]), (struct G3dObjectStatus *)(&s));
        s2.a = ((BeaconDetailWork *)p)->light0;
        s2.b = ((BeaconDetailWork *)p)->light2;
        for (i = 0; i < ((BeaconDetailWork *)p)->recordCount; i++) {
            u16 f;
            MTX_Concat33((union MtxFx33 *)&((BeaconDetailWork *)p)->records[i].matrix, (union MtxFx33 *)&m, (union MtxFx33 *)&m2);
            f = ((BeaconDetailWork *)p)->records[i].state;
            if (f != 0)
                G3D_SYSTEM_DrawObject((void *)(((BeaconDetailWork *)p)->object[f+1]), (struct G3dObjectStatus *)(&s2));
        }
        G3D_SYSTEM_DrawEnd();
        break;
    }
    }
}

/*
 * prototype: caller explicitly truncatesB5B38 member/heap at secondsite; useu16extern for those observed narrow inputs.4790 is tailstubto02025B3C readingonlykey.
 */
int BEACON_DETAIL_GetEntryText(unsigned key,unsigned optional,void *first,void *second,unsigned heap)
{
    unsigned index;
    void *bank;
    int found;
    index=BEACON_DETAIL_GetRecordIndex(key);
    found=0;
    bank=MSGDATA_CreateFromArchive(0,2,231,heap);
    MSGDATA_ReadString(bank,key,first);
    MSGDATA_Delete(bank);
    if(index==0) {index=1;optional=0;}
    else found=1;
    bank=MSGDATA_CreateFromArchive(0,2,NATION_AREA_GetAreaMsgBankByIndex(index),heap);
    MSGDATA_ReadString(bank,optional,second);
    MSGDATA_Delete(bank);
    return found;
}

int BEACON_DETAIL_HasEntry(int a)
{
    return BEACON_DETAIL_GetRecordIndex(a) != 0;
}

static inline int absolute(int a)
{
    return a<0?-a:a;
}

void BEACON_DETAIL_WrapAngle(int *p)
{
    if(p[0]>=0) p[0]%=65535;
    else p[0]+=(absolute(p[0])/65535+1)*65535;
    if(p[1]>=0) p[1]%=65535;
    else p[1]+=(absolute(p[1])/65535+1)*65535;
}

int BEACON_DETAIL_CalcDistance(int *p, int *q)
{
    int dx = p[0] - q[0];
    int dy;

    if (dx < 0)
        dx = -dx;
    dy = p[1] - q[1];
    if (dy < 0)
        dy = -dy;
    if (dx > GF_STANDARD_DegToAngle(180))
        dx = 0xFFFF - dx;
    if (dy > GF_STANDARD_DegToAngle(180))
        dy = 0xFFFF - dy;
    return FX_Sqrt((dx * dx + dy * dy) << 12) >> 12;
}
