/*
 * file:     br_codein.c
 * unit:     yes
 * function: BR_CODEIN_CodeCreate, BR_CODEIN_CodeDestroy, BR_CODEIN_CodeMain, BR_CODEIN_CodeSetupButtons, BR_CODEIN_CodeDeleteButtons, BR_CODEIN_CodeStepInput, BR_CODEIN_CodeSetupMenu, BR_CODEIN_CodeDeleteMenu, BR_CODEIN_CodeStepMenu, BR_CODEIN_CodeOpenPokeSearch, BR_CODEIN_CodeClosePokeSearch, BR_CODEIN_CodeStepPokeSearch, BR_CODEIN_CodeSetupPokeList, BR_CODEIN_CodeDeletePokeList, BR_CODEIN_CodeStepPokeList, BR_CODEIN_CodeSetupText, BR_CODEIN_CodeDeleteText, BR_CODEIN_CodeSetMenuText, BR_CODEIN_CodeHitTestOptions, BR_CODEIN_ProfileScreenCreate, BR_CODEIN_ProfileScreenDestroy, BR_CODEIN_ProfileScreenMain, BR_CODEIN_ProfileCreate, BR_CODEIN_ProfileUpdate, BR_CODEIN_ProfileGetState, BR_CODEIN_ProfileGetValue, BR_CODEIN_ProfileDestroy, BR_CODEIN_ProfileCreateObject, BR_CODEIN_ProfileDestroyObject, BR_CODEIN_ProfileNoop
 * address:  0x021DF920
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
 *   BR_CODEIN_ProfileDeleteActor  0x021E08E4  thumb  ov183
 *   BR_CODEIN_ProfileInitRecordLayout  0x021E1244  thumb  ov183
 *   BR_CODEIN_ProfileUpdateActorAnim  0x021E16E4  thumb  ov183
 *   BR_CODEIN_ProfileCreateButtons  0x021E1910  thumb  ov183
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
#include "../ov183/br_codein_disp.h"
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


int BR_CODEIN_CodeCreate(void *obj, int unused, struct BrProcArgSave *arg)
{
    struct CodeinCodeWork *p;
    int i;
    p = PROCSYS_AllocProcWork(obj, sizeof(*p), BR_PROC_SYS_GetSlotId(arg->proc));
    MI_CpuFill8(p, 0, sizeof(*p));
    p->heapId = BR_PROC_SYS_GetSlotId(arg->proc);
    p->printQue = (void *)PRINTSYS_QUE_Create(p->heapId);
    (p->oamSys) = BMP_OAM_CreateSys(p->heapId, arg->unit);
    p->codeWin = BR_UTIL_CreateTextWin((void *)arg->res, (void *)(p->printQue), p->heapId);
    BR_UTIL_SetWindowText((char *)((*(void **)&p->codeWin)), arg->res, 0x6B);
    for (i = 0; i < 2; i++) {
        (&p->fx)[i] = BR_UTIL_CreateHandles((void *)(arg->unit), arg->res, i, p->heapId);
    }
    arg->species = 0xFFFF;
    arg->language = 0xFF;
    arg->version = 0xFF;
    arg->category = 0x13;
    BR_RES_LoadSprite((struct BrRes *)((char *)(arg->res)), 6, p->heapId);
    BR_CODEIN_CodeSetupText(p, arg);
    return 1;
}

int BR_CODEIN_CodeDestroy(void *work, int unused, struct BrProcArgSave *arg, struct CodeinCodeWork *data)
{
    int i;
    BR_CODEIN_CodeDeleteText(data, arg);
    BR_RES_ReleaseSprite((struct BrRes *)((char *)(arg->res)), 6);
    for (i = 0; i < 2; i++) BR_UTIL_DeleteHandles((&data->fx)[i]);
    BR_UTIL_DeleteTextWin(data->codeWin, arg->res);
    BMP_OAM_DeleteSys((void *)data->oamSys);
    PRINTSYS_QUE_Delete(data->printQue);
    PROCSYS_FreeProcWork(work);
    return 1;
}

int BR_CODEIN_CodeMain(void *unused,u32 *state,struct BrProcArgSave *arg,struct CodeinCodeWork *work)
{
    int i;
    switch(*state) {
    case 0: if(d_021E37A8[work->stage].init(work,arg)) ++*state; break;
    case 1: BR_FADE_Start(arg->fade,2,3,0); ++*state; break;
    case 2: if(BR_FADE_GetResult(arg->fade)) *state=3; break;
    case 3: if(d_021E37A8[work->stage].update(work,arg)) {
        if(work->nextStage==-1) *state=10; else *state=4;
    } break;
    case 4: BR_FADE_Start(arg->fade,2,2,1); ++*state; break;
    case 5: if(BR_FADE_GetResult(arg->fade)) ++*state; break;
    case 6: if(d_021E37A8[work->stage].finish(work,arg)) {
        work->stage=work->nextStage; ++*state;
    } break;
    case 7: if(d_021E37A8[work->stage].init(work,arg)) ++*state; break;
    case 8: BR_FADE_Start(arg->fade,2,2,0); ++*state; break;
    case 9: if(BR_FADE_GetResult(arg->fade)) *state=3; break;
    case 10: BR_FADE_Start(arg->fade,2,3,1); ++*state; break;
    case 11: if(BR_FADE_GetResult(arg->fade)) *state=12; break;
    case 12: if(d_021E37A8[work->stage].finish(work,arg)) return 1; break;
    }
    for(i=0;i<3;i++) if(work->buttonText[i]) BR_UTIL_FlushText(work->buttonText[i]);
    for(i=0;i<6;i++) if(work->text[i]) BR_UTIL_FlushText(work->text[i]);
    if(work->codeWin) BR_UTIL_FlushWindow(work->codeWin);
    PRINTSYS_QUE_Main(work->printQue);
    for(i=0;i<2;i++) BR_UTIL_RunHandles((&work->fx)[i]);
    return 0;
}

int BR_CODEIN_CodeSetupButtons(struct CodeinCodeWork *work,struct BrProcArgSave *arg)
{
    void *first; void *second; int i;
    BrCodeinParams req;
    BrCodeinTriple triple;
    const struct Rec6 *r;
    const struct Rec8 *s;
    first=BR_RES_GetFont((struct BrRes *)(arg->res));
    second=BR_RES_GetMsgData((struct BrRes *)(arg->res));
    BR_RES_LoadBgGraphics((void *)(arg->res),26,work->heapId);
    MI_CpuFill8(&req,0,8);
    BR_RES_GetSprite((void *)arg->res,6,&triple);
    for(i=0;i<2;i++) {
        r=&d_021E3734[i];
        req.a=r->x; req.b=r->y; req.c=r->id; req.flag=1;
        work->button[i]=BR_BTN_CreateFromMessage((void *)&req,r->file,0x60,1,(void *)arg->unit,(void *)work->oamSys,(void *)first,(struct MsgBank *)second,(void *)&triple,work->heapId);
    }
    for(i=0;i<3;i++) {
        s=&d_021E3740[i];
        work->buttonText[i]=BR_UTIL_Create(4,s->a,s->b,s->c,s->d,14,work->printQue,work->heapId);
        BR_UTIL_SetTextFromMessage(*(char * *)&work->buttonText[i],(void *)second,s->value,(void *)first,0x3da0);
    }
    BR_UTIL_SetWindowText(work->codeWin,arg->res,107);
    return 1;
}

int BR_CODEIN_CodeDeleteButtons(struct CodeinCodeWork *work, struct BrProcArgSave *arg)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (work->buttonText[i] != 0) {
            BR_UTIL_Delete(work->buttonText[i]);
            work->buttonText[i] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (work->button[i] != 0) {
            BR_BTN_DeleteObject(work->button[i]);
            work->button[i] = 0;
        }
    }
    BG_SYS_PushTile(4);
    BR_RES_ApplyBgSet((void *)arg->res, 26);
    return 1;
}

/*
 * lever: A separate result!=3 guard around the three-case switch removes the extra 8-byte dense dispatch (460 to 452 B).
 */
