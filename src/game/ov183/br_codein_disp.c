/*
 * file:     br_codein_disp.c
 * unit:     yes
 * function: BR_CODEIN_ProfileSetupSprite, BR_CODEIN_ProfileDeleteActor, BR_CODEIN_ProfileCreateRecordActors, BR_CODEIN_ProfileCreateMarkerActors, BR_CODEIN_ProfileCreateArrowActors, BR_CODEIN_ProfileSetActorVisible, BR_CODEIN_ProfileSetActorPos, BR_CODEIN_ProfileAddActorSurfacePos, BR_CODEIN_ProfileUpdateActorAnims, BR_CODEIN_ProfileGetActorIndex, BR_CODEIN_ProfileUpdateActorVisible, BR_CODEIN_ProfileSetActorAnimFrame, BR_CODEIN_ProfileUpdateActorPos, BR_CODEIN_ProfileCreateOam, BR_CODEIN_ProfileDeleteOam, BR_CODEIN_ProfileDeleteBgHandle, BR_CODEIN_ProfileCreateOamObjects, BR_CODEIN_ProfilePrintOamObject, BR_CODEIN_ProfileSetActorAnim, BR_CODEIN_ProfileInitRecordLayout, BR_CODEIN_ProfileSetAnimSeq, BR_CODEIN_ProfileCreateAllActors, BR_CODEIN_ProfileReturnTrue, BR_CODEIN_ProfileUpdatePendingAndButtons, BR_CODEIN_ProfileUpdateScrollAnim, BR_CODEIN_ProfileUpdateActorAnim, BR_CODEIN_ProfileBuildAnimName, BR_CODEIN_ProfileApplyRecords, BR_CODEIN_ProfileCreateButtons, BR_CODEIN_ProfileHandleInput, BR_CODEIN_ProfileApplyPendingStep, BR_CODEIN_ProfileClear, BR_CODEIN_ProfileFindActorIndex, BR_CODEIN_ProfileFindRecord
 * address:  0x021E0840
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
#include "br_codein_disp.h"
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


void BR_CODEIN_ProfileSetupSprite(struct CodeinProfileWork *work)
{
    struct BrCodeinTriple t;
    if (!BR_RES_GetSprite(work->object.res, 11, &t)) GF_PANIC_Fail(PM_LANG_JA(d_021E3978, str_ja_021E39F0), PM_SRC_LINE(0, 0x33), PM_LANG_JA(d_021E3978, str_ja_021E3A04));
    work->sprite11PaletteId = t.c;
    work->sprite11CharId = t.b;
    work->sprite11CellAnimId = t.a;
    if (!BR_RES_GetSprite(work->object.res, 12, &t)) GF_PANIC_Fail(PM_LANG_JA(d_021E3978, str_ja_021E39F0), PM_SRC_LINE(0, 0x3B), PM_LANG_JA(d_021E3978, str_ja_021E3A04));
    work->sprite12PaletteId = t.c;
    work->sprite12CharId = t.b;
    work->sprite12CellAnimId = t.a;
    if (!BR_RES_GetSprite(work->object.res, 6, &t)) GF_PANIC_Fail(PM_LANG_JA(d_021E3978, str_ja_021E39F0), PM_SRC_LINE(0, 0x44), PM_LANG_JA(d_021E3978, str_ja_021E3A04));
    *(int *)&work->sprite6PaletteId = t.c;
    *(int *)&work->sprite6CharId = t.b;
    *(int *)&work->sprite6CellAnimId = t.a;
}

/*
 * extent: 021E0952 alignment padding.
 */
void BR_CODEIN_ProfileDeleteActor(struct CodeinProfileWork *work)
{
    int i;
    for (i = 0; i < work->recordCount; i++) CLACT_DeleteActor(work->slot[CODEIN_PROFILE_SLOT_RECORD + i].actor);
    for (i = 0; i < 2; i++) {
        CLACT_DeleteActor(work->slot[CODEIN_PROFILE_SLOT_SLIDE + i].actor);
        CLACT_DeleteActor(work->slot[CODEIN_PROFILE_SLOT_ARROW + i].actor);
    }
    for (i = 0; i < 3; i++) CLACT_DeleteActor(work->slot[CODEIN_PROFILE_SLOT_MARKER + i].actor);
    BR_CODEIN_ProfileDeleteOam(work);
}

