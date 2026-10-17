/*
 * file:     btl_setup.c
 * unit:     yes
 * function: BTL_SETUP_Create, BTL_SETUP_Delete, BTL_SETUP_Clear, BTL_SETUP_FreeSlots, BTL_SETUP_SetParty, BTL_SETUP_GetParty, BTL_SETUP_SetStatusFlag, BTL_SETUP_CheckStatusFlag, BTL_SETUP_ApplyRegulation, BTL_SETUP_InitCommFieldSituation, BTL_SETUP_InitFieldSituation, BTL_SETUP_CreateTrainerData, BTL_SETUP_DeleteTrainerData, BTL_SETUP_SetTrainer, BTL_SETUP_SetPlayerParty, BTL_SETUP_InitCommon, BTL_SETUP_SetupWild, BTL_SETUP_SetupTrainerBase, BTL_SETUP_SetupComm, BTL_SETUP_SetupDemo, BTL_SETUP_SetupTrainerSingle, BTL_SETUP_SetupTrainerDouble, BTL_SETUP_SetupTrainerTriple, BTL_SETUP_SetupTrainerRotation, BTL_SETUP_SetupTrainerTag, BTL_SETUP_SetupTrainerMulti, BTL_SETUP_SetupCommSingle, BTL_SETUP_SetupCommDouble, BTL_SETUP_SetupCommMulti, BTL_SETUP_SetupCommAiMulti, BTL_SETUP_SetupCommTriple, BTL_SETUP_SetupCommRotation, BTL_SETUP_InitWithSlots, BTL_SETUP_ClearWithSlots, BTL_SETUP_ChangeToSubway, BTL_SETUP_AllocRecordBuffer
 * address:  0x02013090
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from ica_anime.c, btl_setup.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MI_CpuFill8        0x02082BCC  arm
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   SYSTEM_DATA_GetConfig  0x0200873C  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   BEACON_CountFlags  0x0200C258  thumb
 *   GAME_DATA_GetField114         0x020127A4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   sBtlSetupFileName  0x020A729C  data
 *   POKEPARTY_Copy  0x0201AC2C  thumb
 *   REGULATION_GetRuleValue   0x0200AE54  thumb
 *   REGULATION_GetShooterSettings   0x0200B040  thumb
 *   POKE_REGULATION_AdjustPartyLevels   0x0201A2A8  thumb
 *   POKE_REGULATION_ResetPartyNicknames   0x0201A30C  thumb
 *   POKEPARTY_Create   0x0201A920  thumb
 *   TPOKE_DATA_GetTrainerKind   0x0202A3FC  thumb
 *   TR_TOOL_LoadTrainerInfo   0x0202A440  thumb
 *   TR_TOOL_BuildParty   0x0202A4B4  thumb
 *   FORMCHANGE_UpdateSeasonForms   0x0216AAE4  thumb
 *   BEACON_GetFromSave   0x0200C0E8  thumb
 *   ZUKAN_SAVE_GetFromGameData   0x0200CA1C  thumb
 *   ZONEDATA_CheckEventFlag   0x020142E8  thumb
 *   BOX_SAVEDATA_FindFreeSlot   0x020076D0  thumb
 *   POKEPARTY_GetCapacity   0x0201AA14  thumb
 *   POKEPARTY_GetCount   0x0201AA18  thumb
 *   MYSTATUS_Create   0x0200846C  thumb
 *   BTL_SETUP_FreeSlots     0x020130DC  thumb
 *   CONFIG_Create  0x020082EC  thumb
 *   CONFIG_Copy  0x02008314  thumb
 *   PMSI_PARAM_ClearSentence  0x0202428C  thumb
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   GAME_DATA_GetMapMatrix 0x02012924 thumb arm9
 *   GAME_DATA_GetMyItem 0x0201292C thumb arm9
 *   GAME_DATA_GetMyParty 0x02012934 thumb arm9
 *   GAME_DATA_GetBoxManager 0x0201293C thumb arm9
 *   GAME_DATA_GetEventWork 0x0201296C thumb arm9
 *   GAME_DATA_GetSeason 0x02012984 thumb arm9
 *   GAME_DATA_GetPmsWork 0x02012F20 thumb arm9
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb arm9
 */
#include "btl_setup_types.h"
#include "script_vm_types.h"
#include "vm_shared_types.h"
#include "ica_anime_shared_types.h"
#include "game_data_shared_types.h"

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

struct Regulation;

struct StrBuf;

struct NetHandle;

extern struct PlayerWork *GAME_DATA_GetField114(struct GameData *gd);

extern struct Config *SYSTEM_DATA_GetConfig(struct SaveControl *save);

extern void MI_CpuFill8(void *dst, int c, u32 n);

extern u32 GFL_HEAP_Free(void *p);

extern void POKEPARTY_Copy(const struct Party *src, struct Party *dst);

extern u32 REGULATION_GetRuleValue(struct Regulation *reg, u32 id);

extern void REGULATION_GetShooterSettings(struct Regulation *reg, u8 *rules);

extern void POKE_REGULATION_AdjustPartyLevels(struct Regulation *reg, struct Party *party);

extern void POKE_REGULATION_ResetPartyNicknames(struct Regulation *reg, struct Party *party, u32 level);

extern struct StrBuf *STRBUF_Create(u32 capacity, u32 heapId);

extern void STRBUF_Delete(struct StrBuf *str);

extern void  PMSI_PARAM_ClearSentence(void *word);

extern struct Party *POKEPARTY_Create(u16 heap);

extern void TR_TOOL_LoadTrainerInfo(u32 trainerId, struct BattleTrainerData *tr, u16 heap);

extern void TR_TOOL_BuildParty(u32 trainerId, struct Party *party, u16 heap);

extern void FORMCHANGE_UpdateSeasonForms(struct GameData *gd, struct Party *party, u32 season);

extern u8 TPOKE_DATA_GetTrainerKind(u32 trainerType);

extern struct MiscSave *BEACON_GetFromSave(struct SaveControl *save);

extern u32 BEACON_CountFlags(struct MiscSave *misc);

extern void *ZUKAN_SAVE_GetFromGameData(struct GameData *gd);

extern u32 ZONEDATA_CheckEventFlag(void *eventWork, s32 flagId);