int BR_CODEIN_CodeStepInput(struct CodeinCodeWork *work,struct BrProcArgSave *arg)
{
    int result=BR_CODEIN_CodeHitTestOptions();
    if(result!=3) {
    switch(result) {
    case 0: {
        u32 x,y;
        Point args;
        TOUCHPANEL_GetPointTrg((u32 *)&x,(u32 *)&y);args.x=x;args.y=y;
        BR_UTIL_StartEffect((char *)((void *)work->tapFx),1,(const BrPair *)&args);
        GFL_USE_PlaySeDefaultVolume(0x703);
        arg->category=19;
        BR_CODEIN_CodeSetMenuText(work,arg,0);
        BR_UTIL_SetWindowText(work->codeWin,arg->res,105);
        work->nextStage=1;
        return 1;
    }
    case 1: {
        u32 x,y;
        Point args;
        TOUCHPANEL_GetPointTrg((u32 *)&x,(u32 *)&y);args.x=x;args.y=y;
        BR_UTIL_StartEffect((char *)((void *)work->tapFx),1,(const BrPair *)&args);
        GFL_USE_PlaySeDefaultVolume(0x703);
        arg->species=0xffff;
        BR_CODEIN_CodeSetMenuText(work,arg,1);
        BR_UTIL_SetWindowText(work->codeWin,arg->res,106);
        work->nextStage=2;
        return 1;
    }
    case 2: {
        void *v;
        int a,b;
        u32 x,y;
        Point args;
        v=GAME_DATA_GetMyStatus(arg->gameData);
        a=MYSTATUS_GetNation(v);b=MYSTATUS_GetArea(v);
        if(!a && !b) {
            BR_UTIL_SetWindowText(work->codeWin,arg->res,120);
            GFL_USE_PlaySeDefaultVolume(0x704);
            break;
        }
        TOUCHPANEL_GetPointTrg((u32 *)&x,(u32 *)&y);args.x=x;args.y=y;
        BR_UTIL_StartEffect((char *)((void *)work->tapFx),1,(const BrPair *)&args);
        GFL_USE_PlaySeDefaultVolume(0x703);
#if LANGUAGE == LANGUAGE_JAPANESE
        arg->language=255;arg->version=255;
        BR_CODEIN_CodeSetMenuText(work,arg,2);
        work->nextStage=3;
        return 1;
#else
        if(arg->language==255){arg->language=a;arg->version=b;}
        else{arg->language=255;arg->version=255;}
        BR_CODEIN_CodeSetMenuText(work,arg,2);
        return 0;
#endif
    }
    }
    }
    {
        u32 x,y;
        if(TOUCHPANEL_GetPointTrg(&x,&y)) {
            if(BR_BTN_HitTestWithSound(work->button[0],x,y)) {
                Point args;
                args.x=x;args.y=y;
                BR_UTIL_StartEffect((char *)((void *)work->tapFx),1,(const BrPair *)&args);
                work->nextStage=-1;
                BR_PROC_SYS_PopEntry((arg->proc));
                return 1;
            }
            if(BR_BTN_TestHitBox(work->button[1],x,y)) {
                if(arg->species!=0xffff || arg->version!=255 || arg->category!=19) {
                    Point args;
                    args.x=x;args.y=y;
                    GFL_USE_PlaySeDefaultVolume(0x703);
                    BR_UTIL_StartEffect((char *)((void *)work->tapFx),1,(const BrPair *)&args);
                    work->nextStage=-1;
                    BR_PROC_SYS_PushEntry(arg->proc,5);
                    return 1;
                }
                GFL_USE_PlaySeDefaultVolume(0x704);
                BR_UTIL_SetWindowText(work->codeWin,arg->res,108);
            }
        }
    }
    return 0;
}

