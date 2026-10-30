/*
 * file:     br_bvdelete_proc.c
 * unit:     yes
 * function: BR_CODEIN_UploadCreate, BR_CODEIN_UploadDestroy, BR_CODEIN_UploadMain, BR_CODEIN_UploadStepFadeIn, BR_CODEIN_UploadStepFadeOut, BR_CODEIN_UploadStep, BR_CODEIN_SaveCreate, BR_CODEIN_SaveDestroy, BR_CODEIN_SaveMain, BR_CODEIN_SaveStepFadeIn, BR_CODEIN_SaveStepFadeOut, BR_CODEIN_SaveStepVideo, BR_CODEIN_SaveSetupText, BR_CODEIN_SaveDeleteTextWin, BR_CODEIN_SaveTeardown, BR_CODEIN_SaveHitOptionLeft, BR_CODEIN_SaveHitOptionRight, BR_CODEIN_SoclCreate, BR_CODEIN_SoclDestroy, BR_CODEIN_SoclMain, BR_CODEIN_SoclStep, BR_CODEIN_MenuStep, BR_CODEIN_MenuStepInput, BR_CODEIN_MenuStepSave, BR_CODEIN_CallAndClearStepFn, BR_CODEIN_CallAndClearDestroyFn, BR_CODEIN_CopySoclResource, BR_CODEIN_SoclSetupText, BR_CODEIN_SoclTeardown
 * address:  0x021E1C80
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
#include "br_bvdelete_proc.h"
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


extern int (*const d_021E3858[])(char *);


int BR_CODEIN_UploadCreate(struct Proc *obj,int unused,struct BrProcArgNet *arg)
{
    struct CodeinUploadWork *p;
    int i;
    Point pair;
    p=PROCSYS_AllocProcWork(obj,sizeof(*p),BR_PROC_SYS_GetSlotId(arg->proc));
    MI_CpuFill8(p,0,sizeof(*p));
    p->ctx=arg;
    p->heapId=BR_PROC_SYS_GetSlotId(arg->proc);
    p->task=BR_UTIL_CreateTask(p,BR_CODEIN_UploadStepFadeIn,p->heapId);
    p->printQue=PRINTSYS_QUE_Create(p->heapId);
    p->textWin=BR_UTIL_CreateTextWin((void *)(arg->res),(void *)(p->printQue),p->heapId);
    BR_UTIL_SetWindowText((char *)(p->textWin),arg->res,111);
    for (i=0;i<2;i++) (&p->introFx)[i]=BR_UTIL_CreateHandles(arg->unit,arg->res,i,p->heapId);
    pair=d_021E38E0;
    BR_UTIL_StartEffect((char *)((void *)(p->introFx)), 4, (const BrPair *)&pair);
    return 1;
}

int BR_CODEIN_UploadDestroy(struct Proc *proc,int seq,struct BrProcArgNet *arg,struct CodeinUploadWork *work){int i;for(i=0;i<2;i++)BR_UTIL_DeleteHandles((&work->introFx)[i]);BR_UTIL_DeleteTextWin((void *)work->textWin,arg->res);PRINTSYS_QUE_Delete((void *)work->printQue);BR_UTIL_DeleteTask((void *)((work->task)));PROCSYS_FreeProcWork(proc);return 1;}

int BR_CODEIN_UploadMain(int proc,int seq,int arg,struct CodeinUploadWork *work)
{
    int i;
    if (!GAME_DATA_IsSaving((const struct GameData *)((const u8 *)((work->ctx)->gameData))) && BR_NET_HandleNetError((struct BrNet *)(char *)((work->ctx)->net))==2) {
        BR_PROC_SYS_FlushWindows((void *)((work->ctx->proc)));
        return 1;
    }
    BR_UTIL_RunTask(work->task);
    if (BR_UTIL_IsTaskIdle(work->task)) return 1;
    for (i=0;i<2;i++) BR_UTIL_RunHandles((char *)((&work->introFx)[i]));
    PRINTSYS_QUE_Main((struct PrintQueue *)(work->printQue));
    BR_UTIL_FlushWindow((void *)(work->textWin));
    return 0;
}

void BR_CODEIN_UploadStepFadeIn(struct BrUtilTask *task,int *state,struct CodeinUploadWork *work)
{
    switch (*state) {
    case 0: BR_FADE_Start((void *)(work->ctx->fade),2,3,0); *state=1; break;
    case 1: if (BR_FADE_GetResult((struct BrFade *)((int *)(work->ctx->fade)))) *state=2; break;
    case 2: BR_UTIL_SetTaskStep(task,BR_CODEIN_UploadStep); break;
    }
}

void BR_CODEIN_UploadStepFadeOut(struct BrUtilTask *task,int *state,struct CodeinUploadWork *work)
{
    switch (*state) {
    case 0: BR_FADE_Start((void *)(work->ctx->fade),2,3,1); *state=1; break;
    case 1: if (BR_FADE_GetResult((struct BrFade *)((int *)(work->ctx->fade)))) *state=2; break;
    case 2: BR_PROC_SYS_PopEntry((struct BrProcSysContext *)((work->ctx->proc))); BR_UTIL_ClearTaskStep(task); break;
    }
}

/*
 * lever: keep the copied u64 and quotient distinct; use the emitted _ull_mod runtime symbol.
 */
