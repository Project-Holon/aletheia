/*
 * function: TR_TOOL_BuildParty
 * address:  0x0202A4B4
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

typedef struct {
    u8  type;
    u8  cls;
    u8  f02;
    u8  count;
    u8  rest[0x10];
} TrData;

typedef struct { u8 dv; u8 abil; u16 level; u16 species; u16 form; } TrMon0;
typedef struct { u8 dv; u8 abil; u16 level; u16 species; u16 form; u16 moves[4]; } TrMon1;
typedef struct { u8 dv; u8 abil; u16 level; u16 species; u16 form; u16 item; } TrMon2;
typedef struct { u8 dv; u8 abil; u16 level; u16 species; u16 form; u16 item; u16 moves[4]; } TrMon3;

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
extern void  func_0202A994(u32 species, u32 form, int abil, u32 *gender, u16 heap);
extern void  func_0202A9F4(u32 id, void *mon, u32 form, u32 abil);
extern void POKE_TOOL_SetupPartyParamEx(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void  POKE_TOOL_SetPartyValue(void *mon, u32 id, u32 val);
extern void POKE_TOOL_SetMoveSlot(void *p, u16 move, u32 slot);

void TR_TOOL_BuildParty(u32 trid, void *party, u16 heap)
{
    u32 gender;
    TrData *td;
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
    if (TPOKE_DATA_GetGenderValue(td->cls) == 1) {
        gender = 0x78;
    } else {
        gender = 0x88;
    }

    switch (td->type) {
    case 0: {
        int dv;
        u16 level;
        u16 species;

        for (i = 0; i < td->count; i++) {
            func_0202A994(((TrMon0 *)tp)[i].species, ((TrMon0 *)tp)[i].form, ((TrMon0 *)tp)[i].abil, &gender, heap);
            level = ((TrMon0 *)tp)[i].level;
            dv = ((TrMon0 *)tp)[i].dv;
            species = ((TrMon0 *)tp)[i].species;
            pid = dv + level + species + trid;
            seed = pid;
            for (j = 0; j < td->cls; j++) {
                seed = seed * 0x5D588B656C078965LL + 0x269EC3;
                pid = (u32)((((u64)seed >> 32) * 0x10000) >> 32);
            }
            pid = (pid << 8) + gender;
            iv = (u8)(dv * 31 / 255);
            POKE_TOOL_SetupPartyParamEx(mon, species, level, 0xFFFFFFFF00000000ULL,
                          (iv & 31) | ((iv & 31) << 5) | ((iv & 31) << 10) | ((iv & 31) << 15) | ((iv & 31) << 20) | ((iv & 31) << 25),
                          pid);
            func_0202A9F4(trid, mon, ((TrMon0 *)tp)[i].form, ((TrMon0 *)tp)[i].abil);
            POKEPARTY_Add(party, mon);
        }
        break;
    }
    case 1: {
        int dv;
        u16 level;
        u16 species;

        for (i = 0; i < td->count; i++) {
            func_0202A994(((TrMon1 *)tp)[i].species, ((TrMon1 *)tp)[i].form, ((TrMon1 *)tp)[i].abil, &gender, heap);
            level = ((TrMon1 *)tp)[i].level;
            dv = ((TrMon1 *)tp)[i].dv;
            species = ((TrMon1 *)tp)[i].species;
            pid = dv + level + species + trid;
            seed = pid;
            for (j = 0; j < td->cls; j++) {
                seed = seed * 0x5D588B656C078965LL + 0x269EC3;
                pid = (u32)((((u64)seed >> 32) * 0x10000) >> 32);
            }
            pid = (pid << 8) + gender;
            iv = (u8)(dv * 31 / 255);
            POKE_TOOL_SetupPartyParamEx(mon, species, level, 0xFFFFFFFF00000000ULL,
                          (iv & 31) | ((iv & 31) << 5) | ((iv & 31) << 10) | ((iv & 31) << 15) | ((iv & 31) << 20) | ((iv & 31) << 25),
                          pid);
            for (j = 0; j < 4; j++) {
                POKE_TOOL_SetMoveSlot(mon, ((TrMon1 *)tp)[i].moves[j], (u8)j);
            }
            func_0202A9F4(trid, mon, ((TrMon1 *)tp)[i].form, ((TrMon1 *)tp)[i].abil);
            POKEPARTY_Add(party, mon);
        }
        break;
    }
    case 2: {
        int dv;
        u16 level;
        u16 species;

        for (i = 0; i < td->count; i++) {
            func_0202A994(((TrMon2 *)tp)[i].species, ((TrMon2 *)tp)[i].form, ((TrMon2 *)tp)[i].abil, &gender, heap);
            level = ((TrMon2 *)tp)[i].level;
            dv = ((TrMon2 *)tp)[i].dv;
            species = ((TrMon2 *)tp)[i].species;
            pid = dv + level + species + trid;
            seed = pid;
            for (j = 0; j < td->cls; j++) {
                seed = seed * 0x5D588B656C078965LL + 0x269EC3;
                pid = (u32)((((u64)seed >> 32) * 0x10000) >> 32);
            }
            pid = (pid << 8) + gender;
            iv = (u8)(dv * 31 / 255);
            POKE_TOOL_SetupPartyParamEx(mon, species, level, 0xFFFFFFFF00000000ULL,
                          (iv & 31) | ((iv & 31) << 5) | ((iv & 31) << 10) | ((iv & 31) << 15) | ((iv & 31) << 20) | ((iv & 31) << 25),
                          pid);
            POKE_TOOL_SetPartyValue(mon, 6, ((TrMon2 *)tp)[i].item);
            func_0202A9F4(trid, mon, ((TrMon2 *)tp)[i].form, ((TrMon2 *)tp)[i].abil);
            POKEPARTY_Add(party, mon);
        }
        break;
    }
    case 3: {
        int dv;
        u16 level;
        u16 species;

        for (i = 0; i < td->count; i++) {
            func_0202A994(((TrMon3 *)tp)[i].species, ((TrMon3 *)tp)[i].form, ((TrMon3 *)tp)[i].abil, &gender, heap);
            level = ((TrMon3 *)tp)[i].level;
            dv = ((TrMon3 *)tp)[i].dv;
            species = ((TrMon3 *)tp)[i].species;
            pid = dv + level + species + trid;
            seed = pid;
            for (j = 0; j < td->cls; j++) {
                seed = seed * 0x5D588B656C078965LL + 0x269EC3;
                pid = (u32)((((u64)seed >> 32) * 0x10000) >> 32);
            }
            pid = (pid << 8) + gender;
            iv = (u8)(dv * 31 / 255);
            POKE_TOOL_SetupPartyParamEx(mon, ((TrMon3 *)tp)[i].species, level, 0xFFFFFFFF00000000ULL,
                          (iv & 31) | ((iv & 31) << 5) | ((iv & 31) << 10) | ((iv & 31) << 15) | ((iv & 31) << 20) | ((iv & 31) << 25),
                          pid);
            POKE_TOOL_SetPartyValue(mon, 6, ((TrMon3 *)tp)[i].item);
            for (j = 0; j < 4; j++) {
                POKE_TOOL_SetMoveSlot(mon, ((TrMon3 *)tp)[i].moves[j], (u8)j);
            }
            func_0202A9F4(trid, mon, ((TrMon3 *)tp)[i].form, ((TrMon3 *)tp)[i].abil);
            POKEPARTY_Add(party, mon);
        }
        break;
    }
    }
    func_020307B0(td);
    func_020307B0(tp);
    func_020307B0(mon);
}