/*
 * lever: The explicit entry guard encloses a do-while; a for adds a second entry test (308 B DIFF to 306 B EXACT*).
 * trailing: 021E0A86..021E0A88 is two zero alignment bytes.
 * abi: 0204B294 caller uses returned r0 despite callee's void spelling; fifth payload remains its u32 address word.
 * note 2026-10-05 (wave D9r lane 131): removed the 7 dead first assignments
 * (`heapA=0x25c;` before `heapA=0x34c;`; `aA=0x25c;` before `aA=0x26c;` and
 * 5 more). Game code has no line table, so these were stand-ins. The plain
 * single assignment gives EXACT* in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void BR_CODEIN_ProfileCreateRecordActors(struct CodeinProfileWork *work)
{
    int i,special,normal;
    void *owner;
    BrCodeinParams params;
    normal=0;
    owner=work->actorSys;
    params.a=normal;params.b=normal;params.c=normal;params.flag=10;params.pad=normal;
    special=0;i=0;
    if(work->recordCount+2>0) {
        do {
            struct CodeinProfileSlot *q;
            q=&work->slot[special];
            if(i==work->slot[CODEIN_PROFILE_SLOT_SLIDE+special].tag+special+1) {
                void *obj;
                params.a=i*8+76;params.b=24;params.c=22;
                obj=CLACT_CreateActor(owner,work->sprite11CharId,work->sprite11PaletteId,work->sprite11CellAnimId,(const struct ActorInitParam *)&params,1,work->profileHeapId);
                work->slot[CODEIN_PROFILE_SLOT_SLIDE+special].actor=obj;CLACT_SetActorObjMode(obj,1);
                special++;
            } else {
                void *obj;
                params.a=i*8+76;params.b=24;
                q=&work->slot[normal];
                params.c=BR_CODEIN_ProfileGetActorIndex(q->tag,q->mode);
                obj=CLACT_CreateActor(owner,work->sprite11CharId,work->sprite11PaletteId,work->sprite11CellAnimId,(const struct ActorInitParam *)&params,1,work->profileHeapId);
                q->actor=obj;CLACT_SetActorObjMode(obj,1);
                normal++;
            }
            i++;
        } while(i<work->recordCount+2);
    }
}

/*
 * abi: 0204B294 r0 consumed after call; pointer request passed as the unchanged u32 fifth payload.
 */
void BR_CODEIN_ProfileCreateMarkerActors(struct CodeinProfileWork *work)
{
    int zero;
    void *owner;
    BrCodeinParams params;
    owner=work->actorSys;zero=0;
    params.a=zero;params.b=zero;params.c=zero;params.flag=zero;params.pad=zero;
    work->slot[CODEIN_PROFILE_SLOT_MARKER].actor=CLACT_CreateActor(owner,work->sprite12CharId,work->sprite12PaletteId,work->sprite12CellAnimId,(const struct ActorInitParam *)&params,1,work->profileHeapId);
    CLACT_SetActorObjMode(work->slot[CODEIN_PROFILE_SLOT_MARKER].actor,1);
    work->slot[CODEIN_PROFILE_SLOT_MARKER+1].actor=CLACT_CreateActor(owner,work->sprite12CharId,work->sprite12PaletteId,work->sprite12CellAnimId,(const struct ActorInitParam *)&params,1,work->profileHeapId);
    CLACT_SetActorObjMode(work->slot[CODEIN_PROFILE_SLOT_MARKER+1].actor,1);
    work->slot[CODEIN_PROFILE_SLOT_MARKER+2].actor=CLACT_CreateActor(owner,work->sprite12CharId,work->sprite12PaletteId,work->sprite12CellAnimId,(const struct ActorInitParam *)&params,1,work->profileHeapId);
    CLACT_SetActorObjMode(work->slot[CODEIN_PROFILE_SLOT_MARKER+2].actor,1);
    BR_CODEIN_ProfileSetActorPos(work,0);
    CLACT_SetActorAnimSeq(work->slot[CODEIN_PROFILE_SLOT_MARKER].actor,0);CLACT_SetActorAutoAnim(work->slot[CODEIN_PROFILE_SLOT_MARKER].actor,1);
    work->slot[CODEIN_PROFILE_SLOT_MARKER+1].moveDx=zero;work->slot[CODEIN_PROFILE_SLOT_MARKER+1].moveDy=zero;work->slot[CODEIN_PROFILE_SLOT_MARKER+1].tag=1;
    BR_CODEIN_ProfileAddActorSurfacePos(work,0);
    CLACT_SetActorAnimSeq(work->slot[CODEIN_PROFILE_SLOT_MARKER+1].actor,work->slot[CODEIN_PROFILE_SLOT_MARKER+1].tag);
    CLACT_SetActorAutoAnim(work->slot[CODEIN_PROFILE_SLOT_MARKER+1].actor,1);CLACT_SetActorObjMode(work->slot[CODEIN_PROFILE_SLOT_MARKER+1].actor,1);
    work->slot[CODEIN_PROFILE_SLOT_MARKER+2].moveDx=zero;work->slot[CODEIN_PROFILE_SLOT_MARKER+2].moveDy=zero;work->slot[CODEIN_PROFILE_SLOT_MARKER+2].tag=1;
    BR_CODEIN_ProfileAddActorSurfacePos(work,zero);
    CLACT_SetActorAnimSeq(work->slot[CODEIN_PROFILE_SLOT_MARKER+2].actor,work->slot[CODEIN_PROFILE_SLOT_MARKER+2].tag);
    CLACT_SetActorObjMode(work->slot[CODEIN_PROFILE_SLOT_MARKER+2].actor,1);CLACT_SetActorAutoAnim(work->slot[CODEIN_PROFILE_SLOT_MARKER+2].actor,1);
    BR_CODEIN_ProfileSetActorVisible(work,1,zero);BR_CODEIN_ProfileSetActorVisible(work,2,zero);
}

/*
 * Caller evidence: 0204B294 leaves its forwarded return word live in r0; consumed by store and 0204B688 here.
 */
