/*
 * file:     br_record_proc.c
 * unit:     yes
 * function: BR_CODEIN_SidebarCreate, BR_CODEIN_SidebarDestroy, BR_CODEIN_SidebarMain, BR_CODEIN_SidebarStepIntro, BR_CODEIN_SidebarStepSlideIn, BR_CODEIN_SidebarStepSlideOut, BR_CODEIN_SidebarClearStep, BR_CODEIN_ButtonCreate, BR_CODEIN_ButtonDestroy, BR_CODEIN_ButtonMain, BR_CODEIN_ButtonLoadFadePalettes, BR_CODEIN_RecordCreate, BR_CODEIN_RecordDestroy, BR_CODEIN_RecordMain, BR_CODEIN_RecordStepCreateProfile, BR_CODEIN_RecordStepFadeIn, BR_CODEIN_RecordStepFadeOut, BR_CODEIN_RecordStepDeleteProfile, BR_CODEIN_RecordStepMenu, BR_CODEIN_RecordStepProfileText, BR_CODEIN_RecordStepRequest, BR_CODEIN_RecordStepReceive, BR_CODEIN_RecordStepSave, BR_CODEIN_RecordStepConfirm, BR_CODEIN_RecordSetupProfile, BR_CODEIN_RecordSetupActors, BR_CODEIN_RecordCreateProfileScreen, BR_CODEIN_RecordDeleteProfileScreen, BR_CODEIN_RecordDeleteActors, BR_CODEIN_RecordSetupButtons, BR_CODEIN_RecordDeleteButtons, BR_CODEIN_RecordCreateTextWin, BR_CODEIN_RecordDeleteTextWin, BR_CODEIN_RecordSetupTextWin, BR_CODEIN_RecordTeardownTextWin, BR_CODEIN_RecordIsMultiBattle, BR_CODEIN_RecordIsType2, BR_CODEIN_RecordHitProfileToggle, BR_CODEIN_RecordHitRecordPanel, BR_CODEIN_RecordHitOptionLeft, BR_CODEIN_RecordHitOptionRight
 * address:  0x021DB2E0
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
#include "br_record_proc.h"
#include "../ov183/br_bvrank_proc.h"
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

int BR_CODEIN_SidebarCreate(int *task, int unused, struct BrProcArgBasic *work)
{
    struct CodeinSidebarWork *s;
    BrUtilTaskStep callback;
    s=PROCSYS_AllocProcWork((struct Proc *)task,sizeof(*s),BR_PROC_SYS_GetSlotId(work->proc));
    MI_CpuFill8(s,0,sizeof(*s));
    s->work=work;
    s->heapId=BR_PROC_SYS_GetSlotId(work->proc);
    s->printQue=(void *)PRINTSYS_QUE_Create(s->heapId);
    s->handlesMain=BR_UTIL_CreateHandles(work->unit,work->res,0,s->heapId);
    s->handlesSub=BR_UTIL_CreateHandles(work->unit,work->res,1,s->heapId);
    BR_UTIL_SetHandlesAnimSeq(s->handlesMain,1);
    BR_UTIL_SetHandlesAnimSeq(s->handlesSub,1);
    if(work->mode==0) callback=BR_CODEIN_SidebarStepIntro;
    else if(work->mode==1) callback=BR_CODEIN_SidebarStepSlideIn;
    else callback=BR_CODEIN_SidebarStepSlideOut;
    s->task=BR_UTIL_CreateTask(s,callback,s->heapId);
    return 1;
}

int BR_CODEIN_SidebarDestroy(struct Proc *task,int seq,int arg,struct CodeinSidebarWork *work) { BR_UTIL_DeleteHandles(*(char * *)&work->handlesMain); BR_UTIL_DeleteHandles(*(char * *)&work->handlesSub); PRINTSYS_QUE_Delete((work->printQue)); BR_UTIL_DeleteTask((void *)(work->task)); PROCSYS_FreeProcWork(task); return 1; }

int BR_CODEIN_SidebarMain(int proc,int seq,int arg,struct CodeinSidebarWork *work) { BR_UTIL_RunTask(work->task); PRINTSYS_QUE_Main(work->printQue); BR_UTIL_RunHandles(*(char * *)&work->handlesMain); BR_UTIL_RunHandles(*(char * *)&work->handlesSub); if(BR_UTIL_IsTaskIdle(work->task)) return 1; return 0; }

/*
 * lever: enum-valued one-bit mask preserves the original call/mask scheduling, as in sibling 021DB594.
 * abi: 02035C60 returns a full word consumed by the original caller's comparison.
 */
void BR_CODEIN_SidebarStepIntro(struct BrUtilTask *task,int *state,struct CodeinSidebarWork *work)
{
    void *a; void *b;
    switch(*state) {
    case 0: {Point args;args.x=128;args.y=96;BR_UTIL_StartEffect((char *)((void *)(work->handlesMain)), 2, (const BrPair *)&args);GFL_USE_PlaySeDefaultVolume(0x700);*state=1;break;}
    case 1: if(BR_UTIL_IsEffectDone((char *)(*(char * *)&work->handlesMain)))*state=2;break;
    case 2: {Point args;args.x=128;args.y=-8;BR_UTIL_StartEffect((char *)((void *)(work->handlesSub)), 3, (const BrPair *)&args);*state=3;break;}
    case 3: if(BR_UTIL_IsEffectDone((char *)(*(char * *)&work->handlesSub)))*state=4;break;
    case 4:
        work->noticeText=BR_UTIL_Create(4,8,16,16,2,14,(void *)work->printQue,work->heapId);
        a=BR_RES_GetFont((struct BrRes *)(((struct BrProcArgBasic *)(work->work))->res));
        b=BR_RES_GetMsgData((struct BrRes *)(((struct BrProcArgBasic *)(work->work))->res));
        BR_UTIL_SetTextFromMessage((char *)(*(char * *)&work->noticeText),(void *)b,228,(void *)a,0x440);
        BR_FADE_StartTimed((struct BrFade *)((char *)((((struct BrProcArgBasic *)(work->work))->fade))),3,15,1,4);*state=5;break;
    case 5: if(BR_FADE_GetResult((struct BrFade *)(((struct BrProcArgBasic *)(work->work))->fade)))*state=6;break;
    case 6: BR_FADE_StartTimed((struct BrFade *)((char *)((((struct BrProcArgBasic *)(work->work))->fade))),3,15,0,4);*state=7;break;
    case 7: if(BR_FADE_GetResult((struct BrFade *)(((struct BrProcArgBasic *)(work->work))->fade)))*state=8;break;
    case 8: if(TOUCHPANEL_GetTrg()) {GFL_USE_PlaySeDefaultVolume(0x6ff);BR_UTIL_Delete((u8 *)work->noticeText);*(int *)&work->noticeText=0;BG_SYS_PushTile(4);*state=9;}break;
    case 9: BR_FADE_StartTimed((struct BrFade *)((char *)((((struct BrProcArgBasic *)(work->work))->fade))),3,3,0,48);BR_SIDEBAR_StartBounce((struct BrSidebar *)(char *)(((struct BrProcArgBasic *)(work->work))->sidebar));*state=10;break;
    case 10: {enum {ONE=1} mask=ONE;if(BR_FADE_GetResult((struct BrFade *)((int *)(((struct BrProcArgBasic *)(work->work))->fade)))&mask) {BR_UTIL_StartEffect((char *)((void *)(work->handlesSub)), 8, 0);*state=11;}break;}
    case 11: BR_FADE_StartTimed((struct BrFade *)((char *)((((struct BrProcArgBasic *)(work->work))->fade))),2,3,1,1);*state=12;break;
    case 12: if(BR_FADE_GetResult((struct BrFade *)(((struct BrProcArgBasic *)(work->work))->fade)))*state=13;break;
    case 13: if(BR_UTIL_IsEffectDone(*(char * *)&work->handlesSub)) {BR_PROC_SYS_PushEntry(((struct BrProcArgBasic *)(work->work))->proc,1);BR_UTIL_SetTaskStep(task,BR_CODEIN_SidebarClearStep);}break;
    }
    if(work->noticeText)BR_UTIL_FlushText(work->noticeText);
}