int BR_CODEIN_CodeSetupMenu(struct CodeinCodeWork *work,struct BrProcArgSave *arg)
{
    void *first; void *second; int i;
    CodeinListMenuConfig cfg;
    BrCodeinTriple triple;
    BrCodeinParams params;
    first=BR_RES_GetFont((struct BrRes *)(arg->res));
    second=BR_RES_GetMsgData((struct BrRes *)(arg->res));
    BR_RES_LoadBgGraphics((void *)(arg->res),27,work->heapId);
    *(BmpMenuWorkSlot * *)&work->menuWork=(struct BmpMenuWorkSlot *)BMP_MENUWORK_Create(19,work->heapId);
    for(i=0;i<19;i++)BMP_MENUWORK_AddMsgItem((struct BmpMenuWork *)(BmpMenuWorkSlot *)((char *)*(BmpMenuWorkSlot * *)&work->menuWork+i*8),(struct MsgBank *)second,i+205,i,work->heapId);
    *(CfgTpl *)&cfg=d_021E3758;
    cfg.list=(BrCodeinItem *)work->menuWork;cfg.count=19;
    cfg.resources=arg->res;cfg.manager=arg->unit;
    work->listMenu=BR_UTIL_CreateListMenu(&cfg,work->heapId);
    MI_CpuFill8((void *)&params,0,8);
    BR_RES_GetSprite((struct BrRes *)((void *)arg->res), 6, (void *)((BrCodeinTriple *)&triple));
    params.a=d_021E3728[0].x;params.b=d_021E3728[0].y;params.c=d_021E3728[0].id;params.flag=1;
    (*(void * *)&work->button[0])=BR_BTN_CreateFromMessage((void *)&params,d_021E3728[0].file,96,1,(void *)arg->unit,(void *)work->oamSys,(void *)first,(struct MsgBank *)second,(void *)&triple,work->heapId);
    return 1;
}