void BR_CODEIN_ProfileCreateArrowActors(struct CodeinProfileWork *work) {
    struct PosParams pos;
    void *manager=work->actorSys;
    pos.a=0;pos.b=0;pos.z=0;pos.mode=10;pos.flag=0;
    work->slot[CODEIN_PROFILE_SLOT_ARROW].actor=CLACT_CreateActor(manager,work->sprite6CharId,work->sprite6PaletteId,work->sprite6CellAnimId,(const struct ActorInitParam *)&pos.a,1,work->profileHeapId);
    CLACT_SetActorObjMode(work->slot[CODEIN_PROFILE_SLOT_ARROW].actor,1);
    pos.z=1;
    work->slot[CODEIN_PROFILE_SLOT_ARROW+1].actor=CLACT_CreateActor(manager,work->sprite6CharId,work->sprite6PaletteId,work->sprite6CellAnimId,(const struct ActorInitParam *)&pos.a,1,work->profileHeapId);
    CLACT_SetActorObjMode(work->slot[CODEIN_PROFILE_SLOT_ARROW+1].actor,1);
    pos.x=work->rect[22][2];pos.y=work->rect[22][0]+16;
    CLACT_AddActorSurfacePos(work->slot[CODEIN_PROFILE_SLOT_ARROW].actor,(const struct ClactVec2 *)(&pos.x),1);
    CLACT_SetActorAnimSeq(work->slot[CODEIN_PROFILE_SLOT_ARROW].actor,0);
    pos.x=work->rect[23][2];pos.y=work->rect[23][0]+16;
    CLACT_AddActorSurfacePos(work->slot[CODEIN_PROFILE_SLOT_ARROW+1].actor,(const struct ClactVec2 *)(&pos.x),1);
    CLACT_SetActorAnimSeq(work->slot[CODEIN_PROFILE_SLOT_ARROW+1].actor,PM_LANG_JA(1, 0));
}

void BR_CODEIN_ProfileSetActorVisible(struct CodeinProfileWork *work, int index, int visible)
{
    CLACT_SetActorDrawEnable((work->slot + index)[CODEIN_PROFILE_SLOT_MARKER].actor, (unsigned int)visible);
}

void BR_CODEIN_ProfileSetActorPos(struct CodeinProfileWork *work,int i){short pos[2];void *obj;obj=work->slot[i].actor;work->slot[CODEIN_PROFILE_SLOT_MARKER].tag=i;CLACT_GetActorSurfacePos(obj,(struct ClactVec2 *)pos,1);pos[1]+=16;CLACT_AddActorSurfacePos(work->slot[CODEIN_PROFILE_SLOT_MARKER].actor,(const struct ClactVec2 *)pos,1);}

/*
 * extent: 021E0D8E alignment padding.
 */
void BR_CODEIN_ProfileAddActorSurfacePos(struct CodeinProfileWork *coords, int index)
{
    int width = coords->rect[index + 12][1] - coords->rect[index + 12][0];
    int height = coords->rect[index + 12][3] - coords->rect[index + 12][2];
    s16 pos[2];
    pos[0] = height / 2 + coords->rect[index + 12][2];
    pos[1] = width / 2 + coords->rect[index + 12][0];
    CLACT_AddActorSurfacePos(coords->slot[CODEIN_PROFILE_SLOT_MARKER+1].actor, (const struct ClactVec2 *)pos, 1);
    CLACT_SetActorAnimFrame(coords->slot[CODEIN_PROFILE_SLOT_MARKER+1].actor, 0);
}

/*
 * extent: 021E0E3E alignment padding.
 */
void BR_CODEIN_ProfileUpdateActorAnims(struct CodeinProfileWork *work)
{
    int i, state;
    for (i = 1; i < 3; i++) {
        state = CLACT_GetActorAnimSeq(work->slot[CODEIN_PROFILE_SLOT_MARKER + i].actor);
        if (state == 3) {
            if (!CLACT_IsActorAnimActive(work->slot[CODEIN_PROFILE_SLOT_MARKER + i].actor)) {
                CLACT_SetActorAnimSeq(work->slot[CODEIN_PROFILE_SLOT_MARKER + i].actor, work->slot[CODEIN_PROFILE_SLOT_MARKER + i].tag);
                if (work->markerHidden == 1) BR_CODEIN_ProfileSetActorVisible(work, 1, 0);
                else BR_CODEIN_ProfileSetActorVisible(work, 1, 1);
                BR_CODEIN_ProfileSetActorVisible(work, 2, 0);
            }
        } else {
            if (state != work->slot[CODEIN_PROFILE_SLOT_MARKER + i].tag) CLACT_SetActorAnimSeq(work->slot[CODEIN_PROFILE_SLOT_MARKER + i].actor, work->slot[CODEIN_PROFILE_SLOT_MARKER + i].tag);
            if (CLACT_GetActorAnimSeq(work->slot[CODEIN_PROFILE_SLOT_MARKER + i].actor) != 3) {
                if (work->markerHidden == 1) BR_CODEIN_ProfileSetActorVisible(work, 1, 0);
                else BR_CODEIN_ProfileSetActorVisible(work, 1, 1);
            }
        }
    }
}

