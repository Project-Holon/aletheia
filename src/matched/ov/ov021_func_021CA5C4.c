/*
 * function: BSUBWAY_SCR_CmdTool
 * address:  0x021CA5C4
 * packet:   pkt_ov021_021CA5C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command dispatcher: reads a command id and two arguments from the
 * script, then runs one of 137 cases on the work area, the save blocks
 * 0x39/0x3A/0x3B and the result slot. Returns 1 when the case started a task
 * the script must wait for.  One 4376-byte function (0x021CA5C4..0x021CB6DC,
 * see layout/far_branch_functions.txt); every concrete byte matches.
 *
 * Shape notes (2026-10-01), all measured:
 * - The switch tree only reproduces with one more empty case label inside the
 *   0..113 jump table (any of 9, 10, 46..99, 102; its entry is the break, so
 *   the value is invisible).  Without it the top group becomes one 359..416
 *   table instead of compares for 358/359 and a 400..416 table.
 * - cmd, p1, p2 and s28 are u16 (u16 returns): u32 makes the tree unsigned,
 *   and u32 p1 truncates before each bitfield insert.
 * - Case 334's counter is an enum local: an int counter folds `i + n + 1` and
 *   the loop's entry guard.
 * - Case 351 writes the result in each arm (cross-jumped tail leaves the
 *   `b` to the next instruction); case 404 sets ret after the call (it is
 *   still scheduled into the argument stores); case 45/322 read the table
 *   row through a pointer and pass its three words as separate arguments.
 *
 * Witnesses (closed 2026-10-02, gA2): EVENT_BSUBWAY_COMM_Start (ov007), BSUBWAY_COMM_NetInit
 *   and BSUBWAY_COMM_SetRecvMode (ov010) were seeded in layout/function_starts.txt and
 *   filed EXACT; data_021BB474 (ov214) and data_021BB6A4 (ov100) are
 *   hand-declared proc tables in layout/data_objects.txt, and
 *   attest_xwin_loaded() no longer counts ov021's own start at 0x021BB474
 *   as a third-overlay contest.
 *
 * symbols:
 *   data_021DAD24  0x021DAD24  data
 *   data_021DAD36  0x021DAD36  data
 *   data_021DAD70  0x021DAD70  data
 *   data_021DAD88  0x021DAD88  data
 *   data_021DADAC  0x021DADAC  data
 *   data_021DAE50  0x021DAE50  data
 *   func_020071CC  0x020071CC  thumb
 *   func_02008550  0x02008550  thumb
 *   BATTLE_REC_FreeWork  0x0200B424  thumb
 *   BATTLE_REC_CheckSaved  0x0200B5CC  thumb
 *   BATTLE_REC_IsVersionSupported  0x0200BA38  thumb
 *   BATTLE_REC_LoadToolOverlay  0x0200BA58  thumb
 *   BATTLE_REC_UnloadToolOverlay  0x0200BA68  thumb
 *   BATTLE_BOX_GetFromSave  0x0200BAC8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   BATTLE_BOX_HasMon  0x0200BBA8  thumb
 *   func_0200D85C  0x0200D85C  thumb
 *   func_0200D87C  0x0200D87C  thumb
 *   func_0200D884  0x0200D884  thumb
 *   func_0200D914  0x0200D914  thumb
 *   func_0200D9E8  0x0200D9E8  thumb
 *   func_0200DA14  0x0200DA14  thumb
 *   func_0200DA28  0x0200DA28  thumb
 *   func_0200DA54  0x0200DA54  thumb
 *   func_0200DAC4  0x0200DAC4  thumb
 *   func_0200DB1C  0x0200DB1C  thumb
 *   func_0200DB30  0x0200DB30  thumb
 *   func_0200DB44  0x0200DB44  thumb
 *   func_0200DB80  0x0200DB80  thumb
 *   func_0200DBA0  0x0200DBA0  thumb
 *   BSUBWAY_SAVEDATA_GetTrainersPresent  0x0200DE5C  thumb
 *   BSUBWAY_SAVEDATA_GetHistoryPresent  0x0200DE64  thumb
 *   BSUBWAY_SAVEDATA_GetTrainersTagA  0x0200DE94  thumb
 *   BSUBWAY_SAVEDATA_GetHistoryTagA  0x0200DF40  thumb
 *   BSUBWAY_SAVEDATA_GetHistoryTagB  0x0200DF4C  thumb
 *   BSUBWAY_SAVEDATA_AllocHistoryCopy  0x0200DF58  thumb
 *   BSUBWAY_SAVEDATA_CountHistoryEntries  0x0200DF94  thumb
 *   MISC_SAVEDATA_GetBlock44  0x0200ED48  thumb
 *   MISC_SAVEDATA_InsertRecentValue  0x0200ED54  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   GFL_NET_ERR_RequestScreen  0x0200FB38  thumb
 *   func_02011330  0x02011330  thumb
 *   VM_SetWait  0x020113D0  thumb
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   ICA_ANIME_GetField20  0x0201210C  thumb
 *   ICA_ANIME_SetField30  0x02012124  thumb
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   GAME_DATA_GetField114  0x020127A4  thumb
 *   GAME_DATA_SetField168  0x0201289C  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   func_02012944  0x02012944  thumb
 *   ov007_id       0x00000007  data  a1
 *   ov100_id       0x00000064  data  a1
 *   ov214_id       0x000000D6  data  a1
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAME_DATA_GetCurrentEvent  0x02012ED8  thumb
 *   BTL_SETUP_Delete  0x020130B4  thumb
 *   ZONEDATA_SetDirectLocation  0x02014184  thumb
 *   ZONEDATA_SetEventFlag  0x02014314  thumb
 *   ZONEDATA_ResetEventFlag  0x0201433C  thumb
 *   FIELD_STATUS_CreateSubProcCallbackEvent  0x02014808  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02019ED4  0x02019ED4  thumb
 *   POKE_REGULATION_Load  0x0201A354  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   ISS_SYS_GetSwitchSys  0x0202B578  thumb
 *   ISS_SWITCH_SYS_SwitchOn  0x0202C0D0  thumb
 *   func_020307B0  0x020307B0  arm
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   OS_ResetSystem  0x02087BCC  arm
 *   EVENT_BSUBWAY_COMM_Start  0x021542C0  thumb  ov007
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_GetWorkPtr  0x02158FE0  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   BSUBWAY_COMM_NetInit  0x02167AB0  thumb  ov010
 *   BSUBWAY_COMM_AddCommandTable  0x02167B00  thumb  ov010
 *   BSUBWAY_COMM_StartTimingSync  0x02167B24  thumb  ov010
 *   BSUBWAY_COMM_SetSendData  0x02167BFC  thumb  ov010
 *   BSUBWAY_COMM_SetRecvMode  0x02167CF4  thumb  ov010
 *   NAMEIN_SETUP_StartPartyPickEvent  0x0216C538  thumb  ov010
 *   NAMEIN_SETUP_StartEncounterScene  0x0216C640  thumb  ov010
 *   NAMEIN_SETUP_StartNameBalloonFromRecord  0x0216C6E8  thumb  ov010
 *   NAMEIN_SETUP_StartHistoryScreenEvent  0x0216C860  thumb  ov010
 *   NAMEIN_SETUP_StartNameBalloonFromHistory  0x0216CB48  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_GetParam  0x0216D63C  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   FLDMMDL_OnMoveBitMovePause  0x0216DAF8  thumb  ov010
 *   FLDMMDL_SetStatusBitHeightGetOff  0x0216DB4C  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_InitPosition  0x0216E014  thumb  ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   FIELD_PLAYER_GetSex  0x021A30B0  thumb  ov021
 *   FIELD_PLAYER_GetFormObjCode  0x021A3190  thumb  ov021
 *   FIELD_PLAYER_GetObjCodeOfFormCode  0x021A31A4  thumb  ov021
 *   data_021BB474  0x021BB474  data  ov214
 *   data_021BB6A4  0x021BB6A4  data  ov100
 *   BSUBWAY_SCR_ChangeCommMultiMode  0x021C9B78  thumb  ov021
 *   BSUBWAY_SCR_SaveRestPlayData  0x021C9BCC  thumb  ov021
 *   BSUBWAY_SCR_LoadMembers  0x021C9C54  thumb  ov021
 *   BSUBWAY_SCR_SavePlayDataMembers  0x021C9CAC  thumb  ov021
 *   BSUBWAY_SCR_ResetPlayMode  0x021C9D30  thumb  ov021
 *   BSUBWAY_SCR_SetLoseScore  0x021C9D70  thumb  ov021
 *   BSUBWAY_SCR_AddBattlePoint  0x021C9DB0  thumb  ov021
 *   BSUBWAY_SCR_DrawTrainerNos  0x021C9E8C  thumb  ov021
 *   BSUBWAY_SCR_SetSelectedMembers  0x021C9F44  thumb  ov021
 *   BSUBWAY_SCR_IsWinMax  0x021C9FD0  thumb  ov021
 *   BSUBWAY_SCR_SetClearScore  0x021C9FFC  thumb  ov021
 *   BSUBWAY_SCR_ClearStateBits  0x021CA048  thumb  ov021
 *   BSUBWAY_SCR_CreateRoundTrainers  0x021CA05C  thumb  ov021
 *   BSUBWAY_SCR_GetTrainerObjCode  0x021CA150  thumb  ov021
 *   BSUBWAY_SCR_UpdateStageRank  0x021CA164  thumb  ov021
 *   BSUBWAY_SCR_LoadPartyCopy  0x021CA1E4  thumb  ov021
 *   BSUBWAY_SCR_GetWinCount  0x021CA234  thumb  ov021
 *   BSUBWAY_SCR_IncWinCount  0x021CA23C  thumb  ov021
 *   BSUBWAY_SCR_ClearWinCount  0x021CA250  thumb  ov021
 *   BSUBWAY_SCR_GetMemberNum  0x021CA270  thumb  ov021
 *   BSUBWAY_SCR_CreatePartners  0x021CA338  thumb  ov021
 *   func_021CB6DC  0x021CB6DC  thumb  ov021
 *   func_021CB700  0x021CB700  thumb  ov021
 *   func_021CB754  0x021CB754  thumb  ov021
 *   func_021CB7E8  0x021CB7E8  thumb  ov021
 *   func_021CB86C  0x021CB86C  thumb  ov021
 *   func_021CB914  0x021CB914  thumb  ov021
 *   func_021CB9BC  0x021CB9BC  thumb  ov021
 *   func_021CB9E4  0x021CB9E4  thumb  ov021
 *   func_021CBBA0  0x021CBBA0  thumb  ov021
 *   func_021CBBAC  0x021CBBAC  thumb  ov021
 *   func_021CBBD0  0x021CBBD0  thumb  ov021
 *   func_021CBC14  0x021CBC14  thumb  ov021
 *   BSUBWAY_SCR_GetRegulationNo  0x021CBC94  thumb  ov021
 *   BSUBWAY_SCR_GetTrainNo  0x021CBCC4  thumb  ov021
 *   COMM_ENTRY_MENU_Create  0x021CD48C  thumb  ov021
 *   FLDEFF_BTRAIN_SetAnime  0x021D024C  thumb  ov021
 *   FLDEFF_BTRAIN_SetHidden  0x021D028C  thumb  ov021
 *   BATTLE_REC_TOOL_PackSetup  0x021EEE78  thumb  ov188
 *   FIELD_GIMMICK_BSUBWAY_StartTrain  0x021F37C0  thumb  ov052
 *   FIELD_GIMMICK_BSUBWAY_GetTrainEffect  0x021F380C  thumb  ov052
 *   FIELD_GIMMICK_BSUBWAY_HaltTrainSway  0x021F388C  thumb  ov052
 */