int BR_CODEIN_CodeDeleteMenu(struct CodeinCodeWork *work, struct BrProcArgSave *arg)
{
    if ((*(void * *)&work->button[0])) {
        BR_BTN_DeleteObject((*(void * *)&work->button[0]));
        (*(void * *)&work->button[0]) = 0;
    }
    BR_UTIL_DeleteListMenu(work->listMenu);
    work->listMenu = 0;
    BMP_MENUWORK_Delete((void *)work->menuWork);
    work->menuWork = 0;
    BR_RES_ApplyBgSet((void *)arg->res, 27);
    BG_SYS_PushTile(4);
    return 1;
}

int BR_CODEIN_CodeStepMenu(struct CodeinCodeWork *work, struct BrProcArgSave *arg)
{
    int selected, pressed;
    unsigned int x, y;
    BR_UTIL_MainListMenu(work->listMenu);
    selected = BR_UTIL_GetListMenuHitId(work->listMenu);
    pressed = TOUCHPANEL_GetPointTrg(&x, &y);
    pressed &= BR_BTN_HitTestWithSound(work->button[0], x, y);
    if (selected != -1) {
        unsigned int x1, y1;
        Point args;
        TOUCHPANEL_GetPointTrg((u32 *)&x1, (u32 *)&y1);
        args.x = x1;
        args.y = y1;
        BR_UTIL_StartEffect((char *)((void *)work->tapFx), 1, (const BrPair *)&args);
        arg->category = selected;
        BR_CODEIN_CodeSetMenuText(work, arg, 0);
        work->nextStage = 0;
        return 1;
    } else if (pressed != 0) {
        unsigned int x2, y2;
        Point args;
        TOUCHPANEL_GetPointTrg((u32 *)&x2, (u32 *)&y2);
        args.x = x2;
        args.y = y2;
        BR_UTIL_StartEffect((char *)((void *)work->tapFx), 1, (const BrPair *)&args);
        work->nextStage = 0;
        return 1;
    }
    return 0;
}

unsigned BR_CODEIN_CodeOpenPokeSearch(struct CodeinCodeWork *work, struct BrProcArgSave *arg)
{
    work->pokeSearch = (char *)BR_POKESEARCH_Create(ZUKAN_SAVE_GetFromGameData((arg->gameData)), (arg->res), arg->unit, work->oamSys, (struct BrFade *)arg->fade, (work->fx), (struct BrTapFx *)work->tapFx, work->heapId);
    BR_POKESEARCH_Open((struct BrPokeSearch *)work->pokeSearch);
    return BR_POKESEARCH_UpdatePrint((struct BrPokeSearch *)work->pokeSearch);
}

int BR_CODEIN_CodeClosePokeSearch(struct CodeinCodeWork *work)
{
    BR_POKESEARCH_Close((struct BrPokeSearch *)(*(void * *)&work->pokeSearch));
    BR_POKESEARCH_Destroy((struct BrPokeSearch *)(*(void * *)&work->pokeSearch));
    BG_SYS_PushTile(4);
    return 1;
}

/*
 * lever: Repeat the reset store in both result arms, with return 1 shared after them; hoisting the store removes the branch at 0x021E00C8.
 */
