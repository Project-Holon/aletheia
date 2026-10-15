/*
 * file:     misc_savedata.c
 * unit:     yes
 * function: MISC_SAVEDATA_GetStatusByte, MISC_SAVEDATA_GetHalfword, MISC_SAVEDATA_AddHalfwordClamped, MISC_SAVEDATA_GetTallyWord, MISC_SAVEDATA_GetAnswerMessageOffset, MISC_SAVEDATA_IsTallyFull, MISC_SAVEDATA_GetTallyValue, MISC_SAVEDATA_AddTallyValue, MISC_SAVEDATA_GetScoreValue, MISC_SAVEDATA_FoldTally, BATTLE_EXAMINATION_GetBlockSize, BATTLE_EXAMINATION_ClearBlock, BATTLE_EXAMINATION_IsDeliveryValid, BATTLE_EXAMINATION_IsDeliveryUnused, BATTLE_EXAMINATION_GetDeliveryId, BATTLE_EXAMINATION_GetTrainerSlot, BATTLE_EXAMINATION_LoadDelivery, func_0200E684, func_0200E6B4, func_0200E6E8, MISC_SAVEDATA_CopyQuadRecord, MISC_SAVEDATA_StoreQuadRecord, MISC_SAVEDATA_GetMonEntrySize, MISC_SAVEDATA_ClearMonEntry, MISC_SAVEDATA_GetMonEntryFlag, MISC_SAVEDATA_GetMonEntryLevel,, MISC_SAVEDATA_FillMonEntry, func_0200E874, func_0200E878, func_0200E884, func_0200E89C, func_0200E8B0, func_0200E8B8, func_0200E8CC, func_0200E8D0, func_0200E8D8, func_0200E8E0, func_0200E8F8, func_0200E904, func_0200E918, func_0200E938, func_0200E958, func_0200E978, MISC_SAVEDATA_FindKey, MISC_SAVEDATA_GetMacStructSize, MISC_SAVEDATA_InitMacAndStats, MISC_SAVEDATA_GetBlock3C, MISC_SAVEDATA_GetStatsBase, MISC_SAVEDATA_GetStatsBase2, MISC_SAVEDATA_GetRecordBase, MISC_SAVEDATA_GetRingBlockSize, MISC_SAVEDATA_GetRecordSize, MISC_SAVEDATA_ClearRingBlock, MISC_SAVEDATA_InitRecord, MISC_SAVEDATA_SnapshotParty, MISC_SAVEDATA_AppendPartyRecord, MISC_SAVEDATA_FindFreeRecordSlot, MISC_SAVEDATA_ExportRecord, func_0200EC98, func_0200ECB4, func_0200ECD0, MISC_SAVEDATA_ExportRingRecord, MISC_SAVEDATA_GetRingRecordDate, MISC_SAVEDATA_GetShortBlockSize, MISC_SAVEDATA_InitShortBlock, MISC_SAVEDATA_GetBlock44, MISC_SAVEDATA_InsertRecentValue, func_0200EDC4, func_0200EDEC
 * address:  0x0200E44C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 *   GF_STANDARD_SetupCalc 0x0203F1FC  arm, not otherwise called in arm9_main
 * symbols:
 *   QUESTIONNAIRE_GetFirstAnswerMessageOffset    0x0216736C  thumb  ov010
 *   MI_CpuFill8  0x02082BCC  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   data_020A721C  0x020A721C  data
 *   SAVE_CONTROL_LoadExtraSaveWithBuffer  0x020072CC  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   GAME_DATA_PartSaveStart  0x02012E4C  thumb
 *   GAME_DATA_PartSaveMain  0x02012E7C  thumb
 *   OS_WaitIrq     0x0208459C  arm
 *   func_0200734C  0x0200734C  thumb
 *   func_020307B0  0x020307B0  arm
 *   PMSI_PARAM_SetDefaultGreeting  0x02024344  thumb
 *   PMSI_PARAM_SetDefaultSentence  0x020242D8  thumb
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   func_02017E1C   0x02017E1C  thumb
 *   MSGDATA_ReadUnits   0x02045F5C  arm
 *   func_0201F41C   0x0201F41C  thumb
 *   gSpeciesNameBank      0x020A7370  data
 *   MIi_CpuCopy32 0x02082A90  arm
 *   OS_GetMacAddress 0x02087C6C  arm
 *   _u32_div_f    0x0209C2B0  arm
 *   MI_CpuCopy8   0x02082D44  arm
 *   func_0200E918  0x0200E918  thumb
 *   func_0200E938  0x0200E938  thumb
 *   func_0203EFC8  0x0203EFC8  arm
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   STRBUF_ToChars  0x02045A38  arm
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   STRBUF_SetStringN  0x02045994  arm
 *   sub_0200EC14   0x0200EC14  thumb
 *   BSUBWAY_SAVEDATA_InitStats  0x0200DFCC  thumb
 */
/* Struct views of the save objects this file works on, defined here instead of
 * in a match/include/ObjNNNNN.h stand-in. */
struct TrialHouseDelivery;
struct PartyRingSave;
struct Rec;

struct Big;
struct Sub02007324Ctrl;
struct Sub020071CCCtrl;
struct MsgData;
struct Sav;
struct U16Vec;
struct Rec;
struct Date;
struct Strbuf;
struct Entry;
struct RecordTarget;
struct RecordDate;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Tally {
    u16 add16[30];      /* 0x000 */
    u8 add8[150];       /* 0x03C */
    u8 pad[10];         /* 0x0D2 */
    u32 total32[30];    /* 0x0DC */
    u16 total16[150];   /* 0x154 */
} Tally;

/* One 8-byte record of the four-halfword table the copy helpers move. */
struct QuadRecord {
    u16 data[4];
};

/* The byte at +0x1a of a BoxMonSlot: bit 0 is a set flag, bits 1..7 a level. */
struct LevelFlagBits {
    u8 flag : 1;
    u8 level : 7;
};

/* One 0x20-byte slot of the Pokemon list MISC_SAVEDATA_FillMonEntry fills. */
struct BoxMonSlot {
    u32 pid;                    /* +0x00 */
    u16 name[11];               /* +0x04 */
    struct LevelFlagBits bits;  /* +0x1a */
    u8  tag;                    /* +0x1b, 0xFF means unset */
    u32 experience;             /* +0x1c */
};

typedef signed int     s32;

/* One 0x3c-byte party member snapshot of struct Rec. */
struct Entry {
    u16 species;
    u8  level;
    u8  form : 6;
    u8  gender : 2;
    u32 pid;
    u32 experience;
    u16 name[11];
    u16 ot[8];
    u16 traits[4];
};

struct Rec {
    struct Entry e[6];
    u16 year;
    u8  month;
    u8  day;
};

struct Date {
    u32 year;
    u32 month;
    u32 day;
};

/* Save block 5, 0x5C8 bytes: the wireless-delivered trainer data read by the
 * battle examination code (ov021 TrialHouseDelivery). */
struct TrialHouseDelivery {
    u8  pad[0x5C2];
    u16 magic;      /* +0x5C2, 0xD68 while the slot holds valid data */
    u16 idAndUsed;  /* +0x5C4, delivery id in bits 0..6, bit 15 marks a used slot */
    u16 checksum;   /* +0x5C6 */
};

/* Save block with a ring of 15 dated party snapshots (0x155C bytes). */
struct PartyRingSave {
    struct Rec entries[15];   /* +0x000 */
    u32 writeIndex;           /* +0x1554 slot the next snapshot goes to */
    u32 recordCount;          /* +0x1558 saturating total, stops at 9999 */
};


/* An exported party record: two string buffers and the copied fields. */
struct RecordTarget {
    void *nicknameStr;  /* +0x00 */
    void *otNameStr;    /* +0x04 */
    u32   pid;          /* +0x08 */
    u32   experience;   /* +0x0c */
    u16   species;      /* +0x10 */
    u8    level;        /* +0x12 */
    u8    form : 6;     /* +0x13 */
    u8    gender : 2;
    u16   traits[4];    /* +0x14 */
};

