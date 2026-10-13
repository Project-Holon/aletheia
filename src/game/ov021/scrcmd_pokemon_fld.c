/*
 * file:     scrcmd_pokemon_fld.c
 * unit:     yes
 * function: SCRCMD_POKEMON_FLD_SelectPartyMon, SCRCMD_POKEMON_FLD_StoreMonRecord, SCRCMD_POKEMON_FLD_StorePartySpeciesRecord, SCRCMD_POKEMON_FLD_RegisterRecordSpecies, SCRCMD_POKEMON_FLD_GetMonIvStat, SCRCMD_POKEMON_FLD_LookupThreshold, SCRCMD_POKEMON_FLD_GetPokedexRating, SCRCMD_POKEMON_FLD_GetPokedexComplete, SCRCMD_POKEMON_FLD_GetTutorMoveId, SCRCMD_POKEMON_FLD_GetTutorFriendship, SCRCMD_POKEMON_FLD_CheckTutorGroup, SCRCMD_POKEMON_FLD_FindTutorCandidates, SCRCMD_POKEMON_FLD_GetTutorAvailability, SCRCMD_POKEMON_FLD_GetMonTutorMove, SCRCMD_POKEMON_FLD_CheckMonTutorStatus, SCRCMD_POKEMON_FLD_SelectTutorMon, SCRCMD_POKEMON_FLD_CheckPartyFlagged, SCRCMD_POKEMON_FLD_GetMonTypeForTm, SCRCMD_POKEMON_FLD_StartSelectEvent, SCRCMD_POKEMON_FLD_SelectMonMove, SCRCMD_POKEMON_FLD_StartEggHatch, SCRCMD_POKEMON_FLD_CheckTradeMon, SCRCMD_POKEMON_FLD_StartTradeEvent, SCRCMD_POKEMON_FLD_GetRandomBagPocketValue, SCRCMD_POKEMON_FLD_StoreMonName, SCRCMD_POKEMON_FLD_RegisterStoredName, SCRCMD_POKEMON_FLD_ControlLegendMon, SCRCMD_POKEMON_FLD_SwapPartyMonWithBoxedLegend, SCRCMD_POKEMON_FLD_FindBoxedLegend, SCRCMD_POKEMON_FLD_MoveLegendToFront, SCRCMD_POKEMON_FLD_FindPartyLegend, SCRCMD_POKEMON_FLD_StartOv55SubProc, SCRCMD_POKEMON_FLD_RegisterBirthdayEntry, SCRCMD_POKEMON_FLD_GetMysteryEntryCount, SCRCMD_POKEMON_FLD_GetWarpEntry, SCRCMD_POKEMON_FLD_NoopWarpEntry, SCRCMD_POKEMON_FLD_CountWarpEntries, SCRCMD_POKEMON_FLD_SetWarpTable, SCRCMD_POKEMON_FLD_AddWarpMenuItems, SCRCMD_POKEMON_FLD_WarpToEntry, SCRCMD_POKEMON_FLD_HandleMysteryGift, SCRCMD_POKEMON_FLD_CheckGiftCanReceive, SCRCMD_POKEMON_FLD_PrepareGiftReceiveMessage, SCRCMD_POKEMON_FLD_PrepareGiftFollowUpMessage, SCRCMD_POKEMON_FLD_ReceiveGift, SCRCMD_POKEMON_FLD_GetGiftReceiveType, SCRCMD_POKEMON_FLD_GetDeliveryNpcId, SCRCMD_POKEMON_FLD_CheckDeliveryNpcLoaded, SCRCMD_POKEMON_FLD_FindDeliveryMmdl, SCRCMD_POKEMON_FLD_FindDeliveryNpcObjId, SCRCMD_POKEMON_FLD_IsLibertyPassGift, SCRCMD_POKEMON_FLD_CreateGiftMon, SCRCMD_POKEMON_FLD_CheckGiftMonCanReceive, SCRCMD_POKEMON_FLD_ReceiveGiftMon, SCRCMD_POKEMON_FLD_GetGiftMonReceiveType, SCRCMD_POKEMON_FLD_PrepareGiftMonMessage, SCRCMD_POKEMON_FLD_PrepareGiftMonFollowUpMessage, SCRCMD_POKEMON_FLD_CheckGiftItemCanReceive, SCRCMD_POKEMON_FLD_ReceiveGiftItem, SCRCMD_POKEMON_FLD_GetGiftItemReceiveType, SCRCMD_POKEMON_FLD_PrepareGiftItemMessage, SCRCMD_POKEMON_FLD_PrepareGiftItemFollowUpMessage, SCRCMD_POKEMON_FLD_CheckGiftFlagCanReceive, SCRCMD_POKEMON_FLD_ReceiveGiftFlag, SCRCMD_POKEMON_FLD_GetGiftFlagReceiveType, SCRCMD_POKEMON_FLD_PrepareGiftFlagMessage, SCRCMD_POKEMON_FLD_PrepareGiftFlagFollowUpMessage, SCRCMD_POKEMON_FLD_LookupTableValue, SCRCMD_POKEMON_FLD_CheckTableItemInBag, SCRCMD_POKEMON_FLD_RegisterTableValueNumber, SCRCMD_POKEMON_FLD_AddTableValueToPoints, SCRCMD_POKEMON_FLD_GetDailyGift, SCRCMD_POKEMON_FLD_IsSpecialDate, SCRCMD_POKEMON_FLD_GetDailyGiftIndex
 * address:  0x021B5B4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Takes the mystery gift kind handlers 021B6D0C..021B72CC (unit_021B6D0C.c, unit_021B6D30.c, unit_021B6D64.c, unit_021B6DC0.c) and the first three script commands of pdw_postman.c, 021B7364..021B73B8 (lane FXC3).
 * Split from scrcmd_c03center.c at 0x021B5B4C (lane FXC2, CL133: party and Pokemon script commands; the pokemon_fld.c file string sScrcmdPokemonFldFileName is first used by 021B6708; the cut address is the first command after the c03center camera turn).
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   EVENT_POKE_STATUS_CreatePokeSelectEvent  0x0215A07C  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_PROC_GetPartyMember  0x0215B4AC  thumb  ov010
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   func_0200C11C  0x0200C11C  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   func_0200C2B0  0x0200C2B0  thumb
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   func_0200C2D0  0x0200C2D0  thumb
 *   func_0201EE60  0x0201EE60  thumb
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0200CF08  0x0200CF08  thumb
 *   func_0200D298  0x0200D298  thumb
 *   func_0200D0F8  0x0200D0F8  thumb
 *   func_0200D2C4  0x0200D2C4  thumb
 *   func_0200CF54  0x0200CF54  thumb
 *   func_0200D2B0  0x0200D2B0  thumb
 *   gPokedexRatingTableKind3     0x021D98DC  data  a4
 *   gPokedexRatingTableKind2     0x021D9904  data  a4
 *   gPokedexRatingTableKind1     0x021D992C  data  a4
 *   POKE_TOOL_CheckTutorCompat  0x0201891C  thumb
 *   SCRCMD_PROC_CheckMonKnowsMove  0x0215B500  thumb  ov010
 *   EVENT_POKE_STATUS_CreatePokeSelectMoveEvent  0x0215A0E8  thumb  ov010
 *   func_0202130C  0x0202130C  thumb
 *   POKE_TOOL_CheckTmCompat  0x020188AC  thumb
 *   POKE_TOOL_GetHiddenPowerType  0x02018790  thumb
 *   SCRCMD_CreateNicknameEvent  0x021C5AAC  thumb  ov021
 *   EVENT_POKE_STATUS_CreateMoveSelectEvent  0x0215A2E4  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   SYMBOL_MAP_CreatePokeEventTask  0x02166C4C  thumb  ov010
 *   FLD_TRADE_Create  0x021CBFB0  thumb  ov021
 *   FLD_TRADE_Delete  0x021CC040  thumb  ov021
 *   FLD_TRADE_GetWantedSpecies  0x021CC060  thumb  ov021
 *   FLD_TRADE_GetWantedGender  0x021CC068  thumb  ov021
 *   FLD_TRADE_CreateEvent  0x021CC500  thumb  ov021
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   func_02007FA0  0x02007FA0  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_020081DC  0x020081DC  thumb
 *   func_020212B0  0x020212B0  thumb
 *   GAME_DATA_GetSaveBlock43  0x02012FD8  thumb
 *   func_0200E7BC  0x0200E7BC  thumb
 *   SCRIPT_WORK_GetTempBuffer  0x02158F7C  thumb ov010
 *   func_0200E740  0x0200E740  thumb
 *   func_0200E7AC  0x0200E7AC  thumb
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   STRBUF_SetString  0x02045924  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0202136C  0x0202136C  thumb
 *   func_02008FEC  0x02008FEC  thumb
 *   MAIL_Create  0x02008F08  thumb
 *   MAIL_FindEmptySlot  0x02009020  thumb
 *   func_0200903C  0x0200903C  thumb
 *   func_02008EAC  0x02008EAC  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   func_02007A18  0x02007A18  thumb
 *   POKE_TOOL_CreateFromBoxParam  0x0201747C  thumb
 *   POKEPARTY_SetMember  0x0201AB48  thumb
 *   POKE_TOOL_Dummy  0x020185F0  thumb
 *   func_020075B0  0x020075B0  thumb
 *   sScrcmdPokemonFldFileName     0x021DE270  data   ov021  a1
 *   func_02007698  0x02007698  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020079BC  0x020079BC  thumb
 *   POKEPARTY_SwapMembers  0x0201AB8C  thumb
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb ov010
 *   FIELDMAP_GetMapFunc  0x02188D24  thumb ov021
 *   FIELD_SUBPROC_Start  0x021BB990  thumb ov021
 *   ov055_id       0x00000037  data  a1
 *   gCrowdSubprocTemplate     0x021F45F0  data  ov055  a4
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200A8A0  0x0200A8A0  thumb
 *   FIELD_CLOCK_GetDate  0x021690A4  thumb  ov010
 *   func_02087C88  0x02087C88  arm
 *   func_0200A940  0x0200A940  thumb
 *   func_0200A8F8  0x0200A8F8  thumb
 *   func_0200A8C8  0x0200A8C8  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   func_0200A8AC  0x0200A8AC  thumb
 *   VM_GetU32  0x0201134C  thumb
 *   SCRCMD_WORK_SetFadeState  0x0215A6D0  thumb ov010
 *   SCRCMD_WORK_GetFadeState  0x0215A6C4  thumb  ov010
 *   SCRIPT_WORK_GetMsgBuffer  0x02158F78  thumb  ov010
 *   SCRCMD_WORK_GetScriptId  0x0215A5D0  thumb  ov010
 *   SCRCMD_WORK_AddMenuItem  0x0215A7F0  thumb  ov010
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   EVENT_MAPCHANGE_CreateWarpEventDefaultTransition  0x021854B0  thumb  ov020
 *   MYSTERY_DATA_Create  0x0200A300  thumb
 *   MYSTERY_DATA_Delete  0x0200A338  thumb
 *   PDW_POSTMAN_FindMysteryCard  0x021B7834  thumb  ov021
 *   PDW_POSTMAN_GetMysteryGiftType  0x021B7864  thumb  ov021
 *   PDW_POSTMAN_SetMysteryReceived  0x021B785C  thumb  ov021
 *   SCRCMD_POKEMON_FLD_CheckGiftCanReceive  0x021B6D0C  thumb  ov021
 *   SCRCMD_POKEMON_FLD_PrepareGiftReceiveMessage  0x021B6D30  thumb  ov021
 *   SCRCMD_POKEMON_FLD_PrepareGiftFollowUpMessage  0x021B6D64  thumb  ov021
 *   SCRCMD_POKEMON_FLD_ReceiveGift  0x021B6D98  thumb  ov021
 *   SCRCMD_POKEMON_FLD_GetGiftReceiveType  0x021B6DC0  thumb  ov021
 *   SCRCMD_POKEMON_FLD_GetDeliveryNpcId  0x021B6DE4  thumb  ov021
 *   SCRCMD_POKEMON_FLD_CheckDeliveryNpcLoaded  0x021B6E0C  thumb  ov021
 *   SCRCMD_POKEMON_FLD_IsLibertyPassGift  0x021B6EB0  thumb  ov021
 *   FIELD_G3D_MAP_StoreBeaconTrainerKey  0x0216BF74  thumb  ov010
 *   sMysteryGiftKindHandlers     0x021D9970  data   ov021  a4
 *   FLDMMDL_GetObjId  0x0216D588  thumb ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   EVENTDATA_SYSTEM_GetNpcHeaders  0x02162740  thumb  ov010
 *   EVENTDATA_SYSTEM_GetNpcCount  0x02162744  thumb  ov010
 *   MYSTERY_GIFT_CreateMon  0x02157E9C  thumb  ov010
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EEC4  0x0201EEC4  thumb
 *   func_0201EED4  0x0201EED4  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_0201EF40  0x0201EF40  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_0200BF18  0x0200BF18  thumb
 *   func_0201F184  0x0201F184  thumb
 *   ARC_UTIL_LoadMemberWithSize  0x0204A298  arm
 *   sScrcmdTableFileIds     0x021D99D0  data   ov021  a1
 *   func_02007F68  0x02007F68  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   func_0200C278  0x0200C278  thumb
 *   sDailyGifts     0x021D99E8  data  a2
 *   sDailyGiftSpecialDates     0x021D99D4  data  a2
 *   FIELD_CLOCK_GetMonth  0x021690D0  thumb  ov010
 *   FIELD_CLOCK_GetDay  0x021690E0  thumb  ov010
 *   sDailyGiftIndexByDay     0x021D99DE  data   ov021  a1
 */