int BR_CODEIN_CodeStepPokeSearch(struct CodeinCodeWork *work, struct BrProcArgSave *arg)
{
    u16 out;
    int result;
    BR_POKESEARCH_Main((struct BrPokeSearch *)*(char * *)&work->pokeSearch);
    result = BR_POKESEARCH_GetResult((struct BrPokeSearch *)*(int * *)&work->pokeSearch, &out);
    if (result) {
        if (result == 2) {
            arg->species = out;
            BR_CODEIN_CodeSetMenuText(work, arg, 1);
            work->nextStage = 0;
        } else {
            work->nextStage = 0;
        }
        return 1;
    }
    return 0;
}

int BR_CODEIN_CodeSetupPokeList(struct CodeinCodeWork *work,struct BrProcArgSave *arg)
{
    void *first; void *second; int a, b;
    void *v,*text,*data;
    void *ws;
    CodeinListMenuConfig cfg;
    BrCodeinTriple triple;
    BrCodeinParams params;
    first=BR_RES_GetFont((struct BrRes *)(arg->res));
    second=BR_RES_GetMsgData((struct BrRes *)(arg->res));
    BR_RES_LoadBgGraphics((void *)(arg->res),28,work->heapId);
    text=STRBUF_Create(128,work->heapId);
    v=GAME_DATA_GetMyStatus((struct GameData *)((arg->gameData)));
    a=MYSTATUS_GetNation(v);b=MYSTATUS_GetArea(v);
    ws=BR_RES_GetWordSet((struct BrRes *)(arg->res));
    data=MSGDATA_AllocString((void *)second,125);
    if(!NATION_AREA_GetAreaCount(a))WORDSET_SetSlotFromMsgE7((void *)ws,0,a);
    else WORDSET_SetSlotFromKeyedMessage((void *)ws,0,a,b);
    WORDSET_CopyTaggedText((void *)ws,text,data);
    STRBUF_Delete(data);
    *(BmpMenuWorkSlot * *)&work->menuWork=(struct BmpMenuWorkSlot *)BMP_MENUWORK_Create(1,work->heapId);
    BMP_MENUWORK_AddStrItem((struct BmpMenuWork *)*(BmpMenuWorkSlot * *)&work->menuWork,(const struct U16Vec *)text,0,work->heapId);
    STRBUF_Delete(text);
    *(CfgTpl *)&cfg=d_021E3780;
    cfg.list=(BrCodeinItem *)work->menuWork;cfg.count=1;
    cfg.resources=arg->res;cfg.manager=arg->unit;
    work->listMenu=BR_UTIL_CreateListMenu(&cfg,work->heapId);
    MI_CpuFill8((void *)&params,0,8);
    BR_RES_GetSprite((struct BrRes *)((void *)arg->res), 6, (void *)((BrCodeinTriple *)&triple));
    params.a=d_021E372E[0].x;params.b=d_021E372E[0].y;params.c=d_021E372E[0].id;params.flag=1;
    (*(void * *)&work->button[0])=BR_BTN_CreateFromMessage((void *)&params,d_021E372E[0].file,96,1,(void *)arg->unit,(void *)work->oamSys,(void *)first,(struct MsgBank *)second,(void *)&triple,work->heapId);
    return 1;
}

int BR_CODEIN_CodeDeletePokeList(struct CodeinCodeWork *work, struct BrProcArgSave *arg)
{
    if ((*(void * *)&work->button[0])) {
        BR_BTN_DeleteObject((*(void * *)&work->button[0]));
        (*(void * *)&work->button[0]) = 0;
    }
    BR_UTIL_DeleteListMenu(work->listMenu);
    work->listMenu = 0;
    BMP_MENUWORK_Delete((void *)work->menuWork);
    work->menuWork = 0;
    BR_RES_ApplyBgSet((void *)arg->res, 28);
    BG_SYS_PushTile(4);
    return 1;
}

/*
 * trailing: two zero alignment bytes at 0x021E02F6
 */