#include "../include/Obj00335.h"
#include "../include/Obj02400.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

#define NULL ((void *)0)

typedef struct {
    u16 b0  : 1;
    u16 f1  : 2;
    u16 f3  : 2;
    u16 f5  : 3;
    u16 b8  : 1;
    u16 b9  : 1;
    u16 f10 : 2;
    u16 b12 : 1;
    u16 f13 : 3;
} Flags;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} Trip;

typedef struct {
    u32 w[7];
} Rec1C;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Vec;

typedef struct {
    u32 val;
    u16 *dst;
} Wait;

typedef enum {
    SLOT_0
} Slot;

#define FLAGS(w) ((Flags *)((w) + 0xc))

typedef signed int     s32;
struct Big;
struct BigObj;
struct Blk1AC;
struct Blk3C;
struct Buf3FC;
struct Ctx;
struct L0200ED54;
struct Pair;
struct RecSlot;
struct SaveBlock;
struct Sub0200852CObj;
extern u8 *func_02012944(void *p);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern void *SCRIPT_WORK_GetGameSystem(void *p);
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern void *GAME_DATA_GetCurrentEvent(struct Big *p);
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern u32 func_0200D884(struct Blk3C *p, u32 id, void *out);
struct Ctx;
extern void *ICA_ANIME_GetField20(const struct Ctx *p);
struct Desc;
struct Obj;
struct Rec1C;
struct Stream;
extern u16 func_02011330(struct Stream *s);
extern u16 SCRIPT_WORK_ReadWorkValue(void *a, u32 b);
extern u16 *SCRIPT_WORK_GetWorkPtr(void *a, void *b, unsigned int id);
extern void SCRIPT_SYS_CallEvent(void *h, void *task);