/*
 * lever: enum mask local materializes one before the call; int mask left nine bytes different
 */
void BR_CODEIN_SidebarStepSlideIn(struct BrUtilTask *task, int *state, struct CodeinSidebarWork *work)
{
    switch(*state) {
    case 0: *state=1; break;
    case 1:
        BR_SIDEBAR_StartSlide((struct BrSidebar *)(char *)(((struct BrProcArgBasic *)(work->work))->sidebar));
        *state=2;
        break;
    case 2:
        if(((*(int *)&work->slideTimer))++ !=0) {
            (*(int *)&work->slideTimer)=0;
            BR_FADE_StartTimed((struct BrFade *)((char *)((((struct BrProcArgBasic *)(work->work))->fade))),3,3,1,26);
            *state=3;
        }
        break;
    case 3:
    {
        enum { MASK=1 } mask=MASK;
        if(BR_FADE_GetResult((struct BrFade *)(((struct BrProcArgBasic *)(work->work))->fade))&mask) *state=4;
        break;
    }
    case 4:
        BR_PROC_SYS_PopEntry((((struct BrProcArgBasic *)(work->work))->proc));
        BR_UTIL_SetTaskStep(task,BR_CODEIN_SidebarClearStep);
        break;
    }
}

void BR_CODEIN_SidebarStepSlideOut(struct BrUtilTask *task, int *state, struct CodeinSidebarWork *work)
{
    switch(*state) {
    case 0:
        BR_FADE_StartTimed((struct BrFade *)((char *)((((struct BrProcArgBasic *)(work->work))->fade))),2,3,1,1);
        *state=1;
        break;
    case 1:
        if(BR_FADE_GetResult((struct BrFade *)(((struct BrProcArgBasic *)(work->work))->fade))) *state=2;
        break;
    case 2:
        BR_SIDEBAR_ResetPositions((struct BrSidebar *)(char *)(((struct BrProcArgBasic *)(work->work))->sidebar));
        BR_SIDEBAR_StartWobble((struct BrSidebar *)(char *)(((struct BrProcArgBasic *)(work->work))->sidebar));
        BR_PROC_SYS_PushEntry((struct BrProcSysContext *)(((struct BrProcArgBasic *)(work->work))->proc),1);
        BR_UTIL_SetTaskStep(task,BR_CODEIN_SidebarClearStep);
        break;
    }
}

void BR_CODEIN_SidebarClearStep(struct BrUtilTask *task)
{
    BR_UTIL_ClearTaskStep(task);
}

/*
 * extent: two bytes of zero alignment padding at 0x021DB73E
 */
int BR_CODEIN_ButtonCreate(int *task,int seq,struct CodeinButtonArg *work)
{
    struct CodeinButtonWork *s;
    s=PROCSYS_AllocProcWork((struct Proc *)task,sizeof(*s),BR_PROC_SYS_GetSlotId(work->procQuery));
    MI_CpuFill8(s,0,sizeof(*s));
    s->work=work;
    s->heapId=BR_PROC_SYS_GetSlotId(work->procQuery);
    BR_RES_ReleaseUiPalette((struct BrRes *)(work->res),0);
    BR_RES_ReleaseUiPalette((struct BrRes *)(work->res),1);
    BR_RES_LoadUiPalette((struct BrRes *)((char *)(work->res)),0,s->heapId);
    BR_RES_LoadUiPalette((struct BrRes *)((char *)(work->res)),1,s->heapId);
    if(work->kind<5) BR_RES_LoadBgGraphics((void *)(work->res),3,s->heapId);
    else BR_RES_LoadBgGraphics((void *)(work->res),4,s->heapId);
    s->handles=BR_UTIL_CreateHandles((void *)((work->actorSys)),work->res,1,s->heapId);
    s->button=BR_BTN_Create(work->kind,(work->actorSys),work->res,work->dataId,(work->uiRes),s->handles,s->heapId);
    if(work->fadeMode==4) BR_FADE_SetBlendLevel(work->screenFade,2,0);
    else BR_FADE_SetBlendLevel(work->screenFade,3,0);
    return 1;
}

/*
 * lever: Explicit call arms preserve the original conditional argument branch.
 */
int BR_CODEIN_ButtonDestroy(struct Proc *task,int seq,struct CodeinButtonArg *arg,struct CodeinButtonWork *work) { if(arg->kind<5) BR_RES_ApplyBgSet(arg->res,3); else BR_RES_ApplyBgSet(arg->res,4); BR_BTN_Delete(work->button); BR_UTIL_DeleteHandles((char *)(work->handles)); PROCSYS_FreeProcWork(task); return 1; }

/*
 * lever: explicit case-3 call arms preserve the original block shape; ARM9 division helper uses the proven _u32_div_f ABI.
 */
int BR_CODEIN_ButtonMain(int *task,int *state,struct CodeinButtonArg *work,struct CodeinButtonWork *arg)
{
    u32 x,y;
    switch(*state) {
    case 0: BR_FADE_Start((void *)work->screenFade,work->fadeMode,3,0);*state=1;break;
    case 1: if(BR_FADE_GetResult((struct BrFade *)(work->screenFade)))*state=2;break;
    case 2:
        if(work->kind<=4 && !BR_BTN_GetPressed(arg->button) && TOUCHPANEL_GetPointTrg(&x,&y)) {
            if(x<8 || x>248) {GFL_USE_PlaySeDefaultVolume(0x703);*state=6;break;}
        }
        BR_BTN_UpdatePrint(arg->button);
        if(BR_BTN_GetPlacement(arg->button,&work->placement,&work->placementArg)) *state=3;
        break;
    case 3:
        if(work->placement==12)BR_FADE_Start((void *)work->screenFade,4,3,1);
        else BR_FADE_Start((void *)work->screenFade,2,3,1);
        *state=4;break;
    case 4: if(BR_FADE_GetResult((struct BrFade *)(work->screenFade)))*state=5;break;
    case 5:
        switch(BR_BTN_GetPlacement(arg->button,&work->placement,&work->placementArg)) {
        case 1: BR_PROC_SYS_PushEntry(work->procQuery,(unsigned short)work->placement);return 1;
        case 2: BR_PROC_SYS_PopEntry((work->procQuery));**(int * *)&work->resultOut=BR_BTN_GetResultValue(arg->button);return 1;
        }
        break;
    case 6: {
        int v=BR_RES_GetPalSet((struct BrRes *)work->res);u32 i;
        for(i=0;i<7;i++) {if(v==d_021E3280[i]) {v=d_021E3280[(i+1)%7];break;}}
        BR_RES_SetPalSet((struct BrRes *)work->res,v);
        BR_FADE_SetBlendColor((struct BrFade *)work->screenFade,BR_RES_GetCurrentSetParam((struct BrRes *)work->res));
        BR_FADE_Start((void *)work->screenFade,3,3,1);*state=7;break;
    }
    case 7: if(BR_FADE_GetResult((struct BrFade *)(work->screenFade)))*state=8;break;
    case 8: arg->fadeTask=GFL_USE_AddMainTask(BR_CODEIN_ButtonLoadFadePalettes, arg,0);arg->fadeDone=0;*state=9;break;
    case 9: if(arg->fadeDone) {TCB_DeleteTask(arg->fadeTask);*state=10;}break;
    case 10: BR_FADE_Start((void *)work->screenFade,3,3,0);*state=11;break;
    case 11: if(BR_FADE_GetResult((struct BrFade *)(work->screenFade)))*state=2;break;
    }
    BR_UTIL_RunHandles(arg->handles);return 0;
}

