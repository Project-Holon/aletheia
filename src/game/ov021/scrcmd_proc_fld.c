/*
 * file:     scrcmd_proc_fld.c
 * unit:     yes
 * function: SCRCMD_PROC_FLD_StepShopTask, SCRCMD_PROC_FLD_InitShop, SCRCMD_PROC_FLD_LoadShopMessages, SCRCMD_PROC_FLD_GetShopCurrency, SCRCMD_PROC_FLD_PickQuantityOutcome, SCRCMD_PROC_FLD_PollItemList, SCRCMD_PROC_FLD_PollMessageEnd, SCRCMD_PROC_FLD_PayPrice, SCRCMD_PROC_FLD_StepShop, SCRCMD_PROC_FLD_LoadItemRows, SCRCMD_PROC_FLD_SetItemSlot, SCRCMD_PROC_FLD_BuildItemListByBadges, SCRCMD_PROC_FLD_BuildItemListFixed, SCRCMD_PROC_FLD_BuildItemListFromRange, SCRCMD_PROC_FLD_FreeItemSlots, SCRCMD_PROC_FLD_AllocShopResources, SCRCMD_PROC_FLD_FreeShopResources, SCRCMD_PROC_FLD_InitShopGraphics, SCRCMD_PROC_FLD_ExitShopGraphics, SCRCMD_PROC_FLD_LoadCursorResources, SCRCMD_PROC_FLD_LoadIconResources, SCRCMD_PROC_FLD_UpdateItemIcon, SCRCMD_PROC_FLD_CreateShopActors, SCRCMD_PROC_FLD_InitShopCells, SCRCMD_PROC_FLD_FreeShopCells, SCRCMD_PROC_FLD_InitShopWindows, SCRCMD_PROC_FLD_FreeShopWindows, SCRCMD_PROC_FLD_PrintMoneyWindow, SCRCMD_PROC_FLD_PrintOwnedWindow, SCRCMD_PROC_FLD_PrintItemDescription, SCRCMD_PROC_FLD_PrintQuantityWindow, SCRCMD_PROC_FLD_CreateItemListMenu, SCRCMD_PROC_FLD_PrintListText, SCRCMD_PROC_FLD_PrintPriceEntry, SCRCMD_PROC_FLD_PrintUniqueItemEntry, SCRCMD_PROC_FLD_OnListCursorMove, SCRCMD_PROC_FLD_FreeItemListMenu, SCRCMD_PROC_FLD_ReturnZero, SCRCMD_PROC_FLD_ShowItemMessage, SCRCMD_PROC_FLD_ShowConfirmMessage, SCRCMD_PROC_FLD_PrepareMessageWindow, SCRCMD_PROC_FLD_ShowMessage, SCRCMD_PROC_FLD_ShowBuyConfirm, SCRCMD_PROC_FLD_ShowTmBuyConfirm, SCRCMD_PROC_FLD_AdjustQuantity, SCRCMD_PROC_FLD_StepQuantitySelect, SCRCMD_PROC_FLD_SetQuantityMask, SCRCMD_PROC_FLD_StoreGameSystemValue, SCRCMD_PROC_FLD_StoreSubObjectValueA, SCRCMD_PROC_FLD_StoreSubObjectValueB, SCRCMD_PROC_FLD_CallOv006Event, SCRCMD_PROC_FLD_CallOv004Event, SCRCMD_PROC_FLD_CallOv001Event, SCRCMD_PROC_FLD_FinishOv170Event, SCRCMD_PROC_FLD_CallOv170Event, SCRCMD_PROC_FLD_StartNameInMode5, SCRCMD_PROC_FLD_StartNameInMode6, SCRCMD_PROC_FLD_SetNextEventAndEnd, SCRCMD_PROC_FLD_CallSubProcWithFlag, SCRCMD_PROC_FLD_CallOv219Event, SCRCMD_PROC_FLD_CallShortcutEvent, SCRCMD_PROC_FLD_CallEventWithVarPtr, SCRCMD_PROC_FLD_CallEventFromThreeValues, SCRCMD_PROC_FLD_CallFieldMapEvent, SCRCMD_PROC_FLD_StoreByteValue, SCRCMD_PROC_FLD_CallEventMode4, SCRCMD_PROC_FLD_StoreCameraValue, SCRCMD_PROC_FLD_SetFlagIfClear, SCRCMD_PROC_FLD_AddUniqueU16, SCRCMD_PROC_FLD_StoreRandomUniqueEntry, SCRCMD_PROC_FLD_ReleaseFieldRegion, SCRCMD_PROC_FLD_ReleaseFieldRegionTask, SCRCMD_PROC_FLD_BeginFieldRegionRelease, SCRCMD_PROC_FLD_ReleaseFieldRegionCmd, SCRCMD_PROC_FLD_ResetFieldRegionA, SCRCMD_PROC_FLD_ResetFieldRegionB, SCRCMD_PROC_FLD_SetFieldRegionFromStream, SCRCMD_PROC_FLD_SetFieldRegionFromArchive, SCRCMD_PROC_FLD_SetFieldRegionLayerFlags, SCRCMD_PROC_FLD_SetFieldRegionValue, SCRCMD_PROC_FLD_CallFieldRegionWaitEvent, SCRCMD_PROC_FLD_CallCustomEvent, SCRCMD_PROC_FLD_PollFieldRegionStart, SCRCMD_PROC_FLD_PollFieldRegionIdle, SCRCMD_PROC_FLD_CallOv056Event, SCRCMD_PROC_FLD_SetOv056Slot, SCRCMD_PROC_FLD_SetFieldRegionTable
 * address:  0x021B3158
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetUserWorkPtr  0x02158FB4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   ICA_ANIME_GetField20  0x0201210C  thumb
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
 *   func_020307B0  0x020307B0  arm
 *   d_021D9738     0x021D9738  data   ov021  a4
 *   ICA_ANIME_GetField1C 0x020120F4 thumb
 *   func_02012944 0x02012944 thumb
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   BEACON_CountFlags 0x0200C258 thumb
 *   func_02045EC0  0x02045EC0  arm
 *   BEACON_GetPoints  0x0200C274  thumb
 *   GDS_PROFILE_GetScoreRecTotal  0x0200DABC  thumb
 *   func_02007FB8  0x02007FB8  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0200823C  0x0200823C  thumb
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
 *   func_02008DAC  0x02008DAC  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   BEACON_SubPoints  0x0200C29C  thumb
 *   GDS_PROFILE_SubScoreRecTotal  0x0200DA98  thumb
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   func_02041B6C  0x02041B6C  arm
 *   BMP_MENULIST_Redraw  0x02020234  thumb
 *   BMP_MENU_CreateYesNo  0x0201FDA0  thumb
 *   BMP_MENU_ProcessYesNo  0x0201FEBC  thumb
 *   func_02007E50  0x02007E50  thumb
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   TCBL_Main  0x020310C4  arm
 *   d_021D9440     0x021D9440  data   ov021  a4
 *   FILE_UTIL_Check1288  0x02021288  thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   FILE_UTIL_Get_12B0 0x020212B0 thumb
 *   WORDSET_SetSlotFromMsgCB 0x0201EF34 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   BMP_MENUWORK_AddStrItem 0x0201F898 thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   func_02045B38 0x02045B38 arm
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   FILE_UTIL_Get_0FE4 0x02020FE4 thumb
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
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_02049990 0x02049990 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   FILE_UTIL_Get 0x02020E60 thumb
 *   func_02049F78 0x02049F78 arm
 *   func_02049E74 0x02049E74 arm
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
 *   func_02020D0C 0x02020D0C thumb
 *   func_0201D304 0x0201D304 thumb
 *   BMP_GetWidth 0x020437DC arm
 *   func_02007F68 0x02007F68 thumb
 *   func_020202FC 0x020202FC thumb
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   BMP_MENULIST_Delete  0x0202020C  thumb
 *   WORDSET_SetSlotFromBank  0x0201EF6C  thumb
 *   WORDSET_SetSlotFromMsg37  0x0201F14C  thumb
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   PRINTSYS_PrintStreamCallBack  0x0201CD10  thumb
 *   KEY_GetRepeat 0x0203633C arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   d_021D9654     0x021D9654  data  a4
 *   ICA_ANIME_GetField24  0x02012138  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FIELDMAP_GetCommKind  0x021896F4  thumb  ov021
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetField1A0  0x0201283C  thumb
 *   func_02009CE4  0x02009CE4  thumb
 *   func_02009A34  0x02009A34  thumb
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
 *   func_0200873C  0x0200873C  thumb
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   BATTLE_BOX_IsLocked  0x0200BBFC  thumb
 *   FIELD_STATUS_CreateSubProcNoFadeCallbackEvent  0x02014840  thumb
 *   func_02030734  0x02030734  arm
 *   d_021DE220     0x021DE220  data  a1
 *   ov170_id       0x000000AA  data  a1
 *   d_021EF78C     0x021EF78C  data  ov170  a4
 *   EVENT_NAMEIN_Create  0x021CD2A4  thumb  ov021
 *   func_02011290  0x02011290  thumb
 *   SCRIPT_SYS_SetNextEventFromWork  0x0215898C  thumb  ov010
 *   SCRCMD_NETWORK_CreateCommBattleEvent  0x0215F8A8  thumb  ov010
 *   func_02009210  0x02009210  thumb
 *   func_020090D8  0x020090D8  thumb
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
 *   GAME_DATA_GetFieldMode  0x02012A44  thumb
 *   EVENT_BATTLE_GetKindFlag  0x0216EFCC  thumb  ov010
 *   EVENT_BATTLE_CreateCatchTutorial  0x0216E95C  thumb  ov010
 *   EFFECT_ENCOUNT_GetItemId  0x021AAB48  thumb  ov021
 *   MOVE_POKEMON_SAVE_GetBlock  0x0200D418  thumb
 *   MOVE_POKEMON_SAVE_IsEntryActive  0x0200D488  thumb
 *   MOVE_POKEMON_SpawnEntry  0x0215E440  thumb  ov010
 *   FIELD_ENCOUNT_ST_LoadEncountData  0x0215E2B8  thumb  ov010
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   func_02005728  0x02005728  thumb
 *   d_021DE234     0x021DE234  data  a1
 *   d_021D98D0     0x021D98D0  data  a2
 *   FIELD_CAMERA_HasDelay  0x0218F0F8  thumb  ov021
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELD_NOGRID_MAPPER_SetActive  0x021BB260  thumb  ov021
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   FIELD_CAMERA_PushState  0x0218F818  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   VM_ReadU16  0x02011330  thumb
 *   VM_GetU32  0x0201134C  thumb
 *   FIELD_CAMERA_StartMove  0x0218F900  thumb  ov021
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   FIELD_CAMERA_StartMoveToSetting  0x0218FA40  thumb  ov021
 *   FIELD_CAMERA_CreateShakeTask  0x021D2D50  thumb  ov021
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GIMMICK_INIT_SetCartLanesFlags  0x021F36C0  thumb  ov037
 *   FIELD_CAMERA_SetSetting  0x0218E17C  thumb  ov021
 *   FIELD_FK_DEMO_GetCameraSettingId  0x021F36C8  thumb  ov056
 *   FIELDMAP_GetMapFunc  0x02188D24  thumb  ov021
 *   FIELD_SUBPROC_Start  0x021BB990  thumb  ov021
 *   ov56_id        0x00000038  data  a1
 *   g_021F4344     0x021F4344  data  ov056  a4
 *   g_021F4374     0x021F4374  data  ov056  a4
 *   g_021F438C     0x021F438C  data  ov056  a4
 *   g_021F435C     0x021F435C  data  ov056  a4
 */