void BR_CODEIN_UploadStep(struct BrUtilTask *task,int *state,struct CodeinUploadWork *work) {
    u32 out;
    u64 total;
    u32 msg,x,y; Point pair;
    void *str,*expanded,*ws,*bank;
    u64 copy,quotient;
    int result;
    switch(*state) {
    case 0:
        BATTLE_REC_Load(GAME_DATA_GetSaveControl((work->ctx->gameData)),89,&out,0);
        if(out==1)*state=1;else BR_UTIL_SetTaskStep(task,BR_CODEIN_UploadStepFadeOut);break;
    case 1:
        work->frames=0;BR_NET_StartRequest((work->ctx->net),2,0);*state=2;break;
    case 2:
        ++work->frames;
        if(BR_NET_IsIdle((work->ctx->net))) {
            total=0;
            if(work->frames>=96) {
                result=BR_NET_PollErrorMessage((work->ctx->net),(int *)(&msg));
                if(result==0) {
                    if(BR_NET_GetUploadedDataNumber((work->ctx->net),&total)) {
                        bank=(void *)BR_RES_GetMsgData((struct BrRes *)(work->ctx->res));
                        ws=(void *)BR_RES_GetWordSet((struct BrRes *)(work->ctx->res));
                        str=MSGDATA_AllocString(bank,334);expanded=STRBUF_Create(128,0x8059);
                        copy=total;quotient=copy/100000;
                        WORDSET_SetSlotNumber(ws,2,(u32)(copy%100000),5,2, PM_LANG_HALF_WIDTH_DIGITS);
                        WORDSET_SetSlotNumber(ws,1,(u32)(quotient%100000),5,2, PM_LANG_HALF_WIDTH_DIGITS);
                        WORDSET_SetSlotNumber(ws,0,(u32)(quotient/100000),2,2, PM_LANG_HALF_WIDTH_DIGITS);
                        WORDSET_CopyTaggedText(ws,expanded,str);
                        BR_UTIL_SetWindowTextBuf((char *)(work->textWin),(void *)((work->ctx->res)),expanded);
                        STRBUF_Delete(expanded);STRBUF_Delete(str);
                    }
                } else if(result==3) {
                    BR_PROC_SYS_FlushWindows((void *)((work->ctx->proc)));BR_UTIL_ClearTaskStep(task);break;
                } else BR_UTIL_SetWindowText((char *)(work->textWin),work->ctx->res,msg);
                BR_UTIL_StartEffect((void *)(work->introFx), 0, 0);*state=4;
            }
        }break;
    case 3:BR_UTIL_SetTaskStep(task,BR_CODEIN_UploadStepFadeOut);break;
    case 4:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg((u32 *)&x,(u32 *)&y);pair.x=x;pair.y=y;BR_UTIL_StartEffect((char *)((void *)((work->tapFx))), 1, (const BrPair *)&pair);
            GFL_USE_PlaySeDefaultVolume(0x703);*state=3;
        }break;
    }
}

int BR_CODEIN_SaveCreate(struct Proc *obj,int unused,struct BrProcArgRecord *arg)
{
    struct CodeinSaveWork *p;
    int i;
    if (arg->mode>=4) GF_PANIC_Fail(PM_LANG_JA(d_021E39B4, str_ja_021E3A40), PM_SRC_LINE(0, 0x8E), PM_LANG_JA(d_021E39B4, str_ja_021E3A54));
    p=PROCSYS_AllocProcWork(obj,sizeof(struct CodeinSaveWork),BR_PROC_SYS_GetSlotId(arg->proc));
    MI_CpuFill8(p,0,sizeof(struct CodeinSaveWork));
    p->saveCtx=arg;
    p->heapId=BR_PROC_SYS_GetSlotId(arg->proc);
    p->task=BR_UTIL_CreateTask(p,BR_CODEIN_SaveStepFadeIn,p->heapId);
    p->printQue=PRINTSYS_QUE_Create(p->heapId);
    BR_CODEIN_SaveSetupText(p,arg);
    for (i=0;i<2;i++) (&p->introFx)[i]=BR_UTIL_CreateHandles(arg->unit,arg->res,i,p->heapId);
    return 1;
}