extern int BSUBWAY_SCR_GetTrainNo(void *a);
extern void OS_ResetSystem(u32 a);
extern void func_0200D85C(struct Blk3C *p);
extern u32 func_0200D87C(struct Blk3C *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *a, struct VecFx32 *t);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void ZONEDATA_SetDirectLocation(Rec1C *out, u32 id, s16 n, u32 a, u32 b, u32 c);
extern void GAME_DATA_SetField168(struct BigObj *p, const struct Rec1C *src);
extern void ZONEDATA_SetEventFlag(char *a0, int a1);
extern void ZONEDATA_ResetEventFlag(char *a0, int a1);
extern u16 func_0200DAC4(struct Blk1AC *p, u32 i);
extern u32 BSUBWAY_SCR_ResetPlayMode(const struct Ctx *a0);
extern u32 FIELD_PLAYER_GetSex(u8 *p);
extern u16 FIELD_PLAYER_GetFormObjCode(int i, int j);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern void *FLDMMDL_SysSearchObjId(void *a, u32 id);
extern void FLDMMDL_SetStatusBitVanish(unsigned int *p, unsigned int v);
extern u16 func_0200DA54(struct Blk3C *p);
extern u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op);
extern void FIELD_GIMMICK_BSUBWAY_StartTrain(void *a, int b, int c);
extern int FIELD_GIMMICK_BSUBWAY_GetTrainEffect(int a);
extern void FLDEFF_BTRAIN_SetAnime(void *o, u32 v);
extern void FLDEFF_BTRAIN_SetHidden(void *o, u32 v);
struct Actor;
extern void FLDMMDL_GetPos(const struct Actor *o, struct VecFx32 *v);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void FLDMMDL_InitPosition(void *a, int *p, int b);
extern int FLDMMDL_SetStatusBitHeightGetOff(void *a0, int a1);
extern u32 func_021CBBA0(u32 a);
extern int BSUBWAY_SCR_UpdateStageRank(void *a, int unused, int mode);
extern u16 func_0200DB80(struct Blk1AC *p, u32 i);
extern void *GAME_DATA_GetField114(struct SaveBlock *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern int FIELD_PLAYER_GetObjCodeOfFormCode(int i, int v);
extern void *BATTLE_BOX_GetFromSave(void *p);
extern u32 BATTLE_BOX_HasMon(void *a);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
extern void FLDMMDL_OnMoveBitMovePause(void *o);
extern int FLDMMDL_GetParam(char *a0, int a1);
extern void *NAMEIN_SETUP_StartNameBalloonFromHistory(u32 x, u32 v, u32 id);
extern u32 func_0200DB44(struct Blk1AC *p, u32 i);
extern u32 func_021CBBAC(u8 *w, u32 v);
extern void func_021CBBD0(u8 *w, u32 v, u16 *a, u16 *b, u16 *c);
extern struct Buf3FC *BSUBWAY_SAVEDATA_AllocHistoryCopy(struct RecSlot *p, u32 heap);
extern u32 BSUBWAY_SAVEDATA_CountHistoryEntries(struct Buf3FC *b);
extern u32 func_020307B0(void *p);
extern void *func_021CB9BC(void *a, u32 owner, u32 result, u32 arg);
extern struct Desc *GAME_EVENT_CreateOverlayEvent(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern int EVENT_BSUBWAY_COMM_Start(int x, struct Pair *p);
extern u8 BSUBWAY_SAVEDATA_GetTrainersTagA(struct RecSlot *p);
extern u8 BSUBWAY_SAVEDATA_GetTrainersPresent(struct RecSlot *p);
extern void func_0200D914(struct Blk3C *p, u32 id, const void *src);
extern u8 BSUBWAY_SAVEDATA_GetHistoryPresent(struct RecSlot *p);
extern void *NAMEIN_SETUP_StartHistoryScreenEvent(void *a);
extern int BSUBWAY_SAVEDATA_GetHistoryTagA(struct RecSlot *p);
extern u8 BSUBWAY_SAVEDATA_GetHistoryTagB(struct RecSlot *p);
struct PartyCaller;
extern void *NAMEIN_SETUP_StartPartyPickEvent(struct PartyCaller *c, void *sys, u8 useOwn);
extern u32 BSUBWAY_SCR_SetSelectedMembers(u8 *w, u32 x);
extern int BSUBWAY_SCR_IsWinMax(u8 *w);
extern void BSUBWAY_SCR_SetLoseScore(u32 x, u8 *w);
extern void BSUBWAY_SCR_SetClearScore(u8 *w, u32 x);
extern void BSUBWAY_SCR_SaveRestPlayData(u8 *w);
extern void BSUBWAY_SCR_CreateRoundTrainers(u8 *w);
extern u32 BSUBWAY_SCR_GetTrainerObjCode(u8 *p, int i);
extern void *NAMEIN_SETUP_StartEncounterScene(u8 *w, u32 x, void *s);
extern u32 BSUBWAY_SCR_AddBattlePoint(u8 *w);
extern void BSUBWAY_SCR_DrawTrainerNos(u8 *w);
extern void MI_CpuFill8(void *p, int v, int n);
extern void *NAMEIN_SETUP_StartNameBalloonFromRecord(u8 *d, void *sys, u32 idx, u16 id, u8 dir);
extern void BSUBWAY_SCR_SavePlayDataMembers(u8 *w);
extern void BSUBWAY_SCR_LoadMembers(u8 *w, u32 x);
extern void BSUBWAY_SCR_ChangeCommMultiMode(u8 *w);
extern void func_021CB9E4(u8 *p, void *a1, void *a2, void *a3);
extern int BSUBWAY_SCR_ClearStateBits(u32 a, u32 b);
extern u32 GAMESYSTEM_GetIssSystem(u32 *p);
extern u32 ISS_SYS_GetSwitchSys(u32 *p);
extern void ISS_SWITCH_SYS_SwitchOn(u8 *p, u32 a);
extern void BSUBWAY_SCR_CreatePartners(u8 *w, u8 alt);
extern int BSUBWAY_SCR_GetRegulationNo(u32 kind);
extern void *POKE_REGULATION_Load(int a, int b);
extern void *func_0200BAF4(int a0, int a1);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern int func_02019ED4(void *ctx, void *q);
extern void BSUBWAY_SCR_LoadPartyCopy(u8 *w);
extern int BSUBWAY_SCR_GetMemberNum(u16 kind);
extern u32 BATTLE_REC_CheckSaved(void *a, u32 heap, u32 *dp, u32 id);
extern void BATTLE_REC_LoadToolOverlay(void);
extern void BATTLE_REC_TOOL_PackSetup(void *p);
extern void BATTLE_REC_UnloadToolOverlay(void);
extern void VM_SetWait(char *p, int val);
extern void BATTLE_REC_FreeWork(void);
extern int BTL_SETUP_Delete(int a0);
extern u16 BSUBWAY_SCR_GetWinCount(u8 *w);
extern void *FIELD_STATUS_CreateSubProcCallbackEvent(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void func_0200DA14(struct Blk3C *p);
extern void func_0200DB1C(struct Blk1AC *p, u32 i);
extern void FIELD_GIMMICK_BSUBWAY_HaltTrainSway(int a);
extern u32 POKEPARTY_GetCount(void *party);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void func_0200D9E8(struct Blk3C *p, s32 a, s32 b, s32 c);
extern void func_0200DA28(struct Blk3C *p);
extern void BSUBWAY_SCR_IncWinCount(u8 *w);
extern void func_0200DB30(struct Blk1AC *p, u32 i);
extern int BSUBWAY_SCR_ClearWinCount(u32 a);
extern void BSUBWAY_COMM_AddCommandTable(u32 a);
extern void BSUBWAY_COMM_NetInit(void *p);
extern void *func_021CB914(void *a, u32 owner);
extern int BSUBWAY_COMM_StartTimingSync(int a0);
extern u32 COMM_ENTRY_MENU_Create(u32 a, void *b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void BSUBWAY_COMM_SetSendData(struct Obj *o, u32 cmd, u32 arg);
extern void BSUBWAY_COMM_SetRecvMode(u8 *w, u8 v);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void MISC_SAVEDATA_InsertRecentValue(struct L0200ED54 *l, u32 val);
extern void *MISC_SAVEDATA_GetBlock44(void *p);
extern void GFL_NET_ERR_RequestScreen(void);
extern void ICA_ANIME_SetField30(struct Ctx *p, u32 v);
extern u32 func_0200FB24(void);
extern u32 BATTLE_REC_IsVersionSupported(u32 v);

extern int func_021CB700(u32 unused, u32 a);
extern int func_021CB754(u32 unused, u32 a);
extern int func_021CB7E8(u32 unused, u32 a);
extern int func_021CB6DC(void *task, void *p);
extern int func_021CB86C(u32 unused, u32 a);
extern int func_021CBC14(u32 unused, u32 a);
extern u8 data_021BB474[];
extern u8 data_021BB6A4[];
extern char ov007_id[];
extern char ov100_id[];
extern char ov214_id[];

extern const u16 data_021DAD36[];
extern const u32 data_021DAD88[];
extern const Trip data_021DAD70[];
extern const Trip data_021DAE50[];
extern const u32 data_021DADAC[];
extern const u16 data_021DAD24[];

int BSUBWAY_SCR_CmdTool(void *a, u32 b)
{
    Trip t;
    Rec1C r4;
    Vec v;
    Rec1C r45;
    Rec1C r322;
    Wait st;
    u32 out;
    u16 a40, b40, c40;
    u16 a41, b41, c41;
    u16 a42, b42, c42;
    u8 t108;
    u8 t324;
    int ret;
    void *h;
    u32 x;
    u32 s4c;
    u32 s48;
    u32 s44;
    u8 *w;
    u32 s40;
    u32 s3c;
    u32 s38;
    u32 s34;
    void *s30;
    u16 p1;
    u16 p2;
    u16 s28;
    u16 *dst;
    u16 cmd;

    ret = 0;
    h = SCRCMD_WORK_GetScriptWork((void *)b);
    SCRIPT_WORK_ResetFieldParam((int)h);
    x = (u32)SCRIPT_WORK_GetGameSystem(h);
    s4c = (u32)ICA_ANIME_GetField1C((const struct Ctx *)x);
    s48 = (u32)GAME_DATA_GetSaveControl((struct Big *)s4c);
    s44 = GAME_DATA_GetEventWork((const struct BigObj *)s4c);
    w = GAME_DATA_GetCurrentEvent((struct Big *)s4c);
    s40 = (u32)func_020071CC((struct Sub020071CCCtrl *)s48, 0x39);
    s3c = func_0200D884((struct Blk3C *)s40, 0, 0);
    s38 = (u32)func_020071CC((struct Sub020071CCCtrl *)s48, 0x3a);
    s34 = (u32)func_020071CC((struct Sub020071CCCtrl *)s48, 0x3b);
    s30 = ICA_ANIME_GetField20((void *)x);
    cmd = func_02011330(a);
    p1 = SCRIPT_WORK_ReadWorkValue(a, b);
    p2 = SCRIPT_WORK_ReadWorkValue(a, b);
    s28 = func_02011330(a);
    dst = SCRIPT_WORK_GetWorkPtr(h, (void *)s4c, s28);

    if (w == NULL && cmd >= 300)
        return ret;

    switch (cmd) {
    case 0:
        *dst = BSUBWAY_SCR_GetTrainNo(s30);
        break;
    case 1:
        OS_ResetSystem(0);
        break;
    case 2:
        func_0200D85C((struct Blk3C *)s40);
        break;
    case 3:
        *dst = func_0200D87C((struct Blk3C *)s40);
        break;
    case 4: {
        void *o = FIELDMAP_GetFieldPlayer((void *)s30);
        u32 k = FIELD_PLAYER_GetDirDisp(o);
        int n;
        FIELD_PLAYER_GetPos(o, (struct VecFx32 *)&t);
        switch (k) {
        case 0:
            n = 1;
            break;
        case 1:
            n = 2;
            break;
        case 2:
            n = 3;
            break;
        case 3:
            n = 4;
            break;
        default:
            n = 0;
            break;
        }
        ZONEDATA_SetDirectLocation(&r4, FIELDMAP_GetZoneId(s30), n, t.a, t.b, t.c);
        GAME_DATA_SetField168((struct BigObj *)s4c, (const struct Rec1C *)(&r4));
        ZONEDATA_SetEventFlag((char *)s44, 0x966);
        break;
    }
    case 5:
        ZONEDATA_ResetEventFlag((char *)s44, 0x966);
        break;
    case 6:
        *dst = func_0200DAC4((struct Blk1AC *)s38, p1);
        if (*dst > 9999)
            *dst = 9999;
        break;
    case 7:
        *dst = BSUBWAY_SCR_ResetPlayMode((const struct Ctx *)x);
        break;
    case 12:
        *dst = FIELD_PLAYER_GetFormObjCode(FIELD_PLAYER_GetSex(FIELDMAP_GetFieldPlayer((void *)s30)), 0);
        break;
    case 13: {
        void *o = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)s30), p1);
        if (o != 0)
            FLDMMDL_SetStatusBitVanish(o, p2);
        break;
    }
    case 8:
        *dst = func_0200DA54((struct Blk3C *)s40) + 1;
        break;
    case 11:
        *dst = func_0200DA54((struct Blk3C *)(((struct Obj00335 *)w)->f70));
        *dst += 1;
        break;
    case 14:
        if (data_021DAD36[p1] == 11)
            *dst = 1;
        else
            *dst = func_0200DBA0((struct Blk1AC *)s38, data_021DAD36[p1], 0);
        break;
    case 15:
        if (data_021DAD36[p1] != 11)
            func_0200DBA0((struct Blk1AC *)s38, data_021DAD36[p1], 1);
        break;
    case 16:
        *dst = func_0200DBA0((struct Blk1AC *)s38, 10, 0);
        break;
    case 17:
        func_0200DBA0((struct Blk1AC *)s38, 10, 1);
        break;
    case 18:
        FIELD_GIMMICK_BSUBWAY_StartTrain(s30, data_021DAD88[p1], (int)(&data_021DAD70[p2]));
        break;
    case 19:
        FLDEFF_BTRAIN_SetAnime((void *)FIELD_GIMMICK_BSUBWAY_GetTrainEffect((int)s30), p1);
        break;
    case 20:
        FLDEFF_BTRAIN_SetHidden((void *)FIELD_GIMMICK_BSUBWAY_GetTrainEffect((int)s30), p1);
        break;
    case 21:
        *dst = func_0200D884((struct Blk3C *)s40, 0, 0);
        break;
    case 22:
        *dst = 0;
        switch (p1) {
        case 0:
        case 1:
        case 4:
        case 5:
        case 6:
            break;
        case 2:
        case 3:
        case 7:
        case 8:
            *dst = 1;
            break;
        }
        break;
    case 23: {
        u32 y = p2 << 16;
        void *o = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)s30), p1);
        if (o != 0) {
            FLDMMDL_GetPos(o, (struct VecFx32 *)&v);
            v.y = y;
            FLDMMDL_InitPosition(o, (int *)(&v), FLDMMDL_GetDirDisp(o));
            FLDMMDL_SetStatusBitHeightGetOff(o, 1);
        }
        break;
    }
    case 24: {
        void *o = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)s30), p1);
        if (o != 0)
            FLDMMDL_SetStatusBitHeightGetOff(o, 0);
        break;
    }
    case 25: {
        void *o = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)s30), p1);
        *dst = 0;
        if (o != 0)
            *dst = 1;
        break;
    }
    case 26: {
        void *o = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)s30), p1);
        *dst = 0;
        if (o != 0)
            *dst = func_021CBBA0((u32)o);
        break;
    }
    case 27:
        *dst = BSUBWAY_SCR_UpdateStageRank((void *)s38, x, 0);
        if ((s16)*dst <= 0)
            *dst = 1;
        break;
    case 28:
        *dst = BSUBWAY_SCR_UpdateStageRank((void *)s38, x, 3);
        break;
    case 29:
        *dst = BSUBWAY_SCR_UpdateStageRank((void *)s38, x, 4);
        break;
    case 30:
        *dst = func_0200DB80((struct Blk1AC *)s38, p1);
        break;
    case 31:
        *dst = FIELD_PLAYER_GetObjCodeOfFormCode(func_02008550((const struct Sub0200852CObj *)((u8 *)GAME_DATA_GetField114((struct SaveBlock *)s4c) + 0x20)) == 0 ? 1 : 0, 0);
        break;
    case 32: {
        u32 o = (u32)BATTLE_BOX_GetFromSave((void *)s48);
        *dst = 0;
        if (BATTLE_BOX_HasMon((void *)o) == 1)
            *dst = 1;
        break;
    }
    case 33:
        *dst = 0;
        break;
    case 34:
        FIELD_GIMMICK_BSUBWAY_StartTrain(s30, 7, (int)data_021DAD70);
        break;
    case 35: {
        void *o = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)s30), p1);
        if (o != 0)
            FLDMMDL_SetDirDispCheckPause((int)o, p2);
        break;
    }
    case 36: {
        void *o = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)s30), p1);
        if (o != 0)
            FLDMMDL_OnMoveBitMovePause(o);
        break;
    }
    case 37:
        SCRIPT_SYS_CallEvent(h, NAMEIN_SETUP_StartNameBalloonFromHistory(x, FLDMMDL_GetParam(FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)s30), p1), 0), p1));
        ret = 1;
        break;
    case 38:
        *dst = func_0200DB44((struct Blk1AC *)s38, p1);
        break;
    case 39: {
        u32 o = FLDMMDL_GetParam(FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)s30), p1), 0);
        *dst = 0;
        if (func_021CBBAC(w, o) == 1)
            *dst = 1;
        break;
    }
    case 40:
        func_021CBBD0(w, FLDMMDL_GetParam(FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)s30), p1), 0), &a40, &b40, &c40);
        *dst = a40;
        break;
    case 41:
        func_021CBBD0(w, FLDMMDL_GetParam(FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)s30), p1), 0), &a41, &b41, &c41);
        *dst = b41;
        break;
    case 42:
        func_021CBBD0(w, FLDMMDL_GetParam(FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)s30), p1), 0), &a42, &b42, &c42);
        *dst = c42;
        break;
    case 43: {
        void *l = BSUBWAY_SAVEDATA_AllocHistoryCopy((struct RecSlot *)s34, 4);
        *dst = BSUBWAY_SAVEDATA_CountHistoryEntries(l);
        func_020307B0(l);
        break;
    }
    case 44: {
        u32 f = 0;
        if (p1 == 1)
            f = 1;
        SCRIPT_SYS_CallEvent(h, func_021CB9BC((void *)x, b, (u32)dst, f));
        ret = 1;
        break;
    }
    case 45: {
        u16 i = BSUBWAY_SCR_GetTrainNo(s30);
        const Trip *e = &data_021DAE50[i];
        ZONEDATA_SetDirectLocation(&r45, data_021DADAC[i], 4, e->a, e->b, e->c);
        GAME_DATA_SetField168((struct BigObj *)s4c, (const struct Rec1C *)(&r45));
        ZONEDATA_SetEventFlag((char *)s44, 0x966);
        break;
    }
    case 100:
        if (p1 == 0)
            func_0200DBA0((struct Blk1AC *)s38, 1, 2);
        else
            func_0200DBA0((struct Blk1AC *)s38, 1, 1);
        break;
    case 101:
        *dst = func_0200DBA0((struct Blk1AC *)s38, 1, 0);
        break;
    case 103:
        st.val = 0;
        st.dst = dst;
        SCRIPT_SYS_CallEvent(h, GAME_EVENT_CreateOverlayEvent((void *)x, (u32)ov007_id, (u32 (*)(void *, u32))EVENT_BSUBWAY_COMM_Start, (u32)(&st)));
        ret = 1;
        break;
    case 104:
        ret = 1;
        st.val = 1;
        st.dst = dst;
        SCRIPT_SYS_CallEvent(h, GAME_EVENT_CreateOverlayEvent((void *)x, (u32)ov007_id, (u32 (*)(void *, u32))EVENT_BSUBWAY_COMM_Start, (u32)(&st)));
        break;
    case 105:
        st.val = 2;
        st.dst = dst;
        SCRIPT_SYS_CallEvent(h, GAME_EVENT_CreateOverlayEvent((void *)x, (u32)ov007_id, (u32 (*)(void *, u32))EVENT_BSUBWAY_COMM_Start, (u32)(&st)));
        ret = 1;
        break;
    case 106:
        *dst = BSUBWAY_SAVEDATA_GetTrainersTagA((struct RecSlot *)s34);
        break;
    case 107:
        *dst = BSUBWAY_SAVEDATA_GetTrainersPresent((struct RecSlot *)s34);
        break;
    case 108:
        t108 = p1;
        func_0200D914((struct Blk3C *)s40, 11, &t108);
        break;
    case 109:
        *dst = func_0200D884((struct Blk3C *)s40, 11, 0);
        break;
    case 110:
        *dst = BSUBWAY_SAVEDATA_GetHistoryPresent((struct RecSlot *)s34);
        break;
    case 111:
        SCRIPT_SYS_CallEvent(h, NAMEIN_SETUP_StartHistoryScreenEvent((void *)x));
        ret = 1;
        break;
    case 112:
        *dst = BSUBWAY_SAVEDATA_GetHistoryTagA((struct RecSlot *)s34);
        break;
    case 113:
        *dst = BSUBWAY_SAVEDATA_GetHistoryTagB((struct RecSlot *)s34);
        break;
    case 200:
        *dst = 0;
        break;
    case 102:
    case 201:
    case 202:
        break;
    case 203:
        *dst = 0;
        break;
    case 322:
        if (s3c < 9) {
            const Trip *e = &data_021DAE50[s3c];
            ZONEDATA_SetDirectLocation(&r322, data_021DADAC[s3c], 4, e->a, e->b, e->c);
            GAME_DATA_SetField168((struct BigObj *)s4c, (const struct Rec1C *)(&r322));
            ZONEDATA_SetEventFlag((char *)s44, 0x966);
        }
        break;
    case 300:
        {
            u8 v = func_0200D884((struct Blk3C *)s40, 10, 0);
            SCRIPT_SYS_CallEvent(h, NAMEIN_SETUP_StartPartyPickEvent((struct PartyCaller *)w, (void *)x, v));
        }
        ret = 1;
        break;
    case 301:
        *dst = BSUBWAY_SCR_SetSelectedMembers(w, x);
        break;
    case 302:
        *dst = 0;
        break;
    case 303:
        if (BSUBWAY_SCR_IsWinMax(w) == 1)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 304:
        BSUBWAY_SCR_SetLoseScore(x, w);
        break;
    case 305:
        BSUBWAY_SCR_SetClearScore(w, x);
        break;
    case 306:
        BSUBWAY_SCR_SaveRestPlayData(w);
        break;
    case 307:
        BSUBWAY_SCR_CreateRoundTrainers(w);
        break;
    case 308:
        *dst = BSUBWAY_SCR_GetTrainerObjCode(w, p1);
        break;
    case 309:
        SCRIPT_SYS_CallEvent(h, NAMEIN_SETUP_StartEncounterScene(w, x, s30));
        ret = 1;
        break;
    case 310:
        *dst = w[9];
        break;
    case 311:
        FLAGS(w)->f1 = p1;
        break;
    case 312:
        *dst = FLAGS(w)->f1;
        break;
    case 313:
        *dst = BSUBWAY_SCR_AddBattlePoint(w);
        break;
    case 314:
        FLAGS(w)->f5 = p1;
        break;
    case 315:
        *dst = FLAGS(w)->f5;
        break;
    case 316:
        BSUBWAY_SCR_DrawTrainerNos(w);
        break;
    case 317:
        *dst = *(w + p1 + 0x1e);
        break;
    case 319:
        w[0x724] = 0;
        MI_CpuFill8(w + 0x6ae, 0, 0x46);
        break;
    case 320:
        SCRIPT_SYS_CallEvent(h, NAMEIN_SETUP_StartNameBalloonFromRecord(w, (void *)x, p1, p2, 5));
        ret = 1;
        break;
    case 321:
        BSUBWAY_SCR_SavePlayDataMembers(w);
        break;
    case 323:
        BSUBWAY_SCR_LoadMembers(w, x);
        break;
    case 324:
        t324 = p1;
        func_0200D914((struct Blk3C *)s40, 10, &t324);
        break;
    case 325:
        BSUBWAY_SCR_ChangeCommMultiMode(w);
        break;
    case 326:
        if (s3c - 5 <= 3)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 329:
        func_021CB9E4(w, (void *)s4c, FIELDMAP_GetMmdlSys((void *)s30), s30);
        break;
    case 330:
        FLAGS(w)->b8 = p1;
        break;
    case 331:
        *dst = FLAGS(w)->b8;
        break;
    case 332: {
        u8 *e = *(u8 * *)&((struct Obj00335 *)w)->f7CC;
        if (e == NULL)
            *dst = 0;
        else if (((struct Obj02400 *)e)->f8C == 1)
            *dst = 1;
        else
            *dst = 0;
        break;
    }
    case 333:
        BSUBWAY_SCR_ClearStateBits((u32)w, x);
        break;
    case 334: {
        Slot i = 0;
        u16 n = func_0200DA54((struct Blk3C *)s40);
        if (n != 0) {
            void *p = (void *)ISS_SYS_GetSwitchSys((u32 *)GAMESYSTEM_GetIssSystem((u32 *)x));
            n = i + n + 1;
            for (; i < n; i++) {
                if (i < 9 && i != 0)
                    ISS_SWITCH_SYS_SwitchOn(p, i);
            }
        }
        break;
    }
    case 335:
        BSUBWAY_SCR_CreatePartners(w, func_02008550((const struct Sub0200852CObj *)((u8 *)GAME_DATA_GetField114((struct SaveBlock *)s4c) + 0x20)) == 0 ? 1 : 0);
        break;
    case 336:
        *dst = *(u16 *)(w + p1 * 2 + 0x22);
        break;
    case 337:
        FLAGS(w)->b9 = p1;
        break;
    case 338:
        *dst = FLAGS(w)->b9;
        break;
    case 339: {
        void *p4 = NULL;
        u32 mode;
        void *rules;
        void *party;
        u32 res;
        *dst = 0;
        mode = func_0200D884((struct Blk3C *)s40, 10, 0);
        rules = POKE_REGULATION_Load(BSUBWAY_SCR_GetRegulationNo(s3c), 4);
        if (mode == 1) {
            p4 = func_0200BAF4((u32)BATTLE_BOX_GetFromSave((void *)s48), 4);
            party = p4;
        } else {
            party = GAME_DATA_GetMyParty((void *)s4c);
        }
        res = func_02019ED4(rules, party);
        func_020307B0(rules);
        if (p4 != NULL)
            func_020307B0(p4);
        if (res <= 1)
            *dst = 1;
        break;
    }
    case 340:
        BSUBWAY_SCR_LoadPartyCopy(w);
        break;
    case 341:
        *dst = BSUBWAY_SCR_GetRegulationNo(s3c);
        break;
    case 342:
        *dst = BSUBWAY_SCR_GetMemberNum(s3c);
        break;
    case 343:
        if (FLAGS(w)->f10 == 0) {
            FLAGS(w)->f10 = 1;
            if (BATTLE_REC_CheckSaved((void *)s48, 4, &out, 0) == 1)
                FLAGS(w)->f10 = 2;
        }
        break;
    case 344:
        if (FLAGS(w)->f10 == 1)
            *dst = 0;
        else
            *dst = 1;
        break;
    case 345:
        BATTLE_REC_LoadToolOverlay();
        BATTLE_REC_TOOL_PackSetup((void *)(*(u32 *)&((struct Obj00335 *)w)->f7CC));
        BATTLE_REC_UnloadToolOverlay();
        break;
    case 346:
        ((struct Obj00335 *)w)->f7E8 = 0;
        ((struct Obj00335 *)w)->f7EA = 0;
        ((struct Obj00335 *)w)->f10 = p1;
        VM_SetWait(a, (int)func_021CBC14);
        FLAGS(w)->f10 = 2;
        ret = 1;
        break;
    case 347:
        if (*(u32 *)&((struct Obj00335 *)w)->f7CC != 0) {
            BATTLE_REC_FreeWork();
            BTL_SETUP_Delete(*(u32 *)&((struct Obj00335 *)w)->f7CC);
            *(u32 *)&((struct Obj00335 *)w)->f7CC = 0;
        }
        break;
    case 348:
        MI_CpuFill8(w + 0x7d0, 0, 0x18);
        ((struct Obj00335 *)w)->f7D0 = s4c;
        ((struct Obj00335 *)w)->f7D4 = 1;
        ((struct Obj00335 *)w)->f7D8 = 0;
        ((struct Obj00335 *)w)->f7DC = 1;
        ((struct Obj00335 *)w)->f7E0 = data_021DAD24[s3c];
        ((struct Obj00335 *)w)->f7E4 = BSUBWAY_SCR_GetWinCount(w);
        if (((struct Obj00335 *)w)->f7E4 > 9999)
            ((struct Obj00335 *)w)->f7E4 = 9999;
        SCRIPT_SYS_CallEvent(h, FIELD_STATUS_CreateSubProcCallbackEvent((char *)x, (int)s30, (u32)ov214_id, (int)data_021BB474, (int)(w + 0x7d0), 0, 0));
        ret = 1;
        break;
    case 349:
        func_0200DA14((struct Blk3C *)s40);
        func_0200DB1C((struct Blk1AC *)s38, s3c);
        break;
    case 350:
        FIELD_GIMMICK_BSUBWAY_HaltTrainSway((int)s30);
        break;
    case 351: {
        u32 n = func_0200DA54((struct Blk3C *)s40);
        switch (s3c) {
        case 2:
        case 3:
        case 7:
        case 8:
            *dst = *(u16 *)(w + (n * 2 + p1) * 2 + 0x32);
            break;
        case 0:
        case 1:
        case 4:
        case 5:
        case 6:
        default:
            *dst = *(u16 *)(w + n * 2 + 0x32);
            break;
        }
        break;
    }
    case 352:
        SCRIPT_SYS_CallEvent(h, NAMEIN_SETUP_StartNameBalloonFromRecord(w, (void *)x, p1, p2, 6));
        ret = 1;
        break;
    case 353: {
        u8 *e = *(u8 * *)&((struct Obj00335 *)w)->f7CC;
        if (e != NULL) {
            u32 kb6 = e[0xb6];
            u32 kbf = e[0xbf];
            int cnt;
            void *party = ((struct Obj02400 *)e)->f24;
            int i;
            int sa;
            int sb;
            cnt = POKEPARTY_GetCount(party);
            sa = 0;
            sb = 0;
            for (i = 0; i < cnt; i++) {
                void *mon = POKEPARTY_GetMember(party, i);
                int a1 = func_02017E1C(mon, 0xa0, 0);
                int b1 = func_02017E1C(mon, 0xa1, 0);
                sa += a1;
                sb += b1;
            }
            func_0200D9E8((struct Blk3C *)s40, kbf, kb6, (u16)(sb - sa));
        }
        break;
    }
    case 354:
        FLAGS(w)->b12 = p1;
        break;
    case 355:
        *dst = FLAGS(w)->b12;
        break;
    case 356:
        *dst = func_0200D884((struct Blk3C *)s40, 10, 0);
        break;
    case 357:
        func_0200DA28((struct Blk3C *)s40);
        BSUBWAY_SCR_IncWinCount(w);
        *dst = BSUBWAY_SCR_GetWinCount(w);
        if (*dst > 9999)
            *dst = 9999;
        break;
    case 358:
        *dst = BSUBWAY_SCR_GetWinCount(w);
        if (*dst > 9999)
            *dst = 9999;
        break;
    case 359:
        if (func_0200DB44((struct Blk1AC *)s38, s3c) == 0) {
            func_0200DB30((struct Blk1AC *)s38, s3c);
            func_0200DA14((struct Blk3C *)s40);
            BSUBWAY_SCR_ClearWinCount((u32)w);
        }
        break;
    case 400:
        if (FLAGS(w)->b9 == 1)
            BSUBWAY_COMM_AddCommandTable((u32)w);
        else
            BSUBWAY_COMM_NetInit(w);
        break;
    case 401:
        SCRIPT_SYS_CallEvent(h, func_021CB914((void *)x, (u32)w));
        ret = 1;
        break;
    case 402:
        w[0x727] = p1;
        ((struct Obj00335 *)w)->f72A = s28;
        BSUBWAY_COMM_StartTimingSync(w[0x727]);
        VM_SetWait(a, (int)func_021CB700);
        ret = 1;
        break;
    case 403:
        *(u16 * *)&((struct Obj00335 *)w)->f720 = dst;
        ((struct Obj00335 *)w)->f71C = COMM_ENTRY_MENU_Create((u32)func_02012944((void *)s4c), s30, 2, 2, 4, 0, 2, 0);
        VM_SetWait(a, (int)func_021CB754);
        ret = 1;
        break;
    case 404:
        *(u16 * *)&((struct Obj00335 *)w)->f720 = dst;
        ((struct Obj00335 *)w)->f71C = COMM_ENTRY_MENU_Create((u32)func_02012944((void *)s4c), s30, 2, 2, 4, 1, 2, 0);
        ret = 1;
        VM_SetWait(a, (int)func_021CB7E8);
        break;
    case 405:
        BSUBWAY_COMM_SetSendData((struct Obj *)w, p1, p2);
        VM_SetWait(a, (int)func_021CB6DC);
        ret = 1;
        break;
    case 406:
        BSUBWAY_COMM_SetRecvMode(w, p1);
        ((struct Obj00335 *)w)->f72A = s28;
        VM_SetWait(a, (int)func_021CB86C);
        ret = 1;
        break;
    case 407:
        *dst = GFL_NET_SYSTEM_GetCurrentAid();
        break;
    case 408:
        MI_CpuFill8(w + 0x7a4, 0, 0x24);
        ((struct Obj00335 *)w)->f7A4 = s4c;
        ((struct Obj00335 *)w)->f7C0 = 11;
        SCRIPT_SYS_CallEvent(h, FIELD_STATUS_CreateSubProcCallbackEvent((char *)x, (int)s30, (u32)ov100_id, (int)data_021BB6A4, (int)(w + 0x7a4), 0, 0));
        ret = 1;
        break;
    case 409:
        switch (((struct Obj00335 *)w)->f7C0) {
        case 11:
            *dst = 0;
            break;
        case 12:
            *dst = 1;
            break;
        case 13:
            *dst = 2;
            break;
        default:
            *dst = 1;
            break;
        }
        break;
    case 410:
        MISC_SAVEDATA_InsertRecentValue(MISC_SAVEDATA_GetBlock44((void *)s48), ((struct Obj00335 *)w)->f73C);
        break;
    case 411:
        *dst = FIELD_PLAYER_GetFormObjCode(GFL_NET_SYSTEM_GetCurrentAid() == 0 ? FIELD_PLAYER_GetSex(FIELDMAP_GetFieldPlayer((void *)s30)) : w[0x749], 0);
        break;
    case 412:
        *dst = FIELD_PLAYER_GetFormObjCode(GFL_NET_SYSTEM_GetCurrentAid() == 0 ? w[0x749] : FIELD_PLAYER_GetSex(FIELDMAP_GetFieldPlayer((void *)s30)), 0);
        break;
    case 413:
        GFL_NET_ERR_RequestScreen();
        break;
    case 414:
        ICA_ANIME_SetField30((struct Ctx *)x, 1);
        break;
    case 415:
        *dst = 0;
        if (func_0200FB24() != 0)
            *dst = 1;
        break;
    case 416: {
        u8 *e;
        *dst = 0;
        e = *(u8 * *)&((struct Obj00335 *)w)->f7CC;
        if (e != NULL && BATTLE_REC_IsVersionSupported(e[0x91]) == 1)
            *dst = 1;
        break;
    }
    case 501:
        break;
    }
    return ret;
}