void BR_CODEIN_ButtonLoadFadePalettes(struct TcbTask *unused, void *workArg)
{
    struct CodeinButtonWork * work = workArg;
    int v = work->fadeDone;
    struct CodeinButtonArg *q = work->work;

    if (v == 0) {
        BR_RES_LoadFadePalettes((struct BrRes *)q->res, (void *)q->screenFade,
                      work->heapId);
    }
    work->fadeDone = 1;
}

/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * lever: shared state-flag store and distinct case-5 null path preserve the original switch layout.
 * blocker-C: copied prior verified Thumb EXACT from BR_CODEIN_SearchBuildHeader.c header, blocker-r2.log; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 */
int BR_CODEIN_RecordCreate(int *task,int *state,struct BrProcArgBattle *arg)
{
    struct CodeinRecordWork *p;
    struct BrRecCache *s;
    int i;
    p=PROCSYS_AllocProcWork((struct Proc *)task,sizeof(struct CodeinRecordWork),BR_PROC_SYS_GetSlotId(arg->proc));
    MI_CpuFill8(p,0,sizeof(struct CodeinRecordWork));
    p->heapId=BR_PROC_SYS_GetSlotId(arg->proc);
    p->profileScreenShown=0;
    p->ctx=arg;
    *(void **)p=BMP_OAM_CreateSys(p->heapId,arg->unit);
    p->printQue=(void *)PRINTSYS_QUE_Create(p->heapId);
    p->task=BR_UTIL_CreateTask(p,0,p->heapId);
    for(i=0;i<2;i++) (&p->introFx)[i]=BR_UTIL_CreateHandles((void *)(arg->unit),arg->res,i,p->heapId);
    switch(p->ctx->mode) {
    case 4:
        s=p->ctx->recB;
        p->header=s->entry[s->selection].header;
        s=p->ctx->recB;
        p->recData=&s->entry[s->selection];
        p->hasSecondButton=1;
        if(*p->ctx->recC && p->ctx->flag) {
            s=p->ctx->recB;
            s->saved[s->selection]=1;
        }
        s=p->ctx->recB;
        p->savedActorSys=s->saved[s->selection];
        break;
    case 0:
        p->header=BATTLE_REC_GetHeader();p->recData=BATTLE_REC_GetWork();
        p->savedActorSys=1;i=0;goto set_cc;
    case 1: case 2: case 3:
        p->header=BATTLE_REC_GetHeader();p->recData=BATTLE_REC_GetWork();
        p->savedActorSys=BATTLE_REC_GetHeaderParam(p->header,5,0);p->hasSecondButton=0;break;
    case 5:
        if(p->ctx->flag==0) {
            p->header=0;p->recData=0;
        }else {
            p->header=BATTLE_REC_GetHeader();p->recData=BATTLE_REC_GetWork();
            p->savedActorSys=*p->ctx->recC;
        }
        i=1;
    set_cc:
        p->hasSecondButton=i;
        break;
    }
    if(p->ctx->mode==5) {
        if(p->ctx->flag==0)BR_UTIL_SetTaskStep(p->task,BR_CODEIN_RecordStepRequest);
        else BR_UTIL_SetTaskStep(p->task,BR_CODEIN_RecordStepCreateProfile);
    }else if((u32)(p->ctx->mode-1)<=2 && p->ctx->flag && *p->ctx->recC && p->savedActorSys==0) {
        BR_UTIL_SetTaskStep(p->task,BR_CODEIN_RecordStepSave);
    }else BR_UTIL_SetTaskStep(p->task,BR_CODEIN_RecordStepCreateProfile);
    return 1;
}

int BR_CODEIN_RecordDestroy(struct Proc *task,int seq,struct BrProcArgBattle *arg,struct CodeinRecordWork *work)
{
    int i;
    BR_CODEIN_RecordDeleteProfileScreen(work,arg);
    BR_CODEIN_RecordDeleteActors(work,arg);
    BR_CODEIN_RecordDeleteButtons(work,arg);
    BR_CODEIN_RecordDeleteTextWin(work,arg);
    BR_CODEIN_RecordTeardownTextWin(work,arg);
    arg->kind=work->savedActorSys;
    BG_SYS_PushTile(4);
    BG_SYS_PushTile(1);
    if(work->textWin) {
        BR_UTIL_DeleteTextWin(work->textWin,(work->ctx)->res);
        work->textWin=0;
    }
    for(i=0;i<2;i++) BR_UTIL_DeleteHandles((&work->introFx)[i]);
    BR_UTIL_DeleteTask((void *)((work->task)));
    PRINTSYS_QUE_Delete((work->printQue));
    BMP_OAM_DeleteSys((void *)(work->oamSys));
    PROCSYS_FreeProcWork(task);
    return 1;
}

/*
 * extent: two bytes of zero alignment padding at 0x021DBC66
 */
int BR_CODEIN_RecordMain(int proc,int seq,int arg,struct CodeinRecordWork *work)
{
    int i;
    if(GAME_DATA_IsSaving((work->ctx)->gameData)==0 && BR_NET_HandleNetError((work->ctx)->net)==2) {
        BR_PROC_SYS_FlushWindows(((work->ctx)->proc));
        return 1;
    }
    BR_UTIL_RunTask(work->task);
    if(BR_UTIL_IsTaskIdle(work->task)) return 1;
    for(i=0;i<2;i++) BR_UTIL_RunHandles((&work->introFx)[i]);
    PRINTSYS_QUE_Main((work->printQue));
    for(i=0;i<2;i++) if(work->captionText[i]) BR_UTIL_FlushText(work->captionText[i]);
    for(i=0;i<5;i++) if(work->profileText[i]) BR_UTIL_FlushText(work->profileText[i]);
    if((*(void * *)&work->profileScreen)) BR_UTIL_MainProfileScreen((*(void * *)&work->profileScreen));
    if(work->textWin) BR_UTIL_FlushWindow(work->textWin);
    return 0;
}

/*
 * Flush the object, dispatch on the p+0xB0 flag, then chain to 0x21FD73C.
 */
void BR_CODEIN_RecordStepCreateProfile(struct BrUtilTask *task, int b, struct CodeinRecordWork *work)
{
    BR_CODEIN_RecordSetupButtons(work, work->ctx);
    if (work->profileScreenShown != 0)
        BR_CODEIN_RecordCreateProfileScreen(work, work->ctx);
    else
        BR_CODEIN_RecordSetupProfile(work, work->ctx);
    BR_UTIL_SetTaskStep(task, BR_CODEIN_RecordStepFadeIn);
}

void BR_CODEIN_RecordStepFadeIn(struct BrUtilTask *task, int *state, struct CodeinRecordWork *work)
{
    switch(*state) {
    case 0:
        BR_FADE_Start((void *)(((work->ctx)->fade)),2,3,0);
        *state=1;
        break;
    case 1:
        if(BR_FADE_GetResult((struct BrFade *)((work->ctx)->fade))) *state=2;
        break;
    case 2:
        BR_UTIL_SetTaskStep(task,BR_CODEIN_RecordStepMenu);
        break;
    }
}