#include "../arm9/script_vm_types.h"
#include "../ov010/fldmmdl_types.h"
#include "../ov010/script_work_types.h"
#include "scrcmd_pokemon_fld_types.h"

struct ScrcmdWork;
struct GameSystem;
struct GameData;
struct MiscSave;
struct WordSet;
struct ZukanSave;
struct FldTrade;
struct StoredNames;
struct Strbuf;
struct Party;
struct PartyMon;
struct BoxMon;
struct Mail;
struct MyStatus;
struct MysteryData;
struct MysteryDataEntry;
struct OSOwnerInfo;
struct FieldMap;
struct EventDataSystem;
struct PokemonParam;
struct MyItem;
struct IntrudeSave;
struct SaveControl;
struct PlayerWork;
struct ZukanWork;

/* One row of a count to value table; a row with limit 0 ends the table. */
typedef struct ThresholdEntry {
    u16 limit;
    u16 value;
} ThresholdEntry;

typedef signed int     s32;

/* Owner information from the firmware user settings (OS owner info). */
typedef struct OwnerInfo {
    u8 language;
    u8 color;
    u8 birthMonth;
    u8 birthDay;
    u8 nameAndComment[0x50];
} OwnerInfo;

typedef struct { int x, y, z; } Vec3;

/* One entry of a warp list placed in the script data (10 bytes); the first halfword 0xFFFF ends the list. */
typedef struct WarpEntry {
    u16 labelId;      /* 0x00: menu label message id */
    u16 mapId;        /* 0x02 */
    u16 gridX;        /* 0x04 */
    u16 gridY;        /* 0x06 */
    u16 gridZ;        /* 0x08 */
} WarpEntry;

typedef struct ScrcmdWork ScrcmdWork;

/* One row (8 bytes) of a key to value table loaded from an archive. */
typedef struct ScrcmdKeyValueEntry {
    u32 key;
    u32 value;
} ScrcmdKeyValueEntry;

#define SCRCMD_TABLE_ARC_ID          0xD0
#define SCRCMD_DELIVERY_OBJ_CODE     0x46
#define SCRCMD_HEAP_FLAG_TAIL        0x8000   /* allocate from the tail of the heap */