int BR_CODEIN_CodeStepPokeList(struct CodeinCodeWork *work, struct BrProcArgSave *arg)
{
    int selected, pressed;
    unsigned int x, y;
    BR_UTIL_MainListMenu(work->listMenu);
    selected = BR_UTIL_GetListMenuHitId(work->listMenu);
    pressed = TOUCHPANEL_GetPointTrg(&x, &y);
    pressed &= BR_BTN_HitTestWithSound(work->button[0], x, y);
    if (selected != -1) {
        unsigned int x1, y1;
        Point args;
        void *v;
        int a;
        TOUCHPANEL_GetPointTrg((u32 *)&x1, (u32 *)&y1);
        args.x = x1;
        args.y = y1;
        BR_UTIL_StartEffect((char *)((void *)work->tapFx), 1, (const BrPair *)&args);
        v = GAME_DATA_GetMyStatus(arg->gameData);
        a = MYSTATUS_GetNation(v);
        arg->version = MYSTATUS_GetArea(v);
        arg->language = a;
        BR_CODEIN_CodeSetMenuText(work, arg, 2);
        work->nextStage = 0;
        return 1;
    } else if (pressed != 0) {
        unsigned int x2, y2;
        Point args;
        TOUCHPANEL_GetPointTrg((u32 *)&x2, (u32 *)&y2);
        args.x = x2;
        args.y = y2;
        BR_UTIL_StartEffect((char *)((void *)work->tapFx), 1, (const BrPair *)&args);
        work->nextStage = 0;
        return 1;
    }
    return 0;
}

void BR_CODEIN_CodeSetupText(struct CodeinCodeWork *work, struct BrProcArgSave *arg)
{
    void *first; void *second; int i;
    const BrCodeinRecord *r;
    first = BR_RES_GetFont(arg->res);
    second = BR_RES_GetMsgData(arg->res);
    BR_RES_LoadBgGraphics(arg->res, 25, work->heapId);
    for (i = 0; i < 6; i++) {
        r = &d_021E37D8[i];
        work->text[i] = BR_UTIL_Create(1, r->a, r->b, r->c, r->d, 14, work->printQue, work->heapId);
#if LANGUAGE != LANGUAGE_JAPANESE
        BR_UTIL_SetTextLayout(work->text[i], 0, 1, 0);
#endif
        BR_UTIL_SetTextFromMessage(work->text[i], (void *)second, r->value, (void *)first, 15776);
    }
}

/*
 * extent: final two bytes are alignment padding.
 */
void BR_CODEIN_CodeDeleteText(struct CodeinCodeWork *work,struct BrProcArgSave *arg){int i;for(i=0;i<6;i++){if(work->text[i]){BR_UTIL_Delete((u8 *)work->text[i]);work->text[i]=0;}}BR_RES_ApplyBgSet((void *)arg->res,25);BG_SYS_PushTile(1);}

void BR_CODEIN_CodeSetMenuText(struct CodeinCodeWork *work,struct BrProcArgSave *arg,int mode)
{
    void *first; void *second; void *ws;
    void *data,*text;
    first=BR_RES_GetFont((struct BrRes *)(arg->res));
    second=BR_RES_GetMsgData((struct BrRes *)(arg->res));
    switch(mode) {
    case 0:
        if(arg->category!=19)BR_UTIL_SetTextFromMessage(work->text[1],(void *)second,arg->category+205,(void *)first,0x3da0);
        else BR_UTIL_SetTextFromMessage(work->text[1],(void *)second,117,(void *)first,0x3da0);
        return;
    case 1:
        if(arg->species!=0xffff)BR_UTIL_SetTextFromMessage(work->text[3],gSpeciesNameBank,(u32)arg->species,(void *)first,0x3da0);
        else BR_UTIL_SetTextFromMessage(work->text[3],(void *)second,117,(void *)first,0x3da0);
        return;
    case 2:
        if(arg->language==255 && arg->version==255) {
            BR_UTIL_SetTextFromMessage((char *)work->text[5],(void *)second,117,(void *)first,0x3da0);
            return;
        }
        ws=BR_RES_GetWordSet((struct BrRes *)(arg->res));
        data=MSGDATA_AllocString((void *)second,24);
        text=STRBUF_Create(128,work->heapId);
        if(!NATION_AREA_GetAreaCount(arg->language))WORDSET_SetSlotFromMsgE7((void *)ws,0,arg->language);
        else WORDSET_SetSlotFromKeyedMessage((void *)ws,0,arg->language,arg->version);
        WORDSET_CopyTaggedText((void *)ws,text,data);
        BR_UTIL_SetTextFromBuffer(work->text[5],text,(void *)first,0x3da0);
        STRBUF_Delete(data);STRBUF_Delete(text);
        break;
    }
}

