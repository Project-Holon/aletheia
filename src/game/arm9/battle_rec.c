/*
 * file:     battle_rec.c
 * unit:     yes
 * function: func_0200B2A4, func_0200B348, func_0200B358, func_0200B364, func_0200B368, func_0200B37C, func_0200B394, func_0200B3A4, func_0200B3A8, func_0200B3AC, func_0200B3B0, func_0200B3C8, BATTLE_REC_Create, BATTLE_REC_AllocWork, BATTLE_REC_FreeWork, BATTLE_REC_Delete, BATTLE_REC_GetWorkSize, BATTLE_REC_Clear, BATTLE_REC_IsDataExist, BATTLE_REC_ClearWork, BATTLE_REC_DecodeWork, BATTLE_REC_EncodeWork, BATTLE_REC_LoadToWork, BATTLE_REC_Load, BATTLE_REC_LoadAlloc, BATTLE_REC_CheckSaved, BATTLE_REC_SaveSeq, func_0200B6E0, BATTLE_REC_GetModeLayout, BATTLE_REC_MakeHeader, BATTLE_REC_IsMagicBroken, BATTLE_REC_IsValid, BATTLE_REC_Decode, BATTLE_REC_Encode, BATTLE_REC_GetWork, BATTLE_REC_GetBody, BATTLE_REC_GetHeader, BATTLE_REC_GetHeaderOf, BATTLE_REC_SetData, BATTLE_REC_GetHeaderParam, BATTLE_REC_IsVersionSupported, BATTLE_REC_SetBodyCrc, BATTLE_REC_LoadToolOverlay, BATTLE_REC_UnloadToolOverlay, func_0200BA78, func_0200BA80, func_0200BAC8, func_0200BAD4, sub_0200BAF4, func_0200BB58, func_0200BBA8, func_0200BBC8, func_0200BBD8, func_0200BBEC, func_0200BBFC, func_0200BC10, func_0200BC20, func_0200BC2C, func_0200BC4C, func_0200BC88, func_0200BCA0, func_0200BCA8, func_0200BCB8, func_0200BCD8, func_0200BCEC, func_0200BD48, func_0200BD98, func_0200BDA0, func_0200BDB0, func_0200BDBC, func_0200BDC4, func_0200BDE4, func_0200BDF8, func_0200BDFC, func_0200BE00, func_0200BE24, func_0200BE48, func_0200BE54, func_0200BE6C, func_0200BE84, func_0200BF08, func_0200BF10, func_0200BF18, func_0200BF54, func_0200BF70, func_0200BF78, func_0200BF94, func_0200BFA4, func_0200C054, func_0200C058, func_0200C0E8, func_0200C0F0, func_0200C0FC, func_0200C104, func_0200C10C, func_0200C11C, func_0200C164, func_0200C184, func_0200C18C, func_0200C1A4, func_0200C1B0, func_0200C1C4, func_0200C1C8, func_0200C1DC, func_0200C1E0, func_0200C1F4, func_0200C1F8, func_0200C20C, func_0200C210, func_0200C224, func_0200C22C, func_0200C234, func_0200C248, func_0200C258, func_0200C274, func_0200C278, func_0200C29C, func_0200C2B0, func_0200C2D0, func_0200C2F0, func_0200C308, func_0200C31C, func_0200C324, func_0200C32C, func_0200C334, func_0200C33C, func_0200C344, func_0200C34C, func_0200C358, func_0200C364, func_0200C37C, func_0200C384, func_0200C38C, func_0200C39C, func_0200C3B0, func_0200C3B8, func_0200C3C0, func_0200C3E0, func_0200C3EC
 * address:  0x0200B2A4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0200B1F8   0x0200B1F8  thumb
 *   func_0201AA18   0x0201AA18  thumb
 *   func_0201AB28   0x0201AB28  thumb
 *   func_02017E1C   0x02017E1C  thumb
 *   func_0200B254   0x0200B254  thumb
 *   _BattleRecFileName  0x020A71C4  data
 *   func_020307B0   0x020307B0  arm
 *   pBattleRec   0x0214616C  data
 *   MIi_CpuClear32  0x02082A7C  arm
 *   func_0203F2FC   0x0203F2FC  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   MI_CpuFill8          0x02082BCC  arm
 *   func_0203F37C  0x0203F37C  arm
 *   func_0203F328  0x0203F328  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   BattleRecModeTable 0x0209DDCC data
 *   ov188_id       0x000000BC  data  a1
 *   func_02045B38  0x02045B38  arm
 *   MSGDATA_ReadUnits  0x02045F5C  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   INTRUDE_COMM_ResetOutcomes   0x021763BC  thumb
 *   GX_GetBankForLCDC  0x02045A98  arm
 *   func_0200864C  0x0200864C  thumb
 *   func_02008650  0x02008650  thumb
 *   func_02008654  0x02008654  thumb
 *   _ull_mul       0x0209C054  arm
 *   _PlayTimeLatch  0x02146170  data  a8
 *   func_02045EC0    0x02045EC0  arm
 *   STRBUF_ToChars    0x02045A38  arm
 *   STRBUF_Delete    0x02045808  arm
 *   SAVE_CONTROL_LoadExtraSave  0x0200725C  thumb
 *   POKE_TOOL_ClearBoxParam  0x02017550  thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   SAVE_CONTROL_LoadExtraSaveWithBuffer  0x020072CC  thumb
 *   GAME_DATA_PartSaveStart  0x02012E4C  thumb
 *   GAME_DATA_PartSaveMain  0x02012E7C  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   POKE_TOOL_CreateFromBoxParam  0x0201747C  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

/* Objects owned by other files; only pointers to them pass through here. */
struct SaveControl;
struct GameData;
struct Party;
struct MsgData;
struct StrBuf;
struct PlayTime;
struct RegulationParty;

/* A party Pokemon (0xDC bytes) and a boxed Pokemon (0x88 bytes).  Both are
 * declared as words: the copies of them are eight-byte stepped ldm/stm loops. */
struct PokeParam {
    u32 data[0x37];
};

struct BoxMon {
    u32 data[0x22];
};

/* Save block 0x2F: battle competition data (read by digitalcardcheck,
 * battle_championship_flow and wifibattlematch). */
struct BattleCompetitionSave {
    u8 data[0x2FC];
};

/* Save block 0x30: the field gimmick work.  The id says which gimmick owns the
 * two work areas; -1 is none. */
struct GimmickWork {
    s32 id;
    s32 work[32];
    u8  subWork[0x10];
};

/* Battle recorder.  The header is a 0x44-byte summary of the recorded battle
 * (shown in lists without decoding the body); the body holds the battle
 * setup and the four parties.  Both carry the magic BATTLE_REC_MAGIC and a
 * CRC. */
struct BattleRecHeader {
    u16 species[12];
    u8  formGender[12];     /* form in bits 0..6, gender in bit 7 */
    u16 battleCount;
    u16 mode;
    u16 magic;
    u8  secure;
    u8  version;
    u8  unusedBytes[0x0C];
    u64 dataNumber;
    u16 crc;
    u16 padding;
};

/* A compact Pokemon record inside the battle record body. */
struct BattleRecPoke {
    u32 personality;
    u16 fastMode : 2;
    u16 badEgg : 1;
    u16 unusedBits : 13;
    u16 species;
    u8  info[0x24];
    u32 ivs : 30;
    u32 isEgg : 1;
    u32 hasNickname : 1;
    u8  fatefulEncounter : 1;
    u8  gender : 2;
    u8  form : 5;
    u8  detail[0x3F];
};

struct BattleRecParty {
    struct BattleRecPoke poke[6];
    u32 count;
};

struct BattleRecBody {
    u8  setup[0xC3C];
    struct BattleRecParty party[4];
    u8  playerInfo[0x10C];
    u16 magic;
    u16 unusedHalf;
    u16 crc;
    u16 padding;
};

struct BattleRecSave {
    u8  profile[0x80];
    struct BattleRecHeader head;
    struct BattleRecBody body;
};

/* Save block 0x31: the Battle Box, six boxed Pokemon and the box name.
 * func_0200BBEC indexes the group array with a 0x330 stride. */
struct BoxMonGroup {
    struct BoxMon mon[6];
};

struct BattleBoxSave {
    struct BoxMonGroup group;
    u16 boxName[10];
    u8  unusedData[0x14];
    u16 lockFlags;
    u16 padding;
};

/* Save block 0x32: the day care, two slots and the egg flag. */
struct DaycareSlot {
    s32 inUse;
    struct PokeParam mon;
    u32 steps;
};

struct DaycareSave {
    struct DaycareSlot slot[2];
    u32 eggReady;
};

/* Save block 0x35: the Entralink (intrude) record. */
struct IntrudeOccupy {
    u8  info[0x0C];
    u16 missionScore;
    u16 missionBonusScore;
};

/* 19 bytes rounded to 20 by the two-byte alignment; memberIds[8] is the
 * free-slot marker. */
struct IntrudeLogEntry {
    u16 memberIds[9];
    u8  kind;
};

struct IntrudeSave {
    struct IntrudeOccupy occupy;
    struct IntrudeLogEntry log[20];
    u8  monolithLevel;
    u8  obtainedFlags[2];
    u8  padding;
    u32 missionClearCount;
    u64 playSeconds;
};

/* Save block 0x34: the C-Gear beacon record (greeting and thanks messages and
 * their counters, survey points, recent partners). */
struct BeaconSelect {
    u8 kind : 6;
    u8 enabled : 1;
    u8 isSingle : 1;
};

union BeaconTime {
    u64 value;
    struct {
        u32 lo;
        u32 hi;
    } half;
};

struct BeaconTeam {
    u16 species[6];
};

struct BeaconSave {
    u32 points;
    u32 flags;
    u16 selectId;
    struct BeaconSelect select;
    u8  padding;
    u8  inputFlags[8];
    u32 bestScore : 28;
    u32 rank : 4;
    u32 greetCount;
    u32 thanksCount;
    u16 greetMessage[9];
    u16 thanksMessage[9];
    u8  mode;
    u8  slotStates;         /* 2 bits per slot */
    u8  entryCount;
    u8  recentIds[3];
    u16 recentValues[3];
    union BeaconTime lastTime;
    struct BeaconTeam teams[8];
    u32 hashedIds[8];
    u32 unusedWord;
    u32 recorderFlag;
    /* stand-in: volatile keeps the two reads of func_0200C3C0 (compare, then
     * subtract); every ordinary spelling folds them into one load, and a
     * 16-bit bitfield changes the getter and setter. */
    volatile u16 gatePoints;
    u16 unusedHalf;
    u8  unusedTail[8];
};

#define BATTLE_REC_MAGIC 0xE281