#include "scrcmd_proc_fld_types.h"
#include "fieldmap_types.h"

struct Ctx;
struct MsgBank;
struct Blk1AC;
struct Blk34;
struct Cfg;
struct Descriptor;
struct Obj;
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
struct Bank;
struct CharBuf;
struct Src;
struct Bmp;
struct StrObj;
struct Vec2;
struct Sub020097BCObj;
struct BigObj;
struct Pair;
struct Desc;
struct Big;
struct Blk37;
struct Sub02008700Obj;
struct ScriptVm;
struct Sub020090B0Obj;
struct Sub02009210Obj;
struct Blk38;
struct Stream;
struct Cursor;
struct ScrcmdWork;
struct Blk021D2D50;

/* Six enable flags handed to the field region object. */
typedef struct LayerFlags {
    u32 flag[6];
} LayerFlags;

typedef signed char    s8;

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

/* One wild encounter entry: species and form in 4 bytes. */
typedef struct EncounterSlot {
    u16 species : 11;
    u16 form : 5;
    u16 reserved;
} EncounterSlot;

/* 0xE8-byte encounter table record filled by FIELD_ENCOUNT_ST_LoadEncountData. */
typedef struct EncounterRecord {
    u8  reserved00[5];
    u8  hasSetA;
    u8  hasSetB;
    u8  reserved07[0xc0 - 7];
    EncounterSlot setA[5];
    EncounterSlot setB[5];
} EncounterRecord;

/* Field region record read from archive 0xA3 (0x2C bytes). */
typedef struct FieldRegionRecord {
    u16 areaWidth;
    u16 areaHeight;
    u32 areaFlags;
    VecFx32 origin;
    LayerFlags layers;
} FieldRegionRecord;

/* Field region parameter block (0x48 bytes) handed to the field region object. */
typedef struct FieldRegionParam {
    u32 reserved00[3];
    VecFx32 origin;         /* 0x0c */
    u32 reserved18[3];
    u16 areaWidth;          /* 0x24 */
    u16 areaHeight;         /* 0x26 */
    u32 areaFlags;          /* 0x28 */
    u32 reserved2C;
    LayerFlags layers;      /* 0x30: six layer enable flags */
} FieldRegionParam;

/* Custom event record built from eight script values. */
typedef struct CustomEventParam {
    u16 eventId;            /* 0x00 */
    u16 eventKind;          /* 0x02 */
    u16 mapX;               /* 0x04 */
    u16 mapY;               /* 0x06 */
    u16 mapZ;               /* 0x08 */
    u16 reserved0A;         /* 0x0a */
    u16 facing;             /* 0x0c */
    u8 kind;                /* 0x0e */
    u8 kindCopy;            /* 0x0f */
    u32 scriptId;           /* 0x10 */
    u32 reserved14;         /* 0x14 */
} CustomEventParam;