int BR_CODEIN_ProfileGetActorIndex(int tag, int mode) { int n=0; if(mode==0)n=11; return n+tag; }

void BR_CODEIN_ProfileUpdateActorVisible(struct CodeinProfileWork *work)
{
    int i;
    for (i = 0; i < work->recordCount; i++) {
        if (i >= work->rangeAFirst && i < work->rangeAEnd)
            work->slot[i].mode = 1;
        else
            work->slot[i].mode = 0;
    }
}

void BR_CODEIN_ProfileSetActorAnimFrame(struct CodeinProfileWork *work,int animated) {
    int i,group;
    s16 pos;
    struct CodeinProfileSlot *record,*special;
    Coords coords;
    pos=work->pos[work->animState];
    group=0;
    for(i=0;i<work->recordCount;i++){
        if(i>=work->rangeAFirst&&i<work->rangeAEnd){
            if(i==work->rangeAFirst)pos+=20;else pos+=32;
        }else{
            if(i==0)pos+=20;else pos+=8;
        }
        record=&work->slot[i];
        CLACT_GetActorSurfacePos(record->actor,(struct ClactVec2 *)&coords.x,1);
        if(animated==0){
            coords.x=pos;
            CLACT_AddActorSurfacePos(record->actor,(const struct ClactVec2 *)(&coords.x),1);
        }else{
            record->moveDx=(pos-coords.x)/4;
            record->moveDy=0;
            record->moveFrames=4;
            record->scaleStep=0;
        }
        special=work->slot+group;
        if(i==special[CODEIN_PROFILE_SLOT_SLIDE].tag&&group!=2){
            CLACT_GetActorSurfacePos(special[CODEIN_PROFILE_SLOT_SLIDE].actor,(struct ClactVec2 *)&coords.a,1);
            if(work->rangeAFirst==work->rangeAEnd)pos+=8;
            else {
                if(i>work->rangeAFirst&&i<work->rangeAEnd)pos+=20;
                else pos+=8;
            }
            if(animated==0){
                coords.a=pos;
                CLACT_AddActorSurfacePos(special[CODEIN_PROFILE_SLOT_SLIDE].actor,(const struct ClactVec2 *)(&coords.a),1);
            }else{
                special[CODEIN_PROFILE_SLOT_SLIDE].moveDx=(pos-coords.a)/4;
                special[CODEIN_PROFILE_SLOT_SLIDE].moveDy=0;
                special[CODEIN_PROFILE_SLOT_SLIDE].moveFrames=4;
            }
            group++;
        }
    }
}

void BR_CODEIN_ProfileUpdateActorPos(struct CodeinProfileWork *work)
{
    int i, x, y;
    s16 pos[2];
    for (i = 0; i < work->recordCount; i++) {
        if (i >= work->rangeAFirst && i < work->rangeAEnd) {
            x = 16;
            y = 16;
        } else {
            x = 4;
            y = 8;
        }
        CLACT_GetActorSurfacePos(work->slot[i].actor, (struct ClactVec2 *)pos, 1);
        work->slot[i].rect[0] = pos[1] - y;
        work->slot[i].rect[2] = pos[0] - x;
        work->slot[i].rect[1] = pos[1] + y;
        work->slot[i].rect[3] = pos[0] + x;
    }
}

void BR_CODEIN_ProfileCreateOam(struct CodeinProfileWork *work)
{
    work->profileOamSys =
        BMP_OAM_CreateSys(work->profileHeapId, work->actorSys);
}

void BR_CODEIN_ProfileDeleteOam(struct CodeinProfileWork *work){ BMP_OAM_Delete(work->grid[0]); BMP_OAM_Delete(work->grid[1]); BMP_OAM_DeleteSys(work->profileOamSys); }

void BR_CODEIN_ProfileDeleteBgHandle(struct CodeinProfileWork *work)
{
    ARC_TOOL_DeleteHandle(ARC_TOOL_CreateHandle(0x17, work->profileHeapId));
}

void BR_CODEIN_ProfileCreateOamObjects(struct CodeinProfileWork *work){ BR_CODEIN_ProfileDeleteBgHandle(work);BR_CODEIN_ProfilePrintOamObject(work,0,32,8,0);BR_CODEIN_ProfilePrintOamObject(work,1,32,8,0); }

/*
 * lever: form slot=&out[index] before the constructor call and store/reload through slot. The direct out[index] spelling sank the output base and left 15 bytes different.
 */
