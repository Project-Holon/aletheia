/*
 * file:     tr_tool.c
 * unit:     yes
 * function: TR_TOOL_LoadTrainerInfo, TR_TOOL_BuildParty
 * address:  0x0202A440
 * packet:   pkt_0202A4B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_020A76DC     0x020A76DC  data
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   POKEPARTY_InitEx  0x0201A954  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb
 *   TPOKE_DATA_ReadRecord  0x0202A3AC  thumb
 *   TPOKE_DATA_ReadParty  0x0202A3BC  thumb
 *   TPOKE_DATA_GetGenderValue  0x0202A3CC  thumb
 *   func_0202A994  0x0202A994  thumb
 *   func_0202A9F4  0x0202A9F4  thumb
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_SetMoveSlot  0x020181F4  thumb
 *   _ll_mul        0x0209C054  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   PMSI_PARAM_ClearSentence  0x0202428C  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *
 * tr_tool.c: build a trainer's party.  Loads the trainer record (0x14
 * bytes) and its party table (up to 6 entries) from the archive, then per
 * entry: form/gender adjust (func_0202A994), a personality seeded from
 * dv + level + species + trainer id and stepped cls times through the
 * 64-bit LCG (mul 0x5D588B656C078965, add 0x269EC3, top 16 bits taken as
 * ((u64)(seed >> 32) * 0x10000) >> 32), IVs dv * 31 / 255 in all six
 * slots, then the per-type extras: type 1 moves, type 2 item, type 3 item
 * and moves.  Entry strides 8, 16, 10, 18 bytes.
 *
 * Shape facts that the allocator depends on (each one measured):
 *  - pid, seed, j and iv are function-scope; dv, level and species are
 *    declared in each case block (per-case stack homes);
 *  - the party table is read as ((TrMonN *)tp)[i] everywhere, no typed
 *    local pointer;
 *  - pid is one variable for the seed sum, the random draw and the final
 *    personality (it is what keeps the draw out of a callee-saved
 *    register);
 *  - the random draw's (u64)(u32) product by 0x10000 is what leaves the
 *    `lsls rX, zero, #16; orrs` pair and the hoisted zero;
 *  - case 3 passes the species to POKE_TOOL_SetupPartyParamEx as a fresh table read.
 */

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
typedef signed int         s32;

/* The 0x14-byte trainer record read from archive member 0x5c.  Both
 * TR_TOOL_LoadTrainerInfo and TR_TOOL_BuildParty read the same record, so it is one
 * struct: partyType/genderClass/partyCount are the party builder's view,
 * data04/data0C are the trainer-info view (data04 is the 8 bytes copied to
 * the info record, data0C the word stored there). */
typedef struct {
    u8  partyType;
    u8  genderClass;
    u8  pad02;
    u8  partyCount;
    u8  data04[8];
    u32 data0C;
    u32 data10;
} TrTrainerRecord;

typedef struct { u8 dv; u8 ability; u16 level; u16 species; u16 form; } TrPartyMon;
typedef struct { u8 dv; u8 ability; u16 level; u16 species; u16 form; u16 moves[4]; } TrPartyMonMoves;
typedef struct { u8 dv; u8 ability; u16 level; u16 species; u16 form; u16 item; } TrPartyMonItem;
typedef struct { u8 dv; u8 ability; u16 level; u16 species; u16 form; u16 item; u16 moves[4]; } TrPartyMonItemMoves;

extern char  g_020A76DC[];

