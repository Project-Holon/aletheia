/*
 * file:     scrcmd_proc_fld.c
 * unit:     yes
 * function: SCRCMD_PROC_FLD_StepShopTask, SCRCMD_PROC_FLD_InitShop, SCRCMD_PROC_FLD_LoadShopMessages, SCRCMD_PROC_FLD_GetShopCurrency, SCRCMD_PROC_FLD_PickQuantityOutcome, SCRCMD_PROC_FLD_PollItemList, SCRCMD_PROC_FLD_PollMessageEnd, SCRCMD_PROC_FLD_PayPrice, SCRCMD_PROC_FLD_StepShop, SCRCMD_PROC_FLD_LoadItemRows, SCRCMD_PROC_FLD_SetItemSlot, SCRCMD_PROC_FLD_BuildItemListByBadges, SCRCMD_PROC_FLD_BuildItemListFixed, SCRCMD_PROC_FLD_BuildItemListFromRange, SCRCMD_PROC_FLD_FreeItemSlots, SCRCMD_PROC_FLD_AllocShopResources, SCRCMD_PROC_FLD_FreeShopResources, SCRCMD_PROC_FLD_InitShopGraphics, SCRCMD_PROC_FLD_ExitShopGraphics, SCRCMD_PROC_FLD_LoadCursorResources, SCRCMD_PROC_FLD_LoadIconResources, SCRCMD_PROC_FLD_UpdateItemIcon, SCRCMD_PROC_FLD_CreateShopActors, SCRCMD_PROC_FLD_InitShopCells, SCRCMD_PROC_FLD_FreeShopCells, SCRCMD_PROC_FLD_InitShopWindows, SCRCMD_PROC_FLD_FreeShopWindows, SCRCMD_PROC_FLD_PrintMoneyWindow, SCRCMD_PROC_FLD_PrintOwnedWindow, SCRCMD_PROC_FLD_PrintItemDescription, SCRCMD_PROC_FLD_PrintQuantityWindow, SCRCMD_PROC_FLD_CreateItemListMenu, SCRCMD_PROC_FLD_PrintListText, SCRCMD_PROC_FLD_PrintPriceEntry, SCRCMD_PROC_FLD_PrintUniqueItemEntry, SCRCMD_PROC_FLD_OnListCursorMove, SCRCMD_PROC_FLD_FreeItemListMenu, SCRCMD_PROC_FLD_ReturnZero, SCRCMD_PROC_FLD_ShowItemMessage, SCRCMD_PROC_FLD_ShowConfirmMessage, SCRCMD_PROC_FLD_PrepareMessageWindow, SCRCMD_PROC_FLD_ShowMessage, SCRCMD_PROC_FLD_ShowBuyConfirm, SCRCMD_PROC_FLD_ShowTmBuyConfirm, SCRCMD_PROC_FLD_AdjustQuantity, SCRCMD_PROC_FLD_StepQuantitySelect, SCRCMD_PROC_FLD_SetQuantityMask, SCRCMD_PROC_FLD_StoreCommKind, SCRCMD_PROC_FLD_StoreWifiProfileValid, SCRCMD_PROC_FLD_StoreWifiFriendCount, SCRCMD_PROC_FLD_CallWifiClubEvent, SCRCMD_PROC_FLD_CallWorldTradeEvent, SCRCMD_PROC_FLD_CallGtsNegoEvent, SCRCMD_PROC_FLD_FinishOv170Event, SCRCMD_PROC_FLD_CallOv170Event, SCRCMD_PROC_FLD_StartNameInMode5, SCRCMD_PROC_FLD_StartNameInMode6, SCRCMD_PROC_FLD_SetGameClearEventAndEnd, SCRCMD_PROC_FLD_ObtainCGearAndCallCommResetEvent, SCRCMD_PROC_FLD_CallOv219Event, SCRCMD_PROC_FLD_CallShortcutEvent, SCRCMD_PROC_FLD_CallGameManual, SCRCMD_PROC_FLD_StartScriptedWildBattle, SCRCMD_PROC_FLD_StartFieldMapFadeIn, SCRCMD_PROC_FLD_StoreBattleResult, SCRCMD_PROC_FLD_CallCatchTutorial, SCRCMD_PROC_FLD_StoreEffectEncountItemId, SCRCMD_PROC_FLD_SpawnMovePokemonIfInactive, SCRCMD_PROC_FLD_AddUniqueU16
 * address:  0x021B3158
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from scrcmd_proc_fld.c by tools/splitfile.py.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetUserWorkPtr  0x02158FB4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   SCRCMD_SHOP_PrepareFieldCamera  0x021B30C8  thumb  ov021
 *   FIELD_CAMERA_IsMoving  0x0218FE50  thumb  ov021
 *   FIELD_MSGBG_SetBlendThunk  0x02193060  thumb  ov021
 *   FIELD_CAMERA_StartMoveToSaved  0x0218F9C4  thumb  ov021
 *   FIELD_CAMERA_ResumeTargetTrace  0x0218EC60  thumb  ov021
 *   FIELD_CAMERA_SetAreasEnabled  0x0218F1AC  thumb  ov021
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb  ov021
 *   FIELD_CAMERA_PopState  0x0218F878  thumb  ov021
 *   GFL_HEAP_Free  0x020307B0  arm
 *   d_021D9738     0x021D9738  data   ov021  a4
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   MISC_CountBadges 0x0200C258 thumb
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   MISC_GetMoney  0x0200C274  thumb
 *   BSUBWAY_SCOREDATA_GetBattlePoints  0x0200DABC  thumb
 *   MYITEM_SAVEDATA_GetItemQuantity  0x02007FB8  thumb
 *   MYITEM_SAVEDATA_CanAddItem  0x02007E3C  thumb
 *   MYITEM_SAVEDATA_GetMaxStack  0x0200823C  thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BMP_MENULIST_Main 0x020200CC thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   KEY_GetCont 0x0203630C arm
 *   KEY_GetTrg 0x020362DC arm
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   RECORD_AddCounter  0x02008DAC  thumb
 *   RECORD_AddOne  0x02008DF0  thumb
 *   MISC_SubMoney  0x0200C29C  thumb
 *   BSUBWAY_SCOREDATA_SubBattlePoints  0x0200DA98  thumb
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   BMP_MENULIST_Redraw  0x02020234  thumb
 *   BMP_MENU_CreateYesNo  0x0201FDA0  thumb
 *   BMP_MENU_ProcessYesNo  0x0201FEBC  thumb
 *   MYITEM_SAVEDATA_AddItem  0x02007E50  thumb
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   TCBL_Main  0x020310C4  arm
 *   d_021D9440     0x021D9440  data   ov021  a4
 *   FILE_UTIL_IsMachineItem  0x02021288  thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   FILE_UTIL_GetMachineMove 0x020212B0 thumb
 *   WORDSET_SetSlotFromMsgCB 0x0201EF34 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   BMP_MENUWORK_AddStrItem 0x0201F898 thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   FILE_UTIL_GetItemParam 0x02020FE4 thumb
 *   GPOWER_ApplyShopPrice 0x0201102C thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   d_021D946C 0x021D946C data
 *   d_021D95DE 0x021D95DE data
 *   d_021DE1A8 0x021DE1A8 data
 *   d_021DE164     0x021DE164  data  a4
 *   d_021D9430     0x021D9430  data  a1
 *   FIELD_WFBC_DATA_LOCAL_FillPeopleListEntries 0x02186670 thumb ov020
 *   BMP_MENUWORK_Delete  0x0201F868  thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   TCBL_Create 0x0203101C arm
 *   TCBL_Destroy 0x02031140 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_SetPriority 0x0204047C arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   FILE_UTIL_Get 0x02020E60 thumb
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   ARC_UTIL_LoadScreenDataFromHandle 0x02049E74 arm
 *   CLACT_TransferPalette 0x0204ADEC arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   d_021D96E0     0x021D96E0  data   ov021  a2
 *   d_021D96E8     0x021D96E8  data   ov021  a2
 *   d_021D96F0     0x021D96F0  data   ov021  a2
 *   d_021D96F8     0x021D96F8  data   ov021  a2
 *   d_021D9700     0x021D9700  data   ov021  a2
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDrawEnable  0x0204B22C  arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   d_021DE18C    0x021DE18C data ov021 a4
 *   d_021DE170    0x021DE170 data ov021 a4
 *   BMP_WIN_Create 0x020450F0 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   d_021D945C    0x021D945C data a4
 *   BMP_MENUWORK_CountItems 0x0201F91C thumb
 *   BMP_MENULIST_Create 0x0201FF30 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   BMP_MENULIST_GetUserData 0x02020D0C thumb
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   BMP_GetWidth 0x020437DC arm
 *   MYITEM_SAVEDATA_HasItem 0x02007F68 thumb
 *   BMP_MENULIST_GetPos 0x020202FC thumb
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   BMP_MENULIST_Delete  0x0202020C  thumb
 *   WORDSET_SetSlotFromBank  0x0201EF6C  thumb
 *   WORDSET_SetSlotFromMsg37  0x0201F14C  thumb
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   PRINTSYS_PrintStreamCallBack  0x0201CD10  thumb
 *   KEY_GetRepeat 0x0203633C arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   d_021D9654     0x021D9654  data  a4
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FIELDMAP_GetCommKind  0x021896F4  thumb  ov021
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetWifiList  0x0201283C  thumb
 *   WIFILIST_IsProfileValid  0x02009CE4  thumb
 *   WIFILIST_CountFriends  0x02009A34  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   abs_id_6       0x00000006  data
 *   EVENT_WIFICLUB_Entry  0x02154C20  thumb  ov006
 *   abs_id_4       0x00000004  data
 *   EVENT_WORLDTRADE_Entry  0x021542C0  thumb  ov004
 *   abs_id_01        0x00000001  data
 *   EVENT_GTSNEGO_Entry  0x02154694  thumb  ov001
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   BATTLE_BOX_GetFromSave  0x0200BAC8  thumb
 *   BATTLE_BOX_StoreParty  0x0200BB58  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb
 *   SYSTEM_DATA_GetConfig  0x0200873C  thumb
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   BATTLE_BOX_CreateParty  0x0200BAF4  thumb
 *   BATTLE_BOX_IsLocked  0x0200BBFC  thumb
 *   FIELD_STATUS_CreateSubProcNoFadeCallbackEvent  0x02014840  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   d_021DE220     0x021DE220  data  a1
 *   ov170_id       0x000000AA  data  a1
 *   d_021EF78C     0x021EF78C  data  ov170  a4
 *   EVENT_NAMEIN_Create  0x021CD2A4  thumb  ov021
 *   VM_End  0x02011290  thumb
 *   SCRIPT_SYS_SetNextEventFromWork  0x0215898C  thumb  ov010
 *   EVENT_GAMECLEAR_Create  0x0215F8A8  thumb  ov010
 *   BLOCK20_SAVEDATA_GetBlock  0x02009210  thumb
 *   CGEAR_SAVE_SetObtained  0x020090D8  thumb
 *   FLD_BTL_INST_TOOL_CreateCommResetEvent  0x02168BBC  thumb  ov010
 *   FIELD_STATUS_CreateSubProcEvent  0x020146F8  thumb
 *   abs_id_DB      0x000000DB  data
 *   d_02185F0C     0x02185F0C  data  ov219  a4
 *   SCRCMD_CreateSubProcEvent  0x021C5BD0  thumb  ov021
 *   EVENT_GAME_MANUAL_Create  0x021D30B8  thumb  ov021
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   FIELD_ENCOUNT_StartScriptedWild  0x021AA0A0  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   GAME_DATA_GetLastBattleResult  0x02012A44  thumb
 *   EVENT_BATTLE_GetResultFlag  0x0216EFCC  thumb  ov010
 *   EVENT_BATTLE_CreateCatchTutorial  0x0216E95C  thumb  ov010
 *   EFFECT_ENCOUNT_GetItemId  0x021AAB48  thumb  ov021
 *   MOVE_POKEMON_SAVE_GetBlock  0x0200D418  thumb
 *   MOVE_POKEMON_SAVE_IsEntryActive  0x0200D488  thumb
 *   MOVE_POKEMON_SpawnEntry  0x0215E440  thumb  ov010
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "scrcmd_proc_fld_types.h"
#include "scrcmd_proc_fld_shared_types.h"

struct MsgBank;

struct Blk1AC;

struct Blk34;

struct Cfg;

struct Descriptor;

struct PrintSys;

struct Rec;

struct Rec3;

struct Sub02008C20Obj;

struct Tcbl;

struct WordSet;

struct Slot;

struct U16Vec;

struct S02031140;

struct Sub0204A9D0;

struct Unit;

struct CharBuf;

struct Src;

struct Bmp;

struct StrObj;

struct Vec2;

struct Sub020097BCObj;

struct Pair;

struct Big;

struct Blk37;

struct Sub02008700Obj;

struct Sub020090B0Obj;

struct Sub02009210Obj;

struct Blk38;

/* Argument block of the field events that take the field map (ov006 / ov004 callbacks). */
typedef struct FieldEventArgs {
    void *fieldMap;
    u32 reserved;
} FieldEventArgs;