typedef enum { B_FALSE, B_TRUE } Bool;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRIPT_WORK_GetUserWorkPtr(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *ICA_ANIME_GetField20(const struct Ctx *p);
extern void *FIELDMAP_GetCamera(void *a);
extern void FIELD_CAMERA_EndDelay(u8 *a);
extern u32 FIELD_CAMERA_IsDelayEnabled(u8 *a);
extern void SCRCMD_SHOP_PrepareFieldCamera(u32 *p, u32 b, void *h);
extern int FIELD_CAMERA_IsMoving(u8 *a);
extern void FIELD_MSGBG_SetBlendThunk(u32 a);
extern void FIELD_CAMERA_StartMoveToSaved(u8 *p, u8 *src, u16 v);
extern int FIELD_CAMERA_ResumeTargetTrace(u32 a);
extern void FIELD_CAMERA_SetAreasEnabled(u8 *p, u32 v);
extern void FIELD_CAMERA_RestartDelay(unsigned char *a);
extern void FIELD_CAMERA_PopState(u8 *a);
extern u32 func_020307B0(void *p);
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern void *GAME_DATA_GetMiscSave(int *p);
extern int BEACON_CountFlags(void);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 BEACON_GetPoints(struct Blk34 *p);
extern u16 GDS_PROFILE_GetScoreRecTotal(struct Blk1AC *p);
extern u32 func_02007FB8(u8 *base, u16 id, u16 d);
extern u32 func_02007E3C(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_0200823C(u32 a);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 index);
extern s32 BMP_MENULIST_Main(struct Obj *o);
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern unsigned int KEY_GetCont(void);
extern u32 KEY_GetTrg(void);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern u32 BEACON_SubPoints(struct Blk34 *p, u32 v);
extern void GDS_PROFILE_SubScoreRecTotal(struct Blk1AC *p, u16 v);
extern u32 func_02008DAC(struct Sub02008C20Obj *obj, int i, u32 delta);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void func_02041B6C(u32 a);
extern void BMP_MENULIST_Redraw(u8 *p);
extern u32 BMP_MENU_CreateYesNo(const void *a, u32 b, u32 c, u32 d, u32 e);
extern u32 BMP_MENU_ProcessYesNo(u8 *p);
extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void TCBL_Main(struct Tcbl *p);
extern u32 FILE_UTIL_Check1288(u32 id);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern int FILE_UTIL_Get_12B0(u32 a);
extern void WORDSET_SetSlotFromMsgCB(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void BMP_MENUWORK_AddStrItem(struct Slot *table, u32 a, u32 b, u32 tag);
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *BMP_MENUWORK_Create(int, int);
extern u32 FILE_UTIL_Get_0FE4(void *a, u32 sel, u32 id);
extern u32 GPOWER_ApplyShopPrice(u32 v);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void FIELD_WFBC_DATA_LOCAL_FillPeopleListEntries(char *base, char *out, u16 *cnt, int n, u16 id);
extern u32 BMP_MENUWORK_Delete(void *p);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void BG_SYS_ClearSlot(u32 i);
extern void BG_SYS_SetVisibleLayer(int idx, unsigned short val);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern unsigned FILE_UTIL_Get(unsigned a, unsigned b);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void CLACT_TransferPalette(u32 a, u32 b, u32 c);
extern void CLACT_TransferCharacter(int a, struct Sub0204A9D0 *b);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void CLACT_SetActorAutoAnim(struct Obj *, unsigned int);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDrawEnable(struct Bank *bank, u32 mode);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern u32 BMP_MENUWORK_CountItems(struct Slot *s);
extern struct Obj *BMP_MENULIST_Create(struct Src *src, u16 a, u16 b, u32 heap);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02020D0C(u8 *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern u32 func_02007F68(u8 *base, u16 id, u16 qty, u16 d);
extern void func_020202FC(struct Obj *obj, u16 *a, u16 *b);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);
extern void WORDSET_SetSlotFromBank(struct WordSet *p, u32 i, u32 v, u32 a, u32 b);
extern void WORDSET_SetSlotFromMsg37(struct WordSet *p, u32 i, u32 v);
extern signed char MSG_SPEED_GetWait(void);
extern struct Rec *PRINTSYS_PrintStreamCallBack(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern unsigned int KEY_GetRepeat(void);
extern void BG_SYS_SetTileEntry(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u32 ICA_ANIME_GetField24(const struct Ctx *p);
extern int FIELDMAP_GetCommKind(void *p);
extern u32 func_02009CE4(struct Sub020097BCObj *obj);
extern u32 GAME_DATA_GetField1A0(const struct BigObj *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern u32 func_02009A34(struct Sub020097BCObj *obj);
extern void SCRIPT_SYS_CallEvent(void *a, void *b);
extern struct Desc *GAME_EVENT_CreateOverlayEvent(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern int EVENT_WIFICLUB_Entry(int x, struct Pair *p);
extern int EVENT_WORLDTRADE_Entry(int x, struct Pair *p);
extern void *EVENT_GTSNEGO_Entry(void *p, int a);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BATTLE_BOX_GetFromSave(void *p);
extern void BATTLE_BOX_StoreParty(u8 *a0, u8 *a1);
extern u32 SCRIPT_WORK_ReadWorkValue(void *c, void *vm);
extern void *ZUKAN_SAVE_GetFromGameData(void *p);
extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u32 GAME_DATA_GetBoxManager(const struct BigObj *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern void *func_0200BAF4(int a0, int a1);
extern u32 BATTLE_BOX_IsLocked(struct Obj *p, u32 mask);
extern void *FIELD_STATUS_CreateSubProcNoFadeCallbackEvent(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 EVENT_NAMEIN_Create(u32 a, u32 b, u32 x, u32 c, u32 d);
extern void *SCRCMD_NETWORK_CreateCommBattleEvent(void *p, int a1);
extern void SCRIPT_SYS_SetNextEventFromWork(int a, int b);
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern void func_020090D8(struct Sub020090B0Obj *obj, u8 value);
extern void *FLD_BTL_INST_TOOL_CreateCommResetEvent(void *a, void *b);
extern void *FIELD_STATUS_CreateSubProcEvent(char *a0, int a1, int a2, int a3, int a4);
extern void *SCRCMD_CreateSubProcEvent(void *a, u32 b, u32 c);
extern void *EVENT_GAME_MANUAL_Create(void *, u16 *);
extern void *SCRIPT_WORK_GetGameSystem(void *p);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u32 FIELDMAP_GetEncount(u8 *p);
extern u32 FIELD_ENCOUNT_StartScriptedWild(u32 a, u32 b, u32 c, u32 d);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern u32 GAME_DATA_GetFieldMode(const struct BigObj *p);
extern u8 EVENT_BATTLE_GetKindFlag(int i);
extern void *EVENT_BATTLE_CreateCatchTutorial(void *sys, u32 arg, u32 heap);
extern u16 EFFECT_ENCOUNT_GetItemId(char *p);
extern void *MOVE_POKEMON_SAVE_GetBlock(void *sys);
extern u8 MOVE_POKEMON_SAVE_IsEntryActive(struct Blk38 *p, u32 i);
extern void MOVE_POKEMON_SpawnEntry(void *sys, u8 which);
extern int FIELD_ENCOUNT_ST_LoadEncountData(EncounterRecord *r, void *h, u32 k, u32 x);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern u32 func_02005728(u32 range);
extern u32 SCRIPT_WORK_ResetCheckFlag(u32);
extern u32 FIELDMAP_GetNogridMapper(u8 *p);
extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern int FIELD_CAMERA_HasDelay(u8 *a);
extern u32 FIELD_NOGRID_MAPPER_SetActive(u32, u32);
extern void SCRIPT_WORK_SetCheckFlag(int n);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void FIELD_CAMERA_PushState(u8 *a);
extern void FIELD_CAMERA_StopTargetTrace(u8 *p);
extern u16 VM_ReadU16(struct ScriptVm *vm);
extern u32 VM_GetU32(struct ScriptVm *vm);
extern void FIELD_CAMERA_StartMove(u8 *a, void *p, int n);
extern void ARC_TOOL_ReadMember(void *dst, u32 archive_id, u32 member);
extern void FIELD_CAMERA_StartMoveToSetting(u8 *p, u16 v);
extern void *FIELD_CAMERA_CreateShakeTask(void *a, struct Blk021D2D50 *src);
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GIMMICK_INIT_SetCartLanesFlags(void *a, u8 *b, u32 c);
extern u32 FIELD_FK_DEMO_GetCameraSettingId(u32 idx);
extern void FIELD_CAMERA_SetSetting(u32 *p, u32 v);
extern u32 FIELDMAP_GetMapFunc(u8 *p);
extern int *FIELD_SUBPROC_Start(int a, int *d, const int *c);
int SCRCMD_PROC_FLD_StepShopTask(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
void SCRCMD_PROC_FLD_InitShop(int ctx, ShopWork *a, int b, int c);
void SCRCMD_PROC_FLD_LoadShopMessages(ShopWork *w, int b);
u32 SCRCMD_PROC_FLD_GetShopCurrency(ShopWork *w);
void SCRCMD_PROC_FLD_PickQuantityOutcome(ShopWork *w);
void SCRCMD_PROC_FLD_PollItemList(ShopWork *p);
u8 SCRCMD_PROC_FLD_PollMessageEnd(ShopWork *p);
void SCRCMD_PROC_FLD_PayPrice(ShopWork *w, u32 b);
int SCRCMD_PROC_FLD_StepShop(u32 a, ShopWork *p, u32 c, u8 d);
u32 SCRCMD_PROC_FLD_LoadItemRows(ShopItem *items, int n);
void SCRCMD_PROC_FLD_SetItemSlot(ShopWork *p, int idx, int mode, int val, int arg);
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
void SCRCMD_PROC_FLD_PrintListText(void *a, u32 b, int c, int d, u32 e, u32 f, u16 g);
void SCRCMD_PROC_FLD_PrintPriceEntry(u8 *p, int a, u8 b);
void SCRCMD_PROC_FLD_PrintUniqueItemEntry(u32 ctx, int a, u8 b);
void SCRCMD_PROC_FLD_OnListCursorMove(u32 a, u32 idx);
void SCRCMD_PROC_FLD_FreeItemListMenu(ShopWork *w);
int SCRCMD_PROC_FLD_ReturnZero(void);
void SCRCMD_PROC_FLD_ShowItemMessage(ShopWork *p, u32 sel, u32 c, u32 d);
void SCRCMD_PROC_FLD_ShowConfirmMessage(ShopWork *w, u32 a);
void SCRCMD_PROC_FLD_PrepareMessageWindow(u32 a);
void SCRCMD_PROC_FLD_ShowMessage(ShopWork *w, u32 b);
void SCRCMD_PROC_FLD_ShowBuyConfirm(ShopWork *w, u32 a, u16 b, u32 c, u16 d);
void SCRCMD_PROC_FLD_ShowTmBuyConfirm(ShopWork *w, u32 a, u32 b, u32 c);
int SCRCMD_PROC_FLD_AdjustQuantity(s16 *p, int max, int key);
int SCRCMD_PROC_FLD_StepQuantitySelect(ShopWork *w);
void SCRCMD_PROC_FLD_SetQuantityMask(int i);
int SCRCMD_PROC_FLD_StoreGameSystemValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StoreSubObjectValueA(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StoreSubObjectValueB(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_CallOv006Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_CallOv004Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_CallOv001Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
void SCRCMD_PROC_FLD_FinishOv170Event(volatile Ov170EventHandoff *handoff);
int SCRCMD_PROC_FLD_CallOv170Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StartNameInMode5(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StartNameInMode6(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_SetNextEventAndEnd(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_CallSubProcWithFlag(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_CallOv219Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_CallShortcutEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_CallEventWithVarPtr(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_CallEventFromThreeValues(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_CallFieldMapEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StoreByteValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_CallEventMode4(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StoreCameraValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_SetFlagIfClear(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
u16 SCRCMD_PROC_FLD_AddUniqueU16(u16 *values, u16 count, u16 value);
int SCRCMD_PROC_FLD_StoreRandomUniqueEntry(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_ReleaseFieldRegion(void *fieldMap, void *fieldRegion);
int SCRCMD_PROC_FLD_ReleaseFieldRegionTask(void **eventWork);
int SCRCMD_PROC_FLD_BeginFieldRegionRelease(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_ReleaseFieldRegionCmd(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_ResetFieldRegionA(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_ResetFieldRegionB(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_SetFieldRegionFromStream(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_SetFieldRegionFromArchive(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_SetFieldRegionLayerFlags(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_SetFieldRegionValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_CallFieldRegionWaitEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_CallCustomEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_PollFieldRegionStart(void *event);
int SCRCMD_PROC_FLD_PollFieldRegionIdle(void *event);
int SCRCMD_PROC_FLD_CallOv056Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_SetOv056Slot(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_SetFieldRegionTable(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern const LayerFlags d_021D9738;
extern const u8 d_021D9440[];
extern u8 d_021D946C[];
extern u8 d_021D95DE[];
extern u16 *d_021DE1A8[];
extern ShopItem *d_021DE164[];
extern u8 d_021D9430[];
extern const ShopActorPlacement d_021D96E0;
extern const ShopActorPlacement d_021D96E8;
extern const ShopActorPlacement d_021D96F0;
extern const ShopActorPlacement d_021D96F8;
extern const ShopActorPlacement d_021D9700;
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
extern const char d_021DE234[];
extern const u16 d_021D98D0[];
extern u8 ov56_id[];
extern u32 g_021F4344[];
extern u32 g_021F4374[];
extern u32 g_021F438C[];
extern u32 g_021F435C[];






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
    fieldMap = ICA_ANIME_GetField20((void *)gameSystem);
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
        SCRCMD_SHOP_PrepareFieldCamera((u32 *)task, (u32)fieldMap, fieldRegion);
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
        if (SCRCMD_PROC_FLD_StepShop((u32)gameSystem, &task->shop, task->shopKind, task->shopVariant)) {
            task->state++;
        }
        break;
    case 5:
        layers = d_021D9738;
        FIELD_CAMERA_StartMoveToSaved(fieldRegion, (u8 *)(&layers), 8);
        task->state++;
        task->subState = 0;
        break;
    case 6:
        if (FIELD_CAMERA_IsMoving(fieldRegion) == 0) {
            FIELD_CAMERA_ResumeTargetTrace((u32)fieldRegion);
            FIELD_CAMERA_SetAreasEnabled(fieldRegion, task->fieldRegionArg);
            FIELD_CAMERA_RestartDelay(fieldRegion);
            FIELD_CAMERA_PopState(fieldRegion);
            FIELD_MSGBG_SetBlendThunk(1);
            task->state++;
        }
        break;
    case 7:
        func_020307B0(*slot);
        return 1;
    }
    return 0;
}






void SCRCMD_PROC_FLD_InitShop(int gameSystem, ShopWork *shop, int shopKind, int shopVariant)
{
    void *gameData = ICA_ANIME_GetField1C((void *)gameSystem);
    int tableKind;

    func_02012944(gameData);
    shop->isTmShop = 0;
    shopKind = SCRCMD_PROC_FLD_AllocShopResources(shop, shopKind);
    tableKind = shopKind;
    switch (tableKind) {
    case 255:
        GAME_DATA_GetMiscSave(gameData);
        SCRCMD_PROC_FLD_BuildItemListByBadges(shop, tableKind, shopVariant, BEACON_CountFlags());
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
        shop->priceFormat = func_02045EC0((struct MsgBank *)(shop->shopMsgBank), 0xd);
    } else {
        shop->priceFormat = func_02045EC0((struct MsgBank *)(shop->shopMsgBank), 0xc);
    }
    shop->soldOutText = func_02045EC0((struct MsgBank *)(shop->shopMsgBank), 0xe);
}




u32 SCRCMD_PROC_FLD_GetShopCurrency(ShopWork *shop)
{
    if (shop->usesBattlePoints == 0) {
        return BEACON_GetPoints((struct Blk34 *)(shop->moneyData));
    } else {
        return GDS_PROFILE_GetScoreRecTotal((struct Blk1AC *)(shop->battlePointData));
    }
}








void SCRCMD_PROC_FLD_PickQuantityOutcome(ShopWork *shop)
{
    u32 money;
    u32 ownedCount;
    u32 price;

    money = SCRCMD_PROC_FLD_GetShopCurrency(shop);
    ownedCount = func_02007FB8((u8 *)(shop->bagData), shop->itemId, shop->heapId);
    if (func_02007E3C((u8 *)(shop->bagData), shop->itemId, 1, shop->heapId) == 0) {
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
        if (shop->maxQuantity + ownedCount > func_0200823C(shop->itemId)) {
            shop->maxQuantity = func_0200823C(shop->itemId) - ownedCount;
        }
    } else {
        SCRCMD_PROC_FLD_ShowConfirmMessage(shop, shop->isTmShop);
        shop->state = SHOP_STATE_MESSAGE_WAIT;
        shop->nextState = SHOP_STATE_YESNO_OPEN_NOICON;
    }
}









void SCRCMD_PROC_FLD_PollItemList(ShopWork *shop)
{
    void *window;
    int selection;
    ShopWork *row;

    if (PRINTSYS_QUE_IsFinished(shop->printSys) == 0) {
        return;
    }
    if (shop->introShown == 0) {
        window = (void *)shop->windows[SHOP_WIN_LIST];
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
        BEACON_SubPoints((struct Blk34 *)(shop->moneyData), cost);
        func_02008DAC((struct Sub02008C20Obj *)(shop->recordData), 0x16, cost);
    } else {
        GDS_PROFILE_SubScoreRecTotal((struct Blk1AC *)(shop->battlePointData), cost);
        func_02008DAC((struct Sub02008C20Obj *)(shop->recordData), 0x22, cost);
    }
    func_02008DF0((struct Sub02008C20Obj *)(shop->recordData), 0x15);
}









/*
 * Addresses are Black-image addresses.
 */
int SCRCMD_PROC_FLD_StepShop(u32 gameSystem, ShopWork *shop, u32 shopKind, u8 shopVariant)
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
        CLACT_SetActorDrawEnable((struct Obj *)shop->quantityArrowActor, 1);
        shop->state = SHOP_STATE_QUANTITY_STEP;
        break;
    case SHOP_STATE_QUANTITY_STEP:
        shop->state = SCRCMD_PROC_FLD_StepQuantitySelect(shop);
        break;
    case SHOP_STATE_LIST_RESUME:
        SCRCMD_PROC_FLD_SetQuantityMask(0);
        BMP_WIN_MakeScreen((struct Cfg *)(shop->windows[SHOP_WIN_LIST]));
        BMP_WIN_MakeScreen((struct Cfg *)(shop->windows[SHOP_WIN_DESCRIPTION]));
        func_02041B6C(1);
        CLACT_SetActorDrawEnable((struct Obj *)shop->quantityArrowActor, 0);
        BMP_MENULIST_Redraw((u8 *)(shop->listMenu));
        shop->state = SHOP_STATE_LIST_POLL;
        break;
    case SHOP_STATE_YESNO_OPEN:
        SCRCMD_PROC_FLD_SetQuantityMask(1);
        BMP_WIN_MakeScreen((struct Cfg *)(shop->windows[SHOP_WIN_LIST]));
        CLACT_SetActorDrawEnable((struct Obj *)shop->quantityArrowActor, 0);
        shop->yesNoMenu = BMP_MENU_CreateYesNo(d_021D9440, 1, 9, 0, shop->heapId);
        if (shop->isTmShop != 1) {
            SCRCMD_PROC_FLD_PrintOwnedWindow(shop, shop->itemId);
        }
        shop->state = SHOP_STATE_YESNO_POLL;
        break;
    case SHOP_STATE_YESNO_OPEN_NOICON:
        SCRCMD_PROC_FLD_SetQuantityMask(1);
        BMP_WIN_MakeScreen((struct Cfg *)(shop->windows[SHOP_WIN_LIST]));
        CLACT_SetActorDrawEnable((struct Obj *)shop->quantityArrowActor, 0);
        shop->yesNoMenu = BMP_MENU_CreateYesNo(d_021D9440, 1, 9, 0, shop->heapId);
        shop->state = SHOP_STATE_YESNO_POLL;
        break;
    case SHOP_STATE_YESNO_POLL:
        selection = BMP_MENU_ProcessYesNo((u8 *)(shop->yesNoMenu));
        if (selection == -1) {
        } else if (selection == 0) {
            shop->state = SHOP_STATE_PURCHASE;
            SCRCMD_PROC_FLD_SetQuantityMask(1);
            BMP_MENULIST_Redraw((u8 *)(shop->listMenu));
            BMP_WIN_MakeScreen((struct Cfg *)(shop->windows[SHOP_WIN_LIST]));
            func_02041B6C(1);
        } else if (selection == -2) {
            shop->state = SHOP_STATE_LIST_RESUME;
        }
        break;
    case SHOP_STATE_PURCHASE:
        GFL_USE_PlaySeDefaultVolume(0x655);
        SCRCMD_PROC_FLD_ShowItemMessage(shop, 9, shop->itemId, *(s16 *)&shop->quantity > 1);
        SCRCMD_PROC_FLD_PayPrice(shop, shop->price * *(s16 *)&shop->quantity);
        SCRCMD_PROC_FLD_PrintMoneyWindow(shop);
        func_02007E50((u8 *)(shop->bagData), shop->itemId, shop->quantity, shop->heapId);
        shop->state = SHOP_STATE_MESSAGE_WAIT;
        shop->nextState = SHOP_STATE_BONUS_ITEM;
        break;
    case SHOP_STATE_BONUS_ITEM:
        if (shop->itemId == 4 && *(s16 *)&shop->quantity >= 10) {
            SCRCMD_PROC_FLD_ShowItemMessage(shop, 15, shop->itemId, *(s16 *)&shop->quantity > 1);
            func_02007E50((u8 *)(shop->bagData), 12, 1, shop->heapId);
            func_02008DF0((struct Sub02008C20Obj *)(shop->recordData), 0x1F);
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
    PRINTSYS_QUE_Main((struct PrintSys *)(shop->printSys));
    printSys = shop->printSys;
    if (shop->printerBusy != 0 && PRINTSYS_QUE_IsExistTarget((struct PrintSys *)printSys, (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)shop->listWindow))) == 0) {
        BMP_WIN_TransferChars((struct Descriptor *)shop->listWindow);
        shop->printerBusy = 0;
    }
    TCBL_Main((struct Tcbl *)(shop->tcbList));
    TCBL_Main((struct Tcbl *)(shop->tcbList));
    return 0;
}









u32 SCRCMD_PROC_FLD_LoadItemRows(ShopItem *items, int count)
{
    u32 result = FILE_UTIL_Check1288(items[0].itemId);
    int i;

    for (i = 0; i < count; i++) {
        FILE_UTIL_Check1288(items[i].itemId);
    }
    return result;
}








void SCRCMD_PROC_FLD_SetItemSlot(ShopWork *shop, int slotIndex, int isTmShop, int itemId, int msgBank)
{
    if (isTmShop == 1) {
        WORDSET_SetSlotNumber(shop->wordSet, 0, itemId - 327, 2, 2, 1);
        WORDSET_SetSlotFromMsgCB(shop->wordSet, 1, FILE_UTIL_Get_12B0((u16)itemId));
        WORDSET_CopyTaggedText(shop->wordSet, shop->textBuffer, shop->cancelText);
        BMP_MENUWORK_AddStrItem((struct Slot *)((char *)shop->itemSlots + slotIndex * 8), (u32)(shop->textBuffer), slotIndex, shop->heapId);
    } else {
        BMP_MENUWORK_AddMsgItem((struct Slot *)((char *)shop->itemSlots + slotIndex * 8), msgBank, itemId, slotIndex, shop->heapId);
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
    void *msgBank = func_02045B38(0, 2, 54, shop->heapId);
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
    if (FILE_UTIL_Check1288(**(u16 **)((char *)d_021DE1A8 + tableOffset))) {
        shop->isTmShop = 1;
        tableOffset = tableIndex * 4;
    }
    itemCount = d_021D95DE[tableIndex];
    shop->itemSlots = BMP_MENUWORK_Create(itemCount + 1, shop->heapId);
    for (row = 0; row < itemCount; row++) {
        itemId = (*(u16 **)((char *)d_021DE1A8 + tableOffset))[row];
        SCRCMD_PROC_FLD_SetItemSlot(shop, row, shop->isTmShop, itemId, (int)msgBank);
        /* stand-in: the row is reached as base + row * 8 plus the field offset */
        rowBase = (ShopWork *)((char *)shop + row * 8);
        rowBase->items[0].itemId = itemId;
        rowBase->items[0].price = GPOWER_ApplyShopPrice(FILE_UTIL_Get_0FE4((void *)itemId, 0, shop->heapId));
    }
    shop->itemCount = row;
    SCRCMD_PROC_FLD_LoadItemRows(shop->items, shop->itemCount);
    BMP_MENUWORK_AddMsgItem((struct Slot *)((char *)shop->itemSlots + row * 8), (u32)(shop->shopMsgBank), 11, -2, shop->heapId);
    MSGDATA_Delete(msgBank);
}








void SCRCMD_PROC_FLD_BuildItemListFixed(ShopWork *shop, int tableIndex)
{
    int row;
    ShopItem *table;
    u32 msgBank;
    int itemCount;

    row = 0;
    msgBank = (u32)func_02045B38(0, 2, 0x36, shop->heapId);
    table = d_021DE164[tableIndex];
    itemCount = d_021D9430[tableIndex];
    shop->itemSlots = BMP_MENUWORK_Create(itemCount + 1, shop->heapId);
    for (; row < itemCount; row++) {
        SCRCMD_PROC_FLD_SetItemSlot(shop, row, shop->isTmShop, table[row].itemId, msgBank);
        shop->items[row].itemId = table[row].itemId;
        shop->items[row].price = table[row].price;
    }
    shop->itemCount = row;
    BMP_MENUWORK_AddMsgItem((struct Slot *)((char *)shop->itemSlots + row * 8), (u32)shop->shopMsgBank, 0xb, -2, shop->heapId);
    MSGDATA_Delete((struct Rec *)msgBank);
}








void SCRCMD_PROC_FLD_BuildItemListFromRange(ShopWork *shop, int kind)
{
    int row = 0;
    void *msgBank = func_02045B38(0, 2, 54, shop->heapId);

    FIELD_WFBC_DATA_LOCAL_FillPeopleListEntries((char *)shop->shopTable, (char *)shop->items, &shop->itemCount, kind - 247, shop->heapId);
    shop->itemSlots = BMP_MENUWORK_Create(shop->itemCount + 1, shop->heapId);
    for (; row < shop->itemCount; row++) {
        SCRCMD_PROC_FLD_SetItemSlot(shop, row, shop->isTmShop, shop->items[row].itemId, (int)msgBank);
    }
    BMP_MENUWORK_AddMsgItem((struct Slot *)((char *)shop->itemSlots + row * 8), (u32)(shop->shopMsgBank), 11, -2, shop->heapId);
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
    shop->shopMsgBank = func_02045B38(0, 3, 423, shop->heapId);
    shop->itemMsgBank = func_02045B38(0, 2, 53, shop->heapId);
    shop->wordSet = WORDSET_CreateDefault(shop->heapId);
    shop->textBuffer = STRBUF_Create(200, shop->heapId);
    shop->tcbList = TCBL_Create(shop->heapId, shop->heapId, 32, 32);
    shop->cancelText = func_02045EC0(shop->shopMsgBank, 29);
    return shopKind;
}








void SCRCMD_PROC_FLD_FreeShopResources(ShopWork *shop)
{
    TCBL_Destroy(shop->tcbList);
    WORDSET_DeleteStrbufED04(shop->wordSet);
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
    archive = func_020490F4(54, shop->heapId);
    func_02049B68(archive, 1, 0, 0, 96, shop->heapId);
    func_02049658(archive, 0, 2, 100, 0, 0, shop->heapId);
    func_02049990(archive, 2, 2, 0, 100, 0, 0, shop->heapId);
    ARC_TOOL_DeleteHandle(archive);
    BMP_MENUWORK_LoadCharAndPltt(1, 228, 9, 0, shop->heapId);
    BG_SYS_ClearSlot(1);
    BG_SYS_SetVisibleLayer(2, 1);
}








void SCRCMD_PROC_FLD_ExitShopGraphics(ShopWork *shop)
{
    BG_SYS_ClearSlot(1);
    BG_SYS_ClearSlot(2);
    BG_SYS_SetVisibleLayer(2, 0);
    FIELD_MSGBG_SetBlendThunk(1);
}








void SCRCMD_PROC_FLD_LoadCursorResources(ShopWork *shop)
{
    void *archive = func_020490F4(54, shop->heapId);

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
    u32 plttData;
    u32 charData;
    u32 charBuf;
    u32 plttBuf;

    if (itemId <= 0x272) {
        charBuf = (u32)func_02049F78((void *)(shop->iconArchive), FILE_UTIL_Get(itemId, 2), (u32)(&charData), shop->heapId);
        plttBuf = (u32)func_02049E74((void *)(shop->iconArchive), FILE_UTIL_Get(itemId, 1), 0, (u32)(&plttData), shop->heapId);
        CLACT_TransferPalette(shop->iconCharRes, charData, 1);
        CLACT_TransferCharacter(shop->iconPlttRes, (struct Sub0204A9D0 *)plttData);
        func_020307B0((void *)charBuf);
        func_020307B0((void *)plttBuf);
        CLACT_SetActorDrawEnable((struct Obj *)shop->iconActor, 1);
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)shop->iconActor, 0);
    }
}







void SCRCMD_PROC_FLD_CreateShopActors(ShopWork *shop)
{
    shop->cursorActor = (int)CLACT_CreateActor((void *)shop->cellSystem, shop->cursorPlttRes, shop->arrowCharRes,
                                        shop->cursorCellRes, &d_021D96E0, 0, shop->heapId);
    shop->arrowUpActor = (int)CLACT_CreateActor((void *)shop->cellSystem, shop->arrowPlttRes, shop->arrowCharRes,
                                        shop->arrowCellRes, &d_021D96E8, 0, shop->heapId);
    shop->arrowDownActor = (int)CLACT_CreateActor((void *)shop->cellSystem, shop->arrowPlttRes, shop->arrowCharRes,
                                        shop->arrowCellRes, &d_021D96F0, 0, shop->heapId);
    shop->quantityArrowActor = (int)CLACT_CreateActor((void *)shop->cellSystem, shop->arrowPlttRes, shop->arrowCharRes,
                                        shop->arrowCellRes, &d_021D96F8, 0, shop->heapId);
    CLACT_SetActorAutoAnim((struct Obj *)shop->quantityArrowActor, 1);
    shop->iconActor = (int)CLACT_CreateActor((void *)shop->cellSystem, shop->iconPlttRes, shop->iconCharRes,
                                        shop->iconCellRes, &d_021D9700, 0, shop->heapId);
    CLACT_SetActorDrawEnable((struct Obj *)shop->arrowUpActor, 0);
    CLACT_SetActorDrawEnable((struct Obj *)shop->arrowDownActor, 0);
    CLACT_SetActorDrawEnable((struct Obj *)shop->quantityArrowActor, 0);
}







void SCRCMD_PROC_FLD_InitShopCells(ShopWork *shop)
{
    shop->cellSystem = CLACT_CreateUnit(5, 1, shop->heapId);
    CLACT_SetUnitDrawEnable((struct Bank *)(shop->cellSystem), 1);
    SCRCMD_PROC_FLD_LoadCursorResources(shop);
    shop->iconArchive = func_020490F4(0x19, shop->heapId);
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
    u32 headerText;
    u32 window;

    templates = d_021DE18C;
    if (shop->usesBattlePoints != 1) {
        templates = d_021DE170;
    }
    for (i = 0; i < SHOP_WIN_COUNT; i++) {
        template = templates[i];
        shop->windows[i] = BMP_WIN_Create((u8)template->bgId, template->x, template->y, template->width, template->height, (u8)template->paletteNum, 1);
    }
    headerText = (u32)func_02045EC0((struct MsgBank *)(shop->shopMsgBank), 0x14);
    PRINTSYS_PrintColor((void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)shop->windows[SHOP_WIN_HEADER])), 0, 0, (void *)headerText, (void *)(shop->fontInfo), 0x3C4F);
    STRBUF_Delete((struct U16Vec *)headerText);
    shop->listWindow = shop->windows[SHOP_WIN_LIST];
    shop->printerBusy = 0;
    shop->printSys = (void *)PRINTSYS_QUE_Create((void *)(shop->heapId));
    if (shop->usesBattlePoints == 1) {
        window = shop->windows[SHOP_WIN_MONEY];
        BMP_WIN_TransferChars((struct Descriptor *)window);
        BMP_WIN_MakeScreen((struct Cfg *)window);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)window));
    } else {
        window = shop->windows[SHOP_WIN_HEADER];
        BMP_WIN_TransferChars((struct Descriptor *)window);
        BMP_WIN_MakeScreen((struct Cfg *)window);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)window));
        window = shop->windows[SHOP_WIN_MONEY];
        BMP_WIN_TransferChars((struct Descriptor *)window);
        BMP_WIN_MakeScreen((struct Cfg *)window);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)window));
    }
}







void SCRCMD_PROC_FLD_FreeShopWindows(ShopWork *shop)
{
    int i;

    PRINTSYS_QUE_Clear((struct PrintSys *)(shop->printSys));
    PRINTSYS_QUE_Delete((struct PrintSys *)(shop->printSys));
    for (i = 0; i < SHOP_WIN_COUNT; i++) {
        BMP_WIN_Delete((struct Descriptor *)(shop->windows[i]));
    }
}







void SCRCMD_PROC_FLD_PrintMoneyWindow(ShopWork *shop)
{
    u32 formatText, expandedText, bitmap, window;

    if (shop->usesBattlePoints == 1) {
        formatText = (u32)func_02045EC0((struct MsgBank *)(shop->shopMsgBank), 0x16);
        expandedText = (u32)STRBUF_Create(10, shop->heapId);
        WORDSET_SetSlotNumber((struct WordSet *)(shop->wordSet), 0, GDS_PROFILE_GetScoreRecTotal((struct Blk1AC *)(shop->battlePointData)), 4, 1, 1);
    } else {
        formatText = (u32)func_02045EC0((struct MsgBank *)(shop->shopMsgBank), 0x15);
        expandedText = (u32)STRBUF_Create(10, shop->heapId);
        WORDSET_SetSlotNumber((struct WordSet *)(shop->wordSet), 0, BEACON_GetPoints((struct Blk34 *)(shop->moneyData)), 7, 1, 1);
    }
    WORDSET_CopyTaggedText((struct WordSet *)(shop->wordSet), (void *)expandedText, (void *)formatText);
    bitmap = (u32)BMP_WIN_GetBmp((struct Descriptor *)shop->windows[SHOP_WIN_MONEY]);
    BMP_Clear((struct CharBuf *)bitmap, 0);
    PRINTSYS_PrintColor((void *)bitmap, 0, 0, (void *)expandedText, (void *)(shop->fontInfo), 0x3C4F);
    window = shop->windows[SHOP_WIN_MONEY];
    BMP_WIN_TransferChars((struct Descriptor *)window);
    BMP_WIN_MakeScreen((struct Cfg *)window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)window));
    STRBUF_Delete((struct U16Vec *)expandedText);
    STRBUF_Delete((struct U16Vec *)formatText);
}







/*
 * The spilled second parameter is a u16 (SCRCMD_PROC_FLD_PickQuantityOutcome passes a u16 field
 * to func_02007FB8 in the same slot): as u32 its entry spill
 * `str r1, [sp, #8]` lands after the `lsls` instead of before it.
 *
 * Addresses are Black-image addresses.
 */
void SCRCMD_PROC_FLD_PrintOwnedWindow(ShopWork *shop, u16 itemId)
{
    u32 formatText, expandedText, bitmap, window;

    formatText = (u32)func_02045EC0((struct MsgBank *)(shop->shopMsgBank), 0x17);
    expandedText = (u32)STRBUF_Create(0x14, shop->heapId);
    BMP_MENUWORK_DrawWindow((void *)(shop->windows[SHOP_WIN_OWNED]), 2, 0xE4, 9);
    WORDSET_SetSlotNumber((struct WordSet *)(shop->wordSet), 0, func_02007FB8((u8 *)(shop->bagData), itemId, shop->heapId), 3, 0, 1);
    WORDSET_CopyTaggedText((struct WordSet *)(shop->wordSet), (void *)expandedText, (void *)formatText);
    bitmap = (u32)BMP_WIN_GetBmp((struct Descriptor *)shop->windows[SHOP_WIN_OWNED]);
    BMP_Clear((struct CharBuf *)bitmap, 0xF);
    PRINTSYS_PrintColor((void *)bitmap, 0, 0, (void *)expandedText, (void *)(shop->fontInfo), 0x44F);
    window = shop->windows[SHOP_WIN_OWNED];
    BMP_WIN_TransferChars((struct Descriptor *)window);
    BMP_WIN_MakeScreen((struct Cfg *)window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)window));
    STRBUF_Delete((struct U16Vec *)expandedText);
    STRBUF_Delete((struct U16Vec *)formatText);
}







void SCRCMD_PROC_FLD_PrintItemDescription(ShopWork *shop, u32 itemId)
{
    u32 bitmap;
    u32 text;
    u32 window;

    bitmap = (u32)BMP_WIN_GetBmp((struct Descriptor *)shop->windows[SHOP_WIN_DESCRIPTION]);
    BMP_Clear((struct CharBuf *)bitmap, 0);
    if (itemId <= 0x272) {
        text = (u32)func_02045EC0((struct MsgBank *)(shop->itemMsgBank), itemId);
        PRINTSYS_PrintColor((void *)bitmap, 0, 0, (void *)text, (void *)(shop->fontInfo), 0x3C40);
        STRBUF_Delete((struct U16Vec *)text);
    }
    window = shop->windows[SHOP_WIN_DESCRIPTION];
    BMP_WIN_TransferChars((struct Descriptor *)window);
    BMP_WIN_MakeScreen((struct Cfg *)window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)window));
}







void SCRCMD_PROC_FLD_PrintQuantityWindow(ShopWork *shop, u32 quantity, u32 price)
{
    u32 quantityFormat, totalFormat, text, bitmap, window;

    quantityFormat = (u32)func_02045EC0((struct MsgBank *)(shop->shopMsgBank), 0x18);
    totalFormat = (u32)func_02045EC0((struct MsgBank *)(shop->shopMsgBank), d_021D945C[shop->usesBattlePoints]);
    text = (u32)STRBUF_Create(0x14, shop->heapId);
    bitmap = (u32)BMP_WIN_GetBmp((struct Descriptor *)shop->windows[SHOP_WIN_QUANTITY]);
    BMP_Clear((struct CharBuf *)bitmap, 0xF);
    BMP_MENUWORK_DrawWindow((void *)(shop->windows[SHOP_WIN_QUANTITY]), 2, 0xE4, 9);
    WORDSET_SetSlotNumber((struct WordSet *)(shop->wordSet), 0, quantity, 2, 0, 1);
    WORDSET_CopyTaggedText((struct WordSet *)(shop->wordSet), (void *)text, (void *)quantityFormat);
    PRINTSYS_PrintColor((void *)bitmap, 0, 0, (void *)text, (void *)(shop->fontInfo), 0x44F);
    WORDSET_SetSlotNumber((struct WordSet *)(shop->wordSet), 0, quantity * price, 7, 1, 1);
    WORDSET_CopyTaggedText((struct WordSet *)(shop->wordSet), (void *)text, (void *)totalFormat);
    if (shop->usesBattlePoints == 0) {
        PRINTSYS_PrintColor((void *)bitmap, 0x23, 0, (void *)text, (void *)(shop->fontInfo), 0x44F);
    } else {
        PRINTSYS_PrintColor((void *)bitmap, 0x1D, 0, (void *)text, (void *)(shop->fontInfo), 0x44F);
    }
    window = shop->windows[SHOP_WIN_QUANTITY];
    BMP_WIN_TransferChars((struct Descriptor *)window);
    BMP_WIN_MakeScreen((struct Cfg *)window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)window));
    STRBUF_Delete((struct U16Vec *)text);
    STRBUF_Delete((struct U16Vec *)totalFormat);
    STRBUF_Delete((struct U16Vec *)quantityFormat);
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
    shop->listMenu = BMP_MENULIST_Create((struct Src *)(&listTemplate), 0, 0, shop->heapId);
}






void SCRCMD_PROC_FLD_PrintListText(void *printSys, u32 bitmap, int x, int y, u32 text, u32 fontInfo, u16 colorBits)
{
    if (y <= 8) {
        PRINTSYS_PrintColor((void *)bitmap, x, y, (void *)text, (void *)fontInfo, colorBits);
    } else {
        PRINTSYS_PrintQueColor(printSys, bitmap, (s16)x, (s16)y, text, fontInfo, (u32)colorBits);
    }
}






/*
 * Twin of SCRCMD_PROC_FLD_PrintUniqueItemEntry (its else arm alone). The u8 third parameter is
 * what keeps the reload of its spill slot just before the last call; as u32
 * the reload is hoisted above the hi - lo subtraction. The first parameter
 * is forwarded untouched to func_02020D0C.
 *
 * Addresses are Black-image addresses.
 */
void SCRCMD_PROC_FLD_PrintPriceEntry(u8 *listMenu, int row, u8 y)
{
    ShopWork *shop;
    u32 textWidth;
    int windowWidth;

    shop = (ShopWork *)func_02020D0C(listMenu);
    if (row != -2) {
        WORDSET_SetSlotNumber((struct WordSet *)(shop->wordSet), 1, shop->items[row].price, 5, 0, 1);
        WORDSET_CopyTaggedText((struct WordSet *)(shop->wordSet), (void *)(shop->textBuffer), (void *)(shop->priceFormat));
        textWidth = func_0201D304((struct StrObj *)(shop->textBuffer), shop->fontInfo, 0);
        windowWidth = BMP_GetWidth((const struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)shop->windows[SHOP_WIN_LIST])));
        SCRCMD_PROC_FLD_PrintListText((void *)(shop->printSys), (u32)BMP_WIN_GetBmp((struct Descriptor *)shop->windows[SHOP_WIN_LIST]), windowWidth - textWidth, y,
                      (u32)shop->textBuffer, shop->fontInfo, 0x31A0);
    }
}






/*
 * The u8 third parameter (a list-cursor callback's on-init flag) is what
 * moves the reload of its spill slot to just before the last call; as int or
 * u32 the reload is hoisted above the hi - lo subtraction.
 */
void SCRCMD_PROC_FLD_PrintUniqueItemEntry(u32 listMenu, int row, u8 y)
{
    ShopWork *shop;
    u32 textWidth;
    int windowWidth;

    shop = (ShopWork *)func_02020D0C((void *)listMenu);
    if (row != -2) {
        if (func_02007F68((u8 *)(shop->bagData), shop->items[row].itemId, 1, shop->heapId) != 0) {
            textWidth = func_0201D304((struct StrObj *)(shop->soldOutText), shop->fontInfo, 0);
            windowWidth = BMP_GetWidth((const struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)shop->windows[SHOP_WIN_LIST])));
            SCRCMD_PROC_FLD_PrintListText((void *)(shop->printSys), (u32)BMP_WIN_GetBmp((struct Descriptor *)shop->windows[SHOP_WIN_LIST]), windowWidth - textWidth, y,
                          (u32)shop->soldOutText, shop->fontInfo, 0x31A0);
        } else {
            WORDSET_SetSlotNumber((struct WordSet *)(shop->wordSet), 1, shop->items[row].price, 5, 1, 1);
            WORDSET_CopyTaggedText((struct WordSet *)(shop->wordSet), (void *)(shop->textBuffer), (void *)(shop->priceFormat));
            textWidth = func_0201D304((struct StrObj *)(shop->textBuffer), shop->fontInfo, 0);
            windowWidth = BMP_GetWidth((const struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)shop->windows[SHOP_WIN_LIST])));
            SCRCMD_PROC_FLD_PrintListText((void *)(shop->printSys), (u32)BMP_WIN_GetBmp((struct Descriptor *)shop->windows[SHOP_WIN_LIST]), windowWidth - textWidth, y,
                          (u32)shop->textBuffer, shop->fontInfo, 0x31A0);
        }
    }
}