/* The date unpacked from a struct Rec at +0x168. */
struct RecordDate {
    u32 year;
    u32 month;
    u32 day;
    u32 reserved;
};

/* The 0x6204-byte save block with a 32-entry recent-value list and a 256-bit
 * page bitmap at +0x84. */
struct RecentValueSave {
    u32 values[32];         /* +0x00 */
    u32 count;              /* +0x80 */
    u8  bitmap[0x20];       /* +0x84 */
    u8  reserved[0x615C];   /* +0x0a4 .. +0x61ff */
    unsigned int flags6200; /* +0x6200 */
};

extern u8 QUESTIONNAIRE_GetFirstAnswerMessageOffset(u32 id);
extern void MI_CpuFill8(void *dst, unsigned char val, unsigned long size);
extern u16 GF_STANDARD_SetupCalc(const u8 *src, u32 len);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int SAVE_CONTROL_LoadExtraSaveWithBuffer(u32 sv, u32 id, u32 heap, void *buf, u32 size);
extern void GAME_DATA_PartSaveStart(u8 *p, u32 id);
extern int GAME_DATA_PartSaveMain(char *p, int partId);
extern void OS_WaitIrq(int clear, u32 mask);
extern void func_0200734C(struct Sub02007324Ctrl *ctrl, u32 id);
extern u32 func_020307B0(void *p);
extern void PMSI_PARAM_SetDefaultGreeting(void *obj);
extern void PMSI_PARAM_SetDefaultSentence(void *slot, u32 idx);
extern void *SAVE_CONTROL_GetBlock(struct Sub020071CCCtrl *ctrl, u32 id);
extern u32  func_02017E1C(void *mon, u32 id, u32 buf);
extern void MSGDATA_ReadUnits(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern void func_0201F41C(const u16 *src, u16 *dst, u32 n);
extern void  MIi_CpuCopy32(void *dest, const void *src, u32 size);
extern void  OS_GetMacAddress(void *obj);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern u8 func_0200E918(const u8 *base, u32 idx);
extern void func_0200E938(u8 *obj, u32 id, void *dest);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_0200E904(void *p);
extern void BSUBWAY_SAVEDATA_InitStats(void *p);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern u32 POKEPARTY_GetCount(void *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern void STRBUF_ToChars(struct U16Vec *vec, u16 *out, u32 n);
extern u16   STRBUF_GetEosChar(void);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, u32 len);
extern int sub_0200EC14(char *o);
int MISC_SAVEDATA_GetStatusByte(int tally, int index);
u16 MISC_SAVEDATA_GetHalfword(const u16 *p, int i);
void MISC_SAVEDATA_AddHalfwordClamped(char *p, int idx, int v);
u32 MISC_SAVEDATA_GetTallyWord(u8 *p, int i);
u32 MISC_SAVEDATA_GetAnswerMessageOffset(u32 fieldId, u32 index);
u32 MISC_SAVEDATA_IsTallyFull(u8 *p, u32 a, u32 count);
u32 MISC_SAVEDATA_GetTallyValue(u8 *tally, u32 fieldId, u32 index);
void MISC_SAVEDATA_AddTallyValue(u8 *tally, u32 fieldId, u32 index, int delta);
int MISC_SAVEDATA_GetScoreValue(int tally, int fieldId, int index);
void MISC_SAVEDATA_FoldTally(Tally *t);
u32 BATTLE_EXAMINATION_GetBlockSize(void);
void BATTLE_EXAMINATION_ClearBlock(void *p);
int BATTLE_EXAMINATION_IsDeliveryValid(void *delivery);
int BATTLE_EXAMINATION_IsDeliveryUnused(void *p);
u16 BATTLE_EXAMINATION_GetDeliveryId(void *p);
char *BATTLE_EXAMINATION_GetTrainerSlot(char *p, u32 idx);
void BATTLE_EXAMINATION_LoadDelivery(void *sys, void *dst, u32 heap);
void BATTLE_EXAMINATION_RefreshMarker(void *obj);
u32 BATTLE_EXAMINATION_GetGreetingSize(void);
void BATTLE_EXAMINATION_InitGreetings(void *obj);
void *SAVEDATA_GetExtraBlockThunk(u32 a);
void *SAVEDATA_GetExtraBlock(u32 a);
void MISC_SAVEDATA_CopyQuadRecord(struct QuadRecord *src, int idx, struct QuadRecord *dst);
void MISC_SAVEDATA_StoreQuadRecord(struct QuadRecord *dst, int idx, struct QuadRecord *src);
u32 MISC_SAVEDATA_GetMonEntrySize(void);
void MISC_SAVEDATA_ClearMonEntry(void *dest);
u32 MISC_SAVEDATA_GetMonEntryFlag(const void *obj, u32 idx);
u32 MISC_SAVEDATA_GetMonEntryLevel(const void *obj, u32 idx);
u32 MISC_SAVEDATA_IsMonEntrySet(const void *obj, u32 idx);
u8 MISC_SAVEDATA_GetMonEntryTag(const void *obj, u32 idx);
u32 MISC_SAVEDATA_GetMonEntryCost(const void *unused, u32 a, u32 b);
u32 MISC_SAVEDATA_GetMonEntryPid(const void *obj, u32 idx);
void *MISC_SAVEDATA_GetMonEntryName(void *obj, u32 idx);
u32 MISC_SAVEDATA_GetMonEntryExperience(const void *obj, u32 idx);
void MISC_SAVEDATA_FillMonEntry(struct BoxMonSlot *o, int idx, void *mon);
int MISC_SAVEDATA_GetSmallEntrySize(void);
void MISC_SAVEDATA_ClearSmallEntry(void *dst);
void MISC_SAVEDATA_SaveScratch16(void *sys, void *src);
void MISC_SAVEDATA_LoadScratch16(void *sys, void *dest);
u32 MISC_SAVEDATA_GetBigBlockSize(void);
void MISC_SAVEDATA_ClearBigBlock(void *dest);
void MISC_SAVEDATA_EmptyHook(void);
void *MISC_SAVEDATA_GetScratchBase(void *obj);
u32 MISC_SAVEDATA_GetFlags6200(const void *obj);
void MISC_SAVEDATA_SetFlags6200(void *obj, u32 value);
u32 MISC_SAVEDATA_GetMacSize(void);
void MISC_SAVEDATA_ClearMacArea(void *dest);
void *MISC_SAVEDATA_GetBlock41(void *sys);
void MISC_SAVEDATA_InitMac(void *obj);
u8 MISC_SAVEDATA_GetKeyByte(const u8 *base, u32 idx);
void MISC_SAVEDATA_AddKeyByte(u8 *base, u32 idx, int delta);
void MISC_SAVEDATA_GetKey(u8 *obj, u32 id, void *dest);
void MISC_SAVEDATA_SetKey(u8 *obj, u32 id, const void *src);
void MISC_SAVEDATA_SetKeyField(u8 *obj, u32 id, u32 extra, u8 value);
u32 MISC_SAVEDATA_FindKey(void *base, void *key);
unsigned int MISC_SAVEDATA_GetMacStructSize(void);
void MISC_SAVEDATA_InitMacAndStats(void *record);
void *MISC_SAVEDATA_GetBlock3C(void *p);
int MISC_SAVEDATA_GetStatsBase(int p);
int MISC_SAVEDATA_GetStatsBase2(int p);
int MISC_SAVEDATA_GetRecordBase(int p);
u32 MISC_SAVEDATA_GetRingBlockSize(void);
u32 MISC_SAVEDATA_GetRecordSize(void);
void MISC_SAVEDATA_ClearRingBlock(void *p);
void MISC_SAVEDATA_InitRecord(void *block);
void MISC_SAVEDATA_SnapshotParty(struct Rec *rec, void *party, struct Date *date, u32 heap);
void MISC_SAVEDATA_AppendPartyRecord(struct PartyRingSave *obj, void *party, void *date, u32 heap);
int MISC_SAVEDATA_FindFreeRecordSlot(char *p);
void MISC_SAVEDATA_ExportRecord(const struct Entry *base, int idx, struct RecordTarget *dst);
void MISC_SAVEDATA_GetRecordDate(const u8 *o, struct RecordDate *out);
u32 MISC_SAVEDATA_GetRingIndex(char *o);
u32 MISC_SAVEDATA_GetRingRemaining(char *o, u32 n);
int MISC_SAVEDATA_GetRingRecordIndex(char *o, int idx);
void MISC_SAVEDATA_ExportRingRecord(void *ring, u32 index, void *recordIndex, void *target);
void MISC_SAVEDATA_GetRingRecordDate(u8 *o, int idx, void *out);
u32 MISC_SAVEDATA_GetShortBlockSize(void);
void MISC_SAVEDATA_InitShortBlock(void *block);
void *MISC_SAVEDATA_GetBlock44(void *p);
void MISC_SAVEDATA_InsertRecentValue(struct RecentValueSave *l, u32 val);
int MISC_SAVEDATA_ContainsRecentValue(struct RecentValueSave *l, u32 val);
int MISC_SAVEDATA_TestBitmapBit(char *obj, int i);
void MISC_SAVEDATA_SetBitmapBit(char *obj, int i);
extern const char data_020A721C[];
extern void *gSpeciesNameBank;










int MISC_SAVEDATA_GetStatusByte(int tally, int index){ return *(unsigned char *)(((tally + index) + ((0xa << 6) << 0))); }











/*
 * Unlabelled Thumb leaf in the ARM9 module: halfword array index.
 *
 * Addresses are Black-image addresses.
 */
u16 MISC_SAVEDATA_GetHalfword(const u16 *array, int index)
{
    return array[index];
}










void MISC_SAVEDATA_AddHalfwordClamped(char *tally, int index, int delta)
{
    unsigned short *cell = (unsigned short *)(tally + index * 2);
    *cell = *cell + (unsigned short)delta;
    if (*cell > 0x270f)
        *cell = 0x270f;
}











/*
 * Unlabelled Thumb leaf in the ARM9 module: word array at +0xDC, index i.
 * Filed by wave D4 lane 12 (blocked ov217 RESEARCH_GRAPH_BuildGraphTable).
 *
 * Addresses are Black-image addresses.
 */
u32 MISC_SAVEDATA_GetTallyWord(u8 *tally, int index)
{
    return *(u32 *)(tally + index * 4 + 0xdc);
}











/*
 * note:     wave 16: promoted.  0x0216736C is the unlabelled ov010 leaf matched
 *           in src/matched/QUESTIONNAIRE_GetFirstAnswerMessageOffset.c (ov010/pkt_02167358); it attests as
 *           `matched, overlay` under the ov010 hint.  The source shape that
 *           works: a1-1 must be a named local computed before the call;
 *           writing `f(a0) + (a1 - 1)` gives `adds r0, r1, r0` instead of
 *           `adds r0, r0, r1`.
 */
u32 MISC_SAVEDATA_GetAnswerMessageOffset(u32 fieldId, u32 index)
{
    u32 offset = index - 1;
    u32 base = QUESTIONNAIRE_GetFirstAnswerMessageOffset((u8)fieldId);

    return base + offset;
}











/*
 * Returns 1 when MISC_SAVEDATA_GetTallyValue's result is 0x63 or more, else 0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MISC_SAVEDATA_IsTallyFull.c \
 *       --func MISC_SAVEDATA_IsTallyFull --addr 0x0200E49C --thumb --cc 1.1p1
 */
u32 MISC_SAVEDATA_IsTallyFull(u8 *tally, u32 fieldId, u32 index)
{
    return MISC_SAVEDATA_GetTallyValue(tally, fieldId, index) >= 0x63 ? 1 : 0;
}











u32 MISC_SAVEDATA_GetTallyValue(u8 *tally, u32 fieldId, u32 index)
{
    if (index == 0)
        return 0;
    return *(tally + MISC_SAVEDATA_GetAnswerMessageOffset(fieldId, index) + 0x3c);
}











/*
 * Two tells on the source, both four bytes each.  The base has to be taken as
 * a pointer (`p = a0 + 0x3c` then `p[off]`) rather than as one subscript
 * `a0[off + 0x3c]`: the original adds the 0x3c to the object pointer and then
 * indexes off against that, not the other way round.  And the guard is
 * written `a3 + v`, not `v + a3`: the add is commutative but this front end
 * keeps the source order in the encoding, and `v + a3` emits `adds r1, r2,
 * r4` where the original has `adds r1, r4, r2`.  The fourth parameter is
 * signed (the guard is `ble`, not `bls`).
 */
void MISC_SAVEDATA_AddTallyValue(u8 *tally, u32 fieldId, u32 index, int delta)
{
    u8 *base;
    u32 offset;
    u8 value;

    if (index == 0)
        return;
    offset = MISC_SAVEDATA_GetAnswerMessageOffset(fieldId, index);
    base = tally + 0x3c;
    value = base[offset];
    if (delta + value > 0x63) {
        base[offset] = 0x63;
        return;
    }
    base[offset] = value + (u8)delta;
}










int MISC_SAVEDATA_GetScoreValue(int tally, int fieldId, int index){ int offset; if ((unsigned int)(index) == (unsigned int)(0)) {  return 0; } else { offset = MISC_SAVEDATA_GetAnswerMessageOffset((int)(fieldId + 0), (int)(index + 0)); return *(unsigned short *)(((char *)(((tally + 0) + (offset << 1))) + ((int)((0x55 << 2)) << 0))); } }











/*
 * Folds two arrays of pending increments into their saturating totals and
 * clears the increments: 30 u16 into u32 totals capped at 999999, then 150
 * u8 into u16 totals capped at 9999.  Seeded in layout/function_starts.txt
 * from its only caller, the bl at ov010 0x02169056 (w6_fix18).
 */
void MISC_SAVEDATA_FoldTally(Tally *tally)
{
    int i;

    for (i = 0; i < 30; i++) {
        tally->total32[i] += tally->add16[i];
        if (tally->total32[i] > 999999) {
            tally->total32[i] = 999999;
        }
        tally->add16[i] = 0;
    }
    for (i = 0; i < 150; i++) {
        tally->total16[i] += tally->add8[i];
        if (tally->total16[i] > 9999) {
            tally->total16[i] = 9999;
        }
        tally->add8[i] = 0;
    }
}











/*
 * Unlabelled arm9 leaf returning the constant 0x5C8 (a structure size); filed
 * as the relocation witness for ov021 callers 021D096C, 021D0BE4, 021D10A8
 * (wave A1).
 */
u32 BATTLE_EXAMINATION_GetBlockSize(void)
{
    return 0x5C8;
}











/*
 * Clears the 0x5C8-byte save block (BATTLE_EXAMINATION_GetBlockSize returns its size):
 * a tail call to MI_CpuFill8(p, 0, 0x5C8).
 */
void BATTLE_EXAMINATION_ClearBlock(void *p)
{
    MI_CpuFill8(p, 0, 0x5C8);
}











/*
 * The two tests share one exit, so they have to be one conjunction with the
 * `return 0` written after it; as two separate `if (...) return 0;` statements
 * the compiler emits two copies of the `movs r0, #0; pop` pair and lands 28
 * bytes wrong.  EXACT*: the listing extent runs to the next label at
 * 0x0200E688, over three unlabelled followers.
 */
int BATTLE_EXAMINATION_IsDeliveryValid(void *delivery)
{
    if (((struct TrialHouseDelivery *)delivery)->checksum == GF_STANDARD_SetupCalc(delivery, 0x5c6) &&
        ((struct TrialHouseDelivery *)delivery)->magic == 0xd68)
        return 1;
    return 0;
}











/*
 * Unlabelled arm9 leaf: true when bit 15 of the halfword at +0x5C4 is clear.
 * Filed as the relocation witness for ov021 TRIAL_HOUSE_LoadDeliveryState (wave A1).
 */
int BATTLE_EXAMINATION_IsDeliveryUnused(void *delivery)
{
    if (((struct TrialHouseDelivery *)delivery)->idAndUsed & 0x8000) {
        return 0;
    }
    return 1;
}











/*
 * Unlabelled arm9 leaf: the low seven bits of the halfword at +0x5C4. Filed
 * as the relocation witness for ov021 TRIAL_HOUSE_DeliveryTaskMain (wave A1).
 */
u16 BATTLE_EXAMINATION_GetDeliveryId(void *delivery)
{
    return ((struct TrialHouseDelivery *)delivery)->idAndUsed & 0x7F;
}











/*
 * Unlabelled arm9 leaf: element idx of a five-entry array of 0x120 byte
 * records, the base itself when idx is out of range. Filed as the relocation
 * witness for ov021 TRIAL_HOUSE_LoadDeliveredTrainer (wave A1).
 */
char *BATTLE_EXAMINATION_GetTrainerSlot(char *base, u32 index)
{
    if (index < 5) {
        base += index * 0x120;
    }
    return base;
}











/*
 * Unlabelled arm9 function: loads save block 5 into a 0x1000 byte heap buffer,
 * copies its first 0x5C8 bytes to dst, then starts a save of block 5 and spins
 * on OS_WaitIrq until it reports done. Filed as the relocation witness for
 * ov021 TRIAL_HOUSE_DeliveryTaskMain (wave A1).
 */
void BATTLE_EXAMINATION_LoadDelivery(void *gameData, void *dst, u32 heap)
{
    u32 sv = (u32)GAME_DATA_GetSaveControl(gameData);
    void *buf = func_02030734(heap, 0x1000, 0, data_020A721C, 0x99);

    SAVE_CONTROL_LoadExtraSaveWithBuffer(sv, 5, heap, buf, 0x1000);
    MI_CpuCopy8(dst, buf, 0x5C8);
    GAME_DATA_PartSaveStart(gameData, 5);
    for (;;) {
        if (GAME_DATA_PartSaveMain(gameData, 5) == 2) {
            break;
        }
        OS_WaitIrq(1, 1);
    }
    func_0200734C((struct Sub02007324Ctrl *)sv, 5);
    func_020307B0(buf);
}











/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: BATTLE_EXAMINATION_RefreshMarker toggles one flag half of a caller object's field pair
 * addressed by the constant id 0x5c6: it looks the field up through
 * GF_STANDARD_SetupCalc, and if the stored halfword at +0x5c6 already equals the
 * looked-up value, rewrites the paired halfword at +0x5c2 with the constant
 * 0x7da and refreshes +0x5c6 with a second lookup.  BATTLE_EXAMINATION_GetGreetingSize is an
 * unlabelled getter returning the constant 0x28, sitting in what disasm.py
 * printed as trailing data after BATTLE_EXAMINATION_RefreshMarker because it carries no
 * register-saving prologue; see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E684.c \
 *       --addr 0x0200E684 --thumb
 */
void BATTLE_EXAMINATION_RefreshMarker(void *delivery)
{
    u32 fieldId = 0x5c6;
    if (*(u16 *)((u8 *)delivery + fieldId) == GF_STANDARD_SetupCalc(delivery, fieldId)) {
        *(u16 *)((u8 *)delivery + (fieldId - 4)) = 0x7da;
        *(u16 *)((u8 *)delivery + fieldId) = GF_STANDARD_SetupCalc(delivery, fieldId);
    }
}











u32 BATTLE_EXAMINATION_GetGreetingSize(void)
{
    return 0x28;
}










/*
 * Promoted from src/pending/BATTLE_EXAMINATION_InitGreetings.c: every concrete byte was
 * already reproduced, and both callees were unresolved relocations
 * because each is called from exactly this one place in the whole ROM,
 * the case the honesty rule's cut remedy cannot reach (docs/MATCHING.md,
 * "the limit of the remedy"). Both are now EXACT entries in their own
 * right (src/matched/sub_020242A4.c's PMSI_PARAM_SetDefaultGreeting, and
 * src/matched/unit_020242D8.c's PMSI_PARAM_SetDefaultSentence), so the `matched` class
 * attests both calls without a second caller, and this file closes to
 * EXACT.
 *
 * Initialises obj, then calls a per-slot setup helper on four 8-byte
 * slots starting at obj+8, tagging each with its index 0..3.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BATTLE_EXAMINATION_InitGreetings.c \
 *       --func BATTLE_EXAMINATION_InitGreetings --addr 0x0200E6B4 --cc 1.1p1 --thumb
 */
void BATTLE_EXAMINATION_InitGreetings(void *greetings)
{
    PMSI_PARAM_SetDefaultGreeting(greetings);
    PMSI_PARAM_SetDefaultSentence((u8 *)greetings + 8, 0);
    PMSI_PARAM_SetDefaultSentence((u8 *)greetings + 0x10, 1);
    PMSI_PARAM_SetDefaultSentence((u8 *)greetings + 0x18, 2);
    greetings = (u8 *)greetings + 0x20;
    PMSI_PARAM_SetDefaultSentence(greetings, 3);
}










/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: a two-hop tail-call chain. SAVEDATA_GetExtraBlockThunk is a pure forwarder to
 * SAVEDATA_GetExtraBlock, which itself tail calls SAVE_CONTROL_GetBlock with a fixed id of
 * 0x3e; both pass their argument through unchanged. Neither carries a
 * register-saving prologue, so disasm.py's sweep does not label
 * SAVEDATA_GetExtraBlock and it prints as data between the two literal pools; see
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md and
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E6E8.c \
 *       --addr 0x0200E6E8 --thumb
 */
void *SAVEDATA_GetExtraBlockThunk(u32 saveData)
{
    return SAVEDATA_GetExtraBlock(saveData);
}










void *SAVEDATA_GetExtraBlock(u32 saveData)
{
    return SAVE_CONTROL_GetBlock((struct Sub020071CCCtrl *)saveData, 0x3e);
}










/*
 * One 8-byte record copied out: four u16 fields, so the copy unrolls to four
 * ldrh/strh pairs rather than an ldm/stm.  It has to be written as a struct
 * assignment: the same copy spelled field by field, or through a `u16 *`
 * temporary, picks the other register for the scaled index (r1 instead of
 * r3) and lands six bytes wrong.  EXACT*: the listing extent runs 192 bytes
 * because the follower at 0x0200E714 saves nothing and carries no label.
 */
void MISC_SAVEDATA_CopyQuadRecord(struct QuadRecord *src, int idx, struct QuadRecord *dst)
{
    *dst = src[idx];
}








/*
 * Unlabelled Thumb leaf that follows MISC_SAVEDATA_CopyQuadRecord: copy one 8-byte record to dst[idx].
 */
void MISC_SAVEDATA_StoreQuadRecord(struct QuadRecord *dst, int idx, struct QuadRecord *src)
{
    dst[idx] = *src;
}







/*
 * A whole translation unit, matched as one byte range.
 *
 *           MISC_SAVEDATA_IsMonEntrySet, MISC_SAVEDATA_GetMonEntryTag, MISC_SAVEDATA_GetMonEntryCost, MISC_SAVEDATA_GetMonEntryPid,
 *           MISC_SAVEDATA_GetMonEntryName, MISC_SAVEDATA_GetMonEntryExperience
 *
 * alias: ten accessors on an array of 0x20-byte records, indexed by idx into
 * base + idx*0x20. MISC_SAVEDATA_GetMonEntrySize/MISC_SAVEDATA_ClearMonEntry are the constant-getter and
 * fill-user pair seen elsewhere in this packet: MISC_SAVEDATA_GetMonEntrySize returns 0x40,
 * and MISC_SAVEDATA_ClearMonEntry zero-fills that many bytes at the given pointer.
 *
 * The byte at record offset +0x1a packs two fields, read by the next pair:
 * bit 0 is a plain flag (MISC_SAVEDATA_GetMonEntryFlag), and bits [7:1] are a level clamped
 * into [0x41, 0x64] (MISC_SAVEDATA_GetMonEntryLevel, which adds 5 to the raw value once it is
 * at least 0x41 and clamps the low end up to 0x41 otherwise). The two
 * fields are declared as one bitfield struct so the compiler's lsls
 * #0x18 / lsrs #0x19 extraction for the 7-bit field is generated directly
 * instead of re-derived as a mask; see
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md.
 *
 * MISC_SAVEDATA_IsMonEntrySet/MISC_SAVEDATA_GetMonEntryTag are a validity check and raw getter on the byte
 * at +0x1b (0xff means "unset"). MISC_SAVEDATA_GetMonEntryCost ignores its first argument
 * (r0) and looks at the second and third (r1, r2): it returns 0x23c when
 * r1 == 1, 0x222 when r2 == 0x15, and 0x224 otherwise, apparently a cost
 * table keyed by two flags. MISC_SAVEDATA_GetMonEntryPid/MISC_SAVEDATA_GetMonEntryName/MISC_SAVEDATA_GetMonEntryExperience are a
 * plain word getter at +0, a pointer-to-field getter at +4, and a plain
 * word getter at +0x1c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E730.c \
 *       --addr 0x0200E730 --thumb
 */
u32 MISC_SAVEDATA_GetMonEntrySize(void)
{
    return 0x40;
}







void MISC_SAVEDATA_ClearMonEntry(void *dest)
{
    MI_CpuFill8(dest, 0, 0x40);
}







u32 MISC_SAVEDATA_GetMonEntryFlag(const void *slots, u32 index)
{
    return ((const struct LevelFlagBits *)((const u8 *)slots + index * 0x20 + 0x1a))->flag;
}







u32 MISC_SAVEDATA_GetMonEntryLevel(const void *slots, u32 index)
{
    u32 level = ((const struct LevelFlagBits *)((const u8 *)slots + index * 0x20 + 0x1a))->level;
    if (level < 0x41) {
        level = 0x41;
    } else {
        level = (u8)(level + 5);
    }
    if (level > 0x64) {
        level = 0x64;
    }
    return level;
}







u32 MISC_SAVEDATA_IsMonEntrySet(const void *slots, u32 index)
{
    return *((const u8 *)slots + index * 0x20 + 0x1b) != 0xff;
}







u8 MISC_SAVEDATA_GetMonEntryTag(const void *slots, u32 index)
{
    return *((const u8 *)slots + index * 0x20 + 0x1b);
}







u32 MISC_SAVEDATA_GetMonEntryCost(const void *unused, u32 a, u32 b)
{
    if (a == 1) {
        return 0x23c;
    }
    if (b == 0x15) {
        return 0x222;
    }
    return 0x224;
}







u32 MISC_SAVEDATA_GetMonEntryPid(const void *slots, u32 index)
{
    return *(const u32 *)((const u8 *)slots + index * 0x20);
}







void *MISC_SAVEDATA_GetMonEntryName(void *slots, u32 index)
{
    return (u8 *)slots + index * 0x20 + 4;
}







u32 MISC_SAVEDATA_GetMonEntryExperience(const void *slots, u32 index)
{
    return *(const u32 *)((const u8 *)slots + index * 0x20 + 0x1c);
}









/*
 * Fill slot idx of the 0x20-byte-stride record array that unit_0200E730's
 * ten accessors read (level in bits 1..7 of +0x1a, a "set" flag in bit 0,
 * the +0x1b byte or 0xff, words at +0 and +0x1c, an 11-u16 name at +4)
 * from a Pokemon via func_02017E1C: fields 0x9e, 0x71/0xa, 0, 7, then the
 * nickname (0x74) when field 0x75 says there is one, else the species name
 * (field 5) read out of the message bank at gSpeciesNameBank into a stack buffer
 * and copied in.
 *
 * Two facts closed the 133-135-byte "pointer permutation" of the earlier
 * notes: the notes' struct had a stray pad byte before +0x1a (every field
 * from the bitfield on was one byte off), and every field is written as
 * o[idx].field rather than through a hoisted record pointer.  Written that
 * way mwcc keeps o and idx*32 in r5/r7 across all nine calls and CSEs
 * o + idx*32 into r4 for most, but not all, of the uses -- the image's
 * `adds r1, r5, r7` before the +0x1c store is exactly that.
 *
 * EXACT* because the listing extent runs over the unlabelled followers at
 * 0x0200E874/0x0200E878 (unit_0200E874.c); compiled bytes match exactly.
 */
void MISC_SAVEDATA_FillMonEntry(struct BoxMonSlot *slots, int index, void *mon)
{
    slots[index].bits.level = func_02017E1C(mon, 0x9e, 0);
    if (func_02017E1C(mon, 0x71, 0) != 0)
        slots[index].tag = func_02017E1C(mon, 0xa, 0);
    else
        slots[index].tag = 0xff;
    slots[index].pid = func_02017E1C(mon, 0, 0);
    slots[index].experience = func_02017E1C(mon, 7, 0);
    if (func_02017E1C(mon, 0x75, 0) != 0) {
        func_02017E1C(mon, 0x74, (u32)slots[index].name);
    } else {
        u16 buf[12];

        MSGDATA_ReadUnits(gSpeciesNameBank, func_02017E1C(mon, 5, 0), buf, 0xb);
        func_0201F41C(buf, slots[index].name, 0xb);
    }
    slots[index].bits.flag = 1;
}







/*
 * A whole translation unit, matched as one byte range.
 *
 * The twelve bytes after MISC_SAVEDATA_FillMonEntry: two unlabelled leaves that save
 * nothing at all, so their bytes print as part of the same `.word` run as
 * the pool word in front of them (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  The first is a size
 * getter returning 0x10, the second is a tail call to the SDK's
 * MI_CpuFill8 (arm: the pool word is even, so `bx r3` switches to ARM) that
 * clears 0x10 bytes from whatever pointer it is handed.
 */
int MISC_SAVEDATA_GetSmallEntrySize(void)
{
    return 0x10;
}







void MISC_SAVEDATA_ClearSmallEntry(void *dst)
{
    MI_CpuFill8(dst, 0, 0x10);
}








/*
 * A whole translation unit, matched as one byte range.
 *
 *           MISC_SAVEDATA_EmptyHook, MISC_SAVEDATA_GetScratchBase, MISC_SAVEDATA_GetFlags6200, MISC_SAVEDATA_SetFlags6200,
 *           MISC_SAVEDATA_GetMacSize, MISC_SAVEDATA_ClearMacArea, MISC_SAVEDATA_GetBlock41, MISC_SAVEDATA_InitMac
 *
 * alias: twelve functions on the same big object as unit_0200E938.c, all
 * working the same field at +0x6200/+0x6204.  MISC_SAVEDATA_SaveScratch16 and MISC_SAVEDATA_LoadScratch16
 * are a copy-in/copy-out pair around a 0x10-byte scratch object obtained
 * from SAVE_CONTROL_GetBlock(id 0x40); MISC_SAVEDATA_GetBigBlockSize hands back the constant 0x6204,
 * which MISC_SAVEDATA_ClearBigBlock uses as the zero-fill size for the whole object;
 * MISC_SAVEDATA_EmptyHook is an empty hook; MISC_SAVEDATA_GetScratchBase hands out the address 0x6000
 * bytes into the object; MISC_SAVEDATA_GetFlags6200/MISC_SAVEDATA_SetFlags6200 are a plain word
 * getter/setter on the field at +0x6200; MISC_SAVEDATA_GetMacSize returns the constant
 * 0x5c, which MISC_SAVEDATA_ClearMacArea's tail call to MI_CpuFill8 also uses directly
 * (the same 0x5c constant this compiler would otherwise route through
 * MISC_SAVEDATA_GetMacSize, but the tail call inlines it); MISC_SAVEDATA_GetBlock41 tail calls
 * SAVE_CONTROL_GetBlock(sys, 0x41); MISC_SAVEDATA_InitMac zero-fills a separate 0x5a-byte
 * scratch object and hands it to OS_GetMacAddress.
 *
 * Four of the twelve carry no label in the generated listing: they are
 * two- and three-instruction leaves with no register-saving prologue, so
 * disasm.py's sweep never fires on them and the listing prints them as a
 * run of .word data between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * This file merges what used to be four single-function files
 * (MISC_SAVEDATA_SaveScratch16.c, MISC_SAVEDATA_LoadScratch16.c, MISC_SAVEDATA_GetBigBlockSize.c, MISC_SAVEDATA_InitMac.c) and
 * unit_0200E8B8.c: the five are contiguous in the image with no gap and no
 * intervening matched/sdk address, and the whole 0x0200E884..0x0200E918
 * range still reproduces EXACT as a single translation unit.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E884.c \
 *       --addr 0x0200E884 --thumb
 */
void MISC_SAVEDATA_SaveScratch16(void *src, void *saveData)
{
    void *obj = SAVE_CONTROL_GetBlock(saveData, 0x40);
    MIi_CpuCopy32(src, obj, 0x10);
}








void MISC_SAVEDATA_LoadScratch16(void *src, void *dest)
{
    void *obj = SAVE_CONTROL_GetBlock(src, 0x40);
    MIi_CpuCopy32(obj, dest, 0x10);
}








u32 MISC_SAVEDATA_GetBigBlockSize(void)
{
    return 0x6204;
}








void MISC_SAVEDATA_ClearBigBlock(void *dest)
{
    MI_CpuFill8(dest, 0, MISC_SAVEDATA_GetBigBlockSize());
}








void MISC_SAVEDATA_EmptyHook(void)
{
}








void *MISC_SAVEDATA_GetScratchBase(void *saveData)
{
    return (u8 *)saveData + 0x6000;
}








u32 MISC_SAVEDATA_GetFlags6200(const void *saveData)
{
    return *(const u32 *)&((struct RecentValueSave *)saveData)->flags6200;
}








void MISC_SAVEDATA_SetFlags6200(void *saveData, u32 value)
{
    ((struct RecentValueSave *)saveData)->flags6200 = value;
}








u32 MISC_SAVEDATA_GetMacSize(void)
{
    return 0x5c;
}








void MISC_SAVEDATA_ClearMacArea(void *dest)
{
    MI_CpuFill8(dest, 0, 0x5c);
}








void *MISC_SAVEDATA_GetBlock41(void *saveData)
{
    return SAVE_CONTROL_GetBlock(saveData, 0x41);
}








void MISC_SAVEDATA_InitMac(void *buffer)
{
    MI_CpuFill8(buffer, 0, 0x5a);
    OS_GetMacAddress(buffer);
}








/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: a byte array at offset 6 of some base object, indexed by the second
 * parameter.  MISC_SAVEDATA_GetKeyByte is the plain getter; MISC_SAVEDATA_AddKeyByte adds a signed
 * delta to one element and clamps the result to 0..255 before storing it
 * back.  MISC_SAVEDATA_GetKeyByte has no register-saving prologue (two instructions, no
 * push), so disasm.py's sweep never labelled it; it sits in the listing as a
 * .word between two functions.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E918.c \
 *       --addr 0x0200E918 --thumb
 */
u8 MISC_SAVEDATA_GetKeyByte(const u8 *keys, u32 index)
{
    return (keys + index)[6];
}








void MISC_SAVEDATA_AddKeyByte(u8 *keys, u32 index, int delta)
{
    u8 *array = keys + 6;
    int value = array[index] + delta;

    if (value > 0xff) {
        value = 0xff;
    } else if (value < 0) {
        value = 0;
    }
    array[index] = (u8)value;
}








/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: three accessors on an array of 6-byte records that starts 0xa bytes
 * into the object, indexed by "id mod 10".  MISC_SAVEDATA_GetKey reads a record out,
 * MISC_SAVEDATA_SetKey stores one in, and MISC_SAVEDATA_SetKeyField writes a single byte field at
 * +0x10 past an extra caller-given offset from the same slot.  Each divides
 * by 10 for the remainder only; the
 * quotient the helper also returns is never used, per
 * docs/idioms/div-and-mod-are-two-calls.md and
 * docs/idioms/runtime-helper-reloc.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E938.c \
 *       --addr 0x0200E938 --thumb
 */
void MISC_SAVEDATA_GetKey(u8 *obj, u32 id, void *dest)
{
    u32 idx = id % 10;

    MI_CpuCopy8(obj + 0xa + idx * 8, dest, 6);
}








void MISC_SAVEDATA_SetKey(u8 *obj, u32 id, const void *src)
{
    u32 idx = id % 10;

    MI_CpuCopy8(src, obj + 0xa + idx * 8, 6);
}








void MISC_SAVEDATA_SetKeyField(u8 *obj, u32 id, u32 extra, u8 value)
{
    u32 idx = id % 10;
    u8 *p = obj + idx * 8;

    p += extra;
    p[0x10] = value;
}







/*
 * Linear search over up to 10 stored 6-byte keys: func_0200E918(base, 0)
 * gives the stored count (capped at 10), func_0200E938 copies the i'th key
 * into a stack buffer, and func_0203EFC8 (DWC's own key comparator)
 * compares it against the caller's key. Returns 1 on the first match, 0
 * if none of the stored keys match.
 *
 * EXACT* because the 70 compiled bytes fall six short of the disasm.py
 * extent: MISC_SAVEDATA_GetMacStructSize, a four-byte constant getter with no
 * register-saving prologue, hides in the two trailing pad bytes plus this
 * function's own alignment filler (see "the two missing labels" in
 * docs/MATCHING.md); it is matched separately.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MISC_SAVEDATA_FindKey.c \
 *       --func MISC_SAVEDATA_FindKey --addr 0x0200E994 --cc 1.1p1
 */
u32 MISC_SAVEDATA_FindKey(void *keys, void *key)
{
    int i;
    int count = func_0200E918(keys, 0);
    u8 buf[6];

    if (count > 10) {
        count = 10;
    }

    for (i = 0; i < count; i++) {
        func_0200E938(keys, i, buf);
        if (func_0203EFC8(key, buf, 6) == 0) {
            return 1;
        }
    }
    return 0;
}




/*
 * A four-byte constant getter with no register-saving prologue; it was
 * hiding as the unlabelled follower behind MISC_SAVEDATA_FindKey's EXACT* extent
 * (see docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md). Its own
 * follower, sub_0200E9E0, already carries a label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MISC_SAVEDATA_GetMacStructSize.c \
 *       --func MISC_SAVEDATA_GetMacStructSize --addr 0x0200E9DC --cc 1.1p1
 */
unsigned int MISC_SAVEDATA_GetMacStructSize(void)
{
    return 0x9c;
}






void MISC_SAVEDATA_InitMacAndStats(void *record)
{
    func_0200E904(record);
    BSUBWAY_SAVEDATA_InitStats((u8 *)record + 0x5a);
}






/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
void *MISC_SAVEDATA_GetBlock3C(void *saveData)
{
    return func_020071CC(saveData, 0x3c);
}





/*
 * Unlabelled leaf accessor matched to give overlay call sites a matched
 * witness.  Addresses are Black-image addresses.
 */
int MISC_SAVEDATA_GetStatsBase(int stats)
{
    return stats + 0x5a;
}





int MISC_SAVEDATA_GetStatsBase2(int stats)
{
    return stats + 0x5a;
}





int MISC_SAVEDATA_GetRecordBase(int stats)
{
    return stats;
}



u32 MISC_SAVEDATA_GetRingBlockSize(void)
{
    return 0x155C;
}



/*
 * Save-table size callback: returns 0x16C, the size of the block that
 * MISC_SAVEDATA_InitRecord clears.  Pointer word 0x0200EA15 at 0x0209DD44.
 */
u32 MISC_SAVEDATA_GetRecordSize(void)
{
    return 0x16C;
}



void MISC_SAVEDATA_ClearRingBlock(void *block)
{
    MI_CpuFill8(block, 0, 0x155C);
}




/*
 * Save-table init callback: clears the 0x16C-byte block (tail call to
 * MI_CpuFill8 through the pool word at 0x0200EA38).  Pointer word
 * 0x0200EA2D at 0x0209DD48.
 */
void MISC_SAVEDATA_InitRecord(void *block)
{
    MI_CpuFill8(block, 0, 0x16C);
}




/*
 * Snapshot of a party into a 0x16c-byte ring record (MISC_SAVEDATA_AppendPartyRecord's slot):
 * zero the six 0x3c-byte entries, then for every non-egg member (field 0x4c
 * of func_02017E1C is 0) store species (5), level (0x9e), the 6/2-bit pair
 * 0x6f/0x6e, fields 0 and 7, fields 0x36..0x39, and the nickname (0x73, 11
 * u16) and OT name (0x8d, 8 u16) through an 11-char string buffer, or the
 * terminator from STRBUF_GetEosChar in both name slots when the buffer could not
 * be allocated.  The date record (first three words) goes to +0x168.
 * The layout of struct Entry is the one MISC_SAVEDATA_ExportRecord (EXACT*) reads back.
 *
 * Levers: the loop counter i is initialised AFTER the memset and before
 * n (both zeroes are then scheduled across the call with i first, which is
 * what puts i at sp+0x14 and n at sp+0x10); the species store goes through
 * rec->e[n] and every later field through the named entry pointer.
 *
 * EXACT* only because the 402 compiled bytes stop two short of the listing
 * extent at a "movs r0, r0" alignment filler; no byte differs.
 */
void MISC_SAVEDATA_SnapshotParty(struct Rec *rec, void *party, struct Date *date, u32 heap)
{
    int count = POKEPARTY_GetCount(party);
    void *buf = STRBUF_Create(11, heap);
    int i;
    int n;

    MI_CpuFill8(rec, 0, 0x168);
    i = 0;
    n = 0;
    for (; i < count; i++) {
        void *mon = POKEPARTY_GetMember(party, i);
        u32 saved = POKE_TOOL_DecodePartyParam(mon);
        if (func_02017E1C(mon, 0x4c, 0) == 0) {
            struct Entry *e = &rec->e[n];
            rec->e[n].species = func_02017E1C(mon, 5, 0);
            e->level = func_02017E1C(mon, 0x9e, 0);
            e->form = func_02017E1C(mon, 0x6f, 0);
            e->gender = func_02017E1C(mon, 0x6e, 0);
            e->pid = func_02017E1C(mon, 0, 0);
            e->experience = func_02017E1C(mon, 7, 0);
            e->traits[0] = func_02017E1C(mon, 0x36, 0);
            e->traits[1] = func_02017E1C(mon, 0x37, 0);
            e->traits[2] = func_02017E1C(mon, 0x38, 0);
            e->traits[3] = func_02017E1C(mon, 0x39, 0);
            if (buf != 0) {
                func_02017E1C(mon, 0x73, (u32)buf);
                STRBUF_ToChars(buf, e->name, 11);
                func_02017E1C(mon, 0x8d, (u32)buf);
                STRBUF_ToChars(buf, e->ot, 8);
            } else {
                e->name[0] = STRBUF_GetEosChar();
                e->ot[0] = STRBUF_GetEosChar();
            }
            n++;
        }
        POKE_TOOL_EncodePartyParam(mon, saved);
    }
    rec->year = date->year;
    rec->month = date->month;
    rec->day = date->day;
    if (buf != 0) {
        STRBUF_Delete(buf);
    }
}




/*
 * Ring-buffer record dispatcher: while the saturating counter at +0x1558 is
 * below 9999, hand the 0x16c-byte record at slot +0x1554 to MISC_SAVEDATA_SnapshotParty,
 * then advance the slot (wrapping at 15) and the counter.
 *
 * The residue that stood for four passes (r6 vs r1, push one register
 * narrower) was the parameter list: MISC_SAVEDATA_SnapshotParty takes FOUR arguments
 * (its prologue homes r0..r3), and this function forwards its own r1..r3 to
 * it untouched.  With a1..a3 live in r1..r3 across the prologue the index
 * temporary cannot take r1 and lands in r6.  The only caller
 * (ov205 0x021B9B62) passes (obj, GAME_DATA_GetMyParty result, &stack date record
 * from RTC_GetDate, 4).  The slot index is read inline in the call's
 * argument, not through a named local.
 *
 * Current listing extent is 68 bytes; compiled bytes match exactly.
 */
void MISC_SAVEDATA_AppendPartyRecord(struct PartyRingSave *obj, void *party, void *date, u32 heap)
{
    if (obj->recordCount < 9999) {
        u32 slot;
        MISC_SAVEDATA_SnapshotParty((struct Rec *)((u8 *)obj + obj->writeIndex * 0x16c), party, date, heap);
        slot = obj->writeIndex + 1;
        obj->writeIndex = slot;
        if (slot >= 15) {
            obj->writeIndex = 0;
        }
        obj->recordCount += 1;
    }
}



/*
 * An unlabelled leaf: it saves nothing, so disasm.py's lr-saving prologue
 * sweep never fired and the bytes print as a run of `.word` in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Nothing in
 * the image branches to it either, so no `function_starts.txt` seed exists.
 * First zero halfword of six 0x3c-byte records.
 *
 * It is not an anonymous hole, though: MISC_SAVEDATA_GetRingRecordIndex (src/matched/
 * unit_0200EC98.c) tail-calls it through a pool word, which is why that file
 * could not resolve its one relocation until this entry existed -- the
 * `matched` class is the only witness 0x0200EC14 can ever have, since no
 * branch anywhere in the image names it and its address appears in exactly
 * one pool.
 */
int MISC_SAVEDATA_FindFreeRecordSlot(char *records)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (*(u16 *)(records + i * 0x3c) == 0)
            break;
    }
    return i;
}