extern ScriptWork *SCRCMD_WORK_GetScriptWork(ScrcmdWork *work);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern struct GameData *SCRCMD_WORK_GetGameData(void *work);
extern u16 SCRIPT_WORK_ReadWorkValue(void *, void *);
extern void *GAMESYSTEM_GetFieldMap(const struct GameSystem *p);
extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *core, void *work);
extern void *EVENT_POKE_STATUS_CreatePokeSelectEvent(int a, u16 *b, u16 *c);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern int SCRCMD_PROC_GetPartyMember(void *a0, unsigned int a1, void **out);
extern struct MiscSave *GAME_DATA_GetMiscSave(struct GameData *gameData);
extern u32 POKE_TOOL_GetPartyValue(struct PokemonParam *mon, u32 paramId, u32 arg);
extern void func_0200C11C(struct MiscSave *p, u16 a, u32 b, u32 c, u32 d);
extern struct Party *GAME_DATA_GetMyParty(const struct GameData *gameData);
extern int POKEPARTY_GetCount(const struct Party *party);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void func_0200C2B0(struct MiscSave *p, u32 i, const u16 *src);
extern struct WordSet *SCRIPT_WORK_GetWordSet(ScriptWork *scriptWork);
extern void func_0200C2D0(struct MiscSave *p, u32 i, u16 *dest);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern u16 SCRCMD_WORK_GetHeapId(ScrcmdWork *work);
extern void *func_0200CA1C(void *a);
extern u32 func_0200CA38(struct ZukanSave *p);
extern u16 func_0200CF08(struct ZukanSave *p, u32 heap);
extern int func_0200D298(void *a0);
extern u16 func_0200D0F8(struct ZukanSave *p, u32 heap);
extern int func_0200D2C4(void *p, unsigned int heap);
extern u16 func_0200CF54(struct ZukanSave *p, u32 heap);
extern int func_0200D2B0(void *a0, int a1);
extern u32 POKE_TOOL_CheckTutorCompat(void *p, s32 v);
extern int SCRCMD_PROC_CheckMonKnowsMove(int a0, int a1);
extern void *EVENT_POKE_STATUS_CreatePokeSelectMoveEvent(void *t, u16 *o1, u16 *o2, u8 c, u32 v);
extern u32 func_0202130C(u32 id);
extern u32 POKE_TOOL_CheckTmCompat(void *p, int v);
extern u32 POKE_TOOL_GetHiddenPowerType(void *p);
extern int SCRCMD_CreateNicknameEvent(void *a, int b, int c, int d);
extern int EVENT_POKE_STATUS_CreateMoveSelectEvent(int a, int b, int c, int d, int e, int f, unsigned short g);
extern void *GAMESYSTEM_GetGameData(const struct GameSystem *p);
extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gameData);
extern void *SYMBOL_MAP_CreatePokeEventTask(void *a, void *b, void *c);
extern struct FldTrade *FLD_TRADE_Create(u32 a, u32 b);
extern void FLD_TRADE_Delete(struct FldTrade *o);
extern u32 FLD_TRADE_GetWantedSpecies(struct FldTrade *p);
extern u32 FLD_TRADE_GetWantedGender(struct FldTrade *p);
extern void *FLD_TRADE_CreateEvent(void *a, u32 b, u32 c);
extern struct MyItem *GAME_DATA_GetMyItem(const struct GameData *gameData);
extern u32 func_02007FA0(u8 *base, u32 id);
extern u32 func_020056EC(u32);
extern u16 *func_020081DC(void *, int, u16);
extern u16 func_020212B0(u16);
extern void *GAME_DATA_GetSaveBlock43(void **p);
extern void func_0200E7BC(struct StoredNames *o, int idx, void *mon);
extern u32 SCRIPT_WORK_GetTempBuffer(u8 *p);
extern u32 func_0200E740(const void *obj, u32 idx);
extern void *func_0200E7AC(void *obj, u32 idx);
extern u16 STRBUF_GetEosChar(void);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern u32 GAME_DATA_GetBoxManager(const struct GameData *p);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void func_02082D44(void *src, void *dst, u32 n);
extern u32 func_0202136C(u16 v);
extern struct Mail *func_02008FEC(void *sys);
extern void *MAIL_Create(int a0);
extern int MAIL_FindEmptySlot(void *obj, int v);
extern void func_0200903C(struct Mail *arr, u32 unused, int i, const struct Mail *src);
extern void func_02008EAC(struct Mail *obj);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_ChangeForm(void *p, u32 a);
extern void POKE_TOOL_RecalcParam(void *mon);
extern struct BoxMon *func_02007A18(void **save, u32 box, u32 slot);
extern void *POKE_TOOL_CreateFromBoxParam(struct BoxMon *p, u32 heap);
extern void POKEPARTY_SetMember(struct Party *p, u32 idx, const struct PartyMon *src);
extern void *POKE_TOOL_Dummy(void *mon);
extern int func_020075B0(void *save, u32 box, u32 slot, const struct BoxMon *src);
extern int func_02007698(void);
extern u32 func_02008530(const struct MyStatus *obj);
extern int func_020079BC(void **save, u32 box, u32 slot, int field, int arg);
extern u32 POKEPARTY_SwapMembers(struct Party *p, u32 i, u32 j, u32 heap);
extern ScriptFieldParam *SCRIPT_WORK_ResetFieldParam(ScriptWork *scriptWork);
extern u32 FIELDMAP_GetMapFunc(u8 *p);
extern int *FIELD_SUBPROC_Start(int, int *, const int *);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern void *func_0200A8A0(void *);
extern void *FIELD_CLOCK_GetDate(int a0);
extern void func_02087C88(struct OSOwnerInfo *info);
extern int func_0200A940(void *, int, int, void *);
extern u32 func_0200A8F8(struct MysteryData *r, u32 index);
extern struct MysteryDataEntry *func_0200A8C8(struct MysteryData *r, u32 index);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_Delete(struct Strbuf *vec);
extern s32 func_0200A8AC(struct MysteryData *r);
extern u32 VM_GetU32(struct ScriptVm *p);
extern void SCRCMD_WORK_SetFadeState(void *p, u32 v);
extern u32 SCRCMD_WORK_GetFadeState(void *p);
extern u32 SCRIPT_WORK_GetMsgBuffer(u8 *p);
extern u16 SCRCMD_WORK_GetScriptId(void *);
extern void SCRCMD_WORK_AddMenuItem(void *p, int a, int b, int c, struct Strbuf *s0, void *s1);
extern void *SCRIPT_WORK_GetGameSystem(void *);
extern int EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(void *, void *, int, Vec3 *, int);
extern void *MYSTERY_DATA_Create(void *a0, void *a1, void *a2);
extern void MYSTERY_DATA_Delete(void *h);
extern void *PDW_POSTMAN_FindMysteryCard(void *a, int *out, void *buf);
extern u8 PDW_POSTMAN_GetMysteryGiftType(void *a);
extern void PDW_POSTMAN_SetMysteryReceived(u8 *p, u32 i);
int SCRCMD_POKEMON_FLD_CheckGiftCanReceive(int giftKind, struct ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int SCRCMD_POKEMON_FLD_PrepareGiftReceiveMessage(int giftKind, MysteryGiftCard *card, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_PrepareGiftFollowUpMessage(int giftKind, MysteryGiftCard *card, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_ReceiveGift(int giftKind, struct ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int SCRCMD_POKEMON_FLD_GetGiftReceiveType(int giftKind, ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
u16 SCRCMD_POKEMON_FLD_GetDeliveryNpcId(struct FieldMap *fieldMap, struct GameData *gameData);
u16 SCRCMD_POKEMON_FLD_CheckDeliveryNpcLoaded(struct FieldMap *fieldMap);
int SCRCMD_POKEMON_FLD_IsLibertyPassGift(MysteryGiftCard *card, int giftType);
extern void FIELD_G3D_MAP_StoreBeaconTrainerKey(void *a, int i, void *b);
extern u16 FLDMMDL_GetObjId(Mmdl *mmdl);
extern MmdlSys *FIELDMAP_GetMmdlSys(struct FieldMap *fieldMap);
extern int FLDMMDL_SysSearchUseMmdl(MmdlSys *mmdlSys, Mmdl **mmdlOut, u32 *iterator);
extern u16 FLDMMDL_GetObjCode(Mmdl *mmdl);
extern struct EventDataSystem *GAME_DATA_GetEventData(const struct GameData *gameData);
extern MmdlHeader *EVENTDATA_SYSTEM_GetNpcHeaders(struct EventDataSystem *eventData);
extern u16 EVENTDATA_SYSTEM_GetNpcCount(struct EventDataSystem *eventData);
extern struct PokemonParam *MYSTERY_GIFT_CreateMon(const MysteryGiftCard *card, u32 heapId, struct GameData *gameData);
extern u32 POKEPARTY_Add(struct Party *party, const struct PokemonParam *mon);
extern void func_0200CDE0(struct ZukanWork *zukan, struct PokemonParam *mon);
extern void func_0201F02C(struct WordSet *wordSet, u32 bufferId, struct MyStatus *myStatus);
extern void func_0201EEC4(struct WordSet *wordSet, u32 bufferId, u32 value);
extern void func_0201EED4(struct WordSet *wordSet, u32 bufferId, struct PokemonParam *mon);
extern void func_02007E50(struct MyItem *bag, u32 itemId, int count, u32 heapId);
extern void func_0201EF40(struct WordSet *wordSet, u32 bufferId, u32 value);
extern struct IntrudeSave *func_0200BE48(struct SaveControl *save);
extern void func_0200BF18(struct IntrudeSave *intrude, s32 flagId);
extern void func_0201F184(struct WordSet *wordSet, u32 bufferId, s32 value);
extern int ARC_UTIL_LoadMemberWithSize(int arcId, int memberId, int unused, u32 heapId, u32 *sizeOut);
extern int func_02007F68(struct MyItem *bag, u32 itemId, u32 count, u32 heapId);
extern void func_0201EFA4(struct WordSet *wordSet, u32 bufferId, u32 number, u32 digits, u32 dispType, u32 code);
extern struct PlayerWork *GAME_DATA_GetMyPlayerWork(struct GameData *gameData);
extern u32 func_0200C278(struct MiscSave *miscSave, u32 amount);
Mmdl *SCRCMD_POKEMON_FLD_FindDeliveryMmdl(struct FieldMap *fieldMap);
int SCRCMD_POKEMON_FLD_FindDeliveryNpcObjId(struct GameData *gameData);
struct PokemonParam *SCRCMD_POKEMON_FLD_CreateGiftMon(ScrcmdWork *work, MysteryGiftCard *card);
int SCRCMD_POKEMON_FLD_CheckGiftMonCanReceive(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
void SCRCMD_POKEMON_FLD_ReceiveGiftMon(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int SCRCMD_POKEMON_FLD_GetGiftMonReceiveType(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int SCRCMD_POKEMON_FLD_PrepareGiftMonMessage(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_PrepareGiftMonFollowUpMessage(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_CheckGiftItemCanReceive(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
void SCRCMD_POKEMON_FLD_ReceiveGiftItem(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int SCRCMD_POKEMON_FLD_GetGiftItemReceiveType(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int SCRCMD_POKEMON_FLD_PrepareGiftItemMessage(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_PrepareGiftItemFollowUpMessage(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_CheckGiftFlagCanReceive(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
void SCRCMD_POKEMON_FLD_ReceiveGiftFlag(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int SCRCMD_POKEMON_FLD_GetGiftFlagReceiveType(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int SCRCMD_POKEMON_FLD_PrepareGiftFlagMessage(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_PrepareGiftFlagFollowUpMessage(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_LookupTableValue(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_CheckTableItemInBag(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_RegisterTableValueNumber(struct ScriptVm *vm, ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_AddTableValueToPoints(struct ScriptVm *vm, ScrcmdWork *work);
extern const u8 sScrcmdTableFileIds[];
extern int FIELD_CLOCK_GetMonth(struct GameData *gameData);
extern int FIELD_CLOCK_GetDay(struct GameData *gameData);
int SCRCMD_POKEMON_FLD_GetDailyGift(void *core, void *work);
int SCRCMD_POKEMON_FLD_IsSpecialDate(u32 month, int day);
int SCRCMD_POKEMON_FLD_GetDailyGiftIndex(void *core, void *work);
extern const u16 sDailyGifts[];
extern const u16 sDailyGiftSpecialDates[];
extern const u8 sDailyGiftIndexByDay[];
int SCRCMD_POKEMON_FLD_SelectPartyMon(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_StoreMonRecord(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_StorePartySpeciesRecord(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_RegisterRecordSpecies(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_GetMonIvStat(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 SCRCMD_POKEMON_FLD_LookupThreshold(ThresholdEntry *table, int count);
int SCRCMD_POKEMON_FLD_GetPokedexRating(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_GetPokedexComplete(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_GetTutorMoveId(void *mon, int tutorKind);
int SCRCMD_POKEMON_FLD_GetTutorFriendship(int tutorKind);
int SCRCMD_POKEMON_FLD_CheckTutorGroup(void *mon, int tutorKind);
int SCRCMD_POKEMON_FLD_FindTutorCandidates(struct ScriptVm *vm, struct ScrcmdWork *work, int tutorKind, u8 *eligibleMask, u32 checkFriendship);
int SCRCMD_POKEMON_FLD_GetTutorAvailability(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_GetMonTutorMove(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_CheckMonTutorStatus(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_SelectTutorMon(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_CheckPartyFlagged(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_GetMonTypeForTm(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_StartSelectEvent(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_SelectMonMove(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 SCRCMD_POKEMON_FLD_StartEggHatch(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_CheckTradeMon(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 SCRCMD_POKEMON_FLD_StartTradeEvent(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 SCRCMD_POKEMON_FLD_GetRandomBagPocketValue(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 SCRCMD_POKEMON_FLD_StoreMonName(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_RegisterStoredName(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 SCRCMD_POKEMON_FLD_ControlLegendMon(struct ScriptVm *vm, struct ScrcmdWork *work);
void SCRCMD_POKEMON_FLD_SwapPartyMonWithBoxedLegend(struct ScrcmdWork *work, int partySlot);
int SCRCMD_POKEMON_FLD_FindBoxedLegend(void *gameData, u16 species, u16 *boxOut, u16 *slotOut);
void SCRCMD_POKEMON_FLD_MoveLegendToFront(struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_FindPartyLegend(void *gameData);
int SCRCMD_POKEMON_FLD_StartOv55SubProc(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 SCRCMD_POKEMON_FLD_RegisterBirthdayEntry(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_GetMysteryEntryCount(struct ScriptVm *vm, struct ScrcmdWork *work);
WarpEntry *SCRCMD_POKEMON_FLD_GetWarpEntry(WarpEntry *table, u32 index);
void SCRCMD_POKEMON_FLD_NoopWarpEntry(u16 *labelId);
int SCRCMD_POKEMON_FLD_CountWarpEntries(WarpEntry *table);
int SCRCMD_POKEMON_FLD_SetWarpTable(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 SCRCMD_POKEMON_FLD_AddWarpMenuItems(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 SCRCMD_POKEMON_FLD_WarpToEntry(struct ScriptVm *vm, struct ScrcmdWork *work);
int SCRCMD_POKEMON_FLD_HandleMysteryGift(struct ScriptVm *vm, struct ScrcmdWork *work);
extern u16 gPokedexRatingTableKind3[];
extern u16 gPokedexRatingTableKind2[];
extern u16 gPokedexRatingTableKind1[];
extern u8 sScrcmdPokemonFldFileName[];
extern u8 ov055_id[];
extern const int gCrowdSubprocTemplate[];

/* Script command: open the party select screen. */
int SCRCMD_POKEMON_FLD_SelectPartyMon(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u16 *selectedSlotOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    u16 *resultOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    void *scriptWork;

    SCRIPT_WORK_ReadWorkValue(vm, work);
    scriptWork = SCRCMD_WORK_GetScriptWork(work);
    SCRIPT_SYS_CallEvent(scriptWork, EVENT_POKE_STATUS_CreatePokeSelectEvent((int)SCRCMD_WORK_GetGameSystem(work), selectedSlotOut, resultOut));
    return 1;
}

/*
 * Script command: store the species, form, egg flag and gender of a party
 * member in the record of the misc save.
 *
 * Addresses are Black-image addresses.
 */
int SCRCMD_POKEMON_FLD_StoreMonRecord(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *mon;
    struct MiscSave *miscSave;
    u16 species, form, isEgg, gender;

    if (SCRCMD_PROC_GetPartyMember(work, SCRIPT_WORK_ReadWorkValue(vm, work), &mon) == 1) {
        miscSave = GAME_DATA_GetMiscSave(SCRCMD_WORK_GetGameData(work));
        species = POKE_TOOL_GetPartyValue(mon, 5, 0);
        form = POKE_TOOL_GetPartyValue(mon, 0x6f, 0);
        isEgg = POKE_TOOL_GetPartyValue(mon, 0x4c, 0);
        gender = POKE_TOOL_GetPartyValue(mon, 0x6e, 0);
        func_0200C11C(miscSave, species, form, isEgg, gender);
    }
    return 0;
}

/* Script command: store the species of the non-egg party members in a record slot. */
int SCRCMD_POKEMON_FLD_StorePartySpeciesRecord(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u16 species[6];
    void *gameData;
    unsigned int recordSlot;
    void *party;
    void *mon;
    int i;
    int j;
    int count;

    gameData = SCRCMD_WORK_GetGameData(work);
    party = GAME_DATA_GetMyParty(gameData);
    recordSlot = SCRIPT_WORK_ReadWorkValue(vm, work);
    for (i = 0; i < 6; i++)
        species[i] = 0;
    for (j = 0, count = 0; j < (int)POKEPARTY_GetCount(party); j++) {
        mon = POKEPARTY_GetMember(party, j);
        if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0) == 0)
            species[count++] = POKE_TOOL_GetPartyValue(mon, 5, 0);
    }
    func_0200C2B0(GAME_DATA_GetMiscSave(gameData), recordSlot, species);
    return 0;
}

/* Script command: put the species names of a record slot in the word set; the count goes to the result variable. */
int SCRCMD_POKEMON_FLD_RegisterRecordSpecies(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *gameData;
    struct WordSet *wordSet;
    unsigned int recordSlot;
    u16 *countOut;
    int i;
    int count;
    u16 species[6];

    gameData = SCRCMD_WORK_GetGameData(work);
    wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(work));
    recordSlot = SCRIPT_WORK_ReadWorkValue(vm, work);
    countOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    func_0200C2D0(GAME_DATA_GetMiscSave(gameData), recordSlot, species);
    for (i = 0, count = 0; i < 6; i++) {
        if (species[i] != 0) {
            func_0201EE60(wordSet, count, species[i]);
            count++;
        }
    }
    *countOut = count;
    return 0;
}

/*
 * Script command: read the six individual values of a party member. The
 * request picks the sum, the highest value or one of the six values.
 */
int SCRCMD_POKEMON_FLD_GetMonIvStat(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u16 ivs[6];
    void *mon;
    u32 partySlot;
    u32 request;
    u16 *resultOut;
    u16 sum;
    u16 highest;
    u32 i;

    partySlot = SCRIPT_WORK_ReadWorkValue(vm, work);
    request = SCRIPT_WORK_ReadWorkValue(vm, work);
    resultOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    if (SCRCMD_PROC_GetPartyMember(work, partySlot, &mon) == 0) {
        *resultOut = 0;
        return 0;
    }
    sum = 0;
    ivs[0] = POKE_TOOL_GetPartyValue(mon, 0x46, 0);
    ivs[1] = POKE_TOOL_GetPartyValue(mon, 0x47, 0);
    ivs[2] = POKE_TOOL_GetPartyValue(mon, 0x48, 0);
    ivs[3] = POKE_TOOL_GetPartyValue(mon, 0x49, 0);
    ivs[4] = POKE_TOOL_GetPartyValue(mon, 0x4a, 0);
    ivs[5] = POKE_TOOL_GetPartyValue(mon, 0x4b, 0);
    highest = 0;
    for (i = 0; i < 6; i++) {
        sum += ivs[i];
        if (highest < ivs[i]) {
            highest = ivs[i];
        }
    }
    switch (request) {
    case 0:
        *resultOut = sum;
        break;
    case 1:
        *resultOut = highest;
        break;
    case 2:
        *resultOut = ivs[0];
        break;
    case 3:
        *resultOut = ivs[1];
        break;
    case 4:
        *resultOut = ivs[2];
        break;
    case 5:
        *resultOut = ivs[3];
        break;
    case 6:
        *resultOut = ivs[4];
        break;
    case 7:
        *resultOut = ivs[5];
        break;
    }
    return 0;
}

/*
 * Returns the value of the first row whose limit is at least count (or of
 * the row with limit 0 that ends the table).
 * Unlabelled leaf (saves no lr), called by SCRCMD_POKEMON_FLD_GetPokedexRating.
 * Addresses are Black-image addresses.
 */
u32 SCRCMD_POKEMON_FLD_LookupThreshold(ThresholdEntry *table, int count)
{
    int i;
    u32 limit;

    for (i = 0; ; i++) {
        limit = table[i].limit;
        if (limit == 0)
            return table[i].value;
        if (count <= (int)limit)
            return table[i].value;
    }
}

/*
 * Script command: Pokedex rating for one of three Pokedex kinds. The first
 * result variable gets the rating row (a fixed value when the kind is
 * complete), the second the Pokedex count.
 *
 * Case blocks are in source order 3, 2, 1; per-case stores to *ratingOut but a
 * single *countOut store after the switch is what spills countOut (register
 * pressure) and gives ratingOut r4.
 *
 * Case 3 reads gPokedexRatingTableKind3 and case 1 gPokedexRatingTableKind1 (pool words in that order);
 * the earlier draft had the two swapped, which only the relocation check saw.
 *
 * Addresses are Black-image addresses.
 */
int SCRCMD_POKEMON_FLD_GetPokedexRating(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u32 dexKind;
    u16 *ratingOut;
    u16 *countOut;
    u32 heapId;
    struct ZukanSave *zukan;
    u32 count;

    dexKind = SCRIPT_WORK_ReadWorkValue(vm, work);
    ratingOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    countOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    heapId = SCRCMD_WORK_GetHeapId(work);
    zukan = func_0200CA1C(SCRCMD_WORK_GetGameData(work));
    func_0200CA38(zukan);
    *ratingOut = 5;
    *countOut = 0;
    switch (dexKind) {
    case 3:
        count = func_0200CF54(zukan, heapId);
        if (func_0200D2B0(zukan, heapId) == 1)
            *ratingOut = 0x1e;
        else
            *ratingOut = SCRCMD_POKEMON_FLD_LookupThreshold((ThresholdEntry *)gPokedexRatingTableKind3, count);
        break;
    case 2:
        count = func_0200D0F8(zukan, heapId);
        if (func_0200D2C4(zukan, heapId) == 1)
            *ratingOut = 0xd;
        else
            *ratingOut = SCRCMD_POKEMON_FLD_LookupThreshold((ThresholdEntry *)gPokedexRatingTableKind2, count);
        break;
    case 1:
        count = func_0200CF08(zukan, heapId);
        if (func_0200D298(zukan) == 1)
            *ratingOut = 0x32;
        else
            *ratingOut = SCRCMD_POKEMON_FLD_LookupThreshold((ThresholdEntry *)gPokedexRatingTableKind1, count);
        break;
    default:
        return 0;
    }
    *countOut = count;
    return 0;
}

/* Script command: check whether the Pokedex of one kind is complete. */
int SCRCMD_POKEMON_FLD_GetPokedexComplete(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    struct ZukanSave *zukan;
    void *fieldMap;
    u16 *completeOut;

    zukan = func_0200CA1C(SCRCMD_WORK_GetGameData(work));
    fieldMap = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(work));
    completeOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    switch (SCRIPT_WORK_ReadWorkValue(vm, work)) {
    case 1:
        *completeOut = func_0200D298(zukan);
        break;
    case 3:
        *completeOut = func_0200D2B0(zukan, FIELDMAP_GetHeapId(fieldMap));
        break;
    case 2:
        *completeOut = func_0200D2C4(zukan, FIELDMAP_GetHeapId(fieldMap));
        break;
    }
    return 0;
}

/*
 * Move that the tutor of a starter group teaches to a Pokemon. Kind 0 is
 * the dragon tutor, kind 1 the group of the three older starter types and
 * kind 2 the group of the Unova starters.
 */
int SCRCMD_POKEMON_FLD_GetTutorMoveId(void *mon, int tutorKind)
{
    switch (tutorKind) {
    case 1:
        if (POKE_TOOL_CheckTutorCompat(mon, 3))
            return 0x152;
        if (POKE_TOOL_CheckTutorCompat(mon, 4))
            return 0x133;
        if (POKE_TOOL_CheckTutorCompat(mon, 5))
            return 0x134;
        break;
    case 0:
        return 0x1b2;
    case 2:
        if (POKE_TOOL_CheckTutorCompat(mon, 0))
            return 0x208;
        if (POKE_TOOL_CheckTutorCompat(mon, 1))
            return 0x207;
        if (POKE_TOOL_CheckTutorCompat(mon, 2))
            return 0x206;
        break;
    }
    return 0x133;
}

/*
 * Friendship that a Pokemon needs for the tutor of a kind.
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int SCRCMD_POKEMON_FLD_GetTutorFriendship(int tutorKind)
{
    return 255;
}

/* Whether a Pokemon belongs to a group that the tutor of a kind teaches. */
int SCRCMD_POKEMON_FLD_CheckTutorGroup(void *mon, int tutorKind)
{
    switch (tutorKind) {
    case 1:
        if (POKE_TOOL_CheckTutorCompat(mon, 3))
            return 1;
        if (POKE_TOOL_CheckTutorCompat(mon, 4))
            return 1;
        if (POKE_TOOL_CheckTutorCompat(mon, 5))
            return 1;
        return 0;
    case 0:
        if (POKE_TOOL_CheckTutorCompat(mon, 6))
            return 1;
        return 0;
    case 2:
        if (POKE_TOOL_CheckTutorCompat(mon, 0))
            return 1;
        if (POKE_TOOL_CheckTutorCompat(mon, 1))
            return 1;
        if (POKE_TOOL_CheckTutorCompat(mon, 2))
            return 1;
        return 0;
    }
    return 0;
}

/*
 * Finds the party members that the tutor of a kind can teach (eligibleMask
 * gets one bit per member; with checkFriendship only members with enough
 * friendship count). Returns 1 when no member is in the group, 2 when none
 * has the friendship, else 0.
 */
int SCRCMD_POKEMON_FLD_FindTutorCandidates(struct ScriptVm *vm, struct ScrcmdWork *work, int tutorKind, u8 *eligibleMask, u32 checkFriendship)
{
    void *party;
    int partyCount;
    int i;
    int anyInGroup;
    int anyEligible;
    void *mon;
    u32 friendship;

    party = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(work));
    partyCount = POKEPARTY_GetCount(party);
    anyInGroup = 0;
    anyEligible = 0;
    *eligibleMask = anyInGroup;
    for (i = 0; i < partyCount; i++) {
        mon = POKEPARTY_GetMember(party, i);
        if (POKE_TOOL_GetPartyValue(mon, 0x4c, 0) == 1)
            continue;
        if (SCRCMD_POKEMON_FLD_CheckTutorGroup(mon, tutorKind) == 0)
            continue;
        anyInGroup = 1;
        if (checkFriendship != 0) {
            friendship = POKE_TOOL_GetPartyValue(mon, 9, 0);
            if (friendship < SCRCMD_POKEMON_FLD_GetTutorFriendship(tutorKind))
                continue;
        }
        anyEligible = 1;
        *eligibleMask = *eligibleMask | (u8)(1 << i);
    }
    if (anyInGroup == 0)
        return 1;
    if (anyEligible == 0)
        return 2;
    return 0;
}

/* Script command: tutor availability of the party for a kind (0 ok, 1 no group member, 2 no friendship). */
int SCRCMD_POKEMON_FLD_GetTutorAvailability(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u32 tutorKind;
    u16 *resultOut;
    u32 eligibleMask;

    tutorKind = SCRIPT_WORK_ReadWorkValue(vm, work);
    resultOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *resultOut = SCRCMD_POKEMON_FLD_FindTutorCandidates(vm, work, tutorKind, (u8 *)(&eligibleMask), 1);
    return 0;
}

/* Script command: move that the tutor of a kind teaches to one party member (0 when there is no such member). */
int SCRCMD_POKEMON_FLD_GetMonTutorMove(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u32 tutorKind;
    u32 partySlot;
    u16 *moveOut;
    void *mon;
    int moveId;

    tutorKind = SCRIPT_WORK_ReadWorkValue(vm, work);
    partySlot = SCRIPT_WORK_ReadWorkValue(vm, work);
    moveOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    if (SCRCMD_PROC_GetPartyMember(work, partySlot, &mon) == 1)
        moveId = SCRCMD_POKEMON_FLD_GetTutorMoveId(mon, tutorKind);
    else
        moveId = 0;
    *moveOut = moveId;
    return 0;
}

/*
 * Script command: can a party member learn the tutor move of a kind?
 * Result 0 yes, 1 not in the group, 2 not enough friendship, 3 knows the
 * move already.
 */
int SCRCMD_POKEMON_FLD_CheckMonTutorStatus(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u32 tutorKind;
    u32 partySlot;
    u16 *resultOut;
    void *mon;

    tutorKind = SCRIPT_WORK_ReadWorkValue(vm, work);
    partySlot = SCRIPT_WORK_ReadWorkValue(vm, work);
    resultOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *resultOut = 1;
    if (SCRCMD_PROC_GetPartyMember(work, partySlot, &mon) == 0)
        return 0;
    if (SCRCMD_POKEMON_FLD_CheckTutorGroup(mon, tutorKind) == 0) {
        *resultOut = 1;
    } else if (SCRCMD_PROC_CheckMonKnowsMove((int)mon, SCRCMD_POKEMON_FLD_GetTutorMoveId(mon, tutorKind)) == 1) {
        *resultOut = 3;
    } else if (POKE_TOOL_GetPartyValue(mon, 9, 0) < SCRCMD_POKEMON_FLD_GetTutorFriendship(tutorKind)) {
        *resultOut = 2;
    } else {
        *resultOut = 0;
    }
    return 0;
}

/*
 * Script command: let the player pick a party member for the tutor of a
 * kind. Starts the party select event unless no member qualifies.
 */
int SCRCMD_POKEMON_FLD_SelectTutorMon(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u32 tutorKind;
    u16 *selectedSlotOut;
    u16 *resultOut;
    void *scriptWork;
    void *gameSystem;
    u32 displayMoveId;
    u8 eligibleMask;

    tutorKind = SCRIPT_WORK_ReadWorkValue(vm, work);
    selectedSlotOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    resultOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    scriptWork = SCRCMD_WORK_GetScriptWork(work);
    gameSystem = SCRCMD_WORK_GetGameSystem(work);
    if (SCRCMD_POKEMON_FLD_FindTutorCandidates(vm, work, tutorKind, &eligibleMask, 0)) {
        *selectedSlotOut = 0;
    } else {
        switch (tutorKind) {
        case 1:
            displayMoveId = 0xfffe;
            break;
        case 2:
            displayMoveId = 0xfffd;
            break;
        case 0:
            displayMoveId = 0x1b2;
            break;
        default:
            displayMoveId = 0xa5;
            break;
        }
        SCRIPT_SYS_CallEvent(scriptWork, EVENT_POKE_STATUS_CreatePokeSelectMoveEvent(gameSystem, selectedSlotOut, resultOut, eligibleMask, displayMoveId));
    }
    return 1;
}

/* Script command: does any party member have the flag of value 0x97 set? */
int SCRCMD_POKEMON_FLD_CheckPartyFlagged(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u16 *foundOut;
    void *party;
    u32 partyCount;
    u32 i;

    foundOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *foundOut = 0;
    party = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(work));
    partyCount = POKEPARTY_GetCount(party);
    for (i = 0; i < partyCount; i++) {
        if (POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(party, i), 0x97, 0) != 0) {
            *foundOut = 1;
            break;
        }
    }
    return 0;
}

/* Script command: type of the signature move check of a party member (0xFFFF when it does not qualify). */
int SCRCMD_POKEMON_FLD_GetMonTypeForTm(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u16 *typeOut;
    u32 partySlot;
    u32 tmValue;
    void *mon;

    typeOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    partySlot = SCRIPT_WORK_ReadWorkValue(vm, work);
    tmValue = func_0202130C(0x151);
    if (SCRCMD_PROC_GetPartyMember(work, partySlot, &mon) == 0) {
        *typeOut = 0xFFFF;
    } else if (POKE_TOOL_CheckTmCompat(mon, tmValue) == 0) {
        *typeOut = 0xFFFF;
    } else {
        *typeOut = POKE_TOOL_GetHiddenPowerType(mon);
    }
    return 0;
}

/* Script command: start a selection event with two script arguments and a result variable. */
int SCRCMD_POKEMON_FLD_StartSelectEvent(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *scriptWork;
    void *gameSystem;
    u16 *resultOut;
    u32 firstArg;

    scriptWork = SCRCMD_WORK_GetScriptWork(work);
    gameSystem = SCRCMD_WORK_GetGameSystem(work);
    resultOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    firstArg = SCRIPT_WORK_ReadWorkValue(vm, work);
    SCRIPT_SYS_CallEvent(scriptWork, (void *)SCRCMD_CreateNicknameEvent(gameSystem, (int)resultOut, firstArg, SCRIPT_WORK_ReadWorkValue(vm, work)));
    return 1;
}

/* Script command: open the move select screen of a party member. */
int SCRCMD_POKEMON_FLD_SelectMonMove(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u16 *moveOut;
    u16 *resultOut;
    u16 partySlot;
    u16 mode;
    void *scriptWork;
    void *gameSystem;

    moveOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    resultOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    partySlot = SCRIPT_WORK_ReadWorkValue(vm, work);
    mode = SCRIPT_WORK_ReadWorkValue(vm, work);
    scriptWork = SCRCMD_WORK_GetScriptWork(work);
    gameSystem = SCRCMD_WORK_GetGameSystem(work);
    SCRIPT_SYS_CallEvent(scriptWork, (void *)EVENT_POKE_STATUS_CreateMoveSelectEvent((int)gameSystem, (int)GAMESYSTEM_GetFieldMap(gameSystem), partySlot, (int)moveOut, (int)resultOut, mode == 0, mode));
    return 1;
}

/*
 * Script command: find the first egg in the party that is ready to hatch
 * and start its hatch event; the party index goes to the result variable.
 * Returns 1 when an event started.
 */
u32 SCRCMD_POKEMON_FLD_StartEggHatch(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u16 *slotOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    void *scriptWork = SCRCMD_WORK_GetScriptWork(work);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(work);
    void *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    void *gameData;
    void *party;
    int partyCount;
    int i;

    FIELDMAP_GetHeapId(fieldMap);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    GAME_DATA_GetMyStatus(gameData);
    party = GAME_DATA_GetMyParty(gameData);
    partyCount = POKEPARTY_GetCount(party);
    for (i = 0; i < partyCount; i++) {
        void *mon = POKEPARTY_GetMember(party, i);
        u32 isEgg = POKE_TOOL_GetPartyValue(mon, 0x4c, 0);
        u32 isBadEgg = POKE_TOOL_GetPartyValue(mon, 3, 0);
        u32 hatchCounter = POKE_TOOL_GetPartyValue(mon, 9, 0);

        if (isEgg != 0 && isBadEgg == 0 && hatchCounter == 0) {
            SCRIPT_SYS_CallEvent(scriptWork, SYMBOL_MAP_CreatePokeEventTask(gameSystem, fieldMap, mon));
            *slotOut = i;
            return 1;
        }
    }
    return 0;
}

/*
 * Script command: compare a party member with the trade request. Result 0
 * fits, 1 egg, 2 wrong species, 3 wrong gender.
 */
int SCRCMD_POKEMON_FLD_CheckTradeMon(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *gameSystem;
    void *gameData;
    u32 heapId;
    u16 *resultOut;
    u32 tradeId;
    u32 partySlot;
    void *mon;
    struct FldTrade *trade;
    u32 value;

    SCRCMD_WORK_GetScriptWork(work);
    gameSystem = SCRCMD_WORK_GetGameSystem(work);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    heapId = FIELDMAP_GetHeapId(GAMESYSTEM_GetFieldMap(gameSystem));
    resultOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    tradeId = SCRIPT_WORK_ReadWorkValue(vm, work);
    partySlot = SCRIPT_WORK_ReadWorkValue(vm, work);
    mon = POKEPARTY_GetMember(GAME_DATA_GetMyParty(gameData), partySlot);
    trade = FLD_TRADE_Create(heapId, tradeId);
    *resultOut = 0;
    if (*resultOut == 0 && POKE_TOOL_GetPartyValue(mon, 0x4c, 0) == 1) {
        *resultOut = 1;
    }
    if (*resultOut == 0) {
        value = POKE_TOOL_GetPartyValue(mon, 5, 0);
        if (value != FLD_TRADE_GetWantedSpecies(trade)) {
            *resultOut = 2;
        }
    }
    if (*resultOut == 0 && FLD_TRADE_GetWantedGender(trade) != 2) {
        value = POKE_TOOL_GetPartyValue(mon, 0x6e, 0);
        if (value != FLD_TRADE_GetWantedGender(trade)) {
            *resultOut = 3;
        }
    }
    FLD_TRADE_Delete(trade);
    return 0;
}

/* Script command: start the trade event for a trade and a party slot. */
u32 SCRCMD_POKEMON_FLD_StartTradeEvent(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(work);
    void *gameSystem = SCRCMD_WORK_GetGameSystem(work);
    u32 tradeId = SCRIPT_WORK_ReadWorkValue(vm, work);
    u32 partySlot = SCRIPT_WORK_ReadWorkValue(vm, work);
    SCRIPT_SYS_CallEvent(scriptWork, FLD_TRADE_CreateEvent(gameSystem, (u8)tradeId, (u8)partySlot));
    return 1;
}

/* Script command: pick a random entry of bag pocket 2 and return its value (0 when the pocket is empty). */
u32 SCRCMD_POKEMON_FLD_GetRandomBagPocketValue(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u16 *valueOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    void *bag = GAME_DATA_GetMyItem(SCRCMD_WORK_GetGameData(work));
    int pocket = 2;
    u32 itemCount = func_02007FA0(bag, 2);
    u32 randomIndex = func_020056EC(itemCount);
    u16 value;

    if (itemCount == 0)
        value = 0;
    else
        value = func_020212B0(*func_020081DC(bag, pocket, randomIndex));
    *valueOut = value;
    return 0;
}

/* Script command: store the name of a party member in a slot of the stored name save block. */
u32 SCRCMD_POKEMON_FLD_StoreMonName(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *gameData;
    void *nameStore;
    int partySlot;
    int nameSlot;

    SCRCMD_WORK_GetScriptWork(work);
    gameData = GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(work));
    nameStore = GAME_DATA_GetSaveBlock43(gameData);
    gameData = GAME_DATA_GetMyParty(gameData);
    partySlot = SCRIPT_WORK_ReadWorkValue(vm, work);
    nameSlot = SCRIPT_WORK_ReadWorkValue(vm, work);
    func_0200E7BC(nameStore, nameSlot, POKEPARTY_GetMember(gameData, partySlot));
    return 0;
}

/*
 * Script command: put a stored name in the word set (the end-of-string
 * character alone when the slot is empty).
 *
 * The else arm zero is an array initialiser: `u16 s[1] = {0}` keeps &s in r6
 * for the call argument while the result store gets a fresh add sp.
 */
int SCRCMD_POKEMON_FLD_RegisterStoredName(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *scriptWork;
    void *nameStore;
    u32 nameSlot;
    u32 wordSetIndex;
    void *tempBuffer;
    void *wordSet;

    scriptWork = SCRCMD_WORK_GetScriptWork(work);
    nameStore = GAME_DATA_GetSaveBlock43(GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(work)));
    nameSlot = SCRIPT_WORK_ReadWorkValue(vm, work);
    wordSetIndex = SCRIPT_WORK_ReadWorkValue(vm, work);
    tempBuffer = (void *)SCRIPT_WORK_GetTempBuffer(scriptWork);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    if (func_0200E740(nameStore, nameSlot)) {
        STRBUF_SetString(tempBuffer, func_0200E7AC(nameStore, nameSlot));
    } else {
        u16 emptyName[1] = {0};
        emptyName[0] = STRBUF_GetEosChar();
        STRBUF_SetString(tempBuffer, emptyName);
    }
    func_0201EE0C(wordSet, wordSetIndex, tempBuffer, 0, 1, 2);
    return 0;
}

/*
 * Script command: handling of the player's own Reshiram. Operation 0 checks
 * that one is in the party, 1 moves it to the front of the party, 2 first
 * swaps the party member in the result variable with the one in the boxes.
 */
u32 SCRCMD_POKEMON_FLD_ControlLegendMon(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u32 operation = SCRIPT_WORK_ReadWorkValue(vm, work);
    u16 *resultOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    void *gameData = SCRCMD_WORK_GetGameData(work);

    switch (operation) {
    case 0:
        if (SCRCMD_POKEMON_FLD_FindPartyLegend(gameData) < 0)
            *resultOut = 0;
        else
            *resultOut = 1;
        break;
    case 1:
        SCRCMD_POKEMON_FLD_MoveLegendToFront(work);
        break;
    case 2:
        SCRCMD_POKEMON_FLD_SwapPartyMonWithBoxedLegend(work, *resultOut);
        SCRCMD_POKEMON_FLD_MoveLegendToFront(work);
        break;
    }
    return 0;
}

/*
 * Swaps a party member with the player's boxed Reshiram (species 0x283). A
 * held mail goes to the mailbox and Shaymin takes its Land Forme.
 */
void SCRCMD_POKEMON_FLD_SwapPartyMonWithBoxedLegend(struct ScrcmdWork *work, int partySlot)
{
    void *gameData;
    void *party;
    u32 heapId;
    void *boxManager;
    void *mon;
    u32 monSize;
    void *mailSave;
    void *mail;
    int mailSlot;
    void *boxedPartyMon;
    u16 boxPos[2];

    gameData = SCRCMD_WORK_GetGameData(work);
    party = GAME_DATA_GetMyParty(gameData);
    if (SCRCMD_POKEMON_FLD_FindBoxedLegend(gameData, 0x283, &boxPos[1], &boxPos[0]) == 0) {
        return;
    }
    heapId = SCRCMD_WORK_GetHeapId(work);
    boxManager = (void *)GAME_DATA_GetBoxManager(gameData);
    mon = func_02030734(heapId, POKE_TOOL_GetPartyParamSize(), 1, (const char *)sScrcmdPokemonFldFileName, 0x4c7);
    monSize = POKE_TOOL_GetPartyParamSize();
    func_02082D44(POKEPARTY_GetMember(party, partySlot), mon, monSize);
    if (func_0202136C(POKE_TOOL_GetPartyValue(mon, 6, 0)) == 1) {
        mailSave = func_02008FEC(gameData);
        mail = MAIL_Create(SCRCMD_WORK_GetHeapId(work));
        mailSlot = MAIL_FindEmptySlot(mailSave, 0);
        POKE_TOOL_GetPartyValue(mon, 0xa7, (u32)mail);
        GAME_DATA_GetMyStatus(gameData);
        if (mailSlot >= 0) {
            func_0200903C(mailSave, 0, mailSlot, mail);
        }
        func_02008EAC(mail);
        POKE_TOOL_SetPartyValue(mon, 0xa7, (u32)mail);
        POKE_TOOL_SetPartyValue(mon, 6, 0);
        func_020307B0(mail);
    }
    if (POKE_TOOL_GetPartyValue(mon, 0xab, 0) == 0x1ec) {
        POKE_TOOL_ChangeForm(mon, 0);
        POKE_TOOL_RecalcParam(mon);
    }
    boxedPartyMon = POKE_TOOL_CreateFromBoxParam(func_02007A18(boxManager, boxPos[1], boxPos[0]), heapId);
    POKEPARTY_SetMember(party, partySlot, boxedPartyMon);
    func_020307B0(boxedPartyMon);
    func_020075B0(boxManager, boxPos[1], boxPos[0], POKE_TOOL_Dummy(mon));
    func_020307B0(mon);
}

/*
 * Looks for a box slot that holds a non-egg Pokemon of the species with
 * the trainer id of the player, starting at the box that the box manager
 * names; stores box and slot and returns 1 when found.
 */
int SCRCMD_POKEMON_FLD_FindBoxedLegend(void *gameData, u16 species, u16 *boxOut, u16 *slotOut)
{
    int startBox;
    int i;
    u32 trainerId;
    int slot;
    int box;
    void *myStatus;
    void *boxManager;

    GAME_DATA_GetMyParty(gameData);
    myStatus = GAME_DATA_GetMyStatus(gameData);
    boxManager = (void *)GAME_DATA_GetBoxManager(gameData);
    startBox = func_02007698();
    trainerId = func_02008530(myStatus);
    for (i = 0; i < 24; i++) {
        box = (i + startBox) % 24;
        for (slot = 0; slot < 30; slot++) {
            if (func_020079BC((void **)boxManager, box, slot, 0xa9, 0) != 0
                && trainerId == func_020079BC((void **)boxManager, box, slot, 7, 0)
                && species == func_020079BC((void **)boxManager, box, slot, 5, 0)
                && func_020079BC((void **)boxManager, box, slot, 0x4c, 0) == 0) {
                *boxOut = box;
                *slotOut = slot;
                return 1;
            }
        }
    }
    return 0;
}

/* Moves the player's own Reshiram of the party to the first party slot. */
void SCRCMD_POKEMON_FLD_MoveLegendToFront(struct ScrcmdWork *work)
{
    void *gameData;
    void *party;
    int partyIndex;

    gameData = SCRCMD_WORK_GetGameData(work);
    party = GAME_DATA_GetMyParty(gameData);
    partyIndex = SCRCMD_POKEMON_FLD_FindPartyLegend(gameData);
    if (partyIndex >= 0) {
        POKEPARTY_SwapMembers(party, partyIndex, 0, SCRCMD_WORK_GetHeapId(work));
    }
}

/* Party index of the player's own Reshiram that is not an egg, or -1. */
int SCRCMD_POKEMON_FLD_FindPartyLegend(void *gameData)
{
    void *party = GAME_DATA_GetMyParty(gameData);
    void *myStatus = GAME_DATA_GetMyStatus(gameData);
    int partyCount = POKEPARTY_GetCount(party);
    u32 trainerId = func_02008530(myStatus);
    int i;

    for (i = 0; i < partyCount; i++) {
        void *mon = POKEPARTY_GetMember(party, i);

        if (trainerId == POKE_TOOL_GetPartyValue(mon, 7, 0)
            && POKE_TOOL_GetPartyValue(mon, 5, 0) == 0x283
            && POKE_TOOL_GetPartyValue(mon, 0x4c, 0) == 0)
            return i;
    }
    return -1;
}

/*
 * Script command: start the sub process of overlay 55 with the map function
 * of the field map.
 *
 * gCrowdSubprocTemplate is the ov055 proc table (ov055 is the overlay id passed to
 * FIELD_SUBPROC_Start), hence the ov055 token on its symbols: line.
 */
int SCRCMD_POKEMON_FLD_StartOv55SubProc(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    FIELD_SUBPROC_Start((int)ov055_id, (int *)FIELDMAP_GetMapFunc((u8 *)SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(work))->fieldSystem), gCrowdSubprocTemplate);
    return 0;
}

/*
 * Script command: look up the entry of the mystery data for the owner's
 * birthday and the date, and put its text in the word set.
 */
u32 SCRCMD_POKEMON_FLD_RegisterBirthdayEntry(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *gameData = SCRCMD_WORK_GetGameData(work);
    u32 wordSetIndex = SCRIPT_WORK_ReadWorkValue(vm, work);
    void *mysteryData;
    int entryIndex;
    int flags;
    void *entryText;
    void *date;
    void *wordSet;
    struct Strbuf *text;
    OwnerInfo owner;

    mysteryData = func_0200A8A0(GAME_DATA_GetSaveControl(gameData));
    date = FIELD_CLOCK_GetDate((int)gameData);
    func_02087C88((struct OSOwnerInfo *)(&owner));
    entryIndex = func_0200A940(mysteryData, owner.birthMonth, owner.birthDay, date);
    flags = func_0200A8F8(mysteryData, entryIndex);
    flags = flags != 1;
    entryText = func_0200A8C8(mysteryData, entryIndex);
    wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(work));
    text = STRBUF_Create(8, 0x8001);
    STRBUF_SetString(text, (const u16 *)entryText);
    func_0201EE0C((struct WordSet *)wordSet, wordSetIndex, text, flags, 1, 2);
    STRBUF_Delete(text);
    return 0;
}

/* Script command: number of entries of the mystery data. */
int SCRCMD_POKEMON_FLD_GetMysteryEntryCount(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *gameData;
    u16 *countOut;

    gameData = SCRCMD_WORK_GetGameData(work);
    countOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *countOut = func_0200A8AC(func_0200A8A0(GAME_DATA_GetSaveControl(gameData)));
    return 0;
}

/* Entry number index of a warp list. */
WarpEntry *SCRCMD_POKEMON_FLD_GetWarpEntry(WarpEntry *table, u32 index)
{
    return table + index;
}

void SCRCMD_POKEMON_FLD_NoopWarpEntry(u16 *labelId)
{
}

/* Number of entries of a warp list (0 when the list has no end marker among the first 8). */
int SCRCMD_POKEMON_FLD_CountWarpEntries(WarpEntry *table)
{
    int i;
    u16 *labelId;

    for (i = 0; i < 8; i++) {
        labelId = (u16 *)SCRCMD_POKEMON_FLD_GetWarpEntry(table, i);
        SCRCMD_POKEMON_FLD_NoopWarpEntry(labelId);
        if (*labelId == 0xFFFF) {
            return i;
        }
    }
    return 0;
}

/*
 * Script command: keep the warp list that follows the command in the
 * script data for the next warp commands.
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */
int SCRCMD_POKEMON_FLD_SetWarpTable(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    SCRCMD_WORK_SetFadeState(work, (u32)(vm->pc + VM_GetU32(vm)));
    return 0;
}

/* Script command: add every warp of the list, except the current map, to the menu. */
u32 SCRCMD_POKEMON_FLD_AddWarpMenuItems(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    WarpEntry *table = (WarpEntry *)SCRCMD_WORK_GetFadeState(work);
    void *scriptWork = SCRCMD_WORK_GetScriptWork(work);
    int msgBuffer = SCRIPT_WORK_GetMsgBuffer(scriptWork);
    int tempBuffer = SCRIPT_WORK_GetTempBuffer(scriptWork);
    u16 currentMapId = SCRCMD_WORK_GetScriptId(work);
    u32 entryCount = SCRCMD_POKEMON_FLD_CountWarpEntries(table);
    u32 i = 0;

    for (; i < entryCount; i++) {
        WarpEntry *entry = SCRCMD_POKEMON_FLD_GetWarpEntry(table, i);

        if (currentMapId != entry->mapId)
            SCRCMD_WORK_AddMenuItem(work, entry->labelId, 0xffff, i, (struct Strbuf *)msgBuffer, (void *)tempBuffer);
    }
    return 0;
}

/* Script command: warp to an entry of the warp list. */
u32 SCRCMD_POKEMON_FLD_WarpToEntry(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u32 entryIndex = SCRIPT_WORK_ReadWorkValue(vm, work);
    WarpEntry *table = (WarpEntry *)SCRCMD_WORK_GetFadeState(work);

    SCRCMD_WORK_GetScriptId(work);
    if (entryIndex < SCRCMD_POKEMON_FLD_CountWarpEntries(table)) {
        const WarpEntry *entry = SCRCMD_POKEMON_FLD_GetWarpEntry(table, entryIndex);
        void *scriptWork = SCRCMD_WORK_GetScriptWork(work);
        void *gameSystem = SCRIPT_WORK_GetGameSystem(scriptWork);
        void *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
        Vec3 position;
        u32 gridY = entry->gridY;
        u32 gridZ = entry->gridZ;
        u32 mapId = entry->mapId;
        u32 gridX = entry->gridX;

        position.x = gridX << 16;
        position.y = gridY << 16;
        position.z = gridZ << 16;
        SCRIPT_SYS_CallEvent(scriptWork, (void *)EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(gameSystem, fieldMap, mapId, &position, 1));
    }
    return 1;
}

/*
 * Script command: read the received mystery gift data and do the operation
 * of the mode on it: 0 whether a gift of a known kind is waiting, 1 to 3 and
 * 7 checks and queries of its kind, 4 hand it over, 5 and 6 queries on the
 * field map.
 */
int SCRCMD_POKEMON_FLD_HandleMysteryGift(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    int mode;
    u16 *resultOut;
    void *gameData;
    void *giftHandle;
    u32 heapId;
    MysteryGiftCard *giftData;
    int giftKind;
    MysteryGiftCard cardBuffer;
    u32 giftIndex;

    mode = SCRIPT_WORK_ReadWorkValue(vm, work);
    resultOut = SCRIPT_WORK_ReadWorkPointer(vm, work);
    gameData = SCRCMD_WORK_GetGameData(work);
    heapId = SCRCMD_WORK_GetHeapId(work);
    giftHandle = MYSTERY_DATA_Create(GAME_DATA_GetSaveControl(gameData), 0, (void *)heapId);
    giftData = PDW_POSTMAN_FindMysteryCard(giftHandle, (int *)(&giftIndex), &cardBuffer);
    giftKind = PDW_POSTMAN_GetMysteryGiftType(giftHandle);
    if (giftKind != sMysteryGiftKindHandlers[giftKind].kind) {
        MYSTERY_DATA_Delete(giftHandle);
        return 0;
    }
    switch (mode) {
    case 0:
        if (giftKind != 0) {
            *resultOut = 1;
        } else {
            *resultOut = 0;
        }
        break;
    case 1:
        *resultOut = SCRCMD_POKEMON_FLD_CheckGiftCanReceive(giftKind, work, gameData, giftData);
        break;
    case 2:
        *resultOut = SCRCMD_POKEMON_FLD_PrepareGiftReceiveMessage(giftKind, giftData, work);
        break;
    case 3:
        *resultOut = SCRCMD_POKEMON_FLD_PrepareGiftFollowUpMessage(giftKind, giftData, work);
        break;
    case 4:
        if (SCRCMD_POKEMON_FLD_ReceiveGift(giftKind, work, gameData, giftData) == 1) {
            PDW_POSTMAN_SetMysteryReceived(giftHandle, giftIndex);
            if (SCRCMD_POKEMON_FLD_IsLibertyPassGift(giftData, giftKind) == 1) {
                FIELD_G3D_MAP_StoreBeaconTrainerKey(GAME_DATA_GetMiscSave(gameData), 1, GAME_DATA_GetMyStatus(gameData));
            }
        }
        *resultOut = 0;
        break;
    case 5:
        *resultOut = SCRCMD_POKEMON_FLD_GetDeliveryNpcId(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(work)), gameData);
        break;
    case 6:
        *resultOut = SCRCMD_POKEMON_FLD_CheckDeliveryNpcLoaded(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(work)));
        break;
    case 7:
        *resultOut = SCRCMD_POKEMON_FLD_GetGiftReceiveType(giftKind, work, gameData, giftData);
        break;
    }
    MYSTERY_DATA_Delete(giftHandle);
    return 0;
}


/* Asks the kind handler whether the player can take the gift. 0 when the kind has none. */
int SCRCMD_POKEMON_FLD_CheckGiftCanReceive(int giftKind, struct ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    MysteryGiftQueryFn canReceive = sMysteryGiftKindHandlers[giftKind].canReceive;

    if (card != 0 && canReceive != 0) {
        return canReceive(work, gameData, card);
    }
    return 0;
}


/* Fills the word set for the gift received message and returns its message id.
 * 7 when the kind has no handler. */
int SCRCMD_POKEMON_FLD_PrepareGiftReceiveMessage(int giftKind, MysteryGiftCard *card, struct ScrcmdWork *work)
{
    struct WordSet *wordSet;
    MysteryGiftMessageFn prepareMessage;

    wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(work));
    prepareMessage = sMysteryGiftKindHandlers[giftKind].prepareReceiveMessage;
    if (card != 0 && prepareMessage != 0) {
        return prepareMessage(wordSet, card, work);
    }
    return 7;
}


/* Fills the word set for the follow-up message of the gift and returns its
 * message id. 8 when the kind has no handler. */
int SCRCMD_POKEMON_FLD_PrepareGiftFollowUpMessage(int giftKind, MysteryGiftCard *card, struct ScrcmdWork *work)
{
    struct WordSet *wordSet;
    MysteryGiftMessageFn prepareMessage;

    wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(work));
    prepareMessage = sMysteryGiftKindHandlers[giftKind].prepareFollowUpMessage;
    if (card != 0 && prepareMessage != 0) {
        return prepareMessage(wordSet, card, work);
    }
    return 8;
}

/* Puts the gift into the save through the kind handler. 1 when a handler ran. */
int SCRCMD_POKEMON_FLD_ReceiveGift(int giftKind, struct ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    MysteryGiftReceiveFn receive = sMysteryGiftKindHandlers[giftKind].receive;

    if (card != 0 && receive != 0) {
        receive(work, gameData, card);
        return 1;
    }
    return 0;
}


/* Asks the kind handler which scene the script plays for the gift. 0 when the kind has none. */
int SCRCMD_POKEMON_FLD_GetGiftReceiveType(int giftKind, ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    MysteryGiftQueryFn getReceiveType = sMysteryGiftKindHandlers[giftKind].getReceiveType;

    if (card != 0 && getReceiveType != 0) {
        return getReceiveType(work, gameData, card);
    }
    return 0;
}

/* Script command mode: object id of the delivery person on the map, found among
 * the loaded models first, then among the placement records of the zone. 0 when absent. */
u16 SCRCMD_POKEMON_FLD_GetDeliveryNpcId(struct FieldMap *fieldMap, struct GameData *gameData)
{
    Mmdl *mmdl;
    int objId;

    mmdl = SCRCMD_POKEMON_FLD_FindDeliveryMmdl(fieldMap);
    if (mmdl != 0) {
        return FLDMMDL_GetObjId(mmdl);
    }
    objId = SCRCMD_POKEMON_FLD_FindDeliveryNpcObjId(gameData);
    if (objId >= 0) {
        return objId;
    }
    return 0;
}

/* Script command mode: 1 when a delivery person model is loaded on the map. */
u16 SCRCMD_POKEMON_FLD_CheckDeliveryNpcLoaded(struct FieldMap *fieldMap)
{
    return SCRCMD_POKEMON_FLD_FindDeliveryMmdl(fieldMap) != 0 ? 1 : 0;
}

/* Finds the loaded model with the delivery person's object code. */
Mmdl *SCRCMD_POKEMON_FLD_FindDeliveryMmdl(struct FieldMap *fieldMap)
{
    u32 iterator = 0;
    Mmdl *mmdl;
    MmdlSys *mmdlSys;

    mmdlSys = FIELDMAP_GetMmdlSys(fieldMap);
    while (FLDMMDL_SysSearchUseMmdl(mmdlSys, &mmdl, &iterator) == 1) {
        if (FLDMMDL_GetObjCode(mmdl) == SCRCMD_DELIVERY_OBJ_CODE)
            return mmdl;
    }
    return 0;
}

/*
 * Searches the placement records of the zone for the delivery person and
 * returns its object id, or -1. The return reads through a byte offset rather
 * than headers[i].objId: the subscript form lets the compiler CSE
 * headers + i*0x24 into one register (product in r2, ldrh r0,[r3]); the
 * byte-offset form keeps only the product live and loads ldrh r0,[r4,r3]
 * as the original does.
 */
int SCRCMD_POKEMON_FLD_FindDeliveryNpcObjId(struct GameData *gameData)
{
    MmdlHeader *headers;
    int count;
    struct EventDataSystem *eventData;
    int i;

    eventData = GAME_DATA_GetEventData(gameData);
    headers = EVENTDATA_SYSTEM_GetNpcHeaders(eventData);
    count = EVENTDATA_SYSTEM_GetNpcCount(eventData);
    if (headers == 0 || count == 0) {
        return -1;
    }
    for (i = 0; i < count; i++) {
        if (headers[i].objCode == SCRCMD_DELIVERY_OBJ_CODE) {
            return *(u16 *)((u8 *)headers + i * sizeof(MmdlHeader));
        }
    }
    return -1;
}

/* TRUE for the Liberty Pass gift: an item card of item 0x23E with event number 0x7FE. */
int SCRCMD_POKEMON_FLD_IsLibertyPassGift(MysteryGiftCard *card, int giftType)
{
    if (giftType != MYSTERY_GIFT_TYPE_ITEM) {
        return 0;
    }
    if (card->eventId != MYSTERY_GIFT_LIBERTY_PASS_EVENT) {
        return 0;
    }
    if (card->param == MYSTERY_GIFT_LIBERTY_PASS_ITEM) {
        return 1;
    }
    return 0;
}

/* Builds the gift Pokemon of a card in a heap block. The caller frees it. */
struct PokemonParam *SCRCMD_POKEMON_FLD_CreateGiftMon(ScrcmdWork *work, MysteryGiftCard *card)
{
    return MYSTERY_GIFT_CreateMon(card, SCRCMD_WORK_GetHeapId(work), SCRCMD_WORK_GetGameData(work));
}

/* Kind 1 canReceive: the party has room. */
int SCRCMD_POKEMON_FLD_CheckGiftMonCanReceive(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    if (POKEPARTY_GetCount(GAME_DATA_GetMyParty(gameData)) < MYSTERY_GIFT_PARTY_MAX) {
        return 1;
    }
    return 0;
}

/* Kind 1 receive: adds the gift Pokemon to the party and registers it in the Pokedex. */
void SCRCMD_POKEMON_FLD_ReceiveGiftMon(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    struct Party *party;
    struct PokemonParam *mon;

    party = GAME_DATA_GetMyParty(gameData);
    mon = SCRCMD_POKEMON_FLD_CreateGiftMon(work, card);
    if (POKEPARTY_GetCount(party) < MYSTERY_GIFT_PARTY_MAX && mon != 0) {
        POKEPARTY_Add(party, mon);
        func_0200CDE0(func_0200CA1C(gameData), mon);
        func_020307B0(mon);
    }
}

/* Kind 1 getReceiveType: egg or Pokemon. */
int SCRCMD_POKEMON_FLD_GetGiftMonReceiveType(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    struct PokemonParam *mon;
    int isEgg;

    mon = SCRCMD_POKEMON_FLD_CreateGiftMon(work, card);
    if (mon == 0) {
        return MYSTERY_GIFT_RECEIVE_MON;
    }
    isEgg = POKE_TOOL_GetPartyValue(mon, MYSTERY_GIFT_MON_PARAM_IS_EGG, 0);
    func_020307B0(mon);
    return isEgg == 1 ? MYSTERY_GIFT_RECEIVE_EGG : MYSTERY_GIFT_RECEIVE_MON;
}

/* Kind 1 prepareReceiveMessage: player name and Pokemon name; the egg message has no Pokemon name. */
int SCRCMD_POKEMON_FLD_PrepareGiftMonMessage(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work)
{
    struct PokemonParam *mon;
    struct MyStatus *myStatus;
    int messageId;

    myStatus = GAME_DATA_GetMyStatus(SCRCMD_WORK_GetGameData(work));
    mon = SCRCMD_POKEMON_FLD_CreateGiftMon(work, card);
    messageId = MYSTERY_GIFT_MSG_MON_RECEIVED;
    func_0201F02C(wordSet, 0, myStatus);
    if (mon == 0) {
        func_0201EEC4(wordSet, 1, 0);
    } else {
        if (POKE_TOOL_GetPartyValue(mon, MYSTERY_GIFT_MON_PARAM_IS_EGG, 0) == 1)
            messageId = MYSTERY_GIFT_MSG_EGG_RECEIVED;
        else
            func_0201EED4(wordSet, 1, mon);
        func_020307B0(mon);
    }
    return messageId;
}

/* Kind 1 prepareFollowUpMessage. */
int SCRCMD_POKEMON_FLD_PrepareGiftMonFollowUpMessage(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work)
{
    return MYSTERY_GIFT_MSG_MON_FOLLOW_UP;
}

/* Kind 2 canReceive: an item always fits. */
int SCRCMD_POKEMON_FLD_CheckGiftItemCanReceive(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    return 1;
}

/* Kind 2 receive: puts one of the item into the bag when the id is in range. */
void SCRCMD_POKEMON_FLD_ReceiveGiftItem(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    u32 heapId;
    struct MyItem *bag;
    u16 itemId;

    heapId = SCRCMD_WORK_GetHeapId(work);
    bag = GAME_DATA_GetMyItem(gameData);
    itemId = card->param;
    if (itemId != 0 && itemId <= MYSTERY_GIFT_ITEM_MAX) {
        func_02007E50(bag, itemId, 1, heapId);
    }
}

/* Kind 2 getReceiveType: the Liberty Pass or a plain item. */
int SCRCMD_POKEMON_FLD_GetGiftItemReceiveType(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    if (SCRCMD_POKEMON_FLD_IsLibertyPassGift(card, card->giftType) == 1) {
        return MYSTERY_GIFT_RECEIVE_LIBERTY_PASS;
    }
    return MYSTERY_GIFT_RECEIVE_ITEM;
}

/* Kind 2 prepareReceiveMessage: player name and item name. */
int SCRCMD_POKEMON_FLD_PrepareGiftItemMessage(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work)
{
    struct MyStatus *myStatus;
    u16 itemId;

    myStatus = GAME_DATA_GetMyStatus(SCRCMD_WORK_GetGameData(work));
    itemId = card->param;
    func_0201F02C(wordSet, 0, myStatus);
    func_0201EF40(wordSet, 1, itemId);
    return MYSTERY_GIFT_MSG_ITEM_RECEIVED;
}

/* Kind 2 prepareFollowUpMessage: item name. */
int SCRCMD_POKEMON_FLD_PrepareGiftItemFollowUpMessage(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work)
{
    func_0201EF40(wordSet, 0, (u16)card->param);
    return MYSTERY_GIFT_MSG_ITEM_FOLLOW_UP;
}

/* Kind 3 canReceive: always. */
int SCRCMD_POKEMON_FLD_CheckGiftFlagCanReceive(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    return 1;
}

/* Kind 3 receive: sets the obtained flag of the card in the intrude save. */
void SCRCMD_POKEMON_FLD_ReceiveGiftFlag(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    func_0200BF18(func_0200BE48(GAME_DATA_GetSaveControl(gameData)), card->param);
}

/* Kind 3 getReceiveType. */
int SCRCMD_POKEMON_FLD_GetGiftFlagReceiveType(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    return MYSTERY_GIFT_RECEIVE_FLAG;
}

/* Kind 3 prepareReceiveMessage: player name and the flag id as a number. */
int SCRCMD_POKEMON_FLD_PrepareGiftFlagMessage(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work)
{
    struct GameData *gameData;
    struct MyStatus *myStatus;
    u32 flagId;

    gameData = SCRCMD_WORK_GetGameData(work);
    func_0200BE48(GAME_DATA_GetSaveControl(gameData));
    myStatus = GAME_DATA_GetMyStatus(gameData);
    flagId = card->param;
    func_0201F02C(wordSet, 0, myStatus);
    func_0201F184(wordSet, 1, flagId);
    return MYSTERY_GIFT_MSG_FLAG_RECEIVED;
}

/* Kind 3 prepareFollowUpMessage. */
int SCRCMD_POKEMON_FLD_PrepareGiftFlagFollowUpMessage(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work)
{
    return MYSTERY_GIFT_MSG_FLAG_FOLLOW_UP;
}

/* Script command: looks a key up in a key to value table and returns the
 * value in the result variable (0 when the key is not listed).
 * Arguments: key, table index, result variable. */
int SCRCMD_POKEMON_FLD_LookupTableValue(struct ScriptVm *vm, ScrcmdWork *work)
{
    u32 i;
    u32 heapId;
    u32 key;
    u32 tableIndex;
    u16 *result;
    ScrcmdKeyValueEntry *table;
    u32 count;

    heapId = FIELDMAP_GetHeapId((struct FieldMap *)SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(work))->fieldSystem);
    key = SCRIPT_WORK_ReadWorkValue(vm, work);
    tableIndex = SCRIPT_WORK_ReadWorkValue(vm, work);
    result = SCRIPT_WORK_ReadWorkPointer(vm, work);
    table = (ScrcmdKeyValueEntry *)ARC_UTIL_LoadMemberWithSize(SCRCMD_TABLE_ARC_ID, sScrcmdTableFileIds[tableIndex], 0, (u16)((heapId & 0x7fff) | SCRCMD_HEAP_FLAG_TAIL), &count);
    count >>= 3;
    i = 0;
    *result = 0;
    for (i = 0; i < count; i++) {
        if (key == table[i].key) {
            *result = table[i].value;
            break;
        }
    }
    func_020307B0(table);
    return 0;
}

/* Script command: result 1 when the bag holds any item listed in a table
 * (the key column holds the item ids). Arguments: table index, result variable. */
int SCRCMD_POKEMON_FLD_CheckTableItemInBag(struct ScriptVm *vm, ScrcmdWork *work)
{
    ScriptWork *scriptWork;
    struct GameData *gameData;
    struct MyItem *bag;
    u32 heapId;
    u32 tableIndex;
    u16 *result;
    u32 *table;
    u32 count;
    u32 i;

    scriptWork = SCRCMD_WORK_GetScriptWork(work);
    gameData = SCRCMD_WORK_GetGameData(work);
    heapId = FIELDMAP_GetHeapId((struct FieldMap *)SCRIPT_WORK_ResetFieldParam(scriptWork)->fieldSystem);
    tableIndex = SCRIPT_WORK_ReadWorkValue(vm, work);
    result = SCRIPT_WORK_ReadWorkPointer(vm, work);
    bag = GAME_DATA_GetMyItem(gameData);
    table = (u32 *)ARC_UTIL_LoadMemberWithSize(SCRCMD_TABLE_ARC_ID, sScrcmdTableFileIds[tableIndex], 0, (u16)((heapId & 0x7fff) | SCRCMD_HEAP_FLAG_TAIL), &count);
    count >>= 3;
    *result = 0;
    for (i = 0; i < count; i++) {
        if (func_02007F68(bag, (u16)table[i * 2], 1, heapId)) {
            *result = 1;
            break;
        }
    }
    func_020307B0(table);
    return 0;
}

/*
 * Script command: looks a key up in a key to value table and registers the
 * value as a number in the word set. Arguments: key, table index, buffer id,
 * digit count.
 * The table byte sScrcmdTableFileIds[tableIndex] is loaded ahead of the `str r0,[sp]`
 * that passes &count: that needs the table declared const, otherwise the load
 * may alias the stack store and is scheduled after it.
 */
int SCRCMD_POKEMON_FLD_RegisterTableValueNumber(struct ScriptVm *vm, ScrcmdWork *work)
{
    ScriptWork *scriptWork;
    u32 heapId;
    u32 key;
    u32 tableIndex;
    u32 bufferId;
    u32 digits;
    struct WordSet *wordSet;
    ScrcmdKeyValueEntry *table;
    u32 count;
    u32 i;

    scriptWork = SCRCMD_WORK_GetScriptWork(work);
    heapId = FIELDMAP_GetHeapId((struct FieldMap *)SCRIPT_WORK_ResetFieldParam(scriptWork)->fieldSystem);
    key = SCRIPT_WORK_ReadWorkValue(vm, work);
    tableIndex = SCRIPT_WORK_ReadWorkValue(vm, work);
    bufferId = SCRIPT_WORK_ReadWorkValue(vm, work);
    digits = SCRIPT_WORK_ReadWorkValue(vm, work);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    table = (ScrcmdKeyValueEntry *)ARC_UTIL_LoadMemberWithSize(SCRCMD_TABLE_ARC_ID, sScrcmdTableFileIds[tableIndex], 0, (u16)((heapId & 0x7fff) | SCRCMD_HEAP_FLAG_TAIL), &count);
    count >>= 3;
    for (i = 0; i < count; i++) {
        if (key == table[i].key) {
            func_0201EFA4(wordSet, bufferId, table[i].value, digits, 0, 1);
            break;
        }
    }
    func_020307B0(table);
    return 0;
}

/*
 * Script command: looks a key up in a key to value table and adds the value to
 * the survey points of the misc save. Arguments: key, table index.
 * Same archive lookup as SCRCMD_POKEMON_FLD_LookupTableValue / SCRCMD_POKEMON_FLD_CheckTableItemInBag; the const table byte
 * is scheduled ahead of the `str r0,[sp]` that passes &count (see SCRCMD_POKEMON_FLD_RegisterTableValueNumber).
 */
int SCRCMD_POKEMON_FLD_AddTableValueToPoints(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData;
    u32 heapId;
    u32 key;
    u32 tableIndex;
    ScrcmdKeyValueEntry *table;
    u32 count;
    u32 i;

    heapId = FIELDMAP_GetHeapId((struct FieldMap *)SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(work))->fieldSystem);
    key = SCRIPT_WORK_ReadWorkValue(vm, work);
    tableIndex = SCRIPT_WORK_ReadWorkValue(vm, work);
    gameData = SCRCMD_WORK_GetGameData(work);
    GAME_DATA_GetMyPlayerWork(gameData);
    table = (ScrcmdKeyValueEntry *)ARC_UTIL_LoadMemberWithSize(SCRCMD_TABLE_ARC_ID, sScrcmdTableFileIds[tableIndex], 0, (u16)((heapId & 0x7fff) | SCRCMD_HEAP_FLAG_TAIL), &count);
    count >>= 3;
    for (i = 0; i < count; i++) {
        if (key == table[i].key) {
            func_0200C278(GAME_DATA_GetMiscSave(gameData), table[i].value);
            break;
        }
    }
    func_020307B0(table);
    return 0;
}



/* Script command: return the gift of the given daily index (0 when out of range). */
int SCRCMD_POKEMON_FLD_GetDailyGift(void *core, void *work)
{
    u32 index;
    u16 *ret;

    index = SCRIPT_WORK_ReadWorkValue(core, work);
    ret = SCRIPT_WORK_ReadWorkPointer(core, work);
    if (index >= 11) {
        index = 0;
    }
    *ret = sDailyGifts[index];
    return 0;
}

/* TRUE when the month and day are one of the five special dates. */
int SCRCMD_POKEMON_FLD_IsSpecialDate(u32 month, int day)
{
    u32 i;
    u16 date;

    date = (month << 8) | day;
    for (i = 0; i < 5; i++) {
        if (date == sDailyGiftSpecialDates[i]) {
            return 1;
        }
    }
    return 0;
}

/*
 * Script command: the daily gift index of today, 10 on a special date.
 * Addresses are Black-image addresses.
 */
int SCRCMD_POKEMON_FLD_GetDailyGiftIndex(void *core, void *work)
{
    u16 *ret;
    struct GameData *gameData;
    u32 month;
    int day;

    ret = SCRIPT_WORK_ReadWorkPointer(core, work);
    gameData = SCRCMD_WORK_GetGameData(work);
    month = FIELD_CLOCK_GetMonth(gameData);
    day = FIELD_CLOCK_GetDay(gameData);
    if (SCRCMD_POKEMON_FLD_IsSpecialDate(month, day) == 1)
        *ret = 10;
    else
        *ret = sDailyGiftIndexByDay[day % 10];
    return 0;
}
