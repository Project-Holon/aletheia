/*
 * file:     worldtrade.c
 * unit:     yes
 * function: WORLDTRADE_GetFromSave, WORLDTRADE_GetSize, WORLDTRADE_Init, WORLDTRADE_GetIsDeposited, WORLDTRADE_SetIsDeposited, WORLDTRADE_CopyPokemon, WORLDTRADE_NoOp, WORLDTRADE_SetPokemon, WORLDTRADE_SetLastTradeId, WORLDTRADE_SetLastSearchId, WORLDTRADE_GetReturnBox
 * address:  0x0200AD6C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mystery_data.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_020071CC  0x020071CC  thumb
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 */
#include "wifilist_tail_shared_types.h"

/* Save block 0x2E, the GTS deposit data (0xF8 bytes). */
struct WorldTradeData {
    u8  pokemon[0xDC];
    u8  depositInfo[0x10];
    u16 isDeposited;
    u16 returnBox;
    u32 lastTradeId;
    u32 lastSearchId;
};

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

extern void MIi_CpuClearFast(u32 data, void *dest, u32 size);

extern void *func_020071CC(struct SaveControl *save, u32 blockId);

extern u32  POKE_TOOL_GetPartyParamSize(void);

struct WorldTradeData *WORLDTRADE_GetFromSave(struct SaveControl *save);

int WORLDTRADE_GetSize(void);

void WORLDTRADE_Init(struct WorldTradeData *trade);

u16 WORLDTRADE_GetIsDeposited(const struct WorldTradeData *trade);

void WORLDTRADE_SetIsDeposited(struct WorldTradeData *trade, u16 isDeposited);

void WORLDTRADE_CopyPokemon(struct WorldTradeData *trade, void *outPokemon);

void WORLDTRADE_NoOp(void);

void WORLDTRADE_SetPokemon(struct WorldTradeData *trade, const void *pokemon, u32 boxPos);

void WORLDTRADE_SetLastTradeId(struct WorldTradeData *trade, u32 tradeId);

void WORLDTRADE_SetLastSearchId(struct WorldTradeData *trade, u32 searchId);

u16 WORLDTRADE_GetReturnBox(struct WorldTradeData *trade);

/*
 * Save-block getter for block 0x2E, the same one-line shape as
 * MUSICAL_SHOT_GetFromSave / IRC_RANKING_GetFromSave (blocks 0x2B, 0x2C) in unit_0200A864.c:
 * a tail call through the pool with the id in r1.
 */
struct WorldTradeData *WORLDTRADE_GetFromSave(struct SaveControl *save)
{
    return func_020071CC(save, 0x2e);
}

/*
 * note:     wave 17 lane untried_small: return 0xF8 (the size of a 0xF8-byte record); listing extent runs over the unlabelled neighbours 0x0200AD7C, 0x0200AD8C, 0x0200AD94.
 */
int WORLDTRADE_GetSize(void)
{
    return sizeof(struct WorldTradeData);
}

/*
 * note:     wave 18 lane ties_b: unlabelled follower of WORLDTRADE_GetSize; clears a 0xF8-byte record with MIi_CpuClearFast (tail call).
 */
void WORLDTRADE_Init(struct WorldTradeData *trade)
{
    MIi_CpuClearFast(0, trade, sizeof(struct WorldTradeData));
}

/*
 * note:     wave 18 lane ties_b: unlabelled follower; getter of the u16 at +0xEC (extent includes two bytes of padding).
 */
u16 WORLDTRADE_GetIsDeposited(const struct WorldTradeData *trade)
{
    return trade->isDeposited;
}

/*
 * note:     wave 18 lane ties_b: unlabelled follower; setter of the u16 at +0xEC (extent includes two bytes of padding).
 */
void WORLDTRADE_SetIsDeposited(struct WorldTradeData *trade, u16 isDeposited)
{
    trade->isDeposited = isDeposited;
}

void WORLDTRADE_CopyPokemon(struct WorldTradeData *trade, void *outPokemon)
{
    u32 size = POKE_TOOL_GetPartyParamSize();
    MI_CpuCopy8(trade, outPokemon, size);
}

/*
 * Unlabelled Thumb leaf in the ARM9 module: an empty `bx lr` body.
 *
 * Addresses are Black-image addresses.
 */
