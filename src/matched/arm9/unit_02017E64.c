/*
 * unit:     yes
 * address:  0x02017E64
 * packet:   pkt_02017C50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_TOOL_SetBoxValue, POKE_TOOL_GetBoxValue, POKE_TOOL_IsShiny, POKE_TOOL_IsBoxShiny,
 *           POKE_TOOL_IsShinyOtIdPersonality, POKE_TOOL_GetGender, POKE_TOOL_GetBoxGender, POKE_TOOL_CalcGender,
 *           POKE_TOOL_GetStatusCondition, POKE_TOOL_SetStatusCondition, POKE_TOOL_SetDefaultMoves
 *
 * symbols:
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_SetBoxDefaultMoves  0x02017FB0  thumb
 *   POKE_TOOL_DecodeBoxBlock  0x02018D34  thumb
 *   POKE_TOOL_EncodeBoxBlock  0x02018D8C  thumb
 *   POKE_TOOL_GetBoxValueRaw  0x02018E34  thumb
 *   POKE_TOOL_SetBoxValueRaw  0x02019388  thumb
 *   POKE_TOOL_GetPersonalData  0x02019C54  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *
 * Five of the eleven carry no label in the generated listing: the three eight
 * to twelve byte pool-word tail calls at 0x02017EAC, 0x02017F00 and
 * 0x02017FA8, and the two twelve byte argument-setting thunks at 0x02017F90
 * and 0x02017F9C, all of them
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.  POKE_TOOL_IsShiny, POKE_TOOL_GetGender
 * and POKE_TOOL_SetDefaultMoves each tail call the function immediately after them, which
 * makes two of the three sites the `local` class.
 *
 * POKE_TOOL_IsShinyOtIdPersonality folds two words to sixteen bits and its four XOR operands have
 * exactly one source order, which is not the order the `eors` appear in; see
 * docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md.
 *
 * POKE_TOOL_CalcGender dispatches 0, 0xFE and 0xFF out of a byte and falls through to
 * a comparison for everything else.  The three tests are one `switch`: written
 * as a chain of `if (n == k) return v;` statements each return gets its own
 * epilogue, while the switch puts the three bodies after the compare chain and
 * shares one `pop`, which is what the original does.  The `lsls`/`lsrs` pair
 * that truncates the call result is only emitted when the callee is declared
 * wider than `u8`, so POKE_PERSONAL_GetParam returns a word and the source assigns it to
 * a byte local.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Mon;
struct Personal;
struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern u32  POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32  POKE_TOOL_SetBoxDefaultMoves(void *p);
extern u32 POKE_TOOL_DecodeBoxBlock(struct Sav *p);
extern void POKE_TOOL_EncodeBoxBlock(struct Sav *p);
extern u32 POKE_TOOL_GetBoxValueRaw(struct Mon *p, u32 id, u32 v);
extern void POKE_TOOL_SetBoxValueRaw(struct Mon *p, u32 id, u32 v);
extern void *POKE_TOOL_GetPersonalData(u32 a, u32 b);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);

u32 POKE_TOOL_IsBoxShiny(void *p);
u32 POKE_TOOL_IsShinyOtIdPersonality(u32 a, u32 b);
u8 POKE_TOOL_GetBoxGender(void *p);
u8 POKE_TOOL_CalcGender(u32 a, u16 b, u32 c);

void POKE_TOOL_SetBoxValue(void *p, u32 id, u32 v)
{
    if (POKE_TOOL_DecodeBoxBlock(p) == 1) {
        POKE_TOOL_SetBoxValueRaw(p, id, v);
    }
    POKE_TOOL_EncodeBoxBlock(p);
}

u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v)
{
    u32 r;

    POKE_TOOL_DecodeBoxBlock(p);
    r = POKE_TOOL_GetBoxValueRaw(p, id, v);
    POKE_TOOL_EncodeBoxBlock(p);
    return r;
}

u32 POKE_TOOL_IsShiny(void *p)
{
    return POKE_TOOL_IsBoxShiny(p);
}

u32 POKE_TOOL_IsBoxShiny(void *p)
{
    u32 a = POKE_TOOL_GetBoxValue(p, 7, 0);

    return POKE_TOOL_IsShinyOtIdPersonality(a, POKE_TOOL_GetBoxValue(p, 0, 0));
}

u32 POKE_TOOL_IsShinyOtIdPersonality(u32 a, u32 b)
{
    u32 x = ((a & 0xFFFF0000) >> 16) ^ (u16)a ^ ((b & 0xFFFF0000) >> 16) ^ (u16)b;

    if (x < 8) {
        return 1;
    }
    return 0;
}

u8 POKE_TOOL_GetGender(void *p)
{
    return POKE_TOOL_GetBoxGender(p);
}

u8 POKE_TOOL_GetBoxGender(void *p)
{
    u32 t = POKE_TOOL_DecodeBoxParam(p);
    u16 a = (u16)POKE_TOOL_GetBoxValue(p, 5, 0);
    u32 b = POKE_TOOL_GetBoxValue(p, 0x6F, 0);
    u32 c = POKE_TOOL_GetBoxValue(p, 0, 0);

    POKE_TOOL_EncodeBoxParam(p, t);
    return POKE_TOOL_CalcGender(a, (u16)b, c);
}

u8 POKE_TOOL_CalcGender(u32 a, u16 b, u32 c)
{
    u8 n = POKE_PERSONAL_GetParam(POKE_TOOL_GetPersonalData(a, b), 0x14);
    u8 r;

    switch (n) {
    case 0x00:
        return 0;
    case 0xFE:
        return 1;
    case 0xFF:
        return 2;
    }
    if ((u8)c < n) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

u32 POKE_TOOL_GetStatusCondition(void *p)
{
    return POKE_TOOL_GetPartyValue(p, 0x9D, 0);
}

void POKE_TOOL_SetStatusCondition(void *p, u32 v)
{
    POKE_TOOL_SetPartyValue(p, 0x9D, v);
}

u32 POKE_TOOL_SetDefaultMoves(void *p)
{
    return POKE_TOOL_SetBoxDefaultMoves(p);
}