void SCRCMD_PROC_FLD_OnListCursorMove(u32 listMenu, u32 row)
{
    u16 cursorPos[4];
    ShopWork *shop;
    ShopItem *items;

    shop = (ShopWork *)func_02020D0C((void *)listMenu);
    func_020202FC((struct Obj *)listMenu, &cursorPos[1], &cursorPos[0]);
    cursorPos[2] = 0xAC;
    cursorPos[3] = cursorPos[0] * 16 + 0x16;
    CLACT_AddActorSurfacePos((struct Obj *)(shop->cursorActor), (const struct Vec2 *)(&cursorPos[2]), 0);
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

    BMP_MENULIST_Delete((struct Obj *)(shop->listMenu), &scrollPos, &cursorPos);
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
    u32 messageText;
    u32 window;

    if (messageId == 9 && plural != 0)
        isPlural = 1;
    else
        isPlural = 0;
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)shop->windows[SHOP_WIN_MESSAGE])), 0xf);
    BMP_MENUWORK_DrawWindow((void *)(shop->windows[SHOP_WIN_MESSAGE]), 0, 0xe4, 9);
    WORDSET_SetSlotFromBank((struct WordSet *)(shop->wordSet), 0, itemId, isPlural, 0);
    WORDSET_SetSlotFromMsg37((struct WordSet *)(shop->wordSet), 1, FILE_UTIL_Get_0FE4((void *)itemId, 5, shop->heapId));
    messageText = (u32)func_02045EC0((struct MsgBank *)(shop->shopMsgBank), messageId);
    WORDSET_CopyTaggedText((struct WordSet *)(shop->wordSet), (void *)(shop->textBuffer), (void *)messageText);
    STRBUF_Delete((struct U16Vec *)messageText);
    shop->messagePrinter = PRINTSYS_PrintStreamCallBack(shop->windows[SHOP_WIN_MESSAGE], 0, 0, (u32)shop->textBuffer,
                                        shop->fontInfo, MSG_SPEED_GetWait(),
                                        (u32)shop->tcbList, 0, shop->heapId, 0xffff,
                                        (u32)SCRCMD_PROC_FLD_ReturnZero);
    window = shop->windows[SHOP_WIN_MESSAGE];
    BMP_WIN_TransferChars((struct Descriptor *)window);
    BMP_WIN_MakeScreen((struct Cfg *)window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)window));
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
void SCRCMD_PROC_FLD_PrepareMessageWindow(u32 window)
{
BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)window)), 15);
    BMP_MENUWORK_DrawWindow((void *)window, 0, 228, 9);
}