void BR_CODEIN_ProfilePrintOamObject(struct CodeinProfileWork *object,Index index,int x,int y,int unused)
{
    struct CodeinProfileWork *p=object;
    void *source; void *handle; int obj;
    u8 xx,yy;
    struct BmpOam **slots;
    CodeinProfileDescriptor desc;
    source=BR_RES_GetMsgData((struct BrRes *)(p->object.res));
    source=MSGDATA_AllocString((struct MsgBank *)source,d_021E3850[index]);
    handle=BMP_Create(10,2,32,p->profileHeapId);
    PRINTSYS_Print((void *)handle,PM_LANG_JA(1,0),0,(void *)source,(void *)(p->font));
    xx=p->rect[index+22][2];
    yy=p->rect[index+22][0];
    desc.handle=(void *)handle;
    desc.x=xx+x;
    desc.y=yy+y;
    desc.data=(*(int *)&p->sprite6PaletteId);
    desc.zero=0;
    desc.a=0;
    desc.b=0;
    desc.c=1;
    desc.d=1;
    {
        struct BmpOam **out=(struct BmpOam **)p->grid;
        struct BmpOam **slot;
        struct BmpOam *grid;
        slot=&out[index];
        grid=BMP_OAM_Create(object->profileOamSys,(const struct BmpOamParam *)(&desc));
        *slot=grid;
        BMP_OAM_UploadChars((struct BmpOam *)(struct Obj *)(grid));
        BMP_OAM_SetObjMode(*slot,1);
    }
    BMP_Delete((struct Bmp *)handle);
    STRBUF_Delete((struct Strbuf *)source);
}

/*
 * Extent remainder: zero alignment halfword at 021E1242.
 */
void BR_CODEIN_ProfileSetActorAnim(struct CodeinProfileWork *work,int state)
{
    work->prevAnimState=work->animState;
    work->animState=state;
    work->rangeAFirst=0;
    work->rangeAEnd=0;
    work->rangeBFirst=0;
    work->rangeBEnd=0;
    if (state) {
        work->rangeAFirst=work->range[state-1].first;
        work->rangeAEnd=work->range[state-1].end;
    }
    if (work->prevAnimState) {
        work->rangeBFirst=work->range[work->prevAnimState-1].first;
        work->rangeBEnd=work->range[work->prevAnimState-1].end;
    }
}

/*
 * 2026-10-05 (wave P7 lane V7, pengy share): EXACT in c99 and c. The older DIFF28 draft (see docs/notes) closed with two
 * changes. (1) The row index is a block-local initialised BEFORE the table copy (int row = 0, then the const Table copy):
 * the zero then lives across the copy and the copy takes r5/r3 as in the original. (2) The count row pointer of the last
 * loop is a named CodeinProfileState pointer local declared before j (cnt = p + group * 4), which gives j r3
 * and the row pointer r2. Original reads: p[0x2FC] = 1; halfword offsets; a stray store at 0x21A reading row[i - 1] after the
 * copy loop (reproduced as in the listing, probably an off-by-one in the original); no hidden callee arguments.
 */
void BR_CODEIN_ProfileInitRecordLayout(struct CodeinProfileWork *profile)
{
  int i;
  int sum;
  int prefix;
  int group;
  int k;
  struct CodeinProfileWork *cnt;
  int j;
  u16 truncated;
  u16 *tmp;
  profile->markerHidden = 1;
  profile->range[0].first = 0;
  sum = profile->object.entries[0];
  truncated = sum;
  profile->range[0].end = truncated;
  profile->range[1].first = truncated;
  sum += profile->object.entries[1];
  tmp = &profile->range[1].end;
  truncated = sum;
  *tmp = truncated;
  profile->range[2].first = truncated;
  sum = profile->object.entries[2] + ((int) sum);
  profile->range[2].end = sum;
  BR_CODEIN_ProfileSetActorAnim(profile, 1);
  for (i = 0; i < 3; i++)
    profile->recordCount += profile->object.entries[i];

  {
    int row = 0;
    const CodeinProfileTable table = d_021E3868;
    if (profile->object.entries[0] != 4)
      row = 1;
    for (i = 0; i < 3; i++)
      profile->pos[i] = table.row[row].v[i];

    profile->pos[i] = table.row[row].v[i - 1];
    prefix = 0;
    for (group = 0; group < 2; group++)
    {
      prefix += profile->object.entries[group];
      profile->slot[CODEIN_PROFILE_SLOT_SLIDE + group].tag = prefix - 1;
    }

    group = 0;
    j = 0;
    do
    {
      cnt = (struct CodeinProfileWork *)((char *)profile + group * 4);
      for (k = 0; k < cnt->object.entries[0]; k++)
      {
        profile->slot[j].group = group + 1;
        j++;
      }

      group++;
    }
    while (j < profile->recordCount);
  }
}

void BR_CODEIN_ProfileSetAnimSeq(struct CodeinProfileWork *work, int v)
{
    work->animSeq = v;
    work->reserved230 = 0;
    work->phase = 0;
    work->phaseTimer = 0;
}

/*
 * Follower: 021E13D4 return-one stub, after 021E13D2 alignment.
 */
int BR_CODEIN_ProfileCreateAllActors(struct CodeinProfileWork *work)
{
    BR_CODEIN_ProfileSetupSprite(work);
    BR_CODEIN_ProfileUpdateActorVisible(work);
    BR_CODEIN_ProfileCreateRecordActors(work);
    BR_CODEIN_ProfileSetActorAnimFrame(work,0);
    BR_CODEIN_ProfileCreateMarkerActors(work);
    BR_CODEIN_ProfileCreateArrowActors(work);
    BR_CODEIN_ProfileUpdateActorPos(work);
    BR_CODEIN_ProfileCreateOam(work);
    BR_CODEIN_ProfileCreateOamObjects(work);
    BR_CODEIN_ProfileSetAnimSeq(work,1);
    return 0;
}