void BR_CODEIN_RecordStepFadeOut(struct BrUtilTask *task, int *state, struct CodeinRecordWork *work)
{
    switch(*state) {
    case 0:
        BR_FADE_Start((void *)(((work->ctx)->fade)),2,3,1);
        *state=1;
        break;
    case 1:
        if(BR_FADE_GetResult((struct BrFade *)((work->ctx)->fade))) *state=2;
        break;
    case 2:
        BR_UTIL_SetTaskStep(task,BR_CODEIN_RecordStepDeleteProfile);
        break;
    }
}

void BR_CODEIN_RecordStepDeleteProfile(struct BrUtilTask *task,int b,struct CodeinRecordWork *work) { if(work->profileScreenShown) BR_CODEIN_RecordDeleteProfileScreen(work,work->ctx); else BR_CODEIN_RecordDeleteActors(work,work->ctx); BR_CODEIN_RecordDeleteButtons(work,work->ctx); BR_UTIL_ClearTaskStep(task); }

/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * lever: decode each callback literal from its actual PC-relative pool slot; repeated shared loads obscure distinct callback targets.
 * blocker-C: copied prior verified Thumb EXACT from BR_CODEIN_SearchBuildHeader.c header, blocker-r2.log; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 */
void BR_CODEIN_RecordStepMenu(struct BrUtilTask *task,int *state,struct CodeinRecordWork *work)
{
    u32 x,y;
    if(TOUCHPANEL_GetPointTrg(&x,&y)) {
        if(BR_CODEIN_RecordHitProfileToggle(work,x,y)) {
            work->profileScreenShown^=1;
            BR_UTIL_SetTaskStep(task,BR_CODEIN_RecordStepProfileText);
        }
        if(BR_BTN_HitTestWithSound(work->button[0],x,y)) {
            Point args;
            args.x=x;args.y=y;
            BR_UTIL_StartEffect((char *)((void *)(work->tapFx)), 1, (const BrPair *)&args);
            work->ctx->result=0;
            BR_PROC_SYS_PopEntry(work->ctx->proc);
            BR_UTIL_SetTaskStep(task,BR_CODEIN_RecordStepFadeOut);
        }
        if(work->button[1] && BR_BTN_HitTestWithSound(work->button[1],x,y)) {
            Point args;
            args.x=x;args.y=y;
            BR_UTIL_StartEffect((char *)((void *)(work->tapFx)), 1, (const BrPair *)&args);
            BR_PROC_SYS_PushEntry(work->ctx->proc,10);
            *(u64 *)work->ctx->value=BATTLE_REC_GetHeaderParam(work->header,4,0);
            BR_UTIL_SetTaskStep(task,BR_CODEIN_RecordStepFadeOut);
        }
        if(BR_CODEIN_RecordHitRecordPanel(work,x,y)) {
            if((u32)(work->ctx->mode-4)<=1)BR_UTIL_SetTaskStep(task,BR_CODEIN_RecordStepReceive);
            else if(work->savedActorSys==0)BR_UTIL_SetTaskStep(task,BR_CODEIN_RecordStepConfirm);
            else {
                work->ctx->result=1;
                BR_PROC_SYS_SetupWindow(work->ctx->proc);
                BR_UTIL_SetTaskStep(task,BR_CODEIN_RecordStepFadeOut);
            }
        }
    }
}

void BR_CODEIN_RecordStepProfileText(struct BrUtilTask *task,int *state,struct CodeinRecordWork *work)
{
    void *a; void *b;
    switch(*state) {
    case 0:
        BR_FADE_Start((void *)(((work->ctx)->fade)),2,1,1);
        (*state)++;break;
    case 1:
        if(BR_FADE_GetResult((struct BrFade *)((work->ctx)->fade)))(*state)++;
        break;
    case 2:
        a=BR_RES_GetFont((struct BrRes *)((work->ctx)->res));
        b=BR_RES_GetMsgData((struct BrRes *)((work->ctx)->res));
        if(work->profileScreenShown) {
            BR_CODEIN_RecordDeleteActors(work,work->ctx);
            BR_UTIL_SetTextFromMessage(*(char * *)&work->captionText[0],(void *)b,0x72,(void *)a,0x3da0);
            BR_CODEIN_RecordCreateProfileScreen(work,work->ctx);
        }else{
            BR_CODEIN_RecordDeleteProfileScreen(work,work->ctx);
            BR_UTIL_SetTextFromMessage((char *)(*(char * *)&work->captionText[0]),(void *)b,0x71,(void *)a,0x3da0);
            BR_CODEIN_RecordSetupProfile(work,work->ctx);
        }
        BR_FADE_Start((void *)(((work->ctx)->fade)),2,1,0);
        (*state)++;break;
    case 3:
        if(BR_FADE_GetResult((struct BrFade *)((work->ctx)->fade)))BR_UTIL_SetTaskStep(task,BR_CODEIN_RecordStepMenu);
        break;
    }
}

/*
 * note 2026-10-05: shape copied from matched twin BR_CODEIN_RecordStepReceive.c (same state machine, same callees). v1 was 4 bytes off (stack slots of source and index swapped); declaring source before index fixed it. Older draft docs/notes/pkt_ov183_021DBFB0.c.txt (167 B off) superseded.
 */
void BR_CODEIN_RecordStepRequest(struct BrUtilTask *task,int *state,struct CodeinRecordWork *work)
{
    u64 t;
    sptr message;
    struct BattleRecSave *source;
    int index;
    u32 x,y;
    Point args;
    switch(*state) {
    case 0:
        BR_CODEIN_RecordCreateTextWin(work,work->ctx);
        BR_UTIL_SetWindowText((char *)work->textWin,work->ctx->res,0x14b);*state=1;break;
    case 1: BR_FADE_Start((void *)((work->ctx->fade)),2,3,0);*state=2;break;
    case 2: if(BR_FADE_GetResult((struct BrFade *)(work->ctx->fade))) *state=3;break;
    case 3:
        MI_CpuFill8(&t,0,8);
        t=*(u64 *)work->ctx->value;
        BR_NET_StartRequest(work->ctx->net,3,(const union BrNetRequest *)(const int *)(&t));
        work->waitFrames=0;*state=4;break;
    case 4:
        ++work->waitFrames;
        if(BR_NET_IsIdle(work->ctx->net) && work->waitFrames>96) {
            BR_UTIL_StartEffect((void *)(work->introFx), 0, 0);*state=5;
        }
        break;
    case 5:
        if(!BR_NET_PollErrorMessage(work->ctx->net,&message)) {
            if(BR_NET_GetVideoReply((struct BrNet *)work->ctx->net,&source,&index)) {
                work->recData=source;
                work->header=&source->head;*state=6;
            } else {
                BR_UTIL_SetWindowText(work->textWin,work->ctx->res,0x114);*state=11;
            }
        } else {
            BR_UTIL_SetWindowText(work->textWin,work->ctx->res,message);*state=11;
        }
        break;
    case 11:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg((u32 *)&x,(u32 *)&y);args.x=x;args.y=y;
            BR_UTIL_StartEffect((char *)((void *)(work->tapFx)), 1, (const BrPair *)&args);GFL_USE_PlaySeDefaultVolume(0x703);
            BR_PROC_SYS_PopEntry(work->ctx->proc);*state=12;
        }
        break;
    case 6: BR_FADE_Start((void *)((work->ctx->fade)),2,3,1);*state=7;break;
    case 7:
        if(BR_FADE_GetResult((struct BrFade *)(work->ctx->fade))) {
            BR_CODEIN_RecordDeleteTextWin(work,work->ctx);
            BR_CODEIN_RecordSetupButtons(work,work->ctx);
            BR_CODEIN_RecordSetupProfile(work,work->ctx);*state=8;
        }
        break;
    case 8: BR_FADE_Start((void *)((work->ctx->fade)),2,3,0);*state=9;break;
    case 9: if(BR_FADE_GetResult((struct BrFade *)(work->ctx->fade))) *state=10;break;
    case 10: BR_UTIL_SetTaskStep(task,BR_CODEIN_RecordStepMenu);break;
    case 12: BR_FADE_Start((void *)((work->ctx->fade)),2,3,1);*state=13;break;
    case 13: if(BR_FADE_GetResult((struct BrFade *)(work->ctx->fade))) *state=14;break;
    case 14: BR_CODEIN_RecordDeleteTextWin(work,work->ctx);BR_UTIL_ClearTaskStep(task);break;
    }
}