/* 0x2C-byte work block built here and handed to the ov170 process. */
typedef struct Ov170EventWork {
    void *gameData;         /* 0x00 */
    u32 boxManager;         /* 0x04 */
    void *party;            /* 0x08: replaced by a heap copy when kind is 4 */
    u32 myItem;             /* 0x0c */
    u8 *myStatus;           /* 0x10 */
    u32 extraData;          /* 0x14: heap block only when kind is 4 */
    u32 saveStateA;         /* 0x18 */
    u32 saveStateB;         /* 0x1c */
    u32 reserved20;         /* 0x20 */
    u32 kind;               /* 0x24: hand-off kind, 4 copies the party */
    u16 result;             /* 0x28: written by the ov170 process, 1 means success */
    u16 reserved2A;         /* 0x2a */
} Ov170EventWork;

/* 0xc-byte record passed alongside it. */
typedef struct Ov170EventHandoff {
    void *gameData;                 /* 0x00 */
    unsigned short *resultVar;      /* 0x04: script variable that receives the flag */
    Ov170EventWork *work;           /* 0x08 */
} Ov170EventHandoff;
struct ScrcmdWork;
struct ScriptWork;

#include "../ov010/scrcmd_work.h"

#include "../arm9/gamesystem.h"
#include "../ov010/script_sys.h"
#include "../ov010/script_work.h"
#include "fieldmap.h"
struct GameSystem;


struct FieldMap;
struct FieldCamera;


#include "field_camera.h"

struct ShopTask;

#include "scrcmd_shop.h"


#include "field_msgbg.h"
struct FieldCameraMoveChannels;






#include "../arm9/gfl_heap_wrap.h"
struct GameData;

struct GameData;
struct MyStatus;

#include "../arm9/game_data.h"

struct MiscSave;

#include "../arm9/beacon.h"
struct Strbuf;

#include "../arm9/msgdata.h"

struct BsubwayScoreData;

#include "../arm9/gds_profile.h"
struct MyItem;

#include "../arm9/myitem_savedata.h"


struct PrintQueue;

#include "../arm9/printsys.h"
struct BmpWin;

#include "../arm9/bmp_win.h"



#include "../arm9/bg_sys.h"
struct BmpMenuList;

#include "../arm9/bmp_menulist.h"
struct TextPrinter;




#include "../arm9/key.h"



#include "../arm9/gfl_use.h"



#include "../arm9/record.h"

struct ClactActor;

#include "../arm9/clact.h"



#include "../arm9/bmp_menu.h"





struct TcblSystem;

#include "../arm9/tcbl.h"

/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define FILE_UTIL_GetMachineMove FILE_UTIL_GetMachineMove_header
#endif
#include "../arm9/file_util.h"
#ifdef __MWERKS__
#undef FILE_UTIL_GetMachineMove
extern int FILE_UTIL_GetMachineMove(u32);
#endif

#include "../arm9/wordset.h"




#include "../arm9/bmp_menuwork.h"





#include "../arm9/gpower.h"

struct WfbcListEntry;
struct WfbcData;

#include "../ov020/field_wfbc_data_local.h"


#include "../arm9/gf_font.h"

#include "../arm9/strbuf.h"





#include "../arm9/arc_tool.h"

#include "../arm9/arc_util.h"













struct PaletteData;










struct GfFont;






typedef short s16_p07;
#include "../arm9/bmp.h"


struct MenuTemplate;












#include "../arm9/msg_speed.h"



struct ScriptVm;

#include "../ov010/script_work_cmd.h"
struct GameComm;


struct WifiList;

#include "../arm9/wifilist.h"
struct FieldState;




struct GameEvent;

extern struct GameEvent *GAME_EVENT_CreateOverlayEvent(struct GameSystem *gameSystem, unsigned int overlayId, u32 (*fn)(void *, u32), void *arg);

#include "../ov006/event_wificlub.h"

#include "../ov004/event_worldtrade.h"

#include "../ov001/event_gtsnego.h"
struct SaveControl;

struct BattleBoxSave;

#include "../arm9/battle_box.h"
struct Party;
struct BoxMonGroup;



#include "../arm9/zukan_save.h"
struct ZukanSave;


#include "../arm9/system_data.h"






#include "../arm9/field_status.h"


#include "event_namein.h"

#include "../ov010/event_gameclear.h"


#include "../arm9/vm.h"
struct CgearSaveBlock;

#include "../arm9/block20_savedata.h"
struct CGearSave;

#include "../arm9/cgear_save.h"

#include "../ov010/fld_btl_inst_tool.h"


#include "scrcmd_sub_proc_events.h"

#include "event_game_manual.h"

struct ScriptFieldParam;

struct FieldEncount;


/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define FIELD_ENCOUNT_StartScriptedWild FIELD_ENCOUNT_StartScriptedWild_header
#endif
#include "field_encount.h"
#ifdef __MWERKS__
#undef FIELD_ENCOUNT_StartScriptedWild
extern struct GameEvent *FIELD_ENCOUNT_StartScriptedWild(FieldEncount *, u32, u32, u32);
#endif

#include "event_fieldmap_control.h"


#include "../ov010/event_battle.h"


#include "effect_encount.h"

#include "../arm9/move_pokemon_save.h"
struct MovePokemonSave;


#include "../ov010/move_pokemon.h"

