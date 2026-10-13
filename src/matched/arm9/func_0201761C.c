/*
 * function: POKE_TOOL_SetupBoxParamEx
 * address:  0x0201761C
 * packet:   pkt_0201756C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_ClearBoxParam  0x02017550  thumb
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb
 *   func_02019C54  0x02019C54  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_0203F0A8  0x0203F0A8  arm
 *   POKE_TOOL_SetBoxValue  0x02017E64  thumb
 *   POKE_TOOL_CheckShiny  0x02017ED8  thumb
 *   MSGDATA_ReadUnits  0x02045F5C  arm
 *   POKE_TOOL_GetExpForLevel  0x02018584  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   func_02019C7C  0x02019C7C  thumb
 *   POKE_TOOL_GetBoxGender  0x02017F08  thumb
 *   POKE_TOOL_SetBoxDefaultMoves  0x02017FB0  thumb
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb
 *   GAME_LANGUAGE_Code      0x0209DF0C  data  a1
 *   gSpeciesNameBank       0x020A7370  data
 *   gNameBuf       0x021462F0  data
 *   GAME_VERSION_Code      0x0209DF08  data  a1
 *
 * Initialise a record's block area: species, level, a 64-bit trainer id and
 * a 64-bit personality with two sentinel values each, and packed IVs (or
 * 0xFFFFFFFF for six fresh draws).  Wave 11, 2026-09-23.  The levers
 * that closed it after 2026-09-21's 612-against-700 DIFF:
 *   - the 4th parameter is a u64 `id` straddling r3 and the first stack
 *     word; the 7th is a u64 `rnd`.  Sentinels: id == ~0 (draw a fresh one),
 *     id == 0xFFFFFFFF00000000 (search for a non-shiny id: the
 *     POKE_TOOL_CheckShiny retry loop, `id = (u32)(rnd + 1)` then
 *     `id = (id + 1) & 0xFFFFFFFF`); rnd == 0xFFFFFFFF00000000 (draw),
 *     rnd == 0xFFFFFFFF00000001 (take id).  Callers 0x0201756C/0x02017600
 *     pass pow = -1, rnd = 0xFFFFFFFF00000000.
 *   - the IV draws are `(u64)func_0203F0A8() * 32 >> 32`
 *     (docs/idioms/random-below-n-is-a-64-bit-multiply-high.md).
 *   - POKE_TOOL_ClearBoxParam takes `obj` (it is unit_02017528.c's area clear).  The
 *     last ten prologue bytes (r1 vs r0 as the scratch for the stack-param
 *     home rewrite) came from that alone: r0 must survive to the call.
 *     The permuter (hill 800 + anneal 1000, --types) could not move them.
 *   - 0x020A7370 is gSpeciesNameBank (a pointer, dereferenced), 0x021462F0 is
 *     gNameBuf (passed by address), as docs/families/poke_tool.h says.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;

struct MsgData;
struct Personal;
struct Sav;
extern void POKE_TOOL_ClearBoxParam(struct Sav *p);
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern void *func_02019C54(u32 a, u32 b);
extern u32   func_020056EC(u32 a);
extern u32   func_0203F0A8(void);
extern void  POKE_TOOL_SetBoxValue(void *obj, u32 id, u32 val);
extern u32   POKE_TOOL_CheckShiny(u32 a, u32 b);
extern void MSGDATA_ReadUnits(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern u32   POKE_TOOL_GetExpForLevel(u16 a, u16 b, u16 c);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern u32   func_02019C7C(void *a);
extern u8 POKE_TOOL_GetBoxGender(void *p);
extern u32 POKE_TOOL_SetBoxDefaultMoves(void *p);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);

extern u8   GAME_LANGUAGE_Code;
extern void *gSpeciesNameBank;
extern u16  gNameBuf[];
extern u8   GAME_VERSION_Code;

void POKE_TOOL_SetupBoxParamEx(void *obj, u16 species, u16 level, u64 id, u32 pow, u64 rnd)
{
    void *rec;
    u32 flag;
    u32 v;

    POKE_TOOL_ClearBoxParam(obj);
    flag = POKE_TOOL_DecodeBoxParam(obj);
    rec = func_02019C54(species, 0);

    if (rnd == 0xFFFFFFFF00000000ULL) {
        rnd = func_020056EC(0);
        func_0203F0A8();
    } else if (rnd == 0xFFFFFFFF00000001ULL) {
        rnd = id;
    }
    POKE_TOOL_SetBoxValue(obj, 0, (u32)rnd);

    if (id == 0xFFFFFFFFFFFFFFFFULL) {
        id = func_020056EC(0);
    } else if (id == 0xFFFFFFFF00000000ULL) {
        id = (u32)(rnd + 1);
        while (POKE_TOOL_CheckShiny((u32)id, (u32)rnd)) {
            id = (id + 1) & 0xFFFFFFFF;
        }
    }
    POKE_TOOL_SetBoxValue(obj, 7, (u32)id);
    POKE_TOOL_SetBoxValue(obj, 0xc, GAME_LANGUAGE_Code);
    POKE_TOOL_SetBoxValue(obj, 5, species);
    MSGDATA_ReadUnits(gSpeciesNameBank, species, gNameBuf, 0x20);
    POKE_TOOL_SetBoxValue(obj, 0x74, (u32)gNameBuf);
    POKE_TOOL_SetBoxValue(obj, 8, POKE_TOOL_GetExpForLevel(species, 0, level));
    POKE_TOOL_SetBoxValue(obj, 9, POKE_PERSONAL_GetParam(rec, 0x16));
    POKE_TOOL_SetBoxValue(obj, 0x99, level);
    POKE_TOOL_SetBoxValue(obj, 0x77, GAME_VERSION_Code);
    POKE_TOOL_SetBoxValue(obj, 0x98, 4);

    if (pow == 0xFFFFFFFF) {
        POKE_TOOL_SetBoxValue(obj, 0x46, (u32)(((u64)func_0203F0A8() * 32) >> 32));
        POKE_TOOL_SetBoxValue(obj, 0x47, (u32)(((u64)func_0203F0A8() * 32) >> 32));
        POKE_TOOL_SetBoxValue(obj, 0x48, (u32)(((u64)func_0203F0A8() * 32) >> 32));
        POKE_TOOL_SetBoxValue(obj, 0x4a, (u32)(((u64)func_0203F0A8() * 32) >> 32));
        POKE_TOOL_SetBoxValue(obj, 0x4b, (u32)(((u64)func_0203F0A8() * 32) >> 32));
        POKE_TOOL_SetBoxValue(obj, 0x49, (u32)(((u64)func_0203F0A8() * 32) >> 32));
    } else {
        POKE_TOOL_SetBoxValue(obj, 0x46, (u8)(pow & 0x1f));
        POKE_TOOL_SetBoxValue(obj, 0x47, (u8)((pow >> 5) & 0x1f));
        POKE_TOOL_SetBoxValue(obj, 0x48, (u8)((pow >> 10) & 0x1f));
        POKE_TOOL_SetBoxValue(obj, 0x4a, (u8)((pow >> 15) & 0x1f));
        POKE_TOOL_SetBoxValue(obj, 0x4b, (u8)((pow >> 20) & 0x1f));
        POKE_TOOL_SetBoxValue(obj, 0x49, (u8)((pow >> 25) & 0x1f));
    }

    v = 0x1a;
    if (func_02019C7C(rec) == 2 && (rnd & 0x10000) != 0) {
        v = 0x1b;
    }
    POKE_TOOL_SetBoxValue(obj, 0xa, POKE_PERSONAL_GetParam(rec, v));
    POKE_TOOL_SetBoxValue(obj, 0x6e, POKE_TOOL_GetBoxGender(obj));
    POKE_TOOL_SetBoxValue(obj, 0x70, func_020056EC(0x19));
    POKE_TOOL_SetBoxDefaultMoves(obj);
    POKE_TOOL_EncodeBoxParam(obj, flag);
}