extern void MI_CpuCopy8(const void *src, void *dst, u32 n);

extern u32  POKEPARTY_GetCount(struct Party *party);

extern u32 POKEPARTY_GetCapacity(struct Party *party);

extern int BOX_SAVEDATA_FindFreeSlot(u32 boxManager, u32 *tray, u32 *pos);

extern void *MYSTATUS_Create(u16 heap);

extern u8 GFL_NET_GetHandleNetID(struct NetHandle *net);

extern struct Config *CONFIG_Create(u16 heap);

extern void CONFIG_Copy(struct Config *src, struct Config *dest);

extern const char sBtlSetupFileName[];

u32 GAME_DATA_GetMapMatrix(const struct GameData *gd);

void *GAME_DATA_GetMyItem(const struct GameData *gd);

void *GAME_DATA_GetMyParty(const struct GameData *gd);

u32 GAME_DATA_GetBoxManager(const struct GameData *gd);

struct PlayerStatus *GAME_DATA_GetMyStatus(struct GameData *gd);

void *GAME_DATA_GetEventWork(const struct GameData *gd);

u8 GAME_DATA_GetSeason(const struct GameData *gd);

struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gd);

int GAME_DATA_GetPmsWork(struct GameData *gd);

void *GAME_DATA_GetTrainerRecord(struct GameData *gd);

struct BattleSetupParam *BTL_SETUP_Create(u32 heap);

void BTL_SETUP_Delete(struct BattleSetupParam *param);

void BTL_SETUP_Clear(struct BattleSetupParam *param);

void BTL_SETUP_FreeSlots(struct BattleSetupParam *param);

void BTL_SETUP_SetParty(struct BattleSetupParam *param, struct Party *src, int client);

void *BTL_SETUP_GetParty(struct BattleSetupParam *param, int client);

void BTL_SETUP_SetStatusFlag(struct BattleSetupParam *param, int flag);

int BTL_SETUP_CheckStatusFlag(struct BattleSetupParam *param, int mask);

void BTL_SETUP_ApplyRegulation(struct BattleSetupParam *param, struct Regulation *reg, u32 level);

void BTL_SETUP_InitCommFieldSituation(struct FieldSituation *sit);

void BTL_SETUP_InitFieldSituation(struct FieldSituation *sit);

struct BattleTrainerData *BTL_SETUP_CreateTrainerData(u16 heap);

void BTL_SETUP_DeleteTrainerData(struct BattleTrainerData *tr);

void BTL_SETUP_SetTrainer(struct BattleSetupParam *param, struct GameData *gd, u32 client, struct Party **party, u32 trainerId, u16 heap);

void BTL_SETUP_SetPlayerParty(struct BattleSetupParam *param, struct GameData *gd, u16 heap);

void BTL_SETUP_InitCommon(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit);

void BTL_SETUP_SetupWild(struct BattleSetupParam *param, struct GameData *gd, struct Party *wildParty, const struct FieldSituation *sit, u32 rule, u16 heap);

void BTL_SETUP_SetupTrainerBase(struct BattleSetupParam *param, struct GameData *gd, u32 rule, const struct FieldSituation *sit, u16 heap);

void BTL_SETUP_SetupComm(struct BattleSetupParam *param, struct GameData *gd, u32 rule, u8 multiMode, u32 netHandle, u8 commPos, u8 netId, u16 heap);

void BTL_SETUP_SetupDemo(struct BattleSetupParam *param, struct GameData *gd, struct Party *enemyParty, struct Party *partnerParty, const struct FieldSituation *sit, u16 heap);

void BTL_SETUP_SetupTrainerSingle(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap);

void BTL_SETUP_SetupTrainerDouble(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap);

void BTL_SETUP_SetupTrainerTriple(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap);

void BTL_SETUP_SetupTrainerRotation(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap);

void BTL_SETUP_SetupTrainerTag(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId1, u32 trainerId2, u16 heap);

void BTL_SETUP_SetupTrainerMulti(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 partnerId, u32 trainerId1, u32 trainerId2, u16 heap);

void BTL_SETUP_SetupCommSingle(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u16 heap);

void BTL_SETUP_SetupCommDouble(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u16 heap);

void BTL_SETUP_SetupCommMulti(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u8 netId, u16 heap);

void BTL_SETUP_SetupCommAiMulti(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u8 netId, u32 trainerId1, u32 trainerId2, u16 heap);

void BTL_SETUP_SetupCommTriple(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u16 heap);

void BTL_SETUP_SetupCommRotation(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u16 heap);

void BTL_SETUP_InitWithSlots(struct BattleSetupParam *param, struct GameData *gd, u16 heap);

void BTL_SETUP_ClearWithSlots(struct BattleSetupParam *param);

void BTL_SETUP_ChangeToSubway(struct BattleSetupParam *param);

void BTL_SETUP_AllocRecordBuffer(struct BattleSetupParam *param, u32 heap);

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_Create.c \
 *       --func BTL_SETUP_Create --addr 0x02013090 --cc 1.1p1 --thumb
 */
struct BattleSetupParam *BTL_SETUP_Create(u32 heap)
{
    struct BattleSetupParam *param;
    param = GFL_HEAP_Alloc(heap, 0xf0, 0, sBtlSetupFileName, 0x31);
    BTL_SETUP_Clear(param);
    return param;
}

void BTL_SETUP_Delete(struct BattleSetupParam *param)
{
    BTL_SETUP_FreeSlots(param);
    GFL_HEAP_Free(param);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_Clear.c \
 *       --func BTL_SETUP_Clear --addr 0x020130C4 --cc 1.1p1 --thumb
 */
void BTL_SETUP_Clear(struct BattleSetupParam *param)
{
    MI_CpuFill8(param, 0, 0xf0);
    BTL_SETUP_InitFieldSituation(&param->fieldSituation);
}

/*
 * verdict is EXACT* : all 74 code bytes reproduce (5 of 5 relocation sites
 * resolved), the inferred extent only ran long by the follower at 0x02013128
 * (28 bytes, a tail-call wrapper into 0x0201AC2C|1) which has no label
 * because it saves nothing -- report it for layout/function_starts.txt
 * rather than editing that file here.
 */
void BTL_SETUP_FreeSlots(struct BattleSetupParam *param)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (param->party[i] != 0)
            GFL_HEAP_Free(param->party[i]);
        if (param->trainerData[i] != 0)
            BTL_SETUP_DeleteTrainerData(param->trainerData[i]);
        if (i != 0 && param->playerStatus[i] != 0)
            GFL_HEAP_Free(param->playerStatus[i]);
    }
    if (param->recordBuffer != 0)
        GFL_HEAP_Free(param->recordBuffer);
    MI_CpuFill8(param, 0, 0xf0);
}

