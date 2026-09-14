/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * address:  0x02017214..0x02017270, 92 bytes, one function
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right
 *
 * Why it is capped: six of its eight callees, func_0202D5F8, func_0202D640,
 * func_0202D664, func_0202D688, func_0202D6AC and func_0202D6D0, are reached
 * from nowhere else in the image, so the `label` class has no witness for any
 * of them once the compared range holds this function, and no cut helps: the
 * range cannot be made smaller than the one function that needs them.
 *
 * This is the twin of func_02017168 in src/matched/unit_02017100.c: the same
 * nine word record, built from a pair of pointers instead of from five save
 * block fields, with 1 in the last word where the other writes 0.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/unit_02017214.c \
 *       --addr 0x02017214 --thumb
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
 */

typedef unsigned int u32;

extern u32 func_0202D5CC(void *q);
extern u32 func_0202D5F8(void *p, void *q);
extern u32 func_0202D61C(void *p, void *q);
extern u32 func_0202D640(void *p, void *q);
extern u32 func_0202D664(void *p, void *q);
extern u32 func_0202D688(void *p, void *q);
extern u32 func_0202D6AC(void *p, void *q);
extern u32 func_0202D6D0(void *p, void *q);

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
    out->unk00 = func_0202D5CC(q);
    out->unk04 = func_0202D5F8(p, q);
    out->unk08 = func_0202D61C(p, q);
    out->unk0C = func_0202D640(p, q);
    out->unk10 = func_0202D664(p, q);
    out->unk14 = func_0202D688(p, q);
    out->unk18 = func_0202D6AC(p, q);
    out->unk1C = func_0202D6D0(p, q);
    out->unk20 = 1;
}