/*
 * Hit-test a point against a table of three rectangles; returns the index
 * of the first hit, or 3 when none (or when no point is available).
 */
int BR_CODEIN_CodeHitTestOptions(void)
{
    unsigned int x, y;
    int i;

    if (TOUCHPANEL_GetPointTrg(&x, &y)) {
        for (i = 0; i < 3; i++) {
            const BrCodeinRect *r = &g_021E3808[i];
            if (x - r->x0 <= r->x1 - r->x0 && y - r->y0 <= r->y1 - r->y0) {
                return i;
            }
        }
    }
    return 3;
}

/*
 * extent: 021E05C2 alignment padding.
 */
int BR_CODEIN_ProfileScreenCreate(void *task, int unused, struct BrProcArgHead *arg)
{
    struct CodeinWorkData *p;
    int entries[3];
    BR_RES_GetFont((struct BrRes *)((char *)(arg->res)));
    BR_RES_GetMsgData((struct BrRes *)(arg->res));
    p = PROCSYS_AllocProcWork(task, sizeof(struct CodeinWorkData), BR_PROC_SYS_GetSlotId(arg->proc));
    MI_CpuFill8(p, 0, sizeof(struct CodeinWorkData));
    p->heap = BR_PROC_SYS_GetSlotId(arg->proc);
    BR_RES_LoadBgGraphics((void *)(arg->res), 29, p->heap);
    BR_RES_LoadSprite((struct BrRes *)(arg->res), 11, p->heap);
    BR_RES_LoadSprite((struct BrRes *)(arg->res), 12, p->heap);
    BR_RES_LoadSprite((struct BrRes *)(arg->res), 6, p->heap);
    p->handles = BR_UTIL_CreateHandles((void *)(((arg->unit))), arg->res, 1, p->heap);
    entries[0] = 2;
    entries[1] = 5;
    entries[2] = 5;
    p->object = BR_CODEIN_ProfileCreateObject(p->heap, 12, (arg->unit), (void *)(arg->res), p->handles, entries);
    p->profile = BR_CODEIN_ProfileCreate(p->object, p->heap);
    p->printQue = (void *)PRINTSYS_QUE_Create(p->heap);
    p->textWin = BR_UTIL_CreateTextWin((void *)arg->res, (void *)p->printQue, p->heap);
    BR_UTIL_SetWindowText(p->textWin, arg->res, 104);
    return 1;
}

/*
 * extent: 021E0616 alignment padding; next owned function starts 021E0618.
 */
int BR_CODEIN_ProfileScreenDestroy(void *proc, int unused, struct BrProcArgHead *arg, struct CodeinWorkData *work)
{
    BR_UTIL_DeleteTextWin(work->textWin, arg->res);
    BR_CODEIN_ProfileDestroy(work->profile);
    BR_CODEIN_ProfileDestroyObject(work->object);
    PRINTSYS_QUE_Delete((struct PrintQueue *)work->printQue);
    BR_UTIL_DeleteHandles((char *)work->handles);
    BR_RES_ApplyBgSet((void *)arg->res, 29);
    BR_RES_ReleaseSprite((struct BrRes *)((char *)arg->res), 6);
    BR_RES_ReleaseSprite((struct BrRes *)((char *)arg->res), 12);
    BR_RES_ReleaseSprite((struct BrRes *)((char *)arg->res), 11);
    PROCSYS_FreeProcWork(proc);
    return 1;
}

/*
 * extent: 021E06CE alignment padding.
 */