int SCRCMD_PROC_FLD_StepShopTask(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

void SCRCMD_PROC_FLD_InitShop(struct GameSystem *gameSystem, ShopWork *shop, int shopKind, int shopVariant);

void SCRCMD_PROC_FLD_LoadShopMessages(ShopWork *w, int b);

u32 SCRCMD_PROC_FLD_GetShopCurrency(ShopWork *w);

void SCRCMD_PROC_FLD_PickQuantityOutcome(ShopWork *w);

void SCRCMD_PROC_FLD_PollItemList(ShopWork *p);

u8 SCRCMD_PROC_FLD_PollMessageEnd(ShopWork *p);

void SCRCMD_PROC_FLD_PayPrice(ShopWork *w, u32 b);

int SCRCMD_PROC_FLD_StepShop(struct GameSystem *gameSystem, ShopWork *shop, u32 shopKind, u8 shopVariant);

u32 SCRCMD_PROC_FLD_LoadItemRows(ShopItem *items, int n);

void SCRCMD_PROC_FLD_SetItemSlot(ShopWork *shop, int slotIndex, int isTmShop, int itemId, struct MsgBank *msgBank);

void SCRCMD_PROC_FLD_BuildItemListByBadges(ShopWork *p, int a, int b, int c);

void SCRCMD_PROC_FLD_BuildItemListFixed(ShopWork *p, int idx);

void SCRCMD_PROC_FLD_BuildItemListFromRange(ShopWork *p, int i);

void SCRCMD_PROC_FLD_FreeItemSlots(ShopWork *w);

int SCRCMD_PROC_FLD_AllocShopResources(ShopWork *p, int a);

void SCRCMD_PROC_FLD_FreeShopResources(ShopWork *p);

void SCRCMD_PROC_FLD_InitShopGraphics(ShopWork *p);

void SCRCMD_PROC_FLD_ExitShopGraphics(ShopWork *w);

void SCRCMD_PROC_FLD_LoadCursorResources(ShopWork *p);

void SCRCMD_PROC_FLD_LoadIconResources(ShopWork *w);

void SCRCMD_PROC_FLD_UpdateItemIcon(ShopWork *w, u32 b);

void SCRCMD_PROC_FLD_CreateShopActors(ShopWork *w);

void SCRCMD_PROC_FLD_InitShopCells(ShopWork *w);

void SCRCMD_PROC_FLD_FreeShopCells(ShopWork *w);

void SCRCMD_PROC_FLD_InitShopWindows(ShopWork *w);

void SCRCMD_PROC_FLD_FreeShopWindows(ShopWork *w);

void SCRCMD_PROC_FLD_PrintMoneyWindow(ShopWork *w);

void SCRCMD_PROC_FLD_PrintOwnedWindow(ShopWork *w, u16 b);

void SCRCMD_PROC_FLD_PrintItemDescription(ShopWork *w, u32 b);

void SCRCMD_PROC_FLD_PrintQuantityWindow(ShopWork *w, u32 a, u32 b);

void SCRCMD_PROC_FLD_CreateItemListMenu(ShopWork *w);

void SCRCMD_PROC_FLD_PrintListText(struct PrintQueue *printSys, struct Bmp *bitmap, int x, int y, struct Strbuf *text, struct GfFont *fontInfo, u16 colorBits);

void SCRCMD_PROC_FLD_PrintPriceEntry(struct BmpMenuList *listMenu, int row, u8 y);

void SCRCMD_PROC_FLD_PrintUniqueItemEntry(struct BmpMenuList *listMenu, int row, u8 y);

void SCRCMD_PROC_FLD_OnListCursorMove(struct BmpMenuList *listMenu, u32 row);

void SCRCMD_PROC_FLD_FreeItemListMenu(ShopWork *w);

int SCRCMD_PROC_FLD_ReturnZero(void);

void SCRCMD_PROC_FLD_ShowItemMessage(ShopWork *p, u32 sel, u32 c, u32 d);

void SCRCMD_PROC_FLD_ShowConfirmMessage(ShopWork *w, u32 a);

void SCRCMD_PROC_FLD_PrepareMessageWindow(struct BmpWin *window);

void SCRCMD_PROC_FLD_ShowMessage(ShopWork *w, u32 b);

void SCRCMD_PROC_FLD_ShowBuyConfirm(ShopWork *w, u32 a, u16 b, u32 c, u16 d);

void SCRCMD_PROC_FLD_ShowTmBuyConfirm(ShopWork *w, u32 a, u32 b, u32 c);

int SCRCMD_PROC_FLD_AdjustQuantity(s16 *p, int max, int key);

int SCRCMD_PROC_FLD_StepQuantitySelect(ShopWork *w);

void SCRCMD_PROC_FLD_SetQuantityMask(int i);

int SCRCMD_PROC_FLD_StoreCommKind(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_StoreWifiProfileValid(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_StoreWifiFriendCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_CallWifiClubEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_CallWorldTradeEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_CallGtsNegoEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

void SCRCMD_PROC_FLD_FinishOv170Event(void *arg);

int SCRCMD_PROC_FLD_CallOv170Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_StartNameInMode5(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_StartNameInMode6(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_SetGameClearEventAndEnd(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_ObtainCGearAndCallCommResetEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_CallOv219Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_CallShortcutEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_CallGameManual(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_StartScriptedWildBattle(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_StartFieldMapFadeIn(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_StoreBattleResult(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_CallCatchTutorial(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_StoreEffectEncountItemId(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_PROC_FLD_SpawnMovePokemonIfInactive(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

u16 SCRCMD_PROC_FLD_AddUniqueU16(u16 *values, u16 count, u16 value);

extern const LayerFlags d_021D9738;

extern const struct WinDat d_021D9440;

extern u8 d_021D946C[];

extern u8 d_021D95DE[];

extern u16 *d_021DE1A8[];

extern ShopItem *d_021DE164[];

extern u8 d_021D9430[];

extern const struct ActorInitParam d_021D96E0;

extern const struct ActorInitParam d_021D96E8;

extern const struct ActorInitParam d_021D96F0;

extern const struct ActorInitParam d_021D96F8;

extern const struct ActorInitParam d_021D9700;

extern ShopWindowTemplate *d_021DE18C[];

extern ShopWindowTemplate *d_021DE170[];

extern u32 d_021D945C[];

extern const ShopMaskRect d_021D9654[];

extern u8 abs_id_6[];

extern u8 abs_id_4[];

extern u8 abs_id_01[];

extern const char d_021DE220[];

extern char ov170_id[];

extern const u8 d_021EF78C[];

extern u8 abs_id_DB[];

extern u8 d_02185F0C[];

/*
 * Task callback armed by SCRCMD_SHOP_StartShop; steps the 0x214-byte work block it
 * allocated.
 *
 * Addresses are Black-image addresses.
 */
int SCRCMD_PROC_FLD_StepShopTask(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    ShopTask **slot;
    ShopTask *task;
    void *gameSystem;
    void *fieldMap;
    void *fieldRegion;
    LayerFlags layers;

    slot = SCRIPT_WORK_GetUserWorkPtr(SCRCMD_WORK_GetScriptWork(cmdWork));
    task = *slot;
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    fieldMap = GAMESYSTEM_GetFieldMap((void *)gameSystem);
    fieldRegion = FIELDMAP_GetCamera(fieldMap);
    switch (task->state) {
    case 0:
        FIELD_CAMERA_EndDelay(fieldRegion);
        task->state++;
        break;
    case 1:
        if (FIELD_CAMERA_IsDelayEnabled(fieldRegion) == 0) {
            task->state++;
        }
        break;
    case 2:
        SCRCMD_SHOP_PrepareFieldCamera((struct ShopTask *)task, fieldMap, fieldRegion);
        task->state++;
        break;
    case 3:
        if (FIELD_CAMERA_IsMoving(fieldRegion) == 0) {
            task->state++;
            task->shop.state = 0;
            FIELD_MSGBG_SetBlendThunk(0);
        }
        break;
    case 4:
        if (SCRCMD_PROC_FLD_StepShop(gameSystem, &task->shop, task->shopKind, task->shopVariant)) {
            task->state++;
        }
        break;
    case 5:
        layers = d_021D9738;
        FIELD_CAMERA_StartMoveToSaved(fieldRegion, (struct FieldCameraMoveChannels *)(&layers), 8);
        task->state++;
        task->subState = 0;
        break;
    case 6:
        if (FIELD_CAMERA_IsMoving(fieldRegion) == 0) {
            FIELD_CAMERA_ResumeTargetTrace(fieldRegion);
            FIELD_CAMERA_SetAreasEnabled(fieldRegion, task->fieldRegionArg);
            FIELD_CAMERA_RestartDelay(fieldRegion);
            FIELD_CAMERA_PopState(fieldRegion);
            FIELD_MSGBG_SetBlendThunk(1);
            task->state++;
        }
        break;
    case 7:
        GFL_HEAP_Free(*slot);
        return 1;
    }
    return 0;
}

void SCRCMD_PROC_FLD_InitShop(struct GameSystem *gameSystem, ShopWork *shop, int shopKind, int shopVariant)
{
    void *gameData = GAMESYSTEM_GetGameData(gameSystem);
    int tableKind;

    GAME_DATA_GetMyStatus(gameData);
    shop->isTmShop = 0;
    shopKind = SCRCMD_PROC_FLD_AllocShopResources(shop, shopKind);
    tableKind = shopKind;
    switch (tableKind) {
    case 255:
        SCRCMD_PROC_FLD_BuildItemListByBadges(shop, tableKind, shopVariant, MISC_CountBadges(GAME_DATA_GetMiscSave(gameData)));
        break;
    case 254:
        SCRCMD_PROC_FLD_BuildItemListFixed(shop, 0);
        shop->usesBattlePoints = 1;
        break;
    case 253:
        shop->usesBattlePoints = 1;
        shop->isTmShop = 1;
        SCRCMD_PROC_FLD_BuildItemListFixed(shop, 1);
        break;
    case 247:
    case 248:
    case 249:
    case 250:
    case 251:
        SCRCMD_PROC_FLD_BuildItemListFromRange(shop, tableKind);
        break;
    default:
        SCRCMD_PROC_FLD_BuildItemListByBadges(shop, tableKind, shopVariant, 0);
        break;
    }
    SCRCMD_PROC_FLD_LoadShopMessages(shop, shop->usesBattlePoints);
    SCRCMD_PROC_FLD_InitShopGraphics(shop);
    SCRCMD_PROC_FLD_InitShopWindows(shop);
    SCRCMD_PROC_FLD_InitShopCells(shop);
    SCRCMD_PROC_FLD_PrintMoneyWindow(shop);
    SCRCMD_PROC_FLD_CreateItemListMenu(shop);
}

void SCRCMD_PROC_FLD_LoadShopMessages(ShopWork *shop, int usesBattlePoints)
{
    if (usesBattlePoints == 1) {
        shop->priceFormat = MSGDATA_AllocString((struct MsgBank *)(shop->shopMsgBank), 0xd);
    } else {
        shop->priceFormat = MSGDATA_AllocString((struct MsgBank *)(shop->shopMsgBank), 0xc);
    }
    shop->soldOutText = MSGDATA_AllocString((struct MsgBank *)(shop->shopMsgBank), 0xe);
}

u32 SCRCMD_PROC_FLD_GetShopCurrency(ShopWork *shop)
{
    if (shop->usesBattlePoints == 0) {
        return MISC_GetMoney(shop->moneyData);
    } else {
        return BSUBWAY_SCOREDATA_GetBattlePoints(shop->battlePointData);
    }
}

void SCRCMD_PROC_FLD_PickQuantityOutcome(ShopWork *shop)
{
    u32 money;
    u32 ownedCount;
    u32 price;

    money = SCRCMD_PROC_FLD_GetShopCurrency(shop);
    ownedCount = MYITEM_SAVEDATA_GetItemQuantity(shop->bagData, shop->itemId, shop->heapId);
    if (MYITEM_SAVEDATA_CanAddItem(shop->bagData, shop->itemId, 1, shop->heapId) == 0) {
        SCRCMD_PROC_FLD_ShowItemMessage(shop, 10, shop->itemId, 0);
        shop->state = SHOP_STATE_MESSAGE_WAIT;
        shop->nextState = SHOP_STATE_LIST_RESUME;
        return;
    }
    price = shop->price;
    if (money < price) {
        if (shop->usesBattlePoints == 0) {
            SCRCMD_PROC_FLD_ShowItemMessage(shop, 3, shop->itemId, 0);
        } else {
            SCRCMD_PROC_FLD_ShowItemMessage(shop, 0x10, shop->itemId, 0);
        }
        shop->state = SHOP_STATE_MESSAGE_WAIT;
        shop->nextState = SHOP_STATE_LIST_RESUME;
    } else if (money >= price && money < price * 2) {
        SCRCMD_PROC_FLD_ShowConfirmMessage(shop, shop->isTmShop);
        shop->state = SHOP_STATE_MESSAGE_WAIT;
        shop->nextState = SHOP_STATE_YESNO_OPEN;
    } else if (shop->isTmShop == 0) {
        SCRCMD_PROC_FLD_ShowItemMessage(shop, 4, shop->itemId, 0);
        shop->state = SHOP_STATE_MESSAGE_WAIT;
        shop->nextState = SHOP_STATE_QUANTITY_ENTER;
        shop->maxQuantity = money / shop->price;
        if (shop->maxQuantity > 99) {
            shop->maxQuantity = 99;
        }
        if (shop->maxQuantity + ownedCount > MYITEM_SAVEDATA_GetMaxStack(shop->itemId)) {
            shop->maxQuantity = MYITEM_SAVEDATA_GetMaxStack(shop->itemId) - ownedCount;
        }
    } else {
        SCRCMD_PROC_FLD_ShowConfirmMessage(shop, shop->isTmShop);
        shop->state = SHOP_STATE_MESSAGE_WAIT;
        shop->nextState = SHOP_STATE_YESNO_OPEN_NOICON;
    }
}

void SCRCMD_PROC_FLD_PollItemList(ShopWork *shop)
{
    struct BmpWin *window;
    int selection;
    ShopWork *row;

    if (PRINTSYS_QUE_IsFinished(shop->printSys) == 0) {
        return;
    }
    if (shop->introShown == 0) {
        window = shop->windows[SHOP_WIN_LIST];
        BMP_WIN_TransferChars(window);
        BMP_WIN_MakeScreen(window);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
        shop->introShown = shop->introShown + 1;
    }
    selection = BMP_MENULIST_Main(shop->listMenu);
    if (selection == -1) {
        return;
    }
    if (selection == -2) {
        shop->state = SHOP_STATE_EXIT;
        return;
    }
    /* stand-in: the row is reached as base + selection * 8 plus the field offset */
    row = (ShopWork *)((char *)shop + selection * 8);
    shop->itemId = row->items[0].itemId;
    shop->price = row->items[0].price;
    shop->quantity = 1;
    SCRCMD_PROC_FLD_PickQuantityOutcome(shop);
}

u8 SCRCMD_PROC_FLD_PollMessageEnd(ShopWork *shop)
{
    int printState = PRINTSYS_PrintStreamGetState(shop->messagePrinter);

    if (printState == 2) {
        PRINTSYS_PrintStreamDelete(shop->messagePrinter);
        return shop->nextState;
    }
    if (printState == 0) {
        if ((KEY_GetCont() & 1) || (KEY_GetCont() & 2)) {
            PRINTSYS_PrintStreamShortWait(shop->messagePrinter, 0);
        }
    } else if (printState == 1) {
        if ((KEY_GetTrg() & 1) || (KEY_GetTrg() & 2)) {
            PRINTSYS_PrintStreamReleasePause(shop->messagePrinter);
            GFL_USE_PlaySeDefaultVolume(1351);
        }
    }
    return shop->state;
}

void SCRCMD_PROC_FLD_PayPrice(ShopWork *shop, u32 cost)
{
    if (shop->usesBattlePoints == 0) {
        MISC_SubMoney(shop->moneyData, cost);
        RECORD_AddCounter(shop->recordData, 0x16, cost);
    } else {
        BSUBWAY_SCOREDATA_SubBattlePoints(shop->battlePointData, cost);
        RECORD_AddCounter(shop->recordData, 0x22, cost);
    }
    RECORD_AddOne(shop->recordData, 0x15);
}

/*
 * Addresses are Black-image addresses.
 */
int SCRCMD_PROC_FLD_StepShop(struct GameSystem *gameSystem, ShopWork *shop, u32 shopKind, u8 shopVariant)
{
    int selection;
    void *printSys;

    switch (shop->state) {
    case SHOP_STATE_INIT:
        SCRCMD_PROC_FLD_InitShop(gameSystem, shop, shopKind, shopVariant);
        (shop->state)++;
        break;
    case SHOP_STATE_LIST_POLL:
        SCRCMD_PROC_FLD_PollItemList(shop);
        break;
    case SHOP_STATE_QUANTITY_ENTER:
        SCRCMD_PROC_FLD_PrintOwnedWindow(shop, shop->itemId);
        SCRCMD_PROC_FLD_PrintQuantityWindow(shop, shop->quantity, shop->price);
        CLACT_SetActorDrawEnable((struct ClactActor *)shop->quantityArrowActor, 1);
        shop->state = SHOP_STATE_QUANTITY_STEP;
        break;
    case SHOP_STATE_QUANTITY_STEP:
        shop->state = SCRCMD_PROC_FLD_StepQuantitySelect(shop);
        break;
    case SHOP_STATE_LIST_RESUME:
        SCRCMD_PROC_FLD_SetQuantityMask(0);
        BMP_WIN_MakeScreen(shop->windows[SHOP_WIN_LIST]);
        BMP_WIN_MakeScreen(shop->windows[SHOP_WIN_DESCRIPTION]);
        BG_SYS_MarkTileDirty(1);
        CLACT_SetActorDrawEnable((struct ClactActor *)shop->quantityArrowActor, 0);
        BMP_MENULIST_Redraw((struct BmpMenuList *)(shop->listMenu));
        shop->state = SHOP_STATE_LIST_POLL;
        break;
    case SHOP_STATE_YESNO_OPEN:
        SCRCMD_PROC_FLD_SetQuantityMask(1);
        BMP_WIN_MakeScreen(shop->windows[SHOP_WIN_LIST]);
        CLACT_SetActorDrawEnable((struct ClactActor *)shop->quantityArrowActor, 0);
        shop->yesNoMenu = BMP_MENU_CreateYesNo(&d_021D9440, 1, 9, 0, shop->heapId);
        if (shop->isTmShop != 1) {
            SCRCMD_PROC_FLD_PrintOwnedWindow(shop, shop->itemId);
        }
        shop->state = SHOP_STATE_YESNO_POLL;
        break;
    case SHOP_STATE_YESNO_OPEN_NOICON:
        SCRCMD_PROC_FLD_SetQuantityMask(1);
        BMP_WIN_MakeScreen(shop->windows[SHOP_WIN_LIST]);
        CLACT_SetActorDrawEnable((struct ClactActor *)shop->quantityArrowActor, 0);
        shop->yesNoMenu = BMP_MENU_CreateYesNo(&d_021D9440, 1, 9, 0, shop->heapId);
        shop->state = SHOP_STATE_YESNO_POLL;
        break;
    case SHOP_STATE_YESNO_POLL:
        selection = BMP_MENU_ProcessYesNo(shop->yesNoMenu);
        if (selection == -1) {
        } else if (selection == 0) {
            shop->state = SHOP_STATE_PURCHASE;
            SCRCMD_PROC_FLD_SetQuantityMask(1);
            BMP_MENULIST_Redraw((struct BmpMenuList *)(shop->listMenu));
            BMP_WIN_MakeScreen(shop->windows[SHOP_WIN_LIST]);
            BG_SYS_MarkTileDirty(1);
        } else if (selection == -2) {
            shop->state = SHOP_STATE_LIST_RESUME;
        }
        break;
    case SHOP_STATE_PURCHASE:
        GFL_USE_PlaySeDefaultVolume(0x655);
        SCRCMD_PROC_FLD_ShowItemMessage(shop, 9, shop->itemId, *(s16 *)&shop->quantity > 1);
        SCRCMD_PROC_FLD_PayPrice(shop, shop->price * *(s16 *)&shop->quantity);
        SCRCMD_PROC_FLD_PrintMoneyWindow(shop);
        MYITEM_SAVEDATA_AddItem(shop->bagData, shop->itemId, shop->quantity, shop->heapId);
        shop->state = SHOP_STATE_MESSAGE_WAIT;
        shop->nextState = SHOP_STATE_BONUS_ITEM;
        break;
    case SHOP_STATE_BONUS_ITEM:
        if (shop->itemId == 4 && *(s16 *)&shop->quantity >= 10) {
            SCRCMD_PROC_FLD_ShowItemMessage(shop, 15, shop->itemId, *(s16 *)&shop->quantity > 1);
            MYITEM_SAVEDATA_AddItem(shop->bagData, 12, 1, shop->heapId);
            RECORD_AddOne(shop->recordData, 0x1F);
            shop->state = SHOP_STATE_MESSAGE_WAIT;
            shop->nextState = SHOP_STATE_LIST_RESUME;
        } else {
            shop->state = SHOP_STATE_LIST_RESUME;
        }
        break;
    case SHOP_STATE_MESSAGE_WAIT:
        shop->state = SCRCMD_PROC_FLD_PollMessageEnd(shop);
        break;
    case SHOP_STATE_EXIT:
        SCRCMD_PROC_FLD_FreeItemListMenu(shop);
        SCRCMD_PROC_FLD_FreeShopCells(shop);
        SCRCMD_PROC_FLD_FreeShopWindows(shop);
        SCRCMD_PROC_FLD_ExitShopGraphics(shop);
        SCRCMD_PROC_FLD_FreeItemSlots(shop);
        SCRCMD_PROC_FLD_FreeShopResources(shop);
        return 1;
    }
    PRINTSYS_QUE_Main(shop->printSys);
    printSys = shop->printSys;
    if (shop->printerBusy != 0 && PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)printSys, (void *)((uptr)BMP_WIN_GetBmp(shop->listWindow))) == 0) {
        BMP_WIN_TransferChars(shop->listWindow);
        shop->printerBusy = 0;
    }
    TCBL_Main(shop->tcbList);
    TCBL_Main(shop->tcbList);
    return 0;
}

u32 SCRCMD_PROC_FLD_LoadItemRows(ShopItem *items, int count)
{
    u32 result = FILE_UTIL_IsMachineItem(items[0].itemId);
    int i;

    for (i = 0; i < count; i++) {
        FILE_UTIL_IsMachineItem(items[i].itemId);
    }
    return result;
}

void SCRCMD_PROC_FLD_SetItemSlot(ShopWork *shop, int slotIndex, int isTmShop, int itemId, struct MsgBank *msgBank)
{
    if (isTmShop == 1) {
        WORDSET_SetSlotNumber(shop->wordSet, 0, itemId - 327, 2, 2, 1);
        WORDSET_SetSlotFromMsgCB(shop->wordSet, 1, FILE_UTIL_GetMachineMove((u16)itemId));
        WORDSET_CopyTaggedText(shop->wordSet, shop->textBuffer, shop->cancelText);
        BMP_MENUWORK_AddStrItem((struct BmpMenuWork *)((char *)shop->itemSlots + slotIndex * 8), (const struct U16Vec *)shop->textBuffer, slotIndex, shop->heapId);
    } else {
        BMP_MENUWORK_AddMsgItem((struct BmpMenuWork *)((char *)shop->itemSlots + slotIndex * 8), msgBank, itemId, slotIndex, shop->heapId);
    }
}

/*
 * Spill slots: the image puts the tableIndex*4 offset at sp+4, msgBank at sp+8, itemCount at sp+0xc.
 * A single-def offset local is folded into a compiler temporary, and temps
 * take slots above every spilled local; the second (redundant) assignment in
 * the flag arm keeps off a real local, and declaration order (itemCount, msgBank, ..., tableOffset;
 * last declared lowest) gives the image layout.
 */
void SCRCMD_PROC_FLD_BuildItemListByBadges(ShopWork *shop, int shopKind, int shopVariant, int tierIndex)
{
    int itemCount;
    void *msgBank = MSGDATA_CreateFromArchive(0, 2, 54, shop->heapId);
    int tableIndex;
    int row;
    int itemId;
    ShopWork *rowBase;
    int tableOffset;

    if (shopKind == 0xff) {
        tableIndex = d_021D946C[tierIndex];
    } else {
        tableIndex = shopVariant + 6;
    }
    tableOffset = tableIndex * 4;
    if (FILE_UTIL_IsMachineItem(**(u16 **)((char *)d_021DE1A8 + tableOffset))) {
        shop->isTmShop = 1;
        tableOffset = tableIndex * 4;
    }
    itemCount = d_021D95DE[tableIndex];
    shop->itemSlots = BMP_MENUWORK_Create(itemCount + 1, shop->heapId);
    for (row = 0; row < itemCount; row++) {
        itemId = (*(u16 **)((char *)d_021DE1A8 + tableOffset))[row];
        SCRCMD_PROC_FLD_SetItemSlot(shop, row, shop->isTmShop, itemId, msgBank);
        /* stand-in: the row is reached as base + row * 8 plus the field offset */
        rowBase = (ShopWork *)((char *)shop + row * 8);
        rowBase->items[0].itemId = itemId;
        rowBase->items[0].price = GPOWER_ApplyShopPrice(FILE_UTIL_GetItemParam((unsigned int)itemId, 0, shop->heapId));
    }
    shop->itemCount = row;
    SCRCMD_PROC_FLD_LoadItemRows(shop->items, shop->itemCount);
    BMP_MENUWORK_AddMsgItem((struct BmpMenuWork *)((char *)shop->itemSlots + row * 8), shop->shopMsgBank, 11, -2, shop->heapId);
    MSGDATA_Delete(msgBank);
}

void SCRCMD_PROC_FLD_BuildItemListFixed(ShopWork *shop, int tableIndex)
{
    int row;
    ShopItem *table;
    int itemCount;
    struct MsgBank *msgBank;

    row = 0;
    msgBank = MSGDATA_CreateFromArchive(0, 2, 0x36, shop->heapId);
    table = d_021DE164[tableIndex];
    itemCount = d_021D9430[tableIndex];
    shop->itemSlots = BMP_MENUWORK_Create(itemCount + 1, shop->heapId);
    for (; row < itemCount; row++) {
        SCRCMD_PROC_FLD_SetItemSlot(shop, row, shop->isTmShop, table[row].itemId, msgBank);
        shop->items[row].itemId = table[row].itemId;
        shop->items[row].price = table[row].price;
    }
    shop->itemCount = row;
    BMP_MENUWORK_AddMsgItem((struct BmpMenuWork *)((char *)shop->itemSlots + row * 8), shop->shopMsgBank, 0xb, -2, shop->heapId);
    MSGDATA_Delete(msgBank);
}

void SCRCMD_PROC_FLD_BuildItemListFromRange(ShopWork *shop, int kind)
{
    int row = 0;
    void *msgBank = MSGDATA_CreateFromArchive(0, 2, 54, shop->heapId);

    FIELD_WFBC_DATA_LOCAL_FillPeopleListEntries((struct WfbcData *)shop->shopTable, (struct WfbcListEntry *)shop->items, &shop->itemCount, kind - 247, shop->heapId);
    shop->itemSlots = BMP_MENUWORK_Create(shop->itemCount + 1, shop->heapId);
    for (; row < shop->itemCount; row++) {
        SCRCMD_PROC_FLD_SetItemSlot(shop, row, shop->isTmShop, shop->items[row].itemId, msgBank);
    }
    BMP_MENUWORK_AddMsgItem((struct BmpMenuWork *)((char *)shop->itemSlots + row * 8), shop->shopMsgBank, 11, -2, shop->heapId);
    MSGDATA_Delete(msgBank);
}

/*
 * Unlabelled leaf (tail-call stub), called from SCRCMD_PROC_FLD_StepShop.
 *
 * Addresses are Black-image addresses.
 */
void SCRCMD_PROC_FLD_FreeItemSlots(ShopWork *shop)
{
    BMP_MENUWORK_Delete(shop->itemSlots);
}

int SCRCMD_PROC_FLD_AllocShopResources(ShopWork *shop, int shopKind)
{
    shop->shopMsgBank = MSGDATA_CreateFromArchive(0, 3, 423, shop->heapId);
    shop->itemMsgBank = MSGDATA_CreateFromArchive(0, 2, 53, shop->heapId);
    shop->wordSet = WORDSET_CreateDefault(shop->heapId);
    shop->textBuffer = STRBUF_Create(200, shop->heapId);
    shop->tcbList = TCBL_Create(shop->heapId, shop->heapId, 32, 32);
    shop->cancelText = MSGDATA_AllocString(shop->shopMsgBank, 29);
    return shopKind;
}

void SCRCMD_PROC_FLD_FreeShopResources(ShopWork *shop)
{
    TCBL_Destroy(shop->tcbList);
    WORDSET_Delete(shop->wordSet);
    STRBUF_Delete(shop->cancelText);
    STRBUF_Delete(shop->textBuffer);
    STRBUF_Delete(shop->soldOutText);
    STRBUF_Delete(shop->priceFormat);
    MSGDATA_Delete(shop->shopMsgBank);
    MSGDATA_Delete(shop->itemMsgBank);
}

void SCRCMD_PROC_FLD_InitShopGraphics(ShopWork *shop)
{
    void *archive;

    *(volatile u16 *)0x04000050 = 0;
    archive = ARC_TOOL_CreateHandle(54, shop->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(archive, 1, 0, 0, 96, shop->heapId);
    ARC_UTIL_UploadBgCharFromHandle(archive, 0, 2, 100, 0, 0, shop->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(archive, 2, 2, 0, 100, 0, 0, shop->heapId);
    ARC_TOOL_DeleteHandle(archive);
    BMP_MENUWORK_LoadCharAndPltt(1, 228, 9, 0, shop->heapId);
    BG_SYS_ClearSlot(1);
    BG_SYS_SetPriority(2, 1);
}

void SCRCMD_PROC_FLD_ExitShopGraphics(ShopWork *shop)
{
    BG_SYS_ClearSlot(1);
    BG_SYS_ClearSlot(2);
    BG_SYS_SetPriority(2, 0);
    FIELD_MSGBG_SetBlendThunk(1);
}

void SCRCMD_PROC_FLD_LoadCursorResources(ShopWork *shop)
{
    void *archive = ARC_TOOL_CreateHandle(54, shop->heapId);

    shop->arrowCharRes = (u32)CLACT_RegisterPaletteEx(archive, 10, 0, 0, 0, 1, shop->heapId);
    shop->cursorPlttRes = (u32)CLACT_RegisterCharacter(archive, 7, 0, 0, shop->heapId);
    shop->arrowPlttRes = (u32)CLACT_RegisterCharacter(archive, 4, 0, 0, shop->heapId);
    shop->cursorCellRes = (u32)CLACT_RegisterCellAnim(archive, 8, 9, shop->heapId);
    shop->arrowCellRes = (u32)CLACT_RegisterCellAnim(archive, 5, 6, shop->heapId);
    ARC_TOOL_DeleteHandle(archive);
}

void SCRCMD_PROC_FLD_LoadIconResources(ShopWork *shop)
{
    shop->iconCharRes = (u32)CLACT_RegisterPaletteEx(shop->iconArchive, FILE_UTIL_Get(1, 2), 0, 0x20, 0, 1, shop->heapId);
    shop->iconPlttRes = (u32)CLACT_RegisterCharacter(shop->iconArchive, FILE_UTIL_Get(1, 1), 0, 0, shop->heapId);
    shop->iconCellRes = (u32)CLACT_RegisterCellAnim(shop->iconArchive, 1, 0, shop->heapId);
}

void SCRCMD_PROC_FLD_UpdateItemIcon(ShopWork *shop, u32 itemId)
{
    uptr plttData;
    uptr charData;
    uptr charBuf;
    uptr plttBuf;

    if (itemId <= 0x272) {
        charBuf = (uptr)ARC_UTIL_LoadPaletteBlockFromHandle((void *)(shop->iconArchive), FILE_UTIL_Get(itemId, 2), (&charData), shop->heapId);
        plttBuf = (uptr)ARC_UTIL_LoadScreenDataFromHandle((void *)(shop->iconArchive), FILE_UTIL_Get(itemId, 1), 0, (&plttData), shop->heapId);
        CLACT_TransferPalette(shop->iconCharRes, (struct PaletteData *)charData, 1);
        CLACT_TransferCharacter(shop->iconPlttRes, (struct NNSG2dCharacterData *)plttData);
        GFL_HEAP_Free((void *)charBuf);
        GFL_HEAP_Free((void *)plttBuf);
        CLACT_SetActorDrawEnable((struct ClactActor *)shop->iconActor, 1);
    } else {
        CLACT_SetActorDrawEnable((struct ClactActor *)shop->iconActor, 0);
    }
}

void SCRCMD_PROC_FLD_CreateShopActors(ShopWork *shop)
{
    shop->cursorActor = CLACT_CreateActor(shop->cellSystem, shop->cursorPlttRes, shop->arrowCharRes,
                                        shop->cursorCellRes, &d_021D96E0, 0, shop->heapId);
    shop->arrowUpActor = CLACT_CreateActor(shop->cellSystem, shop->arrowPlttRes, shop->arrowCharRes,
                                        shop->arrowCellRes, &d_021D96E8, 0, shop->heapId);
    shop->arrowDownActor = CLACT_CreateActor(shop->cellSystem, shop->arrowPlttRes, shop->arrowCharRes,
                                        shop->arrowCellRes, &d_021D96F0, 0, shop->heapId);
    shop->quantityArrowActor = CLACT_CreateActor(shop->cellSystem, shop->arrowPlttRes, shop->arrowCharRes,
                                        shop->arrowCellRes, &d_021D96F8, 0, shop->heapId);
    CLACT_SetActorAutoAnim((struct ClactActor *)shop->quantityArrowActor, 1);
    shop->iconActor = CLACT_CreateActor(shop->cellSystem, shop->iconPlttRes, shop->iconCharRes,
                                        shop->iconCellRes, &d_021D9700, 0, shop->heapId);
    CLACT_SetActorDrawEnable((struct ClactActor *)shop->arrowUpActor, 0);
    CLACT_SetActorDrawEnable((struct ClactActor *)shop->arrowDownActor, 0);
    CLACT_SetActorDrawEnable((struct ClactActor *)shop->quantityArrowActor, 0);
}

void SCRCMD_PROC_FLD_InitShopCells(ShopWork *shop)
{
    shop->cellSystem = CLACT_CreateUnit(5, 1, shop->heapId);
    CLACT_SetUnitDrawEnable((struct Unit *)(shop->cellSystem), 1);
    SCRCMD_PROC_FLD_LoadCursorResources(shop);
    shop->iconArchive = ARC_TOOL_CreateHandle(0x19, shop->heapId);
    SCRCMD_PROC_FLD_LoadIconResources(shop);
    SCRCMD_PROC_FLD_CreateShopActors(shop);
}

void SCRCMD_PROC_FLD_FreeShopCells(ShopWork *shop)
{
    CLACT_ReleaseCellAnim((u32)(shop->iconCellRes));
    CLACT_ReleaseCellAnim((u32)(shop->arrowCellRes));
    CLACT_ReleaseCellAnim((u32)(shop->cursorCellRes));
    CLACT_ReleaseCharacter((u32)(shop->iconPlttRes));
    CLACT_ReleaseCharacter((u32)(shop->arrowPlttRes));
    CLACT_ReleaseCharacter((u32)(shop->cursorPlttRes));
    CLACT_ReleasePalette((u32)(shop->iconCharRes));
    CLACT_ReleasePalette((u32)(shop->arrowCharRes));
    ARC_TOOL_DeleteHandle(shop->iconArchive);
    CLACT_DeleteUnit(shop->cellSystem);
}

void SCRCMD_PROC_FLD_InitShopWindows(ShopWork *shop)
{
    ShopWindowTemplate **templates;
    ShopWindowTemplate *template;
    int i;
    struct Strbuf *headerText;
    struct BmpWin *window;

    templates = d_021DE18C;
    if (shop->usesBattlePoints != 1) {
        templates = d_021DE170;
    }
    for (i = 0; i < SHOP_WIN_COUNT; i++) {
        template = templates[i];
        shop->windows[i] = BMP_WIN_Create((u8)template->bgId, template->x, template->y, template->width, template->height, (u8)template->paletteNum, 1);
    }
    headerText = MSGDATA_AllocString((struct MsgBank *)(shop->shopMsgBank), 0x14);
    PRINTSYS_PrintColor((void *)((uptr)BMP_WIN_GetBmp(shop->windows[SHOP_WIN_HEADER])), 0, 0, headerText, shop->fontInfo, 0x3C4F);
    STRBUF_Delete(headerText);
    shop->listWindow = shop->windows[SHOP_WIN_LIST];
    shop->printerBusy = 0;
    shop->printSys = (void *)PRINTSYS_QUE_Create((unsigned int)(shop->heapId));
    if (shop->usesBattlePoints == 1) {
        window = shop->windows[SHOP_WIN_MONEY];
        BMP_WIN_TransferChars(window);
        BMP_WIN_MakeScreen(window);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
    } else {
        window = shop->windows[SHOP_WIN_HEADER];
        BMP_WIN_TransferChars(window);
        BMP_WIN_MakeScreen(window);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
        window = shop->windows[SHOP_WIN_MONEY];
        BMP_WIN_TransferChars(window);
        BMP_WIN_MakeScreen(window);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
    }
}

void SCRCMD_PROC_FLD_FreeShopWindows(ShopWork *shop)
{
    int i;

    PRINTSYS_QUE_Clear(shop->printSys);
    PRINTSYS_QUE_Delete(shop->printSys);
    for (i = 0; i < SHOP_WIN_COUNT; i++) {
        BMP_WIN_Delete(shop->windows[i]);
    }
}

void SCRCMD_PROC_FLD_PrintMoneyWindow(ShopWork *shop)
{
    struct Strbuf *formatText;
    struct Strbuf *expandedText;
    struct Bmp *bitmap;
    struct BmpWin *window;

    if (shop->usesBattlePoints == 1) {
        formatText = MSGDATA_AllocString((struct MsgBank *)(shop->shopMsgBank), 0x16);
        expandedText = STRBUF_Create(10, shop->heapId);
        WORDSET_SetSlotNumber(shop->wordSet, 0, BSUBWAY_SCOREDATA_GetBattlePoints(shop->battlePointData), 4, 1, 1);
    } else {
        formatText = MSGDATA_AllocString((struct MsgBank *)(shop->shopMsgBank), 0x15);
        expandedText = STRBUF_Create(10, shop->heapId);
        WORDSET_SetSlotNumber(shop->wordSet, 0, MISC_GetMoney(shop->moneyData), 7, 1, 1);
    }
    WORDSET_CopyTaggedText(shop->wordSet, expandedText, formatText);
    bitmap = BMP_WIN_GetBmp(shop->windows[SHOP_WIN_MONEY]);
    BMP_Clear(bitmap, 0);
    PRINTSYS_PrintColor(bitmap, 0, 0, expandedText, shop->fontInfo, 0x3C4F);
    window = shop->windows[SHOP_WIN_MONEY];
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
    STRBUF_Delete(expandedText);
    STRBUF_Delete(formatText);
}

/*
 * The spilled second parameter is a u16 (SCRCMD_PROC_FLD_PickQuantityOutcome passes a u16 field
 * to MYITEM_SAVEDATA_GetItemQuantity in the same slot): as u32 its entry spill
 * `str r1, [sp, #8]` lands after the `lsls` instead of before it.
 *
 * Addresses are Black-image addresses.
 */
void SCRCMD_PROC_FLD_PrintOwnedWindow(ShopWork *shop, u16 itemId)
{
    struct Strbuf *formatText;
    struct Strbuf *expandedText;
    struct Bmp *bitmap;
    struct BmpWin *window;

    formatText = MSGDATA_AllocString((struct MsgBank *)(shop->shopMsgBank), 0x17);
    expandedText = STRBUF_Create(0x14, shop->heapId);
    BMP_MENUWORK_DrawWindow(shop->windows[SHOP_WIN_OWNED], 2, 0xE4, 9);
    WORDSET_SetSlotNumber(shop->wordSet, 0, MYITEM_SAVEDATA_GetItemQuantity(shop->bagData, itemId, shop->heapId), 3, 0, 1);
    WORDSET_CopyTaggedText(shop->wordSet, expandedText, formatText);
    bitmap = BMP_WIN_GetBmp(shop->windows[SHOP_WIN_OWNED]);
    BMP_Clear(bitmap, 0xF);
    PRINTSYS_PrintColor(bitmap, 0, 0, expandedText, shop->fontInfo, 0x44F);
    window = shop->windows[SHOP_WIN_OWNED];
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
    STRBUF_Delete(expandedText);
    STRBUF_Delete(formatText);
}

void SCRCMD_PROC_FLD_PrintItemDescription(ShopWork *shop, u32 itemId)
{
    struct Bmp *bitmap;
    uptr text;
    struct BmpWin *window;

    bitmap = BMP_WIN_GetBmp(shop->windows[SHOP_WIN_DESCRIPTION]);
    BMP_Clear(bitmap, 0);
    if (itemId <= 0x272) {
        text = (uptr)MSGDATA_AllocString((struct MsgBank *)(shop->itemMsgBank), itemId);
        PRINTSYS_PrintColor(bitmap, 0, 0, (void *)text, shop->fontInfo, 0x3C40);
        STRBUF_Delete((struct Strbuf *)text);
    }
    window = shop->windows[SHOP_WIN_DESCRIPTION];
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
}

void SCRCMD_PROC_FLD_PrintQuantityWindow(ShopWork *shop, u32 quantity, u32 price)
{
    uptr quantityFormat, totalFormat, text;
    struct Bmp *bitmap;
    struct BmpWin *window;

    quantityFormat = (uptr)MSGDATA_AllocString((struct MsgBank *)(shop->shopMsgBank), 0x18);
    totalFormat = (uptr)MSGDATA_AllocString((struct MsgBank *)(shop->shopMsgBank), d_021D945C[shop->usesBattlePoints]);
    text = (uptr)STRBUF_Create(0x14, shop->heapId);
    bitmap = BMP_WIN_GetBmp(shop->windows[SHOP_WIN_QUANTITY]);
    BMP_Clear(bitmap, 0xF);
    BMP_MENUWORK_DrawWindow(shop->windows[SHOP_WIN_QUANTITY], 2, 0xE4, 9);
    WORDSET_SetSlotNumber(shop->wordSet, 0, quantity, 2, 0, 1);
    WORDSET_CopyTaggedText(shop->wordSet, (void *)text, (void *)quantityFormat);
    PRINTSYS_PrintColor(bitmap, 0, 0, (void *)text, shop->fontInfo, 0x44F);
    WORDSET_SetSlotNumber(shop->wordSet, 0, quantity * price, 7, 1, 1);
    WORDSET_CopyTaggedText(shop->wordSet, (void *)text, (void *)totalFormat);
    if (shop->usesBattlePoints == 0) {
        PRINTSYS_PrintColor(bitmap, 0x23, 0, (void *)text, shop->fontInfo, 0x44F);
    } else {
        PRINTSYS_PrintColor(bitmap, 0x1D, 0, (void *)text, shop->fontInfo, 0x44F);
    }
    window = shop->windows[SHOP_WIN_QUANTITY];
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
    STRBUF_Delete((struct Strbuf *)text);
    STRBUF_Delete((struct Strbuf *)totalFormat);
    STRBUF_Delete((struct Strbuf *)quantityFormat);
}

/*
 * Builds a 0x34-byte list template on the stack (layout as read by
 * BMP_MENULIST_Create) and creates the list object from it.
 */
void SCRCMD_PROC_FLD_CreateItemListMenu(ShopWork *shop)
{
    ShopListTemplate listTemplate;

    listTemplate.items = shop->itemSlots;
    listTemplate.cursorMoveFunc = (void *)SCRCMD_PROC_FLD_OnListCursorMove;
    if (shop->isTmShop == 0) {
        listTemplate.printFunc = (void *)SCRCMD_PROC_FLD_PrintPriceEntry;
    } else {
        listTemplate.printFunc = (void *)SCRCMD_PROC_FLD_PrintUniqueItemEntry;
    }
    listTemplate.window = shop->windows[SHOP_WIN_LIST];
    listTemplate.count = BMP_MENUWORK_CountItems(shop->itemSlots);
    listTemplate.visibleRows = 7;
    listTemplate.headerX = 0;
    listTemplate.itemX = 0;
    listTemplate.cursorX = 0;
    listTemplate.fgColor = 8;
    listTemplate.shadowColor = 0xC;
    listTemplate.bgColor = 0;
    listTemplate.cursorColor = 0xD;
    listTemplate.lineSpacing = 0;
    listTemplate.cursorType = 0;
    listTemplate.reservedBits = 1;
    listTemplate.flagBits = 0;
    listTemplate.cancelable = 1;
    listTemplate.userData = shop;
    listTemplate.cursorSpriteX = 0xC;
    listTemplate.cursorSpriteY = 0x10;
    listTemplate.reserved24 = 0;
    listTemplate.activeWindowRef = &shop->listWindow;
    listTemplate.printSys = shop->printSys;
    listTemplate.fontInfo = shop->fontInfo;
    shop->listMenu = BMP_MENULIST_Create((struct BmpMenuListTemplate *)(&listTemplate), 0, 0, shop->heapId);
}

void SCRCMD_PROC_FLD_PrintListText(struct PrintQueue *printSys, struct Bmp *bitmap, int x, int y, struct Strbuf *text, struct GfFont *fontInfo, u16 colorBits)
{
    if (y <= 8) {
        PRINTSYS_PrintColor(bitmap, (s16)x, y, (void *)text, (void *)fontInfo, colorBits);
    } else {
        PRINTSYS_PrintQueColor(printSys, bitmap, (s16)x, (s16)y, (struct Strbuf *)text, (struct GfFont *)fontInfo, (u32)colorBits);
    }
}

/*
 * Twin of SCRCMD_PROC_FLD_PrintUniqueItemEntry (its else arm alone). The u8 third parameter is
 * what keeps the reload of its spill slot just before the last call; as u32
 * the reload is hoisted above the hi - lo subtraction. The first parameter
 * is forwarded untouched to BMP_MENULIST_GetUserData.
 *
 * Addresses are Black-image addresses.
 */
void SCRCMD_PROC_FLD_PrintPriceEntry(struct BmpMenuList *listMenu, int row, u8 y)
{
    ShopWork *shop;
    u32 textWidth;
    int windowWidth;

    shop = (ShopWork *)BMP_MENULIST_GetUserData(listMenu);
    if (row != -2) {
        WORDSET_SetSlotNumber(shop->wordSet, 1, shop->items[row].price, 5, 0, 1);
        WORDSET_CopyTaggedText(shop->wordSet, shop->textBuffer, (void *)(shop->priceFormat));
        textWidth = PRINTSYS_MeasureWidestLine(shop->textBuffer, shop->fontInfo, 0);
        windowWidth = BMP_GetWidth((const struct Bmp *)((uptr)BMP_WIN_GetBmp(shop->windows[SHOP_WIN_LIST])));
        SCRCMD_PROC_FLD_PrintListText(shop->printSys, BMP_WIN_GetBmp(shop->windows[SHOP_WIN_LIST]), windowWidth - textWidth, y,
                      shop->textBuffer, shop->fontInfo, 0x31A0);
    }
}

/*
 * The u8 third parameter (a list-cursor callback's on-init flag) is what
 * moves the reload of its spill slot to just before the last call; as int or
 * u32 the reload is hoisted above the hi - lo subtraction.
 */
void SCRCMD_PROC_FLD_PrintUniqueItemEntry(struct BmpMenuList *listMenu, int row, u8 y)
{
    ShopWork *shop;
    u32 textWidth;
    int windowWidth;

    shop = (ShopWork *)BMP_MENULIST_GetUserData(listMenu);
    if (row != -2) {
        if (MYITEM_SAVEDATA_HasItem(shop->bagData, shop->items[row].itemId, 1, shop->heapId) != 0) {
            textWidth = PRINTSYS_MeasureWidestLine(shop->soldOutText, shop->fontInfo, 0);
            windowWidth = BMP_GetWidth((const struct Bmp *)((uptr)BMP_WIN_GetBmp(shop->windows[SHOP_WIN_LIST])));
            SCRCMD_PROC_FLD_PrintListText(shop->printSys, BMP_WIN_GetBmp(shop->windows[SHOP_WIN_LIST]), windowWidth - textWidth, y,
                          shop->soldOutText, shop->fontInfo, 0x31A0);
        } else {
            WORDSET_SetSlotNumber(shop->wordSet, 1, shop->items[row].price, 5, 1, 1);
            WORDSET_CopyTaggedText(shop->wordSet, shop->textBuffer, (void *)(shop->priceFormat));
            textWidth = PRINTSYS_MeasureWidestLine(shop->textBuffer, shop->fontInfo, 0);
            windowWidth = BMP_GetWidth((const struct Bmp *)((uptr)BMP_WIN_GetBmp(shop->windows[SHOP_WIN_LIST])));
            SCRCMD_PROC_FLD_PrintListText(shop->printSys, BMP_WIN_GetBmp(shop->windows[SHOP_WIN_LIST]), windowWidth - textWidth, y,
                          shop->textBuffer, shop->fontInfo, 0x31A0);
        }
    }
}

void SCRCMD_PROC_FLD_OnListCursorMove(struct BmpMenuList *listMenu, u32 row)
{
    u16 cursorPos[4];
    ShopWork *shop;
    ShopItem *items;

    shop = (ShopWork *)BMP_MENULIST_GetUserData(listMenu);
    BMP_MENULIST_GetPos(listMenu, &cursorPos[1], &cursorPos[0]);
    cursorPos[2] = 0xAC;
    cursorPos[3] = cursorPos[0] * 16 + 0x16;
    CLACT_AddActorSurfacePos(shop->cursorActor, (const struct ClactVec2 *)(&cursorPos[2]), 0);
    if (row < 0x28) {
        items = shop->items;
        SCRCMD_PROC_FLD_PrintItemDescription(shop, items[row].itemId);
        SCRCMD_PROC_FLD_UpdateItemIcon(shop, items[row].itemId);
    } else {
        SCRCMD_PROC_FLD_PrintItemDescription(shop, 0xFFFF);
        SCRCMD_PROC_FLD_UpdateItemIcon(shop, 0xFFFF);
    }
}

void SCRCMD_PROC_FLD_FreeItemListMenu(ShopWork *shop)
{
    u16 scrollPos;
    u16 cursorPos;

    BMP_MENULIST_Delete((struct BmpMenuList *)(shop->listMenu), &scrollPos, &cursorPos);
}

/*
 * Untraced blob: constant zero return.
 *
 * Addresses are Black-image addresses.
 */
int SCRCMD_PROC_FLD_ReturnZero(void)
{
    return 0;
}

void SCRCMD_PROC_FLD_ShowItemMessage(ShopWork *shop, u32 messageId, u32 itemId, u32 plural)
{
    u32 isPlural;
    struct Strbuf *messageText;
    struct BmpWin *window;

    if (messageId == 9 && plural != 0)
        isPlural = 1;
    else
        isPlural = 0;
    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp(shop->windows[SHOP_WIN_MESSAGE])), 0xf);
    BMP_MENUWORK_DrawWindow(shop->windows[SHOP_WIN_MESSAGE], 0, 0xe4, 9);
    WORDSET_SetSlotFromBank(shop->wordSet, 0, itemId, isPlural, 0);
    WORDSET_SetSlotFromMsg37(shop->wordSet, 1, FILE_UTIL_GetItemParam((unsigned int)itemId, 5, shop->heapId));
    messageText = MSGDATA_AllocString((struct MsgBank *)(shop->shopMsgBank), messageId);
    WORDSET_CopyTaggedText(shop->wordSet, shop->textBuffer, messageText);
    STRBUF_Delete(messageText);
    shop->messagePrinter = PRINTSYS_PrintStreamCallBack(shop->windows[SHOP_WIN_MESSAGE], 0, 0, shop->textBuffer,
                                        shop->fontInfo, MSG_SPEED_GetWait(),
                                        (struct Tcbl *)shop->tcbList, 0, shop->heapId, 0xffff,
                                        (u8 (*)(u32))SCRCMD_PROC_FLD_ReturnZero);
    window = shop->windows[SHOP_WIN_MESSAGE];
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
}

void SCRCMD_PROC_FLD_ShowConfirmMessage(ShopWork *shop, u32 isTmShop)
{
    if (shop->isTmShop == 1) {
        if (shop->usesBattlePoints == 1) {
            SCRCMD_PROC_FLD_ShowTmBuyConfirm(shop, 8, shop->itemId, shop->price);
        } else {
            SCRCMD_PROC_FLD_ShowTmBuyConfirm(shop, 7, shop->itemId, shop->price);
        }
    } else {
        if (shop->usesBattlePoints == 1) {
            SCRCMD_PROC_FLD_ShowBuyConfirm(shop, 6, shop->itemId, shop->price, shop->quantity);
        } else {
            SCRCMD_PROC_FLD_ShowBuyConfirm(shop, 5, shop->itemId, shop->price, shop->quantity);
        }
    }
}

/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void SCRCMD_PROC_FLD_PrepareMessageWindow(struct BmpWin *window)
{
BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp(window)), 15);
    BMP_MENUWORK_DrawWindow(window, 0, 228, 9);
}

void SCRCMD_PROC_FLD_ShowMessage(ShopWork *shop, u32 messageId)
{
    struct Strbuf *messageText;
    struct BmpWin *window;

    messageText = MSGDATA_AllocString((struct MsgBank *)(shop->shopMsgBank), messageId);
    WORDSET_CopyTaggedText(shop->wordSet, shop->textBuffer, messageText);
    STRBUF_Delete(messageText);
    shop->messagePrinter = PRINTSYS_PrintStreamCallBack(shop->windows[SHOP_WIN_MESSAGE], 0, 0, shop->textBuffer,
                                        shop->fontInfo, MSG_SPEED_GetWait(), (struct Tcbl *)shop->tcbList, 0,
                                        shop->heapId, 0xFFFF, 0);
    window = shop->windows[SHOP_WIN_MESSAGE];
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
}

/*
 * The spilled third parameter is narrow (u16 here; s16/u8 give the same
 * bytes): as u32/int its entry spill `str r2, [sp, #8]` lands after the
 * `lsls` instead of before it.
 *
 * Addresses are Black-image addresses.
 */
void SCRCMD_PROC_FLD_ShowBuyConfirm(ShopWork *shop, u32 messageId, u16 itemId, u32 price, u16 quantity)
{
    SCRCMD_PROC_FLD_PrepareMessageWindow(shop->windows[SHOP_WIN_MESSAGE]);
    WORDSET_SetSlotFromBank(shop->wordSet, 0, itemId, 0, 0);
    WORDSET_SetSlotNumber(shop->wordSet, 1, quantity, 2, 0, 1);
    WORDSET_SetSlotNumber(shop->wordSet, 2, quantity * price, 7, 0, 1);
    SCRCMD_PROC_FLD_ShowMessage(shop, messageId);
}

void SCRCMD_PROC_FLD_ShowTmBuyConfirm(ShopWork *shop, u32 messageId, u32 itemId, u32 price)
{
    SCRCMD_PROC_FLD_PrepareMessageWindow(shop->windows[SHOP_WIN_MESSAGE]);
    WORDSET_SetSlotNumber(shop->wordSet, 0, itemId - 327, 2, 2, 1);
    WORDSET_SetSlotFromMsgCB(shop->wordSet, 1, FILE_UTIL_GetMachineMove(itemId));
    WORDSET_SetSlotNumber(shop->wordSet, 2, price, 5, 0, 1);
    SCRCMD_PROC_FLD_ShowMessage(shop, messageId);
}

int SCRCMD_PROC_FLD_AdjustQuantity(s16 *value, int maxValue, int step)
{
    int oldValue = *value;
    switch (step) {
    case -1:
        *value = oldValue - 1;
        if (*value <= 0) *value = maxValue;
        if (*value == oldValue) return 0;
        return 2;
    case -10:
        *value = oldValue - 10;
        if (*value <= 0) *value = 1;
        if (*value == oldValue) return 0;
        return 2;
    case 1:
        *value = oldValue + 1;
        if (*value > maxValue) *value = 1;
        if (*value == oldValue) return 0;
        return 1;
    case 10:
        *value = oldValue + 10;
        if (*value > maxValue) *value = maxValue;
        if (*value == oldValue) return 0;
        return 1;
    }
    return 0;
}

int SCRCMD_PROC_FLD_StepQuantitySelect(ShopWork *shop)
{
    if (KEY_GetRepeat() & 0x40) {
        if (SCRCMD_PROC_FLD_AdjustQuantity((s16 *)&shop->quantity, (u16)shop->maxQuantity, 1) != 0) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            SCRCMD_PROC_FLD_PrintQuantityWindow(shop, shop->quantity, shop->price);
        }
    } else if (KEY_GetRepeat() & 0x80) {
        if (SCRCMD_PROC_FLD_AdjustQuantity((s16 *)&shop->quantity, (u16)shop->maxQuantity, -1) != 0) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            SCRCMD_PROC_FLD_PrintQuantityWindow(shop, shop->quantity, shop->price);
        }
    } else if (KEY_GetRepeat() & 0x20) {
        if (SCRCMD_PROC_FLD_AdjustQuantity((s16 *)&shop->quantity, (u16)shop->maxQuantity, -10) != 0) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            SCRCMD_PROC_FLD_PrintQuantityWindow(shop, shop->quantity, shop->price);
        }
    } else if (KEY_GetRepeat() & 0x10) {
        if (SCRCMD_PROC_FLD_AdjustQuantity((s16 *)&shop->quantity, (u16)shop->maxQuantity, 10) != 0) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            SCRCMD_PROC_FLD_PrintQuantityWindow(shop, shop->quantity, shop->price);
        }
    }
    if (KEY_GetTrg() & 1) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        SCRCMD_PROC_FLD_ShowConfirmMessage(shop, shop->isTmShop);
        shop->nextState = SHOP_STATE_YESNO_OPEN_NOICON;
        return SHOP_STATE_MESSAGE_WAIT;
    }
    if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        return SHOP_STATE_LIST_RESUME;
    }
    return SHOP_STATE_QUANTITY_STEP;
}

/*
 * d_021D9654 is a const table of 16-byte {x, y, w, h} records (two of them
 * in the listing: {0,12,32,12}, {0,12,32,6}). Without const the loads for
 * the register arguments cannot pass the first stack-argument store and
 * are issued after it; BG_SYS_SetTileEntry's u8 parameters follow the ldrb reads
 * of its stack arguments (as in src/matched/arm9/BMP_MENUWORK_DrawFrame.c).
 * Addresses are Black-image addresses.
 */
void SCRCMD_PROC_FLD_SetQuantityMask(int i)
{
    BG_SYS_SetTileEntry(1, 0, d_021D9654[i].x, d_021D9654[i].y, d_021D9654[i].w, d_021D9654[i].h, 0);
}

int SCRCMD_PROC_FLD_StoreCommKind(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);

    *resultVar = FIELDMAP_GetCommKind((void *)GAMESYSTEM_GetGameComm(gameSystem));
    return 1;
}

int SCRCMD_PROC_FLD_StoreWifiProfileValid(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
*SCRIPT_WORK_ReadWorkPointer(vm, cmdWork) = WIFILIST_IsProfileValid((struct WifiList *)GAME_DATA_GetWifiList(SCRCMD_WORK_GetGameData(cmdWork)));
return 0;
}

int SCRCMD_PROC_FLD_StoreWifiFriendCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
*SCRIPT_WORK_ReadWorkPointer(vm, cmdWork) = WIFILIST_CountFriends((struct WifiList *)GAME_DATA_GetWifiList(SCRCMD_WORK_GetGameData(cmdWork)));
return 0;
}

int SCRCMD_PROC_FLD_CallWifiClubEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    FieldEventArgs args;
    void *scriptWork;
    void *gameSystem;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    args.fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    args.reserved = 0;
    SCRIPT_SYS_CallEvent(scriptWork, GAME_EVENT_CreateOverlayEvent(gameSystem, (uptr)abs_id_6, (void *)EVENT_WIFICLUB_Entry, (&args)));
    return 1;
}