extern void func_0200B1F8(struct RegulationParty *party);
extern void func_0200B254(struct RegulationParty *party, int field, u8 slot, s32 value);
extern u32 func_0201AA18(struct Party *party);
extern struct PokeParam *func_0201AB28(struct Party *party, u32 index);
extern u32 func_02017E1C(struct PokeParam *mon, u32 param, u32 arg);
extern u32 func_02017E88(struct BoxMon *mon, u32 param, u32 arg);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void MIi_CpuCopy32(const void *src, void *dest, u32 size);
extern void MIi_CpuClear32(u32 data, void *dest, u32 size);
extern void *func_020071CC(struct SaveControl *save, u32 blockId);
extern u32 SAVE_CONTROL_LoadExtraSave(struct SaveControl *save, u32 id, u32 heap);
extern void func_020072A4(struct SaveControl *save, u32 id);
extern u32 SAVE_CONTROL_LoadExtraSaveWithBuffer(struct SaveControl *save, u32 id, u32 heap, void *buf, u32 size);
extern void func_02007324(struct SaveControl *save, u32 id, u32 heap, void *buf, u32 size);
extern void func_0200734C(struct SaveControl *save, u32 id);
extern void *func_020073D8(struct SaveControl *save, u32 id, u32 arg);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *mem);
extern u32 func_0203F2FC(const u8 *data, u32 size);
extern u16 func_0203F1FC(const u8 *data, u32 size);
extern void func_0203F328(void *data, u32 size, u32 code);
extern void func_0203F37C(void *data, u32 size, u32 code);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern void GAME_DATA_PartSaveStart(struct GameData *gameData, u32 id);
extern int GAME_DATA_PartSaveMain(struct GameData *gameData, int id);
extern int func_02034AC4(u32 overlayId);
extern void func_02034A5C(u32 overlayId);
extern struct MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void MSGDATA_ReadUnits(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern u32 MSGDATA_Delete(struct MsgData *msg);
extern struct StrBuf *func_02045EC0(struct MsgData *msg, u32 msgIndex);
extern void STRBUF_ToChars(struct StrBuf *str, u16 *out, u32 maxLen);
extern void STRBUF_Delete(struct StrBuf *str);
extern void POKE_TOOL_ClearBoxParam(struct BoxMon *mon);
extern struct Party *func_0201A920(u32 heap);
extern void func_0201A954(struct Party *party, s32 capacity);
extern u32 func_0201A98C(struct Party *party, const struct PokeParam *mon);
extern struct BoxMon *POKE_TOOL_GetBoxParam(struct PokeParam *mon);
extern struct PokeParam *POKE_TOOL_CreateFromBoxParam(struct BoxMon *mon, u32 heap);
extern void INTRUDE_COMM_ResetOutcomes(struct IntrudeOccupy *occupy);
extern u16 GX_GetBankForLCDC(void);
extern u16 func_0200864C(const struct PlayTime *time);
extern u8 func_02008650(const struct PlayTime *time);
extern u8 func_02008654(const struct PlayTime *time);
void func_0200B2A4(struct RegulationParty *dest, struct Party *party);
void func_0200B348(struct BattleCompetitionSave *competition);
struct BattleCompetitionSave *func_0200B358(struct SaveControl *save);
u32 func_0200B364(void);
void func_0200B368(struct GimmickWork *gimmick);
void func_0200B37C(struct GimmickWork *gimmick);
s32 *func_0200B394(struct GimmickWork *gimmick, s32 id);
s32 *func_0200B3A4(struct GimmickWork *gimmick, u32 id);
u8 *func_0200B3A8(struct GimmickWork *gimmick, u32 id);
s32 func_0200B3AC(struct GimmickWork *gimmick);
void func_0200B3B0(const struct GimmickWork *src, struct SaveControl *save);
void func_0200B3C8(struct SaveControl *save, struct GimmickWork *dest);
struct BattleRecSave *BATTLE_REC_Create(u32 heap);
void BATTLE_REC_AllocWork(u32 heap);
void BATTLE_REC_FreeWork(void);
void BATTLE_REC_Delete(struct BattleRecSave *rec);
u32 BATTLE_REC_GetWorkSize(void);
void BATTLE_REC_Clear(struct BattleRecSave *rec);
u32 BATTLE_REC_IsDataExist(void);
void BATTLE_REC_ClearWork(void);
void BATTLE_REC_DecodeWork(void);
void BATTLE_REC_EncodeWork(void);
u32 BATTLE_REC_LoadToWork(struct SaveControl *save, struct BattleRecSave *rec, u32 heap, u32 *result, u32 id);
u32 BATTLE_REC_Load(struct SaveControl *save, u16 heap, u32 *result, u32 id);
struct BattleRecSave *BATTLE_REC_LoadAlloc(struct SaveControl *save, u32 heap, u32 *result, u32 id);
u32 BATTLE_REC_CheckSaved(struct SaveControl *save, u32 heap, u32 *result, u32 id);
u32 BATTLE_REC_SaveSeq(struct GameData *gameData, struct BattleRecSave *rec, u32 id, u16 *seq, u16 heap);
u32 func_0200B6E0(struct GameData *gameData, u16 heap, u32 modeIndex, u32 battleCount, u32 id, u16 *seq, u16 *subSeq);
void BATTLE_REC_GetModeLayout(u16 mode, s32 *sides, s32 *members);
void BATTLE_REC_MakeHeader(struct SaveControl *save, struct BattleRecHeader *head, const struct BattleRecBody *body, u32 modeIndex, u32 battleCount);
u32 BATTLE_REC_IsMagicBroken(struct SaveControl *save, struct BattleRecSave *rec);
u32 BATTLE_REC_IsValid(struct SaveControl *save, struct BattleRecSave *rec);
void BATTLE_REC_Decode(void *data, u32 size, u32 code);
void BATTLE_REC_Encode(void *data, u32 size, u32 code);
struct BattleRecSave *BATTLE_REC_GetWork(void);
struct BattleRecBody *BATTLE_REC_GetBody(void);
struct BattleRecHeader *BATTLE_REC_GetHeader(void);
struct BattleRecHeader *BATTLE_REC_GetHeaderOf(struct BattleRecSave *rec);
void BATTLE_REC_SetData(const void *profile, const struct BattleRecHeader *head, const struct BattleRecBody *body);
u64 BATTLE_REC_GetHeaderParam(const struct BattleRecHeader *head, int param, int index);
u32 BATTLE_REC_IsVersionSupported(u32 version);
void BATTLE_REC_SetBodyCrc(struct BattleRecBody *body);
void BATTLE_REC_LoadToolOverlay(void);
void BATTLE_REC_UnloadToolOverlay(void);
u32 func_0200BA78(void);
void func_0200BA80(struct BattleBoxSave *box);
struct BattleBoxSave *func_0200BAC8(struct SaveControl *save);
void func_0200BAD4(struct BoxMonGroup *groups, u32 group, u32 index, const struct BoxMon *src);
struct Party *sub_0200BAF4(struct BoxMonGroup *box, int heap);
void func_0200BB58(struct BoxMonGroup *box, struct Party *party);
u32 func_0200BBA8(struct BoxMonGroup *box);
void func_0200BBC8(struct BattleBoxSave *box, u32 flags);
void func_0200BBD8(struct BattleBoxSave *box, int flags);
struct BoxMon *func_0200BBEC(struct BoxMonGroup *groups, u32 group, u32 index);
u32 func_0200BBFC(struct BattleBoxSave *box, u32 flags);
void func_0200BC10(struct DaycareSave *daycare);
void func_0200BC20(struct DaycareSave *daycare);
struct PokeParam *func_0200BC2C(struct DaycareSave *daycare, s32 slot);
void func_0200BC4C(struct DaycareSave *daycare, s32 slot, const struct PokeParam *mon);
void func_0200BC88(struct DaycareSave *daycare, s32 slot);
u32 func_0200BCA0(struct DaycareSave *daycare);
u32 func_0200BCA8(struct DaycareSave *daycare, u32 slot);
u32 func_0200BCB8(struct DaycareSave *daycare);
u32 func_0200BCD8(struct DaycareSave *daycare, u32 slot);
void func_0200BCEC(struct DaycareSave *daycare, s32 slotA, s32 slotB);
void func_0200BD48(struct DaycareSlot *slots, u32 steps);
u32 func_0200BD98(void);
void func_0200BDA0(struct DaycareSave *daycare);
struct DaycareSave *func_0200BDB0(struct SaveControl *save);
u32 func_0200BDBC(void);
void func_0200BDC4(struct IntrudeSave *intrude);
void func_0200BDE4(struct IntrudeSave *intrude);
u16 func_0200BDF8(struct IntrudeSave *intrude);
u16 func_0200BDFC(struct IntrudeSave *intrude);
void func_0200BE00(struct IntrudeSave *intrude, s32 add);
void func_0200BE24(struct IntrudeSave *intrude, s32 add);
struct IntrudeSave *func_0200BE48(struct SaveControl *save);
void func_0200BE54(struct SaveControl *save, const u16 *src);
void func_0200BE6C(struct SaveControl *save, u16 *dest);
void func_0200BE84(struct IntrudeSave *intrude, struct IntrudeLogEntry *entry);
void func_0200BF08(struct IntrudeSave *intrude, u32 level);
u8 func_0200BF10(struct IntrudeSave *intrude);
void func_0200BF18(struct IntrudeSave *intrude, s32 id);
void func_0200BF54(struct IntrudeSave *intrude, u8 *dest, u32 size);
u32 func_0200BF70(struct IntrudeSave *intrude);
u32 func_0200BF78(struct IntrudeSave *intrude);
u64 func_0200BF94(struct IntrudeSave *intrude);
u64 func_0200BFA4(struct IntrudeSave *intrude, const struct PlayTime *time, u32 mode);
u32 func_0200C054(void);
void func_0200C058(struct BeaconSave *beacon);
struct BeaconSave *func_0200C0E8(struct SaveControl *save);
struct BeaconSave *func_0200C0F0(struct SaveControl *save);
void func_0200C0FC(struct BeaconSave *beacon, u32 index, u8 value);
u8 func_0200C104(struct BeaconSave *beacon, u32 index);
void func_0200C10C(struct BeaconSave *beacon);
void func_0200C11C(struct BeaconSave *beacon, u16 id, u32 kind, u32 enabled, u32 single);
void func_0200C164(const struct BeaconSave *beacon, u32 *id, u32 *kind, u32 *enabled, u32 *single);
u32 func_0200C184(struct BeaconSave *beacon);
void func_0200C18C(struct BeaconSave *beacon, u32 score);
u8 func_0200C1A4(struct BeaconSave *beacon);
void func_0200C1B0(struct BeaconSave *beacon, u32 rank);
u32 func_0200C1C4(struct BeaconSave *beacon);
u32 func_0200C1C8(struct BeaconSave *beacon);
u32 func_0200C1DC(struct BeaconSave *beacon);
u32 func_0200C1E0(struct BeaconSave *beacon);
u16 *func_0200C1F4(struct BeaconSave *beacon);
void func_0200C1F8(struct BeaconSave *beacon, struct StrBuf *message);
u16 *func_0200C20C(struct BeaconSave *beacon);
void func_0200C210(struct BeaconSave *beacon, struct StrBuf *message);
u8 func_0200C224(struct BeaconSave *beacon);
void func_0200C22C(struct BeaconSave *beacon, u8 mode);
u32 func_0200C234(struct BeaconSave *beacon, u32 bit);
void func_0200C248(struct BeaconSave *beacon, u32 bit);
u32 func_0200C258(struct BeaconSave *beacon);
u32 func_0200C274(struct BeaconSave *beacon);
u32 func_0200C278(struct BeaconSave *beacon, u32 add);
u32 func_0200C29C(struct BeaconSave *beacon, u32 sub);
void func_0200C2B0(struct BeaconSave *beacon, u32 index, const u16 *species);
void func_0200C2D0(struct BeaconSave *beacon, u32 index, u16 *species);
void func_0200C2F0(struct BeaconSave *beacon, u32 slot, u8 state);
u8 func_0200C308(struct BeaconSave *beacon, u32 slot);
u8 func_0200C31C(struct BeaconSave *beacon);
void func_0200C324(struct BeaconSave *beacon, u8 states);
u8 func_0200C32C(struct BeaconSave *beacon);
void func_0200C334(struct BeaconSave *beacon, u8 count);
int func_0200C33C(struct BeaconSave *beacon, u32 index);
void func_0200C344(struct BeaconSave *beacon, u8 index, u8 id);
u16 func_0200C34C(struct BeaconSave *beacon, u32 index);
void func_0200C358(struct BeaconSave *beacon, u32 index, int value);
void func_0200C364(struct BeaconSave *beacon, u8 index, int add);
u64 func_0200C37C(struct BeaconSave *beacon);
void func_0200C384(struct BeaconSave *beacon, u32 lo, u32 hi);
void func_0200C38C(struct BeaconSave *beacon, s32 index, u32 value);
u32 func_0200C39C(struct BeaconSave *beacon, s32 index);
u16 func_0200C3B0(struct BeaconSave *beacon);
void func_0200C3B8(struct BeaconSave *beacon, u16 points);
void func_0200C3C0(struct BeaconSave *beacon, u16 sub);
u8 func_0200C3E0(struct BeaconSave *beacon);
void func_0200C3EC(struct BeaconSave *beacon, u32 flag);
extern const char _BattleRecFileName[];
extern struct BattleRecSave *pBattleRec;
extern const u16 BattleRecModeTable[];
extern char ov188_id[];
extern u64 _PlayTimeLatch;










/*
 * Rebuild the four per-slot fields for every entry the accessor count reports;
 * the count is a call, so it is re-evaluated on the loop back-edge, and the
 * third argument of every accumulate call is truncated to u8.
 */
void func_0200B2A4(struct RegulationParty *dest, struct Party *party)
{
    int i;

    func_0200B1F8(dest);
    for (i = 0; i < (int)func_0201AA18(party); i++) {
        struct PokeParam *mon = func_0201AB28(party, i);

        if (func_02017E1C(mon, 0xa9, 0) != 0) {
            func_0200B254(dest, 0, i, func_02017E1C(mon, 5, 0));
            func_0200B254(dest, 1, i, func_02017E1C(mon, 0x6f, 0));
            func_0200B254(dest, 2, i, func_02017E1C(mon, 6, 0) != 0);
            func_0200B254(dest, 3, i, func_02017E1C(mon, 0x6e, 0));
        }
    }
}










/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 52 bytes, 0x0200B348..0x0200B37C, 4 functions, none of which carries a
 * label in the generated listing.
 *
 * func_0200B364 returns 0x94 and func_0200B368 clears 0x94 bytes and then
 * writes -1 into the first word, which is the "a block file opens with a
 * function returning its own size, and the constructor clears exactly that"
 * shape this range keeps producing.  The -1 is free: the compiler already
 * has 0x94 in a register for the fill and reaches -1 with `subs r4, #0x95`.
 *
 * This unit starts at 0x0200B348 rather than at the end of
 * src/matched/unit_0200ADB8.c because of a near miss between them:
 * func_0200B2A4, 162 bytes, which walks a list and pushes four fields of each
 * entry into the record through func_0200B254.  Every instruction is
 * reproduced and the size is right; what differs is that the original keeps
 * the constant 0 alive in r7 for the whole loop (it gets there as a copy of
 * the loop counter's initial value) and therefore rematerialises `(u8)i`
 * before each of the four calls, where this source has one register less in
 * play, common-subexpression-eliminates `(u8)i` into r5 and rematerialises
 * the 0 instead.  The two are the same eighteen instructions per iteration in
 * a different order with every register renumbered.
 *
 * This unit stops at 0x0200B37C because of a near miss there; see
 * src/matched/unit_0200B394.c for what it is.
 */
void func_0200B348(struct BattleCompetitionSave *competition)
{
    MI_CpuFill8(competition, 0, sizeof(struct BattleCompetitionSave));
}










struct BattleCompetitionSave *func_0200B358(struct SaveControl *save)
{
    return func_020071CC(save, 0x2F);
}










u32 func_0200B364(void)
{
    return sizeof(struct GimmickWork);
}










void func_0200B368(struct GimmickWork *gimmick)
{
    MI_CpuFill8(gimmick, 0, sizeof(struct GimmickWork));
    gimmick->id = -1;
}









void func_0200B37C(struct GimmickWork *gimmick)
{
    int i;
    gimmick->id = -1;
    for (i = 0; i < 32; i++) {
        gimmick->work[i] = 0;
    }
}









/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200B3B0, func_0200B3C8, BATTLE_REC_Create
 *
 * 108 bytes, 0x0200B394..0x0200B400, 7 functions, four of which carry no
 * label in the generated listing.
 *
 * alias: 0x020A71C4 spells "battle_rec.c", the third original source file
 * name recovered by this project, attested by the `string` class off the
 * terminator of "regulation.c" at 0x020A71C2.  The constructor at 0x0200B3DC
 * allocates 0x2000 bytes at line 0x67 and hands them to BATTLE_REC_Clear, which
 * is the first function of the next packet.
 *
 * Near miss, and the reason this unit starts at 0x0200B394 rather than
 * 0x0200B37C: func_0200B37C, 24 bytes, which writes -1 into the first word
 * and then fills a 32-entry array with 0..31.  The original carries one more
 * instruction than any spelling tried here, an `adds r2, r3, #0` that copies
 * the loop counter before the body and lets the increment be scheduled ahead
 * of the store, and it initialises the counter before the -1 store rather
 * than after.  Five loop spellings (for, while, do/while, a separate value
 * variable, a hoisted array pointer) all produce the same eleven
 * instructions in the other order, so the difference is a register the
 * original had a reason to spend and this source does not give it.  Nineteen
 * bytes differ and the size is right to the padding.
 */
s32 *func_0200B394(struct GimmickWork *gimmick, s32 id)
{
    func_0200B37C(gimmick);
    gimmick->id = id;
    return gimmick->work;
}








s32 *func_0200B3A4(struct GimmickWork *gimmick, u32 id)
{
    return gimmick->work;
}








u8 *func_0200B3A8(struct GimmickWork *gimmick, u32 id)
{
    return gimmick->subWork;
}








s32 func_0200B3AC(struct GimmickWork *gimmick)
{
    return gimmick->id;
}








void func_0200B3B0(const struct GimmickWork *src, struct SaveControl *save)
{
    MIi_CpuCopy32(src, func_020071CC(save, 0x30), sizeof(struct GimmickWork));
}








void func_0200B3C8(struct SaveControl *save, struct GimmickWork *dest)
{
    MIi_CpuCopy32(func_020071CC(save, 0x30), dest, sizeof(struct GimmickWork));
}








struct BattleRecSave *BATTLE_REC_Create(u32 heap)
{
    struct BattleRecSave *rec = func_02030734(heap, 0x2000, 1, _BattleRecFileName, 0x67);

    BATTLE_REC_Clear(rec);
    return rec;
}









/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 72 bytes, 0x0200B400..0x0200B448, 4 functions, three of which carry no
 * label in the generated listing: the last three save nothing or nothing but
 * r4, so the range arrives as a run of `.word`s.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * alias: this continues "battle_rec.c", whose constructor BATTLE_REC_Create is
 * the last function of src/matched/unit_0200B394.c and is what BATTLE_REC_AllocWork
 * calls.  The object it builds is hung off the single global at 0x0214616C,
 * the same one src/matched/unit_0200B900.c reads.
 *
 * BATTLE_REC_AllocWork frees the old object before building the new one and clears
 * the global in between, which is a guard the source wrote rather than dead
 * code: the store of NULL is inside the `if`, and the fresh pointer is
 * assigned unconditionally afterwards.  The address of the global is
 * materialised twice, once for the test and free and once for the final
 * store, because the pool word is reloaded after the call rather than kept
 * in the callee-saved register that already holds it.
 *
 * BATTLE_REC_GetWorkSize returns 0x18A4 out of its own pool word, which is the
 * "a block file opens with a function returning its own size" shape this
 * region keeps producing, except that here the size belongs to whatever the
 * next file allocates rather than to the 0x2000 buffer above it.
 */
void BATTLE_REC_AllocWork(u32 heap)
{
    if (pBattleRec != 0) {
        func_020307B0(pBattleRec);
        pBattleRec = 0;
    }
    pBattleRec = BATTLE_REC_Create(heap);
}









void BATTLE_REC_FreeWork(void)
{
    func_020307B0(pBattleRec);
    pBattleRec = 0;
}









void BATTLE_REC_Delete(struct BattleRecSave *rec)
{
    func_020307B0(rec);
}









u32 BATTLE_REC_GetWorkSize(void)
{
    return sizeof(struct BattleRecSave);
}









/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           BATTLE_REC_EncodeWork
 *
 * 152 bytes, 0x0200B448..0x0200B4E0, 5 functions, three of which carry no
 * label in the generated listing.
 *
 * alias: this continues "battle_rec.c"; BATTLE_REC_Clear is the buffer clear the
 * constructor BATTLE_REC_Create calls, and the object is the 0x18A4-byte record
 * at 0x0214616C that src/matched/unit_0200B400.c allocates and
 * src/matched/unit_0200B938.c publishes.
 *
 * Two things are worth recording.
 *
 *  - BATTLE_REC_DecodeWork and BATTLE_REC_EncodeWork are the same four instructions of
 *    checksum arithmetic as BATTLE_REC_SetData, but as **tail calls**, and that
 *    changes the callee's arity.  A tail call needs r3 for the branch target,
 *    so the fourth argument BATTLE_REC_SetData passes cannot be passed here: the
 *    `ldrh r3` that loads the halfword is overwritten by the `ldr r3, [pc]`
 *    that loads BATTLE_REC_Decode's address.  The callee is therefore declared
 *    with three parameters in this file and with four in
 *    src/matched/unit_0200B900.c, and both are right, because nothing in
 *    BATTLE_REC_Decode reads its arguments.  A four-argument call here compiles
 *    to `push {r3, lr}` / `bl` / `pop` and is eight bytes longer.
 *  - the length 0x17DC is reached as `subs r1, #0xc4` off the 0x18A0 the
 *    halfword load already needed, and 0x18A0 itself is a pool word rather
 *    than a `movs`, so the file spends one pool word where BATTLE_REC_SetData
 *    spends none for the same value.  That is a consequence of the tail call
 *    having no register to spare, not of the source.
 */
void BATTLE_REC_Clear(struct BattleRecSave *rec)
{
    MIi_CpuClear32(0, rec, sizeof(struct BattleRecSave));
}








u32 BATTLE_REC_IsDataExist(void)
{
    if (func_0203F2FC((const u8 *)(&pBattleRec->body), sizeof(pBattleRec->body))
        != 0) {
        return 1;
    }
    return 0;
}









void BATTLE_REC_ClearWork(void)
{
    BATTLE_REC_Clear(pBattleRec);
}









void BATTLE_REC_DecodeWork(void)
{
    u16 crc = pBattleRec->body.crc;

    BATTLE_REC_Decode(&pBattleRec->body, 0x17DC, crc + ((crc ^ 0xFFFF) << 16));
}









void BATTLE_REC_EncodeWork(void)
{
    u16 crc = pBattleRec->body.crc;

    BATTLE_REC_Encode(&pBattleRec->body, 0x17DC, crc + ((crc ^ 0xFFFF) << 16));
}









/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 236 bytes, 0x0200B4E0..0x0200B5CC, 3 functions, all three of which carry a
 * label in the generated listing.
 *
 * alias: inside "battle_rec.c"; see src/matched/unit_0200B394.c for how the
 * name at 0x020A71C4 is attested and src/matched/unit_0200B448.c for the
 * 0x18A4-byte record these work on.
 *
 * BATTLE_REC_LoadToWork loads a saved battle record and classifies the result into
 * the caller's status word: 0 when the block is absent, 3 when the load
 * failed, 0 again when the record's own check rejects it, 2 when the second
 * check does, and 1 when it is good.  Every arm writes the status and returns
 * 1, and the last arm shares its `movs r0, #1` between the store and the
 * return, which is the compiler reusing one constant and not two statements.
 *
 * The address of the checksummed sub-record is a named local, not
 * `&rec->body` written out at each of the three uses: with the local the base
 * is formed once as `adds r0, #0xc4` and the field offset 0x17DC is the
 * register operand, and written inline the compiler folds 0xC4 + 0x17DC into
 * one pool word of 0x18A0 and then subtracts 0xC4 back off it, which is two
 * instructions more.
 *
 * This range stops at 0x0200B5CC and src/matched/unit_0200B5CC.c starts
 * there, because BATTLE_REC_IsMagicBroken and BATTLE_REC_IsValid are each called exactly
 * twice in the image, once from BATTLE_REC_LoadToWork and once from BATTLE_REC_CheckSaved;
 * one range holding both pairs has no witness left for either and caps at
 * MATCH with every byte right.  Cut between them, each file is the other's
 * witness.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md. *
 */
u32 BATTLE_REC_LoadToWork(struct SaveControl *save, struct BattleRecSave *rec, u32 heap, u32 *result, u32 id)
{
    struct BattleRecBody *body;
    u16 crc;

    *result = SAVE_CONTROL_LoadExtraSaveWithBuffer(save, id, heap, rec, 0x2000);
    func_020072A4(save, id);
    if (*result == 0) {
        *result = 0;
        return 1;
    }
    if (*result != 1) {
        *result = 3;
        return 1;
    }
    body = &rec->body;
    crc = body->crc;
    BATTLE_REC_Decode(body, 0x17DC, crc + ((crc ^ 0xFFFF) << 16));
    if (BATTLE_REC_IsMagicBroken(save, rec) == 1) {
        *result = 0;
        return 1;
    }
    if (BATTLE_REC_IsValid(save, rec) == 0) {
        *result = 2;
        return 1;
    }
    *result = 1;
    return 1;
}








u32 BATTLE_REC_Load(struct SaveControl *save, u16 heap, u32 *result, u32 id)
{
    if (pBattleRec != 0) {
        BATTLE_REC_Clear(pBattleRec);
    } else {
        BATTLE_REC_AllocWork(heap);
    }
    return BATTLE_REC_LoadToWork(save, pBattleRec, heap, result, id);
}








struct BattleRecSave *BATTLE_REC_LoadAlloc(struct SaveControl *save, u32 heap, u32 *result, u32 id)
{
    struct BattleRecSave *rec = BATTLE_REC_Create(heap);

    BATTLE_REC_LoadToWork(save, rec, heap, result, id);
    return rec;
}







/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 176 bytes, 0x0200B5CC..0x0200B67C, one function, which carries a label in
 * the generated listing.
 *
 * alias: inside "battle_rec.c".  The same classification BATTLE_REC_LoadToWork does,
 * over a record the save system already holds rather than one just read, and
 * with a `func_020072A4` release on every path instead of only on entry.  See
 * src/matched/unit_0200B4E0.c for why the two are separate files. *
 */
u32 BATTLE_REC_CheckSaved(struct SaveControl *save, u32 heap, u32 *result, u32 id)
{
    struct BattleRecSave *rec;
    struct BattleRecBody *body;
    u16 crc;

    *result = SAVE_CONTROL_LoadExtraSave(save, id, heap);
    rec = func_020073D8(save, id, 0);
    if (*result == 0) {
        *result = 0;
        func_020072A4(save, id);
        return 0;
    }
    if (*result != 1) {
        *result = 3;
        func_020072A4(save, id);
        return 0;
    }
    body = &rec->body;
    crc = body->crc;
    BATTLE_REC_Decode(body, 0x17DC, crc + ((crc ^ 0xFFFF) << 16));
    if (BATTLE_REC_IsMagicBroken(save, rec) == 1) {
        *result = 0;
        func_020072A4(save, id);
        return 0;
    }
    if (BATTLE_REC_IsValid(save, rec) == 0) {
        *result = 2;
        func_020072A4(save, id);
        return 0;
    }
    *result = 1;
    func_020072A4(save, id);
    return 1;
}






/*
 * 264 bytes, 0x0200B67C..0x0200B784, 2 functions, both labelled.  Every
 * concrete byte reproduces.
 *
 * What held it open, and what closed it.  Two call targets have exactly one
 * caller in the whole image and that caller is here:
 *
 *   0x02007324  reached only from 0x0200B6A6, inside BATTLE_REC_SaveSeq
 *   0x0200B7D8  reached only from 0x0200B71A, inside func_0200B6E0
 *
 * Shrinking the range to one function keeps the call that needs the witness in
 * it, which is the limit `docs/MATCHING.md` states for the cut remedy, so no
 * image class could carry either site.  Both are now `matched`:
 * 0x02007324 is src/matched/unit_02007324.c and 0x0200B7D8 is
 * src/matched/unit_0200B7D8.c, two EXACT entries proved byte for byte against
 * the original over ranges this file does not touch.  Pulling either function
 * across the boundary into this range is no longer needed, and would have been
 * wrong anyway: the two belong to different original files.
 *
 * alias: inside "battle_rec.c"; the two steps of the record-save state machine
 * that BATTLE_REC_LoadToWork and BATTLE_REC_CheckSaved read back.
 *
 * Three things cost time here.
 *
 *  - GAME_DATA_GetSaveControl is declared with **one** parameter, not four.  The call
 *    leaves r1 through r3 holding this function's own second, third and fourth
 *    arguments, which reads like a four-argument call and is not one: declaring
 *    four parameters keeps `b` live from the entry and the whole of
 *    func_0200B6E0's case 0 is then allocated the other way round, with the two
 *    sub-record pointers sharing registers with `b` instead of with `a`.  Seven
 *    bytes, and none of them in the arithmetic.  src/matched/unit_0200C9EC.c
 *    declares the same extern with one parameter.
 *  - inside case 0 the two sub-record pointers have to be assigned
 *    `head = &rec->head;` first and `body = &rec->body;` second.  The second
 *    assignment is the last use of `rec`, so it takes over `rec`'s register and the first one
 *    gets the copy; writing them the other way round swaps which of the two is
 *    the `adds rD, rP, #0` and is five bytes.
 *  - the state word is read with `switch (*state)` over the constants 0 and 1,
 *    which is the `cmp #0` / `beq` / `cmp #1` / `beq` / `b` chain the original
 *    has; an `if` / `else if` inverts the first test.
 */
u32 BATTLE_REC_SaveSeq(struct GameData *gameData, struct BattleRecSave *rec, u32 id, u16 *seq, u16 heap)
{
    struct SaveControl *save = GAME_DATA_GetSaveControl(gameData);
    u32 result;

    switch (*seq) {
    case 0:
        func_02007324(save, id, heap, pBattleRec, 0x2000);
        GAME_DATA_PartSaveStart(gameData, id);
        (*seq)++;
        break;
    case 1:
        result = GAME_DATA_PartSaveMain(gameData, id);
        if (result == 2 || result == 3) {
            func_0200734C(save, id);
            return result;
        }
        break;
    }
    return 0;
}






u32 func_0200B6E0(struct GameData *gameData, u16 heap, u32 modeIndex, u32 battleCount, u32 id, u16 *seq, u16 *subSeq)
{
    struct SaveControl *save;
    struct BattleRecSave *rec;
    struct BattleRecHeader *head;
    struct BattleRecBody *body;
    u16 crc;

    save = GAME_DATA_GetSaveControl(gameData);

    switch (*seq) {
    case 0:
        rec = pBattleRec;
        if (rec == 0) {
            return 3;
        }
        head = &rec->head;
        body = &rec->body;
        BATTLE_REC_MakeHeader(save, head, body, modeIndex, battleCount);
        head->magic = BATTLE_REC_MAGIC;
        head->crc = func_0203F1FC((const u8 *)head, 0x38);
        body->magic = BATTLE_REC_MAGIC;
        BATTLE_REC_SetBodyCrc(body);
        crc = body->crc;
        BATTLE_REC_Encode(body, 0x17DC, crc + ((crc ^ 0xFFFF) << 16));
        *subSeq = 0;
        (*seq)++;
        break;
    case 1:
        return BATTLE_REC_SaveSeq(gameData, pBattleRec, id, subSeq, heap);
    }
    return 0;
}







/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 84 bytes, 0x0200B784..0x0200B7D8, one function, which carries a label in the
 * generated listing.
 *
 * alias: inside "battle_rec.c"; the team-layout lookup the record builder at
 * 0x0200B7D8 calls.  It walks a 0x29-entry `u16` table of mode ids at
 * 0x0209DDCC, and the indices 0x10..0x13 and 0x16 are the multi
 * battle modes, which get four sides of three; everything else gets two sides
 * of six.  Indices 0x14 and 0x15 fall back into the search rather than
 * answering, which is the pair of exit-valued entries in the jump table.
 *
 * The switch is written with `case 0x14:` and `case 0x15:` as empty arms even
 * though they do nothing, because without them the labels the compiler sees
 * are not dense and it emits a compare chain instead of the seven-entry
 * `.hword` table the original has.  See
 * docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *
 * This is a file of its own rather than part of the range that follows it
 * because 0x0209DDCC is named by exactly two literal pool words in the whole
 * image, this function's and BATTLE_REC_MakeHeader's, so a range holding both has no
 * witness left.  Cut between them and this one is attested by the other's
 * pool word.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.  The cut
 * does not save BATTLE_REC_MakeHeader, which is the only caller of this function and
 * therefore cannot be split away from it and attested at the same time; it is
 * parked in src/pending/unit_0200B7D8.c.
 */
void BATTLE_REC_GetModeLayout(u16 mode, s32 *sides, s32 *members)
{
    s32 i;

    for (i = 0; i < 0x29; i++) {
        if (mode == BattleRecModeTable[i]) {
            switch (i) {
            case 0x10:
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x16:
                *sides = 4;
                *members = 3;
                return;
            case 0x14:
            case 0x15:
                break;
            }
        }
    }
    *sides = 2;
    *members = 6;
}







/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 176 bytes, 0x0200B7D8..0x0200B888, one function, which carries a label in
 * the generated listing.
 *
 * alias: inside "battle_rec.c".  It builds the 0x44-byte battle header out of
 * the party records that live at +0xC3C of the 0x17E0-byte second half of the
 * record.  The layout, four sides of three or two of six, comes from
 * BATTLE_REC_GetModeLayout, and the group stride 0x2A4 is six 0x70-byte entries plus a
 * word.  An entry is skipped when either of two bits is set, and those two
 * bitfield reads are the only evidence in the image for those field widths.
 *
 * The destination byte packs a five bit field into the low seven bits and a
 * two bit field at bit 7, where only one of the two bits survives the `strb`.
 * That truncation is in the original and is reproduced rather than corrected;
 * the explicit `& 0x7F` on a field that is already five bits wide is what puts
 * the `movs r1, #0x7f` / `ands` pair there, and dropping it loses four bytes.
 *
 * This range starts at 0x0200B7D8 rather than at BATTLE_REC_GetModeLayout, which is its
 * only caller, because 0x0209DDCC is named by exactly two literal pool words
 * in the whole image: this function's at 0x0200B880 and BATTLE_REC_GetModeLayout's at
 * 0x0200B7D4.  One range holding both has no witness for the table at all.
 * Cut between them and each pool word attests the other file.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.  The call
 * to BATTLE_REC_GetModeLayout survives the cut because three overlay branches reach that
 * address from outside this region.
 */
void BATTLE_REC_MakeHeader(struct SaveControl *save, struct BattleRecHeader *head, const struct BattleRecBody *body, u32 modeIndex,
                   u32 battleCount)
{
    s32 nsides;
    s32 nmembers;
    u16 mode;
    s32 side;
    s32 member;
    s32 slot;

    slot = 0;
    MI_CpuFill8(head, 0, sizeof(struct BattleRecHeader));
    mode = BattleRecModeTable[modeIndex];
    BATTLE_REC_GetModeLayout(mode, &nsides, &nmembers);
    for (side = 0; side < nsides; side++) {
        for (member = 0; member < nmembers; member++) {
            const struct BattleRecPoke *poke = &body->party[side].poke[member];

            if (poke->isEgg == 0 && poke->badEgg == 0) {
                head->species[slot] = poke->species;
                head->formGender[slot] = (u8)((poke->form & 0x7F) | (poke->gender << 7));
            }
            slot++;
        }
    }
    head->battleCount = battleCount;
    head->mode = mode;
    head->version = 100;
}







/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 120 bytes, 0x0200B888..0x0200B900, 2 functions, both of which carry a label
 * in the generated listing.
 *
 * alias: inside "battle_rec.c"; the two validity checks src/matched/
 * unit_0200B4E0.c and unit_0200B5CC.c run over a loaded record, and the reason
 * those two are separate files.
 *
 * 0xE281 is the record's magic, stamped into both halves by func_0200B6E0 and
 * into the 0x44-byte header's +0x28 by BATTLE_REC_SetData.  BATTLE_REC_IsMagicBroken answers
 * "this record is NOT stamped", so its result is 1 on failure; BATTLE_REC_IsValid
 * answers "this record is whole", checking the magic in both halves and then
 * both checksums.
 *
 * Both take a first parameter they never read.  BATTLE_REC_IsMagicBroken reaches the
 * 0x17D8 field of the second half as one folded offset 0x189C off the record
 * pointer, because the source names the field through the record rather than
 * through a local, while BATTLE_REC_IsValid needs a local for the sub-record and so
 * carries 0x17D8 in a register instead; the difference is two instructions and
 * is a statement about the source rather than about the value.
 *
 * The two checksum comparisons each bind the call result to a local before
 * comparing, which is what puts it in `cmp`'s left slot; written inline the
 * operand order flips and the entry is two bytes out.  See
 * docs/idioms/cmp-operand-order-names-the-temporary.md.
 */
u32 BATTLE_REC_IsMagicBroken(struct SaveControl *save, struct BattleRecSave *rec)
{
    struct BattleRecHeader *head = &rec->head;

    if (rec->body.magic != BATTLE_REC_MAGIC || head->magic != BATTLE_REC_MAGIC) {
        return 1;
    }
    return 0;
}






u32 BATTLE_REC_IsValid(struct SaveControl *save, struct BattleRecSave *rec)
{
    struct BattleRecBody *body = &rec->body;
    struct BattleRecHeader *head = &rec->head;
    u16 crc;

    if (body->magic != BATTLE_REC_MAGIC || head->magic != BATTLE_REC_MAGIC) {
        return 0;
    }
    crc = func_0203F1FC((const u8 *)head, 0x38);
    if (crc != head->crc) {
        return 0;
    }
    crc = func_0203F1FC((const u8 *)body, 0x17DC);
    if (crc == body->crc) {
        return 1;
    }
    return 0;
}







/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           BATTLE_REC_GetHeader, BATTLE_REC_GetHeaderOf
 *
 * 56 bytes, 0x0200B900..0x0200B938, 6 functions, none of which carries a
 * label in the generated listing.
 *
 * Four accessors on the single object whose address lives at 0x0214616C and
 * two forwarders to a pair of ARM routines.  The three pool words holding
 * 0x0214616C inside this range are not its only ones: seven literal pools in
 * the image hold that address, so the `literal` class keeps a witness outside
 * whatever is compared.
 *
 * The two forwarders are written with their parameters declared and **not**
 * passed on, and that is a property of the codegen rather than a claim about
 * the callees.  This front end only emits the pool-word tail call
 * `ldr r3, [pc, #0]; bx r3` when there is no argument register to set up; a
 * call that names its arguments, even when every one of them is already in
 * the right register, comes out as `push {r3, lr}; blx; pop {r3, pc}`, which
 * is four instructions and eight bytes wrong.  The callers do pass four
 * arguments through BATTLE_REC_Decode (BATTLE_REC_SetData sets r0 through r3 before
 * the `bl`), so the forwarding is real and is simply not expressible here.
 * See docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 */
void BATTLE_REC_Decode(void *data, u32 size, u32 code)
{
    func_0203F37C(data, size, code);
}







void BATTLE_REC_Encode(void *data, u32 size, u32 code)
{
    func_0203F328(data, size, code);
}







struct BattleRecSave *BATTLE_REC_GetWork(void)
{
    return pBattleRec;
}







struct BattleRecBody *BATTLE_REC_GetBody(void)
{
    return &pBattleRec->body;
}







struct BattleRecHeader *BATTLE_REC_GetHeader(void)
{
    return &pBattleRec->head;
}







struct BattleRecHeader *BATTLE_REC_GetHeaderOf(struct BattleRecSave *rec)
{
    return &rec->head;
}






/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 84 bytes, 0x0200B938..0x0200B98C, one function, which carries a label in
 * the generated listing.
 *
 * The publisher of the battle record: three copies into the single object at
 * 0x0214616C and then a checksum word handed to BATTLE_REC_Decode.  The object is
 * 0x18A4 bytes, which is what BATTLE_REC_GetWorkSize in src/matched/unit_0200B400.c
 * returns, so the record is pinned from both ends: 0x80 + 0x44 + 0x17E0 is
 * exactly 0x18A4.
 *
 * The word handed over is `v + ((v ^ 0xFFFF) << 16)`, spelled with `+` and
 * not with `|`: the two halves cannot overlap and this compiler emits `adds`
 * for the one and `orrs` for the other.  The length 0x17DC is rematerialised
 * as `subs r1, r6, #4` off the 0x17E0 that is still live from the second
 * copy, which is the compiler reusing a value rather than a second constant
 * in the source.
 *
 * The range stops at 0x0200B98C because of a near miss there; see
 * src/matched/unit_0200BA38.c. *
 */
void BATTLE_REC_SetData(const void *profile, const struct BattleRecHeader *head, const struct BattleRecBody *body)
{
    u16 crc;

    MI_CpuCopy8(head, &pBattleRec->head, sizeof(pBattleRec->head));
    MI_CpuCopy8(body, &pBattleRec->body, sizeof(pBattleRec->body));
    MI_CpuCopy8(profile, pBattleRec->profile, sizeof(pBattleRec->profile));
    crc = pBattleRec->body.crc;
    BATTLE_REC_Decode(&pBattleRec->body, 0x17DC, crc + ((crc ^ 0xFFFF) << 16));
}






/*
 * A record field getter: selector picks the field, the result is 64-bit.
 * Callers: ov183 0x021DD228, 0x021DD25C, 0x021DEE7C, 0x021DF838 and others.
 */
u64 BATTLE_REC_GetHeaderParam(const struct BattleRecHeader *head, int param, int index)
{
    int i;
    u16 value;
    switch (param) {
    case 0:
        value = head->species[index];
        if (value > 0x289)
            return 0;
        return value;
    case 1:
        return head->formGender[index] & 0x7f;
    case 2:
        value = head->battleCount;
        if (value > 9999)
            return 9999;
        return value;
    case 3:
        for (i = 0; i < 41; i++) {
            if (head->mode == BattleRecModeTable[i])
                return i;
        }
        return 0;
    case 4:
        return head->dataNumber;
    case 5:
        return head->secure;
    case 6:
        return (head->formGender[index] & 0x80) >> 7;
    case 7:
        return head->version;
    }
    return 0;
}





/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 32 bytes, 0x0200BA38..0x0200BA58, 2 functions, one of which carries a
 * label in the generated listing.
 *
 * BATTLE_REC_SetBodyCrc stamps the record's own checksum into its last halfword, and
 * 0x17DC is both the length checksummed and the store's offset, so the
 * compiler holds it in one register and the store is a register-offset
 * `strh`; 0x17DC is far past the 62-byte reach of the immediate form anyway.
 *
 * Near miss, and the reason this range starts at 0x0200BA38: BATTLE_REC_GetHeaderParam,
 * 172 bytes, an eight-case dispatcher returning `long long`.  Every case, the
 * jump table and the three pool words reproduce; what does not is one
 * instruction in the `case 3` table search.  The original keeps the loop
 * index in r2 and copies it into r0 to return it (`adds r0, r2, #0`), where
 * every spelling tried here allocates the index to r0 directly and drops the
 * copy, which is two bytes short and moves the four later table entries.
 * Nine shapes were compiled and ranked: the table as a named `const u16 *`
 * local declared before and after the compared value, the comparison in both
 * operand orders, `while` against `for`, a `continue` form, the index at
 * function scope and at case scope, and the compared field as `u16` and
 * `u32`.  All nine are 168 bytes against the original's 172 and the ranking
 * is flat, so the missing copy is not reachable from the source shape.  Same
 * class as the near misses at 0x0200B2A4 and 0x0200B37C.
 *
 * Near miss, and the reason this range stops at 0x0200BA58: BATTLE_REC_LoadToolOverlay and
 * BATTLE_REC_UnloadToolOverlay, eight bytes of tail call each.  Both reproduce every
 * instruction but hold their argument in a pool word rather than in a `movs`,
 * and 0xBC fits a `movs` immediate, so the argument cannot be an integer
 * literal.  Both are now matched on their own: src/matched/arm9/
 * BATTLE_REC_LoadToolOverlay.c and BATTLE_REC_UnloadToolOverlay.c. *
 */
u32 BATTLE_REC_IsVersionSupported(u32 version)
{
    if (version <= 100) {
        return 1;
    }
    return 0;
}





void BATTLE_REC_SetBodyCrc(struct BattleRecBody *body)
{
    body->crc = func_0203F1FC((const u8 *)body, 0x17DC);
}



/*
 * Loads overlay 188 (0xBC): a Thumb tail call to the ARM loader through
 * `ldr r3; bx r3`.  The id is a pool word, so it is the overlay-id symbol,
 * not an integer literal (0xBC would fit a movs).  Filed as the call witness
 * for the ov021 script dispatcher 0x021CA5C4 (also unblocks the pending
 * ov187 0x0220B164 and ov199 0x022132C4).
 */
void BATTLE_REC_LoadToolOverlay(void)
{
    func_02034AC4((u32)ov188_id);
}



/*
 * Unloads overlay 188 (0xBC), the pair of BATTLE_REC_LoadToolOverlay: a Thumb tail call
 * to the ARM unloader through `ldr r3; bx r3`, the id as the overlay-id
 * symbol.  Filed as the call witness for the ov021 script dispatcher
 * 0x021CA5C4 (also unblocks the pending ov187 0x0220B164 and ov199
 * 0x022132C4).
 */
void BATTLE_REC_UnloadToolOverlay(void)
{
    func_02034A5C((u32)ov188_id);
}





/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 80 bytes, 0x0200BA78..0x0200BAC8, 2 functions, one of which carries a
 * label in the generated listing.
 *
 * The size getter and the constructor of a 0x35C-byte record: six 0x88-byte
 * entries, then 0x14 bytes at +0x330 that a resource read fills.  The two
 * agree, which is what pins the entry size: 6 * 0x88 is 0x330.
 *
 * The entry is declared as an array of words rather than of bytes, because
 * func_0200BAD4 in src/matched/unit_0200BAD4.c copies one with an eight-byte
 * stepped `ldm`/`stm` loop; a one-aligned declaration gives a byte loop
 * instead.  See docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md.
 *
 * The range stops at 0x0200BAC8 because of func_0200BAC8, an eight-byte tail
 * call whose pool word names 0x020271CC and which nothing else in the image
 * branches to or holds a pointer to, so the `label` and `literal` classes are
 * both empty and no cut helps.  It is now matched on its own, as are the
 * other two: src/matched/arm9/func_0200BAC8.c, BATTLE_REC_LoadToolOverlay.c and
 * BATTLE_REC_UnloadToolOverlay.c. *
 */
u32 func_0200BA78(void)
{
    return sizeof(struct BattleBoxSave);
}





void func_0200BA80(struct BattleBoxSave *box)
{
    u32 i;
    struct MsgData *msg;

    MI_CpuFill8(box, 0, sizeof(struct BattleBoxSave));
    for (i = 0; i < 6; i++) {
        POKE_TOOL_ClearBoxParam(&box->group.mon[i]);
    }
    msg = func_02045B38(0, 2, 9, 1);
    if (msg != 0) {
        MSGDATA_ReadUnits(msg, 6, box->boxName, sizeof(box->boxName));
        MSGDATA_Delete(msg);
    }
}






/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
struct BattleBoxSave *func_0200BAC8(struct SaveControl *save)
{
    return func_020071CC(save, 0x31);
}






/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 30 bytes, 0x0200BAD4..0x0200BAF4, one function, which carries no label in
 * the generated listing.
 *
 * One 0x88-byte entry assigned into a two-dimensional array: the outer stride
 * is 0x330 and the inner 0x88, and the copy is an inline counted `ldm`/`stm`
 * loop of 17 iterations, which is 0x88 divided by eight.  The eight-byte step
 * is what says the entry is word aligned; declared as a byte array the same
 * assignment becomes a `ldrb`/`strb` loop of 0x88 iterations.  See
 * docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md.
 *
 * It is a range of its own because the function on either side of it is a
 * near miss: func_0200BAC8 before it, which has no witness for 0x020271CC,
 * and func_0200BAF4 after it, which is fifteen bytes of register numbering.
 * Its only caller, func_0200BB58, is therefore outside this range and is what
 * attests it. *
 */
void func_0200BAD4(struct BoxMonGroup *groups, u32 group, u32 index, const struct BoxMon *src)
{
    groups[group].mon[index] = *src;
}





/*
 * Build a party from the Battle Box members, up to the first empty slot.
 * The temporary-heap value (heap & 0x7fff) | 0x8000 is computed inside the
 * loop, after the existence test is bound to its own local; hoisted above
 * the loop it swaps r6 and r7 across the body.  One local holds the boxed
 * Pokemon and then the party Pokemon made from it, as in the original.
 *
 * `i` is u32, not int: the loop bound at +0x0058 is `blo`, not `blt`.
 * The failing test `break`s out of the loop (beq to the epilogue at
 * +0x005A), it does not `continue`.
 */
struct Party *sub_0200BAF4(struct BoxMonGroup *box, int heap)
{
    struct Party *party;
    u32 i;

    party = func_0201A920(heap);
    func_0201A954(party, 6);
    for (i = 0; i < 6; i++) {
        void *mon = func_0200BBEC(box, 0, i);
        int exists = func_02017E88(mon, 0xa9, 0);
        int tempHeap = (heap & 0x7fff) | 0x8000;

        if (exists == 0) {
            break;
        }
        mon = POKE_TOOL_CreateFromBoxParam(mon, (u16)tempHeap);
        func_0201A98C(party, mon);
        func_020307B0(mon);
    }
    return party;
}





/*
 * Clear the six Battle Box slots, then copy each party member in.  The bound
 * of the second loop is a call: func_0201AA18(party) is re-invoked at the bottom of
 * every iteration and its result compared against the counter (`cmp r5, r0`
 * right after the `bl`), and the entry test is the peeled copy of that same
 * call, which is exactly how mwcc lowers `for (i = 0; i < f(party); i++)`.
 */
void func_0200BB58(struct BoxMonGroup *box, struct Party *party)
{
    u32 i;
    u32 group = 0;

    for (i = 0; i < 6; i++)
        POKE_TOOL_ClearBoxParam(&box->mon[i]);

    for (i = 0; i < (u32)func_0201AA18(party); i++)
        func_0200BAD4(box, group, i, POKE_TOOL_GetBoxParam(func_0201AB28(party, i)));
}





/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 30 bytes, 0x0200BBA8..0x0200BBC8, one function, which carries a label in
 * the generated listing.
 *
 * Whether entry zero of the record is present.  The result is a local
 * initialised to 0 and set to 1 inside the `if`, not a `return 1` /
 * `return 0` pair: there is one epilogue and the arm is a single `movs`.
 *
 * func_0200BBEC, which it calls, is the first function of
 * src/matched/unit_0200BBC8.c; the other caller of that address is
 * func_0200BAF4 at 0x0200BB1E, and that call is what attests it here.
 *
 * func_0200BAF4 itself is a near miss.  Its 100 bytes reproduce in size and
 * in every instruction, and fifteen bytes differ, all of them register
 * numbers: the original keeps the id parameter in r5 and the loop counter in
 * r4, where this source coalesces the two into r4 because the counter is born
 * after the id dies.  Twenty shapes were tried, five declaration orders for
 * the three locals crossed with two statement orders, plus four forms that
 * give the counter a live range reaching back past the id's last use; the
 * best is fifteen and the ranking is flat between fifteen and twenty-eight. *
 */
u32 func_0200BBA8(struct BoxMonGroup *box)
{
    u32 result = 0;

    if (func_02017E88(func_0200BBEC(box, 0, 0), 0xA9, 0) != 0) {
        result = 1;
    }
    return result;
}





/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200BC10, func_0200BC20, func_0200BC2C, func_0200BC4C,
 *           func_0200BC88, func_0200BCA0, func_0200BCA8, func_0200BCB8,
 *           func_0200BCD8, func_0200BCEC
 *
 * 384 bytes, 0x0200BBC8..0x0200BD48, 14 functions, none of which carries a
 * label in the generated listing: not one of them saves lr, so the whole
 * range arrives as a run of `.word`s between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * The object is two 0xE4-byte slots at +0x000, each an in-use word, a
 * 0xDC-byte payload and a word behind it, plus a flag word at +0x1C8.  That
 * is 0x1CC bytes and it is exactly what func_0200BD98 in
 * src/matched/unit_0200BD98.c returns as the size of the save block with id
 * 0x32, so the record is pinned from both ends.  The halfword of bits at
 * +0x358 that func_0200BBC8, func_0200BBD8 and func_0200BBFC reach is past
 * that end: it is the lock flags of the 0x35C-byte Battle Box record.  The
 * three sizes are pinned by the three
 * `ldm`/`stm` copies and agree: 0x1B pairs plus a word is the 0xDC payload
 * func_0200BC4C stores, and 0x1C pairs plus a word is the whole 0xE4 slot
 * func_0200BCEC swaps through a stack temporary.  See
 * docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; both copies are
 * eight-byte stepped, which is what says the payload is word aligned rather
 * than a byte array.
 *
 * func_0200BBEC belongs to a different object: it is pure address arithmetic
 * over a 0x330-byte record holding six 0x88-byte entries, and it is here only
 * because the file it was written in also holds the accessors above.  Its one
 * caller in this region, func_0200BBA8, is outside this range.
 *
 * Every guard in the file that ends in a shared exit is written as one
 * conjunction rather than as a run of early returns, which is what gives the
 * single epilogue the original has; see
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md.
 */
void func_0200BBC8(struct BattleBoxSave *box, u32 flags)
{
    box->lockFlags |= (u16)flags;
}




void func_0200BBD8(struct BattleBoxSave *box, int flags)
{
    box->lockFlags &= ~flags;
}




struct BoxMon *func_0200BBEC(struct BoxMonGroup *groups, u32 group, u32 index)
{
    return &groups[group].mon[index];
}




u32 func_0200BBFC(struct BattleBoxSave *box, u32 flags)
{
    if ((box->lockFlags & flags) != 0) {
        return 1;
    }
    return 0;
}




void func_0200BC10(struct DaycareSave *daycare)
{
    if (daycare->eggReady != 1) {
        daycare->eggReady = 1;
    }
}




void func_0200BC20(struct DaycareSave *daycare)
{
    daycare->eggReady = 0;
}




struct PokeParam *func_0200BC2C(struct DaycareSave *daycare, s32 slot)
{
    if (slot < 0 || slot >= 2 || daycare->slot[slot].inUse != 1) {
        slot = 0;
    }
    return &daycare->slot[slot].mon;
}




void func_0200BC4C(struct DaycareSave *daycare, s32 slot, const struct PokeParam *mon)
{
    if (slot >= 0 && slot < 2 && daycare->slot[slot].inUse != 1) {
        daycare->slot[slot].mon = *mon;
        daycare->slot[slot].inUse = 1;
        daycare->slot[slot].steps = 0;
    }
}




void func_0200BC88(struct DaycareSave *daycare, s32 slot)
{
    if (slot >= 0 && slot < 2 && daycare->slot[slot].inUse == 1) {
        daycare->slot[slot].inUse = 0;
    }
}




u32 func_0200BCA0(struct DaycareSave *daycare)
{
    return daycare->eggReady;
}




u32 func_0200BCA8(struct DaycareSave *daycare, u32 slot)
{
    if (slot >= 2) {
        return 0;
    }
    return daycare->slot[slot].inUse;
}




u32 func_0200BCB8(struct DaycareSave *daycare)
{
    s32 slot;
    u32 count = 0;

    for (slot = 0; slot < 2; slot++) {
        if (daycare->slot[slot].inUse == 1) {
            count++;
        }
    }
    return count;
}




u32 func_0200BCD8(struct DaycareSave *daycare, u32 slot)
{
    if (slot >= 2) {
        return 0;
    }
    return daycare->slot[slot].steps;
}




void func_0200BCEC(struct DaycareSave *daycare, s32 slotA, s32 slotB)
{
    struct DaycareSlot tmp;

    if (slotA >= 0 && slotA < 2 && slotB >= 0 && slotB < 2) {
        tmp = daycare->slot[slotA];
        daycare->slot[slotA] = daycare->slot[slotB];
        daycare->slot[slotB] = tmp;
    }
}




/*
 * Unlabelled arm9 leaf, filed as the relocation witness for ov021 func_021C3378
 * (wave A1, lane 13).
 */
void func_0200BD48(struct DaycareSlot *slots, u32 steps)
{
    int i;
    u64 total;

    for (i = 0; i < 2; i++) {
        if (slots[i].inUse == 1) {
            total = (u64)slots[i].steps + steps;
            if (total > 0xFFFFFFFF)
                total = 0xFFFFFFFF;
            slots[i].steps = total;
        }
    }
}




/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 36 bytes, 0x0200BD98..0x0200BDBC, 3 functions, none of which carries a
 * label in the generated listing.
 *
 * The size, constructor and lookup of the save block with id 0x32.  0x1CC is
 * exactly 2 * 0xE4 + 4, which is the two-slot record the accessors of
 * src/matched/unit_0200BBC8.c reach through a slot stride of 0xE4 and a flag
 * word at +0x1C8, so this is that object's header and the range immediately
 * before it is its accessor set.
 *
 * Both of the last two functions are bare tail calls, which is why neither
 * has a prologue and why each spends a literal pool word on its callee: see
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.  The constructor does
 * nothing but clear the block, so there is no field this file pins.
 */
u32 func_0200BD98(void)
{
    return sizeof(struct DaycareSave);
}




void func_0200BDA0(struct DaycareSave *daycare)
{
    MI_CpuFill8(daycare, 0, sizeof(struct DaycareSave));
}



struct DaycareSave *func_0200BDB0(struct SaveControl *save)
{
    return func_020071CC(save, 0x32);
}




/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200BDFC, func_0200BE00, func_0200BE24
 *
 * 140 bytes, 0x0200BDBC..0x0200BE48, 7 functions, five of which carry no
 * label in the generated listing.
 *
 * A 0x1B0-byte record: func_0200BDBC returns its size and func_0200BDC4
 * clears exactly that many bytes, which is the block-file opening this region
 * keeps producing.  The constructor then seeds the byte at +0x1A0 with 0x30
 * and reaches it by subtracting 0x10 from the size it already has in a
 * register rather than materialising 0x1A0 again; that is the compiler's
 * doing and not a second constant in the source.
 *
 * func_0200BDE4 hands the first sixteen bytes to INTRUDE_COMM_ResetOutcomes, which lives
 * in overlay address space.  The call is attested because ov019's generated
 * listing carries a `func_` label at 0x021763BC and branches elsewhere in the
 * image reach it; see "Callees that live in an overlay" in docs/MATCHING.md.
 *
 * func_0200BE00 and func_0200BE24 are the same clamped adder over two
 * neighbouring `u16` counters, and the ceiling 999 arrives from a literal
 * pool in each of them because it does not fit a Thumb immediate.  The
 * increment has to be written `field += add` with a **signed** parameter: the
 * comparison is a signed `ble`, and spelling the store as
 * `field = field + (u16)add` adds the truncation pair the store already does for
 * free.
 */
u32 func_0200BDBC(void)
{
    return sizeof(struct IntrudeSave);
}




void func_0200BDC4(struct IntrudeSave *intrude)
{
    MI_CpuFill8(intrude, 0, sizeof(struct IntrudeSave));
    func_0200BDE4(intrude);
    intrude->monolithLevel = 0x30;
}



void func_0200BDE4(struct IntrudeSave *intrude)
{
    MI_CpuFill8(&intrude->occupy, 0, sizeof(intrude->occupy));
    INTRUDE_COMM_ResetOutcomes(&intrude->occupy);
}



u16 func_0200BDF8(struct IntrudeSave *intrude)
{
    return intrude->occupy.missionScore;
}



u16 func_0200BDFC(struct IntrudeSave *intrude)
{
    return intrude->occupy.missionBonusScore;
}



void func_0200BE00(struct IntrudeSave *intrude, s32 add)
{
    if (intrude->occupy.missionScore + add > 999) {
        intrude->occupy.missionScore = 999;
    } else {
        intrude->occupy.missionScore += add;
    }
}



void func_0200BE24(struct IntrudeSave *intrude, s32 add)
{
    if (intrude->occupy.missionBonusScore + add > 999) {
        intrude->occupy.missionBonusScore = 999;
    } else {
        intrude->occupy.missionBonusScore += add;
    }
}




/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 60 bytes, 0x0200BE48..0x0200BE84, 3 functions, one of which carries no
 * label in the generated listing.
 *
 * The lookup of the save block with id 0x35 and the two directions of an
 * eight halfword copy in and out of it.  Both loops count **down** from 8
 * with `subs`/`bne` and no compare at all, which a `for (i = 0; i < 8; i++)`
 * does not produce: that spelling keeps the induction variable and costs a
 * `cmp` and a `blt`.  `for (i = 8; i != 0; i--)` over an unsigned counter is
 * what gives the original's six instruction body, and so does the equivalent
 * `do`/`while (--i != 0)`.
 */
struct IntrudeSave *func_0200BE48(struct SaveControl *save)
{
    return func_020071CC(save, 0x35);
}




void func_0200BE54(struct SaveControl *save, const u16 *src)
{
    u16 *dest = (u16 *)&func_0200BE48(save)->occupy;
    u32 i;

    for (i = 8; i != 0; i--) {
        *dest++ = *src++;
    }
}




void func_0200BE6C(struct SaveControl *save, u16 *dest)
{
    const u16 *src = (const u16 *)&func_0200BE48(save)->occupy;
    u32 i;

    for (i = 8; i != 0; i--) {
        *dest++ = *src++;
    }
}




/*
 * Add a log entry to the 20-entry intrude log at +0x10 when the own id is
 * one of its member ids: into the first free entry (memberIds[8] == 0), else
 * drop the oldest entry and append.
 *
 * The entry is 19 bytes rounded to 20 by its two-byte alignment, which is
 * why `*log = *entry;` is a 10-iteration ldrh/strh loop and not a five-word
 * ldm/stm pair: an align-2 aggregate has no four-byte move to use.
 *
 * Declaration order decides the register plan here, and it is not the
 * order the statements run in: with `u16 ownId;` declared before
 * `log = intrude->log;` the same body compiles to the same 130 bytes with a
 * different allocation (p in r5, q in r4, the cursor demoted to the
 * scratch r2, 47 bytes out).  Declaring `log` first makes the cursor's live
 * range start before the GX_GetBankForLCDC call, so it earns a
 * callee-saved register (intrude -> r6, entry -> r5, log -> r4) and the whole
 * prologue lines up.  See docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 *
 * GX_GetBankForLCDC takes no arguments and returns the u16 bank mask
 * (src/calib/gx_getbankforlcdc.c); the `blx` is a Thumb -> ARM call, so
 * the symbol is declared `arm`.
 *
 * EXACT*: the listing's extent for 0x0200BE84 runs to 0x0200BFA4 because
 * the seven functions at 0x0200BF08..0x0200BFA4 save no lr and carry no
 * label; the compared range is the 130 bytes of this function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200BE84.c \
 *       --func func_0200BE84 --addr 0x0200BE84 --cc 1.1p1 --thumb
 */
void func_0200BE84(struct IntrudeSave *intrude, struct IntrudeLogEntry *entry)
{
    struct IntrudeLogEntry *log = intrude->log;
    u16 ownId;
    int i;

    ownId = GX_GetBankForLCDC();

    for (i = 0; i < 8; i++) {
        if (ownId == entry->memberIds[i]) {
            break;
        }
    }
    if (i == 8) {
        return;
    }
    if (entry->kind >= 0x12) {
        return;
    }
    for (i = 0; i < 20; i++, log++) {
        if (log->memberIds[8] == 0) {
            *log = *entry;
            return;
        }
    }
    for (i = 1; i < 20; i++) {
        intrude->log[i - 1] = intrude->log[i];
    }
    intrude->log[19] = *entry;
}




/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200BF70, func_0200BF78, func_0200BF94
 *
 * 156 bytes, 0x0200BF08..0x0200BFA4, 7 functions, none of which carries a
 * label in the generated listing.
 *
 * The tail of the 0x1B0-byte record whose size getter and constructor are
 * src/matched/unit_0200BDBC.c: a byte at +0x1A0, a two-byte bitmap at +0x1A1,
 * a clamped counter at +0x1A4 and a `u64` at +0x1A8, which is 0x1B0 exactly.
 * func_0200BF94 is the tell for the last of those: it returns +0x1A8 in r0
 * and +0x1AC in r1, which is one 64-bit value and not two out-parameters.
 * See docs/idioms/long-long-aligns-to-four.md.
 *
 * func_0200BF18 sets one bit of the bitmap for an id in 0x21..0x26, and the
 * index arithmetic is signed: `lsrs #0x1F` / `lsls #0x1D` / `subs` /
 * `rors #0x1D` is `% 8` on a signed value, exactly as in
 * src/matched/sub_0200A6BC.c, and `& 7` would have been a two-instruction
 * `movs`/`ands`.  The two range tests branch to one exit, so they are one
 * conjunction rather than two early returns.
 *
 * The base address 0x1A1 arrives from a literal pool in both functions that
 * touch the bitmap, because a register-offset `ldrb`/`strb` has no immediate
 * at all; that is the forced case of
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md
 * and not evidence of a second object.
 */
void func_0200BF08(struct IntrudeSave *intrude, u32 level)
{
    intrude->monolithLevel = level;
}



u8 func_0200BF10(struct IntrudeSave *intrude)
{
    return intrude->monolithLevel;
}



void func_0200BF18(struct IntrudeSave *intrude, s32 id)
{
    s32 bit = id - 0x21;

    if (bit >= 0 && id <= 0x26) {
        intrude->obtainedFlags[bit / 8] |= (u8)(1 << (bit % 8));
    }
}



void func_0200BF54(struct IntrudeSave *intrude, u8 *dest, u32 size)
{
    s32 i;

    for (i = 0; i < 2; i++) {
        dest[i] = intrude->obtainedFlags[i];
    }
}



u32 func_0200BF70(struct IntrudeSave *intrude)
{
    return intrude->missionClearCount;
}



u32 func_0200BF78(struct IntrudeSave *intrude)
{
    if (intrude->missionClearCount < 99999) {
        intrude->missionClearCount++;
    }
    return intrude->missionClearCount;
}



u64 func_0200BF94(struct IntrudeSave *intrude)
{
    return intrude->playSeconds;
}




/*
 * battle_rec.c, 0x0200BFA4..0x0200C058: the play-clock accumulator and the
 * unlabelled 4-byte follower func_0200C054 (`return 0xEC;`, a size getter).
 *
 * func_0200BFA4 converts the h:m:s clock at q to seconds and, by mode,
 * latches it (0), adds the elapsed delta into the u64 at +0x1A8 (1), or
 * returns that total plus the delta without storing it (2).  What closed it
 * after docs/notes/pkt_0200BFA4.c.txt (79 out, 4 bytes short):
 *   - the three clock fields are u64 LOCALS: the image zeroes the high half
 *     (`movs r4, #0`) right after the first call and keeps four stack
 *     words, which a u32 t[3] never gives;
 *   - the sum is written minutes first, `mm * 60 + hh * 3600 + ss` (the
 *     _ull_mul calls follow source order);
 *   - mode 2 returns `total + (v - g)`, not `total - g` (the four missing
 *     bytes were that add).
 *
 * Integrator: seed 0x0200C054 (unlabelled follower, member of this unit).
 */
u64 func_0200BFA4(struct IntrudeSave *intrude, const struct PlayTime *time, u32 mode)
{
    u64 hours, minutes, seconds;
    u64 now;

    hours = func_0200864C(time);
    minutes = func_02008650(time);
    seconds = func_02008654(time);
    now = minutes * 60 + hours * 3600 + seconds;

    switch (mode) {
    case 0:
        _PlayTimeLatch = now;
        break;
    case 1:
        intrude->playSeconds = intrude->playSeconds + (now - _PlayTimeLatch);
        break;
    case 2:
        return intrude->playSeconds + (now - _PlayTimeLatch);
    }
    return intrude->playSeconds;
}




u32 func_0200C054(void)
{
    return sizeof(struct BeaconSave);
}




void func_0200C058(struct BeaconSave *beacon)
{
    struct MsgData *msg;
    struct StrBuf *greet;
    struct StrBuf *thanks;

    MI_CpuFill8(beacon, 0, sizeof(struct BeaconSave));
    func_0200C10C(beacon);
    beacon->bestScore = 0;
    msg = func_02045B38(0, 3, 0x2f, 0x8007);
    greet = func_02045EC0(msg, 0x151);
    STRBUF_ToChars(greet, beacon->greetMessage, 9);
    STRBUF_Delete(greet);
    thanks = func_02045EC0(msg, 0x159);
    STRBUF_ToChars(thanks, beacon->thanksMessage, 9);
    STRBUF_Delete(thanks);
    MSGDATA_Delete(msg);
    beacon->mode = 0;
    beacon->entryCount = 0;
    beacon->recentIds[0] = 0xff;
    beacon->recentIds[1] = 0xff;
    beacon->recentIds[2] = 0xff;
}




/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200C10C, func_0200C11C, func_0200C164, func_0200C184,
 *           func_0200C18C, func_0200C1A4, func_0200C1B0, func_0200C1C4,
 *           func_0200C1C8, func_0200C1DC, func_0200C1E0, func_0200C1F4,
 *           func_0200C1F8, func_0200C20C, func_0200C210, func_0200C224,
 *           func_0200C22C, func_0200C234, func_0200C248, func_0200C258,
 *           func_0200C274, func_0200C278, func_0200C29C, func_0200C2B0,
 *           func_0200C2D0, func_0200C2F0, func_0200C308, func_0200C31C,
 *           func_0200C324, func_0200C32C, func_0200C334, func_0200C33C,
 *           func_0200C344, func_0200C34C, func_0200C358, func_0200C364,
 *           func_0200C37C, func_0200C384, func_0200C38C, func_0200C39C,
 *           func_0200C3B0, func_0200C3B8, func_0200C3C0, func_0200C3E0,
 *           func_0200C3EC
 *
 * 780 bytes, 0x0200C0E8..0x0200C3F4, 49 functions, forty-four of which carry
 * no label in the generated listing: the file is almost entirely accessors
 * and none of them saves lr.
 *
 * The object is the save block with id 0x34: func_0200C0F0 is the whole of
 * its lookup, `func_020071CC(sys, 0x34)`, and func_0200C0E8 is a wrapper
 * that forwards to it.  The layout below is read off the accessors and is
 * self-consistent to the byte from +0x00 to +0xE2; nothing here returns
 * sizeof, because the size getter of this block belongs to whatever file
 * precedes it, so the tail past +0xE2 is not pinned.
 *
 * Three things in it cost real time.
 *
 *  - func_0200C164 takes a **const** pointer, and that is the whole
 *    difference between it and the twelve-byte-longer version.  Its three
 *    bitfield reads come out of one `ldrb` in the original, and through a
 *    non-const pointer this compiler reloads the byte before each of the two
 *    later ones, because the intervening `str` through a `u32 *` may alias
 *    it.  See docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md.
 *  - func_0200C3C0 goes the other way and reads +0xE0 twice, once for the
 *    compare and once for the subtraction, with the address recomputed each
 *    time.  Nothing that leaves the field ordinary reproduces that: the
 *    compiler folds the two reads into one under every spelling of the
 *    branch, the arms, the cast and the pointer.  Declaring the field
 *    `volatile` is what keeps both reads, and it costs nothing in the getter
 *    and setter on either side of it, which touch it once each.
 *  - the pair at +0x50 is one `u64` read back as two words, the union of
 *    docs/idioms/long-long-aligns-to-four.md: func_0200C37C returns the
 *    64-bit value and func_0200C384 stores the two halves from two register
 *    arguments.
 */
struct BeaconSave *func_0200C0E8(struct SaveControl *save)
{
    return func_0200C0F0(save);
}




struct BeaconSave *func_0200C0F0(struct SaveControl *save)
{
    return func_020071CC(save, 0x34);
}




void func_0200C0FC(struct BeaconSave *beacon, u32 index, u8 value)
{
    beacon->inputFlags[index] = value;
}



u8 func_0200C104(struct BeaconSave *beacon, u32 index)
{
    return beacon->inputFlags[index];
}



void func_0200C10C(struct BeaconSave *beacon)
{
    MI_CpuFill8(beacon->inputFlags, 0, sizeof(beacon->inputFlags));
}



void func_0200C11C(struct BeaconSave *beacon, u16 id, u32 kind, u32 enabled, u32 single)
{
    beacon->selectId = id;
    beacon->select.kind = kind;
    beacon->select.enabled = enabled;
    beacon->select.isSingle = (single == 1);
}



void func_0200C164(const struct BeaconSave *beacon, u32 *id, u32 *kind, u32 *enabled, u32 *single)
{
    *id = beacon->selectId;
    *kind = beacon->select.kind;
    *enabled = beacon->select.enabled;
    *single = beacon->select.isSingle;
}



u32 func_0200C184(struct BeaconSave *beacon)
{
    return beacon->bestScore;
}



void func_0200C18C(struct BeaconSave *beacon, u32 score)
{
    beacon->bestScore = score;
}



u8 func_0200C1A4(struct BeaconSave *beacon)
{
    return beacon->rank;
}



void func_0200C1B0(struct BeaconSave *beacon, u32 rank)
{
    beacon->rank = rank;
}



u32 func_0200C1C4(struct BeaconSave *beacon)
{
    return beacon->greetCount;
}



u32 func_0200C1C8(struct BeaconSave *beacon)
{
    if (beacon->greetCount < 99999) {
        beacon->greetCount++;
    }
    return beacon->greetCount;
}



u32 func_0200C1DC(struct BeaconSave *beacon)
{
    return beacon->thanksCount;
}



u32 func_0200C1E0(struct BeaconSave *beacon)
{
    if (beacon->thanksCount < 99999) {
        beacon->thanksCount++;
    }
    return beacon->thanksCount;
}



u16 *func_0200C1F4(struct BeaconSave *beacon)
{
    return beacon->greetMessage;
}



void func_0200C1F8(struct BeaconSave *beacon, struct StrBuf *message)
{
    STRBUF_ToChars(message, beacon->greetMessage, 9);
}



u16 *func_0200C20C(struct BeaconSave *beacon)
{
    return beacon->thanksMessage;
}



void func_0200C210(struct BeaconSave *beacon, struct StrBuf *message)
{
    STRBUF_ToChars(message, beacon->thanksMessage, 9);
}



u8 func_0200C224(struct BeaconSave *beacon)
{
    return beacon->mode;
}



void func_0200C22C(struct BeaconSave *beacon, u8 mode)
{
    beacon->mode = mode;
}



u32 func_0200C234(struct BeaconSave *beacon, u32 bit)
{
    return (beacon->flags & (1 << bit)) != 0;
}



void func_0200C248(struct BeaconSave *beacon, u32 bit)
{
    beacon->flags |= 1 << bit;
}



u32 func_0200C258(struct BeaconSave *beacon)
{
    u32 count = 0;
    u32 bits;

    for (bits = beacon->flags; bits != 0; bits >>= 1) {
        if (bits & 1) {
            count++;
        }
    }
    return count;
}



u32 func_0200C274(struct BeaconSave *beacon)
{
    return beacon->points;
}



u32 func_0200C278(struct BeaconSave *beacon, u32 add)
{
    if (add > 9999999) {
        beacon->points = 9999999;
    } else {
        beacon->points += add;
    }
    if (beacon->points > 9999999) {
        beacon->points = 9999999;
    }
    return beacon->points;
}



u32 func_0200C29C(struct BeaconSave *beacon, u32 sub)
{
    if (beacon->points < sub) {
        beacon->points = 0;
    } else {
        beacon->points -= sub;
    }
    return beacon->points;
}



void func_0200C2B0(struct BeaconSave *beacon, u32 index, const u16 *species)
{
    s32 i;

    for (i = 0; i < 6; i++) {
        beacon->teams[index].species[i] = species[i];
    }
}



void func_0200C2D0(struct BeaconSave *beacon, u32 index, u16 *species)
{
    s32 i;

    for (i = 0; i < 6; i++) {
        species[i] = beacon->teams[index].species[i];
    }
}



void func_0200C2F0(struct BeaconSave *beacon, u32 slot, u8 state)
{
    beacon->slotStates |= (u8)(state << (slot * 2));
}



u8 func_0200C308(struct BeaconSave *beacon, u32 slot)
{
    return (u8)((beacon->slotStates >> (slot * 2)) & 3);
}



u8 func_0200C31C(struct BeaconSave *beacon)
{
    return beacon->slotStates;
}



void func_0200C324(struct BeaconSave *beacon, u8 states)
{
    beacon->slotStates = states;
}



u8 func_0200C32C(struct BeaconSave *beacon)
{
    return beacon->entryCount;
}



void func_0200C334(struct BeaconSave *beacon, u8 count)
{
    beacon->entryCount = count;
}



int func_0200C33C(struct BeaconSave *beacon, u32 index)
{
    return beacon->recentIds[index];
}



void func_0200C344(struct BeaconSave *beacon, u8 index, u8 id)
{
    beacon->recentIds[index] = id;
}



u16 func_0200C34C(struct BeaconSave *beacon, u32 index)
{
    return beacon->recentValues[index];
}



void func_0200C358(struct BeaconSave *beacon, u32 index, int value)
{
    beacon->recentValues[index] = value;
}



void func_0200C364(struct BeaconSave *beacon, u8 index, int add)
{
    u32 value = beacon->recentValues[index];

    value += add;
    if (value > 0xFFFF) {
        value = 0xFFFF;
    }
    beacon->recentValues[index] = value;
}



u64 func_0200C37C(struct BeaconSave *beacon)
{
    return beacon->lastTime.value;
}



void func_0200C384(struct BeaconSave *beacon, u32 lo, u32 hi)
{
    beacon->lastTime.half.lo = lo;
    beacon->lastTime.half.hi = hi;
}



void func_0200C38C(struct BeaconSave *beacon, s32 index, u32 value)
{
    if (index < 8) {
        beacon->hashedIds[index] = value;
    }
}



u32 func_0200C39C(struct BeaconSave *beacon, s32 index)
{
    if (index >= 8) {
        return 0;
    }
    return beacon->hashedIds[index];
}



u16 func_0200C3B0(struct BeaconSave *beacon)
{
    return beacon->gatePoints;
}



void func_0200C3B8(struct BeaconSave *beacon, u16 points)
{
    beacon->gatePoints = points;
}



void func_0200C3C0(struct BeaconSave *beacon, u16 sub)
{
    if (sub <= beacon->gatePoints) {
        beacon->gatePoints = beacon->gatePoints - sub;
    } else {
        beacon->gatePoints = 0;
    }
}



u8 func_0200C3E0(struct BeaconSave *beacon)
{
    return beacon->recorderFlag;
}



void func_0200C3EC(struct BeaconSave *beacon, u32 flag)
{
    beacon->recorderFlag = flag;
}