void SCRCMD_PROC_FLD_ShowMessage(ShopWork *shop, u32 messageId)
{
    u32 messageText;
    u32 window;

    messageText = (u32)func_02045EC0((struct MsgBank *)(shop->shopMsgBank), messageId);
    WORDSET_CopyTaggedText((struct WordSet *)(shop->wordSet), (void *)(shop->textBuffer), (void *)messageText);
    STRBUF_Delete((struct U16Vec *)messageText);
    shop->messagePrinter = PRINTSYS_PrintStreamCallBack(shop->windows[SHOP_WIN_MESSAGE], 0, 0, (u32)shop->textBuffer,
                                        shop->fontInfo, MSG_SPEED_GetWait(), (u32)shop->tcbList, 0,
                                        shop->heapId, 0xFFFF, 0);
    window = shop->windows[SHOP_WIN_MESSAGE];
    BMP_WIN_TransferChars((struct Descriptor *)window);
    BMP_WIN_MakeScreen((struct Cfg *)window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)window));
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
    WORDSET_SetSlotFromBank((struct WordSet *)(shop->wordSet), 0, itemId, 0, 0);
    WORDSET_SetSlotNumber((struct WordSet *)(shop->wordSet), 1, quantity, 2, 0, 1);
    WORDSET_SetSlotNumber((struct WordSet *)(shop->wordSet), 2, quantity * price, 7, 0, 1);
    SCRCMD_PROC_FLD_ShowMessage(shop, messageId);
}