/*
 * Extent remainder: zero alignment halfword at 021E20F6.
 */
int BR_CODEIN_SaveDestroy(struct Proc *obj,int seq,struct BrProcArgRecord *arg,struct CodeinSaveWork *work)
{
    int i;
    for (i=0;i<2;i++) BR_UTIL_DeleteHandles((char *)((&work->introFx)[i]));
    if (work->saveCtx->saved) BR_CODEIN_SaveDeleteTextWin(work,arg);
    else { BR_CODEIN_SaveDeleteTextWin(work,arg); BR_CODEIN_SaveTeardown(work,arg); }
    PRINTSYS_QUE_Delete((struct PrintQueue *)((work->printQue)));
    BR_UTIL_DeleteTask((void *)((work->task)));
    PROCSYS_FreeProcWork(obj);
    return 1;
}

int BR_CODEIN_SaveMain(int proc,int seq,int arg,struct CodeinSaveWork *work)
{
    int i;
    BR_UTIL_RunTask(work->task);
    if (BR_UTIL_IsTaskIdle(work->task)) return 1;
    for (i=0;i<2;i++) BR_UTIL_RunHandles((char *)((&work->introFx)[i]));
    PRINTSYS_QUE_Main((struct PrintQueue *)((work->printQue)));
    if ((work->textWin)) BR_UTIL_FlushWindow((void *)((work->textWin)));
    for (i=0;i<2;i++) if (work->bodyText[i]) BR_UTIL_FlushText(work->bodyText[i]);
    return 0;
}

void BR_CODEIN_SaveStepFadeIn(struct BrUtilTask *task,int *state,struct CodeinSaveWork *work)
{
    switch (*state) {
    case 0: BR_FADE_Start(work->saveCtx->fade,2,3,0); *state=1; break;
    case 1: if (BR_FADE_GetResult((struct BrFade *)(work->saveCtx->fade))) *state=2; break;
    case 2: BR_UTIL_SetTaskStep(task,BR_CODEIN_SaveStepVideo); break;
    }
}

void BR_CODEIN_SaveStepFadeOut(struct BrUtilTask *task,int *state,struct CodeinSaveWork *work)
{
    switch (*state) {
    case 0: BR_FADE_Start(work->saveCtx->fade,2,3,1); *state=1; break;
    case 1: if (BR_FADE_GetResult((struct BrFade *)(work->saveCtx->fade))) *state=2; break;
    case 2: BR_PROC_SYS_PopEntry((struct BrProcSysContext *)(work->saveCtx->proc)); BR_UTIL_ClearTaskStep(task); break;
    }
}

/*
 * lever: separate function-scope coordinate pairs retain the switch cases' stack slots.
 */
void BR_CODEIN_SaveStepVideo(struct BrUtilTask *task,int *state,struct CodeinSaveWork *work) {
    u32 x0,y0,x1,y1; Point first; u32 x9,y9; Point second;
    u32 old; int result;
    switch(*state) {
    case 0:
        if(TOUCHPANEL_GetPointTrg(&x0,&y0)) {
            if(BR_CODEIN_SaveHitOptionLeft(work,x0,y0)) {BR_UTIL_SetWindowText((char *)((work->textWin)),work->saveCtx->res,322);*state=1;}
            else if(BR_CODEIN_SaveHitOptionRight(work,x0,y0))*state=10;
        } break;
    case 1:
        if(TOUCHPANEL_GetPointTrg(&x1,&y1)) {
            if(BR_CODEIN_SaveHitOptionLeft(work,x1,y1))*state=2;
            else if(BR_CODEIN_SaveHitOptionRight(work,x1,y1))*state=10;
        } break;
    case 2:BR_FADE_Start(work->saveCtx->fade,2,2,1);++*state;break;
    case 3:
        if(BR_FADE_GetResult((struct BrFade *)(work->saveCtx->fade))) {
            BR_CODEIN_SaveTeardown(work,work->saveCtx);
            BR_UTIL_SetWindowText((char *)((work->textWin)),work->saveCtx->res,323);
            first.x=128;first.y=96;BR_UTIL_StartEffect((char *)((void *)(work->introFx)), 4,(const BrPair *)&first);
            work->videoFrames=0;++*state;
        } break;
    case 4:BR_FADE_Start(work->saveCtx->fade,2,2,0);++*state;break;
    case 5:if(BR_FADE_GetResult((struct BrFade *)(work->saveCtx->fade)))++*state;break;
    case 6:
        GDS_RAP_StartVideoSave((struct GameData *)(work->saveCtx->gameData),work->heapId,work->saveCtx->mode);
        ++work->videoFrames;++*state;break;
    case 7:
        result=GDS_RAP_StepVideoSave((struct GameData *)((char *)(work->saveCtx->gameData)),work->saveCtx->mode);
        ++work->videoFrames;
        if((u32)(result-2)<=1) {work->saveCtx->saved=1;*state=8;}break;
    case 8:
        old=work->videoFrames;work->videoFrames=old+1;
        if(old>96) {BR_UTIL_StartEffect((void *)(work->introFx), 0,0);BR_UTIL_SetWindowText((char *)((work->textWin)),work->saveCtx->res,324);*state=9;}break;
    case 9:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg((u32 *)&x9,(u32 *)&y9);second.x=x9;second.y=y9;
            BR_UTIL_StartEffect((char *)((void *)(work->tapFx)), 1,(const BrPair *)&second);GFL_USE_PlaySeDefaultVolume(0x703);*state=10;
        }break;
    case 10:BR_UTIL_SetTaskStep(task,BR_CODEIN_SaveStepFadeOut);break;
    }
}