int SCRCMD_PROC_FLD_CallWorldTradeEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    FieldEventArgs args;
    void *scriptWork;
    void *gameSystem;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    args.fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    args.reserved = 0;
    SCRIPT_SYS_CallEvent(scriptWork, GAME_EVENT_CreateOverlayEvent(gameSystem, (uptr)abs_id_4, (void *)EVENT_WORLDTRADE_Entry, (&args)));
    return 1;
}

/*
 * 2026-10-02: closed by seeding ov001 0x02154694 (Thumb tail-call thunk to
 * EVENT_GTSNEGO_Create, filed as EVENT_GTSNEGO_Entry.c). Old note: it sat inside the ov001 pool at 02154690
 * (ldr r3,[pc]; bx r3; .word EVENT_GTSNEGO_Create+1) so sole-ref/code finds no func_ label;
 * abs_id_01 is the overlay id 1 that GAME_EVENT_CreateOverlayEvent loads (not an OVERLAY_ID_CONSUMER).
 *
 * Addresses are Black-image addresses.
 */
int SCRCMD_PROC_FLD_CallGtsNegoEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork;
    void *gameSystem;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    SCRIPT_SYS_CallEvent(scriptWork, GAME_EVENT_CreateOverlayEvent(gameSystem, (uptr)abs_id_01, (u32 (*)(void *, u32))EVENT_GTSNEGO_Entry, GAMESYSTEM_GetFieldMap(gameSystem)));
    return 1;
}