void SCRCMD_PROC_FLD_ShowTmBuyConfirm(ShopWork *shop, u32 messageId, u32 itemId, u32 price)
{
    SCRCMD_PROC_FLD_PrepareMessageWindow(shop->windows[SHOP_WIN_MESSAGE]);
    WORDSET_SetSlotNumber((struct WordSet *)(shop->wordSet), 0, itemId - 327, 2, 2, 1);
    WORDSET_SetSlotFromMsgCB((struct WordSet *)(shop->wordSet), 1, FILE_UTIL_Get_12B0(itemId));
    WORDSET_SetSlotNumber((struct WordSet *)(shop->wordSet), 2, price, 5, 0, 1);
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




int SCRCMD_PROC_FLD_StoreGameSystemValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);

    *resultVar = FIELDMAP_GetCommKind((void *)ICA_ANIME_GetField24(gameSystem));
    return 1;
}




int SCRCMD_PROC_FLD_StoreSubObjectValueA(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
*SCRIPT_WORK_ReadWorkPointer(vm, cmdWork) = func_02009CE4((struct Sub020097BCObj *)GAME_DATA_GetField1A0(SCRCMD_WORK_GetGameData(cmdWork)));
return 0;
}




int SCRCMD_PROC_FLD_StoreSubObjectValueB(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
*SCRIPT_WORK_ReadWorkPointer(vm, cmdWork) = func_02009A34((struct Sub020097BCObj *)GAME_DATA_GetField1A0(SCRCMD_WORK_GetGameData(cmdWork)));
return 0;
}