extern void *func_02030734(u16 heap, u32 size, u32 align, const char *file, u32 line);
extern u32 func_020307B0(void *p);
struct Mon;
struct Party;
struct PartyMon;
extern void POKEPARTY_InitEx(struct Party *p, s32 capacity);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern u32   POKE_TOOL_GetPartyParamSize(void);
extern void TPOKE_DATA_ReadRecord(void *a0, void *a1);
extern void TPOKE_DATA_ReadParty(void *a0, void *a1);
extern u8    TPOKE_DATA_GetGenderValue(u32 cls);
extern void  func_0202A994(u32 species, u32 form, int ability, u32 *gender, u16 heap);
extern void  func_0202A9F4(u32 id, void *mon, u32 form, u32 ability);
extern void POKE_TOOL_SetupPartyParamEx(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void  POKE_TOOL_SetPartyValue(void *mon, u32 id, u32 val);
extern void POKE_TOOL_SetMoveSlot(void *p, u16 move, u32 slot);

typedef struct {
    u32 trainerId;    /* +0x00 the trainer id this record was loaded for */
    u32 genderClass;  /* +0x04 copied from the record's genderClass byte */
    u32 data0C;       /* +0x08 copied from the record's data0C word */
    u32 data04[2];    /* +0x0C the record's 8 data04 bytes, copied verbatim */
    u32 name;         /* +0x14 destination buffer for the trainer name string */
    u32 sentence[2];  /* +0x18 PmsData easy-chat sentence (2 words) */
    u32 sentence2[2]; /* +0x20 PmsData easy-chat sentence (2 words) */
} TrTrainerInfo;

struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u32 MSGDATA_Delete(struct MsgBank *rec);
extern void  MIi_CpuCopy16(const void *src, void *dest, u32 size);
extern void  PMSI_PARAM_ClearSentence(void *p);
void TR_TOOL_LoadTrainerInfo(u32 id, TrTrainerInfo *out, u16 heap);

/*
 * The __FILE__ argument at 0x020A76DC is the tr_tool.c anchor recorded in
 * layout/file_anchors.txt for this range; it is pinned by address, not
 * spelled as a literal __FILE__
 * (docs/idioms/file-string-is-an-abs32-into-the-string-area.md).
 */
void TR_TOOL_LoadTrainerInfo(u32 id, TrTrainerInfo *out, u16 heap)
{
    TrTrainerRecord *t;
    void *bank;

    t = func_02030734(heap, 0x14, 0, g_020A76DC, 0x159);
    TPOKE_DATA_ReadRecord((void *)id, t);

    out->trainerId = id;
    out->genderClass = t->genderClass;
    out->data0C = t->data0C;

    bank = func_02045B38(0, 2, 0xbe, heap);
    MSGDATA_ReadString(bank, id, (void *)out->name);
    MSGDATA_Delete(bank);

    MIi_CpuCopy16(t->data04, &out->data04, 8);
    PMSI_PARAM_ClearSentence(&out->sentence);
    PMSI_PARAM_ClearSentence(&out->sentence2);

    func_020307B0(t);
}

/*
 * tr_tool.c: build a trainer's party.  Loads the trainer record (0x14
 * bytes) and its party table (up to 6 entries) from the archive, then per
 * entry: form/gender adjust (func_0202A994), a personality seeded from
 * dv + level + species + trainer id and stepped cls times through the
 * 64-bit LCG (mul 0x5D588B656C078965, add 0x269EC3, top 16 bits taken as
 * ((u64)(seed >> 32) * 0x10000) >> 32), IVs dv * 31 / 255 in all six
 * slots, then the per-type extras: type 1 moves, type 2 item, type 3 item
 * and moves.  Entry strides 8, 16, 10, 18 bytes.
 *
 * Shape facts that the allocator depends on (each one measured):
 *  - pid, seed, j and iv are function-scope; dv, level and species are
 *    declared in each case block (per-case stack homes);
 *  - the party table is read as ((TrMonN *)tp)[i] everywhere, no typed
 *    local pointer;
 *  - pid is one variable for the seed sum, the random draw and the final
 *    personality (it is what keeps the draw out of a callee-saved
 *    register);
 *  - the random draw's (u64)(u32) product by 0x10000 is what leaves the
 *    `lsls rX, zero, #16; orrs` pair and the hoisted zero;
 *  - case 3 passes the species to POKE_TOOL_SetupPartyParamEx as a fresh table read.
 */
void TR_TOOL_BuildParty(u32 trid, void *party, u16 heap)
{
    u32 gender;
    TrTrainerRecord *td;
    int i;
    void *tp;
    void *mon;
    int h;
    u32 pid;
    long long seed;
    int j;
    u32 iv;

    POKEPARTY_InitEx(party, 6);
    h = (heap & 0x7FFF) | 0x8000;
    td = func_02030734(h, 0x14, 0, g_020A76DC, 387);
    tp = func_02030734(h, 0x6C, 0, g_020A76DC, 388);
    mon = func_02030734(h, POKE_TOOL_GetPartyParamSize(), 0, g_020A76DC, 389);
    TPOKE_DATA_ReadRecord((void *)trid, td);
    TPOKE_DATA_ReadParty((void *)trid, tp);
    if (TPOKE_DATA_GetGenderValue(td->genderClass) == 1) {
        gender = 0x78;
    } else {
        gender = 0x88;
    }

    switch (td->partyType) {
    case 0: {
        int dv;
        u16 level;
        u16 species;

        for (i = 0; i < td->partyCount; i++) {
            func_0202A994(((TrPartyMon *)tp)[i].species, ((TrPartyMon *)tp)[i].form, ((TrPartyMon *)tp)[i].ability, &gender, heap);
            level = ((TrPartyMon *)tp)[i].level;
            dv = ((TrPartyMon *)tp)[i].dv;
            species = ((TrPartyMon *)tp)[i].species;
            pid = dv + level + species + trid;
            seed = pid;
            for (j = 0; j < td->genderClass; j++) {
                seed = seed * 0x5D588B656C078965LL + 0x269EC3;
                pid = (u32)((((u64)seed >> 32) * 0x10000) >> 32);
            }
            pid = (pid << 8) + gender;
            iv = (u8)(dv * 31 / 255);
            POKE_TOOL_SetupPartyParamEx(mon, species, level, 0xFFFFFFFF00000000ULL,
                          (iv & 31) | ((iv & 31) << 5) | ((iv & 31) << 10) | ((iv & 31) << 15) | ((iv & 31) << 20) | ((iv & 31) << 25),
                          pid);
            func_0202A9F4(trid, mon, ((TrPartyMon *)tp)[i].form, ((TrPartyMon *)tp)[i].ability);
            POKEPARTY_Add(party, mon);
        }
        break;
    }
    case 1: {
        int dv;
        u16 level;
        u16 species;

        for (i = 0; i < td->partyCount; i++) {
            func_0202A994(((TrPartyMonMoves *)tp)[i].species, ((TrPartyMonMoves *)tp)[i].form, ((TrPartyMonMoves *)tp)[i].ability, &gender, heap);
            level = ((TrPartyMonMoves *)tp)[i].level;
            dv = ((TrPartyMonMoves *)tp)[i].dv;
            species = ((TrPartyMonMoves *)tp)[i].species;
            pid = dv + level + species + trid;
            seed = pid;
            for (j = 0; j < td->genderClass; j++) {
                seed = seed * 0x5D588B656C078965LL + 0x269EC3;
                pid = (u32)((((u64)seed >> 32) * 0x10000) >> 32);
            }
            pid = (pid << 8) + gender;
            iv = (u8)(dv * 31 / 255);
            POKE_TOOL_SetupPartyParamEx(mon, species, level, 0xFFFFFFFF00000000ULL,
                          (iv & 31) | ((iv & 31) << 5) | ((iv & 31) << 10) | ((iv & 31) << 15) | ((iv & 31) << 20) | ((iv & 31) << 25),
                          pid);
            for (j = 0; j < 4; j++) {
                POKE_TOOL_SetMoveSlot(mon, ((TrPartyMonMoves *)tp)[i].moves[j], (u8)j);
            }
            func_0202A9F4(trid, mon, ((TrPartyMonMoves *)tp)[i].form, ((TrPartyMonMoves *)tp)[i].ability);
            POKEPARTY_Add(party, mon);
        }
        break;
    }
    case 2: {
        int dv;
        u16 level;
        u16 species;

        for (i = 0; i < td->partyCount; i++) {
            func_0202A994(((TrPartyMonItem *)tp)[i].species, ((TrPartyMonItem *)tp)[i].form, ((TrPartyMonItem *)tp)[i].ability, &gender, heap);
            level = ((TrPartyMonItem *)tp)[i].level;
            dv = ((TrPartyMonItem *)tp)[i].dv;
            species = ((TrPartyMonItem *)tp)[i].species;
            pid = dv + level + species + trid;
            seed = pid;
            for (j = 0; j < td->genderClass; j++) {
                seed = seed * 0x5D588B656C078965LL + 0x269EC3;
                pid = (u32)((((u64)seed >> 32) * 0x10000) >> 32);
            }
            pid = (pid << 8) + gender;
            iv = (u8)(dv * 31 / 255);
            POKE_TOOL_SetupPartyParamEx(mon, species, level, 0xFFFFFFFF00000000ULL,
                          (iv & 31) | ((iv & 31) << 5) | ((iv & 31) << 10) | ((iv & 31) << 15) | ((iv & 31) << 20) | ((iv & 31) << 25),
                          pid);
            POKE_TOOL_SetPartyValue(mon, 6, ((TrPartyMonItem *)tp)[i].item);
            func_0202A9F4(trid, mon, ((TrPartyMonItem *)tp)[i].form, ((TrPartyMonItem *)tp)[i].ability);
            POKEPARTY_Add(party, mon);
        }
        break;
    }
    case 3: {
        int dv;
        u16 level;
        u16 species;

        for (i = 0; i < td->partyCount; i++) {
            func_0202A994(((TrPartyMonItemMoves *)tp)[i].species, ((TrPartyMonItemMoves *)tp)[i].form, ((TrPartyMonItemMoves *)tp)[i].ability, &gender, heap);
            level = ((TrPartyMonItemMoves *)tp)[i].level;
            dv = ((TrPartyMonItemMoves *)tp)[i].dv;
            species = ((TrPartyMonItemMoves *)tp)[i].species;
            pid = dv + level + species + trid;
            seed = pid;
            for (j = 0; j < td->genderClass; j++) {
                seed = seed * 0x5D588B656C078965LL + 0x269EC3;
                pid = (u32)((((u64)seed >> 32) * 0x10000) >> 32);
            }
            pid = (pid << 8) + gender;
            iv = (u8)(dv * 31 / 255);
            POKE_TOOL_SetupPartyParamEx(mon, ((TrPartyMonItemMoves *)tp)[i].species, level, 0xFFFFFFFF00000000ULL,
                          (iv & 31) | ((iv & 31) << 5) | ((iv & 31) << 10) | ((iv & 31) << 15) | ((iv & 31) << 20) | ((iv & 31) << 25),
                          pid);
            POKE_TOOL_SetPartyValue(mon, 6, ((TrPartyMonItemMoves *)tp)[i].item);
            for (j = 0; j < 4; j++) {
                POKE_TOOL_SetMoveSlot(mon, ((TrPartyMonItemMoves *)tp)[i].moves[j], (u8)j);
            }
            func_0202A9F4(trid, mon, ((TrPartyMonItemMoves *)tp)[i].form, ((TrPartyMonItemMoves *)tp)[i].ability);
            POKEPARTY_Add(party, mon);
        }
        break;
    }
    }
    func_020307B0(td);
    func_020307B0(tp);
    func_020307B0(mon);
}