int BR_CODEIN_ProfileScreenMain(int unused, int *state, struct BrProcArgHead *arg, struct CodeinWorkData *work)
{
    switch (*state) {
    case 0:
        BR_FADE_Start((void *)arg->fade, 2, 3, 0);
        *state = 1;
        break;
    case 1:
        if (BR_FADE_GetResult((struct BrFade *)arg->fade)) *state = 2;
        break;
    case 2:
        BR_CODEIN_ProfileUpdate((struct CodeinProfileWork *)work->profile);
        switch (BR_CODEIN_ProfileGetState((struct CodeinProfileWork *)work->profile)) {
        case 1: BR_PROC_SYS_PopEntry((struct BrProcSysContext *)arg->proc); *state = 3; break;
        case 2: arg->result = BR_CODEIN_ProfileGetValue((struct CodeinProfileWork *)work->profile); BR_PROC_SYS_PushEntry((struct BrProcSysContext *)arg->proc, 2); *state = 3; break;
        }
        break;
    case 3:
        BR_FADE_Start((void *)arg->fade, 2, 3, 1);
        *state = 4;
        break;
    case 4:
        if (BR_FADE_GetResult((struct BrFade *)arg->fade)) *state = 5;
        break;
    case 5: return 1;
    }
    if (work->textWin) BR_UTIL_FlushWindow((void *)work->textWin);
    PRINTSYS_QUE_Main((struct PrintQueue *)work->printQue);
    BR_UTIL_RunHandles((char *)work->handles);
    return 0;
}

/*
 * extent: 0754 tail-call stub; 075C state getter; 0764 64-bit getter; 0772 padding.
 */
struct CodeinProfileWork *BR_CODEIN_ProfileCreate(const CfgTpl *src, u16 heap)
{
    struct CodeinProfileWork *p;
    p = GFL_HEAP_Alloc(heap, sizeof(struct CodeinProfileWork), 0, PM_LANG_JA(d_021E3968, str_ja_021E39AC), 56);
    MI_CpuFill8(p, 0, sizeof(struct CodeinProfileWork));
    p->object = *src;
    p->profileHeapId = heap;
    (p->actorSys) = src->actorSys;
    p->font = BR_RES_GetFont(src->res);
    p->arcHandle = ARC_TOOL_CreateHandle(59, p->profileHeapId);
    BR_CODEIN_ProfileInitRecordLayout(p);
    BR_CODEIN_ProfileCreateButtons(p);
    p->task = GFL_USE_AddMainTask(BR_CODEIN_ProfileNoop, p, 16);
    return p;
}

void BR_CODEIN_ProfileUpdate(struct CodeinProfileWork *work)
{
    BR_CODEIN_ProfileUpdateActorAnim(work);
}

int BR_CODEIN_ProfileGetState(struct CodeinProfileWork *work)
{
    return work->state;
}

u64 BR_CODEIN_ProfileGetValue(struct CodeinProfileWork *work)
{
    return work->result;
}

void BR_CODEIN_ProfileDestroy(struct CodeinProfileWork *work){TCB_DeleteTask(work->task);BR_CODEIN_ProfileDeleteActor(work);ARC_TOOL_DeleteHandle(work->arcHandle);BUTTON_MAN_Delete(work->buttonMan);GFL_HEAP_Free(work);}

struct BrCodeinObject *BR_CODEIN_ProfileCreateObject(int heap, int n, void *actorSys, void *res, void *handles, int *entries)
{
    int i;
    struct BrCodeinObject *p;
    p = GFL_HEAP_Alloc((u16)heap, sizeof(struct BrCodeinObject), 0, PM_LANG_JA(d_021E3968, str_ja_021E39AC), 192);
    p->actorSys = actorSys;
    p->res = res;
    p->capacity = n;
    p->vector = STRBUF_Create(n + 1, heap);
    p->handles = handles;
    for (i = 0; i < 3; i++) p->entries[i] = entries[i];
    p->entries[i] = entries[i - 1];
    return p;
}

/*
 * extent: existing matched callback 021E083C and its alignment follow the pool.
 */
void BR_CODEIN_ProfileDestroyObject(struct BrCodeinObject *work){if(!work->vector)GF_PANIC_Fail(PM_LANG_JA(d_021E3974, str_ja_021E39AC), PM_SRC_LINE(0, 0xDC), PM_LANG_JA(d_021E3974, str_ja_021E39B8));if(!work)GF_PANIC_Fail(PM_LANG_JA(d_021E3974, str_ja_021E39AC), PM_SRC_LINE(0, 0xDD), PM_LANG_JA(d_021E3974, str_ja_021E39D8));STRBUF_Delete(work->vector);GFL_HEAP_Free(work);}

/*
 * leaf: empty callback solely blocks owned constructor 021E06D0; parent cleared.
 * extent: bx lr at 083C; 083E alignment; existing owned 0840 follows.
 */
void BR_CODEIN_ProfileNoop(struct TcbTask *unused, void *work)
{
}


extern int (*const d_021E3858[])(char *);