void SCRCMD_PROC_FLD_FinishOv170Event(void *arg)
{
    volatile Ov170EventHandoff *handoff = arg;
    u32 resultFlag;
    u32 result;
    Ov170EventWork *work;

    if (handoff->work->kind == 4) {
        BATTLE_BOX_StoreParty((struct BoxMonGroup *)BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl((struct GameData *)handoff->gameData)), (struct Party *)handoff->work->party);
    }
    work = handoff->work;
    if (work->kind == 4) {
        GFL_HEAP_Free(work->party);
    }
    result = handoff->work->result;
    if (result == 0 || result != 1)
        resultFlag = 0;
    else
        resultFlag = 1;
    *handoff->resultVar = resultFlag;
    GFL_HEAP_Free(handoff->work);
}

/*
 * Script command: builds a 0x2C-byte work (save handles, the hand-off kind
 * at +0x24) and a 12-byte hand-off record, then launches overlay 0xAA
 * (ov170) over them through FIELD_STATUS_CreateSubProcNoFadeCallbackEvent with the SCRCMD_PROC_FLD_FinishOv170Event callback
 * and parks the task in the script's slot.  Same shape as the ov010
 * SCRCMD_PROC_CallGtsNegotiation.
 *
 * The new work block is assigned to the first parameter (vm) and then
 * read through the typed pointer work: with an independent local, work and
 * the save handle gameData swap r4/r5 whatever the declaration order
 * (docs/idioms/reassigning-a-parameter-to-the-callee-result-keeps-its-
 * register.md).
 *
 * Blocker (MATCH, every concrete byte right, 24 of 25 sites resolved): the
 * pool word 0x000000AA (ov170_id, +0xF0) has no witness.  It is the
 * overlay-id argument (r2) of FIELD_STATUS_CreateSubProcNoFadeCallbackEvent, which is not in
 * OVERLAY_ID_CONSUMERS; FIELD_STATUS_CreateSubProcNoFadeCallbackEvent (EXACT, arm9) stores its a2 as
 * p[2] of the item GAME_EVENT_Create creates, the same shape as the
 * GAME_EVENT_CallProc case ov000 EVENT_WORLDTRADE_Entry's header describes.  Adding
 * 0x02014840 with register 2 to OVERLAY_ID_CONSUMERS (integrator's call,
 * after reading the item's state machine) would resolve it.  ov021 holds
 * one other 0xAA pool word (0x021D5598), yet match.py still reports no
 * witness: a small overlay-id value resolves only through that consumer
 * table, so no cut helps.
 *
 * Addresses are Black-image addresses.
 */