/*
 * Unlabelled Thumb thunk (btl_setup.c). Tail-calls
 * POKEPARTY_Copy (the 0x534-byte container copy in unit_0201AC2C.c,
 * prototype (src, dst)) with the second argument as source and the i-th
 * pointer of the table at +0x24 as destination.
 *
 * Addresses are Black-image addresses.
 */
void BTL_SETUP_SetParty(struct BattleSetupParam *param, struct Party *src, int client)
{
    POKEPARTY_Copy(src, param->party[client]);
}

/*
 * Unlabelled Thumb leaf: the i-th pointer of the table at +0x24.
 */
void *BTL_SETUP_GetParty(struct BattleSetupParam *param, int client)
{
    return param->party[client];
}

void BTL_SETUP_SetStatusFlag(struct BattleSetupParam *param, int flag)
{
    param->statusFlags |= (unsigned short)flag;
}

/*
 * Unlabelled leaf accessor: returns m & *(u16 *)(base + 0x82).
 */
int BTL_SETUP_CheckStatusFlag(struct BattleSetupParam *param, int mask)
{
    return param->statusFlags & mask;
}

/*
 * btl_setup.c.  The per-battle settings copier: two timer fields in seconds,
 * a name block, a three-way flag decision, and a pass over the four +0x24
 * slots binding each to the caller's third argument.
 *
 * This closes the near miss in docs/notes/pkt_02013160.c.txt, which compiled
 * 162 bytes against 172 with 77 concrete bytes out.  Three findings, in
 * descending order of how much each was worth.
 *
 * (1) THE SWITCH NEEDS AN EXPLICIT EMPTY `case 0:`.  This is the whole
 * function.  The image dispatches through a PC-relative halfword table of
 * four entries with a `cmp r0, #3 / bhi` range check, and that table only
 * exists if the case labels are dense from zero; with cases 1, 2 and 3 only,
 * the compiler emits a compare chain instead and the function comes out 12
 * bytes short.  Adding `case 0: break;` took the residue from 80 concrete
 * bytes out to ONE and the permuter's instruction score from 820 to 110, with
 * the size going from 160 to the correct 170.  See
 * docs/idioms/empty-switch-arms-are-what-make-the-table.md and
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *
 * (2) THE LOOP COUNTER IS SIGNED.  The last byte was `blt` against `blo`:
 * `int i` rather than `u32 i` for the four-slot loop.  Nothing else in the
 * function distinguishes them.
 *
 * (3) 0x10 and 0x3C are named locals, not literals.  `movs r5, #0x10` is
 * hoisted to the prologue, before the first REGULATION_GetRuleValue call, and r5 is
 * then shifted left by 6 and by 7 to build the two flag masks; `movs r7,
 * #0x3c` is materialised once and reused as the multiplier for both timer
 * fields.  Spelling the masks as the constants 0x400 and 0x800, or the
 * multiplier as a literal 0x3c at each site, rematerialises them per use.
 * The multiplication is written `sec * f(...)` and not `f(...) * sec`: the
 * accumulator of a commutative chain is its second operand, so the operand
 * order here is what puts the call result in r1 and the constant in r7.
 *
 * The three switch arms tail-merge: case 3 falls into case 1's body rather
 * than duplicating the store, which is why the `b` at the end of case 2
 * targets the middle of case 1's block.  Writing the two ORs of case 3 as
 * two separate statements in source order is what produces that, not a
 * combined `|= (bit << 6) | (bit << 7)`.
 *
 * EXACT*: all 170 code bytes reproduce (4 of 4 relocation sites resolved);
 * the inferred extent ran two bytes long only on the `movs r0, r0` alignment
 * pad at 0x0201320A before BTL_SETUP_InitCommFieldSituation.  Never a byte difference.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_ApplyRegulation.c \
 *       --func BTL_SETUP_ApplyRegulation --addr 0x02013160 --cc 1.1p1 --thumb
 */
void BTL_SETUP_ApplyRegulation(struct BattleSetupParam *param, struct Regulation *reg, u32 level)
{
    u32 bit = 0x10;
    u32 sec = 0x3c;
    int i;
    param->limitTimeCommand = (u16)(sec * REGULATION_GetRuleValue(reg, 0x10));
    param->limitTimeGame = (u16)(sec * REGULATION_GetRuleValue(reg, 0xf));
    REGULATION_GetShooterSettings(reg, param->regulationRules);
    switch (REGULATION_GetRuleValue(reg, 0x12)) {
    case 0:
        break;
    case 1:
        param->statusFlags |= (u16)(bit << 7);
        break;
    case 2:
        param->statusFlags |= (u16)(bit << 6);
        break;
    case 3:
        param->statusFlags |= (u16)(bit << 6);
        param->statusFlags |= (u16)(bit << 7);
        break;
    }
    for (i = 0; i < 4; i++) {
        if (param->party[i] != 0) {
            POKE_REGULATION_ResetPartyNicknames(reg, param->party[i], level);
            POKE_REGULATION_AdjustPartyLevels(reg, param->party[i]);
        }
    }
}

void BTL_SETUP_InitCommFieldSituation(struct FieldSituation *sit)
{
    sit->bgType = 9;
    sit->bgAttr = 0;
    sit->weather = 0;
    sit->zoneId = 0;
    sit->hour = 0;
    sit->minute = 0;
    sit->season = 0;
}