/*
 * lever: bounded permuter extracted index/base/heap-address temporaries;
 *   unsigned index arithmetic and top-of-block declarations preserve behavior.
 *   This removes the 12-byte setup scheduling residue; fixed one confirms EXACT.
 * arity: 0201EE0C's unit declares five arguments; this caller visibly supplies
 *   the sixth stack word (2), retained without editing the callee.
 */
void BR_CODEIN_SaveSetupText(struct CodeinSaveWork *work,const struct BrProcArgRecord *input) {
    struct WordSet *ws;
    struct Strbuf *str,*expanded;
    void *font; void *bank; int i;
    const BrCodeinRec *r;
    struct BrProcRecords *base; u32 index;
    u16 *heapIdPtr;
    if(!work->textWin) work->textWin=BR_UTIL_CreateTextWin((void *)(input->res),(void *)(work->printQue),work->heapId);
    ws=(struct WordSet *)BR_RES_GetWordSet((struct BrRes *)input->res);
    str=MSGDATA_AllocString((struct MsgBank *)BR_RES_GetMsgData((struct BrRes *)input->res),321);
    heapIdPtr=&work->heapId;
    expanded=STRBUF_Create(128,*heapIdPtr);
    base=input->rec;
    index=input->mode;
    WORDSET_SetSlotTag(ws,0,input->rec->name[index],
        base->eggFlag[index],1,PM_LANG_ID);
    WORDSET_CopyTaggedText(ws,expanded,str);
    BR_UTIL_SetWindowTextBuf((char *)(work->textWin),(void *)input->res,(void *)expanded);
    STRBUF_Delete((struct Strbuf *)expanded); STRBUF_Delete((struct Strbuf *)str);
    BR_RES_LoadBgGraphics((void *)(input->res),30,work->heapId);
    font=BR_RES_GetFont((struct BrRes *)input->res);
    bank=BR_RES_GetMsgData((struct BrRes *)input->res);
    for(i=0;i<2;i++) {
        r=&d_021E3900[i];
        work->bodyText[i]=BR_UTIL_Create(4,r->a,r->b,r->c,r->d,14,(work->printQue),work->heapId);
        BR_UTIL_SetTextFromMessage(work->bodyText[i],(void *)bank,r->value,(void *)font,0x3da0);
    }
}

void BR_CODEIN_SaveDeleteTextWin(struct CodeinSaveWork *work, struct BrProcArgRecord *res)
{
    if ((work->textWin) != 0) {
        BR_UTIL_DeleteTextWin((void *)((work->textWin)), res->res);
        (work->textWin) = 0;
    }
}

/*
 * extent: final two bytes are alignment padding.
 */
void BR_CODEIN_SaveTeardown(struct CodeinSaveWork *work,struct BrProcArgRecord *arg){int i;for(i=0;i<2;i++){if(work->bodyText[i]){BR_UTIL_Delete((u8 *)(work->bodyText[i]));work->bodyText[i]=0;}}BG_SYS_PushTile(4);BR_RES_ApplyBgSet(arg->res,30);}

int BR_CODEIN_SaveHitOptionLeft(struct CodeinSaveWork *work, int x, int y)
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

