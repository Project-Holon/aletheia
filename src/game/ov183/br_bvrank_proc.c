/*
 * file:     br_bvrank_proc.c
 * unit:     yes
 * function: BR_CODEIN_ListCreate, BR_CODEIN_ListDestroy, BR_CODEIN_ListMain, BR_CODEIN_ListSetupText, BR_CODEIN_ListSetupRowA, BR_CODEIN_ListSetupRowB, BR_CODEIN_ListSetupRowC, BR_CODEIN_ListSetupRowD, BR_CODEIN_ListTeardown, BR_CODEIN_ListSetupButtons, BR_CODEIN_ListDeleteButtons, BR_CODEIN_ListHitButton, BR_CODEIN_ListIsEventA, BR_CODEIN_ListIsEventB, BR_CODEIN_ListIsEventC, BR_CODEIN_ListCreateActor, BR_CODEIN_ListDeleteActor, BR_CODEIN_ListSetActorAnim, BR_CODEIN_ResultCreate, BR_CODEIN_ResultDestroy, BR_CODEIN_ResultMain, BR_CODEIN_ResultSetupTextWin, BR_CODEIN_ResultSetupRowA, BR_CODEIN_ResultSetupRowB, BR_CODEIN_ResultSetupRowC, BR_CODEIN_ResultTeardown, BR_CODEIN_ResultSetupButtons, BR_CODEIN_ResultDeleteButtons, BR_CODEIN_ResultHitButton, BR_CODEIN_StatCreate, BR_CODEIN_StatDestroy, BR_CODEIN_StatMain, BR_CODEIN_StatSetup, BR_CODEIN_StatTeardown, BR_CODEIN_StatStepFadeIn, BR_CODEIN_StatStepFadeOut, BR_CODEIN_StatStepMenu, BR_CODEIN_SearchStep, BR_CODEIN_SearchStepText, BR_CODEIN_SearchStepFade, BR_CODEIN_SearchCreateList, BR_CODEIN_SearchDeleteList, BR_CODEIN_SearchMainList, BR_CODEIN_SearchGetHitId, BR_CODEIN_SearchCreateActor, BR_CODEIN_SearchDeleteActor, BR_CODEIN_SearchUpdateActor, BR_CODEIN_SearchBuildHeader, BR_CODEIN_SearchHitBox
 * address:  0x021DD37C
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BR_PROC_SYS_GetSlotId 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BR_UTIL_CreateHandles 0x021FD760 thumb ov186
 *   BR_UTIL_SetHandlesAnimSeq 0x021FD940 thumb ov186
 *   BR_UTIL_CreateTask 0x021FD6D8 thumb ov186
 *   BR_UTIL_DeleteHandles 0x021FD820 thumb ov186
 *   BR_UTIL_DeleteTask 0x021FD714 thumb ov186
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   BR_UTIL_RunTask 0x021FD71C thumb ov186
 *   BR_UTIL_RunHandles 0x021FD854 thumb ov186
 *   BR_UTIL_IsTaskIdle 0x021FD72C thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_UTIL_IsEffectDone 0x021FD938 thumb ov186
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_UTIL_SetTextFromMessage 0x021FC754 thumb ov186
 *   BR_FADE_StartTimed 0x021FE794 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_UTIL_Delete 0x021FC734 thumb ov186
 *   BR_SIDEBAR_StartBounce 0x021FEE24 thumb ov186
 *   BR_PROC_SYS_PushEntry 0x021F9BF4 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_UTIL_FlushText 0x021FC830 thumb ov186
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BR_SIDEBAR_StartSlide 0x021FEE74 thumb ov186
 *   BR_PROC_SYS_PopEntry 0x021F9BA0 thumb ov186
 *   BR_SIDEBAR_ResetPositions 0x021FEE9C thumb ov186
 *   BR_SIDEBAR_StartWobble 0x021FEE4C thumb ov186
 *   BR_UTIL_ClearTaskStep 0x021FD744 thumb ov186
 *   BR_RES_ReleaseUiPalette 0x021FC1F8 thumb ov186
 *   BR_RES_LoadUiPalette 0x021FC148 thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_BTN_Create 0x021F9CB8 thumb ov186
 *   BR_FADE_SetBlendLevel 0x021FE840 thumb ov186
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   BR_BTN_Delete 0x021F9F48 thumb ov186
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_BTN_GetPressed 0x021FA018 thumb ov186
 *   BR_BTN_UpdatePrint 0x021F9FE8 thumb ov186
 *   BR_BTN_GetPlacement 0x021FA004 thumb ov186
 *   BR_BTN_GetResultValue 0x021FA01C thumb ov186
 *   BR_RES_GetPalSet 0x021FC238 thumb ov186
 *   BR_RES_SetPalSet 0x021FC230 thumb ov186
 *   BR_RES_GetCurrentSetParam 0x021FC224 thumb ov186
 *   BR_FADE_SetBlendColor 0x021FE7F4 thumb ov186
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021E3280 0x021E3280 data a4
 *   BR_RES_LoadFadePalettes  0x021FC240  thumb  ov186
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   BATTLE_REC_GetHeader 0x0200B928 thumb
 *   BATTLE_REC_GetWork 0x0200B910 thumb
 *   BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   GAME_DATA_IsSaving 0x02012E40 thumb
 *   BR_NET_HandleNetError 0x021FF88C thumb ov186
 *   BR_PROC_SYS_FlushWindows 0x021F9C6C thumb ov186
 *   BR_UTIL_MainProfileScreen 0x021FD6B0 thumb ov186
 *   BR_UTIL_FlushWindow 0x021FD1BC thumb ov186
 *   BR_BTN_HitTestWithSound 0x021FB4B4 thumb ov186
 *   BR_PROC_SYS_SetupWindow 0x021F9C50 thumb ov186
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   BR_NET_StartRequest 0x021FF54C thumb ov186
 *   BR_NET_IsIdle 0x021FF648 thumb ov186
 *   BR_NET_PollErrorMessage 0x021FF72C thumb ov186
 *   BR_NET_GetVideoReply 0x021FF698 thumb ov186
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_REC_SetData 0x0200B938 thumb
 *   GFL_USE_IsSeqPlaying 0x02006254 thumb
 *   GDS_RAP_SaveVideoSecured 0x021D7630 thumb ov125
 *   d_021E3960 0x021E3960 data a1
 *   GF_PANIC_Fail 0x02034714 arm
 *   BATTLE_REC_DecodeWork 0x0200B490 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   BR_RES_GetWordSet 0x021FC21C thumb ov186
 *   BR_UTIL_SetTextLayout 0x021FC868 thumb ov186
 *   BR_UTIL_SetTextFromBuffer 0x021FC7C4 thumb ov186
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   GDS_PROFILE_CreateNameStr 0x0200D6D0 thumb
 *   GDS_PROFILE_GetEggFlag 0x0200D6EC thumb
 *   GDS_PROFILE_ExportRecord 0x0200D774 thumb
 *   WORDSET_SetSlotTag 0x0201EE0C thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   _ll_udiv 0x0209C00C arm
 *   _ull_mod 0x0209C018 arm
 *   d_021E32C8 0x021E32C8 data a4
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   POKE_TOOL_GetIconPaletteArcId 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   POKE_TOOL_GetIconCellArcId 0x0201BC40 thumb
 *   POKE_TOOL_GetIconCellEntryId 0x0201BCB4 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   d_021E32F0 0x021E32F0 data a2
 *   BR_UTIL_CreateProfileScreen 0x021FD1C4 thumb ov186
 *   BR_UTIL_DeleteProfileScreen 0x021FD640 thumb ov186
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_BTN_CreateFromMessage 0x021FB378 thumb ov186
 *   BR_BTN_DeleteObject 0x021FB494 thumb ov186
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   d_021E32A8 0x021E32A8 data a4
 *   BSUBWAY_SCOREDATA_GetBattlePoints 0x0200DABC thumb
 *   d_021E3350 0x021E3350 data a4
 *   BSUBWAY_SCOREDATA_HasCleared 0x0200DB44 thumb
 *   BSUBWAY_SCOREDATA_GetWinCount 0x0200DAC4 thumb
 *   BSUBWAY_SCOREDATA_GetMaxWinCount 0x0200DAD8 thumb
 *   d_021E33C0 0x021E33C0 data a4
 *   d_021E3400 0x021E3400 data a4
 *   d_021E3490 0x021E3490 data a4
 *   BSUBWAY_SCOREDATA_GetLevel 0x0200DC08 thumb
 *   d_021E338C 0x021E338C data a4
 *   d_021E336C 0x021E336C data a4
 *   d_021E3440 0x021E3440 data a4
 *   BSUBWAY_SCOREDATA_AccessFlag 0x0200DBA0 thumb
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   d_021E3358 0x021E3358 data a4
 *   BSUBWAY_SAVEDATA_GetStat 0x0200DFD8 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   d_021E3574 0x021E3574 data a4
 *   d_021E3664 0x021E3664 data a4
 *   d_021E35D4 0x021E35D4 data a4
 *   MSGDATA_ReadString 0x02045CAC arm
 *   d_021E351C 0x021E351C data a4
 *   d_021E3534 0x021E3534 data a4
 *   d_021E3964 0x021E3964 data a1
 *   BR_NET_GetSearchResultsForRanking 0x021FF6DC thumb ov186
 *   BR_NET_GetSearchResultsForNewest 0x021FF704 thumb ov186
 *   BR_NET_GetSearchResults 0x021FF6B4 thumb ov186
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BR_UTIL_CreateListMenu 0x021FC8C8 thumb ov186
 *   BMP_Create 0x02043678 arm
 *   BMP_Clear 0x02043B5C arm
 *   STRBUF_SetString 0x02045924 arm
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BR_UTIL_SetListItemBitmap 0x021FCDAC thumb ov186
 *   BR_UTIL_RefreshList 0x021FCE50 thumb ov186
 *   d_021E3700 0x021E3700 data a4
 *   BR_UTIL_GetListMenuField 0x021FCE0C thumb ov186
 *   BR_UTIL_GetListItemBitmap 0x021FCDE8 thumb ov186
 *   BMP_Delete 0x020437AC arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   BR_UTIL_DeleteListMenu 0x021FCC80 thumb ov186
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   BR_UTIL_MainListMenu 0x021FCD0C thumb ov186
 *   BR_UTIL_GetListMenuHitId 0x021FCDA8 thumb ov186
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   CLACT_GetActorPaletteOffset 0x0204B714 arm
 *   CLACT_SetActorImageProxy 0x0204B784 arm
 *   ARC_UTIL_LoadScreenDataFromHandle 0x02049E74 arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   CLACT_GetCharacterProxy 0x0204AB84 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   d_021E37A8 0x021E37A8 data a4
 *   d_021E3734 0x021E3734 data a2
 *   d_021E3740 0x021E3740 data a4
 *   MYSTATUS_GetNation 0x0200856C thumb
 *   MYSTATUS_GetArea 0x02008570 thumb
 *   BR_BTN_TestHitBox 0x021FB4CC thumb ov186
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   d_021E3758 0x021E3758 data a4
 *   d_021E3728 0x021E3728 data a4
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   BR_POKESEARCH_Create 0x021FFBD4 thumb ov186
 *   BR_POKESEARCH_Open 0x021FFE5C thumb ov186
 *   BR_POKESEARCH_UpdatePrint 0x021FFE34 thumb ov186
 *   BR_POKESEARCH_Close 0x021FFE70 thumb ov186
 *   BR_POKESEARCH_Destroy 0x021FFC6C thumb ov186
 *   BR_POKESEARCH_Main 0x021FFC9C thumb ov186
 *   BR_POKESEARCH_GetResult 0x021FFE90 thumb ov186
 *   BMP_MENUWORK_AddStrItem 0x0201F898 thumb
 *   NATION_AREA_GetAreaCount 0x02025B64 thumb
 *   WORDSET_SetSlotFromMsgE7 0x0201F048 thumb
 *   WORDSET_SetSlotFromKeyedMessage 0x0201F094 thumb
 *   d_021E3780 0x021E3780 data a4
 *   d_021E372E 0x021E372E data a4
 *   d_021E37D8 0x021E37D8 data ov183
 *   gSpeciesNameBank 0x020A7370 data a4
 *   g_021E3808     0x021E3808  data  ov183
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_021E3968 0x021E3968 data ov183
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   d_021E3974 0x021E3974 data a4
 *   d_021E3978 0x021E3978 data ov183
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   BMP_OAM_Delete 0x0202570C thumb
 *   d_021E3850 0x021E3850 data a4
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_OAM_Create 0x020255A0 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 *   BMP_OAM_SetObjMode 0x0202597C thumb
 *   d_021E3868 0x021E3868 data a4
 *   BUTTON_MAN_UpdateSlots 0x02051C88 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   d_021E3998 0x021E3998 data a4
 *   d_021E397C 0x021E397C data a4
 *   d_021E3858 0x021E3858 data a4
 *   STRBUF_Append 0x02045AA8 arm
 *   WORDSET_FormatNumber 0x0201F35C thumb
 *   _ull_mul 0x0209C054 arm
 *   d_021E3880 0x021E3880 data a2
 *   BUTTON_MAN_Create 0x02051B84 arm
 *   d_021E38E0 0x021E38E0 data a4
 *   BATTLE_REC_Load 0x0200B570 thumb
 *   BR_NET_GetUploadedDataNumber 0x021FF67C thumb ov186
 *   BR_UTIL_SetWindowTextBuf 0x021FD19C thumb ov186
 *   d_021E39B4 0x021E39B4 data a4
 *   GDS_RAP_StartVideoSave 0x021D76A8 thumb ov125
 *   GDS_RAP_StepVideoSave 0x021D76D8 thumb ov125
 *   d_021E3900 0x021E3900 data a4
 *   BR_CODEIN_SOCL_InitDefault 0x021E2F98 thumb ov183
 *   BR_CODEIN_GetMenuCallbacks 0x021E300C thumb ov183
 *   BR_CODEIN_HitTestOptionLeft 0x021E31E8 thumb ov183
 *   BR_CODEIN_HitTestOptionRight 0x021E3228 thumb ov183
 *   GDS_RAP_SaveVideoSeq 0x021D7540 thumb ov125
 *   d_021E3910 0x021E3910 data a4
 *   d_021E3928 0x021E3928 data a4
 */
