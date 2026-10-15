/*
 * function: BTL_SETUP_ApplyRegulation
 * address:  0x02013160
 * packet:   pkt_02013160
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   REGULATION_GetRuleValue   0x0200AE54  thumb
 *   REGULATION_GetShooterSettings   0x0200B040  thumb
 *   POKE_REGULATION_AdjustPartyLevels   0x0201A2A8  thumb
 *   POKE_REGULATION_ResetPartyNicknames   0x0201A30C  thumb
 *
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
#include "../include/Obj01199.h"
#include "../include/Obj08746.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Reg;
extern u32 REGULATION_GetRuleValue(struct Reg *p, u32 id);
struct RegAC;
extern void REGULATION_GetShooterSettings(struct Reg *p, struct RegAC *out);
extern void POKE_REGULATION_AdjustPartyLevels(void *a0, void *a1);
extern void POKE_REGULATION_ResetPartyNicknames(void *a0, void *a1, u32 c);

void BTL_SETUP_ApplyRegulation(u8 *o, void *a1, u32 a2)
{
    u32 bit = 0x10;
    u32 sec = 0x3c;
    int i;

    ((struct Obj01199 *)o)->f76 = (u16)(sec * REGULATION_GetRuleValue(a1, 0x10));
    ((struct Obj01199 *)o)->f74 = (u16)(sec * REGULATION_GetRuleValue(a1, 0xf));
    REGULATION_GetShooterSettings(a1, (struct RegAC *)(o + 0x78));
    switch (REGULATION_GetRuleValue(a1, 0x12)) {
    case 0:
        break;
    case 1:
        ((struct Obj01199 *)o)->f82 |= (u16)(bit << 7);
        break;
    case 2:
        ((struct Obj01199 *)o)->f82 |= (u16)(bit << 6);
        break;
    case 3:
        ((struct Obj01199 *)o)->f82 |= (u16)(bit << 6);
        ((struct Obj01199 *)o)->f82 |= (u16)(bit << 7);
        break;
    }
    for (i = 0; i < 4; i++) {
        u8 *e = o + i * 4;
        if (((struct Obj08746 *)e)->f24 != 0) {
            POKE_REGULATION_ResetPartyNicknames(a1, (void *)(((struct Obj08746 *)e)->f24), a2);
            POKE_REGULATION_AdjustPartyLevels(a1, (void *)(((struct Obj08746 *)e)->f24));
        }
    }
}