/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * diagnostic: ov186 0x021FF648 +013C resolved through a sibling's new shard in the TU; only ARM9 remains. TU --suggest-split leaves caller out.
 * blocker-C: prior verified Thumb EXACT from BR_CODEIN_SearchBuildHeader.c header, blocker-r2.log, dsi/1.1p1 -O4,p; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 * abi: B938 retains caller-loaded r3; DD0AC/DD0F4 retain caller-loaded r1; 35C60 return is consumed.
 */
void BR_CODEIN_RecordStepReceive(struct BrUtilTask *task,int *state,struct CodeinRecordWork *work)
{
    u64 t;
    sptr message;
    int index;
    struct BattleRecSave *source;
    u32 x,y;
    Point args;
    switch(*state) {
    case 0: BR_FADE_Start((void *)((work->ctx->fade)),2,3,1);*state=1;break;
    case 1: if(BR_FADE_GetResult((struct BrFade *)(work->ctx->fade))) *state=2;break;
    case 2:
        if(work->profileScreenShown) BR_CODEIN_RecordDeleteProfileScreen(work,work->ctx);
        else BR_CODEIN_RecordDeleteActors(work,work->ctx);
        BR_CODEIN_RecordDeleteButtons(work,work->ctx);
        BR_CODEIN_RecordCreateTextWin(work,work->ctx);
        BR_UTIL_SetWindowText((char *)work->textWin,work->ctx->res,0x14b);
        *state=3;break;
    case 3: BR_FADE_Start((void *)((work->ctx->fade)),2,3,0);*state=4;break;
    case 4: if(BR_FADE_GetResult((struct BrFade *)(work->ctx->fade))) *state=5;break;
    case 5:
        MI_CpuFill8(&t,0,8);
        t=BATTLE_REC_GetHeaderParam(work->header,4,0);
        BR_NET_StartRequest(work->ctx->net,3,(const union BrNetRequest *)(const int *)(&t));
        work->waitFrames=0;*state=6;break;
    case 6:
        ++work->waitFrames;
        if(BR_NET_IsIdle(work->ctx->net) && work->waitFrames>96) {
            BR_UTIL_StartEffect((void *)(work->introFx), 0, 0);*state=7;
        }
        break;
    case 7:
        if(!BR_NET_PollErrorMessage(work->ctx->net,&message)) {
            if(BR_NET_GetVideoReply((struct BrNet *)work->ctx->net,&source,&index)) {
#ifdef __MWERKS__
                BATTLE_REC_SetData(source,&source->head,&source->body,GAME_DATA_GetSaveControl(work->ctx->gameData));
#else
                BATTLE_REC_SetData(source,&source->head,&source->body);
#endif
                *work->ctx->recA=index;
                work->ctx->result=1;
                BR_PROC_SYS_SetupWindow(work->ctx->proc);*state=8;
            } else {
                BR_UTIL_SetWindowText(work->textWin,work->ctx->res,0x114);*state=11;
            }
        } else {
            BR_UTIL_SetWindowText(work->textWin,work->ctx->res,message);*state=11;
        }
        break;
    case 11:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg((u32 *)&x,(u32 *)&y);args.x=x;args.y=y;
            BR_UTIL_StartEffect((char *)((void *)(work->tapFx)), 1, (const BrPair *)&args);GFL_USE_PlaySeDefaultVolume(0x703);*state=12;
        }
        break;
    case 8: BR_FADE_Start((void *)((work->ctx->fade)),2,3,1);*state=9;break;
    case 9: if(BR_FADE_GetResult((struct BrFade *)(work->ctx->fade))) *state=10;break;
    case 10:
        if(!GFL_USE_IsSeqPlaying(0x701)) {BR_CODEIN_RecordDeleteTextWin(work,work->ctx);BR_UTIL_ClearTaskStep(work->task);}
        break;
    case 12: BR_FADE_Start((void *)((work->ctx->fade)),2,3,1);*state=13;break;
    case 13: if(BR_FADE_GetResult((struct BrFade *)(work->ctx->fade))) *state=14;break;
    case 14: BR_CODEIN_RecordDeleteTextWin(work,work->ctx);BR_UTIL_SetTaskStep(task,BR_CODEIN_RecordStepCreateProfile);break;
    }
}

/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * blocker-C: prior verified Thumb EXACT from BR_CODEIN_SearchBuildHeader.c header, blocker-r2.log, dsi/1.1p1 -O4,p; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 * abi: DD0AC/DD0F4 keep the visibly loaded second descriptor argument despite body using only the first.
 */
void BR_CODEIN_RecordStepSave(struct BrUtilTask *task,int *state,struct CodeinRecordWork *work)
{
    switch(*state) {
    case 0:
        BR_CODEIN_RecordCreateTextWin(work,work->ctx);
        BR_UTIL_SetWindowText((char *)work->textWin,work->ctx->res,0x152);
        BR_FADE_Start((void *)((work->ctx->fade)),2,3,0);
        *state=1;break;
    case 1: if(BR_FADE_GetResult((struct BrFade *)(work->ctx->fade))) *state=2;break;
    case 2: *state=3;break;
    case 3: work->saveCode=0;work->saveStatus=0;*state=4;break;
    case 4:
        if(work->ctx->mode>3) GF_PANIC_Fail(PM_LANG_JA(d_021E3960, str_ja_021E3920), PM_SRC_LINE(0, 0x49E), PM_LANG_JA(d_021E3960, str_ja_021E3934));
        if(GDS_RAP_SaveVideoSecured((void *)(work->ctx->gameData),work->ctx->mode,&work->saveCode,&work->saveStatus,work->heapId)==2) {
            BATTLE_REC_DecodeWork();
            work->savedActorSys=(int)BATTLE_REC_GetHeaderParam(work->header,5,0);
            *state=5;
        }
        break;
    case 5: BR_FADE_Start((void *)((work->ctx->fade)),2,3,1);*state=6;break;
    case 6: if(BR_FADE_GetResult((struct BrFade *)(work->ctx->fade))) *state=7;break;
    case 7: BR_CODEIN_RecordDeleteTextWin(work,work->ctx);BR_UTIL_SetTaskStep(task,BR_CODEIN_RecordStepCreateProfile);break;
    }
}

/*
 * abi: DD0AC/DD0F4 retain caller-loaded r1.
 */
