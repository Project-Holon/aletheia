/*
 * unit:     yes
 * function: func_02017214
 * address:  0x02017214
 * packet:   pkt_02017214
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202D5CC  0x0202D5CC  thumb
 *   func_0202D5F8  0x0202D5F8  thumb
 *   func_0202D61C  0x0202D61C  thumb
 *   func_0202D640  0x0202D640  thumb
 *   func_0202D664  0x0202D664  thumb
 *   func_0202D688  0x0202D688  thumb
 *   func_0202D6AC  0x0202D6AC  thumb
 *   func_0202D6D0  0x0202D6D0  thumb
 *
 * Promoted from src/pending/ during a shard verify sweep: all six of its
 * previously witness-less callees (func_0202D5F8, func_0202D640,
 * func_0202D664, func_0202D688, func_0202D6AC, func_0202D6D0) are now
 * EXACT matched entries elsewhere in the tree, so the `matched` class
 * resolves every site that was stuck wildcarded and this closes to
 * EXACT with no change to the C.
 *
 * This is the twin of func_02017168 in src/matched/unit_02017100.c: the
 * same nine word record, built from a pair of pointers instead of from
 * five save block fields, with 1 in the last word where the other
 * writes 0.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02017214.c \
 *       --addr 0x02017214 --thumb
 */

typedef unsigned int u32;

extern u32 func_0202D5CC(u32 a);
extern u32 func_0202D5F8(u32 id, u32 flags);
extern u32 func_0202D61C(u32 id, u32 flags);
extern u32 func_0202D640(u32 id, u32 flags);
extern u32 func_0202D664(u32 id, u32 flags);
extern u32 func_0202D688(u32 id, u32 flags);
extern u32 func_0202D6AC(u32 id, u32 flags);
extern u32 func_0202D6D0(u32 id, u32 flags);

struct Stats {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
};

void func_02017214(void *p, struct Stats *out, void *q)
{
    out->unk00 = func_0202D5CC((u32)q);
    out->unk04 = func_0202D5F8((u32)p, (u32)q);
    out->unk08 = func_0202D61C((u32)p, (u32)q);
    out->unk0C = func_0202D640((u32)p, (u32)q);
    out->unk10 = func_0202D664((u32)p, (u32)q);
    out->unk14 = func_0202D688((u32)p, (u32)q);
    out->unk18 = func_0202D6AC((u32)p, (u32)q);
    out->unk1C = func_0202D6D0((u32)p, (u32)q);
    out->unk20 = 1;
}