int SCRCMD_PROC_FLD_CallOv006Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    FieldEventArgs args;
    void *scriptWork;
    void *gameSystem;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    args.fieldMap = ICA_ANIME_GetField20(gameSystem);
    args.reserved = 0;
    SCRIPT_SYS_CallEvent(scriptWork, GAME_EVENT_CreateOverlayEvent(gameSystem, (u32)abs_id_6, (void *)EVENT_WIFICLUB_Entry, (u32)(&args)));
    return 1;
}




int SCRCMD_PROC_FLD_CallOv004Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    FieldEventArgs args;
    void *scriptWork;
    void *gameSystem;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    args.fieldMap = ICA_ANIME_GetField20(gameSystem);
    args.reserved = 0;
    SCRIPT_SYS_CallEvent(scriptWork, GAME_EVENT_CreateOverlayEvent(gameSystem, (u32)abs_id_4, (void *)EVENT_WORLDTRADE_Entry, (u32)(&args)));
    return 1;
}




/*
 * 2026-10-02: closed by seeding ov001 0x02154694 (Thumb tail-call thunk to
 * EVENT_GTSNEGO_Create, filed as ov001_func_02154694.c). Old note: it sat inside ov001 pool_02154690
 * (ldr r3,[pc]; bx r3; .word EVENT_GTSNEGO_Create+1) so sole-ref/code finds no func_ label;
 * abs_id_01 is the overlay id 1 that GAME_EVENT_CreateOverlayEvent loads (not an OVERLAY_ID_CONSUMER).
 *
 * Addresses are Black-image addresses.
 */
int SCRCMD_PROC_FLD_CallOv001Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork;
    void *gameSystem;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    SCRIPT_SYS_CallEvent(scriptWork, GAME_EVENT_CreateOverlayEvent(gameSystem, (u32)abs_id_01, (u32 (*)(void *, u32))EVENT_GTSNEGO_Entry, (u32)ICA_ANIME_GetField20(gameSystem)));
    return 1;
}




void SCRCMD_PROC_FLD_FinishOv170Event(volatile Ov170EventHandoff *handoff)
{
    u32 resultFlag;
    u32 result;
    Ov170EventWork *work;

    if (handoff->work->kind == 4) {
        BATTLE_BOX_StoreParty(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl((struct Big *)handoff->gameData)), (u8 *)handoff->work->party);
    }
    work = handoff->work;
    if (work->kind == 4) {
        func_020307B0(work->party);
    }
    result = handoff->work->result;
    if (result == 0 || result != 1)
        resultFlag = 0;
    else
        resultFlag = 1;
    *handoff->resultVar = resultFlag;
    func_020307B0(handoff->work);
}




/*
 * Script command: builds a 0x2C-byte work (save handles, the hand-off kind
 * at +0x24) and a 12-byte hand-off record, then launches overlay 0xAA
 * (ov170) over them through FIELD_STATUS_CreateSubProcNoFadeCallbackEvent with the SCRCMD_PROC_FLD_FinishOv170Event callback
 * and parks the task in the script's slot.  Same shape as the ov010
 * pending func_0215C7E0.
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
 * p[2] of the item func_020122C0 creates, the same shape as the
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
    gameData = ICA_ANIME_GetField1C(gameSystem);
    saveControl = GAME_DATA_GetSaveControl(gameData);
    saveStateSource = ZUKAN_SAVE_GetFromGameData(gameData);
    fieldMap = ICA_ANIME_GetField20(gameSystem);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    kind = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    vm = func_02030734(4, 0x2c, 0, d_021DE220, 0x7c);
    work = (Ov170EventWork *)vm;
    work->gameData = gameData;
    work->boxManager = GAME_DATA_GetBoxManager(gameData);
    work->party = GAME_DATA_GetMyParty(gameData);
    work->myItem = (u32)GAME_DATA_GetMyItem(gameData);
    work->myStatus = func_02012944(gameData);
    work->saveStateA = (u32)func_0200873C(saveControl);
    work->saveStateB = ZUKAN_SAVE_IsNationalDexEnabled(saveStateSource);
    work->kind = kind;
    work->extraData = 0;
    if (kind == 4) {
        saveBlock = BATTLE_BOX_GetFromSave(saveControl);
        work->party = func_0200BAF4((int)saveBlock, 4);
        work->extraData = BATTLE_BOX_IsLocked(saveBlock, 3);
    }
    handoff = func_02030734(4, 0xc, 0, d_021DE220, 0x90);
    handoff->gameData = gameData;
    handoff->resultVar = resultVar;
    handoff->work = work;
    SCRIPT_SYS_CallEvent(scriptWork, FIELD_STATUS_CreateSubProcNoFadeCallbackEvent(gameSystem, (int)fieldMap, (u32)ov170_id, (int)d_021EF78C, (int)work, (int)((void *)SCRCMD_PROC_FLD_FinishOv170Event), (int)handoff));
    return 1;
}




int SCRCMD_PROC_FLD_StartNameInMode5(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork;
    void *gameSystem;
    void *fieldMap;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    fieldMap = ICA_ANIME_GetField20(gameSystem);
    SCRIPT_SYS_CallEvent(scriptWork, (void *)EVENT_NAMEIN_Create((u32)gameSystem, (u32)fieldMap, 0, 5, (u32)SCRIPT_WORK_ReadWorkPointer(vm, cmdWork)));
    return 1;
}




int SCRCMD_PROC_FLD_StartNameInMode6(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork;
    void *gameSystem;
    void *fieldMap;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    fieldMap = ICA_ANIME_GetField20(gameSystem);
    SCRIPT_SYS_CallEvent(scriptWork, (void *)EVENT_NAMEIN_Create((u32)gameSystem, (u32)fieldMap, 0, 6, (u32)SCRIPT_WORK_ReadWorkPointer(vm, cmdWork)));
    return 1;
}




int SCRCMD_PROC_FLD_SetNextEventAndEnd(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);

    ICA_ANIME_GetField20(gameSystem);
    SCRIPT_SYS_SetNextEventFromWork((int)scriptWork, (int)SCRCMD_NETWORK_CreateCommBattleEvent(gameSystem, SCRIPT_WORK_ReadWorkValue(vm, cmdWork)));
    func_02011290(vm);
    return 1;
}




int SCRCMD_PROC_FLD_CallSubProcWithFlag(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 saveBlock;
    u32 eventArg;
    void *scriptWork;
    void *gameSystem;

    saveBlock = (u32)func_02009210(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(cmdWork)));
    eventArg = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    func_020090D8((struct Sub020090B0Obj *)saveBlock, 1);
    SCRIPT_SYS_CallEvent(scriptWork, FLD_BTL_INST_TOOL_CreateCommResetEvent(gameSystem, (void *)eventArg));
    return 1;
}




int SCRCMD_PROC_FLD_CallOv219Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem;
    void *scriptWork;
    void *fieldMap;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    fieldMap = ICA_ANIME_GetField20(gameSystem);
    SCRIPT_SYS_CallEvent(scriptWork, FIELD_STATUS_CreateSubProcEvent(gameSystem, (int)fieldMap, (int)abs_id_DB, (int)d_02185F0C, (int)ICA_ANIME_GetField1C(gameSystem)));
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
    GAME_DATA_GetSaveControl(ICA_ANIME_GetField1C(gameSystem));
    ICA_ANIME_GetField20(gameSystem);
    flag = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    if (flag == 0 || flag != 1)
        flagBool = 0;
    else
        flagBool = 1;
    SCRIPT_SYS_CallEvent(scriptWork, SCRCMD_CreateSubProcEvent(gameSystem, flagBool, (u32)resultVar));
    return 1;
}




int SCRCMD_PROC_FLD_CallEventWithVarPtr(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);

    SCRIPT_SYS_CallEvent(scriptWork, EVENT_GAME_MANUAL_Create(gameSystem, SCRIPT_WORK_ReadWorkPointer(vm, cmdWork)));
    return 1;
}




int SCRCMD_PROC_FLD_CallEventFromThreeValues(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
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
    SCRIPT_SYS_CallEvent(scriptWork, (void *)FIELD_ENCOUNT_StartScriptedWild(FIELDMAP_GetEncount((u8 *)(((u32 *)SCRIPT_WORK_ResetFieldParam((int)scriptWork))[1])), eventParam0, (u8)eventParam1, eventParam2));
    return 1;
}




int SCRCMD_PROC_FLD_CallFieldMapEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);

    SCRIPT_SYS_CallEvent(scriptWork, (void *)EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, (int)ICA_ANIME_GetField20(gameSystem), 0, 0, 1, 0, 0));
    return 1;
}




/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */
int SCRCMD_PROC_FLD_StoreByteValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 flagValue = GAME_DATA_GetFieldMode(SCRCMD_WORK_GetGameData(cmdWork));
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);

    *resultVar = EVENT_BATTLE_GetKindFlag(flagValue);
    return 0;
}




int SCRCMD_PROC_FLD_CallEventMode4(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);

    SCRIPT_SYS_CallEvent(scriptWork, EVENT_BATTLE_CreateCatchTutorial(gameSystem, (u32)ICA_ANIME_GetField20(gameSystem), 4));
    return 1;
}




int SCRCMD_PROC_FLD_StoreCameraValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *fieldMap = ICA_ANIME_GetField20(SCRCMD_WORK_GetGameSystem(cmdWork));
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);

    *resultVar = EFFECT_ENCOUNT_GetItemId((char *)FIELDMAP_GetEncount(fieldMap));
    return 0;
}