int BR_CODEIN_ProfileReturnTrue(void)
{
    return 1;
}

s32 BR_CODEIN_ProfileUpdatePendingAndButtons(struct CodeinProfileWork *work)
{
    if (*(s32 *)&work->phase == 0) {
        (*(s32 *)&work->phase)++;
    } else {
        BR_CODEIN_ProfileApplyPendingStep(work);
        BUTTON_MAN_UpdateSlots(work->buttonMan);
    }
    return 0;
}

int BR_CODEIN_ProfileUpdateScrollAnim(struct CodeinProfileWork *work) {
    int i,factor,selected;
    struct CodeinProfileSlot *record;
    Point scale;
    Coords coords;
    switch(work->phase){
    case 0:
        BR_CODEIN_ProfileSetActorVisible(work,0,0);
        for(i=0;i<work->recordCount;i++){
            record=&work->slot[i];
            if(record->moveFrames!=0){
                CLACT_GetActorSurfacePos(record->actor,(struct ClactVec2 *)&coords.x,1);
                coords.x+=record->moveDx;
                coords.y+=record->moveDy;
                CLACT_AddActorSurfacePos(record->actor,(const struct ClactVec2 *)(&coords.x),1);
                --record->moveFrames;
                if(i>=work->rangeAFirst&&i<work->rangeAEnd){
                    factor=d_021E3998[record->scaleStep];
                    scale.x=factor;scale.y=factor;
                    CLACT_SetActorScale(record->actor,(struct Pair32 *)&scale);
                    ++record->scaleStep;
                }
                if(i>=work->rangeBFirst&&i<work->rangeBEnd){
                    factor=d_021E397C[record->scaleStep];
                    scale.x=factor;scale.y=factor;
                    CLACT_SetActorScale(record->actor,(struct Pair32 *)&scale);
                    ++record->scaleStep;
                }
            }
        }
        for(i=0;i<2;i++){
            record=&work->slot[i];
            if(record[CODEIN_PROFILE_SLOT_SLIDE].moveFrames!=0){
                CLACT_GetActorSurfacePos(record[CODEIN_PROFILE_SLOT_SLIDE].actor,(struct ClactVec2 *)&coords.a,1);
                coords.a+=record[CODEIN_PROFILE_SLOT_SLIDE].moveDx;
                coords.b+=record[CODEIN_PROFILE_SLOT_SLIDE].moveDy;
                CLACT_AddActorSurfacePos(record[CODEIN_PROFILE_SLOT_SLIDE].actor,(const struct ClactVec2 *)(&coords.a),1);
                --record[CODEIN_PROFILE_SLOT_SLIDE].moveFrames;
            }
        }
        if(work->slot[0].moveFrames==0){
            for(i=work->rangeAFirst;i<work->rangeAEnd;i++){
                record=&work->slot[i];
                CLACT_SetActorAnimSeq(record->actor,BR_CODEIN_ProfileGetActorIndex(record->tag,record->mode));
            }
            for(i=work->rangeBFirst;i<work->rangeBEnd;i++){
                record=&work->slot[i];
                CLACT_SetActorAnimSeq(record->actor,BR_CODEIN_ProfileGetActorIndex(record->tag,record->mode));
            }
            ++work->phase;
        }
        ++work->phaseTimer;
        break;
    case 1:
        for(i=work->rangeAFirst;i<work->rangeAEnd;i++){
            record=&work->slot[i];
            if(record->scaleStep!=6){
                factor=d_021E3998[record->scaleStep];
                scale.x=factor;scale.y=factor;
                CLACT_SetActorScale(record->actor,(struct Pair32 *)&scale);
                ++record->scaleStep;
            }
        }
        for(i=work->rangeBFirst;i<work->rangeBEnd;i++){
            record=&work->slot[i];
            if(record->scaleStep!=6){
                factor=d_021E397C[record->scaleStep];
                scale.x=factor;scale.y=factor;
                CLACT_SetActorScale(record->actor,(struct Pair32 *)&scale);
                ++record->scaleStep;
            }
        }
        if(++work->phaseTimer==6)++work->phase;
        break;
    default:
        BR_CODEIN_ProfileUpdateActorPos(work);
        if(work->pendingKeyIsRecord==0)selected=BR_CODEIN_ProfileFindActorIndex(work,work->pendingKey);
        else selected=BR_CODEIN_ProfileFindRecord(work,work->pendingKey);
        BR_CODEIN_ProfileSetActorPos(work,selected);
        if(work->animState!=0)BR_CODEIN_ProfileSetActorVisible(work,0,1);
        BR_CODEIN_ProfileClear(work);
        BR_CODEIN_ProfileSetAnimSeq(work,1);
        break;
    }
    return 0;
}

extern int (*const d_021E3858[])(char *);

int BR_CODEIN_ProfileUpdateActorAnim(struct CodeinProfileWork *work){ int r=d_021E3858[work->animSeq]((char *)work); BR_CODEIN_ProfileUpdateActorAnims(work); return r; }

/*
 * Matching: named digit load and byte-field address, with group before used in declaration order, preserve the original loop registers.
 */