void BR_CODEIN_RecordStepConfirm(struct BrUtilTask *task,int *state,struct CodeinRecordWork *work)
{
    u32 x,y;
    switch(*state) {
    case 0: BR_FADE_Start((void *)(((work->ctx)->fade)),2,3,1);*state=1;break;
    case 1: if(BR_FADE_GetResult((struct BrFade *)((work->ctx)->fade))) *state=2;break;
    case 2:
        if(work->profileScreenShown) BR_CODEIN_RecordDeleteProfileScreen(work,work->ctx);
        else BR_CODEIN_RecordDeleteActors(work,work->ctx);
        BR_CODEIN_RecordDeleteButtons(work,work->ctx);BR_CODEIN_RecordSetupTextWin(work,work->ctx);*state=3;break;
    case 3: BR_FADE_Start((void *)(((work->ctx)->fade)),2,3,0);++*state;break;
    case 4: if(BR_FADE_GetResult((struct BrFade *)((work->ctx)->fade))) ++*state;break;
    case 5: ++*state;break;
    case 6:
        if(TOUCHPANEL_GetPointTrg(&x,&y)) {
            if(BR_CODEIN_RecordHitOptionLeft(work,x,y)) *state=7;
            else if(BR_CODEIN_RecordHitOptionRight(work,x,y)) *state=10;
        }
        break;
    case 7: BR_FADE_Start((void *)(((work->ctx)->fade)),2,3,1);++*state;break;
    case 8: if(BR_FADE_GetResult((struct BrFade *)((work->ctx)->fade))) ++*state;break;
    case 9: BR_CODEIN_RecordTeardownTextWin(work,work->ctx);*state=13;break;
    case 10: BR_FADE_Start((void *)(((work->ctx)->fade)),2,3,1);++*state;break;
    case 11: if(BR_FADE_GetResult((struct BrFade *)((work->ctx)->fade))) ++*state;break;
    case 12: BR_CODEIN_RecordTeardownTextWin(work,work->ctx);BR_UTIL_SetTaskStep(task,BR_CODEIN_RecordStepCreateProfile);break;
    case 13: BR_CODEIN_RecordCreateTextWin(work,work->ctx);*state=14;break;
    case 14:
        BR_UTIL_SetWindowText((char *)work->textWin,(work->ctx)->res,0x152);
        BR_FADE_Start((void *)(((work->ctx)->fade)),2,3,0);*state=15;break;
    case 15: if(BR_FADE_GetResult((struct BrFade *)((work->ctx)->fade))) *state=16;break;
    case 16: *state=17;break;
    case 17: GAME_DATA_SaveStart((struct GameData *)(work->ctx)->gameData);*state=18;break;
    case 18:
        if(GAME_DATA_SaveMain((struct GameData *)(work->ctx)->gameData)==2) {BR_UTIL_StartEffect((char *)((void *)(work->introFx)), 0, 0);*state=19;}
        break;
    case 19: BR_FADE_Start((void *)(((work->ctx)->fade)),2,3,1);*state=20;break;
    case 20: if(BR_FADE_GetResult((struct BrFade *)((work->ctx)->fade))) *state=21;break;
    case 21:
        if(!GFL_USE_IsSeqPlaying(0x701)) {
            BR_CODEIN_RecordDeleteTextWin((struct CodeinRecordWork *)work,work->ctx);
            work->ctx->result=1;
            BR_PROC_SYS_SetupWindow(work->ctx->proc);
            BR_UTIL_ClearTaskStep(task);
        }
        break;
    }
}

/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * blocker-C: prior verified Thumb EXACT from BR_CODEIN_SearchBuildHeader.c header, blocker-r2.log, dsi/1.1p1 -O4,p; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 * lever: counter declared before context locals restores stack homes; named selector fixes call-result addition operand order (existing idioms).
 * abi: EE0C retains caller's sixth outgoing word (2), beyond callee's five used arguments.
 */
void BR_CODEIN_RecordSetupProfile(struct CodeinRecordWork *work,struct BrProcArgBattle *arg)
{
    u16 record[4];
    int i;
    void *font;
    MsgBank *bank;
    WordSet *words;
    int ready;
    U16Vec *text;
    if(!work->actorsLoaded) {
        work->actorsLoaded=1;
        if(BR_CODEIN_RecordIsMultiBattle(work->header)) BR_RES_LoadBgGraphics((void *)(arg->res),7,work->heapId);
        else BR_RES_LoadBgGraphics((void *)(arg->res),6,work->heapId);
        font=(void *)BR_RES_GetFont((struct BrRes *)(arg->res));
        bank=(MsgBank *)BR_RES_GetMsgData((struct BrRes *)(arg->res));
        words=(WordSet *)BR_RES_GetWordSet((struct BrRes *)(arg->res));
        for(i=0;i<5;i++) {
            work->profileText[i]=BR_UTIL_Create(1,d_021E32C8[i].x,d_021E32C8[i].y,d_021E32C8[i].w,d_021E32C8[i].h,14,work->printQue,work->heapId);
            switch(i) {
            case 0:
                {
                void *name;
                void *message;
#if LANGUAGE == LANGUAGE_JAPANESE
                text=MSGDATA_AllocString(bank,d_021E32C8[i].message);
#else
                text=STRBUF_Create(128,work->heapId);
#endif
                name=GDS_PROFILE_CreateNameStr(work->recData,work->heapId);
                message=MSGDATA_AllocString(bank,d_021E32C8[i].message);
                WORDSET_SetSlotTag(words,0,name,GDS_PROFILE_GetEggFlag((RecGet *)work->recData),1,PM_LANG_ID);
                WORDSET_CopyTaggedText(words,text,message);
                STRBUF_Delete((U16Vec *)name);STRBUF_Delete((U16Vec *)message);
                BR_UTIL_SetTextLayout(work->profileText[i],0,PM_LANG_JA(1, 0),0);
                ready=1;break;
                }
            case 1:
                {
                u32 selector;
                selector=BATTLE_REC_GetHeaderParam(work->header,3,0);
                text=MSGDATA_AllocString(bank,selector+d_021E32C8[i].message);
                BR_UTIL_SetTextLayout(work->profileText[i],0,PM_LANG_JA(1, 0),0);ready=1;break;
                }
            case 2:
                {
                u64 value;
                u64 quotient;
                void *message;
                u32 low,middle,high;
                void *temporary;
                value=BATTLE_REC_GetHeaderParam(work->header,4,0);
                low=value%100000ULL;
                quotient=value/100000ULL;
                middle=quotient%100000ULL;
                high=quotient/100000ULL;
                temporary=GDS_PROFILE_ExportRecord((GdsProfile *)work->recData,(GdsRecord *)record,work->heapId);
                if(temporary) {
                    message=MSGDATA_AllocString(bank,13);STRBUF_Delete((U16Vec *)temporary);
                } else message=MSGDATA_AllocString(bank,d_021E32C8[i].message);
                text=STRBUF_Create(128,work->heapId);
                WORDSET_SetSlotNumber(words,2,low,5,2, PM_LANG_HALF_WIDTH_DIGITS);WORDSET_SetSlotNumber(words,1,middle,5,2, PM_LANG_HALF_WIDTH_DIGITS);WORDSET_SetSlotNumber(words,0,high,2,2, PM_LANG_HALF_WIDTH_DIGITS);
                WORDSET_CopyTaggedText(words,text,message);
                BR_UTIL_SetTextLayout(work->profileText[i],0,PM_LANG_JA(1, 0),0);STRBUF_Delete((U16Vec *)message);
                ready=1;break;
                }
            case 3:
                if(BR_CODEIN_RecordIsType2(work->header)) {
                    u32 count;
                    void *message;
                    count=BATTLE_REC_GetHeaderParam(work->header,2,0);
#if LANGUAGE == LANGUAGE_JAPANESE
                    text=MSGDATA_AllocString(bank,d_021E32C8[i].message);
#else
                    text=STRBUF_Create(128,work->heapId);
#endif
                    message=MSGDATA_AllocString(bank,d_021E32C8[i].message);
                    WORDSET_SetSlotNumber(words,0,count,4,0, PM_LANG_HALF_WIDTH_DIGITS);WORDSET_CopyTaggedText(words,text,message);STRBUF_Delete((U16Vec *)message);
                    BR_UTIL_SetTextLayout(work->profileText[i],0,PM_LANG_JA(1, 0),1);ready=1;
                } else ready=0;
                break;
            case 4:
                if(BR_CODEIN_RecordIsType2(work->header)) {
                    text=MSGDATA_AllocString(bank,d_021E32C8[i].message);
                    BR_UTIL_SetTextLayout(work->profileText[i],0,PM_LANG_JA(1, 0),1);ready=1;
                } else ready=0;
                break;
            }
            if(ready) {
                BR_UTIL_SetTextFromBuffer(work->profileText[i],text,font,0x3da0);STRBUF_Delete(text);
            }
        }
        BR_CODEIN_RecordSetupActors(work,arg->unit,work->header,work->heapId);
    }
}

