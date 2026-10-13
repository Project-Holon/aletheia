/*
 * function: func_0200BB58
 * address:  0x0200BB58
 * packet:   pkt_0200BAF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKE_TOOL_ClearBoxParam  0x02017550  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   sub_0200BAD4  0x0200BAD4  thumb
 *
 * Clear the six 0x88-byte slots of a0, then walk a1's list.  The bound of the
 * second loop is a call - POKEPARTY_GetCount(a1) is re-invoked at the bottom of
 * every iteration and its result compared against the counter (`cmp r5, r0`
 * right after the `bl`), and the entry test is the peeled copy of that same
 * call, which is exactly how mwcc lowers `for (i = 0; i < f(a1); i++)`.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Sav;
extern void POKE_TOOL_ClearBoxParam(struct Sav *p);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void *POKE_TOOL_GetBoxParam(void *p);
struct Grp330;
struct Ent88;
extern void sub_0200BAD4(struct Grp330 *p, u32 g, u32 i, const struct Ent88 *src);

void func_0200BB58(u8 *a0, u8 *a1)
{
    u32 i;
    u32 k = 0;

    for (i = 0; i < 6; i++)
        POKE_TOOL_ClearBoxParam((struct Sav *)(a0 + i * 0x88));

    for (i = 0; i < (u32)POKEPARTY_GetCount(a1); i++)
        sub_0200BAD4((struct Grp330 *)a0, k, i, POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(a1, i)));
}