void BTL_SETUP_InitFieldSituation(struct FieldSituation *sit)
{
    sit->bgType = 0;
    sit->bgAttr = 0;
    sit->season = 0;
    sit->weather = 0;
    sit->zoneId = 0;
    sit->hour = 0xa;
    sit->minute = 0;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_CreateTrainerData.c \
 *       --func BTL_SETUP_CreateTrainerData --addr 0x02013234 --cc 1.1p1 --thumb
 */
struct BattleTrainerData *BTL_SETUP_CreateTrainerData(u16 heap)
{
    struct BattleTrainerData *tr;
    tr = GFL_HEAP_Alloc(heap, 0x28, 1, sBtlSetupFileName, 0xef);
    tr->name = STRBUF_Create(0x10, heap);
    tr->trainerId = 0;
    PMSI_PARAM_ClearSentence(tr->winWord);
    PMSI_PARAM_ClearSentence(tr->loseWord);
    return tr;
}

void BTL_SETUP_DeleteTrainerData(struct BattleTrainerData *tr)
{
    STRBUF_Delete(tr->name);
    GFL_HEAP_Free(tr);
}

/*
 * btl_setup.c.  The sub-block filler, and the most-called function of the
 * family: every builder in the range (BTL_SETUP_SetupTrainerSingle, BTL_SETUP_SetupTrainerDouble,
 * BTL_SETUP_SetupTrainerTriple, BTL_SETUP_SetupTrainerRotation, BTL_SETUP_SetupTrainerTag, BTL_SETUP_SetupTrainerMulti, BTL_SETUP_SetupCommAiMulti,
 * all EXACT) calls it once or three times.  It lazily fills two slots - the
 * caller's own out-pointer and the object's +0x48 array entry - then, only if
 * the value argument is non-zero, binds them together and picks the object's
 * +0x1a code from a twelve-way switch.
 *
 * This closes the near miss in docs/notes/pkt_02013284.c.txt, which sat at 48
 * concrete bytes out with the size already exact.  Two things closed it.
 *
 * (1) THE ARITY IS SIX, NOT SEVEN.  The note gave it seven parameters
 * (a0..a6).  The six-parameter form is fixed from outside this function by
 * the matched callers, every one of which passes exactly six
 * (o, a1, n, dst, v, h).  Re-spelling the signature that way took the
 * residue from 48 concrete bytes out to 15 and halved the permuter's
 * instruction score, 525 -> 280, with the size unchanged at 184.
 *
 * (2) THE +0x48 SLOT IS REGISTER-OFFSET ADDRESSED, so its base and its
 * scaled index have to be two separate live values.  The image loads it with
 * `ldr r0, [r7, r6]` where r7 is o+0x48 and r6 is n*4; writing the access as
 * a single pointer, `slot = (u32 *)(o + 0x48 + n * 4)`, folds the two into
 * one value and the allocator then has one fewer value to colour, which is
 * what produced the r5/r6/r7 rotation the permuter reported.  Splitting it
 * into a `u8 *slots` (the trainerData array) and a separate `u32 off`, and indexing as
 * `*(struct BattleTrainerData **)(slots + off)`, keeps both values live and gives the original
 * registers and the original `lsls` / `adds` order.  A `u32 *` base with a
 * divided index (`base[off / 4]`) does NOT work: the compiler folds the
 * scaling back out and the rotation returns.
 *
 * The permuter was the diagnostic here rather than the fix.  `--explain` on
 * the seven-parameter source printed a clean three-way register rotation
 * (r7->r6, r6->r7, r5->...), which is what said the residue was an allocation
 * tie and not a mistranslation, and on the six-parameter source it printed
 * the same rotation at 15 bytes out with every instruction aligned - which
 * localised the fix to the one value that was missing.  Its own best results
 * were rejected on both passes: hill found temp(tmp=*slot) at 11 bytes out
 * but with the instruction score RISING 280 -> 460, the signature of a
 * coincidental byte alignment rather than a real fix.
 *
 * The switch is dense from 2 to 11 with 0, 1, 5 and 10 falling to the
 * default, which is what makes the PC-relative halfword table exist; the
 * `cmp r0, #0xb / bhi` pair is the table's range check.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetTrainer.c \
 *       --func BTL_SETUP_SetTrainer --addr 0x02013284 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetTrainer(struct BattleSetupParam *param, struct GameData *gd, u32 client, struct Party **party, u32 trainerId, u16 heap)
{
    u8 *slots;
    u32 off;
    if (*party == 0) {
        *party = POKEPARTY_Create(heap);
    }
    off = client * 4;
    slots = (u8 *)param->trainerData;
    if (*(struct BattleTrainerData **)(slots + off) == 0) {
        *(struct BattleTrainerData **)(slots + off) = BTL_SETUP_CreateTrainerData(heap);
    }
    if (trainerId == 0) {
        return;
    }
    TR_TOOL_LoadTrainerInfo(trainerId, *(struct BattleTrainerData **)(slots + off), heap);
    TR_TOOL_BuildParty(trainerId, *party, heap);
    FORMCHANGE_UpdateSeasonForms(gd, *party, GAME_DATA_GetSeason(gd));
    switch (TPOKE_DATA_GetTrainerKind((*(struct BattleTrainerData **)(slots + off))->trainerType)) {
    case 2:
    case 3:
        param->bgmWin = 0x47e;
        break;
    case 7:
    case 8:
        param->bgmWin = 0x47f;
        break;
    case 4:
    case 11:
        param->bgmWin = 0x480;
        break;
    case 6:
    case 9:
        param->bgmWin = 0x491;
        break;
    default:
        param->bgmWin = 0x47d;
        break;
    }
}

void BTL_SETUP_SetPlayerParty(struct BattleSetupParam *param, struct GameData *gd, u16 heap)
{
    GAME_DATA_GetField114(gd);
    param->party[0] = POKEPARTY_Create(heap);
    POKEPARTY_Copy(GAME_DATA_GetMyParty(gd), param->party[0]);
}

/*
 * btl_setup.c.  The shared setup-object initialiser every builder of the
 * family calls with (o, a1, sub): reset the flag and slot fields, read the
 * per-battle values out of the game-data object a1, and copy the 0x10-byte
 * sub-block a2 to +8.
 *
 * Two facts closed it (docs/notes/pkt_02013360.c.txt had it at 266 bytes
 * out, every line phase-shifted from the head):
 *  - 0x02082D44 is MI_CpuCopy8 (layout/symbols_sdk.txt), whose order is
 *    (src, dst, size): the image computes o + 8 into r1 and a2 into r0.
 *    With that order the whole body is byte-exact and only the head differs.
 *  - The first loop counter is initialised at its declaration, ahead of the
 *    store run.  That puts the constant 0 (shared by the zero stores and the
 *    counter) before the 0xffff store in the IR, so the zero takes r0 and
 *    the 0x84 base is built in r1 from the o copy, which is the image's
 *    head.  With `for (i = 0; ...)` the base coalesces into r0 instead and
 *    every later line is displaced.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_InitCommon.c  *       --func BTL_SETUP_InitCommon --addr 0x02013360 --cc 1.1p1 --thumb
 */
void BTL_SETUP_InitCommon(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit)
{
    u32 i = 0;
    u32 j;
    struct SaveControl *save;
    void *misc;
    param->levelCap = 0xffff;
    param->commPos = 0;
    param->netId = 0;
    param->multiMode = 0;
    param->recordBuffer = 0;
    param->ownsSlots = 0;
    param->bitFlags = param->bitFlags & ~1;
    param->netHandle = 0;
    param->bitFlags = param->bitFlags & ~2;
    param->gameData = gd;
    for (; i < 4; i++) {
        param->party[i] = 0;
        param->playerStatus[i] = 0;
    }
    for (j = 0; j < 6; j++) {
        param->resultFlags[j] = 0;
    }
    param->recordEnabled = 1;
    for (i = 0; i < 7; i++) {
        param->regulationRules[i] = 0;
    }
    param->playerStatus[0] = GAME_DATA_GetMyStatus(gd);
    param->myItem = GAME_DATA_GetMyItem(gd);
    param->mapMatrix = GAME_DATA_GetMapMatrix(gd);
    param->zukanWork = ZUKAN_SAVE_GetFromGameData(gd);
    param->pmsWork = GAME_DATA_GetPmsWork(gd);
    param->trainerRecord = GAME_DATA_GetTrainerRecord(gd);
    save = GAME_DATA_GetSaveControl(gd);
    misc = BEACON_GetFromSave(save);
    param->config = SYSTEM_DATA_GetConfig(save);
    param->badgeCount = (u8)BEACON_CountFlags(misc);
    MI_CpuCopy8(sit, &param->fieldSituation, 0x10);
    param->bgmBattle = 0x468;
    param->bgmWin = 0x468 + 0x14;
    param->moneyRate = 1;
    if (ZONEDATA_CheckEventFlag(GAME_DATA_GetEventWork(gd), 0x96d) != 0) {
        BTL_SETUP_SetStatusFlag(param, 2);
    }
}

/*
 * btl_setup.c.  The link-battle variant of the setup builder: the same
 * three shared writers as BTL_SETUP_SetupDemo, then the object is put in mode 0
 * and a consistency check on the +0x24 slot decides whether flag 0x40 is
 * set.
 *
 * The documented near miss in docs/notes/pkt_02013360.c.txt compiled 122
 * bytes against 120 and missed on 108 of them.  Two leftover-register
 * readings are what close it, and both are the same idiom, see
 * docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-arity.md.
 *
 * (1) POKEPARTY_Copy takes the POKEPARTY_Create result as a second argument.
 * The original writes `adds r1, r0, #0; str r1, [r4, #0x28]`, which reads
 * as a gratuitous register copy before the store.  It is not: r1 is the
 * second argument of the guarded POKEPARTY_Copy call below, so the value has
 * to reach r1 anyway and the store then sources it from there.  The
 * first drafts declared POKEPARTY_Copy variadic; with every call written with
 * both arguments, the plain (src, dst) prototype gives the same bytes.
 *
 * (2) BOX_SAVEDATA_FindFreeSlot takes THREE arguments, and its first is the return
 * value of the GAME_DATA_GetBoxManager call immediately above it.  The original sets
 * only r1 and r2 (`add r1, sp, #4; add r2, sp, #0`) and leaves r0 holding
 * what GAME_DATA_GetBoxManager returned.  Declaring it with two parameters puts the
 * two pointers in r0/r1 and is a two-byte, two-instruction miss; declaring
 * GAME_DATA_GetBoxManager as returning u32 and passing that result explicitly gives
 * the original bytes with no extra `adds`, because the value is already in
 * r0 and the compiler elides the copy.
 *
 * The two out-parameters are declared x then y but passed &x as the SECOND
 * argument and &y as the third: x lives at sp+4 and y at sp+0, which is the
 * later-declaration-at-the-lower-address rule, see
 * docs/idioms/local-declaration-order-is-stack-order.md.
 *
 * EXACT*: all 118 code bytes reproduce (10 of 10 relocation sites
 * resolved); the inferred extent ran two bytes long only on the
 * `movs r0, r0` alignment pad at 0x020134F2 before BTL_SETUP_SetupTrainerBase.  Never a
 * byte difference.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupWild.c \
 *       --func BTL_SETUP_SetupWild --addr 0x0201347C --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupWild(struct BattleSetupParam *param, struct GameData *gd, struct Party *wildParty, const struct FieldSituation *sit, u32 rule, u16 heap)
{
    u32 tray;
    u32 pos;
    struct Party *enemy;
    u32 count;
    u32 box;
    BTL_SETUP_Clear(param);
    BTL_SETUP_InitCommon(param, gd, sit);
    BTL_SETUP_SetPlayerParty(param, gd, heap);
    enemy = POKEPARTY_Create(heap);
    param->party[1] = enemy;
    if (wildParty != 0) {
        POKEPARTY_Copy(wildParty, enemy);
    }
    param->rule = rule;
    param->competitor = 0;
    count = POKEPARTY_GetCount(param->party[0]);
    if (count != POKEPARTY_GetCapacity(param->party[0])) {
        return;
    }
    box = GAME_DATA_GetBoxManager(gd);
    tray = 0;
    pos = 0;
    if (BOX_SAVEDATA_FindFreeSlot(box, &tray, &pos) == 0) {
        BTL_SETUP_SetStatusFlag(param, 0x40);
    }
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupTrainerBase.c \
 *       --func BTL_SETUP_SetupTrainerBase --addr 0x020134F4 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupTrainerBase(struct BattleSetupParam *param, struct GameData *gd, u32 rule, const struct FieldSituation *sit, u16 heap)
{
    BTL_SETUP_Clear(param);
    BTL_SETUP_InitCommon(param, gd, sit);
    BTL_SETUP_SetPlayerParty(param, gd, heap);
    param->competitor = 1;
    param->rule = rule;
    param->bgmWin = 0x47d;
}

/*
 * btl_setup.c. The eight-argument setup builder (sibling of BTL_SETUP_SetupDemo).
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 152/152, 6 bytes out for four
 * waves, docs/notes/pkt_02013528.c.txt): the eighth (stack) parameter is a
 * heap id and is u16, with u16 on the matching parameter of BTL_SETUP_SetPlayerParty,
 * MYSTATUS_Create and POKEPARTY_Create (BTL_SETUP_SetupDemo already declares the first
 * and last that way). With u32 there, 1.1p1 schedules the r3 home store
 * `str r3, [sp]` after the three parameter copies; with u16 it comes first,
 * as in the image. docs/idioms/a-u16-stack-parameter-passed-to-a-u16-callee-
 * stays-behind-a-spill-store.md is the same lever.
 */
void BTL_SETUP_SetupComm(struct BattleSetupParam *param, struct GameData *gd, u32 rule, u8 multiMode, u32 netHandle, u8 commPos, u8 netId, u16 heap)
{
    struct FieldSituation sit;
    u32 i;
    BTL_SETUP_Clear(param);
    BTL_SETUP_InitCommFieldSituation(&sit);
    sit.bgType = 9;
    sit.bgAttr = 1;
    BTL_SETUP_InitCommon(param, gd, &sit);
    BTL_SETUP_SetPlayerParty(param, gd, heap);
    param->competitor = 3;
    param->rule = rule;
    param->netHandle = netHandle;
    param->commPos = commPos;
    param->multiMode = multiMode;
    param->netId = netId;
    param->levelCap = 0xff;
    param->bgmWin = 0x47d;
    i = 0;
    do {
        if (i != 0) {
            if (param->playerStatus[i] == 0)
                param->playerStatus[i] = MYSTATUS_Create(heap);
            if (param->party[i] == 0)
                param->party[i] = POKEPARTY_Create(heap);
        }
        i++;
    } while (i < 4);
}

/*
 * btl_setup.c.  The four-argument variant of the setup builder: the shared
 * writers run first, then up to two optional attachments are bound through
 * POKEPARTY_Copy, and the object is left in mode 4.
 *
 * This closes the near miss documented in docs/notes/pkt_02013528.c.txt.
 * That note was right that POKEPARTY_Copy cannot carry a fixed two-parameter
 * prototype - the first call site passes r0 and r1, the second passes only
 * r0 - and right that a variadic declaration, `void POKEPARTY_Copy(u32 a,
 * ...)`, is the only one under which both sites emit the original bytes.
 * What it could not recover was the `adds r1, r0, #0` the original keeps
 * before the +0x28 store, and it concluded that binding the result to a
 * named local did not help.
 *
 * The resolution is that r1 is not a register copy at all: it is the SECOND
 * ARGUMENT of the second POKEPARTY_Copy call.  Writing the call as
 * `POKEPARTY_Copy(a3, r)` - handing it the POKEPARTY_Create result the +0x28
 * store also consumes - produces `adds r1, r0, #0; str r1, [r5, #0x28]`
 * exactly, because the value has to reach r1 for the call and the store
 * then reads it from there.  The "leftover" register really is a passed
 * argument, the same tell as
 * docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-arity.md.
 * Both calls pass (src, dst), so the plain two-parameter prototype holds.
 *
 * Permuter note: tools/permuter.py hill (179 mutations tried) reached
 * 6 bytes out at the right size with copy(r->r_@6), but its mutation was
 * `r_ = r;` BEFORE r is assigned - an uninitialised read that scores well
 * and is not admissible C.  It did correctly localise the residue to a
 * single r1 -> r0 substitution at the store, which is what pointed at the
 * argument reading rather than at a copy.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupDemo.c \
 *       --func BTL_SETUP_SetupDemo --addr 0x020135C0 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupDemo(struct BattleSetupParam *param, struct GameData *gd, struct Party *enemyParty, struct Party *partnerParty, const struct FieldSituation *sit, u16 heap)
{
    struct Party *party;
    BTL_SETUP_Clear(param);
    BTL_SETUP_InitCommon(param, gd, sit);
    BTL_SETUP_SetPlayerParty(param, gd, heap);
    if (enemyParty != 0) {
        POKEPARTY_Copy(enemyParty, param->party[0]);
    }
    party = POKEPARTY_Create(heap);
    param->party[1] = party;
    if (partnerParty != 0) {
        POKEPARTY_Copy(partnerParty, party);
    }
    param->competitor = 4;
    param->rule = 0;
}

/*
 * One of a family of four (0x02013610, 0x02013644, 0x02013678, 0x020136AC)
 * that differ only in the constant handed to BTL_SETUP_SetupTrainerBase as its third
 * argument - 0, 1, 2 and 3 - so this is the id-0 member of a table of
 * builders.  The fifth argument arrives on the stack (the `add r2, sp, #0x20`
 * / `ldrh` pair), which is why the prologue pushes six registers and then
 * takes eight more bytes.
 *
 * The same object goes to both calls; the second call's fourth argument is
 * the object plus 0x28 (the tail of the two stack arguments it forwards).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupTrainerSingle.c \
 *       --func BTL_SETUP_SetupTrainerSingle --addr 0x02013610 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupTrainerSingle(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap)
{
    BTL_SETUP_SetupTrainerBase(param, gd, 0, sit, heap);
    BTL_SETUP_SetTrainer(param, gd, 1, &param->party[1], trainerId, heap);
}

/*
 * Member 1 of the four-member family at 0x02013610..0x020136E0 - the same
 * two calls with the same object, differing only in the id handed to
 * BTL_SETUP_SetupTrainerBase (1 here, and 0, 1, 2, 3 across the family).  The fifth
 * argument arrives on the stack.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupTrainerDouble.c \
 *       --func BTL_SETUP_SetupTrainerDouble --addr 0x02013644 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupTrainerDouble(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap)
{
    BTL_SETUP_SetupTrainerBase(param, gd, 1, sit, heap);
    BTL_SETUP_SetTrainer(param, gd, 1, &param->party[1], trainerId, heap);
}

/*
 * Member 2 of the four-member family at 0x02013610..0x020136E0 - the same
 * two calls with the same object, differing only in the id handed to
 * BTL_SETUP_SetupTrainerBase (2 here, and 0, 1, 2, 3 across the family).  The fifth
 * argument arrives on the stack.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupTrainerTriple.c \
 *       --func BTL_SETUP_SetupTrainerTriple --addr 0x02013678 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupTrainerTriple(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap)
{
    BTL_SETUP_SetupTrainerBase(param, gd, 2, sit, heap);
    BTL_SETUP_SetTrainer(param, gd, 1, &param->party[1], trainerId, heap);
}

/*
 * Member 3 of the four-member family at 0x02013610..0x020136E0 - the same
 * two calls with the same object, differing only in the id handed to
 * BTL_SETUP_SetupTrainerBase (3 here, and 0, 1, 2, 3 across the family).  The fifth
 * argument arrives on the stack.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupTrainerRotation.c \
 *       --func BTL_SETUP_SetupTrainerRotation --addr 0x020136AC --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupTrainerRotation(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap)
{
    BTL_SETUP_SetupTrainerBase(param, gd, 3, sit, heap);
    BTL_SETUP_SetTrainer(param, gd, 1, &param->party[1], trainerId, heap);
}

/*
 * The main variant of the three-slot setup (see BTL_SETUP_SetupTrainerMulti, the brief
 * one): the first call is the four-register form of the same writer with
 * count 1, then two calls into BTL_SETUP_SetTrainer that each carry the source's
 * own stack arguments - a word and the halfword at +4 of the argument
 * block - plus the two object sub-blocks at +0x28 and +0x30.  The last
 * store marks the object's +0x22 byte as the count of sub-blocks.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupTrainerTag.c \
 *       --func BTL_SETUP_SetupTrainerTag --addr 0x020136E0 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupTrainerTag(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId1, u32 trainerId2,
                   u16 heap)
{
    BTL_SETUP_SetupTrainerBase(param, gd, 1, sit, heap);
    BTL_SETUP_SetTrainer(param, gd, 1, &param->party[1], trainerId1, heap);
    BTL_SETUP_SetTrainer(param, gd, 3, &param->party[3], trainerId2, heap);
    param->multiMode = 4;
}

/*
 * The three-slot setup that takes a single word argument block: the shared
 * halfword is the first word of that block (its low half, copied into the
 * outgoing stack slot of the first call) and the fourth word of the object
 * is the outer value both other calls carry.  Only three sub-blocks here,
 * so the trailing byte is 3.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupTrainerMulti.c \
 *       --func BTL_SETUP_SetupTrainerMulti --addr 0x02013734 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupTrainerMulti(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 partnerId, u32 trainerId1,
                   u32 trainerId2, u16 heap)
{
    BTL_SETUP_SetupTrainerBase(param, gd, 1, sit, heap);
    BTL_SETUP_SetTrainer(param, gd, 2, &param->party[2], partnerId, heap);
    BTL_SETUP_SetTrainer(param, gd, 1, &param->party[1], trainerId1, heap);
    BTL_SETUP_SetTrainer(param, gd, 3, &param->party[3], trainerId2, heap);
    param->multiMode = 3;
}

/*
 * The id-0 member of the second builder family in this packet: the fourth
 * argument of the shared 8-argument helper BTL_SETUP_SetupComm is 0, and the
 * object's argument is first run through GFL_NET_GetHandleNetID (ARM) whose result
 * becomes the seventh argument.  BTL_SETUP_SetupComm's last four parameters live
 * on the stack, which is the sixteen-byte frame.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupCommSingle.c \
 *       --func BTL_SETUP_SetupCommSingle --addr 0x02013790 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupCommSingle(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u16 heap)
{
    u8 netId = GFL_NET_GetHandleNetID((struct NetHandle *)netHandle);
    BTL_SETUP_SetupComm(param, gd, 0, 0, netHandle, commPos, netId, heap);
}

/*
 * The id-1 member of the same family - byte for byte BTL_SETUP_SetupCommSingle with a 1
 * where it has a 0 (the third argument of BTL_SETUP_SetupComm).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupCommDouble.c \
 *       --func BTL_SETUP_SetupCommDouble --addr 0x020137C0 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupCommDouble(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u16 heap)
{
    u8 netId = GFL_NET_GetHandleNetID((struct NetHandle *)netHandle);
    BTL_SETUP_SetupComm(param, gd, 1, 0, netHandle, commPos, netId, heap);
}

/*
 * The shortest member of the family: no GFL_NET_GetHandleNetID call, and the two stack
 * arguments the caller passes (a byte at +0x00 and a halfword at +0x04 of the
 * caller's stack block) are forwarded as the seventh and eighth arguments.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupCommMulti.c \
 *       --func BTL_SETUP_SetupCommMulti --addr 0x020137F0 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupCommMulti(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u8 netId, u16 heap)
{
    BTL_SETUP_SetupComm(param, gd, 1, 1, netHandle, commPos, netId, heap);
}

/*
 * btl_setup.c.  The three-slot builder on the eight-argument writer: the
 * same shape as BTL_SETUP_SetupTrainerTag and BTL_SETUP_SetupTrainerMulti (both EXACT), but the lead
 * call is BTL_SETUP_SetupComm rather than BTL_SETUP_SetupTrainerBase, so the object's mode is
 * stored by this function (1) instead of by the writer.
 *
 * The documented near miss in docs/notes/pkt_02013810.c.txt compiled 56
 * bytes against 84 because it gave BTL_SETUP_SetupComm six parameters and
 * BTL_SETUP_SetTrainer seven, and passed the object's +0x28 sub-block as a bare
 * constant.  The arity is fixed by the matched members of both families:
 * BTL_SETUP_SetupComm takes eight (BTL_SETUP_SetupCommSingle, BTL_SETUP_SetupCommMulti et al) and
 * BTL_SETUP_SetTrainer takes six (BTL_SETUP_SetupTrainerSingle, BTL_SETUP_SetupTrainerTag et al).  With those
 * two prototypes and the shared halfword forwarded to all three calls, the
 * body is the ordinary family shape and matches first try.
 *
 * The incoming stack block is what `add r6, sp, #0x28` addresses (0x10 of
 * frame plus six pushed registers): a4 is the byte at +0x00, a5 the word at
 * +0x04, a6 the word at +0x08 and a7 the halfword at +0x0C, which is why a7
 * is re-loaded with `ldrh [r6, #0xc]` before each of the three calls rather
 * than kept in a register.
 *
 * EXACT*: all 82 code bytes reproduce (3 of 3 relocation sites resolved);
 * the inferred extent ran two bytes long only on the `movs r0, r0` alignment
 * pad at 0x02013862 before BTL_SETUP_SetupCommTriple, which has a label.  Never a byte
 * difference.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupCommAiMulti.c \
 *       --func BTL_SETUP_SetupCommAiMulti --addr 0x02013810 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupCommAiMulti(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u8 netId, u32 trainerId1, u32 trainerId2, u16 heap)
{
    BTL_SETUP_SetupComm(param, gd, 1, 2, netHandle, commPos, netId, heap);
    param->competitor = 1;
    BTL_SETUP_SetTrainer(param, gd, 1, &param->party[1], trainerId1, heap);
    BTL_SETUP_SetTrainer(param, gd, 3, &param->party[3], trainerId2, heap);
}

/*
 * The id-2 member of the same family - byte for byte BTL_SETUP_SetupCommSingle with a 2
 * where it has a 0 (the third argument of BTL_SETUP_SetupComm).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupCommTriple.c \
 *       --func BTL_SETUP_SetupCommTriple --addr 0x02013864 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupCommTriple(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u16 heap)
{
    u8 netId = GFL_NET_GetHandleNetID((struct NetHandle *)netHandle);
    BTL_SETUP_SetupComm(param, gd, 2, 0, netHandle, commPos, netId, heap);
}

/*
 * The id-3 member of the same family - byte for byte BTL_SETUP_SetupCommSingle with a 3
 * where it has a 0 (the third argument of BTL_SETUP_SetupComm).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupCommRotation.c \
 *       --func BTL_SETUP_SetupCommRotation --addr 0x02013894 --cc 1.1p1 --thumb
 */
void BTL_SETUP_SetupCommRotation(struct BattleSetupParam *param, struct GameData *gd, u32 netHandle, u8 commPos, u16 heap)
{
    u8 netId = GFL_NET_GetHandleNetID((struct NetHandle *)netHandle);
    BTL_SETUP_SetupComm(param, gd, 3, 0, netHandle, commPos, netId, heap);
}

void BTL_SETUP_InitWithSlots(struct BattleSetupParam *param, struct GameData *gd, u16 heap)
{
    u32 i;
    struct Config *config;
    struct Config *copy;
    MI_CpuFill8(param, 0, 0xf0);
    for (i = 0; i < 4; i++) {
        param->party[i] = POKEPARTY_Create(heap);
        param->playerStatus[i] = MYSTATUS_Create(heap);
        param->trainerData[i] = BTL_SETUP_CreateTrainerData(heap);
    }
    param->gameData = gd;
    config = SYSTEM_DATA_GetConfig(GAME_DATA_GetSaveControl(gd));
    copy = CONFIG_Create(heap);
    param->config = copy;
    CONFIG_Copy(config, copy);
    param->zukanWork = ZUKAN_SAVE_GetFromGameData(gd);
    param->ownsSlots = 1;
    BTL_SETUP_AllocRecordBuffer(param, heap);
}

/*
 * The subsystem destructor: the +0x5C buffer is released and its pointer
 * cleared (the store inside the guard, not after it), then the teardown is
 * handed to BTL_SETUP_FreeSlots with the object left in r0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_ClearWithSlots.c  *       --func BTL_SETUP_ClearWithSlots --addr 0x02013930 --cc 1.1p1 --thumb
 */
void BTL_SETUP_ClearWithSlots(struct BattleSetupParam *param)
{
    if (param->config != 0) {
        GFL_HEAP_Free(param->config);
        param->config = 0;
    }
    BTL_SETUP_FreeSlots(param);
}

/*
 * btl_setup.c.  A one-shot state step: only while the state word is 1 does it
 * advance to 2 and choose a pair of halfword bounds, keyed off a value read
 * through the object's +0x4c pointer.  The 0x470/0x480 pair is built by
 * `movs`+`lsls` (Thumb has no wide immediate), the 0x46b/0x47d pair comes
 * from the literal pool because 0x46b does not fit a Thumb immediate - both
 * spellings are a plain `u16` store of a constant.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_ChangeToSubway.c \
 *       --func BTL_SETUP_ChangeToSubway --addr 0x0201394C --cc 1.1p1 --thumb
 */
void BTL_SETUP_ChangeToSubway(struct BattleSetupParam *param)
{
    if (param->competitor == 1) {
        param->competitor = 2;
        if (TPOKE_DATA_GetTrainerKind(param->trainerData[1]->trainerType) != 0xb) {
            param->bgmBattle = 0x46b;
            param->bgmWin = 0x47d;
        } else {
            param->bgmBattle = 0x470;
            param->bgmWin = 0x480;
        }
    }
}

/*
 * btl_setup.c.  A lazy 0xc00-byte zeroed allocation hung off the object at
 * +0x94: the allocator gets the caller's heap (its own r0 is overwritten by
 * the pointer arithmetic, so the heap is carried in r1 at entry), the class
 * id 3 << 10 and the file name/line pair.  The `str r0, [sp]` is the fifth
 * argument, i.e. the source line 0x39a.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_AllocRecordBuffer.c \
 *       --func BTL_SETUP_AllocRecordBuffer --addr 0x02013980 --cc 1.1p1 --thumb
 */
void BTL_SETUP_AllocRecordBuffer(struct BattleSetupParam *param, u32 heap)
{
    if (param->recordBuffer == 0) {
        param->recordBuffer = GFL_HEAP_Alloc(heap, 3 << 10, 0, sBtlSetupFileName, 0x39a);
    }
}