int SCRCMD_PROC_FLD_CallOv170Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork;
    void *gameSystem;
    void *gameData;
    void *saveControl;
    void *saveStateSource;
    void *fieldMap;
    unsigned short *resultVar;
    u32 kind;
    Ov170EventHandoff *handoff;
    void *saveBlock;
    Ov170EventWork *work;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    saveControl = GAME_DATA_GetSaveControl(gameData);
    saveStateSource = ZUKAN_SAVE_GetFromGameData(gameData);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    kind = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    vm = GFL_HEAP_Alloc(4, 0x2c, 0, d_021DE220, 0x7c);
    work = (Ov170EventWork *)vm;
    work->gameData = gameData;
    work->boxManager = GAME_DATA_GetBoxManager(gameData);
    work->party = GAME_DATA_GetMyParty(gameData);
    work->myItem = (uptr)GAME_DATA_GetMyItem(gameData);
    work->myStatus = (unsigned char *)GAME_DATA_GetMyStatus(gameData);
    work->saveStateA = (uptr)SYSTEM_DATA_GetConfig(saveControl);
    work->saveStateB = ZUKAN_SAVE_IsNationalDexEnabled(saveStateSource);
    work->kind = kind;
    work->extraData = 0;
    if (kind == 4) {
        saveBlock = BATTLE_BOX_GetFromSave(saveControl);
        work->party = BATTLE_BOX_CreateParty(saveBlock, 4);
        work->extraData = BATTLE_BOX_IsLocked(saveBlock, 3);
    }
    handoff = GFL_HEAP_Alloc(4, 0xc, 0, d_021DE220, 0x90);
    handoff->gameData = gameData;
    handoff->resultVar = resultVar;
    handoff->work = work;
    SCRIPT_SYS_CallEvent(scriptWork, FIELD_STATUS_CreateSubProcNoFadeCallbackEvent(gameSystem, fieldMap, (uptr)ov170_id, (void *)d_021EF78C, work, SCRCMD_PROC_FLD_FinishOv170Event, handoff));
    return 1;
}