/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * blocker-symbols: BattleRecModeTable 0x0209DDCC data a4
 *   typedef unsigned char u8;
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
 * lever: swapped start/end declaration homes, then zeroed phase-two j before coords assignment; DIFF16 to4 to MATCH.
 * checks: 1 own ARM9 and matched caller arities re-derived; B98C original shown, 3 args/u64, DD228 shown 1 arg; 2 F838 and F620/DE084 twins reread; 3 codegen became MATCH in3 runs, further type probes unnecessary; 4 counter-before-base/declared-struct idioms read; 5 fresh directory/neighbors reread before handoff; prior permuter300 not repeated.
 * TU: cbd8-tu.log terminal exit0, MATCH, three B98C wildcards at +009A/+00A6/+00B2, no viable split.
 */
void BR_CODEIN_RecordSetupActors(struct CodeinRecordWork *work,void *manager,void *party,u16 heap)
{
    u32 species[12],forms[12],half[12];
    Position pos;
    u32 v,f,h;
    int count=0;
    int mode;
    void *archive;
    int step;
    int i;
    int start;
    int n;
    int end;
    const Point16 *coords;
    int mapping;
    archive=ARC_TOOL_CreateHandle(7,(u16)((heap&0x7fff)|0x8000));
    work->paletteRes=CLACT_RegisterPaletteCompressed(archive,POKE_TOOL_GetIconPaletteArcId(),0,128,heap);
    mapping=POKE_TOOL_GetIconCellArcId();
    work->cellAnimRes=CLACT_RegisterCellAnim(archive,mapping,POKE_TOOL_GetIconCellEntryId(),heap);
    n=0;
    step=6;start=0;end=6;mode=0;
    if(BR_CODEIN_RecordIsMultiBattle(party)==1) {step=3;end=3;mode=1;}
    do {
        for(i=start;i<end;i++) {
            species[n]=255;
            v=BATTLE_REC_GetHeaderParam(party,0,i);
            f=BATTLE_REC_GetHeaderParam(party,1,i);
            h=BATTLE_REC_GetHeaderParam(party,6,i);
            if(v) {species[n]=v;forms[n]=f;half[n]=h;n++;}
        }
        for(i=n;i<end;i++) {species[n]=0;forms[n]=0;half[n]=0;n++;}
        start+=step;end+=step;
    } while(end<=12);
    {
    int j;
    u32 h2,f2,v2;
    j=0;
    coords=(const Point16 *)((const char *)d_021E32F0+(int)mode*48);
    for(;j<12;j++) {
        work->actor[j]=0;
        work->charRes[j]=-1;
        v2=species[j];
        if(v2) {
            h2=half[j];f2=forms[j];
            work->charRes[j]=CLACT_RegisterCharacter(archive,POKE_TOOL_CalcGraphicIndex(v2,f2,h2,0),0,0,heap);
            MI_CpuFill8(&pos,0,8);
            pos.x=coords[j].x+8;pos.y=coords[j].y-12;pos.z=1;pos.a=12-count;
            work->actor[count]=CLACT_CreateActor(manager,work->charRes[j],work->paletteRes,work->cellAnimRes,(const struct ActorInitParam *)&pos,0,heap);
            CLACT_SetActorObjMode(work->actor[count],1);
            CLACT_SetActorPaletteOffset(work->actor[count],POKE_TOOL_CalcIconPalette(v2,f2,h2,0),0);
            count++;
        }
    }
    }
    ARC_TOOL_DeleteHandle(archive);
}

void BR_CODEIN_RecordCreateProfileScreen(struct CodeinRecordWork *work, struct BrProcArgBattle *arg)
{
    int flag;
    if(*(int *)&work->profileScreen==0 && work->profileScreenLoaded==0) {
        work->profileScreenLoaded=1;
        flag=1;
        if(work->ctx->mode==0) flag=0;
        work->profileScreen=BR_UTIL_CreateProfileScreen((void *)(*(void **)&work->recData),arg->res,(void *)(arg->unit),(void *)(work->printQue),flag,work->heapId);
    }
}

void BR_CODEIN_RecordDeleteProfileScreen(struct CodeinRecordWork *work,struct BrProcArgBattle *unused) { if(work->profileScreenLoaded && *(int * *)&work->profileScreen) { BR_UTIL_DeleteProfileScreen(work->profileScreen); work->profileScreen=0; work->profileScreenLoaded=0; } }

void BR_CODEIN_RecordDeleteActors(struct CodeinRecordWork *work,struct BrProcArgBattle *arg)
{
    int i;
    if(work->actorsLoaded) {
        for(i=0;i<12;i++) {

            if(work->actor[i]) {
                CLACT_SetActorDrawEnable(work->actor[i],0);
                CLACT_DeleteActor(work->actor[i]);
                work->actor[i]=0;
            }
            if(work->charRes[i]!=-1) { CLACT_ReleaseCharacter(work->charRes[i]); work->charRes[i]=-1; }
        }
        if(work->paletteRes!=-1) { CLACT_ReleasePalette(work->paletteRes); work->paletteRes=-1; }
        if(work->cellAnimRes!=-1) { CLACT_ReleaseCellAnim(work->cellAnimRes); work->cellAnimRes=-1; }
        for(i=0;i<5;i++) {

            if(work->profileText[i]) { BR_UTIL_Delete((u8 *)work->profileText[i]); work->profileText[i]=0; }
        }
        BR_RES_ApplyBgSet((void *)(arg->res),6);
        BG_SYS_PushTile(1);
        work->actorsLoaded=0;
    }
}

void BR_CODEIN_RecordSetupButtons(struct CodeinRecordWork *work,struct BrProcArgBattle *arg)
{
    void *a; void *b;
    if(!work->buttonsLoaded) {
        work->buttonsLoaded=1;
        BR_RES_LoadBgGraphics((void *)(arg->res),5,work->heapId);
        BR_RES_LoadSprite((struct BrRes *)(arg->res),6,work->heapId);
        a=BR_RES_GetFont((struct BrRes *)(arg->res));
        b=BR_RES_GetMsgData((struct BrRes *)(arg->res));
        if(work->hasSecondButton) {
            BrCodeinParams d;
            BrCodeinTriple t;
            MI_CpuFill8((void *)&d,0,8);
            d.a=24;d.b=168;d.c=0;d.flag=1;
            BR_RES_GetSprite((struct BrRes *)(arg->res),6,(void *)&t);
            (*(void * *)&work->button[0])=BR_BTN_CreateFromMessage((void *)&d,4,96,1,(void *)(arg->unit),(void *)(work->oamSys),(void *)a,(struct MsgBank *)b,(void *)&t,work->heapId);
            d.a=136;d.c=3;
            (*(void * *)&work->button[1])=BR_BTN_CreateFromMessage((void *)&d,84,96,1,(void *)(arg->unit),(void *)(work->oamSys),(void *)a,(struct MsgBank *)b,(void *)&t,work->heapId);
        } else {
            BrCodeinParams d;
            BrCodeinTriple t;
            MI_CpuFill8((void *)&d,0,8);
            d.a=80;d.b=168;d.c=0;d.flag=1;
            BR_RES_GetSprite((struct BrRes *)(arg->res),6,(void *)&t);
            (*(void * *)&work->button[0])=BR_BTN_CreateFromMessage((void *)&d,4,96,1,(void *)(arg->unit),(void *)(work->oamSys),(void *)a,(struct MsgBank *)b,(void *)&t,work->heapId);
        }
        (*(void * *)&work->captionText[0])=BR_UTIL_Create(4,8,3,16,2,14,work->printQue,work->heapId);
        if(work->profileScreenShown) BR_UTIL_SetTextFromMessage(work->captionText[0],(void *)b,0x72,(void *)a,0x3da0);
        else BR_UTIL_SetTextFromMessage(work->captionText[0],(void *)b,0x71,(void *)a,0x3da0);
    }
}

