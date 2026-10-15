/*
 * function: POKE_TOOL_UpdateAbilityForSpecies
 * address:  0x02017C50
 * packet:   pkt_020179B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Picks one of three record types and writes selector 0xa.  `mask` is a
 * bit test against the byte returned by selector 0, and which bit it is
 * depends on selector 0x77: below 0x14 the mask is bit 0, at or above it the
 * mask is bit 16.  The comparison against 0x14 is *unsigned* in the original
 * (`bhs`, not `bge`), so func_02017E88 must be declared returning an unsigned
 * type - an `int` declaration emits `bge` and costs four bytes.
 *
 * Declaration order is load bearing: `r6` (the 0x1a/0x1b/0x1c selector) is
 * declared first and takes the higher register, `mask` second and takes the
 * lower one.  Reversing them keeps the same instruction count but swaps r4
 * and r6 in nine places.
 *
 * EXACT*: the extent runs into the follower's four-byte pad.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_TOOL_UpdateAbilityForSpecies.c \
 *       --func POKE_TOOL_UpdateAbilityForSpecies --addr 0x02017C50 --cc 1.1p1 --thumb
 *
 * symbols:
 *   POKE_TOOL_SetBoxValue  0x02017E64  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_TOOL_GetPersonalData  0x02019C54  thumb
 *   POKE_TOOL_GetPersonalGender  0x02019C7C  thumb
 */

typedef unsigned int u32;

struct Personal;
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void *POKE_TOOL_GetPersonalData(u32 a, u32 b);
extern u32 POKE_TOOL_GetPersonalGender(void *h);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_TOOL_SetBoxValue(void *p, u32 id, u32 v);

void POKE_TOOL_UpdateAbilityForSpecies(int a0, int a1, int a2)
{
    int v = (int)POKE_TOOL_GetPersonalData(a1, (unsigned short)func_02017E88((void *)a0, 0x6f, 0));
    int r7 = func_02017E88((void *)a0, 0, 0);
    int r6 = 0x1a;
    u32 mask = 1 << 16;

    if (func_02017E88((void *)a0, 0x77, 0) < 0x14) {
        mask = 1;
    }
    if (func_02017E88((void *)a0, 0x71, 0) != 0) {
        r6 = 0x1c;
    } else if (POKE_TOOL_GetPersonalGender((void *)v) == 2 && (r7 & mask) != 0) {
        r6 = 0x1b;
    }
    POKE_TOOL_SetBoxValue((void *)a0, 0xa, POKE_PERSONAL_GetParam((const struct Personal *)v, r6));
}