int SCRCMD_PROC_FLD_StartNameInMode5(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork;
    void *gameSystem;
    void *fieldMap;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    SCRIPT_SYS_CallEvent(scriptWork, (void *)EVENT_NAMEIN_Create((void *)gameSystem, fieldMap, 0, 5, SCRIPT_WORK_ReadWorkPointer(vm, cmdWork)));
    return 1;
}

int SCRCMD_PROC_FLD_StartNameInMode6(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork;
    void *gameSystem;
    void *fieldMap;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    SCRIPT_SYS_CallEvent(scriptWork, (void *)EVENT_NAMEIN_Create((void *)gameSystem, fieldMap, 0, 6, SCRIPT_WORK_ReadWorkPointer(vm, cmdWork)));
    return 1;
}

int SCRCMD_PROC_FLD_SetGameClearEventAndEnd(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);

    GAMESYSTEM_GetFieldMap(gameSystem);
    SCRIPT_SYS_SetNextEventFromWork((void *)scriptWork, EVENT_GAMECLEAR_Create(gameSystem, SCRIPT_WORK_ReadWorkValue(vm, cmdWork)));
    VM_End(vm);
    return 1;
}

int SCRCMD_PROC_FLD_ObtainCGearAndCallCommResetEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    uptr saveBlock;
    u32 eventArg;
    void *scriptWork;
    void *gameSystem;

    saveBlock = (uptr)BLOCK20_SAVEDATA_GetBlock(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(cmdWork)));
    eventArg = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    CGEAR_SAVE_SetObtained((struct CGearSave *)saveBlock, 1);
    SCRIPT_SYS_CallEvent(scriptWork, FLD_BTL_INST_TOOL_CreateCommResetEvent(gameSystem, (int)eventArg));
    return 1;
}