void BR_CODEIN_ProfileBuildAnimName(struct CodeinProfileWork *work)
{
  u32 group = 0;
  u32 i;
  int used = 0;
  int digit;
  void *text;
  struct CodeinProfileSlot *record;
  u64 *acc;
  u64 product;
  u32 tag;
  unsigned char *statusByte;
  text = STRBUF_Create(100, work->profileHeapId);
  statusByte = &work->slot[CODEIN_PROFILE_SLOT_ARROW + 1].moveFrames;
  work->slot[CODEIN_PROFILE_SLOT_ARROW + 1].tag = 1;
  *statusByte = 0;
  work->digitValue[0] = 0;
  work->digitValue[1] = 0;
  work->digitValue[2] = 0;
  work->result = 0;
  i = 0;
  if (((int) i) < work->recordCount)
  {
    acc = &work->result;
    do
    {
      record = &work->slot[i];
      if (record->tag == 0)
      {
        record->tag = 1;
        CLACT_SetActorAnimSeq((struct ClactActor *)record->actor, BR_CODEIN_ProfileGetActorIndex(1, record->mode));
      }
      tag = record->tag;
      digit = tag - 1;
      WORDSET_FormatNumber(text, digit, 1, 1, PM_LANG_HALF_WIDTH_DIGITS);
      STRBUF_Append(work->object.vector, text);
      work->digitValue[group] *= 10;
      work->digitValue[group] += digit;
      used++;
      if (((int) used) >= work->object.entries[group])
      {
        group++;
        used = 0;
      }
      product = (*acc) * 10;
      *acc = product + ((u32) digit);
      i++;
    }
    while (((int) i) < work->recordCount);
  }
  STRBUF_Delete(text);
  BR_CODEIN_ProfileSetAnimSeq(work, 3);
  work->state = 2;
}

void BR_CODEIN_ProfileApplyRecords(struct CodeinProfileWork *p)
{
    struct CodeinProfileSlot *records=p->slot;
    int i,old,value,offset;
    p->slot[CODEIN_PROFILE_SLOT_ARROW].tag=1;
    p->slot[CODEIN_PROFILE_SLOT_ARROW].moveFrames=0;
    if (p->animState==0) {
        i=p->recordCount-1;
        p->slot[CODEIN_PROFILE_SLOT_MARKER].tag=i;
        value=records[i].group;
        p->pendingStep=1;
        p->pendingKey=value;
        p->pendingKeyIsRecord=1;
    } else {
        i=p->slot[CODEIN_PROFILE_SLOT_MARKER].tag;
        CLACT_SetActorAnimSeq((struct ClactActor *)records[i].actor,BR_CODEIN_ProfileGetActorIndex(records[i].tag=0,records[i].mode));
        old=records[i].group;
        if (i>0) {
            CLACT_SetActorAnimSeq((struct ClactActor *)records[i-1].actor,BR_CODEIN_ProfileGetActorIndex(records[i-1].tag,records[i-1].mode));
            value=records[i-1].group;
            if (old!=value) {
                p->pendingStep=1;
                p->pendingKey=value;
                p->pendingKeyIsRecord=1;
            } else {
                p->pendingStep=2;
                p->pendingKey=i-1;
            }
        } else p->state=1;
    }
}

void BR_CODEIN_ProfileCreateButtons(struct CodeinProfileWork *work) {
    int i;
    CodeinTable table;
    for(i=0;i<12;i++)work->slot[i].rect=work->rect[i];
    table=d_021E3880;
    for(;i<24;i++){
        work->rect[i][0]=table.row[i-12].b-table.row[i-12].d;
        work->rect[i][2]=table.row[i-12].a-table.row[i-12].c;
        work->rect[i][1]=table.row[i-12].b+table.row[i-12].d;
        work->rect[i][3]=table.row[i-12].a+table.row[i-12].c;
    }
    work->pressedButton=255;
    work->buttonMan=BUTTON_MAN_Create((u8 *)work->rect,BR_CODEIN_ProfileHandleInput,work,work->profileHeapId);
}

/*
 * 2026-10-05 wave P5 lane T5 (pengy share): earlier DIFF, two residues (merged far-branch stubs, idx-12 CSE).
 * 2026-10-05 wave P5 lane T5b: EXACT with the ov129 021D958C forms: idx is u32 (unsigned % and / by plain 5),
 *   `if (*(int *)(p + 0x22C) != 1) return;` then `if (arg == 0) {`, non-const CodeinProfileRecord pointer. One compile.
 *   Callbacks: BR_CODEIN_ProfileCreateButtons passes this as BUTTON_MAN_Create's callback (idx, arg, obj).
 */