int BR_CODEIN_SaveHitOptionRight(struct CodeinSaveWork *work, int x, int y)
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

int BR_CODEIN_SoclCreate(void *obj,int seq,struct BrProcArgResult *arg)
{
    struct CodeinSoclWork *p;
    int i;
    p=PROCSYS_AllocProcWork(obj,sizeof(struct CodeinSoclWork),BR_PROC_SYS_GetSlotId(arg->proc));
    MI_CpuFill8(p,0,sizeof(struct CodeinSoclWork));
    p->arg=arg;
    p->heapId=BR_PROC_SYS_GetSlotId(arg->proc);
    p->oamSys=BMP_OAM_CreateSys(p->heapId,arg->unit);
    p->task=BR_UTIL_CreateTask(p,BR_CODEIN_SoclStep,p->heapId);
    (p->printQue)=PRINTSYS_QUE_Create((unsigned int)p->heapId);
    for (i=0;i<2;i++) (&p->introFx)[i]=BR_UTIL_CreateHandles(arg->unit,arg->res,i,p->heapId);
    return 1;
}

/*
 * Extent remainder: zero alignment halfword at 021E263E.
 */
int BR_CODEIN_SoclDestroy(struct Proc *obj,int seq,int arg,struct CodeinSoclWork *work)
{
    int i;
    BR_CODEIN_CallAndClearDestroyFn(&work->fns,work,work->arg);
    for (i=0;i<2;i++) BR_UTIL_DeleteHandles((&work->introFx)[i]);
    if (work->textWin) {
        BR_UTIL_DeleteTextWin(work->textWin,work->arg->res);
        work->textWin=0;
    }
    PRINTSYS_QUE_Delete((struct PrintQueue *)((work->printQue)));
    BR_UTIL_DeleteTask((void *)((work->task)));
    BMP_OAM_DeleteSys((void *)((work->oamSys)));
    BR_PROC_SYS_PopEntry(work->arg->proc);
    PROCSYS_FreeProcWork(obj);
    return 1;
}

int BR_CODEIN_SoclMain(int proc,int seq,int arg,struct CodeinSoclWork *work)
{
    int i;
    if (!GAME_DATA_IsSaving(work->arg->gameData) && BR_NET_HandleNetError(work->arg->net)==2) {
        BR_PROC_SYS_FlushWindows(work->arg->proc);
        return 1;
    }
    BR_UTIL_RunTask(work->task);
    if (BR_UTIL_IsTaskIdle(work->task)) return 1;
    for (i=0;i<2;i++) BR_UTIL_RunHandles((char *)((&work->introFx)[i]));
    PRINTSYS_QUE_Main((struct PrintQueue *)((work->printQue)));
    if ((work->textWin)) BR_UTIL_FlushWindow((void *)((work->textWin)));
    for (i=0;i<2;i++) if (work->text[i]) BR_UTIL_FlushText((u8 *)work->text[i]);
    return 0;
}