/*
 * One record of a 0x3c-byte table copied into a destination object.
 *
 * This closes the 76-byte residue that docs/notes/pkt_0200EA3C.c.txt
 * section 2 recorded.  Three spellings had to hold at once:
 *
 *  1. the byte at source +3 is a `u8 :6 / u8 :2` bitfield PAIR, not a plain
 *     u8.  The source side is what produces the `lsls #26 / lsrs #26` pair
 *     the note could not reach; reading it as a plain u8 and shifting gives
 *     `ands` instead and compiles 104 bytes.
 *  2. the destination byte at +0x13 is the same bitfield pair.  That is what
 *     turns the insert into `movs r1, #0x3f; ands r1, r3` rather than a
 *     single immediate mask.  Both sides are needed: either one alone is
 *     still wrong.
 *  3. the source pointer must be `const`.  Without it, the store to
 *     dst->f13a may alias s->f03a, so mwcc reloads `ldrb [r4, #3]` a second
 *     time for the `:2` field, two bytes over at 110.  The original loads it
 *     once into r2 and keeps it live across the first insert.  See
 *     docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md.
 *
 * EXACT* : the inferred extent ran to 0x0200ECF0 because the accessor at
 * 0x0200EC98 saves no lr and so carries no label.  0x0200EC98 is an
 * unlabelled follower and wants seeding into layout/function_starts.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MISC_SAVEDATA_ExportRecord.c \
 *       --func MISC_SAVEDATA_ExportRecord --addr 0x0200EC2C --cc 1.1p1 --thumb
 */