void BR_CODEIN_ProfileHandleInput(u32 idx, s32 arg, void *workArg)
{
    struct CodeinProfileWork *work = workArg;
    struct CodeinProfileSlot *rec = work->slot;
    u32 i, j, v;
    int old, val;
    if (work->animSeq != 1) return;
    if (arg == 0) {
    if (idx <= 11) {
        if (rec[idx].mode == 1) {
            work->pendingStep = 2;
            work->pendingKey = idx;
        } else {
            work->pendingStep = 1;
            work->pendingKey = rec[idx].group;
        }
        GFL_USE_PlaySeDefaultVolume(0x703);
        return;
    }
    if (idx == 0x16) {
        u32 x, y;
        Point args;
        work->slot[CODEIN_PROFILE_SLOT_MARKER + 1].moveDx = 0;
        work->slot[CODEIN_PROFILE_SLOT_MARKER + 1].moveDy = 2;
        GFL_USE_PlaySeDefaultVolume(0x703);
        TOUCHPANEL_GetPointTrg((u32 *)&x, (u32 *)&y);
        args.x = x;
        args.y = y;
        BR_UTIL_StartEffect((char *)work->object.handles, 1, (const BrPair *)&args);
    } else if (idx == 0x17) {
        u32 x, y;
        Point args;
        work->slot[CODEIN_PROFILE_SLOT_MARKER + 1].moveDx = 3;
        work->slot[CODEIN_PROFILE_SLOT_MARKER + 1].moveDy = 2;
        GFL_USE_PlaySeDefaultVolume(0x703);
        TOUCHPANEL_GetPointTrg((u32 *)&x, (u32 *)&y);
        args.x = x;
        args.y = y;
        BR_UTIL_StartEffect((char *)work->object.handles, 1, (const BrPair *)&args);
    } else {
        work->slot[CODEIN_PROFILE_SLOT_MARKER + 1].moveDx = (idx - 12) % 5;
        work->slot[CODEIN_PROFILE_SLOT_MARKER + 1].moveDy = (idx - 12) / 5;
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    if (idx >= 12 && idx <= 21) {
        u32 x, y;
        Point args;
        if (work->animState != 0) {
        TOUCHPANEL_GetPointTrg((u32 *)&x, (u32 *)&y);
        args.x = x;
        args.y = y;
        BR_UTIL_StartEffect((char *)work->object.handles, 1, (const BrPair *)&args);
        i = work->slot[CODEIN_PROFILE_SLOT_MARKER].tag;
        v = idx - 11;
        CLACT_SetActorAnimSeq((struct ClactActor *)(struct Obj *)rec[i].actor, (u16)BR_CODEIN_ProfileGetActorIndex(rec[i].tag = v, rec[i].mode));
        old = rec[i].group;
        j = i + 1;
        if (j == *(u32 *)&work->recordCount) {
            work->pendingStep = 1;
            work->pendingKey = 0;
            work->pendingKeyIsRecord = 0;
        } else {
            val = rec[j].group;
            if (old != val) {
                work->pendingStep = 1;
                work->pendingKey = val;
                work->pendingKeyIsRecord = 0;
            } else {
                work->pendingStep = 2;
                work->pendingKey = j;
            }
        }
        }
    } else if (idx == 0x16) {
        BR_CODEIN_ProfileApplyRecords(work);
    } else {
        BR_CODEIN_ProfileBuildAnimName(work);
    }
    }
}

/*
 * Extent remainder: zero alignment halfword at 021E1BFE.
 */
void BR_CODEIN_ProfileApplyPendingStep(struct CodeinProfileWork *work)
{
    switch (work->pendingStep) {
    case 0: break;
    case 1:
        BR_CODEIN_ProfileSetActorAnim(work,work->pendingKey);
        BR_CODEIN_ProfileUpdateActorVisible(work);
        BR_CODEIN_ProfileSetActorAnimFrame(work,1);
        BR_CODEIN_ProfileSetAnimSeq(work,2);
        work->pendingStep=255;
        break;
    case 2:
        BR_CODEIN_ProfileSetActorPos(work,work->pendingKey);
        BR_CODEIN_ProfileClear(work);
        break;
    case 255: break;
    }
}

void BR_CODEIN_ProfileClear(struct CodeinProfileWork *work)
{
    work->pendingStep = 0;
    work->pendingKey = 0;
    work->pendingKeyIsRecord = 0;
}

/*
 * extent: final two bytes are alignment padding.
 */
int BR_CODEIN_ProfileFindActorIndex(struct CodeinProfileWork *work,int value){int i,n; n=work->recordCount;for(i=0;i<n;i++){if(value==work->slot[i].group)return i;}return 0;}

/*
 * checks: 1 n/a no calls; 2 matched 1C14 confirms signed index/raw28 stride; 3 enum index DIFF7, unsigned-long count and long index each DIFF4; 4 count/address reuse DIFF4, permuter expands the read-only count field at guard and return; 5 refreshed directory and neighbours; no stack object.
 * matching: re-reading count at guard and return instead of a cached scalar lets the dying offset use r4. No stores or calls can change count during this function.
 * extent: 58 code bytes, alignment padding at021E1C7E..021E1C80; next function starts1C80.
 * retry: 5 one runs, once-only permuter budget300 found expand(n x2) after9 candidates; emitted DIFF4 baseline agrees; winner validated by run6.
 */
int BR_CODEIN_ProfileFindRecord(const struct CodeinProfileWork *work, int value)
{
  int i;
  int found;
  unsigned n;
  n = *((const unsigned *) &work->recordCount);
  found = 0;
  for (i = 0; i < ((int) (*((const unsigned *) &work->recordCount))); i++)
  {
    if (value == work->slot[i].group)
      found = 1;
    else
      if (found == 1)
      return i - 1;
  }

  return (*((const unsigned *) &work->recordCount)) - 1;
}