void BR_CODEIN_SoclStep(struct BrUtilTask *task,CodeinSoclState *state,struct CodeinSoclWork *work) {
    u32 req[2];
    int msg;
    int extra;struct BattleRecSave *rec;
    u32 x,y;Point click;struct CodeinStoredFns cb;
    int result,found,i;
    u64 value;struct BrProcArgResult *arg;
    switch(*state) {
    case 0:
        BR_CODEIN_SOCL_InitDefault(&cb);arg=work->arg;work->fns=cb;
        BR_CODEIN_CallAndClearStepFn(&work->fns,work,arg);*state=1;break;
    case 1:BR_FADE_Start(work->arg->fade,2,3,0);*state=2;break;
    case 2:if(BR_FADE_GetResult(work->arg->fade))*state=3;break;
    case 3:
        MI_CpuFill8(req,0,8);*(u64 *)req=*(u64 *)&work->arg->value1;
        BR_NET_StartRequest(work->arg->net,3,(const union BrNetRequest *)(const int *)req);
        work->frames=0;*state=4;break;
    case 4:
        ++work->frames;
        if(BR_NET_IsIdle(work->arg->net) && work->frames>96) {
            BR_UTIL_StartEffect((void *)(work->introFx), 0, 0);*state=5;
        }break;
    case 5:
        result=BR_NET_PollErrorMessage(work->arg->net,&msg);
        if(result==0) {
            if(BR_NET_GetVideoReply(work->arg->net,&rec,&extra)) {
#ifdef __MWERKS__
                BATTLE_REC_SetData(rec,&rec->head,&rec->body,GAME_DATA_GetSaveControl(work->arg->gameData));
#else
                BATTLE_REC_SetData(rec,&rec->head,&rec->body);
#endif
                found=0;value=BATTLE_REC_GetHeaderParam((const struct BattleRecHeader *)((u8 *)BATTLE_REC_GetHeader()),4,0);
                i=1;arg=work->arg;
                for(;i<=3;i++) {
                    if(arg->rec->header[i]==value) {found=1;break;}
                }
                if(found==1) {BR_UTIL_SetWindowText((char *)(work->textWin),arg->res,316);*state=9;}
                else *state=6;
            } else {BR_UTIL_SetWindowText((char *)(work->textWin),work->arg->res,339);*state=9;}
        } else {BR_UTIL_SetWindowText((char *)(work->textWin),work->arg->res,msg);*state=9;}
        break;
    case 9:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg((u32 *)&x,(u32 *)&y);click.x=x;click.y=y;BR_UTIL_StartEffect((char *)((void *)(work->tapFx)), 1, (const BrPair *)&click);
            GFL_USE_PlaySeDefaultVolume(0x703);*state=10;
        }break;
    case 6:BR_FADE_Start(work->arg->fade,2,3,1);*state=7;break;
    case 7:if(BR_FADE_GetResult(work->arg->fade))*state=8;break;
    case 8:BR_CODEIN_CallAndClearDestroyFn(&work->fns,work,work->arg);BR_UTIL_SetTaskStep(task,BR_CODEIN_MenuStep);break;
    case 10:BR_FADE_Start(work->arg->fade,2,3,1);*state=11;break;
    case 11:if(BR_FADE_GetResult(work->arg->fade))*state=12;break;
    case 12:BR_CODEIN_CallAndClearDestroyFn(&work->fns,work,work->arg);BR_UTIL_ClearTaskStep(task);break;
    }
}

/*
 * lever: function-scope pair locals preserve stack-slot order across switch cases.
 */
void BR_CODEIN_MenuStep(struct BrUtilTask *task,int *state,struct CodeinSoclWork *work) {
    u32 x,y;
    Point first,second;
    struct CodeinStoredFns cb;
    int i;
    switch(*state) {
    case 0: {
        BR_CODEIN_GetMenuCallbacks(&cb);
        work->fns=cb;
        BR_CODEIN_CallAndClearStepFn(&work->fns,work,work->arg);
        *state=1; break;
    }
    case 1: BR_FADE_Start(work->arg->fade,2,3,0); *state=2; break;
    case 2: if(BR_FADE_GetResult(work->arg->fade)) *state=3; break;
    case 3: {
        if(TOUCHPANEL_GetPointTrg(&x,&y)) {
            for(i=0;i<=2;i++) {
                if(BR_BTN_HitTestWithSound(work->button[i],x,y)) {
                    first.x=x; first.y=y;
                    BR_UTIL_StartEffect((char *)((void *)((work->tapFx))), 1, (const BrPair *)&first);
                    work->selectedIndex=i;
                    if(*(int *)((char *)work->arg->rec->present+(u32)i*4+4)) *state=7;
                    else *state=4;
                }
            }
            if(BR_BTN_HitTestWithSound(work->button[3],x,y)) {
                second.x=x; second.y=y;
                BR_UTIL_StartEffect((char *)((void *)((work->tapFx))), 1, (const BrPair *)&second); *state=10;
            }
        }
        break;
    }
    case 4: BR_FADE_Start(work->arg->fade,2,3,1); *state=5; break;
    case 5: if(BR_FADE_GetResult(work->arg->fade)) *state=6; break;
    case 6: BR_CODEIN_CallAndClearDestroyFn(&work->fns,work,work->arg); BR_UTIL_SetTaskStep(work->task,BR_CODEIN_MenuStepSave); break;
    case 7: BR_FADE_Start(work->arg->fade,2,3,1); ++*state; break;
    case 8: if(BR_FADE_GetResult(work->arg->fade)) ++*state; break;
    case 9: BR_CODEIN_CallAndClearDestroyFn(&work->fns,work,work->arg); BR_UTIL_SetTaskStep(work->task,BR_CODEIN_MenuStepInput); break;
    case 10: BR_FADE_Start(work->arg->fade,2,3,1); *state=11; break;
    case 11: if(BR_FADE_GetResult(work->arg->fade)) *state=12; break;
    case 12: BR_CODEIN_CallAndClearDestroyFn(&work->fns,work,work->arg); BR_UTIL_ClearTaskStep(task); break;
    }
}