int SCRCMD_PROC_FLD_CallOv219Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem;
    void *scriptWork;
    void *fieldMap;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    SCRIPT_SYS_CallEvent(scriptWork, FIELD_STATUS_CreateSubProcEvent(gameSystem, fieldMap, (sptr)abs_id_DB, (void *)d_02185F0C, GAMESYSTEM_GetGameData(gameSystem)));
    return 1;
}

int SCRCMD_PROC_FLD_CallShortcutEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork;
    void *gameSystem;
    u32 flag;
    unsigned short *resultVar;
    u32 flagBool;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem));
    GAMESYSTEM_GetFieldMap(gameSystem);
    flag = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    if (flag == 0 || flag != 1)
        flagBool = 0;
    else
        flagBool = 1;
    SCRIPT_SYS_CallEvent(scriptWork, SCRCMD_CreateSubProcEvent(gameSystem, flagBool, resultVar));
    return 1;
}

int SCRCMD_PROC_FLD_CallGameManual(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);

    SCRIPT_SYS_CallEvent(scriptWork, EVENT_GAME_MANUAL_Create(gameSystem, SCRIPT_WORK_ReadWorkPointer(vm, cmdWork)));
    return 1;
}

int SCRCMD_PROC_FLD_StartScriptedWildBattle(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork;
    u32 eventParam0;
    u32 eventParam1;
    u32 eventParam2;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    eventParam0 = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    eventParam1 = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    eventParam2 = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRIPT_WORK_GetGameSystem(scriptWork);
    SCRIPT_SYS_CallEvent(scriptWork, FIELD_ENCOUNT_StartScriptedWild(FIELDMAP_GetEncount((struct FieldMap *)SCRIPT_WORK_ResetFieldParam(scriptWork)->fieldSystem), eventParam0, (u8)eventParam1, eventParam2));
    return 1;
}

int SCRCMD_PROC_FLD_StartFieldMapFadeIn(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);

    SCRIPT_SYS_CallEvent(scriptWork, (void *)EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, GAMESYSTEM_GetFieldMap(gameSystem), 0, 0, 1, 0, 0));
    return 1;
}

/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */
int SCRCMD_PROC_FLD_StoreBattleResult(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 flagValue = GAME_DATA_GetLastBattleResult(SCRCMD_WORK_GetGameData(cmdWork));
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);

    *resultVar = EVENT_BATTLE_GetResultFlag(flagValue);
    return 0;
}

int SCRCMD_PROC_FLD_CallCatchTutorial(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);

    SCRIPT_SYS_CallEvent(scriptWork, EVENT_BATTLE_CreateCatchTutorial(gameSystem, GAMESYSTEM_GetFieldMap(gameSystem), 4));
    return 1;
}

int SCRCMD_PROC_FLD_StoreEffectEncountItemId(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *fieldMap = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork));
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);

    *resultVar = EFFECT_ENCOUNT_GetItemId((struct FieldEncount *)FIELDMAP_GetEncount(fieldMap));
    return 0;
}

int SCRCMD_PROC_FLD_SpawnMovePokemonIfInactive(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    struct MovePokemonSave *flagBlock = MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(gameData));
    u8 flagIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    if (MOVE_POKEMON_SAVE_IsEntryActive(flagBlock, flagIndex) == 0) {
        MOVE_POKEMON_SpawnEntry(gameData, flagIndex);
    }
    return 0;
}

u16 SCRCMD_PROC_FLD_AddUniqueU16(u16 *values, u16 count, u16 value)
{
    int i;

    for (i = 0; i < count; i++) {
        if (value == values[i]) {
            return count;
        }
    }
    values[count] = value;
    return count + 1;
}