void BR_CODEIN_RecordDeleteButtons(struct CodeinRecordWork *work, struct BrProcArgBattle *arg)
{
    int i;
    if(work->buttonsLoaded) {
        if(work->captionText[0]) { BR_UTIL_Delete(work->captionText[0]); *(int *)&work->captionText[0]=0; }
        for(i=0;i<2;i++) {

            if(work->button[i]) { BR_BTN_DeleteObject(work->button[i]); work->button[i]=0; }
        }
        BG_SYS_PushTile(4);
        BR_RES_ReleaseSprite((struct BrRes *)((char *)(arg->res)),6);
        BR_RES_ApplyBgSet((void *)(arg->res),5);
        work->buttonsLoaded=0;
    }
}

void BR_CODEIN_RecordCreateTextWin(struct CodeinRecordWork *work, struct BrProcArgBattle *unused)
{
    if (!work->textWinCreated) {
        Point args;
        work->textWinCreated = 1;
        if (!work->textWin)
            work->textWin = BR_UTIL_CreateTextWin((void *)((work->ctx)->res), (void *)(work->printQue), work->heapId);
        args.x = 0x80;
        args.y = 0x60;
        BR_UTIL_StartEffect((char *)((void *)(work->introFx)), 4, (const BrPair *)&args);
    }
}

void BR_CODEIN_RecordDeleteTextWin(struct CodeinRecordWork *work, struct BrProcArgBattle *unused) { if(work->textWinCreated) { BR_UTIL_StartEffect(work->introFx,0,0); if(work->textWin) { BR_UTIL_DeleteTextWin(work->textWin,(work->ctx)->res); work->textWin=0; } work->textWinCreated=0; } }

void BR_CODEIN_RecordSetupTextWin(struct CodeinRecordWork *work, struct BrProcArgBattle *arg)
{
    if (!work->textWinSetup) {
        void *first; void *second; int i;
        const BrCodeinRecord *rec;
        work->textWinSetup = 1;
        if (!work->textWin)
            work->textWin = BR_UTIL_CreateTextWin((void *)(arg->res), (void *)(work->printQue), work->heapId);
        BR_UTIL_SetWindowText((char *)work->textWin, arg->res, 0x14f);
        BR_RES_LoadBgGraphics((void *)(arg->res), 30, work->heapId);
        first = BR_RES_GetFont((struct BrRes *)(arg->res));
        second = BR_RES_GetMsgData((struct BrRes *)(arg->res));
        for (i = 0; i < 2; i++) {
            rec = &d_021E32A8[i];

            work->captionText[i] = BR_UTIL_Create(4, rec->a, rec->b, rec->c, rec->d, 14, (void *)(work->printQue), work->heapId);
            BR_UTIL_SetTextFromMessage(work->captionText[i], (void *)second, rec->value, (void *)first, 0x3da0);
        }
    }
}

/*
 * trailing: 2 zero alignment bytes at 0x021DD226
 */
void BR_CODEIN_RecordTeardownTextWin(struct CodeinRecordWork *work, struct BrProcArgBattle *arg)
{
    int i;
    if (work->textWinSetup) {
        for (i = 0; i < 2; i++) {

            if (work->captionText[i]) {
                BR_UTIL_Delete(work->captionText[i]);
                work->captionText[i] = 0;
            }
        }
        BG_SYS_PushTile(4);
        BR_RES_ApplyBgSet((void *)(arg->res), 30);
        if (work->textWin) {
            BR_UTIL_DeleteTextWin(work->textWin, arg->res);
            work->textWin = 0;
        }
        work->textWinSetup = 0;
    }
}

/*
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * blocker-symbols: BattleRecModeTable 0x0209DDCC data a4
 *   typedef unsigned char u8;
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
 *       case 1: return *(u8 *)(p + index + 0x18) & 0x7F;
 *       case 2:
 *           v = *(u16 *)(p + 0x24);
 *           if (v > 0x270F) return 0x270F;
 *           return v;
 *       case 3:
 *           for (i = 0; i < 0x29; i++) {
 *               if (*(u16 *)(p + 0x26) == BattleRecModeTable[i]) return i;
 *           }
 *           return 0;
 *       case 4: return *(u64 *)&p->profileText[2];
 *       case 5: return *(u8 *)(p + 0x2A);
 *       case 6: return (*(u8 *)(p + index + 0x18) & 0x80) >> 7;
 *       case 7: return *(u8 *)(p + 0x2B);
 *       default: return 0;
 *       }
 *   }
 */
int BR_CODEIN_RecordIsMultiBattle(void *work) { switch((int)BATTLE_REC_GetHeaderParam(work,3,0)) { case 16: case 17: case 18: case 19: case 22: return 1; case 20: case 21: default: return 0; } }

int BR_CODEIN_RecordIsType2(void *work) { int result; int v; result=0; v=(int)BATTLE_REC_GetHeaderParam(work,3,0); if(v==20) goto yes; if(v==21) goto yes; if(v!=22) goto no; yes: return 1; no: return result; }

int BR_CODEIN_RecordHitProfileToggle(struct CodeinRecordWork *work, int x, int y)
{
    int ok = ((unsigned int)(x - 0x40) <= 0x88) &
             ((unsigned int)(y - 0x10) <= 0x20);
    if (ok) {
        Point args;
        args.x = x;
        args.y = y;
        BR_UTIL_StartEffect((char *)((void *)((work->tapFx))), 1, (const BrPair *)&args);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}

int BR_CODEIN_RecordHitRecordPanel(struct CodeinRecordWork *work, int x, int y)
{
    int ok = ((unsigned int)(x - 0x50) <= 0x60) &
             ((unsigned int)(y - 0x38) <= 0x40);
    if (ok) {
        Point args;
        args.x = x;
        args.y = y;
        BR_UTIL_StartEffect((char *)((void *)((work->tapFx))), 1, (const BrPair *)&args);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}

int BR_CODEIN_RecordHitOptionLeft(struct CodeinRecordWork *work, int x, int y)
{
    int ok = ((unsigned int)(x - 0x20) <= 0x48) &
             ((unsigned int)(y - 0x30) <= 0x10);
    if (ok) {
        Point args;
        args.x = x;
        args.y = y;
        BR_UTIL_StartEffect((char *)((void *)(work->tapFx)), 1, (const BrPair *)&args);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}

int BR_CODEIN_RecordHitOptionRight(struct CodeinRecordWork *work, int x, int y)
{
    int ok = ((unsigned int)(x - 0x90) <= 0x48) &
             ((unsigned int)(y - 0x30) <= 0x10);
    if (ok) {
        Point args;
        args.x = x;
        args.y = y;
        BR_UTIL_StartEffect((char *)((void *)(work->tapFx)), 1, (const BrPair *)&args);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}


extern int (*const d_021E3858[])(char *);