/*
 * lever: Declare scalar locals before Point; assign the returned Point as a whole to p+0x4C. Separate word stores produced the wrong stack/copy schedule.
 */
void BR_CODEIN_MenuStepInput(struct BrUtilTask *task,unsigned *state,struct CodeinSoclWork *work)
{
    unsigned x,y;
    struct CodeinStoredFns a;
    switch(*state) {
    case 0:
        BR_CODEIN_CopySoclResource(&a);
        work->fns=a;
        BR_CODEIN_CallAndClearStepFn(&work->fns,work,work->arg);
        ++*state; break;
    case 1:
        BR_FADE_Start(work->arg->fade,2,3,0);
        ++*state; break;
    case 2:
        if(BR_FADE_GetResult(work->arg->fade)) ++*state;
        break;
    case 3:
        if(TOUCHPANEL_GetPointTrg(&x,&y)) {
            if(BR_CODEIN_HitTestOptionLeft(work,x,y)) *state=4;
            if(BR_CODEIN_HitTestOptionRight(work,x,y)) *state=7;
        }
        break;
    case 4:
        BR_FADE_Start(work->arg->fade,2,3,1);
        ++*state; break;
    case 5:
        if(BR_FADE_GetResult(work->arg->fade)) ++*state;
        break;
    case 6:
        BR_CODEIN_CallAndClearDestroyFn(&work->fns,work,work->arg);
        BR_UTIL_SetTaskStep(task,BR_CODEIN_MenuStepSave); break;
    case 7:
        BR_FADE_Start(work->arg->fade,2,3,1);
        ++*state; break;
    case 8:
        if(BR_FADE_GetResult(work->arg->fade)) ++*state;
        break;
    case 9:
        BR_CODEIN_CallAndClearDestroyFn(&work->fns,work,work->arg);
        BR_UTIL_SetTaskStep(task,BR_CODEIN_MenuStep); break;
    }
}

/*
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * lever: Write the zero halfwords in source order p+0x40 then p+0x42; the reversed spelling exchanged those two store addresses.
 * blocker-symbols: BattleRecModeTable 0x0209DDCC data a4
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *     int i;
 *     u16 v;
 *     switch(selector) {
 *     case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *     case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *     case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *     case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *     case 4: return *(u64 *)(p+0x38);
 *     case 5: return *(u8 *)(p+0x2a);
 *     case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *     case 7: return *(u8 *)(p+0x2b);
 *     default:return 0;
 *     }
 * }
 */
void BR_CODEIN_MenuStepSave(struct BrUtilTask *task,unsigned *state,struct CodeinSoclWork *work)
{
    Point initial;
    CodeinProfileConfig cfg;
    int x,y;
    Point pair;
    int r;
    switch(*state) {
    case 0:
        if(!work->textWin) work->textWin=BR_UTIL_CreateTextWin(work->arg->res,work->printQue,work->heapId);
        BR_UTIL_SetWindowText((char *)work->textWin,work->arg->res,0x13d);
        initial.x=0x80;initial.y=0x60;
        BR_UTIL_StartEffect((char *)((void *)(work->introFx)), 4, (const BrPair *)&initial);
        BR_FADE_Start(work->arg->fade,2,3,0);++*state;break;
    case 1:if(BR_FADE_GetResult(work->arg->fade)) ++*state;break;
    case 2:
        work->frames=0;
        work->saveStatus[0]=0;work->saveStatus[1]=0;
        ++*state;break;
    case 3:
        r=GDS_RAP_SaveVideoSeq(work->arg->gameData,work->selectedIndex+1,(unsigned char)work->arg->kind,&work->saveStatus[0],&work->saveStatus[1],work->heapId);
        if((unsigned)(r-2)<=1) {
            work->arg->saved=1;
            work->arg->savedSlot=work->selectedIndex+1;
            ++*state;
        }
        ++work->frames;break;
    case 4:
        MI_CpuFill8(&cfg,0,8);
        cfg.wide=BATTLE_REC_GetHeaderParam((const struct BattleRecHeader *)((u8 *)BATTLE_REC_GetHeader()),4,0);
        BR_NET_StartRequest(work->arg->net,8,(const union BrNetRequest *)(const int *)(&cfg));
        BR_UTIL_SetWindowText(work->textWin,work->arg->res,0x13f);
        work->textFrames=0;++work->frames;++*state;break;
    case 5:
        ++work->frames;++work->textFrames;
        if(BR_NET_IsIdle(work->arg->net) && work->frames>0x60 && work->textFrames>0x3c) {
            BR_UTIL_StartEffect((void *)(work->introFx), 0, 0);
            BR_UTIL_SetWindowText(work->textWin,work->arg->res,0x140);
            ++*state;
        }break;
    case 6:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y));pair.x=x;pair.y=y;
            BR_UTIL_StartEffect((char *)((void *)(work->tapFx)), 1, (const BrPair *)&pair);
            GFL_USE_PlaySeDefaultVolume((int)0x703);++*state;
        }break;
    case 7:BR_FADE_Start(work->arg->fade,2,3,1);++*state;break;
    case 8:if(BR_FADE_GetResult(work->arg->fade)) ++*state;break;
    case 9:
        if(work->textWin) {BR_UTIL_DeleteTextWin(work->textWin,work->arg->res);work->textWin=0;}
        BR_UTIL_ClearTaskStep(task);break;
    }
}

