/*
 * function: NATSUKI_CalcParty
 * address:  0x0201B818
 * packet:   pkt_0201B7A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * was-blocked: 0209E462.  The `literal` class still refuses it -- the only
 *           pool word in the image holding 0x0209E462 is this function's own,
 *           at 0x0201B84C, inside the compared range.  The site resolves as
 *           `sole-ref` instead, so the entry is EXACT and not MATCH.
 *
 * symbols:
 *   _NatsukiPartyDeltas     0x0209E462  data
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   NATSUKI_Apply  0x0201B850  thumb
 *
 * for (i = 0; i < count(a0); i++) NATSUKI_Apply(entry(a0, i), &_NatsukiPartyDeltas,
 * a1, a2); - the entry pointer the loop computes is what feeds the second
 * call's first argument, which is why no `r0 = a0` copy appears in front of
 * it (the returned r0 is already the argument), and the bound is
 * re-evaluated at the bottom of the loop so it stays a call in the
 * condition.  The table pointer is this function's own pool word at
 * 0x0201B84C, behind the C0 46 alignment filler at 0x0201B84A.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NATSUKI_CalcParty.c \
 *       --func NATSUKI_CalcParty --addr 0x0201B818 --cc 1.1p1 --thumb
 */

typedef signed char s8;
typedef unsigned int u32;

extern const s8 _NatsukiPartyDeltas[];
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void NATSUKI_Apply(void *mon, const s8 *tbl, int a2, u32 a3);

void NATSUKI_CalcParty(void *a0, int a1, int a2)
{
    int i;

    for (i = 0; i < (int)POKEPARTY_GetCount(a0); i++) {
        NATSUKI_Apply(POKEPARTY_GetMember(a0, i), _NatsukiPartyDeltas, a1, a2);
    }
}