void WORLDTRADE_NoOp(void)
{
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           REGULATION_GetCompetitionSize, REGULATION_Create, REGULATION_Copy, REGULATION_NoOp,
 *           REGULATION_GetCupName, REGULATION_CreateCupName, REGULATION_GetRuleValue, REGULATION_SetRuleValue,
 *           REGULATION_GetVetoBit, REGULATION_GetShooterSettings, REGULATION_Card_GetCupName, REGULATION_Card_GetValue,
 *           REGULATION_Card_SetValue, REGULATION_Card_IsCrcValid, REGULATION_Card_CalcCrc, REGULATION_GetCard,
 *           REGULATION_SetCard, REGULATION_InitParty, REGULATION_GetParty, REGULATION_Party_GetValue,
 *           REGULATION_Party_SetValue
 *
 * alias: the original source file is named in the image.  The constructor at
 * 0x0200ADF0 passes 0x020A71B4 to the debug allocator at 0x02030734, and the
 * bytes there spell "regulation.c"; the string before it is
 * "mystery_data.c", which is what the `string` attestation class uses to fix
 * the address without reading the pool word under test.  That makes this the
 * second original source file name this project has recovered, after
 * "playtime.c".  The functions keep their func_<address> names, because the
 * file identity is attested and the individual entry points are not.
 *
 * 1260 bytes, 0x0200ADB8..0x0200B2A4, 25 functions, eleven of which carry no
 * label in the generated listing.
 *
 * What a regulation is, read off the accessors: a 0xBC-byte record of
 * battle-rule settings.  The pair at 0x0200AE54 and 0x0200AEE8 is its whole
 * scalar interface, a get and a set indexed by a rule id in 0..22, and the
 * set carries the legal range of every rule: ids 0 to 3 take a value under 7,
 * 6 and 6 and 6; id 4 is capped at 100; id 6 at 600; ids 7, 8, 13, 17 and 19
 * are booleans; id 11 is a u16 under 651; id 20 is capped at 99.  Ids 9, 10
 * and 14 are missing from both tables because they are not scalars: they are
 * the three bitmaps at +0x0A, +0x5C and +0xAC that REGULATION_GetVetoBit tests a bit
 * of.  A second pair at 0x0200B078 and 0x0200B110 does the same job for a
 * larger record that contains this one at offset 0, over ids 1..12 and a set
 * of signed fields at 0x152..0x15D.  0x0200B1A8 checks the record against the
 * checksum stored at +0x15E.
 *
 * Four things here are worth naming:
 *
 *  - a dense switch becomes a PC-relative halfword jump table, and the whole
 *    of it, table included, comes out of ordinary C.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.  The table
 *    is what reads the case list back: an entry pointing at the common exit
 *    is a case that is absent from the source, which is how ids 9, 10 and 14
 *    above are known to be missing rather than empty.
 *  - REGULATION_Card_GetValue falls off the end of its switch with no return statement,
 *    and the original's default arm is a bare `bx lr` that returns the
 *    incoming pointer.  Adding a `return 0;` to make the C well-formed adds
 *    an instruction and moves every case body.
 *  - a 0x160-byte struct assignment is an inline eight-byte `ldm`/`stm` loop
 *    rather than a call, but only when the struct is four-aligned; declared
 *    as a `u8` array it is a byte loop instead.  See
 *    docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md.
 *  - `p->unk12 >> n` on a `u8` field is an *arithmetic* shift, because the
 *    field promotes to `int` before the shift.  Writing the field as `u32`,
 *    or casting, gives `lsrs` and two bytes wrong in REGULATION_Party_GetValue.
 */
void WORLDTRADE_SetPokemon(struct WorldTradeData *trade, const void *pokemon, u32 boxPos)
{
    MI_CpuCopy8(pokemon, trade, POKE_TOOL_GetPartyParamSize());
}

void WORLDTRADE_SetLastTradeId(struct WorldTradeData *trade, u32 tradeId)
{
    trade->lastTradeId = tradeId;
}

void WORLDTRADE_SetLastSearchId(struct WorldTradeData *trade, u32 searchId)
{
    trade->lastSearchId = searchId;
}

u16 WORLDTRADE_GetReturnBox(struct WorldTradeData *trade)
{
    return trade->returnBox;
}