void BR_CODEIN_CallAndClearStepFn(struct CodeinStoredFns *holder, struct CodeinSoclWork *work, struct BrProcArgResult *ctx)
{
    if (holder->stepFn != 0) {
        holder->stepFn(work, ctx);
        holder->stepFn = 0;
    }
}

void BR_CODEIN_CallAndClearDestroyFn(struct CodeinStoredFns *holder, struct CodeinSoclWork *work, struct BrProcArgResult *ctx) { CodeinHookFn f;f=holder->destroyFn;if(f){f(work,ctx);holder->destroyFn=0;} }

void BR_CODEIN_CopySoclResource(struct CodeinStoredFns *resource)
{
    *resource=d_021E3910[2];
}

/*
 * lever: Bounded permuter split the scaled index and delayed the base load, then introduced store-address temporaries after the constructor. Fixed one validated its behavior-preserving winning C.
 */
void BR_CODEIN_SoclSetupText(struct CodeinSoclWork *work, struct BrProcArgResult *argRec)
{
  const char *arg = (const char *)argRec;
  void *a;
  void *s;
  void *b;
  void *h;
  void *c;
  int i;
  const unsigned char *r;
  uptr base;
  unsigned index;
  void **textRef;
  void **textPtr;
  char *printQuePtr;
  if (!(work->textWin))
    work->textWin = BR_UTIL_CreateTextWin(argRec->res, work->printQue, work->heapId);
  a = (void *) BR_RES_GetWordSet((struct BrRes *)argRec->res);
  s = MSGDATA_AllocString((struct MsgBank *)BR_RES_GetMsgData((struct BrRes *)argRec->res), 0x141);
  b = STRBUF_Create(0x80, work->heapId);
  index = work->selectedIndex;
  index = index * 4;
  base = (uptr)argRec->rec;
  WORDSET_SetSlotTag(a, 0, (struct Strbuf *)((struct BrProcRecords *)((base + index) + index * (sizeof(void *) / 4 - 1)))->name[1], ((struct BrProcRecords *)(((char *) base) + index))->eggFlag[1], 1, PM_LANG_ID);
  WORDSET_CopyTaggedText(a, b, s);
  BR_UTIL_SetWindowTextBuf(work->textWin, argRec->res, b);
  STRBUF_Delete((struct Strbuf *)b);
  STRBUF_Delete((struct Strbuf *)s);
  BR_RES_LoadBgGraphics(argRec->res, 0x1e, work->heapId);
  h = BR_RES_GetFont((struct BrRes *)argRec->res);
  c = BR_RES_GetMsgData((struct BrRes *)argRec->res);
  for (i = 0; i < 2; i++)
  {
    r = d_021E3928;
    r = r + (i * 8);
    printQuePtr = (char *)&work->printQue;
    ((struct CodeinSoclWork *)((void **)work + i))->text[0] = BR_UTIL_Create(4, r[0], r[1], r[2], r[3], 14, *((void **) printQuePtr), work->heapId);
    textPtr = &((struct CodeinSoclWork *)((void **)work + i))->text[0];
    textRef = textPtr;
    BR_UTIL_SetTextFromMessage(*textRef, (void *)c, *((int *) (r + 4)), (void *)h, 0x3da0);
  }

}

void BR_CODEIN_SoclTeardown(struct CodeinSoclWork *work,struct BrProcArgResult *arg)
{
    int i;
    for (i=0;i<2;i++) {
        if (work->text[i]) {
            BR_UTIL_Delete(work->text[i]);
            work->text[i]=0;
        }
    }
    BG_SYS_PushTile(4);
    BR_RES_ApplyBgSet(arg->res,0x1e);
    if (work->textWin) {
        BR_UTIL_DeleteTextWin(work->textWin,arg->res);
        work->textWin=0;
    }
}