#include "br_codein_types.h"

struct BrProcQuery;
struct Proc;
struct Proc;
struct PrintQueue;
struct Obj;
struct Node;
struct BattleRecSave;
struct GameData;
struct ClactActor;
struct BsubwayScoreData;
struct MsgBank;
struct Strbuf;
struct WordSet;
struct GameData;
struct Bmp;
struct CharBuf;
struct State;
struct Strbuf;
struct Strbuf;
struct ImageProxy;
struct NNSG2dCharacterData;
struct Sub0200852CObj;
struct BrCodeinObject;
struct ClactVec2;
struct ClactVec2;
struct BmpOam;
struct BmpOamSys;
struct BmpOamParam;
struct ButtonMan;
#include "../types.h"
#include "../version.h"
#include "../ov183/br_codein_rec.h"

typedef struct {char pad[0x4c];char saved[0x18];int count;void *ptr;} CodeinWindowState;

typedef struct CodeinProcEntry CodeinProcEntry;

typedef struct {u8 x,y,w,h;u32 message;} CodeinMenuItem;

typedef struct Strbuf U16Vec;

typedef struct MsgBank MsgBank;

typedef struct WordSet WordSet;

typedef struct GdsProfileRaw GdsProfile;

typedef struct GdsRecord GdsRecord;

typedef struct StoredMon RecGet;

typedef struct {s16 x,y,z;u8 a,b;} Position;

typedef struct {s16 x,y;} Point16;

typedef struct BrCodeinTriple { int a,b,c; } BrCodeinTriple;

typedef struct Point { u32 x,y; } Point;

typedef struct BrCodeinRect { u32 x0, y0, x1, y1; } BrCodeinRect;

typedef u16 Row[3];


typedef struct BrMenuItem BrCodeinItem;

typedef struct BrListMenuConfig CodeinListMenuConfig;

typedef struct BrCodeinObject CfgTpl;


typedef struct BmpMenuWorkSlot { u32 a,b; } BmpMenuWorkSlot;


struct BrCodeinPos { u16 x; short y; u16 z; u8 a,b; };

struct Entries { u32 species[6],form[6],gender[6]; };

struct BrCodeinRec { u32 w[9]; };

struct BrCodeinSub { u8 pad[16]; u32 size,data; };

struct CodeinCodeWork;
struct BrProcArgSave;
typedef int (*Method)(struct CodeinCodeWork *,struct BrProcArgSave *);

struct Methods { Method init,update,finish; };

typedef struct Rec6 { u8 x,y,id,pad; u16 file; } Rec6;

struct Rec8 { u8 a,b,c,d; u32 value; };

typedef struct {u16 a,b,c;u8 flag,pad;} BrCodeinParams;

typedef struct BrCodeinRecord { u8 a, b, c, d; int value; } BrCodeinRecord;


struct PosParams {s16 x,y,a,b,z;u8 mode,flag;};

typedef struct {s16 a,b,x,y;} Coords;

typedef struct {void *handle; short x,y; unsigned data,zero; u8 a,b; u16 c; unsigned d;} CodeinProfileDescriptor;


typedef struct 
{
  int v[3];
} CodeinProfileRow;

typedef struct 
{
  CodeinProfileRow row[2];
} CodeinProfileTable;


typedef struct {short a,b,c,d;} CodeinTableRow;

typedef struct {CodeinTableRow row[12];} CodeinTable;


typedef struct { u8 a,b,c,d; u32 value; } BrCodeinRec;

#include "br_codein.h"
#include "br_bvrank_proc.h"
/* Declared here: CfgTpl is not visible in the header. */
struct CodeinProfileWork *BR_CODEIN_ProfileCreate(const CfgTpl *src, u16 heap);

typedef struct {u32 fields[7];Point request;} BrCodeinArg;

typedef union CodeinProfileConfig {u64 wide;Point pair;} CodeinProfileConfig;


#include "../ov186/br_proc_sys.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
#include "../arm9/printsys.h"
#include "../ov186/br_util.h"
#include "../ov186/br_res.h"
/* The DS code passes the blend colour as a word (the original prototype); the definition takes a halfword. The host build uses the header. */
#ifdef __MWERKS__
#define BR_FADE_SetBlendColor BR_FADE_SetBlendColor_header
#endif
#include "../ov186/br_fade.h"
#ifdef __MWERKS__
#undef BR_FADE_SetBlendColor
extern void BR_FADE_SetBlendColor(struct BrFade *fade, int color);
#endif
#include "../arm9/gfl_use.h"
#include "../arm9/bg_sys.h"
#include "../arm9/touchpanel.h"
extern int BR_BTN_GetPressed(char *),BR_BTN_GetResultValue(char *);
#include "../arm9/tcb_list.h"
/* The DS code also passes the save control as a fourth argument (the definition takes three); the host build calls it with three. The save control is still fetched on the DS. */
#ifdef __MWERKS__
#define BATTLE_REC_SetData BATTLE_REC_SetData_header
#endif
#include "../arm9/battle_rec.h"
#ifdef __MWERKS__
#undef BATTLE_REC_SetData
extern void BATTLE_REC_SetData(const void *profile, const struct BattleRecHeader *head, const struct BattleRecBody *body, struct SaveControl *saveControl);
#endif
#include "../arm9/game_data.h"
/* The DS code passes the heap id as a word (the original prototype); the header takes a byte. The host build uses the header. */
#ifdef __MWERKS__
#define GDS_RAP_StartVideoSave GDS_RAP_StartVideoSave_header
#endif
#include "../ov125/gds_rap.h"
#include "../ov125/gds_rap_response.h"
#ifdef __MWERKS__
#undef GDS_RAP_StartVideoSave
extern void GDS_RAP_StartVideoSave(struct GameData *gameData, u32 heap, u32 id);
#endif
#include "../arm9/gf_panic.h"
/* The DS code passes the heap id as a halfword (the original prototype); the header takes a word. The host build uses the header. */
#ifdef __MWERKS__
#define STRBUF_Create STRBUF_Create_header
#endif
#include "../arm9/strbuf.h"
#ifdef __MWERKS__
#undef STRBUF_Create
extern struct Strbuf *STRBUF_Create(u32 capacity, u16 heapId);
#endif
#include "../arm9/gds_profile.h"
#include "../arm9/arc_tool.h"
extern int POKE_TOOL_GetIconPaletteArcId(void),POKE_TOOL_GetIconCellArcId(void),POKE_TOOL_GetIconCellEntryId(void);
extern u32 POKE_TOOL_CalcGraphicIndex(u32,u32,u32,u32),POKE_TOOL_CalcIconPalette(u32,u32,u32,u32);
#include "../arm9/zonedata.h"
typedef unsigned short StatRow;
#include "../arm9/bsubway_savedata.h"
#include "../arm9/gf_font.h"
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/poke_tool_ext.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/mystatus.h"
#include "../arm9/zukan_save.h"
#include "../arm9/species.h"
#include "../arm9/button_man.h"
#include "br_codein_socl.h"
#include "../arm9/arc_util.h"
#include "../arm9/bmp_oam.h"
#include "../arm9/clact.h"
#include "../arm9/msgdata.h"
#include "../arm9/wordset.h"
#include "../ov186/br_btn.h"
#include "../ov186/br_net.h"
#include "../ov186/br_pokesearch.h"
#include "../ov186/br_sidebar.h"
#include "../arm9/bmp_menuwork.h"
#if LANGUAGE == LANGUAGE_JAPANESE
extern const char str_ja_021E3920[];
extern const char str_ja_021E3934[];
extern const char str_ja_021E3964[];
extern const char str_ja_021E3978[];
extern const char str_ja_021E397C[];
extern const char str_ja_021E39A8[];
extern const char str_ja_021E39AC[];
extern const char str_ja_021E39B8[];
extern const char str_ja_021E39D8[];
extern const char str_ja_021E39F0[];
extern const char str_ja_021E3A04[];
extern const char str_ja_021E3A40[];
extern const char str_ja_021E3A54[];
#endif
extern int BR_CODEIN_HitTestOptionLeft(struct CodeinSoclWork *,int,int),BR_CODEIN_HitTestOptionRight(struct CodeinSoclWork *,int,int);
extern int d_021E3280[];
extern char d_021E3960[];
extern const CodeinMenuItem d_021E32C8[];
extern const Point16 d_021E32F0[];
extern const BrCodeinRecord d_021E32A8[];
extern const BrCodeinRecord d_021E3350[];
extern const BrCodeinRecord d_021E33C0[];
extern const BrCodeinRecord d_021E3400[];
extern const BrCodeinRecord d_021E3490[];
extern const BrCodeinRecord d_021E338C[];
extern const BrCodeinRecord d_021E336C[];
extern const BrCodeinRect d_021E3440[];
extern const u32 d_021E3358[];
extern const BrCodeinRecord d_021E3574[];
extern const BrCodeinRecord d_021E3664[];
extern const BrCodeinRecord d_021E35D4[];
extern const BrCodeinRecord d_021E351C[];
extern const BrCodeinRect d_021E3534[];
extern const char d_021E3964[];
extern const CfgTpl d_021E3700;
extern const struct Methods d_021E37A8[];
extern const struct Rec6 d_021E3734[];
extern const struct Rec8 d_021E3740[];
extern const CfgTpl d_021E3758;
extern const Rec6 d_021E3728[];
extern const CfgTpl d_021E3780;
extern const Rec6 d_021E372E[];
extern const BrCodeinRecord d_021E37D8[];
extern struct MsgBank *gSpeciesNameBank;
extern BrCodeinRect g_021E3808[];
extern char d_021E3968[];
extern char d_021E3974[];
extern char d_021E3978[];
extern const int d_021E3850[];
extern const CodeinProfileTable d_021E3868;
extern const int d_021E3998[],d_021E397C[];
extern const CodeinTable d_021E3880;
extern const Point d_021E38E0;
extern char d_021E39B4[];
extern const BrCodeinRec d_021E3900[];
extern const struct CodeinStoredFns d_021E3910[];
extern const unsigned char d_021E3928[];


/*
 * trailing: 2 zero alignment bytes at 0x021DD3F6
 */