int SCRCMD_PROC_FLD_SetFlagIfClear(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    u32 flagBlock = (u32)MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(gameData));
    u8 flagIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    if (MOVE_POKEMON_SAVE_IsEntryActive((struct Blk38 *)flagBlock, flagIndex) == 0) {
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




/*
 * FIELD_ENCOUNT_ST_LoadEncountData clears and fills a 0xE8-byte record (its own memset size).
 *
 * Addresses are Black-image addresses.
 */
int SCRCMD_PROC_FLD_StoreRandomUniqueEntry(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    EncounterRecord record;
    u32 season;
    u16 tableIndex;
    void *archive;
    u16 *resultVar;
    void *gameData;
    u16 *speciesList;
    u16 slot;
    u16 count;

    count = 0;
    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    season = GAME_DATA_GetSeason(gameData);
    archive = func_020490F4(0x7e, 0x8015);
    speciesList = func_02030734(0x8015, 0x78, 1, d_021DE234, 0xf8);
    for (tableIndex = 0; tableIndex < 6; tableIndex++) {
        if (FIELD_ENCOUNT_ST_LoadEncountData(&record, archive, d_021D98D0[tableIndex], season)) {
            if (record.hasSetA) {
                for (slot = 0; slot < 5; slot++) {
                    count = SCRCMD_PROC_FLD_AddUniqueU16(speciesList, count, record.setA[slot].species);
                }
            }
            if (record.hasSetB) {
                for (slot = 0; slot < 5; slot++) {
                    count = SCRCMD_PROC_FLD_AddUniqueU16(speciesList, count, record.setB[slot].species);
                }
            }
        }
    }
    *resultVar = speciesList[func_02005728(count)];
    func_020307B0(speciesList);
    ARC_TOOL_DeleteHandle(archive);
    return 0;
}




int SCRCMD_PROC_FLD_ReleaseFieldRegion(void *fieldMap, void *fieldRegion)
{
FIELD_CAMERA_PopState(fieldRegion);
if (FIELD_CAMERA_HasDelay(fieldRegion) != 0) {
    FIELD_CAMERA_RestartDelay(fieldRegion);
}
if (FIELDMAP_GetMoveKind(fieldMap) == 1) {
    FIELD_NOGRID_MAPPER_SetActive(FIELDMAP_GetNogridMapper(fieldMap), 1);
}
return SCRIPT_WORK_ResetCheckFlag(0);
}




int SCRCMD_PROC_FLD_ReleaseFieldRegionTask(void **eventWork)
{
    void *fieldMap = ICA_ANIME_GetField20(eventWork[0]);

    SCRCMD_PROC_FLD_ReleaseFieldRegion(fieldMap, FIELDMAP_GetCamera(fieldMap));
    return 1;
}




int SCRCMD_PROC_FLD_BeginFieldRegionRelease(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem;
    void *fieldMap;
    void *fieldRegion;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    fieldMap = ICA_ANIME_GetField20(gameSystem);
    fieldRegion = FIELDMAP_GetCamera(fieldMap);
    SCRIPT_WORK_SetCheckFlag(0);
    if (FIELD_CAMERA_HasDelay(fieldRegion) != 0) {
        FIELD_CAMERA_EndDelay(fieldRegion);
        fieldRegion = SCRCMD_WORK_GetScriptWork(cmdWork);
        SCRIPT_SYS_CallEvent(fieldRegion, func_020122C0(gameSystem, 0, (void *)SCRCMD_PROC_FLD_PollFieldRegionStart, 0));
        if (FIELDMAP_GetMoveKind(fieldMap) == 1) {
            FIELD_NOGRID_MAPPER_SetActive(FIELDMAP_GetNogridMapper(fieldMap), 0);
        }
    } else {
        FIELD_CAMERA_PushState(fieldRegion);
    }
    return 1;
}




int SCRCMD_PROC_FLD_ReleaseFieldRegionCmd(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *fieldMap = ICA_ANIME_GetField20(SCRCMD_WORK_GetGameSystem(cmdWork));

    SCRCMD_PROC_FLD_ReleaseFieldRegion(fieldMap, FIELDMAP_GetCamera(fieldMap));
    return 0;
}




int SCRCMD_PROC_FLD_ResetFieldRegionA(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
FIELD_CAMERA_StopTargetTrace(FIELDMAP_GetCamera(ICA_ANIME_GetField20(SCRCMD_WORK_GetGameSystem(cmdWork))));
return 0;
}




int SCRCMD_PROC_FLD_ResetFieldRegionB(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
FIELD_CAMERA_ResumeTargetTrace((u32)FIELDMAP_GetCamera(ICA_ANIME_GetField20(SCRCMD_WORK_GetGameSystem(cmdWork))));
return 0;
}




int SCRCMD_PROC_FLD_SetFieldRegionFromStream(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    FieldRegionParam param;
    void *fieldRegion;

    fieldRegion = FIELDMAP_GetCamera(ICA_ANIME_GetField20(SCRCMD_WORK_GetGameSystem(cmdWork)));
    param.areaWidth = VM_ReadU16(vm);
    param.areaHeight = VM_ReadU16(vm);
    param.areaFlags = VM_GetU32(vm);
    param.origin.x = VM_GetU32(vm);
    param.origin.y = VM_GetU32(vm);
    param.origin.z = VM_GetU32(vm);
    param.layers.flag[0] = 0;
    param.layers.flag[1] = 1;
    param.layers.flag[2] = 1;
    param.layers.flag[3] = 1;
    param.layers.flag[4] = 0;
    param.layers.flag[5] = 1;
    FIELD_CAMERA_StartMove(fieldRegion, &param, VM_ReadU16(vm));
    return 0;
}




int SCRCMD_PROC_FLD_SetFieldRegionFromArchive(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    FieldRegionRecord record;
    FieldRegionParam param;
    void *fieldRegion;
    int memberIndex;
    int regionIndex;

    fieldRegion = FIELDMAP_GetCamera(ICA_ANIME_GetField20(SCRCMD_WORK_GetGameSystem(cmdWork)));
    memberIndex = VM_ReadU16(vm);
    regionIndex = VM_ReadU16(vm);
    ARC_TOOL_ReadMember(&record, 0xa3, memberIndex);
    param.areaWidth = record.areaWidth;
    param.areaHeight = record.areaHeight;
    param.areaFlags = record.areaFlags;
    param.origin = record.origin;
    param.layers = record.layers;
    FIELD_CAMERA_StartMove(fieldRegion, &param, regionIndex);
    return 0;
}




int SCRCMD_PROC_FLD_SetFieldRegionLayerFlags(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    LayerFlags layers;
    void *fieldRegion = FIELDMAP_GetCamera(ICA_ANIME_GetField20(SCRCMD_WORK_GetGameSystem(cmdWork)));
    u16 regionIndex = VM_ReadU16(vm);

    layers.flag[0] = 1;
    layers.flag[1] = 1;
    layers.flag[2] = 1;
    layers.flag[3] = 1;
    layers.flag[4] = 1;
    layers.flag[5] = 1;
    FIELD_CAMERA_StartMoveToSaved(fieldRegion, (u8 *)&layers, regionIndex);
    return 0;
}




int SCRCMD_PROC_FLD_SetFieldRegionValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
FIELD_CAMERA_StartMoveToSetting(FIELDMAP_GetCamera(ICA_ANIME_GetField20(SCRCMD_WORK_GetGameSystem(cmdWork))), VM_ReadU16(vm));
return 0;
}




int SCRCMD_PROC_FLD_CallFieldRegionWaitEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);

    SCRIPT_SYS_CallEvent(scriptWork, func_020122C0(gameSystem, 0, SCRCMD_PROC_FLD_PollFieldRegionIdle, 0));
    return 1;
}




int SCRCMD_PROC_FLD_CallCustomEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int arg0 = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int arg1 = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int arg2 = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int arg3 = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int arg4 = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int arg5 = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int arg6 = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int arg7 = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *scriptWork;
    void *gameSystem;
    CustomEventParam param;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    param.eventId = arg0;
    param.eventKind = arg1;
    param.scriptId = arg2;
    param.kindCopy = arg3;
    param.kind = arg3;
    param.reserved14 = 0;
    param.mapX = arg4;
    param.mapY = arg5;
    param.mapZ = arg6;
    param.reserved0A = 0;
    param.facing = arg7;
    SCRIPT_SYS_CallEvent(scriptWork, FIELD_CAMERA_CreateShakeTask(gameSystem, (struct Blk021D2D50 *)(&param)));
    return 1;
}




int SCRCMD_PROC_FLD_PollFieldRegionStart(void *event)
{
    u8 *fieldRegion = FIELDMAP_GetCamera(ICA_ANIME_GetField20(GAME_EVENT_GetGameSystem(event)));

    if (FIELD_CAMERA_IsDelayEnabled(fieldRegion) == 0) {
        FIELD_CAMERA_PushState(fieldRegion);
        return 1;
    }
    return 0;
}




int SCRCMD_PROC_FLD_PollFieldRegionIdle(void *event)
{
    int busy = FIELD_CAMERA_IsMoving(FIELDMAP_GetCamera(ICA_ANIME_GetField20(GAME_EVENT_GetGameSystem(event))));

    return busy != 0 ? B_FALSE : B_TRUE;
}




int SCRCMD_PROC_FLD_CallOv056Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u8 *fieldMap = ICA_ANIME_GetField20(gameSystem);
    unsigned int slotNumber = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    SCRIPT_SYS_CallEvent(scriptWork, GIMMICK_INIT_SetCartLanesFlags(gameSystem, fieldMap, (u16)(slotNumber - 1)));
    return 1;
}




/*
 * FIELD_FK_DEMO_GetCameraSettingId is the ov056 slot-table lookup (src/matched/ov/ov056_func_021F36C8.c).
 */
int SCRCMD_PROC_FLD_SetOv056Slot(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *fieldMap = ICA_ANIME_GetField20(SCRCMD_WORK_GetGameSystem(cmdWork));
    unsigned int slotNumber = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    u32 *fieldRegion = FIELDMAP_GetCamera(fieldMap);

    FIELD_CAMERA_SetSetting(fieldRegion, FIELD_FK_DEMO_GetCameraSettingId((u16)(slotNumber - 1)));
    return 0;
}




int SCRCMD_PROC_FLD_SetFieldRegionTable(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int regionTable = FIELDMAP_GetMapFunc(ICA_ANIME_GetField20(SCRCMD_WORK_GetGameSystem(cmdWork)));

    switch (SCRIPT_WORK_ReadWorkValue(vm, cmdWork)) {
    case 0:
        break;
    case 1:
        FIELD_SUBPROC_Start((int)ov56_id, (int *)regionTable, (const int *)g_021F4344);
        break;
    case 2:
        FIELD_SUBPROC_Start((int)ov56_id, (int *)regionTable, (const int *)g_021F4374);
        break;
    case 3:
        FIELD_SUBPROC_Start((int)ov56_id, (int *)regionTable, (const int *)g_021F438C);
        break;
    case 4:
        FIELD_SUBPROC_Start((int)ov56_id, (int *)regionTable, (const int *)g_021F435C);
        break;
    }
    return 0;
}
