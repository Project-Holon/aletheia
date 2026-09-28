/*
 * unit:     yes
 * address:  0x0201ADA4
 * packet:   pkt_0201A5FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201ADA4
 *
 * symbols:
 *   g_0214652C  0x0214652C  data
 *
 * A three-parameter wrapper: calls sub_0201AFD4(a, b) (0x0201AFD4, still
 * open) and threads its result through two handler calls keyed off a static
 * handle at 0x0214652C, then hands the third parameter off to a third
 * handler with a literal id of 0x3C.  Kept as its own file rather than
 * merged with the neighbouring sub_0201ADD0/sub_0201ADE4
 * (src/matched/unit_0201ADD0.c) because both of those call sub_0201AFD4 as
 * well; one range holding all three calls has none of them attested and
 * caps at MATCH (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 * With this function alone, the other two callers are outside the range and
 * carry the `label` evidence.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ADA4.c \
 *       --addr 0x0201ADA4 --thumb
 */

typedef unsigned int u32;

extern void *sub_0201AFD4(void *a, void *b);
extern void *func_02049578(void *handle, void *x);
extern void *func_0204960C(void *handle, void *x);
extern void  func_020495F4(void *handle, u32 id, void *arg);
extern void *g_0214652C;

void sub_0201ADA4(void *a, void *b, void *c)
{
    void *r = sub_0201AFD4(a, b);

    r = func_02049578(g_0214652C, r);
    r = func_0204960C(g_0214652C, r);
    func_020495F4(g_0214652C, 0x3C, c);
}