int BR_CODEIN_ListCreate(void *proc, int unused, struct BrProcArgProfile *arg)
{
    struct CodeinListWork *p = PROCSYS_AllocProcWork(proc, sizeof(*p), BR_PROC_SYS_GetSlotId(arg->proc));
    MI_CpuFill8(p, 0, sizeof(*p));
    p->heapId = BR_PROC_SYS_GetSlotId(arg->proc);
    p->oamSys = BMP_OAM_CreateSys(p->heapId, (arg->unit));
    p->printQue = (void *)PRINTSYS_QUE_Create(p->heapId);
    p->listFx = BR_UTIL_CreateHandles((void *)(((arg->unit))), arg->res, 1, p->heapId);
    BR_RES_LoadSprite((struct BrRes *)(arg->res), 13, p->heapId);
    BR_CODEIN_ListSetupButtons(p, arg);
    BR_CODEIN_ListSetupText(p, arg);
    return 1;
}

int BR_CODEIN_ListDestroy(struct Proc *proc, int unused, struct BrProcArgProfile *arg, struct CodeinListWork *work)
{
    BR_CODEIN_ListDeleteButtons(work, arg);
    BR_CODEIN_ListTeardown(work, arg);
    BG_SYS_PushTile(4);
    BG_SYS_PushTile(1);
    BR_RES_ReleaseSprite((struct BrRes *)((char *)(arg->res)), 13);
    BR_UTIL_DeleteHandles(work->listFx);
    PRINTSYS_QUE_Delete(work->printQue);
    BMP_OAM_DeleteSys(work->oamSys);
    PROCSYS_FreeProcWork(proc);
    return 1;
}

/*
 * tail: 021DD5C6..021DD5C8 is two zero alignment bytes.
 */
int BR_CODEIN_ListMain(void *unused,u32 *state,struct BrProcArgProfile *arg,struct CodeinListWork *work)
{
 int x,y,i;
 Point pair;
 switch(*state){
 case 0:BR_FADE_Start((void *)(arg->fade),2,3,0);*state=1;break;
 case 1:if(BR_FADE_GetResult((struct BrFade *)(arg->fade))) *state=2;break;
 case 2:
  if(TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))){
   work->listChoice=BR_CODEIN_ListHitButton(work,x,y);
   if(work->listChoice) *state=3;
   if(BR_BTN_HitTestWithSound(work->backButton,x,y)){
    pair.x=x;pair.y=y;
    BR_UTIL_StartEffect((char *)((void *)(work->listFx)), 1, (const BrPair *)&pair);
    *state=7;
   }
  }break;
 case 3:BR_FADE_Start((void *)(arg->fade),2,1,1);++*state;break;
 case 4:if(BR_FADE_GetResult((struct BrFade *)(arg->fade))) ++*state;break;
 case 5:
  BR_CODEIN_ListTeardown(work,arg);
  switch(*(u32 *)&work->listChoice){
  case 1:BR_CODEIN_ListSetupRowA(work,arg);break;
  case 2:BR_CODEIN_ListSetupRowB(work,arg);break;
  case 3:BR_CODEIN_ListSetupRowC(work,arg);break;
  case 4:BR_CODEIN_ListSetupRowD(work,arg);break;
  }
  BR_FADE_Start((void *)(arg->fade),2,1,0);++*state;break;
 case 6:if(BR_FADE_GetResult((struct BrFade *)(arg->fade))) *state=2;break;
 case 7:BR_FADE_Start((void *)(arg->fade),2,3,1);*state=8;break;
 case 8:if(BR_FADE_GetResult((struct BrFade *)(arg->fade))) *state=9;break;
 case 9:BR_PROC_SYS_PopEntry(arg->proc);return 1;
 }
 for(i=0;i<4;i++) if(((struct CodeinListWork *)work)->buttonText[i]) BR_UTIL_FlushText(((struct CodeinListWork *)work)->buttonText[i]);
 for(i=0;i<16;i++) if(((struct CodeinListWork *)work)->rowText[i]) BR_UTIL_FlushText(((struct CodeinListWork *)work)->rowText[i]);
 PRINTSYS_QUE_Main(work->printQue);
 if((work->textWin))BR_UTIL_FlushWindow((work->textWin));
 BR_UTIL_RunHandles(work->listFx);
 return 0;
}

/*
 * lever: const record array at the table address restores early argument loads;
 *        a scalar record and const pointer local remained 22 bytes DIFF.
 */
void BR_CODEIN_ListSetupText(struct CodeinListWork *work, struct BrProcArgProfile *arg)
{
    void *first; void *second; int v;
    BrCodeinTriple triple;
    const BrCodeinRecord *rec;
    u8 a, b, c, d;
    first = BR_RES_GetFont((struct BrRes *)(arg->res));
    second = BR_RES_GetMsgData((struct BrRes *)(arg->res));
    BR_RES_LoadBgGraphics((void *)(arg->res), 14, work->heapId);
    rec = &d_021E3350[0];
    d = rec->d;
    a = rec->a;
    b = rec->b;
    c = rec->c;
    work->rowText[0] = BR_UTIL_Create(1, a, b, c, d, 14, (void *)work->printQue, work->heapId);
#if LANGUAGE != LANGUAGE_JAPANESE
    BR_UTIL_SetTextLayout((u8 *)work->rowText[0], 0, 1, 0);
#endif
    BR_UTIL_SetTextFromMessage((char *)work->rowText[0], (void *)second, rec->value, (void *)first, 0x3da0);
    (work->textWin) = BR_UTIL_CreateTextWin((void *)(arg->res), (void *)(work->printQue), work->heapId);
    BR_UTIL_SetWindowText((work->textWin), arg->res, 0x86);
    v = BSUBWAY_SCOREDATA_GetBattlePoints((struct BsubwayScoreData *)(arg->block));
    BR_RES_GetSprite((void *)(arg->res), 13, (BrCodeinTriple *)((BrCodeinTriple *)&triple));
    BR_CODEIN_ListCreateActor((void *)(&work->pointActors), (void *)(arg->unit), &triple, v, 0x68, 0x58, work->heapId);
}

