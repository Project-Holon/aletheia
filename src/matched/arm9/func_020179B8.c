/*
 * function: POKE_TOOL_ChangeBoxForm
 * address:  0x020179B8
 * packet:   pkt_020179B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * A "select and apply" pair, structurally the sibling of POKE_TOOL_ChangeBoxSpecies.
 * The value at selector 5 is compared against a1; when they already agree
 * nothing but the +0x18 restore happens.  Otherwise the old selection is read
 * back out of selector 0x6f into r4 (the local that was 0, which is why the
 * clearing write passes r4 and not a literal 0) and the new value is written
 * with selector 0x6f before the two geometry calls run with it.
 *
 * The `cmp` operand order is the tell: `(u16)func_02017E88(...)` only reaches
 * cmp's left slot because it was first bound to a named local (`t`), see
 * docs/idioms/cmp-operand-order-names-the-temporary.md.  Comparing the call
 * result directly emits `cmp a1, r0` and differs by one byte.
 *
 * EXACT*: the compared extent ran into the follower's four-byte pad, which is
 * identical in both objects.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_TOOL_ChangeBoxForm.c \
 *       --func POKE_TOOL_ChangeBoxForm --addr 0x020179B8 --cc 1.1p1 --thumb
 *
 * symbols:
 *   POKE_TOOL_UpdateAbilityForSpecies  0x02017C50  thumb
 *   POKE_TOOL_UpdateGenderForSpecies  0x02017CC8  thumb
 *   POKE_TOOL_SetBoxValue  0x02017E64  thumb
 */

typedef unsigned int   u32;
struct Sav;
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetBoxValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_UpdateAbilityForSpecies(int a0, int a1, int a2);
extern void POKE_TOOL_UpdateGenderForSpecies(void *a0, void *a1, void *a2);
extern u32 func_02017DE4(struct Sav *p, u32 f);

int POKE_TOOL_ChangeBoxForm(int a0, int a1)
{
    int r4 = 0;
    int r7 = (unsigned char)func_02017DBC((struct Sav *)a0);
    int t = (unsigned short)func_02017E88((void *)a0, 0x6f, 0);

    if (t != a1) {
        func_02017E88((void *)a0, 0x6f, r4);
        r4 = (unsigned short)func_02017E88((void *)a0, 5, r4);
        POKE_TOOL_SetBoxValue((void *)a0, 0x6f, a1);
        POKE_TOOL_UpdateAbilityForSpecies(a0, r4, r4);
        POKE_TOOL_UpdateGenderForSpecies((void *)a0, (void *)r4, (void *)r4);
        r4 = 1;
    }
    func_02017DE4((struct Sav *)a0, r7);
    return r4;
}