void MISC_SAVEDATA_ExportRecord(const struct Entry *records, int index, struct RecordTarget *dst)
{
    const struct Entry *s = records + index;
    int i;

    dst->species = s->species;
    dst->level = s->level;
    dst->pid = s->pid;
    dst->experience = s->experience;
    dst->form = s->form;
    dst->gender = s->gender;

    STRBUF_SetStringN(dst->nicknameStr, (const u16 *)s->name, 0xb);
    STRBUF_SetStringN(dst->otNameStr, (const u16 *)s->ot, 8);

    for (i = 0; i < 4; i++)
        dst->traits[i] = s->traits[i];
}



/*
 * An unlabelled leaf accessor (it saves no lr, so disasm.py gives it no
 * label, see docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It unpacks the three fields at +0x168..+0x16b of the object into a
 * four-word output record and zeroes the fourth word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MISC_SAVEDATA_GetRecordDate.c \
 *       --func MISC_SAVEDATA_GetRecordDate --addr 0x0200EC98 --cc 1.1p1 --thumb
 */
void MISC_SAVEDATA_GetRecordDate(const u8 *record, struct RecordDate *out)
{
    out->year = ((const struct Rec *)record)->year;
    out->month = ((const struct Rec *)record)->month;
    out->day = ((const struct Rec *)record)->day;
    out->reserved = 0;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * The tail of this packet: three unlabelled accessors of the object
 * MISC_SAVEDATA_AppendPartyRecord and MISC_SAVEDATA_ExportRecord work on (their bytes print as `.word`
 * runs because none of them saves lr, see docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  The byte range here is
 * 0x0200ECB4..0x0200ECF0, its two leading pad bytes belong to
 * MISC_SAVEDATA_GetRecordDate (which is not part of this file), and the three pool words
 * between the functions are each function's own.
 *
 * MISC_SAVEDATA_GetRingRecordIndex is a tail call through a pool word to
 * src/matched/MISC_SAVEDATA_FindFreeRecordSlot.c, and the pool word is the only reference to
 * 0x0200EC14 anywhere in the image, so that entry is what makes this file
 * verifiable at all (the `matched` class).
 */
u32 MISC_SAVEDATA_GetRingIndex(char *ring)
{
    u32 count = ((struct PartyRingSave *)ring)->recordCount;

    if (count >= 0xf)
        count = 0xf;
    return count;
}



u32 MISC_SAVEDATA_GetRingRemaining(char *ring, u32 count)
{
    return ((struct PartyRingSave *)ring)->recordCount - count;
}



int MISC_SAVEDATA_GetRingRecordIndex(char *o, int idx)
{
    int n = ((struct PartyRingSave *)o)->writeIndex - 1 - idx;

    if (n < 0)
        n += 0xf;
    return sub_0200EC14(o + n * 0x16c);
}



void MISC_SAVEDATA_ExportRingRecord(void *ring, u32 index, void *recordIndex, void *target)
{
    int slot = ((struct PartyRingSave *)ring)->writeIndex - 1 - (int)index;

    if (slot < 0)
        slot += 0xf;
    MISC_SAVEDATA_ExportRecord((const struct Entry *)((u8 *)ring + slot * 0x16c), (int)recordIndex, target);
}



/*
 * An unlabelled accessor (its bytes print as a `.word` run after the pool
 * of MISC_SAVEDATA_ExportRingRecord): the header of ring entry `count - 1 - idx`, a tail call
 * to MISC_SAVEDATA_GetRecordDate through a pool word. Same shape as MISC_SAVEDATA_GetRingRecordIndex in
 * unit_0200ECB4.c. Its only caller is ov171 DENDOU_VIEW_LoadHallOfFame.
 */
void MISC_SAVEDATA_GetRingRecordDate(u8 *ring, int index, void *out)
{
    int slot = *(int *)(ring + 0x1554) - 1 - index;

    if (slot < 0)
        slot += 0xf;
    MISC_SAVEDATA_GetRecordDate(ring + slot * 0x16c, out);
}



/*
 * Save-table size callback: returns 0xFC, the size of the block that
 * MISC_SAVEDATA_InitShortBlock clears.  Pointer word 0x0200ED39 at 0x0209DD5C.
 */
u32 MISC_SAVEDATA_GetShortBlockSize(void)
{
    return 0xFC;
}



/*
 * Save-table init callback: clears the 0xFC-byte block (tail call to
 * MI_CpuFill8 through the pool word at 0x0200ED44).  Pointer word
 * 0x0200ED3D at 0x0209DD60.
 */
void MISC_SAVEDATA_InitShortBlock(void *block)
{
    MI_CpuFill8(block, 0, 0xFC);
}



void *MISC_SAVEDATA_GetBlock44(void *saveData)
{
    return func_020071CC(saveData, 0x44);
}



/*
 * Insert `val` into a 32-entry u32 list unless it is already there: the
 * table is the object's first 0x80 bytes and the count lives at +0x80.
 * When the value is found at index i, everything above it shifts up one
 * slot (the memmove) and the value is rewritten into the last live slot
 * (`p[-1]` on a pointer to one past the end), so the list keeps its
 * length; when it is not found and there is room it goes at the end, and
 * when the list is full the whole table shifts up one slot and the value
 * lands in slot 31.
 *
 * Two shapes the bytes pinned down, both from
 * docs/idioms/pointer-minus-one-scales-before-the-subtraction.md and the
 * signed/unsigned split:
 *
 *  - the copy is MI_CpuCopy8(src, dst, size) -- the SDK's argument order,
 *    which is why the source passes the higher index first: the shift is
 *    downward, arr[i+1] is copied onto arr[i];
 *  - the trailing store is NOT `l->values[l->count - 1]` (which subtracts one
 *    from the count and then scales) but `p[-1]` on a pointer computed as
 *    `l->values + l->count`: the original scales the count by four first and
 *    subtracts the element size afterwards, four instructions against
 *    three and the whole tail shifts;
 *  - the walk is unsigned (`bls`/`blo`) while the element count `n` that
 *    gates the shift is signed (`ble`).
 *
 * EXACT* rather than EXACT: the follower at 0x0200EDC4 saves registers but
 * not lr, so disasm.py did not label it (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md) and the inferred extent
 * runs to 0x0200EE48. The bytes all match; see
 * src/matched/unit_0200EDC4.c for that follower, which this project can
 * reproduce but has not been able to seed in layout/function_starts.txt.
 */
void MISC_SAVEDATA_InsertRecentValue(struct RecentValueSave *list, u32 value)
{
    u32 index;
    int shiftCount;

    for (index = 0; index < list->count; index++) {
        if (list->values[index] != value)
            continue;
        shiftCount = (int)list->count - 1 - (int)index;
        if (shiftCount <= 0)
            return;
        MI_CpuCopy8(&list->values[index + 1], &list->values[index], (u32)shiftCount * 4);
        {
            u32 *end = list->values + list->count;
            end[-1] = value;
        }
        return;
    }

    if (list->count < 32) {
        list->values[list->count] = value;
        list->count++;
        return;
    }

    MI_CpuCopy8(&list->values[1], &list->values[0], 0x7c);
    list->values[31] = value;
    list->count = 32;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * The three functions that follow MISC_SAVEDATA_InsertRecentValue (src/matched/
 * MISC_SAVEDATA_InsertRecentValue.c) inside this packet, none of which carries a label in
 * the generated listing: 0x0200EDC4 saves registers but not lr, and the
 * other two save nothing, so disasm.py's lr-saving prologue sweep never
 * fired on any of them and they print as runs of `.word` (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  Nothing branches to
 * them either: the only references are the calls from the two functions
 * just past the end of the range.
 *
 * 0x0200EDC4, 40 bytes, is `contains` on the same 32-entry list
 * MISC_SAVEDATA_InsertRecentValue inserts into, and 0x0200EDEC / 0x0200EE14 are the
 * get-bit and set-bit pair of a 256-bit bitmap at +0x84 of the same
 * object, both written with a signed index (`/ 32` and `% 32`, which is
 * what the `asrs`/`rors` pair is).
 */
int MISC_SAVEDATA_ContainsRecentValue(struct RecentValueSave *list, u32 value)
{
    u32 index;

    for (index = 0; index < list->count; index++) {
        if (list->values[index] == value)
            return 1;
    }
    return 0;
}


int MISC_SAVEDATA_TestBitmapBit(char *list, int bitIndex)
{
    u32 *bitmap = (u32 *)(list + 0x84);

    return (bitmap[bitIndex / 32] >> (bitIndex % 32)) & 1;
}


void MISC_SAVEDATA_SetBitmapBit(char *list, int bitIndex)
{
    if (bitIndex >= 256)
        return;
    ((u32 *)(list + 0x84))[bitIndex / 32] |= (u32)(1 << (bitIndex % 32));
}