void BR_CODEIN_ListSetupRowA(struct CodeinListWork *work,struct BrProcArgProfile *arg)
{
 void *first; void *second; void *third; int index, v;
 const BrCodeinRecord *rec;
 unsigned select;
 int number1,number2;
 void *obj;
 BrCodeinTriple triple;
 first=BR_RES_GetFont((struct BrRes *)(arg->res));
 second=BR_RES_GetMsgData((struct BrRes *)(arg->res));
 third=BR_RES_GetWordSet((struct BrRes *)(arg->res));
 BR_RES_LoadBgGraphics((void *)(arg->res),10,work->heapId);
 select=BR_CODEIN_ListIsEventA(arg->block,arg->gameData)?5:0;
 for(index=0;index<8;index++){
  rec=&d_021E33C0[index];work->rowText[index]=BR_UTIL_Create(1,rec->a,rec->b,rec->c,rec->d,14,work->printQue,work->heapId);
#if LANGUAGE != LANGUAGE_JAPANESE
  BR_UTIL_SetTextLayout(work->rowText[index],0,1,0);
#endif
  switch(index){
   case 1:
    obj=MSGDATA_AllocString((struct MsgBank *)second,BR_CODEIN_ListIsEventA(arg->block,arg->gameData)?0x83:0x7e);break;
   case 2:
    obj=MSGDATA_AllocString((struct MsgBank *)second,BSUBWAY_SCOREDATA_HasCleared(arg->block,select)?0x91:0x87);break;
   case 3:{
    void *base;
    number1=BSUBWAY_SCOREDATA_GetWinCount(arg->block,select);
    number1=(number1>9999)?9999:number1;
#if LANGUAGE == LANGUAGE_JAPANESE
    base=MSGDATA_AllocString((struct MsgBank *)second,d_021E33C0[index].value);
    obj=MSGDATA_AllocString((struct MsgBank *)second,d_021E33C0[index].value);
#else
    base=MSGDATA_AllocString((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,work->heapId);
#endif
    WORDSET_SetSlotNumber((void *)third,0,number1,4,1, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_CopyTaggedText((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   case 6:{
    void *base;
    number2=BSUBWAY_SCOREDATA_GetMaxWinCount(arg->block,select);
    number2=(number2>9999)?9999:number2;
#if LANGUAGE == LANGUAGE_JAPANESE
    base=MSGDATA_AllocString((struct MsgBank *)second,d_021E33C0[index].value);
    obj=MSGDATA_AllocString((struct MsgBank *)second,d_021E33C0[index].value);
#else
    base=MSGDATA_AllocString((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,work->heapId);
#endif
    WORDSET_SetSlotNumber((void *)third,0,number2,4,1, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_CopyTaggedText((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   default:obj=MSGDATA_AllocString((struct MsgBank *)second,rec->value);break;
  }
  BR_UTIL_SetTextFromBuffer(work->rowText[index],obj,(void *)first,0x3da0);
  STRBUF_Delete(obj);
 }
 v=BSUBWAY_SCOREDATA_GetBattlePoints(arg->block);
 BR_RES_GetSprite((void *)(arg->res), 13, (BrCodeinTriple *)((BrCodeinTriple *)&triple));
 BR_CODEIN_ListCreateActor(&work->pointActors,arg->unit,&triple,v,0xa0,0x20,work->heapId);
}

/*
 * note: 2026-10-05 wave P10 lane Y1. Twin of BR_CODEIN_ListSetupRowA (same body: other table d_021E3400, getter BR_CODEIN_ListIsEventB, selector 6/1, argument 11, strings 0x84/0x7f). 468 B; the 1140 B listing extent also holds BR_CODEIN_ListSetupRowC, filed separately. The clamps are n = (n > 9999) ? 9999 : n; as in the twin.
 */
void BR_CODEIN_ListSetupRowB(struct CodeinListWork *work,struct BrProcArgProfile *arg)
{
 void *first; void *second; void *third; int index, v;
 const BrCodeinRecord *rec;
 unsigned select;
 int number1,number2;
 void *obj;
 BrCodeinTriple triple;
 first=BR_RES_GetFont((struct BrRes *)(arg->res));
 second=BR_RES_GetMsgData((struct BrRes *)(arg->res));
 third=BR_RES_GetWordSet((struct BrRes *)(arg->res));
 BR_RES_LoadBgGraphics((void *)(arg->res),11,work->heapId);
 select=BR_CODEIN_ListIsEventB(arg->block,arg->gameData)?6:1;
 for(index=0;index<8;index++){
  rec=&d_021E3400[index];work->rowText[index]=BR_UTIL_Create(1,rec->a,rec->b,rec->c,rec->d,14,work->printQue,work->heapId);
#if LANGUAGE != LANGUAGE_JAPANESE
  BR_UTIL_SetTextLayout(work->rowText[index],0,1,0);
#endif
  switch(index){
   case 1:
    obj=MSGDATA_AllocString((struct MsgBank *)second,BR_CODEIN_ListIsEventB(arg->block,arg->gameData)?0x84:0x7f);break;
   case 2:
    obj=MSGDATA_AllocString((struct MsgBank *)second,BSUBWAY_SCOREDATA_HasCleared(arg->block,select)?0x91:0x87);break;
   case 3:{
    void *base;
    number1=BSUBWAY_SCOREDATA_GetWinCount(arg->block,select);
    number1=(number1>9999)?9999:number1;
#if LANGUAGE == LANGUAGE_JAPANESE
    base=MSGDATA_AllocString((struct MsgBank *)second,d_021E3400[index].value);
    obj=MSGDATA_AllocString((struct MsgBank *)second,d_021E3400[index].value);
#else
    base=MSGDATA_AllocString((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,work->heapId);
#endif
    WORDSET_SetSlotNumber((void *)third,0,number1,4,1, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_CopyTaggedText((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   case 6:{
    void *base;
    number2=BSUBWAY_SCOREDATA_GetMaxWinCount(arg->block,select);
    number2=(number2>9999)?9999:number2;
#if LANGUAGE == LANGUAGE_JAPANESE
    base=MSGDATA_AllocString((struct MsgBank *)second,d_021E3400[index].value);
    obj=MSGDATA_AllocString((struct MsgBank *)second,d_021E3400[index].value);
#else
    base=MSGDATA_AllocString((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,work->heapId);
#endif
    WORDSET_SetSlotNumber((void *)third,0,number2,4,1, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_CopyTaggedText((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   default:obj=MSGDATA_AllocString((struct MsgBank *)second,rec->value);break;
  }
  BR_UTIL_SetTextFromBuffer(work->rowText[index],obj,(void *)first,0x3da0);
  STRBUF_Delete(obj);
 }
 v=BSUBWAY_SCOREDATA_GetBattlePoints(arg->block);
 BR_RES_GetSprite((void *)(arg->res), 13, (BrCodeinTriple *)((BrCodeinTriple *)&triple));
 BR_CODEIN_ListCreateActor(&work->pointActors,arg->unit,&triple,v,0xa0,0x20,work->heapId);
}

/*
 * lever: bounded permuter rec/index declaration order, selector use and
 *        field-base expansion restore the three selector/index spill homes.
 */
void BR_CODEIN_ListSetupRowC(struct CodeinListWork *work,struct BrProcArgProfile *arg)
{
 void *first; void *second; void *third; int v;
 const BrCodeinRecord *rec;
 unsigned select, select2;
 int index;
 int number1,number2,number3,number4;
 void *obj;
 BrCodeinTriple triple;
 first=BR_RES_GetFont((struct BrRes *)(arg->res));
 second=BR_RES_GetMsgData((struct BrRes *)(arg->res));
 third=BR_RES_GetWordSet((struct BrRes *)(arg->res));
 BR_RES_LoadBgGraphics((void *)(arg->res),12,work->heapId);
 if(BR_CODEIN_ListIsEventC(arg->block,arg->gameData)){select=7;select2=8;}
 else{select=2;select2=3;}
 for(index=0;index<16;index++){
  rec=&d_021E3490[index];work->rowText[index]=BR_UTIL_Create(1,rec->a,rec->b,rec->c,rec->d,14,work->printQue,work->heapId);
#if LANGUAGE != LANGUAGE_JAPANESE
  BR_UTIL_SetTextLayout(work->rowText[index],0,1,0);
#endif
  switch(index){
   case 1:
    obj=MSGDATA_AllocString((struct MsgBank *)second,BR_CODEIN_ListIsEventC(arg->block,arg->gameData)?0x85:0x80);break;
   case 3:
    obj=MSGDATA_AllocString((struct MsgBank *)second,BSUBWAY_SCOREDATA_HasCleared(arg->block,select)?0x91:0x87);break;
   case 4:{
    void *base;
    number1=BSUBWAY_SCOREDATA_GetWinCount(arg->block,select);
    number1=(number1>9999)?9999:number1;
#if LANGUAGE == LANGUAGE_JAPANESE
    base=MSGDATA_AllocString((struct MsgBank *)second,d_021E3490[index].value);
    obj=MSGDATA_AllocString((struct MsgBank *)second,d_021E3490[index].value);
#else
    base=MSGDATA_AllocString((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,work->heapId);
#endif
    WORDSET_SetSlotNumber((void *)third,0,number1,4,1, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_CopyTaggedText((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   case 7:{
    void *base;
    number2=BSUBWAY_SCOREDATA_GetMaxWinCount(arg->block,select);
    number2=(number2>9999)?9999:number2;
#if LANGUAGE == LANGUAGE_JAPANESE
    base=MSGDATA_AllocString((struct MsgBank *)second,d_021E3490[index].value);
    obj=MSGDATA_AllocString((struct MsgBank *)second,d_021E3490[index].value);
#else
    base=MSGDATA_AllocString((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,work->heapId);
#endif
    WORDSET_SetSlotNumber((void *)third,0,number2,4,1, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_CopyTaggedText((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   case 10:
    obj=MSGDATA_AllocString((struct MsgBank *)second,BSUBWAY_SCOREDATA_HasCleared(arg->block,select2)?0x91:0x87);break;
   case 11:{
    void *base;
    number3=BSUBWAY_SCOREDATA_GetWinCount(arg->block,select2);
    number3=(number3>9999)?9999:number3;
#if LANGUAGE == LANGUAGE_JAPANESE
    base=MSGDATA_AllocString((struct MsgBank *)second,d_021E3490[index].value);
    obj=MSGDATA_AllocString((struct MsgBank *)second,d_021E3490[index].value);
#else
    base=MSGDATA_AllocString((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,work->heapId);
#endif
    WORDSET_SetSlotNumber((void *)third,0,number3,4,1, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_CopyTaggedText((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   case 14:{
    void *base;
    number4=BSUBWAY_SCOREDATA_GetMaxWinCount(arg->block,select2);
    number4=(number4>9999)?9999:number4;
#if LANGUAGE == LANGUAGE_JAPANESE
    base=MSGDATA_AllocString((struct MsgBank *)second,d_021E3490[index].value);
    obj=MSGDATA_AllocString((struct MsgBank *)second,d_021E3490[index].value);
#else
    base=MSGDATA_AllocString((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,work->heapId);
#endif
    WORDSET_SetSlotNumber((void *)third,0,number4,4,1, PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_CopyTaggedText((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   default:obj=MSGDATA_AllocString((struct MsgBank *)second,rec->value);break;
  }
  BR_UTIL_SetTextFromBuffer(work->rowText[index],obj,(void *)first,0x3da0);
  STRBUF_Delete(obj);
 }
 v=BSUBWAY_SCOREDATA_GetBattlePoints(arg->block);
 BR_RES_GetSprite((void *)(arg->res), 13, (BrCodeinTriple *)((BrCodeinTriple *)&triple));
 BR_CODEIN_ListCreateActor(&work->pointActors,arg->unit,&triple,v,0xa0,0x20,work->heapId);
}

/*
 * lever: declaring the text object before the loop index fixes r4/r5.
 */
void BR_CODEIN_ListSetupRowD(struct CodeinListWork *work,struct BrProcArgProfile *arg)
{
 void *first; void *second; void *third; int v; struct Strbuf *text;
 void *obj;
 int i;
 const BrCodeinRecord *rec;
 BrCodeinTriple triple;
 first=BR_RES_GetFont((struct BrRes *)(arg->res));
 second=BR_RES_GetMsgData((struct BrRes *)(arg->res));
 third=BR_RES_GetWordSet((struct BrRes *)(arg->res));
 BR_RES_LoadBgGraphics((void *)(arg->res),13,work->heapId);
 for(i=0;i<5;i++){
  rec=&d_021E338C[i]; work->rowText[i]=BR_UTIL_Create(1,rec->a,rec->b,rec->c,rec->d,14,work->printQue,work->heapId);
  if(i==4){
   v=BSUBWAY_SCOREDATA_GetLevel((struct BsubwayScoreData *)(arg->block));
#if LANGUAGE == LANGUAGE_JAPANESE
   text=MSGDATA_AllocString((struct MsgBank *)second,d_021E338C[i].value);
   obj=MSGDATA_AllocString((struct MsgBank *)second,d_021E338C[i].value);
#else
   text=MSGDATA_AllocString((struct MsgBank *)second,rec->value);
   obj=STRBUF_Create(0x80,work->heapId);
#endif
   WORDSET_SetSlotNumber((void *)third,0,v,2,1,1);
   WORDSET_CopyTaggedText((void *)third,obj,text);
   STRBUF_Delete(text);
  }else obj=(void *)MSGDATA_AllocString((struct MsgBank *)second,rec->value);
  BR_UTIL_SetTextFromBuffer(work->rowText[i],obj,(void *)first,0x3da0);
  STRBUF_Delete((struct Strbuf *)(obj));
 }
 v=BSUBWAY_SCOREDATA_GetBattlePoints((struct BsubwayScoreData *)(arg->block));
 BR_RES_GetSprite((void *)(arg->res), 13, (BrCodeinTriple *)((BrCodeinTriple *)&triple));
 BR_CODEIN_ListCreateActor(&work->pointActors,(arg->unit),&triple,v,0xa0,0x20,work->heapId);
}

void BR_CODEIN_ListTeardown(struct CodeinListWork *work, struct BrProcArgProfile *arg)
{
    int i;
    BR_CODEIN_ListDeleteActor(&work->pointActors);
    for (i = 0; i < 16; i++) {

        if (work->rowText[i]) {
            BR_UTIL_Delete(work->rowText[i]);
            work->rowText[i] = 0;
        }
    }
    BR_RES_ApplyBgSet((void *)(arg->res), 10);
    if ((work->textWin)) {
        BR_UTIL_DeleteTextWin((work->textWin), arg->res);
        work->textWin = 0;
    }
}

void BR_CODEIN_ListSetupButtons(struct CodeinListWork *work,struct BrProcArgProfile *arg)
{
 void *first; void *second; int i; sptr id;
 BrCodeinTriple triple;
 Position pos;
 const BrCodeinRecord *rec;
 BR_RES_LoadSprite((struct BrRes *)(arg->res),6,work->heapId);
 BR_RES_LoadBgGraphics((void *)(arg->res),9,work->heapId);
 first=BR_RES_GetFont((struct BrRes *)(arg->res));
 second=BR_RES_GetMsgData((struct BrRes *)(arg->res));
 MI_CpuFill8((void *)&pos,0,8);
 pos.x=0x50;pos.y=0xa8;pos.z=0;pos.a=1;
 BR_RES_GetSprite((struct BrRes *)((void *)(arg->res)), 6, (void *)((BrCodeinTriple *)((BrCodeinTriple *)&triple)));
 (work->backButton)=BR_BTN_CreateFromMessage((void *)&pos,4,0x60,1,(void *)(arg->unit),(void *)work->oamSys,(void *)first,(struct MsgBank *)second,(void *)&triple,work->heapId);
 for(i=0;i<4;i++){
  rec=&d_021E336C[i];work->buttonText[i]=BR_UTIL_Create(4,rec->a,rec->b,rec->c,rec->d,14,work->printQue,work->heapId);
  switch(i){
   case 0: if(BR_CODEIN_ListIsEventA(arg->block,arg->gameData)) id=0x83;else id=0x7e;break;
   case 1: if(BR_CODEIN_ListIsEventB(arg->block,arg->gameData)) id=0x84;else id=0x7f;break;
   case 2: if(BR_CODEIN_ListIsEventC(arg->block,arg->gameData)) id=0x85;else id=0x80;break;
   case 3: id=0x81;break;
  }
  BR_UTIL_SetTextFromMessage(work->buttonText[i],(void *)second,id,(void *)first,0x3da0);
 }
}

void BR_CODEIN_ListDeleteButtons(struct CodeinListWork *work, struct BrProcArgProfile *arg)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (work->buttonText[i]) {
            BR_UTIL_Delete(work->buttonText[i]);
            work->buttonText[i] = 0;
        }
    }
    if ((work->backButton)) {
        BR_BTN_DeleteObject((work->backButton));
        work->backButton = 0;
    }
    BR_RES_ReleaseSprite((struct BrRes *)((char *)(arg->res)), 6);
    BR_RES_ApplyBgSet((void *)(arg->res), 9);
}

int BR_CODEIN_ListHitButton(struct CodeinListWork *work, int x, int y)
{
    int skip = work->listChoice;
    int i;
    for (i = 0; i < 5; i++) {
        if (i != skip && (u32)(x - d_021E3440[i].x0) <= d_021E3440[i].x1 - d_021E3440[i].x0 &&
            (u32)(y - d_021E3440[i].y0) <= d_021E3440[i].y1 - d_021E3440[i].y0) {
            Point args;
            args.x = x;
            args.y = y;
            BR_UTIL_StartEffect((char *)((void *)(work->listFx)), 1, (const BrPair *)&args);
            GFL_USE_PlaySeDefaultVolume(0x703);
            return i;
        }
    }
    return 0;
}

int BR_CODEIN_ListIsEventA(struct BsubwayScoreData *work,struct GameData *gameData) { u32 a,b; a=BSUBWAY_SCOREDATA_AccessFlag(work,4,0); b=ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(gameData),0x960); if(a && b) return 1; return 0; }

int BR_CODEIN_ListIsEventB(struct BsubwayScoreData *work, struct GameData *gameData)
{
    int a = BSUBWAY_SCOREDATA_AccessFlag(work, 5, 0);
    unsigned b = ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(gameData), 0x960);
    if (a && b) return 1;
    return 0;
}

int BR_CODEIN_ListIsEventC(struct BsubwayScoreData *work, struct GameData *gameData)
{
    int a = BSUBWAY_SCOREDATA_AccessFlag(work, 6, 0);
    unsigned b = ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(gameData), 0x960);
    if (a && b) return 1;
    return 0;
}

/*
 * extent: two trailing zero bytes are alignment padding before the next labelled function.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`base = x;` before `base = x + 20;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT* in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
void BR_CODEIN_ListCreateActor(struct CodeinPointActors *work, void *manager, const BrCodeinTriple *arg, unsigned int value, s16 x, s16 y, u16 heap)
{
    Position pos;
    int base;
    int i;
    MI_CpuFill8(work, 0, sizeof(*work));
    MI_CpuFill8(&pos, 0, 8);
    pos.x = x;
    pos.y = y;
    pos.z = 10;
    work->frame = CLACT_CreateActor(manager, arg->b, arg->c, arg->a, (const struct ActorInitParam *)&pos, 0, heap);
    CLACT_SetActorObjMode(work->frame, 1);
    pos.z = 0;
    base = x + 20;
    for (i = 0; i < 4; i++) {
        pos.x = base + i * 16;
        pos.y = y;

        work->digit[i] = CLACT_CreateActor(manager, arg->b, arg->c, arg->a, (const struct ActorInitParam *)&pos, 0, heap);
        CLACT_SetActorObjMode(work->digit[i], 1);
    }
    BR_CODEIN_ListSetActorAnim(work, value);
}

void BR_CODEIN_ListDeleteActor(struct CodeinPointActors *work)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (work->digit[i]) {
            CLACT_DeleteActor(work->digit[i]);
            work->digit[i] = 0;
        }
    }
    CLACT_DeleteActor(work->frame);
    MI_CpuFill8(work, 0, sizeof(*work));
}

void BR_CODEIN_ListSetActorAnim(struct CodeinPointActors *work, u32 value)
{
    u8 temp = value;
    int i;
    int j;
    if (temp != 0) {
        for (;;) {
            if (temp == 0) break;
            temp /= 10;
        }
    }
    for (i = 0; i < 4; i++) CLACT_SetActorAnimSeq(work->digit[i], 0);
    for (j = 0; j < 4; j++)
        CLACT_SetActorAnimSeq(work->digit[3 - j], value % d_021E3358[j + 1] / d_021E3358[j]);
}

int BR_CODEIN_ResultCreate(void *proc, int seq, struct BrProcArgProfile *arg)
{
    struct CodeinResultWork *p = PROCSYS_AllocProcWork(proc, sizeof(*p), BR_PROC_SYS_GetSlotId(arg->proc));
    MI_CpuFill8(p, 0, sizeof(*p));
    p->heapId = BR_PROC_SYS_GetSlotId(arg->proc);
    p->oamSys = BMP_OAM_CreateSys(p->heapId, (arg->fade));
    p->printQue = (void *)PRINTSYS_QUE_Create(p->heapId);
    p->resultFx = BR_UTIL_CreateHandles((void *)(((arg->fade))), arg->res, 1, p->heapId);
    BR_CODEIN_ResultSetupTextWin(p, arg);
    BR_CODEIN_ResultSetupButtons(p, arg);
    return 1;
}

int BR_CODEIN_ResultDestroy(void *proc, int seq, struct BrProcArgProfile *arg, struct CodeinResultWork *work)
{
    BR_CODEIN_ResultTeardown(work, arg);
    BR_CODEIN_ResultDeleteButtons(work, arg);
    BG_SYS_PushTile(4);
    BG_SYS_PushTile(1);
    BR_UTIL_DeleteHandles(work->resultFx);
    PRINTSYS_QUE_Delete(work->printQue);
    BMP_OAM_DeleteSys(work->oamSys);
    PROCSYS_FreeProcWork(proc);
    return 1;
}

int BR_CODEIN_ResultMain(void *unused,u32 *state,struct BrProcArgProfile *arg,struct CodeinResultWork *work)
{
 int x,y,i;
 Point pair;
 switch(*state){
 case 0:BR_FADE_Start((void *)(arg->unit),2,3,0);*state=1;break;
 case 1:if(BR_FADE_GetResult((struct BrFade *)(arg->unit))) *state=2;break;
 case 2:
  if(TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))){
   work->resultChoice=BR_CODEIN_ResultHitButton(work,x,y);
   if(work->resultChoice) *state=3;
   if(BR_BTN_HitTestWithSound(work->backButton,x,y)){
    pair.x=x;pair.y=y;
    BR_UTIL_StartEffect((char *)((void *)(work->resultFx)), 1, (const BrPair *)&pair);
    *state=7;
   }
  }break;
 case 3:BR_FADE_Start((void *)(arg->unit),2,1,1);++*state;break;
 case 4:if(BR_FADE_GetResult((struct BrFade *)(arg->unit))) ++*state;break;
 case 5:
  BR_CODEIN_ResultTeardown(work,arg);
  switch(*(u32 *)&work->resultChoice){
  case 1:BR_CODEIN_ResultSetupRowA(work,arg);break;
  case 2:BR_CODEIN_ResultSetupRowB(work,arg);break;
  case 3:BR_CODEIN_ResultSetupRowC(work,arg);break;
  }
  BR_FADE_Start((void *)(arg->unit),2,1,0);++*state;break;
 case 6:if(BR_FADE_GetResult((struct BrFade *)(arg->unit))) *state=2;break;
 case 7:BR_FADE_Start((void *)(arg->unit),2,3,1);*state=8;break;
 case 8:if(BR_FADE_GetResult((struct BrFade *)(arg->unit))) *state=9;break;
 case 9:BR_PROC_SYS_PopEntry(arg->proc);return 1;
 }
 for(i=0;i<3;i++) if(((struct CodeinResultWork *)work)->buttonText[i]) BR_UTIL_FlushText(((struct CodeinResultWork *)work)->buttonText[i]);
 for(i=0;i<18;i++) if(((struct CodeinResultWork *)work)->rowText[i]) BR_UTIL_FlushText(((struct CodeinResultWork *)work)->rowText[i]);
 PRINTSYS_QUE_Main(work->printQue);
 BR_UTIL_RunHandles(work->resultFx);
 if(work->textWin)BR_UTIL_FlushWindow(work->textWin);
 return 0;
}

void BR_CODEIN_ResultSetupTextWin(struct CodeinResultWork *work, struct BrProcArgProfile *arg)
{
    work->textWin = BR_UTIL_CreateTextWin((void *)(arg->res), (void *)(work->printQue), work->heapId);
    BR_UTIL_SetWindowText(work->textWin, arg->res, 0x86);
}

/*
 * lever: declaring text before i/flag restores the original stack slots.
 */
void BR_CODEIN_ResultSetupRowA(struct CodeinResultWork *work,struct BrProcArgProfile *arg)
{
    void *font; void *bank; void *words;
    struct Strbuf *text;
    int i, flag;
    const BrCodeinRecord *rec;
    void *base;
    font=BR_RES_GetFont((struct BrRes *)(arg->res));
    bank=BR_RES_GetMsgData((struct BrRes *)(arg->res));
    words=BR_RES_GetWordSet((struct BrRes *)(arg->res));
    BR_RES_LoadBgGraphics((void *)(arg->res),16,work->heapId);
    for(i=0;i<12;i++) {
        flag=1;
        rec=&d_021E3574[i];
        work->rowText[i]=BR_UTIL_Create(1,rec->a,rec->b,rec->c,rec->d,14,work->printQue,work->heapId);
#if LANGUAGE != LANGUAGE_JAPANESE
        BR_UTIL_SetTextLayout(work->rowText[i],0,1,0);
#endif
        switch(i) {
        case 0: WORDSET_SetSlotMyStatus((struct WordSet *)words,0,(void *)(GAME_DATA_GetMyStatus((struct GameData *)((arg->block))))); break;
        case 7: WORDSET_SetSlotNumber((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat((BsubwayStatRow *)(*(Row * *)&arg->gameData),5,0),4,1, PM_LANG_HALF_WIDTH_DIGITS); break;
        case 8: WORDSET_SetSlotNumber((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat((BsubwayStatRow *)(*(Row * *)&arg->gameData),6,0),4,1, PM_LANG_HALF_WIDTH_DIGITS); break;
        case 9: WORDSET_SetSlotNumber((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat((BsubwayStatRow *)(*(Row * *)&arg->gameData),7,0),4,1, PM_LANG_HALF_WIDTH_DIGITS); break;
        case 10: WORDSET_SetSlotNumber((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat((BsubwayStatRow *)(*(Row * *)&arg->gameData),8,0),4,1, PM_LANG_HALF_WIDTH_DIGITS); break;
        case 11: WORDSET_SetSlotNumber((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat((BsubwayStatRow *)(*(Row * *)&arg->gameData),9,0),4,1, PM_LANG_HALF_WIDTH_DIGITS); break;
        default: text=MSGDATA_AllocString((struct MsgBank *)bank,rec->value); flag=0; break;
        }
        if(flag) {
#if LANGUAGE == LANGUAGE_JAPANESE
            base=MSGDATA_AllocString((struct MsgBank *)bank,d_021E3574[i].value);
            text=MSGDATA_AllocString((struct MsgBank *)bank,d_021E3574[i].value);
#else
            base=MSGDATA_AllocString((struct MsgBank *)bank,rec->value);
            text=STRBUF_Create(128,work->heapId);
#endif
            WORDSET_CopyTaggedText((struct WordSet *)words,text,base);
            STRBUF_Delete(base);
        }
        BR_UTIL_SetTextFromBuffer(work->rowText[i],text,(void *)font,0x3da0);
        STRBUF_Delete(text);
    }
}

void BR_CODEIN_ResultSetupRowB(struct CodeinResultWork *work,struct BrProcArgProfile *arg)
{
    void *font; void *bank; void *words; int i, flag, value;
    const BrCodeinRecord *rec;
    struct Strbuf *text;
    void *base;
    font=BR_RES_GetFont((struct BrRes *)(arg->res));
    bank=BR_RES_GetMsgData((struct BrRes *)(arg->res));
    words=BR_RES_GetWordSet((struct BrRes *)(arg->res));
    BR_RES_LoadBgGraphics((void *)(arg->res),17,work->heapId);
    for(i=0;i<18;i++) {
        rec=&d_021E3664[i];
        work->rowText[i]=BR_UTIL_Create(1,rec->a,rec->b,rec->c,rec->d,14,(void *)work->printQue,work->heapId);
#if LANGUAGE != LANGUAGE_JAPANESE
        BR_UTIL_SetTextLayout(work->rowText[i],0,1,0);
#endif
        if(i>=8 && i<=12) {value=BSUBWAY_SAVEDATA_GetStat((BsubwayStatRow *)(*(Row * *)&arg->gameData),i-3,1);flag=1;}
        else if(i>=13 && i<=17) {value=BSUBWAY_SAVEDATA_GetStat((BsubwayStatRow *)(*(Row * *)&arg->gameData),i-8,2);flag=1;}
        else {text=MSGDATA_AllocString((struct MsgBank *)bank,rec->value);flag=0;}
        if(flag) {
#if LANGUAGE == LANGUAGE_JAPANESE
            base=MSGDATA_AllocString((struct MsgBank *)bank,d_021E3664[i].value);
            text=MSGDATA_AllocString((struct MsgBank *)bank,d_021E3664[i].value);
#else
            base=MSGDATA_AllocString((struct MsgBank *)bank,rec->value);
            text=STRBUF_Create(128,work->heapId);
#endif
            WORDSET_SetSlotNumber((struct WordSet *)words,0,value,5,1, PM_LANG_HALF_WIDTH_DIGITS);
            WORDSET_CopyTaggedText((struct WordSet *)words,text,base);
            STRBUF_Delete(base);
        }
        BR_UTIL_SetTextFromBuffer(work->rowText[i],text,(void *)font,0x3da0);
        STRBUF_Delete(text);
    }
}

void BR_CODEIN_ResultSetupRowC(struct CodeinResultWork *work,struct BrProcArgProfile *arg)
{
    void *font; void *bank; void *words; int i, flag, value;
    const BrCodeinRecord *rec;
    struct Strbuf *text;
    void *base;
    font=BR_RES_GetFont((struct BrRes *)(arg->res));
    bank=BR_RES_GetMsgData((struct BrRes *)(arg->res));
    words=BR_RES_GetWordSet((struct BrRes *)(arg->res));
    BR_RES_LoadBgGraphics((void *)(arg->res),17,work->heapId);
    for(i=0;i<18;i++) {
        rec=&d_021E35D4[i];
        work->rowText[i]=BR_UTIL_Create(1,rec->a,rec->b,rec->c,rec->d,14,(void *)work->printQue,work->heapId);
#if LANGUAGE != LANGUAGE_JAPANESE
        BR_UTIL_SetTextLayout(work->rowText[i],0,1,0);
#endif
        if(i>=8 && i<=12) {value=BSUBWAY_SAVEDATA_GetStat((BsubwayStatRow *)(*(Row * *)&arg->gameData),i-8,1);flag=1;}
        else if(i>=13 && i<=17) {value=BSUBWAY_SAVEDATA_GetStat((BsubwayStatRow *)(*(Row * *)&arg->gameData),i-13,2);flag=1;}
        else {text=MSGDATA_AllocString((struct MsgBank *)bank,rec->value);flag=0;}
        if(flag) {
#if LANGUAGE == LANGUAGE_JAPANESE
            base=MSGDATA_AllocString((struct MsgBank *)bank,d_021E35D4[i].value);
            text=MSGDATA_AllocString((struct MsgBank *)bank,d_021E35D4[i].value);
#else
            base=MSGDATA_AllocString((struct MsgBank *)bank,rec->value);
            text=STRBUF_Create(128,work->heapId);
#endif
            WORDSET_SetSlotNumber((struct WordSet *)words,0,value,5,1, PM_LANG_HALF_WIDTH_DIGITS);
            WORDSET_CopyTaggedText((struct WordSet *)words,text,base);
            STRBUF_Delete(base);
        }
        BR_UTIL_SetTextFromBuffer(work->rowText[i],text,(void *)font,0x3da0);
        STRBUF_Delete(text);
    }
}

/*
 * extent: two trailing zero bytes are alignment padding before the next labelled function.
 */
void BR_CODEIN_ResultTeardown(struct CodeinResultWork *work, struct BrProcArgProfile *arg)
{
    int i;
    for (i = 0; i < 18; i++) {
        if (work->rowText[i] != 0) {
            BR_UTIL_Delete(work->rowText[i]);
            work->rowText[i] = 0;
        }
    }
    BR_RES_ApplyBgSet((void *)(arg->res), 17);
    if (work->textWin != 0) {
        BR_UTIL_DeleteTextWin(work->textWin, arg->res);
        work->textWin = 0;
    }
}

/*
 * lever: bank/words declaration order selects their original stack slots.
 * omits MSGDATA_ReadString from its function header. Existing C verified EXACT
 * (344 bytes, 12/12 relocations; ARM9-45CAC-one.log, terminal exit 0).
 * typedef unsigned char  u8;
 * typedef unsigned short u16;
 * typedef unsigned int   u32;
 *
 * struct MsgEntry {
 *     u32 off;
 *     u16 len;
 *     u16 pad_06;
 * };
 *
 * struct MsgFile {
 *     u16 langCount;
 *     u16 count;
 *     u32 unk_04;
 *     u32 unk_08;
 *     u32 langOff[1];
 * };
 *
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void                 *base;
 *     struct MsgEntry       cache;
 *     u32                   origin;
 *     void                 *stream;
 *     u16                   heapId;
 *     u8                    langIndex;
 *     u8                    resident;
 * };
 *
 * extern char MSGDATA_AllocSite[];
 * extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site,
 *                           u16 tag);
 * extern void GFL_HEAP_Free(void *p);
 * extern void ARC_TOOL_ReadHandle(void *stream, u32 size, void *dest);
 * extern void ARC_TOOL_SeekHandle(void *stream, u32 pos);
 * extern void STRBUF_Clear(void *dest);
 * extern void STRBUF_SetChars(void *dest, const void *src, u16 len);
 * extern void MSGDATA_DecryptStrbuf(void *dest, u32 index);
 * extern u8 MSGDATA_GetLanguageIndex(const void *file);
 * extern void MSGDATA_LoadBank(struct MsgBank *bank);
 * extern void MSGDATA_RefreshLanguage(struct MsgBank *bank);
 *
 * void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *
 *     MSGDATA_RefreshLanguage(bank);
 *
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *
 *         ARC_TOOL_SeekHandle(bank->stream, pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream, 8, &bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *
 *     if (bank->resident == 0) {
 *         void *buf;
 *
 *         size = e->len * 2;
 *         buf = GFL_HEAP_Alloc((u16)((bank->heapId & 0x7fff) | 0x8000), size,
 *                            0, MSGDATA_AllocSite, 0xd6);
 *         if (buf != 0) {
 *             ARC_TOOL_SeekHandle(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream, size, buf);
 *             STRBUF_SetChars(dest, buf, e->len);
 *             GFL_HEAP_Free(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest, (u8 *)bank->base + e->off, e->len);
 *     }
 *
 *     MSGDATA_DecryptStrbuf(dest, index);
 * }
 */
void BR_CODEIN_ResultSetupButtons(struct CodeinResultWork *work,struct BrProcArgProfile *arg)
{
    void *font; void *words; void *bank; int i;
    BrCodeinParams config;
    BrCodeinTriple triple;
    struct Strbuf *base,*text;
    void *value;
    const BrCodeinRecord *rec;
    BR_RES_LoadSprite((struct BrRes *)(arg->res),6,work->heapId);
    BR_RES_LoadBgGraphics((void *)(arg->res),15,work->heapId);
    font=BR_RES_GetFont((struct BrRes *)(arg->res));
    bank=BR_RES_GetMsgData((struct BrRes *)(arg->res));
    words=BR_RES_GetWordSet((struct BrRes *)(arg->res));
    MI_CpuFill8((void *)&config,0,8);
    config.a=80; config.b=168; config.c=0; config.flag=1;
    BR_RES_GetSprite((struct BrRes *)((void *)(arg->res)), 6, (void *)((BrCodeinTriple *)&triple));
    work->backButton=BR_BTN_CreateFromMessage((void *)&config,4,96,1,(void *)(*(void **)arg),(void *)*(void **)work,(void *)font,(struct MsgBank *)bank,(void *)&triple,work->heapId);
    base=STRBUF_Create(128,work->heapId);
    text=STRBUF_Create(128,work->heapId);
    value=GAME_DATA_GetMyStatus(arg->block);
    for(i=0;i<3;i++) {
        rec=&d_021E351C[i];
        work->buttonText[i]=BR_UTIL_Create(4,rec->a,rec->b,rec->c,rec->d,14,work->printQue,work->heapId);
        if(i==0) {
            MSGDATA_ReadString((struct MsgBank *)bank,rec->value,base);
            WORDSET_SetSlotMyStatus((struct WordSet *)words,0,value);
            WORDSET_CopyTaggedText((struct WordSet *)words,text,base);
        } else MSGDATA_ReadString((struct MsgBank *)bank,rec->value,text);
        BR_UTIL_SetTextFromBuffer(work->buttonText[i],text,(void *)font,0x3da0);
    }
    STRBUF_Delete(base);
    STRBUF_Delete(text);
}

void BR_CODEIN_ResultDeleteButtons(struct CodeinResultWork *work, struct BrProcArgProfile *arg)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (work->buttonText[i]) {
            BR_UTIL_Delete(work->buttonText[i]);
            work->buttonText[i] = 0;
        }
    }
    if (work->backButton) {
        BR_BTN_DeleteObject(work->backButton);
        work->backButton = 0;
    }
    BR_RES_ReleaseSprite((struct BrRes *)((char *)(arg->res)), 6);
    BR_RES_ApplyBgSet((void *)(arg->res), 15);
}

int BR_CODEIN_ResultHitButton(struct CodeinResultWork *work, int x, int y)
{
    int skip = work->resultChoice;
    int i;
    for (i = 0; i < 4; i++) {
        if (i != skip && (u32)(x - d_021E3534[i].x0) <= d_021E3534[i].x1 - d_021E3534[i].x0 &&
            (u32)(y - d_021E3534[i].y0) <= d_021E3534[i].y1 - d_021E3534[i].y0) {
            Point args;
            args.x = x;
            args.y = y;
            BR_UTIL_StartEffect((char *)((void *)(work->resultFx)), 1, (const BrPair *)&args);
            GFL_USE_PlaySeDefaultVolume(0x703);
            return i;
        }
    }
    return 0;
}

int BR_CODEIN_StatCreate(void *proc, int seq, struct BrProcArgType *arg)
{
    struct CodeinStatWork *p = PROCSYS_AllocProcWork(proc, sizeof(struct CodeinStatWork), BR_PROC_SYS_GetSlotId(arg->proc));
    int i;
    MI_CpuFill8(p, 0, sizeof(struct CodeinStatWork));
    p->statCtx = arg;
    p->heapId = BR_PROC_SYS_GetSlotId(arg->proc);
    p->oamSys = BMP_OAM_CreateSys(p->heapId, arg->unit);
    p->printQue = (void *)PRINTSYS_QUE_Create(p->heapId);
    for (i = 0; i < 2; i++)
        (&p->listFx)[i] = BR_UTIL_CreateHandles(arg->unit, arg->res, i, p->heapId);
    p->task = BR_UTIL_CreateTask(p, BR_CODEIN_SearchStepText, p->heapId);
    if (p->statCtx->flag != 0)
        BR_UTIL_SetTaskStep(p->task, BR_CODEIN_StatSetup);
    else
        BR_UTIL_SetTaskStep(p->task, BR_CODEIN_SearchStepText);
    return 1;
}

int BR_CODEIN_StatDestroy(void *proc, int seq, struct BrProcArgType *arg, struct CodeinStatWork *work)
{
    int i;
    if (work->listCreated != 0) {
        BR_CODEIN_SearchDeleteList(&work->list);
        work->listCreated = 0;
    }
    if (work->titleText != 0) {
        BR_UTIL_Delete(work->titleText);
        work->titleText = 0;
    }
    if (work->headerText != 0) {
        BR_UTIL_Delete(work->headerText);
        work->headerText = 0;
    }
    if (work->backButton != 0) {
        BR_BTN_DeleteObject(work->backButton);
        work->backButton = 0;
    }
    if (work->spriteLoaded != 0) {
        BR_RES_ReleaseSprite(work->statCtx->res, 6);
        BR_RES_ApplyBgSet(work->statCtx->res, 24);
        work->spriteLoaded = 0;
    }
    BR_UTIL_DeleteTask(work->task);
    if (work->textWin != 0) {
        BR_UTIL_DeleteTextWin(work->textWin, arg->res);
        work->textWin = 0;
    }
    for (i = 0; i < 2; i++) BR_UTIL_DeleteHandles((&work->listFx)[i]);
    BMP_OAM_DeleteSys(work->oamSys);
    PRINTSYS_QUE_Delete(work->printQue);
    PROCSYS_FreeProcWork(proc);
    return 1;
}

int BR_CODEIN_StatMain(int proc, int seq, int arg, struct CodeinStatWork *work)
{
    int i;
    if (BR_NET_HandleNetError(work->statCtx->net) == 2) {
        BR_PROC_SYS_FlushWindows((work->statCtx->proc));
        return 1;
    }
    BR_UTIL_RunTask(work->task);
    if (BR_UTIL_IsTaskIdle(work->task) != 0) return 1;
    for (i = 0; i < 2; i++) BR_UTIL_RunHandles((&work->listFx)[i]);
    PRINTSYS_QUE_Main(work->printQue);
    if (work->headerText != 0) BR_UTIL_FlushText(work->headerText);
    if (work->titleText != 0) BR_UTIL_FlushText(work->titleText);
    if (work->textWin != 0) BR_UTIL_FlushWindow(work->textWin);
    return 0;
}

void BR_CODEIN_StatSetup(struct BrUtilTask *task,int *state,struct CodeinStatWork *work)
{
    void *font; void *bank;
    BrCodeinParams config;
    BrCodeinTriple triple;
    font=BR_RES_GetFont((struct BrRes *)(work->statCtx->res));
    bank=BR_RES_GetMsgData((struct BrRes *)(work->statCtx->res));
    if(work->textWin) {
        BR_UTIL_DeleteTextWin(work->textWin,work->statCtx->res);
        work->textWin=0;
    }
    BR_RES_LoadBgGraphics((void *)(work->statCtx->res),24,work->heapId);
    BR_RES_LoadSprite((struct BrRes *)(work->statCtx->res),6,work->heapId);
    work->spriteLoaded=1;
    MI_CpuFill8(&config,0,8);
    config.a=80;config.b=168;config.c=0;config.flag=1;
    if(!BR_RES_GetSprite((struct BrRes *)((void *)((work->statCtx->res))), 6, (void *)((BrCodeinTriple *)&triple)))
        GF_PANIC_Fail(PM_LANG_JA((const char *)d_021E3964, str_ja_021E3964), PM_SRC_LINE(0, 0x18B), PM_LANG_JA((const char *)d_021E3964, str_ja_021E3978));
    work->backButton=BR_BTN_CreateFromMessage((void *)&config,4,96,1,(void *)((work->statCtx->unit)),(void *)(work->oamSys),(void *)font,(struct MsgBank *)bank,(void *)&triple,work->heapId);
    work->headerText=BR_UTIL_Create(4,11,6,10,4,14,work->printQue,work->heapId);
    BR_UTIL_SetTextFromMessage(work->headerText,(void *)bank,0x55,(void *)font,0x3da0);
    work->titleText=BR_UTIL_Create(1,3,3,26,4,14,work->printQue,work->heapId);
#if LANGUAGE != LANGUAGE_JAPANESE
    BR_UTIL_SetTextLayout(work->titleText,0,1,0);
#endif
    BR_UTIL_SetTextFromMessage(work->titleText,(void *)bank,work->statCtx->mode+0x57,(void *)font,0x3da0);
    BR_CODEIN_SearchCreateList(&work->list, &work->statCtx->data->cache, work->statCtx->res, work->statCtx->unit, work->listFx, work->tapFx, &work->statCtx->rec->selection, work->heapId);
    work->listCreated=1;
    BR_UTIL_SetTaskStep(task,BR_CODEIN_StatStepFadeIn);
}

void BR_CODEIN_StatTeardown(struct BrUtilTask *proc, int seq, struct CodeinStatWork *work)
{
    BR_CODEIN_SearchDeleteList(&work->list);
    work->listCreated = 0;
    BR_UTIL_Delete(work->titleText);
    work->titleText = 0;
    BR_UTIL_Delete(work->headerText);
    work->headerText = 0;
    BG_SYS_PushTile(4);
    BG_SYS_PushTile(1);
    BR_BTN_DeleteObject(work->backButton);
    work->backButton = 0;
    BR_RES_ReleaseSprite((struct BrRes *)((work->statCtx->res)), 6);
    BR_RES_ApplyBgSet((void *)(((work->statCtx->res))), 24);
    work->spriteLoaded = 0;
    BR_UTIL_ClearTaskStep(proc);
}

void BR_CODEIN_StatStepFadeIn(struct BrUtilTask *task, int *state, struct CodeinStatWork *work)
{
    switch (*state) {
    case 0:
        BR_FADE_Start((void *)(((work->statCtx->fade))), 2, 3, 0);
        *state = 1;
        break;
    case 1:
        if (BR_FADE_GetResult((struct BrFade *)(work->statCtx->fade)) != 0) *state = 2;
        break;
    case 2:
        BR_UTIL_SetTaskStep(task, BR_CODEIN_StatStepMenu);
        break;
    }
}

void BR_CODEIN_StatStepFadeOut(struct BrUtilTask *work, int *state, struct CodeinStatWork *arg)
{
    switch (*state) {
    case 0:
        BR_FADE_Start((void *)((arg->statCtx->fade)), 2, 3, 1);
        *state = 1;
        break;
    case 1:
        if (BR_FADE_GetResult((struct BrFade *)(arg->statCtx->fade)) != 0) *state = 2;
        break;
    case 2:
        BR_UTIL_SetTaskStep(work, BR_CODEIN_StatTeardown);
        break;
    }
}

void BR_CODEIN_StatStepMenu(struct BrUtilTask *task, int *state, struct CodeinStatWork *work)
{
    u32 x,y;
    BR_CODEIN_SearchMainList(&work->list,work->heapId);
    if (TOUCHPANEL_GetPointTrg(&x,&y)) {
        if (BR_BTN_HitTestWithSound(work->backButton,x,y)) {
            Point args;
            args.x=x; args.y=y;
            BR_UTIL_StartEffect((char *)((void *)(work->tapFx)), 1, (const BrPair *)&args);
            BR_PROC_SYS_PopEntry(work->statCtx->proc);
            BR_UTIL_SetTaskStep(task,BR_CODEIN_StatStepFadeOut);
        }
        if (BR_CODEIN_SearchHitBox(x,y)) {
            u32 selection;
            Point args;
            selection=BR_CODEIN_SearchGetHitId(&work->list);
            if (selection>=work->statCtx->data->cache.itemCount)
                GF_PANIC_Fail(PM_LANG_JA(d_021E3964, str_ja_021E3964), PM_SRC_LINE(0, 0x237), PM_LANG_JA(d_021E3964, str_ja_021E397C));
            work->statCtx->data->cache.selection=selection;
            BR_PROC_SYS_PushEntry(work->statCtx->proc,2);
            BR_UTIL_SetTaskStep(task,BR_CODEIN_StatStepFadeOut);
            args.x=x; args.y=y;
            BR_UTIL_StartEffect((char *)((void *)(work->tapFx)), 1, (const BrPair *)&args);
        }
    }
}

void BR_CODEIN_SearchStep(struct BrUtilTask *task,u32 *state,struct CodeinStatWork *work)
{
    switch(*state) {
    case 0: {
        Point initial;
        int mode;
        MI_CpuFill8(&initial,0,8);
        switch(work->statCtx->mode) {
        case 0: mode=5; break;
        case 1: mode=6; break;
        case 2: mode=7; break;
        case 3: initial=*(Point *)&work->statCtx->valueA; mode=4; break;
        default: GF_PANIC_Fail(PM_LANG_JA(d_021E3964, str_ja_021E3964), PM_SRC_LINE(0, 0x27E), PM_LANG_JA(d_021E3964, str_ja_021E39A8)); break;
        }
        MI_CpuFill8(&work->statCtx->data->cache,0,sizeof(struct BrRecCache));
        work->frames=0;
        BR_NET_StartRequest(work->statCtx->net,mode,(const union BrNetRequest *)(const int *)(&initial));
        *state=1; break;
    }
    case 1:
        ++work->frames;
        if(BR_NET_IsIdle(work->statCtx->net) && work->frames>96) {
            BR_UTIL_StartEffect((void *)(work->listFx), 0, 0); *state=2;
        } break;
    case 2: {
        sptr message; int success, i;
        struct BrRecCache *data;
        enum { COUNT_OFFSET=0x1718 } offset;
        data=&work->statCtx->data->cache;
        offset=COUNT_OFFSET;
        if(!BR_NET_PollErrorMessage(work->statCtx->net,&message)) {
            switch(work->statCtx->mode) {
            case 0: success=BR_NET_GetSearchResultsForRanking(work->statCtx->net,(char *)data,30,(void *)((char *)data+offset)); break;
            case 1: success=BR_NET_GetSearchResultsForRanking(work->statCtx->net,(char *)data,30,(void *)((char *)data+offset)); break;
            case 2: success=BR_NET_GetSearchResultsForNewest(work->statCtx->net,(char *)data,30,(void *)((char *)data+offset)); break;
            case 3: success=BR_NET_GetSearchResults(work->statCtx->net,(char *)data,30,(void *)((char *)data+offset)); break;
            default: GF_PANIC_Fail(PM_LANG_JA(d_021E3964, str_ja_021E3964), PM_SRC_LINE(0, 0x2B1), PM_LANG_JA(d_021E3964, str_ja_021E39A8)); break;
            }
            if(success) {
                for(i=0;i<(int)work->statCtx->data->cache.itemCount;i++) {
                    work->statCtx->data->cache.saved[i]=(u8)BATTLE_REC_GetHeaderParam((const struct BattleRecHeader *)work->statCtx->data->cache.entry[i].header,5,0);
                }
                BR_UTIL_SetTaskStep(task,BR_CODEIN_SearchStepFade);
            } else {
                if(work->statCtx->mode==3) BR_UTIL_SetWindowText(work->textWin,work->statCtx->res,276);
                else BR_UTIL_SetWindowText(work->textWin,work->statCtx->res,339);
                *state=3;
            }
        } else {
            BR_UTIL_SetWindowText(work->textWin,work->statCtx->res,message);
            *state=3;
        } break;
    }
    case 3: {
        u32 x,y;
        Point clicked;
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg((u32 *)&x,(u32 *)&y);
            clicked.x=x; clicked.y=y;
            BR_UTIL_StartEffect((char *)((void *)(work->tapFx)), 1, (const BrPair *)&clicked);
            GFL_USE_PlaySeDefaultVolume(0x703);
            BR_FADE_Start(work->statCtx->fade,2,3,1);
            *state=4;
        } break;
    }
    case 4:
        if(BR_FADE_GetResult(work->statCtx->fade)) *state=5;
        break;
    case 5:
        BR_PROC_SYS_PopEntry(work->statCtx->proc); BR_UTIL_ClearTaskStep(task); break;
    }
}

void BR_CODEIN_SearchStepText(struct BrUtilTask *work, int *state, struct CodeinStatWork *arg)
{
    Point args;
    switch (*state) {
    case 0:
        if (arg->textWin == 0) {
            arg->textWin = BR_UTIL_CreateTextWin((void *)(arg->statCtx->res), arg->printQue, arg->heapId);
        }
        if (arg->statCtx->mode == 3) {
            BR_UTIL_SetWindowText((char *)(arg->textWin), arg->statCtx->res, 0x14B);
        } else {
            BR_UTIL_SetWindowText((char *)(arg->textWin), arg->statCtx->res, 0x13E);
        }
        args.x = 0x80;
        args.y = 0x60;
        BR_UTIL_StartEffect((char *)((void *)(arg->listFx)), 4, (const BrPair *)&args);
        *state = 1;
        break;
    case 1:
        BR_FADE_Start((void *)((arg->statCtx->fade)), 2, 3, 0);
        *state = 2;
        break;
    case 2:
        if (BR_FADE_GetResult((struct BrFade *)(arg->statCtx->fade)) != 0) *state = 3;
        break;
    case 3:
        BR_UTIL_SetTaskStep(work, BR_CODEIN_SearchStep);
        break;
    }
}

void BR_CODEIN_SearchStepFade(struct BrUtilTask *work, int *state, struct CodeinStatWork *arg)
{
    switch (*state) {
    case 0:
        BR_FADE_Start((void *)((arg->statCtx->fade)), 2, 3, 1);
        *state = 1;
        break;
    case 1:
        if (BR_FADE_GetResult((struct BrFade *)(arg->statCtx->fade)) != 0) *state = 2;
        break;
    case 2:
        BR_UTIL_SetTaskStep(work, BR_CODEIN_StatSetup);
        break;
    }
}

void BR_CODEIN_SearchCreateList(struct CodeinSearchList *menu,struct BrRecCache *base,struct BrRes *res,struct Unit *mgr,void *listParam,void *tapFx,u16 *sel,u16 heap)
{
    void *first; void *second;
    int i;
    void *bmp;
    void *buf1,*msg,*buf2;
    CodeinListMenuConfig cfg;
    first=BR_RES_GetFont((struct BrRes *)res);
    second=BR_RES_GetMsgData((struct BrRes *)res);
    MI_CpuFill8(menu,0,sizeof(struct CodeinSearchList));
    menu->cache=base;
    menu->wordSet=WORDSET_CreateDefault(heap);
    menu->listParam=listParam;
    menu->tapFx=tapFx;
    menu->menuWork=(struct BmpMenuWorkSlot *)BMP_MENUWORK_Create(base->itemCount,heap);
    for(i=0;i<(int)base->itemCount;i++)menu->menuWork[i].b=i;
    *(CfgTpl *)&cfg=d_021E3700;
    cfg.list=(BrCodeinItem *)menu->menuWork;
    cfg.count=base->itemCount;
    cfg.resources=(struct BrRes *)res;
    cfg.manager=mgr;
    cfg.cursor=menu->listParam;
    cfg.other=menu->tapFx;
    cfg.selection=sel;
    menu->listMenu=BR_UTIL_CreateListMenu((const CodeinListMenuConfig *)&cfg, heap);
    buf1=STRBUF_Create(0xff,heap);
    msg=MSGDATA_AllocString((struct MsgBank *)second,0x7a);
    buf2=STRBUF_Create(0xff,heap);
    for(i=0;i<(int)base->itemCount;i++){
        bmp=BMP_Create(cfg.width,cfg.spacing,0x20,heap);
        BMP_Clear(bmp,0);
        WORDSET_SetSlotNumber((struct WordSet *)menu->wordSet,0,i+1,2,0, PM_LANG_HALF_WIDTH_DIGITS);
        WORDSET_CopyTaggedText(menu->wordSet,buf1,msg);
        STRBUF_SetString((struct Strbuf *)buf2,(const u16 *)base->entry[i].profile);
        PRINTSYS_PrintColor((struct Bmp *)bmp,(short)(16-PRINTSYS_MeasureWidestLine((struct Strbuf *)buf1,(struct GfFont *)first,0)),4,(struct Strbuf *)buf1,(struct GfFont *)((void *)first),0x3DA0);
        PRINTSYS_PrintColor(bmp,0x14,4,buf2,(void *)first,0x3DA0);
        BR_UTIL_SetListItemBitmap(menu->listMenu,(u16)i,bmp);
    }
    STRBUF_Delete(buf2);
    STRBUF_Delete(buf1);
    STRBUF_Delete(msg);
    BR_UTIL_RefreshList(menu->listMenu);
    BR_CODEIN_SearchCreateActor(menu,mgr,heap);
    for(i=0;i<*sel;i++)BR_CODEIN_SearchUpdateActor(menu,i+1,1,heap);
}

/*
 * trailing: two zero alignment bytes at 0x021DF3DA
 */
void BR_CODEIN_SearchDeleteList(struct CodeinSearchList *work)
{
    unsigned int i;
    BR_CODEIN_SearchDeleteActor(work);
    for (i = 0; i < BR_UTIL_GetListMenuField(work->listMenu, 3); i++) {
        BMP_Delete(BR_UTIL_GetListItemBitmap(work->listMenu, i));
    }
    WORDSET_Delete(work->wordSet);
    BR_UTIL_DeleteListMenu(work->listMenu);
    BMP_MENUWORK_Delete(work->menuWork);
    MI_CpuFill8(work, 0, sizeof(struct CodeinSearchList));
}

/*
 * trailing: two zero alignment bytes at 0x021DF41A
 */
void BR_CODEIN_SearchMainList(struct CodeinSearchList *work, u16 heapId)
{
    unsigned int old, current;
    s8 direction;
    old = BR_UTIL_GetListMenuField(work->listMenu, 1);
    BR_UTIL_MainListMenu(work->listMenu);
    current = BR_UTIL_GetListMenuField(work->listMenu, 1);
    direction = BR_UTIL_GetListMenuField(work->listMenu, 2);
    if (direction != 0 && old != current) BR_CODEIN_SearchUpdateActor(work, current, direction, heapId);
}

int BR_CODEIN_SearchGetHitId(struct CodeinSearchList *work)
{
    return BR_UTIL_GetListMenuHitId(work->listMenu);
}

/*
 * 2026-10-05 (wave P6 lane U1b): EXACT. Types from matched ov183 021DF1DC (Menu: base
 * at +0xD0) and 021DF620 (State layout). Two fixes closed the earlier 24 B residue:
 * heap is a u16 parameter (it is only masked and passed to u16-style callees; the
 * narrow type moves its home store before mgr's), and the clamp is a ternary
 * `n = (n >= 5) ? 5 : n;` which gives n the lowest spill slot, under the loop temps.
 * Final call is an if/else with a call in each arm.
 */
void BR_CODEIN_SearchCreateActor(struct CodeinSearchList *search,struct Unit *mgr,u16 heap)
{
    int i,j;
    void *archive;
    u32 mode,species;
    int n;
    struct Entries e;
    struct BrCodeinPos pos;
    n=search->cache->itemCount;
    n=(n>=5)?5:n;
    mode=(heap&0x7fff)|0x8000;
    archive=ARC_TOOL_CreateHandle(7,(u16)mode);
    i=0;
    search->paletteRes=CLACT_RegisterPaletteCompressed(archive,POKE_TOOL_GetIconPaletteArcId(),0,0x80,heap);
    search->cellAnimRes=CLACT_RegisterCellAnim(archive,POKE_TOOL_GetIconCellArcId(),POKE_TOOL_GetIconCellEntryId(),heap);
    MI_CpuFill8(&pos,0,8);
    pos.z=1;
    pos.a=i;
    pos.b=i;
    for(i=0;i<n;i++) {
        BR_CODEIN_SearchBuildHeader(&search->cache->entry[i],&e);
        for(j=0;j<6;j++) {
            species=e.species[j];
            if(species==0) species=1;
            search->charRes[i][j]=CLACT_RegisterCharacter(archive,POKE_TOOL_CalcGraphicIndex(species,e.form[j],e.gender[j],0),0,0,heap);
            pos.x=j*0x18+0x6e;
            pos.y=i*0x18+0x48;
            pos.a=6-j;
            search->sprites[i][j]=CLACT_CreateActor((void *)mgr,search->charRes[i][j],search->paletteRes,search->cellAnimRes,(const struct ActorInitParam *)&pos,0,heap);
            CLACT_SetActorPaletteOffset(search->sprites[i][j],POKE_TOOL_CalcIconPalette(species,e.form[j],e.gender[j],0),0);
            CLACT_SetActorObjMode(search->sprites[i][j],1);
            if(e.species[j]==0) CLACT_SetActorDrawEnable((struct ClactActor *)search->sprites[i][j],0);
            else CLACT_SetActorDrawEnable((struct ClactActor *)search->sprites[i][j],1);
        }
    }
    ARC_TOOL_DeleteHandle(archive);
}

/*
 * trailing: two zero alignment bytes at 0x021DF61E
 * lever: padded struct array members prevent caching the element cursor across calls.
 */
void BR_CODEIN_SearchDeleteActor(struct CodeinSearchList *work)
{
    int i, j;
    CLACT_ReleaseCellAnim(work->cellAnimRes);
    CLACT_ReleasePalette(work->paletteRes);
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 6; j++) {
            if (work->sprites[i][j] != 0) {
                CLACT_ReleaseCharacter(work->charRes[i][j]);
                CLACT_DeleteActor((struct ClactActor *)work->sprites[i][j]);
                work->sprites[i][j] = 0;
            }
        }
    }
}

/*
 * Lever: short step spills first; i remains live after the first loop and
 * supplies the second loop's row; forward/back/loaded declaration order
 * gives the three 36-byte buffers at sp+7c, sp+58, sp+34.
 */
void BR_CODEIN_SearchUpdateActor(struct CodeinSearchList *search,int first,short step,u16 heap)
{
    int i,j;
    char *src,*dst;
    u32 value;
    void *archive,*handle;
    struct BrCodeinSub *data;
    struct BrCodeinRec forward,back,loaded;
    struct Entries entries;
    u32 mode;
    for(i=0;i<5;i++) {
        for(j=0;j<6;j++) {
            if(step==1 && i!=4) {
                src=search->sprites[i+1][j]; dst=search->sprites[i][j];
                if(CLACT_GetActorDrawEnable((struct ClactActor *)(struct Obj *)src)) {
                    CLACT_GetActorImageProxy(src,(struct ImageProxy *)(&forward));
                    value=CLACT_GetActorPaletteOffset((struct ClactActor *)(struct Obj *)src);
                    CLACT_SetActorImageProxy(dst,(const struct ImageProxy *)(&forward));
                    CLACT_SetActorPaletteOffset((struct ClactActor *)(struct Obj *)dst,value,0);
                    CLACT_SetActorDrawEnable((struct ClactActor *)(struct Obj *)dst,1);
                } else CLACT_SetActorDrawEnable((struct ClactActor *)(struct Obj *)dst,0);
            } else if(step==-1 && i!=4) {
                src=search->sprites[3-i][j]; dst=search->sprites[4-i][j];
                if(CLACT_GetActorDrawEnable((struct ClactActor *)(struct Obj *)src)) {
                    CLACT_GetActorImageProxy(src,(struct ImageProxy *)(&back));
                    value=CLACT_GetActorPaletteOffset((struct ClactActor *)(struct Obj *)src);
                    CLACT_SetActorImageProxy(dst,(const struct ImageProxy *)(&back));
                    CLACT_SetActorPaletteOffset((struct ClactActor *)(struct Obj *)dst,value,0);
                    CLACT_SetActorDrawEnable((struct ClactActor *)(struct Obj *)dst,1);
                } else CLACT_SetActorDrawEnable((struct ClactActor *)(struct Obj *)dst,0);
            }
        }
    }
    mode=(heap&0x7fff)|0x8000;
    archive=ARC_TOOL_CreateHandle(7,(u16)mode);
    if(step==-1) { --search->cursor; if(search->cursor<0) search->cursor=4; }
    for(j=0;j<6;j++) {
        if(step==1) i=4; else if(step==-1) i=0;
        BR_CODEIN_SearchBuildHeader(&search->cache->entry[i+first],&entries);
        if(entries.species[j]) {
            handle=ARC_UTIL_LoadScreenDataFromHandle((void *)archive,POKE_TOOL_CalcGraphicIndex(entries.species[j],entries.form[j],entries.gender[j],0),0,(void *)&data,mode);
            CLACT_TransferCharacter(search->charRes[search->cursor][j],(struct NNSG2dCharacterData *)data);
            CLACT_GetCharacterProxy(search->charRes[search->cursor][j],(struct ImageProxy *)&loaded);
            CLACT_SetActorImageProxy(search->sprites[i][j],(const struct ImageProxy *)(&loaded));
            CLACT_SetActorPaletteOffset((struct ClactActor *)(struct Obj *)search->sprites[i][j],POKE_TOOL_CalcIconPalette(entries.species[j],entries.form[j],entries.gender[j],0),0);
            GFL_HEAP_Free(handle);
            CLACT_SetActorDrawEnable((struct ClactActor *)(struct Obj *)search->sprites[i][j],1);
        } else CLACT_SetActorDrawEnable((struct ClactActor *)(struct Obj *)search->sprites[i][j],0);
    }
    if(step==1) { ++search->cursor; if(search->cursor>4) search->cursor=0; }
    ARC_TOOL_DeleteHandle(archive);
}

/*
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * blocker-symbols: BattleRecModeTable 0x0209DDCC data a4
 * + *   typedef unsigned char u8;
 *   typedef unsigned short u16;
 *   typedef unsigned long long u64;
 *   extern const u16 BattleRecModeTable[];
 *   u64 BATTLE_REC_GetHeaderParam(char *p, int selector, int index)
 *   {
 *       int i;
 *       u16 v;
 *       switch (selector) {
 *       case 0:
 *           v = ((u16 *)p)[index];
 *           if (v > 0x289) return 0;
 *           return v;
 *       case 1:
 *           return *(u8 *)(p + index + 0x18) & 0x7F;
 *       case 2:
 *           v = *(u16 *)(p + 0x24);
 *           if (v > 0x270F) return 0x270F;
 *           return v;
 *       case 3:
 *           for (i = 0; i < 0x29; i++) {
 *               if (*(u16 *)(p + 0x26) == BattleRecModeTable[i]) return i;
 *           }
 *           return 0;
 *       case 4:
 *           return *(u64 *)(p + 0x38);
 *       case 5:
 *           return *(u8 *)(p + 0x2A);
 *       case 6:
 *           return (*(u8 *)(p + index + 0x18) & 0x80) >> 7;
 *       case 7:
 *           return *(u8 *)(p + 0x2B);
 *       default:
 *           return 0;
 *       }
 *   }
 * checks: 1 full callee reads 3 args, 64-bit return; 2 no filed twin; 3 int base/long index unchanged (2/2); 4 named base and second declaration order close DIFF (2/2); 5 fresh idiom/neighbour reread, no stack-object residue. Both reorder variants consumed.
 */
void BR_CODEIN_SearchBuildHeader(struct BrCachedRecord *work, struct Entries *out)
{
    long i;
    int a, b, c;
    void *base;
    int special, n = 0;
    unsigned int count;
    MI_CpuFill8(out, 0, sizeof(struct Entries));
    base = work->header;
    switch ((int)BATTLE_REC_GetHeaderParam(base, 3, 0)) {
    case 16: case 17: case 18: case 19: case 22:
        special = 1;
        count = 9;
        break;
    default:
        special = 0;
        count = 6;
        break;
    }
    for (i = 0; i < count; i++) {
        if (special && i >= 3 && i <= 5) continue;
        a = BATTLE_REC_GetHeaderParam(base, 0, i);
        b = BATTLE_REC_GetHeaderParam(base, 1, i);
        c = BATTLE_REC_GetHeaderParam(base, 6, i);
        if (a >= SPECIES_LAST + 2) a = 0;
        if (a != 0) {
            out->species[n] = a;
            out->form[n] = b;
            out->gender[n] = c;
            n++;
        }
    }
}

int BR_CODEIN_SearchHitBox(int x, int y)
{
    int ok = ((unsigned)(x - 80) <= 88) & ((unsigned)(y - 32) <= 56);
    if (ok) GFL_USE_PlaySeDefaultVolume(0x703);
    return ok;
}


extern int (*const d_021E3858[])(char *);


